#include <memory/socmem.h>
#include <isa.h>



static uint8_t mrom[CONFIG_MROMSIZE] PG_ALIGN = {};
static uint8_t sram[CONFIG_SRAMSIZE] PG_ALIGN = {};
static uint8_t flash[CONFIG_FLASHSIZE] PG_ALIGN = {};
static uint8_t psram[CONFIG_PSRAMSIZE] PG_ALIGN = {};
static uint8_t sdram[CONFIG_SDRAMSIZE] PG_ALIGN = {};

const char *socmem_name[] = {
    "MROM",
    "SRAM",
    "FLASH",
    "PSRAM",
    "SDRAM",
};

paddr_t socmem_base[] = {
    CONFIG_MROMBASE,
    CONFIG_SRAMBASE,
    CONFIG_FLASHBASE,
    CONFIG_PSRAMBASE,
    CONFIG_SDRAMBASE,
};

word_t socmem_size[] = {
    CONFIG_MROMSIZE,
    CONFIG_SRAMSIZE,
    CONFIG_FLASHSIZE,
    CONFIG_PSRAMSIZE,
    CONFIG_SDRAMSIZE,
};

static void socmem_out_of_bound(paddr_t addr) {
    panic("address = " FMT_PADDR " is out of bound of socmem at pc = " FMT_WORD, addr, cpu.pc);
}

uint8_t* socmem_guest_to_host(paddr_t addr) {
    socmem_type_t dev = (socmem_type_t)SOCMEM_DEV_NUM;
    for (int i = 0; i < SOCMEM_DEV_NUM; i++) {
        if (addr >= SOCMEM_LEFT(i) && addr <= SOCMEM_RIGHT(i)) {
            dev = (socmem_type_t)i;
            break;
        }
    }
    if(dev == SOCMEM_DEV_NUM) socmem_out_of_bound(addr);

    uint8_t *membase_ptr =  dev == MROM ? mrom : 
                            dev == SRAM ? sram :
                            dev == FLASH ? flash :
                            dev == PSRAM ? psram : 
                            dev == SDRAM ? sdram : NULL;
    IFDEF(CONFIG_RT_CHECK, assert(membase_ptr != NULL));
    
    int32_t offset = 0;
    offset = dev == MROM ? addr - CONFIG_MROMBASE :
             dev == SRAM ? addr - CONFIG_SRAMBASE :
             dev == FLASH ? addr - CONFIG_FLASHBASE :
             dev == PSRAM ? addr - CONFIG_PSRAMBASE :
             dev == SDRAM ? addr - CONFIG_SDRAMBASE : -1;
    IFDEF(CONFIG_RT_CHECK, assert(offset >= 0));

    return membase_ptr + offset;
}

static word_t socmem_host_read(void* addr, int len){
    switch(len){
        case 1: return *(uint8_t  *)addr;
        case 2: return *(uint16_t *)addr;
        case 4: return *(uint32_t *)addr;
        IFDEF(CONFIG_ISA64, case 8: return *(uint64_t *)addr);
        IFDEF(CONFIG_RT_CHECK, default: assert(0));
    }
	return 0;
}

word_t socmem_read(paddr_t addr, int len){

    if(addr >= 0x10000000 && addr <= 0x10000000 + 0x1000){
        return 0;  //UART 
    }else if(addr >= 0x02000000 && addr <= 0x02000040 + 0x10000){
        return 0;  //CLINT
    }else if(addr >= 0x21000000 && addr <= 0x21000000 + 0x1200000){
        return 0;  //VGA
    }
    return socmem_host_read(socmem_guest_to_host(addr), len);
}

void socmem_host_write(void* addr, int len, word_t data){
    switch(len){
        case 1: *(uint8_t  *)addr = data; return;
        case 2: *(uint16_t *)addr = data; return;
        case 4: *(uint32_t *)addr = data; return;
        IFDEF(CONFIG_ISA64, case 8: *(uint64_t *)addr = data; return);
        IFDEF(CONFIG_RT_CHECK, default: assert(0));
    }
}

void socmem_write(paddr_t addr, int len, word_t data){
    if(addr >= 0x10000000 && addr <= 0x10000000 + 0x1000){
        return;  //UART 
    }else if(addr >= 0x21000000 && addr <= 0x21000000 + 0x1200000){
        return;  //VGA
    }

    socmem_host_write(socmem_guest_to_host(addr), len, data);
}



#ifdef CONFIG_SOC_DIFFTEST

void init_mem(){
    memset(mrom, 0, CONFIG_MROMSIZE);
    memset(sram, 0, CONFIG_SRAMSIZE);
    memset(flash, 0, CONFIG_FLASHSIZE);
    memset(psram, 0, CONFIG_PSRAMSIZE);
    memset(sdram, 0, CONFIG_SDRAMSIZE);
    Log("Use YSYX SoC memory model: MROM, SRAM, FLASH, PSRAM, SDRAM");
}

#endif 
