#ifndef NPC_H__
#define NPC_H__

#include <klib-macros.h>

# define npc_trap(code) asm volatile("mv a0, %0; ebreak" : :"r"(code))

# define DEVICE_BASE 0x10000000
#define MMIO_BASE    0x10000000

#define SERIAL_PORT (DEVICE_BASE + 0x0000000)
#define UART_RX     (DEVICE_BASE + 0x0000000)
#define RTC_ADDR    (0x02000000)

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define NEMU_PADDR_SPACE \
  RANGE(&_pmem_start, PMEM_END), \
  RANGE(MMIO_BASE, MMIO_BASE + 0x1000) /* serial, rtc */

typedef uintptr_t PTE;

#define PGSIZE    4096
#define CPU_FREQ_HZ 1000000ULL

#endif
