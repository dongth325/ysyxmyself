#include "Vysyx_24090012_NPC.h"
#include "verilated.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "verilated_vcd_c.h"  // 确保包含 Verilator VCD 支持头文件
#include "difftest_loader.h"  // 包含 DiffTest 加载的头文件
#include "isa.h" // 包含 CPU_state 的定义
#include "svdpi.h"

// 调用该函数来确保DPI上下文已设置
void set_dpi_context() {
    svScope scope = svGetScopeFromName("TOP.ysyx_24090012_NPC.regfile");
    if (scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope\n");
        exit(1);
    }
    svSetScope(scope);
}





//声明从 Verilog 导出的 DPI-C 函数
extern "C" void get_rf(uint32_t regs[32]);

// 定义简单的存储器，假设大小为 128MB（与 NEMU 一致）
#define MEM_SIZE (128 * 1024 * 1024)
uint8_t *memory = nullptr;



// 程序加载地址，与链接脚本中的 `_pmem_start` 一致
#define PROGRAM_START_ADDRESS 0x80000000
size_t program_size = 0;

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

#define MEM_BASE 0x80000000
#define MEM_SIZE (128 * 1024 * 1024)


uint32_t pmem_read(uint32_t addr) {
    if (addr >= MEM_BASE && addr < MEM_BASE + MEM_SIZE) {
        uint32_t offset = addr - MEM_BASE;
        uint32_t data = *(uint32_t *)(memory + offset);
        return data;
    } else {
        printf("Error: Accessing invalid memory address: 0x%08x\n", addr);
        exit(1);
    }
}


// 定义外部的 ebreak 函数，用于处理 ebreak 指令
extern "C" void ebreak(uint32_t exit_code) {
    if (exit_code == 0) {
        std::cout << "HIT GOOD TRAP" << std::endl;
    } else {
        std::cout << "HIT BAD TRAP with exit_code= " << exit_code << std::endl;
    }
    Verilated::gotFinish(true);  // 通知 Verilator 结束仿真
}

void get_dut_cpu_state(Vysyx_24090012_NPC *top, CPU_state *dut_cpu_state) {
    // 获取 PC
   set_dpi_context();
   printf("hua hua hua hua hua hua\n");
    dut_cpu_state->pc = top->pc;
    printf("pc=0x%08x\n",dut_cpu_state->pc);
    printf("pi pi pi pi pi pi\n");
    // 获取通用寄存器
    uint32_t regs[32];
    get_rf(regs);  // 调用 DPI-C 函数，获取寄存器文件内容
    printf("yue yue yue yue\n");;
    for (int i = 0; i < 32; i++) {
        printf("sun sun sun sun %d\n",i);
        printf("当前寄存器值：regs[%d] = 0x%08x\n", i, regs[i]);
        dut_cpu_state->gpr[i] = regs[i];
        printf("赋值后的 dut_cpu_state->gpr[%d] = 0x%08x\n", i, dut_cpu_state->gpr[i]);
    }
    printf("shu shu shu shu\n");
}

bool isa_difftest_checkregs(CPU_state *dut, CPU_state *ref) {
    // 比较通用寄存器
    for (int i = 0; i < 32; i++) {
        if (dut->gpr[i]!= ref->gpr[i]) {
            std::cerr << "Register x" << i << " mismatch: "
                      << "DUT = 0x" << std::hex << dut->gpr[i]
                      << ", REF = 0x" << ref->gpr[i] << std::dec << std::endl;
            return false;
        }
    }
    // 比较 PC
    if (dut->pc != ref->pc) {
        std::cerr << "PC mismatch: "
                  << "DUT = 0x" << std::hex << dut->pc
                  << ", REF = 0x" << ref->pc << std::dec << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    // 加载 DiffTest 库
    load_difftest_library();
    // 初始化顶层模块实例
    Vysyx_24090012_NPC *top = new Vysyx_24090012_NPC;
    // 创建 VCD 文件
    VerilatedVcdC *trace = new VerilatedVcdC;
    Verilated::traceEverOn(true);  // 启用追踪功能

    top->trace(trace, 99);  // 设置追踪深度
    trace->open("npc_trace.vcd");  // 打开 VCD 文件

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <program.bin>" << std::endl;
        return 1;
    }

    // 分配存储器
    memory = new uint8_t[MEM_SIZE];
    memset(memory, 0, MEM_SIZE);
    const char *program_path = argv[1];
    // 加载程序到存储器，并获取程序大小
    load_memory(program_path, program_size);
    // 将程序加载到参考模型的内存中
    difftest_memcpy(PROGRAM_START_ADDRESS, memory, program_size, 1);//true代表什么意思？？具体方向是什么 会不会是传递有误
    // 初始化参考模型的寄存器状态
    CPU_state cpu_state = {0};
    cpu_state.pc = PROGRAM_START_ADDRESS;
    difftest_regcpy(&cpu_state, true);

    // 复位处理器
    top->rst = 1;      // 设置复位信号为高
    top->clk = 0;      // 初始化时钟为低

    uint32_t reset_pc = PROGRAM_START_ADDRESS;
    uint32_t inst = pmem_read(reset_pc);
    top->mem_data = inst;

    // 保持复位高电平 5 个时钟周期
    for (int i = 0; i < 5; i++) {
        top->clk = 1;
        top->eval();
        trace->dump(Verilated::time());
        Verilated::timeInc(1);

        top->clk = 0;
        top->eval();
        trace->dump(Verilated::time());
        Verilated::timeInc(1);
    }

    // 释放复位
    top->rst = 0;
    top->eval();

    uint32_t prev_pc = PROGRAM_START_ADDRESS;

    // 主仿真循环
    while (!Verilated::gotFinish()) {
        // 读取当前 PC
        uint32_t current_pc = top->pc;

        // 在时钟上升沿前更新 mem_data
        if (prev_pc >= PROGRAM_START_ADDRESS && prev_pc < PROGRAM_START_ADDRESS + MEM_SIZE) {
            uint32_t inst = pmem_read(prev_pc);
            top->mem_data = inst;
            std::cout << "Current time: " << Verilated::time() << "     PC: 0x" << std::hex << prev_pc << std::dec << std::endl;
            std::cout << "Fetched Instruction: 0x" << std::hex << inst << std::dec << std::endl;
        } else {
            std::cerr << "Error: PC out of bounds: 0x" << std::hex << prev_pc << std::dec << std::endl;
            exit(1);
        }

        prev_pc = current_pc;  // 更新 prev_pc

        // 时钟上升沿
        top->clk = 1;
        top->eval();
        trace->dump(Verilated::time());
        Verilated::timeInc(1);

        // 检查 ebreak_flag
        if (top->ebreak_flag) {
            std::cout << "Encountered ebreak_flag. Exiting simulation." << std::endl;
            break;
        }

        // 时钟下降沿
        top->clk = 0;
        top->eval();
        trace->dump(Verilated::time());
        Verilated::timeInc(1);
           
        // 执行参考模型
        difftest_exec(1);

        // 获取 DUT CPU 状态
        CPU_state dut_cpu_state;
        get_dut_cpu_state(top, &dut_cpu_state);
         printf("shen shen shen\n");
        // 获取参考模型的 CPU 状态
        CPU_state ref_cpu_state;
        printf("zhang zhang zhang\n");
        difftest_regcpy(&ref_cpu_state, false);
         printf("wei wei wei wei\n");
        // 比较 CPU 状态
        if (!isa_difftest_checkregs(&dut_cpu_state, &ref_cpu_state)) {
            std::cerr << "Difftest failed at PC = 0x" << std::hex << dut_cpu_state.pc << std::dec << std::endl;
            exit(1);
        }
    }

    // 释放资源
    top->final();            // 完成仿真
    delete top;              // 删除顶层模块实例
    delete[] memory;         // 释放内存
    trace->close();  // 关闭 VCD 文件

    return 0;
}
