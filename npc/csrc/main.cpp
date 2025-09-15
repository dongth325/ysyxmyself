
#include "VysyxSoCFull.h"  // Verilator 会自动生成这个头文件
#include "verilated.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "verilated_vcd_c.h"
#include "difftest_loader.h"
#include "isa.h"
#include <stdint.h>
#include <sys/time.h>
#include "svdpi.h"
#include "verilated_dpi.h"//用于打印所有dpi 上下文环境
#include <chrono>  // 添加获取时间的库 
//dddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
#include <nvboard.h>
#include <readline/readline.h>
#include <readline/history.h>
#define MEM_SIZE (128 * 1024 * 1024)
uint8_t *memory = nullptr;
uint64_t execution_count = 0;//统计exec_once真实执行多少次 可以截止到报错
#define PROGRAM_START_ADDRESS 0x30000000//   flash
size_t program_size = 0;
#define MEM_BASE 0x80000000
#define GPIO_BASE             0x10002000
#define SWITCH_REG_OFFSET     0x4
#define SWITCH_PASSWORD       0x0001 //

void nvboard_bind_all_pins(VysyxSoCFull* top);

extern "C" int get_reg_value(int reg_index);
extern "C" int get_pc_value();
extern "C" int get_inst_r();
extern "C" int get_if_allow_in();
extern "C" int get_saved_addr();
extern "C" int get_instr_completed();
extern "C" int get_saved_sim_lsu_addr();
extern "C" int get_switch_value();


static VerilatedVcdC* tfp = nullptr;
static vluint64_t main_time = 0;


extern "C" void flash_read(int32_t addr, int32_t *data) {
    static uint32_t flash_memory[4 * 1024 * 1024];  // 16MB Flash空间
    static bool initialized = false;
    
    // 初始化flash内容
   /* if (!initialized) {
       for (uint32_t i = 0; i < sizeof(flash_memory)/sizeof(uint32_t); i++) {
            // 实际地址 = 索引 * 4，保持在24位地址范围内
            uint32_t base_addr = (i * 4) & 0x00FFFFFF;
            flash_memory[i] = ((base_addr + 3) << 24) |
                            ((base_addr + 2) << 16) |
                            ((base_addr + 1) << 8)  |
                            (base_addr + 0); 
        }
        const uint32_t char_test_program[] = {
            0x100007b7,  // lui a5,0x10000
            0x04100713,  // li a4,65 ('A')
            0x00e78023,  // sb a4,0(a5)
            0x0000006f   // j 0xc (无限循环)
        };
        
        // 将char-test程序存储到flash的开始位置
        for (uint32_t i = 0; i < sizeof(char_test_program)/sizeof(uint32_t); i++) {
            flash_memory[i] = char_test_program[i];
        }
        
   
        






        initialized = true;
    }*/

    // 确保地址在24位范围内
    addr = addr & 0x00FFFFFF;

    // 地址对齐检查
   /* if (addr & 0x3) {
        printf("Error: Unaligned flash access at address 0x%x\n", addr);
        *data = 0;
        return;
    }*/

    // 计算数组索引（24位地址除以4）
    uint32_t flash_offset = addr >> 2;
    if (flash_offset >= sizeof(flash_memory)/sizeof(uint32_t)) {
        printf("Error: Flash access out of range at address 0x%x\n", addr);
        *data = 0;
        return;
    }

   // uint32_t raw_data = flash_memory[flash_offset];
      uint32_t raw_data = *(uint32_t *)(memory + (flash_offset * 4));
    
    // 对数据进行字节反转，抵消flash.v中的反转效果
    uint32_t swapped_data = 
        ((raw_data & 0xFF000000) >> 24) |
        ((raw_data & 0x00FF0000) >> 8)  |
        ((raw_data & 0x0000FF00) << 8)  |
        ((raw_data & 0x000000FF) << 24);
    
    // 将反转后的数据赋值给输出参数
    *data = swapped_data;
   /* printf("Flash read: addr=0x%06x, offset=%d, data=0x%08x [%02x %02x %02x %02x]\n",
           addr, flash_offset, *data,
           (*data >> 24) & 0xFF,
           (*data >> 16) & 0xFF,
           (*data >> 8) & 0xFF,
           *data & 0xFF);*/
}
     

     
extern "C" void mrom_read(int32_t addr, int32_t *data) {  
    
    // *data = *(int32_t *)addr; 
        if (addr >= 0x20000000 && addr < 0x20000000 + MEM_SIZE) {
        uint32_t offset = addr - 0x20000000;  // 计算在memory数组中的偏移
        *data = *(int32_t *)(memory + offset);
    } else {
        *data = 0;  // 无效地址返回0
    }
     }
// 定义仿真状态结构体
struct NpcState {
    //Vysyx_24090012_NPC *top;
    VysyxSoCFull *top;
    uint64_t inst_count;
    bool ebreak_encountered; //让exec once 循环退出
    uint32_t pc;
};
NpcState npc_state;

  
struct Command {
    const char *name;
    const char *description;
    int (*handler)(char *args);
};



uint64_t total_cycles = 0;
uint64_t total_instructions = 0;






// 函数声明
void execute(NpcState *s, uint64_t n);
extern "C"  uint32_t pmem_read(uint32_t addr);
void exec_once(NpcState *s);
// 定义简单命令函数
int cmd_c(char *args);
int cmd_si(char *args);
int cmd_q(char *args);
int cmd_info(char *args);
int cmd_x(char *args);

// 将命令添加到命令表中
Command cmd_table[] = {
    {"c", "Continue the execution of the program", cmd_c},
    {"si", "Step one instruction", cmd_si},
    {"q", "Quit the simulation", cmd_q},
    {"info", "Show register or memory information", cmd_info},
    {"x", "Examine memory at address", cmd_x}
};

#define NR_CMD (sizeof(cmd_table) / sizeof(cmd_table[0]))

bool is_running = true; // 控制 sdb 主循环
  

  // 命令处理函数实现
int cmd_c(char *args) {
    std::cout << "Continuing execution..." << std::endl;
    
      while (!Verilated::gotFinish() && !npc_state.ebreak_encountered) {    //while循环=批处理模式 dddddddddd
        exec_once(&npc_state);
    }
    return 0;
}

int cmd_si(char *args) {
    int steps = 1;
    if (args) {
        steps = atoi(args);
    }
    std::cout << "Stepping " << steps << " instruction(s)" << std::endl;
    execute(&npc_state,steps);
    return 0;
}

extern "C" {   //所有性能计数器dpi-c
    // IFU相关
    extern int get_ifu_count();
  //  extern int get_hit_count();
  //  extern int get_miss_count();
    // IDU相关
    extern int get_idu_count();
    extern int get_compute_inst_count();
    extern int get_load_inst_count();
    extern int get_store_inst_count();
    extern int get_branch_inst_count();
    extern int get_jump_inst_count();
    extern int get_csr_inst_count();
    extern int get_other_inst_count();
    
    // EXU相关
    extern int get_exu_count();
    
    // LSU相关
    extern int get_lsu_count();
    extern int get_read_count();
    extern int get_write_count();
}

// 打印性能统计信息的函数
void print_performance_stats() {
    printf("\n=== 性能统计 ===\n");
    printf("总周期数: %lu\n", total_cycles);
    printf("总指令数: %lu\n", total_instructions);
    
    double ipc = (total_cycles > 0) ? ((double)total_instructions / total_cycles) : 0.0;
    printf("IPC (每周期指令数): %.4f\n", ipc);
    printf("CPI (每指令周期数): %.4f\n", (total_instructions > 0) ? ((double)total_cycles / total_instructions) : 0.0);
    printf("================\n");


    // 获取各模块计数器值
    int ifu_count = 0;
    int hit_count = 0;
    int miss_count = 0;
    int idu_count = 0;
    int exu_count = 0;
    int lsu_count = 0;
    
    // 获取IDU指令类型计数
    int compute_count = 0;
    int load_count = 0;
    int store_count = 0;
    int branch_count = 0;
    int jump_count = 0;
    int csr_count = 0;
    int other_count = 0;
    
    // 获取LSU读写计数
    int read_count = 0;
    int write_count = 0;




    // 切换到IFU作用域并获取计数
    svScope ifu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.ifu");
    if (ifu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set IFU DPI scope\n");
        exit(1);
    }
    svSetScope(ifu_scope);
    ifu_count = get_ifu_count();
   // hit_count = get_hit_count();
   // miss_count = get_miss_count();
    double hit_rate = (hit_count + miss_count > 0) ? 
                 (100.0 * hit_count / (hit_count + miss_count)) : 0.0;
    
    // 切换到IDU作用域并获取计数
    svScope idu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.idu");
    if (idu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set IDU DPI scope\n");
        exit(1);
    }
    svSetScope(idu_scope);
    idu_count = get_idu_count();
    compute_count = get_compute_inst_count();
    load_count = get_load_inst_count();
    store_count = get_store_inst_count();
    branch_count = get_branch_inst_count();
    jump_count = get_jump_inst_count();
    csr_count = get_csr_inst_count();
    other_count = get_other_inst_count();
    
    // 切换到EXU作用域并获取计数
    svScope exu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.exu");
    if (exu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set EXU DPI scope\n");
        exit(1);
    }
    svSetScope(exu_scope);
    exu_count = get_exu_count();
    
    // 切换到LSU作用域并获取计数
    svScope lsu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.lsu");
    if (lsu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set LSU DPI scope\n");
        exit(1);
    }
    svSetScope(lsu_scope);
    lsu_count = get_lsu_count();
    read_count = get_read_count();
    write_count = get_write_count();
    



    // 打印流水线各阶段统计
    printf("\n----- 流水线各阶段统计 -----\n");
    printf("IFU取指次数: %d\n", ifu_count);
    printf("IDU解码次数: %d\n", idu_count);
    printf("EXU执行次数: %d\n", exu_count);
    printf("LSU访存次数: %d\n", lsu_count);

    // 打印指令类型分布
    printf("\n----- 指令类型分布 -----\n");
    if (idu_count > 0) {
        printf("计算类指令: %d (%.2f%%)\n", compute_count, 100.0 * compute_count / idu_count);
        printf("加载指令: %d (%.2f%%)\n", load_count, 100.0 * load_count / idu_count);
        printf("存储指令: %d (%.2f%%)\n", store_count, 100.0 * store_count / idu_count);
        printf("分支指令: %d (%.2f%%)\n", branch_count, 100.0 * branch_count / idu_count);
        printf("跳转指令: %d (%.2f%%)\n", jump_count, 100.0 * jump_count / idu_count);
        printf("CSR指令: %d (%.2f%%)\n", csr_count, 100.0 * csr_count / idu_count);
        printf("其他指令: %d (%.2f%%)\n", other_count, 100.0 * other_count / idu_count);
        
        // 指令类型一致性检查
        int type_sum = compute_count + load_count + store_count + 
                      branch_count + jump_count + csr_count + other_count;
        if (type_sum != idu_count) {
            printf("警告: 指令类型总和(%d)与IDU总数(%d)不一致!\n", type_sum, idu_count);
        }
    } else {
        printf("未检测到指令执行\n");
    }



    // 打印内存访问统计
    printf("\n----- 内存访问统计 -----\n");
    if (lsu_count > 0) {
        printf("总内存访问次数: %d\n", lsu_count);
        printf("读操作: %d (%.2f%%)\n", read_count, 100.0 * read_count / lsu_count);
        printf("写操作: %d (%.2f%%)\n", write_count, 100.0 * write_count / lsu_count);
        
        // 计算每指令的内存访问次数
        double mem_per_inst = (double)lsu_count / total_instructions;
        printf("每指令内存访问次数: %.4f\n", mem_per_inst);
        
        // LSU读写一致性检查
        int rw_sum = read_count + write_count;
        if (rw_sum != lsu_count) {
            printf("警告: 读写操作总和(%d)与总操作数(%d)不一致!\n", rw_sum, lsu_count);
        }
        
        // 检查加载/存储指令与LSU读写操作的一致性
        if (load_count != read_count || store_count != write_count) {
            printf("警告: 加载指令数(%d)与LSU读操作数(%d)不一致!\n", load_count, read_count);
            printf("警告: 存储指令数(%d)与LSU写操作数(%d)不一致!\n", store_count, write_count);
        }
    } else {
        printf("未检测到内存访问操作\n");
    }

 // 打印分支/跳转统计
    printf("\n----- 分支/跳转统计 -----\n");
    int control_flow_insts = branch_count + jump_count;
    if (idu_count > 0) {
        printf("控制流指令总数: %d (%.2f%%)\n", control_flow_insts, 
               100.0 * control_flow_insts / idu_count);
        printf("分支指令: %d (%.2f%%)\n", branch_count, 
               100.0 * branch_count / control_flow_insts);
        printf("跳转指令: %d (%.2f%%)\n", jump_count, 
               100.0 * jump_count / control_flow_insts);
    } else {
        printf("未检测到控制流指令\n");
    }





 
                 
printf("\n----- ICache统计 -----\n");
printf("缓存命中次数: %d\n", hit_count);
printf("缓存未命中次数: %d\n", miss_count);
printf("缓存命中率: %.2f%%\n", hit_rate);
    
    printf("\n====================================\n");



}


int cmd_q(char *args) {
    std::cout << "Exiting simulation." << std::endl;
    is_running = false; // 停止 sdb_mainloop



 print_performance_stats();


  // close_pc_trace();//npc执行后关闭用于cachesim的pc序列统计


     if (tfp) {
        tfp->close();
       delete tfp;
   }
    return -1;
}

int cmd_info(char *args) {


    if (args && strcmp(args, "r") == 0) {

    svScope scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.regfile");
    if (scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope\n");
        exit(1);
    }
    svSetScope(scope);//首先切换回普通reg上下文



        for(int i=0;i<32;i++){
int reg_value;
reg_value = get_reg_value(i);
printf("reg[%d] = %08x\n",i,reg_value);
//printf("register DUT %d value: 0x%08x from (get_dut_cpu_state)\n", i,dut_cpu_state->gpr[i]);
   }
   svScope cpu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu");
    if (cpu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope for CPU\n");
        exit(1);
    }
    svSetScope(cpu_scope);

   uint32_t pc = get_pc_value();
   printf(" PC = %08x\n",pc);
    } else if (args && strcmp(args, "m") == 0) {
        // 显示内存信息
    } else {
        std::cout << "Unknown info argument: " << args << std::endl;
    }
    return 0;
}

int cmd_x(char *args) {
    int n = 0;  // 表示要读取的4字节块的数量
    uint32_t address = 0;  // 起始地址

    // 解析参数，n 是要读取的块数，address 是起始地址
    if (sscanf(args, "%d %x", &n, &address) != 2) {
        std::cout << "Usage: x <num> <address>" << std::endl;
        return 1;  // 参数解析失败，返回错误
    }

    std::cout << "Reading " << n << " memory block(s) from address 0x" 
              << std::hex << address << std::dec << std::endl;

    // 遍历 n 个块，假设每块 4 字节
    for (int i = 0; i < n; ++i) {
        uint32_t data = pmem_read(address + i * 4);  // 读取 4 字节数据
        std::cout << "Address 0x" << std::hex << (address + i * 4) 
                  << ": 0x" << data << std::dec << std::endl;
    }
    
    return 0;
}

void sdb_mainloop() {
 
    while (is_running) {
        char *line = readline("(npc) ");
        if (line == nullptr) break;
        add_history(line);

        char *cmd = strtok(line, " ");
        char *args = cmd ? cmd + strlen(cmd) + 1 : nullptr;

        bool found = false;
        for (int i = 0; i < NR_CMD; i++) {
            if (strcmp(cmd, cmd_table[i].name) == 0) {
                found = true;
                if (cmd_table[i].handler(args) < 0) {
                    is_running = false;
                }
                break;
            }
        }
        if (!found) {
            printf("Unknown command '%s'\n", cmd);
        }

        free(line);
    }
}
//ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd

// 系统启动时的基准时间
// 获取当前时间的低32位（微秒）
auto start_time = std::chrono::steady_clock::now();

uint32_t get_current_time_low() {//get time
    using namespace std::chrono;
    auto now = steady_clock::now();
    auto elapsed = duration_cast<microseconds>(now - start_time).count();
    return static_cast<uint32_t>(elapsed & 0xFFFFFFFF); // 返回低32位
}

uint32_t get_current_time_high() {//get time
    using namespace std::chrono;
    auto now = steady_clock::now();
    auto elapsed = duration_cast<microseconds>(now - start_time).count();
    return static_cast<uint32_t>((elapsed >> 32) & 0xFFFFFFFF); // 返回高32位
}
void load_memory(const char *program_path, size_t &program_size) {
    // 打开文件
    std::ifstream infile(program_path, std::ios::binary | std::ios::in);
    if (!infile) {
        std::cerr << "Cannot open program file: " << program_path << std::endl;
        exit(1);
    }

    infile.seekg(0, std::ios::end);
    program_size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    if (program_size > MEM_SIZE) {
        std::cerr << "Program size (" << program_size << " bytes) exceeds memory size (" << MEM_SIZE << " bytes)." << std::endl;
exit(1);
    }

    infile.read(reinterpret_cast<char *>(memory), program_size);
    infile.close();

    std::cout << "Loaded program: " << program_path << ", size: " << program_size << " bytes." << std::endl;
}


extern "C" void pmem_write(uint32_t addr, uint32_t data, uint8_t mask) {
     if (addr ==  0xa00003f8) {
         putchar(data & 0xFF);
         // difftest_skip_ref();      eeeeeeeeeeee
        return; // 返回，不继续写入内存
    }
   else if (addr >= MEM_BASE && addr < MEM_BASE + MEM_SIZE) {
        uint32_t offset = addr - MEM_BASE;
        uint8_t *bytePtr = reinterpret_cast<uint8_t *>(memory + offset);

        switch (mask) {
            case 1:  // Write 1 byte
                *bytePtr = data & 0xFF;
                break;
            case 2:  // Write 2 bytes
                *reinterpret_cast<uint16_t *>(bytePtr) = data & 0xFFFF;
                break;
            case 4:  // Write 4 bytes
                *reinterpret_cast<uint32_t *>(bytePtr) = data;
                break;
            default:
               // std::cerr << "Error: Invalid write mask in pmem_write\n";
                exit(1);
        }

        /*std::cout << "MTRACE: Write " << (int)mask << " bytes to 0x" << std::hex << addr
                  << ", data = 0x" << std::hex << data << " from (pmem_write)" << std::dec << std::endl;*/
    } else {
        std::cerr << "Error: Attempt to write to invalid memory address: 0x"
                  << std::hex << addr << " from (pmem_write)" << std::dec << std::endl;
        exit(1);
    }
}


extern "C"  uint32_t pmem_read(uint32_t addr) {
      if (addr == 0x20000008) { 
       //difftest_skip_ref();eeeeeeeeeee
        return get_current_time_low();  // 返回时间的低32位
        //return 0;
    }
    else if (addr == 0x2000000c) { 
         // difftest_skip_ref();eeeeeeeeeeeeeee
        return get_current_time_high(); // 返回时间的高32位
        //return 0;
    }
   else if (addr >= MEM_BASE && addr < MEM_BASE + MEM_SIZE) {
        uint32_t offset = addr - MEM_BASE;
        uint32_t data = *(uint32_t *)(memory + offset);
        return data;
    } else {
        printf("Error: Accessing invalid memory address: 0x%08x from (pmem_read)\n", addr);
      
       
        exit(1);
    }
}

// ebreak 处理函数
// 定义外部的 ebreak 函数，用于处理 ebreak 指令
extern "C" void ebreak(uint32_t exit_code) {
    if (exit_code == 0) {
        std::cout << "HIT GOOD TRAP" << std::endl;
        npc_state.ebreak_encountered = true;
    } else {
        std::cout << "HIT BAD TRAP with exit_code= " << exit_code << std::endl;
         //exit(1);  // 立即退出
         npc_state.ebreak_encountered = true;
    }
    Verilated::gotFinish(true);  // 通知 Verilator 结束仿真
}


/*void exec_once(NpcState *s) {
 
        // 时钟下降沿
        s->top->reset = 0;


        s->top->clock = 0;
        s->top->eval();
        //if (tfp) tfp->dump(main_time++);
        // if (record_wave && tfp) tfp->dump(main_time++);
        
        s->top->eval();
        //if (tfp) tfp->dump(main_time++);
      //    if (record_wave && tfp) tfp->dump(main_time++);
   
    
        
        // 时钟上升沿
        s->top->clock = 1;
        s->top->eval();
        //if (tfp) tfp->dump(main_time++);
        // if (record_wave && tfp) tfp->dump(main_time++);
        
        s->top->eval();
       // if (tfp) tfp->dump(main_time++);
        // if (record_wave && tfp) tfp->dump(main_time++);
     
}*/

// 执行单条指令的函数（类似于 NEMU 的 exec_once）
void exec_once(NpcState *s) {
  
             // 时钟上升沿（更新 PC 和寄存器）
  
        // 设置CPU上下文
    svScope cpu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu");
    if (cpu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope for CPU\n");
        exit(1);
    }
    svSetScope(cpu_scope);
    
    // 获取旧的PC值
    uint32_t old_pc = get_pc_value();
    
    bool record_wave = (old_pc >= 0xa0000400);
//bool record_wave = 1;//运行difftest以外程序默认全部记录波形
     static int cycle_count = 0;  // 静态计数器，确保在函数调用

    // 使用do-while循环等待指令执行完成
    do {
        if (s->ebreak_encountered) {
            Verilated::gotFinish(true);  // 强制终止Verilator
            return;  // 立即返回
        }

     
        

        // 时钟下降沿
        s->top->reset = 0;


        s->top->clock = 0;
        s->top->eval();
       // if (tfp) tfp->dump(main_time++);
        // if (record_wave && tfp) tfp->dump(main_time++);
        
        s->top->eval();
        //if (tfp) tfp->dump(main_time++);
      //    if (record_wave && tfp) tfp->dump(main_time++);
   
    
        
        // 时钟上升沿
        s->top->clock = 1;
        s->top->eval();
      //  if (tfp) tfp->dump(main_time++);
        // if (record_wave && tfp) tfp->dump(main_time++);

        nvboard_update();
        
        s->top->eval();
       // if (tfp) tfp->dump(main_time++);
        // if (record_wave && tfp) tfp->dump(main_time++);
        
         total_cycles++;  // 全局周期计数


               cycle_count++;  // 增加每条指令周期计数
               
        if (cycle_count >= 200000) {
            std::cout << "\nError: No new instruction received for 200000 cycles, simulation terminated" << std::endl;
         npc_state.ebreak_encountered = true;

           svScope cpu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu");
    if (cpu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope for CPU\n");
        exit(1);
    }
    svSetScope(cpu_scope);
    
    
    uint32_t old_pc = get_pc_value();

    printf("111111111111111pc is %08x from exec_once.cpp line:485\n",old_pc);
            return;
        }


 

          // 设置RegisterFile上下文以检查指令完成状态
       


      svScope cpu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu");
    if (cpu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope for CPU\n");
        exit(1);
    }
    svSetScope(cpu_scope);
      
       s->pc = get_pc_value();


        svScope regfile_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.regfile");
        if (regfile_scope == NULL) {
            fprintf(stderr, "Error: Unable to set DPI scope for RegisterFile\n");
            exit(1);
        }
        svSetScope(regfile_scope);
    
 if (get_instr_completed()) {
            cycle_count = 0;  // 收到新指令时重置计数器
        }
    
      
   // } while (!get_if_allow_in());

    } while (!get_instr_completed());  // 使用之前获取的指令完成状态
   
    // 更新指令计数
    s->inst_count++;//用不上


     total_instructions++;  // 全局指令计数


    // 获取当前指令和内存访问地址
        svScope idu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.idu");
    if (idu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope for IDU\n");
        exit(1);
    }
    svSetScope(idu_scope);
    uint32_t inst = get_inst_r();   // 从IDU模块获取inst_r



   
    
svScope regfile_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.regfile");
if (regfile_scope == NULL) {
    fprintf(stderr, "Error: Unable to set DPI scope for regfile\n");
    exit(1);
}
svSetScope(regfile_scope);
uint32_t mem_addr = get_saved_sim_lsu_addr();
//printf("saved_lsu_addr =  0x%08x\n", mem_addr);

    // 检查是否需要跳过DiffTest
    //bool is_load = (inst & 0x7F) == 0x03;//流水线检测的时候inst不是当前diff的inst，所以不检测inst了。太麻烦了
    //bool is_store = (inst & 0x7F) == 0x23;
    
   // if ((is_load || is_store) && (((mem_addr >= 0x10000000 && mem_addr <= 0x10000fff) ||  // UART地址范围，下面的spi
   if ((((mem_addr >= 0x10000000 && mem_addr <= 0x10000fff) ||
        (mem_addr >= 0x10001000 && mem_addr <= 0x10001fff))||  // UART扩展地址范围
        (mem_addr >= 0x02000000 && mem_addr <= 0x0200000f) )    ) {// CLINT时钟地址范围
        //printf("Skipping DiffTest for UART access at 0x%08x\n", mem_addr);
        difftest_skip_ref();
    }
       
    
    // 执行DiffTest
   // difftest_step(s->top, old_pc, s->pc);
//111111111111111111111111111111111111111111111111111111111111



}

// 执行多条指令的函数（类似于 NEMU 的 execute）
void execute(NpcState *s, uint64_t n) {
    for (uint64_t i = 0; i < n; i++) {
        exec_once(s);
         tfp->dump(main_time);  // 记录波形
      main_time++;           // 更新时间
        if (s->ebreak_encountered) {
          
            break;
        }
    }
}

// 主函数
int main(int argc, char **argv) {

    
    // 初始化部分（与之前相同）
    Verilated::commandArgs(argc, argv);

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <program.bin>" << std::endl;
        return 1;
    }
        std::cout << "Received " << argc << " arguments:\n";
    for(int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "] = " << argv[i] << "\n";
    }
    const char *program_path = argv[1];

    // 初始化内存
    memory = new uint8_t[MEM_SIZE];
    memset(memory, 0, MEM_SIZE);

    // 加载程序到内存
    load_memory(program_path, program_size);

        // 初始化 Verilated 模型
   VysyxSoCFull *top = new VysyxSoCFull; 

   nvboard_bind_all_pins(top);
   nvboard_init();

 
        // 设置 npc_state 的初始值
    npc_state.top = top;
   npc_state.inst_count = 0;
   npc_state.ebreak_encountered = false;
    npc_state.pc = PROGRAM_START_ADDRESS;

    

    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    //tfp->set_time_escape(".", "_");  // 新增：替换特殊字符
    top->trace(tfp, 99);  // 99 是追踪的层级深度
    tfp->open("build/wave.vcd");  // 指定波形文件名

    // 初始化 DiffTest
   /* load_difftest_library();
    difftest_memcpy(PROGRAM_START_ADDRESS, memory, program_size, true);

    CPU_state cpu_state = {0};
    cpu_state.pc = PROGRAM_START_ADDRESS;
   difftest_regcpy(&cpu_state, true);  */// 初始化参考模型的 CPU 状态

    // 复位 
    top->reset = 1;
        top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

printf("rrrrrrrreset111 = %d \n", top->reset);
    // 施加复位信号若干周期
    for (int i = 0; i < 30; i++) {
        top->clock = 0;
            top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形
        

        top->clock = 1;
            top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形
      printf("rrrrrrrreset222 = %d \n", top->reset);
    }

    // 释放复位信号
      top->reset = 0;
        top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

     printf("rrrrrrrreset333 = %d \n", top->reset);


     for (int i = 0; i < 10; i++) {
        top->clock = 0;
            top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形
          printf("rrrrrrrreset444 = %d \n", top->reset);

        top->clock = 1;
            top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形
        printf("rrrrrrrreset555 = %d \n", top->reset);
    }
   
     


 // init_pc_trace("pc_trace.txt");//初始化用于cachesim的pc序列统计

 printf("Please set switches to password (0x%04X) to continue...\n", SWITCH_PASSWORD);
    
 // 切换到正确的 DPI 作用域
 svScope gpio_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.lgpio.mgpio");
 if (gpio_scope) {
     svSetScope(gpio_scope);
 } else {
     fprintf(stderr, "Fatal Error: Unable to set GPIO DPI scope inside exec_once. Aborting.\n");
     // 在这里直接退出，因为这是一个致命错误
     exit(1); 
 }

 // 循环等待密码正确
 //while ((get_switch_value() & 0xFFFF) != SWITCH_PASSWORD) {
     while ((get_switch_value() & 0xFFFF) != SWITCH_PASSWORD) {
     // 在等待期间，我们需要继续驱动时钟并更新nvboard
    
     //printf("Current switch value: 0x%04X (expected: 0x%04X)\n", get_switch_value() & 0xFFFF, SWITCH_PASSWORD);  // 调试打印：实时输出当前开关值

     nvboard_update();
 }
 printf("Password correct. Entering interactive mode.\n");




     sdb_mainloop();  //dddddddddddddddddddd

    // 执行指令
    /*while (!Verilated::gotFinish() && !npc_state.ebreak_encountered) {    //while循环=批处理模式 dddddddddd
        exec_once(&npc_state);
    }*/

    nvboard_quit();

    // 完成仿真
    top->final();
    delete top;
    delete[] memory;
   


    return 0;
}