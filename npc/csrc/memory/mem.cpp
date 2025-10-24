#include <mem.h>
#include <common.h>
#include <circuit.h>
#include <wave.h>
#include <timer.h>
#include <utils.h>
#include <device.h>
#include <lightsss.h> // 确保路径正确



extern bool is_skip_diff;
static uint64_t timer = 0;

extern uint64_t light_cycle_num;
extern LightSSS lightsss;




static uint8_t *pmem = NULL;
#define IN_PMEM(paddr) paddr >= CONFIG_MBASE && paddr <= CONFIG_MBASE + CONFIG_MSIZE


static uint8_t *flash = NULL;
static uint8_t *sdram_chip0 = NULL;
static uint8_t *sdram_chip1 = NULL;
static uint8_t *sdram_chip2 = NULL;
static uint8_t *sdram_chip3 = NULL;
#define IN_FLASH(paddr) paddr >= FLASH_BASE && paddr <= FLASH_BASE + FLASH_SIZE
#define IN_SDRAM(paddr) paddr >= SDRAM_BASE && paddr <= SDRAM_BASE + SDRAM_SIZE


static uint8_t *psram = NULL;
static uint8_t *mrom = NULL;
#define IN_PSRAM(paddr) paddr >= PSRAM_BASE && paddr <= PSRAM_BASE + PSRAM_SIZE
#define IN_MROM(paddr) paddr >= MROM_BASE && paddr <= MROM_BASE + MROM_SIZE


uint8_t* guest_to_host(paddr_t paddr) {
    if (IN_PMEM(paddr)) {
        return pmem + paddr - CONFIG_MBASE;
    }
    else if(IN_FLASH(paddr)){
        return flash + paddr - FLASH_BASE;
    }
    /*下面两个实际上最终版本不需要访存*/
    else if(IN_PSRAM(paddr)){
        return psram + paddr - PSRAM_BASE;
    }
    else if(IN_MROM(paddr)){
        return mrom + paddr - MROM_BASE;
    }
    else{
        printf("Address out of bounds: %#x\n", paddr);
        assert(0);
    }
}

uint8_t* guest_to_host_sdram(paddr_t paddr, int id) {
    if(id == 0)
        if(IN_SDRAM(paddr))
            return sdram_chip0 + paddr - SDRAM_BASE;
        else
            assert(0);
    else if(id == 1)
        if(IN_SDRAM(paddr))
            return sdram_chip1 + paddr - SDRAM_BASE;
        else
            assert(0);
    else if(id == 2)
        if(IN_SDRAM(paddr))
            return sdram_chip2 + paddr - SDRAM_BASE;
        else
            assert(0);
    else if(id == 3)
        if(IN_SDRAM(paddr))
            return sdram_chip3 + paddr - SDRAM_BASE;
        else
            assert(0);
    else{
        printf("sdram Address out of bounds: %#x\n", paddr);
        assert(0);
    }
}


















void init_psram(){
    psram = (uint8_t *)malloc(PSRAM_SIZE);
    assert(psram);
    printf("=============为YSYXSOC初始化PSRAM成功(确实需要初始化psram吗?)=============\n");
    printf("=========地址为%x~%x==========\n", PSRAM_BASE, PSRAM_BASE + PSRAM_SIZE);
}
void init_mrom(){
    mrom = (uint8_t *)malloc(MROM_SIZE);
    assert(mrom);
    printf("=============为YSYXSOC初始化MROM成功(确实需要初始化mrom吗?)=============\n");
    printf("=========地址为%x~%x==========\n", MROM_BASE, MROM_BASE + MROM_SIZE);
}

extern "C" void mrom_read(int32_t addr, int32_t *data) {
    int32_t addr_processed = addr & (~3);
    *data = *(uint32_t *)guest_to_host(addr_processed);
}

extern "C" void psram_read(int32_t addr, int32_t *rdata) {
	int32_t addr_processed = addr + PSRAM_BASE;
	*rdata = *(int32_t *)guest_to_host(addr_processed);
    // printf("psram_read addr = %#x, data = %#x\n", addr_processed, *rdata);
}

extern "C" void psram_write(int32_t addr, int32_t wdata, char wstrb) {
	int32_t addr_processed = addr + PSRAM_BASE;
	fflush(stdout);
	switch (wstrb)
	{
	case 0b0001:
		*(uint8_t *)guest_to_host(addr_processed) = wdata;
		// printf("psram_write addr = %#x , data = %#x ,wstrb = %d\n",addr_processed, wdata, wstrb);
		break;
	case 0b0011:
		*(uint16_t *)guest_to_host(addr_processed) = wdata;
		// printf("psram_write addr = %#x , data = %#x ,wstrb = %d\n",addr_processed, wdata, wstrb);
		break;
	case 0b1111:
		*(uint32_t *)guest_to_host(addr_processed) = wdata;
		// printf("psram_write addr = %#x , data = %#x ,wstrb = %d\n",addr_processed, wdata, wstrb);
		break;
	default:
		break;
	}
    // printf("psram_write addr = 0x%x, data = 0x%x, wstrb = 0x%x\n", addr, wdata, wstrb);
}









void init_pmem() {
    pmem = (uint8_t *)malloc(CONFIG_MSIZE);
    assert(pmem);
    printf("=============为NPC初始化PMEM成功=============\n");
    printf("=========地址为%x~%x==========\n", CONFIG_MBASE, CONFIG_MBASE + CONFIG_MSIZE);
}

void init_flash() {
    flash = (uint8_t *)malloc(FLASH_SIZE);
    assert(flash);
    printf("=============为YSYXSOC初始化FLASH成功=============\n");
    printf("=========地址为%x~%x==========\n", FLASH_BASE, FLASH_BASE + FLASH_SIZE);
}

void init_sdram(){
    sdram_chip0 = (uint8_t *)malloc(SDRAM_SIZE);
    sdram_chip1 = (uint8_t *)malloc(SDRAM_SIZE);
    sdram_chip2 = (uint8_t *)malloc(SDRAM_SIZE);
    sdram_chip3 = (uint8_t *)malloc(SDRAM_SIZE);
    assert(sdram_chip0);
    assert(sdram_chip1);
    assert(sdram_chip2);
    assert(sdram_chip3);
    printf("=============为YSYXSOC初始化SDRAM成功=============\n");
    printf("=========地址为%x~%x==========\n", SDRAM_BASE, SDRAM_BASE + SDRAM_SIZE);
}




/*YSYXSOC内存操作相关函数*/
extern "C" void flash_read(int32_t addr, int32_t *data) {
    int32_t addr_processed = addr + FLASH_BASE;
    *data = *(uint32_t *)guest_to_host(addr_processed);
    // printf("flash_read addr = %#x, data = %#x\n", addr_processed, *data);
}

extern "C" void sdram_read(int id, int bank_addr, int row_addr, int col_addr, int *rdata){
	int32_t addr_processed = (bank_addr * 512 * 2) + (row_addr * 512 * 2 * 4) + (col_addr * 2) + SDRAM_BASE;
	*rdata = *(uint16_t *)guest_to_host_sdram(addr_processed, id);
    // printf("sdram_read addr = %#x, data = %#x\n", addr_processed, *rdata);
}

extern "C" void sdram_write(int id, int bank_addr, int row_addr, int col_addr, int wdata, char wstrb) {
	int addr_processed = (bank_addr * 512 * 2) + (row_addr * 512 * 2 * 4) + (col_addr * 2) + SDRAM_BASE;
	fflush(stdout);
	switch (wstrb)
	{
	case 0b0001:{
		*(uint8_t *)guest_to_host_sdram(addr_processed, id) = wdata;
		// printf("sdram_write addr = %#x , data = %#x ,wstrb = %d\n", addr_processed, wdata, wstrb);
		break;}
    case 0b0010:{
		*(uint8_t *)(guest_to_host_sdram(addr_processed, id) + 1) = wdata >> 8;
		// printf("sdram_write addr = %#x , data = %#x ,wstrb = %d\n", addr_processed, wdata, wstrb);
		break;}
	case 0b0011:{
		*(uint16_t *)guest_to_host_sdram(addr_processed, id) = wdata;
		// printf("sdram_write addr = %#x , data = %#x ,wstrb = %d\n", addr_processed, wdata, wstrb);
		break;}
	default:{
        // printf("default : sdram_write addr = %#x , data = %#x ,wstrb = %d\n", addr_processed, wdata, wstrb);
		break;}
	}
}









/*NPC内存操作相关函数*/
static word_t pmem_read(paddr_t addr) {
  word_t ret = *(uint32_t *)guest_to_host(addr);
  return ret;
}
static void pmem_write(paddr_t addr, word_t data) {
  *(uint8_t *)guest_to_host(addr) = data;
}


extern "C" int paddr_read(int addr, int is_pc_read) {
#ifdef NPCCONFIG_MTRACE
    if(!is_pc_read){
        printf("pc = 0x%x", PC);
        display_pread(addr);
    }
#endif
    if(IN_PMEM(addr) || addr == RTC_ADDR || addr == RTC_ADDR + 4 || addr == SERIAL_PORT){
        if(addr == RTC_ADDR || addr == RTC_ADDR + 4 || addr == SERIAL_PORT){
            is_skip_diff = true;
            if(addr == RTC_ADDR + 4){
                timer = get_time();
		        return (uint32_t)(timer >> 32);
            }
            else if(addr == RTC_ADDR){
                return (uint32_t)timer;
            }
            else if(addr == SERIAL_PORT){
                return 0;
            }
        }
        else
            return pmem_read(addr);
    }
    return 0;
}

extern "C" void paddr_write(int addr, int data, char wmask) {
#ifdef NPCCONFIG_MTRACE
    printf("pc = 0x%x", PC);
    display_pwrite(addr, data);
#endif
    if(IN_PMEM(addr) || addr == RTC_ADDR || addr == RTC_ADDR + 4 || addr == SERIAL_PORT){
        if(addr == SERIAL_PORT){
            is_skip_diff = true;
            fflush(stdout);//fuck this code! I'v been fixing this bug for a longlong time!
            putchar((char)data);
            return;
        }
        else{
            for (int i = 0; i < 4; i++) {
                if (wmask & (1 << i)){
                    pmem_write(addr + i, (data >> (i * 8)) & 0xFF);
                }
            }
            return;
        }
    }

#if defined(NPCCONFIG_DUMPWAVE) || defined(NPCCONFIG_LIGHTSSS)
#ifdef NPCCONFIG_LIGHTSSS
        if(lightsss.is_child()){
            dump_wave();
	        close_wave(4);
            printf("=====================波形因触发访存越界而退出, 查看child波形=====================\n");
        }else{
            lightsss.wakeup_child(light_cycle_num);
        }
#else
        dump_wave();
	    close_wave(4);
        printf("=====================波形因触发访存越界而退出, 查看father波形=====================\n");
#endif
#endif
    exit(1);
}


