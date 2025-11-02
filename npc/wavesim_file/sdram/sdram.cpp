#include "sdram.h"

uint8_t sdram[SDRAM_SIZE] = {0};


//对于地址addr,应该读出2*addr~(2*addr+1)处相邻的两个8bit
extern "C" uint32_t sdram_read(uint32_t addr){
	//printf("the addr is %x\n", addr);
	return  ((uint32_t)sdram[2*addr+1] << 8) | 
			(uint32_t)sdram[2*addr];
}

//对于地址addr,应该对2*addr~(2*addr+1)处的数据依mask进行写入
extern "C" void sdram_write(uint32_t addr, uint32_t data, uint8_t mask){
	if((mask & 0b00000001) == 0){//注意这里的括号不能少,因为==优先级高于&
		sdram[2*addr] = (uint8_t)(data & 0x000000ff);
	}
		//sdram[addr] = (sdram[addr] & 0xff00) + (data & 0x00ff);
	if((mask & 0b00000010) == 0){
		sdram[2*addr+1] = (uint8_t)((data & 0x0000ff00) >> 8);
	}
		//sdram[addr] = (sdram[addr] & 0x00ff) + (data & 0xff00);
	if(mask > 3)
		printf("mask error in sdram_write!\n");
}



uint32_t sdram_read_sdb(uint32_t addr){
	return  ( (uint32_t)sdram[addr+3] << 24
            | (uint32_t)sdram[addr+2] << 16
            | (uint32_t)sdram[addr+1] << 8
            | (uint32_t)sdram[addr] );

}
