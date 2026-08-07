#pragma once
#include <bits/stdc++.h>
#include <elf.h>
#include <format.hpp>
#include <pattern.hpp>
struct FuncInfo {
  std::string name;
  uint32_t start_addr;
  uint32_t end_addr;
};

class Ftrace {
  std::vector<FuncInfo> funcs;
  std::map<std::string, uint32_t> symbols;

  // 按名字查找 section header
  static Elf32_Shdr *findSection(std::vector<uint8_t> &elf_data,
                                 const Elf32_Ehdr *ehdr, const char *name) {
    auto *shdr =
        reinterpret_cast<Elf32_Shdr *>(elf_data.data() + ehdr->e_shoff);
    auto *shstrtab_hdr = &shdr[ehdr->e_shstrndx];
    const char *shstrtab = reinterpret_cast<const char *>(
        elf_data.data() + shstrtab_hdr->sh_offset);
    for (int i = 0; i < ehdr->e_shnum; i++) {
      if (strcmp(shstrtab + shdr[i].sh_name, name) == 0) {
        return &shdr[i];
      }
    }
    return nullptr;
  }
  Ftrace() {}

public:
  struct ProcedureInfo {
  public:
#define PROCEDURE_TYPES                                                        \
  X(nothing)                                                                   \
  X(call)                                                                      \
  X(ret)                                                                       \
  X(tailcall)
    enum class Type : uint8_t {
#define X(name) name,
      PROCEDURE_TYPES
#undef X
    };
  private:
    static std::string typeName(Type t) {
      static const std::map<Type, std::string> names = {
#define X(name) {Type::name, #name},
          PROCEDURE_TYPES
#undef X
      };
      auto it = names.find(t);
      return it != names.end() ? it->second : "unknown";
    }
    Type type;

  public:
    ProcedureInfo(Type type) : type(type) {}
    Type getType() const { return type; }
    std::string typeStr() const { return typeName(type); }
    explicit operator bool() const { return type != Type::nothing; }
#undef PROCEDURE_TYPES
  };
  static Ftrace &getInstance() {
    static Ftrace ftrace;
    return ftrace;
  }
  const std::map<std::string, uint32_t> &getSymbols() const { return symbols; }
  void loadELF(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    assert(file.is_open() && "Failed to open ELF file");

    std::vector<uint8_t> elf_data((std::istreambuf_iterator<char>(file)),
                                  std::istreambuf_iterator<char>());
    file.close();

    // 解析 ELF header
    auto *ehdr = reinterpret_cast<Elf32_Ehdr *>(elf_data.data());
    assert(memcmp(ehdr->e_ident, ELFMAG, SELFMAG) == 0 &&
           "Not a valid ELF file");

    // 查找 .symtab 和 .strtab
    auto *symtab_hdr = findSection(elf_data, ehdr, ".symtab");
    auto *strtab_hdr = findSection(elf_data, ehdr, ".strtab");
    assert(symtab_hdr && "No .symtab section found");
    assert(strtab_hdr && "No .strtab section found");

    const char *strtab =
        reinterpret_cast<const char *>(elf_data.data() + strtab_hdr->sh_offset);

    // 遍历符号表，提取函数符号
    auto *syms =
        reinterpret_cast<Elf32_Sym *>(elf_data.data() + symtab_hdr->sh_offset);
    int num_syms = symtab_hdr->sh_size / sizeof(Elf32_Sym);

    funcs.clear();
    symbols.clear();
    for (int i = 0; i < num_syms; i++) {
      auto type = ELF32_ST_TYPE(syms[i].st_info);
      const char *name = strtab + syms[i].st_name;
      if (*name && type != STT_SECTION && type != STT_FILE)
        symbols[name] = syms[i].st_value;
      if (type != STT_SECTION && type != STT_FILE && syms[i].st_size > 0) {
        funcs.push_back({
            .name = std::string(name),
            .start_addr = syms[i].st_value,
            .end_addr = syms[i].st_value + syms[i].st_size,
        });
      }
    }

    std::sort(funcs.begin(), funcs.end(),
              [](const FuncInfo &a, const FuncInfo &b) {
                return a.start_addr < b.start_addr;
              });
  }

  void display() {
    for (const auto &f : funcs) {
      std::cout << std::left << std::setw(40) << f.name << "  " << std::hex
                << "0x" << f.start_addr << " - 0x" << f.end_addr << std::dec
                << std::endl;
    }
  }
  FuncInfo *hit(uint32_t address) {
    int l = 0, r = funcs.size() - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (funcs[mid].start_addr <= address) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    if (!funcs.empty() && funcs[l].start_addr <= address &&
        address < funcs[l].end_addr) {
      return &funcs[l];
    }
    return NULL;
  }
  ProcedureInfo judge(uint32_t instruction) {
    bool isJal = (instruction & pattern::jalMask) == pattern::jalPattern;
    bool isJalr = (instruction & pattern::jalrMask) == pattern::jalrPattern;
    if (!isJal && !isJalr)
      return ProcedureInfo(ProcedureInfo::Type::nothing);
    uint8_t rs1 = instruction >> 15 & 0x1f;
    uint8_t rd = instruction >> 7 & 0x1f;
    auto isHit1or5 = [](auto &x) -> bool { return x == 1 || x == 5; };
    bool call = isHit1or5(rd) && !isHit1or5(rs1) ||
                isHit1or5(rd) && isHit1or5(rs1) && rd == rs1;
    bool ret = isHit1or5(rs1);
    bool tailcall = isHit1or5(rd) && isHit1or5(rs1) && rd != rs1;
    return ProcedureInfo(call       ? ProcedureInfo::Type::call
                         : ret      ? ProcedureInfo::Type::ret
                         : tailcall ? ProcedureInfo::Type::tailcall
                                    : ProcedureInfo::Type::nothing);
  }
};
