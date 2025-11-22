#include <am.h>
#include <nemu.h>
#include "../../../riscv/riscv.h"
void __am_timer_init() {
  outl(RTC_ADDR,0);//将计时器的低 32 位和高 32 位清零
  outl(RTC_ADDR + 4,0);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = (uint64_t)inl(RTC_ADDR+4);//使用inl函数从RTC_ADDR和RTC_ADDR + 4读取计时器的低 32 位和高 32 位
  uptime->us <<= 32;
  uptime->us += (uint64_t)inl(RTC_ADDR);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
//先更新低32位，再更新高32位；读取时先读取高32位，再读取低32位；
//这样可以避免在更新过程中出现读取到不完整数据的情况。
//避免“旧高32位 + 新低32位”或“新高32位 + 旧低32位”的情况