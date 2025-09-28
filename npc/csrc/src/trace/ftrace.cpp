#include "common.h"
#include "trace.h"
#include <cstring>

extern ElfSymbol elf_symbol_list[];
extern int elf_symbol_list_size;

static int get_func_sym_ndx(addr_t p) {
  for (int i = 0; i < elf_symbol_list_size; ++i) {
    if (elf_symbol_list[i].type == ELF_SYM_FUNC && elf_symbol_list[i].addr <= p) {
      if (p < elf_symbol_list[i].addr + elf_symbol_list[i].size) return i;
    }
  }
  // Log(ANSI_FMT("[FTRACE] Warning: PC outside any FUNC symbol area: " FMT_ADDR, ANSI_FG_YELLOW), p);
  return -1;
}

void ftrace(addr_t pc, addr_t next_pc) {
  static addr_t ret_st[128];
  static int ftrace_dep = 0;
  static int lock_dep = 0;

  if (next_pc == pc + 4 || elf_symbol_list_size == 0) return;
  int from = get_func_sym_ndx(pc), to = get_func_sym_ndx(next_pc);
  if (from == to || from == -1 || to == -1) return;

  if (elf_symbol_list[to].addr == next_pc) { // call, jump to the begging of a func
    if (!lock_dep) {
      log_write("[FTRACE] " FMT_ADDR ": ", pc);
      for (int i = 0; i < ftrace_dep; ++i) log_write(" ");
      log_write("call [%s@" FMT_ADDR "] -> [%s@" FMT_ADDR "]\n",
                elf_symbol_list[from].name,
                elf_symbol_list[from].addr,
                elf_symbol_list[to].name,
                elf_symbol_list[to].addr);
      if (strstr(elf_symbol_list[to].name, "printf")) {
        lock_dep = ftrace_dep;
      }
    }
    ret_st[ftrace_dep++] = pc + 4;
  } else { // ret, return to calling position
    Assert(ftrace_dep, "Error occured in FTRACE: negative deepth");
    while (ret_st[--ftrace_dep] != next_pc);
    if (!lock_dep || ftrace_dep <= lock_dep) {
      lock_dep = 0;
      log_write("[FTRACE] " FMT_ADDR ": ", pc);
      for (int i = 0; i < ftrace_dep; ++i) log_write(" ");
      log_write("ret [%s@" FMT_ADDR "] -> [%s@" FMT_ADDR "]:" FMT_ADDR "\n",
                elf_symbol_list[from].name,
                elf_symbol_list[from].addr,
                elf_symbol_list[to].name,
                elf_symbol_list[to].addr,
                next_pc);
    }
  }
}
