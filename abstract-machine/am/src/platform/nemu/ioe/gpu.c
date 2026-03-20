#include <am.h>
#include <nemu.h>
#include <stdio.h>
#include <string.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

#define fb_as_u32 ((uint32_t *)(uintptr_t)FB_ADDR);

// AM假设系统在运行过程中, 屏幕大小不会发生变化.
static uint16_t gpu_w,gpu_h;

void __am_gpu_init() {
//  int i;
//
  gpu_w = io_read(AM_GPU_CONFIG).width;
  gpu_h = io_read(AM_GPU_CONFIG).height;
//  printf("get w=%d h=%d\n",w,h);
//  uint32_t* fb=fb_as_u32;
// 
//  for (i = 0; i < w * h; i ++) fb[i] = i;
//  outl(SYNC_ADDR, 1);
}


void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
	uint32_t packed_wh=inl(VGACTL_ADDR);
	gpu_h=packed_wh&0xffff;
	gpu_w=packed_wh>>16;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = gpu_w, .height = gpu_h,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
	//printf("__am_gpu_fbdraw called\n");
	//printf("gpu_w %d gpu_h %d\n",gpu_w,gpu_h);
	uint32_t* row_beg=fb_as_u32;
	row_beg+=ctl->y*gpu_w+ctl->x;
	uint32_t* row_end=row_beg+ctl->h*gpu_w;
	uint32_t* pix=ctl->pixels;
	while (row_beg!=row_end) {
		memcpy(row_beg, pix, ctl->w*sizeof(uint32_t));
		pix+=ctl->w;
		row_beg+=gpu_w;
	}
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
