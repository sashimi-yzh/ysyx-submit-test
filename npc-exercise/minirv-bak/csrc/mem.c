#include "common.h"
#include "mem.h"
#include "devices.h"
#include "trace.h"
uint32_t MEM[CONFIG_MSIZE>>2];
int pmem_read(int raddr){
	if(check_pmem_bound(raddr)){
		// 总是读取地址为`raddr & ~0x3u`的4字节返回
		mtrace(raddr, 0x0000, 0);
		return MEM(raddr);
	}else{
		uint32_t data;
		read_devices(raddr, &data);
		//Assert(read_devices(raddr, &data), "Out of bound ["FMT_WORD"] (read pmem)", raddr);
		return data;
	}
}

void pmem_write(int waddr, int wdata, char wmask) {
	if(check_pmem_bound(waddr)){
		// 总是读取地址为`raddr & ~0x3u`的4字节返回
		wmask=wmask<<(waddr&0x03);
		uint32_t sdata = MEM(waddr);
		// 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
		// `wmask`中每比特表示`wdata`中1个字节的掩码,
		// 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
		MEM(waddr)=(MEM(waddr)&0x00ffffff)|((((wmask>>3)&0x1)?((wdata>>24)&0xff):((MEM(waddr)>>24)&0xff))<<24);
		MEM(waddr)=(MEM(waddr)&0xff00ffff)|((((wmask>>2)&0x1)?((wdata>>16)&0xff):((MEM(waddr)>>16)&0xff))<<16);
		MEM(waddr)=(MEM(waddr)&0xffff00ff)|((((wmask>>1)&0x1)?((wdata>> 8)&0xff):((MEM(waddr)>> 8)&0xff))<< 8);
		MEM(waddr)=(MEM(waddr)&0xffffff00)|((((wmask>>0)&0x1)?((wdata>> 0)&0xff):((MEM(waddr)>> 0)&0xff))<< 0);
		mtrace(waddr, wmask, sdata);
	}else{
		write_devices(waddr, wdata);
		//Assert(write_devices(waddr, wdata), "Out of bound ["FMT_WORD"] (write pmem)", waddr);
	}	
}

bool check_pmem_bound(uint32_t addr){
	if(addr >= CONFIG_MBASE && addr < CONFIG_MBASE + CONFIG_MSIZE){
		return true;
	}else{
		return false;
	}
}