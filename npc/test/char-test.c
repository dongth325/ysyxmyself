#define UART_BASE 0x10000000    // UART设备基地址
#define UART_TX   0x00          // 发送寄存器偏移

void _start() {
  *(volatile char *)(UART_BASE + UART_TX) = 'A';
  //*(volatile char *)(UART_BASE + UART_TX) = '\n';
  while (1);
}