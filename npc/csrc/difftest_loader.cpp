#include "difftest_loader.h"
#include <iostream>
#include "isa.h" // 包含 CPU_state 的定义
#include "Vysyx_24090012_NPC.h"
#include "svdpi.h"
difftest_memcpy_t difftest_memcpy = nullptr;
difftest_regcpy_t difftest_regcpy = nullptr;
difftest_exec_t difftest_exec = nullptr;

extern "C" int get_reg_value(int reg_index);

// 调用该函数来确保DPI上下文已设置
void set_dpi_context() {
    svScope scope = svGetScopeFromName("TOP.ysyx_24090012_NPC.regfile");
    if (scope == NULL) {
        fprintf(stderr, "Error: Unable to set DPI scope\n");
        exit(1);
    }
    svSetScope(scope);
}


void load_difftest_library() {
    void *handle = dlopen("/home/dongtaiheng/desktopp/ffuck/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed to load NEMU shared library: " << dlerror() << std::endl;
        exit(1);
    }

    difftest_memcpy = (difftest_memcpy_t)dlsym(handle, "difftest_memcpy");
    difftest_regcpy = (difftest_regcpy_t)dlsym(handle, "difftest_regcpy");
    difftest_exec = (difftest_exec_t)dlsym(handle, "difftest_exec");

    if (!difftest_memcpy || !difftest_regcpy || !difftest_exec) {
        std::cerr << "Failed to load DiffTest functions: " << dlerror() << std::endl;
        exit(1);
    }
}


void get_dut_cpu_state(Vysyx_24090012_NPC *top, CPU_state *dut_cpu_state) {
    // 获取 PC
   set_dpi_context();
   //printf("hua hua hua hua hua hua\n");
    dut_cpu_state->pc = top->pc;
   // printf("dut_cpu_state->pc=0x%08x from get_dut_cpu_state\n",dut_cpu_state->pc);
   // printf("pi pi pi pi pi pi\n");
    // 获取通用寄存器
    //uint32_t regs[32];
  // get_rf(regs);  // 调用 DPI-C 函数，获取寄存器文件内容
for(int i=0;i<32;i++){
int reg_value;
reg_value = get_reg_value(i);
dut_cpu_state->gpr[i]=get_reg_value(i);
printf("register DUT %d value: 0x%08x from (get_dut_cpu_state)\n", i,dut_cpu_state->gpr[i]);
   }
   // printf("yue yue yue yue\n");;
    for (int i = 0; i < 32; i++) {
       // printf("sun sun sun sun %d\n",i);
        //printf("当前寄存器值：regs[%d] = 0x%08x\n", i, regs[i]);
       // dut_cpu_state->gpr[i] = regs[i];
      // printf("赋值后的 dut_cpu_state->gpr[%d] = 0x%08x\n", i, dut_cpu_state->gpr[i]);
        //printf("赋值后的 dut_cpu_state->pc = 0x%08x\n", dut_cpu_state->pc);
    }
    //printf("shu shu shu shu\n");
}

bool isa_difftest_checkregs(CPU_state *dut, CPU_state *ref) {
    // 比较通用寄存器
  for (int i = 0; i < 32; i++) {
     // 比较 PC
    if (dut->pc != ref->pc) {
        std::cerr << "PC mismatch: "
                  << "DUT = 0x" << std::hex << dut->pc
                  << ", REF = 0x" << ref->pc << std::dec << std::endl;
        return false;
    }
    if (dut->gpr[i] != ref->gpr[i]) {
        std::cerr << "Register " << i << " mismatch: "
                  << "DUT = 0x" << std::hex << dut->gpr[i] 
                  << ", REF = 0x" << ref->gpr[i] << std::endl;
        return false;
    }
}
   
    return true;
}
