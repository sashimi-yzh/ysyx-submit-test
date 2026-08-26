#ifndef __DEVICES_H__
#define __DEVICES_H__
#include "common.h"
#define DEVICE_BASE 0x10000000

#define CONFIG_SERIAL_MMIO (DEVICE_BASE + 0x00000000)
#define CONFIG_SERIAL_MMIO_SIZE 4

#define CONFIG_RTC_MMIO (DEVICE_BASE + 0x00000048)
#define CONFIG_RTC_MMIO_SIZE 8

#define CONFIG_MMIO_MAX 16

typedef uint32_t(*io_callback_t)(uint32_t, uint32_t, int, bool);

typedef struct {
  const char *name;
  uint32_t low;
  uint32_t high;
  io_callback_t callback;
} IOSpace;

uint64_t get_time();
void init_rtc();
void init_serial();
void add_mmio_space(const char *name, uint32_t addr, uint32_t size, io_callback_t callback);
const char *get_device_name(uint32_t addr);
bool read_devices(uint32_t addr, uint32_t*data);
bool write_devices(uint32_t addr, uint32_t data);
#endif