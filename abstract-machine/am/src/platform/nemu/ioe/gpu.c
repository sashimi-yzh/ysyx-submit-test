#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t screen_size = inl(VGACTL_ADDR);
  int width = screen_size >> 16;
  int height = screen_size & 0xffff;
  *cfg = (AM_GPU_CONFIG_T){.present = true,
                           .has_accel = false,
                           .width = width,
                           .height = height,
                           .vmemsz = width * height};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t screen_size = inl(VGACTL_ADDR);
  int width = screen_size >> 16;
  int height = screen_size & 0xffff;

  int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
  uint32_t *pixels = ctl->pixels;
  uint32_t fb_offset = (y * width + x) * sizeof(uint32_t);

  int boundary_w = ((x + w) <= width) ? x + w : width;
  int boundary_h = ((y + h) <= height) ? y + h : height;

  for (int i = y; i < boundary_h; i++) {
    uint32_t write_addr = FB_ADDR + fb_offset;
    for (int j = x; j < boundary_w; j++) {
      outl(write_addr, *pixels++);
      write_addr += sizeof(uint32_t);
    }
    fb_offset += width * sizeof(uint32_t);
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
