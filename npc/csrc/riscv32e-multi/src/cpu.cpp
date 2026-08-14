#include <common.h>
#include <dpi-c.h>
static long long cycle = 0;
static long long npc_valid = 0;

long long ifu_counter;
long long load_counter;
long long store_counter;
long long exu_counter;
long long idu_load;
long long idu_store;
long long idu_jalr;
long long idu_jal;
long long idu_branch;
long long idu_csr;
long long idu_mret;
long long idu_ecall;
long long idu_alu;
long long lsu_load_delay;
long long lsu_store_delay;
long long ifu_fetch_delay;
long long ifu_wait_delay;

long long access_time=1;
long long miss_penalty;
long long ifu_req;
long long icache_hit;
void npctrap() {
  word_t a0 = get_regs(10);
  if(a0 == 0) {
    printf(ANSI_FMT("HIT GOOD TRAP\n", ANSI_FG_GREEN));
    printf("TOTAL CYCLES: %lld\n", cycle);
    printf("TOTAL INST: %lld\n", npc_valid);

    printf("IPC = %.3f\n", npc_valid * 1.0 / cycle);
    printf("IFU FETCH INST: %lld + 1\n", ifu_counter - 1); // 不考虑ebreak
    printf("\tFETCH DELAY: %.3f cycles(%.3f%%)\tWAIT DELAY: %.3f cycles(%.3f%%)\n", ifu_fetch_delay * 1.0 / npc_valid, ifu_fetch_delay * 100.0 / (ifu_fetch_delay + ifu_wait_delay), ifu_wait_delay * 1.0 / npc_valid, ifu_wait_delay * 100.0 / (ifu_fetch_delay + ifu_wait_delay));
    printf("ICACHE:\n");
    printf("\tAMAT: %.3f cycles\n", (ifu_req + miss_penalty) * 1.0 / ifu_req);
    printf("\taccess_time: 1 cycle\n\tmiss_penalty: %.3f cycles\n\tAccesses: %lld\n\tHits: %lld\n\thit_rate: %.3f%%\n", miss_penalty * 1.0 / (ifu_req - icache_hit), ifu_req, icache_hit, icache_hit * 100.0 / ifu_req);
    printf("IDU INST TYPE:\n");
    if(idu_alu + idu_load + idu_store + idu_jal + idu_jalr + idu_branch + idu_csr + idu_ecall + idu_mret != ifu_counter - 1) 
      printf(ANSI_FMT("IFU INST != IDU INST(%lld)\n", ANSI_FG_RED), idu_alu + idu_load + idu_store + idu_jal + idu_jalr + idu_branch + idu_csr + idu_ecall + idu_mret);
    printf("\tALU\t%lld(%.3f%%)\t1 cycle\n", idu_alu, (idu_alu * 100.0 / (ifu_counter - 1)));
    printf("\tLOAD\t%lld(%.3f%%)\t%.3f cycles\n", idu_load, idu_load * 100.0 / (ifu_counter - 1), lsu_load_delay * 1.0 / load_counter);
    printf("\tSTORE\t%lld(%.3f%%)\t%.3f cycles\n", idu_store, idu_store * 100.0 / (ifu_counter - 1), lsu_store_delay * 1.0 / store_counter);
    printf("\tJALR\t%lld(%.3f%%)\t1 cycle\n", idu_jalr, idu_jalr * 100.0 / (ifu_counter - 1));
    printf("\tJAL\t%lld(%.3f%%)\t1 cycle\n", idu_jal, idu_jal * 100.0 / (ifu_counter - 1));
    printf("\tBRANCH\t%lld(%.3f%%)\t1 cycle\n", idu_branch, idu_branch * 100.0 / (ifu_counter - 1));
    printf("\tCSR\t%lld(%.3f%%)\t1 cycle\n", idu_csr, idu_csr * 100.0 / (ifu_counter - 1));
    printf("\tMRET\t%lld(%.3f%%)\t1 cycle\n", idu_mret, idu_mret * 100.0 / (ifu_counter - 1));
    printf("\tECALL\t%lld(%.3f%%)\t1 cycle\n", idu_ecall, idu_ecall * 100.0 / (ifu_counter - 1));
    printf("EXU FINISH: %lld\n", exu_counter);
    printf("LSU LOAD DATA: %lld\tDELAY: %.3f\n", load_counter, lsu_load_delay * 1.0 / load_counter);
    printf("LSU STORE DATA: %lld\tDELAY: %.3f\n", store_counter, lsu_store_delay * 1.0 / store_counter);
    npc_state = NPC_GOODTRAP;
  }
  else {
    printf(ANSI_FMT("HIT BAD TRAP\n", ANSI_FG_RED));
    npc_state = NPC_BADTRAP;
  }
}

bool itrace_flag = true;

void tick() {
  top->clock = 1; top->eval(); tfp->dump(contextp->time()); contextp->timeInc(5);
  top->clock = 0; top->eval(); tfp->dump(contextp->time()); contextp->timeInc(5);
}

void exec_once() {
  // 取指令
  while(get_ifu_state() == 0) { // 等待复位信号稳定
    tick();
  }
  while(get_ifu_state() == 1) {
    tick();
  }

  if(itrace_flag) {
    inst_display(get_pc(), get_inst());
  }
  if(get_inst() == 0x00100073) {
    npctrap();
  }
  if(get_isRet()) ftrace_ret(get_pc());
  if(get_isCall()) ftrace_call(get_pc(), get_jump_addr());

   // 执行指令
  while(get_ifu_state() == 2) {
    tick();
  }

  if(npc_pc >= 0x80000000 && npc_pc <= 0x804fffff) {
    if(regs(2) < 0xf000000) {
      npc_state = NPC_ABORT;
      printf("stack overflow\n");
    }
  }
}

void cpu_exec(uint64_t n) {
  switch (npc_state) {
    case NPC_BADTRAP: case NPC_ABORT: case NPC_GOODTRAP: case NPC_QUIT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state = NPC_RUNNING;
  }
  while(n--) {
    word_t cur_pc = get_pc();
    exec_once();
    // printf("0x%08x\n", get_pc());
    difftest_step(get_pc(), cur_pc);
    if(npc_state != NPC_RUNNING) break;
  }

  if(npc_state == NPC_RUNNING) npc_state = NPC_STOP;
}
