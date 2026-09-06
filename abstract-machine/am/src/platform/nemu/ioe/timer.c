#include "amdev.h"
#include "klib-macros.h"
#include <am.h>
#include <nemu.h>
#include <stdint.h>
#include "klib.h"

void __am_timer_init() {}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uintptr_t rtcbase = (uintptr_t)RTC_ADDR;
  uint64_t uptimehgh = *((uint32_t *)rtcbase + 1);
  uint64_t uptimelow = *(uint32_t *)(rtcbase);
  uptime->us = (uptimehgh << 32) + uptimelow;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour = 0;
  rtc->day = 0;
  rtc->month = 0;
  rtc->year = 1900;
}
