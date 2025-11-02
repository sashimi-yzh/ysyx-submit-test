#include <trace/trace.h>

//dtrace相关
dtrace ringbuf_dtrace[50];
int32_t ringbuf_dtrace_head = 0;
int32_t ringbuf_dtrace_tail = 0;

void dtrace_record(int32_t pc, int32_t inst, int32_t addr, const char* name){
    ringbuf_dtrace[ringbuf_dtrace_tail].dtrace_pc = pc;
    ringbuf_dtrace[ringbuf_dtrace_tail].dtrace_inst = inst;
    ringbuf_dtrace[ringbuf_dtrace_tail].dtrace_addr = addr;
    strncpy(ringbuf_dtrace[ringbuf_dtrace_tail].dtrace_device, name, 64);
	//ringbuf_dtrace[ringbuf_dtrace_tail].dtrace_name = name;
    ringbuf_dtrace_tail = (ringbuf_dtrace_tail + 1) % 50;
    if(ringbuf_dtrace_head == ringbuf_dtrace_tail)
        ringbuf_dtrace_head = (ringbuf_dtrace_head + 1) % 50;
    return;
}

void display_dtrace(){
    printf("\033[33m---------------------------------dtrace----------------------------------\n");
    if(ringbuf_dtrace_head <= ringbuf_dtrace_tail)
        for(int i = ringbuf_dtrace_head; i < ringbuf_dtrace_tail; ++i)
            printf("At %#8.8x (inst %#8.8x), addr: %#8.8x, device: %s\n", ringbuf_dtrace[i].dtrace_pc, ringbuf_dtrace[i].dtrace_inst, ringbuf_dtrace[i].dtrace_addr, ringbuf_dtrace[i].dtrace_device);
    else{
        for(int i = ringbuf_dtrace_head; i < 50; ++i)
            printf("At %#8.8x (inst %#8.8x), addr: %#8.8x, device: %s\n", ringbuf_dtrace[i].dtrace_pc, ringbuf_dtrace[i].dtrace_inst, ringbuf_dtrace[i].dtrace_addr, ringbuf_dtrace[i].dtrace_device);
        for(int i = 0; i < ringbuf_dtrace_tail; ++i)
            printf("At %#8.8x (inst %#8.8x), addr: %#8.8x, device: %s\n", ringbuf_dtrace[i].dtrace_pc, ringbuf_dtrace[i].dtrace_inst, ringbuf_dtrace[i].dtrace_addr, ringbuf_dtrace[i].dtrace_device);
    }
    printf("-------------------------------------------------------------------------\033[0m\n");
}

