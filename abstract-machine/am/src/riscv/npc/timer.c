#include <am.h>
#include <riscv/riscv.h>

// #define DEVICE_BASE 0xa0000000
// #define RTC_ADDR  (DEVICE_BASE + 0x0000048)
#define RTC_ADDR  (0x02000000)

static uint64_t base_time = 0;
static uint64_t base_rtc = 0;

static uint64_t am_get_time() {
  uint32_t hi, lo;
  hi = inl(RTC_ADDR + 4);
  lo = inl(RTC_ADDR);
  return ((uint64_t)hi << 32) | lo;
}

void __am_timer_init() {
  base_time = am_get_time();
  base_rtc = 1672531200;
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint64_t now = am_get_time();
  uint64_t elapsed_seconds = (now - base_time) / 2;
  uptime->us = elapsed_seconds;// (μs)
  // uptime->us = now - base_time;// (μs)
}

static void convert_timestamp_to_calendar(uint64_t seconds, AM_TIMER_RTC_T *rtc) {
    // 简化计算：假设所有月份都是30天
    uint64_t secs = seconds;
    
    rtc->second = secs % 60;
    secs /= 60;
    rtc->minute = secs % 60;
    secs /= 60;
    rtc->hour   = secs % 24;
    secs /= 24;
    
    // 计算年份（从1970年开始）
    rtc->year = 1970 + secs / 365;
    secs %= 365;
    
    // 计算月份和日期
    rtc->month = secs / 30 + 1;
    secs %= 30;
    rtc->day = secs + 1;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
 uint64_t elapsed_seconds = (am_get_time() - base_time) / 2000000;
    uint64_t current_seconds = base_rtc + elapsed_seconds;
    
    // 转换为日历时间
    convert_timestamp_to_calendar(current_seconds, rtc);
//   time_t now = time(NULL);
//   struct tm *utc_time = gmtime(&now);
//   rtc->second = utc_time->tm_sec;
//   rtc->minute = utc_time->tm_min;
//   rtc->hour   = utc_time->tm_hour;
//   rtc->day    = utc_time->tm_mday;
//   rtc->month  = utc_time->tm_mon + 1;    // tm_mon 范围是 0-11
//   rtc->year   = utc_time->tm_year + 1900; // tm_year 是从 1900 开始的年数
}
