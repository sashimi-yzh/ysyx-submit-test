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
#include <cpu/difftest.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_R, TYPE_B, TYPE_CR, TYPE_CRI,
  TYPE_N, // none
};
static uint64_t branch_cnt=0;
#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do { *imm = ((((((SEXT(BITS(i, 31, 31), 1) << 8) | BITS(i, 19, 12)) << 1) | BITS(i, 20, 20)) << 10) | BITS(i, 30, 21)) << 1; } while(0)
#define immB() do { *imm = ((((((SEXT(BITS(i, 31, 31), 1) << 1) | BITS(i, 7, 7)) << 6) | BITS(i, 30, 25)) << 4) | BITS(i, 11, 8)) << 1; } while(0)
#define immCRI() do { *imm = BITS(i, 19, 15); } while(0)
static void decode_operand(Decode *s, int *rd, int *rcsr, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rcsr = BITS(i, 31, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I:  src1R();          immI(); break;
    case TYPE_U:                    immU(); break;
    case TYPE_S:  src1R(); src2R(); immS(); break;
    case TYPE_J:                    immJ(); break;
    case TYPE_R:  src1R(); src2R();         break;
    case TYPE_B:  src1R(); src2R(); immB(); break;
    case TYPE_CR: src1R();                  break;
    case TYPE_CRI:                immCRI(); break;
    case TYPE_N: break;
    default: panic("unsupported type = %d", type);
  }
}

static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;
  extern void func_trace(Decode *s);
  extern void difftest_skip_ref();
  extern void write_btrace_log(uint32_t pc,uint32_t tar,uint32_t is_jump);
#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0, rcsr = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &rcsr, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}
  // Log("Ready to execute: " FMT_WORD " 0x%08x", s->pc, s->isa.inst);
  if(!(s->pc&0x03)){
    INSTPAT_START();
  
    INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
    INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
    INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, if((s->pc+imm)&0x03)       {s->dnpc = isa_raise_intr(0, s->pc);}else{R(rd) = s->snpc; s->dnpc=s->pc + imm;};func_trace(s););
    INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, if((src1+imm)&0x03)        {s->dnpc = isa_raise_intr(0, s->pc);}else{R(rd) = s->snpc; s->dnpc=src1 + imm;};func_trace(s););
    INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, branch_cnt++;write_btrace_log(s->pc,s->pc + imm,(src1==src2));                  if(src1==src2)                    {if((s->pc + imm)&0x03){s->dnpc = isa_raise_intr(0, s->pc);}else{s->dnpc = s->pc + imm;}}  else{s->dnpc = s->snpc;});
    INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, branch_cnt++;write_btrace_log(s->pc,s->pc + imm,(src1!=src2));                  if(src1!=src2)                    {if((s->pc + imm)&0x03){s->dnpc = isa_raise_intr(0, s->pc);}else{s->dnpc = s->pc + imm;}}  else{s->dnpc = s->snpc;});
    INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, branch_cnt++;write_btrace_log(s->pc,s->pc + imm,((sword_t)src1<(sword_t)src2)); if((sword_t)src1<(sword_t)src2)   {if((s->pc + imm)&0x03){s->dnpc = isa_raise_intr(0, s->pc);}else{s->dnpc = s->pc + imm;}}  else{s->dnpc = s->snpc;});
    INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, branch_cnt++;write_btrace_log(s->pc,s->pc + imm,((sword_t)src1>=(sword_t)src2));if((sword_t)src1>=(sword_t)src2)  {if((s->pc + imm)&0x03){s->dnpc = isa_raise_intr(0, s->pc);}else{s->dnpc = s->pc + imm;}}  else{s->dnpc = s->snpc;});
    INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, branch_cnt++;write_btrace_log(s->pc,s->pc + imm,((word_t)src1<(word_t)src2));   if((word_t)src1<(word_t)src2)     {if((s->pc + imm)&0x03){s->dnpc = isa_raise_intr(0, s->pc);}else{s->dnpc = s->pc + imm;}}  else{s->dnpc = s->snpc;});
    INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, branch_cnt++;write_btrace_log(s->pc,s->pc + imm,((word_t)src1>=(word_t)src2));  if((word_t)src1>=(word_t)src2)    {if((s->pc + imm)&0x03){s->dnpc = isa_raise_intr(0, s->pc);}else{s->dnpc = s->pc + imm;}}  else{s->dnpc = s->snpc;});
    INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));
    INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
    INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
    INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
    INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
    INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
    INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2));
    INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));
    INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = imm + src1);
    INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = (sword_t)src1 < (sword_t)imm ? 1:0);
    INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = (word_t)src1 < (word_t)imm ? 1:0);
    INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm);
    INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm);
    INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
    INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = src1 << (imm & 0x3f));
    INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = (word_t)src1 >> (imm & 0x3f));
    INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = (sword_t)src1 >> (imm & 0x3f));
    INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
    INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
    INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << (src2 & 0x3f));
    INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = (sword_t)src1 < (sword_t)src2 ? 1:0);
    INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = (word_t)src1 < (word_t)src2 ? 1:0);
    INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
    INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = (word_t)src1 >> (src2 & 0x3f));
    INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (sword_t)src1 >> (src2 & 0x3f));
    INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
    INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);


    INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2);
    INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = ((int64_t)(sword_t)src1 * (int64_t)(sword_t)src2)>>32);
    INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu , R, R(rd) = ((int64_t)(sword_t)src1 * (uint64_t)(word_t)src2)>>32);
    INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, R(rd) = ((uint64_t)(word_t)src1 * (uint64_t)(word_t)src2)>>32);
    INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, if(src2==0){R(rd)=0xffffffff;}else if(src2==0xffffffff){R(rd)=src1;}else{R(rd) = (sword_t)src1 / (sword_t)src2;});
    INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, if(src2==0){R(rd)=0xffffffff;}else{R(rd) = (word_t)src1 / (word_t)src2;});
    INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, if(src2==0){R(rd)=src1;}else if(src2==0xffffffff){R(rd)=0;}else{R(rd) = (sword_t)src1 % (sword_t)src2;});
    INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, if(src2==0){R(rd)=src1;}else{R(rd) = (word_t)src1 % (word_t)src2;});

    INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, s->dnpc = isa_raise_intr(11, s->pc));
    INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
    INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , N, s->dnpc = csr(CSR_MEPC));
    INSTPAT("0000000 00000 00000 001 00000 00011 11", fencei , N, do{}while(0););
    
    INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , CR, R(rd) = isa_csr_r(rcsr);isa_csr_w(rcsr, src1););
    INSTPAT("??????? ????? ????? 101 ????? 11100 11", csrrwi ,CRI, R(rd) = isa_csr_r(rcsr);isa_csr_w(rcsr, imm););
    INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , CR, R(rd) = isa_csr_r(rcsr);isa_csr_w(rcsr, isa_csr_r(rcsr) | src1););
    INSTPAT("??????? ????? ????? 110 ????? 11100 11", csrrsi ,CRI, R(rd) = isa_csr_r(rcsr);isa_csr_w(rcsr, isa_csr_r(rcsr) | imm););
    INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc  , CR, R(rd) = isa_csr_r(rcsr);isa_csr_w(rcsr, isa_csr_r(rcsr) & ~src1););
    INSTPAT("??????? ????? ????? 111 ????? 11100 11", csrrci ,CRI, R(rd) = isa_csr_r(rcsr);isa_csr_w(rcsr, isa_csr_r(rcsr) & ~imm););

    
    INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
    INSTPAT_END();
  }else{
    s->dnpc = isa_raise_intr(0, s->pc);
  }
  //printf("NEMU=%08x\n",csr(CSR_MCYCLE));
  csr(CSR_MCYCLE) ++;
  R(0) = 0; // reset $zero to 0
  // Log("Finish executing: " FMT_WORD " 0x%08x", s->pc, s->isa.inst);

  return 0;
}

int isa_exec_once(Decode *s) {
  // if(branch_cnt % 10000 == 0) Log("=%lu=",branch_cnt);
  s->isa.inst = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
