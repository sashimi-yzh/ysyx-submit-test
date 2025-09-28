#include "common.h"
#include "cpu.h"
#include "mem.h"
#include "trace.h"
#include "perf.h"

addr_t cpu_pc;

static uint64_t nr_cycle = 0;
static uint64_t nr_inst = 0;
bool trace_enabled = true;

static void statistic() {
  Log("total instructions = %lu", nr_inst);
  Log("total cycles = %lu", nr_cycle);
  Log("average IPC = %lf", nr_inst / (double)nr_cycle);

  log_write("---------- Performance Counter ----------\n");
  log_perf_stat();
}

void assert_fail_msg() {
  reg_display();
  IFDEF(ITRACE, print_iringbuf());
  statistic();
}

static void exec_once() {
  extern bool exec_once_flag;
  exec_once_flag = false;
  while (true) {
    driver_cycle();
    ++nr_cycle;
    if (exec_once_flag) break;
  }
  ++nr_inst;

  // 执行一定数量的指令后开始记录波形
  // extern bool wave_rec;
  // if (nr_inst > 160000) wave_rec = true;
}

static void wp_and_difftest() {
  IFDEF(DIFFTEST, difftest_step());
#ifdef WATCHPOINT
  bool check_wps(void);
  if (check_wps()) {
    if (npc_state.state == NPC_RUNNING) npc_state.state = NPC_STOP;
  }
#endif
}

static void execute(uint64_t n) {
  bool print = n <= 24;
  while (n--) {
    addr_t trace_pc = cpu_pc;

    exec_once();

#ifdef ITRACE
    extern word_t itrace_inst;
    itrace(trace_pc, itrace_inst, print);
    Assert((itrace_inst & 0b11) == 0b11, "Illegal instruction fetched!");
#endif
#ifdef PCTRACE
    pctrace(trace_pc);
#endif
#ifdef FTRACE
    ftrace(trace_pc, cpu_pc);
#endif

    wp_and_difftest();
    if (nr_cycle >= MAX_CYCLE) {
      Log("Cycle limit exceed, abort");
      npc_state.state = NPC_ABORT;
      break;
    }
    if (npc_state.state != NPC_RUNNING) break;
  }
}

void cpu_exec(uint64_t n) {
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT:
      printf("Program execution has ended. To restart the program, exit and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }

  execute(n);

  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;
    case NPC_ABORT: IFDEF(ITRACE, print_iringbuf());
    // fall through
    case NPC_END:
      Log("npc: %s at pc = " FMT_ADDR,
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))), npc_state.halt_pc);
      // fall through
    case NPC_QUIT: statistic();
  }
}

void init_cpu() {
  reset_top();
  cpu_pc = MUXDEF(YSYXSOC, FLASH_BASE, MEM_BASE);
}
