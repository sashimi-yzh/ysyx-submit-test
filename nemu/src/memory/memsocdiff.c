#include "memory/memsocdiff.h"

#if defined(CONFIG_TARGET_SHARE) || defined(CONFIG_YSYXSOC_EMU)
#define SRAM_SIZE (8 * 1024 * 1024)
#define SRAM_START 0x0f000000
#define SRAM_END 0x0f001fff
static uint8_t sram[SRAM_SIZE] PG_ALIGN = {};

// MROM: 0x2000_0000 ~ 0x2000_0fff (4KB)
#define MROM_SIZE 0x1000
#define MROM_START 0x20000000
#define MROM_END 0x20000fff
static uint8_t mrom[MROM_SIZE] PG_ALIGN = {};

// Flash: 0x3000_0000 ~ 0x3fff_ffff (256MB)
#define FLASH_SIZE 0x10000000
#define FLASH_START 0x30000000
#define FLASH_END 0x3fffffff
static uint8_t flash[FLASH_SIZE] PG_ALIGN = {};

// SDRAM: 0xa000_0000 ~ 0xbfff_ffff (512MB)
#define SDRAM_SIZE 0x20000000
#define SDRAM_START 0xa0000000
#define SDRAM_END 0xbfffffff
static uint8_t sdram[SDRAM_SIZE] PG_ALIGN = {};

// ========== 外设设备定义（MMIO，无需内存空间，space = NULL）==========
// 这些设备由 MMIO 处理，在此仅用于地址范围识别
// 注意：PSRAM (0x8000_0000 ~ 0x9fff_ffff) 由 NEMU 的 pmem 处理，不在此处定义

soc_device soc_devices[] = {
    {SRAM_START, SRAM_END, "sram", sram},
    {MROM_START, MROM_END, "mrom", mrom},
    {FLASH_START, FLASH_END, "flash", flash},
    {SDRAM_START, SDRAM_END, "sdram", sdram},

    {0x02000000, 0x0200ffff, "clint", NULL},         // CLINT
    {0x10000000, 0x10000fff, "uart16550", NULL},     // UART16550
    {0x10001000, 0x10001fff, "spi_master", NULL},    // SPI master
    {0x10002000, 0x1000200f, "gpio", NULL},          // GPIO
    {0x10011000, 0x10011007, "ps2", NULL},           // PS2
    {0x21000000, 0x211fffff, "vga", NULL},           // VGA
    {0x40000000, 0x7fffffff, "chiplink_mmio", NULL}, // ChipLink MMIO
    {0xc0000000, 0xffffffff, "chiplink_mem", NULL},  // ChipLink MEM
};

soc_device *fetch_the_soc(paddr_t addr) {
  for (int i = 0; i < ARRLEN(soc_devices); i++) {
    if (addr >= soc_devices[i].soc_start && addr <= soc_devices[i].soc_end) {
      return &soc_devices[i];
    }
  }
  return NULL;
}

// 初始化 SOC 内存空间（仅初始化需要的内存设备）
void init_soc() {
  memset(sram, 0, SRAM_SIZE);
  memset(mrom, 0, MROM_SIZE);
}
#else
soc_device *fetch_the_soc(paddr_t addr) { return NULL; }
void init_soc() {}
#endif
