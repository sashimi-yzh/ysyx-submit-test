#ifndef RISCV_H__
#define RISCV_H__

#include <stdint.h>

// clang-format off
static inline uint8_t  inb(uintptr_t addr) { return *(volatile uint8_t  *)addr; }
static inline uint16_t inw(uintptr_t addr) { return *(volatile uint16_t *)addr; }
static inline uint32_t inl(uintptr_t addr) { return *(volatile uint32_t *)addr; }

static inline void outb(uintptr_t addr, uint8_t  data) { *(volatile uint8_t  *)addr = data; }
static inline void outw(uintptr_t addr, uint16_t data) { *(volatile uint16_t *)addr = data; }
static inline void outl(uintptr_t addr, uint32_t data) { *(volatile uint32_t *)addr = data; }
// clang-format on

#define PTE_V 0x01
#define PTE_R 0x02
#define PTE_W 0x04
#define PTE_X 0x08
#define PTE_U 0x10
#define PTE_A 0x40
#define PTE_D 0x80

enum { MODE_U, MODE_S, MODE_M = 3 };
#define MSTATUS_MXR (1 << 19)
#define MSTATUS_SUM (1 << 18)

#if __riscv_xlen == 64
#define MSTATUS_SXL (2ull << 34)
#define MSTATUS_UXL (2ull << 32)
#else
#define MSTATUS_SXL 0
#define MSTATUS_UXL 0
#endif

#define VPN0_SHIFT 12  /* VA[21:12] for Sv32 */
#define VPN1_SHIFT 22  /* VA[31:22] for Sv32 */

#define VPN1_MASK (0x3FF << VPN1_SHIFT)
#define VPN0_MASK (0x3FF << VPN0_SHIFT)
#define OFFSET_MASK 0xFFF  /* VA[11:0] page offset for 4KB page */
#define OFFSET_MAX 0xFFF

#define PPN_MASK (0x3FFFFF << 10)

#define PTE_PPN(pte) (pte & PPN_MASK)

#endif
