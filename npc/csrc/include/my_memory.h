#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <circuit.h>
#ifdef CONFIG_SOC
#define RESET_VECTOR 0x30000000
#else
#define RESET_VECTOR 0x80000000
#endif
#define MROM_BASE   0x20000000
#define MROM_SIZE   0xfff
#define PMEM_BASE   0x80000000
#define PMEM_SIZE   0xfffffff
#define FLASH_BASE  0x30000000
// #define FLASH_SIZE  0xfffffff    // 这是划分的地址空间，实际使用的flash颗粒没有这么大
#define FLASH_SIZE 256 * 16 * 16 * 256
#define PSRAM_BASE  0x80000000
#define PSRAM_SIZE  0x20000000
#define SDRAM_BASE  0xa0000000
#define SDRAM_SIZE  0x20000000
// #define RESET_VECTOR 0x80000000
#define REGNUM 16

extern uint32_t gpr[REGNUM];
extern uint32_t csr[4];
extern const char *regs[];
extern const char *SysReg[];

void init_mem(size_t size);
void init_mrom();
void init_flash();
void init_psram();
void init_sdram();
uint8_t *guest_to_host(uint32_t addr);
uint8_t *guest_to_host_sdram(uint32_t paddr, int chip_id);
void isa_reg_display();
uint32_t isa_reg_str2val(const char *s, bool *success);
void get_reg();


static inline bool in_pmem(paddr_t addr){
    return addr - PMEM_BASE < PMEM_SIZE;
}

static inline bool in_mrom(paddr_t addr){
    return addr - MROM_BASE < MROM_SIZE;
}

static inline bool in_flash(paddr_t addr){
    return addr - FLASH_BASE < FLASH_SIZE;
}

static inline bool in_psram(paddr_t addr){
    return addr - PSRAM_BASE < PSRAM_SIZE;
}

static inline bool in_sdram(paddr_t addr){
    return addr - SDRAM_BASE < SDRAM_SIZE;
}

#endif