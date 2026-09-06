#ifndef __DEVICE_CLINT_H__
#define __DEVICE_CLINT_H__

#include <common.h>

void init_clint();
void clint_update_mtime(uint64_t mtime);
uint64_t clint_get_mtime(void);

#define CLINT_BASE 0x02000000u

#define CLINT_MAX_HART_ID 4u
#define CLINT_NR_HARTS (CLINT_MAX_HART_ID + 1)

#define CLINT_MSIP_BASE 0x0000u
#define CLINT_MTIMECMP_BASE 0x4000u
#define CLINT_MTIME_BASE 0xbff8u

#define CLINT_MSIP_STRIDE 0x4u
#define CLINT_MTIMECMP_STRIDE 0x8u
#define CLINT_MTIME_BYTES 0x8u

#define CLINT_MSIP_BYTES (CLINT_NR_HARTS * CLINT_MSIP_STRIDE)
#define CLINT_MTIMECMP_BYTES (CLINT_NR_HARTS * CLINT_MTIMECMP_STRIDE)
#define CLINT_SIZE 0x10000u

#define CLINT_WORD_OFFSET(offset) ((offset) & ~0x3u)
#define CLINT_DWORD_OFFSET(offset) ((offset) & ~0x7u)

#define CLINT_MSIP_REG(hart) (CLINT_MSIP_BASE + ((hart) * CLINT_MSIP_STRIDE))
#define CLINT_MTIMECMP_REG(hart)                                               \
  (CLINT_MTIMECMP_BASE + ((hart) * CLINT_MTIMECMP_STRIDE))
#define CLINT_MTIMECMP_LO_REG(hart) CLINT_MTIMECMP_REG(hart)
#define CLINT_MTIMECMP_HI_REG(hart) (CLINT_MTIMECMP_REG(hart) + 0x4u)
#define CLINT_MTIME_REG CLINT_MTIME_BASE
#define CLINT_MTIME_LO_REG CLINT_MTIME_REG
#define CLINT_MTIME_HI_REG (CLINT_MTIME_REG + 0x4u)

#define CLINT_IN_MSIP(offset)                                                  \
  (CLINT_WORD_OFFSET(offset) >= CLINT_MSIP_BASE &&                             \
   CLINT_WORD_OFFSET(offset) < (CLINT_MSIP_BASE + CLINT_MSIP_BYTES))
#define CLINT_IN_MTIMECMP(offset)                                              \
  (CLINT_DWORD_OFFSET(offset) >= CLINT_MTIMECMP_BASE &&                        \
   CLINT_DWORD_OFFSET(offset) < (CLINT_MTIMECMP_BASE + CLINT_MTIMECMP_BYTES))
#define CLINT_IN_MTIME(offset)                                                 \
  (CLINT_DWORD_OFFSET(offset) >= CLINT_MTIME_BASE &&                           \
   CLINT_DWORD_OFFSET(offset) < (CLINT_MTIME_BASE + CLINT_MTIME_BYTES))

#define CLINT_MSIP_HART_ID(offset)                                             \
  ((CLINT_WORD_OFFSET(offset) - CLINT_MSIP_BASE) / CLINT_MSIP_STRIDE)
#define CLINT_MTIMECMP_HART_ID(offset)                                         \
  ((CLINT_DWORD_OFFSET(offset) - CLINT_MTIMECMP_BASE) / CLINT_MTIMECMP_STRIDE)
#define CLINT_MTIMECMP_LOCAL_OFFSET(offset)                                    \
  (CLINT_WORD_OFFSET(offset) -                                                 \
   CLINT_MTIMECMP_REG(CLINT_MTIMECMP_HART_ID(offset)))
#define CLINT_MTIME_LOCAL_OFFSET(offset)                                       \
  (CLINT_WORD_OFFSET(offset) - CLINT_MTIME_BASE)

#define CLINT_HART_VALID(hart) ((hart) < CLINT_NR_HARTS)

#endif
