#include <am.h>
#include <riscv/riscv.h>
#include "../npc.h"

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = 3 * ((uint64_t)inl(RTC_ADDR + 4) << 32 | (uint64_t)inl(RTC_ADDR));
}

// #define SEC_ADDR TIME_ADDR
// #define MIN_ADDR (TIME_ADDR + 4u)
// #define HOUR_ADDR (TIME_ADDR + 8u)
// #define DAY_ADDR (TIME_ADDR + 12u)
// #define MON_ADDR (TIME_ADDR + 16u)
// #define YEAR_ADDR (TIME_ADDR + 20u)

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  // rtc->second = inl(SEC_ADDR);
  // rtc->minute = inl(MIN_ADDR);
  // rtc->hour   = inl(HOUR_ADDR);
  // rtc->day    = inl(DAY_ADDR);
  // rtc->month  = inl(MON_ADDR);
  // rtc->year   = inl(YEAR_ADDR);
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
