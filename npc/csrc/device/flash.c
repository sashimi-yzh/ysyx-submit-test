#include <stdio.h>
#include <common.h>
#include <device/device.h>
#include <memory/memory.h>

static uint8_t npc_flash[CONFIG_FLASH_SIZE] = {0};


void init_flash() {
    // npc_flash = (uint8_t*)malloc(CONFIG_FLASH_SIZE);
    // memcpy(npc_flash, _mem, sizeof(_mem));
    return;
}

#ifdef __cplusplus
extern "C" {
#endif
#ifdef CONFIG_HAS_FLASH

    void flash_read(int32_t addr, int32_t *data){
        // uint32_t flash_data = host_read(guest_to_flash(addr), 4);
        // uint32_t temp[4] = {flash_data & 0xff, (flash_data >> 8) & 0xff, (flash_data >> 16) & 0xff, (flash_data >> 24) & 0xff};
		// *data =  (temp[0] << 24) | (temp[1] << 16) | (temp[2] << 8) | temp[3];
        addr = addr & 0xfffffffc;
        *data =  host_read(guest_to_flash(addr), 4);
        // if(addr >= 0x100) printf("flash_read: address %x data %.8x \n", addr,*data);
    }
#endif

#ifdef __cplusplus
}
#endif
