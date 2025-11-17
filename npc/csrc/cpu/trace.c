#include <cpu/cpu.h>
#include <cpu/top.h>
#include <cpu/difftest.h>
#include <npc.h>
#include <ringbuffer.h>


#ifdef CONFIG_PC_MAX_REPEAT
static uint32_t pc_repeat_count = 0;
static paddr_t  pc_old = 0;
#endif
bool wps_diff();

#ifdef CONFIG_ITRACE
char itrace_buff [ITRACE_SIZE];
RingBuffer *rb = NULL;

void init_disasm();
void init_itrace(){
    init_disasm();
    rb = RingBuffer_create(LOG_BUFSIZE);
}

void itrace_once(Decode * s) {
    // 32 match inst name in capstone define
    char inst_name[32];
    char *p = itrace_buff;
    p +=  (npc_state.state != NPC_ABORT) ? 
        snprintf(p, ITRACE_SIZE,"    " FMT_WORD ":", s->pc):
        snprintf(p, ITRACE_SIZE," -->" FMT_WORD ":", s->pc);
    int ilen = sizeof(word_t);
    int i;
    uint32_t inst = s->inst;
    
    uint8_t *inst_ptr = (uint8_t *)(&inst);
    for (i = ilen - 1; i >= 0; i --) {
        p += snprintf(p, 4, " %02x", *(inst_ptr+i));
    }

    int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
    int space_len = ilen_max - ilen;
    if (space_len < 0) space_len = 0;
    space_len = space_len * 3 + 1;
    memset(p, ' ', space_len);
    p += space_len;
    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte,char* inst);
    disassemble(p, itrace_buff + LOG_BUFSIZE - p, s->pc, inst_ptr, ilen,inst_name);
    int len = strlen(itrace_buff);
    memset(itrace_buff+len,' ',ITRACE_SIZE-len);
    itrace_buff[ITRACE_SIZE-1] = '\n';
    if(RingBuffer_available(rb)<ITRACE_SIZE){
    RingBuffer_commit_read(rb,ITRACE_SIZE);
    }
    Assert(ITRACE_SIZE>(len+1),"length of itrace excceed\n");
    RingBuffer_put(rb,itrace_buff,ITRACE_SIZE);
    memset(itrace_buff,0,ITRACE_SIZE);
}
#endif
void trace_and_difftest(Decode* s, vaddr_t dnpc){

    #ifdef CONFIG_PC_MAX_REPEAT
        if (s->pc != pc_old) {pc_old = s->pc; pc_repeat_count = 0;}
        else pc_repeat_count++;
        if (pc_repeat_count >= CONFIG_PC_MAX_REPEAT) {
            npc_state.state = NPC_ABORT;
            npc_state.halt_pc = s->pc;
            Log("pc %0.8x repeat %d times!!!",s->pc, CONFIG_PC_MAX_REPEAT);
        }
    #endif

    #ifdef CONFIG_DIFFTEST
    difftest_step(s->pc,dnpc);
    #endif
    #ifdef CONFIG_ITRACE
    itrace_once(s);
    if ((npc_state.state!=NPC_RUNNING)) {
        char temp_buf [LOG_BUFSIZE];
        RingBuffer_get(rb,temp_buf,LOG_BUFSIZE);
        log_write("%s", temp_buf); 
    }
    #endif
    #ifdef CONFIG_WATCHPOINT
    if (npc_state.state != NPC_END && wps_diff()){

        npc_state.state = NPC_STOP;
    }
    #endif
    if (dnpc != s->pc) clear_top_lsu_state();
    return;
}