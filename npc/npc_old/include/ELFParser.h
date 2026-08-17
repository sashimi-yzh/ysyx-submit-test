#pragma once
#include <ELFParser.h>
#include <algorithm>
#include <cstdint>
#include <elfio/elfio.hpp>
#include <fmt/format.h>
#include <memory>
#include <my_utils.h>
#include <spdlog/spdlog.h>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

class ProgSymTab {
public:
  typedef struct {
    std::string name;
    uint32_t start;
  } SymbolItem;
  struct SymbolsTable {
    int symbol_count;
    std::vector<SymbolItem> symbol_items;
    std::vector<int> symbol_map;
  };
  typedef struct {
    int symbol;
    uint32_t pc;
  } Call;

  ProgSymTab(std::string_view elf_path) { init_and_parse(elf_path); }

  void init_and_parse(std::string_view elf_path);

  void push_call_stack(int symbol, uint32_t pc);
  Call pop_call_stack();
  int stack_cnt() { return call_stack.size(); }
  const std::string &find_symbol_name(int idx);
  int find_symbol_by_addr(uint32_t addr);

private:
  SymbolsTable table;
  std::vector<Call> call_stack;
  uint32_t pc_offset;
};

inline void ProgSymTab::init_and_parse(std::string_view elf_path) {
  using namespace ELFIO;
  table.symbol_items.clear();
  call_stack.clear();
  call_stack.shrink_to_fit();
  pc_offset = 0xFFFFFFFF;
  spdlog::info("Loading symbols from {}", elf_path);
  elfio reader;
  if (!reader.load(std::string(elf_path))) {
    log_and_throw<std::runtime_error>("Can't find or process ELF file : {}",
                                      elf_path);
  }
  if (reader.get_class() != ELFCLASS32) {
    log_and_throw<std::logic_error>("Class of ELF file is not ELF32 : {}",
                                    elf_path);
  }
  Elf_Half sec_num = reader.sections.size();

  for (int i = 0; i < sec_num; ++i) {
    section *psec = reader.sections[i];
    if (psec->get_type() == SHT_SYMTAB) {
      uint32_t max_addr = 0;
      const symbol_section_accessor symbols(reader, psec);

      std::string name;
      Elf64_Addr value;
      Elf_Xword size;
      unsigned char bind;
      unsigned char type;
      Elf_Half section_index;
      unsigned char other;
      for (unsigned int j = 0; j < symbols.get_symbols_num(); ++j) {
        symbols.get_symbol(j, name, value, size, bind, type, section_index,
                           other);
        if (type == STT_FUNC) {
          pc_offset = std::min(pc_offset, static_cast<uint32_t>(value));
          max_addr = std::max(max_addr, static_cast<uint32_t>(value + size));
        }
      }
      table.symbol_map.resize(max_addr - pc_offset);
      std::fill(table.symbol_map.begin(), table.symbol_map.end(), -1);

      for (unsigned int j = 0; j < symbols.get_symbols_num(); ++j) {
        symbols.get_symbol(j, name, value, size, bind, type, section_index,
                           other);
        if (type == STT_FUNC) {
          for (uint32_t addr = value; addr < value + size; addr++) {
            table.symbol_map[addr - pc_offset] = table.symbol_items.size();
          }
          spdlog::info("Found symbol {}@{:#08x}, size = {:#x}", name, value,
                       size);
          table.symbol_items.push_back({std::move(name), (uint32_t)value});
        }
      }
    }
  }
}
inline void ProgSymTab::push_call_stack(int symbol, uint32_t pc) {
  call_stack.push_back({symbol, pc});
}

inline ProgSymTab::Call ProgSymTab::pop_call_stack() {
  if (call_stack.empty())
    log_and_throw<std::logic_error>("Can't pop an empty call stack");
  Call ret = call_stack.back();
  call_stack.pop_back();
  return ret;
}

inline const std::string &ProgSymTab::find_symbol_name(int idx) {
  if (idx < 0 || idx >= table.symbol_items.size()) {
    log_and_throw<std::logic_error>(
        "Index {} of symbol_table is out of range [0, {})", idx,
        table.symbol_items.size());
  }
  return table.symbol_items[idx].name;
}
inline int ProgSymTab::find_symbol_by_addr(uint32_t addr) {
  if (addr < pc_offset || addr >= pc_offset + table.symbol_map.size()) {
    log_and_throw<std::logic_error>("Addr {} is out of range [{}, {})", addr,
                                    pc_offset,
                                    pc_offset + table.symbol_map.size());
  }
  return table.symbol_map[addr - pc_offset];
}

inline std::unique_ptr<ProgSymTab> sym_table;

inline void init_sym_table(std::string_view elf_path) {
  sym_table = std::make_unique<ProgSymTab>(elf_path);
  spdlog::info("ELF loading finished");
}
