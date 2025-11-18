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

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

void ftrace(word_t, word_t, uint32_t, bool, bool);

enum {
  TYPE_I, TYPE_U, TYPE_S,
  TYPE_J, TYPE_R, TYPE_B,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ()                                                                 \
  do {                                                                         \
    *imm = SEXT(BITS(i, 31, 31), 1) << 20 | BITS(i, 19, 12) << 12 |            \
           BITS(i, 20, 20) << 11 | BITS(i, 30, 25) << 5 |                      \
           BITS(i, 24, 21) << 1;                                               \
  } while (0)
#define immB()                                                                 \
  do {                                                                         \
    *imm = SEXT(BITS(i, 31, 31), 1) << 12 | BITS(i, 7, 7) << 11 |              \
           BITS(i, 30, 25) << 5 | BITS(i, 11, 8) << 1;                         \
  } while (0)


static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_J:                   immJ(); break;
    case TYPE_R: src1R(); src2R();         break;
    case TYPE_B: src1R(); src2R(); immB(); break;
    case TYPE_N: break;
    default: panic("unsupported type = %d", type);
  }
}

word_t read_csr(word_t csr) {
  csr &= 0xfff;
  switch (csr) {
  case 0x300:
    return cpu.mstatus;
  case 0x305:
    return cpu.mtvec;
  case 0x341:
    return cpu.mepc;
  case 0x342:
    return cpu.mcause;
  case 0xf11:
    return cpu.mvendorid;
  case 0xf12:
    return cpu.marchid;
  default:
    Assert(0, "others csr:%x are not supported", csr);
    return 0;
  }
}

void write_csr(word_t csr, word_t data) {
  csr &= 0xfff;
  switch (csr) {
  case 0x300:
    cpu.mstatus = data;
    break;
  case 0x305:
    cpu.mtvec = data;
    break;
  case 0x341:
    cpu.mepc = data;
    break;
  case 0x342:
    cpu.mcause = data;
    break;
  case 0xf11:
    cpu.mvendorid = data;
    break;
  case 0xf12:
    cpu.marchid = data;
    break;
  default:
    Assert(0, "others csr:%x are not supported", csr);
    return;
  }
}

FILE* etrace_log = NULL;

void etrace(word_t pc, bool ecall){
  if (ecall) {
    fprintf(etrace_log, FMT_PADDR ":ecall\tnum:%d\n", pc,
            (int32_t)MUXDEF(CONFIG_RVE, gpr(15), gpr(17)));
  } else {
    fprintf(etrace_log, FMT_PADDR ":mret\n", pc);
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

#ifdef CONFIG_MTRACE
  extern bool print_mtrace;
  print_mtrace = true;
#endif

  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->snpc; s->dnpc = s->pc + imm; IFDEF(CONFIG_FTRACE, ftrace(s->pc, s->dnpc, s->isa.inst, 0, 0)); Assert(s->dnpc % 4 == 0, "target address is not aligned to a four-byte boundary"));
  
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, R(rd) = s->snpc; s->dnpc = (src1 + imm) & ~1; IFDEF(CONFIG_FTRACE, ftrace(s->pc, s->dnpc, s->isa.inst, 1, 0)); Assert(s->dnpc % 4 == 0, "target address is not aligned to a four-byte boundary"));

  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if (src1 == src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if (src1 != src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if ((int32_t)src1 < (int32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if ((int32_t)src1 >= (int32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if (src1 < src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if (src1 >= src2) s->dnpc = s->pc + imm);
  
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
  
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));
  
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = (sword_t)src1 < (sword_t)imm);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = src1 < imm);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = src1 << BITS(imm, MUXDEF(CONFIG_ISA_64, 5, 4), 0));
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = src1 >> BITS(imm, MUXDEF(CONFIG_ISA_64, 5, 4), 0));
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = (sword_t)src1 >> BITS(imm, MUXDEF(CONFIG_ISA_64, 5, 4), 0));

  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << BITS(src2, MUXDEF(CONFIG_ISA_64, 5, 4), 0));
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = (sword_t)src1 < (sword_t)src2);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = src1 < src2);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = src1 >> BITS(src2, MUXDEF(CONFIG_ISA_64, 5, 4), 0));
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (sword_t)src1 >> BITS(src2, MUXDEF(CONFIG_ISA_64, 5, 4), 0));
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);

  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2);
  #ifdef CONFIG_ISA64
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = ((__int128_t)(int64_t)src1 * (__int128_t)(int64_t)src2) >> 64);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, R(rd) = ((__int128_t)src1 * (__int128_t)src2) >> 64);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhsu , R, R(rd) = ((__int128_t)(int64_t)src1 * (__int128_t)src2) >> 64);
  #else
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = BITS(SEXT(src1, 32) * SEXT(src2, 32), 63, 32));
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, R(rd) = BITS((uint64_t)src1 * (uint64_t)src2, 63, 32));
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhsu , R, R(rd) = BITS(SEXT(src1, 32) * (uint64_t)src2, 63, 32));
  #endif
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = (sword_t)src1 / (sword_t)src2);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = src1 / src2);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = (sword_t)src1 % (sword_t)src2);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = src1 % src2);

  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, R(rd) = read_csr(imm); write_csr(imm, src1));
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, R(rd) = read_csr(imm); write_csr(imm, read_csr(imm) | src1));
  INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc  , I, R(rd) = read_csr(imm); write_csr(imm, read_csr(imm) & ~src1));
  // Environment call from M-mode use NO.11
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, s->dnpc = isa_raise_intr(11, s->pc); IFDEF(CONFIG_FTRACE, ftrace(s->pc, s->dnpc, s->isa.inst, 0, 0)); IFDEF(CONFIG_ETRACE, etrace(s->pc, 1)));
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , N, s->dnpc = cpu.mepc; IFDEF(CONFIG_FTRACE, ftrace(s->pc, s->dnpc, s->isa.inst, 0, 1)); IFDEF(CONFIG_ETRACE, etrace(s->pc, 0)));
  INSTPAT("??????? ????? ????? 001 ????? 00011 11", fence_i, N, ); //do nothing
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));

  INSTPAT_END();

#ifdef CONFIG_MTRACE
  print_mtrace = false;
#endif

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
