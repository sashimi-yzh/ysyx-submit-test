#include "tpdef.h"

#include <cstdint>
#include <cstdio>
#include <cstring>

#include <sys/types.h>
#include <svdpi.h>

static uint16_t sdram[4][8192][512][2][2] __attribute((aligned(4096))) = {};


word_t sdram_read_expr(word_t addr)
{
    uint32_t col  = BITS(addr, 11, 2);
    uint32_t bank = BITS(addr, 13, 12); 
    uint32_t row  = BITS(addr, 26, 14);    
    int group = BITS(col, 9, 9);
    int idx = col % 512;
    // printf(ANSI_FMT("[read sdram] bank:%d  row:0x%04x  idx:%d;  group:%d;  data:%04x %04x\n", ANSI_FG_CYAN),
    // 		bank, row, idx, group, sdram[bank][row][idx][1][group], sdram[bank][row][idx][0][group]);
    return ((uint32_t)sdram[bank][row][idx][1][group] << 16) | (uint32_t)sdram[bank][row][idx][0][group];
}


extern "C" void sdram_row_load(int8_t bank, int16_t row, int16_t *data, int8_t raw, svBit group)
{
    int n = svSize(data, 1);
    uint16_t *p0 = (uint16_t*)svGetArrayPtr(data);

    for (int i = 0; i < n; i++) p0[i] = sdram[bank][row][i][raw][group];
 
    // printf(ANSI_FMT("[read sdram] bank:%d  row:0x%04x  num:%d;\n", ANSI_FG_CYAN),
	// 		bank, row, n);
}


extern "C" void sdram_row_store(int8_t bank, int16_t row, const svOpenArrayHandle data, int8_t raw, svBit group)
{
    int n = svSize(data, 1);
    uint16_t *p0 = (uint16_t*)svGetArrayPtr(data);

    for (int i = 0; i < n; i++) sdram[bank][row][i][raw][group] = p0[i];

    // printf(ANSI_FMT("[write sdram] bank:%d  row:0x%04x  num:%d;\n", ANSI_FG_CYAN),
	// 		bank, row, n);
}