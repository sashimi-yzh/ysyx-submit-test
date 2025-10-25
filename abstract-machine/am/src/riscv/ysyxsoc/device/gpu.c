#include <am.h>
#include <amdev.h>
#include <klib.h>

#include "device.h"

void __am_gpu_config(AM_GPU_CONFIG_T *cfg)
{
  *cfg = (AM_GPU_CONFIG_T) 
  {
    .present = true, .has_accel = false,
    .width = 0, .height = 0,
    .vmemsz = 0
  };
  cfg->width  = 640;
  cfg->height = 480;
  cfg->vmemsz = cfg->width * cfg->height; 
}


void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) 
{
    int i = 0, j = 0, k = 0;
    int w = 640;
    volatile uint32_t* fb = (volatile uint32_t*)(DEV_VGA);
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
}