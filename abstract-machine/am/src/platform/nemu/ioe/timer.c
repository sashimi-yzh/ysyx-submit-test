#include <am.h>
#include <nemu.h>

void __am_timer_init() {
}

// AM系统启动时间, 可读出系统启动后的微秒数.
/**
 * 先读取的低32位会导致rtc_port_base没有更新，获取到的是上一次__am_timer_uptime得到的系统时间的低32位
 * 在nemu的/src/device/timer.c中的rtc_io_handler函数会有一个判断逻辑判断是否是读取时间操作，只有没有人进行写操作以及偏移为4时才会更新保存时间的rtc_port_base数组
 * 因为每一次读取时间都需要调用这个接口，所以只能估计当高32位或者低32位读的时候进行获取时间，否则高32位和低32位获取的时间可能不是一个值
 */
void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uint32_t high_part = inl(RTC_ADDR + 4);
  uint32_t low_part = inl(RTC_ADDR);
  uptime->us = ((uint64_t)high_part) << 32 | low_part;
}

//  AM实时时钟(RTC, Real Time Clock), 可读出当前的年月日时分秒.
void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
