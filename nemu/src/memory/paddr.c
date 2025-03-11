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



// 定义MROM和SRAM的基址和大小
#define MROM_BASE 0x20000000
#define MROM_SIZE (4 * 1024)  // 4KB
#define SRAM_BASE 0x0f000000
#define SRAM_SIZE (16 * 1024 * 1024) // 16MB





#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
static uint8_t *mrom = NULL;  // MROM内存区域  可能用不上
static uint8_t *sram = NULL;  // SRAM内存区域  可能用不上
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
static uint8_t mrom[MROM_SIZE] PG_ALIGN = {};  // MROM内存区域//dddddddd
static uint8_t sram[SRAM_SIZE] PG_ALIGN = {};  // SRAM内存区域dddddddd
#endif

// 检查地址是否在MROM范围内
static inline bool in_mrom(paddr_t addr) {//dddddddd
  return (addr >= MROM_BASE) && (addr < MROM_BASE + MROM_SIZE);
}

// 检查地址是否在SRAM范围内
static inline bool in_sram(paddr_t addr) {//dddddddd
  return (addr >= SRAM_BASE) && (addr < SRAM_BASE + SRAM_SIZE);
}



#ifdef CONFIG_MTRACE
#include <stdio.h>

void mtrace_read(paddr_t addr, int len, word_t data) {
    printf("MTRACE: Read %d bytes from 0x%x, data = 0x%x from (void mtrace_read)\n", len, addr, data);
}

void mtrace_write(paddr_t addr, int len, word_t data) {
    printf("MTRACE: Write %d bytes to 0x%x, data = 0x%x from (void mtrace_write)\n", len, addr, data);
}
#endif




// MROM地址转换函数
uint8_t* mrom_to_host(paddr_t paddr) { //dddddddddd
  return mrom + (paddr - MROM_BASE); 
}

// MROM地址转换函数 - 主机地址到物理地址
 paddr_t mrom_to_guest(uint8_t *haddr) { 
  return haddr - mrom + MROM_BASE; 
}
// SRAM地址转换函数
uint8_t* sram_to_host(paddr_t paddr) { 
  return sram + (paddr - SRAM_BASE); 
}

// SRAM地址转换函数 - 主机地址到物理地址
paddr_t sram_to_guest(uint8_t *haddr) { 
  return haddr - sram + SRAM_BASE; 
}//ddddddddd


// 通用的物理地址到主机地址转换函数
uint8_t* guest_to_host(paddr_t paddr) { //dddddddddd
  if (in_pmem(paddr)) return pmem + paddr - CONFIG_MBASE;
  if (in_mrom(paddr)) return mrom_to_host(paddr);
  if (in_sram(paddr)) return sram_to_host(paddr);
  return NULL;
}

// 通用的主机地址到物理地址转换函数
paddr_t host_to_guest(uint8_t *haddr) { //dddddddddd
  if (haddr >= pmem && haddr < pmem + CONFIG_MSIZE) 
    return haddr - pmem + CONFIG_MBASE;
  if (haddr >= mrom && haddr < mrom + MROM_SIZE)
    return mrom_to_guest(haddr);
  if (haddr >= sram && haddr < sram + SRAM_SIZE)
    return sram_to_guest(haddr);
  return 0;
}


//uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
//paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

// MROM读取函数
static word_t mrom_read(paddr_t addr, int len) {//dddddd
  uint8_t *host_addr = mrom_to_host(addr);
  word_t ret = host_read(host_addr, len);
  return ret;
}
// MROM写入函数 (只读，实际上不会写入)
static void mrom_write(paddr_t addr, int len, word_t data) {//ddddddd
   uint8_t *host_addr = mrom_to_host(addr);
  host_write(host_addr, len, data);
  Log("MROM write: address " FMT_PADDR ", data " FMT_WORD ", len %d", addr, data, len);
}
// SRAM读取函数
static word_t sram_read(paddr_t addr, int len) {//ddddddd
  uint8_t *host_addr = sram_to_host(addr);
  word_t ret = host_read(host_addr, len);
  return ret;
}

// SRAM写入函数
static void sram_write(paddr_t addr, int len, word_t data) {//ddddd
  uint8_t *host_addr = sram_to_host(addr);
  host_write(host_addr, len, data);
}


  static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);

        panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] "//dddddddddddddd
        "mrom [" FMT_PADDR ", " FMT_PADDR "] "
        "sram [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, PMEM_LEFT, PMEM_RIGHT, 
        MROM_BASE, MROM_BASE + MROM_SIZE - 1,
        SRAM_BASE, SRAM_BASE + SRAM_SIZE - 1, 
        cpu.pc);//ddddddd
}     

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
    mrom = malloc(MROM_SIZE);//dddddddddddddd
  assert(mrom);
  sram = malloc(SRAM_SIZE);
  assert(sram);//ddddddddddd
#endif
#ifdef CONFIG_MEM_RANDOM
  uint32_t *p = (uint32_t *)pmem;
  int i;
  for (i = 0; i < (int) (CONFIG_MSIZE / sizeof(p[0])); i ++) {
    p[i] = rand();
  }

    // 随机初始化MROM和SRAM
  p = (uint32_t *)mrom;//dddddddddddddddddddddddddd
  for (i = 0; i < (int) (MROM_SIZE / sizeof(p[0])); i ++) {
    p[i] = rand();
  }
  
  p = (uint32_t *)sram;
  for (i = 0; i < (int) (SRAM_SIZE / sizeof(p[0])); i ++) {
    p[i] = rand();
  }//ddddddddddd
#endif
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
  Log("MROM area [0x%x, 0x%x]", MROM_BASE, MROM_BASE + MROM_SIZE - 1);
  Log("SRAM area [0x%x, 0x%x]", SRAM_BASE, SRAM_BASE + SRAM_SIZE - 1);
}

word_t paddr_read(paddr_t addr, int len) {
  word_t data;
   if (likely(in_mrom(addr))) { return mrom_read(addr, len); }//ddddddddddddd
  if (likely(in_sram(addr))) { return sram_read(addr, len); }//dddddddddddd
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
   if (likely(in_mrom(addr))) { mrom_write(addr, len, data); return; }//ddddddddddddd
  if (likely(in_sram(addr))) { sram_write(addr, len, data); return; }//dddddddddddd
  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
  } else {
    IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
    out_of_bound(addr);
    return;
  }
#ifdef CONFIG_MTRACE
  mtrace_write(addr, len, data);  // 调用 mtrace_write 记录写入操作
#endif
}

