#include<vector>
#include "include/difftest.h"
#include "include/common.h"

struct Device
{
    uint32_t begin_addr;
    int len;
    uint32_t (*read)(int addr);
    void (*write)(int addr, int data, char wmask);
};

std::vector<Device> devices;
void add_device(uint32_t begin_addr, int len, uint32_t (*read)(int addr), void (*write)(int addr, int data, char wmask))
{
    devices.push_back({begin_addr, len, read, write});
}



bool handle_mmio_write(int addr, int data, char wmask)
{
    for (const auto &dev : devices)
    {
        if (addr >= dev.begin_addr && addr < dev.begin_addr + dev.len)
        {
            if (dev.write)
            {
                dev.write(addr, data, wmask);
                return true;
            }
            else{
                printf("Error: Write to MMIO address 0x%08x with no write handler\n", addr);
                exit(1);
            }
        }
    }
    return false;
}

bool handle_mmio_read(int addr, int &data)
{
    for (const auto &dev : devices)
    {
        if (addr >= dev.begin_addr && addr < dev.begin_addr + dev.len)
        {
            if (dev.read)
            {
                data = dev.read(addr);
                return true;
            }
            else{
                printf("Error: Read from MMIO address 0x%08x with no read handler\n", addr);
                exit(1);
            }
        }
    }
    return false;
}

void init_devices()
{
    init_serial();
    init_timer();
}