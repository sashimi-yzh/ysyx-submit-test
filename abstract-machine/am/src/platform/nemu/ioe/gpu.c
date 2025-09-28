#include <am.h>
#include <nemu.h>
#include <klib.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

static int w, h;

void __am_gpu_init() {
  uint32_t conf = inl(VGACTL_ADDR);
  w = (conf >> 16) & 0xffff;
  h = conf & 0xffff;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = w * h * sizeof(uint32_t)
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t *p = ctl->pixels;
  for (int i = 0; i < ctl->h; ++i) {
    for (int j = 0; j < ctl->w; ++j) {
      fb[(ctl->y + i) * w + ctl->x + j] = *p++;
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_memcpy(AM_GPU_MEMCPY_T *ctl) {
  void *dst = (void *)(uintptr_t)(FB_ADDR + ctl->dest);
  memcpy(dst, ctl->src, ctl->size);
  outl(SYNC_ADDR, 1);
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
