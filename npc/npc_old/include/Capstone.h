#pragma once
#include <capstone/capstone.h>
#include <dlfcn.h>
#include <string>

class Capstone {
public:
  std::string disassemble(uint64_t pc, uint8_t *code, int nbyte,
                          bool display = true);
  bool load_libcapstone();
  Capstone() = default;
  Capstone(const Capstone &) = delete;
  Capstone(Capstone &&) noexcept = delete;
  ~Capstone();

  static Capstone capstone;

private:
  using disasm_fn_type = size_t (*)(csh handle, const uint8_t *code,
                                    size_t code_size, uint64_t address,
                                    size_t count, cs_insn **insn);
  using csfree_fn_type = void (*)(cs_insn *insn, size_t count);
  using cserr_fn_type = cs_err (*)(cs_arch arch, cs_mode mode, csh *handle);
  using csclose_fn_type = cs_err (*)(csh *);
  void *loaded_lib;
  disasm_fn_type cs_disasm_dl;
  csfree_fn_type cs_free_dl;
  csclose_fn_type cs_close_dl;
  csh handle;
};