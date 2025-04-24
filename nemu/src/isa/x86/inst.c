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

typedef union {
  struct {
    uint8_t R_M		:3;
    uint8_t reg		:3;
    uint8_t mod		:2;
  };
  struct {
    uint8_t dont_care	:3;
    uint8_t opcode		:3;
  };
  uint8_t val;
} ModR_M;

typedef union {
  struct {
    uint8_t base	:3;
    uint8_t index	:3;
    uint8_t ss		:2;
  };
  uint8_t val;
} SIB;

static word_t x86_inst_fetch(Decode *s, int len) {
#if defined(CONFIG_ITRACE) || defined(CONFIG_IQUEUE)
  uint8_t *p = &s->isa.inst[s->snpc - s->pc];
  word_t ret = inst_fetch(&s->snpc, len);
  word_t ret_save = ret;
  int i;
  assert(s->snpc - s->pc < sizeof(s->isa.inst));
  for (i = 0; i < len; i ++) {
    p[i] = ret & 0xff;
    ret >>= 8;
  }
  return ret_save;
#else
  return inst_fetch(&s->snpc, len);
#endif
}

word_t reg_read(int idx, int width) {
  switch (width) {
    case 4: return reg_l(idx);
    case 1: return reg_b(idx);
    case 2: return reg_w(idx);
    default: assert(0);
  }
}

static void reg_write(int idx, int width, word_t data) {
  switch (width) {
    case 4: reg_l(idx) = data; return;
    case 1: reg_b(idx) = data; return;
    case 2: reg_w(idx) = data; return;
    default: assert(0);
  }
}

static void load_addr(Decode *s, ModR_M *m, word_t *rm_addr) {
  assert(m->mod != 3);

  sword_t disp = 0;
  int disp_size = 4;
  int base_reg = -1, index_reg = -1, scale = 0;

  if (m->R_M == R_ESP) {
    SIB sib;
    sib.val = x86_inst_fetch(s, 1);
    base_reg = sib.base;
    scale = sib.ss;

    if (sib.index != R_ESP) { index_reg = sib.index; }
  }
  else { base_reg = m->R_M; } /* no SIB */

  if (m->mod == 0) {
    if (base_reg == R_EBP) { base_reg = -1; }
    else { disp_size = 0; }
  }
  else if (m->mod == 1) { disp_size = 1; }

  if (disp_size != 0) { /* has disp */
    disp = x86_inst_fetch(s, disp_size);
    if (disp_size == 1) { disp = (int8_t)disp; }
  }

  word_t addr = disp;
  if (base_reg != -1)  addr += reg_l(base_reg);
  if (index_reg != -1) addr += reg_l(index_reg) << scale;
  *rm_addr = addr;
}

static void decode_rm(Decode *s, int *rm_reg, word_t *rm_addr, int *reg, int width) {
  ModR_M m;
  m.val = x86_inst_fetch(s, 1);
  if (reg != NULL) *reg = m.reg;
  if (m.mod == 3) *rm_reg = m.R_M;
  else { load_addr(s, &m, rm_addr); *rm_reg = -1; }
}

#define Rr reg_read
#define Rw reg_write
#ifndef __ICS_EXPORT
#define Mr(addr, len)       vaddr_read(s, addr, len, MMU_DYNAMIC)
#define Mw(addr, len, data) vaddr_write(s, addr, len, data, MMU_DYNAMIC)
#else
#define Mr vaddr_read
#define Mw vaddr_write
#endif
#define RMr(reg, w)  (reg != -1 ? Rr(reg, w) : Mr(addr, w))
#define RMw(data) do { if (rd != -1) Rw(rd, w, data); else Mw(addr, w, data); } while (0)

#define destr(r)  do { *rd_ = (r); } while (0)
#define src1r(r)  do { *src1 = Rr(r, w); } while (0)
#define imm()     do { *imm = x86_inst_fetch(s, w); } while (0)
#define simm(w)   do { *imm = SEXT(x86_inst_fetch(s, w), w * 8); } while (0)

enum {
  TYPE_r, TYPE_I, TYPE_SI, TYPE_J, TYPE_E,
  TYPE_I2r,  // XX <- Ib / eXX <- Iv
  TYPE_I2a,  // AL <- Ib / eAX <- Iv
  TYPE_G2E,  // Eb <- Gb / Ev <- Gv
  TYPE_E2G,  // Gb <- Eb / Gv <- Ev
  TYPE_I2E,  // Eb <- Ib / Ev <- Iv
  TYPE_Ib2E, TYPE_cl2E, TYPE_1_E, TYPE_SI2E,
  TYPE_Eb2G, TYPE_Ew2G,
  TYPE_O2a, TYPE_a2O,
  TYPE_I_E2G,  // Gv <- EvIb / Gv <- EvIv // use for imul
  TYPE_SI_E2G,  // Gv <- EvIb / Gv <- EvIv // use for imul
  TYPE_Ib_G2E, // Ev <- GvIb // use for shld/shrd
  TYPE_cl_G2E, // Ev <- GvCL // use for shld/shrd
  TYPE_N, // none
};

#ifndef __ICS_EXPORT
#define INSTPAT_INST(s) opcode
#define INSTPAT_MATCH(s, name, type, width, ... /* execute body */ ) { \
  int rd = 0, rs = 0, gp_idx = 0; \
  word_t src1 = 0, addr = 0, imm = 0; \
  int w = width == 0 ? (is_operand_size_16 ? 2 : 4) : width; \
  decode_operand(s, opcode, &rd, &src1, &addr, &rs, &gp_idx, &imm, w, concat(TYPE_, type)); \
  cpu.pc = s->snpc; \
  __VA_ARGS__ ; \
}

uint32_t pio_read(ioaddr_t addr, int len);
void pio_write(ioaddr_t addr, int len, uint32_t data);
uint32_t bit_scan(uint32_t x, bool reverse);
word_t iret();

static bool msb(word_t x, int width) { return (x >> (width * 8 - 1)) & 0x1; }

static word_t sext(word_t x, int width) {
  int shamt = (4 - width) * 8;
  return (sword_t)(x << shamt) >> shamt;
}

static void decode_operand(Decode *s, uint8_t opcode, int *rd_, word_t *src1,
    word_t *addr, int *rs, int *gp_idx, word_t *imm, int w, int type) {
  switch (type) {
    case TYPE_r:    destr(opcode & 0x7); src1r(opcode & 0x7); break;
    case TYPE_I:    imm(); break;
    case TYPE_SI:   simm(1); break;
    case TYPE_E:    decode_rm(s, rd_, addr, gp_idx, w); break;
    case TYPE_J:    if (w == 4) imm(); else simm(1); break;
    case TYPE_I2r:  destr(opcode & 0x7); imm(); break;
    case TYPE_I2a:  destr(R_EAX); imm(); break;
    case TYPE_G2E:  decode_rm(s, rd_, addr, rs, w); src1r(*rs); break;
    case TYPE_E2G:  decode_rm(s, rs, addr, rd_, w); break;
    case TYPE_I2E:  decode_rm(s, rd_, addr, gp_idx, w); imm(); break;
    case TYPE_Ib2E: decode_rm(s, rd_, addr, gp_idx, w); *src1 = x86_inst_fetch(s, 1); break;
    case TYPE_cl2E: decode_rm(s, rd_, addr, gp_idx, w); *src1 = Rr(R_CL, 1) & 0x1f; break;
    case TYPE_1_E:  decode_rm(s, rd_, addr, gp_idx, w); *src1 = 1; break;
    case TYPE_SI2E: decode_rm(s, rd_, addr, gp_idx, w); simm(1);
                    if (w == 2) { *imm &= 0xffff; }
                    break;
    case TYPE_Eb2G: decode_rm(s, rs, addr, rd_, 1); break;
    case TYPE_Ew2G: decode_rm(s, rs, addr, rd_, 2); break;
    case TYPE_O2a:  destr(R_EAX); *addr = x86_inst_fetch(s, 4); break;
    case TYPE_a2O:  *rs = R_EAX;  *addr = x86_inst_fetch(s, 4); break;
    case TYPE_I_E2G:  decode_rm(s, rs, addr, rd_, w); *imm = sext(x86_inst_fetch(s, w), w); break;
    case TYPE_SI_E2G: decode_rm(s, rs, addr, rd_, w); simm(1); break;
    case TYPE_Ib_G2E: decode_rm(s, rd_, addr, rs, w); *imm = x86_inst_fetch(s, 1); break;
    case TYPE_cl_G2E: decode_rm(s, rd_, addr, rs, w); *src1 = Rr(R_CL, 1) & 0x1f;; break;
    case TYPE_N: break;
    default: panic("type = %d at pc = " FMT_WORD , type, s->pc);
  }
}

#define push(data) do { Mw(cpu.esp - 4, 4, data); cpu.esp -= 4; } while (0)
#define pop()      (cpu.esp += 4, Mr(cpu.esp - 4, 4))

static void jcond(bool cond, vaddr_t target) {
  if (cond) cpu.pc = target;
}

static void update_ZFSF(word_t res, int width) {
  cpu.ZF = (res & (0xffffffffu >> ((4 - width) * 8))) == 0;
  cpu.SF = msb(res, width);
}

static bool is_sub_carry(word_t src1, word_t src2) {
  return src1 < src2;
}

static bool is_sub_overflow(word_t res, word_t src1, word_t src2, int width) {
  return msb((src1 ^ src2) & (src1 ^ res), width);
}

static bool is_add_carry(word_t res, word_t src1) {
  return is_sub_carry(res, src1);
}

static bool is_add_overflow(word_t res, word_t src1, word_t src2, int width) {
  return is_sub_overflow(src1, res, src2, width);
}

static void update_eflags_logic(word_t res, int width) {
  update_ZFSF(res, width);
  cpu.CF = 0;
  cpu.OF = 0;
}

static word_t add(word_t src1, word_t src2, int width) {
  word_t res = src1 + src2;
  update_ZFSF(res, width);
  if (width != 4) res = (res & (0xffffffffu >> ((4 - width) * 8)));
  cpu.CF = is_add_carry(res, src1);
  cpu.OF = is_add_overflow(res, src1, src2, width);
  return res;
}

static word_t sub(word_t src1, word_t src2, int width) {
  word_t res = src1 - src2;
  update_ZFSF(res, width);
  cpu.CF = is_sub_carry(src1, src2);
  cpu.OF = is_sub_overflow(res, src1, src2, width);
  return res;
}

static word_t adc(word_t src1, word_t src2, int width) {
  word_t t = src2 + cpu.CF;
  word_t res = src1 + t;
  update_ZFSF(res, width);
  cpu.OF = is_add_overflow(res, src1, src2, width);
  if (width != 4) res = (res & (0xffffffffu >> ((4 - width) * 8)));
  cpu.CF = is_add_carry(res, t) || is_add_carry(t, src2);
  return res;
}

static word_t sbb(word_t src1, word_t src2, int width) {
  word_t t = src2 + cpu.CF;
  word_t res = src1 - t;
  update_ZFSF(res, width);
  cpu.CF = is_add_carry(t, src2) || is_sub_carry(src1, t);
  cpu.OF = is_sub_overflow(res, src1, src2, width);
  return res;
}

static word_t and(word_t src1, word_t src2, int width) {
  word_t res = src1 & src2;
  update_eflags_logic(res, width);
  return res;
}
static word_t or(word_t src1, word_t src2, int width) {
  word_t res = src1 | src2;
  update_eflags_logic(res, width);
  return res;
}

void _2byte_esc(Decode *s, bool is_operand_size_16) {
  uint8_t opcode = x86_inst_fetch(s, 1);

  INSTPAT_START();

  INSTPAT("0000 0000", gp7,    E,    2, switch (gp_idx) {
                                          case 0b011: cpu.sreg[CSR_TR].val = RMr(rd, w); break;
                                          default: INV(s->pc);
                                        });
  INSTPAT("0000 0001", gp7,    E,    4, switch (gp_idx) {
                                          case 0b010: cpu.gdtr.limit = Mr(addr, 2); cpu.gdtr.base  = Mr(addr + 2, 4); break;
                                          case 0b011: cpu.idtr.limit = Mr(addr, 2); cpu.idtr.base  = Mr(addr + 2, 4); break;
                                          default: INV(s->pc);
                                        });

  INSTPAT("0010 0000", mov_cr, G2E,  4, RMw(cpu.cr[rs]));
  INSTPAT("0010 0010", mov_cr, E2G,  4, cpu.cr[rd] = RMr(rs, w));

  INSTPAT("1000 0010", jb,     J,    4, jcond(cpu.CF, s->snpc + imm));
  INSTPAT("1000 0011", jae,    J,    4, jcond(!cpu.CF, s->snpc + imm));
  INSTPAT("1000 0100", je,     J,    4, jcond(cpu.ZF, s->snpc + imm));
  INSTPAT("1000 0101", jne,    J,    4, jcond(!cpu.ZF, s->snpc + imm));
  INSTPAT("1000 0110", jbe,    J,    4, jcond(cpu.CF | cpu.ZF, s->snpc + imm));
  INSTPAT("1000 0111", ja,     J,    4, jcond(!(cpu.CF | cpu.ZF), s->snpc + imm));
  INSTPAT("1000 1000", js,     J,    4, jcond(cpu.SF, s->snpc + imm));
  INSTPAT("1000 1001", jns,    J,    4, jcond(!cpu.SF, s->snpc + imm));
  INSTPAT("1000 1101", jge,    J,    4, jcond(!(cpu.SF ^ cpu.OF), s->snpc + imm));
  INSTPAT("1000 1110", jle,    J,    4, jcond((cpu.SF ^ cpu.OF) | cpu.ZF, s->snpc + imm));
  INSTPAT("1000 1100", jl,     J,    4, jcond(cpu.SF ^ cpu.OF, s->snpc + imm));
  INSTPAT("1000 1111", jg,     J,    4, jcond(!((cpu.SF ^ cpu.OF) | cpu.ZF), s->snpc + imm));

  INSTPAT("1001 0010", setb,   E,    1, RMw(cpu.CF));
  INSTPAT("1001 0011", setae,  E,    1, RMw(!cpu.CF));
  INSTPAT("1001 0100", sete,   E,    1, RMw(cpu.ZF));
  INSTPAT("1001 0101", setne,  E,    1, RMw(!cpu.ZF));
  INSTPAT("1001 0110", setbe,  E,    1, RMw(cpu.CF | cpu.ZF));
  INSTPAT("1001 1100", setl,   E,    1, RMw(cpu.SF ^ cpu.OF));
  INSTPAT("1001 1110", setle,  E,    1, RMw((cpu.SF ^ cpu.OF) | cpu.ZF));
  INSTPAT("1001 1111", setg,   E,    1, RMw(!((cpu.SF ^ cpu.OF) | cpu.ZF)));

  INSTPAT("1010 0100", shld,   Ib_G2E, 4, RMw((RMr(rd, w) << imm) | (Rr(rs, w) >> (31 - imm) >> 1)));
  INSTPAT("1010 0101", shld,   cl_G2E, 4, RMw((RMr(rd, w) << src1) | (Rr(rs, w) >> (31 - src1) >> 1)));
  INSTPAT("1010 1100", shrd,   Ib_G2E, 4, RMw((RMr(rd, w) >> imm) | (Rr(rs, w) << (31 - imm) << 1)));
  INSTPAT("1010 1111", imul,   E2G,  0, Rw(rd, w, RMr(rs, w) * Rr(rd, w)));

  INSTPAT("1011 0110", movzbl, Eb2G, 0, Rw(rd, w, RMr(rs, 1)));
  INSTPAT("1011 0111", movzbl, Ew2G, 4, Rw(rd, w, RMr(rs, 2)));
  INSTPAT("1011 1101", bsr,    E2G,  0, Rw(rd, w, bit_scan(RMr(rs, w), true)));
  INSTPAT("1011 1110", movsbl, Eb2G, 0, Rw(rd, w, sext(RMr(rs, 1), 1)));
  INSTPAT("1011 1111", movswl, Ew2G, 4, Rw(rd, w, sext(RMr(rs, 2), 2)));

  INSTPAT("???? ????", inv,    N,    0, INV(s->pc));

  INSTPAT_END();
}

static void mul(Decode *s, word_t src, int width) {
  switch (width) {
    case 1: Rw(R_AX, 2, src * reg_b(R_AL)); break;
    case 4: {
      uint64_t res = (uint64_t)src * cpu.eax;
      cpu.edx = res >> 32;
      cpu.eax = (uint32_t)res;
      break;
    }
    default: INV(s->pc);
  }
}

static void imul(Decode *s, word_t src, int width) {
  switch (width) {
    case 4: {
      int64_t res = (int64_t)(int32_t)src * (int64_t)(int32_t)cpu.eax;
      cpu.edx = res >> 32;
      cpu.eax = (uint32_t)res;
      break;
    }
    default: assert(0);
  }
}

#define do_div(type, _dividend, _divisor, q, r) do { \
  type dividend = _dividend, divisor = _divisor; \
  q = dividend / divisor; r = dividend % divisor; \
} while (0)

static void div_(Decode *s, word_t src, int width) {
  switch (width) {
    case 1: do_div(uint32_t, reg_w(R_AX), src, reg_b(R_AL), reg_b(R_AH)); break;
    case 2: do_div(uint32_t, (reg_w(R_DX) << 16) | reg_w(R_AX), src, reg_w(R_AX), reg_w(R_DX)); break;
    case 4: do_div(uint64_t, ((uint64_t)cpu.edx << 32) | cpu.eax, src, cpu.eax, cpu.edx); break;
    default: INV(s->pc);
  }
}

static void idiv(Decode *s, word_t src, int width) {
  switch (width) {
    case 2: do_div(int32_t, (reg_w(R_DX) << 16) | reg_w(R_AX), src, reg_w(R_AX), reg_w(R_DX)); break;
    case 4: do_div(int64_t, ((uint64_t)cpu.edx << 32) | cpu.eax, src, cpu.eax, cpu.edx); break;
    default: INV(s->pc);
  }
}

#define gp1() do { \
  switch (gp_idx) { \
    case 0b000: RMw(add(RMr(rd, w), imm, w)); break; \
    case 0b001: RMw(or(RMr(rd, w), imm, w)); break; \
    case 0b010: RMw(adc(RMr(rd, w), imm, w)); break; \
    case 0b011: RMw(sbb(RMr(rd, w), imm, w)); break; \
    case 0b100: RMw(and(RMr(rd, w), imm, w)); break; \
    case 0b101: RMw(sub(RMr(rd, w), imm, w)); break; \
    case 0b110: RMw(RMr(rd, w) ^ imm); break; \
    case 0b111: sub(RMr(rd, w), imm, w); break; \
    default: INV(s->pc); \
  }; \
} while (0)

#define gp2() do { \
  word_t res = 0; \
  switch (gp_idx) { \
    case 0b000: res = (RMr(rd, w) << src1) | (RMr(rd, w) >> ((w * 8) - src1)); break; \
    case 0b001: res = (RMr(rd, w) >> src1) | (RMr(rd, w) << ((w * 8) - src1)); break; \
    case 0b100: res = RMr(rd, w) << src1; break; \
    case 0b101: res = RMr(rd, w) >> src1; break; \
    case 0b111: res = (sword_t)sext(RMr(rd, w), w) >> src1; break; \
    default: INV(s->pc); \
  }; \
  RMw(res); \
  update_eflags_logic(res, w); \
} while (0)

#define gp3() do { \
  switch (gp_idx) { \
    case 0b000: and(RMr(rd, w), x86_inst_fetch(s, w), w); cpu.pc += w; break; \
    case 0b010: RMw(~RMr(rd, w)); break; \
    case 0b011: RMw(-RMr(rd, w)); break; \
    case 0b100: mul(s, RMr(rd, w), w); break; \
    case 0b101: imul(s, RMr(rd, w), w); break; \
    case 0b110: div_(s, RMr(rd, w), w); break; \
    case 0b111: idiv(s, RMr(rd, w), w); break; \
    default: INV(s->pc); \
  }; \
} while (0)

int isa_exec_once(Decode *s) {
  bool is_operand_size_16 = false;
  uint8_t opcode = 0;

again:
  opcode = x86_inst_fetch(s, 1);

  INSTPAT_START();

  INSTPAT("0000 0000", add,       G2E,  1, RMw(add(RMr(rd, w), src1, w)));
  INSTPAT("0000 0001", add,       G2E,  0, RMw(add(RMr(rd, w), src1, w)));
  INSTPAT("0000 0010", add,       E2G,  1, Rw(rd, w, add(RMr(rs, w), Rr(rd, w), w)));
  INSTPAT("0000 0011", add,       E2G,  0, Rw(rd, w, add(RMr(rs, w), Rr(rd, w), w)));
  INSTPAT("0000 0101", add,       I2a,  0, Rw(R_EAX, w, add(Rr(R_EAX, w), imm, w)));
  INSTPAT("0000 1000", or,        G2E,  1, RMw(or(RMr(rd, w), src1, w)));
  INSTPAT("0000 1001", or,        G2E,  0, RMw(or(RMr(rd, w), src1, w)));
  INSTPAT("0000 1010", or,        E2G,  1, Rw(rd, w, or(RMr(rs, w), Rr(rd, w), w)));
  INSTPAT("0000 1011", or,        E2G,  0, Rw(rd, w, or(RMr(rs, w), Rr(rd, w), w)));
  INSTPAT("0000 1101", or,        I2a,  0, Rw(R_EAX, w, or(Rr(R_EAX, w), imm, w)));
  INSTPAT("0000 1111", 2byte_esc, N,    0, _2byte_esc(s, is_operand_size_16));

  INSTPAT("0001 0001", adc,       G2E,  0, RMw(adc(RMr(rd, w), src1, w)));
  INSTPAT("0001 0011", adc,       E2G,  0, Rw(rd, w, adc(RMr(rs, w), Rr(rd, w), w)));
  INSTPAT("0001 1000", sbb,       G2E,  1, RMw(sbb(RMr(rd, w), src1, w)));
  INSTPAT("0001 1001", sbb,       G2E,  0, RMw(sbb(RMr(rd, w), src1, w)));
  INSTPAT("0001 1011", sbb,       E2G,  0, Rw(rd, w, sbb(Rr(rd, w), RMr(rs, w), w)));

  INSTPAT("0010 0000", and,       G2E,  1, RMw(and(RMr(rd, w), src1, w)));
  INSTPAT("0010 0001", and,       G2E,  0, RMw(and(RMr(rd, w), src1, w)));
  INSTPAT("0010 0010", and,       E2G,  1, Rw(rd, w, and(RMr(rs, w), Rr(rd, w), w)));
  INSTPAT("0010 0011", and,       E2G,  0, Rw(rd, w, and(RMr(rs, w), Rr(rd, w), w)));
  INSTPAT("0010 0100", and,       I2a,  1, Rw(R_EAX, w, and(Rr(R_EAX, w), imm, w)));
  INSTPAT("0010 0101", and,       I2a,  0, Rw(R_EAX, w, and(Rr(R_EAX, w), imm, w)));
  INSTPAT("0010 1001", sub,       G2E,  0, RMw(sub(RMr(rd, w), src1, w)));
  INSTPAT("0010 1010", sub,       E2G,  1, Rw(rd, w, sub(Rr(rd, w), RMr(rs, w), w)));
  INSTPAT("0010 1011", sub,       E2G,  0, Rw(rd, w, sub(Rr(rd, w), RMr(rs, w), w)));
  INSTPAT("0010 1101", sub,       I2a,  0, Rw(R_EAX, w, sub(Rr(R_EAX, w), imm, w)));

  INSTPAT("0011 0000", xor,       G2E,  1, RMw(RMr(rd, w) ^ src1));
  INSTPAT("0011 0001", xor,       G2E,  0, RMw(RMr(rd, w) ^ src1));
  INSTPAT("0011 0010", xor,       E2G,  1, Rw(rd, w, RMr(rs, w) ^ Rr(rd, w)));
  INSTPAT("0011 0011", xor,       E2G,  0, Rw(rd, w, RMr(rs, w) ^ Rr(rd, w)));
  INSTPAT("0011 0101", xor,       I2a,  0, Rw(R_EAX, w, Rr(R_EAX, w) ^ imm));
  INSTPAT("0011 1000", cmp,       G2E,  1, sub(RMr(rd, w), src1, w));
  INSTPAT("0011 1001", cmp,       G2E,  0, sub(RMr(rd, w), src1, w));
  INSTPAT("0011 1010", cmp,       E2G,  1, sub(Rr(rd, w), RMr(rs, w), w));
  INSTPAT("0011 1011", cmp,       E2G,  0, sub(Rr(rd, w), RMr(rs, w), w));
  INSTPAT("0011 1100", cmp,       I2a,  1, sub(Rr(R_EAX, w), imm, w));
  INSTPAT("0011 1101", cmp,       I2a,  0, sub(Rr(R_EAX, w), imm, w));

  INSTPAT("0100 0???", inc,       r,    0, Rw(rd, w, add(src1, 1, w)));
  INSTPAT("0100 1???", dec,       r,    0, Rw(rd, w, sub(src1, 1, w)));

  INSTPAT("0101 0???", push,      r,    4, push(src1));
  INSTPAT("0101 1???", pop,       r,    4, Rw(rd, 4, pop()));

  INSTPAT("0110 0000", pusha,     N,    0, src1 = cpu.esp;
                                           push(cpu.eax); push(cpu.ecx); push(cpu.edx); push(cpu.ebx);
                                           push(src1);    push(cpu.ebp); push(cpu.esi); push(cpu.edi));
  INSTPAT("0110 0001", popa,      N,    0, cpu.edi = pop(); cpu.esi = pop(); cpu.ebp = pop(); pop();
                                           cpu.ebx = pop(); cpu.edx = pop(); cpu.ecx = pop(); cpu.eax = pop());
  INSTPAT("0110 0110", data_size, N,    0, is_operand_size_16 = true; goto again;);
  INSTPAT("0110 1000", push,      I,    0, push(imm));
  INSTPAT("0110 1001", imul,      I_E2G,0, Rw(rd, w, sext(RMr(rs, w), w) * imm));
  INSTPAT("0110 1010", push,      SI,   1, push(imm));
  INSTPAT("0110 1011", imul,      SI_E2G,0, Rw(rd, w, sext(RMr(rs, w), w) * imm));

  INSTPAT("0111 0010", jb,        J,    1, jcond(cpu.CF, s->snpc + imm));
  INSTPAT("0111 0011", jae,       J,    1, jcond(!cpu.CF, s->snpc + imm));
  INSTPAT("0111 0100", je,        J,    1, jcond(cpu.ZF, s->snpc + imm));
  INSTPAT("0111 0101", jne,       J,    1, jcond(!cpu.ZF, s->snpc + imm));
  INSTPAT("0111 0110", jbe,       J,    1, jcond(cpu.CF | cpu.ZF, s->snpc + imm));
  INSTPAT("0111 0111", ja,        J,    1, jcond(!(cpu.CF | cpu.ZF), s->snpc + imm));
  INSTPAT("0111 1000", js,        J,    1, jcond(cpu.SF, s->snpc + imm));
  INSTPAT("0111 1001", jns,       J,    1, jcond(!cpu.SF, s->snpc + imm));
  INSTPAT("0111 1100", jl,        J,    1, jcond(cpu.SF ^ cpu.OF, s->snpc + imm));
  INSTPAT("0111 1101", jge,       J,    1, jcond(!(cpu.SF ^ cpu.OF), s->snpc + imm));
  INSTPAT("0111 1110", jle,       J,    1, jcond((cpu.SF ^ cpu.OF) | cpu.ZF, s->snpc + imm));
  INSTPAT("0111 1111", jg,        J,    1, jcond(!((cpu.SF ^ cpu.OF) | cpu.ZF), s->snpc + imm));

  INSTPAT("1000 0000", gp1,       I2E,  1, gp1());
  INSTPAT("1000 0001", gp1,       I2E,  0, gp1());
  INSTPAT("1000 0011", gp1,       SI2E, 0, gp1());
  INSTPAT("1000 0100", test,      G2E,  1, and(RMr(rd, w), src1, w));
  INSTPAT("1000 0101", test,      G2E,  0, and(RMr(rd, w), src1, w));
  INSTPAT("1000 0111", xchg,      G2E,  0, Rw(rs, w, RMr(rd, w)); RMw(src1));
  INSTPAT("1000 1000", mov,       G2E,  1, RMw(src1));
  INSTPAT("1000 1001", mov,       G2E,  0, RMw(src1));
  INSTPAT("1000 1010", mov,       E2G,  1, Rw(rd, w, RMr(rs, w)));
  INSTPAT("1000 1011", mov,       E2G,  0, Rw(rd, w, RMr(rs, w)));
  INSTPAT("1000 1101", lea,       E2G,  4, Rw(rd, 4, addr));

  INSTPAT("1001 0000", nop,       N,    0, );
  INSTPAT("1001 1000", cwtl,      N,    0, Rw(R_EAX, w, sext(cpu.eax, (w == 2) ? 1 : 2)));
  INSTPAT("1001 1001", cltd,      N,    0, assert(w == 4); cpu.edx = (sword_t)cpu.eax >> 31);

  INSTPAT("1010 0000", mov,       O2a,  1, Rw(R_EAX, 1, Mr(addr, 1)));
  INSTPAT("1010 0001", mov,       O2a,  0, Rw(R_EAX, w, Mr(addr, w)));
  INSTPAT("1010 0010", mov,       a2O,  1, Mw(addr, 1, Rr(R_EAX, 1)));
  INSTPAT("1010 0011", mov,       a2O,  0, Mw(addr, w, Rr(R_EAX, w)));
  INSTPAT("1010 0100", movs,      N,    1, Mw(reg_l(R_EDI), 1, Mr(reg_l(R_ESI), 1)); cpu.esi ++; cpu.edi ++);
  INSTPAT("1010 0101", movs,      N,    0, Mw(reg_l(R_EDI), w, Mr(reg_l(R_ESI), w)); cpu.esi += w; cpu.edi += w);
  INSTPAT("1010 1000", test,      I2a,  1, and(Rr(R_EAX, w), imm, w));
  INSTPAT("1010 1001", test,      I2a,  0, and(Rr(R_EAX, w), imm, w));

  INSTPAT("1011 0???", mov,       I2r,  1, Rw(rd, 1, imm));
  INSTPAT("1011 1???", mov,       I2r,  0, Rw(rd, w, imm));

  INSTPAT("1100 0000", gp2,       Ib2E, 1, gp2());
  INSTPAT("1100 0001", gp2,       Ib2E, 0, gp2());
  INSTPAT("1100 0011", ret,       N,    0, jcond(true, pop()));
  INSTPAT("1100 0110", mov,       I2E,  1, RMw(imm));
  INSTPAT("1100 0111", mov,       I2E,  0, RMw(imm));
  INSTPAT("1100 1001", leave,     N,    0, cpu.esp = cpu.ebp; cpu.ebp = pop());
  INSTPAT("1100 1100", nemu_trap, N,    0, NEMUTRAP(s->pc, cpu.eax));
  INSTPAT("1100 1101", int,       I,    1, jcond(true, isa_raise_intr(imm, s->snpc)));
  INSTPAT("1100 1111", iret,      N,    0, jcond(true, iret()));

  INSTPAT("1101 0000", gp2,       1_E,  1, gp2());
  INSTPAT("1101 0001", gp2,       1_E,  0, gp2());
  INSTPAT("1101 0011", gp2,       cl2E, 0, gp2());

  INSTPAT("1110 1000", call,      J,    4, push(s->snpc); jcond(true, s->snpc + imm));
  INSTPAT("1110 1001", jmp,       J,    4, jcond(true, s->snpc + imm));
  INSTPAT("1110 1011", jmp,       J,    1, jcond(true, s->snpc + imm));
  INSTPAT("1110 1101", in,        N,    0, Rw(R_EAX, w, pio_read(reg_w(R_DX), w)));
  INSTPAT("1110 1110", out,       N,    1, pio_write(reg_w(R_DX), 1, reg_b(R_AL)));
  INSTPAT("1110 1111", out,       N,    0, pio_write(reg_w(R_DX), w, Rr(R_EAX, w)));

  INSTPAT("1111 0110", gp3,       E,    1, gp3());
  INSTPAT("1111 0111", gp3,       E,    0, gp3());
  INSTPAT("1111 1110", gp4,       E,    1, switch (gp_idx) {
                                             case 0b000: RMw(add(RMr(rd, w), 1, w)); break;
                                             case 0b001: RMw(sub(RMr(rd, w), 1, w)); break;
                                             default: INV(s->pc);
                                           });
  INSTPAT("1111 1111", gp5,       E,    0, switch (gp_idx) {
                                             case 0b000: RMw(add(RMr(rd, w), 1, w)); break;
                                             case 0b001: RMw(sub(RMr(rd, w), 1, w)); break;
                                             case 0b010: push(s->snpc); jcond(true, RMr(rd, w)); break;
                                             case 0b100: jcond(true, RMr(rd, w)); break;
                                             case 0b110: push(RMr(rd, w)); break;
                                             default: INV(s->pc);
                                           });

  INSTPAT("???? ????", inv,       N,    0, INV(s->pc));
  INSTPAT_END();

  return 0;
}

#else
#define INSTPAT_INST(s) opcode
#define INSTPAT_MATCH(s, name, type, width, ... /* execute body */ ) { \
  int rd = 0, rs = 0, gp_idx = 0; \
  word_t src1 = 0, addr = 0, imm = 0; \
  int w = width == 0 ? (is_operand_size_16 ? 2 : 4) : width; \
  decode_operand(s, opcode, &rd, &src1, &addr, &rs, &gp_idx, &imm, w, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

static void decode_operand(Decode *s, uint8_t opcode, int *rd_, word_t *src1,
    word_t *addr, int *rs, int *gp_idx, word_t *imm, int w, int type) {
  switch (type) {
    case TYPE_I2r:  destr(opcode & 0x7); imm(); break;
    case TYPE_G2E:  decode_rm(s, rd_, addr, rs, w); src1r(*rs); break;
    case TYPE_E2G:  decode_rm(s, rs, addr, rd_, w); break;
    case TYPE_I2E:  decode_rm(s, rd_, addr, gp_idx, w); imm(); break;
    case TYPE_O2a:  destr(R_EAX); *addr = x86_inst_fetch(s, 4); break;
    case TYPE_a2O:  *rs = R_EAX;  *addr = x86_inst_fetch(s, 4); break;
    default: panic("Unsupported type = %d", type);
  }
}

#define gp1() do { \
  switch (gp_idx) { \
    default: INV(s->pc); \
  }; \
} while (0)

void _2byte_esc(Decode *s, bool is_operand_size_16) {
  uint8_t opcode = x86_inst_fetch(s, 1);
  INSTPAT_START();
  INSTPAT("???? ????", inv,    N,    0, INV(s->pc));
  INSTPAT_END();
}

int isa_exec_once(Decode *s) {
  bool is_operand_size_16 = false;
  uint8_t opcode = 0;
  s->dnpc = s->snpc;

again:
  opcode = x86_inst_fetch(s, 1);

  INSTPAT_START();

  INSTPAT("0000 1111", 2byte_esc, N,    0, _2byte_esc(s, is_operand_size_16));

  INSTPAT("0110 0110", data_size, N,    0, is_operand_size_16 = true; goto again;);

  INSTPAT("1000 0000", gp1,       I2E,  1, gp1());
  INSTPAT("1000 1000", mov,       G2E,  1, RMw(src1));
  INSTPAT("1000 1001", mov,       G2E,  0, RMw(src1));
  INSTPAT("1000 1010", mov,       E2G,  1, Rw(rd, w, RMr(rs, w)));
  INSTPAT("1000 1011", mov,       E2G,  0, Rw(rd, w, RMr(rs, w)));

  INSTPAT("1010 0000", mov,       O2a,  1, Rw(R_EAX, 1, Mr(addr, 1)));
  INSTPAT("1010 0001", mov,       O2a,  0, Rw(R_EAX, w, Mr(addr, w)));
  INSTPAT("1010 0010", mov,       a2O,  1, Mw(addr, 1, Rr(R_EAX, 1)));
  INSTPAT("1010 0011", mov,       a2O,  0, Mw(addr, w, Rr(R_EAX, w)));

  INSTPAT("1011 0???", mov,       I2r,  1, Rw(rd, 1, imm));
  INSTPAT("1011 1???", mov,       I2r,  0, Rw(rd, w, imm));

  INSTPAT("1100 0110", mov,       I2E,  1, RMw(imm));
  INSTPAT("1100 0111", mov,       I2E,  0, RMw(imm));
  INSTPAT("1100 1100", nemu_trap, N,    0, NEMUTRAP(s->pc, cpu.eax));
  INSTPAT("???? ????", inv,       N,    0, INV(s->pc));
  INSTPAT_END();

  return 0;
}
#endif
