#include "riscv/riscv.h"
#include <am.h>
#include <klib.h>
#include <soc.h>
#include <stdint.h>
uint64_t rtc_start_us;
static uint64_t rtc_convert(uint32_t lower, uint32_t upper) {
  return (((uint64_t)upper << 32ull) | (uint64_t)lower) * 3;
}
void __am_timer_init() {

  uint32_t lower;
  uint32_t upper;
  do {
    lower = inl(RTC_ADDR);
    upper = inl(RTC_ADDR + 0x4);
  } while (upper != inl(RTC_ADDR + 0x4));
  rtc_start_us = rtc_convert(lower, upper);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t lower;
  uint32_t upper;
  do {
    lower = inl(RTC_ADDR);
    upper = inl(RTC_ADDR + 0x4);
  } while (upper != inl(RTC_ADDR + 0x4));
  uptime->us = rtc_convert(lower, upper) - rtc_start_us;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour = 0;
  rtc->day = 0;
  rtc->month = 0;
  rtc->year = 1900;
}
