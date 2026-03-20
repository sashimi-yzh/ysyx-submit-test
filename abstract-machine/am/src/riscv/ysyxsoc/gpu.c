#include <am.h>
#include <klib-macros.h>
#include <klib.h>

#include "soc_devreg.h"

#define fb_as_u32 ((uint32_t *)VGA_FB_BEG)

static uint16_t gpu_w, gpu_h;

// addr bit [1:0] are ignored
// bit [19:10] are y
// bit [9:2] are x
//
#define AT_FB_ADDR(x, y) ((uint32_t*)(VGA_FB_BEG + (((y)<<10)|((x)<<2))))

void __am_gpu_init() {
  gpu_w = io_read(AM_GPU_CONFIG).width;
  gpu_h = io_read(AM_GPU_CONFIG).height;

	// for(int y=0;y<gpu_h;y++) {
	// 	// printf("init line %d\n", y);
	// 	for(int x=0;x<gpu_w;x++) {
	// 		AT_FB_ADDR(x,y)[0] = x<320?0x00ff0000:0x0000ff00;
	// 	}
	// }
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  gpu_h = 480;
  gpu_w = 640;
  *cfg = (AM_GPU_CONFIG_T){.present = true,
                           .has_accel = false,
                           .width = gpu_w,
                           .height = gpu_h,
                           .vmemsz = 0};
}
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
#define ADDR_ONE_ROW_OFFSET 1024

  uint32_t *row_beg = fb_as_u32 + ctl->y * ADDR_ONE_ROW_OFFSET + ctl->x;
  uint32_t *row_end = row_beg + ctl->h * ADDR_ONE_ROW_OFFSET;
  uint32_t *pix = ctl->pixels;
  while (row_beg != row_end) {
    // memcpy(row_beg, pix, ctl->w * sizeof(uint32_t));
		for (int i = 0; i < ctl->w; i++) {
			row_beg[i] = pix[i];
		}
    pix += ctl->w;
    row_beg += ADDR_ONE_ROW_OFFSET;
  }
  if (ctl->sync) {
    // 由于NVBoard提供的VGA机制是自动刷新的, 因此无需实现AM中的画面同步功能
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) { status->ready = true; }
