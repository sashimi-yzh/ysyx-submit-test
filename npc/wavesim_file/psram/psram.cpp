#include "psram.h"

uint8_t psram[PSRAM_SIZE] = {0};

extern "C" uint32_t psram_read(uint32_t addr){
	//if(addr != (addr & 0xfffffffc)){
    //  printf("ERROR!!!!!!!!!!!!!!!! the raddr is %x\n", addr);
    //}
	//addr = addr - 0x80000000;
	//addr = addr & 0xfffffffc;//默认4字节对齐
	return 	( (uint32_t)psram[addr+3] << 24 
			| (uint32_t)psram[addr+2] << 16
            | (uint32_t)psram[addr+1] << 8
            | (uint32_t)psram[addr] );
}


extern "C" void psram_write(uint32_t addr, uint32_t data, uint8_t bytes_to_write){//注意最后一项决定了应该写入几个字节
	//printf("the write addr is %x, the write data is %x\n",addr, data);
	//addr = addr - 0x80000000;
	//psram[addr] = data;
	//addr = addr & 0xfffffffc;//未默认4字节对齐
	//if(addr != (addr & 0xfffffffc)){
	//	printf("ERROR!!!!!!!!!!!!!!!! the addr is %x\n", addr);
	//}
	if(bytes_to_write == 4){//写入四个字节
		psram[addr] = (uint8_t) (data & 0x000000ff);
		psram[addr+1] = (uint8_t) ((data & 0x0000ff00) >> 8);
		psram[addr+2] = (uint8_t) ((data & 0x00ff0000) >> 16);
		psram[addr+3] = (uint8_t) ((data & 0xff000000) >> 24);
	}
	else if(bytes_to_write == 2){
		psram[addr] = (uint8_t) (data & 0x000000ff);
		psram[addr+1] = (uint8_t) ((data & 0x0000ff00) >> 8);
	}
	else if(bytes_to_write == 1){
		psram[addr] = (uint8_t) (data & 0x000000ff);
	}
	else
		printf("Error occurred at psram_write in wavesim_file/psram/psram.cpp!\n");
}
