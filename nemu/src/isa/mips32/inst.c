/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>

#ifndef __ICS_EXPORT
#include "local-include/intr.h"
#include <cpu/difftest.h>

#define R(i) gpr(i)
#define Mr(addr, len)       ({ word_t tmp = vaddr_read(s, addr, len, MMU_DYNAMIC); check_ex(0); tmp; })
#define Mw(addr, len, data) vaddr_write(s, addr, len, data, MMU_DYNAMIC);

enum {
  TYPE_U, TYPE_R, TYPE_I,
  TYPE_J, TYPE_B, TYPE_S,  // shift
  TYPE_jalr, TYPE_N, // none
};

void csrrw(word_t *dest, const word_t *src, uint32_t csrid);
word_t priv_inst(uint32_t op, const word_t *src);
uint32_t clz(uint32_t x);

#define immI() do { *imm = SEXT(BITS(i, 15, 0), 16); } while(0)
#define immU() do { *imm = BITS(i, 15, 0); } while(0)
#define immS() do { *imm = BITS(i, 10, 6); } while(0)
#define immJ() do { *imm = (s->pc & 0xf0000000) | (BITS(i, 25, 0) << 2); } while(0)
#define immB() do { immI(); *imm <<= 2; *imm += s->pc + 4; } while(0)

#ifdef CONFIG_PERF_OPT
#include <isa-all-inst.h>
static word_t zero_null = 0;
#define src1R() do { id_src1->preg = &R(rs); } while (0)
#define src2R() do { id_src2->preg = &R(rt); } while (0)
#define destR() do { id_dest->preg = (rd == 0 ? &zero_null : &R(rd)); } while (0)
#define src1I() do { id_src1->imm = *imm; } while (0)
#define src2I() do { id_src2->imm = *imm; } while (0)
#define destI() do { id_dest->imm = *imm; } while (0)
#else
#define src1R() do { *src1 = R(rs); } while (0)
#define src2R() do { *src2 = R(rt); } while (0)
#define destR() do { *rd_ = rd; } while (0)
#define src1I()
#define src2I()
#define destI()
#endif

static void decode_operand(Decode *s, int *rd_, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rt = BITS(i, 20, 16);
  int rs = BITS(i, 25, 21);
  int rd = (type == TYPE_U || type == TYPE_I) ? rt : BITS(i, 15, 11);
  destR();
  switch (type) {
    case TYPE_U: immU(); src1R(); src2I(); break;
    case TYPE_I: immI(); src1R(); src2I(); break;
    case TYPE_J: immJ(); destI(); goto pc_plus8;
    case TYPE_S: immS(); src1I(); src2R(); break;
    case TYPE_B: immB(); destI(); // fall through
    case TYPE_R: src1R(); src2R(); break;
    case TYPE_jalr: src1R(); // fall through
pc_plus8: IFDEF(CONFIG_PERF_OPT, *imm = s->pc + 8); src2I(); break;
  }
}

static void jcond(bool cond, vaddr_t target) {
  difftest_skip_ref();
  if (cond) cpu.pc = target;
}

static word_t lwl(Decode *s, uint32_t rt, vaddr_t addr) {
  // mem.shmat2
  uint32_t mem_shmat = 24 - ((addr & 0x3) * 8);
  // load the aligned memory word and prepare memory data
  word_t mem_data = Mr((addr & ~0x3u), 4) << mem_shmat;
  // reg.shmat = 24 - mem.shmat2
  uint32_t reg_shmat = 24 - mem_shmat;
  // prepare register data
  word_t reg_data = (R(rt) << (8 + reg_shmat)) >> (8 + reg_shmat);
  // merge the word
  R(rt) = reg_data | mem_data;
  return 0;
}

static word_t lwr(Decode *s, uint32_t rt, vaddr_t addr) {
  // mem.shmat2
  uint32_t mem_shmat = (addr & 0x3) * 8;
  // load the aligned memory word and prepare memory data
  word_t mem_data = Mr((addr & ~0x3u), 4) >> mem_shmat;
  // reg.shmat = 24 - mem.shmat2
  uint32_t reg_shmat = 24 - mem_shmat;
  // prepare register data
  word_t reg_data = (R(rt) >> (8 + reg_shmat)) << (8 + reg_shmat);
  // merge the word
  R(rt) = reg_data | mem_data;
  return 0;
}

static word_t swl(Decode *s, uint32_t rt, vaddr_t addr) {
  // mem.shmat2
  uint32_t mem_shmat = (addr & 0x3) * 8;
  // load the aligned memory word and prepare memory data
  word_t mem_data = Mr((addr & ~0x3u), 4);
  mem_data = (mem_data >> (8 + mem_shmat)) << (8 + mem_shmat);
  // reg.shmat = 24 - mem.shmat2
  uint32_t reg_shmat = 24 - mem_shmat;
  // prepare register data
  word_t reg_data = R(rt) >> reg_shmat;
  // merge the word
  mem_data = reg_data | mem_data;
  // write back
  Mw((addr & ~0x3u), 4, mem_data);
  return 0;
}

static word_t swr(Decode *s, uint32_t rt, vaddr_t addr) {
  // mem.shmat2
  uint32_t mem_shmat = 24 - (addr & 0x3) * 8;
  // load the aligned memory word and prepare memory data
  word_t mem_data = Mr((addr & ~0x3u), 4);
  mem_data = (mem_data << (8 + mem_shmat)) >> (8 + mem_shmat);
  // reg.shmat = 24 - mem.shmat2
  uint32_t reg_shmat = 24 - mem_shmat;
  // prepare register data
  word_t reg_data = R(rt) << reg_shmat;
  // merge the word
  mem_data = reg_data | mem_data;
  // write back
  Mw((addr & ~0x3u), 4, mem_data);
  return 0;
}

static int decode_exec(Decode *s) {
  cpu.pc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  IFDEF(CONFIG_PERF_OPT, return concat(EXEC_ID_, name)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  INSTPAT("000000 00000 ????? ????? ????? 000000", sll    , S, R(rd) = src2 << imm);
  INSTPAT("000000 00000 ????? ????? ????? 000010", srl    , S, R(rd) = src2 >> imm);
  INSTPAT("000000 00000 ????? ????? ????? 000011", sra    , S, R(rd) = (sword_t)src2 >> imm);
  INSTPAT("000000 ????? ????? ????? 00000 000100", sllv   , R, R(rd) = src2 << src1);
  INSTPAT("000000 ????? ????? ????? 00000 000110", srlv   , R, R(rd) = src2 >> src1);
  INSTPAT("000000 ????? ????? ????? 00000 000111", srav   , R, R(rd) = (sword_t)src2 >> src1);
  INSTPAT("000000 ????? 00000 00000 ????? 001000", jr     , R, jcond(true, src1));
  INSTPAT("000000 ????? 00000 ????? ????? 001001", jalr   , jalr, R(rd) = s->pc + 8; jcond(true, src1));
  INSTPAT("000000 ????? ????? ????? 00000 001010", movz   , R, if (src2 == 0) R(rd) = src1);
  INSTPAT("000000 ????? ????? ????? 00000 001011", movn   , R, if (src2 != 0) R(rd) = src1);
  INSTPAT("000000 ????? ????? ????? ????? 001100", syscall, N, cpu.pc = isa_raise_intr(EX_SYSCALL, s->pc));
  INSTPAT("000000 00000 00000 ????? 00000 010000", mfhi   , R, R(rd) = cpu.hi);
  INSTPAT("000000 ????? 00000 00000 00000 010001", mthi   , R, cpu.hi = src1);
  INSTPAT("000000 00000 00000 ????? 00000 010010", mflo   , R, R(rd) = cpu.lo);
  INSTPAT("000000 ????? 00000 00000 00000 010011", mtlo   , R, cpu.lo = src1);
  INSTPAT("000000 ????? ????? 00000 00000 011000", mult   , R,
      uint64_t res = (int64_t)(int32_t)src1 * (int64_t)(int32_t)src2;
      cpu.lo = (uint32_t)res, cpu.hi = res >> 32);
  INSTPAT("000000 ????? ????? 00000 00000 011001", multu  , R,
      uint64_t res = (uint64_t)src1 * src2;
      cpu.lo = (uint32_t)res, cpu.hi = res >> 32);
  INSTPAT("000000 ????? ????? 00000 00000 011010", div    , R, cpu.lo = (int32_t)src1 / (int32_t)src2,
                                                               cpu.hi = (int32_t)src1 % (int32_t)src2);
  INSTPAT("000000 ????? ????? 00000 00000 011011", divu   , R, cpu.lo = src1 / src2, cpu.hi = src1 % src2);
  INSTPAT("000000 ????? ????? ????? 00000 100001", add    , R, R(rd) = src1 + src2);
  INSTPAT("000000 ????? ????? ????? 00000 100011", sub    , R, R(rd) = src1 - src2);
  INSTPAT("000000 ????? ????? ????? 00000 100100", and    , R, R(rd) = src1 & src2);
  INSTPAT("000000 ????? ????? ????? 00000 100101", or     , R, R(rd) = src1 | src2);
  INSTPAT("000000 ????? ????? ????? 00000 100110", xor    , R, R(rd) = src1 ^ src2);
  INSTPAT("000000 ????? ????? ????? 00000 100111", nor    , R, R(rd) = ~(src1 | src2));
  INSTPAT("000000 ????? ????? ????? 00000 101010", slt    , R, R(rd) = (int32_t)src1 < (int32_t)src2);
  INSTPAT("000000 ????? ????? ????? 00000 101011", sltu   , R, R(rd) = src1 < src2);
  INSTPAT("011100 ????? ????? ????? 00000 000010", mul    , R, R(rd) = (int32_t)src1 * (int32_t)src2);
  INSTPAT("011100 ????? ????? ????? 00000 100000", clz    , R, R(rd) = clz(src1));
  INSTPAT("000001 ????? 00000 ????? ????? ??????", bltz   , B, jcond((int32_t)src1 <  0, imm));
  INSTPAT("000001 ????? 00001 ????? ????? ??????", bgez   , B, jcond((int32_t)src1 >= 0, imm));
  INSTPAT("000010 ????? ????? ????? ????? ??????", j      , J, jcond(true, imm));
  INSTPAT("000011 ????? ????? ????? ????? ??????", jal    , J, jcond(true, imm); R(31) = s->pc + 8);
  INSTPAT("000100 ????? ????? ????? ????? ??????", beq    , B, jcond(src1 == src2, imm));
  INSTPAT("000101 ????? ????? ????? ????? ??????", bne    , B, jcond(src1 != src2, imm));
  INSTPAT("000110 ????? ????? ????? ????? ??????", blez   , B, jcond((int32_t)src1 <= 0, imm));
  INSTPAT("000111 ????? ????? ????? ????? ??????", bgtz   , B, jcond((int32_t)src1 >  0, imm));
  INSTPAT("001001 ????? ????? ????? ????? ??????", addi   , I, R(rd) = src1 + imm);
  INSTPAT("001010 ????? ????? ????? ????? ??????", slti   , I, R(rd) = (int32_t)src1 < (int32_t)imm);
  INSTPAT("001011 ????? ????? ????? ????? ??????", sltui  , I, R(rd) = src1 < imm);
  INSTPAT("001100 ????? ????? ????? ????? ??????", andi   , U, R(rd) = src1 & imm);
  INSTPAT("001101 ????? ????? ????? ????? ??????", ori    , U, R(rd) = src1 | imm);
  INSTPAT("001110 ????? ????? ????? ????? ??????", xori   , U, R(rd) = src1 ^ imm);
  INSTPAT("001111 ????? ????? ????? ????? ??????", lui    , U, R(rd) = imm << 16);
  INSTPAT("100000 ????? ????? ????? ????? ??????", lb     , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));
  INSTPAT("100001 ????? ????? ????? ????? ??????", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("100010 ????? ????? ????? ????? ??????", lwl    , I, lwl(s, rd, src1 + imm));
  INSTPAT("100011 ????? ????? ????? ????? ??????", lw     , I, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("100100 ????? ????? ????? ????? ??????", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("100101 ????? ????? ????? ????? ??????", lhu    , I, R(rd) = Mr(src1 + imm, 2));
  INSTPAT("100110 ????? ????? ????? ????? ??????", lwr    , I, lwr(s, rd, src1 + imm));
  INSTPAT("101000 ????? ????? ????? ????? ??????", sb     , I, Mw(src1 + imm, 1, R(rd)));
  INSTPAT("101001 ????? ????? ????? ????? ??????", sh     , I, Mw(src1 + imm, 2, R(rd)));
  INSTPAT("101010 ????? ????? ????? ????? ??????", swl    , I, swl(s, rd, src1 + imm));
  INSTPAT("101011 ????? ????? ????? ????? ??????", sw     , I, Mw(src1 + imm, 4, R(rd)));
  INSTPAT("101110 ????? ????? ????? ????? ??????", swr    , I, swr(s, rd, src1 + imm));

  int rt = BITS(s->isa.inst, 20, 16);
  INSTPAT("010000 00000 ????? ????????????????"  , mfc0   , R, csrrw(&R(rt), NULL, rd));
  INSTPAT("010000 00100 ????? ????????????????"  , mtc0   , R, csrrw(NULL, &R(rt), rd));
  INSTPAT("010000 1 0000000000000000000 001000"  , tlbp   , N, priv_inst(PRIV_TLBP, NULL));
  INSTPAT("010000 1 0000000000000000000 000010"  , tlbwi  , N, priv_inst(PRIV_TLBWI, NULL));
  INSTPAT("010000 1 0000000000000000000 000110"  , tlbwr  , N, priv_inst(PRIV_TLBWR, NULL));
  INSTPAT("010000 1 0000000000000000000 011000"  , eret   , N, cpu.pc = priv_inst(PRIV_ERET, NULL));

  INSTPAT("011100 ????? ????? ????? ????? 111111", sdbbp  , N, NEMUTRAP(s->pc, R(2))); // R(2) is $v0;
  INSTPAT("?????? ????? ????? ????? ????? ??????", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  check_ex(0);
  int idx = decode_exec(s);
#ifdef CONFIG_PERF_OPT
  s->type = INST_TYPE_N;
  switch (idx) {
    case EXEC_ID_j: case EXEC_ID_jal:
      s->jnpc = id_dest->imm; s->type = INST_TYPE_J; break;

    case EXEC_ID_beq: case EXEC_ID_bne: case EXEC_ID_blez:
    case EXEC_ID_bltz: case EXEC_ID_bgez: case EXEC_ID_bgtz:
      s->jnpc = id_dest->imm; s->type = INST_TYPE_B; break;

    case EXEC_ID_ret: case EXEC_ID_jr: case EXEC_ID_jalr:
    case EXEC_ID_eret: case EXEC_ID_syscall:
      s->type = INST_TYPE_I;
  }
#endif
  return idx;
}
#else // __ICS_EXPORT
#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs); } while (0)
#define src2R() do { *src2 = R(rt); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 15, 0), 16); } while(0)
#define immU() do { *imm = BITS(i, 15, 0); } while(0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rt = BITS(i, 20, 16);
  int rs = BITS(i, 25, 21);
  *rd = (type == TYPE_U || type == TYPE_I) ? rt : BITS(i, 15, 11);
  switch (type) {
    case TYPE_I: src1R(); immI(); break;
    case TYPE_U: src1R(); immU(); break;
    case TYPE_N: break;
    default: panic("unsupported type = %d", type);
  }
}

static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  INSTPAT("001111 ????? ????? ????? ????? ??????", lui    , U, R(rd) = imm << 16);
  INSTPAT("100011 ????? ????? ????? ????? ??????", lw     , I, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("101011 ????? ????? ????? ????? ??????", sw     , I, Mw(src1 + imm, 4, R(rd)));

  INSTPAT("011100 ????? ????? ????? ????? 111111", sdbbp  , N, NEMUTRAP(s->pc, R(2))); // R(2) is $v0;
  INSTPAT("?????? ????? ????? ????? ????? ??????", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
#endif
