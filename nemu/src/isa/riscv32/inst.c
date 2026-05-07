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
#define Mr vaddr_read
#define Mw vaddr_write

void trace_call(paddr_t pc, paddr_t target);
void trace_ret(paddr_t pc);

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_UJ, TYPE_SB, TYPE_R, TYPE_ShiftI, TYPE_C,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immUJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) \
                            | (BITS(i, 30, 21) << 1) \
                            | (BITS(i, 20, 20) << 11) \
                            | (BITS(i, 19, 12) << 12); } while(0)
#define immSB() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 12) \
                            | (BITS(i, 30, 25) << 5) \
                            | (BITS(i, 11, 8) << 1) \
                            | (BITS(i, 7, 7) << 11); } while(0)
#define immShiftI() do { *imm = SEXT(BITS(i, 24, 20), 5); } while(0)
#define immC() do { *imm = BITS(i, 31, 20); } while(0)

word_t * csr(word_t imm) {
  switch(imm){
    case 0x300: return &(cpu.csr_mstatus);break;
    case 0x305: return &(cpu.csr_mtvec);break;
    case 0x341: return &(cpu.csr_mepc);break;
    case 0x342: return &(cpu.csr_mcause);break;
    case 0xf11: return &(cpu.csr_mvendorid);break;
    case 0xf12: return &(cpu.csr_marchid);break;
    default: assert(0); return NULL;
  }
} 

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_R: src1R(); src2R();         break;
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_UJ:                  immUJ(); break;
    case TYPE_SB:src1R(); src2R(); immSB(); break;
    case TYPE_ShiftI: src1R();     immShiftI(); break;
    case TYPE_C: src1R();          immC(); break;
  }
}

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
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm;);
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm;);
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    ,UJ, \
          s->dnpc = s->pc + imm;R(rd)=s->pc + 4;\
          IFDEF(CONFIG_FTRACE, \
          {\
            if(rd == 1) {\
              trace_call(s->pc, s->dnpc);\
            }\
          })\
          );
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, \
          s->dnpc = src1 + imm;R(rd)=s->pc + 4;\
          IFDEF(CONFIG_FTRACE, \
          {\
            if (s->isa.inst.val == 0x00008067){\
              trace_ret(s->pc);\
              //printf("ret\n");
            }
            else if (rd == 1)\
              trace_call(s->pc, s->dnpc);\
          })\
          );
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    ,SB, \
          if(src1 == src2){s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    ,SB, \
          if(src1 != src2){s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    ,SB, \
          if(((sword_t)src1) < ((sword_t)src2)){s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    ,SB, \
          if(((sword_t)src1) >= ((sword_t)src2)){s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   ,SB, \
          if(src1 < src2){s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   ,SB, \
          if(src1 >= src2){s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = SEXT(BITS(Mr(src1 + imm, 1), 7, 0), 8) ;);
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(BITS(Mr(src1 + imm, 2), 15, 0), 16););
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4););
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1););
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2););
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2););
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2););
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2););
  
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm;);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm;);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, \
            if(((sword_t)src1) < ((sword_t)imm)) R(rd) = 1;\
            else R(rd) = 0;);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, \
            if(src1 < imm) R(rd) = 1;\
            else R(rd) = 0;); 
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm;);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm;);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , ShiftI, R(rd) = src1 << imm;);
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , ShiftI, R(rd) = src1 >> imm;);
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , ShiftI, R(rd) = (sword_t)src1 >> ((sword_t)imm););
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2;);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2;);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << src2;);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, \
            if((sword_t)src1 < (sword_t)src2) R(rd) = 1;\
            else R(rd) = 0;); 
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, \
            if(src1 < src2) R(rd) = 1;\
            else R(rd) = 0;); 
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2;);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = src1 >> src2;);
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (sword_t)src1 >> ((sword_t)src2););
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2;);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2;);

  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, \
            int64_t tmp = (int64_t)src1 * (int64_t)src2;
            R(rd) = BITS(tmp, 31, 0););
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, \
            int64_t tmp = SEXT(BITS((sword_t)src1, 31, 0), 32) * SEXT(BITS((sword_t)src2, 31, 0), 32);
            ///int64_t tmp = (int64_t)((sword_t)src1) * (int64_t)((sword_t)src2);
            R(rd) = BITS(tmp, 63, 32););
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, \
            //uint64_t tmp = SEXT(BITS(src1, 31, 0), 32) * SEXT(BITS(src2, 31, 0), 32);
            uint64_t tmp = (uint64_t)(src1) * (uint64_t)(src2);
            R(rd) = BITS(tmp, 63, 32););
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = (sword_t)src1 / (sword_t)src2;);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = src1 / src2;);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = (sword_t)src1 % (sword_t)src2;);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = src1 % src2;);
#ifdef __riscv_e
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, bool a; \
            s->dnpc = isa_raise_intr(isa_reg_str2val("a5",&a),s->pc);\
            IFDEF(CONFIG_ETRACE,\
              Log("mepc="FMT_PADDR", mcause="FMT_PADDR,cpu.csr_mepc,cpu.csr_mcause)\
            );); 
#else
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, bool a; \
            s->dnpc = isa_raise_intr(isa_reg_str2val("a7",&a),s->pc);\
            IFDEF(CONFIG_ETRACE,\
              Log("mepc="FMT_PADDR", mcause="FMT_PADDR,cpu.csr_mepc,cpu.csr_mcause)\
            );); 
#endif
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , N, s->dnpc = cpu.csr_mepc;);
            //cpu.csr_mstatus &= ~(1<<3);             cpu.csr_mstatus |= ((cpu.csr_mstatus&(1<<7))>>4);            cpu.csr_mstatus |= 1<<7);
  
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , C, R(rd) = *(csr(imm)); *(csr(imm)) = src1;);
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , C, R(rd) = *(csr(imm)); *(csr(imm)) = src1 | *(csr(imm)););
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
