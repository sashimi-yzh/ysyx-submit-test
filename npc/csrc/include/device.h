#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <stdbool.h>
#include <common.h>
#include <utils.h>
#include <SDL2/SDL.h>
#include "macro.h"

#define DEVICE_BASE     0xa0000000
#define MMIO_BASE       0xa0000000

#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)
#define RTC_ADDR        (DEVICE_BASE + 0x0000048)
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)
#define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)
#define DISK_ADDR       (DEVICE_BASE + 0x0000300)
#define FB_ADDR         (MMIO_BASE   + 0x1000000)
#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)

#if CONFIG_MBASE + CONFIG_MSIZE > 0x100000000ul
    #define PMEM64 1
#endif

void init_device();
void device_update();
extern uint32_t key_dequeue();

#endif