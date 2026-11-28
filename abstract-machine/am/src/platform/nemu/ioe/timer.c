#include <am.h>
#include <nemu.h>
#include <stdio.h>
static uint64_t boot_time;
void __am_timer_init() {
  boot_time = inl(RTC_ADDR+4);
  boot_time = (boot_time << 32 | inl(RTC_ADDR));
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint64_t cur_time;
  cur_time = inl(RTC_ADDR+4);
  cur_time = (cur_time << 32 | inl(RTC_ADDR));
  uptime->us = cur_time - boot_time;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
