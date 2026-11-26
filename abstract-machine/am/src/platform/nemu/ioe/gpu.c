#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t vgactl = inl(VGACTL_ADDR);
  uint32_t width = vgactl >> 16;  // 高16位是宽度
  uint32_t height = vgactl & 0xFFFF;  // 低16位是高度
  
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width, .height = height,
    .vmemsz = width * height * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t *pixels = (uint32_t *)ctl->pixels;
  
  // 获取屏幕宽度
  AM_GPU_CONFIG_T cfg;
  __am_gpu_config(&cfg);
  int screen_w = cfg.width;
  
  // 将像素数据写入帧缓冲
  for (int j = 0; j < ctl->h; j++) {
    for (int i = 0; i < ctl->w; i++) {
      int screen_idx = (ctl->y + j) * screen_w + (ctl->x + i);
      int pixel_idx = j * ctl->w + i;
      fb[screen_idx] = pixels[pixel_idx];
    }
  }
  
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
