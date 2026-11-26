#include "log.h"
#include "../core/npc.h"
#include "../core/reg.h"
#include "../core/memory.h"
#include "../trace/itrace.h"
#include "../trace/mtrace.h"
#include "../trace/ftrace.h"

// 失败时的统一快照：GPR/CSR + 最近指令 + 最近数据访存/函数调用 + PC 附近内存
void npc_dump_snapshot() {
  LogError("==================== NPC snapshot ====================");
  LogError("pc=0x%08x cycle=%llu commit=%llu time=%llu",
           npc_get_pc(), (unsigned long long)npc_get_cycle(),
           (unsigned long long)npc_get_commit_count(),
           (unsigned long long)npc_get_time());

  npc_reg_display();

  display_iringbuf();
  mtrace_dump_recent();
  ftrace_dump_recent();

  printf("\nMemory around pc:\n");
  log_write("\nMemory around pc:\n");
  uint32_t pc = npc_get_pc();
  for (int i = -4; i <= 4; i++) {
    uint32_t addr = pc + i * 4;
    uint32_t data;
    if (npc_mem_read_word(addr, &data)) {
      printf("  0x%08x: 0x%08x\n", addr, data);
      log_write("  0x%08x: 0x%08x\n", addr, data);
    } else {
      printf("  0x%08x: <unavailable>\n", addr);
      log_write("  0x%08x: <unavailable>\n", addr);
    }
  }

  log_flush();
  LogError("=======================================================");
  log_flush();
}
