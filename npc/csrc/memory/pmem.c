#include<stdio.h>
#include "include/mydpi.h"
#include "include/debug.h"
#include "include/macro.h"
#include "memory/pmem.h"
#include "cpu/cpu.h"
#include "include/autoconf.h"
void difftest_skip_ref();
uint32_t mrom[MROM_SIZE]={0};
uint32_t flash[FLASH_SIZE]={0};
uint8_t psram[PSRAM_SIZE]={0};
uint8_t sdram0[SDRAM_SIZE]={0};
uint8_t sdram1[SDRAM_SIZE]={0};
uint8_t sdram2[SDRAM_SIZE]={0};
uint8_t sdram3[SDRAM_SIZE]={0};
extern "C" void sdram_read(int32_t id,int32_t addr, int32_t *data){
    uint32_t raddr=(uint32_t)addr<<1;
    if(raddr>=SDRAM_SIZE){
        data[0]=0;
        return ;
    }
    uint8_t *ptr=(uint8_t*)data;
    if(id==0){
        ptr[0]=sdram0[raddr];
        ptr[1]=sdram0[raddr+1];
    }else if(id==1){
        ptr[0]=sdram1[raddr];
        ptr[1]=sdram1[raddr+1];
    }else if(id==2){
        ptr[0]=sdram2[raddr];
        ptr[1]=sdram2[raddr+1];
    }else if(id==3){
        ptr[0]=sdram3[raddr];
        ptr[1]=sdram3[raddr+1];
    }
    if(id>1)
        printf("Read sdram at addr=0x%08x,data=%08x,id=%d\n",raddr,data[0],id);
#ifdef CONFIG_MTRACE_SDRAM
    Log("Read sdram at addr=0x%08x,data=%08x",raddr,data[0]);
#endif
}
extern "C" void sdram_write(int32_t id,int32_t addr, int32_t data,int32_t dqm){
    uint32_t raddr=(uint32_t)addr<<1;
    if(raddr>=SDRAM_SIZE){
        return;
    }
    if(id==0){
        if((dqm&0x0001)==0) sdram0[raddr]=data&0x00ff;
        if((dqm&0x0002)==0) sdram0[raddr+1]=(data>>8)&0xff;
    }else if(id==1){
        if((dqm&0x0001)==0) sdram1[raddr]=data&0x00ff;
        if((dqm&0x0002)==0) sdram1[raddr+1]=(data>>8)&0xff;
    }else if(id==2){
        if((dqm&0x0001)==0) sdram2[raddr]=data&0x00ff;
        if((dqm&0x0002)==0) sdram2[raddr+1]=(data>>8)&0xff;
    }else if(id==3){
        if((dqm&0x0001)==0) sdram3[raddr]=data&0x00ff;
        if((dqm&0x0002)==0) sdram3[raddr+1]=(data>>8)&0xff;
    }
    if(id>1)
        printf("Write sdram at addr=0x%08x,data=%08x,dqm=%d,id=%d\n",raddr,data,dqm,id);
#ifdef CONFIG_MTRACE_SDRAM
    Log("Write sdram at addr=0x%08x,data=%08x,dqm=%x",raddr,data,dqm);
#endif
}
extern "C" void psram_read(int32_t addr, int32_t *data){
    uint32_t raddr=(uint32_t)addr;
    if(raddr>=PSRAM_SIZE){
        data[0]=0;
        return ;
    }
    uint8_t *ptr=(uint8_t*)data;
    ptr[0]=psram[raddr];
    ptr[1]=psram[raddr+1];
    ptr[2]=psram[raddr+2];
    ptr[3]=psram[raddr+3];
#ifdef CONFIG_MTRACE_PSRAM
    Log("Read psram at addr=0x%08x,data=%08x",raddr,data[0]);
#endif
}
extern "C" void psram_write(int32_t addr, int32_t data,int32_t count){
    uint32_t raddr=(uint32_t)addr;
    if(raddr>=PSRAM_SIZE){
        return;
    }
    psram[raddr+count]=(uint8_t)data;
#ifdef CONFIG_MTRACE_PSRAM
    Log("Write psram at addr=0x%08x,data=%08x",raddr+count,data);
#endif
}
extern "C" void flash_read(int32_t addr, int32_t *data) {
    uint32_t raddr=((uint32_t)addr)>>2;
    if(raddr>=FLASH_SIZE){
        data[0]=0;
        return ;
    }
    data[0]=flash[raddr];
#ifdef CONFIG_MTRACE_FLASH
    Log("Read flash at addr=0x%08x,data=%08x",raddr,data[0]);
#endif
}
extern "C" void mrom_read(int32_t addr, int32_t *data){
    uint32_t raddr=(addr-MROM_START)>>2;
    if(raddr>=MROM_SIZE){
        data[0]=0;
        return ;
    }
    data[0]=mrom[raddr];
#ifdef CONFIG_MTRACE_FLASH
    Log("Read mrom at addr=0x%08x,data=%08x",addr,data[0]);
#endif
}
uint64_t get_time(){
    static struct timeval tv;
    static uint64_t bool_time=0;
    if(bool_time==0){
        gettimeofday(&tv, NULL);
        bool_time=(uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
    }
    gettimeofday(&tv,NULL);
    uint64_t now=(uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;

    return now-bool_time;
}
extern "C" void paddr_read(int32_t addr,int32_t *data){
    if(addr>=0x80000000&&addr<=0x9fffffff){
        psram_read(addr&0x00fffffc,data);
    }
}
extern "C" void paddr_write(int32_t addr, int32_t data, int32_t mask) {
    if(addr>=0x80000000&&addr<=0x9fffffff){
        int32_t paddr;
        paddr=addr&0x00fffffc;
        if((mask&0b1)==1)
            psram_write(paddr,data&0xff,0);
        if((mask&0b10)==0b10)
            psram_write(paddr,(data&0xff00)>>8,1);
        if((mask&0b100)==0b100)
            psram_write(paddr,(data&0xff0000)>>16,2);
        if((mask&0b1000)==0b1000)
            psram_write(paddr,(data&0xff000000)>>24,3);
    }else if(addr==0x10000000)
        putc((char)data&0xff,stderr);
}

