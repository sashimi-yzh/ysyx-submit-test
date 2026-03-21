#include <ysyxsoc.h>

void __am_gpu_init() {
}


void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {

    int w = 640;
    int h = 480;

    *cfg = (AM_GPU_CONFIG_T) {
        .present = true, .has_accel = false,
        .width = w, .height = h,
        .vmemsz = w * h
    };
}

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {

    int width = 640;
    int height = 480;

    int x = ctl->x;;
    int y = ctl->y;
    int w = ctl->w;;
    int h = ctl->h;

    uint32_t *px = (uint32_t *)(uintptr_t)ctl->pixels;

    if(px != NULL) {
        
        if(x < 0 || y < 0 || x + w > width || y + h > height) {
            printf("GPU_FBD: Error! Region out of bounds: x=%d y=%d w=%d h=%d screen=%dx%d\n", ctl->x, ctl->y, ctl->w, ctl->h, width, height);
        }

        // for(int j=0; j<h; j++) {
        //     for(int i=0; i<w; i++) {
        //         uint32_t px_value = px[j * w + i];
        //         outl((uintptr_t)VGA_PORT + (y * width + x + j * width + i) * sizeof(uint32_t), px_value);
        //     }
        // }

        uint32_t *fb = (uint32_t *)(uintptr_t)VGA_PORT;
        for(int j=0; j<ctl->h; j++) {
            uint32_t *src = px + j * ctl->w;
            uint32_t *dst = fb + (ctl->y + j) * width + ctl->x;
            for(int i=0; i<ctl->w; i++) {
                dst[i] = src[i];
            }
        }
    }

}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
    status->ready = true;
}
