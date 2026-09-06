/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 *PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 *KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 *NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/
// clang-format off
#include "debug.h"
#include <dlfcn.h>

#include <isa.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>
#include <stdbool.h>
#include <utils.h>
#include <difftest-def.h>

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;
void (*ref_difftest_raise_sync_exception)(uint64_t cause, uint64_t tval) = NULL;
void (*ref_difftest_probe_mem)(vaddr_t addr, difftest_mem_probe_t *result,
                               size_t n) = NULL;

#ifdef CONFIG_DIFFTEST

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

#ifdef CONFIG_ISA_riscv
RISCV_GPR_TYPE difftest_ref_priv = DIFFTEST_RISCV_PRIV_M;

static void pack_difftest_ctx(riscv_difftest_ctx_t *ctx, const CPU_state *state) {
  for (int i = 0; i < RISCV_GPR_NUM; i++) {
    ctx->gpr[i] = state->gpr[i];
  }
  ctx->pc = state->pc;
  ctx->priv = state->priv;
#define PACK_DIFFTEST_CSR(name) ctx->csr.name = state->csr.name;
  EACH_DIFFTEST_CSR(PACK_DIFFTEST_CSR)
#undef PACK_DIFFTEST_CSR
}

static void unpack_difftest_ctx(CPU_state *state,
                                const riscv_difftest_ctx_t *ctx) {
  for (int i = 0; i < RISCV_GPR_NUM; i++) {
    state->gpr[i] = ctx->gpr[i];
  }
  state->pc = ctx->pc;
  state->priv = ctx->priv;
#define UNPACK_DIFFTEST_CSR(name) state->csr.name = ctx->csr.name;
  EACH_DIFFTEST_CSR(UNPACK_DIFFTEST_CSR)
#undef UNPACK_DIFFTEST_CSR
}

static void difftest_regcpy_to_ref(const CPU_state *state) {
  riscv_difftest_ctx_t ctx = {};
  pack_difftest_ctx(&ctx, state);
  ref_difftest_regcpy(&ctx, DIFFTEST_TO_REF);
}

static void difftest_regcpy_to_dut(CPU_state *state) {
  riscv_difftest_ctx_t ctx = {};
  ref_difftest_regcpy(&ctx, DIFFTEST_TO_DUT);
  difftest_ref_priv = ctx.priv;
  unpack_difftest_ctx(state, &ctx);
}
#else
static void difftest_regcpy_to_ref(const CPU_state *state) {
  ref_difftest_regcpy((void *)state, DIFFTEST_TO_REF);
}

static void difftest_regcpy_to_dut(CPU_state *state) {
  ref_difftest_regcpy(state, DIFFTEST_TO_DUT);
}
#endif

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
void difftest_skip_ref() {
  is_skip_ref = true;
  // If such an instruction is one of the instruction packing in QEMU
  // (see below), we end the process of catching up with QEMU's pc to
  // keep the consistent behavior in our best.
  // Note that this is still not perfect: if the packed instructions
  // already write some memory, and the incoming instruction in NEMU
  // will load that memory, we will encounter false negative. But such
  // situation is infrequent.
  skip_dut_nr_inst = 0;
}

void difftest_raise_sync_exception(uint64_t cause, uint64_t tval) {
  assert(ref_difftest_raise_sync_exception);
  ref_difftest_raise_sync_exception(cause, tval);
}

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NEMU's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
void difftest_skip_dut(int nr_ref, int nr_dut) {
  skip_dut_nr_inst += nr_dut;

  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  ref_difftest_raise_sync_exception =
      dlsym(handle, "difftest_raise_sync_exception");

  ref_difftest_probe_mem = dlsym(handle, "difftest_probe_mem");

  void (*ref_difftest_init)(int) = dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  cpu.csr.mstatus = 0x1800;

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  difftest_regcpy_to_ref(&cpu);
}

static void difftest_syn() {
  // detach -> attach: need to sync
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), CONFIG_MSIZE,DIFFTEST_TO_REF);
  difftest_regcpy_to_ref(&cpu);
}

static void checkregs(CPU_state *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    nemu_state.state = NEMU_ABORT;
    nemu_state.halt_pc = pc;
    isa_reg_display(ref);
  }
}

static void difftest_step_(vaddr_t pc, vaddr_t npc) {
  CPU_state ref_r;

  if (skip_dut_nr_inst > 0) {
    difftest_regcpy_to_dut(&ref_r);
    if (ref_r.pc == npc) {
      skip_dut_nr_inst = 0;
      checkregs(&ref_r, npc);
      return;
    }
    skip_dut_nr_inst --;
    if (skip_dut_nr_inst == 0)
      panic("can not catch up with ref.pc = " FMT_WORD " at pc = " FMT_WORD, ref_r.pc, pc);
    return;
  }

  if (is_skip_ref) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    difftest_regcpy_to_ref(&cpu);
    is_skip_ref = false;
    return;
  }

  ref_difftest_exec(1);
  difftest_regcpy_to_dut(&ref_r);

  checkregs(&ref_r, pc);
}

static bool difftest_attached = true;
void difftest_step(vaddr_t pc, vaddr_t npc) {
  if(difftest_attached) {
    difftest_step_(pc, npc);
  }
}

void difftest_attach() {
  if(difftest_attached == true) {
    printf("[warning] the difftest is already attached\n");
    return ;
  }
  difftest_syn();
  difftest_attached = true;
}

void difftest_detach() {
  difftest_attached = false;
}

bool difftest_is_attach() {
  return difftest_attached;
}

#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif

// clang-format on
