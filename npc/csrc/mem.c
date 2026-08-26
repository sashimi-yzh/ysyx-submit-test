#include "common.h"
#include "mem.h"
#include "devices.h"
#include "trace.h"


uint32_t MEM[CONFIG_SRAMSIZE>>2];
uint32_t MROM[CONFIG_MROMSIZE>>2];
uint32_t FLASH[CONFIG_FLASHSIZE>>2];
uint8_t PSRAM[CONFIG_PSRAMSIZE];
uint16_t SDRAM00[CONFIG_SDRAMSIZE>>3];
uint16_t SDRAM01[CONFIG_SDRAMSIZE>>3];
uint16_t SDRAM10[CONFIG_SDRAMSIZE>>3];
uint16_t SDRAM11[CONFIG_SDRAMSIZE>>3];


int pmem_read(int raddr){
	if(raddr >= CONFIG_SRAMBASE && raddr < CONFIG_SRAMBASE + CONFIG_SRAMSIZE){
		return CPUSRAMTop[(raddr - CONFIG_SRAMBASE)>>2];
	}else if(raddr >= CONFIG_MROMBASE && raddr < CONFIG_MROMBASE + CONFIG_MROMSIZE){
		return MROM(raddr);
	}else if(raddr >= CONFIG_FLASHBASE && raddr < CONFIG_FLASHBASE + CONFIG_FLASHSIZE){
		return FLASH(raddr);
	}else if(raddr >= CONFIG_PSRAMBASE && raddr < CONFIG_PSRAMBASE + CONFIG_PSRAMSIZE){
		return (uint32_t)PSRAM(raddr);
	}else if(raddr >= CONFIG_SDRAMBASE && raddr < CONFIG_SDRAMBASE + CONFIG_SDRAMSIZE){
		return sdram_read_word(raddr);
	}else{
		return 0x2b2b2b2b;
	}
}

void pmem_write(int waddr, int wdata, char wmask) {
	if(check_sram_bound(waddr)){
		wmask=wmask<<(waddr&0x03);
		wdata=wdata<<(waddr&0x03)*8;
		uint32_t sdata = MEM(waddr);
		// `wmask`中每比特表示`wdata`中1个字节的掩码,
		// 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
		

		MEM(waddr)=(MEM(waddr)&0x00ffffff) | ((((wmask>>3)&0x1) ? ((wdata>>24)&0xff) : ((MEM(waddr)>>24)&0xff))<<24);
		MEM(waddr)=(MEM(waddr)&0xff00ffff) | ((((wmask>>2)&0x1) ? ((wdata>>16)&0xff) : ((MEM(waddr)>>16)&0xff))<<16);
		MEM(waddr)=(MEM(waddr)&0xffff00ff) | ((((wmask>>1)&0x1) ? ((wdata>> 8)&0xff) : ((MEM(waddr)>> 8)&0xff))<< 8);
		MEM(waddr)=(MEM(waddr)&0xffffff00) | ((((wmask>>0)&0x1) ? ((wdata>> 0)&0xff) : ((MEM(waddr)>> 0)&0xff))<< 0);
		mtrace(waddr, wmask, sdata);
	}else{
		write_devices(waddr, wdata);
		//Assert(write_devices(waddr, wdata), "Out of bound ["FMT_WORD"] (write pmem)", waddr);
	}	
}

bool check_sram_bound(uint32_t addr){
	if(addr >= CONFIG_SRAMBASE && addr < CONFIG_SRAMBASE + CONFIG_SRAMSIZE){
		return true;
	}else{
		return false;
	}
}
bool check_mrom_bound(uint32_t addr){
	if(addr >= CONFIG_MROMBASE && addr < CONFIG_MROMBASE + CONFIG_MROMSIZE){
		return true;
	}else{
		return false;
	}
}
// bool check_flash_bound(uint32_t addr){
// 	if(addr >= CONFIG_FLASHBASE && addr < CONFIG_FLASHBASE + CONFIG_FLASHSIZE){
// 		return true;
// 	}else{
// 		return false;
// 	}
// }

extern "C" void flash_read(int32_t addr, int32_t *data) {
	// Log("READ FLASH: addr = " FMT_WORD " val = " FMT_WORD, addr, FLASH(addr + CONFIG_FLASHBASE));
	*data = FLASH(addr + CONFIG_FLASHBASE);
}
extern "C" void mrom_read(int32_t addr, int32_t *data) {
	*data = MROM(addr);
}
extern void psram_read(int raddr, int count, int* rdata) {
	// Log("READ FLASH: addr = " FMT_WORD " val = " FMT_WORD, addr, FLASH(addr + CONFIG_FLASHBASE));
	// *data = FLASH(addr + CONFIG_FLASHBASE);
	*rdata = (int32_t)PSRAM((((uint32_t)raddr + (uint32_t)count)%1024)+((CONFIG_PSRAMBASE + raddr)& ~0x3ff));
}
extern void psram_write(int waddr, int count, int wdata){
	// Log("WRITE PSRAM: addr = " FMT_WORD " val = " FMT_WORD " count = " FMT_WORD, waddr, wdata, count);
	PSRAM((((uint32_t)waddr + (uint32_t)count)%1024)+((CONFIG_PSRAMBASE + waddr)& ~0x3ff)) = wdata & 0xff;
	// Log("WRITE FLASH: addr = " FMT_WORD " val = " FMT_WORD, addr, data);
	// FLASH(addr + CONFIG_FLASHBASE) = data;
}
extern void sdram_read(int raddr, int count, int* rdata, int sel) {
	// Log("READ FLASH: addr = " FMT_WORD " val = " FMT_WORD, addr, FLASH(addr + CONFIG_FLASHBASE));
	// *data = FLASH(addr + CONFIG_FLASHBASE);
	switch (sel & 0x3) {
		case 0x0: *rdata = ((int32_t)SDRAM00((uint32_t)raddr + CONFIG_SDRAMBASE + count*4)); break;
		case 0x1: *rdata = ((int32_t)SDRAM01((uint32_t)raddr + CONFIG_SDRAMBASE + count*4)); break;
		case 0x2: *rdata = ((int32_t)SDRAM10((uint32_t)raddr + CONFIG_SDRAMBASE + count*4)); break;
		case 0x3: *rdata = ((int32_t)SDRAM11((uint32_t)raddr + CONFIG_SDRAMBASE + count*4)); break;
		default: Assert(0, "Invalid sel value for sdram_read");
	}
}

uint32_t sdram_read_word(uint32_t raddr) {
	uint16_t dataL,dataH;
	uint32_t bank = (raddr >> 11) & 0x3;
	uint32_t bank_ext = (raddr >> 13) & 0x1;
	uint32_t row = (raddr>>14)&0x1fff;
	uint32_t col = (raddr>>2)&0x1ff;
	uint32_t wire_addr = (col << 2) | (bank << (2 + 9)) |( row << (2 + 9 + 2));

	if(!bank_ext){
		sdram_read(wire_addr, 0, (int*)&dataL, 0x0);
		sdram_read(wire_addr, 0, (int*)&dataH, 0x1);
	}else{
		sdram_read(wire_addr, 0, (int*)&dataL, 0x2);
		sdram_read(wire_addr, 0, (int*)&dataH, 0x3);
	}
	return (uint32_t)((uint32_t)dataL | ((uint32_t)dataH << 16));
}

extern void sdram_write(int waddr, int count, int wdata, int sel){
	uint8_t wenH = (wdata >> 31)&0x1;
	uint8_t wenL = (wdata >> 30)&0x1;
	uint16_t wda = wdata & 0xffff;
	uint16_t source;
	switch(sel & 0x3){
		case 0x0:
			source = SDRAM00((uint32_t)(waddr + CONFIG_SDRAMBASE + count*4));
			// Log("WRITE SDRAM00: addr = " FMT_WORD " val = " FMT_WORD " count = " FMT_WORD " WH=%d WL=%d at pc = " FMT_WORD, waddr, wdata, count, wenH,wenL, cpu.pc);
			SDRAM00((uint32_t)waddr + CONFIG_SDRAMBASE + count*4) = (0xff00 & ((wenH)?(wda):(source))) | (0x00ff & ((wenL)?(wda):(source))) ;
			break;
		case 0x1:
			source = SDRAM01((uint32_t)(waddr + CONFIG_SDRAMBASE + count*4));
			// Log("WRITE SDRAM01: addr = " FMT_WORD " val = " FMT_WORD " count = " FMT_WORD " WH=%d WL=%d at pc = " FMT_WORD, waddr, wdata, count, wenH,wenL, cpu.pc);
			SDRAM01((uint32_t)waddr + CONFIG_SDRAMBASE + count*4) = (0xff00 & ((wenH)?(wda):(source))) | (0x00ff & ((wenL)?(wda):(source))) ;
			break;
		case 0x2:
			source = SDRAM10((uint32_t)(waddr + CONFIG_SDRAMBASE + count*4));
			// Log("WRITE SDRAM10: addr = " FMT_WORD " val = " FMT_WORD " count = " FMT_WORD " WH=%d WL=%d at pc = " FMT_WORD, waddr, wdata, count, wenH,wenL, cpu.pc);
			SDRAM10((uint32_t)waddr + CONFIG_SDRAMBASE + count*4) = (0xff00 & ((wenH)?(wda):(source))) | (0x00ff & ((wenL)?(wda):(source))) ;
			break;
		case 0x3:
			source = SDRAM11((uint32_t)(waddr + CONFIG_SDRAMBASE + count*4));
			// Log("WRITE SDRAM11: addr = " FMT_WORD " val = " FMT_WORD " count = " FMT_WORD " WH=%d WL=%d at pc = " FMT_WORD, waddr, wdata, count, wenH,wenL, cpu.pc);
			SDRAM11((uint32_t)waddr + CONFIG_SDRAMBASE + count*4) = (0xff00 & ((wenH)?(wda):(source))) | (0x00ff & ((wenL)?(wda):(source))) ;
			break;
		default: Assert(0, "Invalid sel value for sdram_write");
	}
	// Log("WRITE PSRAM: addr = " FMT_WORD " val = " FMT_WORD " count = " FMT_WORD, waddr, wdata, count);
	// PSRAM((((uint32_t)waddr + (uint32_t)count)%1024)+((CONFIG_PSRAMBASE + waddr)& ~0x3ff)) = wdata & 0xff;
	// Log("WRITE FLASH: addr = " FMT_WORD " val = " FMT_WORD, addr, data);
	// FLASH(addr + CONFIG_FLASHBASE) = data;
}
