#ifndef NPC
#include <svdpi.h>
#include <VysyxSoCFull__Dpi.h>
#include <stdint.h> // 引入 uint32_t, uint8_t 等标准类型
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mmio.h>
#include <autoconf.h>
#include <trace.h>
#include <cassert>
#include <npc-memory.h>

extern struct timespec start, end;

void difftest_skip_ref();

uint32_t mrom[1024];
uint32_t mrom_size = 4*1024;

#define FLASH_SIZE  (16*1024*1024)
uint32_t flash[FLASH_SIZE / 4];

uint32_t img_size = 0;

void load_img(const char* path){

    uint8_t *pmem_byte = (uint8_t *)flash;
    FILE* fp = fopen(path,"r");
    if(fp == NULL){
        printf("can't open this file: %s\n",path);
        exit(1);
    }
    size_t len;
    uint32_t idx = 0;
    while((len = fread(pmem_byte+idx,1,1024,fp)) > 0){
        idx += len;
    }
    img_size = idx;
    fclose(fp);
}

extern "C" void flash_read(int32_t addr, int32_t *data) {
    uint32_t uaddr = addr;
    if (uaddr >= FLASH_SIZE) {
        printf("Error: flash_read out of range: addr=0x%08x\n", addr);
        assert(0);
    }
    *data = (int32_t)flash[(uaddr >> 2)];
}

extern "C" void mrom_read(int32_t addr, int32_t *data) {
    uint32_t uaddr = addr - 0x20000000;
    if (uaddr >= sizeof(mrom)) {
        printf("Error: mrom_read out of range: addr=0x%08x\n", addr);
        assert(0);
    }
    *data = (int32_t)mrom[uaddr >> 2];
}

uint32_t psram[1024*1024];

extern "C" void psram_read(int32_t addr,int32_t *data){
    uint32_t uaddr = addr;
    *data = (int32_t)psram[uaddr >> 2];
    //printf("read addr: %x data: %x\n",uaddr,*data);
}

extern "C" void psram_write(int32_t addr,char data){
    uint32_t uaddr = addr;
    uint8_t *psram_8bits = (uint8_t*)psram;
    psram_8bits[uaddr] = data;
}

#define SDRAM_WORDS (16u * 1024u * 1024u)   // 16M words = 64MB
static uint32_t sdram_mem[SDRAM_WORDS];

static inline uint32_t sdram_index(int32_t addr) {
    return (uint32_t)addr & 0xFFFFFFu;
}

extern "C" void sdram_read(int32_t addr, int32_t *data) {
    *data = (int32_t)sdram_mem[sdram_index(addr)];
}

extern "C" void sdram_write(int32_t addr, int32_t wdata, char mask) {
    uint32_t *word = &sdram_mem[sdram_index(addr)];
    uint32_t m = 0;
    for (int i = 0; i < 4; i++)                   // mask 是 DQM，低有效：0 才写
        if (!(mask & (1 << i))) m |= 0xFFu << (8 * i);
    *word = (*word & ~m) | (wdata & m);
}


// 供 SDB 调用
uint32_t mem_read(uint32_t addr) {
    if (addr >= 0x20000000 && addr < 0x20001000)         // MROM
        return mrom[(addr - 0x20000000) >> 2];
    else if (addr >= 0x30000000 && addr < 0x40000000) {  // Flash XIP
        uint32_t off = (addr - 0x30000000) >> 2;
        if (off >= FLASH_SIZE / 4) {
            printf("Error: mem_read out of range: addr=0x%08x\n", addr);
            assert(0);
        }
        return flash[off];
    }
    else if (addr >= 0x80000000 && addr < 0x80400000)    // PSRAM
        return psram[(addr - 0x80000000) >> 2];
    else if(addr >= 0xa0000000 && addr < 0xa4000000)    // SDRAM
        return sdram_mem[((addr - 0xa0000000) >> 2) & 0xFFFFFFu];
    return 0;
}

bool in_mem(uint32_t addr){
    if (addr >= 0x20000000 && addr < 0x20001000)         // MROM
        return true;
    else if (addr >= 0x30000000 && addr < 0x40000000)    // Flash XIP
        return true;
    else if (addr >= 0x80000000 && addr < 0x80400000)    // PSRAM
        return true;
    else if(addr >= 0xa0000000 && addr < 0xa4000000)     // SDRAM
        return true;
    return false;
}
uint32_t read_rf_reg(int addr);

// 辅助函数：对指定位宽的数值进行符号扩展
static inline int32_t sign_extend(uint32_t val, int bits) {
    uint32_t sign_bit = 1u << (bits - 1);
    return (int32_t)((val ^ sign_bit) - sign_bit);
}

MemAccessInfo get_mem_access_info(uint32_t instr) {
    MemAccessInfo info;
    info.type     = 0;
    info.addr     = 0;
    info.size     = 0;
    info.sign_ext = 0;
    info.data     = 0;
    info.reg      = 0;
    info.funct3   = 0;
    info.opcode   = 0;

    uint8_t opcode = instr & 0x7F;
    uint8_t funct3 = (instr >> 12) & 0x7;
    uint8_t rs1    = (instr >> 15) & 0x1F;

    info.opcode = opcode;
    info.funct3 = funct3;

    uint32_t base_addr = read_rf_reg(rs1);
    int32_t  offset    = 0;

    if (opcode == 0x03) {              /* ---- Load ---- */
        uint32_t imm_11_0 = (instr >> 20) & 0xFFF;
        offset = sign_extend(imm_11_0, 12);
        info.addr = base_addr + offset;
        info.reg  = (instr >> 7) & 0x1F;   /* rd */
        info.type = 1;
        uint32_t raw = mem_read(info.addr);
        switch (funct3) {
            case 0x0: /* LB  */
                info.size = 1; info.sign_ext = 1;
                info.data = (uint32_t)(int32_t)(int8_t)(raw & 0xFF);
                break;
            case 0x1: /* LH  */
                info.size = 2; info.sign_ext = 1;
                info.data = (uint32_t)(int32_t)(int16_t)(raw & 0xFFFF);
                break;
            case 0x2: /* LW  */
                info.size = 4; info.sign_ext = 0;
                info.data = raw;
                break;
            case 0x4: /* LBU */
                info.size = 1; info.sign_ext = 0;
                info.data = raw & 0xFF;
                break;
            case 0x5: /* LHU */
                info.size = 2; info.sign_ext = 0;
                info.data = raw & 0xFFFF;
                break;
            default:                  /* 未知 load */
                info.type = 0;
                info.size = 0;
                info.data = 0;
                break;
        }
    }
    else if (opcode == 0x23) {         /* ---- Store ---- */
        uint32_t imm_11_5 = (instr >> 25) & 0x7F;
        uint32_t imm_4_0  = (instr >> 7)  & 0x1F;
        uint32_t imm_11_0 = (imm_11_5 << 5) | imm_4_0;
        offset = sign_extend(imm_11_0, 12);
        info.addr = base_addr + offset;
        info.reg  = (instr >> 20) & 0x1F;   /* rs2 */
        info.type = 2;
        info.sign_ext = 0;
        info.data = read_rf_reg(info.reg);  /* 待写入内存的数据 */

        switch (funct3) {
            case 0x0: /* SB */
                info.size = 1; info.data = info.data & 0xFF;
                break;
            case 0x1: /* SH */
                info.size = 2; info.data = info.data & 0xFFFF;
                break;
            case 0x2: /* SW */
                info.size = 4;
                break;
            default:                  /* 未知 store */
                info.type = 0;
                info.size = 0;
                info.data = 0;
                break;
        }
    }

    return info;
}
void *ref_mem_ptr() { return flash; }
uint32_t ref_mem_base() { return 0x30000000u; }

#endif
