#include "tpdef.h"

#include <cstdint>
#include <cstdio>
#include <cstring>

static uint8_t psram[4*1024*1024]  __attribute((aligned(4096))) = {};


word_t psram_read_expr(word_t addr)
{
    return *((word_t*)(psram + addr));
}


extern "C" void psram_read(int32_t addr, int32_t *data)
{
    memcpy(data, psram + addr, 4);
    // printf(ANSI_FMT("[read psram] address: 0x%08x; data: 0x%08x;\n", ANSI_FG_CYAN),
	// 		(paddr_t)addr, *data);
}


extern "C" void psram_write(int32_t addr, int32_t data, int32_t len)
{
    uint32_t right = 24;
    while (len)
    {
        // printf("%08x  %08x\n", addr + len, data >> right);
        psram[addr + len - 1] = data >> right;
        right -= 8;
        len--;
    }

    // printf(ANSI_FMT("[write psram] address: 0x%08x; data: 0x%08x;\n", ANSI_FG_CYAN),
    //     (paddr_t)addr, data);
}