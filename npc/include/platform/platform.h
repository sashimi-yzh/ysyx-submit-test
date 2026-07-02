#ifndef __PLATFORM_PLATFORM_H__
#define __PLATFORM_PLATFORM_H__

#include <common.h>

#ifdef __cplusplus
#if defined(NPC_BUILD_PLATFORM_NPC)
class Vtop;
typedef Vtop SimTop;
#elif defined(NPC_BUILD_PLATFORM_YSYXSOC)
class VysyxSoCFull;
typedef VysyxSoCFull SimTop;
#else
#error "unknown NPC platform"
#endif
extern SimTop *g_top;
#endif

#define NPC_PMEM_BASE 0x80000000u
#define NPC_PMEM_SIZE 0x08000000u
#define NPC_RESET_PC_NPC 0x80000000u

#define NPC_FLASH_BASE 0x30000000u
#define NPC_FLASH_SIZE (16u * 1024u * 1024u)
#define NPC_SRAM_BASE  0x0f000000u
#define NPC_SRAM_SIZE  0x00002000u
#define NPC_SDRAM_BASE 0xa0000000u
#define NPC_SDRAM_SIZE (32u * 1024u * 1024u)
#define NPC_RESET_PC_YSYXSOC 0x30000000u

#ifdef __cplusplus
extern "C" {
#endif

void platform_init();
void platform_cleanup();
void platform_update();
uint32_t platform_reset_pc();
void platform_log_memory();
long platform_load_image(const char *img_file);
bool platform_read(paddr_t addr, int len, word_t *data);
bool platform_write(paddr_t addr, int len, word_t data);
void platform_out_of_bound(paddr_t addr);
bool platform_in_comparable_mem(paddr_t addr);
void platform_difftest_memcpy(void (*ref_memcpy)(paddr_t, void *, size_t, bool), bool direction);
void platform_enable_ref_paddr(void (*enable_ysyxsoc_paddr)(void));
void platform_trace_read(paddr_t addr, int len, word_t data);
void platform_trace_write(paddr_t addr, int len, word_t data);

#ifdef __cplusplus
}
void platform_set_external_idle(SimTop *top);
#endif

#endif
