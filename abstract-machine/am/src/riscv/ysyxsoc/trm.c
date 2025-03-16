#include <am.h>
#include <klib-macros.h>

extern char _heap_start;
extern char _heap_end;
int main(const char *args);


// 链接脚本中定义的符号
extern char _data_lma;          // 数据段在MROM中的位置
extern char _data_vma_start;    // 数据段在SRAM中的起始位置
extern char _data_vma_end;      // 数据段在SRAM中的结束位置
extern char _bss_start;         // BSS段起始位置
//extern char _bss_end;           // BSS段结束位置

void bootloader() {
  uint32_t *src = (uint32_t*)&_data_lma;// 按字复制保证对齐
  uint32_t *dst = (uint32_t*)&_data_vma_start;
  size_t words = (&_data_vma_end - &_data_vma_start) / 4;
  
  for (size_t i=0; i<words; i++) {
    dst[i] = src[i]; // 32位对齐访问
  }


}

//extern char _pmem_start;
//#define PMEM_SIZE (16 * 1024 * 1024)  // ysyxSoC的SRAM大小，16MB
//#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, &_heap_end);
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
    bootloader();
  int ret = main(mainargs);
  halt(ret);
}