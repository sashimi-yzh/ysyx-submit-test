#include <common.h>
#include <memory/paddr.h>
#include <memory/host.h> 
#include <device/mmio.h>
#include <cpu/difftest.h>

#ifdef PLATFORM_YSYXSOC
static uint8_t mrom[CONFIG_MROM_SIZE] PG_ALIGN = {};
static uint8_t flash[CONFIG_FLASH_SIZE] PG_ALIGN = {};

extern "C" void difftest_device_skip() { difftest_skip_ref();}

uint8_t* mrom_guest_to_host(paddr_t paddr) { return mrom + paddr - CONFIG_MROM_BASE; }
uint8_t* flash_guest_to_host(paddr_t paddr) { return flash + paddr - CONFIG_FLASH_BASE; }

void init_mem() {
  memset(mrom, rand(), CONFIG_MROM_SIZE);
  memset(flash, 0x86, CONFIG_FLASH_SIZE);
  Log("physical mrom area [%08x, %08x]", MROM_LEFT, MROM_RIGHT);
  Log("physical flash area [%08x, %08x]", FLASH_LEFT, FLASH_RIGHT);
}

extern "C" void flash_read(int32_t addr, int32_t *data) { 
  uint32_t res = *(uint32_t *)(flash_guest_to_host(addr + CONFIG_FLASH_BASE));
  #if CONFIG_MTRACE
    printf("flash_read(0x%08x, %d) = 0x%08x\n", addr, 4, res);
  #endif
  *data = res;
}

uint32_t sdb_flash_read(int32_t addr){
  return *(uint32_t *)(flash_guest_to_host(addr));
}

extern "C" void mrom_read(int32_t addr, int32_t *data) { 
  uint32_t res = *(uint32_t *)(mrom_guest_to_host(addr));
  #if CONFIG_MTRACE
    printf("mrom_read(0x%08x, %d) = 0x%08x\n", addr, 4, res);
  #endif
  *data = res;
}

uint32_t sdb_mrom_read(int32_t addr){
  return *(uint32_t *)(mrom_guest_to_host(addr));
}
// #endif
#else
// #ifdef PLATFORM_NPC
#define SERIAL_PORT_LEFT      CONFIG_SERIAL_MMIO
#define SERIAL_PORT_RIGHT    (CONFIG_SERIAL_MMIO + 7)
// 时钟
#define RTC_ADDR_LEFT  0x02000000
#define RTC_ADDR_RIGHT  (0x02000000 + 7)
// 键盘
#define I8042_DATA_ADDR_LEFT (CONFIG_I8042_DATA_MMIO)
#define I8042_DATA_ADDR_RIGHT (CONFIG_I8042_DATA_MMIO + 3)
// 屏幕
#define VGA_CTL_ADDR_LEFT (CONFIG_VGA_CTL_MMIO)
#define VGA_CTL_ADDR_RIGHT (CONFIG_VGA_CTL_MMIO + 7)
// 声卡
#define AUDIO_CTL_ADDR_LEFT (CONFIG_AUDIO_CTL_MMIO)
#define AUDIO_CTL_ADDR_RIGHT (CONFIG_AUDIO_CTL_MMIO + 0x20 - 1)
// 存储卡
#define SDCARD_CTL_ADDR_LEFT (CONFIG_SDCARD_CTL_MMIO)
#define SDCARD_CTL_ADDR_RIGHT (CONFIG_SDCARD_CTL_MMIO + 7)
// 声卡缓存区
#define SB_ADDR_LEFT (CONFIG_SB_ADDR)
#define SB_ADDR_RIGHT (CONFIG_SB_ADDR + 0x10000 - 1)
// 帧缓存区
#define FB_ADDR_LEFT (CONFIG_FB_ADDR)
#define FB_ADDR_RIGHT (CONFIG_FB_ADDR + 0x75300 - 1)


static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
// static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

void init_mem() {
  memset(pmem, rand(), CONFIG_MSIZE);
  Log("physical memory area [%08x, %08x]", PMEM_LEFT, PMEM_RIGHT);
}

static word_t internal_pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void internal_pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, _pc_data_);
}

extern "C" int pmem_read(int addr, int len) {
  addr = paddr_t(addr) & 0xfffffffc;
  uint32_t ret;
  if (addr >= SERIAL_PORT_LEFT && addr <= SERIAL_PORT_RIGHT || \
      addr >= RTC_ADDR_LEFT && addr <= RTC_ADDR_RIGHT || \
      addr >= I8042_DATA_ADDR_LEFT && addr <= I8042_DATA_ADDR_RIGHT || \
      addr >= VGA_CTL_ADDR_LEFT && addr <= VGA_CTL_ADDR_RIGHT || \
      addr >= AUDIO_CTL_ADDR_LEFT && addr <= AUDIO_CTL_ADDR_RIGHT || \
      addr >= SDCARD_CTL_ADDR_LEFT && addr <= SDCARD_CTL_ADDR_RIGHT || \
      addr >= SB_ADDR_LEFT && addr <= SB_ADDR_RIGHT || \
      addr >= FB_ADDR_LEFT && addr <= FB_ADDR_RIGHT) { 
    ret = mmio_read(addr, len);
  }
  else{
    ret = internal_pmem_read(addr, len);
    #if CONFIG_MTRACE
    if (addr > 0x80000190) {
        char s[128];
        sprintf(s, "DPI-RET: pmem_read(0x%08x, %d) = 0x%08x\n", addr, len, ret);
        log_write("%s\n", s);
        printf("DPI-CALL: pmem_read(0x%08x, %d, 0x%08x)\n", addr, len, ret);
    }

    #endif
  }
  return ret;
}
extern "C" void pmem_write(int addr, int len, int data) {
  addr = paddr_t(addr) & 0xfffffffc;
  word_t wdata = word_t(data);
  // data = word_t(data);
  int shift_len = len;
  while ((shift_len & 1) == 0) {
    wdata = wdata >> 8;
    addr = addr + 1;
    shift_len = shift_len >> 1;
  }
  switch (len) {
    case 0b1111:
      len = 4;
      break;
    case 0b0011:
      len = 2;
      break;
    case 0b1100:
      len = 2;
      break;
    case 0b0001:
      len = 1;
      break;
    case 0b0010:
      len = 1;
      break;
    case 0b0100:
      len = 1;
      break;
    case 0b1000:
      len = 1;
      break;
  }
  // printf("len = %d\n", len);
  
  if(addr >= SERIAL_PORT_LEFT && addr <= SERIAL_PORT_RIGHT || \
      addr >= RTC_ADDR_LEFT && addr <= RTC_ADDR_RIGHT || \
      addr >= I8042_DATA_ADDR_LEFT && addr <= I8042_DATA_ADDR_RIGHT || \
      addr >= VGA_CTL_ADDR_LEFT && addr <= VGA_CTL_ADDR_RIGHT || \
      addr >= AUDIO_CTL_ADDR_LEFT && addr <= AUDIO_CTL_ADDR_RIGHT || \
      addr >= SDCARD_CTL_ADDR_LEFT && addr <= SDCARD_CTL_ADDR_RIGHT || \
      addr >= SB_ADDR_LEFT && addr <= SB_ADDR_RIGHT || \
      addr >= FB_ADDR_LEFT && addr <= FB_ADDR_RIGHT){
    // putchar(char(data));
    mmio_write(addr, len, wdata);
    // printf("串口传出数据%08x\n", data);
  }
  else{
    #if CONFIG_MTRACE
    char s[128];
    sprintf(s, "DPI-CALL: pmem_write(0x%08x, %d, 0x%08x)\n", addr, len, wdata);
    log_write("%s\n", s);
    printf("DPI-CALL: pmem_write(0x%08x, %d, 0x%08x)\n", addr, len, wdata);

  #endif
    internal_pmem_write(addr, len, wdata);
  }
}

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  #if CONFIG_DEVICE
  return mmio_read(addr, len);
  #endif
    out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  #if CONFIG_DEVICE
  mmio_write(addr, len, data);
  return;
  #endif
  out_of_bound(addr);
}

#endif