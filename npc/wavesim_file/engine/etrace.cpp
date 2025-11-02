#include "engine.h"

//etrace相关
int32_t ringbuf_etrace_pc[50];
int32_t etrace_pc_tmp = 0;
int32_t ringbuf_etrace_head = 0;
int32_t ringbuf_etrace_tail = 0;

extern "C" void etrace_record_pc(int32_t pc){
    etrace_pc_tmp = pc;
}

extern "C" void etrace_record(void){
#ifdef CONFIG_ETRACE
    ringbuf_etrace_pc[ringbuf_etrace_tail] = etrace_pc_tmp;
    ringbuf_etrace_tail = (ringbuf_etrace_tail + 1) % 50;
    if(ringbuf_etrace_head == ringbuf_etrace_tail)
        ringbuf_etrace_head = (ringbuf_etrace_head + 1) % 50;
#endif
    return;
}

void display_etrace(){
    printf("\033[33m---------------------------------etrace----------------------------------\n");
    if(ringbuf_etrace_head <= ringbuf_etrace_tail)
        for(int i = ringbuf_etrace_head; i < ringbuf_etrace_tail; ++i)
            printf("At %#8.8x, type: ecall\n", ringbuf_etrace_pc[i]);
    else{
        for(int i = ringbuf_etrace_head; i < 50; ++i)
            printf("At %#8.8x, type: ecall\n", ringbuf_etrace_pc[i]);
        for(int i = 0; i < ringbuf_etrace_tail; ++i)
            printf("At %#8.8x, type: ecall\n", ringbuf_etrace_pc[i]);
    }
    printf("-------------------------------------------------------------------------\033[0m\n");
}

