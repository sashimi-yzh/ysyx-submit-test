#include <am.h>
#include <nemu.h>

static uint64_t base_time = 0;

static uint64_t am_get_time() {
   inl(RTC_ADDR + 4); // clear pending interrupts
  uint32_t hi, lo;
  lo = inl(RTC_ADDR);
  hi = inl(RTC_ADDR + 4);
  return ((uint64_t)hi << 32) | lo;
}


void __am_timer_init() {
  base_time = am_get_time();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {

  uint64_t now = am_get_time();
  uptime->us = now - base_time;// (μs)
  
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
