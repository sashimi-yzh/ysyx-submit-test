#include <dlfcn.h>
#include <cassert>
#include <common.h>
#include <cpu.h>

#ifdef ITRACE_COND
#include <capstone/capstone.h>
static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code, size_t code_size, uint64_t address, size_t count, cs_insn **insn);
static void (*cs_free_dl)(cs_insn *insn, size_t count);
static csh handle;
#endif

void init_disasm() {
#ifdef ITRACE_COND
  void *dl_handle;
  dl_handle = dlopen("/home/haiji/Learn/ysyx-workbench/nemu/tools/capstone/repo/libcapstone.so.5", RTLD_LAZY);
  assert(dl_handle);

  cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
  cs_open_dl = reinterpret_cast<cs_err (*)(cs_arch, cs_mode, csh*)>(dlsym(dl_handle, "cs_open"));
  assert(cs_open_dl);

  cs_disasm_dl = reinterpret_cast<size_t (*)(csh, const uint8_t*, size_t, uint64_t, size_t, cs_insn**)>(dlsym(dl_handle, "cs_disasm"));
  assert(cs_disasm_dl);

  cs_free_dl = reinterpret_cast<void (*)(cs_insn*, size_t)>(dlsym(dl_handle, "cs_free"));
  assert(cs_free_dl);

  cs_arch arch = CS_ARCH_RISCV;
  cs_mode mode = static_cast<cs_mode>(CS_MODE_RISCV32 | CS_MODE_RISCVC);
	int ret = cs_open_dl(arch, mode, &handle);
  assert(ret == CS_ERR_OK);
#endif
}

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte) {
#ifdef ITRACE_COND
	cs_insn *insn;
	size_t count = cs_disasm_dl(handle, code, nbyte, pc, 0, &insn);
  if(count != 1) {
    invalid_inst = 1;
    return ;
  }
  assert(count == 1);
  int ret = snprintf(str, size, "%s", insn->mnemonic);
  if (insn->op_str[0] != '\0') {
    snprintf(str + ret, size - ret, "\t%s", insn->op_str);
  }
  cs_free_dl(insn, count);
#endif
}

void inst_display(word_t pc, word_t inst) {
#ifdef ITRACE_COND
  char log[ITRACE_LOG_LEN];
  char *p = log;
  p += snprintf(p, ITRACE_LOG_LEN, FMT_WORD ":", pc);
  uint8_t* inst_bytes = (uint8_t *)&inst;
  int i;
  for(i = 3;i >= 0;i --){
    p += snprintf(p, 4, " %02x", inst_bytes[i]);
  }
  *p++ = ' ';
  disassemble(p, log + ITRACE_LOG_LEN - p, (uint64_t)pc, (uint8_t *)&inst, 4);
  if(invalid_inst) return ;
  printf("%s\n", log);
#endif
}
  