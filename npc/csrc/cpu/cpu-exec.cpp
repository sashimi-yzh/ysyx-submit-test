#include <npc/cpu.h>
#include <npc/diagnostics.h>
#include <locale.h>
#include <string.h>
#include <npc/monitor.h>
#include <npc/platform.h>
#include <sim_top.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10
// cpu (C struct) && inst commit number
CPU_state cpu = {};
uint64_t guest_insts = 0;
// static of the simulation info
typedef struct {
  uint64_t host_time;
  uint64_t nr_cycles;
  uint64_t stall_cycles;
  bool print_step;
} RunStats;
static RunStats stats = {};

extern VerilatedContext *sim_ctx;
extern VerilatedVcdC *sim_trace;
// etrace output
static void trace_exception_event(vaddr_t pc, vaddr_t dnpc, uint32_t inst) {
#ifdef CONFIG_ETRACE
  if (inst == 0x00000073) {
    trace_write(TRACE_ETRACE, "raise NO=11 epc=" FMT_WORD " -> mtvec=" FMT_WORD " mstatus=" FMT_WORD "\n", pc, dnpc, cpu.mstatus);
  } else if (inst == 0x30200073) {
    trace_write(TRACE_ETRACE, "mret -> " FMT_WORD " mstatus=" FMT_WORD "\n", dnpc, cpu.mstatus);
  }
#endif
}
// itracr && ftrace && etrace && difftest && watchpoint interface
static void trace_retire(const Decode *decode, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { trace_write(TRACE_ITRACE, "%s\n", decode->logbuf); }
#endif
  if (stats.print_step) { IFDEF(CONFIG_ITRACE, puts(decode->logbuf)); }
  ftrace_trace(decode->pc, decode->isa.inst, dnpc);
  trace_exception_event(decode->pc, dnpc, decode->isa.inst);
  IFDEF(CONFIG_DIFFTEST, difftest_step(decode->pc, dnpc, decode->isa.inst));
#ifdef CONFIG_WATCHPOINT
  if (check_watchpoints()) {
    npc_state.state = NPC_STOP;
  }
#endif
}
// record wave
static void capture_waveform() {
#ifdef CONFIG_WAVE
  if (sim_trace != NULL) sim_trace->dump(sim_ctx->time());
#endif
}
// time add
static void drive_half_cycle(bool high) {
  sim_top->clock = high;
  sim_top->eval();
  sim_ctx->timeInc(1);
  capture_waveform();
}
// the clock flip
static void advance_rtl() {
  drive_half_cycle(true);
  drive_half_cycle(false);
  stats.nr_cycles ++;
  stats.stall_cycles ++;

  if (stats.nr_cycles >= CONFIG_MAX_SIM_TIME) {
    Log("run limit reached: cycles=%" PRIu64, stats.nr_cycles);
    npc_state.state = NPC_ABORT;
  } else if (stats.stall_cycles >= CONFIG_MAX_NO_COMMIT_CYCLES) {
    Log("run stalled: idle_cycles=%" PRIu64 " pc=" FMT_WORD, stats.stall_cycles, cpu.pc);
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = cpu.pc;
  }
}
// decode the itrace inst to assembly language
static void format_instruction(Decode *decode) {
#ifdef CONFIG_ITRACE
  char *cursor = decode->logbuf;
  cursor += snprintf(cursor, sizeof(decode->logbuf), FMT_WORD ":", decode->pc);
  const int instruction_length = sizeof(decode->isa.inst);
  const uint8_t *bytes = (const uint8_t *)&decode->isa.inst;
  for (int index = instruction_length - 1; index >= 0; index --) {
    cursor += snprintf(cursor, 4, " %02x", bytes[index]);
  }
  const int padding = (int)sizeof(decode->isa.inst) - instruction_length;
  const int padding_length = padding > 0 ? padding * 3 + 1 : 1;
  memset(cursor, ' ', padding_length);
  cursor += padding_length;
  disassemble(cursor, decode->logbuf + sizeof(decode->logbuf) - cursor, decode->pc, (uint8_t *)&decode->isa.inst, instruction_length);
#else
  (void)decode;
#endif
}
// retire one inst and decode to assembly language
static bool retire_one(Decode *decode) {
  vaddr_t retired_pc = 0;
  uint32_t retired_inst = 0;
  do {
    advance_rtl();
    update_platform();
  } while (npc_state.state == NPC_RUNNING && !cpu_take_commit(&retired_pc, &retired_inst) && !Verilated::gotFinish());

  if (npc_state.state != NPC_RUNNING) {
    return false;
  } else if (Verilated::gotFinish()) {
    npc_state.state = NPC_ABORT;
    return false;
  }
  stats.stall_cycles = 0;

  decode->pc = retired_pc;
  decode->isa.inst = retired_inst;
  format_instruction(decode);
  return true;
}
// the top one cycle core
static void run_instructions(uint64_t count) {
  Decode decode;
  for (; count > 0; count --) {
    if (!retire_one(&decode)) break;
    guest_insts ++;
    trace_retire(&decode, cpu.pc);
    if (npc_state.state != NPC_RUNNING) break;
  }
}
// print the statistic info
static void print_run_summary() {
  setlocale(LC_NUMERIC, "");
#define NUMERIC_FMT "%'" PRIu64
  double ipc = stats.nr_cycles == 0 ? 0.0 : (double)guest_insts / (double)stats.nr_cycles;
  double cpi = guest_insts == 0 ? 0.0 : (double)stats.nr_cycles / (double)guest_insts;
  uint64_t instruction_rate = stats.host_time == 0 ? 0 : guest_insts * 1000000 / stats.host_time;
  uint64_t cycle_rate = stats.host_time == 0 ? 0 : stats.nr_cycles * 1000000 / stats.host_time;

  Log("host time spent = " NUMERIC_FMT " us (%.3f ms)", stats.host_time, (double)stats.host_time / 1000.0);
  Log("total guest instructions = " NUMERIC_FMT, guest_insts);
  Log("RTL cycles = " NUMERIC_FMT, stats.nr_cycles);
  Log("IPC = %.4f, CPI = %.2f", ipc, cpi);
  if (stats.host_time > 0) {
    Log("simulation frequency = " NUMERIC_FMT " inst/s, " NUMERIC_FMT " cycles/s", instruction_rate, cycle_rate);
  } else {
    Log("simulation frequency is unavailable (runtime < 1 us)");
  }
}
// print info if error
void assert_fail_msg() {
  isa_reg_display();
  print_run_summary();
}
// top function for c drive
void cpu_exec(uint64_t n) {
  stats.print_step = (n < MAX_INST_TO_PRINT);
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }
  // record each cycle time by end and start
  uint64_t timer_start = get_time();

  run_instructions(n);

  uint64_t timer_end = get_time();
  stats.host_time += timer_end - timer_start;
  // drive the state machin
  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;
    case NPC_STOP: break;
    case NPC_END: case NPC_ABORT:
      if (npc_state.state == NPC_ABORT) {
        Log("npc: %s at pc = " FMT_WORD, ANSI_FMT("ABORT", ANSI_FG_RED), npc_state.halt_pc);
      } else if (npc_state.halt_ret == 0) {
        Log("npc: %s at pc = " FMT_WORD ", exit code = %u", ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN), npc_state.halt_pc, npc_state.halt_ret);
      } else {
        Log("npc: %s at pc = " FMT_WORD ", exit code = %u", ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED), npc_state.halt_pc, npc_state.halt_ret);
      }
      // fall through
    case NPC_QUIT:
      print_run_summary();
  }
}
