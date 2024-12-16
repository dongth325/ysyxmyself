/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
    if (direction == DIFFTEST_TO_DUT) { // 当方向为 DIFFTEST_TO_DUT，表示从参考模型 (REF) 复制到 DUT
   
    buf = (void *)guest_to_host(addr);
  } 
  else if (direction == DIFFTEST_TO_REF) {// 当方向为 DIFFTEST_TO_REF，表示从 DUT 复制到参考模型 (REF)
    
    //Log("loglogloglog%x,%lx", addr, n); // 打印地址和大小

   
    char *buf_char = (char *)buf; // 将 buf 视为字节数组，逐字节复制
    for (size_t i = 0; i < n; i++) {
     
      paddr_write(addr + i, 1, buf_char[i]); // 将 DUT 的内存逐字节写入到参考模型
        //printf("Writing to REF address 0x%08x: value = 0x%02x  from void (difftest_memcpy)\n", (uint32_t)(addr + i), buf_char[i]);
    }
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
 
      if (direction == DIFFTEST_TO_DUT) {
    
    // 将参考模型 (REF) 的寄存器状态复制到 DUT
    for (int i = 0; i < 32; i++) {
      //printf("dong dong dong %d\n",i);
      ((CPU_state *)dut)->gpr[i] = cpu.gpr[i]; // 将每个通用寄存器从 REF 复制到 DUT
     // printf("REF->gpr[%d] = 0x%08x from (difftest_regcopy)\n",i,cpu.gpr[i]);
     // printf("ang ang ang ang %d\n",i);
    }
    ((CPU_state *)dut)->pc = cpu.pc; // 复制程序计数器 (PC)
      ((CPU_state *)dut)->csr.mcause = cpu.csr.mcause;
    ((CPU_state *)dut)->csr.mepc = cpu.csr.mepc;
    ((CPU_state *)dut)->csr.mstatus = cpu.csr.mstatus;
    ((CPU_state *)dut)->csr.mtvec = cpu.csr.mtvec;
    //printf("yang yang yang \n");
  } else if (direction == DIFFTEST_TO_REF) {
    //printf("yang yang yangwww \n");
    //printf("da da da da \n");
    // 将 DUT 的寄存器状态复制到参考模型 (REF)
    cpu = *(CPU_state *)dut; // 直接将整个 CPU 状态复制到参考模型
    
    //printf("sha sha sha sha\n");
  }


}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);  // 执行n条指令
}

__EXPORT void difftest_raise_intr(word_t NO) {
 // printf("zan shi bu shi xian");
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
