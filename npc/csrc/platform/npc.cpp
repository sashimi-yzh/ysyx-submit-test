#include <stdio.h>

#include <isa.h>
#include <difftest-def.h>
#include <npc/diagnostics.h>
#include <npc/memory.h>
#include <npc/platform.h>

static uint8_t pmem[NPC_PMEM_SIZE] = {};
static long image_size = 0;
// the address constrain for npc
static bool pmem_contains(paddr_t address) {
  return address_in_window(address, NPC_PMEM_BASE, NPC_PMEM_SIZE);
}
// load the bin into flash && return the size of bin (for function load_image(const char *path))
static long read_image(const char *path) {
  FILE *file = fopen(path, "rb");
  Assert(file != NULL, "can not open '%s'", path);

  Assert(fseek(file, 0, SEEK_END) == 0, "can not fint image : '%s'", path);
  long size = ftell(file);
  Assert(size > 0 && size <= NPC_PMEM_SIZE, "error image size %ld", size);
  Assert(fseek(file, 0, SEEK_SET) == 0, "can not rewind image '%s'", path);

  size_t loaded = fread(pmem, 1, (size_t)size, file);
  fclose(file);
  Assert(loaded == (size_t)size, "failed to read image '%s': size=%ld loaded=%zu", path, size, loaded);
  return size;
}

void log_memory() {
  Log("PMEM: [0x%08x, 0x%08x] (%u MiB)", NPC_PMEM_BASE, NPC_PMEM_BASE + NPC_PMEM_SIZE - 1, NPC_PMEM_SIZE >> 20);
}
// no use function just for compatibility
void init_platform() {}
void cleanup_platform() {}
void update_platform() {}
void platform_idle(SimTop *model) { (void)model; }
uint32_t reset_pc() { return NPC_RESET_PC_NPC; }
// the main image load function
long load_image(const char *path) {
  image_size = read_image(path);
  return image_size;
}
// mem-read function for debug
bool mem_read(paddr_t address, int length, word_t *value) {
  if (!access_fits(address, length, NPC_PMEM_BASE, NPC_PMEM_SIZE)) return false;
  *value = host_read(pmem + address - NPC_PMEM_BASE, length);
  return true;
}
// mem-write function for debug
bool mem_write(paddr_t address, int length, word_t value) {
  if (!access_fits(address, length, NPC_PMEM_BASE, NPC_PMEM_SIZE)) return false;
  host_write(pmem + address - NPC_PMEM_BASE, length, value);
  return true;
}
// security function for error memory access
void mem_fault(paddr_t address) {
  panic("address = " FMT_PADDR " is outside PMEM [0x%08x, 0x%08x] at pc = " FMT_WORD, address, NPC_PMEM_BASE, NPC_PMEM_BASE + NPC_PMEM_SIZE - 1, cpu.pc);
}
// since the npc just have uart (clint is not in the device map)
const char *device_region(paddr_t address) {
  return address_in_window(address, 0x10000000u, 0x1000u) ? "UART" : NULL;
}

#ifdef CONFIG_MTRACE
const char *mem_region(paddr_t address) {
  return pmem_contains(address) ? "PMEM" : NULL;
}
#else
const char *mem_region(paddr_t address) {
  (void)address;
  return NULL;
}
#endif

bool mem_is_shared(paddr_t address) {
  return pmem_contains(address);
}

void difftest_copy_memory(
    void (*reference_memcpy)(paddr_t, void *, size_t, bool), bool direction) {
  Assert(reference_memcpy != NULL, "difftest image copy has no reference callback");
  Assert(direction == DIFFTEST_TO_DUT || direction == DIFFTEST_TO_REF, "difftest image copy has bad direction: %d", direction);
  Assert(image_size >= 0 && image_size <= NPC_PMEM_SIZE, "difftest image size is invalid: %ld", image_size);
  if (image_size > 0) {
    reference_memcpy(NPC_PMEM_BASE, pmem, (size_t)image_size, direction);
  }
}

void difftest_copy_sdram(
    void (*reference_memcpy)(paddr_t, void *, size_t, bool), bool direction) {
  (void)reference_memcpy;
  (void)direction;
}

void difftest_enable_soc(void (*enable_soc_address_space)(void)) {
  (void)enable_soc_address_space;
}
// for verilator simulation
extern "C" int pmem_read(int address) {
  word_t value = 0;
  uint32_t aligned = (uint32_t)address & ~0x3u;
  if (!mem_read(aligned, 4, &value)) return 0;
  return (int)value;
}
// for verilator simulation
extern "C" void pmem_write(int address, int data, unsigned char byte_enable) {
  uint32_t aligned = (uint32_t)address & ~0x3u;
  Assert((byte_enable & 0xf0u) == 0 && (byte_enable & 0x0fu) != 0, "bad DPI store: addr=0x%08x data=0x%08x mask=0x%02x pc=" FMT_WORD, (uint32_t)address, (uint32_t)data, byte_enable, cpu.pc);
  Assert(access_fits(aligned, 4, NPC_PMEM_BASE, NPC_PMEM_SIZE), "DPI store outside PMEM: addr=0x%08x pc=" FMT_WORD, (uint32_t)address, cpu.pc);

  uint8_t *bytes = pmem + aligned - NPC_PMEM_BASE;
  for (int index = 0; index < 4; index ++) {
    if (byte_enable & (1u << index)) {
      bytes[index] = (uint8_t)((uint32_t)data >> (index * 8));
    }
  }
}
