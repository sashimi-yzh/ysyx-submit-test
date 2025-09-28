#ifdef YSYXSOC
#include "VysyxSoCFull__Dpi.h"
#else
#include "Vysyx_23060203__Dpi.h"
#endif

#include "common.h"
#include "cpu.h"
#include "mem.h"
#include "trace.h"

#ifdef DIFFTEST
void difftest_skip_ref();
void difftest_skip_ref_next();
#endif

void halt() {
  // ret a0 x10
#ifdef DIFFTEST
  difftest_skip_ref();
#endif
  set_npc_state(NPC_END, cpu_pc, gpr(10));
}

bool exec_once_flag;
word_t itrace_inst;
void inst_complete(int new_pc, int new_inst) {
  cpu_pc = new_pc;
  itrace_inst = new_inst;
  exec_once_flag = true;
}

void event_mem_read(int raddr, int rsize, int rdata) {
#ifdef MTRACE
  mtrace_read(raddr, 1 << rsize, rdata);
#endif
#ifdef DIFFTEST
#ifdef YSYXSOC
  if (!get_mem_map(raddr, false)) difftest_skip_ref();
#else
  // MMIO_BASE 0xa0000000
  if (((raddr >> 28) & 0xf) == 0xa) difftest_skip_ref();
#endif
#endif
}

void event_mem_write(int waddr, int wsize, int wdata) {
#ifdef MTRACE
  mtrace_write(waddr, 1 << wsize, wdata);
#endif
#ifdef DIFFTEST
#ifdef YSYXSOC
  if (!get_mem_map(waddr, false)) difftest_skip_ref();
#else
  // MMIO_BASE 0xa0000000
  if (((waddr >> 28) & 0xf) == 0xa) difftest_skip_ref();
#endif
#endif
}

#ifdef YSYXSOC

void abort_err(int err) {
  switch (err) {
    case 101: printf(ANSI_FMT("AXI Access Fault while reading\n", ANSI_FG_RED)); break;
    case 102: printf(ANSI_FMT("AXI Access Fault while writing\n", ANSI_FG_RED)); break;
  }
  set_npc_state(NPC_ABORT, cpu_pc, err);
}

void flash_read(int addr, int *data) {
  addr = addr & ~0x3u;
  *(uint32_t *)data = addr_read(addr | FLASH_BASE, 4);
}

void mrom_read(int addr, int *data) {
  addr = addr & ~0x3u;
  *(uint32_t *)data = addr_read(addr, 4);
}

#else

int pmem_read(int raddr) {
  raddr = raddr & ~0x3u;
  word_t rdata = addr_read((addr_t)raddr, 4);
  return *(int *)&rdata;
}

void pmem_write(int waddr, int wdata, char wmask) {
  waddr = waddr & ~0x3u;
  // NPC UART
  if (waddr == 0xa00003F8) {
    putchar(wdata & 0xff);
    fflush(stdout);
    return;
  }
  if (wmask & 0b0001) addr_write(waddr + 0, 1, wdata >> 0);
  if (wmask & 0b0010) addr_write(waddr + 1, 1, wdata >> 8);
  if (wmask & 0b0100) addr_write(waddr + 2, 1, wdata >> 16);
  if (wmask & 0b1000) addr_write(waddr + 3, 1, wdata >> 24);
}

#endif
