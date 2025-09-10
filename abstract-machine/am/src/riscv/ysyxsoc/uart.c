#include <am.h>

#define UART_BASE     0x10000000
#define UART_REG_RBR 0x00  // 接收缓冲寄存器
#define UART_REG_LSR 0x05  // 线路状态寄存器
#define UART_LSR_DR  0x01  // 数据就绪标志位

static inline uint8_t inb(uintptr_t addr) {
    return *(volatile uint8_t *)addr;
}

// 底层UART接收函数
void __am_uart_rx(AM_UART_RX_T *rx) {
    if ((inb(UART_BASE + UART_REG_LSR) & UART_LSR_DR)) {
      rx->data = inb(UART_BASE + UART_REG_RBR);
    } else {
      rx->data = -1;
    }
  }
