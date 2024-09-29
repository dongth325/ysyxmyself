#include "Vysyx_24090012_NPC.h"
#include "verilated.h"
#include <iostream>
#include <fstream>
#include <cstring>

// 定义简单的存储器，假设大小为 128MB（与 NEMU 一致）
#define MEM_SIZE (128 * 1024 * 1024)
uint8_t *memory = nullptr;

// 程序加载地址，与链接脚本中的 `_pmem_start` 一致
#define PROGRAM_START_ADDRESS 0x80000000

// 存储器初始化函数，从文件加载程序
void load_memory(const char *program_path) {
    std::ifstream infile(program_path, std::ios::binary | std::ios::in);
    if (!infile) {
        std::cerr << "Cannot open program file: " << program_path << std::endl;
        exit(1);
    }

    infile.seekg(0, std::ios::end);
    size_t size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    if (size > MEM_SIZE) {
        std::cerr << "Program size (" << size << " bytes) exceeds memory size (" << MEM_SIZE << " bytes)." << std::endl;
        exit(1);
    }

    infile.read(reinterpret_cast<char *>(memory + PROGRAM_START_ADDRESS - 0x80000000), size);
    infile.close();

    std::cout << "Loaded program: " << program_path << ", size: " << size << " bytes." << std::endl;
}

// 模拟从存储器读取指令的函数
uint32_t pmem_read(uint32_t addr) {
    if (addr >= PROGRAM_START_ADDRESS && addr < PROGRAM_START_ADDRESS + MEM_SIZE) {
        uint32_t data = *(uint32_t *)(memory + addr - PROGRAM_START_ADDRESS);
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
        std::cout << "HIT BAD TRAP with code " << exit_code << std::endl;
    }
    // 您可以在这里输出更多统计信息
    Verilated::gotFinish(true);  // 通知 Verilator 结束仿真
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <program.bin>" << std::endl;
        return 1;
    }

    const char *program_path = argv[1];

    // 分配存储器
    memory = new uint8_t[MEM_SIZE];
    memset(memory, 0, MEM_SIZE);

    // 加载程序到存储器
    load_memory(program_path);

    // 初始化顶层模块实例
    Vysyx_24090012_NPC *top = new Vysyx_24090012_NPC;

    // 复位处理器
    top->rst = 1;
    top->clk = 0;
    top->eval();
    top->rst = 0;

    // 主仿真循环
    while (!Verilated::gotFinish()) {
        top->clk = !top->clk;  // 时钟翻转
        if (top->clk) {
            top->mem_data = pmem_read(top->pc);  // 从存储器取指并传递给 IFU 模块
            // 您可以根据需要添加更多日志输出
            // printf("PC: 0x%08x, Instruction: 0x%08x\n", top->pc, top->mem_data);
        }

        top->eval();  // 评估仿真

        if (top->ebreak_flag) {  // 如果检测到 ebreak 指令，则结束仿真
            break;
        }
    }

    // 释放资源
    top->final();
    delete top;
    delete[] memory;

    return 0;
}
