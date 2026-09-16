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

#ifdef CONFIG_FTRACE
#include "../../monitor/elf_reader.h"
  int count = 0;
#endif



#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write


enum {
  TYPE_I, TYPE_U, TYPE_S,
	TYPE_J, TYPE_B, TYPE_R,	
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do { *imm = \
										(SEXT(BITS(i, 31, 31), 1) << 20) | \
										(BITS(i, 19, 12) << 12) | \
										(BITS(i, 20, 20) << 11) | \
										(BITS(i, 30, 21) << 1 ); } while(0)
#define immB() do { *imm = \
										(SEXT(BITS(i, 31, 31), 1) << 12) | \
										(BITS(i, 7, 7) << 11) | \
										(BITS(i, 30, 25) << 5) | \
										(BITS(i, 11, 8) << 1); } while(0)
// #define immR() do { *imm = /*待完成*/ } while(0)

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
		case TYPE_B: src1R(); src2R(); immB(); break;
		case TYPE_R: src1R(); src2R();         break;
    case TYPE_N: break;
    default: panic("unsupported type = %d", type);
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
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);

  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, uint8_t shamt = imm & 0x1F; R(rd) = src1 << shamt);// 在RV32I中，仅当shamt[5]=0时该指令合法 没有实现
	INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, uint8_t shamt = imm & 0x1F; R(rd) = (int32_t)src1 >> shamt);// 在RV32I中，仅当shamt[5]=0时该指令合法，还没有实现
	INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, R(rd) = s->pc + 4; s->dnpc = (src1 + imm) & ~1);
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, uint8_t shamt = imm & 0x1F; R(rd) = src1 >> shamt);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, uint8_t val = Mr(src1 + imm, 1) ; R(rd) = (int8_t)val);
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, uint16_t val = Mr(src1 + imm, 2); R(rd) = (int16_t)val );
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
	INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
	INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
	INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm);
	INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = (uint32_t)src1 < (uint32_t)imm ? 1 : 0);
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm);
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = ((int32_t)src1 < (int32_t)imm) ? 1 : 0);
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, uint16_t caddr = imm & 0xfff; *csr(caddr) = *csr(caddr) | src1; R(rd) = *csr(caddr)); // NEW
  INSTPAT("??????? ????? ????? 110 ????? 11100 11", csrrsi , I, word_t zimm = imm & 0x1f; uint16_t caddr = imm & 0xfff; *csr(caddr) = *csr(caddr) | zimm; R(rd) = *csr(caddr)); // NEW
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, uint16_t caddr = imm & 0xfff; *csr(caddr) = src1; R(rd) = *csr(caddr)); // NEW
  INSTPAT("??????? ????? ????? 101 ????? 11100 11", csrrwi , I, word_t zimm = imm & 0x1f; uint16_t caddr = imm & 0xfff; R(rd) = *csr(caddr); *csr(caddr) = zimm); // NEW
  INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc  , I, uint16_t caddr = imm & 0xfff; *csr(caddr) = *csr(caddr) & ~src1; R(rd) = *csr(caddr)); // NEW
  INSTPAT("??????? ????? ????? 111 ????? 11100 11", csrrci , I, word_t zimm = imm & 0x1f; uint16_t caddr = imm & 0xfff; *csr(caddr) = *csr(caddr) & ~zimm; R(rd) = *csr(caddr)); // NEW
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, s->dnpc = isa_raise_intr(11, s->pc));// 数据测试用 未实现特权级切换
   
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
	INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));
	INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2));

  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->pc + 4; s->dnpc = s->pc + imm);

  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = (int32_t)src1 < (int32_t)src2 ? 1 : 0);
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = src1 < src2 ? 1 : 0);
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2);
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = ((int64_t)(int32_t)src1 * (int64_t)(int32_t)src2) >> 32);
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, {uint64_t product = (uint64_t)src1 * (uint64_t)src2; R(rd) = product >> 32;});
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu , R, { int64_t product = (int64_t)(int32_t)src1 * (uint64_t)(uint32_t)src2; R(rd) = product >> 32;});
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = src2 == 0 ? 0xFFFFFFFF : src1 == 0x80000000 && src2 == 0xFFFFFFFF ? 0x80000000 : (int32_t)src1 / (int32_t)src2);
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = src2 == 0 ? 0xFFFFFFFF : src1 / src2);
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = src2 == 0 ? src1 : src1 == 0x80000000 && src2 == 0xFFFFFFFF ? 0 : (int32_t)src1 % (int32_t)src2);
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = src2 == 0 ? src1 : src1 % src2);
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << (src2 & 0x1F));
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, uint8_t shamt = src2 & 0x1F; R(rd) = (int32_t)src1 >> shamt);
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = src1 >> (src2 & 0x1F));
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , R, s->dnpc = MEPC);// 待实现 NEW

  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(src1 == src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if(src1 != src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if((int32_t)src1 >= (int32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if((uint32_t)src1 >= (uint32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if((int32_t)src1 < (int32_t)src2) s->dnpc = s->pc + imm);
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if((uint32_t)src1 < (uint32_t)src2) s->dnpc = s->pc + imm);

  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);

  #ifdef CONFIG_FTRACE
  int is_call = 0;
  int is_ret = 0;

  uint32_t opcode = BITS(s->isa.inst, 6, 0);
  uint32_t rd = BITS(s->isa.inst, 11, 7);
  uint32_t rs1 = BITS(s->isa.inst, 19, 15);
 

  if ((opcode == 0x6F && rd == 1) ||  // JAL rd=x1
      (opcode == 0x67 && rd == 1)) {  // JALR rd=x1
    is_call = 1;
  }
  if (opcode == 0x67 && rs1 == 1 && rd == 0) {
    is_ret = 1;
  }
  
  int ret = decode_exec(s);
  char blank [40];
  int j = 0;
  if (is_call) {
    count += 2;
    for(j = 0; j < count; j ++){
      blank[j] = ' ';
    }
    blank[count] = '\0';
    for(int i = 0; i < functab_count; i ++){
      if(functab[i].value == s->dnpc){
        log_write("0x%08x:%s call [%s@0x%08x]", s->pc, blank, functab[i].func_name, functab[i].value);
        printf("0x%08x:%s call [%s@0x%08x]\n", s->pc, blank, functab[i].func_name, functab[i].value);
        break;
      }
    }
  }
  else if (is_ret) {
    count -= 2;
    for(j = 0; j < count; j ++){
      blank[j] = ' ';
    }
    blank[count] = '\0';
    printf("0x%08x:%s ret [0x%08x]\n", s->pc, blank, R(1));
    log_write("0x%08x:%s ret [0x%08x]\n", s->pc, blank, R(1));
    // for(int i = 0; i < functab_count; i ++){
    //   if(functab[i].value == s->dnpc){
    //     log_write("0x%08x:%s ret [%s]", s->pc, blank, functab[i].func_name);
    //     printf("0x%08x:%s ret [%s]\n", s->pc, blank, functab[i].func_name);
    //     break;
    //   }
    // }
  }
  
  return ret;
#endif
  return decode_exec(s);
}
