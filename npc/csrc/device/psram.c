#include <stdio.h>
#include <common.h>
#include <device/device.h>
#include <memory/memory.h>

static uint8_t npc_psram[CONFIG_PSRAM_SIZE] = {0};

void init_psram() {
    // npc_psram[4] = 0x04;
    // npc_psram[5] = 0x03;
    // npc_psram[0] = 0x58;
    // npc_psram[1] = 0x02;
    // npc_psram[2] = 0x04;
    // npc_psram[3] = 0x03;
    return;
}

#ifdef __cplusplus
extern "C" {
#endif
#ifdef CONFIG_HAS_PSRAM
    uint8_t* guest_to_psram(uint32_t paddr) { return npc_psram + paddr; }
    void psram_read(int32_t addr,int32_t length, int32_t *data){
        *data =  host_read(guest_to_psram(addr), length);
        // printf("psram_read: address %x length %d, data %x \n", addr,length, *data);
    }

    void psram_write(int32_t addr, int32_t length, int32_t data){
        // printf("psram_write: address %x x length %d, data %x \n", addr,length,data);
        host_write(guest_to_psram(addr), length, data);
        // uint32_t new_data =  host_read(guest_to_psram(addr), 4);
        // printf("new_data: address %x data %x \n", addr,new_data);

    }
#endif

#ifdef __cplusplus
}
#endif