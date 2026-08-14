#include <common.h>

extern "C" void flash_read(int32_t addr, int32_t *data) {
  addr &= FLASH_SIZE - 1;
  addr &= 0xfffffffc;
  *data = flash[addr + 3] | (flash[addr+2] << 8) | (flash[addr+1] << 16) | (flash[addr] << 24);
  // printf("read 0x%08x: 0x%08x\n", addr, *data);
}

extern "C" void mrom_read(int32_t addr, int32_t *data) { 
  assert(0);
}

extern "C" void dram_read(int32_t addr, int32_t *data) {
  addr &= DRAM_SIZE - 1;
  *data = dram[addr + 3] | (dram[addr+2] << 8) | (dram[addr+1] << 16) | (dram[addr] << 24);
  // assert(0);
}

extern "C" void dram_write(int32_t addr, int32_t data, int32_t len) {
  // printf("write 0x%08x: 0x%08x, len: %d\n", addr, data, len);
  for(int i=0;i<len;i++) {
    dram[addr + (len - i - 1)] = (data >> (i*8)) & 0xff;
  }
}

extern "C" void sdram_read(int32_t row, int32_t bank, int32_t col, int32_t *data) {
  *data = sdram[bank][row][col];
  // printf("sdram read: 0x%04x col: 0x%x\n", *data, col);
}

extern "C" void sdram_write(int32_t row, int32_t bank, int32_t col, int32_t mask, int32_t data) {
  uint16_t temp = sdram[bank][row][col];
  switch (mask & 0b11) {
    case 0x0: sdram[bank][row][col] = data & 0xffff; break;
    case 0x1: sdram[bank][row][col] = (data & 0xff00) | (temp & 0xff); break;
    case 0x2: sdram[bank][row][col] = (data & 0x00ff) | (temp & 0xff00); break;
    default: break;
  }
  // printf("write: 0x%04x col: 0x%08x\n", sdram[bank][row][col], col);
}

extern "C" void event_count(int32_t type) {
  switch (type)
  {
  case 0x0:
    // IFU取到指令
    ifu_counter ++;
    break;
  case 0x1:
    // LSU加载数据（LOAD）
    load_counter ++;
    break;
  case 0x2:
    // LSU加载数据（LOAD）
    store_counter ++;
    break;
  case 0x3:
    // EXU计算完毕
    exu_counter ++;
    break;
  case 0x4:
    idu_load ++;
    break;
  case 0x5:
    idu_store ++;
    break;
  case 0x6:
    idu_jalr ++;
    break;
  case 0x7:
    idu_jal ++;
    break;
  case 0x8:
    idu_branch ++;
    break;
  case 0x9:
    idu_csr ++;
    break;
  case 0xa:
    idu_mret ++;
    break;
  case 0xb:
    idu_ecall ++;
    break;
  case 0xc:
    idu_alu ++;
    break;
  case 0xd:
    lsu_load_delay ++;
    break;
  case 0xe:
    lsu_store_delay ++;
    break;
  case 0xf:
    ifu_fetch_delay ++;
    break;
  case 0x10:
    ifu_wait_delay ++;
    break;
  case 0x11:
    ifu_req ++;
    break;
  case 0x12:
    icache_hit ++;
    break;
  case 0x13:
    miss_penalty ++;
    break;
  default:
    break;
  }
}

extern bool difftest_skip_ref;
extern "C" void dpi_diff_skip() {
  difftest_skip_ref = true;
}

int get_pc() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.IFU0"));
  return npc_pc();
}

int get_regs(int addr) {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.RegisterFile0"));
  return npc_regs(addr);
}

int get_inst() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.IDU0"));
  return npc_inst();
}

int get_ifu_state() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.IFU0"));
  return npc_ifu_state();
}

int get_csrs(int addr) {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.CSR0"));
  return npc_csrs(addr);
}

int get_jump_addr() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.IDU0"));
  return npc_jump_addr();
}
int get_isRet() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.IDU0"));
  return npc_isRet();
}
int get_isCall() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.IDU0"));
  return npc_isCall();
}

long get_clint() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.clint"));
  return npc_clint();
}