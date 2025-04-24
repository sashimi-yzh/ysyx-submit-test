#include <utils.h>
#include <device/map.h>

#define ROM_BASE 0x20000000
#define ROM_SIZE 0x1000
#define SRAM_BASE 0x0f000000
#define SRAM_SIZE 0x2000
#define FLASH_BASE 0x30000000
#define FLASH_SIZE 0x1000000

static uint8_t *rom_base = NULL;
static uint8_t *sram_base = NULL;
static uint8_t *flash_base = NULL;

void init_ysyxsoc() {
  rom_base = new_space(ROM_SIZE);
  add_mmio_map("rom", ROM_BASE, rom_base, ROM_SIZE, NULL);
  sram_base = new_space(SRAM_SIZE);
  add_mmio_map("sram", SRAM_BASE, sram_base, SRAM_SIZE, NULL);
  flash_base = new_space(FLASH_SIZE);
  add_mmio_map("flash", FLASH_BASE, flash_base, FLASH_SIZE, NULL);
}

uint8_t* get_flash_base() {
  return flash_base;
}
