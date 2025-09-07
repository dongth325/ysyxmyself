#include <am.h>

#define FB_ADDR 0x21000000

void __am_gpu_init() {
  int w = 640;  // Fixed width
  int h = 480;  // Fixed height
  
  // 获取帧缓冲区地址
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;

  // 用不同颜色填充整个帧缓冲区
  for (int i = 0; i < w * h; i++) {
    fb[i] = i;  // 每个像素使用不同的颜色值
  }
  
  // NVBoard自动刷新，无需显式同步
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = 640, .height = 480,
    .vmemsz = 640 * 480 * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  if (w == 0 || h == 0) return;
  uint32_t *pixels = ctl->pixels;
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  int screen_w = 640;
  for (int i = y; i < y + h; i++) {
    for (int j = x; j < x + w; j++) {
      if (i < 480 && j < screen_w) {
        fb[i * screen_w + j] = pixels[(i - y) * w + (j - x)];
      }
    }
  }
  // NVBoard自动刷新，无需sync
}