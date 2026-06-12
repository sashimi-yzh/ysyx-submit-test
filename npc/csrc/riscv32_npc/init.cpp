/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include "local-include/reg.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include <generated/autoconf.h>
#include <isa.h>
#include <memory/paddr.h>
#include <sys/cdefs.h>
#include str(__TOP_NAME_INCLUDE__)
#include str(__TOP_NAME_SYMS_INCLUDE__)
#ifdef CONFIG_NVBOARD
#include <nvboard.h>
#endif

void nvboard_bind_all_pins(__VTOP_NAME__ *top);

static VerilatedContext *contextp = NULL;
static __VTOP_NAME__ *top = NULL;
static VerilatedFstC *tfp = NULL;

static uint32_t *npc_gpr_ptr = NULL;
paddr_t npc_pc = 0;
paddr_t npc_pc_raw = 0;
// CPU_state npc_state = {};
int npc_stop_flag = 0;
ISADecodeInfo npc_inst = {};
paddr_t npc_dnpc;
int npc_wbu_valid = 0;
int npc_is_jump = 0;
uint32_t npc_jump_target = 0;

// DIP-C
#ifdef CONFIG_HAS_FLASH
extern "C" void flash_read(uint32_t addr, uint32_t *data) {
  addr += CONFIG_FLASH_MMIO;
  uint32_t rdata = paddr_read(addr, 4);
  *data = rdata;
  // printf("addr: 0x%x  data: 0x%x\n", addr, rdata);
}
#endif

#ifdef CONFIG_HAS_MROM
extern "C" void mrom_read(uint32_t addr, uint32_t *data) {
  addr &= ~3u;
  *data = paddr_read(addr, 4);
}
#endif

extern "C" void psram_read(uint32_t addr, uint32_t *data, uint32_t len) {
  Assert(len % 8 == 0, "Invalid PSRAM read length");
  len /= 8;
  addr += CONFIG_MBASE;
  uint32_t rdata = paddr_read(addr, len);
  *data = rdata;
  // printf("addr: 0x%x  data: 0x%x\n", addr, rdata);
}

extern "C" void psram_write(uint32_t addr, uint32_t data, uint32_t len) {
  Assert(len % 8 == 0, "Invalid PSRAM write length");
  len /= 8;
  addr += CONFIG_MBASE;
  paddr_write(addr, len, data);
}

#ifdef CONFIG_HAS_SDRAM
extern "C" uint32_t sdram_read(uint32_t addr, uint32_t len) {
  Assert(len % 8 == 0, "Invalid SDRAM read length");
  len /= 8;
  addr += CONFIG_SDRAM_MMIO;
  uint32_t rdata = paddr_read(addr, len);
  return rdata;
  // printf("addr: 0x%x  data: 0x%x\n", addr, rdata);
}

extern "C" void sdram_write(uint32_t addr, uint32_t data, uint32_t wmask,
                            uint32_t len) {
  Assert(len % 8 == 0, "Invalid SDRAM write length");
  if (wmask == 0) {
    return;
  }
  wmask &= 3u;
  len /= 8;
  addr += CONFIG_SDRAM_MMIO;
  while ((wmask & 1u) == 0) {
    addr++;
    wmask >>= 1;
    data >>= 8;
  }
  int wlen = 0;
  while (wmask & 1u) {
    wlen++;
    wmask >>= 1;
  }
  Assert(wmask == 0, "Invalid wmask");
  paddr_write(addr, wlen, data);
}
#endif

// #define MEM_READ_SKIP 0
extern "C" void dpic_pmem_read(uint32_t raddr, uint32_t *rdata) {
  // static int skip_cnt = 0;
  // if (skip_cnt < MEM_READ_SKIP) {
  //   skip_cnt++;
  //   Log("Skip raddr: %u", raddr);
  //   *rdata = 0;
  //   return;
  // }
  // raddr &= ~3u;

  // static uint32_t last_raddr = 0;
  // static uint32_t rdata = 0;
  // if (raddr != last_raddr) {
  //   last_raddr = raddr;
  //   *rdata = paddr_read(raddr, 4);
  //   printf("READ %d Byte: *" FMT_PADDR "=" FMT_WORD "\n", 4, raddr, rdata);
  // }
  // return rdata;

  raddr &= ~3u;
  *rdata = paddr_read(raddr, 4);
}

extern "C" void dpic_pmem_write(uint32_t waddr, uint32_t wdata,
                                uint32_t wmask) {
  waddr &= ~3u;
  wmask &= 15u;
  // Log("Front " FMT_PADDR " " FMT_PADDR " %d", waddr, wdata, wmask);
  if (wmask == 0) {
    return;
  }
  while ((wmask & 1u) == 0) {
    waddr++;
    wmask >>= 1;
    wdata >>= 8;
  }
  int len = 0;
  while (wmask & 1u) {
    len++;
    wmask >>= 1;
  }
  Assert(wmask == 0, "Invalid wmask");
  // Log(FMT_PADDR " " FMT_PADDR " %d", waddr, wdata, len);
  // printf("WRITE %d Byte: *" FMT_PADDR "=" FMT_WORD "\n", 4, waddr, wdata);
  paddr_write(waddr, len, wdata);
}

extern "C" void set_debug_info(int is_ebreak, uint32_t pc, uint32_t pc_raw,
                               uint32_t inst, int wbu_valid, int is_jump,
                               uint32_t jump_target) {
  npc_stop_flag = is_ebreak;
  npc_pc = pc;
  npc_pc_raw = pc_raw;
  // npc_dnpc = dnpc;
  // npc_dnpc = is_jump ? jump_target : pc + 4u;
  npc_inst.inst = inst;
  npc_wbu_valid = wbu_valid;
  npc_is_jump = is_jump;
  npc_jump_target = jump_target;
  // Log("%u %u %u", is_ebreak, pc, inst);
}

// extern "C" void get_ret(uint32_t a0) {
// 	ret_val = a0;
// }

// extern "C" void set_gpr_ptr(uint32_t *ptr) {
//   npc_gpr_ptr = ptr;
// }

#ifdef CONFIG_NVBOARD
static void nvb_init(void) {
  nvboard_bind_all_pins(top);
  nvboard_init();
}
#endif

static void sim_init(void) {
  const char *verilator_argv[] = {
      "riscv32_npc-nemu-interpreter",
  };
  Verilated::commandArgs(1, verilator_argv);
  contextp = new VerilatedContext;
  contextp->commandArgs(1, verilator_argv);
  top = new __VTOP_NAME__{contextp};
#ifdef CONFIG_NPC_WAVE
  Verilated::traceEverOn(true);
  tfp = new VerilatedFstC;
  top->trace(tfp, 99);
  tfp->open(str(__WAVE__));
#endif

  // npc_gpr_ptr = (uint32_t
  // *)top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__getGprDpiC__DOT__temp_regs.data();
#define CONCAT_PTR_INNER(a, b) a->b
#define CONCAT_PTR(a, b) CONCAT_PTR_INNER(a, b)
  npc_gpr_ptr =
      (uint32_t *)CONCAT_PTR(top->rootp, __NPC_VERILATOR_GPR__).data();
}

extern "C" void sim_close(void) {
#ifdef CONFIG_NPC_WAVE
  if (tfp) {
    tfp->close();
  }
#endif
  if (top != NULL) {
    delete top;
    top = NULL;
  }
  if (contextp != NULL) {
    delete contextp;
    contextp = NULL;
  }
}

// #define WAVE_SKIP_CYC 1904288551
#define WAVE_SKIP_CYC 0

void single_cycle(void) {
  top->clock = 1;
  top->eval();
  contextp->timeInc(1);

#ifdef CONFIG_NPC_WAVE
  static uint64_t cycle_cnt = 0;
  if (cycle_cnt >= WAVE_SKIP_CYC) {
    tfp->dump(contextp->time());
  }
#endif
  top->clock = 0;
  top->eval();
  contextp->timeInc(1);
#ifdef CONFIG_NPC_WAVE
  if (cycle_cnt >= WAVE_SKIP_CYC) {
    tfp->dump(contextp->time());
  }
  cycle_cnt++;
#endif
  IFDEF(CONFIG_NVBOARD, nvboard_update());
}

static void reset(int n) {
  top->reset = 1;
  while (n-- > 0) {
    single_cycle();
  }
  top->reset = 0;
}

// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
static const uint32_t img[] = {
    // 0x00000297, // auipc t0,0
    // 0x00028823, // sb  zero,16(t0)
    // 0x0102c503, // lbu a0,16(t0)
    // 0x00100073, // ebreak (used as nemu_trap)
    // 0xdeadbeef, // some data

    0x800000b7, // lui x1, 0x80000
    0x00a00113, // addi x2, x0, 10
    0x800011b7, // lui x3, 0x80001
    0x0021a023, // sw x2, 0(x3)
    0x0001a203, // lw x4, 0(x3)
    0x0ff00293, // addi x5, x0, 255
    0x00518223, // sb x5, 4(x3)
    0x0041c303, // lbu x6, 4(x3)
    0x006203b3, // add x7, x4, x6
    0x03008413, // addi x8, x1, 48
    0x000400e7, // jalr x1, 0(x8)
    0x00100073, // ebreak
    0x007383b3, // add x7, x7, x7
    0x00008067, // jalr x0, 0(x1)

    // 0xb0002573,
    // 0xb00025f3,
    // 0xb0002673,
    // 0xb00026f3
};

void sync_npc_gpr(void) {
  int i;
  for (i = 0; i < LENGTH(cpu.gpr); i++) {
    gpr(i) = npc_gpr_ptr[i];
  }
}

extern "C" void restart() {
  reset(20);
  cpu.pc = npc_pc_raw;
  sync_npc_gpr();
}

__BEGIN_DECLS
void init_isa() {
  sim_init();
  IFDEF(CONFIG_NVBOARD, nvb_init());
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));
}
__END_DECLS
