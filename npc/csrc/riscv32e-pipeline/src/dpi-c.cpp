#include <common.h>
#include <cpu.h>

extern "C" void flash_read(int32_t addr, int32_t *data) {
  addr &= FLASH_SIZE - 1;
  addr &= 0xfffffffc;
  *data = flash[addr + 3] | (flash[addr+2] << 8) | (flash[addr+1] << 16) | (flash[addr] << 24);
}

extern "C" void mrom_read(int32_t addr, int32_t *data) { 
  
  printf("read: 0x%08x\n", addr);
  assert(0);
}

extern "C" void dram_read(int32_t addr, int32_t *data) {
  assert(0);
}

extern "C" void dram_write(int32_t addr, int32_t data, int32_t len) {
  assert(0);
}

extern "C" void sdram_read(int32_t row, int32_t bank, int32_t col, int32_t *data, int32_t sdram_set, int32_t sel_set) {
  // uint32_t temp = sdram[bank][row][col];
  // printf("read: %d, %d\n", sel_set, sdram_set);
  if (sel_set == 0) {
    switch (sdram_set)
    {
    case 0x0:
      *data = sdram0[bank][row][col] & 0x0000ffff;
      break;
    case 0x1:
      *data = (sdram0[bank][row][col] & 0xffff0000) >> 16;
      break;
    default:
      break;
    }
  }
  else if(sel_set == 1) {
    switch (sdram_set)
    {
    case 0x0:
      *data = sdram1[bank][row][col] & 0x0000ffff;
      break;
    case 0x1:
      *data = (sdram1[bank][row][col] & 0xffff0000) >> 16;
      break;
    default:
      break;
    }
  }
  #ifdef MTRACE_COND
    int32_t addr = 0xa0000000 | (sel_set << 25) | (row << 12) | (col << 2) | (bank << 10);
    printf("sdram read addr: 0x%08x data: 0x%08x\n", addr, (*data << (sdram_set * 16)));
  #endif
}

extern "C" void sdram_write(int32_t row, int32_t bank, int32_t col, int32_t mask, int32_t data, int32_t sdram_set, int32_t sel_set) {
  if (sel_set == 0) {
    uint32_t temp = sdram0[bank][row][col];
    switch ((sdram_set << 2) | (mask & 0b11)) {
      case 0b000: sdram0[bank][row][col] = (temp & 0xffff0000) | (data & 0x0000ffff); break;
      case 0b001: sdram0[bank][row][col] = (temp & 0xffff0000) | (data & 0x0000ff00) | (temp & 0x000000ff); break;
      case 0b010: sdram0[bank][row][col] = (temp & 0xffff0000) | (data & 0x000000ff) | (temp & 0x0000ff00); break;
      case 0b100: sdram0[bank][row][col] = (temp & 0x0000ffff) | (data << 16) & 0xffff0000; break;
      case 0b101: sdram0[bank][row][col] = (temp & 0x0000ffff) | ((data << 16) & 0xff000000) | (temp & 0x00ff0000); break;
      case 0b110: sdram0[bank][row][col] = (temp & 0x0000ffff) | ((data << 16) & 0x00ff0000) | (temp & 0xff000000); break;
      default: break;
    }
  }
  else if(sel_set == 1) {
    uint32_t temp = sdram1[bank][row][col];
    switch ((sdram_set << 2) | (mask & 0b11)) {
      case 0b000: sdram1[bank][row][col] = (temp & 0xffff0000) | (data & 0x0000ffff); break;
      case 0b001: sdram1[bank][row][col] = (temp & 0xffff0000) | (data & 0x0000ff00) | (temp & 0x000000ff); break;
      case 0b010: sdram1[bank][row][col] = (temp & 0xffff0000) | (data & 0x000000ff) | (temp & 0x0000ff00); break;
      case 0b100: sdram1[bank][row][col] = (temp & 0x0000ffff) | (data << 16) & 0xffff0000; break;
      case 0b101: sdram1[bank][row][col] = (temp & 0x0000ffff) | ((data << 16) & 0xff000000) | (temp & 0x00ff0000); break;
      case 0b110: sdram1[bank][row][col] = (temp & 0x0000ffff) | ((data << 16) & 0x00ff0000) | (temp & 0xff000000); break;
      default: break;
    }
  }
  #ifdef MTRACE_COND
    int32_t addr = 0xa0000000 | (sel_set << 25) | (row << 12) | (col << 2) | (bank << 10);
    printf("sdram write addr: 0x%08x data: 0x%08x mask: 0x%1x\n", addr, (data << (sdram_set * 16)), mask);
  #endif
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
  case 0x14:
    jump_fail ++;
    break;
  case 0x15:
    data_risk ++;
    break;
  case 0x16:
    load_use ++;
    break;
  case 0x17:
    struct_load_risk ++;
    break;
  case 0x18:
    struct_store_risk ++;
    break;
  case 0x19:
    struct_ifu_risk ++;
    break;
  case 0x1a:
    jump_re_wait ++;
    break;
  case 0x1b:
    reset_cycles ++;
    break;
  case 0x1c:
    ifu_valid_inst ++;
    break;
  case 0x1d:
    flush_inst ++;
    break;
  case 0x1e:
    ifu_jump_wait ++;
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
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu"));
  return npc_pc();
}

int get_npc() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu"));
  return npc_npc();
}

int get_wbu_valid() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu"));
  return npc_wbu_valid();
}

int get_regs(int addr) {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.RegisterFile0"));
  return npc_regs(addr);
}

int get_inst() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu"));
  return npc_inst();
}

int get_csrs(int addr) {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.CSR0"));
  return npc_csrs(addr);
}

int get_isRet() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu"));
  return npc_wbu_is_ret();
}
int get_isCall() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu"));
  return npc_wbu_is_call();
}

int ebreak_inst() {
  svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.cpu.IDU0"));
  return npc_ebreak_inst();
}