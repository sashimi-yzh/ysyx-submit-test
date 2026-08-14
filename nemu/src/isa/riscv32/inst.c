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

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_R, TYPE_B,
  TYPE_N, // none
};

static inline word_t csr(int num) {
  switch (num) {
    case MEPC_NUM:    return cpu.mepc; break;
    case MSTATUS_NUM: return cpu.mstatus; break;
    case MCAUSE_NUM:  return cpu.mcause; break;
    case MTVEC_NUM:  return cpu.mtvec; break;
    case MVENDORID_NUM: return cpu.mvendorid; break;
    case MARCHID_NUM: return cpu.marchid; break;
    default: Log("num 0x%03x csr is not supported!", num); nemu_state.state = NEMU_ABORT; return 0;
  }
}

static inline void csr_write(int num, word_t data) {
  switch (num) {
    case MEPC_NUM:    cpu.mepc = data; break;
    case MSTATUS_NUM: cpu.mstatus = data; break;
    case MCAUSE_NUM:  cpu.mcause = data; break;
    case MTVEC_NUM:   cpu.mtvec = data; break;
    case MVENDORID_NUM: cpu.mvendorid = data; break;
    case MARCHID_NUM: cpu.marchid = data; break;
    default: Log("num 0x%03x csr is not supported!", num); nemu_state.state = NEMU_ABORT;
  }
}

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immB() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 12) | (BITS(i, 7, 7) << 11) | (BITS(i, 30, 25) << 5) | (BITS(i, 11, 8) << 1); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | (BITS(i, 19, 12) << 12) | (BITS(i, 20, 20) << 11) | (BITS(i, 30, 21) << 1); } while(0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, word_t *rs1_p, word_t* rs2_p, int type) {
  uint32_t i = s->isa.inst;
  word_t rs1 = BITS(i, 19, 15) & MUXDEF(CONFIG_RVE, 0xf, 0x1f);
  word_t rs2 = BITS(i, 24, 20) & MUXDEF(CONFIG_RVE, 0xf, 0x1f);
  *rs1_p = rs1;
  *rs2_p = rs2;
  *rd     = BITS(i, 11,  7) & MUXDEF(CONFIG_RVE, 0xf, 0x1f);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_J: src1R();          immJ(); break;
    case TYPE_R: src1R(); src2R();         break;
    case TYPE_B: src1R(); src2R(); immB(); break;
    case TYPE_N: break;
    default: panic("unsupported type = %d", type);
  }
}

static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0, rs1 = 0, rs2 = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, &rs1, &rs2, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  // U
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
  // I
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = SEXT((Mr(src1 + imm, 1)), 8));
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, R(rd) = s->pc + 4; s->dnpc = (src1 + imm) & (~1); if(rd == 0 && imm == 0 && rs1 == 1) {ftrace_ret(s->pc, s->dnpc);} else if(rd == 1){ftrace_call(s->pc, s->dnpc);});
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = src1 < imm);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = (sword_t)src1 < (sword_t)imm);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm);
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = src1 >> imm);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = src1 << imm);
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = (sword_t)src1 >> (imm & 0x1f));

  // S
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2));
  // J
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->pc + 4; s->dnpc = s->pc + imm; if(rd == 1) {ftrace_call(s->pc, s->dnpc);});
  // B
#ifdef CONFIG_TARGET_SHARE
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if(src1 != src2) {s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(src1 == src2) {s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if((sword_t)src1 >= (sword_t)src2) {s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if((sword_t)src1 < (sword_t)src2) {s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if(src1 < src2) {s->dnpc = s->pc + imm;});
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if(src1 >= src2) {s->dnpc = s->pc + imm;});
#else
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, int flag; if(src1 != src2) {s->dnpc = s->pc + imm; flag = 1;  branch_trace_write(flag, s->pc, s->dnpc);} else {flag = 0; branch_trace_write(flag, s->pc, s->dnpc);});
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(src1 == src2) {s->dnpc = s->pc + imm; int flag = 1; branch_trace_write(flag, s->pc, s->dnpc);} else {int flag = 0; branch_trace_write(flag, s->pc, s->dnpc);});
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if((sword_t)src1 >= (sword_t)src2) {s->dnpc = s->pc + imm; int flag = 1; branch_trace_write(flag, s->pc, s->dnpc);} else {int flag = 0; branch_trace_write(flag, s->pc, s->dnpc);});
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if((sword_t)src1 < (sword_t)src2)  {s->dnpc = s->pc + imm; int flag = 1; branch_trace_write(flag, s->pc, s->dnpc);} else {int flag = 0; branch_trace_write(flag, s->pc, s->dnpc);});
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if(src1 < src2)  {s->dnpc = s->pc + imm; int flag = 1; branch_trace_write(flag, s->pc, s->dnpc);} else {int flag = 0; branch_trace_write(flag, s->pc, s->dnpc);});
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if(src1 >= src2) {s->dnpc = s->pc + imm; int flag = 1; branch_trace_write(flag, s->pc, s->dnpc);} else {int flag = 0; branch_trace_write(flag, s->pc, s->dnpc);});
#endif
  // R
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = src1 < src2);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = (sword_t)src1 < (sword_t)src2);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << src2);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = src1 >> src2);
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (sword_t)src1 >> src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);
  // RV32M
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = (SEXT(src1, 32) * SEXT(src2, 32)) >> 32);
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu , R, R(rd) = (SEXT(src1, 32) * (uint64_t)src2) >> 32);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, R(rd) = ((uint64_t)src1 * (uint64_t)src2) >> 32);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, if(src2 == 0) {R(rd) = -1;} else if(src1 == 0x80000000 && src2 == -1) {R(rd) = 0x80000000;} else {R(rd) = (sword_t)src1 / (sword_t)src2;});
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, if(src2 == 0) {R(rd) = -1;} else {R(rd) = src1 / src2;});
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, if(src2 == 0) {R(rd) = src1;} else if(src1 == 0x80000000 && src2 == -1) {R(rd) = 0;} else {R(rd) = (sword_t)src1 % (sword_t)src2;});
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, if(src2 == 0) {R(rd) = src1;} else {R(rd) = src1 % src2;});
  // RV32Zicsr
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, word_t csr_num = imm & 0xfff; word_t csr_temp = csr(csr_num); R(rd) = csr_temp; csr_write(csr_num, src1));
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, word_t csr_num = imm & 0xfff; word_t csr_temp = csr(csr_num); R(rd) = csr_temp; csr_write(csr_num, csr_temp |  src1));
  INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc  , I, word_t csr_num = imm & 0xfff; word_t csr_temp = csr(csr_num); R(rd) = csr_temp; csr_write(csr_num, csr_temp & ~src1));
  INSTPAT("??????? ????? ????? 101 ????? 11100 11", csrrwi , I, word_t csr_num = imm & 0xfff; word_t csr_temp = csr(csr_num); R(rd) = csr_temp; csr_write(csr_num, rs1));
  INSTPAT("??????? ????? ????? 110 ????? 11100 11", csrrsi , I, word_t csr_num = imm & 0xfff; word_t csr_temp = csr(csr_num); R(rd) = csr_temp; csr_write(csr_num, csr_temp |  rs1));
  INSTPAT("??????? ????? ????? 111 ????? 11100 11", csrrci , I, word_t csr_num = imm & 0xfff; word_t csr_temp = csr(csr_num); R(rd) = csr_temp; csr_write(csr_num, csr_temp & ~rs1));
  // N
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , N, s->dnpc = cpu.mepc;);
  INSTPAT("0000000 00000 00000 001 00000 00011 11", fencei , N, ;);
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, s->dnpc = isa_raise_intr(0xb, s->pc);); // R(10) is $a0
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();
  // ret  : jalr x0, 0(x1)
  // call : jal (rd=x1)
  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
