#ifndef YSYXSOC_H__
#define YSYXSOC_H__

#include <klib-macros.h>

#define ysyxsoc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

#define DEVICE_BASE (0xa0000000)
#define MMIO_BASE   (0x10000000)
#define FLASH_BASH  (0x30000000)

#define UART_BASE (0x10000000)
#define UART_TX	  (UART_BASE + 0x00)
#define UART_RX	  (UART_BASE + 0x00)
#define UART_LCR  (UART_BASE + 0x03)
#define UART_LSR  (UART_BASE + 0x05)
#define UART_LSB  (UART_BASE + 0x00)
#define UART_MSB  (UART_BASE + 0x01)

#define SERIAL_PORT (0x10000000)
#define RTC_ADDR    (0x02000000)
#define KBD_ADDR    (0x10011000)
#define VGACTL_ADDR (0x21000000)
#define FB_ADDR		(0x21000000)

extern char _pmem_start;
extern char _heap_start;
extern char _heap_end;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define HEAP_BASE ((uintptr_t)&_heap_start)
#define HEAP_END  ((uintptr_t)&_heap_end)
#define YSYXSOC_PADDR_SPACE \
	RANGE($_pmem_start, PMEM_END), \
	RANGE(FB_ADDR, FB_ADDR + 0x100000), \
	RANGE(MMIO_BASE, MMIO_BASE + 0x1000) /* serial, rtc, screen, keyboard */

typedef uintptr_t PTE;

#define PGSIZE		4096
#define CPU_FREQ_HZ 1000000ULL 

#endif


