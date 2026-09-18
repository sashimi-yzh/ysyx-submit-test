#include <npc.h>
#include <common.h>
#include <sdb.h>

#define COUNTER 7
#define MAX_LOOP 1000000

MUXDEF(CONFIG_SOC, VysyxSoCFull *top = new VysyxSoCFull;, Vtop *top = new Vtop;)

VerilatedFstC* tfp = new VerilatedFstC;
vluint64_t main_time = 0;

bool en[COUNTER] = {0};
bool cpu_valid = false;
bool in_bootloader = false;

int lsu_r_valid = 0;
int lsu_w_valid = 0;
int exu_valid   = 0;
int alu_valid   = 0;
int csr_valid   = 0;
int jump        = 0;
int branch      = 0;

uint32_t total_inst;
uint32_t lsu_r_counter;
uint32_t lsu_w_counter;
uint32_t exu_counter;
uint32_t alu_counter;
uint32_t csr_counter;
uint32_t jump_counter;
uint32_t branch_counter;
uint32_t icache_hit_counter;
uint32_t icache_miss_counter;
uint32_t icache_miss_latency;

// get cpu state
extern "C" void get_cpu_state(int lsu_get_data, int lsu_w_data, int exu_done, int alu_we, int csr_we, int cpu_jump, int cpu_branch, int icache_hit, int icache_miss, int miss_lat) {
  lsu_r_valid = lsu_get_data;
  lsu_w_valid = lsu_w_data;
  exu_valid   = exu_done;
  alu_valid   = alu_we;
  csr_valid   = csr_we;
  jump        = cpu_jump;
  branch      = cpu_branch;
  icache_hit_counter  = icache_hit;
  icache_miss_counter = icache_miss;
  icache_miss_latency = miss_lat;
}

// PC 初始化
CPU_state cpu_n = { .pc = PC_START };

// 性能计数器和 IPC 追踪
static void statistics() {
  uint32_t total_access = icache_hit_counter + icache_miss_counter;
  double amat = total_access > 0 ?
    (double)(icache_hit_counter * 1 + icache_miss_latency) / total_access : 0;
  double miss_rate = total_access > 0 ?
    (double)icache_miss_counter / total_access * 100 : 0;

  Log("Total cycles = %ld", main_time);
  Log("Total insts = %ld", total_inst);
#ifdef CONFIG_STATISTICS
  Log("- Load and Store insts = %ld, with %ld loads and %ld stores", lsu_r_counter + lsu_w_counter, lsu_r_counter, lsu_w_counter);
  Log("- Execution insts = %ld", exu_counter);
  Log("- Computational insts = %ld", alu_counter);
  Log("- CSR insts = %ld", csr_counter);
  Log("- Jump insts = %ld", jump_counter);
  Log("- Branch insts = %ld", branch_counter);
  Log("- ICache: hit=%ld miss=%ld miss_rate=%.1f%% miss_latency=%ld AMAT=%.2f",
      icache_hit_counter, icache_miss_counter, miss_rate, icache_miss_latency, amat);
#endif
  Log("Simulation IPC of npc = %.8f", (double)total_inst / main_time);
}

// eval
struct pc_loop // 单个死循环指令
{
  uint32_t pc;
  uint32_t loop_time;
};
pc_loop *lp = new pc_loop{ .pc = PC_START, .loop_time = 0 };

static void dead_loop() {
  Log("\033[1;31mDead loop at PC = 0x%08x\033[0m", lp->pc);
  npc_state.state = NPC_ABORT;
  npc_state.halt_pc = lp->pc;
}

void step_and_eval() {
  // eval
  top->clock = 0; top->eval();
  top->clock = 1; top->eval();

  // wave dump
  IFDEF(CONFIG_WAVE_DUMP, tfp->dump(main_time));
  main_time ++;

  // check dead loop
  lp->loop_time ++;
  if (lp->loop_time > MAX_LOOP) dead_loop();

  // nvboard
  IFDEF(CONFIG_NVBOARD, nvboard_update());

  // difftest
  cpu_n.pc = CPU_DNPC();
  check_device();

  // statistics
  get_cpu_state(lsu_r_valid, lsu_w_valid, exu_valid, alu_valid, csr_valid, jump, branch, icache_hit_counter, icache_miss_counter, icache_miss_latency);
  if (en[0] && lsu_r_valid) { lsu_r_counter++;  en[0] = 0; }
  if (en[1] && lsu_w_valid) { lsu_w_counter++;  en[1] = 0; }
  if (en[2] && exu_valid)   { exu_counter++;    en[2] = 0; }
  if (en[3] && alu_valid)   { alu_counter++;    en[3] = 0; }
  if (en[4] && csr_valid)   { csr_counter++;    en[4] = 0; }
  if (en[5] && jump)        { jump_counter++;   en[5] = 0; }
  if (en[6] && branch)      { branch_counter++; en[6] = 0; }
}

// debug相关
static void trace_and_difftest() {
  cpu_valid = CPU_VALID();
  in_bootloader = (CPU_PC() >= CONFIG_FLASH_BASE && CPU_PC() < CONFIG_FLASH_BASE + CONFIG_FLASH_SIZE) || (CPU_PC() >= CONFIG_SRAM_BASE && CPU_PC() < CONFIG_SRAM_BASE + CONFIG_SRAM_SIZE);
  if (cpu_valid) {
    itrace_record(CPU_PC(), CPU_INST());
    IFDEF(CONFIG_WATCHPOINT, check_watchpoints());
    IFDEF(CONFIG_DIFFTEST, check_difftest());
    total_inst ++;
    for (int i = 0; i < COUNTER; i++) en[i] = 1;

    lp->pc = CPU_PC();
    lp->loop_time = 0;
  }
}

// 执行相关
void cpu_exec(uint64_t n) {
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
    printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
    return;
    default: npc_state.state = NPC_RUNNING;
  }

  for (uint64_t i = 0; i < n; i ++) {
    step_and_eval();
    trace_and_difftest();
    if (npc_state.state != NPC_RUNNING) break;
  }

  if (npc_state.state == NPC_RUNNING) npc_state.state = NPC_STOP;
}

// 退出模拟
void sim_exit() {
  statistics();
  Log("Simulation already ended at 0x%08x.", npc_state.halt_pc);
#ifdef CONFIG_WAVE_DUMP
  tfp->close();
  delete tfp;
#endif
  IFDEF(CONFIG_NVBOARD, nvboard_quit());
  delete top;
}

// ebreak
void finish_sim() {
  npc_state.halt_pc = CPU_PC();
  if (R[10] == 0) { 
    Log("\033[1;32mHIT GOOD TRAP\033[0m"); 
    npc_state.state = NPC_END;
  }
  else {
    Log("\033[1;31mHIT BAD TRAP\033[0m");
    npc_state.state = NPC_ABORT;
    itrace_dump(16);
  }
}

