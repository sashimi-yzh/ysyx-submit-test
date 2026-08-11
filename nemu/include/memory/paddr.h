/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
***************************************************************************************/

#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>

#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)

/*
 * APP-only:
 *   RESET_VECTOR = CONFIG_MBASE + CONFIG_PC_RESET_OFFSET
 *   例如 CONFIG_MBASE=0xa0000000 时，从 SDRAM APP 开始。
 *
 * FULL-BOOT:
 *   RESET_VECTOR = 0x20000000
 *   从 ysyxSoC MROM/FSBL 开始。
 */
#ifdef CONFIG_YSYXSOC_FULL_BOOT
#define RESET_VECTOR ((paddr_t)0x20000000u)
#else
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
#endif

// =========================
// ysyxSoC address map
// =========================

#define YSYXSOC_MROM_BASE   ((paddr_t)0x20000000u)
#define YSYXSOC_MROM_SIZE   ((paddr_t)0x00004000u)   // 16KB

#define YSYXSOC_SRAM_BASE   ((paddr_t)0x0f000000u)
#define YSYXSOC_SRAM_SIZE   ((paddr_t)0x00002000u)   // 8KB

#define YSYXSOC_UART_BASE   ((paddr_t)0x10000000u)
#define YSYXSOC_UART_SIZE   ((paddr_t)0x00001000u)

#define YSYXSOC_SPI_BASE    ((paddr_t)0x10001000u)
#define YSYXSOC_SPI_SIZE    ((paddr_t)0x00001000u)

#define YSYXSOC_FLASH_BASE  ((paddr_t)0x30000000u)
#define YSYXSOC_FLASH_SIZE  ((paddr_t)0x01000000u)   // 16MB

#define YSYXSOC_PSRAM_BASE  ((paddr_t)0x80000000u)
#define YSYXSOC_PSRAM_SIZE  ((paddr_t)0x00400000u)   // 4MB

#define YSYXSOC_SDRAM_BASE  ((paddr_t)0xa0000000u)
#define YSYXSOC_SDRAM_SIZE  ((paddr_t)0x08000000u)   // 128MB

uint8_t* guest_to_host(paddr_t paddr);
paddr_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(paddr_t addr) {
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

static inline bool in_ysyxsoc_mrom(paddr_t addr) {
  return addr - YSYXSOC_MROM_BASE < YSYXSOC_MROM_SIZE;
}

static inline bool in_ysyxsoc_sram(paddr_t addr) {
  return addr - YSYXSOC_SRAM_BASE < YSYXSOC_SRAM_SIZE;
}

static inline bool in_ysyxsoc_uart(paddr_t addr) {
  return addr - YSYXSOC_UART_BASE < YSYXSOC_UART_SIZE;
}

static inline bool in_ysyxsoc_spi(paddr_t addr) {
  return addr - YSYXSOC_SPI_BASE < YSYXSOC_SPI_SIZE;
}

static inline bool in_ysyxsoc_flash(paddr_t addr) {
  return addr - YSYXSOC_FLASH_BASE < YSYXSOC_FLASH_SIZE;
}

static inline bool in_ysyxsoc_psram(paddr_t addr) {
  return addr - YSYXSOC_PSRAM_BASE < YSYXSOC_PSRAM_SIZE;
}

static inline bool in_ysyxsoc_sdram(paddr_t addr) {
  return addr - YSYXSOC_SDRAM_BASE < YSYXSOC_SDRAM_SIZE;
}

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
