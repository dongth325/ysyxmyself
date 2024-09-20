#include "Vysyx_24090012_NPC.h"       // Verilator 自动生成的顶层模块类
#include "verilated.h"  // Verilator 的核心头文件
#include <iostream>


// 定义简单的存储器
int memory[1024];

// 存储器初始化函数
void load_memory() {
    memory[0] = 0x00000293; // addi x5, x0, 0
    memory[1] = 0x00100313; // addi x6, x0, 1
    memory[2] = 0x005302b3; // add x5, x6, x5
    memory[3] = 0x00100073; // ebreak
}

// 模拟从存储器读取指令的函数
int pmem_read(int addr) {
    int index = (addr - 0x80000000) / 4;  // 将地址映射到 memory 数组的索引
    if (index >= 0 && index < 1024) {
        return memory[index];  // 4字节对齐的访问
    } else {
        printf("Error: Accessing invalid memory address: 0x%08x\n", addr);
        exit(1);  // 访问越界时退出程序
    }
}

extern "C" void ebreak() {
    std::cout << "ebreak detected, ending simulation." << std::endl;
    Verilated::gotFinish(true);  // 通知Verilator结束仿真
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    // 初始化顶层模块实例
    Vysyx_24090012_NPC *top = new Vysyx_24090012_NPC;

    // 初始化存储器
    load_memory();

    // 复位处理器
    top->rst = 1;
    top->clk = 0;
    top->eval();
    top->rst = 0;

    // 主仿真循环
    while (!Verilated::gotFinish()) {
        top->clk = !top->clk;  // 时钟翻转
        if (top->clk) {
            
           // printf("PC: 0x%08x, Instruction: 0x%08x\n", top->pc, top->mem_data);
            top->mem_data = pmem_read(top->pc);  // 从存储器取指并传递给 IFU 模块
            printf("PC: 0x%08x, Instruction: 0x%08x\n", top->pc, top->mem_data);
        }

        top->eval();  // 评估仿真

        if (top->ebreak_flag) {  // 如果检测到 ebreak 指令，则结束仿真
            break;
        }
    }

    // 释放资源
    top->final();
    delete top;

    return 0;
}
