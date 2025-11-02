#include "engine.h"


//itrace相关
int32_t ringbuf_itrace_pc[50];
int32_t ringbuf_itrace_inst[50];
int32_t ringbuf_itrace_head = 0;
int32_t ringbuf_itrace_tail = 0;

extern "C" void itrace_record(int32_t pc, int32_t inst){
#ifdef CONFIG_ITRACE
    ringbuf_itrace_pc[ringbuf_itrace_tail] = pc;
    ringbuf_itrace_inst[ringbuf_itrace_tail] = inst;
    ringbuf_itrace_tail = (ringbuf_itrace_tail + 1) % 50;
    if(ringbuf_itrace_head == ringbuf_itrace_tail)
        ringbuf_itrace_head = (ringbuf_itrace_head + 1) % 50;
#endif
    return;
}

void display_itrace(){
    printf("\033[33m---------------------------------itrace----------------------------------\n");
    if(ringbuf_itrace_head <= ringbuf_itrace_tail)
        for(int i = ringbuf_itrace_head; i < ringbuf_itrace_tail; ++i)
            printf("At %#8.8x, inst: %#8.8x\n", ringbuf_itrace_pc[i], ringbuf_itrace_inst[i]);
    else{
        for(int i = ringbuf_itrace_head; i < 50; ++i)
            printf("At %#8.8x, inst: %#8.8x\n", ringbuf_itrace_pc[i], ringbuf_itrace_inst[i]);
        for(int i = 0; i < ringbuf_itrace_tail; ++i)
            printf("At %#8.8x, inst: %#8.8x\n", ringbuf_itrace_pc[i], ringbuf_itrace_inst[i]);
    }
    printf("-------------------------------------------------------------------------\033[0m\n");
}


