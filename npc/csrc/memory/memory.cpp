#include "../../include/common.h"
#include <stdio.h>
// 内存
uint8_t imem[CONFIG_IMEM_SIZE] __attribute((aligned(4096))) = {}; // 内存变量
uint8_t dmem[CONFIG_DMEM_SIZE] __attribute((aligned(4096))) = {}; // 内存变量
mem_info_t npc_mem_info;

static inline uint8_t *imem_guest_to_host(uint32_t paddr) { return imem + paddr - CONFIG_IMEM_BASE; }
static inline uint8_t *dmem_guest_to_host(uint32_t paddr) { return dmem + paddr - CONFIG_DMEM_BASE; }
static inline uint8_t *sram_guest_to_host(uint32_t paddr) { 
    uint32_t offset = paddr - CONFIG_SRAM_BASE;
    uint32_t word_index = offset / 4;  // 每个 unsigned int 是 4 字节
    uint32_t byte_offset = offset % 4;
    
    // 获取对应字的引用，然后转换为字节指针
    unsigned int& word = SOC_SRAM[word_index];
    return reinterpret_cast<uint8_t*>(&word) + byte_offset;
}
static inline bool in_imem(uint32_t paddr) { return paddr - CONFIG_IMEM_BASE < CONFIG_IMEM_SIZE; }
static inline bool in_dmem(uint32_t paddr) { return paddr - CONFIG_DMEM_BASE < CONFIG_DMEM_SIZE; }
static inline bool in_sram(uint32_t paddr) { return paddr - CONFIG_SRAM_BASE < CONFIG_SRAM_SIZE; }


long init_imem(char *img_file)
{
  if (!img_file)
  {
    uint32_t *imem_w = (uint32_t *)imem;
    *imem_w++ = 0x23458593;
    *imem_w++ = 0x00100073; // ebreak
    Log("没有给源文件, 程序使用了内置的代码.");
    return 20;
  }
  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("源文件是 %s, 文件大小为 %ld byte.", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(imem, size, 1, fp);
  assert(ret == 1);

  fclose(fp); 
  return size;
}

extern "C" int pmem_read(int raddr) {assert(0);}

extern "C" void pmem_write(int waddr, int wdata, int wmask) {assert(0);}

extern "C" void flash_read(int32_t addr, int32_t *data) {
  uint32_t raddr = addr & (~0x3);
  Assert((raddr < CONFIG_IMEM_SIZE), "FLASH模块读地址越界");
  *data = *(int32_t *)(imem + raddr);
}

extern "C" void mrom_read(int32_t addr, int32_t *data) {
  uint32_t raddr = addr & (~0x3);
  Assert(in_imem(raddr), "MROM模块读地址越界");
  *data = *(int32_t *)imem_guest_to_host(raddr);
}

extern "C" void psram_read(int32_t addr, int32_t *data) {
  uint32_t raddr = addr & (~0x3);
  Assert((raddr < CONFIG_DMEM_SIZE), "PSRAM模块读地址越界");
  *data = *(int32_t *)(dmem + raddr);
}

extern "C" void psram_write(int32_t addr, int32_t data, int32_t len) {
  Assert((addr < CONFIG_DMEM_SIZE), "PSRAM模块写地址越界");
  switch (len)
  {
  case 1:  
    *(uint8_t *)(dmem + addr) = (uint8_t)data;  
    break;
  case 2:  
    *(uint16_t *)(dmem + addr) = (uint16_t)data;  
    break;
  case 4:  
    *(uint32_t *)(dmem + addr) = (uint32_t)data;  
    break;
  default:
    break;
  }
}

extern "C" void find_ebreak() {
  set_nemu_state(NPC_END, SOC_NPC, get_reg(10));
}

extern "C" void find_resp() {
  Log("NPC抛出Access Fault异常, 但我继续仿真, 如果后续有问题可以检查这个");
  set_nemu_state(NPC_END, SOC_NPC, 2);
}

extern "C" void find_addr_0() {
  Log("你正在对地址0进行读写");
  set_nemu_state(NPC_END, SOC_NPC, 3);
}

extern "C" void find_diff_skip() {
  if_skip = true;
}

extern "C" void find_diff_mem(int addr, int data, char len, char mem_type) {
  // printf("内存数据不同步, addr: 0x%08x, data: 0x%08x, len: %08x, type: %08x\n", addr, data, len, mem_type);
  npc_mem_info.data = (uint32_t)data;
  npc_mem_info.vaddr = (uint32_t)addr;
  npc_mem_info.len = len & 0x7;
  npc_mem_info.type = mem_type & 0x3;
}

NPC_perforcount npc_perC = {0};
extern "C" void fetch_get()                  {npc_perC.fetch_count++;            }
extern "C" void commit_get()                 {npc_perC.commit_count++;           }
extern "C" void load_get()                   {npc_perC.load_count++;             }
extern "C" void store_get()                  {npc_perC.store_count++;            }
extern "C" void jump_get()                   {npc_perC.jump_count++;             }
extern "C" void branch_get()                 {npc_perC.branch_count++;           }
extern "C" void alu_get()                    {npc_perC.alu_count++;              }
extern "C" void system_get()                 {npc_perC.system_count++;           }
extern "C" void predict_miss_count()         {npc_perC.predict_miss_count++;     }
extern "C" void predict_not_jump_count()     {npc_perC.predict_not_jump_count++; }
extern "C" void related_delay_get()          {npc_perC.related_delay_count++;    }
extern "C" void icache_get(int type) {
  switch(type) {
    case 0: npc_perC.icache_sram_count++; break;
    case 1: npc_perC.icache_flash_count++;  break;
    case 2: npc_perC.icache_sdram_count++; break;
    default: break;
  }
}
extern "C" void icache_miss(int type) {
  switch(type) {
    case 0: npc_perC.icache_sram_miss++; break;
    case 1: npc_perC.icache_flash_miss++;  break;
    case 2: npc_perC.icache_sdram_miss++; break;
    default: break;
  }
}
extern "C" void icache_misscycle(int type) {
  switch(type) {
    case 0: npc_perC.icache_sram_misscycle++; break;
    case 1: npc_perC.icache_flash_misscycle++;  break;
    case 2: npc_perC.icache_sdram_misscycle++; break;
    default: break;
  }
}
extern "C" void dcache_get(int type) {
  switch(type) {
    case 0: npc_perC.dcache_sram_rcount++; break;
    case 1: npc_perC.dcache_flash_count++;  break;
    case 2: npc_perC.dcache_sdram_rcount++; break;
    case 3: npc_perC.dcache_sram_wcount++; break;
    case 4: break;
    case 5: npc_perC.dcache_sdram_wcount++; break;
    default: break;
  }
}
extern "C" void dcache_misscycle(int type) {
  switch(type) {
    case 0: npc_perC.dcache_sram_rmisscycle++; break;
    case 1: npc_perC.dcache_flash_misscycle++;  break;
    case 2: npc_perC.dcache_sdram_rmisscycle++; break;
    case 3: npc_perC.dcache_sram_wmisscycle++; break;
    case 4: break;
    case 5: npc_perC.dcache_sdram_wmisscycle++; break;
    default: break;
  }
}

uint32_t vaddr_read(uint32_t paddr)
{
  if (in_imem(paddr)) return *(uint32_t *)imem_guest_to_host(paddr);
  if (in_dmem(paddr)) return *(uint32_t *)dmem_guest_to_host(paddr);
  if (in_sram(paddr)) return *(uint32_t *)sram_guest_to_host(paddr);
  Assert(0, "你使用sdb查看的地址值不合法,addr = 0x%08x\n", paddr);
  return 0;
}