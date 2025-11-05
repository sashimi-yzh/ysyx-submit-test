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
#include <ftrace.h>
#include <fmt-def.h>

#ifndef CONFIG_BTRACE 
//#define CONFIG_USE_ICACHE //Not Config in Kconfig
#endif 


extern CPU_state cpu;

static vaddr_t *csr_register(word_t imm) {
  switch (imm){
    case 0x341: return &(cpu.csr.mepc);
    case 0x342: return &(cpu.csr.mcause);
    case 0x300: return &(cpu.csr.mstatus);
    case 0x305: return &(cpu.csr.mtvec);
    default: panic("Unknown csr");
  }
}
/*
#define ECALL(dnpc) { bool success; dnpc = (\
isa_raise_intr(isa_reg_str2val(MUXDEF(CONFIG_RVE,"a5","a7"), &success), s->pc)); }
*/

#define ECALL(dnpc) { \
  dnpc = isa_raise_intr(0xb, s->pc); \
}
#define CSR(i) *csr_register(i)


#define R(i) gpr(i)

#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_R, TYPE_B,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | BITS(i, 30, 21) << 1 | \
    (BITS(i, 20, 20) << 11) | (BITS(i, 19, 12) << 12) ; } while(0)
#define immB() do { *imm = SEXT(BITS(i, 31, 31), 1) << 11 | \
    ((SEXT(BITS(i, 7, 7), 1) << 63) >> 63) << 10 | \
    ((SEXT(BITS(i, 30, 25), 6) << 58) >> 58) << 4 | \
    ((SEXT(BITS(i, 11, 8), 4) << 60) >> 60); *imm = *imm << 1; } while (0)

#ifdef CONFIG_USE_ICACHE
#define SHAMT (BITS(icache[index].inst, 24, 20))
#else  
#define SHAMT (BITS(s->isa.inst.val, 24, 20))
#endif 

#ifdef CONFIG_RV64
#ifdef CONFIG_USE_ICACHE
#define SHAMT_LONG (BITS(icache[index].inst, 25, 20))
#else 
#define SHAMT_LONG (BITS(s->isa.inst.val, 25, 20))
#endif 
#define SHAMT_LONG_LEN 6
#else
#define SHAMT_LONG SHAMT
#define SHAMT_LONG_LEN 5
#endif

void etrace_print_info(){
#ifdef CONFIG_ETRACE
  printf("ETRACE: pc: 0x"FMT_WORD_HEX" mepc =" FMT_WORD_HEX " mstatus = " FMT_WORD_HEX 
  "\n mcause = " FMT_WORD_HEX " mtvec = " FMT_WORD_HEX "\n", 
  cpu.pc, cpu.csr.mepc, cpu.csr.mstatus, cpu.csr.mcause, cpu.csr.mtvec);
#endif
}

#if defined(CONFIG_USE_ICACHE) && defined(CONFIG_BTRACE)
#error "CONFIG_USE_ICACHE and CONFIG_BTRACE can not be defined at the same time"
#endif 


void btrace(word_t pc, uint32_t inst, uint8_t taken);
#ifdef CONFIG_BTRACE
#define BTRACE(pc, inst,taken) btrace(pc, inst, taken),
#else 
#define BTRACE(pc, inst,taken) 
#endif 


#define XLEN (MUXDEF(CONFIG_RV64, 64, 32)) 

////CSR(0x341) = mepc 
/*
#define MRET() { \
  s->dnpc = cpu.csr.mepc; \
  cpu.csr.mstatus &= ~(1<<3); \
  cpu.csr.mstatus |= ((cpu.csr.mstatus&(1<<7))>>4); \
  cpu.csr.mstatus |= (1<<7); \
  cpu.csr.mstatus &= ~((3U<<11)); \
}*/

#define MRET() { \
  s->dnpc = cpu.csr.mepc;  /* 设置下一个指令的地址为 mepc 的值 */ \
  uint32_t mstatus = cpu.csr.mstatus; \
  cpu.csr.mstatus = (mstatus & ~(1 << 3)) | ((mstatus & (1 << 7)) >> 4); /* 复制 MPIE 到 MIE */ \
  cpu.csr.mstatus |= (1 << 7); /* 设置 MPIE 位为 1 */ \
  cpu.csr.mstatus &= ~(3U << 11); /* 清除 MPP 位 */ \
}

//该函数在INSTPAT宏内被调用
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

#ifdef CONFIG_USE_ICACHE

#define ICACHE_SIZE (1024*4) //4k

typedef struct {
  void *label;
  word_t imm;
  word_t rs1;
  word_t rs2;
  word_t rd;
  uint32_t inst;
  word_t pc;
} ICacheEntry;

ICacheEntry  icache[ICACHE_SIZE] PG_ALIGN =  {0};
#endif 

uint64_t icache_hit = 0;
uint64_t icache_miss = 0;

#ifdef CONFIG_USE_ICACHE
void fencei(){
	for(int i=0; i<ICACHE_SIZE; i++){
		icache[i].pc = 0;
	}
}
#endif 

static int decode_exec(Decode *s) {
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0;

  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)

#ifndef CONFIG_USE_ICACHE
#define INSTPAT_MATCH(s, name, type, ... ) { \
   decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
   __VA_ARGS__ ; \
}
#else 
#define INSTPAT_MATCH(s, name, t, ...) { \
  icache[index].inst = INSTPAT_INST(s); \
  icache[index].pc = s->pc; \
  icache[index].label = &&exe_##name; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_,t)); \
  icache[index].rd = rd; \
  icache[index].rs1 = BITS(icache[index].inst, 19, 15); \
  icache[index].rs2 = BITS(icache[index].inst, 24, 20); \
  icache[index].imm = imm; \
  __VA_ARGS__ ; \
}

  // TODO: fencei
  unsigned index = s->pc & (ICACHE_SIZE - 1);
  if (icache[index].pc == s->pc ) {
          s->dnpc = s->pc+4;
#ifdef CONFIG_TRACE
          s->snpc = s->pc+4;
          s->isa.inst.val = icache[index].inst;
          icache_hit++;
#endif 
          goto *icache[index].label;
  }
#ifdef CONFIG_TRACE
  icache_miss++;
#endif 
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  s->dnpc = s->snpc;
#endif //!CONFIG_USE_ICACHE

  

  //printf("s->pc: 0x" FMT_WORD_HEX "\n",s->pc);
  INSTPAT_START();
  //printf("nemu: src1: %08x src2: %08x imm: %08x\n",src1,src2,imm);
  //printf("nemu: rs1: %08x, cpu.gpr[rs1]=%08x\n",(uint32_t)BITS( s->isa.inst.val, 19, 15),cpu.gpr[BITS( s->isa.inst.val, 19, 15)]);
  //printf("nemu: cpu.grp[2]=%08x\n", cpu.gpr[2]);
   INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm); //addi(li,mv)
   INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));
   INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, BTRACE(s->pc,INSTPAT_INST(s), src1 != src2) s->dnpc = (src1 != src2 ? s->pc + imm : s->dnpc));
   INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = SEXT(Mr(src1 + imm, 4), 32));
   INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
   INSTPAT("000000? ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = src1 << SHAMT_LONG);
   INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, BTRACE(s->pc,INSTPAT_INST(s),src1 == src2) s->dnpc = (src1 == src2 ? s->pc + imm : s->dnpc));
   INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, BTRACE(s->pc,INSTPAT_INST(s), (word_t)src1 < (word_t)src2) s->dnpc = ((word_t)src1 < (word_t)src2 ? s->pc + imm : s->dnpc));
   INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, R(rd) = s->pc + 4; s->dnpc = (src1 + imm) & (~1)); //jalr(ret)
   INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
   INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
   INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->pc + 4; s->dnpc = s->pc + imm);


  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);


   INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
   INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));
   INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
  INSTPAT("??????? ????? ????? 110 ????? 00000 11", lwu    , I, R(rd) = Mr(src1 + imm, 4));
   
   INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = src1 & imm);
   
   INSTPAT("??????? ????? ????? 000 ????? 00110 11", addiw  , I ,R(rd) = SEXT(BITS(src1 + imm, 31, 0),32));
   INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I ,R(rd) = ((word_t)src1 < (word_t)imm ? 1 : 0));
   INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I ,R(rd) = ((sword_t)src1 < (sword_t)imm ? 1 : 0));
   
   INSTPAT("??????? ????? ????? 011 ????? 00000 11", ld     , I, R(rd) = Mr(src1 + imm, 8)); 
   INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = src1 ^ imm); //XORI rd, rs1, -1 =  NOT rd, rs
   INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = src1 | imm); 
   INSTPAT("010000? ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = (sword_t)src1 >> (sword_t)SHAMT_LONG);
   
   INSTPAT("0100000 ????? ????? 101 ????? 00110 11", sraiw  , I, R(rd) = SEXT((int32_t)src1 >> (int32_t)SHAMT, 32));
   INSTPAT("0100000 ????? ????? 101 ????? 00110 11", sraiw  , I, R(rd) = SEXT((int32_t)src1 >> (int32_t)SHAMT, 32));
  INSTPAT("0000000 ????? ????? 001 ????? 00110 11", slliw  , I, R(rd) = SEXT((uint32_t)src1 << SHAMT, 32));
  INSTPAT("0000000 ????? ????? 101 ????? 00110 11", srliw  , I, R(rd) = SEXT((uint32_t)src1 >> SHAMT, 32));
   INSTPAT("000000? ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = src1 >> SHAMT_LONG);

   INSTPAT("??????? ????? ????? 011 ????? 01000 11", sd     , S, Mw(src1 + imm, 8, src2)); 

   INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2));
   INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));


   
  
  
   
   
   INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, BTRACE(s->pc,INSTPAT_INST(s),(sword_t)src1 < (sword_t)src2)  s->dnpc = ((sword_t)src1 < (sword_t)src2 ? s->pc + imm : s->dnpc));
   INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, BTRACE(s->pc,INSTPAT_INST(s),((sword_t)src1 >= (sword_t)src2))  s->dnpc = (((sword_t)src1 >= (sword_t)src2 ? s->pc + imm : s->dnpc)));
   
   INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, BTRACE(s->pc,INSTPAT_INST(s),((word_t)src1 >= (word_t)src2))  s->dnpc = ((word_t)src1 >= (word_t)src2 ? s->pc + imm : s->dnpc));


   INSTPAT("0000000 ????? ????? 000 ????? 01110 11", addw   , R, R(rd) = SEXT(BITS((uint32_t)src1 + (uint32_t)src2, 31, 0),32));
   INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
   
   INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);
   
   INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
   INSTPAT("0000000 ????? ????? 001 ????? 01110 11", sllw   , R, R(rd) = SEXT((uint32_t)src1 << BITS(src2, 4, 0), 32));
   INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = ((word_t)src1 < (word_t)src2 ? 1 : 0));
   INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = ((sword_t)src1 < (sword_t)src2 ? 1 : 0));

   INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (sword_t)src1 >> (sword_t)src2);
   INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = (word_t)src1 >> (word_t)src2);
   
   INSTPAT("0100000 ????? ????? 101 ????? 01110 11", sraw   , R, R(rd) = SEXT((int32_t)src1 >> (int32_t)BITS(src2, 4, 0), 32));
   INSTPAT("0000000 ????? ????? 101 ????? 01110 11", srlw   , R, R(rd) = SEXT((uint32_t)src1 >> (uint32_t)BITS(src2, 4, 0), 32));
   INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << BITS(src2, 4, 0));


#ifndef CONFIG_RV32                                                            //不可直接转换到int64_t
   INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = BITS((int64_t)(int32_t)src1 * (int64_t)(int32_t)src2, 63,32));
   INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu  , R, R(rd) = BITS((uint64_t)(uint32_t)src1 * (uint64_t)(uint32_t)src2, 63,32));
#endif 
   INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = (sword_t)src1 * (sword_t)src2);
   INSTPAT("0000001 ????? ????? 000 ????? 01110 11", mulw   , R, R(rd) = SEXT(BITS(src1 * src2, 31, 0), 32));
   INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = (sword_t)src1 % (sword_t)src2);
   INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = (word_t)src1 % (word_t)src2);
   INSTPAT("0000001 ????? ????? 110 ????? 01110 11", remw   , R, R(rd) = SEXT((int32_t)BITS(src1,31,0)%(int32_t)BITS(src2,31,0) ,32));
   INSTPAT("0000001 ????? ????? 111 ????? 01110 11", remuv  , R, R(rd) = SEXT((uint32_t)BITS(src1,31,0)%(uint32_t)BITS(src2,31,0) ,32));
   INSTPAT("0100000 ????? ????? 000 ????? 01110 11", subw   , R, R(rd) = SEXT(BITS(src1 - src2, 31, 0), 32));
  
   INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = ((sword_t)src1 / (sword_t)src2));
   INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = ((word_t)src1 / (word_t)src2));
   INSTPAT("0000001 ????? ????? 100 ????? 01110 11", divw   , R, R(rd) = SEXT((int32_t)BITS(src1,31,0)/(int32_t)BITS(src2,31,0),  32));
   INSTPAT("0000001 ????? ????? 101 ????? 01110 11", divuw  , R, R(rd) = SEXT((uint32_t)BITS(src1,31,0)/(uint32_t)BITS(src2,31,0), 32));
  

  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, R(rd) = CSR(imm); CSR(imm) = src1);
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, R(rd) = CSR(imm); CSR(imm) |= src1);
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , N, ECALL(s->dnpc));
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , N, MRET());


	 INSTPAT("0000000 00000 00000 001 00000 00011 11", fence.i, N, MUXDEF(CONFIG_USE_ICACHE,fencei(),R(0)=0)); // fence.i
   INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
   INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));


#ifdef CONFIG_USE_ICACHE
#include "../../../tools/gen_icache_label/label_run.c"
#endif 

  INSTPAT_END();

  //printf("s->dnpc:0x" FMT_WORD_HEX_WIDTH ", s->snpc:0x%010lx, s->pc:0x" FMT_WORD_HEX_WIDTH "\n",s->dnpc,s->snpc,s->pc);
  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
#ifndef CONFIG_USE_ICACHE
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
#endif 
  return decode_exec(s);
}
