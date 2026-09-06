#ifndef SOC_IOE_H
#define SOC_IOE_H

#include "amdev.h"

// register addr and and the handler
#define UART_ADDR 0x10000008
#define INPUT_ADDR 0x10011000
#define VGA_ADDR 0x21000000

void __am_input_keybrd(AM_INPUT_KEYBRD_T *keybrd);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *fbdraw);
void __am_gpu_memcpy(AM_GPU_MEMCPY_T *memcpy);
void __am_timer_uptime(AM_TIMER_UPTIME_T *cfg);
void __am_timer_rtc(AM_TIMER_RTC_T *rtc);
#endif
