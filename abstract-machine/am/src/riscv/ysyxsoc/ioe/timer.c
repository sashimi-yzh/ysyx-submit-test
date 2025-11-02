#include <am.h>
#include <riscv/riscv.h>
#include <ysyxsoc.h>

//#define RATIO_PARAM	 *4/5
//用于将从模拟CLINT寄存器中读到的值转化为真实时间,适用于FAST_FLASH

#define RATIO_PARAM	 *4/11
//适用于XIP(非FAST_FLASH),其实和FAST_FLASH的系数一样,因为仿真时cpu主时钟频率相同

void __am_timer_init() {
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
    uint32_t us_high = inl(CLINT_BASE + 4); // 0xa000004c,offset=4
    uint32_t us_low = inl(CLINT_BASE);

    //uptime->us = ((uint64_t)us_high) << 32 | us_low;
    uptime->us = (((uint64_t)us_high) << 32 | us_low) RATIO_PARAM;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
  rtc->second = 0;
  rtc->minute = 0;
  rtc->hour   = 0;
  rtc->day    = 0;
  rtc->month  = 0;
  rtc->year   = 1900;
}
