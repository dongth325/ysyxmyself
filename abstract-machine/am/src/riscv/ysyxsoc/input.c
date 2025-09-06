#include <am.h>

#define PS2_CTRL_BASE 0x10011000

// 自定义读取函数（inb: 读取8位字节）
static inline uint8_t inb(unsigned long addr) {
  return *(volatile uint8_t *)addr;
}

// 标准 PS/2 扫描码 (第二套) 到 AM 键盘码的映射表
static const uint16_t keymap[256] = {
  [0x1C] = AM_KEY_A, [0x32] = AM_KEY_B, [0x21] = AM_KEY_C, [0x23] = AM_KEY_D,
  [0x24] = AM_KEY_E, [0x2B] = AM_KEY_F, [0x34] = AM_KEY_G, [0x33] = AM_KEY_H,
  [0x43] = AM_KEY_I, [0x3B] = AM_KEY_J, [0x42] = AM_KEY_K, [0x4B] = AM_KEY_L,
  [0x3A] = AM_KEY_M, [0x31] = AM_KEY_N, [0x44] = AM_KEY_O, [0x4D] = AM_KEY_P,
  [0x15] = AM_KEY_Q, [0x2D] = AM_KEY_R, [0x1B] = AM_KEY_S, [0x2C] = AM_KEY_T,
  [0x3C] = AM_KEY_U, [0x2A] = AM_KEY_V, [0x1D] = AM_KEY_W, [0x22] = AM_KEY_X,
  [0x35] = AM_KEY_Y, [0x1A] = AM_KEY_Z,
  [0x45] = AM_KEY_0, [0x16] = AM_KEY_1, [0x1E] = AM_KEY_2, [0x26] = AM_KEY_3,
  [0x25] = AM_KEY_4, [0x2E] = AM_KEY_5, [0x36] = AM_KEY_6, [0x3D] = AM_KEY_7,
  [0x3E] = AM_KEY_8, [0x46] = AM_KEY_9,
  [0x0D] = AM_KEY_TAB, [0x29] = AM_KEY_SPACE, [0x4E] = AM_KEY_MINUS,
  [0x55] = AM_KEY_EQUALS, [0x54] = AM_KEY_LEFTBRACKET, [0x5B] = AM_KEY_RIGHTBRACKET,
  [0x5D] = AM_KEY_BACKSLASH, [0x4C] = AM_KEY_SEMICOLON, [0x52] = AM_KEY_APOSTROPHE,
  [0x0E] = AM_KEY_GRAVE, [0x41] = AM_KEY_COMMA, [0x49] = AM_KEY_PERIOD,
  [0x4A] = AM_KEY_SLASH, [0x58] = AM_KEY_CAPSLOCK,
  [0x76] = AM_KEY_ESCAPE, [0x66] = AM_KEY_BACKSPACE, [0x5A] = AM_KEY_RETURN,
  [0x12] = AM_KEY_LSHIFT, [0x59] = AM_KEY_RSHIFT,
  [0x14] = AM_KEY_LCTRL,  [0x11] = AM_KEY_LALT
};

// 扩展键 (以 0xE0 为前缀) 的映射表
static const uint16_t keymap_ext[256] = {
  [0x14] = AM_KEY_RCTRL, [0x11] = AM_KEY_RALT,
  [0x70] = AM_KEY_INSERT, [0x6C] = AM_KEY_HOME, [0x7D] = AM_KEY_PAGEUP,
  [0x71] = AM_KEY_DELETE, [0x69] = AM_KEY_END, [0x7A] = AM_KEY_PAGEDOWN,
  [0x75] = AM_KEY_UP, [0x6B] = AM_KEY_LEFT, [0x72] = AM_KEY_DOWN, [0x74] = AM_KEY_RIGHT
};

void __am_input_keybrd(AM_INPUT_KEYBRD_T *kbd) {
  static bool is_ext = false;
  static bool is_break = false;

  uint8_t scancode = inb(PS2_CTRL_BASE);

  if (scancode == 0) {
    kbd->keydown = false;
    kbd->keycode = AM_KEY_NONE;
    return;
  }
  
  // 检查并处理特殊码
  if (scancode == 0xE0) {
    is_ext = true;
    kbd->keydown = false;
    kbd->keycode = AM_KEY_NONE; // 等待下一个码
    return;
  } else if (scancode == 0xF0) {
    is_break = true;
    kbd->keydown = false;
    kbd->keycode = AM_KEY_NONE; // 等待下一个码
    return;
  }
  
  // 查找对应的AM键盘码
  uint16_t am_code;
  if (is_ext) {
    am_code = keymap_ext[scancode];
    is_ext = false; // 处理完扩展码后清除标志
  } else {
    am_code = keymap[scancode];
  }
  
  kbd->keydown = !is_break;
  kbd->keycode = am_code;

  // 处理完断开码后清除标志
  if (is_break) {
    is_break = false;
  }
}