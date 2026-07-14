#include "include/common.h"
#include "config.h"
#include "include/CPU.h"
#include <fstream>

#define PSRAM_SIZE (4 * 1024 * 1024) // 4MB
uint8_t psram[PSRAM_SIZE];



extern "C" void psram_read(int addr, char *rdata)
{

    if ((uint32_t)addr >= PSRAM_SIZE) {
        fprintf(stderr, "[NPC] psram_read: addr 0x%x out of range\n", addr);
        *rdata = 0;
        return;
    }
    *rdata = (char)psram[addr];
    // printf(".");
    // printf("[NPC] psram_read: addr=0x%08x, data=0x%02x, at cycle=%llu\n", addr, (uint8_t)*rdata, cpu->cycle_count);
}

extern "C" void psram_write(int addr, char wdata)
{
    if ((uint32_t)addr >= PSRAM_SIZE) {
        fprintf(stderr, "[NPC] psram_write: addr 0x%x out of range\n", addr);
        return;
    }
    psram[addr] = (uint8_t)wdata;
    // printf(".");
    // printf("[NPC] psram_write: addr=0x%08x, data=0x%02x, at cycle=%llu\n", addr, (uint8_t)wdata, cpu->cycle_count);
}