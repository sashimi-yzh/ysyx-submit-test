#include "include/trace.h"
#include "include/CPU.h"
#include "config.h"

#define BEGIN_ADDR 0x80000000
#define MEM_SIZE (1024 * 1024 * 64)
uint8_t memory[MEM_SIZE];
long long bin_size=0;

static bool pmem_to_index(int addr, uint32_t &idx)
{
    uint32_t u_addr = (uint32_t)addr;
    u_addr &= ~0x3;
    u_addr -= BEGIN_ADDR;
    if ((u_addr + 3) >= MEM_SIZE)
    {
        return false;
    }
    idx = u_addr;
    return true;
}
int mem_read(int addr)
{
    int data;
    int mmio_data;
    uint32_t idx;

    if (handle_mmio_read(addr, mmio_data))
    {
        data = mmio_data;
    }
    else if (pmem_to_index(addr, idx))
    {
        data = memory[idx] | (memory[idx + 1] << 8) | (memory[idx + 2] << 16) | (memory[idx + 3] << 24);
    }
    else
    {
        data = 0;
    }

#ifdef ENABLE_MTRACE
    if (cpu->nextPc != addr)
    {
        char msg[64];
        sprintf(msg, "[R addr=0x%08x: 0x%08x]", addr, data);
        mtrace_record(msg);
    }
    
#endif

// printf("mem_read: addr=0x%08x, data=0x%08x\n", addr, data);

    return data;
}

void mem_write(int addr, int data, char wmask)
{
#ifdef ENABLE_MTRACE
    char msg[64];
    sprintf(msg, "[W addr=0x%08x: 0x%08x wmask=0b%04b]", addr, data, wmask);
    mtrace_record(msg);
#endif

    if (handle_mmio_write(addr, data, wmask))
    {
        return;
    }

    uint32_t idx;
    if (!pmem_to_index(addr, idx))
    {
        return;
    }
    memory[idx] = (wmask & 0x1) ? (data & 0xFF) : memory[idx];
    memory[idx + 1] = (wmask & 0x2) ? ((data >> 8) & 0xFF) : memory[idx + 1];
    memory[idx + 2] = (wmask & 0x4) ? ((data >> 16) & 0xFF) : memory[idx + 2];
    memory[idx + 3] = (wmask & 0x8) ? ((data >> 24) & 0xFF) : memory[idx + 3];

    // printf("mem_write: addr=0x%08x, data=0x%08x, wmask=0b%04b\n", addr, data, wmask);
}

int mem_print(uint32_t addr, int len)
{
    uint32_t idx;
    if (!pmem_to_index(addr, idx))
    {
        printf("Mem print out of range: 0x%08x\n", addr);
        return -1;
    }
    for (int i = 0; i < len; i += 4)
    {
        uint32_t data = memory[idx + i] | (memory[idx + i + 1] << 8) | (memory[idx + i + 2] << 16) | (memory[idx + i + 3] << 24);
        printf("0x%08x: 0x%08x\t", addr + i, data);
        if ((i + 4) % 16 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}

void init_mem(const std::string &filename)
{
    printf("init_mem: loading binary from '%s'\n", filename.c_str());
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        std::exit(1);
    }

    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    if (size > MEM_SIZE)
    {
        std::cerr << "Error: File size (" << size << ") is larger than memory size (" << MEM_SIZE << ")" << std::endl;
        std::exit(1);
    }

    if (!file.read((char *)memory, size))
    {
        std::cerr << "Error: Failed to read file content." << std::endl;
        std::exit(1);
    }

    bin_size = size;
    std::cout << "Loaded " << size << " bytes from " << filename << " to memory." << std::endl;
}