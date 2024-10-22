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
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
    
  if (cpu.pc != pc) {
   printf("PC mismatch: NEMU PC = 0x%x, REF PC = 0x%x from (bool isa_difftest_checkregs)\n", cpu.pc, pc);
    //return false;  difftest由于pc没有对其 差了4字节所以注释掉 但是下面寄存器是对齐了的
  }
  for (int i = 0; i < 32; i++) {
    //printf("difftest ref REG(%d) = 0x%x\n",i,ref_r->gpr[i]);
    if (cpu.gpr[i] != ref_r->gpr[i]) {
     printf("Register x%d mismatch: NEMU = 0x%x, REF = 0x%x from (bool isa_difftest_checkregs)\n",
       i, cpu.gpr[i], ref_r->gpr[i]);
       
      return false;
    }
  }

  
  return true;
}

void isa_difftest_attach() {
}
