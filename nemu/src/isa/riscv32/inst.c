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
#include <elf.h>//ftrace

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write
//CSRs
static vaddr_t *csrs(word_t csr) {
	switch(csr){
		case 0x341: return &(cpu.csr.mepc);
		case 0x342: return &(cpu.csr.mcause);
		case 0x300: return &(cpu.csr.mstatus);
		case 0x305: return &(cpu.csr.mtvec);
		default: panic("Wait Add CSR");
	}
}
#define CSRs(i) *(csrs(i))

#define MRET() { \
	s->dnpc = CSRs(0x341); \
}

#ifdef CONFIG_ETRACE
	extern char *etrace_p;
	static void ETRACE() {
		etrace_p += sprintf(etrace_p, "ecall in mepc = %08x, mcause = %08x\n", cpu.csr.mepc, cpu.csr.mcause);
	}
#else
	static void ETRACE() {};
#endif
/***ftrace***/
#ifdef CONFIG_FTRACE
#define MAX_FTRACE_SIZE 1024
#define MAX_ELF_SIZE 2 * 1024 * 1024
void difftest_skip_ref();
typedef struct Ftrace
{
  word_t pc;
  word_t npc;
  word_t depth;
  bool ret;
} Ftrace;
Ftrace ftracebuf[MAX_FTRACE_SIZE];
word_t ftracehead = 0;
word_t ftracedepth = 0;
char elfbuf[MAX_ELF_SIZE];
typedef MUXDEF(CONFIG_ISA64, Elf64_Ehdr, Elf32_Ehdr) Elf_Ehdr;
typedef MUXDEF(CONFIG_ISA64, Elf64_Shdr, Elf32_Shdr) Elf_Shdr;
typedef MUXDEF(CONFIG_ISA64, Elf64_Sym, Elf32_Sym) Elf_Sym;
Elf_Ehdr elf_ehdr;
Elf_Shdr *elfshdr_symtab = NULL, *elfshdr_strtab = NULL;
#endif
/******/

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_R, TYPE_B,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immB() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 12) | (BITS(i, 30, 25) << 5) | (BITS(i, 11, 8) << 1) | (BITS(i, 7,7) << 11); } while(0)
#define immJ() do { *imm = (SEXT(BITS(i, 31, 31), 1) << 20) | (BITS(i, 19, 12) << 12) | (BITS(i, 20, 20) << 11) | (BITS(i, 30, 21) << 1) ;} while(0)
#define Shamt() do { *shamt = BITS(i, 25, 20); } while (0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, word_t *shamt, int type) {
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R(); Shamt(); immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
		case TYPE_J:									 immJ(); break;
		case TYPE_R: src1R(); src2R();				 break;
		case TYPE_B: src1R(); src2R(); immB(); break;
  }
}

static int decode_exec(Decode *s) {
  int rd = 0;
  word_t src1 = 0, src2 = 0, imm = 0, shamt = 0;
  s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  decode_operand(s, &rd, &src1, &src2, &imm, &shamt, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}

  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc  , U, R(rd) = s->pc + imm);
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, R(rd) = Mr(src1 + imm, 1));
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, src2));
/***I***/
	INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi   , I, R(rd) = src1 + imm);
	INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, s->dnpc = ((src1 + imm)&(~1)); R(rd) = s->pc + 4);
	INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
	INSTPAT("??????? ????? ????? 010 ????? 00100 11", slti   , I, R(rd) = ((int)src1 < (int)imm));
	INSTPAT("??????? ????? ????? 011 ????? 00100 11", sltiu  , I, R(rd) = (src1 < imm));
	INSTPAT("0100000 ????? ????? 101 ????? 00100 11", srai   , I, R(rd) = ((int)src1 >> shamt));
	INSTPAT("??????? ????? ????? 111 ????? 00100 11", andi   , I, R(rd) = (src1 & imm));
	INSTPAT("??????? ????? ????? 110 ????? 00100 11", ori    , I, R(rd) = (src1 | imm));
	INSTPAT("??????? ????? ????? 100 ????? 00100 11", xori   , I, R(rd) = (src1 ^ imm));
	INSTPAT("0000000 ????? ????? 101 ????? 00100 11", srli   , I, R(rd) = (src1 >> shamt));
	INSTPAT("0000000 ????? ????? 001 ????? 00100 11", slli   , I, R(rd) = (src1 << shamt));
	INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, R(rd) = SEXT(Mr(src1 + imm, 1), 8));
	INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, R(rd) = SEXT(Mr(src1 + imm, 2), 16));
	INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, R(rd) = Mr(src1 + imm, 2));
/***R***/
	INSTPAT("0000000 ????? ????? 000 ????? 01100 11", add    , R, R(rd) = src1 + src2);
	INSTPAT("0100000 ????? ????? 000 ????? 01100 11", sub    , R, R(rd) = src1 - src2);
	INSTPAT("0000000 ????? ????? 011 ????? 01100 11", sltu   , R, R(rd) = (src1 < src2));
	INSTPAT("0000000 ????? ????? 100 ????? 01100 11", xor    , R, R(rd) = src1 ^ src2);
	INSTPAT("0000000 ????? ????? 110 ????? 01100 11", or     , R, R(rd) = src1 | src2);
	INSTPAT("0000000 ????? ????? 001 ????? 01100 11", sll    , R, R(rd) = src1 << src2);
	INSTPAT("0000000 ????? ????? 010 ????? 01100 11", slt    , R, R(rd) = (int)src1 < (int)src2);
	INSTPAT("0100000 ????? ????? 101 ????? 01100 11", sra    , R, R(rd) = (int)src1 >> (src2 & 0x0000001f));
	INSTPAT("0000000 ????? ????? 101 ????? 01100 11", srl    , R, R(rd) = src1 >> (src2 & 0x0000001f));
	INSTPAT("0000000 ????? ????? 111 ????? 01100 11", and    , R, R(rd) = src1 & src2);
	INSTPAT("0000001 ????? ????? 000 ????? 01100 11", mul    , R, R(rd) = src1 * src2);
	INSTPAT("0000001 ????? ????? 001 ????? 01100 11", mulh   , R, R(rd) = (sword_t)(((int64_t)(sword_t)src1 * (int64_t)(sword_t)src2) >> 32));//
	INSTPAT("0000001 ????? ????? 011 ????? 01100 11", mulh   , R, R(rd) = ((uint64_t)src1 * (uint64_t)src2 >> 32));
	INSTPAT("0000001 ????? ????? 100 ????? 01100 11", div    , R, R(rd) = (int)src1 / (int)src2);
	INSTPAT("0000001 ????? ????? 101 ????? 01100 11", divu   , R, R(rd) = src1 / src2);
	INSTPAT("0000001 ????? ????? 110 ????? 01100 11", rem    , R, R(rd) = (int)src1 % (int)src2);
	INSTPAT("0000001 ????? ????? 111 ????? 01100 11", remu   , R, R(rd) = src1 % src2);
/***S***/
	INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));
	INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, Mw(src1 + imm, 2, src2));
/***B***/
	INSTPAT("??????? ????? ????? 000 ????? 11000 11", beq    , B, if(src1 == src2) s->dnpc = s->pc + imm);
	INSTPAT("??????? ????? ????? 001 ????? 11000 11", bne    , B, if(src1 != src2) s->dnpc = s->pc + imm);
	INSTPAT("??????? ????? ????? 101 ????? 11000 11", bge    , B, if((int)src1 >= (int)src2) s->dnpc = s->pc + imm);
	INSTPAT("??????? ????? ????? 111 ????? 11000 11", bgeu   , B, if(src1 >= src2) s->dnpc = s->pc + imm);
	INSTPAT("??????? ????? ????? 100 ????? 11000 11", blt    , B, if((int)src1 < (int)src2) s->dnpc = s->pc + imm);
	INSTPAT("??????? ????? ????? 110 ????? 11000 11", bltu   , B, if(src1 < src2) s->dnpc = s->pc + imm);
/***U***/
	INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
/***J***/	
	INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, R(rd) = s->pc + 4; s->dnpc = s->pc + imm);
/******/
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
#ifdef CONFIG_TARGET_SHARE
	INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, s->dnpc = isa_raise_intr(R(15), s->pc); ETRACE()); //RISCV32E R(15) is $a5
#else
	INSTPAT("0000000 00000 00000 000 00000 11100 11", ecall  , I, s->dnpc = isa_raise_intr(R(17), s->pc); ETRACE()); //R(17) is $a7
#endif
	INSTPAT("??????? ????? ????? 001 ????? 11100 11", csrrw  , I, R(rd) = CSRs(imm); CSRs(imm) = src1);
	INSTPAT("??????? ????? ????? 010 ????? 11100 11", csrrs  , I, R(rd) = CSRs(imm); CSRs(imm) |= src1);
	INSTPAT("??????? ????? ????? 011 ????? 11100 11", csrrc  , I, R(rd) = CSRs(imm); CSRs(imm) &= ~src1);
	INSTPAT("0011000 00010 00000 000 00000 11100 11", mret   , R, MRET(););
	INSTPAT("0000000 00000 00000 001 00000 00011 11", fencei , I);
	INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

#ifdef CONFIG_FTRACE
	//fbreak jalr: 0b1100111 ; jal: 0b1101111
	uint32_t opcode = BITS(s->isa.inst.val, 6, 0);
  if (opcode == 0b1100111 || opcode == 0b1101111) {
    ftracebuf[ftracehead].pc = s->pc;
    ftracebuf[ftracehead].npc = s->dnpc;
    // jalr x0, 0(x1): 0x00008067, a.k.a. ret
    if (s->isa.inst.val == 0x00008067) {
      ftracebuf[ftracehead].ret = true;
      ftracedepth--;
      ftracebuf[ftracehead].depth = ftracedepth;
    } else {
      ftracebuf[ftracehead].ret = false;
      ftracebuf[ftracehead].depth = ftracedepth;
      ftracedepth++;
    }
    ftracehead = (ftracehead + 1) % MAX_FTRACE_SIZE;
  }
#endif
	
  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);
  return decode_exec(s);
}

/***ftrace***/
#ifdef CONFIG_FTRACE
void isa_parser_elf(char *filename) {
  printf("ELF FILE is:%s\n", filename);
	FILE *fp = fopen(filename, "rb");
  Assert(fp, "Can not open '%s'", filename);
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  Assert(size < MAX_ELF_SIZE, "elf file is too large");
  fseek(fp, 0, SEEK_SET);
  int ret = fread(&elf_ehdr, sizeof(elf_ehdr), 1, fp);
	printf("slf_ehdr_size = %ld\n", sizeof(elf_ehdr));
  assert(ret == 1);
  assert(memcmp(elf_ehdr.e_ident, ELFMAG, SELFMAG) == 0);
  fseek(fp, 0, SEEK_SET);
  ret = fread(elfbuf, size, 1, fp);
  assert(ret == 1);
  fclose(fp);

  printf("e_ident: ");
  for (size_t i = 0; i < SELFMAG; i++) {
    printf("%02x ", elf_ehdr.e_ident[i]);
  }
  printf("\n");
  printf("e_type: %d\t", elf_ehdr.e_type);
  printf("e_machine: %d\t", elf_ehdr.e_machine);
  printf("e_version: %d\n", elf_ehdr.e_version);
  printf("e_entry: " FMT_WORD "\t", elf_ehdr.e_entry);
  printf("e_phoff: " FMT_WORD "\n", elf_ehdr.e_phoff);
  printf("e_shoff: " FMT_WORD "\t", elf_ehdr.e_shoff);
  printf("e_flags: 0x%016x\n", elf_ehdr.e_flags);
  printf("e_ehsize: %d\t", elf_ehdr.e_ehsize);
  printf("e_phentsize: %d\t", elf_ehdr.e_phentsize);
  printf("e_phnum: %d\n", elf_ehdr.e_phnum);
  printf("e_shentsize: %d\t", elf_ehdr.e_shentsize);
  printf("e_shnum: %d\t", elf_ehdr.e_shnum);
  printf("e_shstrndx: %d\n", elf_ehdr.e_shstrndx);
  for (size_t i = 0; i < elf_ehdr.e_shnum; i++) {
    Elf_Shdr *shdr = (Elf_Shdr *)(elfbuf + elf_ehdr.e_shoff + i * elf_ehdr.e_shentsize);
    if (shdr->sh_type == SHT_SYMTAB) {
      elfshdr_symtab = shdr;
    } else if (shdr->sh_type == SHT_STRTAB) {
      elfshdr_strtab = shdr;
    }
    if (elfshdr_symtab != NULL && elfshdr_strtab != NULL) {
      break;
      for (size_t j = 0; j < elfshdr_symtab->sh_size / sizeof(Elf_Sym); j++) {
        Elf_Sym *sym = (Elf_Sym *)(elfbuf + elfshdr_symtab->sh_offset + j * sizeof(Elf_Sym));
        printf("" FMT_WORD ": %s\n", sym->st_value, elfbuf + elfshdr_strtab->sh_offset + sym->st_name);
      }
      break;
    }
  }
}

void cpu_show_ftrace() {
  Elf_Sym *sym = NULL;
  Ftrace *ftrace = NULL;
  for (size_t i = 0; i < ftracehead; i++) {
    ftrace = ftracebuf + i;
    printf("" FMT_WORD ": ", ftrace->pc);
    for (size_t j = 0; j < ftrace->depth; j++) {
      printf("  ");
    }
    printf("%s ", ftrace->ret ? "ret" : "call");
    if (elfshdr_symtab == NULL) {
      printf("\n");
      continue;
    }
    for (int j = elfshdr_symtab->sh_size / sizeof(Elf_Sym) - 1; j >= 0; j--) {
      sym = (Elf_Sym *)(elfbuf + elfshdr_symtab->sh_offset + j * sizeof(Elf_Sym));
      if (sym->st_value == ftrace->npc) {
        break;
      }
    }
    printf(
      "[%s@" FMT_WORD "]\n",
      elfbuf + elfshdr_strtab->sh_offset + sym->st_name,
      ftrace->npc);
  }
}
#else
void isa_parser_elf(char *filename){};
#endif
/******/
