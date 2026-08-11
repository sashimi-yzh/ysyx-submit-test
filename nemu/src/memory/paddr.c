/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
***************************************************************************************/

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

#ifndef MTRACE_COND
#define MTRACE_COND (true)
#endif


// ============================================================
// ysyxSoC memory areas
// ============================================================

#ifdef CONFIG_YSYXSOC_ADDRSPACE

static uint8_t ysyxsoc_mrom[YSYXSOC_MROM_SIZE] PG_ALIGN = {};
static uint8_t ysyxsoc_sram[YSYXSOC_SRAM_SIZE] PG_ALIGN = {};

static uint8_t *ysyxsoc_flash = NULL;
static uint8_t *ysyxsoc_psram = NULL;
static uint8_t *ysyxsoc_sdram = NULL;

// ============================================================
// Simple SPI model
//
// 这个模型不是周期级 SPI，只是为了让 FSBL/SSBL 能从 flash 读数据。
// 支持两种常见写法：
//   1. TX0 = 0x03xxxxxx，其中 xxxxxx 是 24-bit flash 地址
//   2. TX0 = 0x00000003, TX1 = addr
//
// 如果你的 FSBL 使用的 SPI 寄存器格式不同，再针对 FSBL 微调这里。
// ============================================================

#define SPI_REG_TX0   0x00
#define SPI_REG_RX0   0x00
#define SPI_REG_TX1   0x04
#define SPI_REG_RX1   0x04
#define SPI_REG_CTRL  0x10
#define SPI_REG_DIV   0x14
#define SPI_REG_SS    0x18

static uint32_t spi_tx0 = 0;
static uint32_t spi_tx1 = 0;
static uint32_t spi_rx0 = 0;
static uint32_t spi_rx1 = 0;
static uint32_t spi_ctrl = 0;
static uint32_t spi_div = 0;
static uint32_t spi_ss = 0;

static uint32_t flash_read_u32_le(uint32_t off) {
  if (ysyxsoc_flash == NULL) return 0;

  if (off + 3 >= YSYXSOC_FLASH_SIZE) {
    return 0;
  }

  uint32_t b0 = ysyxsoc_flash[off + 0];
  uint32_t b1 = ysyxsoc_flash[off + 1];
  uint32_t b2 = ysyxsoc_flash[off + 2];
  uint32_t b3 = ysyxsoc_flash[off + 3];

  return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
}

static void spi_do_transfer(void) {
  uint32_t cmd = 0;
  uint32_t addr = 0;

  /*
   * 情况 1:
   *   TX0 = 0x03xxxxxx
   */
  if (((spi_tx0 >> 24) & 0xff) == 0x03) {
    cmd = 0x03;
    addr = spi_tx0 & 0x00ffffffu;
  }
  /*
   * 情况 2:
   *   TX0 = 0x00000003
   *   TX1 = addr
   */
  else if ((spi_tx0 & 0xff) == 0x03) {
    cmd = 0x03;
    addr = spi_tx1 & 0x00ffffffu;
  }

  if (cmd == 0x03) {
    spi_rx0 = flash_read_u32_le(addr);
    spi_rx1 = flash_read_u32_le(addr + 4);
  } else {
    spi_rx0 = 0;
    spi_rx1 = 0;
  }

  /*
   * 清 busy/go 位。
   * OpenCores SPI 常见 GO_BSY 在 bit8。
   * 这里直接清掉，表示传输立即完成。
   */
  spi_ctrl &= ~(1u << 8);
}

static word_t ysyxsoc_spi_read(paddr_t addr, int len) {
  paddr_t off = addr - YSYXSOC_SPI_BASE;
  uint32_t ret = 0;

  switch (off) {
    case SPI_REG_RX0:
      ret = spi_rx0;
      break;
    case SPI_REG_RX1:
      ret = spi_rx1;
      break;
    case SPI_REG_CTRL:
      ret = spi_ctrl;
      break;
    case SPI_REG_DIV:
      ret = spi_div;
      break;
    case SPI_REG_SS:
      ret = spi_ss;
      break;
    default:
      ret = 0;
      break;
  }

  if (len == 1) return ret & 0xff;
  if (len == 2) return ret & 0xffff;
  return ret;
}

static void ysyxsoc_spi_write(paddr_t addr, int len, word_t data) {
  paddr_t off = addr - YSYXSOC_SPI_BASE;
  uint32_t wdata = (uint32_t)data;

  switch (off) {
    case SPI_REG_TX0:
      spi_tx0 = wdata;
      break;
    case SPI_REG_TX1:
      spi_tx1 = wdata;
      break;
    case SPI_REG_CTRL:
      spi_ctrl = wdata;
      /*
       * 如果写 CTRL 时置了 GO_BSY，立即完成一次传输。
       * 如果你的驱动不是 bit8，也可以直接每次写 CTRL 都 transfer。
       */
      if (spi_ctrl & (1u << 8)) {
        spi_do_transfer();
      } else {
        spi_do_transfer();
      }
      break;
    case SPI_REG_DIV:
      spi_div = wdata;
      break;
    case SPI_REG_SS:
      spi_ss = wdata;
      break;
    default:
      break;
  }

  (void)len;
}

// ============================================================
// UART
// ============================================================

static word_t ysyxsoc_uart_read(paddr_t addr, int len) {
  paddr_t off = addr - YSYXSOC_UART_BASE;
  (void)len;

  /*
   * UART16550 LSR:
   * bit 5: THRE
   * bit 6: TEMT
   *
   * 支持：
   *   0x10000005
   *   0x10000014 = 5 * 4
   */
  if (off == 0x05 || off == 0x14) {
    return 0x60;
  }

  return 0;
}

static void ysyxsoc_uart_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_YSYXSOC_RUN
  paddr_t off = addr - YSYXSOC_UART_BASE;
  (void)len;

  if (off == 0x00) {
    putchar(data & 0xff);
    fflush(stdout);
    return;
  }

  return;
#else
  (void)addr;
  (void)len;
  (void)data;
#endif
}

#endif

// ============================================================
// Address conversion
// ============================================================

uint8_t *guest_to_host(paddr_t paddr) {
#ifdef CONFIG_YSYXSOC_ADDRSPACE
  if (in_ysyxsoc_mrom(paddr)) {
    return ysyxsoc_mrom + (paddr - YSYXSOC_MROM_BASE);
  }

  if (in_ysyxsoc_sram(paddr)) {
    return ysyxsoc_sram + (paddr - YSYXSOC_SRAM_BASE);
  }

  if (in_ysyxsoc_flash(paddr)) {
    Assert(ysyxsoc_flash != NULL, "ysyxsoc_flash is not initialized");
    return ysyxsoc_flash + (paddr - YSYXSOC_FLASH_BASE);
  }

  if (in_ysyxsoc_psram(paddr)) {
    Assert(ysyxsoc_psram != NULL, "ysyxsoc_psram is not initialized");
    return ysyxsoc_psram + (paddr - YSYXSOC_PSRAM_BASE);
  }

  if (in_ysyxsoc_sdram(paddr)) {
    Assert(ysyxsoc_sdram != NULL, "ysyxsoc_sdram is not initialized");
    return ysyxsoc_sdram + (paddr - YSYXSOC_SDRAM_BASE);
  }
#endif

  if (in_pmem(paddr)) {
    return pmem + paddr - CONFIG_MBASE;
  }

  panic("guest_to_host: invalid paddr = " FMT_PADDR, paddr);
}

paddr_t host_to_guest(uint8_t *haddr) {
  uintptr_t h = (uintptr_t)haddr;

#ifdef CONFIG_YSYXSOC_ADDRSPACE
  uintptr_t mrom_l = (uintptr_t)ysyxsoc_mrom;
  uintptr_t mrom_r = (uintptr_t)(ysyxsoc_mrom + YSYXSOC_MROM_SIZE);
  if (h >= mrom_l && h < mrom_r) {
    return YSYXSOC_MROM_BASE + (h - mrom_l);
  }

  uintptr_t sram_l = (uintptr_t)ysyxsoc_sram;
  uintptr_t sram_r = (uintptr_t)(ysyxsoc_sram + YSYXSOC_SRAM_SIZE);
  if (h >= sram_l && h < sram_r) {
    return YSYXSOC_SRAM_BASE + (h - sram_l);
  }

  if (ysyxsoc_flash != NULL) {
    uintptr_t l = (uintptr_t)ysyxsoc_flash;
    uintptr_t r = (uintptr_t)(ysyxsoc_flash + YSYXSOC_FLASH_SIZE);
    if (h >= l && h < r) return YSYXSOC_FLASH_BASE + (h - l);
  }

  if (ysyxsoc_psram != NULL) {
    uintptr_t l = (uintptr_t)ysyxsoc_psram;
    uintptr_t r = (uintptr_t)(ysyxsoc_psram + YSYXSOC_PSRAM_SIZE);
    if (h >= l && h < r) return YSYXSOC_PSRAM_BASE + (h - l);
  }

  if (ysyxsoc_sdram != NULL) {
    uintptr_t l = (uintptr_t)ysyxsoc_sdram;
    uintptr_t r = (uintptr_t)(ysyxsoc_sdram + YSYXSOC_SDRAM_SIZE);
    if (h >= l && h < r) return YSYXSOC_SDRAM_BASE + (h - l);
  }
#endif

  uintptr_t pmem_l = (uintptr_t)pmem;
  uintptr_t pmem_r = (uintptr_t)(pmem + CONFIG_MSIZE);

  if (h >= pmem_l && h < pmem_r) {
    return haddr - pmem + CONFIG_MBASE;
  }

  panic("host_to_guest: invalid host addr = %p", haddr);
}

static word_t pmem_read(paddr_t addr, int len) {
  return host_read(guest_to_host(addr), len);
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("%s[ERROR]address = " FMT_PADDR
        " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR
        "] at pc = " FMT_WORD "%s",
        ANSI_FG_RED, addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc, ANSI_NONE);
}

// ============================================================
// init memory
// ============================================================

void init_mem() {
#if defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif

  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));

#ifdef CONFIG_YSYXSOC_ADDRSPACE
  memset(ysyxsoc_mrom, 0, sizeof(ysyxsoc_mrom));
  memset(ysyxsoc_sram, 0, sizeof(ysyxsoc_sram));

  ysyxsoc_flash = (uint8_t *)calloc(1, YSYXSOC_FLASH_SIZE);
  ysyxsoc_psram = (uint8_t *)calloc(1, YSYXSOC_PSRAM_SIZE);
  ysyxsoc_sdram = (uint8_t *)calloc(1, YSYXSOC_SDRAM_SIZE);

  Assert(ysyxsoc_flash != NULL, "failed to allocate ysyxsoc_flash");
  Assert(ysyxsoc_psram != NULL, "failed to allocate ysyxsoc_psram");
  Assert(ysyxsoc_sdram != NULL, "failed to allocate ysyxsoc_sdram");

  Log("ysyxSoC MROM  area [" FMT_PADDR ", " FMT_PADDR "]",
      YSYXSOC_MROM_BASE, YSYXSOC_MROM_BASE + YSYXSOC_MROM_SIZE - 1);

  Log("ysyxSoC SRAM  area [" FMT_PADDR ", " FMT_PADDR "]",
      YSYXSOC_SRAM_BASE, YSYXSOC_SRAM_BASE + YSYXSOC_SRAM_SIZE - 1);

  Log("ysyxSoC UART  area [" FMT_PADDR ", " FMT_PADDR "]",
      YSYXSOC_UART_BASE, YSYXSOC_UART_BASE + YSYXSOC_UART_SIZE - 1);

  Log("ysyxSoC SPI   area [" FMT_PADDR ", " FMT_PADDR "]",
      YSYXSOC_SPI_BASE, YSYXSOC_SPI_BASE + YSYXSOC_SPI_SIZE - 1);

  Log("ysyxSoC FLASH area [" FMT_PADDR ", " FMT_PADDR "]",
      YSYXSOC_FLASH_BASE, YSYXSOC_FLASH_BASE + YSYXSOC_FLASH_SIZE - 1);

  Log("ysyxSoC PSRAM area [" FMT_PADDR ", " FMT_PADDR "]",
      YSYXSOC_PSRAM_BASE, YSYXSOC_PSRAM_BASE + YSYXSOC_PSRAM_SIZE - 1);

  Log("ysyxSoC SDRAM area [" FMT_PADDR ", " FMT_PADDR "]",
      YSYXSOC_SDRAM_BASE, YSYXSOC_SDRAM_BASE + YSYXSOC_SDRAM_SIZE - 1);
#endif

  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]",
      PMEM_LEFT, PMEM_RIGHT);
}

// ============================================================
// paddr read/write
// ============================================================

word_t paddr_read(paddr_t addr, int len) {
  word_t data = 0;

#ifdef CONFIG_YSYXSOC_ADDRSPACE
  if (likely(in_ysyxsoc_mrom(addr))) {
    return host_read(guest_to_host(addr), len);
  }

  if (likely(in_ysyxsoc_sram(addr))) {
    return host_read(guest_to_host(addr), len);
  }

  if (likely(in_ysyxsoc_uart(addr))) {
    return ysyxsoc_uart_read(addr, len);
  }

  if (likely(in_ysyxsoc_spi(addr))) {
    return ysyxsoc_spi_read(addr, len);
  }

  if (likely(in_ysyxsoc_flash(addr))) {
    return host_read(guest_to_host(addr), len);
  }

  if (likely(in_ysyxsoc_psram(addr))) {
    return host_read(guest_to_host(addr), len);
  }

  if (likely(in_ysyxsoc_sdram(addr))) {
    return host_read(guest_to_host(addr), len);
  }
#endif

  if (likely(in_pmem(addr))) {
    data = pmem_read(addr, len);
    return data;
  }

#ifdef CONFIG_DEVICE
  data = mmio_read(addr, len);
  return data;
#endif

  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_YSYXSOC_ADDRSPACE
  if (unlikely(in_ysyxsoc_mrom(addr))) {
    panic("[MROM] write is not allowed: pc=" FMT_WORD
          " addr=" FMT_PADDR " len=%d data=" FMT_WORD,
          cpu.pc, addr, len, data);
  }

  if (likely(in_ysyxsoc_sram(addr))) {
    host_write(guest_to_host(addr), len, data);
    return;
  }

  if (likely(in_ysyxsoc_uart(addr))) {
    ysyxsoc_uart_write(addr, len, data);
    return;
  }

  if (likely(in_ysyxsoc_spi(addr))) {
    ysyxsoc_spi_write(addr, len, data);
    return;
  }

  if (unlikely(in_ysyxsoc_flash(addr))) {
    panic("[FLASH] write is not allowed: pc=" FMT_WORD
          " addr=" FMT_PADDR " len=%d data=" FMT_WORD,
          cpu.pc, addr, len, data);
  }

  if (likely(in_ysyxsoc_psram(addr))) {
    host_write(guest_to_host(addr), len, data);
    return;
  }

  if (likely(in_ysyxsoc_sdram(addr))) {
    host_write(guest_to_host(addr), len, data);
    return;
  }
#endif

  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
    return;
  }

#ifdef CONFIG_DEVICE
  mmio_write(addr, len, data);
  return;
#endif

  out_of_bound(addr);
}
