#include <trace/trace.h>

//etrace相关
int32_t ringbuf_etrace_pc[50];
int32_t ringbuf_etrace_head = 0;
int32_t ringbuf_etrace_tail = 0;


void etrace_record(int32_t pc){
    ringbuf_etrace_pc[ringbuf_etrace_tail] = pc;
    ringbuf_etrace_tail = (ringbuf_etrace_tail + 1) % 50;
    if(ringbuf_etrace_head == ringbuf_etrace_tail)
        ringbuf_etrace_head = (ringbuf_etrace_head + 1) % 50;
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

