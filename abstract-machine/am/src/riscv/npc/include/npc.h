#ifndef NPC_H__
#define NPC_H__

#include <klib-macros.h>
#include <riscv/riscv.h>

// Keep NPC device layout independent from NEMU.
#define DEVICE_BASE 0x10000000
#define MMIO_BASE   DEVICE_BASE

#define SERIAL_PORT     (DEVICE_BASE + 0x00000000)
#define KBD_ADDR        (DEVICE_BASE + 0x00000060)
#define RTC_ADDR        0x00100048
#define CLINT_BASE      0x02000000
#define CLINT_MTIME     0x0200bff8
#define CLINT_MTIMEH    0x0200bffc

// Time base assumptions for NPC CLINT mtime.
// Tune this single macro to adjust AM_TIMER_UPTIME scaling globally.
#define NPC_CPU_FREQ_HZ 1000000ull
#define NPC_CLINT_CYCLES_PER_US (NPC_CPU_FREQ_HZ / 1000000ull)
#define VGACTL_ADDR     (DEVICE_BASE + 0x00000100)
#define AUDIO_ADDR      (DEVICE_BASE + 0x00000200)
#define DISK_ADDR       (DEVICE_BASE + 0x00000300)
#define FB_ADDR         (MMIO_BASE   + 0x01000000)
#define AUDIO_SBUF_ADDR (MMIO_BASE   + 0x01200000)

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

typedef uintptr_t PTE;

#define PGSIZE    4096

#endif
