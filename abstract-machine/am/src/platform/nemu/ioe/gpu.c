#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg =
      (AM_GPU_CONFIG_T){.present = true,
                        .has_accel = false,
                        .width = inw(VGACTL_ADDR + 2),
                        .height = inw(VGACTL_ADDR),
                        .vmemsz = inw(VGACTL_ADDR + 2) * inw(VGACTL_ADDR) * 4};
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }

  int i, j;
  int idx = 0;
  int w = inw(VGACTL_ADDR + 2);

  for (i = ctl->y; i < ctl->y + ctl->h; i++) {
    for (j = ctl->x; j < ctl->x + ctl->w; j++) {
      outl(FB_ADDR + (i*w + j)*4, ((uint32_t *)ctl->pixels)[idx++] );
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }
