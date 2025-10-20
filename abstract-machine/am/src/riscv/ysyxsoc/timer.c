#include <am.h>
#include "../riscv.h"
#include <stdio.h>

#define RTC_ADDR 0x02000000

static uint64_t start_time = 0;

static uint64_t get_time()
{
  uint32_t high = inl(RTC_ADDR + 4);
  uint32_t low = inl(RTC_ADDR);
  uint64_t time = ((uint64_t)high << 32) + low;
  return time;
}

void __am_timer_init() {
  start_time = get_time();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = (get_time() - start_time);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
