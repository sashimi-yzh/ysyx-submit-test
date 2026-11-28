#include <dlfcn.h>
#include <stdio.h>
#include <assert.h>
#include <capstone/capstone.h>
#include "disasm.h"

static bool disasm_inited = false;
static void *cs_handle = NULL;
static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code,
    size_t code_size, uint64_t address, size_t count, cs_insn **insn) = NULL;
static void (*cs_free_dl)(cs_insn *insn, size_t count) = NULL;
static csh cs_h;
static bool disasm_ok = false;

void init_disasm(void) {
  if (disasm_inited) return;
  disasm_inited = true;

  const char *cs_lib = "tools/capstone/repo/libcapstone.so.5";

  cs_handle = dlopen(cs_lib, RTLD_LAZY);
  if (!cs_handle) {
    printf("Disasm: Cannot open '%s'. Disassembly disabled.\n", cs_lib);
    return;
  }

  cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle);
  cs_open_dl = (cs_err (*)(cs_arch, cs_mode, csh *))dlsym(cs_handle, "cs_open");
  assert(cs_open_dl);

  cs_disasm_dl = (size_t (*)(csh, const uint8_t *, size_t, uint64_t, size_t, cs_insn **))
                 dlsym(cs_handle, "cs_disasm");
  assert(cs_disasm_dl);

  cs_free_dl = (void (*)(cs_insn *, size_t))dlsym(cs_handle, "cs_free");
  assert(cs_free_dl);

  int ret = cs_open_dl(CS_ARCH_RISCV, CS_MODE_RISCV32, &cs_h);
  assert(ret == CS_ERR_OK);
  disasm_ok = true;
}

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
  if (!disasm_ok) {
    snprintf(str, size, "0x%08x", *(uint32_t *)code);
    return;
  }
  cs_insn *insn;
  size_t count = cs_disasm_dl(cs_h, code, nbyte, pc, 0, &insn);
  if (count == 0) {
    snprintf(str, size, "0x%08x", *(uint32_t *)code);
    return;
  }
  int ret = snprintf(str, size, "%s", insn->mnemonic);
  if (insn->op_str[0] != '\0') {
    snprintf(str + ret, size - ret, "\t%s", insn->op_str);
  }
  cs_free_dl(insn, count);
}
