#include "memory.h"
#include "device.h"
#include "npc.h"
#include "../utils/log.h"
#include "../utils/difftest.h"
#include <cassert>
#include <cstdio>
#include <cstring>

#ifdef SOC_MODE
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
extern VysyxSoCFull* top;
#endif

static uint8_t pmem[PMEM_SIZE];
static uint8_t flash[FLASH_SIZE];

uint8_t* get_flash_buffer() {
    return flash;
}
uint32_t flash_read_word(uint32_t addr) {
    uint32_t off = ((uint32_t)addr - FLASH_BASE) & ~0x3u;
    uint32_t value = 0;
    for (int i = 0; i < 4; i++) {
        uint32_t boff = off + i;
        value |= (boff < FLASH_SIZE ? (uint32_t)flash[boff] : 0u) << (8 * i);
    }
    return value;
}

bool in_flash(uint32_t addr) {
    return addr >= FLASH_BASE && addr < FLASH_BASE + FLASH_SIZE;
}

bool flash_load(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        Log("ERROR: Cannot open file '%s'", filename);
        return false;
    }
    
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    if (size > FLASH_SIZE) {
        Log("ERROR: Program size (%ld bytes) exceeds flash size (%d bytes)", size, FLASH_SIZE);
        fclose(fp);
        return false;
    }
    
    size_t bytes_read = fread(flash, 1, size, fp);
    fclose(fp);
    
    Log("Loaded %zu bytes from '%s' into flash at 0x%08x", bytes_read, filename, FLASH_BASE);
    return true;
}

// DPI-C: flash 颗粒读 (flash.v 的 flash_cmd 调用), 按字节地址读 4 字节
extern "C" void flash_read(int32_t addr, int32_t *data) {
    uint32_t off = ((uint32_t)addr & ~0x3u);
    uint32_t value = 0;
    for (int i = 0; i < 4; i++) {
        uint32_t boff = off + i;
        value |= (boff < FLASH_SIZE ? (uint32_t)flash[boff] : 0u) << (8 * i);
    }
    *data = (int32_t)value;
}

extern "C" void mrom_read(int32_t addr, int32_t *data) {
    (void)addr;
    *data = 0;
}

uint8_t* get_pmem_buffer() {
    return pmem;
}

uint8_t* guest_to_host(uint32_t paddr) {
    return pmem + (paddr - PMEM_BASE);
}

// DPI-C函数：读取存储器
extern "C" int pmem_read(int raddr) {
    // 按4字节对齐读取
    raddr = raddr & ~0x3u;

    // 处理设备读取
    if (is_device_addr(raddr)) {
        difftest_skip_ref();  // MMIO 访问结果不确定，跳过 REF 对比
        return device_read(raddr);
    }

    // 帧缓冲区不可读（只写），返回0
    if (is_fb_addr(raddr)) {
        difftest_skip_ref();
        return 0;
    }
    
    // 检查地址是否在有效范围内
    if (raddr < PMEM_BASE || raddr >= PMEM_BASE + PMEM_SIZE) {
        printf("ERROR: pmem_read address out of range: 0x%x (valid: 0x%x - 0x%x)\n", 
               raddr, PMEM_BASE, PMEM_BASE + PMEM_SIZE - 1);
        return 0;
    }
    
    uint32_t* p = (uint32_t*)guest_to_host(raddr);
    return *p;
}

// DPI-C函数：写入存储器
extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    // 按4字节对齐写入
    waddr = waddr & ~0x3u;

    // 处理设备寄存器写入
    if (is_device_addr(waddr)) {
        difftest_skip_ref();  // MMIO 写入，跳过 REF 对比
        device_write(waddr, wdata, (uint8_t)wmask);
        return;
    }

    // 帧缓冲写入
    if (is_fb_addr(waddr)) {
        difftest_skip_ref();
        fb_write(waddr, wdata, (uint8_t)wmask);
        return;
    }
    
    // 检查地址是否在有效范围内
    if (waddr < PMEM_BASE || waddr >= PMEM_BASE + PMEM_SIZE) {
        printf("ERROR: pmem_write address out of range: 0x%x (valid: 0x%x - 0x%x)\n", 
               waddr, PMEM_BASE, PMEM_BASE + PMEM_SIZE - 1);
        return;
    }
    
    uint8_t* p = guest_to_host(waddr);
    
    // 根据写掩码写入数据
    if (wmask & 0x01) p[0] = wdata & 0xFF;
    if (wmask & 0x02) p[1] = (wdata >> 8) & 0xFF;
    if (wmask & 0x04) p[2] = (wdata >> 16) & 0xFF;
    if (wmask & 0x08) p[3] = (wdata >> 24) & 0xFF;
}

// 内存访问接口
uint32_t pmem_read_word(uint32_t addr) {
    addr = addr & ~0x3u;
    
    if (addr < PMEM_BASE || addr >= PMEM_BASE + PMEM_SIZE) {
        return 0;
    }
    
    uint32_t* p = (uint32_t*)guest_to_host(addr);
    return *p;
}

bool in_pmem(uint32_t addr) {
    return addr >= PMEM_BASE && addr < PMEM_BASE + PMEM_SIZE;
}

#ifdef SOC_MODE
static bool in_window(uint32_t addr, uint32_t base, uint32_t size) {
    return addr >= base && addr < base + size;
}

static bool soc_model_ready() {
    return top != nullptr && top->rootp != nullptr;
}

static uint32_t soc_read_sdram(uint32_t addr) {
    if (!soc_model_ready()) return 0;

    uint32_t off = (addr - SDRAM_BASE) & ~0x3u;
    uint32_t word_index = off >> 2;
    uint32_t bank = (word_index >> 8) & 0x3u;
    uint32_t row  = (word_index >> 10) & 0x1fffu;
    uint32_t col  = (word_index & 0xffu) << 1;

    uint32_t lo = top->rootp->ysyxSoCFull__DOT__sdram__DOT__mem[bank][row][col];
    uint32_t hi = top->rootp->ysyxSoCFull__DOT__sdram__DOT__mem[bank][row][col + 1];
    return lo | (hi << 16);
}


static uint32_t soc_read_sram(uint32_t addr) {
    if (!soc_model_ready()) return 0;
    uint32_t word = ((addr - SRAM_BASE) & ~0x3u) >> 2;
    return top->rootp->ysyxSoCFull__DOT__asic__DOT__axi4ram__DOT__mem_ext__DOT__Memory[word];
}


static uint32_t soc_read_psram(uint32_t addr) {
    if (!soc_model_ready()) return 0;
    uint32_t off = (addr - PSRAM_BASE) & ~0x3u;
    uint32_t value = 0;
    for (int i = 0; i < 4; i ++) {
        value |= (uint32_t)top->rootp->ysyxSoCFull__DOT__psram__DOT__mem[off + i] << (8 * i);
    }
    return value;
}

static uint32_t soc_read_vga(uint32_t addr) {
    if (!soc_model_ready()) return 0;
    uint32_t pixel = ((addr - VGA_BASE) & ~0x3u) >> 2;
    return top->rootp->ysyxSoCFull__DOT__asic__DOT__lvga__DOT__mvga__DOT__fb[pixel];
}
#endif

bool npc_mem_read_word(uint32_t addr, uint32_t *data) {
#ifdef SOC_MODE
    if (in_flash(addr)) {
        *data = flash_read_word(addr);
        return true;
    }
    if (in_window(addr, MROM_BASE, MROM_SIZE)) {
        *data = 0;
        return true;
    }
    if (in_window(addr, SRAM_BASE, SRAM_SIZE)) {
        *data = soc_read_sram(addr);
        return true;
    }
    if (in_window(addr, SDRAM_BASE, SDRAM_SIZE)) {
        *data = soc_read_sdram(addr);
        return true;
    }
    if (in_window(addr, PSRAM_BASE, PSRAM_SIZE)) {
        *data = soc_read_psram(addr);
        return true;
    }
    if (in_window(addr, VGA_BASE, VGA_SIZE)) {
        *data = soc_read_vga(addr);
        return true;
    }
    return false;
#else
    if (in_pmem(addr)) {
        *data = pmem_read_word(addr);
        return true;
    }
    if (in_flash(addr)) {
        *data = flash_read_word(addr);
        return true;
    }
    if (is_device_addr(addr)) {
        *data = device_read(addr);
        return true;
    }
    if (is_fb_addr(addr)) {
        *data = 0;
        return true;
    }
    return false;
#endif
}

bool load_program(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        Log("ERROR: Cannot open file '%s'", filename);
        return false;
    }
    
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    if (size > PMEM_SIZE) {
        Log("ERROR: Program size (%ld bytes) exceeds memory size (%d bytes)", size, PMEM_SIZE);
        fclose(fp);
        return false;
    }
    
    size_t bytes_read = fread(pmem, 1, size, fp);
    fclose(fp);
    
    Log("Loaded %zu bytes from '%s' into memory at 0x%08x", bytes_read, filename, PMEM_BASE);
    return true;
}
