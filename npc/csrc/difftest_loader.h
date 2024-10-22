#ifndef DIFFTEST_LOADER_H
#define DIFFTEST_LOADER_H

#include <dlfcn.h>
#include </home/dongtaiheng/desktopp/ffuck/ysyx-workbench/nemu/src/isa/riscv32/include/isa-def.h>
#include "/home/dongtaiheng/desktopp/ffuck/ysyx-workbench/nemu/include/common.h"
#include "Vysyx_24090012_NPC.h"


#include </home/dongtaiheng/desktopp/ffuck/ysyx-workbench/nemu/include/isa.h>        // 这个是定义与 ISA 相关的头文件
#include <memory/paddr.h>  // 如果你有物理地址相关的头文件，包含它
#include <cstddef>        // 包含 size_t 定义
#include <cstdbool>       // 包含 bool 定义




typedef void (*difftest_memcpy_t)(paddr_t, void*, size_t, bool);
typedef void (*difftest_regcpy_t)(void*, bool);
typedef void (*difftest_exec_t)(uint64_t);

extern difftest_memcpy_t difftest_memcpy;
extern difftest_regcpy_t difftest_regcpy;
extern difftest_exec_t difftest_exec;

void load_difftest_library();
void get_dut_cpu_state(Vysyx_24090012_NPC *top, CPU_state *dut_cpu_state);
bool isa_difftest_checkregs(CPU_state *dut, CPU_state *ref);

#endif
