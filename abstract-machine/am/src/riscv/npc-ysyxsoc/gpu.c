#include <am.h>
#include "npc.h"
#include <stdint.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  uint32_t data_raw = inl(VGACTL_ADDR);
  int width = data_raw >> 16;
  int height = data_raw & ((1 << 16) - 1);
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = width, .height = height,
    .vmemsz = width * height * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  static int width = 0;
  if (width == 0) {
    width = inl(VGACTL_ADDR) >> 16;
  }
  uintptr_t first_col_addr = FB_ADDR + (ctl->y * width + ctl->x) * sizeof(uint32_t);
  uintptr_t addr;
  uint32_t *pixels = (uint32_t *)ctl->pixels;
  int i, j;
  for (i = 0; i < ctl->h; i++) {
    addr = first_col_addr;
    for (j = 0; j < ctl->w; j++) {
      outl(addr, *pixels++);
      addr += sizeof(uint32_t);
    }
    first_col_addr += width * sizeof(uint32_t);
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
