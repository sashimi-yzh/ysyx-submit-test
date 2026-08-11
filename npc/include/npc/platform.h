#ifndef NPC_PLATFORM_INTERFACE_H
#define NPC_PLATFORM_INTERFACE_H

#include <npc/base.h>

#define NPC_FLASH_BASE       0x30000000u
#define NPC_FLASH_SIZE       (16u * 1024u * 1024u)
#define NPC_SRAM_BASE        0x0f000000u
#define NPC_SRAM_SIZE        0x00002000u
#define NPC_SDRAM_BASE       0xa0000000u
#define NPC_SDRAM_SIZE       (32u * 1024u * 1024u)
#define NPC_RESET_PC_YSYXSOC NPC_FLASH_BASE

#define NPC_PMEM_BASE        0x80000000u
#define NPC_PMEM_SIZE        0x08000000u
#define NPC_RESET_PC_NPC     NPC_PMEM_BASE

static inline bool address_in_window(paddr_t address, paddr_t base, uint32_t size) {
  return address >= base && (uint64_t)(address - base) < size;
}

static inline bool access_fits(paddr_t address, int length, paddr_t base, uint32_t size) {
  return length > 0 && address >= base && (uint64_t)(address - base) + (uint32_t)length <= size;
}

#ifdef __cplusplus
#if defined(NPC_BUILD_PLATFORM_YSYXSOC)
class VysyxSoCFull;
typedef VysyxSoCFull SimTop;
#elif defined(NPC_BUILD_PLATFORM_NPC)
class Vnpc_top;
typedef Vnpc_top SimTop;
#else
#error "unknown NPC platform"
#endif

extern SimTop *sim_top;
#endif

NPC_EXTERN_C_BEGIN

void trace_bus_write(paddr_t address, int length, word_t value);
void trace_bus_read(paddr_t address, int length, word_t value);

void difftest_enable_soc(void (*enable)(void));
void difftest_copy_memory(void (*copy)(paddr_t, void *, size_t, bool), bool direction);
void difftest_copy_sdram(void (*copy)(paddr_t, void *, size_t, bool), bool direction);
bool mem_is_shared(paddr_t address);

const char *mem_region(paddr_t address);
const char *device_region(paddr_t address);
void mem_fault(paddr_t address);
bool mem_write(paddr_t address, int length, word_t value);
bool mem_read(paddr_t address, int length, word_t *value);

long load_image(const char *image_path);
void log_memory(void);
uint32_t reset_pc(void);
void update_platform(void);
void cleanup_platform(void);
void init_platform(void);

NPC_EXTERN_C_END

#ifdef __cplusplus
void platform_idle(SimTop *model);
#endif

#endif
