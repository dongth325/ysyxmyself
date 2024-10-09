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
    if (direction == DIFFTEST_TO_REF) {
    // 将DUT的内存数据复制到REF
    printf("mmmmmmmmmmmmmmmmmmmmmmmmmm");//dddddddddddddddddd
    memcpy(guest_to_host(addr), buf, n);
  } else {
    // 将REF的内存数据复制到DUT
    printf("nnnnnnnnnnnnnnnnnnnnn");//dddddddddddddddddddd
    memcpy(buf, guest_to_host(addr), n);
  }
}

__EXPORT void difftest_regcpy(void *dut, bool direction) {
        printf("wwwwwwwwwwwwwwwwwwwwwwwww\n");//dddddddddddddddddddd
    if (direction == DIFFTEST_TO_REF) {
        // 将DUT的寄存器状态复制到参考模型(REF)
        printf("sssssssssssssssssssssss");//ddddddddddddddddddddddd
        memcpy(dut, &cpu, sizeof(CPU_state));
    } else {
        // 将参考模型(REF)的寄存器状态复制到DUT
        printf("pppppppppppppppppppp");//dddddddddddddddddddddddd
        memcpy(&cpu, dut, sizeof(CPU_state));
    }


}

__EXPORT void difftest_exec(uint64_t n) {
  cpu_exec(n);  // 执行n条指令
}

__EXPORT void difftest_raise_intr(word_t NO) {
  printf("zan shi bu shi xian");
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
  /* Perform ISA dependent initialization. */
  init_isa();
}
