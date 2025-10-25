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
word_t csrr(word_t csr)
{
	csr = csr & 0xFFF;
	switch (csr)
	{
	case 0x300:
		return cpu.mstatus;
	case 0x305:
		return cpu.mtvec;
	case 0x341:
		return cpu.mepc;
	case 0x342:
		return cpu.mcause;
	case 0x343:
		return cpu.mtval;
	case 0x180:
		return cpu.satp;
	case 0x340:
		return cpu.mscratch; // Added for RISC-V
	case 0x114:
		return 0x79737978;
	case 0x514:
		return 25040129;
	default:
		printf("csr = 0x%x\n", csr);
		printf("pc = 0x%x\n", cpu.pc);
		assert(0);
		return 0;
	}
}
word_t csrw(word_t csr, word_t val)
{
	word_t old_val = csrr(csr); // Read the old value before writing
	csr = csr & 0xFFF;
	switch (csr)
	{
	case 0x300:
		cpu.mstatus = val;
		break;
	case 0x305:
		cpu.mtvec = val;
		break;
	case 0x341:
		cpu.mepc = val;
		break;
	case 0x342:
		cpu.mcause = val;
		break;
	case 0x343:
		cpu.mtval = val;
		break;
	case 0x180:
		cpu.satp = val;
		break;
	case 0x340:
		cpu.mscratch = val; // Added for RISC-V
		break;
	default:
		printf("csr = 0x%x\n", csr);
		printf("pc = 0x%x\n", cpu.pc);
		assert(0);
	}
	return old_val; // Return the old value before writing
}
#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum
{
	TYPE_I,
	TYPE_U,
	TYPE_S,
	TYPE_B,
	TYPE_RR,
	TYPE_J,
	TYPE_N, // none
};

#define src1R()         \
	do                  \
	{                   \
		*src1 = R(rs1); \
	} while (0)
#define src2R()         \
	do                  \
	{                   \
		*src2 = R(rs2); \
	} while (0)
#define immI()                            \
	do                                    \
	{                                     \
		*imm = SEXT(BITS(i, 31, 20), 12); \
	} while (0)
#define immU()                                  \
	do                                          \
	{                                           \
		*imm = SEXT(BITS(i, 31, 12), 20) << 12; \
	} while (0)
#define immS()                                                   \
	do                                                           \
	{                                                            \
		*imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); \
	} while (0)
#define immJ()                                                                                                  \
	do                                                                                                          \
	{                                                                                                           \
		*imm = (BITS(i, 31, 31) << 19) | (BITS(i, 19, 12) << 11) | (BITS(i, 20, 20) << 10) | (BITS(i, 30, 21)); \
		*imm = SEXT(*imm, 20) << 1;                                                                             \
	} while (0)
#define immB()                                                                                              \
	do                                                                                                      \
	{                                                                                                       \
		*imm = (BITS(i, 31, 31) << 11) | (BITS(i, 7, 7) << 10) | (BITS(i, 30, 25) << 4) | (BITS(i, 11, 8)); \
		*imm = SEXT(*imm, 12) << 1;                                                                         \
	} while (0)
static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type)
{
	uint32_t i = s->isa.inst;
	int rs1 = BITS(i, 19, 15);
	int rs2 = BITS(i, 24, 20);
	*rd = BITS(i, 11, 7);
	switch (type)
	{
	case TYPE_I:
		src1R();
		immI();
		break;
	case TYPE_U:
		immU();
		break;
	case TYPE_S:
		src1R();
		src2R();
		immS();
		break;
	case TYPE_N:
		break;
	case TYPE_RR:
		src1R();
		src2R();
		break;
	case TYPE_J:
		immJ();
		break;
	case TYPE_B:
		src1R();
		src2R();
		immB();
		break;
	default:
		panic("unsupported type = %d", type);
	}
}

static int decode_exec(Decode *s)
{
	s->dnpc = s->snpc;
#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */)             \
	{                                                                    \
		int rd = 0;                                                      \
		word_t src1 = 0, src2 = 0, imm = 0;                              \
		decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
		__VA_ARGS__;                                                     \
	}

	INSTPAT_START();
	// 模式匹配字符串
	// 对对应的操作码执行不同的操作
	// 有很多译码宏，灵活使用
	// 实现32位rsicv指令集中的li指令，addi指令，jal指令 ret指令//jalr sw指令 mv指令 j指令的解码和执行
	// li load immete 需要addi或者lui来实现
	INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr, I, {
		R(rd) = s->pc + 4;
		// printf("imm=%d\n", imm);
		s->dnpc = (src1 + imm) & ~1;
	});
	INSTPAT("??????? ????? ????? ??? ????? 00011 11", fence, I, );
	INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi, I, R(rd) = src1 & imm);
	INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori, I, R(rd) = src1 ^ imm);
	INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori, I, R(rd) = src1 | imm);
	INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw, S, {
		Mw(src1 + imm, 4, src2);
	});
	//                1000 00010 010 11000 01000 11
	INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw, I, R(rd) = Mr(src1 + imm, 4));
	INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh, I, R(rd) = SEXT((int16_t)Mr(src1 + imm, 2), 16));
	INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb, I, R(rd) = SEXT((int8_t)Mr(src1 + imm, 1), 8));
	INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
	INSTPAT("0011000 00010 00000 000 00000 11100 11", mret, I, {
		// printf("mret: :beg:mstatus = %x, mepc = %x, mcause = %d\n", cpu.mstatus, cpu.mepc, cpu.mcause);
		s->dnpc = cpu.mepc;
		word_t MPIE = (cpu.mstatus >> 7) & 1;
		cpu.mstatus &= ~(1 << 3); // MIE = 0
		cpu.mstatus &= ~(1 << 7); // MPIE = 0
		cpu.mstatus |= MPIE << 3; // MPIE = MIE
		// printf("mret:end:mstatus = %x\n", cpu.mstatus);
		// printf("mstatus restored to %x, there could be interrupt\n", cpu.mstatus);
		IFDEF(CONFIG_ETRACE, printf("error %d return to %x\n", cpu.mcause, s->dnpc));
	});
	INSTPAT("??????? ????? ????? 000 ????? 11100 11", ecall, I, { s->dnpc = isa_raise_intr(11, s->pc); });
	INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrw, I, R(rd) = csrw(imm, src1));
	INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrr, I, R(rd) = csrr(imm););
	INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc, U, R(rd) = s->pc + imm);
	INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui, U, R(rd) = imm);
	INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi, I, R(rd) = src1 + imm);
	INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll, RR, R(rd) = src1 << src2);
	INSTPAT("??????? ????? ????? 001 ????? 00100 11", slli, I, R(rd) = src1 << imm);
	INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add, RR, R(rd) = src1 + src2);
	INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu, I, R(rd) = src1 < (word_t)imm);
	INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti, I, R(rd) = (int32_t)src1 < imm);
	INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu, RR, R(rd) = src1 < src2);
	INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt, RR, R(rd) = (int32_t)src1 < (int32_t)src2);
	INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne, B, if (src1 != src2) s->dnpc += imm - 4);
	INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt, B, if ((int32_t)src1 < (int32_t)src2) s->dnpc += imm - 4);
	INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu, B, if (src1 < src2) s->dnpc += imm - 4);
	INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge, B, if ((int32_t)src1 >= (int32_t)src2) s->dnpc += imm - 4);
	INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu, B, if (src1 >= src2) s->dnpc += imm - 4);
	INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq, B, if (src1 == src2) s->dnpc += imm - 4);
	INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub, RR, R(rd) = src1 - src2);
	INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and, RR, R(rd) = src1 & src2);
	INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul, RR, {
		int32_t s1 = (int32_t)src1;
		int32_t s2 = (int32_t)src2;
		int64_t res = 0;

		if (s1 < 0 && s2 < 0)
			res = (int64_t)(-s1) * (int64_t)(-s2);
		else
			res = (int64_t)s1 * (int64_t)s2;

		R(rd) = (int32_t)res;
	});
	INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh, RR, {
		int32_t s1 = (int32_t)src1;
		int32_t s2 = (int32_t)src2;
		int64_t res = 0;

		if (s1 < 0 && s2 < 0)
			res = (int64_t)(-s1) * (int64_t)(-s2);
		else
			res = (int64_t)s1 * (int64_t)s2;

		R(rd) = (int32_t)(res >> 32);
	});
	INSTPAT("0000001 ????? ????? 010 ????? 01100 11", mulhsu, RR, {
		int32_t s1 = (int32_t)src1;
		uint32_t s2 = (uint32_t)src2;
		int64_t res = 0;

		res = (int64_t)s1 * (uint64_t)s2;

		R(rd) = (uint32_t)(res >> 32);
	});
	INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulhu, RR, {
		uint32_t s1 = src1;
		uint32_t s2 = src2;
		int64_t res = 0;
		res = (uint64_t)s1 * (uint64_t)s2;

		R(rd) = (uint32_t)(res >> 32);
	});
	INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div, RR, {
		if (src2 == 0)
			R(rd) = 0xFFFFFFFF;
		else if (src1 == INT32_MIN && src2 == -1)
			R(rd) = INT32_MIN;
		else
			R(rd) = (int)src1 / (int)src2;
	});

	INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu, RR, {
		if (src1 == 0)
			R(rd) = 0x0;
		else if (src2 == 0)
			R(rd) = 0xFFFFFFFF;
		else
			R(rd) = src1 / src2; });
	INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem, RR, {
		if (src2 == 0)
			R(rd) = src1;
		else if (src1 == INT32_MIN && src2 == -1)
			R(rd) = 0;
		else
			R(rd) = (int)src1 % (int)src2; });
	INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu, RR, {
				if (src2 == 0)
					R(rd) = src1;
				else
					R(rd) = src1 % src2; });
	INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor, RR, R(rd) = src1 ^ src2);
	INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or, RR, R(rd) = src1 | src2);
	INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal, J, {
		R(rd) = s->pc + 4;
		// printf("imm=%d\n", imm);
		s->dnpc = s->pc + imm;
	});

	INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu, I, R(rd) = Mr(src1 + imm, 1));
	INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu, I, R(rd) = Mr(src1 + imm, 2));
	INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai, I, R(rd) = (((int32_t)src1) >> imm));
	INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra, RR, R(rd) = (((int32_t)src1) >> (uint8_t)src2));
	INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl, RR, R(rd) = (((word_t)src1) >> src2));
	INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli, I, R(rd) = ((word_t)src1) >> imm);
	INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb, S, Mw(src1 + imm, 1, src2));
	INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh, S, Mw(src1 + imm, 2, src2));

	INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak, N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
	INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv, N, INV(s->pc));
	INSTPAT_END();

	R(0) = 0; // reset $zero to 0

	return 0;
}

int isa_exec_once(Decode *s)
{
	s->isa.inst = inst_fetch(&s->snpc, 4);
	return decode_exec(s);
}
