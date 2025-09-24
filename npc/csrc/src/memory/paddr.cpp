#include <cpu/difftest.h>
#include <isa.h>
#include <memory/host.h>
#include <memory/paddr.h>
#include <stdio.h>
#include <utils.h>

#define DEVICE_BASE 0xa0000000
#define SERIAL_PORT (DEVICE_BASE + 0x00003f8)
#define RTC_ADDR (DEVICE_BASE + 0x0000048)

static uint32_t paddr_read_old_rdata = 0;
static uint32_t pmem_read_old_rdata = 0;
static bool is_skip = false;

extern void assert_fail_msg();

static uint8_t pmrom[CONFIG_MROM_SIZE] PG_ALIGN = {};
static uint8_t pflash[CONFIG_FLASH_SIZE] PG_ALIGN = {};
static uint8_t psram[CONFIG_PSRAM_SIZE] PG_ALIGN = {};
static uint8_t sdram[CONFIG_SDRAM_SIZE] PG_ALIGN = {};
static uint8_t pmem[CONFIG_PMEM_SIZE] PG_ALIGN = {};

#ifdef CONFIG_MTRACE
uint32_t mem_acc_pc() {
  if (icache_acc_sram_grant()) {
    return ifu_idu_pc();
  } else {
    return lsu_wbu_pc();
  }
}
#endif

uint8_t *guest_to_host(paddr_t paddr) {
  if (in_pmrom(paddr)) {
    return pmrom + paddr - CONFIG_MROM_BASE;
  } else if (in_pflash(paddr)) {
    return pflash + paddr - CONFIG_FLASH_BASE;
  } else if (in_psram(paddr)) {
    return psram + paddr - CONFIG_PSRAM_BASE; 
  } else if (in_sdram(paddr)) {
    return sdram + paddr - CONFIG_SDRAM_BASE;
  } else if (in_pmem(paddr)) {
    return pmem + paddr - CONFIG_PMEM_BASE; 
  } else {
  #ifdef CONFIG_MTRACE
    Assert(0, "pc = 0x%.8x, paddr = " FMT_PADDR " is out of bound", mem_acc_pc(), paddr);
    Log("pc = 0x%.8x, paddr = " FMT_PADDR " is out of bound", mem_acc_pc(), paddr);
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = mem_acc_pc();
  #endif
    return NULL;
  }
}

#ifdef CONFIG_MTRACE
static bool in_mtrace(paddr_t addr) {
  bool in = false;
  if (addr >= CONFIG_MTRACE_START && addr <= CONFIG_MTRACE_END)
    in = true;
  return in;
}
#endif /* ifdef CONFIG_MTRACE */

/* uint8_t diff_mem_read(int idx) { return pmrom[idx]; } */

extern "C" void mrom_read(int32_t addr, int32_t *data) {
  *data = host_read(guest_to_host(addr), 4);
}

extern "C" void flash_read(int32_t addr, int32_t *data) {
  *data = host_read(pflash + addr, 4);
};

extern "C" uint32_t psram_read(uint32_t raddr) {
  uint32_t rdata;
  rdata = host_read(psram + raddr, 4);
  // IFDEF(CONFIG_MTRACE, trace_write(
  //                         "pc: 0x%.8x  psram read:  addr = 0x%.8x, "
  //                         "len = %d, data = 0x%.8x\n",
  //                         cpu.pc, raddr, 4, rdata));
  return rdata;
}

extern "C" void psram_write(uint32_t waddr, uint32_t wdata, uint32_t len) {
  host_write(psram + waddr, len, wdata);

  // IFDEF(CONFIG_MTRACE, trace_write(
  //                           "pc: 0x%.8x  psram write: addr = 0x%.8x, "
  //                           "len = %d, data = 0x%.8x\n",
  //                           cpu.pc, waddr, len, wdata));
}

extern "C" uint32_t sdram_read0(uint32_t raddr) {
  uint32_t rdata;
  rdata = host_read(sdram + raddr, 4);
  IFDEF(CONFIG_MTRACE, trace_write(
                          "pc: 0x%.8x  sdram0 read:  addr = 0x%.8x, "
                          "len = %d, data = 0x%.8x\n",
                          mem_acc_pc(), raddr, 4, rdata));
  return rdata;
}

extern "C" void sdram_write0(uint32_t waddr, uint32_t wdata, uint32_t len) {
  host_write(sdram + waddr, len, wdata);

  IFDEF(CONFIG_MTRACE, trace_write(
                            "pc: 0x%.8x  sdram0 write: addr = 0x%.8x, "
                            "len = %d, data = 0x%.8x\n",
                            mem_acc_pc(), waddr, len, wdata));
}

extern "C" uint32_t sdram_read1(uint32_t raddr) {
  uint32_t rdata;
  rdata = host_read(sdram + raddr, 4);
  IFDEF(CONFIG_MTRACE, trace_write(
                          "pc: 0x%.8x  sdram1 read:  addr = 0x%.8x, "
                          "len = %d, data = 0x%.8x\n",
                          mem_acc_pc(), raddr, 4, rdata));
  return rdata;
}

extern "C" void sdram_write1(uint32_t waddr, uint32_t wdata, uint32_t len) {
  host_write(sdram + waddr, len, wdata);

  IFDEF(CONFIG_MTRACE, trace_write(
                            "pc: 0x%.8x  sdram1 write: addr = 0x%.8x, "
                            "len = %d, data = 0x%.8x\n",
                            mem_acc_pc(), waddr, len, wdata));
}


extern "C" uint32_t pmem_read(uint32_t raddr) {
  uint32_t rdata = pmem_read_old_rdata;
  if (is_skip) {
    is_skip = false;
    difftest_skip_ref();
  }
  if (in_pmem(raddr)) {
    rdata = host_read(guest_to_host(raddr), 4);
    pmem_read_old_rdata = rdata;
  } else {
    sim_exit();
    panic("raddr = 0x%.8x out of pmem\n", raddr);
  }

  IFDEF(CONFIG_MTRACE, if (in_mtrace(raddr)) trace_write(
  "pc: 0x%.8x  memory read:  addr = 0x%.8x, "
    "len = %d, data = 0x%.8x\n",
    mem_acc_pc(), raddr, 4, rdata));
  return rdata;
}

extern "C" void pmem_write(uint32_t waddr, int wmask, uint32_t wdata) {
    if ( lsu_Xbar_aw_handshake() && lsu_Xbar_w_handshake() ) {

      int len;
      uint32_t new_waddr;
      uint32_t new_wdata;
      switch (wmask) {
        case 0b0001: len = 1; new_waddr = waddr;     new_wdata = wdata;       break;
        case 0b0010: len = 1; new_waddr = waddr + 1; new_wdata = wdata >> 8;  break;
        case 0b0100: len = 1; new_waddr = waddr + 2; new_wdata = wdata >> 16; break;
        case 0b1000: len = 1; new_waddr = waddr + 3; new_wdata = wdata >> 24; break;
        case 0b0011: len = 2; new_waddr = waddr;     new_wdata = wdata;       break;
        case 0b1100: len = 2; new_waddr = waddr + 2; new_wdata = wdata >> 16; break;
        case 0b1111: len = 4; new_waddr = waddr;     new_wdata = wdata;       break;
        default:
          sim_exit();
          panic("Wrong wmask = 0x%.8x", wmask);
      }

      if (in_pmem(new_waddr)) {
          host_write(guest_to_host(new_waddr), len, new_wdata);
      } else if (new_waddr == SERIAL_PORT) {
          putc((int)new_wdata, stderr);
      } else {
        sim_exit();
        panic("waddr = 0x%.8x out of range", new_waddr);
      }

      IFDEF(CONFIG_MTRACE, if (in_mtrace(new_waddr)) trace_write(
                               "pc: 0x%.8x  memory write: addr = 0x%.8x, "
                               "len = %d, data = 0x%.8x, align data = 0x%.8x\n",
                               mem_acc_pc(), new_waddr, len, new_wdata, wdata));
    }
}

static void out_of_bound(paddr_t addr) {
  #ifdef CONFIG_MTRACE
  panic("address = " FMT_PADDR " is out of bound of pflash [" FMT_PADDR
        ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, FLASH_LEFT, FLASH_RIGHT, mem_acc_pc());
  #endif
}

void init_mem() {
  Log("pmem  area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
  Log("flash area [" FMT_PADDR ", " FMT_PADDR "]", FLASH_LEFT, FLASH_RIGHT);
  Log("sdram area [" FMT_PADDR ", " FMT_PADDR "]", SDRAM_LEFT, SDRAM_RIGHT);
}