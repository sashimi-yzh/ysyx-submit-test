#ifndef AM_RISCV_NPC_PLATFORM_H
#define AM_RISCV_NPC_PLATFORM_H

#include <riscv/riscv.h>

#define NPC_UART_ADDR        0x10000000u
#define NPC_EXIT_MMIO_ADDR   0x10000004u
#define NPC_MTIME_LOW_ADDR   0x02000040u
#define NPC_MTIME_HIGH_ADDR  0x02000044u

#define NPC_PMEM_SIZE_BYTES  (128u * 1024u * 1024u)
extern char _pmem_start;
#define NPC_PMEM_END_ADDR \
  ((uintptr_t)&_pmem_start + NPC_PMEM_SIZE_BYTES)

void putch(char ch);
void halt(int code);
void print_boot_banner(void);

#endif
