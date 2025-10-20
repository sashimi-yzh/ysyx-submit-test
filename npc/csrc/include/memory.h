#ifndef MEMORY_H
#define MEMORY_H


#define RESET_VECTOR 0x80000000
#define CONFIG_MBASE 0x80000000
#define CONFIG_END   0x8fffffff

#define MROM_RESET_VECTOR 0x20000000
#define MROM_BASE_END     0x20000fff
#define MROM_MSIZE        0x00001000

#define FLASH_RESET_VECTOR 0x30000000
#define FLASH_BASE_END     0x3fffffff
#define FLASH_MSIZE        0x10000000

#define PSRAM_CONFIG_START 0x80000000
#define PSRAM_BASE_END     0x9fffffff
#define PSRAM_MSIZE        0x20000000

#define CONFIG_MSIZE 0x10000000
#define UART_BASE    0xa00003F8
#define CLK_BASE     0xa0000048
#define CLK_SIZE     0x00000002
#define PG_ALIGN __attribute((aligned(4096)))

#ifdef __cplusplus
extern "C" {
#endif

uint8_t* guest_to_host(uint32_t paddr);
uint8_t* SoC_to_host(uint32_t paddr);
word_t pmem_read(paddr_t addr, uint8_t len, int trace_on);
void pmem_write(paddr_t addr, uint8_t len, word_t data, int trace_on);
void init_isa();
void init_device();

#ifdef __cplusplus
}
#endif

#endif