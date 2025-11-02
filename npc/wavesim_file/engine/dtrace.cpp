#include "engine.h"
#include <memory/memory.h>


//dtrace相关
int32_t ringbuf_dtrace_pc[50];
const char* ringbuf_dtrace_device[50];
int32_t ringbuf_dtrace_head = 0;
int32_t ringbuf_dtrace_tail = 0;


const char* fetch_device_by_addr(uint32_t addr){
	if(addr >= 0x02000000 && addr <= 0x0200ffff)//CLINT	
		return "CLINT";
	else if(addr >= 0x10000000 && addr <= 0x10000fff)//uart
		return "uart";
	else if(addr >= 0x10002000 && addr <= 0x1000200f)//gpio
		return "GPIO";
	else if(addr >= 0x10011000 && addr <= 0x10011007)//keyboard
		return "keyboard";
	else if(addr >= 0x21000000 && addr <= 0x211fffff)//vga
		return "vga";
	else//暂不考虑其他设备
		return NULL;
}




void dtrace_record(int32_t pc, int32_t addr){
#ifdef CONFIG_DTRACE
	const char *ret = fetch_device_by_addr(addr);
	if(ret){//忽略NULL
    	ringbuf_dtrace_pc[ringbuf_dtrace_tail] = pc;
    	ringbuf_dtrace_device[ringbuf_dtrace_tail] = ret;
    	ringbuf_dtrace_tail = (ringbuf_dtrace_tail + 1) % 50;
    	if(ringbuf_dtrace_head == ringbuf_dtrace_tail)
        	ringbuf_dtrace_head = (ringbuf_dtrace_head + 1) % 50;
	}
#endif
    return;
}

void display_dtrace(){
    printf("\033[33m---------------------------------dtrace----------------------------------\n");
    if(ringbuf_dtrace_head <= ringbuf_dtrace_tail)
        for(int i = ringbuf_dtrace_head; i < ringbuf_dtrace_tail; ++i)
            printf("At %#8.8x, device: %s\n", ringbuf_dtrace_pc[i], ringbuf_dtrace_device[i]);
    else{
        for(int i = ringbuf_dtrace_head; i < 50; ++i)
            printf("At %#8.8x, device: %s\n", ringbuf_dtrace_pc[i], ringbuf_dtrace_device[i]);
        for(int i = 0; i < ringbuf_dtrace_tail; ++i)
            printf("At %#8.8x, device: %s\n", ringbuf_dtrace_pc[i], ringbuf_dtrace_device[i]);
    }
    printf("-------------------------------------------------------------------------\033[0m\n");
}

