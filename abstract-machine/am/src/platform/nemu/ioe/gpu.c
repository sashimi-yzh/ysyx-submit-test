#include<am.h>
#include<nemu.h>
#include<stdint.h>
#include<stdio.h>
#include<string.h>
#define SYNC_ADDR (VGACTL_ADDR + 4)
static uint64_t last_sec = 1;   
static uint64_t frame_count = 0; 

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime);
static inline uint32_t mmio_read(uintptr_t addr) {
  return *(volatile uint32_t *)addr;
}

static inline uint32_t vgactl_read(){
  return *(volatile uint32_t *) (uintptr_t) VGACTL_ADDR;
}

static inline volatile uint32_t *fb_base(){
  return (volatile uint32_t *) (uintptr_t) FB_ADDR;
}

void __am_gpu_init(){
  uint32_t v=vgactl_read();
  int w=v>>16;
  int h=v&(0xffff);
  volatile uint32_t *fb=fb_base();
  for(int i=0;i<w*h;i++){
    fb[i]=0;
  }
  //*(volatile uint32_t*)(uintptr_t)SYNC_ADDR=1;
  outl(SYNC_ADDR,1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg){
  uint32_t v=vgactl_read();
  int w=v>>16;
  int h=v&(0xffff);
  *cfg = (AM_GPU_CONFIG_T){
    .present=true,
    .has_accel=false,
    .width=w,
    .height=h,
    .vmemsz=(size_t)w*(size_t)h*4
  };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl){
  uint32_t *fb=(uint32_t*)FB_ADDR;
  uint32_t v=vgactl_read();
  int screen_w=v>>16;
  uint32_t *pixels=(uint32_t*)ctl->pixels;
  for(int i=0;i<ctl->h;i++){
    for(int j=0;j<ctl->w;j++){
      int x=ctl->x+j;
      int y=ctl->y+i;
      fb[y*screen_w+x]=pixels[i*ctl->w+j];
    }
  }
  if(ctl->sync){
    outl(SYNC_ADDR,1);
    frame_count++; 
  }
  AM_TIMER_UPTIME_T uptime;
  __am_timer_uptime(&uptime);
  uint64_t current_sec = uptime.us / 1000000;
  if (current_sec >= last_sec) {
    printf("第%d秒 | FPS=%d\n", (int)current_sec, frame_count);
    frame_count = 0;
    last_sec = current_sec + 1; 
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
