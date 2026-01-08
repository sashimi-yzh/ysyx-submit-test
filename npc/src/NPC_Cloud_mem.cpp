#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>//获得系统时间

#include "VysyxSoCFull.h"
#include <verilated.h>

#include "verilated_vcd_c.h"   //用来生成vcd
//#include <nvboard.h>   //启用nvboard

#include "npc.h"
#include "device.h"
#include "trace.h"

#include "sdb.h"

/*存储器*/
uint8_t pmem[NPC_PMEM_MSIZE];
uint8_t mrom[NPC_MROM_MSIZE];
uint8_t sram[NPC_SRAM_MSIZE];
uint8_t flash[NPC_FLASH_MSIZE];
uint8_t psram[NPC_PSRAM_MSIZE];
uint8_t sdram[NPC_SDRAM_MSIZE];

/*接入ysyxSoC*/
extern "C" void sdram_read(uint32_t addr, uint16_t *data) { 
	if ( addr <   NPC_SDRAM_MSIZE ) {	//访问sdram
		*data = *(uint16_t *)(sdram + (addr));
		//if(addr % 0x1000 == 0)printf("[sdram_read]0x%08x:0x%04x\n",addr + NPC_SDRAM_MBASE, *data);
		return;             
    }
	// Assert(0,"Memory address = 0x%04X is out of bound of sdram[0x%08X, %08X]"\
	// 		    , addr + NPC_SDRAM_MBASE, NPC_SDRAM_MBASE, NPC_SDRAM_MBASE + NPC_SDRAM_MSIZE -1);
}

extern "C" void sdram_write(uint32_t addr, uint16_t data, char wmask) { 
	if ( addr < NPC_SDRAM_MSIZE ) {	//访问sdram
		uint16_t current_value = *(uint32_t *)(sdram + (addr));
		uint16_t full_mask = 0;  //构建完整掩码
    	if (wmask & 0b00000001) full_mask |= 0x00FF;
    	if (wmask & 0b00000010) full_mask |= 0xFF00;
    	// if (wmask & 0b00000100) full_mask |= 0x00FF0000;
    	// if (wmask & 0b00001000) full_mask |= 0xFF000000;
		*(uint16_t *)(sdram + (addr)) = (current_value & ~full_mask) |(data & full_mask);
		//printf("[sdram_write]0x%08x:0x%04x\n",addr + NPC_SDRAM_MBASE, *(uint16_t *)(sdram + (addr)) );
		//if(addr % 0x1000 == 0) printf("[sdram_write]0x%08x:0x%04x,%d\n",addr + NPC_SDRAM_MBASE, data , wmask);
		return;             
    }
	Assert(0,"Memory address = 0x%08X is out of bound of sdram[0x%08X, %08X]"\
			    , addr + NPC_SDRAM_MBASE, NPC_SDRAM_MBASE, NPC_SDRAM_MBASE + NPC_SDRAM_MSIZE -1);
}

extern "C" void psram_read(int32_t addr, int32_t *data) { 
	if ( addr <   NPC_PSRAM_MSIZE ) {	//访问psram
		*data = *(uint32_t *)(psram + (addr));
		//printf("[psram_read]0x%08x:0x%08x\n",addr + NPC_PSRAM_MBASE, *data);
		return;             
    }
	// Assert(0,"Memory address = 0x%08X is out of bound of psram[0x%08X, %08X]"\
	// 		    , addr + NPC_PSRAM_MBASE, NPC_PSRAM_MBASE, NPC_PSRAM_MBASE + NPC_PSRAM_MSIZE -1);

}

extern "C" void psram_write(int32_t addr, int32_t data) { 
	if ( addr < NPC_PSRAM_MSIZE ) {	//访问psram
		*(uint8_t *)(psram + (addr)) = data;
		//printf("[psram_write]0x%08x:0x%08x\n",addr + NPC_PSRAM_MBASE, *(uint32_t *)(psram + (addr)));
		return;             
    }
	// Assert(0,"Memory address = 0x%08X is out of bound of psram[0x%08X, %08X]"\
	// 		    , addr + NPC_PSRAM_MBASE, NPC_PSRAM_MBASE, NPC_PSRAM_MBASE + NPC_PSRAM_MSIZE -1);

}

extern "C" void flash_read(int32_t addr, int32_t *data) {//flash会地址转换，去掉高8位和后2位
	if (addr >= 0 && addr < NPC_FLASH_MSIZE - 1) {//访问fllash
		*data = *(uint32_t *)(flash + addr);
		//if(addr >= 0x00000108) printf("[flash_read]0x%x:0x%08x\n",addr + NPC_FLASH_MBASE, *data);
		return;          
    }
	// Assert(0,"Memory address = 0x%08X is out of bound of flash[0x%08X, %08X]"\
	// 		    , addr + NPC_FLASH_MBASE, NPC_FLASH_MBASE, NPC_FLASH_MBASE + NPC_FLASH_MSIZE -1);

}  //140周期 + 138周期 = 278周期

extern "C" void mrom_read(int32_t addr, int32_t *data) { 
	if (addr >= NPC_MROM_MBASE && addr < NPC_MROM_MBASE + NPC_MROM_MSIZE - 1) {	//访问MROM
		*data = *(uint32_t *)(mrom + (addr - NPC_MROM_MBASE));
		return;                //ysyxSoC中延迟1周期
    }
	// Assert(0,"Memory address = 0x%08X is out of bound of mrom[0x%08X, %08X]"\
	// 		    , addr, NPC_MROM_MBASE, NPC_MROM_MBASE + NPC_MROM_MSIZE -1);
}

void pmem_write(int awaddr, int wdata, char wmask) {
	if (awaddr == SERIAL_PORT) {//串口的输出功能
		//printf("[%x]=%x wdata=%c %d\n", npc.dnpc, top->io_inst, wdata & 0xFF, wdata & 0xFF);
		putchar(wdata & 0xFF); 
		fflush(stdout); 
    	return;

	}
	uint32_t current_value = *paddr_read(awaddr);
    //构建完整掩码
    uint32_t full_mask = 0;
    if (wmask & 0b00000001) full_mask |= 0x000000FF;
    if (wmask & 0b00000010) full_mask |= 0x0000FF00;
    if (wmask & 0b00000100) full_mask |= 0x00FF0000;
    if (wmask & 0b00001000) full_mask |= 0xFF000000;
	
    
    *paddr_read(awaddr) = (current_value & ~full_mask) |(wdata & full_mask);
	
	if(NPC_MTRACE) mtrace_write_display(awaddr);
	//printf("peme_write:awaddr=0X%08X,w_value=0X%08X\n", awaddr, *paddr_read(awaddr));
}

uint32_t pmem_read(uint32_t raddr) {
	// if(raddr < NPC_MBASE || raddr >= NPC_MBASE + NPC_MSIZE - 1) {//不在内存范围的指令
	// 	//printf("pmem_read [0X%08X] ",raddr);
	// 	//printf("pc=0X%08X inst=0X%08X dnpc=0X%08X\n", npc.pc, npc.inst, npc.dnpc);
	// 	return 0;
	// }
   
	if(NPC_MTRACE) mtrace_read_display(raddr);
	// printf("pmem_read [0X%08X]\n",raddr);
	// printf("pmem_read [0X%08X]: 0X%08X\n",raddr, *paddr_read(raddr));
	return *paddr_read(raddr);
}


uint32_t *paddr_read(uint32_t addr) {
	if (addr >= NPC_PMEM_MBASE && addr < NPC_PMEM_MBASE + NPC_PMEM_MSIZE - 1) {	//访问PEME
		return (uint32_t *)(pmem + (addr - NPC_PMEM_MBASE));
    }	
	// if (addr >= NPC_SRAM_MBASE && addr < NPC_SRAM_MBASE + NPC_SRAM_MSIZE - 1) {	//访问SRAM
	// 	return (uint32_t *)(sram + (addr - NPC_SRAM_MBASE));
    // }
	// if (addr >= NPC_MROM_MBASE && addr < NPC_MROM_MBASE + NPC_MROM_MSIZE - 1) {	//访问MROM
	// 	return (uint32_t *)(mrom + (addr - NPC_MROM_MBASE));
    // }
	if (addr >= NPC_FLASH_MBASE && addr < NPC_FLASH_MBASE + NPC_FLASH_MSIZE - 1) {//访问fllash
		return (uint32_t *)(flash + (addr - NPC_FLASH_MBASE));
    }
	// if (addr >= NPC_SDRAM_MBASE && addr < NPC_SDRAM_MBASE + NPC_SDRAM_MSIZE - 1) {//访问sdram
	// 	return (uint32_t *)(sdram + (addr - NPC_SDRAM_MBASE));
    // }
	Assert(0,"Memory address = 0x%08X is out of bound of pm`em", addr);
	return NULL;  // 不在内存范围的指令
}

void default_peme(){
	uint32_t *pmem_write = (uint32_t *)pmem;
	pmem_write[0] = 0x00440413; // addi s0, s0, 4
	//pmem_write[1] = 0x00412783; // lw	a5,4(sp)
	//pmem_write[2] = 0x00812403; // lw	s0,8(sp)
	pmem_write[1] = 0x10cb0b13; // addi s6, s6, 268  
	pmem_write[2] = 0x00448493; // addi s1, s1, 4
	pmem_write[3] = 0x238b8b93; // addi s7, s7, 568
	pmem_write[4] = 0x00100073;  //ebreak指令,结束仿真
	// for(int i = 0; i < 5; i++){
	// 	printf("npc_peme:[0x%08X]: 0x%08X\n", NPC_MROM_MBASE + i * 4, *paddr_read(NPC_MROM_MBASE + i * 4));
	// }
}

void default_flash(){  //char-test指令
	uint32_t *pmem_write = (uint32_t *)flash;
	pmem_write[0] = 0x100007B7; // lui a5, 0x10000
	pmem_write[1] = 0x04100713; // addi a4, zero, 0x41
	//pmem_write[2] = 0x00E78023; // sb a4, 0(a5)
	pmem_write[2] = 0x00448493; // addi s1, s1, 4
	//pmem_write[3] = 0x0000006F; // jal zero, 0
	pmem_write[3] = 0x00100073;  //ebreak指令,结束仿真

	for(int i = 0; i < 4; i++){
		printf("npc_flash:[0x%08X]: 0x%08X\n", NPC_FLASH_MBASE + i * 4, *paddr_read(NPC_FLASH_MBASE + i * 4));
	}
	printf("\n");
}


long load_img(const char* img_file){//导入镜像文件，保存到存储器
	
	memset(&npc, 0, sizeof(CPU_state));//初始化寄存器全为0
	Log("Initialize general-purpose registers.");

	if(npc_without_soc == false){ //make ARCH=riscv32e-ysyxSoC run 初始化flash和sdram
		// memset(mrom, 0, NPC_MROM_MSIZE);//初始化MROM全为0
		//Log("physical MROM area [0X%08X,0X%08X].", NPC_MROM_MBASE, NPC_MROM_MBASE + NPC_MROM_MSIZE -1);
		memset(flash, 0, NPC_FLASH_MSIZE);//初始化flash存储器全为0
		Log("Flash: [0X%08X,0X%08X].", NPC_FLASH_MBASE, NPC_FLASH_MBASE + NPC_FLASH_MSIZE -1);
		// memset(psram, 0, NPC_PSRAM_MSIZE);//初始化psram存储器全为0
		// Log("physical psram area [0X%08X,0X%08X].", NPC_PSRAM_MBASE, NPC_PSRAM_MBASE + NPC_PSRAM_MSIZE -1);
		memset(sdram, 0, NPC_SDRAM_MSIZE);//初始化sdram存储器全为0
		Log("SDRAM: [0X%08X,0X%08X].", NPC_SDRAM_MBASE, NPC_SDRAM_MBASE + NPC_SDRAM_MSIZE -1);
		npc.pc = npc.dnpc = NPC_FLASH_MBASE;//初始化pc,指向flash
		Log("Initialize PC to 0x%x.", NPC_FLASH_MBASE);
	} else { //make ARCH=riscv32e-npc run 没有soc,指令数据导入到pmem,0x8000_0000作为复位时的PC值.
		memset(pmem, 0, NPC_PMEM_MSIZE);//初始化存储器全为0
		Log("physical memory area [0X%08X,0X%08X].", NPC_PMEM_MBASE, NPC_PMEM_MBASE + NPC_PMEM_MSIZE -1);
		npc.pc = npc.dnpc = NPC_PMEM_MBASE;//初始化pc
		Log("Initialize PC to 0x%x.", NPC_PMEM_MBASE);
	}

	if(img_file == NULL){//没有导入镜像文件，则用默认指令
		Log("No image file provided. Use the default build-in image into memory.");
		default_flash();
		return 0;
	}

    FILE *fp = fopen(img_file, "rb");

    if (fp == NULL) {//打开镜像文件失败，则用默认指令
        Log("Failed to open image file: %s. Use the default build-in image into memory.", img_file);
        default_flash();
        return 0;
    }
	
	fseek(fp, 0, SEEK_END);
	long file_size = ftell(fp); // 获取文件大小

	//assert((file_size <= NPC_FLASH_MSIZE) && "out of bound of pmem"); // 检查不超出内存

	fseek(fp, 0, SEEK_SET);

	int bytes_read = file_size;

	if(npc_without_soc == false){ //make ARCH=riscv32e-ysyxSoC run
	
		if (file_size >= NPC_FLASH_MSIZE) {
    		//printf("Warning: File too large, truncating to %d bytes\n", NPC_FLASH_MSIZE);
    		bytes_read = NPC_FLASH_MSIZE;
		}

		int ret = fread(flash, 1, bytes_read, fp); // 读取文件到内存(flash)

		assert( (ret == bytes_read) && "failed fread!" ); // 确保完整读取

		Log("Loaded %d bytes from %s to Flash[0x%08X, 0x%08X].",
           bytes_read, img_file, 
           NPC_FLASH_MBASE, 
           NPC_FLASH_MBASE + bytes_read);


	} else { //make ARCH=riscv32e-npc run 没有soc,指令数据导入到pmem,0x8000_0000作为复位时的PC值.
		int ret = fread(pmem, 1, file_size, fp); // 读取文件到内存

		assert( (ret == file_size) && "failed fread!" ); // 确保完整读取

		Log("Loaded %ld bytes from %s to memory peme[0x%08X, 0x%08lX].",
           file_size, img_file, 
           NPC_PMEM_MBASE, 
           NPC_PMEM_MBASE + file_size - 1);

	}
	fclose(fp);
	//default_flash();

	// for(int i = 0; i*4 < bytes_read; i++){
	// 	if(*paddr_read(NPC_FLASH_MBASE + i * 4) == 0x00000000){continue;	}
	// 	printf("[npc_flash]0x%08X: 0x%08X\n", NPC_FLASH_MBASE + i * 4, *paddr_read(NPC_FLASH_MBASE + i * 4));
	// }
	
	// for(int a = 0x3025bf9b; a <=  0x3025bf9b + 0x3b0; a=a+4){
	// 	printf("npc_flash:[0x%08X]: 0x%08X\n", a, *paddr_read(a));
	// }
	// assert(0);
	
	return bytes_read;
}

