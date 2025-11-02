#include <memory/memory.h>


uint8_t serial_port[8] = {0,0,0,0,0,0,0,0};


void update_serial_addr(uint32_t waddr, int wdata, char wmask){
	//assert(wmask == 0b00000001);
    serial_port[0] = (uint8_t)wdata;
    putc((uint8_t)wdata, stderr);
}

