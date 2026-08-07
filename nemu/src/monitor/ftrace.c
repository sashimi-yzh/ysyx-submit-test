#include <common.h>
#include <debug.h>
#include <ftrace.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <utils.h>
#define MAX_FUNC 4096

static FuncInfo func_table[MAX_FUNC];
static int func_cnt = 0;
void init_ftrace(const char *elf_path) {
  if (!elf_path || !*elf_path)
    return;
  // 打开 ELF 文件
  FILE *fp = fopen(elf_path, "rb");
  assert(fp);

  // 读取 ELF 文件头
  Elf32_Ehdr ehdr;
  assert(fread(&ehdr, sizeof(ehdr), 1, fp));
  assert(*(uint32_t *)ehdr.e_ident == 0x464C457F);

  // 把文件指针跳到 ELF 文件中节头表的起始位置
  fseek(fp, ehdr.e_shoff, SEEK_SET);

  // 读取 ELF 文件中的节头表
  Elf32_Shdr shdrs[ehdr.e_shnum];
  assert(fread(shdrs, sizeof(Elf32_Shdr), ehdr.e_shnum, fp));

  // 查找符号表和字符串表
  Elf32_Shdr *symtab = NULL, *strtab = NULL;
  for (int i = 0; i < ehdr.e_shnum; i++) {
    // 找到符号表
    if (shdrs[i].sh_type == SHT_SYMTAB) {
      symtab = &shdrs[i];
    }
    // 找到字符串表
    else if (shdrs[i].sh_type == SHT_STRTAB && i != ehdr.e_shstrndx) {
      strtab = &shdrs[i];
    }
  }
  assert(symtab && strtab);

  // 计算符号的数量
  int num_syms = symtab->sh_size / symtab->sh_entsize;

  // 为符号表和字符串表分配内存
  Elf32_Sym *syms = malloc(symtab->sh_size);
  char *strs = malloc(strtab->sh_size);
  // 跳转到 ELF 文件中 .symtab 节的起始偏移位置
  fseek(fp, symtab->sh_offset, SEEK_SET);
  assert(fread(syms, symtab->sh_entsize, num_syms, fp));
  // 跳转到 ELF 文件中 .strtab 节的起始偏移位置
  fseek(fp, strtab->sh_offset, SEEK_SET);
  assert(fread(strs, strtab->sh_size, 1, fp));

  // 遍历符号表，查找函数符号并添加到函数表中
  for (int i = 0; i < num_syms; i++) {
    // 如果符号类型为函数且大小大于0
    if (ELF32_ST_TYPE(syms[i].st_info) == STT_FUNC && syms[i].st_size > 0) {
      // 将符号地址和大小添加到函数表中
      func_table[func_cnt].addr = syms[i].st_value;
      func_table[func_cnt].size = syms[i].st_size;
      // 将符号名称复制到函数表中
      strncpy(func_table[func_cnt].name, &strs[syms[i].st_name], 127);
      // 函数表计数器加一
      func_cnt++;
    }
  }
  // 打印日志，输出加载的函数数量
  Log("ftrace loaded %d functions", func_cnt);
  free(syms);
  free(strs);
  fclose(fp);
}

const char *find_func(uint32_t addr) {
  // 遍历函数表
  for (int i = 0; i < func_cnt; i++) {
    // 判断地址是否在函数范围内
    if (addr >= func_table[i].addr && addr < func_table[i].addr + func_table[i].size) {
      // 返回函数名称
      return func_table[i].name;
    }
  }
  // 未找到匹配的函数，返回NULL
  return NULL;
}

/**
 * @brief 打印函数调用信息
 *
 * 该函数用于打印当前调用栈中的函数调用信息，包括调用深度、调用地址和函数名称。
 *
 * @param call_depth 调用深度，表示当前函数在调用栈中的位置
 * @param addr       被调用函数的地址
 * @param pc         当前指令指针的地址
 */
void ftrace_call(int call_depth, uint32_t addr, uint32_t pc) {
  if (!func_cnt)
    return;
  // 查找函数名称
  const char *func = find_func(addr);
  if (func)
    printf(ANSI_FMT(FMT_PADDR ": %*sCall %s @ 0x%08x\n", ANSI_FG_BLUE), pc, call_depth * 2, "", func, addr);
  else
    printf(ANSI_FMT(FMT_PADDR ": %*sCall unknown @ 0x%08x\n", ANSI_FG_BLUE), pc, call_depth * 2, "", addr);
}
/**
 * @brief 记录函数返回时的信息
 *
 * 通过给定的程序计数器（pc）查找对应的函数名，并打印出函数返回的信息。
 *
 * @param call_depth 调用深度
 * @param pc         程序计数器
 */
void ftrace_return(int call_depth, uint32_t pc) {
  if (!func_cnt)
    return;
  // 通过给定的程序计数器（pc）查找对应的函数名
  const char *func = find_func(pc);
  if (func)
    printf(ANSI_FMT(FMT_PADDR ": %*sReturn from %s\n", ANSI_FG_BLUE), pc, call_depth * 2, "", func);
  else
    printf(ANSI_FMT(FMT_PADDR ": %*sReturn from unknown\n", ANSI_FG_BLUE), pc, call_depth * 2, "");
}