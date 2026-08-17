#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <stdint.h>
#define N 64
const uint32_t colors[] = {0xffffff, 0xff0000, 0x00ff00, 0x0000ff,
                           0xffff00, 0xff00ff, 0x00ffff, 0xffffff};

void draw(uint32_t color) {
  static uint32_t color_buf[N * N];
  int w = io_read(AM_GPU_CONFIG).width / N;
  int h = io_read(AM_GPU_CONFIG).height / N;
  for (int i = 0; i < LENGTH(color_buf); i++) {
    color_buf[i] = color;
  }
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      io_write(AM_GPU_FBDRAW, x * N, y * N, color_buf, N, N, false);
    }
  }
}

int main() {
  ioe_init(); // initialization for GUI
  unsigned int cycle = 0;
  // unsigned long long last = 0;
  // unsigned long long fps = 2;
  while (1) {
    // unsigned long long upt = io_read(AM_TIMER_UPTIME).us;
    // if (upt - last > 1000000 / fps) {
    draw(colors[cycle]);
    cycle = (cycle + 1) % LENGTH(colors);
    //   last = upt;
    // }
    // AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
    // if (ev.keycode == AM_KEY_ESCAPE) {
    //   break;
    // } else if (ev.keydown) {
    //   fps = 16;
    // } else {
    //   fps = 2;
    // }
  }
  return 0;
}