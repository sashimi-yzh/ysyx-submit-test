#ifndef ARCH_H__
#define ARCH_H__

#include <stdint.h>
#ifdef __riscv_e
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

struct Context {
  uintptr_t gpr[NR_REGS];
  uintptr_t mcause;
  uintptr_t mstatus;
  uintptr_t mepc;
  void *pdir;
};

#ifdef __riscv_e
#define GPR1 gpr[15] // a5
#else
#define GPR1 gpr[17] // a7
#endif

#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]

#define SPI_BASE 0x10001000
#define SPI(x) (int *)(SPI_BASE + (x))
#define TX 0x0
#define CTRL 0x10
#define SS 0x18
#define DIVIDER 0x14

// bootloder.c
void loader_init();

/* 基本复制宏 */
#define COPY_SECTION(lma_start, vma_start, vma_end, type) do { \
    type *src = (type*)&(lma_start); \
    type *dst = (type*)&(vma_start); \
    unsigned int len = (uintptr_t)&(vma_end) - (uintptr_t)dst; \
    unsigned int count = len / sizeof(type); \
    for (unsigned int i = 0; i < count; i++) { \
        dst[i] = src[i]; \
    } \
} while(0)

/* 清零宏 */
#define CLEAR_BSS(bss_start, bss_end) do { \
    char *start = (char*)&(bss_start); \
    char *end = (char*)&(bss_end); \
    for (char *p = start; p <= end; p++) { \
        *p = 0; \
    } \
} while(0)

#define DECLARE_WEAK_SYMBOL(type, name) \
    extern type name[] __attribute__((weak));

#define CHECK_SECTION_EXISTS(start, end) \
    (&(start) != NULL && &(end) != NULL && (end) > (start))

#define COPY_OPTIONAL_SECTION(lma_start, vma_start, vma_end, type, name) do { \
    if (CHECK_SECTION_EXISTS(vma_start, vma_end)) { \
        type *src = (type*)(lma_start); \
        type *dst = (type*)(vma_start); \
        unsigned int len = (uintptr_t)&(vma_end) - (uintptr_t)dst; \
        unsigned int count = len / sizeof(type); \
        for (unsigned int i = 0; i < count; i++) { \
            dst[i] = src[i]; \
        } \
    } \
} while(0)
#endif