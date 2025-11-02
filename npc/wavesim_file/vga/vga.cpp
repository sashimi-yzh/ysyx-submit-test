#include "vga.h"

uint8_t fb[FB_SIZE] = {0};


extern "C" uint32_t vga_read(uint32_t addr){
	return  ( (uint32_t)fb[addr+3] << 24
            | (uint32_t)fb[addr+2] << 16
            | (uint32_t)fb[addr+1] << 8
            | (uint32_t)fb[addr] );
}

//全写入四个字节
extern "C" void vga_write(uint32_t addr, uint32_t data){
	//printf("the addr is %x, data is %x\n", addr, data);
	fb[addr]   = (uint8_t) (data & 0x000000ff);
    fb[addr+1] = (uint8_t) ((data & 0x0000ff00) >> 8);
    fb[addr+2] = (uint8_t) ((data & 0x00ff0000) >> 16);
    fb[addr+3] = (uint8_t) ((data & 0xff000000) >> 24);
}
