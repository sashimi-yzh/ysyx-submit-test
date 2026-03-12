#ifndef __NPC_H__
#define __NPC_H__

#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>
#include <klib-macros.h>

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define PMEM_END ((uintptr_t)&_pmem_start + PMEM_SIZE)
#define npc_trap(code) asm volatile("mv a0, %0; ebreak" : : "r"(code))
#define npc_csr_read(csr_id) ({ \
    uint32_t val; \
    asm volatile("csrr %0, %1" : "=r"(val) : "i"(csr_id)); \
    val; \
})

#define SERIAL_PORT     0x10000000
#define RTC_PORT        0x02000000
#define KBD_PORT        0x10011000
#define VGA_PORT        0x21000000

#define CSR_MVENDORID   0xF11
#define CSR_MARCHID     0xF12

#define YSYX_LOGO       0x79737978 //ysyx的logo
#define YSYX_STU_NUM    0x25110270 //我的学号-25110270

#define VERSION         "NPC"

#endif