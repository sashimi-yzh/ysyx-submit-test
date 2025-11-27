#include "memory.h"
#include "npc.h"
#include "tpdef.h"

#include <cstdio>
#include <cstring>
#include <fstream>


// virtual device
static uint8_t pmem[MSIZE] __attribute((aligned(4096))) = {};

// img size
static size_t imgsize = 0;

// is in pmem
bool in_pmem(paddr_t addr) 
{
    return addr - MBASE < MSIZE;
}


// read from real device
static word_t host_read(void *addr, int len) 
{
    switch (len) {
      case 1: return *(uint8_t  *)addr;
      case 2: return *(uint16_t *)addr;
      case 4: return *(uint32_t *)addr;
      default: return 0;
    }
}
  

// write in real device
static void host_write(void *addr, int len, word_t data) 
{
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default: return;
  }
}


// get real address
uint8_t* guest_to_host(paddr_t paddr) { return pmem + (paddr - MBASE); }


// get virtual address
paddr_t host_to_guest(uint8_t *haddr) { return (haddr - pmem) + MBASE; }


static word_t pmem_read(paddr_t addr, int len)
{
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}


static void pmem_write(paddr_t addr, int len, word_t data) 
{
  host_write(guest_to_host(addr), len, data);
}


// error message
static void out_of_bound(paddr_t addr) 
{
  printf("address = %x is out of bound of pmem [%x, %x]\n",
      addr, PMEM_LEFT, PMEM_RIGHT);
  npc_stat = NPC_ABORT;
}


// load binary file to execute
static bool load_binary(const char* fbin, uint8_t* mem)
{
  printf(ANSI_FMT("[execute file] %s\n", ANSI_FG_BLUE), fbin);

  std::ifstream file(fbin, std::ios::binary); 
  if (!file.is_open()) 
  {
      printf("open %s failed.\n", fbin);
      return false;
  }

  // get file size
  file.seekg(0, std::ios::end);
  std::streamsize fsize = file.tellg();
  file.seekg(0, std::ios::beg);

  if (fsize > MSIZE)
  {
      printf("binary file is too big\n");
      return false;
  }

  if (!file.read((char*)mem, fsize))
  {
    printf("read %s failed\n", fbin);
    return false;
  }

  file.close();
  if (mem == pmem) imgsize = fsize;

  return true;
}


size_t get_img_size()
{
  return imgsize;
}


word_t  paddr_read(paddr_t addr, int len)
{
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  out_of_bound(addr);
  return 0;
}


void paddr_write(paddr_t addr, int len, word_t data)
{
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  out_of_bound(addr);
}


bool pmem_init(const char* fbin)
{
  static const uint32_t img [] = {
      0x00100093,  // addi x1, x0, 1
      0x00508113,  // addi x2, x1, 5
      0xFFF10193,  // addi x3, x2, -1
      0x06400513,  // addi x10, x0, 100
      0x00A28293,  // addi x5, x5, 10 
      0x00000513,  // addi a0, x0, 0
      0x00100073   // ebreak
  };
  
  imgsize = sizeof(img);
  if (fbin == NULL || !load_binary(fbin, pmem))
  {
    printf(ANSI_FMT("load img file failed.\n", ANSI_FG_RED));
  }

  return true;
}


extern "C" void flash_read(int32_t addr, int32_t *data)
{
  uint32_t address = (addr & ~0x3u) + MBASE;
  // printf(ANSI_FMT("load flash 0x%08x  ", ANSI_FG_GREEN), address);
  if (likely(in_pmem(address)))
  {
    *data = paddr_read(address, 4);
    // printf(ANSI_FMT("data 0x%08x.\n", ANSI_FG_GREEN), *data);
    return;
  }

	finalize(2);
}


extern "C" void mrom_read(int32_t addr, int32_t *data) 
{
	paddr_t address = addr & ~0x3u;

	if (likely(in_pmem(address)))
  {
    
    *data = paddr_read(address, 4);
    return;
  }

	finalize(2);
}
