#include "soc-ioe.h"
#include "amdev.h"
#include "klib-macros.h"

#define CLINT_ADDR 0x02000000

void __am_timer_uptime(AM_TIMER_UPTIME_T *buf) {
    volatile const uint32_t *clint = (volatile const uint32_t*)CLINT_ADDR;
    
    uint32_t mtime_low = clint[0];
    uint32_t mtime_hig = clint[1];
    
    uint64_t cycs = ((uint64_t)mtime_hig << 32) | mtime_low;
    buf->us = cycs;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour = 0;
  rtc->day = 0;
  rtc->month = 0;
  rtc->year = 1900;
} 