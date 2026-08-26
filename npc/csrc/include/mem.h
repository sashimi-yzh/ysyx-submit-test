#ifndef __MEM_H__
#define __MEM_H__
#include "common.h"
#include "VysyxSoCFull__Dpi.h"
#include "svdpi.h"
#define MEM(addr) (MEM[(addr - SRAM_LEFT)>>2])
#define MROM(addr) (MROM[(addr - CONFIG_MROMBASE)>>2])
#define FLASH(addr) (FLASH[(addr - CONFIG_FLASHBASE)>>2])
#define PSRAM(addr) (PSRAM[(addr - CONFIG_PSRAMBASE)])
#define SDRAM00(addr) (SDRAM00[(addr - CONFIG_SDRAMBASE)>>2])
#define SDRAM01(addr) (SDRAM01[(addr - CONFIG_SDRAMBASE)>>2])
#define SDRAM10(addr) (SDRAM10[(addr - CONFIG_SDRAMBASE)>>2])
#define SDRAM11(addr) (SDRAM11[(addr - CONFIG_SDRAMBASE)>>2])

        
extern uint32_t MEM[CONFIG_SRAMSIZE>>2];
extern uint32_t MROM[CONFIG_MROMSIZE>>2];
extern uint32_t FLASH[CONFIG_FLASHSIZE>>2];
extern uint8_t  PSRAM[CONFIG_PSRAMSIZE];
extern uint16_t SDRAM00[CONFIG_SDRAMSIZE>>3];
extern uint16_t SDRAM01[CONFIG_SDRAMSIZE>>3];
extern uint16_t SDRAM10[CONFIG_SDRAMSIZE>>3];
extern uint16_t SDRAM11[CONFIG_SDRAMSIZE>>3];
void pmem_write(int waddr, int wdata, char wmask);
int pmem_read(int raddr);
uint32_t sdram_read_word(uint32_t raddr);
bool check_sram_bound(uint32_t addr);
bool check_mrom_bound(uint32_t addr);
#endif