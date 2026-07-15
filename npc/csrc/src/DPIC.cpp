#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <assert.h>
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"

#include "config.hpp"
#include "ftrace.hpp"
#include "reg.hpp"

extern bool exit_flag;
extern uint8_t mrom[0x8000000];
extern uint8_t flash[0x1000000];
extern uint8_t psram[0x1000000];
extern uint16_t sdram[4][8192][512];
extern uint8_t vbuf[640*480*4];
extern uint64_t cycle_cnt;
extern uint64_t instr_cnt;
extern uint64_t ihit_cnt;
extern uint64_t ifetch_cnt;
extern bool bootloader_stage;

typedef struct {
    uint64_t ifu;
    uint64_t idu;
    uint64_t exu;
    uint64_t lsu;
} performance_cnt;

performance_cnt perf_cnt;


uint32_t sdram_read_laddr(uint32_t addr){
    addr &= ~0x3u;

    uint32_t row_addr = (addr >> 12) & 0x1fffu;
    uint32_t bank = (addr >> 10) & 0x3u;
    uint32_t col_addr = ((addr >> 1) & 0x1ffu);

    uint32_t low = sdram[bank][row_addr][col_addr];
    uint32_t high = sdram[bank][row_addr][col_addr + 1];
    return low | (high << 16);
}

void sdram_write_laddr(uint32_t addr, uint16_t data) {
    uint32_t row_addr = (addr >> 12) & 0x1fffu;
    uint32_t bank = (addr >> 10) & 0x3u;
    uint32_t col_addr = ((addr >> 1) & 0x1ffu);

    sdram[bank][row_addr][col_addr] = data;
    // printf("sdram write: addr=0x%08x, bank=%d, row_addr=0x%08x, col_addr=0x%08x, data=0x%04x\n", addr, bank, row_addr, col_addr, data);
}

extern "C" void enter_userapp(uint32_t npc)
{
    if(npc >= 0xa0000000 && npc <=0xbfffffff) {
        bootloader_stage = false;
    }
}

extern "C" void ihit_num()
{
    if(!bootloader_stage)
    {
        ihit_cnt++;
    }
}

extern "C" void ifetch_num()
{
    if(!bootloader_stage)
    {
        ifetch_cnt++;
    }
}

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
extern "C" void perf_cnt_update(uint8_t target) {
    if(!bootloader_stage)
    {
        switch (target) {
            case 0: perf_cnt.ifu++;
            break;
            case 1: perf_cnt.idu++;
            break;
            case 2: perf_cnt.exu++;
            break;
            case 3: perf_cnt.lsu++;
            break;
        }
    }
    
}

extern "C" void ftrace(int pc, int npc)
{
#ifdef FTRACE
    int inst = sdram_read_laddr(pc);
    ftrace_detect(inst, pc, npc);
#endif
}

extern "C" void itrace(int inst, int pc)
{
#ifdef ITRACE
    printf("PC: 0x%08x, Instruction: 0x%08x\n", pc, inst);

    char buf[128];
    char *p = buf;
    p += snprintf(p, sizeof(buf), "%08x:", pc);
    int ilen = 4;
    uint8_t *instp = (uint8_t *)&inst;
    for (int i = ilen - 1; i >= 0; i--)
    {
        p += snprintf(p, 4, " %02x", instp[i]);
    }

    *(p++) = ' ';

    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);

    disassemble(p, sizeof(buf) - (p - buf), pc, instp, ilen);

    printf("Inst to be exe:%s\n\n", buf);
#endif
    if(!bootloader_stage)
    {
        instr_cnt ++;
    
    }   
}

extern "C" int mtime_read(int raddr)
{
    if (raddr == 0x02000004 || raddr == 0x02000008)
    {
        if (raddr == 0x02000004)
        {
            // 0x02000004是一个特殊的地址, 读取这里会返回当前时间的低32位
            return (uint32_t)(clock());
        }
        else
        {
            // 0x02000008是一个特殊的地址, 读取这里会返回当前时间的高32位
            return (uint32_t)(clock() >> 32);
        }
    }

    else
    {
        printf("\033[31;1mUnknown MTIME Read: addr=0x%08x\033[0m\n", raddr);
        assert(0);
    }
}


extern "C" void sim_exit()
{
    extern VysyxSoCFull* cpu;
    volatile uint32_t code = cpu->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_26040125_GPR__DOT__gpr[9];
    
    printf("Code:%d ", code);

    if (code == 0)
    {
        printf("\033[32;1mHit Good Trap\033[0m\n");
    }
    else if (code == 1)
    {
        printf("\033[31;1mHit Bad Trap\033[0m\n");
    }

    printf("\033[34mTotal Cycles: \t\t%lu\n", cycle_cnt);
    printf("Total Instructions: \t%lu\n", instr_cnt);
    printf("IPC: \t\t\t%f\n", (double)instr_cnt / (double)cycle_cnt);
    printf("============================\n");
    printf("Performance Counters:\n");
    printf("  IFU: \t%lu\n", perf_cnt.ifu);
    printf("  IDU: \t%lu\n", perf_cnt.idu);
    printf("  EXU: \t%lu\n", perf_cnt.exu);
    printf("  LSU: \t%lu\n", perf_cnt.lsu);
    printf("============================\n");
    printf("Num of ifetch: %lu\tNum of iCache hit: %lu\t%f%%\033[0m\n", ifetch_cnt, ihit_cnt, (double)ihit_cnt / (double)ifetch_cnt * 100);

    exit_flag = true;
}

extern "C" void flash_read(uint32_t addr, uint32_t *data) {
    *data = *(uint32_t *)(flash + (addr & ~0x3u));
    // printf("flash read: addr=0x%08x, data=0x%08x\n", addr, *data);
}
extern "C" void mrom_read(uint32_t addr, uint32_t *data) {
    addr = addr - 0x20000000;
    *data = *(uint32_t *)(mrom + (addr & ~0x3u));
}

extern "C" void psram_read(uint32_t addr, uint32_t *data) {
    *data = *(uint32_t *)(psram + (addr & ~0x3u));
    // printf("psram read: addr=0x%08x, data=0x%08x\n", addr, *data);
}

extern "C" void psram_write(uint32_t addr, uint8_t data) {
    *(psram + addr) = data;
    // printf("psram write: addr=0x%08x, data=0x%08x\n", addr, data);
}

extern "C" void sdram_read(uint8_t bank, uint32_t row_addr, uint32_t col_addr, uint16_t *data) {
    assert(bank < 4);
    assert(row_addr < 8192);
    assert(col_addr < 512);
    *data = sdram[bank][row_addr][col_addr];

    uint32_t addr = (bank << 10) | (row_addr << 12) | (col_addr << 1);
    // printf("sdram read: addr = 0x%08x, bank=%d, row_addr=0x%08x, col_addr=0x%08x, data=0x%04x\n", addr, bank, row_addr, col_addr, *data);
}

extern "C" void sdram_write(uint8_t bank, uint32_t row_addr, uint32_t col_addr, uint16_t data, uint8_t wmask) {
    assert(bank < 4);
    assert(row_addr < 8192);
    assert(col_addr < 512);
    uint32_t addr = (bank << 10) | (row_addr << 12) | (col_addr << 1);
    // printf("sdram write: addr = 0x%08x, bank=%d, row_addr=0x%08x, col_addr=0x%08x, data=0x%04x, wmask=0x%02x\n", addr, bank, row_addr, col_addr, data, wmask);
    if (~wmask & 0x1) {
        sdram[bank][row_addr][col_addr] = (sdram[bank][row_addr][col_addr] & 0xFF00) | (data & 0x00FF);
    }
    if (~wmask & 0x2) {
        sdram[bank][row_addr][col_addr] = (sdram[bank][row_addr][col_addr] & 0x00FF) | (data & 0xFF00);
    }
}

extern "C" void vga_write(uint32_t addr, uint32_t color, uint8_t strb) {
    addr = addr & 0xFFFFFFu;
    if (addr < 640*480*4) {
        if (strb & 0x1) *(vbuf + addr) = color & 0xFF;
        if (strb & 0x2) *(vbuf + addr + 1) = (color >> 8) & 0xFF;
        if (strb & 0x4) *(vbuf + addr + 2) = (color >> 16) & 0xFF;
        if (strb & 0x8) *(vbuf + addr + 3) = (color >> 24) & 0xFF;
    } else assert(0);
}

extern "C" void vga_read(uint32_t x, uint32_t y, uint32_t *color) {
    uint32_t addr = (y * 640 + x) * 4;
    if (x < 640 && y < 480) *color = *(uint32_t *)(vbuf + addr);
    else assert(0);
}
