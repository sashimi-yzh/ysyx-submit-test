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
#include <itrace.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S, 
  TYPE_N, // none

  // add by XueHaiyang
  TYPE_J,
  TYPE_B,
  TYPE_R
};

static vaddr_t *csr_register(word_t imm) {
  switch (imm)
  {
  case 0x341: return &(cpu.csr.mepc);
  case 0x342: return &(cpu.csr.mcause);
  case 0x300: return &(cpu.csr.mstatus);
  case 0x305: return &(cpu.csr.mtvec);
  default: panic("Unknown csr");
  }
}

#define ECALL(dnpc) {dnpc = (isa_raise_intr(11, s->pc)); }
#define CSR(i) *csr_register(i)

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)

// add by XueHaiyang
#define immJ() do {  *imm = (SEXT(BITS(i, 31, 31), 1) << 20) \
                          | (BITS(i, 30, 21) << 1)    \
                          | (BITS(i, 20, 20) << 11)   \
                          | (BITS(i, 19, 12) << 12);  \
} while(0)

#define immB() do {  *imm = (SEXT(BITS(i, 31, 31), 1) << 12) \
                          | (BITS(i, 30, 25) << 5)    \
                          | (BITS(i, 7, 7) << 11)   \
                          | (BITS(i, 11, 8) << 1);  \
} while(0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;

    // add by XueHaiyang
    case TYPE_J:                   immJ(); break;
    case TYPE_B: src1R(); src2R(); immB(); break;
    case TYPE_R: src1R(); src2R();         break;
  }
}

///////////////////////////////////////////////////////

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

  // add by XueHaiyang 2024.5.7
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", li      , I, R(rd) = src1 + imm); // 此处的dest是函数 decode_exec中定义的int 类型 dest
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui     , U, R(rd) = imm); // 此处的dest是函数 decode_exec中定义的int 类型 dest
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc   , U, R(rd) = s -> pc + imm); 
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw      , I, R(rd) = Mr(src1 + imm, 4)); // 从内存相应位置读出并写入到寄存器中
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu     , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb      , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh      , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu     , I, R(rd) = Mr(src1 + imm, 2));
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi    , I, R(rd) = imm & src1);
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb      , S, Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw      , S, Mw(src1 + imm, 4, src2)); // 向内存中写入
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh      , S, Mw(src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal     , J, R(rd) = s -> pc + 4; s -> dnpc += imm -4; IFDEF(CONFIG_FTRACE, {
  if (rd == 1) { // 返回时读取ra寄存器也就是r1
    trace_func_call(s->pc, s->dnpc);
  }
  })); // jal指令
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr    , I, s->dnpc = (src1 + imm) & ~(word_t)1;  R(rd) = s->pc + 4; IFDEF(CONFIG_FTRACE, {
    if (s->isa.inst.val == 0x00008067) { //0x00008067为返回
      trace_func_ret(s->pc); // ret -> jalr x0, 0(x1)
    } else if (rd == 1) { // rd==1显然是跳转，寄存器1为ra，即return addr 记录为返回的地址
      trace_func_call(s->pc, s->dnpc);
    } else if (rd == 0 && imm == 0) {
      trace_func_call(s->pc, s->dnpc); // jr rs1 -> jalr x0, 0(rs1), which may be other control flow e.g. 'goto','for'
    }
  }));
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori    , I, R(rd) = src1 ^ imm);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori     , I, R(rd) = src1 | imm);
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi    , I, R(rd) = src1 + imm); // addi指令
  // mv 指令是addi指令的一个语法糖，无需单独实现
  // 手册中未发现li指令的描述，但查阅资料时对li指令的描述表示这也是addi指令的语法糖，R[rd] = R[rs1] + imm(符号扩展12位到32位) 其特殊之处是rs1总是0号寄存器，riscv体系中0号寄存器总是0,因此作用是加载立即数。
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai    , I, imm = BITS(imm, 4, 0); R(rd) = (SEXT(BITS(src1, 31, 31), 1) << (32 - imm)) | (src1 >> imm));
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli    , I, R(rd)= src1 >> imm);
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", elli    , I, R(rd)= src1 << imm);
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", ret     , I, R(rd) = s -> pc + 4; s -> dnpc = (src1 + imm) & ~1); // jalr(ret)指令
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt     , B, s -> dnpc += (int)src1 < (int)src2 ? imm - 4: 0; IFDEF(CONFIG_BTRACE, blog_write("0x%x %d %d\n", s -> pc, (int)src1 < (int)src2, (imm  & 0x80000000)>> 31)););
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu    , B, s -> dnpc += (uint32_t)src1 < (uint32_t)src2 ? imm - 4: 0; IFDEF(CONFIG_BTRACE, blog_write("0x%x %d %d\n", s -> pc, (uint32_t)src1 < (uint32_t)src2, (imm  & 0x80000000)>> 31)););
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge     , B, s -> dnpc += (int)src1 >= (int)src2 ? imm - 4: 0; IFDEF(CONFIG_BTRACE, blog_write("0x%x %d %d\n", s -> pc, (int)src1 >= (int)src2, (imm  & 0x80000000)>> 31)););
  /*
   * 使用bge指令代替blez,ble指令仅仅将bge指令的操作数顺序改变，而blez只是将其中的一个操作数选择为0号寄存器（始终为0）
   */
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu    , B, s -> dnpc += src1 >= src2 ? imm - 4: 0; IFDEF(CONFIG_BTRACE, blog_write("0x%x %d %d\n", s -> pc, src1 >= src2, (imm  & 0x80000000)>> 31)););
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq     , B, s -> dnpc += src1 == src2 ? imm - 4: 0; IFDEF(CONFIG_BTRACE, blog_write("0x%x %d %d\n", s -> pc, src1 == src2, (imm  & 0x80000000)>> 31));); 
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne     , B, s -> dnpc += src1 != src2 ? imm - 4: 0; IFDEF(CONFIG_BTRACE, blog_write("0x%x %d %d\n", s -> pc, src1 != src2, (imm  & 0x80000000)>> 31)););
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra     , R, R(rd) = (SEXT(BITS(src1, 31, 31), 1) << (32 - src2)) | (src1 >> src2));
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl     , R, R(rd) = src1 >> src2);

  // M extension
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem     , R, R(rd) = (int32_t)src1 % (int32_t)src2);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu    , R, R(rd) = src1 % src2);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu    , R, R(rd) = (uint32_t)src1 / (uint32_t)src2);
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div     , R, R(rd) = (int32_t)src1 / (int32_t)src2);
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul     , R, R(rd) = src1 * src2);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh    , R, int32_t a = src1; int32_t b = src2; int64_t tmp = (int64_t)a * (int64_t)b; R(rd) = BITS(tmp, 63, 32));
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu  , R, int32_t a = src1; uint32_t b = src2; int64_t tmp = (int64_t)a * (uint64_t)b; R(rd) = BITS(tmp, 63, 32));
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu   , R, uint64_t tmp = (uint64_t)src1 * (uint64_t)src2; R(rd) = BITS(tmp, 63, 32));

  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and     , R, R(rd) = src1 & src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll     , R, R(rd) = src1 << src2);
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add     , R, R(rd) = src1 + src2); 
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub     , R, R(rd) = src1 - src2);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu    , R, R(rd) = (uint32_t)src1 < (uint32_t)src2 ? 1: 0;);
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu   , I, R(rd) = (uint32_t)src1 < (uint32_t)imm ? 1: 0);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti    , I, R(rd) = (int32_t)src1 < (int32_t)imm ? 1: 0);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt     , R, R(rd) = (int)src1 < (int)src2 ? 1: 0);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor     , R, R(rd) = src1 ^ src2);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or      , R, R(rd) = src1 | src2);
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak  , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0

  //CSR
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, R(rd) = CSR(imm); CSR(imm) = src1);
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, R(rd) = CSR(imm); CSR(imm) |= src1);
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, ECALL(s->dnpc); IFDEF(CONFIG_ETRACE, Log("\nETRACE info: \n\tmepc: 0x%08x\n\tmstatus: 0x%x\n\tmcause: %d\n", cpu.csr.mepc, cpu.csr.mstatus, cpu.csr.mcause)););
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , N, s -> dnpc = cpu.csr.mepc);

  INSTPAT("0000000 00000 00000 001 00000 00011 11", fencn_i , I, );

  // 


  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv     , N, INV(s->pc)); // 对所有模式都无法匹配的指令，判定为非法指令

  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  IFDEF(CONFIG_ITRACE, trace_inst(s->pc, s->isa.inst.val));
  return decode_exec(s);
}