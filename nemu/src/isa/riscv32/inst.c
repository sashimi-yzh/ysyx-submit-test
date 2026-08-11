/***************************************************************************************
***************************************************************************************/

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include <stdint.h>

#define R(i) gpr(i)
#define Mr vaddr_read   // Load 类指令
#define Mw vaddr_write  // Store 类指令

#define CSR_MSTATUS 0x300
#define CSR_MTVEC   0x305
#define CSR_MEPC    0x341
#define CSR_MCAUSE  0x342

typedef int32_t  sword_t;
typedef uint32_t uword_t;

enum {
  TYPE_R, TYPE_I, TYPE_S, TYPE_B, TYPE_U, TYPE_J,
  TYPE_N // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)

#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while (0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while (0)

#define immS() do { \
  uint32_t val = (BITS(i, 31, 25) << 5) | BITS(i, 11, 7); \
  *imm = SEXT(val, 12); \
} while (0)

#define immB() do { \
  uint32_t val = (BITS(i, 31, 31) << 12) | \
                 (BITS(i, 7, 7)   << 11) | \
                 (BITS(i, 30, 25) << 5)  | \
                 (BITS(i, 11, 8)  << 1); \
  *imm = SEXT(val, 13); \
} while (0)

#define immJ() do { \
  uint32_t val = (BITS(i, 31, 31) << 20) | \
                 (BITS(i, 19, 12) << 12) | \
                 (BITS(i, 20, 20) << 11) | \
                 (BITS(i, 30, 21) << 1); \
  *imm = SEXT(val, 21); \
} while (0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);

  switch (type) {
    case TYPE_R: src1R(); src2R(); break;
    case TYPE_I: src1R(); immI(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_B: src1R(); src2R(); immB(); break;
    case TYPE_U: immU(); break;
    case TYPE_J: immJ(); break;
    case TYPE_N: break;
    default: panic("unsupported type = %d", type);
  }
}

// RV32M helper（mulh 系列）
static inline word_t mul_lo(word_t a, word_t b) {
  return (word_t)((uint64_t)(uword_t)a * (uint64_t)(uword_t)b);
}
static inline word_t mulh_ss(word_t a, word_t b) {
  int64_t p = (int64_t)(sword_t)a * (int64_t)(sword_t)b;
  return (word_t)((uint64_t)p >> 32);
}
static inline word_t mulh_su(word_t a, word_t b) {
  int64_t  aa = (int64_t)(sword_t)a;
  uint64_t bb = (uint64_t)(uword_t)b;
  int64_t  p  = aa * (int64_t)bb; // 够用：aa 为 signed，bb 为 unsigned
  return (word_t)((uint64_t)p >> 32);
}
static inline word_t mulh_uu(word_t a, word_t b) {
  uint64_t p = (uint64_t)(uword_t)a * (uint64_t)(uword_t)b;
  return (word_t)(p >> 32);
}

static inline word_t div_s(word_t a, word_t b) {
  sword_t sa = (sword_t)a, sb = (sword_t)b;
  if (sb == 0) return 0xFFFFFFFFu;
  if (sa == (sword_t)0x80000000u && sb == -1) return 0x80000000u; // overflow
  return (word_t)(sa / sb);
}
static inline word_t div_u(word_t a, word_t b) {
  uword_t ua = (uword_t)a, ub = (uword_t)b;
  if (ub == 0) return 0xFFFFFFFFu;
  return (word_t)(ua / ub);
}
static inline word_t rem_s(word_t a, word_t b) {
  sword_t sa = (sword_t)a, sb = (sword_t)b;
  if (sb == 0) return a;
  if (sa == (sword_t)0x80000000u && sb == -1) return 0; // overflow case remainder
  return (word_t)(sa % sb);
}
static inline word_t rem_u(word_t a, word_t b) {
  uword_t ua = (uword_t)a, ub = (uword_t)b;
  if (ub == 0) return a;
  return (word_t)(ua % ub);
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

  // =========================
  // U-type
  // =========================
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui   , U, R(rd) = imm);// 装入高位立即数
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc , U, R(rd) = s->pc + imm);// PC加高位立即数

  // =========================
  // Jumps
  // =========================
  // jal: rd = pc+4; dnpc = pc+imm
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal   , J, R(rd) = s->pc + 4; s->dnpc = s->pc + imm;);// 跳转并链接

  // jalr: rd = pc+4; dnpc = (rs1+imm)&~1
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr  , I, word_t t = (src1 + imm) & ~1; R(rd) = s->pc + 4; s->dnpc = t;);// 寄存器跳转并链接

  // =========================
  // Branches (B-type)
  // =========================
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq   , B, if (src1 == src2) s->dnpc = s->pc + imm);// 相等时分支
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne   , B, if (src1 != src2) s->dnpc = s->pc + imm);// 不相等时分支
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt   , B, if ((sword_t)src1 <  (sword_t)src2) s->dnpc = s->pc + imm);// 小于时分支
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge   , B, if ((sword_t)src1 >= (sword_t)src2) s->dnpc = s->pc + imm);// 大于等于时分支
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu  , B, if ((uword_t)src1 <  (uword_t)src2) s->dnpc = s->pc + imm);// 无符号小于时分支
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu  , B, if ((uword_t)src1 >= (uword_t)src2) s->dnpc = s->pc + imm);// 无符号大于等于时分支

  // =========================
  // Loads (I-type, opcode 0000011)
  // =========================
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb    , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));// 取字节
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh    , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));// 取半字节
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw    , I, R(rd) = Mr(src1 + imm, 4));// 取字
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu   , I, R(rd) = Mr(src1 + imm, 1));// 取无符号字节
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu   , I, R(rd) = Mr(src1 + imm, 2));// 取无符号半字节

  // =========================
  // Stores (S-type, opcode 0100011)
  // =========================
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb    , S, Mw(src1 + imm, 1, src2));// 存字节
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh    , S, Mw(src1 + imm, 2, src2));// 存半字节
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw    , S, Mw(src1 + imm, 4, src2));// 存字

  // =========================
  // ALU imm (I-type, opcode 0010011)
  // =========================
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi  , I, R(rd) = src1 + imm);// 加立即数
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti  , I, R(rd) = ((sword_t)src1 <  (sword_t)imm));// 小于立即数则置位
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu , I, R(rd) = ((uword_t)src1 <  (uword_t)imm));// 无符号小于立即数则置位
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori  , I, R(rd) = src1 ^ imm);// 异或立即数
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori   , I, R(rd) = src1 | imm);// 或立即数
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi  , I, R(rd) = src1 & imm);// 与立即数

  // shifts imm: shamt = imm[4:0], 通过 funct7 区分 srli/srai
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli  , I, R(rd) = src1 << (imm & 0x1F));// 逻辑左移立即数
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli  , I, R(rd) = (uword_t)src1 >> (imm & 0x1F));// 逻辑右移立即数
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai  , I, R(rd) = (word_t)((sword_t)src1 >> (imm & 0x1F)));// 算数右移立即数

  // =========================
  // ALU reg (R-type, opcode 0110011) - RV32I
  // =========================
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add   , R, R(rd) = src1 + src2);//加法
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub   , R, R(rd) = src1 - src2);//减法
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll   , R, R(rd) = src1 << (src2 & 0x1F));// 逻辑左移
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt   , R, R(rd) = ((sword_t)src1 <  (sword_t)src2));// 小于则置位
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu  , R, R(rd) = ((uword_t)src1 <  (uword_t)src2));// 无符号小于则置位
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor   , R, R(rd) = src1 ^ src2);// 异或
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl   , R, R(rd) = (uword_t)src1 >> (src2 & 0x1F));// 逻辑右移
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra   , R, R(rd) = (word_t)((sword_t)src1 >> (src2 & 0x1F)));// 算数右移
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or    , R, R(rd) = src1 | src2);// 或
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and   , R, R(rd) = src1 & src2);// 与

  // =========================
  // RV32M (funct7=0000001)
  // =========================
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = mul_lo(src1, src2));// 乘法
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = mulh_ss(src1, src2));// 高位乘法
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu , R, R(rd) = mulh_su(src1, src2));// 高位有符号-无符号乘
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, R(rd) = mulh_uu(src1, src2));// 高位无符号乘
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = div_s(src1, src2));// 除法
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = div_u(src1, src2));// 无符号除法
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = rem_s(src1, src2));// 求余数
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = rem_u(src1, src2));// 求无符号余数

  // =========================
  // System / Fence
  // =========================
  // 我暂时还没想到有啥用，就先放在这了
  INSTPAT("??????? ????? ????? 000 ????? 00011 11", fence  , N, /* nop */ );// 同步线程
  INSTPAT("??????? ????? ????? 001 ????? 00011 11", fencei , N, /* nop */ );// 同步指令和数据

  // ecall/ebreak
  //INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, NEMUTRAP(s->pc, R(10)));// 环境调用
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, {s->dnpc = isa_raise_intr(11, s->pc);});
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , N, {s->dnpc = csr_read(CSR_MEPC);});
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10)));// 环境断点
  // =========================
  // CSR (SYSTEM opcode=1110011, funct3!=000)
  // =========================
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw , I, {
    uint32_t i   = s->isa.inst;
    uint32_t csr = BITS(i, 31, 20);
    word_t old = csr_read(csr);
    csr_write(csr, src1);
    R(rd) = old;
  });

  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs , I, {
    uint32_t i   = s->isa.inst;
    uint32_t csr = BITS(i, 31, 20);
    word_t old = csr_read(csr);
    if (BITS(i, 19, 15) != 0) { // rs1 != x0 才写
      csr_write(csr, old | src1);
    }
    R(rd) = old;
  });

  INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc , I, {
    uint32_t i   = s->isa.inst;
    uint32_t csr = BITS(i, 31, 20);
    word_t old = csr_read(csr);
    if (BITS(i, 19, 15) != 0) { // rs1 != x0 才写
      csr_write(csr, old & ~src1);
    }
    R(rd) = old;
  });

  INSTPAT("??????? ????? ????? 101 ????? 11100 11", csrrwi, I, {
    uint32_t i   = s->isa.inst;
    uint32_t csr = BITS(i, 31, 20);
    uint32_t zimm = BITS(i, 19, 15);
    word_t old = csr_read(csr);
    csr_write(csr, (word_t)zimm);
    R(rd) = old;
  });

  INSTPAT("??????? ????? ????? 110 ????? 11100 11", csrrsi, I, {
    uint32_t i   = s->isa.inst;
    uint32_t csr = BITS(i, 31, 20);
    uint32_t zimm = BITS(i, 19, 15);
    word_t old = csr_read(csr);
    if (zimm != 0) { // zimm != 0 才写
      csr_write(csr, old | (word_t)zimm);
    }
    R(rd) = old;
  });

  INSTPAT("??????? ????? ????? 111 ????? 11100 11", csrrci, I, {
    uint32_t i   = s->isa.inst;
    uint32_t csr = BITS(i, 31, 20);
    uint32_t zimm = BITS(i, 19, 15);
    word_t old = csr_read(csr);
    if (zimm != 0) { // zimm != 0 才写
      csr_write(csr, old & ~(word_t)zimm);
    }
    R(rd) = old;
  });

  // default
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));

  INSTPAT_END();

  R(0) = 0; // keep x0 = 0
  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
