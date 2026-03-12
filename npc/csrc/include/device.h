#ifndef __DEVICE_H__
#define __DEVICE_H__


#define SERIAL_MMIO     0x10000000
#define RTC_MMIO        0x02000000

uint64_t get_time();
uint64_t get_time_internal();
extern uint64_t boot_time;

#endif