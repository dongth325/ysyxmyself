#include <am.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;
static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }//ddddddddddddddddddd
#define DEVICE_BASE     0xa0000000//ddddddddddddddddddddddd
#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)//dddddddddddddddddddddd

void putch(char ch) {
   outb(SERIAL_PORT, ch);
}

void halt(int code) {
  asm volatile ("mv a0, a0");  // 添加 'mv a0, a0' 指令
  asm volatile("ebreak");  // 触发 ebreak 指令ddddddddddddddddddddddddddddddd
  
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
