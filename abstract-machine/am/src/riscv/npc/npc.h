#ifndef NPC_H__
#define NPC_H__

#include <riscv/riscv.h>

#define DEVICE_BASE 0x10000000
#define MMIO_BASE 0x10000000

#define SERIAL_PORT     (DEVICE_BASE + 0x00000000)
#define VGACTL_ADDR     (DEVICE_BASE + 0x00000100)
//#define AUDIO_ADDR      (DEVICE_BASE + 0x00000200)
//#define DISK_ADDR       (DEVICE_BASE + 0x00000300)
#define KBD_ADDR        (DEVICE_BASE + 0x00000500)
// #define RTC_ADDR        (DEVICE_BASE + 0x00000600)
#define RTC_ADDR        0x02000000
#define TIME_ADDR        (DEVICE_BASE + 0x00000700)
#define FB_ADDR         (MMIO_BASE   + 0x01000000)
//#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x01200000)

#endif

