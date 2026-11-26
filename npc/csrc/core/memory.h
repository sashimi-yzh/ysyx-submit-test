#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <cstdint>

#define SERIAL_PORT 0x10000000  // 串口地址
#define RTC_ADDR_LO 0x10000048  // RTC低32位
#define RTC_ADDR_HI 0x1000004c  // RTC高32位

#define MROM_BASE 0x20000000
#define MROM_SIZE 0x1000

#define SRAM_BASE  0x0f000000
#define SRAM_SIZE  0x2000       // 8KB
#define SDRAM_BASE 0xa0000000
#define SDRAM_SIZE 0x2000000    // 32MB
#define PSRAM_BASE 0x80000000
#define PSRAM_SIZE 0x400000     // 4MB
#define VGA_BASE   0x21000000
#define VGA_SIZE   0x200000     // 2MB

#define PMEM_SIZE (128 * 1024 * 1024)  
#define PMEM_BASE 0x80000000           

#define FLASH_BASE 0x30000000
#define FLASH_SIZE 0x1000000   // 16MB

#define MAX_IMG_SIZE PMEM_SIZE

bool flash_load(const char* filename);
bool load_program(const char* filename);

uint8_t* get_flash_buffer();
uint8_t* get_pmem_buffer();

uint32_t flash_read_word(uint32_t addr);
uint32_t pmem_read_word(uint32_t addr);

bool npc_mem_read_word(uint32_t addr, uint32_t *data);

bool in_flash(uint32_t addr);
bool in_pmem(uint32_t addr);

uint8_t* guest_to_host(uint32_t paddr);


extern "C" {
    void flash_read(int32_t addr, int32_t* data);
    void mrom_read(int32_t addr, int32_t* data);
    int pmem_read(int raddr);
    void pmem_write(int waddr, int wdata, char wmask);
}

#endif
