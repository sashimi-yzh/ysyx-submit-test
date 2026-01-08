#include <am.h>
//#include <riscv/riscv.h>
#include <stdio.h>

#define CLINK_ADDR      0x02000000  //ysyxSoC中CLINT地址：0x0200_0000~0x0200_ffff


#define CYCLES_PER_US 1 //Verilator 的仿真频率通常是 10 MHz 左右

static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }

static inline void outl(uintptr_t addr, uint32_t data) { *(volatile uint32_t *)addr = data; }

void __am_timer_init() {
	//outl(RTC_ADDR, 0); 
	//outl(RTC_ADDR + 4, 0); 
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
	//printf("am_timer_uptime");
	uint32_t low = inl(CLINK_ADDR);
	//printf("low:%d\n",low);
	uint32_t high = inl(CLINK_ADDR + 4);
	//printf("high:0x%x\n",high);
	//uptime->us = (uint64_t)low + (((uint64_t)high) << 32);
	uint64_t mtime = ((uint64_t)high << 32) | low;
	uptime->us = mtime / CYCLES_PER_US;
	//printf("uptime->us:%d\n",uptime->us);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
	rtc->second = 0;
	rtc->minute = 0;
	rtc->hour   = 0;
	rtc->day    = 0;
	rtc->month  = 0;
	rtc->year   = 1900;
	//printf("rtc->year:%d\n",rtc->year);
}
