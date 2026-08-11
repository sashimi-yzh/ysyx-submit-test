#include <stdio.h>
#include <string.h>

#include <nvboard.h>

#include <isa.h>
#include <difftest-def.h>
#include <npc/diagnostics.h>
#include <npc/memory.h>
#include <npc/platform.h>
#include <sim_top.h>

void nvboard_bind_all_pins(SimTop *model);

static uint8_t flash_mem[NPC_FLASH_SIZE];
static uint8_t sdram_mem[NPC_SDRAM_SIZE];
static long loaded_size = 0;

typedef struct{
  paddr_t base;
  uint32_t size;
  const char *name;
} Region;

static const Region devices[] = {
    {0x10000000u, 0x1000u, "UART16550"},
    {0x10001000u, 0x1000u, "SPI"},
    {0x10002000u, 0x10u, "GPIO"},
    {0x10011000u, 0x8u, "PS2"},
    {0x21000000u, 0x200000u, "VGA"},
    {0x40000000u, 0x40000000u, "ChipLink MMIO"},
};

#ifdef CONFIG_MTRACE
static const Region memories[] = {
    {0x0f000000u, 0x01000000u, "SRAM"},
    {0x20000000u, 0x1000u, "MROM"},
    {0x30000000u, 0x10000000u, "Flash"},
    {0x80000000u, 0x20000000u, "PSRAM"},
    {0xa0000000u, 0x20000000u, "SDRAM"},
    {0xc0000000u, 0x40000000u, "ChipLink MEM"},
};
#endif

static const char *lookup_region(paddr_t address, const Region *map, size_t count){
  for (size_t i = 0; i < count; i++)
  {
    if (address_in_window(address, map[i].base, map[i].size))
      return map[i].name;
  }
  return NULL;
}

static bool in_flash(paddr_t address){
  return address_in_window(address, NPC_FLASH_BASE, NPC_FLASH_SIZE);
}

static bool in_sdram(paddr_t address){
  return address_in_window(address, NPC_SDRAM_BASE, NPC_SDRAM_SIZE);
}
// load the bin into flash && return the size of bin (for function load_image(const char *path))
static long read_image(const char *path){
  // initial the mem (flash wit ff)
  memset(flash_mem, 0xff, sizeof(flash_mem));
  memset(sdram_mem, 0, sizeof(sdram_mem));

  FILE *file = fopen(path, "rb");
  Assert(file != NULL, "can not open '%s'", path);
  Assert(fseek(file, 0, SEEK_END) == 0, "can not find image '%s'", path);
  long size = ftell(file);
  Assert((size > 0 && size <= NPC_FLASH_SIZE), "error flash image size %ld", size);
  Assert(fseek(file, 0, SEEK_SET) == 0, "can not back image '%s'", path);
  size_t count = fread(flash_mem, 1, (size_t)size, file);
  fclose(file);
  Assert(count == (size_t)size, "failed to read image '%s': size=%ld loaded=%zu", path, size, count);
  return size;
}

void log_memory(){
  Log("Flash: [0x%08x, 0x%08x] (%u MB)", NPC_FLASH_BASE, NPC_FLASH_BASE + NPC_FLASH_SIZE - 1, NPC_FLASH_SIZE >> 20);
  Log("SDRAM: [0x%08x, 0x%08x] (%u MB)", NPC_SDRAM_BASE, NPC_SDRAM_BASE + NPC_SDRAM_SIZE - 1, NPC_SDRAM_SIZE >> 20);
}

void init_platform(){
  nvboard_bind_all_pins(sim_top);
  nvboard_init();
}

void cleanup_platform() { nvboard_quit(); }
void update_platform() { nvboard_update(); }

void platform_idle(SimTop *model){
  model->externalPins_ps2_clk = 1;
  model->externalPins_ps2_data = 1;
  model->externalPins_uart_rx = 1;
}

uint32_t reset_pc() { return NPC_RESET_PC_YSYXSOC; }
// the image loading function
long load_image(const char *path){
  loaded_size = read_image(path);
  return loaded_size;
}
// sdb debug port
bool mem_read(paddr_t address, int length, word_t *value){
  if (access_fits(address, length, NPC_FLASH_BASE, NPC_FLASH_SIZE)){
    *value = host_read(flash_mem + address - NPC_FLASH_BASE, length);
    return true;
  }
  if (!access_fits(address, length, NPC_SDRAM_BASE, NPC_SDRAM_SIZE))
    return false;
  *value = host_read(sdram_mem + address - NPC_SDRAM_BASE, length);
  return true;
}
// now no use
bool mem_write(paddr_t address, int length, word_t value){
  if (access_fits(address, length, NPC_FLASH_BASE, NPC_FLASH_SIZE)){
    host_write(flash_mem + address - NPC_FLASH_BASE, length, value);
    return true;
  }
  if (!access_fits(address, length, NPC_SDRAM_BASE, NPC_SDRAM_SIZE))
    return false;
  host_write(sdram_mem + address - NPC_SDRAM_BASE, length, value);
  return true;
}
// out of bound warning
void mem_fault(paddr_t address){
  panic("address = " FMT_PADDR " is outside SoC memory at pc = " FMT_WORD, address, cpu.pc);
}
// dtrace
const char *device_region(paddr_t address){
  return lookup_region(address, devices, ARRLEN(devices));
}
// no use port for mmu
bool mem_is_shared(paddr_t address){
  return in_flash(address) || address_in_window(address, NPC_SRAM_BASE, NPC_SRAM_SIZE) || in_sdram(address);
}

#ifdef CONFIG_MTRACE
const char *mem_region(paddr_t address){
  return lookup_region(address, memories, ARRLEN(memories));
}
#else
const char *mem_region(paddr_t address){
  (void)address;
  return NULL;
}
#endif

void difftest_copy_memory(void (*copy)(paddr_t, void *, size_t, bool), bool dir)
{
  // security check
  Assert(copy != NULL, "difftest image copy has no callback");
  Assert(dir == DIFFTEST_TO_DUT || dir == DIFFTEST_TO_REF, "difftest image copy has bad direction: %d", dir);
  Assert(loaded_size >= 0 && loaded_size <= NPC_FLASH_SIZE, "difftest flash image size is invalid: %ld", loaded_size);
  if (loaded_size > 0)
    copy(NPC_FLASH_BASE, flash_mem, (size_t)loaded_size, dir);
}

void difftest_copy_sdram(void (*copy)(paddr_t, void *, size_t, bool), bool dir)
{
  // security check
  Assert(copy != NULL, "difftest SDRAM copy has no reference callback");
  Assert(dir == DIFFTEST_TO_DUT || dir == DIFFTEST_TO_REF, "difftest SDRAM copy has bad direction: %d", dir);
  copy(NPC_SDRAM_BASE, sdram_mem, NPC_SDRAM_SIZE, dir);
}

void difftest_enable_soc(void (*enable)(void)){
  Assert(enable != NULL, "missing SoC memory-space DiffTest hook");
  enable();
}
// for soc DPI-flash read (since the verilog realize is too slow)
extern "C" void flash_read(int addr, int *out){
  uint32_t offset = (uint32_t)addr & ~3u;
  Assert(out != NULL, "flash read received a null output");
  Assert(offset <= NPC_FLASH_SIZE - 4, "flash read out of bound image: addr=0x%08x pc=" FMT_WORD, (uint32_t)addr, cpu.pc);
  *out = (int)host_read(flash_mem + offset, 4);
}
// for soc DPI-sdram read (since the verilog realize is too slow)
extern "C" int sdram_read(unsigned int index){
  uint32_t offset = index * 2u;
  Assert(offset <= NPC_SDRAM_SIZE - 2,"[ERROR] sdram read out of bound memory: word=0x%08x pc=" FMT_WORD, index, cpu.pc);
  return (int)host_read(sdram_mem + offset, 2);
}
// for soc DPI-sdram write (since the verilog realize is too slow)
extern "C" void sdram_write(unsigned int index, unsigned int value, unsigned int strb){
  uint32_t offset = index * 2u;
  Assert(offset <= NPC_SDRAM_SIZE - 2, "[ERROR] sdram write out of bound memory: word=0x%08x pc=" FMT_WORD, index, cpu.pc);
  if (strb & 1u)
    sdram_mem[offset] = value & 0xffu;
  if (strb & 2u)
    sdram_mem[offset + 1] = (value >> 8) & 0xffu;
}
