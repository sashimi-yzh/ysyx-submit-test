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

#include <common.h>
#include <elf.h>

#ifdef CONFIG_FTRACE

// 符号表相关数据结构
static Elf32_Sym *symtab = NULL;
static char *strtab = NULL;
static int symtab_nr = 0;  // 符号表项数量
static int func_depth = 0;  // 函数调用深度

// 初始化 ftrace
void init_ftrace(const char *elf_file) {
  if (elf_file == NULL) {
    Log("No ELF file for ftrace");
    return;
  }
  
  FILE *fp = fopen(elf_file, "rb");
  Assert(fp, "Can not open '%s'", elf_file);
  
  // 1. 读取 ELF Header
  Elf32_Ehdr ehdr;
  int ret = fread(&ehdr, sizeof(ehdr), 1, fp);
  Assert(ret == 1, "Failed to read ELF header");
  
  // 验证 ELF 魔数
  Assert(memcmp(ehdr.e_ident, ELFMAG, SELFMAG) == 0, "Not an ELF file");
  
  // 2. 读取 Section Header Table
  Elf32_Shdr *shdr = malloc(sizeof(Elf32_Shdr) * ehdr.e_shnum);
  Assert(shdr, "Failed to allocate memory for section headers");
  
  fseek(fp, ehdr.e_shoff, SEEK_SET);
  ret = fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
  Assert(ret == ehdr.e_shnum, "Failed to read section headers");
  
  // 3. 找到 .symtab 和 .strtab
  Elf32_Shdr *symtab_shdr = NULL;
  Elf32_Shdr *strtab_shdr = NULL;
  
  for (int i = 0; i < ehdr.e_shnum; i++) {
    if (shdr[i].sh_type == SHT_SYMTAB) {
      symtab_shdr = &shdr[i];
      strtab_shdr = &shdr[shdr[i].sh_link];  // 字符串表索引
      break;
    }
  }
  
  if (symtab_shdr == NULL) {
    Log("No symbol table found in ELF file");
    free(shdr);
    fclose(fp);
    return;
  }
  
  // 4. 读取符号表
  symtab_nr = symtab_shdr->sh_size / sizeof(Elf32_Sym);
  symtab = malloc(symtab_shdr->sh_size);
  Assert(symtab, "Failed to allocate memory for symbol table");
  
  fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
  ret = fread(symtab, symtab_shdr->sh_size, 1, fp);
  Assert(ret == 1, "Failed to read symbol table");
  
  // 5. 读取字符串表
  strtab = malloc(strtab_shdr->sh_size);
  Assert(strtab, "Failed to allocate memory for string table");
  
  fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
  ret = fread(strtab, strtab_shdr->sh_size, 1, fp);
  Assert(ret == 1, "Failed to read string table");
  
  free(shdr);
  fclose(fp);
  
  Log("ftrace initialized with %d symbols from '%s'", symtab_nr, elf_file);
}

// 根据地址查找函数名
static const char* find_func_name(vaddr_t addr) {
  if (symtab == NULL || strtab == NULL) {
    return "???";
  }
  
  for (int i = 0; i < symtab_nr; i++) {
    // 只关心函数符号
    if (ELF32_ST_TYPE(symtab[i].st_info) != STT_FUNC) {
      continue;
    }
    
    // 检查地址是否在函数范围内
    vaddr_t func_start = symtab[i].st_value;
    vaddr_t func_end = func_start + symtab[i].st_size;
    
    if (addr >= func_start && addr < func_end) {
      return strtab + symtab[i].st_name;
    }
  }
  
  return "???";  // 未找到
}

// 函数调用
void ftrace_call(vaddr_t pc, vaddr_t target) {
  const char *func_name = find_func_name(target);
  log_write(FMT_WORD ": %*scall [%s@" FMT_WORD "]\n", 
            pc, func_depth * 2, "", func_name, target);
  func_depth++;
}

// 函数返回
void ftrace_ret(vaddr_t pc) {
  func_depth--;
  if (func_depth < 0) func_depth = 0;  // 防止深度为负
  
  const char *func_name = find_func_name(pc);
  log_write(FMT_WORD ": %*sret  [%s]\n", 
            pc, func_depth * 2, "", func_name);
}

#endif // CONFIG_FTRACE
