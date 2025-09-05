#include <am.h>

void __am_uart_rx(AM_UART_RX_T *rx);


/*void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  kbd->keydown = 0;
  kbd->keycode = AM_KEY_NONE;
}*/

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  AM_UART_RX_T rx;
  __am_uart_rx(&rx); // 调用底层UART驱动获取数据
  kbd->keydown = (rx.data != AM_KEY_NONE);
  kbd->keycode = rx.data;
}
//ysyxsoc和npc暂不实现键盘输入