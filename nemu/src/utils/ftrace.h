#ifndef FTRACE_H
#define FTRACE_H

#include <stdint.h>
#include <elf.h>
#include <memory/paddr.h>

// 定义 Symbol 结构体
typedef struct {
    char name[64];
    paddr_t addr; // 函数头地址
    Elf32_Xword size;
} Symbol;

// 全局变量声明
extern Symbol *symbols; // 存储符号表
extern int symbol_count; // 符号数量

// 函数声明
void parse_elf(const char *elf_file);
void trace_function_call(paddr_t addr);
void trace_function_return(paddr_t addr);

#endif // FTRACE_H
