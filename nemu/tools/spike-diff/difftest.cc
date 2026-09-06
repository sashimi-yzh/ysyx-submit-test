/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the
 * Mulan PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

// #include "../../include/common.h"
#include "encoding.h"
#include "mmu.h"
#include "sim.h"
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <difftest-def.h>

#define NR_GPR RISCV_GPR_NUM

static std::vector<std::pair<reg_t, abstract_device_t *>>
    difftest_plugin_devices;
static std::vector<std::string> difftest_htif_args;
static std::vector<std::pair<reg_t, mem_t *>>
    difftest_mem(1, std::make_pair(reg_t(DRAM_BASE), new mem_t(CONFIG_MSIZE)));
static debug_module_config_t difftest_dm_config = {
    .progbufsize = 2,
    .max_sba_data_width = 0,
    .require_authentication = false,
    .abstract_rti = 0,
    .support_hasel = true,
    .support_abstract_csr_access = true,
    .support_abstract_fpr_access = true,
    .support_haltgroups = true,
    .support_impebreak = true};

static sim_t *s = NULL;
static processor_t *p = NULL;
static state_t *state = NULL;

static inline auto mscratch_csr() { return state->csrmap.at(CSR_MSCRATCH); }
static inline auto mie_csr() { return state->mie; }
static inline auto sepc_csr() { return state->csrmap.at(CSR_SEPC); }
static inline auto stval_csr() { return state->csrmap.at(CSR_STVAL); }
static inline auto sscratch_csr() { return state->csrmap.at(CSR_SSCRATCH); }
static inline auto stvec_csr() { return state->csrmap.at(CSR_STVEC); }
static inline auto mvendorid_csr() { return state->csrmap.at(CSR_MVENDORID); }
static inline auto marchid_csr() { return state->csrmap.at(CSR_MARCHID); }

static inline void set_const_csr(reg_t csr_num, reg_t value) {
  state->csrmap[csr_num] = std::make_shared<const_csr_t>(p, csr_num, value);
}

static inline RISCV_GPR_TYPE spike_priv_to_ctx(reg_t prv) {
  switch (prv) {
  case PRV_U:
    return DIFFTEST_RISCV_PRIV_U;
  case PRV_S:
    return DIFFTEST_RISCV_PRIV_S;
  default:
    return DIFFTEST_RISCV_PRIV_M;
  }
}

static inline reg_t ctx_priv_to_spike(RISCV_GPR_TYPE prv) {
  switch (prv) {
  case DIFFTEST_RISCV_PRIV_U:
    return PRV_U;
  case DIFFTEST_RISCV_PRIV_S:
    return PRV_S;
  default:
    return PRV_M;
  }
}

void sim_t::diff_init(int port) {
  p = get_core("0");
  state = p->get_state();
}

void sim_t::diff_step(uint64_t n) { step(n); }

void sim_t::diff_get_regs(void *diff_context) {
  riscv_difftest_ctx_t *ctx = (riscv_difftest_ctx_t *)diff_context;
  for (int i = 0; i < NR_GPR; i++) {
    ctx->gpr[i] = state->XPR[i];
  }
  ctx->pc = state->pc;
  ctx->priv = spike_priv_to_ctx(state->prv);

  // get csr from spike
  ctx->csr.mvendorid = mvendorid_csr()->read();
  ctx->csr.marchid = marchid_csr()->read();
  ctx->csr.misa = state->misa->read();
  ctx->csr.medeleg = state->medeleg->read();
  ctx->csr.mideleg = state->mideleg->read();
  ctx->csr.mcause = state->mcause->read();
  ctx->csr.mepc = state->mepc->read();
  ctx->csr.sepc = sepc_csr()->read();
  ctx->csr.mstatus = state->mstatus->read();
  ctx->csr.mtval = state->mtval->read();
  ctx->csr.mtvec = state->mtvec->read();
  ctx->csr.mscratch = mscratch_csr()->read();
  ctx->csr.satp = state->satp->read();
  ctx->csr.mie = mie_csr()->read();
  ctx->csr.scause = state->scause->read();
  ctx->csr.stval = stval_csr()->read();
  ctx->csr.sscratch = sscratch_csr()->read();
  ctx->csr.stvec = stvec_csr()->read();
}

#define rv32_csr_syn(csrname) state->csrname->write(ctx->csr.csrname)
void sim_t::diff_set_regs(void *diff_context) {
  riscv_difftest_ctx_t *ctx = (riscv_difftest_ctx_t *)diff_context;
  for (int i = 0; i < NR_GPR; i++) {
    state->XPR.write(i, (int32_t)ctx->gpr[i]);
  }
  state->pc = ctx->pc;
  p->set_privilege(ctx_priv_to_spike(ctx->priv));
  set_const_csr(CSR_MVENDORID, ctx->csr.mvendorid);
  set_const_csr(CSR_MARCHID, ctx->csr.marchid);
  state->misa->write(ctx->csr.misa);
  rv32_csr_syn(medeleg);
  rv32_csr_syn(mideleg);
  sepc_csr()->write(ctx->csr.sepc);
  rv32_csr_syn(mstatus);
  rv32_csr_syn(mcause);
  rv32_csr_syn(mepc);
  rv32_csr_syn(mtval);
  rv32_csr_syn(mtvec);
  mscratch_csr()->write(ctx->csr.mscratch);
  rv32_csr_syn(mie);
  rv32_csr_syn(satp);
  rv32_csr_syn(scause);
  stval_csr()->write(ctx->csr.stval);
  sscratch_csr()->write(ctx->csr.sscratch);
  stvec_csr()->write(ctx->csr.stvec);
}

void sim_t::diff_memcpy_to_ref(reg_t dest, void *src, size_t n) {
  mmu_t *mmu = p->get_mmu();
  for (size_t i = 0; i < n; i++) {
    mmu->store<uint8_t>(dest + i, *((uint8_t *)src + i));
  }
}

void sim_t::diff_memcpy_to_dut(reg_t src, void *dest, size_t n) {
  mmu_t *mmu = p->get_mmu();
  for (size_t i = 0; i < n; i++) {
    *((uint8_t *)dest + i) = mmu->load<uint8_t>(src + i);
  }
}

extern "C" {

__EXPORT void difftest_memcpy(uint32_t addr, void *buf, size_t n,
                              int direction) {
  if (direction == DIFFTEST_TO_REF) {
    s->diff_memcpy_to_ref(addr, buf, n);
  } else if (direction == DIFFTEST_TO_DUT) {
    s->diff_memcpy_to_dut(addr, buf, n);
  }
}

__EXPORT void difftest_probe_mem(uint32_t addr, difftest_mem_probe_t *result,
                                 size_t n) {
  *result = {};
  if (n > sizeof(result->data)) {
    n = sizeof(result->data);
  }

  try {
    mmu_t *mmu = p->get_mmu();
    for (size_t i = 0; i < n; i++) {
      *((uint8_t *)&result->data + i) = mmu->load<uint8_t>(addr + i);
    }
    result->success = 1;
  } catch (trap_t &t) {
    result->success = 0;
    result->cause = t.cause();
  }
}

__EXPORT void difftest_regcpy(void *dut, int direction) {
  if (direction == DIFFTEST_TO_REF) {
    s->diff_set_regs(dut);
  } else {
    s->diff_get_regs(dut);
  }
}

__EXPORT void difftest_exec(uint64_t n) { s->diff_step(n); }

__EXPORT void difftest_raise_sync_exception(uint64_t cause, uint64_t tval) {
  switch (cause) {
  case CAUSE_ILLEGAL_INSTRUCTION:
    (void)tval;
    p->set_difftest_illegal_instruction();
    break;
  default:
    fprintf(stderr,
            "spike: unsupported synchronous exception cause %" PRIu64
            ", tval 0x%" PRIx64 "\n",
            cause, tval);
    abort();
  }
}

__EXPORT void difftest_init(int port) {
  difftest_htif_args.push_back("");
  const char *isa =
      "RV" MUXDEF(CONFIG_RV64, "64", "32") MUXDEF(CONFIG_RVE, "E", "I") "MAFDC";
  cfg_t cfg(/*default_initrd_bounds=*/std::make_pair((reg_t)0, (reg_t)0),
            /*default_bootargs=*/nullptr,
            /*default_isa=*/isa,
            /*default_priv=*/DEFAULT_PRIV,
            /*default_varch=*/DEFAULT_VARCH,
            /*default_misaligned=*/false,
            /*default_endianness*/ endianness_little,
            /*default_pmpregions=*/16,
            /*default_mem_layout=*/std::vector<mem_cfg_t>(),
            /*default_hartids=*/std::vector<size_t>(1),
            /*default_real_time_clint=*/false,
            /*default_trigger_count=*/4);
  s = new sim_t(&cfg, false, difftest_mem, difftest_plugin_devices,
                difftest_htif_args, difftest_dm_config, nullptr, false, NULL,
                false, NULL, true);
  s->diff_init(port);
}

__EXPORT void difftest_raise_intr(uint64_t NO) {
  trap_t t(NO);
  p->take_trap_public(t, state->pc);
}
}
