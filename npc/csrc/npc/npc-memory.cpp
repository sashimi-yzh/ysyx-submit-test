#ifdef NPC

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// 地址映射与 ysyxSoC 对齐：
//   0x1000_0000 UART16550 (8 字节寄存器)
//   0x1000_0030 RTC（mtime 的低/高 32 位）
//   0x8000_0000 + 128MB 主存（npc 平台程序链接地址）
#define NPC_PMEM_BASE 0x80000000u
#define NPC_PMEM_SIZE (128u * 1024u * 1024u)
#define NPC_UART_BASE 0x10000000u
#define NPC_RTC_BASE  (0x10000000u + 0x30u)

static uint8_t npc_pmem[NPC_PMEM_SIZE] __attribute__((aligned(4096)));

uint32_t img_size = 0;

static uint64_t npc_now_us() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000ull + (uint64_t)ts.tv_nsec / 1000ull;
}

void load_img(const char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("can't open this file: %s\n", path);
        exit(1);
    }
    size_t len;
    uint32_t idx = 0;
    while ((len = fread(npc_pmem + idx, 1, 1024, fp)) > 0) {
        idx += len;
    }
    img_size = idx;
    fclose(fp);
}

static bool npc_pmem_hit(uint32_t addr) {
    return addr >= NPC_PMEM_BASE && addr < NPC_PMEM_BASE + NPC_PMEM_SIZE;
}

static bool npc_bus_read(uint32_t addr, uint32_t *data) {
    uint32_t a = addr & ~3u;
    if (npc_pmem_hit(a)) {
        uint32_t off = a - NPC_PMEM_BASE;
        uint32_t v = 0;
        for (int i = 0; i < 4; i++) {
            if (off + i < NPC_PMEM_SIZE) {
                v |= (uint32_t)npc_pmem[off + i] << (8 * i);
            }
        }
        *data = v;
        return true;
    }
    if (a >= NPC_UART_BASE && a < NPC_UART_BASE + 8) {
        *data = 0;                              
        return true;
    }
    if (a >= NPC_RTC_BASE && a < NPC_RTC_BASE + 8) {
        uint64_t t = npc_now_us();
        *data = (a == NPC_RTC_BASE + 4) ? (uint32_t)(t >> 32) : (uint32_t)t;
        return true;
    }
    *data = 0;
    return false;
}

// 写 4 字节（按 strb 选字节）；返回 false 表示地址未映射
static bool npc_bus_write(uint32_t addr, uint32_t data, uint8_t strb) {
    uint32_t a = addr & ~3u;
    if (npc_pmem_hit(a)) {
        uint32_t off = a - NPC_PMEM_BASE;
        for (int i = 0; i < 4; i++) {
            if ((strb & (1 << i)) && off + i < NPC_PMEM_SIZE) {
                npc_pmem[off + i] = (uint8_t)((data >> (8 * i)) & 0xff);
            }
        }
        return true;
    }
    if (a >= NPC_UART_BASE && a < NPC_UART_BASE + 8) {
        if (a == NPC_UART_BASE) {
            for (int i = 0; i < 4; i++) {
                if (strb & (1 << i)) {
                    putchar((uint8_t)((data >> (8 * i)) & 0xff));
                }
            }
            fflush(stdout);
        }
        return true;
    }
    return false;
}

uint32_t npc_mem_read_word(uint32_t addr) {
    uint32_t v = 0;
    npc_bus_read(addr, &v);
    return v;
}

uint32_t mem_read(uint32_t addr) {
    return npc_mem_read_word(addr);
}

bool in_mem(uint32_t addr) {
    return npc_pmem_hit(addr);
}

void *ref_mem_ptr() {
    return npc_pmem;
}

uint32_t ref_mem_base() {
    return NPC_PMEM_BASE;
}

// DPI：地址未映射时读回 0、写丢弃
extern "C" void npc_mem_read(int addr, int *data) {
    uint32_t v = 0;
    npc_bus_read((uint32_t)addr, &v);
    *data = (int)v;
}

extern "C" void npc_mem_write(int addr, int data, char strb) {
    npc_bus_write((uint32_t)addr, (uint32_t)data, (uint8_t)strb);
}

#endif
