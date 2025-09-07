#include <am.h>

#define FB_ADDR 0x21000000

void __am_gpu_init() {
  int w = 640;  // Fixed width
  int h = 480;  // Fixed height
  
  // 获取帧缓冲区地址
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;

  // 用不同颜色填充整个帧缓冲区（测试位置）
  for (int i = 0; i < h; i++) {  // 行循环先 (v_cnt)
    for (int j = 0; j < w; j++) {  // 列循环后 (h_cnt)
      fb[i * w + j] = (i * j);  // 渐变颜色以测试位置
    }
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
  int screen_h = 480;
  for (int i = 0; i < h; i++) {  // 行优先循环
    for (int j = 0; j < w; j++) {
      int fb_x = x + j;
      int fb_y = y + i;
      if (fb_x >= 0 && fb_x < screen_w && fb_y >= 0 && fb_y < screen_h) {
        fb[fb_y * screen_w + fb_x] = pixels[i * w + j];
      }
    }
  }
  // NVBoard自动刷新，无需sync
}