#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

static int width, height;
uint32_t *fb;

void __am_gpu_init() {
  width = inw(VGACTL_ADDR+2);
  height = inw(VGACTL_ADDR);
  fb = (uint32_t *)(uintptr_t)FB_ADDR;
  //for (int i = 0; i < width * height; i ++) fb[i] = i;

  outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = inw(VGACTL_ADDR+2), .height = inw(VGACTL_ADDR),
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
  int begin =ctl->y * width + ctl->x;
  for(int row=0;row<ctl->h;row++){
    for(int col=0;col<ctl->w;col++){
      fb[begin + row * width + col] = ((uint32_t *)ctl->pixels)[row * ctl->w + col];
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
