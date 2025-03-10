#include <am.h>
#include <klib-macros.h>

extern char _heap_start;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (16 * 1024 * 1024)  // ysyxSoC的SRAM大小，16MB
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;
static inline void outb(uintptr_t addr, uint8_t data) { *(volatile uint8_t *)addr = data; }
#define UART_BASE     0x10000000  // ysyxSoC的UART设备基地址
#define UART_TX       0x00        // 发送寄存器偏移

void putch(char ch) {
   outb(UART_BASE + UART_TX, ch);
}

void halt(int code) {
  asm volatile ("mv a0, %0" : : "r"(code));  // 将返回码移到a0寄存器
  asm volatile("ebreak");  // 触发ebreak指令
  
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}