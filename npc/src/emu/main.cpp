#include "common.h"
#include "utils.h"

#include EMU_TOP_H
#ifndef GSIM
#include EMU_TOP_024ROOT_H
#endif

#ifdef HAS_NVBOARD
#include <nvboard.h>
#endif

#define DIFFTEST
#ifdef NETLIST_SIM  // defined in CFLAGS
#undef DIFFTEST
#endif

#ifdef WAVEFORM
#include "verilated_fst_c.h"
#endif

#ifdef YSYXSOC
//#define HAS_MROM
#define HAS_FLASH
#define MAX_IDLE_CYCLE 20000
#else
#define MAX_IDLE_CYCLE 100
#endif

#define PMEM_BASE  0x80000000
#define PMEM_SIZE  (128 * 1024 * 1024)
#define MROM_BASE  0x20000000
#define MROM_SIZE  0x1000
#define FLASH_BASE 0x30000000
#define FLASH_SIZE (16 * 1024 * 1024)
#define SRAM_BASE  0x0f000000
#define SRAM_SIZE  0x2000

void init_difftest(const char *ref_so_file, word_t *dut_r, void *mem, long img_size);
bool difftest_step(void *dut_r, uint32_t thispc, uint32_t npc);
void difftest_skip_ref();
void init_time();
uint64_t get_time();

static EMU_TOP *top = NULL;
static uint8_t *pmem = NULL;
static uint8_t mrom[MROM_SIZE];
static uint8_t flash[FLASH_SIZE];
static uint64_t cycles = 0, insts = 0;

#ifdef GSIM
static void step() { top->step(); }
static void step_wave(void *contextp, void *tfp) { step(); }
#else
static void step() { top->clock = 0; top->eval(); top->clock = 1; top->eval(); }
static void step_wave(const std::unique_ptr<VerilatedContext> &contextp, VerilatedFstC* tfp) {
#ifdef WAVEFORM
    contextp->timeInc(1);
#endif
    step();
#ifdef WAVEFORM
    tfp->dump(contextp->time());
#endif
}
#endif

static void reset(int n,
#ifdef GSIM
    void *contextp, void *tfp
#else
    const std::unique_ptr<VerilatedContext> &contextp, VerilatedFstC* tfp
#endif
    ) {
  top->reset = 1;
  while (n --) { step_wave(contextp, tfp); }
  top->reset = 0;
}

static size_t load_prog(const char *bin) {
  FILE *fp = fopen(bin, "r");
  assert(fp);
#ifdef HAS_MROM
  size_t s = fread(mrom, 1, MROM_SIZE, fp);
#elif defined(HAS_FLASH)
  size_t s = fread(flash, 1, FLASH_SIZE, fp);
#else
  size_t s = fread(pmem, 1, PMEM_SIZE, fp);
#endif
  fclose(fp);
  Log("image size = %zd", s);
  return s;
}

static uint32_t addr2idx(uint32_t addr, uint32_t base) {
  return (addr - base) & ~(XLEN == 64 ? 0x7ul : 0x3ul);
}

extern "C" sword_t pmem_read(int32_t raddr) {
  uint32_t idx = addr2idx(raddr, PMEM_BASE);
  return (idx < PMEM_SIZE ? *(sword_t *)(pmem + idx) : 0);
}

extern "C" void pmem_write(int32_t waddr, sword_t wdata, uint8_t wmask) {
  if (waddr == 0x10000000) { fputc(wdata, stderr); }
  else {
    uint32_t idx = addr2idx(waddr, PMEM_BASE);
    for (int i = 0; i < sizeof(word_t); i ++) {
      if (wmask & 0x1) { pmem[idx + i] = wdata & 0xff; }
      wmask >>= 1;
      wdata >>= 8;
    }
  }
}

extern "C" void mrom_read(int32_t addr, int32_t *data) {
  uint32_t idx = addr2idx(addr, MROM_BASE);
  *data = (idx < MROM_SIZE ? *(sword_t *)(mrom + idx) : 0);
}

extern "C" void flash_read(int32_t addr, int32_t *data) {
  assert(addr < FLASH_SIZE);
  *data = *(int32_t *)(flash + addr);
}

static struct {
  bool valid, isEbreak, isMMIO, skip;
  word_t code;
  uint32_t memAddr, pc, dnpc;
} commit;

extern "C" void set_commit(uint8_t valid, int32_t pc, int32_t dnpc, uint8_t isEbreak,
    word_t code, uint8_t isMMIO, int32_t memAddr, uint8_t skip) {
  commit.valid = valid;
  if (valid) {
    commit.pc = pc;
    commit.dnpc = dnpc;
    commit.isEbreak = isEbreak;
    commit.code = code;
    commit.isMMIO = isMMIO;
    commit.memAddr = memAddr;
    commit.skip = skip;
  }
}

void NPCTrap(uint8_t valid, uint32_t pc, uint32_t dnpc, uint8_t isEbreak,
    word_t code, uint8_t isMMIO, uint32_t memAddr, uint8_t skip) {
  set_commit(valid, pc, dnpc, isEbreak, code, isMMIO, memAddr, skip);
}

void SimDMEM(uint8_t ren, uint32_t raddr, uint32_t &rdata,
    uint8_t wen, uint32_t waddr, uint32_t wdata, uint8_t wmask) {
  rdata = ren ? pmem_read(raddr) : 0;
  if (wen) pmem_write(waddr, wdata, wmask);
}

static void init_difftest0(void *dut_r, size_t img_size) {
  word_t reset_pc = PMEM_BASE; void *dut_mem = pmem;
#ifdef HAS_MROM
  reset_pc = MROM_BASE; dut_mem = mrom;
#elif defined(HAS_FLASH)
  reset_pc = FLASH_BASE; dut_mem = flash;
#endif
  word_t regs[NR_REGS + 1]; // +1 for PC
  memcpy(regs, dut_r, sizeof(regs[0]) * NR_REGS);
  regs[NR_REGS] = reset_pc;
  init_difftest(REF_SO_FILE, regs, dut_mem, img_size); // now img_size is more than the memory to sync
}

int main(int argc, char *argv[]) {
  pmem = (uint8_t *)malloc(PMEM_SIZE);
  assert(pmem != NULL);
  size_t img_size = load_prog(argv[1]);
  uint64_t last_commit_cycle = 0;
  int exit_code = 0;
  top = new EMU_TOP;

#ifdef HAS_NVBOARD
  void nvboard_bind_all_pins(EMU_TOP* top);
  nvboard_bind_all_pins(top);
  nvboard_init();
#endif

#ifndef GSIM
#ifdef WAVEFORM
  Verilated::traceEverOn(true);
  const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
  VerilatedFstC* tfp = new VerilatedFstC;
  top->trace(tfp, 99);  // Trace 99 levels of hierarchy (or see below)
                         // tfp->dumpvars(1, "t");  // trace 1 level under "t"
  tfp->open("wave.fst");
  tfp->dump(contextp->time());
#else
  const std::unique_ptr<VerilatedContext> contextp{nullptr};
  VerilatedFstC* tfp = NULL;
#endif

  Verilated::commandArgs(argc, argv);
#else
  void *contextp = NULL, *tfp = NULL;
#endif

  reset(10, contextp, tfp);
#ifdef DIFFTEST
#ifdef GSIM
  void *dut_r = &top->npc$idu$R;
#else
  void *dut_r = &top->rootp->concat(NPC_MODULE_PATH, __DOT__idu__DOT__R_ext__DOT__Memory);
#endif
  init_difftest0(dut_r, img_size);
#endif

  init_time();

  while (true) {
#ifdef HAS_NVBOARD
    nvboard_update();
#endif
    step_wave(contextp, tfp);
    cycles ++;
#ifndef NETLIST_SIM
    if (cycles - last_commit_cycle > MAX_IDLE_CYCLE) {
      printf("No instructions commit in %d cycles, maybe get stuck!\n", MAX_IDLE_CYCLE);
      exit_code = 2;
      break;
    }
#endif
    if (commit.valid) {
      insts ++;
      last_commit_cycle = cycles;
#ifndef NETLIST_SIM
      if (commit.isEbreak) {
        exit_code = commit.code;
        printf("npc: %s\n", (exit_code == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
                                              ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED)));
        break;
      }
      if (commit.dnpc == 0) {
        printf("Jump to 0. Maybe there is an exeption.\n");
        exit_code = 3;
        break;
      }
#endif
#ifdef DIFFTEST
      if (commit.isMMIO) { // it seems that store instrucitons perform one cycle earlier in top->eval()
        bool in_rom   = (commit.memAddr >= MROM_BASE)  && (commit.memAddr < MROM_BASE + MROM_SIZE);
        bool in_flash = (commit.memAddr >= FLASH_BASE) && (commit.memAddr < FLASH_BASE + FLASH_SIZE);
        bool in_sram  = (commit.memAddr >= SRAM_BASE)  && (commit.memAddr < SRAM_BASE + SRAM_SIZE);
        if (!in_rom && !in_flash && !in_sram) { difftest_skip_ref(); }
      }
      if (commit.skip) { difftest_skip_ref(); }
      if (difftest_step(dut_r, commit.pc, commit.dnpc) == false) {
        step_wave(contextp, tfp); // step one more time to dump more wave
        exit_code = 2;
        break;
      }
#endif
    }
  }

#ifdef WAVEFORM
  tfp->close();
#endif

  double s = (double)get_time() / 1000000;
  printf("finish after %ld cycles, %le s, simulation freq = %le KHz\n", cycles, s, cycles / s / 1000);
  printf("#inst = %ld, IPC = %lf\n", insts, (double)insts/cycles);

  delete top;
  return exit_code;
}
