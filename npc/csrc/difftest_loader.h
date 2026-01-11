#ifndef DIFFTEST_LOADER_H
#define DIFFTEST_LOADER_H

#include <dlfcn.h>
// 简化为标准包含方式
#include <isa-def.h>
#include <common.h>
#include <isa.h>
#include "VysyxSoCFull.h"



#include <memory/paddr.h>  // 如果你有物理地址相关的头文件，包含它
#include <cstddef>        // 包含 size_t 定义
#include <cstdbool>       // 包含 bool 定义


// 声明PC跟踪相关函数
extern "C" void init_pc_trace(const char* filename);
extern "C" void close_pc_trace();


typedef void (*difftest_memcpy_t)(paddr_t, void*, size_t, bool);
typedef void (*difftest_regcpy_t)(void*, bool);
typedef void (*difftest_exec_t)(uint64_t);

extern difftest_memcpy_t difftest_memcpy;
extern difftest_regcpy_t difftest_regcpy;
extern difftest_exec_t difftest_exec;


extern "C" void difftest_skip_ref();//add difftest skip
extern "C" void difftest_skip_dut(int nr_ref, int nr_dut);//add difftest skip
extern "C" void difftest_step(VysyxSoCFull *top,uint32_t pc, uint32_t npc);//add difftest skip



void load_difftest_library();
void get_dut_cpu_state(VysyxSoCFull *top, CPU_state *dut_cpu_state);
bool isa_difftest_checkregs(CPU_state *dut, CPU_state *ref);

#endif
