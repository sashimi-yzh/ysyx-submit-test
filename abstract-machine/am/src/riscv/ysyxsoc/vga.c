#include <am.h>

#define FB_ADDR 0x21000000

void __am_gpu_init() {
//    int i;
//    uint32_t info=inl(VGACTL_ADDR);
//    int w=(info>>16);
//    int h=(info&0xffff);
//    uint32_t *fb=(uint32_t*)(uintptr_t)FB_ADDR;
//    for(i=0;i<w*h;i++)fb[i]=i;
//    outl(SYNC_ADDR,1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
    uint32_t w=640;
    uint32_t h=480;
    *cfg = (AM_GPU_CONFIG_T) {
        .present = true, .has_accel = false,
        .width = w, .height = h,
        .vmemsz = w*h*sizeof(uint32_t)
    };
}
//FB_ADDR
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
    int x=ctl->x,y=ctl->y,w=ctl->w,h=ctl->h;
    uint32_t screen_w=640;
    volatile uint32_t *fb=(volatile uint32_t*)(uintptr_t)FB_ADDR;
    uint32_t *pixels=(uint32_t*)ctl->pixels;
    
    int i,j;
    for(j=0;j<h;j++){
        for(i=0;i<w;i++){
            fb[(j+y)*screen_w+x+i]=pixels[j*w+i];
        }
    }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
    status->ready = true;
}
