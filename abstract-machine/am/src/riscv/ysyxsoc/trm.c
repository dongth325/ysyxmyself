#include <am.h>
#include <klib-macros.h>

extern char _heap_start;
extern char _heap_end;
int main(const char *args);


#define UART_REG_RBR 0x00  // 接收缓冲寄存器
#define UART_REG_THR 0x00  // 发送保持寄存器
#define UART_REG_DLL 0x00  // 除数锁存器低位 (DLAB=1)
#define UART_REG_DLM 0x01  // 除数锁存器高位 (DLAB=1)
#define UART_REG_LCR 0x03  // 线路控制寄存器
#define UART_REG_LSR 0x05  // 线路状态寄存器
#define UART_LSR_THRE 0x20 // 发送保持寄存器空标志位




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
static inline uint8_t inb(uintptr_t addr) { 
    return *(volatile uint8_t *)addr; 
}
#define UART_BASE     0x10000000  // ysyxSoC的UART设备基地址
#define UART_TX       0x00        // 发送寄存器偏移

// 初始化UART
void uart_init() {
    // 1. 设置DLAB位以访问除数锁存器
    //outb(UART_BASE + UART_REG_LCR, 0x10); // LCR[7] = 1
  // outb(UART_BASE + UART_REG_LCR, 0x20); // LCR[7] = 1
    outb(UART_BASE + UART_REG_LCR, 0x80); // LCR[7] = 1
    // 2. 设置波特率除数（示例值1，最高波特率）
    outb(UART_BASE + UART_REG_DLL, 0x01); // 除数低位
    outb(UART_BASE + UART_REG_DLM, 0x00); // 除数高位
    
    
    // 3. 配置数据格式：8位数据，1停止位，无校验，清除DLAB
    outb(UART_BASE + UART_REG_LCR, 0x03); // LCR = 0000 0011
    
    // 4. 可选：启用并重置FIFO
    // outb(UART_BASE + 2, 0x07); // FCR寄存器
}




void putch(char ch) {

    while ((inb(UART_BASE + UART_REG_LSR) & UART_LSR_THRE) == 0) {
        // 等待THRE位置1
    }
   outb(UART_BASE + UART_TX, ch);
}

void halt(int code) {
  asm volatile ("mv a0, %0" : : "r"(code));  // 将返回码移到a0寄存器
  asm volatile("ebreak");  // 触发ebreak指令
  
  while (1);
}

void _trm_init() {
  uart_init();
    bootloader();
    //uart_init();
  int ret = main(mainargs);
  halt(ret);
}