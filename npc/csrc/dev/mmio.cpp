#include "device.h"
#include "tpdef.h"

#include <cstdint>
#include <cstdio>
#include <sys/types.h>

typedef  void (*callback)(word_t, void*, bool);

typedef struct 
{
    uint32_t start;
    uint32_t end;
    callback handler;

} map;


static map mmio_map[16];
static int mmio_idx = 0;
static bool visit = false; 

// add new device
static void device_add(uint32_t addr, uint32_t len, callback handler)
{
    mmio_map[mmio_idx].start = addr;
    mmio_map[mmio_idx].end = addr + len - 1;
    mmio_map[mmio_idx].handler = handler;
    mmio_idx++;
}


// device call back function
void serial_handler(word_t addr, void* data, bool isw);
void timer_handler(word_t addr, void* data, bool isw);

// device init0
void timer_init();

// init all device
void device_init()
{
    timer_init();

    device_add(DEV_SERIAL, 1, serial_handler);
    device_add(DEV_TIMER,  8, timer_handler);
}


// mmio mapping : call device
bool device_call(uint32_t addr, void *data, bool isw)
{
    visit = true;
    for (int i = 0; i < mmio_idx; i++)
    {
        if (mmio_map[i].start <= addr && mmio_map[i].end >= addr)
        {
            mmio_map[i].handler(addr, data, isw);
            return true;
        }
    }

    printf(ANSI_FMT("device address not found 0x%08x\n", ANSI_FG_RED), addr);
    return false;
}


bool device_visit(paddr_t addr, uint32_t inst)
{
    static const uint8_t load = 0b0000011;
    static const uint8_t store = 0b0100011;

    uint8_t opt = BITS(inst, 6, 0);

    if (opt != load && opt != store)
        return false;

#ifdef RUNSOC
    if (addr >= FLASH_START && addr < FLASH_END)
        return false;
    else if (addr >= MROM_START && addr < MROM_END)
        return false;
    else if (addr >= SRAM_START && addr < SRAM_END)
        return false;
    else if (addr >= PSRAM_START && addr < PSRAM_END)
        return false;
    else if (addr >= SDRAM_START && addr < SDRAM_END)
        return false;

    return true;
#else
    return (addr >= 0xa0000000);
#endif
}