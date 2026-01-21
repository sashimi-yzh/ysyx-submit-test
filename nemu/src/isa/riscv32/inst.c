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
#include "local-include/csr.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include <common.h>

#define Reg(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_B, TYPE_R,
  TYPE_N, // none
};

enum {
  // RV32I
  lui, auipc, jal, jalr, beq, bne, blt, bge, bltu, bgeu, 
  lb, lh, lw, lbu, lhu, sb, sh, sw, addi, slti, 
  sltiu, xori, ori, andi, slli, srli, srai, add, sub, sll,
  slt, sltu, xor, srl, sra, or, and, fence, fence_tso, 
  pause, ecall, ebreak,  
  // RV32M
  mul_, mulh_, mulhsu_, mulhu_, div_, divu_, rem_, remu_,
  // RV32Zicsr
  csrrw, csrrs, csrrc, csrrwi, csrrsi, csrrci,
  // 特权指令
  mret, 
  // NEMU
  inv,
};

enum {
  // 算数
  ADD, SUB, 
  // 逻辑运算
  XOR, OR, AND,
  // 比较
  EQ, NEQ, LEQ_U, GEQ_U, LEQ, GEQ,
  // 移位 
  SRA, SLL, SRL, 
  // 乘除法
  MUL, MULH, MULHSU, MULHU, DIV, DIVU, REM, REMU,
  // csr操作
  CSRRW, CSRRS, CSRRC,
};

#define src1R() do { *src1 = Reg(rs1); } while (0)
#define src2R() do { *src2 = Reg(rs2); } while (0)
#define immI() do { if(name == csrrwi || name == csrrci || name == csrrsi) *imm = BITS(i, 19, 15);\
                    else if(name == srai) *imm = BITS(i, 24, 20); \
                    else *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | (BITS(i, 19, 12) << 12) | \
                    (BITS(i, 20, 20) << 11) | (BITS(i, 30, 21) << 1) | 0; } while(0)
#define immB() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 12) | (BITS(i, 7, 7) << 11) | \
                    (BITS(i, 30, 25) << 5) | (BITS(i, 11, 8) << 1) | 0;} while (0)


static word_t alu(const word_t op1, const word_t op2, int op) {
  int32_t int_op1 = (int32_t)op1;
  int32_t int_op2 = (int32_t)op2;
  word_t  op2_low5 = BITS(op2, 4, 0);

  switch (op)
  { 
    case ADD:     return op1 + op2;
    case SUB:     return op1 - op2;
    case XOR:     return op1 ^ op2;
    case OR:      return op1 | op2;
    case AND:     return op1 & op2;
    case EQ:      return op1 == op2;
    case NEQ:     return op1 != op2;
    case LEQ_U:   return op1 < op2;
    case GEQ_U:   return op1 >= op2;
    case LEQ:     return int_op1 <  int_op2;
    case GEQ:     return int_op1 >= int_op2;
    case SRA:     return int_op1 >> op2_low5;
    case SLL:     return op1 << op2_low5;
    case SRL:     return op1 >> op2_low5;
    default:      return 0;
  }
}

static word_t mul_div(Decode *s, const word_t op1, const word_t op2, int op) {
  int64_t result_mul;
  int32_t int_op1 = (int32_t)op1;
  int32_t int_op2 = (int32_t)op2;

  if (op == DIV && int_op1 == INT32_MIN && int_op2 == -1) {
    printf("PC = 0x%x, 检测到除法溢出: %d / %d\n", s->pc, int_op1, int_op2);
    return (word_t)INT32_MIN; // 返回一个合理的值，例如 INT32_MIN
  }

  if (op == REM && int_op1 == INT32_MIN && int_op2 == -1) {
    printf("PC = 0x%x, 检测到求余数溢出: %d %% %d\n", s->pc, int_op1, int_op2);
    return 0; // 因为求余用到了除法，所以也需要区分
  }

  if ((op == DIV || op == DIVU) && op2 == 0) {
    printf("PC = 0x%x, 检测到除0: %d / %d\n", s->pc, int_op1, int_op2);
    return (word_t)UINT32_MAX; // 返回一个合理的值，例如 INT32_MIN
  }

  if ((op == REM || op == REMU) && op2 == 0) {
    printf("PC = 0x%x, 检测到对0求余: %d %% %d\n", s->pc, int_op1, int_op2);
    return op1; // 返回一个合理的值，例如 INT32_MIN
  }

  switch (op)
  {
    case MUL:     return int_op1 * int_op2;
    case MULH:
      result_mul = (int64_t)int_op1 * (int64_t)int_op2;
      return (word_t)BITS(result_mul, 63, 32);
    case MULHU:
      result_mul = (int64_t)op1 * (int64_t)op2;
      return (word_t)BITS(result_mul, 63, 32);
    case MULHSU:
      result_mul = (int64_t)int_op1 * (int64_t)op2;
      return (word_t)BITS(result_mul, 63, 32);
    case DIV:     return int_op1 / int_op2;
    case DIVU:    return op1 / op2;
    case REM:     return int_op1 % int_op2;
    case REMU:    return op1 % op2;
    default:      return 0;
  }
}

static void csru(Decode *s, int op, const word_t src_value, const int rd )
{
  uint32_t i = s->isa.inst;
  uint16_t csr_addr = BITS(i, 31, 20);
  int rs1 = BITS(i, 19, 15);
  int csr_index;
  bool csr_index_state = false;
  for(int i = 0; i < ARRLEN(csrs); i++) 
  {
    if(csrs[i].addr == csr_addr) {
      csr_index = i;
      csr_index_state = true;
      break;
    }
  }
  Assert(csr_index_state == true, "你访问的csr没有实现或者不存在, 地址为%x\n", csr_addr);
  word_t new_value = src_value & (~csrs[csr_index].wpri_mask); //考虑wpri字段
  switch (op)
  {
	case CSRRW:
		if (rd != 0) {
		Reg(rd) = csrs[csr_index].value;
		}
		// printf("CSRRW对象为%s, rd为%d, csr旧值为0x%08x,",csrs[csr_index].name, rd, csrs[csr_index].value);
		csrs[csr_index].value = new_value;
		// printf(" 新值为0x%08x\n", csrs[csr_index].value);
		break;
	case CSRRS:
		Reg(rd) = csrs[csr_index].value;
		// printf("CSRRS对象为%s, rd%d, csr旧值为0x%08x,",csrs[csr_index].name, rd, csrs[csr_index].value);
		if (rs1 != 0) {
		csrs[csr_index].value |= new_value;
		// printf(" 新值为0x%08x, 操作的value为0x%08x\n", csrs[csr_index].value, new_value);
		}
		break;
	case CSRRC:
		Reg(rd) = csrs[csr_index].value;
		// printf("CSRRC对象为%s, rd%d, csr旧值为0x%08x,",csrs[csr_index].name, rd, csrs[csr_index].value);
		if (rs1 != 0) {
		csrs[csr_index].value &= ~new_value;
		// printf(" 新值为0x%08x, 操作的value为0x%08x\n", csrs[csr_index].value, new_value);
		}
		break;
	default:	Assert(0, "非法的CSR操作，操作代号为%d\n", op);
		break;
  }
}

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type, int name) {
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

// FTRACER部分内容
//===============================================
#ifdef CONFIG_FTRACE
struct {
  word_t ret_addr;
  uint8_t num;
}FUNC_stack[8] = {0};

char repeat_buf[2][128] = {{0}};
char _buf[128] = {0};

static void ftracer_log(Decode *s, int name)
{
  static int repeat_count = 0;
  static uint32_t p_stack = 0;
  // 识别 call 调用函数
  if(name == jal || name == jalr)
  {
    for(int i = 0; i < FUNC_nums; i++)
    {
      if(FUNC_FTRACER[i].addr == 0) break;
      if(s->dnpc == FUNC_FTRACER[i].addr)
      {
        Assert(p_stack < ARRLEN(FUNC_stack), "调用太深, ftracer的堆栈溢出了");
        snprintf(_buf, sizeof(_buf), "0x%8x %u C [%s @ 0x%8x]\n", s->pc, p_stack, FUNC_FTRACER[i].func_name, s->dnpc);
        if(!strcmp(_buf, repeat_buf[1])) {
          repeat_count++;
        } else {
          if(repeat_count) {
            ftracer_write("重复%d次, count = %d\n", repeat_count/2 + 1, repeat_count);
            repeat_count = 0;
          }
          ftracer_write("%s", _buf);
        }
        strcpy(repeat_buf[1], repeat_buf[0]);
        strcpy(repeat_buf[0], _buf);        
        FUNC_stack[p_stack].num = i;
        FUNC_stack[p_stack].ret_addr = s->snpc;
        p_stack++;
      }
    }
  }
  // 识别 ret 返回函数
  if(s->isa.inst == 0x00008067)
  {
    if(p_stack <= ARRLEN(FUNC_stack)) {
      bool good_ret = false;
      uint32_t p_stack_init = p_stack;
      while (p_stack--)
      {
        if(Reg(1) == FUNC_stack[p_stack].ret_addr) {
          good_ret = true;
          break;
        }
      }
      if(good_ret) {
        snprintf(_buf, sizeof(_buf), "0x%8x %u R [%s @ 0x%8x]\n",s->pc, p_stack, FUNC_FTRACER[FUNC_stack[p_stack].num].func_name, Reg(1));
        if(!strcmp(_buf, repeat_buf[1])) {
          repeat_count++;
        } else {
          if(repeat_count) {
            ftracer_write("重复%d次, count = %d\n", repeat_count/2 + 1, repeat_count);
            repeat_count = 0;
          }
          ftracer_write("%s", _buf);
        }
        strcpy(repeat_buf[1], repeat_buf[0]);
        strcpy(repeat_buf[0], _buf);        
      } else {
        p_stack = p_stack_init;
      }
    }
  }
}
#endif
//===============================================
static int decode_exec(Decode *s) {
  s->dnpc = s->snpc;

#ifdef CONFIG_BTRACE
  #define TRACE_COMMON \
    memcpy(p, &s->pc, 4); p += 4; \
    memcpy(p, &s->dnpc, 4); p += 4; \
    memset(p, 0, 4); \
    btrace_write(&s->branchbuf)
#endif
#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type), name); \
  __VA_ARGS__ ; \
  IFDEF(CONFIG_FTRACE,ftracer_log(s, name)); \
}
	// 放到具体指令之后
	// printf("imm = %d  %u  %x \nsrc1 = %x, src2 = %x, rd = %s, Reg(rd) = %x\n$pc = 0x%x\n",(int)imm, imm, imm, src1, src2, reg_name(rd), Reg(rd), s->pc); 
  IFDEF(CONFIG_BTRACE, char *p = s->branchbuf;)
  INSTPAT_START();
  // RV32I
  INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = imm);
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, Reg(rd) = s->snpc; s->dnpc = alu(s->pc, imm, ADD); IFDEF(CONFIG_BTRACE, memcpy(p, &s->pc, 4); p += 4; memcpy(p, &s->dnpc, 4); p+=4; memset(p, 1, 1); p++; if(rd == 1) memset(p, 2, 3); else memset(p, 3, 3); btrace_write(&s->branchbuf)));
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, Reg(rd) = s->snpc; s->dnpc = (alu(src1, imm, ADD) & ~1); IFDEF(CONFIG_BTRACE, memcpy(p, &s->pc, 4); p += 4; memcpy(p, &s->dnpc, 4); p+=4; memset(p, 1, 4); p++; if(s->isa.inst == 0x00008067) memset(p, 1, 3); else if(rd == 1) memset(p, 2, 3); else memset(p, 3, 3); btrace_write(&s->branchbuf)));
  INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(alu(src1, src2, EQ))    s->dnpc = alu(s->pc, imm, ADD); IFDEF(CONFIG_BTRACE, memcpy(p, &s->pc, 4); p += 4; memcpy(p, &s->dnpc, 4); p += 4; if(alu(src1, src2, EQ))    memset(p, 1, 4); else memset(p, 0, 4); p++; memset(p, 3, 3); btrace_write(&s->branchbuf)));
  INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if(alu(src1, src2, NEQ))   s->dnpc = alu(s->pc, imm, ADD); IFDEF(CONFIG_BTRACE, memcpy(p, &s->pc, 4); p += 4; memcpy(p, &s->dnpc, 4); p += 4; if(alu(src1, src2, NEQ))   memset(p, 1, 4); else memset(p, 0, 4); p++; memset(p, 3, 3); btrace_write(&s->branchbuf)));
  INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if(alu(src1, src2, LEQ))   s->dnpc = alu(s->pc, imm, ADD); IFDEF(CONFIG_BTRACE, memcpy(p, &s->pc, 4); p += 4; memcpy(p, &s->dnpc, 4); p += 4; if(alu(src1, src2, LEQ))   memset(p, 1, 4); else memset(p, 0, 4); p++; memset(p, 3, 3); btrace_write(&s->branchbuf)));
  INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if(alu(src1, src2, GEQ))   s->dnpc = alu(s->pc, imm, ADD); IFDEF(CONFIG_BTRACE, memcpy(p, &s->pc, 4); p += 4; memcpy(p, &s->dnpc, 4); p += 4; if(alu(src1, src2, GEQ))   memset(p, 1, 4); else memset(p, 0, 4); p++; memset(p, 3, 3); btrace_write(&s->branchbuf)));
  INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if(alu(src1, src2, LEQ_U)) s->dnpc = alu(s->pc, imm, ADD); IFDEF(CONFIG_BTRACE, memcpy(p, &s->pc, 4); p += 4; memcpy(p, &s->dnpc, 4); p += 4; if(alu(src1, src2, LEQ_U)) memset(p, 1, 4); else memset(p, 0, 4); p++; memset(p, 3, 3); btrace_write(&s->branchbuf)));
  INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if(alu(src1, src2, GEQ_U)) s->dnpc = alu(s->pc, imm, ADD); IFDEF(CONFIG_BTRACE, memcpy(p, &s->pc, 4); p += 4; memcpy(p, &s->dnpc, 4); p += 4; if(alu(src1, src2, GEQ_U)) memset(p, 1, 4); else memset(p, 0, 4); p++; memset(p, 3, 3); btrace_write(&s->branchbuf)));
  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);IFDEF(CONFIG_BTRACE, TRACE_COMMON); Reg(rd) = SEXT(BITS(Mr(src1 + imm, 1), 7, 0), 8));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = SEXT(BITS(Mr(src1 + imm, 2), 15, 0), 16));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = Mr(src1 + imm, 4));
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = Mr(src1 + imm, 2));
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Mw(src1 + imm, 1, src2));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Mw(src1 + imm, 2, src2));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Mw(src1 + imm, 4, src2););
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, imm, ADD));
  INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, imm, LEQ));
  INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, imm, LEQ_U));
  INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, imm, XOR));
  INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, imm, OR));
  INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, imm, AND));
  INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, imm, SLL));
  INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, imm, SRL));
  INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, imm, SRA));
  INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, ADD));
  INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, SUB));
  INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, SLL));
  INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, LEQ));
  INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, LEQ_U));
  INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, XOR));
  INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, SRL));
  INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, SRA));
  INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, OR));
  INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON);Reg(rd) = alu(src1, src2, AND));

  INSTPAT("??????? ????? ????? 000 ????? 00011 11", fence      , N,IFDEF(CONFIG_BTRACE, TRACE_COMMON) );
  INSTPAT("1000001 10011 00000 000 00000 00011 11", fence_tso  , N,IFDEF(CONFIG_BTRACE, TRACE_COMMON) );
  INSTPAT("0000000 10000 00000 000 00000 00011 11", pause      , N,IFDEF(CONFIG_BTRACE, TRACE_COMMON) );
  INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall      , N,IFDEF(CONFIG_BTRACE, TRACE_COMMON); s->dnpc = isa_raise_intr(11,s->pc));
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak     , N,IFDEF(CONFIG_BTRACE, TRACE_COMMON); NEMUTRAP(s->pc, Reg(10))); // R(10) is $a0
  // RV32M
  INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul_   , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON); Reg(rd) = mul_div(s, src1, src2, MUL));
  INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh_  , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON); Reg(rd) = mul_div(s, src1, src2, MULH));
  INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu_, R, IFDEF(CONFIG_BTRACE, TRACE_COMMON); Reg(rd) = mul_div(s, src1, src2, MULHSU));
  INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu_ , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON); Reg(rd) = mul_div(s, src1, src2, MULHU));
  INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div_   , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON); Reg(rd) = mul_div(s, src1, src2, DIV));
  INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu_  , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON); Reg(rd) = mul_div(s, src1, src2, DIVU));
  INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem_   , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON); Reg(rd) = mul_div(s, src1, src2, REM));
  INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu_  , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON); Reg(rd) = mul_div(s, src1, src2, REMU));
  // RV32Zicsr
  INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON); csru(s, CSRRW, src1, rd));
  INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON); csru(s, CSRRS, src1, rd));
  INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc  , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON); csru(s, CSRRC, src1, rd));
  INSTPAT("??????? ????? ????? 101 ????? 11100 11", csrrwi , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON); csru(s, CSRRW, imm, rd));
  INSTPAT("??????? ????? ????? 110 ????? 11100 11", csrrsi , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON); csru(s, CSRRS, imm, rd));
  INSTPAT("??????? ????? ????? 111 ????? 11100 11", csrrci , I, IFDEF(CONFIG_BTRACE, TRACE_COMMON); csru(s, CSRRC, imm, rd));
  // 特权指令
  INSTPAT("0011000 00010 00000 000 00000 11100 11", mret , R, IFDEF(CONFIG_BTRACE, TRACE_COMMON); s->dnpc = csrs[0].value);
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv  , N, IFDEF(CONFIG_BTRACE, TRACE_COMMON); INV(s->pc));
  INSTPAT_END();
  Reg(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}
