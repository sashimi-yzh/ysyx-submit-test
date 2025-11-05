#include <am.h>
#include <riscv/riscv.h>
#include <stdio.h>

#define VGA_BASE 0x21000000
#define VGA_FB   (*(volatile uint32_t *)(VGA_BASE + 0))

#define SYNC_ADDR (VGACTL_ADDR + 4)

static int vga_h = 480;
static int vga_w = 640;

void __am_gpu_init() {

}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = vga_w, .height = vga_h,
    .vmemsz = 0
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if(ctl->w != 0 && ctl->h != 0){
    uint32_t *pixels = ctl->pixels;
    for(int i = ctl->y; i < ctl->y + ctl->h; i++){
      for(int j = ctl->x; j < ctl->x + ctl->w; j++){
        (&VGA_FB)[vga_w*i+j] = pixels[ctl->w*(i-ctl->y)+(j-ctl->x)];
      }
    }
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
