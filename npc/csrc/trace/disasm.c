#include <dlfcn.h>
#include <capstone/capstone.h>
#include <npc/diagnostics.h>

#if defined(__APPLE__)
#define CS_LIB_SUFFIX "5.dylib"
#elif defined(__linux__)
#define CS_LIB_SUFFIX "so.5"
#else
#error "Unsupported platform"
#endif

static size_t (*decode_fn)(csh handle, const uint8_t *code,
    size_t code_size, uint64_t address, size_t count, cs_insn **insn);
static void (*release_fn)(cs_insn *insn, size_t count);

static csh capstone_handle;

void init_disasm(void) {
  void *module = dlopen("tools/capstone/repo/libcapstone." CS_LIB_SUFFIX, RTLD_LAZY);
  Assert(module != NULL, "cannot load Capstone: %s", dlerror());

  cs_err (*open_fn)(cs_arch, cs_mode, csh *) = dlsym(module, "cs_open");
  decode_fn = dlsym(module, "cs_disasm");
  release_fn = dlsym(module, "cs_free");
  Assert(open_fn != NULL && decode_fn != NULL && release_fn != NULL,"Capstone library is missing a required entry point");

  cs_mode mode = (cs_mode)(CS_MODE_RISCV32 | CS_MODE_RISCVC);
  Assert(open_fn(CS_ARCH_RISCV, mode, &capstone_handle) == CS_ERR_OK, "Capstone could not initialize the RISC-V decoder");
}

void disassemble(char *output, int output_size, uint64_t pc, uint8_t *code, int byte_count) {
  cs_insn *instruction = NULL;
  size_t count = decode_fn(capstone_handle, code, (size_t)byte_count, pc, 1, &instruction);
  if (count == 0) {
    snprintf(output, output_size, "<invalid>");
    return;
  }

  int used = snprintf(output, output_size, "%s", instruction[0].mnemonic);
  if (used >= 0 && used < output_size && instruction[0].op_str[0] != '\0') {
    snprintf(output + used, output_size - used, "\t%s", instruction[0].op_str);
  }
  release_fn(instruction, count);
}
