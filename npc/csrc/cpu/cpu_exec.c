#include <cpu/cpu.h>
#include <cpu/top.h>
#include <cpu/difftest.h>
#include <npc.h>
#include <ringbuffer.h>

#include <nvboard.h>
void nvboard_bind_all_pins(Top* _top);

void perf_event_display();
void trace_and_difftest(Decode* s, vaddr_t dnpc);

CPU_state cpu = {};

VerilatedContext* contextp = NULL;
extern char* perf_file;
static uint64_t cycles = 0;


void device_update();

void step() {
    IFDEF(CONFIG_NPC_CHISEL,top()->clock = 0);
    IFDEF(CONFIG_NPC_VERILOG,top()->clk = 0);
    top()->eval(); 
    contextp->timeInc(1);
    IFDEF(CONFIG_WAVETRACE_FST, tfp()->dump(contextp->time())); // 记录当前时间点波形
    IFDEF(CONFIG_NPC_CHISEL,top()->clock = 1);
    IFDEF(CONFIG_NPC_VERILOG,top()->clk = 1); 
    top()->eval(); 
    contextp->timeInc(1);
    cycles++;
    IFDEF(CONFIG_WAVETRACE_FST, tfp()->dump(contextp->time())); // 记录当前时间点波形
    IFDEF(CONFIG_NVBOARD,nvboard_update(););
}

void reset(int n) { 
    IFDEF(CONFIG_NPC_VERILOG,top()->rst = 1);
    IFDEF(CONFIG_NPC_CHISEL,top()->reset = 1);
    cycles = 0;
    while (n --) { step(); } 
    IFDEF(CONFIG_NPC_CHISEL,top()->reset = 0);
    IFDEF(CONFIG_NPC_VERILOG,top()->rst = 0);

}
void sync_cpu(){
    for (int i=0;i<gpr_size;i++)
        cpu.gpr[i] = top_gpr(i);
    cpu.pc = top_pc();
    return;
}

void init_cpu(int argc ,char** argv){

    // Construct a VerilatedContext to hold simulation time, etc.
    contextp = new VerilatedContext;

    // Pass arguments so Verilated code can see them, e.g. $value$plusargs
    // This needs to be called before you create any model
    contextp->commandArgs(argc, argv);
    
    IFDEF(CONFIG_NVBOARD,nvboard_bind_all_pins(top()));
    IFDEF(CONFIG_NVBOARD,nvboard_init());
    
    // Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
    reset(10);
    #ifdef CONFIG_WATCH_TOP
    watch_top();
    #endif


    sync_cpu();
}

void assert_fail_msg() {
  isa_reg_display();
}


int check_halt(){
    printf("npc: %s at pc = %.8x\n", top_gpr(10)?"***HIT BAD TRAP***":"***HIT GOOD TRAP***",top_pc() );
    return top_gpr(10);
}




void exec_once(Decode *s){
    s->pc = top_pc();
    step();
    #ifdef CONFIG_WATCH_TOP
    watch_top();
    #endif

    sync_cpu();
    s->inst = top_inst();
    if (top_halt()){
        NPCTRAP(top_pc(),top_gpr(10));
    }
    return;
}




void execute(u_int64_t n){
    Decode s;
    for(;n>0;n--){
        exec_once(&s);
        trace_and_difftest(&s,cpu.pc);
        if (npc_state.state != NPC_RUNNING) break;
        IFDEF(CONFIG_DEVICE,device_update()); 
    }
}

void free_cpu(){
    // Final model cleanup
    top()->final();
    IFDEF(CONFIG_WAVETRACE_FST, tfp()->close());
    // Destroy model
    delete_top();
    IFDEF(CONFIG_NVBOARD,nvboard_quit());
}

int cpu_exec(uint64_t n){
    switch (npc_state.state) {
        case NPC_END: case NPC_ABORT: case NPC_QUIT:
            printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
            return 0;
        default: npc_state.state = NPC_RUNNING;
    }
    // watch_top();
    execute(n);    
    switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      Log("npc: %s at pc = " FMT_WORD,
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          npc_state.halt_pc);
        perf_event_display();
    // fall through
    case NPC_QUIT: break;;
    }
    return 0;
}


void perf_event_display(){
    FILE *fp = stdout;
    printf("perf_file: %s\n",perf_file);
    if (perf_file) fp = fopen(perf_file,"w");
    fprintf(fp,"******* Performance counter *******\n");
    fprintf(fp,"Cycles: \t %ld\n", cycles);
    top_perf_event_display(fp);
    fprintf(fp,"******* End Performance counter *******\n");
    if (perf_file) fclose(fp);
} 