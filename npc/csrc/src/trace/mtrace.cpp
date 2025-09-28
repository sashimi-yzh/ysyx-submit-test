#include "trace.h"

static void locate_object_sym(addr_t addr) {
  extern ElfSymbol elf_symbol_list[];
  extern word_t elf_symbol_list_size;
  for (word_t i = 0; i < elf_symbol_list_size; ++i) {
    if (elf_symbol_list[i].type == ELF_SYM_OBJECT &&
        elf_symbol_list[i].addr <= addr &&
        addr < elf_symbol_list[i].addr + elf_symbol_list[i].size) {
      log_write("(%s + %u)", elf_symbol_list[i].name, (uint32_t)(addr - elf_symbol_list[i].addr));
      return;
    }
  }
}

void mtrace_read(addr_t addr, int size, word_t data) {
  log_write(ANSI_FG_CYAN "[MTRACE] Read %d bytes at " FMT_ADDR, size, addr);
  locate_object_sym(addr);
  log_write(": " FMT_WORD ANSI_NONE "\n", data);
  // printf(ANSI_FG_CYAN "[MTRACE] Read %d bytes at " FMT_ADDR ": " FMT_WORD ANSI_NONE "\n", size, addr, data);
}

void mtrace_write(addr_t addr, int size, word_t data) {
  log_write(ANSI_FG_YELLOW "[MTRACE] Write %d bytes at " FMT_ADDR , size, addr);
  locate_object_sym(addr);
  log_write(": " FMT_WORD ANSI_NONE "\n", data);
  // printf(ANSI_FG_YELLOW "[MTRACE] Write %d bytes at " FMT_ADDR ": " FMT_WORD ANSI_NONE "\n", size, addr, data);
}
