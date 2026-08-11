#include <am.h>

#include "include/npc.h"

static uint64_t boot_ticks;

static uint32_t read_mtime_low(void) {
  return *(volatile uint32_t *)(uintptr_t)YSYXSOC_MTIME_LOW_ADDR;
}

static uint32_t read_mtime_high(void) {
  return *(volatile uint32_t *)(uintptr_t)YSYXSOC_MTIME_HIGH_ADDR;
}

static uint64_t read_mtime(void) {
  uint32_t high_before;
  uint32_t low;
  uint32_t high_after;

  do {
    high_before = read_mtime_high();
    low = read_mtime_low();
    high_after = read_mtime_high();
  } while (high_before != high_after);

  return ((uint64_t)high_after << 32) | low;
}

void __am_timer_init(void) {
  boot_ticks = read_mtime();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = read_mtime() - boot_ticks;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour = 0;
  rtc->day = 1;
  rtc->month = 1;
  rtc->year = 2000;
}
