#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include <monitor/monitor.h>
#include <platform/platform.h>
#include <sim_top.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static uint64_t g_nr_sim_cycle = 0;
static uint64_t g_no_commit_cycle = 0;
static bool g_print_step = false;

extern VerilatedContext *g_contextp;
extern VerilatedVcdC *g_tfp;
bool npc_fetch_commit(vaddr_t *pc, uint32_t *inst);

static void ftrace_commit(vaddr_t pc, vaddr_t dnpc, uint32_t inst) {
#ifdef CONFIG_FTRACE
  uint32_t opcode = inst & 0x7fu;
  int rd = BITS(inst, 11, 7);
  int rs1 = BITS(inst, 19, 15);
  if (opcode == 0x6f) {
    if (rd == 1 || rd == 5) ftrace_call(pc, dnpc);
  } else if (opcode == 0x67) {
    if (rd == 0 && rs1 == 1) ftrace_ret(pc);
    else if (rd == 1 || rd == 5) ftrace_call(pc, dnpc);
  }
#endif
}

static void etrace_commit(vaddr_t pc, vaddr_t dnpc, uint32_t inst) {
#ifdef CONFIG_ETRACE
  if (inst == 0x00000073) {
    etrace_write("raise NO=11 epc=" FMT_WORD " -> mtvec=" FMT_WORD
        " mstatus=" FMT_WORD "\n", pc, dnpc, cpu.mstatus);
  } else if (inst == 0x30200073) {
    etrace_write("mret -> " FMT_WORD " mstatus=" FMT_WORD "\n", dnpc, cpu.mstatus);
  }
#endif
}

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { itrace_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  ftrace_commit(_this->pc, dnpc, _this->isa.inst);
  etrace_commit(_this->pc, dnpc, _this->isa.inst);
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc, _this->isa.inst));

#ifdef CONFIG_WATCHPOINT
  if (wp_check()) {
    npc_state.state = NPC_STOP;
  }
#endif
}

static void dump_wave() {
#ifdef CONFIG_WAVE
  if (g_tfp != NULL) g_tfp->dump(g_contextp->time());
#endif
}

static void tick_once() {
  g_top->clock = 1;
  g_top->eval();
  g_contextp->timeInc(1);
  dump_wave();

  g_top->clock = 0;
  g_top->eval();
  g_contextp->timeInc(1);
  dump_wave();
  g_nr_sim_cycle ++;
  g_no_commit_cycle ++;

  if (g_nr_sim_cycle >= CONFIG_MAX_SIM_TIME) {
    Log("NPC reaches maximum simulation cycles: %" PRIu64, g_nr_sim_cycle);
    npc_state.state = NPC_ABORT;
  } else if (g_no_commit_cycle >= CONFIG_MAX_NO_COMMIT_CYCLES) {
    Log("NPC has no instruction commit for %" PRIu64 " cycles at pc = " FMT_WORD,
        g_no_commit_cycle, cpu.pc);
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = cpu.pc;
  }
}

static bool exec_once(Decode *s) {
  vaddr_t pc = 0;
  uint32_t inst = 0;
  do {
    tick_once();
    platform_update();
  } while (npc_state.state == NPC_RUNNING
      && !npc_fetch_commit(&pc, &inst) && !Verilated::gotFinish());

  if (npc_state.state != NPC_RUNNING) {
    return false;
  } else if (Verilated::gotFinish()) {
    npc_state.state = NPC_ABORT;
    return false;
  }
  g_no_commit_cycle = 0;

  s->pc = pc;
  s->isa.inst = inst;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = 4;
  uint8_t *inst_bytes = (uint8_t *)&s->isa.inst;
  for (int i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst_bytes[i]);
  }
  int ilen_max = 4;
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      s->pc, (uint8_t *)&s->isa.inst, ilen);
#endif
  return true;
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    if (!exec_once(&s)) break;
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (npc_state.state != NPC_RUNNING) break;
  }
}

static void statistic() {
  setlocale(LC_NUMERIC, "");
#define NUMBERIC_FMT "%'" PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  Log("total simulation cycles = " NUMBERIC_FMT, g_nr_sim_cycle);
  if (g_nr_sim_cycle > 0) Log("IPC = %.4f", (double)g_nr_guest_inst / (double)g_nr_sim_cycle);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      Log("npc: %s at pc = " FMT_WORD,
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          npc_state.halt_pc);
      // fall through
    case NPC_QUIT: statistic();
  }
}
