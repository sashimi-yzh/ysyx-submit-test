#ifndef __DEVICE_PLIC_H__
#define __DEVICE_PLIC_H__

#include <common.h>

typedef void (*plic_intr_complete_t)(void);

int add_intr_source(plic_intr_complete_t compl);
void plic_raise_intr(uint32_t source);
// context 0 -> M-mode, context 1 -> S-mode
bool query_plic_intr_ctx(uint32_t context, int *idx);
bool query_plic_intr(int *idx);
void compl_intr_ctx(uint32_t context, int idx);
void compl_intr(int idx);
void init_plic(void);

/* ===== plic mapping map =====
 *
 *  base + 0x0                        reserve
 *  base + 0x4 ~ base + 0xffc         priority
 *  base + 0x1000 ~ base + 0x107c     interrupt pending
 *
 * ===== Enable Registers (for each context, up to 15872 contexts) =====
 * Each context has 32 x 32-bit registers (1024 bits total)
 * Context n offset: base + 0x002000 + (n * 0x80)
 *   +0x0000  Enable bits [31:0]   (sources 0-31)
 *   +0x0004  Enable bits [63:32]  (sources 32-63)
 *   ...
 *   +0x007C  Enable bits [1023:992] (sources 992-1023)
 * */

#define PLIC_BASE 0x0c000000u

#define PLIC_MAX_SOURCE_ID 1023u
#define PLIC_NR_SOURCES (PLIC_MAX_SOURCE_ID + 1)
#define PLIC_MAX_CONTEXTS 15872u

#define PLIC_PRIORITY_BASE 0x000000u
#define PLIC_PENDING_BASE 0x001000u
#define PLIC_ENABLE_BASE 0x002000u
#define PLIC_CONTEXT_BASE 0x200000u

#define PLIC_THRESHOLD_OFFSET 0x0u
#define PLIC_CLAIM_OFFSET 0x4u

#define PLIC_PRIORITY_BYTES (PLIC_NR_SOURCES * sizeof(uint32_t))
#define PLIC_NR_PENDING_WORDS (PLIC_NR_SOURCES / 32)
#define PLIC_PENDING_BYTES (PLIC_NR_PENDING_WORDS * sizeof(uint32_t))
#define PLIC_ENABLE_STRIDE PLIC_PENDING_BYTES
#define PLIC_ENABLE_BYTES (PLIC_MAX_CONTEXTS * PLIC_ENABLE_STRIDE)
#define PLIC_CONTEXT_STRIDE 0x1000u
#define PLIC_CONTEXT_BYTES (PLIC_MAX_CONTEXTS * PLIC_CONTEXT_STRIDE)
#define PLIC_SIZE (PLIC_CONTEXT_BASE + PLIC_CONTEXT_BYTES)

#define PLIC_WORD_OFFSET(offset) ((offset) & ~0x3u)

#define PLIC_PRIORITY_REG(source) (PLIC_PRIORITY_BASE + ((source) << 2))
#define PLIC_PENDING_REG(word) (PLIC_PENDING_BASE + ((word) << 2))
#define PLIC_ENABLE_REG(context, word)                                         \
  (PLIC_ENABLE_BASE + ((context) * PLIC_ENABLE_STRIDE) + ((word) << 2))
#define PLIC_CONTEXT_REG(context, reg)                                         \
  (PLIC_CONTEXT_BASE + ((context) * PLIC_CONTEXT_STRIDE) + (reg))

#define PLIC_IN_PRIORITY(offset)                                               \
  (PLIC_WORD_OFFSET(offset) < (PLIC_PRIORITY_BASE + PLIC_PRIORITY_BYTES))
#define PLIC_IN_PENDING(offset)                                                \
  (PLIC_WORD_OFFSET(offset) >= PLIC_PENDING_BASE &&                            \
   PLIC_WORD_OFFSET(offset) < (PLIC_PENDING_BASE + PLIC_PENDING_BYTES))
#define PLIC_IN_ENABLE(offset)                                                 \
  (PLIC_WORD_OFFSET(offset) >= PLIC_ENABLE_BASE &&                             \
   PLIC_WORD_OFFSET(offset) < (PLIC_ENABLE_BASE + PLIC_ENABLE_BYTES))
#define PLIC_IN_CONTEXT(offset)                                                \
  (PLIC_WORD_OFFSET(offset) >= PLIC_CONTEXT_BASE &&                            \
   PLIC_WORD_OFFSET(offset) < PLIC_SIZE)

#define PLIC_PRIORITY_ID(offset) (PLIC_WORD_OFFSET(offset) >> 2)
#define PLIC_PENDING_WORD_ID(offset)                                           \
  ((PLIC_WORD_OFFSET(offset) - PLIC_PENDING_BASE) >> 2)
#define PLIC_ENABLE_CONTEXT_ID(offset)                                         \
  ((PLIC_WORD_OFFSET(offset) - PLIC_ENABLE_BASE) / PLIC_ENABLE_STRIDE)
#define PLIC_ENABLE_WORD_ID(offset)                                            \
  (((PLIC_WORD_OFFSET(offset) - PLIC_ENABLE_BASE) % PLIC_ENABLE_STRIDE) >> 2)
#define PLIC_CONTEXT_ID(offset)                                                \
  ((PLIC_WORD_OFFSET(offset) - PLIC_CONTEXT_BASE) / PLIC_CONTEXT_STRIDE)
#define PLIC_CONTEXT_LOCAL_OFFSET(offset)                                      \
  ((PLIC_WORD_OFFSET(offset) - PLIC_CONTEXT_BASE) % PLIC_CONTEXT_STRIDE)
#define PLIC_IS_THRESHOLD(offset)                                              \
  (PLIC_IN_CONTEXT(offset) &&                                                  \
   PLIC_CONTEXT_LOCAL_OFFSET(offset) == PLIC_THRESHOLD_OFFSET)
#define PLIC_IS_CLAIM(offset)                                                  \
  (PLIC_IN_CONTEXT(offset) &&                                                  \
   PLIC_CONTEXT_LOCAL_OFFSET(offset) == PLIC_CLAIM_OFFSET)

#define PLIC_SOURCE_VALID(source)                                              \
  ((source) > 0 && (source) <= PLIC_MAX_SOURCE_ID)
#define PLIC_PENDING_WORD_VALID(word) ((word) < PLIC_NR_PENDING_WORDS)
#define PLIC_CONTEXT_VALID(context) ((context) < PLIC_MAX_CONTEXTS)
#define PLIC_ENABLE_WORD_VALID(word) ((word) < PLIC_NR_PENDING_WORDS)

#endif
