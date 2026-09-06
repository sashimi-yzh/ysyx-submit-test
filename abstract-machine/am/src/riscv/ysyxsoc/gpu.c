#include "soc-ioe.h"
#include "klib.h"

void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *fbdraw) {
   volatile uint32_t *vga_addr = (volatile uint32_t *)VGA_ADDR;
   int x = fbdraw->x;
   int y = fbdraw->y;
   int w = fbdraw->w;
   int h = fbdraw->h;
   uint32_t *pis = fbdraw->pixels;

   // 先行后列
   for (int i = 0; i < h && (i + y) < 480 && (i + y) >= 0; i++) {
    for (int j = 0; j < w && (j + x) < 640 && (j + x) >= 0; j++) {
      int h_addr = j + x;
      int v_addr = i + y;
      uint32_t word_addr = (v_addr << 10) | h_addr;
      vga_addr[word_addr] = *(pis + i * w + j);
      // printf("%d -> %d, data: %x\n", i * w + j, (j + x) + (i + y) * 640, *(pis + i * w + j));
    }
   }
}

void __am_gpu_memcpy(AM_GPU_MEMCPY_T *memcpy) {
  uint32_t dest = memcpy->dest;
  void *src = memcpy->src;
  for (int i = 0; i < memcpy->size; i++) {
    *((uint32_t *)(VGA_ADDR) + dest)  = *(uint32_t *)(src);
    src++;
    dest++;
  }
}