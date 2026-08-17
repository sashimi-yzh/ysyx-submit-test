#ifndef SOC_H__
#define SOC_H__

#include <klib-macros.h>
#include <klib.h>
#include ISA_H
#include <stdint.h>

#define DEVICE_BASE 0xa0000000

#define MMIO_BASE 0xa0000000

#define SERIAL_PORT 0x10000000
#define SERIAL_INT_OFFSET 0x1
#define SERIAL_LCR_OFFSET 0x3
#define SERIAL_LSR_OFFSET 0x5

#define SPI_BASE 0x10001000
#define SPI_CTRL 0x10
#define SPI_DIV 0x14
#define SPI_SS 0x18

#define KBD_ADDR 0x10011000
#define FB_ADDR 0x21000000

#define RTC_ADDR 0x02000000

#define AUDIO_ADDR (DEVICE_BASE + 0x0000200)
#define DISK_ADDR (DEVICE_BASE + 0x0000300)

#define AUDIO_SBUF_ADDR (MMIO_BASE + 0x1200000)

typedef uintptr_t PTE;

#define PGSIZE 4096

#endif
