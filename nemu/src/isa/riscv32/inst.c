/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

#define R(i) gpr(i)
#define dest R(rd)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_R, TYPE_I, TYPE_S, TYPE_B, TYPE_U, TYPE_J,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immB() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 12) | (BITS(i, 7, 7) << 11) | \
                  (BITS(i, 30, 25) << 5) | (BITS(i, 11, 8) << 1); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | (BITS(i, 19, 12) << 12) | \
                  (BITS(i, 20, 20) << 11) | (BITS(i, 30, 25) << 5) | (BITS(i, 24, 21) << 1); } while(0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_R: src1R(); src2R();         break;
    case TYPE_I: src1R();          immI(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_B: src1R(); src2R(); immB(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_J:                   immJ(); break;
  }
}

extern bool no_dest;
extern word_t dest_reg_value;

static int decode_exec(Decode *s) {
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0;
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  // RV32I
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, no_dest = false; dest = imm; dest_reg_value = dest);
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, no_dest = false; dest = s->pc + imm; dest_reg_value = dest);
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, no_dest = false; dest = s->snpc; s->dnpc = s->pc + imm; dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, no_dest = false; dest = s->snpc; s->dnpc = ((src1 + imm) & 0xfffffffe); dest_reg_value = dest);

  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, no_dest =  true; if (src1 == src2) s->dnpc = (s->pc + imm));
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, no_dest =  true; if (src1 != src2) s->dnpc = (s->pc + imm));
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, no_dest =  true; if ((int)src1 < (int)src2) s->dnpc = (s->pc + imm));
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, no_dest =  true; if ((int)src1 >= (int)src2) s->dnpc = (s->pc + imm));
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, no_dest =  true; if (src1 < src2) s->dnpc = (s->pc + imm));
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, no_dest =  true; if (src1 >= src2) s->dnpc = (s->pc + imm));

  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, no_dest = false; dest = SEXT(BITS(Mr(src1 + imm, 1), 7, 0), 8); dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, no_dest = false; dest = SEXT(BITS(Mr(src1 + imm, 2), 15, 0), 16); dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, no_dest = false; dest = Mr(src1 + imm, 4); dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, no_dest = false; dest = Mr(src1 + imm, 1); dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, no_dest = false; dest = Mr(src1 + imm, 2); dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, no_dest =  true; Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, no_dest =  true; Mw(src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, no_dest =  true; Mw(src1 + imm, 4, src2));

  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, no_dest = false; dest = src1 + imm; dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, no_dest = false; dest = ((int)src1 < (int)imm) ? 1 : 0; dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, no_dest = false; dest = (src1 < imm) ? 1 : 0; dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, no_dest = false; dest = src1 ^ imm; dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, no_dest = false; dest = src1 | imm; dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, no_dest = false; dest = src1 & imm; dest_reg_value = dest);

  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, no_dest = false; dest = (src1 << BITS(imm, 4, 0)); dest_reg_value = dest);
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, no_dest = false; dest = (src1 >> BITS(imm, 4, 0)); dest_reg_value = dest);
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, no_dest = false; dest = ((int)src1 >> BITS(imm, 4, 0)); dest_reg_value = dest);

  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, no_dest = false; dest = src1 + src2; dest_reg_value = dest);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, no_dest = false; dest = src1 - src2; dest_reg_value = dest);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, no_dest = false; dest = (src1 << BITS(src2, 4, 0)); dest_reg_value = dest);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, no_dest = false; dest = ((int)src1 < (int)src2) ? 1 : 0; dest_reg_value = dest);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, no_dest = false; dest = (src1 < src2) ? 1 : 0; dest_reg_value = dest);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, no_dest = false; dest = src1 ^ src2; dest_reg_value = dest);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, no_dest = false; dest = (src1  >> BITS(src2, 4, 0)); dest_reg_value = dest);
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, no_dest = false; dest = ((int)src1  >> BITS(src2, 4, 0)); dest_reg_value = dest);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, no_dest = false; dest = src1 | src2; dest_reg_value = dest);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, no_dest = false; dest = src1 & src2; dest_reg_value = dest);

  #ifdef CONFIG_TARGET_SHARE
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, no_dest =  true; s->dnpc = isa_raise_intr(R(15), s->pc));
  #else
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, no_dest =  true; s->dnpc = isa_raise_intr(R(17), s->pc));
  #endif
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, no_dest =  true; NEMUTRAP(s->pc, R(10))); // R(10) is $a0
    // Trap-Return
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , N, no_dest =  true; s->dnpc = csr(MEPC));
  // RV32/RV64 Zicsr
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, no_dest = false; dest = csr(imm); csr(imm) = src1; dest_reg_value = dest);
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, no_dest = false; dest = csr(imm); csr(imm) = csr(imm) | src1; dest_reg_value = dest);
  // RV32M
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, no_dest = false; dest = src1 * src2; dest_reg_value = dest);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, no_dest = false; dest = BITS((int64_t)(int)src1 * (int64_t)(int)src2, 63, 32); dest_reg_value = dest);
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu , R, no_dest = false; dest = BITS((int64_t)(int)src1 * (uint64_t)src2, 63, 32); dest_reg_value = dest);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, no_dest = false; dest = BITS((uint64_t)src1 * (uint64_t)src2, 63, 32); dest_reg_value = dest);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, no_dest = false; dest = (int)src1 / (int)src2; dest_reg_value = dest);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, no_dest = false; dest = src1 / src2; dest_reg_value = dest);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, no_dest = false; dest = (int)src1 % (int)src2; dest_reg_value = dest);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, no_dest = false; dest = src1 % src2; dest_reg_value = dest);
  // invalid inst
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, no_dest = true; INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}

#ifdef CONFIG_FTRACE
void ftrace(word_t pc, word_t npc, bool call);

void ftrace_call_ret(Decode *_this) {
  if ( !memcmp(_this->logbuf + 25, "jal\tra", 6) || !memcmp(_this->logbuf + 25, "jalr\tra", 7) ) {
    ftrace(_this->pc, cpu.pc, true);
  }
  if (!memcmp(_this->logbuf + 25, "jalr\tzero, 0(ra)", 16) ) {
    ftrace(_this->pc, cpu.pc, false);
  }
}
#endif /* ifdef CONFIG_FTRACEj */
