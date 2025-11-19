#include "../include/ysyxsoc_mem.h"

void init_icachesim();

uint8_t *mrom = NULL;
uint8_t *sram = NULL;
uint8_t *flash = NULL;
uint8_t *psram = NULL;
uint8_t *sdram = NULL;

void init_mrom(){
    mrom = malloc(MROM_SIZE);
    assert(mrom);
}

void init_sram(){
    sram = malloc(SRAM_SIZE);
    assert(sram);
}

void init_flash(){
    flash = malloc(FLASH_BASE);
    assert(flash);
}

void init_sdram(){
    sdram = malloc(SDRAM_SIZE);
    assert(sdram);
}

void init_psram(){
    psram = malloc(PSRAM_SIZE);
    assert(psram);
}


// #define CONFIG_TARGET_SHARE


void init_ysyxsoc_mem(){
#ifdef CONFIG_TARGET_SHARE
    init_mrom();
    init_sram();
    init_flash();
    init_sdram();
    init_psram();
    printf("init soc mem success!\n");
    // init_icachesim();
    // printf("init icachesim success!\n");
#elif CONFIG_ICACHESIM
    init_mrom();
    init_sram();
    init_flash();
    init_sdram();
    init_psram();
    printf("init soc mem success!\n");
    init_icachesim();
    printf("init icachesim success!\n");
#else
    init_icachesim();
    printf("init icachesim success!\n");
#endif
}


bool in_mrom(paddr_t addr){
    return addr - MROM_BASE <= MROM_SIZE;
}

bool in_sram(paddr_t addr){
    return addr - SRAM_BASE <= SRAM_SIZE;
}

bool in_flash(paddr_t addr) {
  return addr - FLASH_BASE <= FLASH_SIZE;
}

bool in_sdram(paddr_t addr) {
  return addr - SDRAM_BASE <= SDRAM_SIZE;
}

bool in_psram(paddr_t addr) {
  return addr - PSRAM_BASE <= PSRAM_SIZE;
}




bool in_uart(paddr_t addr) {
  return addr - UART_BASE <= UART_SIZE;
}
bool in_clint(paddr_t addr) {
  return addr - CLINT_BASE <= CLINT_SIZE;
}
bool in_gpio(paddr_t addr) {
  return addr - GPIO_BASE <= GPIO_SIZE;
}
bool in_spi(paddr_t addr) {
  return addr - SPI_BASE <= SPI_SIZE;
}
bool in_ps2(paddr_t addr) {
  return addr - PS2_BASE <= PS2_SIZE;
}
bool in_vga(paddr_t addr) {
  return addr - VGA_BASE <= VGA_SIZE;
}
bool in_mmio(paddr_t addr) {
  return addr - MMIO_BASE <= MMIO_SIZE;
}

#ifdef CONFIG_NPC_SO
#define CONFIG_NPC_SO_EXPAND || (addr >> 28 == 0xa)
#else
#define CONFIG_NPC_SO_EXPAND
#endif


bool in_dev(paddr_t addr) {
    return in_uart(addr) || in_clint(addr) || in_gpio(addr) || in_spi(addr) || in_ps2(addr) || in_vga(addr) || in_mmio(addr) CONFIG_NPC_SO_EXPAND;
}


static FILE *icache_fp = NULL;
static char * icache_file = "../../../icachesim.log";

void init_icachesim(){
    icache_fp = fopen(icache_file, "w");
    assert(icache_fp);
}

void write_icachesim(paddr_t addr){
    fprintf(icache_fp, "%x\n", addr);
}

//下面是增加的一些函数, 用于在icachesim时候, nemu跑ysyxsoc的程序流, 遇到访问ysyxsoc外设, 能够处理.
word_t uart_read_soc2nemu(paddr_t addr, int len){
    assert(len == 1);
    if(addr == UART_BASE + UART_REG_LS)
        return 32;
    return 0;
}
void uart_write_soc2nemu(paddr_t addr, int len, word_t data){
    assert(len == 1);
    if(addr == UART_BASE + UART_REG_RB)
        putchar(data);
}


word_t clint_read_soc2nemu(paddr_t addr, int len){
    paddr_t hi = CLINT_BASE + 0x4;
    paddr_t lo = CLINT_BASE + 0x0;
    assert(addr == hi || addr == lo);
    uint64_t us = get_time();
    if(addr == lo)
        return (uint32_t)us;
    else if(addr == hi)
        return us >> 32;
    assert(0);
    return 0;
}
void clint_write_soc2nemu(paddr_t addr, int len, word_t data){
    assert(0);
}

word_t soc2nemu_read(paddr_t addr, int len){
    word_t ret;
    if(in_uart(addr))
        ret = uart_read_soc2nemu(addr, len);
    else if(in_clint(addr))
        ret = clint_read_soc2nemu(addr, len);
    else
        assert(0);
    return ret;
}
void soc2nemu_write(paddr_t addr, int len, word_t data){
    if(in_uart(addr))
        uart_write_soc2nemu(addr, len, data);
    else if(in_clint(addr))
        clint_write_soc2nemu(addr, len, data);
    else
        assert(0);
}