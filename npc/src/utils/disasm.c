#include <npc.h>
#include <common.h>
#include <capstone/capstone.h>

static csh handle = 0;

// 最近若干条提交指令的环形缓冲
#define ITRACE_RING 256
static struct { uint32_t pc, inst; } itrace_ring[ITRACE_RING];
static uint32_t itrace_wp = 0;

void init_disasm() {
  if (cs_open(CS_ARCH_RISCV, (cs_mode)(CS_MODE_RISCV32 | CS_MODE_RISCVC), &handle) != CS_ERR_OK) {
    handle = 0;
    Log("capstone init failed, itrace disabled");
  }
}

static void fmt_inst(char *buf, size_t sz, uint32_t pc, uint32_t inst) {
  if (handle == 0) {
    snprintf(buf, sz, "0x%08x: %08x", pc, inst);
    return;
  }
  cs_insn *insn;
  size_t count = cs_disasm(handle, (uint8_t *)&inst, 4, pc, 0, &insn);
  if (count > 0) {
    snprintf(buf, sz, "0x%08x: %08x  %s %s", pc, inst, insn[0].mnemonic, insn[0].op_str);
    cs_free(insn, count);
  } else {
    snprintf(buf, sz, "0x%08x: %08x  <invalid>", pc, inst);
  }
}

void itrace_record(int pc, int inst) {
  itrace_ring[itrace_wp % ITRACE_RING].pc   = pc;
  itrace_ring[itrace_wp % ITRACE_RING].inst = inst;
  itrace_wp ++;

  IFDEF(CONFIG_ITRACE, // 实时日志
    char buf[128];
    fmt_inst(buf, sizeof(buf), pc, inst);
    log_write("%s\n", buf);
  );
}

// 出错时打印最近 n 条提交指令
void itrace_dump(int n) {
  uint32_t cnt = itrace_wp < ITRACE_RING ? itrace_wp : ITRACE_RING;
  if (n > (int)cnt) n = cnt;
  Log("---- last %d committed instructions ----", n);
  for (int i = (int)cnt - n; i < (int)cnt; i ++) {
    char buf[128];
    fmt_inst(buf, sizeof(buf), itrace_ring[i].pc, itrace_ring[i].inst);
    Log("  %s", buf);
  }
  Log("----------------------------------------");
}
