#include <am.h>
#include <riscv/riscv.h>
#include <ysyxsoc.h>


void __am_gpio_led_rd(AM_GPIO_LED_RD_T *led_rd) {
	led_rd -> data = inw(GPIO_LED);
}


void __am_gpio_led_wr(AM_GPIO_LED_WR_T *led_wr){
	outw(GPIO_LED, led_wr -> data);
}


void __am_gpio_switch(AM_GPIO_SWITCH_T *_switch){
	_switch -> data = inw(GPIO_SWITCH);
}

void __am_gpio_seg_rd(AM_GPIO_SEG_RD_T *seg_rd){
	seg_rd -> data = inl(GPIO_SEG);
}

void __am_gpio_seg_wr(AM_GPIO_SEG_WR_T *seg_wr){
	outl(GPIO_SEG, seg_wr -> data);
}

