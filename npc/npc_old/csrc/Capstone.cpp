#include "capstone/capstone.h"
#include <Capstone.h>
#include <cstddef>
#include <cstdint>
#include <dlfcn.h>
#include <fmt/format.h>
#include <my_utils.h>
#include <fmt/format.h>
#include <spdlog/spdlog.h>
#include <stdexcept>

Capstone Capstone::capstone{};

bool Capstone::load_libcapstone() {
  if (loaded_lib != nullptr) {
    spdlog::info("Already loaded from {}", STR(SO_PATH_CAPSTONE));
    return true;
  }
  loaded_lib = dlopen(STR(SO_PATH_CAPSTONE), RTLD_LAZY);
  if (loaded_lib == nullptr) {
    log_and_throw<std::runtime_error>("Failed to load library from {}",
                                      STR(SO_PATH_CAPSTONE));
    return false;
  }
  cserr_fn_type cs_open_dl = NULL;
  cs_open_dl = (cserr_fn_type)dlsym(loaded_lib, "cs_open");
  if (cs_open_dl == nullptr) {
    log_and_throw<std::runtime_error>("Failed to load symbol cs_open from {}",
                                      STR(SO_PATH_CAPSTONE));
    dlclose(loaded_lib);
    loaded_lib = nullptr;
    return false;
  }

  cs_disasm_dl = (disasm_fn_type)dlsym(loaded_lib, "cs_disasm");
  if (cs_disasm_dl == nullptr) {
    log_and_throw<std::runtime_error>("Failed to load symbol cs_disasm from {}",
                                      STR(SO_PATH_CAPSTONE));
    dlclose(loaded_lib);
    cs_open_dl = nullptr;
    loaded_lib = nullptr;
    return false;
  }
  cs_close_dl = (csclose_fn_type)dlsym(loaded_lib, "cs_close");
  if (cs_close_dl == nullptr) {
    log_and_throw<std::runtime_error>("Failed to load symbol cs_disasm from {}",
                                      STR(SO_PATH_CAPSTONE));
    dlclose(loaded_lib);
    cs_open_dl = nullptr;
    loaded_lib = nullptr;
    cs_disasm_dl = nullptr;
    return false;
  }
  cs_free_dl = (csfree_fn_type)dlsym(loaded_lib, "cs_free");
  if (cs_free_dl == nullptr) {
    log_and_throw<std::runtime_error>("Failed to load symbol cs_free from {}",
                                      STR(SO_PATH_CAPSTONE));
    dlclose(loaded_lib);
    cs_open_dl = nullptr;
    loaded_lib = nullptr;
    cs_disasm_dl = nullptr;
    return false;
  }

  int ret = cs_open_dl(CS_ARCH_RISCV, CS_MODE_RISCV32, &handle);
  if (ret != 0) {
    dlclose(loaded_lib);
    loaded_lib = nullptr;
    cs_open_dl = nullptr;
    cs_disasm_dl = nullptr;
    return false;
  }
  return true;
}

std::string Capstone::disassemble(uint64_t pc, uint8_t *code, int nbyte,
                                  bool display) {
  if (cs_disasm_dl == nullptr)
    log_and_throw<std::logic_error>(
        "Did not load libcapstone before disassembling instruction");
  cs_insn *insn;

  size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);

  // if (count != 1)
  //   log_and_throw<std::logic_error>(
  //       "Capstone encountered an invalid instruction@{:#010x}", pc);

  std::string str;
  if (count != 1)
    str = fmt::format("{:#010x}\t{:08x}\tinvalid", pc,
                      *reinterpret_cast<uint32_t *>(code));
  else
    str = fmt::format("{:#010x}\t{:08x}\t{}\t{}", pc,
                      *reinterpret_cast<uint32_t *>(code), insn->mnemonic,
                      insn->op_str);
  if (display)
    fmt::println("{}", str);
  cs_free_dl(insn, count);
  return str;
}

Capstone::~Capstone() {
  if (handle)
    cs_close_dl(&handle);
  if (loaded_lib)
    dlclose(loaded_lib);
}