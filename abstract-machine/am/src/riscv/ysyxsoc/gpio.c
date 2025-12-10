#include <am.h>
#include "ysyxsoc.h"

void write_led(uint16_t data) {
  outw(GPIO_LED, data);
}

uint16_t read_sw() {
  return inw(GPIO_SW);
}

void write_seg(uint32_t data) {
  outl(GPIO_SEG, data);
}