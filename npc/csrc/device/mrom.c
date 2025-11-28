#include <stdio.h>
#include <common.h>
#include <device/device.h>
#include <memory/memory.h>

static uint8_t *npc_mrom = NULL;

static uint64_t count_read = 0;
void init_mrom() {
    npc_mrom = (uint8_t*)malloc(CONFIG_MROM_SIZE);
}
#ifdef __cplusplus
extern "C" {
#endif
#ifdef CONFIG_HAS_MROM

    uint8_t* guest_to_mrom(uint32_t paddr) { return npc_mrom + paddr - CONFIG_MROM_BASE; }

    void mrom_read(int32_t addr, int32_t *data){
        
        // printf("mrom_read: address %x data %x \n", addr,*data);
        if (addr >= CONFIG_MROM_BASE && 
        addr < CONFIG_MROM_BASE + CONFIG_MROM_SIZE)
            *data = host_read(guest_to_host(addr), 4);
            // *data = 0x00100073;
        else {
            if (count_read % 0x1000000 == 0){
                printf("mrom_read: invalid address %x, 0x%x times\n", addr,count_read  );
            }
            count_read++;
        }
    }
#endif

#ifdef __cplusplus
}
#endif
