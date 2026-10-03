#include <am.h>
#include "riscv/riscv.h"
#define  RTC_ADDR 0x0200bff8
void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
    uptime->us = ((uint64_t)inl(RTC_ADDR+4)<<32);
    uptime->us |= (uint64_t)inl(RTC_ADDR);
    uptime->us = uptime->us/3;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
