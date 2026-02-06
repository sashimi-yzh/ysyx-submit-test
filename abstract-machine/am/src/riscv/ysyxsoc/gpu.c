#include <am.h>
#include <riscv/riscv.h>


#define FB_ADDR             0x21000000
#define VGACTL_ADDR         0x211FFFF0
#define SYNC_ADDR           (VGACTL_ADDR + 4)

uint32_t w = 640;
uint32_t h = 480;
void __am_gpu_init() {
  
//   int i;
// //   uint32_t vga_config = inl(VGACTL_ADDR);
// //   int w = (vga_config >>  16 );
// //   int h = (vga_config & 0xffff );
//   uint32_t *fb = (uint32_t *)(FB_ADDR) ;
//   for (i = 0; i < w * h; i ++) fb[i] = 0;
//   outl(SYNC_ADDR, 1);
  
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
//   uint32_t vga = inl(VGACTL_ADDR);
//   uint32_t w = vga >> 16;
//   uint32_t h = vga & 0xffff;
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = w, .height = h,
    .vmemsz = w * h * sizeof(uint32_t),
  };
}
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {

//   uint32_t vga_config = inl(VGACTL_ADDR);
//   uint32_t WIDTH = (vga_config >> 16 );

  uint32_t *addr = (uint32_t *)(FB_ADDR) ;
  uint32_t *pixel = (uint32_t *)ctl->pixels;
  if (ctl->sync) {
    outl(SYNC_ADDR, 1);
  }else{
    outl(SYNC_ADDR, 0);
  }
  if(ctl->w==0 || ctl->h==0) return;
  for ( int j = 0; j < ctl->h ; j++) {
    for ( int i = 0; i < ctl->w ; i++) {
      *(addr + w*(ctl->y+j) + ctl->x + i ) = *(pixel + j*ctl->w + i) ;
    }
  }


}



void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
