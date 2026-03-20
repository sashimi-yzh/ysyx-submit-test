/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
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

#include "common.h"
#include "debug.h"
#include "local-include/reg.h"
#include "macro.h"
#include <assert.h>
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/ifetch.h>
#include <stdint.h>
#include <stdio.h>

#include <limits.h>

#include <btrace_pack.h>
#include <itrace_pack.h>

#include "memory/paddr.h"
#include <encoding.out.h>

// We are in riscv32
#define signed_min INT_MIN
#define WORD_MAXBITLEN 32

#define R(i) gpr(i)

static word_t _handle_csr_rw(word_t csr, word_t src1, bool is_write);
static word_t _csr_read(word_t csr) { return _handle_csr_rw(csr, 0, 0); }
static void _csr_write(word_t csr, word_t src1) {
  _handle_csr_rw(csr, src1, 1);
}

itrace_pack_t g_itrace_pack;
itrace_pack_t g_mtrace_pack;
btrace_pack_t g_btrace_pack;

// generate in out.cc
int execute_instruction(word_t instruction, word_t *pc, word_t *regs);

uint64_t g_nbranches;

static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;

  word_t csr_imm = BITS(s->isa.inst, 31, 20); // no sext

  word_t inst = s->isa.inst;

  word_t rd = (inst & INSN_FIELD_RD) >> 7;
  word_t rs1 = (inst & INSN_FIELD_RS1) >> 15;

#define IS_INST(name) (((inst & MASK_##name) == MATCH_##name) && (!matched))

  word_t tmp = s->pc;
  bool matched = (execute_instruction(inst, &tmp, cpu.gpr) == 0);
  if (matched)
    s->dnpc = tmp;

  if (inst == 0x100f) { // fence.i
    matched = true;
  }

#define MATCH_BRANCH 0b1100011
#define MASK_BRANCH 0b1111111

#define _NOCHK_IS_INST(name) ((inst & MASK_##name) == MATCH_##name)

  if (_NOCHK_IS_INST(BRANCH) || _NOCHK_IS_INST(JALR) || _NOCHK_IS_INST(JAL)) {
    g_nbranches++;
    if (g_btrace_pack) {
      btrace_record_t record = {.pc = s->pc, .code = inst, .nxt_pc = s->dnpc};
      btrace_pack_add(g_btrace_pack, &record);
    }
  }

  if (IS_INST(CSRRW)) {
    if (rd != 0) {
      R(rd) = _csr_read(csr_imm);
    }
    word_t src1 = R(rs1);
    _csr_write(csr_imm, src1);
    matched = true;
  }
  if (IS_INST(CSRRS)) {
    word_t old = _csr_read(csr_imm);
    R(rd) = old;
    word_t src1 = R(rs1);
    _csr_write(csr_imm, old | src1);
    matched = true;
  }

  if (IS_INST(EBREAK)) {
    NEMUTRAP(s->pc, R(10)); // R(10) is $a0
    matched = true;
  }
  if (IS_INST(ECALL)) {
    _csr_write(CSR_MEPC, s->pc);
    _csr_write(CSR_MCAUSE, CAUSE_MACHINE_ECALL);
    s->dnpc = isa_raise_intr(0x11451419, s->pc);
    matched = true;
  }

  // xRET sets the pc to the value stored in the xepc register.
  if (IS_INST(MRET)) {
    s->dnpc = _csr_read(CSR_MEPC);
    matched = true;
  }

  if (!matched) {
    INV(s->pc);
  }

  R(0) = 0; // reset $zero to 0

  return 0;
}

extern word_t g_csr_MTVEC;

word_t _handle_csr_rw(word_t csr, word_t src1, bool is_write) {
  static word_t g_csr_MCAUSE = 0, g_csr_MEPC = 0, g_csr_MVENDORID = 0x79737978,
                g_csr_MARCHID = 25100261, g_csr_MSTATUS = 0x1800;

  // printf("csr " #csr_name " %s : old=%08X
  // new=%08X\n",is_write?"write":"read",
  // (uint32_t)old,(uint32_t)(is_write?src1:old));
#define _CASE(csr_name)                                                        \
  case CSR_##csr_name: {                                                       \
    old = g_csr_##csr_name;                                                    \
    if (is_write)                                                              \
      g_csr_##csr_name = src1;                                                 \
    return old;                                                                \
  }
  word_t old;
  switch (csr) {
    _CASE(MCAUSE);
    _CASE(MEPC);
    _CASE(MSTATUS);
    _CASE(MTVEC);
    _CASE(MVENDORID);
    _CASE(MARCHID);
  default:
    panic("unsupported csr read/write: 0x%03X", csr);
  }
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  if (isSoC && g_itrace_pack) {
    itrace_pack_add(g_itrace_pack, s->pc);
  }
  // printf("%08x\n", s->pc);
  return decode_exec(s);
}
