#include <am.h>

// 函数声明（放在顶部，避免 implicit declaration 错误）
void __am_gpu_config(AM_GPU_CONFIG_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);

// 临时缓冲，像 NEMU 一样
static uint32_t color_buf[640 * 480];

#define FB_ADDR 0x21000000

void __am_gpu_init() {
  int w = 640;  // Fixed width，像 NEMU
  int h = 480;  // Fixed height，像 NEMU
  
  // 模仿 NEMU 用渐变颜色填充临时缓冲
  for (int i = 0; i < w * h; i++) {
    color_buf[i] = i;  // 每个像素使用不同的颜色值，像 NEMU
  }
  
  // 模仿 NEMU 的绘制方式写入 fb (全屏绘制)
  AM_GPU_FBDRAW_T ctl = {.x = 0, .y = 0, .w = w, .h = h, .pixels = color_buf, .sync = 1};
  __am_gpu_fbdraw(&ctl);  // 调用 fbdraw 进行实际写入
  
  // NVBoard 自动刷新，无需显式同步，但模仿 NEMU 添加注释
  // outl(SYNC_ADDR, 1);  // 在 ysyxsoc 无 SYNC_ADDR
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  // 模仿 NEMU 返回配置（固定 640x480）
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
  int screen_w = 640;  // 像 NEMU 的 screen_w
  int screen_h = 480;

  // 精确模仿 NEMU 的循环和索引：for i (rows) for j (columns) fb[screen_w*i + j] = pixels[w*i + j]
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int fb_x = x + j;
      int fb_y = y + i;  // 标准位置，如果需要翻转可调整
      if (fb_x >= 0 && fb_x < screen_w && fb_y >= 0 && fb_y < screen_h) {
        fb[fb_y * screen_w + fb_x] = pixels[w * i + j];  // 精确模仿 NEMU
      }
    }
  }
  // 模仿 NEMU 的 SYNC (在 ysyxsoc 无需，但添加虚拟)
  // outl(SYNC_ADDR, 1);  // 无 SYNC_ADDR，注释
}