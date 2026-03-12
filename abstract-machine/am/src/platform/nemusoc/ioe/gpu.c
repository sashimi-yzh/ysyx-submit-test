#include <am.h>
#include <nemusoc.h>
#include <klib.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}


void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
    uint32_t wh = inl(VGACTL_ADDR);

    int w = (int)(wh >> 16);
    int h = (int)(wh & 0xffff);

    *cfg = (AM_GPU_CONFIG_T) {
        .present = true, .has_accel = false,
        .width = w, .height = h,
        .vmemsz = w * h
    };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
    uint32_t wh = inl(VGACTL_ADDR);

    int width = (int)(wh >> 16);
    int height = (int)(wh & 0xffff);


    uint32_t *px = (uint32_t *)(uintptr_t)ctl->pixels;

    if(px != NULL) {
        
        if(ctl->x < 0 || ctl->y < 0 || ctl->x + ctl->w > width || ctl->y + ctl->h > height) {
            printf("GPU_FBD: Error! Region out of bounds: x=%d y=%d w=%d h=%d screen=%dx%d\n", ctl->x, ctl->y, ctl->w, ctl->h, width, height);
        }

/*
        uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
        for(int j=0; j<ctl->h; j++) {
            uint32_t *src = px + j * ctl->w;
            uint32_t *dst = fb + (ctl->y + j) * width + ctl->x;
            memcpy(dst, src, ctl->w * sizeof(uint32_t));
        }
*/
        

        for(int j=0; j<ctl->h; j++) {
            for(int i=0; i<ctl->w; i++) {
                uint32_t px_value = px[j * ctl->w + i];
                outl((uintptr_t)FB_ADDR + (ctl->y * width + ctl->x + j * width + i) * sizeof(uint32_t), px_value);
            }
        }


    }

    if (ctl->sync) {
        outl(SYNC_ADDR, 1);
    }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
    status->ready = true;
}
