#include "klib.h"
#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)


void __am_gpu_init() 
{
  int w = inw(VGACTL_ADDR + 2);
  int h = inw(VGACTL_ADDR);
  printf("w:%d  h:%d\n", w, h);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
  *cfg = (AM_GPU_CONFIG_T) 
  {
    .present = true, .has_accel = false,
    .width = 0, .height = 0,
    .vmemsz = 0
  };
  cfg->width = inw(VGACTL_ADDR + 2);
  cfg->height = inw(VGACTL_ADDR);
  cfg->vmemsz = cfg->width * cfg->height;
}


void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) 
{
  int i = 0, j = 0, k = 0;
  int w = inw(VGACTL_ADDR + 2);
  uint32_t* fb = (uint32_t*)(uintptr_t)FB_ADDR;
  uint32_t* px = (uint32_t*)ctl->pixels;

  int mx = ctl->x + ctl->w;
  int my = ctl->y + ctl->h;

  for (i = ctl->y; i < my; i++)
  {
    for (j = ctl->x; j < mx; j++)
    {
      fb[i * w + j] = px[k++];
    }
  }
  
  if (ctl->sync) 
  { 
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
