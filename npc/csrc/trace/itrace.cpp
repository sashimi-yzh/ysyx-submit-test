#include "itrace.h"
#include "../utils/log.h"
#include "../core/npc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <capstone/capstone.h>

// Capstone函数指针
static size_t (*cs_disasm_dl)(csh handle, const uint8_t *code,
    size_t code_size, uint64_t address, size_t count, cs_insn **insn) = NULL;
static void (*cs_free_dl)(cs_insn *insn, size_t count) = NULL;
static csh cs_handle = 0;
static bool trace_enabled = true;

// 指令环形缓冲区：只保存原始信息，显示时再反汇编
#define IRINGBUF_SIZE 16

typedef struct {
  uint32_t pc;
  uint32_t inst;
  uint64_t cycle;
  uint64_t commit;
  uint64_t time;
} IringBufEntry;

static IringBufEntry iringbuf[IRINGBUF_SIZE];
static int iringbuf_idx = 0;
static bool iringbuf_full = false;

// 反汇编一条指令
static void disassemble(char *str, int size, uint32_t pc, uint8_t *code, int nbyte) {
  if (!cs_disasm_dl || !cs_free_dl || cs_handle == 0) {
    snprintf(str, size, "<disasm not available>");
    return;
  }

  cs_insn *insn;
  size_t count = cs_disasm_dl(cs_handle, code, nbyte, pc, 0, &insn);

  if (count == 0) {
    snprintf(str, size, "<invalid>");
    return;
  }

  int ret = snprintf(str, size, "%s", insn->mnemonic);
  if (ret < size && insn->op_str[0] != '\0') {
    snprintf(str + ret, size - ret, "\t%s", insn->op_str);
  }

  cs_free_dl(insn, count);
}

// 初始化itrace
void init_itrace() {
  const char *nemu_home = getenv("NEMU_HOME");
  char lib_path[512];
  if (nemu_home != NULL && nemu_home[0] != '\0') {
    snprintf(lib_path, sizeof(lib_path),
             "%s/tools/capstone/repo/libcapstone.so.5", nemu_home);
  } else {
    snprintf(lib_path, sizeof(lib_path),
             "../nemu/tools/capstone/repo/libcapstone.so.5");
  }

  void *dl_handle = dlopen(lib_path, RTLD_LAZY);
  if (!dl_handle) {
    LogWarn("Failed to load capstone library, itrace disassembly will not be available");
    LogWarn("  Error: %s", dlerror());
    return;
  }

  cs_err (*cs_open_dl)(cs_arch arch, cs_mode mode, csh *handle) = NULL;
  cs_open_dl = (cs_err (*)(cs_arch, cs_mode, csh*))dlsym(dl_handle, "cs_open");
  if (!cs_open_dl) {
    LogWarn("Failed to find cs_open in capstone library");
    return;
  }

  cs_disasm_dl = (size_t (*)(csh, const uint8_t*, size_t, uint64_t, size_t, cs_insn**))dlsym(dl_handle, "cs_disasm");
  if (!cs_disasm_dl) {
    LogWarn("Failed to find cs_disasm in capstone library");
    return;
  }

  cs_free_dl = (void (*)(cs_insn*, size_t))dlsym(dl_handle, "cs_free");
  if (!cs_free_dl) {
    LogWarn("Failed to find cs_free in capstone library");
    return;
  }

  // NPC 是 RV32E，不实现压缩指令
  int ret = cs_open_dl(CS_ARCH_RISCV, CS_MODE_RISCV32, &cs_handle);
  if (ret != CS_ERR_OK) {
    LogWarn("Failed to initialize capstone (error code: %d)", ret);
    cs_handle = 0;
    return;
  }

  Log("itrace initialized successfully with capstone disassembler");
}

void set_itrace_enabled(bool enable) {
  trace_enabled = enable;
}

bool itrace_enabled() {
  return trace_enabled;
}

static void iringbuf_write(uint32_t pc, uint32_t inst,
                           uint64_t cycle, uint64_t commit, uint64_t time) {
  iringbuf[iringbuf_idx].pc = pc;
  iringbuf[iringbuf_idx].inst = inst;
  iringbuf[iringbuf_idx].cycle = cycle;
  iringbuf[iringbuf_idx].commit = commit;
  iringbuf[iringbuf_idx].time = time;
  iringbuf_idx = (iringbuf_idx + 1) % IRINGBUF_SIZE;
  if (iringbuf_idx == 0) iringbuf_full = true;
}

static void format_itrace_line(char *buf, size_t size, uint32_t pc, uint32_t inst,
                               uint64_t cycle, uint64_t commit, uint64_t time) {
  char prefix[160];
  log_trace_prefix_at(prefix, sizeof(prefix), "ITRACE", pc, cycle, commit, time);

  uint8_t *b = (uint8_t *)&inst;
  char disasm[128];
  disassemble(disasm, sizeof(disasm), pc, b, 4);
  snprintf(buf, size, "%s%02x %02x %02x %02x  %s",
           prefix, b[3], b[2], b[1], b[0], disasm);
}

// 记录一条指令的执行
void itrace_log(uint32_t pc, uint32_t inst, bool print_to_console) {
  if (!trace_enabled) return;

  uint64_t cycle = npc_get_commit_cycle();
  uint64_t commit = npc_get_commit_count();
  uint64_t time = npc_get_commit_time();

  iringbuf_write(pc, inst, cycle, commit, time);

  char logbuf[320];
  format_itrace_line(logbuf, sizeof(logbuf), pc, inst, cycle, commit, time);
  log_write("%s\n", logbuf);

  if (print_to_console) {
    printf("%s\n", logbuf);
    fflush(stdout);
  }
}

// 显示指令环形缓冲区
void display_iringbuf() {
  char header[128];
  snprintf(header, sizeof(header), "Recent executed instructions (iringbuf):");
  printf("\n%s\n", header);
  log_write("\n%s\n", header);

  int start = iringbuf_full ? iringbuf_idx : 0;
  int count = iringbuf_full ? IRINGBUF_SIZE : iringbuf_idx;
  if (count == 0) {
    printf("  (empty)\n");
    log_write("  (empty)\n");
    return;
  }

  for (int i = 0; i < count; i++) {
    int idx = (start + i) % IRINGBUF_SIZE;
    char line[320];
    format_itrace_line(line, sizeof(line), iringbuf[idx].pc, iringbuf[idx].inst,
                       iringbuf[idx].cycle, iringbuf[idx].commit, iringbuf[idx].time);
    const char *mark = (i == count - 1) ? "-->" : "   ";
    printf("%s %s\n", mark, line);
    log_write("%s %s\n", mark, line);
  }
  printf("\n");
  log_write("\n");
}
