#ifndef YSYXSOC_H__
#define YSYXSOC_H__

#include <klib-macros.h>
#include <riscv/riscv.h>

#define ysyxsoc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

// #define DEVICE_BASE 0xa0000000
// #define MMIO_BASE   0xa0000000

// #define SERIAL_PORT     (DEVICE_BASE + 0x0000000)
// #define KBD_ADDR        (DEVICE_BASE + 0x0001000)
// #define RTC_ADDR        (DEVICE_BASE + 0x0002000)
#define RTC_ADDR         0x02000000
// #define VGACTL_ADDR     (DEVICE_BASE + 0x0003000)
// #define AUDIO_ADDR      (DEVICE_BASE + 0x0004000)
// #define DISK_ADDR       (DEVICE_BASE + 0x0005000)
// #define FB_ADDR         (MMIO_BASE   + 0x1000000)
// #define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x1200000)

#define UART_BASE		0x10000000L
#define UART_TX			(UART_BASE + 0x00)
#define UART_RX			(UART_BASE + 0x00)
#define UART_LSB		(UART_BASE + 0x00)
#define UART_MSB		(UART_BASE + 0x01)
#define UART_IER    (UART_BASE + 0x02)
#define UART_LCR		(UART_BASE + 0x03)
#define UART_LSR		(UART_BASE + 0x05)

#define PS2_KBD_ADDR         0x10011000
#define PS2_KBD_REG_SCANCODE 0x0

#define VGA_FB_ADDR          0x21000000
#define VGA_CTL_ADDR         0x211FFFF0
#define VGA_SYNC_ADDR        (VGA_CTL_ADDR + 4)

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define YSYXSOC_PADDR_SPACE \
  RANGE(&_pmem_start, PMEM_END), \
  RANGE(FB_ADDR, FB_ADDR + 0x200000), \
  RANGE(MMIO_BASE, MMIO_BASE + 0x1000) /* serial, rtc, screen, keyboard */

typedef uintptr_t PTE;

#define PGSIZE		4096

#endif

