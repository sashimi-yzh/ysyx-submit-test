#include "ftrace.hpp"
#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


/* ftrace 调用深度（缩进水平） */
static int ftrace_depth = 0;

/*
 * 检测当前指令是否为函数调用或返回。
 * RISC-V 中：
 *   JAL  opcode=0x6F: rd==1 (ra) 表示函数调用
 *   JALR opcode=0x67  funct3=0:
 *     rd==0, rs1==1 (ra) 表示返回 (ret)
 *     rd==1           表示间接调用
 */
void ftrace_detect(uint32_t inst, uint32_t pc, uint32_t npc)
{
  if (ftrace_info.symtab == NULL)
    return;

  uint32_t opcode = inst & 0x7F;
  uint32_t rd = (inst >> 7) & 0x1F;
  uint32_t rs1 = (inst >> 15) & 0x1F;
  uint32_t funct3 = (inst >> 12) & 0x7;

  if (opcode == 0x6F)
  { /* JAL */
    if (rd == 1 || rd == 5)
    { /* rd = ra 或 t0 → 函数调用 */
      uint32_t func_addr = npc;
      const char *name = ftrace_find_func(npc, &func_addr);
      printf("0x%08x: %*scall [%s@0x%08x]\n",
             (uint32_t)pc, ftrace_depth * 2, "",
             name ? name : "???", (uint32_t)func_addr);
      ftrace_depth++;
    }
  }
  else if (opcode == 0x67 && funct3 == 0)
  { /* JALR */
    if (rd == 0 && (rs1 == 1 || rs1 == 5))
    { /* jalr x0, ra, 0 → ret */
      uint32_t func_addr = pc;
      const char *name = ftrace_find_func(pc, &func_addr);
      if (ftrace_depth > 0)
        ftrace_depth--;
      printf("0x%08x: %*sret  [%s]\n",
             (uint32_t)pc, ftrace_depth * 2, "",
             name ? name : "???");
    }
    else if (rd == 1 || rd == 5)
    { /* jalr ra, rs, imm → 间接调用 */
      uint32_t func_addr = npc;
      const char *name = ftrace_find_func(npc, &func_addr);
      printf("0x%08x: %*scall [%s@0x%08x]\n",
             (uint32_t)pc, ftrace_depth * 2, "",
             name ? name : "???", (uint32_t)func_addr);
      ftrace_depth++;
    }
  }
}

ftrace_t ftrace_info = {.symtab = NULL, .strtab = NULL, .symtab_size = 0};
extern char *elf_file;

void init_elf() {
  if (elf_file == NULL) return;

  FILE *fp = fopen(elf_file, "rb");
  assert(fp);

  // 读取 ELF 文件头并校验魔数
  Elf32_Ehdr ehdr;
  int ret = fread(&ehdr, sizeof(ehdr), 1, fp);
  assert(ret == 1);
  assert(memcmp(ehdr.e_ident, ELFMAG, SELFMAG) == 0);

  // 读取所有节区头
  Elf32_Shdr *shdrs = (decltype(shdrs))malloc(sizeof(Elf32_Shdr) * ehdr.e_shnum);
  fseek(fp, ehdr.e_shoff, SEEK_SET);
  ret = fread(shdrs, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
  assert(ret == ehdr.e_shnum);

  // 找到符号表节区（SHT_SYMTAB）
  int symtab_idx = -1;
  for (int i = 0; i < ehdr.e_shnum; i++) {
    if (shdrs[i].sh_type == SHT_SYMTAB) {
      symtab_idx = i;
      break;
    }
  }

  if (symtab_idx < 0) {
    printf("ftrace: no symbol table found in %s\n", elf_file);
    free(shdrs);
    fclose(fp);
    return;
  }

  // sh_link 字段指向对应的字符串表节区
  Elf32_Shdr *symtab_shdr = &shdrs[symtab_idx];
  Elf32_Shdr *strtab_shdr = &shdrs[symtab_shdr->sh_link];

  // 读取符号表
  ftrace_info.symtab_size = symtab_shdr->sh_size / sizeof(Elf32_Sym);
  ftrace_info.symtab = (decltype(ftrace_info.symtab))malloc(symtab_shdr->sh_size);
  fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
  ret = fread(ftrace_info.symtab, symtab_shdr->sh_size, 1, fp);
  assert(ret == 1);

  // 读取字符串表
  ftrace_info.strtab = (decltype(ftrace_info.strtab))malloc(strtab_shdr->sh_size);
  fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
  ret = fread(ftrace_info.strtab, strtab_shdr->sh_size, 1, fp);
  assert(ret == 1);

  free(shdrs);
  fclose(fp);

  printf("ftrace: loaded %zu symbols from %s\n", ftrace_info.symtab_size, elf_file);
}

const char *ftrace_find_func(uint32_t addr, uint32_t *func_start) {
  if (ftrace_info.symtab == NULL) return NULL;
  for (size_t i = 0; i < ftrace_info.symtab_size; i++) {
    Elf32_Sym *sym = &ftrace_info.symtab[i];
    if (ELF32_ST_TYPE(sym->st_info) == STT_FUNC &&
        sym->st_size > 0 &&
        addr >= sym->st_value &&
        addr <  sym->st_value + sym->st_size) {
      if (func_start) *func_start = sym->st_value;
      return ftrace_info.strtab + sym->st_name;
    }
  }
  return NULL;
}