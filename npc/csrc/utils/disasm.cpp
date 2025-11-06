#ifdef CONFIG_ITRACE
#include <dlfcn.h>
#include <capstone/capstone.h>
#include <common.h>

static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code,
    size_t code_size, uint64_t address, size_t count, cs_insn **insn);
static void (*cs_free_dl)(cs_insn *insn, size_t count);

static csh handle;

extern "C" void init_disasm() {
  void *dl_handle;
  dl_handle = dlopen("tools/capstone/repo/libcapstone.so.5", RTLD_LAZY);
  assert(dl_handle);

  // 通过显式转换解决错误
  cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
  cs_open_dl = (cs_err (*)(cs_arch, cs_mode, csh*)) dlsym(dl_handle, "cs_open");
  assert(cs_open_dl);

  cs_disasm_dl = (size_t (*)(csh, const uint8_t*, size_t, uint64_t, size_t, cs_insn**))
                  dlsym(dl_handle, "cs_disasm");
  assert(cs_disasm_dl);

  cs_free_dl = (void (*)(cs_insn*, size_t)) dlsym(dl_handle, "cs_free");
  assert(cs_free_dl);

  cs_arch arch = CS_ARCH_RISCV;
  cs_mode mode = CS_MODE_RISCV32;
  int ret = cs_open_dl(arch, mode, &handle);
  assert(ret == CS_ERR_OK);
}

extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
    cs_insn *insn;
    size_t count = cs_disasm_dl(handle, code, nbyte, pc, 1, &insn);
    if (count != 1) {
        fprintf(stderr, "nbyte is %d,  Disasm error: pc=0x%lx code=%02x%02x%02x%02x\n",
                nbyte, pc, code[0], code[1], code[2], code[3]);
    }
    assert(count == 1);
    // TAG:调试使用
    // printf("count is %ld,pc is %lx\n",count,pc);
    int ret = snprintf(str, size, "%s", insn->mnemonic);
    if (insn->op_str[0] != '\0') {
      snprintf(str + ret, size - ret, "\t%s", insn->op_str);
    }
    cs_free_dl(insn, count);
}
#endif