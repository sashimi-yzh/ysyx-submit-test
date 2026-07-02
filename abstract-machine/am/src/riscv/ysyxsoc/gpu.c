#include <am.h>
#include <klib.h>
#include "include/npc.h"

static int screen_w = 640;
static int screen_h = 480;

void __am_gpu_init() {
  screen_w = 640;
  screen_h = 480;
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = screen_w, .height = screen_h,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (!ctl->pixels || ctl->w <= 0 || ctl->h <= 0) {
    return;
  }

  int src_w = ctl->w;
  int src_h = ctl->h;
  int x = ctl->x;
  int y = ctl->y;

  int x0 = x < 0 ? 0 : x;
  int y0 = y < 0 ? 0 : y;
  int x1 = x + src_w;
  int y1 = y + src_h;

  if (x1 > screen_w) x1 = screen_w;
  if (y1 > screen_h) y1 = screen_h;

  int copy_w = x1 - x0;
  int copy_h = y1 - y0;
  if (copy_w <= 0 || copy_h <= 0) {
    return;
  }

  int src_x0 = x0 - x;
  int src_y0 = y0 - y;

  uint32_t *src = (uint32_t *)ctl->pixels + src_y0 * src_w + src_x0;
  uint32_t *dst_base = (uint32_t *)(uintptr_t)FB_ADDR;
  uint32_t *dst = dst_base + y0 * screen_w + x0;

  for (int j = 0; j < copy_h; j++) {
    for (int i = 0; i < copy_w; i++) {
      dst[i] = src[i];
    }
    src += src_w;
    dst += screen_w;
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
