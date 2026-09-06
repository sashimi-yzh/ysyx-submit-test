#include "../local-include/csr.h"
#include "../local-include/trap-cause.h"
#include "csr-xmacro.h"
#include "debug.h"
#include "isa-def.h"
#include <cpu/difftest.h>
#include <device/clint.h>
#include <isa.h>
#include <stdint.h>
#ifdef CONFIG_HAS_PLIC
#include <device/plic.h>
#endif

static uint32_t device_mip_pending = 0;
static uint32_t csr_mip_pending = 0;
extern uint64_t g_nr_guest_inst;

#define CSR_BIT(n) (1u << (n))

#define MEDELEG_WRITABLE_MASK                                                  \
  (CSR_BIT(EXC_INST_ADDR_MISALIGNED) | CSR_BIT(EXC_INST_ACCESS_FAULT) |        \
   CSR_BIT(EXC_ILLEGAL_INST) | CSR_BIT(EXC_BREAKPOINT) |                       \
   CSR_BIT(EXC_LOAD_ADDR_MISALIGNED) | CSR_BIT(EXC_LOAD_ACCESS_FAULT) |        \
   CSR_BIT(EXC_STORE_ADDR_MISALIGNED) | CSR_BIT(EXC_STORE_ACCESS_FAULT) |      \
   CSR_BIT(EXC_U_ECALL) | CSR_BIT(EXC_S_ECALL) |                               \
   CSR_BIT(EXC_INST_PAGE_FAULT) | CSR_BIT(EXC_LOAD_PAGE_FAULT) |               \
   CSR_BIT(EXC_STORE_PAGE_FAULT))

typedef uint32_t (*csr_read_fn)(void);
typedef void (*csr_write_fn)(uint32_t data);

typedef struct {
  const char *name;
  uint16_t csr_num;
  uint32_t reset;
  uint32_t *raw;
  csr_read_fn read;
  csr_write_fn write;
} csr_desc_t;

static inline uint32_t sie_mask(void) { return MIE_SSIE | MIE_STIE | MIE_SEIE; }
static inline uint32_t sip_mask(void) { return MIP_SSIP | MIP_STIP | MIP_SEIP; }

static inline uint32_t mip_device_pending_mask(void) {
  return MIP_MSIP | MIP_MTIP;
}

static inline uint32_t mip_csr_writable_mask(void) {
  // SEIP needs separate B|E read-modify-write semantics.
  return MIP_SSIP | MIP_STIP;
}

static inline uint32_t mideleg_writable_mask(void) {
  return MIP_SSIP | MIP_STIP | MIP_SEIP;
}

static inline uint32_t sip_writable_mask(void) { return MIP_SSIP; }

static inline uint32_t sstatus_mask(void) {
  return SSTATUS_SIE | SSTATUS_SPIE | SSTATUS_MXR | SSTATUS_SUM | SSTATUS_SPP;
}

static void csr_write_medeleg(uint32_t data) {
  cpu.csr.medeleg = data & MEDELEG_WRITABLE_MASK;
}

static void csr_write_mideleg(uint32_t data) {
  cpu.csr.mideleg = data & mideleg_writable_mask();
}

static void disable_write(uint32_t data) {
  panic("should not reach func disable_write");
}

static uint32_t csr_read_mcounteren(void);
static void csr_write_mcounteren(uint32_t data);
static uint32_t csr_read_scounteren(void);
static void csr_write_scounteren(uint32_t data);
static uint32_t csr_read_mcountinhibit(void);
static void csr_write_mcountinhibit(uint32_t data);

#define DECLARE_VIRTUAL_CSR_HANDLER(name, idx)                                 \
  static uint32_t virt_csr_##name##_read(void);                                \
  static void virt_csr_##name##_write(uint32_t data);
EACH_VIRTUAL_CSR(DECLARE_VIRTUAL_CSR_HANDLER)
#undef DECLARE_VIRTUAL_CSR_HANDLER

static const csr_desc_t csr_descs[] = {
#define CSR_DESC_RAW_PTR_RAW(name) &cpu.csr.name
#define CSR_DESC_RAW_PTR_VIRT(name) NULL
#define CSR_DESC_INIT(kind, name, addr, reset, read, write)                    \
  {#name, addr, reset, CSR_DESC_RAW_PTR_##kind(name), read, write},
    EACH_CSR_DESC(CSR_DESC_INIT)
#undef CSR_DESC_INIT
#undef CSR_DESC_RAW_PTR_RAW
#undef CSR_DESC_RAW_PTR_VIRT
};

static const csr_desc_t *csr_lookup(uint32_t csr_num) {
  for (int i = 0; i < ARRLEN(csr_descs); i++) {
    if (csr_descs[i].csr_num == (csr_num & 0xfffu)) {
      return &csr_descs[i];
    }
  }
  return NULL;
}

void riscv_csr_reset(void) {
  for (int i = 0; i < ARRLEN(csr_descs); i++) {
    if (csr_descs[i].raw != NULL) {
      *csr_descs[i].raw = csr_descs[i].reset;
    }
  }

  device_mip_pending = 0;
  csr_mip_pending = 0;
  cpu.legacy_timer_interrupt_pending = false;
}

bool riscv_csr_read(uint32_t csr_num, uint32_t *data) {
  const csr_desc_t *desc = csr_lookup(csr_num);
  if (desc == NULL) {
    return false;
  }

  if (desc->read != NULL) {
    *data = desc->read();
    return true;
  }

  if (desc->raw == NULL) {
    return false;
  }
  *data = *desc->raw;
  return true;
}

bool riscv_csr_write(uint32_t csr_num, uint32_t data) {
  const csr_desc_t *desc = csr_lookup(csr_num);
  if (desc == NULL) {
    return false;
  }

  if (desc->write != NULL) {
    desc->write(data);
    return true;
  }

  if (desc->raw == NULL) {
    return false;
  }
  *desc->raw = data;
  return true;
}

static inline uint32_t mip_value(void) {
  uint32_t value = device_mip_pending | csr_mip_pending;
#ifdef CONFIG_HAS_PLIC
  if (query_plic_intr_ctx(0, NULL)) {
    value |= MIP_MEIP;
  }
  if (query_plic_intr_ctx(1, NULL)) {
    value |= MIP_SEIP;
  }
#endif
  return value;
}

uint32_t riscv_csr_mip_value(void) { return mip_value(); }

void riscv_csr_set_device_pending(uint32_t mask, bool pending) {
  mask &= mip_device_pending_mask();
  if (pending) {
    device_mip_pending |= mask;
  } else {
    device_mip_pending &= ~mask;
  }
}

#define ZICNTR_MCOUNTINHIBIT_MASK 0x5u

static uint32_t csr_read_mcounteren(void) {
  difftest_skip_ref();
  return cpu.csr.mcounteren;
}

static void csr_write_mcounteren(uint32_t data) {
  difftest_skip_ref();
  cpu.csr.mcounteren = data & MCOUNTEREN_MASK;
}

static uint32_t csr_read_scounteren(void) {
  difftest_skip_ref();
  return cpu.csr.scounteren;
}

static void csr_write_scounteren(uint32_t data) {
  difftest_skip_ref();
  cpu.csr.scounteren = data & MCOUNTEREN_MASK;
}

static uint32_t csr_read_mcountinhibit(void) {
  difftest_skip_ref();
  return cpu.csr.mcountinhibit;
}

static void csr_write_mcountinhibit(uint32_t data) {
  difftest_skip_ref();
  cpu.csr.mcountinhibit = data & ZICNTR_MCOUNTINHIBIT_MASK;
}

static uint64_t zicntr_inst_counter(void) { return g_nr_guest_inst; }

static uint32_t virt_csr_cycle_read(void) {
  difftest_skip_ref();
  return (uint32_t)zicntr_inst_counter();
}

static void virt_csr_cycle_write(uint32_t data) { disable_write(data); }

static uint32_t virt_csr_time_read(void) {
  difftest_skip_ref();
  return (uint32_t)clint_get_mtime();
}

static void virt_csr_time_write(uint32_t data) { disable_write(data); }

static uint32_t virt_csr_instret_read(void) {
  difftest_skip_ref();
  return (uint32_t)zicntr_inst_counter();
}

static void virt_csr_instret_write(uint32_t data) { disable_write(data); }

static uint32_t virt_csr_cycleh_read(void) {
  difftest_skip_ref();
  return (uint32_t)(zicntr_inst_counter() >> 32);
}

static void virt_csr_cycleh_write(uint32_t data) { disable_write(data); }

static uint32_t virt_csr_timeh_read(void) {
  difftest_skip_ref();
  return (uint32_t)(clint_get_mtime() >> 32);
}

static void virt_csr_timeh_write(uint32_t data) { disable_write(data); }

static uint32_t virt_csr_instreth_read(void) {
  difftest_skip_ref();
  return (uint32_t)(zicntr_inst_counter() >> 32);
}

static void virt_csr_instreth_write(uint32_t data) { disable_write(data); }

static uint32_t virt_csr_mip_read(void) { return mip_value(); }

static void virt_csr_mip_write(uint32_t data) {
  uint32_t mask = mip_csr_writable_mask();
  csr_mip_pending = (csr_mip_pending & ~mask) | (data & mask);
}

static uint32_t virt_csr_sip_read(void) {
  uint32_t mask = sip_mask() & cpu.csr.mideleg;
  return mip_value() & mask;
}

static void virt_csr_sip_write(uint32_t data) {
  uint32_t mask = sip_mask() & cpu.csr.mideleg & sip_writable_mask();
  csr_mip_pending = (csr_mip_pending & ~mask) | (data & mask);
}

static uint32_t virt_csr_sie_read(void) {
  uint32_t mask = sie_mask() & cpu.csr.mideleg;
  return cpu.csr.mie & mask;
}

static void virt_csr_sie_write(uint32_t data) {
  uint32_t mask = sie_mask() & cpu.csr.mideleg;
  cpu.csr.mie = (cpu.csr.mie & ~mask) | (data & mask);
}

static uint32_t virt_csr_sstatus_read(void) {
  uint32_t mask = sstatus_mask();
  return cpu.csr.mstatus & mask;
}

static void virt_csr_sstatus_write(uint32_t data) {
  uint32_t mask = sstatus_mask();
  cpu.csr.mstatus = (cpu.csr.mstatus & ~mask) | (data & mask);
}
