#include "npc.h"
#include "device.h"
#include "memory.h"
#include "svdpi.h"
#include "tpdef.h"
#include "util.h"
#include <cassert>

#ifdef RUNSOC
#include "nvboard.h"
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"

#define REG       (top.rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_reg__DOT__rf)
#define CPU_PC    (top.rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_arbiter__DOT__endpc)
#define ADDR      (top.rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__u_arbiter__DOT__endaddr)
#else
#include "Vysyx_25040111.h"
#include "Vysyx_25040111___024root.h"

#define REG       (top.rootp->ysyx_25040111__DOT__u_reg__DOT__rf)
#define CPU_PC    (top.rootp->ysyx_25040111__DOT__u_arbiter__DOT__endpc)
#define ADDR      (top.rootp->ysyx_25040111__DOT__u_arbiter__DOT__endaddr)
#endif // RUNSOC

#include <cstdio>
#include <verilated.h>
#include <verilated_vcd_c.h>

#define VCD_PATH  "/home/dallous/Documents/ysyx-workbench/npc/waveform/waveform.vcd"

#ifdef RUNSOC
typedef VysyxSoCFull mtop;

void nvboard_renew();
void nvboard_initialize(VysyxSoCFull *top);
void nvboard_free();
#else
typedef Vysyx_25040111 mtop;
#endif // RUNSOC

// #define EN_TRACE
// #define ITRACE
// #define FTRACE
// #define MTRACE
// #define DIFFTEST

static mtop top;
static VerilatedVcdC *vtrace = nullptr;
static bool vstart = false;
void start_v() {vstart = true;}

// 用于计数时钟边沿
static vluint64_t sim_time = 0;
static uint64_t inst_num = 0;
uint64_t get_inst_num() { return inst_num; }

// regiestor name
static const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    // "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    // "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

uint32_t npc_stat = -1;
static word_t currpc = 0;

// cpi 计算
int64_t cyc_num = 0;


// initialize npc resource
void npc_init(bool vcd, int argc, char** argv)
{
	Verilated::commandArgs(argc, argv);

	if (vcd)
	{
		// set vcd
		Verilated::traceEverOn(true);
		vtrace = new VerilatedVcdC;
		top.trace(vtrace, 5);
		vtrace->open(VCD_PATH);
	}

#ifdef RUNSOC
  nvboard_initialize(&top);
#endif

  // reset
	top.reset = 1;
  for (int i = 0; i < 20; i++)
  {
    top.clock = 0; top.eval();
    top.clock = 1; top.eval();
  }
	top.reset = 0;

	npc_stat = NPC_RUN;
}


static void ftrace(paddr_t pc, paddr_t call, word_t inst)
{
  const char *ftrace_get_name(paddr_t addr);

  static const uint8_t jal = 0b1101111;
  static const uint8_t jalr = 0b1100111;

  uint8_t opt = BITS(inst, 6, 0);
  uint8_t rd = BITS(inst, 11, 7);

  if (opt == jal || opt == jalr)
  {
    const char *dst = ftrace_get_name(call);
    const char *src = ftrace_get_name(pc);

    if (rd == 1)
      printf(ANSI_FMT("[0x%x in %s] call [%s 0x%x]\n", ANSI_FG_CYAN), pc, src,
             dst, call);
    else if (rd == 0 && strcmp(dst, src))
      printf(ANSI_FMT("[0x%x in %s] ret  [%s 0x%x]\n", ANSI_FG_CYAN), pc, src,
             dst, call);
  }
}


// print execute infomation
static void print_exe_info(word_t tpc, word_t tinst, char *logbuf, size_t buflen)
{
  char *p = logbuf;
  p += snprintf(p, buflen, "0x%08x: ", tpc);

  uint8_t *inst = (uint8_t *)&tinst;
  for (int i = 3; i >= 0; i--)
    p += snprintf(p, 4, " %02x", inst[i]);

  *p = '\t';
  p++;

  disassemble(p, logbuf + buflen - p, tpc, (uint8_t *)&tinst, 4);
}


// get instruct
word_t sdram_read_expr(word_t addr);
static word_t inst_get(word_t addr)
{

#ifdef RUNSOC
  if (addr >= FLASH_START && addr < FLASH_END)
    return paddr_read(addr, 4);
  else if (addr >= SDRAM_START && addr < SDRAM_END)
    return sdram_read_expr(addr - SDRAM_START);
#else
  if (addr >= 0x80000000 && addr < 0x81000000)
    return paddr_read(addr, 4);
#endif

  assert(1);
  return 0;
}


// execute
void pmc_print();
void cycle_counter(word_t inst, int64_t ncyc);
int cpu_exec(uint64_t steps)
{
  void check_wp();

  if (npc_stat != NPC_RUN)
  {
    printf(ANSI_FMT("Program is stop!\n", ANSI_FG_MAGENTA));
    return 0;
  }

  uint64_t step_ok = 0;
  char logbuf[128] = {};
  currpc = CPU_PC;
  while (steps--)
  {
#ifdef RUNSOC
    nvboard_renew();
#endif
    top.clock = 0; top.eval();
    if (vtrace && vstart)
      vtrace->dump(sim_time++);
    top.clock = 1; top.eval();
    if (vtrace && vstart)
      vtrace->dump(sim_time++);

    cyc_num++;

    if (CPU_PC != currpc)
    {
      currpc = CPU_PC;
      word_t inst = inst_get(CPU_PC);
      cycle_counter(inst, cyc_num);
      cyc_num = 0;
      inst_num++;

#if defined(EN_TRACE) && defined(ITRACE)
      print_exe_info(CPU_PC, inst, logbuf, 128);
      printf("%s\n", logbuf);
#endif // ITRACE

#if defined(EN_TRACE) && defined(FTRACE)
      ftrace(currpc, CPU_PC, inst);
#endif // FTRACE

      check_wp();

#ifdef DIFFTEST
      // printf("currpc : %08x\n", currpc);
      if (device_visit(ADDR, inst))
        difftest_nop(currpc + 4);
      else if (!difftest_step(CPU_PC))
        npc_stat = NPC_STOP;
#endif // DIFFTEST
    }

    switch (npc_stat)
    {
    case NPC_RUN:
      step_ok++;
      break;
    case NPC_STOP:
      return step_ok;
    case NPC_ABORT:
      printf("ebreak [" ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED) "]\n");
      return step_ok;
    case NPC_END:
      printf("ebreak [" ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) "]\n");
      pmc_print();
      return step_ok;
    default:
      finalize(1);
    }
  }

  return step_ok;
}


// print regiestor
void reg_print()
{
  for (int i = 0; i < ARRLEN(regs); ++i)
  {
    int j = i + 4;
    for (; i < j; ++i)
      printf("[%s] 0x%08x\t", regs[i], REG[i]);
    putchar('\n');
    --i;
  }
}


// get regiestor value
word_t reg_get_value(char *s, bool *success)
{
  if (s == NULL || success == NULL)
  {
    if (success == NULL)
      return 0;

    *success = false;
    return 0;
  }

  if (strcmp(s, "pc") == 0)
  {
    *success = true;
    return CPU_PC;
  }

  int i = 0;
  for (; i < ARRLEN(regs); i++)
  {
    if (strcmp(s, regs[i]) == 0)
      break;
  }

  if (i == ARRLEN(regs))
  {
    *success = false;
    return 0;
  }

  *success = true;
  return REG[i];
}


// get reg values
void reg_value(word_t *regbuf)
{
  int i = 0;
  for (; i < ARRLEN(regs); i++)
  {
    regbuf[i] = REG[i];
  }
}


const char *reg_name(int idx) {
  if (idx >= 0 && idx < 16)
  {
    return regs[idx];
  }
  return "???";
}


// free npc resource
void npc_free()
{
  if (vtrace)
  {
    vtrace->close();
    delete vtrace;
  }

#ifdef RUNSOC
  nvboard_quit();
#endif
}


// inst: ebreak
extern "C" void ebreak(int code)
{
	if (code)
	{
		npc_stat = NPC_ABORT;
		if (code == 9)
		{
			char logbuf[128] = {};
			print_exe_info(CPU_PC, paddr_read(CPU_PC, 4), logbuf, 128);
			printf(ANSI_FMT("[unrealized] %s\n", ANSI_FG_RED), logbuf);
		}
	} else npc_stat = NPC_END;
}


extern "C" int pmem_read(int raddr)
{
	paddr_t address = raddr & ~0x3u;
	word_t rdata = 0;

  if (likely(in_pmem(address)))
    rdata = paddr_read(address, 4);
  else if (!device_call((paddr_t)raddr, &rdata, false))
    finalize(2);

#if defined(EN_TRACE) && defined(MTRACE)
	// mtrace memory read
	word_t minst = paddr_read(CPU_PC, 4);
	if (raddr != CPU_PC && 0b0000011 == BITS(minst, 6, 0))
	{
		printf(ANSI_FMT("[read mem] address: 0x%08x; data: 0x%08x; pc: 0x%08x;\n",
						ANSI_FG_CYAN),
			(word_t)raddr, rdata, CPU_PC);
	}
#endif // MTRACE

	// 总是读取地址为`raddr & ~0x3u`的4字节返回
	return (int)rdata;
}


static void pmem_write_core(paddr_t address, int wdata, char wmask)
{
	// 读出当前地址上的完整 4 字节
	word_t wdata_ = paddr_read(address, 4);

	// 使用掩码逐字节合成新的数据
	for (int i = 0; i < 4; ++i)
	{
		if (wmask & (1 << i))
		{
			// 替换 old_data 中对应字节为 wdata 中对应的字节
			uint8_t byte = ((word_t)wdata >> (8 * i)) & 0xFF;
			wdata_ &= ~(0xFFu << (8 * i));       // 清空对应位置
			wdata_ |= ((word_t)byte << (8 * i)); // 写入对应字节
		}
	}

	// 按4字节对齐写入
	paddr_write(address, 4, wdata_);
}


extern "C" void pmem_write(int waddr, int wdata, char wmask)
{
	// 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
	// `wmask`中每比特表示`wdata`中1个字节的掩码
	// 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变

	paddr_t address = waddr & ~0x3u;

#if defined(EN_TRACE) && defined(MTRACE)
	// mtrace memory write
	word_t minst = paddr_read(CPU_PC, 4);
	if (0b0100011 == BITS(minst, 6, 0))
	{
		printf(ANSI_FMT("[write mem] address: 0x%08x; data: 0x%08x; pc: 0x%08x; "
						"mask: 0x%02x;\n",
						ANSI_FG_CYAN),
			(paddr_t)waddr, (word_t)wdata, CPU_PC, wmask);
	}
#endif // MTRACE

	if (likely(in_pmem(address)))
	{
		pmem_write_core(address, wdata, wmask);
		return;
	}
	if (device_call((paddr_t)waddr, &wdata, true))
		return;

	finalize(2);
}
