#include <am.h>
#include "../riscv.h"

#define DEV_TIMMER        (0xa0000048)

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) 
{
  uint64_t high = inl(DEV_TIMMER + 4);
  uint64_t low =  inl(DEV_TIMMER);
  uptime->us = (low | (high << 32));  
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
