#ifndef _YSYXSOC_H_
#define _YSYXSOC_H_
#include <common.h>

extern uint8_t *mrom;
extern uint8_t *sram;
extern uint8_t *flash;
extern uint8_t *psram;
extern uint8_t *sdram;

void init_ysyxsoc_mem();

bool in_mrom(paddr_t addr);
bool in_sram(paddr_t addr);
bool in_flash(paddr_t addr);
bool in_sdram(paddr_t addr);
bool in_psram(paddr_t addr);

bool in_uart(paddr_t addr);
bool in_clint(paddr_t addr);
bool in_gpio(paddr_t addr);
bool in_spi(paddr_t addr);
bool in_ps2(paddr_t addr);
bool in_vga(paddr_t addr);
bool in_mmio(paddr_t addr);

bool in_dev(paddr_t addr);

void write_icachesim(paddr_t addr);


word_t uart_read_soc2nemu(paddr_t addr, int len);
void uart_write_soc2nemu(paddr_t addr, int len, word_t data);
word_t clint_read_soc2nemu(paddr_t addr, int len);
void clint_write_soc2nemu(paddr_t addr, int len, word_t data);
word_t soc2nemu_read(paddr_t addr, int len);
void soc2nemu_write(paddr_t addr, int len, word_t data);
#endif