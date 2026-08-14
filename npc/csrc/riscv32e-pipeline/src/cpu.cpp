#include <common.h>
#include <dpi-c.h>
#include <cpu.h>
static long long cycle = 0;
static long long npc_valid = 0;

long long reset_cycles;
long long ifu_counter;
long long ifu_valid_inst;
long long flush_inst;
long long ifu_jump_wait;

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
long long jump_re_wait;
long long jump_fail;
long long struct_load_risk;
long long struct_store_risk;
long long struct_ifu_risk;

long long access_time=1;
long long miss_penalty;
long long ifu_req;
long long icache_hit;
long long data_risk;
long long load_use;

int invalid_inst = 0;
void npctrap() {
  word_t a0 = get_regs(10);
  if(a0 == 0) {
    cycle -= reset_cycles;
    
    printf(ANSI_FMT("HIT GOOD TRAP\n", ANSI_FG_GREEN));
    
    
    printf("IFU FETCH INST: %lld (VALID INST: %lld, FLUSH INST: %lld)\n", ifu_counter, ifu_valid_inst, flush_inst);
    printf("\tFETCH DELAY: %.3f cycles(ARBITER WAIT: %.3f%%)\n\tWAIT DELAY: %.3f cycles\n\tJUMP RECOVER DELAY: %.3f cycles\n", 
      ifu_fetch_delay * 1.0 / npc_valid, struct_ifu_risk * 100.0 / ifu_fetch_delay,
      ifu_wait_delay * 1.0 / npc_valid, 
      ifu_jump_wait * 1.0 / npc_valid);

    printf("ICACHE:\n");
    printf("\tAMAT: %.3f cycles\n", (ifu_req + miss_penalty) * 1.0 / ifu_req);
    printf("\taccess_time: 1 cycle\n\tmiss_penalty: %.3f cycles\n\tAccesses: %lld\n\tHits: %lld\n\thit_rate: %.3f%%\n", miss_penalty * 1.0 / (ifu_req - icache_hit), ifu_req, icache_hit, icache_hit * 100.0 / ifu_req);

    printf("IDU INST TYPE:\n");
    // if(idu_alu + idu_load + idu_store + idu_jal + idu_jalr + idu_branch + idu_csr + idu_ecall + idu_mret != ifu_counter - jump_fail - 1) 
    //   printf(ANSI_FMT("IFU INST != IDU INST(%lld)\n", ANSI_FG_RED), idu_alu + idu_load + idu_store + idu_jal + idu_jalr + idu_branch + idu_csr + idu_ecall + idu_mret);
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

    printf("LSU LOAD DATA: %lld\tDELAY: %.3f(ARBITER WAIT: %.f%%)\n", load_counter, lsu_load_delay * 1.0 / load_counter, struct_load_risk * 100.0 / lsu_load_delay);
    printf("LSU STORE DATA: %lld\tDELAY: %.3f(ARBITER WAIT: %.f%%)\n", store_counter, lsu_store_delay * 1.0 / store_counter, struct_store_risk * 100.0 / lsu_store_delay);
    npc_state = NPC_GOODTRAP;

    printf("TOTAL CYCLES: %lld\tTOTAL INST: %lld\tIPC = %.3f\n", cycle, npc_valid, npc_valid * 1.0 / cycle);
    long long struct_risk = struct_load_risk + struct_store_risk + struct_ifu_risk;
    long long control_risk = ifu_jump_wait;
    long long total_risk = data_risk + (jump_fail * 2) + struct_risk;
    ifu_fetch_delay -= struct_ifu_risk;
    lsu_load_delay -= struct_load_risk;
    lsu_store_delay -= struct_store_risk;
    long long total_stall = ifu_fetch_delay + lsu_load_delay + lsu_store_delay + control_risk;
    printf("\tRISKS: struct(%.3f%%), data(%.3f%%), control(%.3f%%)\n", struct_risk * 100.0 / total_risk, data_risk * 100.0 / total_risk, control_risk * 100.0 / total_risk);
    printf("\tSTALL: inst fetch(%.3f%%), load & store(%.3f%%), risks(%.3f%%)\n", ifu_fetch_delay * 100.0 / total_stall, (lsu_load_delay + lsu_store_delay) * 100.0 / total_stall, control_risk * 100.0 / total_stall);
  }
  else {
    printf(ANSI_FMT("HIT BAD TRAP\n", ANSI_FG_RED));
    npc_state = NPC_BADTRAP;
  }
}

bool itrace_flag = true;

void tick() {
  cycle++;
  top->clock = 1; top->eval();
#ifdef CONFIG_WAVEFORM
   tfp->dump(contextp->time());
  contextp->timeInc(1);
#endif

  top->clock = 0; top->eval();
#ifdef CONFIG_WAVEFORM
   tfp->dump(contextp->time());
  contextp->timeInc(1);
#endif
#ifdef CONFIG_BOARD
  nvboard_update();
#endif
}

word_t diff_npc = 0;
word_t cur_pc = 0;
word_t cur_inst = 0;
void exec_once() {
  long long count = 0;
  while(get_wbu_valid() == 0) {
    tick();
    count++;
    if(count == 10000) {
      npc_state = NPC_ABORT;
      printf(ANSI_FMT("WBU STALL FOR TOO LONG\n", ANSI_FG_RED));
      printf("LAST PC: 0x%08x\tLAST INST: 0x%08x\n", cur_pc, cur_inst); 
      return ;
    }
  }
  if(get_isRet()) ftrace_ret(get_pc());
  if(get_isCall()) ftrace_call(get_pc(), get_npc());
  npc_valid++;
  if(itrace_flag) {
    if(get_pc() >= 0xa0000000 && get_pc() < 0xc0000000) inst_display(get_pc(), get_inst());
    if(invalid_inst) {
      printf("INVALID INST\n");
      npc_state = NPC_ABORT;
      return ;
    }
  }
  if(get_inst() == 0x00100073) {
    npctrap();
  }
  cur_pc = get_pc();
  cur_inst = get_inst();
  diff_npc = get_npc();
  tick();
}

void cpu_exec(uint64_t n) {
  switch (npc_state) {
    case NPC_BADTRAP: case NPC_ABORT: case NPC_GOODTRAP: case NPC_QUIT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state = NPC_RUNNING;
  }
  while(n--) {
    exec_once();
    if(npc_state != NPC_RUNNING) break;
    difftest_step(diff_npc, cur_pc);
  }

  if(npc_state == NPC_RUNNING) npc_state = NPC_STOP;
}
