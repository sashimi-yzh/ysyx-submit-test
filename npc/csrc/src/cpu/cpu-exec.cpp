#include "utils.h"
#include <cpu/difftest.h>
#include <isa.h>
#include <locale.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
extern uint64_t inst_num;
extern uint64_t cycle;
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;
extern uint64_t inst_num;
bool is_skip_exec = false;
bool no_dest = false;
uint32_t dest_reg_value = 0;

void device_update();
int scan_wp();
void ftrace_call_ret(Decode *_this);
void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void set_npc_state(int state, vaddr_t pc, int halt_ret);
void sim_exit();

#ifdef CONFIG_FTRACE
void ftrace(word_t pc, word_t npc, bool call);

void ftrace_call_ret(Decode *_this) {
  if (!memcmp(_this->logbuf + 39, "jal\tra", 6) ||
      !memcmp(_this->logbuf + 39, "jalr\tra", 7)) {
    ftrace(_this->pc, cpu.pc, true);
  }
  if (!memcmp(_this->logbuf + 39, "jalr\tzero, 0(ra)", 16)) {
    ftrace(_this->pc, cpu.pc, false);
  }
}
#endif /* ifdef CONFIG_FTRACEj */

#ifdef CONFIG_IRINGBUF
// 注释的是保证开始几条指令出错时，打印信息的美观
static char iringbuf[16][128] = {};
static int w_ptr = 0;
// static int r_ptr = 0;
// static uint64_t ir = 0;

void iringbuf_write(char *logbuf) {
  strcpy(iringbuf[w_ptr], logbuf);
  // if (ir != 0)
  //   if (w_ptr == r_ptr) {
  //     r_ptr++;
  //     r_ptr %= 16;
  //   }
  // ir++;
  w_ptr++;
  w_ptr %= 16;
}

void iringbuf_read() {
  int i;
  // for (i = 0; i < 15 && iringbuf[r_ptr + 1][0]; i++) {
  printf("\n");
  printf("Iringbuf Read Result:\n");
  for (i = 0; i < 15; i++) {
    // printf("%s\n", iringbuf[r_ptr++]);
    // r_ptr %= 16;
    printf("%s\n", iringbuf[w_ptr++]);
    w_ptr %= 16;
  }
  // printf(ANSI_FMT("%s\n", ANSI_FG_RED), iringbuf[r_ptr]);
  printf(ANSI_FMT("%s\n", ANSI_FG_RED), iringbuf[w_ptr]);
}
#endif /* ifdef CONFIG_IRINGBUF */

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (inst_num >= CONFIG_TRACE_INST_NUM)
  { log_write("%s\n", _this->logbuf); }
#endif /* ifdef CONFIG_ITRACE_COND */

  if (g_print_step) {
    IFDEF(CONFIG_ITRACE, puts(_this->logbuf));
  }

  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
  IFDEF(CONFIG_WATCHPOINT, if (scan_wp() < 0) npc_state.state = NPC_STOP);
  IFDEF(CONFIG_IRINGBUF, iringbuf_write(_this->logbuf));
  IFDEF(CONFIG_FTRACE, ftrace_call_ret(_this));
}

void disasm_to_logbuf(Decode *s) {
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i--) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0)
    space_len = 0;
  space_len = space_len * 3 + 4;
  memset(p, ' ', space_len);
  p += space_len;
  if (no_dest) {
    p += snprintf(p, 16, "               ");
  } else {
    p += snprintf(p, 16, "res: 0x%08x", dest_reg_value);
  }
  memset(p, ' ', 2);
  p += 2;

  if (s->acc_mem) {
    p += snprintf(p, 17, "addr: 0x%08x", s->mem_addr);
  } else {
    p += snprintf(p, 17, "                ");
  }
  memset(p, ' ', 2);
  p += 2;

  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
              MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc),
              (uint8_t *)&s->isa.inst.val, ilen);
#endif
}

void set_s_and_cpu(Decode *s, vaddr_t pc) {
  #ifndef CONFIG_FAST_SIM
  s->pc = lsu_wbu_pc();
  s->snpc = lsu_wbu_pc() + 4;
  s->dnpc = lsu_wbu_npc();
  s->mem_addr = r_exu_out();
  s->acc_mem = r_mem_ren() || r_mem_wen();
  s->isa.inst.val = lsu_wbu_inst();

  cpu.pc = s->dnpc;
  if (lsu_gpr_wen()) {
    cpu.gpr[lsu_gpr_waddr()] = lsu_wbu_gpr_wdata();
    cpu.gpr[0] = 0;
  }

  if (lsu_csr_wen()) {
    switch (lsu_csr_waddr()) {
      case 0:
        cpu.csr[MTVEC] = lsu_csr_wdata();
        break;
      case 1:
        cpu.csr[MEPC] = lsu_csr_wdata();
        break;
      case 2:
        cpu.csr[MCAUSE] = lsu_csr_wdata();
        break;
      case 3:
        cpu.csr[MSTATUS] = lsu_csr_wdata();
        break;
      default:
        break;
    }
  }

  if (lsu_csr_excp()) {
    cpu.csr[MEPC] = lsu_wbu_pc();
    cpu.csr[MCAUSE] = lsu_csr_mcause();
  }

  no_dest = !(lsu_gpr_wen() || lsu_csr_wen());
  dest_reg_value = lsu_gpr_wen() ? lsu_wbu_gpr_wdata() : lsu_csr_wdata();

  // recognise ecall inst
  if (is_skip_exec) {
    is_skip_exec = false;
    difftest_skip_ref();
  }
  #endif
}

#ifdef CONFIG_SDB
extern "C" void Ebreak() {
  set_npc_state(NPC_END, lsu_wbu_pc(), reg_value(10));
}
#endif // CONFIG_SDB

static void exec_once(Decode *s, vaddr_t pc) {
  #ifndef CONFIG_FAST_SIM
  while (1) {
    if (!step_and_dump_once()) return;

    if (lsu_valid() == 1) {
      IFNDEF(CONFIG_FAST_SIM, if (addr_in_uart() == 1 || addr_in_clint() || lsu_r_is_fencei()) is_skip_exec = true);
      set_s_and_cpu(s, pc);
      break;
    }
  }

  disasm_to_logbuf(s);
  #endif
}

static void execute(uint64_t n) {
  Decode s;
  for (; n > 0; n--) {
    exec_once(&s, cpu.pc);
    trace_and_difftest(&s, cpu.pc);
    if (npc_state.state != NPC_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void execute_fast() {
  while(1) {
    step_and_dump_once();
    if (npc_state.state != NPC_RUNNING) break;
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us (" NUMBERIC_FMT "s)", g_timer, g_timer/1000000);
  Log("total guest instructions = " NUMBERIC_FMT, inst_num);
  Log("total guest cycles = " NUMBERIC_FMT, cycle);
  Log("IPC = %lf", (double)inst_num / (double)cycle);
  if (g_timer > 0)
    Log("host simulation frequency = " NUMBERIC_FMT " inst/s",
        inst_num * 1000000 / g_timer);
  else
    Log("Finish running in less than 1 us and can not calculate the simulation "
        "frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  IFDEF(CONFIG_IRINGBUF, iringbuf_read());
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (npc_state.state) {
  case NPC_END:
  case NPC_ABORT:
    printf("Program execution has ended. To restart the program, exit npc and "
           "run again.\n");
    return;
  default:
    npc_state.state = NPC_RUNNING;
  }

  uint64_t timer_start = get_time();

#ifdef CONFIG_FAST_SIM
  execute_fast();
#else
  execute(n);
#endif

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (npc_state.state) {
  case NPC_RUNNING:
    npc_state.state = NPC_STOP;
    break;

  case NPC_END:
  case NPC_ABORT:
    Log("npc: %s, halt_ret = %d, at pc = " FMT_WORD,
        (npc_state.state == NPC_ABORT
             ? ANSI_FMT("ABORT", ANSI_FG_RED)
             : (npc_state.halt_ret == 0
                    ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN)
                    : ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
        npc_state.halt_ret, npc_state.halt_pc);
    IFDEF(CONFIG_IRINGBUF, if (npc_state.state == NPC_ABORT) iringbuf_read());
    if (npc_state.state == NPC_ABORT) {
      assert_fail_msg();
    }
    sim_exit();
    if (npc_state.halt_ret) assert(0);
    // fall through
  case NPC_QUIT:
    statistic();
  }
}
