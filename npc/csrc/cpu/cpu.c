#include "cpu/cpu.h"
#include "memory/pmem.h"
#include "include/macro.h"
#include "include/autoconf.h"
#include "include/debug.h"
#define ANSI_FG_GREEN "\e[1;32m"
#define ANSI_FG_RED "\e[1;31m"
#define ANSI_NONE "\e[0m"
#define MAX_INST_TO_PRINT 10

TOP_NAME* dut=NULL;
VerilatedContext*contextp=NULL;
VerilatedVcdC* tfp=NULL;
#ifdef RISCV32E_NPC
NPC_state npc_state={NPC_RUNNING,0,PSRAM_START};
CPU_state cpu_dut={{0},PSRAM_START};
#else
NPC_state npc_state={NPC_RUNNING,0,FLASH_START};
CPU_state cpu_dut={{0},FLASH_START};
#endif
uint32_t cpu_pc=0,cpu_dnpc=0,inst;
static char logbuf[128]={};
static char iringbuf[16][128]={};
static int iringbuf_index=0;
static bool g_print_step=false;
//ftrace
static char ftrace_buf[1024][128]={};
static int ftrace_cnt=0;
static int depth=0;
//CPI
static uint64_t DIC=0;//Dynamic instruction count
static uint64_t DCC=0;//Dynamic cycles count
//Debug info
static Debug_info exu_debug,lsu_debug,wbu_debug;
static void debug_update(){
    if(DLSU_WBU_fire){
        wbu_debug=lsu_debug;
        wbu_debug.skip_ref=0;
        if(DLSU_ISMEM){
            wbu_debug.skip_ref=1;
            if((DLSU_ADDR>=0xa0000000&&DLSU_ADDR<=0xbfffffff)||
               (DLSU_ADDR>=0x80000000&&DLSU_ADDR<=0x9fffffff)||
               (DLSU_ADDR>=0x30000000&&DLSU_ADDR<=0x3fffffff)||
               (DLSU_ADDR>=0x0f000000&&DLSU_ADDR<=0x0f001fff))
                wbu_debug.skip_ref=0;
        }
    }
    if(DEXU_LSU_fire){
        lsu_debug=exu_debug;
        lsu_debug.dnpc=DEXU_REDIRECT?DEXU_AUX:exu_debug.dnpc;
    }
    if(DIDU_EXU_fire){
        exu_debug.pc=DIDU_PC;
        exu_debug.inst=DIDU_INST;
        exu_debug.dnpc=DIDU_PC+4;
        exu_debug.skip_ref=false;
    }
}
void get_cpu_state(CPU_state *cpu_dut){
    int i;
    for(i=0;i<16;i++){
        cpu_dut->gpr[i]=cpu_gpr(i);
    }
    cpu_dut->pc=cpu_pc;
}
static void trace_and_difftest(uint32_t pc){
    if(g_print_step){IFDEF(CONFIG_ITRACE,puts(logbuf));}
    IFDEF(CONFIG_ITRACE,strcpy(iringbuf[iringbuf_index],logbuf);
        iringbuf_index=(iringbuf_index+1)%16);
    IFDEF(CONFIG_DIFFTEST, difftest_step(pc, cpu_pc));
}
void iringbuf_print(){
    int i;
    int index;
    printf("Instruction Ring Buffer Trace:\n");
    for(i=0;i<16;i++){
        index=(iringbuf_index+i)%16;
        if(i==15){//这个下标指向下一个
            printf(" --> %s\n",iringbuf[index]);
        }else {
            printf("     %s\n",iringbuf[index]);
        }
    }
}
extern "C" void npc_trap(){
    IFDEF(CONFIG_DIFFTEST,difftest_skip_ref();) 
    npc_state.state=NPC_END;
    npc_state.halt_pc=cpu_pc;//?
    npc_state.halt_ret=cpu_gpr(10);
    printf("ret=%d\n",npc_state.halt_ret);
}
int is_exit_status_bad() {
    printf("Dynamic instruction count=%lu\ncycles count=%lu\nCycles Per Instruction=%.6f\ninstructions Per Cycle=%.6f\n",
            DIC,DCC,(double)DCC/(double)DIC,(double)DIC/(double)DCC);
    int good=(npc_state.state==NPC_END&&npc_state.halt_ret==0)||
        (npc_state.state==NPC_QUIT);
    return !good;
}

void single_cycle(){
    DCC++;
    IFDEF(USE_NVBOARD,nvboard_update();)
    if(!dut->reset)
        debug_update();
    dut->clock=1;dut->eval();
    IFDEF(CONFIG_VCD_TRACE,
            if(contextp->time()<1000000){tfp->dump(contextp->time());}
            contextp->timeInc(1);)
    dut->clock=0;dut->eval();
    IFDEF(CONFIG_VCD_TRACE,
            if(contextp->time()<1000000){tfp->dump(contextp->time());}
            contextp->timeInc(1);)
}
void reset(int n){
    dut->reset=1;
    dut->clock=0;dut->eval();
    while(n-->0)single_cycle();
    dut->reset=0;dut->eval();
    DIC = 0;
    DCC = 0;
    exu_debug={};
    lsu_debug={};
    wbu_debug={};
}
static void itrace_record(uint32_t pc,uint32_t inst){
#ifdef CONFIG_ITRACE
    char *p=logbuf;
    p+=snprintf(p,sizeof(logbuf),"0x%08x %08x",pc,inst);
    memset(p,' ',1);
    p+=1;
    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
    disassemble(p,logbuf+sizeof(logbuf)-p,pc,(uint8_t *)(&inst),4);
#endif
}
static void ftrace_record(uint32_t pc,uint32_t dnpc,int is_return){
    int i;int index1=-1,index2=-1;
    char space[32];
    if(!is_return) depth++;
    int space_len=depth>31?31:depth;
    if(is_return) {depth--; if(depth<0) depth=0;}
    memset(space,' ',space_len);
    space[space_len]='\0';
    for(i=0;i<func_cnt;i++){
        if(pc>=func_list[i].low&&pc<=func_list[i].high){
            index1=i;break;
        }
    }
    for(i=0;i<func_cnt;i++){
        if(dnpc>=func_list[i].low&&dnpc<=func_list[i].high){
            index2=i;break;
        }
    }
    if(is_return){
        sprintf(ftrace_buf[ftrace_cnt],"0x%08x:%sret [%s] to [%s]",pc,space,index1>=0?func_list[index1].name:"???",index2>=0?func_list[index2].name:"???"); 
    }else{
        sprintf(ftrace_buf[ftrace_cnt],"0x%08x:%scall [%s@0x%08x], from [%s]",pc,space,index2>=0?func_list[index2].name:"???",dnpc,index1>=0?func_list[index1].name:"???");  
    }
    ftrace_cnt=(ftrace_cnt+1)%1024;
}
static void ftrace_call(uint32_t pc,uint32_t inst,uint32_t dnpc){
    int opcode=BITS(inst,6,0);
    int funct3=BITS(inst,14,12);
    int rd=BITS(inst,11,7);
    if(opcode==0b01101111){
       if(rd==1)ftrace_record(pc,dnpc,0); 
    }else if(opcode==0b01100111&&funct3==0){
        if(rd==1)ftrace_record(pc,dnpc,0);
        else if(BITS(inst,19,15)==1) ftrace_record(pc,dnpc,1);
    }

}

void ftrace_print(){
    int i;
    printf("print ftrace\n");
    for(i=0;i<ftrace_cnt;i++){
        printf("id:%s\n",ftrace_buf[i]);
    }
}
static void execute(uint64_t n){
    for(;n>0;n--){
        while(DWBU_IFU_fire==0){
            single_cycle();
            if(npc_state.state!=NPC_RUNNING)return;
        }
        cpu_pc=wbu_debug.pc;
        inst=wbu_debug.inst;
        int trap_info=DWBU_TRAP_INFO;
        if((trap_info>>2)==0b00111)
            npc_trap();
        cpu_dnpc=(trap_info&0x6)?DWBU_TRAP_DNPC:wbu_debug.dnpc;
        uint32_t old_cpu_pc=cpu_pc;
#ifdef CONFIG_DIFFTEST
        int skip_ref=wbu_debug.skip_ref;
        uint32_t csr_addr=DWBU_CSR_ADDR;
        if((trap_info&0x1)&&
           (csr_addr==0x0||csr_addr==0x1||
            csr_addr==0x6||csr_addr==0x7)){
            skip_ref=1;
        }
#endif
        IFDEF(CONFIG_FTRACE,ftrace_call(cpu_pc,inst,cpu_dnpc);)
        IFDEF(CONFIG_ITRACE,itrace_record(cpu_pc,inst);)
         /* 完成WBU_IFU_fire */
        single_cycle();
        cpu_pc=cpu_dnpc;
        DIC++;
        if(npc_state.state!=NPC_RUNNING)return;
#ifdef CONFIG_DIFFTEST
        get_cpu_state(&cpu_dut);
        if(skip_ref)
            difftest_skip_ref();
#endif
        trace_and_difftest(old_cpu_pc);
        if(npc_state.state!=NPC_RUNNING)return;
    }
}
void cpu_exec(uint64_t n){
    g_print_step=(n<MAX_INST_TO_PRINT);
    switch (npc_state.state) {
        case NPC_END:case NPC_QUIT:case NPC_ABORT:
            printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
            return;
        default:npc_state.state=NPC_RUNNING;
    }
    execute(n);
    switch(npc_state.state){
        case NPC_RUNNING:npc_state.state=NPC_STOP;break;
        case NPC_END:case NPC_ABORT: 
            Log("npc: %s at pc = 0x%08x \n%s\n",
                (npc_state.state==NPC_ABORT? ANSI_FG_RED "ABORT" ANSI_NONE:
                (npc_state.halt_ret==0?ANSI_FG_GREEN"HIT GOOD TRAP" ANSI_NONE:
                ANSI_FG_RED "HITBAD TRAP" ANSI_NONE)),
                npc_state.halt_pc,logbuf);
            if(npc_state.state==NPC_ABORT)
                iringbuf_print();

    }
}
