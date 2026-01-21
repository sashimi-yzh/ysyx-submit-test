#include <am.h>
#include <nemu.h>

#define NEMUSOC_RTC 0x02000000
void __am_timer_init() {
  outl(NEMUSOC_RTC, 0);        
  outl(NEMUSOC_RTC + 4, 0);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = inl(NEMUSOC_RTC + 4);
  uptime->us <<= 32;
  uptime->us += inl(NEMUSOC_RTC);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
