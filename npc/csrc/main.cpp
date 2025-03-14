
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
#include <readline/readline.h>
#include <readline/history.h>
#define MEM_SIZE (128 * 1024 * 1024)
uint8_t *memory = nullptr;
uint64_t execution_count = 0;//统计exec_once真实执行多少次 可以截止到报错
#define PROGRAM_START_ADDRESS 0x20000000//原来是8,修改成2
size_t program_size = 0;
#define MEM_BASE 0x80000000


extern "C" int get_reg_value(int reg_index);
extern "C" int get_pc_value();
extern "C" int get_inst_r();
extern "C" int get_if_allow_in();
extern "C" int get_saved_addr();



static VerilatedVcdC* tfp = nullptr;
static vluint64_t main_time = 0;

extern "C" void flash_read(int32_t addr, int32_t *data) { assert(0); }
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

int cmd_q(char *args) {
    std::cout << "Exiting simulation." << std::endl;
    is_running = false; // 停止 sdb_mainloop

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
      if (addr == 0xa0000048) { 
       //difftest_skip_ref();eeeeeeeeeee
        return get_current_time_low();  // 返回时间的低32位
        //return 0;
    }
    else if (addr == 0xa000004c) { 
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
         exit(1);  // 立即退出
    }
    Verilated::gotFinish(true);  // 通知 Verilator 结束仿真
}




// 执行单条指令的函数（类似于 NEMU 的 exec_once）
void exec_once(NpcState *s) {
    /* 从内存中获取指令
    uint32_t inst;
    execution_count++;//实际循环了多少次exec_once 也就是真实执行次数 可截止到报错（可在下方添加以便追寻报错）
    uint32_t pc = s->pc;//h后面会再复用
    if (pc >= MEM_BASE && pc < MEM_BASE + MEM_SIZE) {
        //inst = pmem_read(pc);
         //std::cout << "Fetched instruction: 0x" << std::hex << inst << std::dec << std::endl;
        //s->top->mem_data = inst;
         s->top->input_pc = pc;
         
         s->top->input_valid = 1;
         
    } else {
        std::cerr << "Error: PC out of bounds: 0x" << std::hex << pc << std::dec << std::endl;
        std::cout << "Total instructions executed before error: " << execution_count << std::endl;  // 输出执行次数
        exit(1);
    }*/
 //111111111111111111111111111111111111111111111111111111111111111111111111111111111111

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
        if (tfp) tfp->dump(main_time++);
        
        s->top->eval();
        if (tfp) tfp->dump(main_time++);
        
   
    
        
        // 时钟上升沿
        s->top->clock = 1;
        s->top->eval();
        if (tfp) tfp->dump(main_time++);
        
        s->top->eval();
        if (tfp) tfp->dump(main_time++);
        
   
    

        // 更新当前PC
        s->pc = get_pc_value();
        //printf("11111pc = %08x\n",s->pc);
        //printf("11111 if allow in = %08x\n",get_if_allow_in());
    } while (!get_if_allow_in());
    //printf("222222pc = %08x\n",s->pc);
   // printf("222222 if allow in = %08x\n",get_if_allow_in());
    // 更新指令计数
    s->inst_count++;
    
    // 获取当前指令和内存访问地址
        svScope idu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.idu");
    if (idu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope for IDU\n");
        exit(1);
    }
    svSetScope(idu_scope);
    uint32_t inst = get_inst_r();   // 从IDU模块获取inst_r



        // 设置LSU上下文以获取内存地址
    svScope lsu_scope = svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.lsu");
    if (lsu_scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope for LSU\n");
        exit(1);
    }
    svSetScope(lsu_scope);
    uint32_t mem_addr = get_saved_addr();  // 假设LSU是CPU的直接子模块
    
    // 检查是否需要跳过DiffTest
    bool is_load = (inst & 0x7F) == 0x03;
    bool is_store = (inst & 0x7F) == 0x23;
    
    if ((is_load || is_store) && mem_addr >= 0x10000000 && mem_addr <= 0x10000fff) {
        printf("Skipping DiffTest for UART access at 0x%08x\n", mem_addr);
        difftest_skip_ref();
    }
    
    // 执行DiffTest
    difftest_step(s->top, old_pc, s->pc);
//111111111111111111111111111111111111111111111111111111111111




    // 一个时钟周期
  /* for(int i=0;i<30;i++){
s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化
   }

    s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

       s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化











            s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化





            s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化




            s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化






            s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化


                s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化



                   s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化




            s->top->clock = 0;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
    if (tfp) tfp->dump(main_time++);  // 记录组合逻辑变化

    s->top->clock = 1;
    s->top->eval();
     if (tfp) tfp->dump(main_time++);  // 记录波形

         s->top->eval();
         if (tfp) tfp->dump(main_time++);
    // 更新指令计数
    //s->inst_count++;

    // 检查 ebreak 信号
 /*   if (s->top->ebreak_flag) {
        s->ebreak_encountered = true;
          std::cout << "Encountered ebreak. Exiting simulation." << std::endl;
        return;
    }
*/
    // 更新 PC
  //  s->pc = s->top->pc;

   

     //执行 DiffTest
   // difftest_exec(1);   被包含在difftest step函数里


    //difftest_step(s->top, pc, s->pc);

    //获取 DUT 和 REF 的 CPU 状态                    
  /*  CPU_state dut_cpu_state;                            //以下被纳入到difftest_step里!!!!!!
    get_dut_cpu_state(s->top, &dut_cpu_state);

   CPU_state ref_cpu_state;
   difftest_regcpy(&ref_cpu_state, false);

   // 比较 CPU 状态
if (!isa_difftest_checkregs(&dut_cpu_state, &ref_cpu_state)) {
        std::cerr << "Difftest failed at PC = 0x" << std::hex << dut_cpu_state.pc << std::dec << std::endl;
         std::cout << "old instruction: 0x" << std::hex << inst << std::dec << std::endl;
       // exit(1);
    }*/
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
    load_difftest_library();
    difftest_memcpy(PROGRAM_START_ADDRESS, memory, program_size, true);

    CPU_state cpu_state = {0};
    cpu_state.pc = PROGRAM_START_ADDRESS;
   difftest_regcpy(&cpu_state, true);  // 初始化参考模型的 CPU 状态

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
   
        //printf("Available Verilator scopes:\n");
//Verilated::scopesDump();

     sdb_mainloop();  //dddddddddddddddddddd

    // 执行指令
    /*while (!Verilated::gotFinish() && !npc_state.ebreak_encountered) {    //while循环=批处理模式 dddddddddd
        exec_once(&npc_state);
    }*/

    // 完成仿真
    top->final();
    delete top;
    delete[] memory;
   

    //trace->close();

    return 0;
}