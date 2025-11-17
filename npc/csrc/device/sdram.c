#include <stdio.h>
#include <common.h>
#include <device/device.h>
#include <memory/memory.h>
#define SRAM_BIT_LENGTH 2
#define SRAM_BIT_WORD_EXTEND 2

static uint16_t npc_sdram[CONFIG_SDRAM_ROW_BITS][SRAM_BIT_WORD_EXTEND][CONFIG_SDRAM_BA_BITS][CONFIG_SDRAM_COL_BITS][SRAM_BIT_LENGTH] = {0};

void init_sdram() {
    // uint32_t rom =0,ba=0,word =0; 
    // for (int i = 0; i < 24; i+=2) {
    //     npc_sdram[rom][word][ba][i][0] =0x4033;
    //     npc_sdram[rom][word][ba][i][1] =0x0000;
    // }
    // npc_sdram[rom][word][ba][24][0] = 0x8067;
    // npc_sdram[rom][word][ba][24][1] = 0x0000;
}

const uint16_t masks[4] = {0xffff,0xff00,0x00ff,0x0000};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef CONFIG_HAS_SDRAM
    void sdram_read(int32_t word,int32_t bit, int32_t row,int32_t col,int32_t ba,int32_t dqm, uint32_t *data){
        uint16_t ret = npc_sdram[row][word][ba][col][bit];
        uint16_t mask = masks[dqm];
        *data = (ret & mask);
        // printf("read  [row][word][ba][col][bit] %x %x %x %x %x data %x dqm %d mask %08x \n", row,word,ba,col,bit, npc_sdram[row][word][ba][col][bit],dqm,mask );
    }

    void sdram_write(int32_t word,int32_t bit, int32_t row,int32_t col,int32_t ba,int32_t dqm, uint32_t data){
        uint16_t ret = npc_sdram[row][word][ba][col][bit];
        uint16_t mask = masks[dqm];
        npc_sdram[row][word][ba][col][bit] = (ret & ~mask) | (data & mask);
        // printf("write [row][word][ba][col][bit] %x %x %x %x %x data %.4x dqm %d mask %08x \n", row,word,ba,col,bit, npc_sdram[row][word][ba][col][bit],dqm,mask );
    }
#endif

#ifdef __cplusplus
}
#endif