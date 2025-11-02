#include "engine.h"


//mtrace相关
int32_t ringbuf_mtrace_pc[50];
int32_t ringbuf_mtrace_addr[50];
int32_t ringbuf_mtrace_head = 0;
int32_t ringbuf_mtrace_tail = 0;

extern "C" void mtrace_record(int32_t pc, int32_t addr){
#ifdef CONFIG_MTRACE
    ringbuf_mtrace_pc[ringbuf_mtrace_tail] = pc;
    ringbuf_mtrace_addr[ringbuf_mtrace_tail] = addr;
    ringbuf_mtrace_tail = (ringbuf_mtrace_tail + 1) % 50;
    if(ringbuf_mtrace_head == ringbuf_mtrace_tail)
        ringbuf_mtrace_head = (ringbuf_mtrace_head + 1) % 50;
#endif
	//在涉及访存时调用dtrace
	dtrace_record(pc, addr);
    return;
}

void display_mtrace(){
    printf("\033[33m---------------------------------mtrace----------------------------------\n");
    if(ringbuf_mtrace_head <= ringbuf_mtrace_tail)
        for(int i = ringbuf_mtrace_head; i < ringbuf_mtrace_tail; ++i)
            printf("At %#8.8x, addr: %#8.8x\n", ringbuf_mtrace_pc[i], ringbuf_mtrace_addr[i]);
    else{
        for(int i = ringbuf_mtrace_head; i < 50; ++i)
            printf("At %#8.8x, addr: %#8.8x\n", ringbuf_mtrace_pc[i], ringbuf_mtrace_addr[i]);
        for(int i = 0; i < ringbuf_mtrace_tail; ++i)
            printf("At %#8.8x, addr: %#8.8x\n", ringbuf_mtrace_pc[i], ringbuf_mtrace_addr[i]);
    }
    printf("-------------------------------------------------------------------------\033[0m\n");
}
