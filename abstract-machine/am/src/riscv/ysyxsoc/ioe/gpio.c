#include <am.h>
#include <ysyxsoc.h>

#define GPIO_OUT_ADDR GPIO_ADDR + 0x0
#define GPIO_IN_ADDR  GPIO_ADDR + 0x4
#define GPIO_SEG_ADDR GPIO_ADDR + 0x8

void __am_gpio_init() {
}

void __am_gpio_out(AM_GPIO_OUT_T *out) {
  outw(GPIO_OUT_ADDR, out->data);
}

void __am_gpio_in(AM_GPIO_IN_T *in) {
  in->data = inw(GPIO_IN_ADDR);
}

void __am_gpio_seg(AM_GPIO_SEG_T *out) {
  outl(GPIO_SEG_ADDR, out->data);
}
