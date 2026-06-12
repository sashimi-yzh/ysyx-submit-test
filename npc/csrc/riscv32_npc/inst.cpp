/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <sys/cdefs.h>

void single_cycle(void);
void sync_npc_gpr(void);

__BEGIN_DECLS

#include "common.h"
#include "difftest-def.h"
#include "macro.h"
#include "local-include/rvc.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#include "local-include/reg.h"
#include <cpu/difftest.h>
#include <device/mmio.h>

#define R(idx) gpr(idx)

extern bool g_print_step;

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J, TYPE_B, TYPE_R, 
  GEN_MAP_ENUM_C
  TYPE_N, // none
};

#define src1R() do { *src1 = R(*rs1); } while (0)
#define src2R() do { *src2 = R(*rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
#define immJ() do { *imm = SEXT((BITS(i, 31, 31) << 20) | \
                                (BITS(i, 19, 12) << 12) | \
                                (BITS(i, 20, 20) << 11) | \
                                (BITS(i, 30, 21) << 1), 21); } while(0)
#define immB() do { *imm = SEXT(BITS(i, 31, 31) << 12 | \
								BITS(i, 7, 7) << 11 | \
								BITS(i, 30, 25) << 5 | \
								BITS(i, 11, 8) << 1, 13); } while(0)

static void decode_operand(Decode *s, int *rd, int *rs1, int *rs2, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst;
  *rs1 = BITS(i, 19, 15);
  *rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
	  case TYPE_J:			             immJ(); break;
	  case TYPE_B: src1R(); src2R(); immB(); break;
	  case TYPE_R: src1R(); src2R();		     break;
    case TYPE_N:                           break;

    GEN_MAP_CASE_C

    default: panic("unsupported type = %d", type);
  }
}

#ifdef CONFIG_FTRACE
const char *get_function_name(paddr_t addr);

static void ftrace(int rd, int rs1, paddr_t pc, paddr_t dnpc) {
#define FUNC_NAME_MAX 128
#define FRONT_MSG "FTrace: " FMT_PADDR ": ", pc
#define RET_MSG "ret  [%s]\n", pc_func_name
#define CALL_MSG "call [%s @ " FMT_PADDR "]\n", dnpc_func_name, dnpc
#define PRINT_MSG(cmd) do { \
  if (is_ret) { \
    cmd(FRONT_MSG); \
    for (i = 0; i < cnt - 1; i++) cmd("| "); \
    cmd(RET_MSG); \
  } \
  if (is_call) { \
    cmd(FRONT_MSG); \
    for (i = 0; i < cnt - 1; i++) cmd("| "); \
    cmd(CALL_MSG); \
  }} while(0) 

  static int cnt = 0;
  static bool last_is_ret = false;
  bool is_call = false;
  bool is_ret = false;
  bool rd_is_addr = rd == 1 || rd == 5;
  bool rs1_is_addr = rs1 == 1 || rs1 == 5;

  if (rd_is_addr) {
    is_call = true;
    if (!last_is_ret) {
      cnt++;
    }
    last_is_ret = false;
  }
  if (rd != rs1 && rs1_is_addr) {
    is_ret = true;
    if (last_is_ret) {
      cnt--;
    }
    last_is_ret = true;
  }

  const char *pc_func_name_raw = get_function_name(pc);
  const char *pc_func_name = (pc_func_name_raw == NULL || *pc_func_name_raw == '\0') ? 
    "???" : pc_func_name_raw;
  const char *dnpc_func_name_raw = get_function_name(dnpc);
  const char *dnpc_func_name = (dnpc_func_name_raw == NULL || *dnpc_func_name_raw == '\0') ? 
    "???" : dnpc_func_name_raw;
  int i;
#ifdef CONFIG_FTRACE_COND
  if (FTRACE_COND) {
    PRINT_MSG(log_write);
  }
#endif 
  if (g_print_step) {
    PRINT_MSG(printf);
  }
}
#endif

bool is_npc_skip(vaddr_t addr) {
#define NPC_SKIP_COMPARE(addr, name) do { \
    if ((addr) >= (CONFIG_NPC_ ## name ## _START) && (addr) <= (CONFIG_NPC_ ## name ## _END)) { \
      return true; \
    } \
  } while(0)
#define NPC_SKIP(addr, name) IFDEF(CONFIG_NPC_SKIP_ ## name, NPC_SKIP_COMPARE(addr, name))

  NPC_SKIP(addr, CLINT);
  NPC_SKIP(addr, SRAM);
  NPC_SKIP(addr, UART);
  NPC_SKIP(addr, SPI);
  NPC_SKIP(addr, GPIO);
  NPC_SKIP(addr, PS2);
  NPC_SKIP(addr, MROM);
  NPC_SKIP(addr, VGA);
  NPC_SKIP(addr, FLASH);
  NPC_SKIP(addr, CHIPLINK_MMIO);
  NPC_SKIP(addr, PSRAM);
  NPC_SKIP(addr, SDRAM);
  NPC_SKIP(addr, CHIPLINK_MEM);

  return false;
}

void mmio_check(vaddr_t addr) {
  if (is_npc_skip(addr)) {
    // Log("Skip by menuconfig. addr: %x", addr);
    difftest_skip_ref();
    return;
  }
  fetch_mmio_map(addr);
}

static int decode_inst(Decode *s) {
#define INSTPAT_INST(s) ((s)->isa.inst)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
  int rd = 0, rs1 = 0, rs2 = 0; \
  word_t src1 = 0, src2 = 0, imm = 0; \
  decode_operand(s, &rd, &rs1, &rs2, &src1, &src2, &imm, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}
#define SIGN(x) ({word_t _us = (x); sword_t _s; memcpy(&_s, &_us, sizeof(_s)); _s;})
#define SHIFT_RA(n, b) ((n) >> 31 ? (n) >> BITS((b), 4, 0) | \
								~BITMASK(32 - BITS((b), 4, 0)) : \
								(n) >> BITS((b), 4, 0))
#define MUX_DIV_ZERO(y, normal_result, zero_result) ((y) ? (normal_result) : (zero_result))
#define MUX_DIV_OVERFLOW(x, y, normal_result, overflow_result) \
	(SIGN(x) == INT32_MIN && SIGN(y) == -1 ? (overflow_result) : (normal_result))
								

  INSTPAT_START();
  INSTPAT("???????????????? 001 ? ?? ??? ?? ??? 01", c_jal , CJ_CJ, \
      IFDEF(CONFIG_FTRACE, ftrace(1, rs1, s->pc, s->dnpc)));
  INSTPAT("???????????????? 100 0 ?? ??? 00 000 10", c_jr , CR_CNONE, \
      IFDEF(CONFIG_FTRACE, ftrace(0, rs1, s->pc, s->dnpc)));
  INSTPAT("???????????????? 100 1 ?? ??? 00 000 10", c_jalr , CR_CNONE, \
      IFDEF(CONFIG_FTRACE, ftrace(1, rs1, s->pc, s->dnpc)));

  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal    , J, \
      IFDEF(CONFIG_FTRACE, ftrace(rd, rs1, s->pc, s->dnpc)));
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr   , I, \
      IFDEF(CONFIG_FTRACE, ftrace(rd, rs1, s->pc, s->dnpc)));

  INSTPAT("???????????????? 010 ? ?? ??? ?? ??? 00", c_lw , CL_CLSW, \
      mmio_check(src1 + imm));
  INSTPAT("???????????????? 110 ? ?? ??? ?? ??? 00", c_sw , CS_CLSW, \
      mmio_check(src1 + imm));
  INSTPAT("???????????????? 010 ? ?? ??? ?? ??? 10", c_lwsp , CI_CLWSP, \
      mmio_check(R(2) + imm));
  INSTPAT("???????????????? 110 ? ?? ??? ?? ??? 10", c_swsp , CSS_CSWSP, \
      mmio_check(R(2) + imm));

  INSTPAT("??????? ????? ????? 000 ????? 00000 11", lb     , I, \
      mmio_check(src1 + imm));
  INSTPAT("??????? ????? ????? 100 ????? 00000 11", lbu    , I, \
      mmio_check(src1 + imm));
  INSTPAT("??????? ????? ????? 001 ????? 00000 11", lh     , I, \
      mmio_check(src1 + imm));
  INSTPAT("??????? ????? ????? 101 ????? 00000 11", lhu    , I, \
      mmio_check(src1 + imm));
  INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, \
      mmio_check(src1 + imm));
  INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, \
      mmio_check(src1 + imm));
  INSTPAT("??????? ????? ????? 001 ????? 01000 11", sh     , S, \
      mmio_check(src1 + imm));
  INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, \
      mmio_check(src1 + imm));
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, );
  INSTPAT_END();

  return 0;
}

void sim_close(void);
void print_disassemble(Decode *);
// void restart(void);
extern CPU_state npc_state;
extern ISADecodeInfo npc_inst;
extern paddr_t npc_pc;
// extern paddr_t npc_dnpc;
extern int npc_is_jump;
extern uint32_t npc_jump_target;
extern int npc_stop_flag;
extern int npc_wbu_valid;
extern bool g_cpu_stop_flag;
extern uint64_t g_nr_guest_cyc;

int isa_exec_once(Decode *s) {
  static int inst_cyc_cnt = 0;
  s->dnpc = s->pc;

  while (npc_wbu_valid == 0) {
    if (g_cpu_stop_flag) {
      difftest_skip_ref();
      return 0;
    }
    single_cycle(); 
    sync_npc_gpr();
    inst_cyc_cnt++;
    if (inst_cyc_cnt >= 50000 && inst_cyc_cnt % 10000 == 0) {
      printf("[npc] Warning: A instruction has been executed for %d cycles at " FMT_WORD "\n", inst_cyc_cnt, s->pc);
    }
  }
  s->isa.inst = npc_inst.inst;
  bool is_c = (s->isa.inst & 3u) != 3u;
  // s->snpc = s->pc + (is_c ? 2 : 4);
  s->snpc = npc_pc + (is_c ? 2 : 4);
  s->dnpc = npc_is_jump ? npc_jump_target : s->snpc;
#ifdef CONFIG_ITRACE
  if (g_print_step) {
    printf("Executing %dcyc @" FMT_WORD "\n", inst_cyc_cnt, s->pc);
  }
  log_write("Executing %dcyc @" FMT_WORD "\n", inst_cyc_cnt, s->pc);
  print_disassemble(s);
#endif
  decode_inst(s);

  if (npc_stop_flag != 0) {
    set_nemu_state(NEMU_END, s->pc, gpr(10));
  }

  single_cycle(); 
  sync_npc_gpr();
  inst_cyc_cnt++;
  g_nr_guest_cyc += inst_cyc_cnt;
  inst_cyc_cnt = 0;

  return 0;
}

__END_DECLS
