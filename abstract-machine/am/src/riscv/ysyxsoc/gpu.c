#include <am.h>

// 函数声明（避免 implicit declaration）
void __am_gpu_config(AM_GPU_CONFIG_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);


// 模仿 NEMU 的 SYNC_ADDR (虚拟地址，无实际效果)
#define SYNC_ADDR 0x0

// 临时缓冲，像 NEMU 一样
static uint32_t color_buf[640 * 480];

#define FB_ADDR 0x21000000

void __am_gpu_init() {
  // 模仿 NEMU 读取屏幕大小（ysyxsoc 固定值）
  int w = 640;
  int h = 480;
  
  // 模仿 NEMU 用渐变颜色填充临时缓冲
  for (int i = 0; i < w * h; i++) {
    color_buf[i] = i;  // 每个像素使用不同的颜色值，像 NEMU
  }
  
  // 模仿 NEMU 的全屏绘制
  AM_GPU_FBDRAW_T ctl = {.x = 0, .y = 0, .w = w, .h = h, .pixels = color_buf, .sync = 1};
  __am_gpu_fbdraw(&ctl);
  

}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  // 模仿 NEMU 读取 screen_wh (用固定值模拟 inl)
  uint32_t screen_wh = (640 << 16) | 480;  // 模拟 inl(VGACTL_ADDR)
  uint32_t h = screen_wh & 0xffff;
  uint32_t w = screen_wh >> 16;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = 0  // 模仿 NEMU 返回 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  // 精确模仿 NEMU 的条件返回
  if (!ctl->sync && (ctl->w == 0 || ctl->h == 0)) return;
  
  uint32_t *pixels = ctl->pixels;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t screen_w = 640;  // 固定，像 NEMU 获取
  for (int i = ctl->y; i < ctl->y + ctl->h; i++) {
    for (int j = ctl->x; j < ctl->x + ctl->w; j++) {
      fb[screen_w * i + j] = pixels[ctl->w * (i - ctl->y) + (j - ctl->x)];  // 精确模仿 NEMU 索引
    }
  }

}



