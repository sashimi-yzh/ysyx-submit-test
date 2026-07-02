#include <am.h>
#include "include/npc.h"

static uint64_t boot_mtime = 0;

#if (NPC_CPU_FREQ_HZ % 1000000ull) != 0
#error "NPC_CPU_FREQ_HZ must be divisible by 1,000,000"
#endif

static uint64_t read_rtc_us() {
  uint32_t hi1, hi2, lo;
  do {
    hi1 = inl(RTC_ADDR + 4);
    lo = inl(RTC_ADDR);
    hi2 = inl(RTC_ADDR + 4);
  } while (hi1 != hi2);

  return ((uint64_t)hi2 << 32) | lo;
}

static uint64_t read_mtime() {
  uint32_t hi1, hi2, lo;
  do {
    hi1 = inl(CLINT_MTIMEH);
    lo = inl(CLINT_MTIME);
    hi2 = inl(CLINT_MTIMEH);
  } while (hi1 != hi2);

  return ((uint64_t)hi2 << 32) | lo;
}

static int is_leap_year(int year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

static int days_in_month(int year, int month) {
  static const int mdays[12] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
  };
  if (month == 2 && is_leap_year(year)) return 29;
  return mdays[month - 1];
}

// Convert Unix epoch seconds to UTC calendar date/time.
static void epoch_to_utc(uint64_t sec, AM_TIMER_RTC_T *rtc) {
  uint64_t days = sec / 86400;
  uint64_t rem  = sec % 86400;

  rtc->hour   = rem / 3600;
  rem        %= 3600;
  rtc->minute = rem / 60;
  rtc->second = rem % 60;

  int year = 1970;
  while (1) {
    int diy = is_leap_year(year) ? 366 : 365;
    if (days < (uint64_t)diy) break;
    days -= diy;
    year++;
  }

  int month = 1;
  while (1) {
    int dim = days_in_month(year, month);
    if (days < (uint64_t)dim) break;
    days -= dim;
    month++;
  }

  rtc->year = year;
  rtc->month = month;
  rtc->day = (int)days + 1;
}

void __am_timer_init() {
  boot_mtime = read_mtime();
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint64_t now_mtime = read_mtime();
  uptime->us = (now_mtime - boot_mtime) / NPC_CLINT_CYCLES_PER_US;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  epoch_to_utc(read_rtc_us() / 1000000, rtc);
}
