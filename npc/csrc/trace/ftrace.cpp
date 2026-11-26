#include "ftrace.h"
#include "../utils/log.h"
#include "../core/npc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <deque>
#include <vector>
#include <string>

// 符号表相关数据结构
static Elf32_Sym *symtab = NULL;
static char *strtab = NULL;
static int symtab_nr = 0;  // 符号表项数量
static int func_depth = 0;  // 函数调用深度
static bool trace_enabled = true;

// ftrace缓冲区（用于延迟输出）和最近记录
static std::vector<std::string> ftrace_buffer;
static std::deque<std::string> ftrace_recent;
static const size_t RECENT_MAX = 32;

void set_ftrace_enabled(bool enable) {
  trace_enabled = enable;
}

bool ftrace_enabled() {
  return trace_enabled;
}

// 根据地址查找函数名
static const char* find_func_name(uint32_t addr) {
  if (symtab == NULL || strtab == NULL) {
    return "???";
  }
  
  for (int i = 0; i < symtab_nr; i++) {
    // 只关心函数符号
    if (ELF32_ST_TYPE(symtab[i].st_info) != STT_FUNC) {
      continue;
    }
    
    // 检查地址是否在函数范围内
    uint32_t func_start = symtab[i].st_value;
    uint32_t func_end = func_start + symtab[i].st_size;
    
    if (addr >= func_start && addr < func_end) {
      return strtab + symtab[i].st_name;
    }
  }
  
  return "???";  // 未找到
}

// 初始化ftrace
void init_ftrace(const char *elf_file) {
  trace_enabled = true;
  if (elf_file == NULL) {
    Log("No ELF file for ftrace");
    return;
  }
  
  FILE *fp = fopen(elf_file, "rb");
  if (fp == NULL) {
    Log("Warning: Cannot open ELF file '%s' for ftrace", elf_file);
    return;
  }
  
  // 1. 读取 ELF Header
  Elf32_Ehdr ehdr;
  int ret = fread(&ehdr, sizeof(ehdr), 1, fp);
  if (ret != 1) {
    Log("Warning: Failed to read ELF header");
    fclose(fp);
    return;
  }
  
  // 验证 ELF 魔数
  if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
    Log("Warning: Not an ELF file");
    fclose(fp);
    return;
  }
  
  // 2. 读取 Section Header Table
  Elf32_Shdr *shdr = (Elf32_Shdr*)malloc(sizeof(Elf32_Shdr) * ehdr.e_shnum);
  if (shdr == NULL) {
    Log("Warning: Failed to allocate memory for section headers");
    fclose(fp);
    return;
  }
  
  fseek(fp, ehdr.e_shoff, SEEK_SET);
  ret = fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
  if (ret != ehdr.e_shnum) {
    Log("Warning: Failed to read section headers");
    free(shdr);
    fclose(fp);
    return;
  }
  
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
    Log("Warning: No symbol table found in ELF file");
    free(shdr);
    fclose(fp);
    return;
  }
  
  // 4. 读取符号表
  symtab_nr = symtab_shdr->sh_size / sizeof(Elf32_Sym);
  symtab = (Elf32_Sym*)malloc(symtab_shdr->sh_size);
  if (symtab == NULL) {
    Log("Warning: Failed to allocate memory for symbol table");
    free(shdr);
    fclose(fp);
    return;
  }
  
  fseek(fp, symtab_shdr->sh_offset, SEEK_SET);
  ret = fread(symtab, symtab_shdr->sh_size, 1, fp);
  if (ret != 1) {
    Log("Warning: Failed to read symbol table");
    free(symtab);
    symtab = NULL;
    free(shdr);
    fclose(fp);
    return;
  }
  
  // 5. 读取字符串表
  strtab = (char*)malloc(strtab_shdr->sh_size);
  if (strtab == NULL) {
    Log("Warning: Failed to allocate memory for string table");
    free(symtab);
    symtab = NULL;
    free(shdr);
    fclose(fp);
    return;
  }
  
  fseek(fp, strtab_shdr->sh_offset, SEEK_SET);
  ret = fread(strtab, strtab_shdr->sh_size, 1, fp);
  if (ret != 1) {
    Log("Warning: Failed to read string table");
    free(strtab);
    strtab = NULL;
    free(symtab);
    symtab = NULL;
    free(shdr);
    fclose(fp);
    return;
  }
  
  free(shdr);
  fclose(fp);
  
  Log("ftrace initialized with %d symbols from '%s'", symtab_nr, elf_file);
}

// 记录函数调用（延迟输出）
static void ftrace_add(const char *line) {
  ftrace_buffer.push_back(std::string(line));
  ftrace_recent.push_back(std::string(line));
  if (ftrace_recent.size() > RECENT_MAX) {
    ftrace_recent.pop_front();
  }
}

void ftrace_call(uint32_t pc, uint32_t target) {
#ifndef ENABLE_TRACE
  return;  // TRACE 未开启时直接返回，避免 ftrace_buffer 无限增长
#endif
  if (!trace_enabled) return;

  const char *func_name = find_func_name(target);
  // 用固定宽度缩进，避免 %*s 在 depth 很大时撑爆 buffer
  int indent = func_depth * 2;
  if (indent > 40) indent = 40;  // 最多 20 层缩进
  char prefix[160];
  log_trace_prefix_at(prefix, sizeof(prefix), "FTRACE", pc,
                      npc_get_cycle(), npc_get_commit_count(), npc_get_time());
  char logbuf[512];
  snprintf(logbuf, sizeof(logbuf), "%s%*scall [%s@0x%08x]",
           prefix, indent, "", func_name, target);

  func_depth++;
  ftrace_add(logbuf);
}

// 记录函数返回（延迟输出）
// pc: jalr 指令地址（用于显示位置）
// target: 返回目标地址，即 ra 寄存器的值（用于查函数名）
void ftrace_ret(uint32_t pc, uint32_t target) {
#ifndef ENABLE_TRACE
  return;  // TRACE 未开启时直接返回，避免 ftrace_buffer 无限增长
#endif
  if (!trace_enabled) return;

  func_depth--;
  if (func_depth < 0) func_depth = 0;

  const char *func_name = find_func_name(target);
  int indent = func_depth * 2;
  if (indent > 40) indent = 40;
  char prefix[160];
  log_trace_prefix_at(prefix, sizeof(prefix), "FTRACE", pc,
                      npc_get_cycle(), npc_get_commit_count(), npc_get_time());
  char logbuf[512];
  snprintf(logbuf, sizeof(logbuf), "%s%*sret  [%s@0x%08x]",
           prefix, indent, "", func_name, target);

  ftrace_add(logbuf);
}

// 刷新ftrace缓冲区
void ftrace_flush(bool print_to_console) {
  if (ftrace_buffer.empty()) return;
  
  // 先收集所有输出到一个字符串，确保原子性
  std::string output;
  for (const auto& line : ftrace_buffer) {
    output += line + "\n";
  }
  
  // 一次性输出到日志文件
  log_write("%s", output.c_str());
  
  // 一次性输出到控制台
  if (print_to_console) {
    printf("%s", output.c_str());
    fflush(stdout);  // 立即刷新，避免缓冲
  }
  
  ftrace_buffer.clear();
}

void ftrace_dump_recent() {
  const char *header = "Recent function calls (ftrace):";
  printf("\n%s\n", header);
  log_write("\n%s\n", header);

  if (ftrace_recent.empty()) {
    printf("  (empty)\n");
    log_write("  (empty)\n");
    return;
  }
  for (const auto &line : ftrace_recent) {
    printf("  %s\n", line.c_str());
    log_write("  %s\n", line.c_str());
  }
  printf("\n");
  log_write("\n");
}
