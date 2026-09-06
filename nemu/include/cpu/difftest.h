/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#ifndef __CPU_DIFFTEST_H__
#define __CPU_DIFFTEST_H__

#include <common.h>
#include <difftest-def.h>

#ifdef CONFIG_DIFFTEST
void difftest_skip_ref();
void difftest_skip_dut(int nr_ref, int nr_dut);
void difftest_set_patch(void (*fn)(void *arg), void *arg);
void difftest_raise_sync_exception(uint64_t cause, uint64_t tval);
void difftest_step(vaddr_t pc, vaddr_t npc);
void difftest_detach();
void difftest_attach();
bool difftest_is_attach();
#else
static inline void difftest_skip_ref() {}
static inline void difftest_skip_dut(int nr_ref, int nr_dut) {}
static inline void difftest_set_patch(void (*fn)(void *arg), void *arg) {}
static inline void difftest_raise_sync_exception(uint64_t cause, uint64_t tval) {}
static inline void difftest_step(vaddr_t pc, vaddr_t npc) {}
static inline void difftest_detach() {}
static inline void difftest_attach() {}
static inline bool difftest_is_attach() { return false; }
#endif

extern void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n,
                                   bool direction);
extern void (*ref_difftest_regcpy)(void *dut, bool direction);
extern void (*ref_difftest_exec)(uint64_t n);
extern void (*ref_difftest_raise_intr)(uint64_t NO);
extern void (*ref_difftest_raise_sync_exception)(uint64_t cause, uint64_t tval);
extern void (*ref_difftest_probe_mem)(vaddr_t addr,
                                      difftest_mem_probe_t *result, size_t n);
#ifdef CONFIG_ISA_riscv
extern RISCV_GPR_TYPE difftest_ref_priv;
#endif

static inline bool difftest_check_reg(const char *name, vaddr_t pc, word_t ref,
                                      word_t dut) {
  if (ref != dut) {
    Log("%s is different after executing instruction at pc = " FMT_WORD
        ", right = " FMT_WORD ", wrong = " FMT_WORD ", diff = " FMT_WORD,
        name, pc, ref, dut, ref ^ dut);
    return false;
  }
  return true;
}

#endif
