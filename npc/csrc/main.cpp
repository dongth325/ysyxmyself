#include "Vysyx_24090012_NPC.h"
#include "verilated.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "verilated_vcd_c.h"
#include "difftest_loader.h"
#include "isa.h"
#include "svdpi.h"

#define MEM_SIZE (128 * 1024 * 1024)
uint8_t *memory = nullptr;

#define PROGRAM_START_ADDRESS 0x80000000
size_t program_size = 0;
#define MEM_BASE 0x80000000

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
    if (addr >= MEM_BASE && addr < MEM_BASE + MEM_SIZE) {
        uint32_t offset = addr - MEM_BASE;
        *(uint32_t *)(memory + offset) = data;
        std::cout << "MTRACE: Write " << (int)mask << " bytes to 0x" << std::hex << addr 
                  << ", data = 0x" << std::hex << data << " from (pmem_write)" << std::dec << std::endl;
                  
                 
    } else {
        std::cerr << "Error: Attempt to write to invalid memory address: 0x from (extern \"C\" void pmem_write)\n"
                  << std::hex << addr << std::dec << std::endl;
        exit(1);
    }
}


extern "C"  uint32_t pmem_read(uint32_t addr) {
    if (addr >= MEM_BASE && addr < MEM_BASE + MEM_SIZE) {
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
    } else {
        std::cout << "HIT BAD TRAP with exit_code= " << exit_code << std::endl;
    }
    Verilated::gotFinish(true);  // 通知 Verilator 结束仿真
}


// 定义仿真状态结构体
struct NpcState {
    Vysyx_24090012_NPC *top;
    uint64_t inst_count;
    bool ebreak_encountered;
    uint32_t pc;
};

// 执行单条指令的函数（类似于 NEMU 的 exec_once）
void exec_once(NpcState *s) {
    // 从内存中获取指令
    uint32_t pc = s->pc;
    if (pc >= MEM_BASE && pc < MEM_BASE + MEM_SIZE) {
        uint32_t inst = pmem_read(pc);
        s->top->mem_data = inst;
    } else {
        std::cerr << "Error: PC out of bounds: 0x" << std::hex << pc << std::dec << std::endl;
        exit(1);
    }

    // 模拟一个时钟周期（上升沿和下降沿）
    s->top->clk = 1;
    s->top->eval();
    // 可在此添加跟踪代码
    s->top->clk = 0;
    s->top->eval();

    // 更新指令计数
    s->inst_count++;

    // 检查 ebreak 信号
    if (s->top->ebreak_flag) {
        s->ebreak_encountered = true;
    }

    // 更新 PC
    s->pc = s->top->pc;

    // 执行 DiffTest
    difftest_exec(1);

    // 获取 DUT 和 REF 的 CPU 状态
    CPU_state dut_cpu_state;
    get_dut_cpu_state(s->top, &dut_cpu_state);

    CPU_state ref_cpu_state;
    difftest_regcpy(&ref_cpu_state, false);

    // 比较 CPU 状态
    if (!isa_difftest_checkregs(&dut_cpu_state, &ref_cpu_state)) {
        std::cerr << "Difftest failed at PC = 0x" << std::hex << dut_cpu_state.pc << std::dec << std::endl;
        exit(1);
    }
}

// 执行多条指令的函数（类似于 NEMU 的 execute）
void execute(NpcState *s, uint64_t n) {
    for (uint64_t i = 0; i < n; i++) {
        exec_once(s);
        if (s->ebreak_encountered) {
            std::cout << "Encountered ebreak. Exiting simulation." << std::endl;
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

    const char *program_path = argv[1];

    // 初始化内存
    memory = new uint8_t[MEM_SIZE];
    memset(memory, 0, MEM_SIZE);

    // 加载程序到内存
    load_memory(program_path, program_size);

    // 初始化 Verilated 模型
    Vysyx_24090012_NPC *top = new Vysyx_24090012_NPC;

    // 初始化波形追踪
    VerilatedVcdC *trace = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    top->trace(trace, 99);
    trace->open("npc_trace.vcd");

    // 初始化 DiffTest
    load_difftest_library();
    difftest_memcpy(PROGRAM_START_ADDRESS, memory, program_size, true);

    CPU_state cpu_state = {0};
    cpu_state.pc = PROGRAM_START_ADDRESS;
    difftest_regcpy(&cpu_state, true);  // 初始化参考模型的 CPU 状态

    // 复位 DUT
    top->rst = 1;
    top->clk = 0;

    // 施加复位信号若干周期
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

    // 释放复位信号
    top->rst = 0;
    top->eval();

    // 初始化仿真状态
    NpcState npc_state;
    npc_state.top = top;
    npc_state.inst_count = 0;
    npc_state.ebreak_encountered = false;
    npc_state.pc = PROGRAM_START_ADDRESS;

    // 执行指令
    while (!Verilated::gotFinish() && !npc_state.ebreak_encountered) {
        exec_once(&npc_state);
    }

    // 完成仿真
    top->final();
    delete top;
    delete[] memory;
    trace->close();

    return 0;
}