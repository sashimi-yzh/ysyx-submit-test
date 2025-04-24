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
#define R(i) gpr(i)
#define Mr(addr, len)       ({ word_t tmp = vaddr_read(s, addr, len, MMU_DYNAMIC); check_ex(0); tmp; })
#define Mw(addr, len, data) vaddr_write(s, addr, len, data, MMU_DYNAMIC)
#define Jcond(cond, target) do { if (cond) cpu.pc = target; } while (0)

enum {
  TYPE_2R, TYPE_3R, TYPE_4R,
  TYPE_2RI8, TYPE_2RI12, TYPE_2RI14, TYPE_2RI16,
  TYPE_1RI21, TYPE_I26,
  TYPE_1RI20, TYPE_2RUI5, TYPE_2RUI12, TYPE_CSR, // undocumented
  TYPE_N, // none
};

void csrrd(word_t *dest, uint32_t csrid);
void csrwr(word_t src, uint32_t csrid);
word_t priv_inst(uint32_t op, const word_t *src);

#define uimm5()  do { *imm = BITS(i, 14, 10); } while (0)
#define simm8()  do { *imm = SEXT(BITS(i, 17, 10), 8); } while (0)
#define simm12() do { *imm = SEXT(BITS(i, 21, 10), 12); } while (0)
#define uimm12() do { *imm = BITS(i, 21, 10); } while (0)
#define simm14() do { *imm = SEXT(BITS(i, 23, 10), 14); } while (0)
#define uimm14() do { *imm = BITS(i, 23, 10); } while (0)
#define simm16() do { *imm = SEXT(BITS(i, 25, 10), 16) << 2; } while (0)
#define simm20() do { *imm = SEXT(BITS(i, 24, 5), 20) << 12; } while (0)
#define simm21() do { *imm = SEXT(BITS(i, 4, 0), 5) << 16 | BITS(i, 25, 10); } while (0)
#define simm26() do { *imm = (SEXT(BITS(i, 9, 0), 10) << 16 | BITS(i, 25, 10)) << 2; } while (0)

#ifdef CONFIG_PERF_OPT
#include <isa-all-inst.h>
static word_t zero_null = 0;
#define src1R(n) do { id_src1->preg = &R(n); } while (0)
#define src2R(n) do { id_src2->preg = &R(n); } while (0)
#define destR()  do { id_dest->preg = (n == 0 ? &zero_null : &R(n)); } while (0)
#define src1I(i) do { id_src1->imm = i; } while (0)
#define src2I(i) do { id_src2->imm = i; } while (0)
#define destI(i) do { id_dest->imm = i; } while (0)
#else
#define src1R()  do { *src1 = R(rj); } while (0)
#define src2R()  do { *src2 = R(rk); } while (0)
#define destR()  do { *rd_ = rd; } while (0)
#define src1I(i) do { *src1 = i; } while (0)
#define src2I(i) do { *src2 = i; } while (0)
#define destI(i) do { *dest = i; } while (0)
#endif

static void decode_operand(Decode *s, int *rd_, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rd  = BITS(i, 4, 0);
  int rj = BITS(i, 9, 5);
  int rk = BITS(i, 14, 10);
  destR();
  switch (type) {
    case TYPE_1RI20: simm20(); src1R();          break;
    case TYPE_2R:              src1R();          break;
    case TYPE_2RUI5: uimm5();  src1R();          break;
    case TYPE_2RI8:  simm8();  src1R();          break;
    case TYPE_2RI12: simm12(); src1R();          break;
    case TYPE_2RUI12:uimm12(); src1R();          break;
    case TYPE_2RI16: simm16(); src1R();          break;
    case TYPE_3R:              src1R(); src2R(); break;
    case TYPE_I26:   simm26();                   break;
    case TYPE_CSR:   uimm14();                   break;
    case TYPE_N: break;
    default: panic("unsupported type = %d", type);
  }
}

static int decode_exec(Decode *s) {
  cpu.pc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
  IFDEF(CONFIG_PERF_OPT, return concat(EXEC_ID_, name)); \
  IFNDEF(CONFIG_PERF_OPT, __VA_ARGS__); \
}

  INSTPAT_START();
  INSTPAT("0000 0000 0001 00000 ????? ????? ?????", add.w    , 3R    , R(rd) = src1 + src2);
  INSTPAT("0000 0000 0001 00010 ????? ????? ?????", sub.w    , 3R    , R(rd) = src1 - src2);
  INSTPAT("0000 0000 0001 00100 ????? ????? ?????", slt      , 3R    , R(rd) = (sword_t)src1 < (sword_t)src2);
  INSTPAT("0000 0000 0001 00101 ????? ????? ?????", sltu     , 3R    , R(rd) = src1 < src2);
  INSTPAT("0000 0000 0001 01000 ????? ????? ?????", nor      , 3R    , R(rd) = ~(src1 | src2));
  INSTPAT("0000 0000 0001 01001 ????? ????? ?????", and      , 3R    , R(rd) = src1 & src2);
  INSTPAT("0000 0000 0001 01010 ????? ????? ?????", or       , 3R    , R(rd) = src1 | src2);
  INSTPAT("0000 0000 0001 01011 ????? ????? ?????", xor      , 3R    , R(rd) = src1 ^ src2);
  INSTPAT("0000 0000 0001 01110 ????? ????? ?????", sll.w    , 3R    , R(rd) = src1 << src2);
  INSTPAT("0000 0000 0001 01111 ????? ????? ?????", srl.w    , 3R    , R(rd) = src1 >> src2);
  INSTPAT("0000 0000 0001 10000 ????? ????? ?????", sra.w    , 3R    , R(rd) = (sword_t)src1 >> src2);

  INSTPAT("0000 0000 0001 11000 ????? ????? ?????", mul.w    , 3R    , R(rd) = (sword_t)src1 * (sword_t)src2);
  INSTPAT("0000 0000 0001 11001 ????? ????? ?????", mulh.w   , 3R    , R(rd) = ((int64_t)(sword_t)src1 * (int64_t)(sword_t)src2) >> 32);
  INSTPAT("0000 0000 0001 11010 ????? ????? ?????", mulh.wu  , 3R    , R(rd) = ((uint64_t)src1 * (uint64_t)src2) >> 32);
  INSTPAT("0000 0000 0010 00000 ????? ????? ?????", div.w    , 3R    , R(rd) = (sword_t)src1 / (sword_t)src2);
  INSTPAT("0000 0000 0010 00001 ????? ????? ?????", mod.w    , 3R    , R(rd) = (sword_t)src1 % (sword_t)src2);
  INSTPAT("0000 0000 0010 00010 ????? ????? ?????", div.wu   , 3R    , R(rd) = src1 / src2);
  INSTPAT("0000 0000 0010 00011 ????? ????? ?????", mod.wu   , 3R    , R(rd) = src1 % src2);

  INSTPAT("0000 0000 0100 00001 ????? ????? ?????", slli.w   , 2RUI5 , R(rd) = src1 << imm);
  INSTPAT("0000 0000 0100 01001 ????? ????? ?????", srli.w   , 2RUI5 , R(rd) = src1 >> imm);
  INSTPAT("0000 0000 0100 10001 ????? ????? ?????", srai.w   , 2RUI5 , R(rd) = (sword_t)src1 >> imm);

  INSTPAT("0001010 ????? ????? ????? ????? ?????" , lu12i.w  , 1RI20 , R(rd) = imm);
  INSTPAT("0001110 ????? ????? ????? ????? ?????" , pcaddu12i, 1RI20 , R(rd) = s->pc + imm);

  INSTPAT("00000 01000 ???? ???? ???? ????? ?????", slti     , 2RI12 , R(rd) = (sword_t)src1 < (sword_t)imm);
  INSTPAT("00000 01001 ???? ???? ???? ????? ?????", sltui    , 2RI12 , R(rd) = src1 < imm);
  INSTPAT("00000 01010 ???? ???? ???? ????? ?????", addi.w   , 2RI12 , R(rd) = src1 + imm);
  INSTPAT("00000 01101 ???? ???? ???? ????? ?????", andi     , 2RUI12, R(rd) = src1 & imm);
  INSTPAT("00000 01110 ???? ???? ???? ????? ?????", ori      , 2RUI12, R(rd) = src1 | imm);
  INSTPAT("00000 01111 ???? ???? ???? ????? ?????", xori     , 2RUI12, R(rd) = src1 ^ imm);

  INSTPAT("0000 0100 ???? ????? ????? 00000 ?????", csrrd    , CSR,    csrrd(&R(rd), imm));
  INSTPAT("0000 0100 ???? ????? ????? 00001 ?????", csrwr    , CSR,    csrwr(R(rd), imm));

  INSTPAT("0010100000 ???????????? ????? ?????"   , ld.b     , 2RI12 , R(rd) = SEXT(Mr(src1 + imm, 1), 8));
  INSTPAT("0010100001 ???????????? ????? ?????"   , ld.h     , 2RI12 , R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("0010100010 ???????????? ????? ?????"   , ld.w     , 2RI12 , R(rd) = Mr(src1 + imm, 4));
  INSTPAT("0010100100 ???????????? ????? ?????"   , st.b     , 2RI12 , Mw(src1 + imm, 1, R(rd)));
  INSTPAT("0010100101 ???????????? ????? ?????"   , st.h     , 2RI12 , Mw(src1 + imm, 2, R(rd)));
  INSTPAT("0010100110 ???????????? ????? ?????"   , st.w     , 2RI12 , Mw(src1 + imm, 4, R(rd)));
  INSTPAT("0010101000 ???????????? ????? ?????"   , ld.bu    , 2RI12 , R(rd) = Mr(src1 + imm, 1));
  INSTPAT("0010101001 ???????????? ????? ?????"   , ld.hu    , 2RI12 , R(rd) = Mr(src1 + imm, 2));

  INSTPAT("010011 ???? ???? ???? ???? ????? ?????", jirl     , 2RI16 , Jcond(true, src1 + imm); R(rd) = s->snpc);
  INSTPAT("010100 ???? ???? ???? ???? ????? ?????", b        , I26   , Jcond(true, s->pc + imm));
  INSTPAT("010101 ???? ???? ???? ???? ????? ?????", bl       , I26   , Jcond(true, s->pc + imm); R(1) = s->snpc);
  INSTPAT("010110 ???? ???? ???? ???? ????? ?????", beq      , 2RI16 , Jcond(src1 == R(rd), s->pc + imm));
  INSTPAT("010111 ???? ???? ???? ???? ????? ?????", bne      , 2RI16 , Jcond(src1 != R(rd), s->pc + imm));
  INSTPAT("011000 ???? ???? ???? ???? ????? ?????", blt      , 2RI16 , Jcond((sword_t)src1 <  (sword_t)R(rd), s->pc + imm));
  INSTPAT("011001 ???? ???? ???? ???? ????? ?????", bge      , 2RI16 , Jcond((sword_t)src1 >= (sword_t)R(rd), s->pc + imm));
  INSTPAT("011010 ???? ???? ???? ???? ????? ?????", bltu     , 2RI16 , Jcond(src1 <  R(rd), s->pc + imm));
  INSTPAT("011011 ???? ???? ???? ???? ????? ?????", bgeu     , 2RI16 , Jcond(src1 >= R(rd), s->pc + imm));

  INSTPAT("0000 0000 0010 10110 ????? ????? ?????", syscall  , N     , Jcond(true, isa_raise_intr(0xb, s->pc)));
  INSTPAT("0000 0110 0100 1000 001010 00000 00000", tlbsrch  , N     , priv_inst(PRIV_TLBSRCH, NULL));
  INSTPAT("0000 0110 0100 1000 001100 00000 00000", tlbwr    , N     , priv_inst(PRIV_TLBWR, NULL));
  INSTPAT("0000 0110 0100 1000 001110 00000 00000", ertn     , N     , Jcond(true, priv_inst(PRIV_ERTN, NULL)));
  INSTPAT("0000 0110 0100 10011 ????? ????? ?????", invtlb   , N     , priv_inst(PRIV_INVTLB, NULL));

  INSTPAT("0000 0000 0010 10100 ????? ????? ?????", break    , N     , NEMUTRAP(s->pc, R(4))); // R(4) is $a0
  INSTPAT("????????????????? ????? ????? ?????"   , inv      , N     , INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  check_ex(0);
  return decode_exec(s);
}
#else // __ICS_EXPORT
#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_2RI12, TYPE_1RI20,
  TYPE_N, // none
};

#define src1R()  do { *src1 = R(rj); } while (0)
#define simm12() do { *imm = SEXT(BITS(i, 21, 10), 12); } while (0)
#define simm20() do { *imm = SEXT(BITS(i, 24, 5), 20) << 12; } while (0)

static void decode_operand(Decode *s, int *rd_, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rj = BITS(i, 9, 5);
  *rd_ = BITS(i, 4, 0);
  switch (type) {
    case TYPE_1RI20: simm20(); src1R(); break;
    case TYPE_2RI12: simm12(); src1R(); break;
    case TYPE_N: break;
    default: panic("Unsupport type = %d", type);
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
  INSTPAT("0001110 ????? ????? ????? ????? ?????" , pcaddu12i, 1RI20 , R(rd) = s->pc + imm);
  INSTPAT("0010100010 ???????????? ????? ?????"   , ld.w     , 2RI12 , R(rd) = Mr(src1 + imm, 4));
  INSTPAT("0010100110 ???????????? ????? ?????"   , st.w     , 2RI12 , Mw(src1 + imm, 4, R(rd)));

  INSTPAT("0000 0000 0010 10100 ????? ????? ?????", break    , N     , NEMUTRAP(s->pc, R(4))); // R(4) is $a0
  INSTPAT("????????????????? ????? ????? ?????"   , inv      , N     , INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
#endif
