#include <device/map.h>
#include <device/plic.h>
#include <isa.h>
#include <utils.h>

#ifdef CONFIG_HAS_PLIC

static uint8_t *plic_space = NULL;
static plic_intr_complete_t intr_complete[PLIC_NR_SOURCES] = {};
static uint32_t intr_signum = 1;

static uint32_t priority_regs[PLIC_NR_SOURCES] = {};
static uint32_t pending_regs[PLIC_NR_PENDING_WORDS] = {};
static uint32_t pending_count = 0;
static uint32_t enable_regs[PLIC_MAX_CONTEXTS][PLIC_NR_PENDING_WORDS] = {};
static uint32_t threshold_regs[PLIC_MAX_CONTEXTS] = {};

static inline uint32_t *plic_reg(uint32_t offset) {
  return (uint32_t *)(plic_space + PLIC_WORD_OFFSET(offset));
}

static inline void plic_set_pending(uint32_t source, bool pending) {
  uint32_t word = source >> 5;
  uint32_t bit = source & 0x1f;
  uint32_t mask = 1u << bit;
  bool was_pending = (pending_regs[word] & mask) != 0;

  if (pending) {
    if (!was_pending) {
      pending_regs[word] |= mask;
      pending_count++;
    }
  } else if (was_pending) {
    pending_regs[word] &= ~mask;
    pending_count--;
  }
}

static inline uint32_t plic_get_enable(uint32_t context, uint32_t source) {
  uint32_t word = source >> 5;
  uint32_t bit = source & 0x1f;
  return (enable_regs[context][word] >> bit) & 1u;
}

static uint32_t plic_pick_irq(uint32_t context) {
  if (!PLIC_CONTEXT_VALID(context) || pending_count == 0) {
    return 0;
  }

  uint32_t best_source = 0;
  uint32_t best_prio = 0;
  uint32_t threshold = threshold_regs[context];

  for (uint32_t word = 0; word < PLIC_NR_PENDING_WORDS; word++) {
    uint32_t candidates = pending_regs[word] & enable_regs[context][word];
    if (word == 0) {
      candidates &= ~1u;
    }

    while (candidates != 0) {
      uint32_t bit = __builtin_ctz(candidates);
      uint32_t source = (word << 5) + bit;
      uint32_t prio = priority_regs[source];

      if (prio > threshold && prio > best_prio) {
        best_source = source;
        best_prio = prio;
      }

      candidates &= candidates - 1;
    }
  }

  return best_source;
}

static uint32_t plic_claim_irq(uint32_t context) {
  uint32_t source = plic_pick_irq(context);
  if (source != 0) {
    plic_set_pending(source, false);
  }
  return source;
}

static void plic_complete_irq(uint32_t context, uint32_t source) {
  if (!PLIC_CONTEXT_VALID(context) || !PLIC_SOURCE_VALID(source)) {
    return;
  }

  if (!plic_get_enable(context, source)) {
    return;
  }

  if (source < intr_signum && intr_complete[source] != NULL) {
    intr_complete[source]();
  }
}

int add_intr_source(plic_intr_complete_t compl) {
  if (intr_signum > PLIC_MAX_SOURCE_ID) {
    return -1;
  }

  uint32_t source = intr_signum++;
  intr_complete[source] = compl;
  return source;
}

void plic_raise_intr(uint32_t source) {
  if (!PLIC_SOURCE_VALID(source) || source >= intr_signum) {
    return;
  }

  plic_set_pending(source, true);
}

bool query_plic_intr_ctx(uint32_t context, int *idx) {
  uint32_t source = plic_pick_irq(context);
  if (idx != NULL) {
    *idx = (int)source;
  }
  return source != 0;
}

bool query_plic_intr(int *idx) { return query_plic_intr_ctx(0, idx); }

static void plic_sync_priority(uint32_t offset, bool is_write) {
  uint32_t source = PLIC_PRIORITY_ID(offset);
  uint32_t *reg = plic_reg(offset);

  if (!is_write) {
    *reg = (source < PLIC_NR_SOURCES) ? priority_regs[source] : 0;
    return;
  }

  if (!PLIC_SOURCE_VALID(source)) {
    priority_regs[source] = 0;
  } else {
    priority_regs[source] = *reg;
  }
  *reg = priority_regs[source];
}

static void plic_sync_pending(uint32_t offset) {
  uint32_t word = PLIC_PENDING_WORD_ID(offset);
  uint32_t *reg = plic_reg(offset);
  *reg = PLIC_PENDING_WORD_VALID(word) ? pending_regs[word] : 0;
}

static void plic_sync_enable(uint32_t offset, bool is_write) {
  uint32_t context = PLIC_ENABLE_CONTEXT_ID(offset);
  uint32_t word = PLIC_ENABLE_WORD_ID(offset);
  uint32_t *reg = plic_reg(offset);

  if (!PLIC_CONTEXT_VALID(context) || !PLIC_ENABLE_WORD_VALID(word)) {
    *reg = 0;
    return;
  }

  if (!is_write) {
    *reg = enable_regs[context][word];
    return;
  }

  enable_regs[context][word] = *reg;
  if (word == 0) {
    enable_regs[context][word] &= ~1u;
  }
  *reg = enable_regs[context][word];
}

static void plic_sync_context(uint32_t offset, bool is_write) {
  uint32_t context = PLIC_CONTEXT_ID(offset);
  uint32_t *reg = plic_reg(offset);

  if (!PLIC_CONTEXT_VALID(context)) {
    *reg = 0;
    return;
  }

  if (PLIC_IS_THRESHOLD(offset)) {
    if (is_write) {
      threshold_regs[context] = *reg;
    } else {
      *reg = threshold_regs[context];
    }
    return;
  }

  if (PLIC_IS_CLAIM(offset)) {
    if (is_write) {
      plic_complete_irq(context, *reg);
      *reg = 0;
    } else {
      *reg = plic_claim_irq(context);
    }
    return;
  }

  *reg = 0;
}

void plic_io_handler(uint32_t offset, int len, bool is_write) {
  Assert(((offset & 0x3u) + len) <= 4,
         "PLIC only supports accesses within a single 32-bit register: "
         "offset=0x%08x len=%d",
         offset, len);

  if (PLIC_IN_PRIORITY(offset)) {
    plic_sync_priority(offset, is_write);
    return;
  }

  if (PLIC_IN_PENDING(offset)) {
    plic_sync_pending(offset);
    return;
  }

  if (PLIC_IN_ENABLE(offset)) {
    plic_sync_enable(offset, is_write);
    return;
  }

  if (PLIC_IN_CONTEXT(offset)) {
    plic_sync_context(offset, is_write);
    return;
  }

  *plic_reg(offset) = 0;
}

void init_plic() {
  plic_space = calloc(1, PLIC_SIZE);
  assert(plic_space != NULL);
  add_mmio_map("plic", PLIC_BASE, plic_space, PLIC_SIZE, plic_io_handler);
}

void compl_intr_ctx(uint32_t context, int idx) {
  plic_complete_irq(context, (uint32_t)idx);
}

void compl_intr(int idx) { compl_intr_ctx(0, idx); }

#endif
