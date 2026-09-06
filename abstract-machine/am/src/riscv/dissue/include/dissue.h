#ifndef NEMU_H__
#define NEMU_H__

#include "am.h"
#include "riscv/riscv.h"
#include <klib-macros.h>

#define dissue_trap(code) asm volatile("mv a0, %0; ebreak" : : "r"(code))

#define MMIO_BASE 0xa0000000

#define SERIAL_PORT (MMIO_BASE + 0x00003f8)
#define CLINT_BASE 0x02000000
#define CLINT_SIZE 0x00010000
#define CLINT_MTIME_ADDR (CLINT_BASE + 0x0000bff8)

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define DISSUE_PADDR_SPACE                                                     \
  RANGE(&_pmem_start, PMEM_END),                                               \
      RANGE(CLINT_BASE, CLINT_BASE + CLINT_SIZE),                              \
      RANGE(MMIO_BASE, MMIO_BASE + 0x1000) /* serial, rtc, screen, keyboard */

typedef uintptr_t PTE;

#define PGSIZE 4096

#endif
