#include <trace/trace.h>
#include <memory/paddr.h>

//mtrace相关
mtrace ringbuf_mtrace[50];
int32_t ringbuf_mtrace_head = 0;
int32_t ringbuf_mtrace_tail = 0;

void mtrace_record(int32_t pc, int32_t addr, int32_t inst){
    ringbuf_mtrace[ringbuf_mtrace_tail].mtrace_pc = pc;
    ringbuf_mtrace[ringbuf_mtrace_tail].mtrace_addr = addr;
    ringbuf_mtrace[ringbuf_mtrace_tail].mtrace_inst = inst;
    ringbuf_mtrace_tail = (ringbuf_mtrace_tail + 1) % 50;
    if(ringbuf_mtrace_head == ringbuf_mtrace_tail)
        ringbuf_mtrace_head = (ringbuf_mtrace_head + 1) % 50;
    return;
}

void display_mtrace(){
    printf("\033[33m---------------------------------mtrace----------------------------------\n");
    if(ringbuf_mtrace_head <= ringbuf_mtrace_tail)
        for(int i = ringbuf_mtrace_head; i < ringbuf_mtrace_tail; ++i)
            printf("At %#8.8x (inst %#8.8x), addr: %#8.8x\n", ringbuf_mtrace[i].mtrace_pc, ringbuf_mtrace[i].mtrace_inst, ringbuf_mtrace[i].mtrace_addr);
    else{
        for(int i = ringbuf_mtrace_head; i < 50; ++i)
            printf("At %#8.8x (inst %#8.8x), addr: %#8.8x\n", ringbuf_mtrace[i].mtrace_pc, ringbuf_mtrace[i].mtrace_inst, ringbuf_mtrace[i].mtrace_addr);
        for(int i = 0; i < ringbuf_mtrace_tail; ++i)
            printf("At %#8.8x (inst %#8.8x), addr: %#8.8x\n", ringbuf_mtrace[i].mtrace_pc, ringbuf_mtrace[i].mtrace_inst, ringbuf_mtrace[i].mtrace_addr);
    }
    printf("-------------------------------------------------------------------------\033[0m\n");
}

