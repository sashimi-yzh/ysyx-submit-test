#include <am.h>
//#include <riscv/riscv.h>
#include <stdio.h>

#define DEVICE_BASE 0xa0000000
#define MMIO_BASE 0xa0000000
#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)
#define RTC_ADDR        (DEVICE_BASE + 0x0000048)
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)
#define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)
#define DISK_ADDR       (DEVICE_BASE + 0x0000300)
#define FB_ADDR         (MMIO_BASE   + 0x1000000)
#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)

#define CLINK_ADDR      0x02000000  //npc中CLINT地址：0x0200_0000~0x0200_ffff

#define CYCLES_PER_US 5 //Verilator 的仿真频率通常是 10 MHz 左右

static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }

static inline void outl(uintptr_t addr, uint32_t data) { *(volatile uint32_t *)addr = data; }

void __am_timer_init() {
	//outl(RTC_ADDR, 0); 
	//outl(RTC_ADDR + 4, 0); 
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime) {
	//uint32_t low = inl(RTC_ADDR);
	uint32_t low = inl(CLINK_ADDR);
	//printf("low:%d\n",low);
	//uint32_t high = inl(RTC_ADDR + 4);
	uint32_t high = inl(CLINK_ADDR + 4);
	//printf("high:0x%x\n",high);
	//uptime->us = (uint64_t)low + (((uint64_t)high) << 32);
	uint64_t mtime = ((uint64_t)high << 32) | low;
	// #ifdef ARCH_SIM_IVERILOGC_NETLIST
	// 	uptime->us = mtime * 200;
	// #elif defined(ARCH_SIM_IVERILOGC)
	// 	uptime->us = mtime * 20;
	// #else
	// 	uptime->us = mtime / CYCLES_PER_US;
	// #endif
	uptime->us = mtime;
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc) {
	rtc->second = 0;
	rtc->minute = 0;
	rtc->hour   = 0;
	rtc->day    = 0;
	rtc->month  = 0;
	rtc->year   = 1900;
}
