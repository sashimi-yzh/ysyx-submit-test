/***************************************************************************************
 * Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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
// clang-format off

#include "common.h"
#include "debug.h"
#include "isa-def.h"
#include "isa.h"
#include "local-include/exception.h"
#include "local-include/reg.h"
#include "local-include/csr.h"
#include "local-include/trap-cause.h"
#include "macro.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <memory/lrsc.h>
#include <stdint.h>

#define R(i) gpr(i)

static inline word_t riscv_vaddr_read(vaddr_t addr, int len) {
  if ((addr & (len - 1)) != 0) {
    cpu_throw_exception(EXC_LOAD_ADDR_MISALIGNED, addr);
  }
  return vaddr_read(addr, len);
}

static inline void riscv_vaddr_write(vaddr_t addr, int len, word_t data) {
  if ((addr & (len - 1)) != 0) {
    cpu_throw_exception(EXC_STORE_ADDR_MISALIGNED, addr);
  }
  vaddr_write(addr, len, data);
}

static inline word_t rv32_div(word_t dividend_raw, word_t divisor_raw) {
  int32_t dividend = (int32_t)dividend_raw;
  int32_t divisor = (int32_t)divisor_raw;

  if (divisor == 0) {
    return UINT32_MAX;
  }
  if (dividend == INT32_MIN && divisor == -1) {
    return (uint32_t)dividend;
  }
  return (uint32_t)(dividend / divisor);
}

static inline word_t rv32_mulhsu(word_t multiplicand, word_t multiplier) {
  int64_t lhs = (int64_t)(int32_t)multiplicand;
  int64_t rhs = (int64_t)(uint32_t)multiplier;
  return (uint64_t)(lhs * rhs) >> 32;
}

static inline word_t rv32_divu(word_t dividend, word_t divisor) {
  if (divisor == 0) {
    return UINT32_MAX;
  }
  return dividend / divisor;
}

static inline word_t rv32_rem(word_t dividend_raw, word_t divisor_raw) {
  int32_t dividend = (int32_t)dividend_raw;
  int32_t divisor = (int32_t)divisor_raw;

  if (divisor == 0) {
    return dividend_raw;
  }
  if (dividend == INT32_MIN && divisor == -1) {
    return 0;
  }
  return (uint32_t)(dividend % divisor);
}

static inline word_t rv32_remu(word_t dividend, word_t divisor) {
  if (divisor == 0) {
    return dividend;
  }
  return dividend % divisor;
}

#define Mr riscv_vaddr_read
#define Mw riscv_vaddr_write

static lrsc_reservation_t lrsc_reservation = {};

static word_t ecall_inst();
static word_t mret_inst(Decode *s);
static word_t sret_inst(Decode *s);
static void wfi_inst(void);

static inline word_t lr_w_inst(vaddr_t addr) {
  if ((addr & 0x3) != 0) {
    cpu_throw_exception(EXC_LOAD_ADDR_MISALIGNED, addr);
  }

  paddr_t paddr = isa_mmu_translate(addr, 4, MEM_TYPE_READ);
  return lrsc_load_reserved(&lrsc_reservation, paddr, 4);
}

static inline word_t sc_w_inst(vaddr_t addr, word_t data) {
  if ((addr & 0x3) != 0) {
    cpu_throw_exception(EXC_STORE_ADDR_MISALIGNED, addr);
  }

  paddr_t paddr = isa_mmu_translate(addr, 4, MEM_TYPE_WRITE);
  return lrsc_store_conditional(&lrsc_reservation, paddr, 4, data) ? 0 : 1;
}

#define ECALL cpu_throw_exception(ecall_inst(), 0)
#define MRET s->dnpc = mret_inst(s)
#define SRET s->dnpc = sret_inst(s)

enum {
  TYPE_I, TYPE_U, TYPE_S,
  TYPE_N, TYPE_J, TYPE_R,
  TYPE_B, 
};

enum {
  TYPE_C_N,
  TYPE_CI, TYPE_CI_SHAMT, TYPE_CI16SP, TYPE_C_LUI,
  TYPE_CILWSP, TYPE_CIW, TYPE_CL, TYPE_CS, TYPE_CSS,
  TYPE_CR, TYPE_CA, TYPE_CB, TYPE_CB_IMM, TYPE_CJ,
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do { *imm = SEXT(BITS(i, 31, 31), 1) << 20 | BITS(i, 30, 21) << 1 | BITS(i, 20, 20) << 11 | BITS(i, 19, 12) << 12; } while(0)
#define immB() do { *imm = SEXT(BITS(i, 31, 31), 1) << 12 | BITS(i, 30, 25) << 5 | BITS(i, 11, 8) << 1 | BITS(i, 7, 7) << 11; } while(0)

#define C_BIT(i, n) BITS(i, n, n)
#define C_RD(i) BITS(i, 11, 7)
#define C_RS1(i) BITS(i, 11, 7)
#define C_RS2(i) BITS(i, 6, 2)
#define C_RDP(i) (8 + BITS(i, 4, 2))
#define C_RS1P(i) (8 + BITS(i, 9, 7))
#define C_RS2P(i) (8 + BITS(i, 4, 2))
#define C_IMM_CI(i) SEXT((C_BIT(i, 12) << 5) | BITS(i, 6, 2), 6)
#define C_UIMM_CI(i) ((C_BIT(i, 12) << 5) | BITS(i, 6, 2))
#define C_SHAMT(i) ((C_BIT(i, 12) << 5) | BITS(i, 6, 2))

// clang-format on
#define C_IMM_ADDI4SPN(i)                                                      \
  ((BITS(i, 10, 7) << 6) | (BITS(i, 12, 11) << 4) | (C_BIT(i, 5) << 3) |       \
   (C_BIT(i, 6) << 2))
#define C_IMM_LW(i)                                                            \
  ((C_BIT(i, 5) << 6) | (BITS(i, 12, 10) << 3) | (C_BIT(i, 6) << 2))
#define C_IMM_LWSP(i)                                                          \
  ((BITS(i, 3, 2) << 6) | (C_BIT(i, 12) << 5) | (BITS(i, 6, 4) << 2))
#define C_IMM_SWSP(i) ((BITS(i, 8, 7) << 6) | (BITS(i, 12, 9) << 2))
#define C_IMM_ADDI16SP(i)                                                      \
  SEXT((C_BIT(i, 12) << 9) | (BITS(i, 4, 3) << 7) | (C_BIT(i, 5) << 6) |       \
           (C_BIT(i, 2) << 5) | (C_BIT(i, 6) << 4),                            \
       10)
#define C_IMM_LUI(i) (SEXT((C_BIT(i, 12) << 5) | BITS(i, 6, 2), 6) << 12)
#define C_IMM_CB(i)                                                            \
  SEXT((C_BIT(i, 12) << 8) | (BITS(i, 6, 5) << 6) | (C_BIT(i, 2) << 5) |       \
           (BITS(i, 11, 10) << 3) | (BITS(i, 4, 3) << 1),                      \
       9)
#define C_IMM_CJ(i)                                                            \
  SEXT((C_BIT(i, 12) << 11) | (C_BIT(i, 8) << 10) | (BITS(i, 10, 9) << 8) |    \
           (C_BIT(i, 6) << 7) | (C_BIT(i, 7) << 6) | (C_BIT(i, 2) << 5) |      \
           (C_BIT(i, 11) << 4) | (BITS(i, 5, 3) << 1),                         \
       12)
// clang-format off

static bool csr_read(Decode *s, uint32_t csr_num, uint32_t *data);
static bool csr_write(Decode *s, uint32_t csr_num, uint32_t data);
static bool csr_check_access(Decode *s, uint32_t csr_num, bool write,
                             const char *op);
static void csrrw_inst(Decode *s, int rd, uint32_t csr_num, uint32_t data);
static void csrrs_inst(Decode *s, int rd, uint32_t csr_num, uint32_t data);
static void csrrc_inst(Decode *s, int rd, uint32_t csr_num, uint32_t data);
static void csrrwi_inst(Decode *s, int rd, uint32_t csr_num, uint32_t zimm);
static void csrrsi_inst(Decode *s, int rd, uint32_t csr_num, uint32_t zimm);
static void csrrci_inst(Decode *s, int rd, uint32_t csr_num, uint32_t zimm);
word_t isa_raise_sync_intr(word_t NO, vaddr_t epc, word_t tval);

#define HANDLE_EXCEPTION(s)                                                    \
  CPU_state cpu_backup = cpu;                                                  \
  cpu_exception_begin();                                                       \
  if (setjmp(cpu_exception_env) != 0) {                                        \
    cpu_exception_t exception = *cpu_exception_current();                       \
    cpu_exception_end();                                                       \
    cpu = cpu_backup;                                                          \
    (s)->dnpc =                                                               \
        isa_raise_sync_intr(exception.cause, exception.epc, exception.tval);   \
    return -1;                                                                \
  }

#define END_EXCEPTION() cpu_exception_end()

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst.val;
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
  }
}

// clang-format on
static void decode_operand_c(Decode *s, int *rd, word_t *src1, word_t *src2,
                             word_t *imm, word_t *uimm, int type) {
  uint32_t i = s->isa.inst.val & 0xffff;

  switch (type) {
  case TYPE_CI:
    *rd = C_RD(i);
    *imm = C_IMM_CI(i);
    *uimm = C_UIMM_CI(i);
    break;
  case TYPE_CI_SHAMT:
    *rd = C_RD(i);
    *src1 = R(C_RS1(i));
    *imm = C_SHAMT(i);
    break;
  case TYPE_CI16SP:
    *rd = 2;
    *src1 = R(2);
    *imm = C_IMM_ADDI16SP(i);
    break;
  case TYPE_C_LUI:
    *rd = C_RD(i);
    *imm = C_IMM_LUI(i);
    break;
  case TYPE_CILWSP:
    *rd = C_RD(i);
    *src1 = R(2);
    *imm = C_IMM_LWSP(i);
    break;
  case TYPE_CIW:
    *rd = C_RDP(i);
    *src1 = R(2);
    *uimm = C_IMM_ADDI4SPN(i);
    break;
  case TYPE_CL:
    *rd = C_RDP(i);
    *src1 = R(C_RS1P(i));
    *imm = C_IMM_LW(i);
    break;
  case TYPE_CS:
    *src1 = R(C_RS1P(i));
    *src2 = R(C_RS2P(i));
    *imm = C_IMM_LW(i);
    break;
  case TYPE_CSS:
    *src1 = R(2);
    *src2 = R(C_RS2(i));
    *imm = C_IMM_SWSP(i);
    break;
  case TYPE_CR:
    *rd = C_RD(i);
    *src1 = R(C_RS1(i));
    *src2 = R(C_RS2(i));
    break;
  case TYPE_CA:
    *rd = C_RS1P(i);
    *src2 = R(C_RS2P(i));
    break;
  case TYPE_CB:
    *rd = C_RS1P(i);
    *src1 = R(C_RS1P(i));
    *imm = C_IMM_CB(i);
    *uimm = C_SHAMT(i);
    break;
  case TYPE_CB_IMM:
    *rd = C_RS1P(i);
    *src1 = R(C_RS1P(i));
    *imm = C_IMM_CI(i);
    *uimm = C_SHAMT(i);
    break;
  case TYPE_CJ:
    *imm = C_IMM_CJ(i);
    break;
  }
}
// clang-format off

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
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));

  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
#ifndef CONFIG_FTRACE
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->pc+4;s->dnpc=s->pc+imm;);
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, R(rd)=s->pc+4;s->dnpc=(src1+imm)&~1);
#else // def ftrace
  INSTPAT("??????? ????? ????? 000 ????? 11001 11",jalr,I,R(rd)=s->pc+4;s->dnpc=src1+(imm&~1);dealftrace(s));
  INSTPAT("??????? ????? ????? ??? ????? 11011 11",jal,J,R(rd) = s->pc+4;s->dnpc=s->pc+imm;dealftrace(s));
#endif
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1+imm, 4, src2));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1+imm, 4));
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = src1 < imm);
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(src1 == src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if(src1 != src2) s->dnpc = s->pc + imm);
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = rv32_div(src1, src2));
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if((int)src1 >= (int)src2) s->dnpc = s->pc + imm);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = src1 << imm);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, long t1=(int)src1;long t2=(int)src2;R(rd)=(t1*t2)>>32);
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu , R, R(rd) = rv32_mulhsu(src1, src2));
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = src1 < src2);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if((int)src1 < (int)src2) s->dnpc = s->pc + imm);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = (int)src1 < (int)src2);
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = rv32_rem(src1, src2));
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = (int)src1 >> imm);
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = src1 >> imm);
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (int)src1 >> src2);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = src1 >> src2);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if(src1 < src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1+imm, 2, (uint16_t)src2));
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm);
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = rv32_remu(src1, src2));
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = rv32_divu(src1, src2));
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if(src1 >= src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = (int)src1 < (int)imm);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, uint64_t t = (uint64_t)src1*src2;R(rd) = t >> 32);
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));

  INSTPAT("00001?? ????? ????? 010 ????? 01011 11", amoswap.w, R, R(rd) = Mr(src1, 4);      \
                                                                       Mw(src1, 4, src2));
  INSTPAT("00000?? ????? ????? 010 ????? 01011 11", amoadd.w , R, uint32_t t = Mr(src1, 4);      \
                                                                       R(rd) = t;                           \
                                                                       Mw(src1, 4, src2 + t));
  INSTPAT("01000?? ????? ????? 010 ????? 01011 11", amoor.w  , R, uint32_t t = Mr(src1, 4);      \
                                                                       R(rd) = t;                           \
                                                                       Mw(src1, 4, t | src2));
  INSTPAT("01100?? ????? ????? 010 ????? 01011 11", amoand.w , R, uint32_t t = Mr(src1, 4);      \
                                                                       R(rd) = t;                           \
                                                                       Mw(src1, 4, t & src2));
  INSTPAT("00100?? ????? ????? 010 ????? 01011 11", amoxor.w , R, uint32_t t = Mr(src1, 4);      \
                                                                       R(rd) = t;                           \
                                                                       Mw(src1, 4, t ^ src2));

  INSTPAT("00010?? 00000 ????? 010 ????? 01011 11", lr.w     , R, R(rd) = lr_w_inst(src1));
  INSTPAT("00011?? ????? ????? 010 ????? 01011 11", sc.w     , R, R(rd) = sc_w_inst(src1, src2));

  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, csrrw_inst(s, rd, imm, src1));
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, csrrs_inst(s, rd, imm, src1));
  INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc  , I, csrrc_inst(s, rd, imm, src1));
  INSTPAT("??????? ????? ????? 101 ????? 11100 11", csrrwi , I, csrrwi_inst(s, rd, imm, BITS(s->isa.inst.val, 19, 15)));
  INSTPAT("??????? ????? ????? 110 ????? 11100 11", csrrsi , I, csrrsi_inst(s, rd, imm, BITS(s->isa.inst.val, 19, 15)));
  INSTPAT("??????? ????? ????? 111 ????? 11100 11", csrrci , I, csrrci_inst(s, rd, imm, BITS(s->isa.inst.val, 19, 15)));
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, ECALL);
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , I, MRET);
  INSTPAT("0001000 00010 00000 000 00000 11100 11", sret   , I, SRET);

  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("0000000 00000 00000 001 00000 00011 11", fence.i, I, );
  INSTPAT("0000??? ????? 00000 000 00000 00011 11", fence  , I, );
  INSTPAT("0001000 00101 00000 000 00000 11100 11", wfi    , R, wfi_inst());
  INSTPAT("0001001 ????? ????? 000 00000 11100 11", sfence.vma, R, );

  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}
#undef INSTPAT_MATCH
#undef INSTPAT_INST

static int decode_exec_c(Decode *s) {
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0, uimm = 0;
  s->dnpc = s->snpc;

  #define INSTPAT_INST(s) ((s)->isa.inst.val)
  #define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  decode_operand_c(s, &rd, &src1, &src2, &imm, &uimm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
  }
  INSTPAT_START(c_extern);
  INSTPAT("100 0 ????? 00000 10" , c.jr      , CR    , s->dnpc = src1);
  INSTPAT("100 0 ????? ????? 10" , c.mv      , CR    , R(rd) = src2);
  INSTPAT("100 1 00000 00000 10" , c.ebreak  , C_N   , NEMUTRAP(s->pc, R(10)));
  INSTPAT("100 1 ????? 00000 10" , c.jalr    , CR    , R(1) = s->pc + 2; s->dnpc = src1);
  INSTPAT("100 1 ????? ????? 10" , c.add     , CR    , R(rd) = src1 + src2);
  INSTPAT("000 ? ????? ????? 10" , c.slli    , CI    , R(rd) = R(rd) << uimm);

  INSTPAT("001 ??????????? 01"   , c.jal     , CJ    , R(1) = s->pc+2;s->dnpc=s->pc+imm);
  INSTPAT("000 ? ????? ????? 01" , c.addi    , CI    , R(rd) = R(rd) + imm);
  INSTPAT("010 ? ????? ????? 01" , c.li      , CI    , R(rd) = imm);
  INSTPAT("110 ??????????? 01"   , c.beqz    , CB    , if(src1 == 0) s->dnpc = s->pc + imm);
  INSTPAT("100 ? 00 ??? ????? 01", c.srli    , CB    , R(rd) = R(rd) >> uimm);
  INSTPAT("100 ? 01 ??? ????? 01", c.srai    , CB    , R(rd) = (int32_t)R(rd) >> uimm);
  INSTPAT("100 ? 10 ??? ????? 01", c.andi    , CB_IMM, R(rd) = src1 & imm);
  INSTPAT("111 ??????????? 01"   , c.bnez    , CB    , if(src1 != 0) s->dnpc = s->pc + imm);
  INSTPAT("100011 ??? 00 ??? 01" , c.sub     , CA    , R(rd) = R(rd) - src2);
  INSTPAT("100011 ??? 01 ??? 01" , c.xor     , CA    , R(rd) = R(rd) ^ src2);
  INSTPAT("100011 ??? 10 ??? 01" , c.or      , CA    , R(rd) = R(rd) | src2);
  INSTPAT("100011 ??? 11 ??? 01" , c.and     , CA    , R(rd) = R(rd) & src2);
  INSTPAT("101 ??????????? 01"   , c.j       , CJ    , s->dnpc = s->pc + imm);
  INSTPAT("010 ? ????? ????? 10" , c.lwsp    , CILWSP, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("000 ???????? ??? 00"  , c.addi4spn, CIW   , R(rd) = R(2) + uimm);
  INSTPAT("010 ??? ??? ?? ??? 00", c.lw      , CL    , R(rd) = Mr(src1 + imm, 4));
  INSTPAT("110 ??? ??? ?? ??? 00", c.sw      , CS    , Mw(src1 + imm, 4, src2));
  INSTPAT("011 ? 00010 ????? 01" , c.addi16sp, CI16SP, R(2) = R(2) + imm);
  INSTPAT("011 ? ????? ????? 01" , c.lui     , C_LUI , R(rd) = imm);
  INSTPAT("110 ?????? ????? 10"  , c.swsp    , CSS   , Mw(src1 + imm, 4, src2));

  INSTPAT("???? ????? ????? ??"  , inv       , C_N   , INV(s->pc));
  INSTPAT_END(c_extern);

  R(0) = 0;
  return 0;
}

int isa_exec_once(Decode *s) {
  HANDLE_EXCEPTION(s);

  s->isa.inst.val = inst_fetch(&s->snpc, 2);
  if((s->isa.inst.val & 0b11 ) != 3) {
    int ret = decode_exec_c(s);
    END_EXCEPTION();
    return ret;
  }

  s->isa.inst.val |= (inst_fetch(&s->snpc, 2) << 16);
  int ret = decode_exec(s);
  END_EXCEPTION();
  return ret;
}

static word_t ecall_inst() {
  if (cpu.priv == M_MODE) {
    return EXC_M_ECALL;
  } else if (cpu.priv == S_MODE) {
    return EXC_S_ECALL;
  } else if(cpu.priv == U_MODE) {
    return EXC_U_ECALL;
  } else {
    assert(false && "invalid cpu.priv");
  }
  return 0;
}

static word_t mret_inst(Decode *s) {
  if (cpu.priv != M_MODE) {
    cpu_throw_exception(EXC_ILLEGAL_INST, s->isa.inst.val);
  }
  uint32_t mpp = cpu.csr.mstatus & MSTATUS_MPP_MASK;
  if(mpp == MSTATUS_MPP_M) {
    cpu.priv = M_MODE;
  } else if(mpp == MSTATUS_MPP_S) {
    cpu.priv = S_MODE;
  } else if(mpp == MSTATUS_MPP_U) {
    cpu.priv = U_MODE;
  } else {
    assert(false && "mpp");
  }
  // reset MSTATUS_MPP 
  cpu.csr.mstatus = cpu.csr.mstatus & ~(MSTATUS_MPP_MASK);
  // MSTATUS_MPIE -> MSTATUS_MIE
  // 1 -> MSTATUS_MPIE
  uint32_t mpie = cpu.csr.mstatus & MSTATUS_MPIE;
  cpu.csr.mstatus = (cpu.csr.mstatus & ~(MSTATUS_MIE)) | (mpie >> 4);
  cpu.csr.mstatus = cpu.csr.mstatus | MSTATUS_MPIE;
  if (cpu.priv != M_MODE) {
    cpu.csr.mstatus = cpu.csr.mstatus & ~MSTATUS_MPRV;
  }

  return cpu.csr.mepc;
}

static word_t sret_inst(Decode *s) {
  if (cpu.priv != S_MODE && cpu.priv != M_MODE) {
    cpu_throw_exception(EXC_ILLEGAL_INST, s->isa.inst.val);
  }
  if (cpu.priv == S_MODE && (cpu.csr.mstatus & MSTATUS_TSR)) {
    cpu_throw_exception(EXC_ILLEGAL_INST, s->isa.inst.val);
  }
  uint32_t spp = cpu.csr.mstatus & MSTATUS_SPP;
  if(spp == 0){
    cpu.priv = U_MODE;
  } else {
    cpu.priv = S_MODE;
  }
  cpu.csr.mstatus = cpu.csr.mstatus & ~MSTATUS_SPP;

  uint32_t spie = cpu.csr.mstatus & MSTATUS_SPIE;
  cpu.csr.mstatus = (cpu.csr.mstatus & ~(MSTATUS_SIE)) | (spie >> 4);
  cpu.csr.mstatus = cpu.csr.mstatus | MSTATUS_SPIE;
  cpu.csr.mstatus = cpu.csr.mstatus & ~MSTATUS_MPRV;

  return cpu.csr.sepc;
}

static void wfi_inst(void) {
  difftest_skip_ref();
}

#define CSR_MASK 0xfff

static uint32_t cpu_priv_level() {
  switch (cpu.priv) {
  case U_MODE:
    return 0;
  case S_MODE:
    return 1;
  case M_MODE:
    return 3;
  default:
    assert(false && "invalid cpu.priv");
    return 0;
  }
}

static void raise_illegal_csr_access(Decode *s, uint32_t csr_num,
                                     const char *op, const char *reason,
                                     bool skip_ref) {
  csr_num &= CSR_MASK;
  Log("illegal CSR access: %s, CSR 0x%03x in %s at pc = " FMT_WORD
      ", raise illegal instruction for firmware trap handler",
      reason, csr_num, op, s->pc);
  IFDEF(CONFIG_DIFFTEST, if (skip_ref && difftest_is_attach()) {
    difftest_raise_sync_exception(EXC_ILLEGAL_INST, s->isa.inst.val);
  });
  cpu_throw_exception(EXC_ILLEGAL_INST, s->isa.inst.val);
}

static bool csr_check_access(Decode *s, uint32_t csr_num, bool write,
                             const char *op) {
  csr_num &= CSR_MASK;
  uint32_t csr_priv = BITS(csr_num, 9, 8);
  uint32_t csr_rw = BITS(csr_num, 11, 10);

  if (cpu_priv_level() < csr_priv) {
    raise_illegal_csr_access(s, csr_num, op, "insufficient privilege", false);
    return false;
  }

  if (write && csr_rw == 3) {
    raise_illegal_csr_access(s, csr_num, op, "write read-only CSR", false);
    return false;
  }

  if (!write) {
    uint32_t counteren_bit = counteren_bit_from_csr(csr_num);
    if (!counteren_allows(cpu.priv, cpu.csr.mcounteren, cpu.csr.scounteren,
                          counteren_bit)) {
      raise_illegal_csr_access(s, csr_num, op, "counter disabled", false);
      return false;
    }
  }

  return true;
}

static bool csr_read(Decode *s, uint32_t csr_num, uint32_t *data) {
  csr_num &= CSR_MASK;
  if (!csr_check_access(s, csr_num, false, "read")) {
    return false;
  }
  if (!riscv_csr_read(csr_num, data)) {
    raise_illegal_csr_access(s, csr_num, "read", "unsupported CSR", true);
    return false;
  }
  return true;
}

static bool csr_write(Decode *s, uint32_t csr_num, uint32_t data) {
  csr_num &= CSR_MASK;
  if (!csr_check_access(s, csr_num, true, "write")) {
    return false;
  }
  if (!riscv_csr_write(csr_num, data)) {
    raise_illegal_csr_access(s, csr_num, "write", "unsupported CSR", true);
    return false;
  }
  return true;
}

static void csrrw_inst(Decode *s, int rd, uint32_t csr_num, uint32_t data) {
  uint32_t old = 0;
  if (rd != 0) {
    if (!csr_read(s, csr_num, &old)) {
      return;
    }
  }
  if (!csr_write(s, csr_num, data)) {
    return;
  }
  if (rd != 0) {
    R(rd) = old;
  }
}

static void csrrs_inst(Decode *s, int rd, uint32_t csr_num, uint32_t data) {
  uint32_t old = 0;
  if (!csr_read(s, csr_num, &old)) {
    return;
  }
  if (BITS(s->isa.inst.val, 19, 15) != 0 && !csr_write(s, csr_num, old | data)) {
    return;
  }
  R(rd) = old;
}

static void csrrc_inst(Decode *s, int rd, uint32_t csr_num, uint32_t data) {
  uint32_t old = 0;
  if (!csr_read(s, csr_num, &old)) {
    return;
  }
  if (BITS(s->isa.inst.val, 19, 15) != 0 && !csr_write(s, csr_num, old & ~data)) {
    return;
  }
  R(rd) = old;
}

static void csrrwi_inst(Decode *s, int rd, uint32_t csr_num, uint32_t zimm) {
  uint32_t old = 0;
  if (rd != 0) {
    if (!csr_read(s, csr_num, &old)) {
      return;
    }
  }
  if (!csr_write(s, csr_num, zimm)) {
    return;
  }
  if (rd != 0) {
    R(rd) = old;
  }
}

static void csrrsi_inst(Decode *s, int rd, uint32_t csr_num, uint32_t zimm) {
  uint32_t old = 0;
  if (!csr_read(s, csr_num, &old)) {
    return;
  }
  if (zimm != 0 && !csr_write(s, csr_num, old | zimm)) {
    return;
  }
  R(rd) = old;
}

static void csrrci_inst(Decode *s, int rd, uint32_t csr_num, uint32_t zimm) {
  uint32_t old = 0;
  if (!csr_read(s, csr_num, &old)) {
    return;
  }
  if (zimm != 0 && !csr_write(s, csr_num, old & ~zimm)) {
    return;
  }
  R(rd) = old;
}
