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

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif





#ifdef CONFIG_MTRACE
#include <stdio.h>

void mtrace_read(paddr_t addr, int len, word_t data) {
   // printf("MTRACE: Read %d bytes from 0x%x, data = 0x%x from (void mtrace_read)\n", len, addr, data);
}

void mtrace_write(paddr_t addr, int len, word_t data) {
    //printf("MTRACE: Write %d bytes to 0x%x, data = 0x%x from (void mtrace_write)\n", len, addr, data);
}
#endif








uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

/*static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}*/     //npc difftest的时候nemu设备device不能开启 要把这一部分判定注释掉 才能跑diff

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
#ifdef CONFIG_MEM_RANDOM
  uint32_t *p = (uint32_t *)pmem;
  int i;
  for (i = 0; i < (int) (CONFIG_MSIZE / sizeof(p[0])); i ++) {
    p[i] = rand();
  }
#endif
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  word_t data;
  if (likely(in_pmem(addr))) {
    //printf("dt dt dt dt dt from (word_t paddr_read)\n");
    data = pmem_read(addr, len);
    //printf("th th th th th th from(word_t paddr_read)\n");
  } else {
   // printf("aaaaaaaaaa from (word_t paddr_read)\n");
    IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
   // printf("bbbbbbbbbbbbbbb from (word_t paddr_read)\n");
    //out_of_bound(addr);//npc difftest的时候nemu设备device不能开启 要把这一部分判定注释掉 才能跑diffdddddddddddddddddd
    //printf("cccccccccccccccc from (word_t paddr_read)\n");
    return 0;
  }
#ifdef CONFIG_MTRACE
  mtrace_read(addr, len, data);  // 调用 mtrace_read 记录读取操作
#endif
  return data;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
  } else {
    IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
    //out_of_bound(addr);//npc difftest的时候nemu设备device不能开启 要把这一部分判定注释掉 才能跑diffddddddddddddddddddd
    return;
  }
#ifdef CONFIG_MTRACE
  mtrace_write(addr, len, data);  // 调用 mtrace_write 记录写入操作
#endif
}

