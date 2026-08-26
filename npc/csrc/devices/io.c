#include "common.h"
#include "devices.h"
#include "mem.h"
#include "trace.h"
static int io_num = 0;
static IOSpace iospace[CONFIG_MMIO_MAX];

static uint32_t check_devices(uint32_t addr, io_callback_t *io_callback, int *id){
    for(int i=0;i<io_num;i++){
        if(addr >= iospace[i].low && addr <= iospace[i].high){
            if(io_callback != NULL) *io_callback = iospace[i].callback;
            if(id != NULL) *id = i;
            return (addr - iospace[i].low);
        }
    }
    return 0;
}

extern void difftest_skip_ref(int reason);
bool read_devices(uint32_t addr, uint32_t*data){
    io_callback_t io_callback=NULL;
    uint32_t offset = check_devices(addr, &io_callback, NULL);
    if(io_callback == NULL) return false;
    difftest_skip_ref(1);
    *data = io_callback(offset, 0, 4, false);
    dtrace(addr, false, *data);
    return true;
}

bool write_devices(uint32_t addr, uint32_t data){
    io_callback_t io_callback=NULL;
    uint32_t offset = check_devices(addr, &io_callback, NULL);
    if(io_callback == NULL) return false;
    difftest_skip_ref(2);
    io_callback(offset, data, 4, true);
    dtrace(addr, true, data);
    return true;
}

void add_mmio_space(const char *name, uint32_t addr, uint32_t size, io_callback_t callback){
    Assert(io_num<CONFIG_MMIO_MAX, "Cannot add device:%s (MMIO space is full)", name);
    uint32_t low = addr;
    uint32_t high = addr + size - 1;
    Assert(!(check_sram_bound(low) || check_sram_bound(high)), "Cannot add device:%s [" FMT_WORD "-" FMT_WORD "]", name, low, high);
    IOSpace s = {.name = name, .low = low, .high = high, .callback = callback};
    iospace[io_num] = s;
    io_num++;
    Log("Added device:%s [" FMT_WORD "-" FMT_WORD "]", name, low, high);
}

const char *get_device_name(uint32_t addr){
    io_callback_t io_callback=NULL;
    int id;
    check_devices(addr, &io_callback, &id);
    if(io_callback == NULL) return NULL;
    return iospace[id].name;
}