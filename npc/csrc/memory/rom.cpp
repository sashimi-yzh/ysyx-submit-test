
#include <iostream>
#include <vector>
#include <cstdint>
#include <fstream>
#include "include/common.h"

uint32_t rom_begin = 0x20000000;
uint32_t rom_end = 0x20000fff;
uint32_t rom[4096 / 4];

void init_rom(const std::string &path)
{
    std::ifstream f(path, std::ios::binary | std::ios::ate);
    if (!f.is_open())
    {
        std::cerr << "load_rom: cannot open " << path << std::endl;
        std::exit(1);
    }

    std::streamsize size = f.tellg();
    uint32_t max_size = rom_end - rom_begin;
    if (size > max_size)
    {
        std::cerr << "load_rom: file too large (" << size << " bytes, max " << max_size << ")" << std::endl;
        std::exit(1);
    }

    f.seekg(0, std::ios::beg);
    f.read(reinterpret_cast<char *>(rom), size);
    if (!f)
    {
        std::cerr << "load_rom: read failed" << std::endl;
        std::exit(1);
    }
    bin_size = size;

    std::cout << "load_rom: loaded " << size << " bytes from " << path << std::endl;
}

extern "C" void mrom_read(int32_t addr, int32_t *data)
{

    addr &= 0xfffffffc;
    if (addr >= rom_begin && addr < rom_end)
    {
        *data = rom[(addr - rom_begin) / 4];
    }
    else
    {
        std::cerr << "mrom_read: Address out of range: " << std::hex << addr << std::dec << std::endl;
        *data = 0; // 或者其他默认值
    }

    // printf("mrom_read: addr=0x%08x, data=0x%08x\n", addr, *data);
}
