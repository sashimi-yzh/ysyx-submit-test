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
#include "isa.h"
#include "local-include/reg.h"
#include "macro.h"
#include "memory/symbols.h"
#include "ringbuffer.h"
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/ifetch.h>
#include <stdint.h>
#include <stdio.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I,
  TYPE_U,
  TYPE_S,
  TYPE_R,
  TYPE_J,
  TYPE_B,
  TYPE_CSRR,
  TYPE_CSRI,
  TYPE_N, // none
};

#define src1R()                                                                \
  do {                                                                         \
    *src1 = R(rs1);                                                            \
  } while (0)
#define src2R()                                                                \
  do {                                                                         \
    *src2 = R(rs2);                                                            \
  } while (0)
#define immI()                                                                 \
  do {                                                                         \
    *imm = SEXT(BITS(i, 31, 20), 12);                                          \
  } while (0)
#define csrC()                                                                 \
  do {                                                                         \
    *csr = BITS(i, 31, 20);                                                    \
  } while (0)
#define immU()                                                                 \
  do {                                                                         \
    *imm = SEXT(BITS(i, 31, 12), 20) << 12;                                    \
  } while (0)
#define immS()                                                                 \
  do {                                                                         \
    *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7);                   \
  } while (0)
#define immB()                                                                 \
  do {                                                                         \
    word_t imm12 = BITS(i, 31, 31), imm10_5 = BITS(i, 30, 25);                 \
    word_t imm11 = BITS(i, 7, 7), imm4_1 = BITS(i, 11, 8);                     \
    word_t _13bitimm =                                                         \
        (imm12 << 12) | (imm11 << 11) | (imm10_5 << 5) | (imm4_1 << 1);        \
    *imm = SEXT(_13bitimm, 13);                                                \
  } while (0)
#define immJ()                                                                 \
  do {                                                                         \
    word_t imm20 = BITS(i, 31, 31), imm10_1 = BITS(i, 30, 21);                 \
    word_t imm11 = BITS(i, 20, 20), imm19_12 = BITS(i, 19, 12);                \
    word_t _21bitimm =                                                         \
        (imm20 << 20) | (imm19_12 << 12) | (imm11 << 11) | (imm10_1 << 1);     \
    *imm = SEXT(_21bitimm, 21);                                                \
  } while (0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2,
                           word_t *imm, int *csr, int type) {
  uint32_t i = s->isa.inst;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd = BITS(i, 11, 7);
  switch (type) {
  case TYPE_I:
    src1R();
    immI();
    break;
  case TYPE_U:
    immU();
    break;
  case TYPE_J:
    immJ();
    break;
  case TYPE_S:
    src1R();
    src2R();
    immS();
    break;
  case TYPE_R:
    src1R();
    src2R();
    break;
  case TYPE_B:
    src1R();
    src2R();
    immB();
    break;
  case TYPE_CSRR:
    src1R();
    csrC();
    break;
  case TYPE_N:
    break;
  default:
    panic("unsupported type = %d", type);
  }
}

#ifdef CONFIG_FTRACER

static void several_spaces(unsigned cnt) {
  while (cnt--)
    fputc(' ', stderr);
}

static void check_jal(vaddr_t from_pc, vaddr_t to_pc, uint32_t inst) {
  if (symbols_table.symbol_count == 0)
    return;
  uint32_t rd = BITS(inst, 11, 7);
  int func_from = find_symbol(from_pc);
  int func_to = find_symbol(to_pc);
  if (rd == 1) {
    several_spaces(cnt_stack_ftrace * 2);
    int to_symbol = func_to;
    fprintf(stderr, "call [%s@0x%08x]\n", find_symbol_name(to_symbol), from_pc);
    push_stack_ftrace(from_pc, to_symbol);

  } else if (inst == 0x00008067) {
    Call ret_call = pop_stack_ftrace();
    several_spaces(cnt_stack_ftrace * 2);
    fprintf(stderr, "ret  [%s]\n", find_symbol_name(ret_call.symbol));
  } else if (func_to != func_from) {
    several_spaces(cnt_stack_ftrace * 2);
    fprintf(stderr, "into [%s]\n", find_symbol_name(func_to));
  }
}
#endif

static word_t *csr_id(int csr) {
  switch (csr) {
  case 0x300:
    return &cpu.csr_mstatus;
  case 0x305:
    return &cpu.csr_mtvec;
  case 0x341:
    return &cpu.csr_mepc;
  case 0x342:
    return &cpu.csr_mcause;
  case 0xf11:
    return &cpu.csr_mvendorid;
  case 0xf12:
    return &cpu.csr_marchid;
  }
  panic("Unknown csr id 0x%x", csr);
}

static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;
  IFDEF(CONFIG_INST_RINGBUFFER,
        pushRingBuffer(&inst_buffer, s->pc, s->isa.inst));
#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */)                   \
  {                                                                            \
    int rd = 0, csr = 0;                                                       \
    word_t src1 = 0, src2 = 0, imm = 0;                                        \
    decode_operand(s, &rd, &src1, &src2, &imm, &csr, concat(TYPE_, type));     \
    __VA_ARGS__;                                                               \
  }
  //   printf("%08x %08x\n", s->pc, s->isa.inst);
  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc, U,
          R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui, U, R(rd) = imm);

  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi, I,
          R(rd) = src1 + imm);
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add, R,
          R(rd) = src1 + src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub, R,
          R(rd) = src1 - src2);
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul, R,
          R(rd) = src1 * src2);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh, R,
          R(rd) =
              BITS((int64_t)(sword_t)src1 * (int64_t)(sword_t)src2, 63, 32));
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu, R,
          R(rd) = BITS((uint64_t)src1 * (uint64_t)src2, 63, 32));
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu, R,
          R(rd) = BITS((int64_t)(sword_t)src1 * (uint64_t)src2, 63, 32));
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu, R,
          if (src2 == 0) R(rd) = src1;
          else R(rd) = src1 % src2);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem, R,
          if (src2 == 0) R(rd) = src1;
          else if (src2 == -1) R(rd) = 0;
          else R(rd) = (sword_t)src1 % (sword_t)src2);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu, R,
          if (src2 == 0) R(rd) = -1;
          else R(rd) = src1 / src2);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div, R,
          if (src2 == 0) R(rd) = -1;
          else if (src2 == -1) R(rd) = -src1;
          else R(rd) = (sword_t)src1 / (sword_t)src2);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori, I,
          R(rd) = src1 ^ imm);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor, R,
          R(rd) = src1 ^ src2);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi, I,
          R(rd) = src1 & imm);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and, R,
          R(rd) = src1 & src2);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori, I, R(rd) = src1 | imm);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or, R, R(rd) = src1 | src2);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt, R,
          R(rd) = (sword_t)src1 < (sword_t)src2 ? 1 : 0);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu, R,
          R(rd) = src1 < src2 ? 1 : 0);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu, I,
          R(rd) = src1 < imm ? 1 : 0);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti, I,
          R(rd) = (sword_t)src1 < (sword_t)imm ? 1 : 0);

  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli, I,
          word_t shamt = imm & 0x1f;
          R(rd) = src1 << shamt);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll, R,
          word_t shift = BITS(src2, 4, 0);
          R(rd) = src1 << shift);
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli, I,
          word_t shamt = imm & 0x1f;
          R(rd) = src1 >> shamt);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl, R,
          word_t shift = BITS(src2, 4, 0);
          R(rd) = src1 >> shift);
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai, I,
          word_t shamt = imm & 0x1f;
          R(rd) = (word_t)((sword_t)src1 >> (sword_t)shamt));
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra, R,
          word_t shift = src2 & 0x1f;
          R(rd) = (word_t)((sword_t)src1 >> (sword_t)shift));
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or, R, R(rd) = src1 | src2);

  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb, I,
          R(rd) = SEXT(Mr(src1 + imm, 1), 8));
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu, I,
          R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh, I,
          R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu, I,
          R(rd) = Mr(src1 + imm, 2));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw, I,
          R(rd) = Mr(src1 + imm, 4));
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal, J, R(rd) = s->snpc;
          s->dnpc = s->pc + imm;
          IFDEF(CONFIG_FTRACER, check_jal(s->pc, s->dnpc, s->isa.inst)));
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr, I, R(rd) = s->snpc;
          s->dnpc = (src1 + imm) & (~0x1u);
          IFDEF(CONFIG_FTRACER, check_jal(s->pc, s->dnpc, s->isa.inst)));
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne, B,
          if (src1 != src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq, B,
          if (src1 == src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge, B,
          if ((sword_t)src1 >= (sword_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt, B,
          if ((sword_t)src1 < (sword_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu, B,
          if (src1 >= src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu, B,
          if (src1 < src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb, S,
          Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh, S,
          Mw(src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw, S,
          Mw(src1 + imm, 4, src2));
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N,
          NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall, N,
          s->dnpc = isa_raise_intr(11, cpu.pc));
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret, N,
          s->dnpc = cpu.csr_mepc);
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw, CSRR,
          word_t *dest_csr = csr_id(csr);
          R(rd) = *dest_csr; *dest_csr = src1;);
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs, CSRR,
          word_t *dest_csr = csr_id(csr);
          R(rd) = *dest_csr; *dest_csr = *dest_csr | src1);
  //   INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc, CSRR,
  //           word_t *dest_csr = csr_id(csr);
  //           R(rd) = *dest_csr; *dest_csr = *dest_csr & ~src1);
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv, N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
