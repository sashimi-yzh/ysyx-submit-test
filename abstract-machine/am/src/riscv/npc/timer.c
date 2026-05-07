#include <am.h>

# define DEVICE_BASE 0x02000000
#define RTC_ADDR        (DEVICE_BASE + 0x0000048)
static inline uint8_t  inb(uintptr_t addr) { return *(volatile uint8_t  *)addr; }
static inline uint16_t inw(uintptr_t addr) { return *(volatile uint16_t *)addr; }
static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }

static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }
static inline void outw(uintptr_t addr, uint16_t data) { *(volatile uint16_t *)addr = data; }
static inline void outl(uintptr_t addr, uint32_t data) { *(volatile uint32_t *)addr = data; }

uint64_t start_time;
void __am_timer_init() {
  start_time = inl(RTC_ADDR+4);
  start_time = start_time << 32;
  start_time = start_time + inl(RTC_ADDR);
  ///outl(RTC_ADDR,0);
  //outl(RTC_ADDR+4,0);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
  uptime->us = inl(RTC_ADDR+4);
  uptime->us = uptime->us << 32;
  uptime->us = uptime->us + inl(RTC_ADDR);
  uptime->us = uptime->us - start_time;
  //uptime->us = 0;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
