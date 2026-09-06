#include "common.h"
#include <assert.h>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <dlfcn.h>

#define CHECK_CSR(x)                                                           \
  if (ref_context->csr.x != cpu->commit.csr.x) {                               \
    printf("difftest failed at csr " #x "\n");                                 \
    printf(#x "[npc]: 0x%08x -> [nemu]: 0x%08x\n", cpu->commit.csr.x,          \
           ref_context->csr.x);                                                \
    goto regdiferror;                                                          \
  }

#define DIS_CSR(x)                                                             \
  printf(#x "[npc]: 0x%08x -> [nemu]: 0x%08x\n", cpu->commit.csr.x,            \
         ref_context->csr.x);

#ifdef DIFFTEST
void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction);
void (*ref_difftest_regcpy)(void *dut, bool direction);
void (*ref_difftest_exec)(uint64_t n);
void (*ref_difftest_init)(int port);
uint32_t (*ref_difftest_get_mem)(uint32_t addr);

enum { DIFF_TO_DUT, DIFF_TO_REF };
extern Cpu *cpu;
static bool inst_ref_skip = false;
static int inst_skip_nr = 0;

static constexpr uint32_t INST_ECALL = 0x00000073;
static constexpr uint32_t INST_MRET = 0x30200073;

// fit for nemu
struct DifftestCsr {
  uint32_t mepc;
  uint32_t sepc;
  uint32_t misa;
  uint32_t mstatus;
  uint32_t mstatush;
  uint32_t mcause;
  uint32_t mtval;
  uint32_t mtvec;
  uint32_t mscratch;
  uint32_t satp;
  uint32_t medeleg;
  uint32_t mideleg;
  uint32_t mvendorid;
  uint32_t marchid;
  uint32_t mhartid;
  uint32_t mimpid;
  uint32_t pmpaddr0;
  uint32_t pmpaddr1;
  uint32_t pmpaddr2;
  uint32_t pmpaddr3;
  uint32_t pmpaddr4;
  uint32_t pmpaddr5;
  uint32_t pmpaddr6;
  uint32_t pmpaddr7;
  uint32_t pmpcfg0;
  uint32_t pmpcfg1;
  uint32_t scause;
  uint32_t stval;
  uint32_t sscratch;
  uint32_t stvec;
  uint32_t mie;
  uint32_t mcounteren;
  uint32_t scounteren;
  uint32_t mcountinhibit;
};

struct DifftestContext {
  uint32_t gpr[32];
  uint32_t pc;
  uint32_t priv;
  DifftestCsr csr;
};

static_assert(offsetof(DifftestContext, pc) == 0x80,
              "unexpected difftest pc offset");
static_assert(offsetof(DifftestContext, priv) == 0x84,
              "unexpected difftest privilege offset");
static_assert(offsetof(DifftestContext, csr) == 0x88,
              "unexpected difftest CSR offset");
static_assert(sizeof(DifftestContext) == 0x110,
              "NPC/NEMU difftest context ABI mismatch");

static void pack_context(DifftestContext *dst, const context *src) {
  *dst = {};
  std::memcpy(dst->gpr, src->gpr, sizeof(dst->gpr));
  dst->pc = src->pc;
  // NEMU uses 1 for machine mode (DIFFTEST_RISCV_PRIV_M).
  dst->priv = 1;
  dst->csr.mstatus = src->csr.mstatus;
  dst->csr.mtvec = src->csr.mtvec;
  dst->csr.mepc = src->csr.mepc;
  dst->csr.mcause = src->csr.mcause;
}

static void unpack_context(context *dst, const DifftestContext *src) {
  std::memcpy(dst->gpr, src->gpr, sizeof(dst->gpr));
  dst->pc = src->pc;
  dst->csr.mstatus = src->csr.mstatus;
  dst->csr.mtvec = src->csr.mtvec;
  dst->csr.mepc = src->csr.mepc;
  dst->csr.mcause = src->csr.mcause;
}

void set_ref_skip() {
  inst_ref_skip = true;
  inst_skip_nr = 0;
}

void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(uint32_t, void *, size_t, bool))dlsym(
      handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy =
      (void (*)(void *, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_init = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  ref_difftest_get_mem =
      (uint32_t (*)(uint32_t))dlsym(handle, "difftest_get_mem");
  assert(ref_difftest_get_mem);

  ref_difftest_init(port);
  ref_difftest_memcpy(MBASE, guest_to_host(MBASE), 0xfff, DIFF_TO_REF);
  ref_difftest_memcpy(FBASE, guest_to_host(FBASE), 0xfffffff, DIFF_TO_REF);
  ref_difftest_memcpy(PSBASE, guest_to_host(PSBASE), 0x400000, DIFF_TO_REF);
  DifftestContext initial_context{};
  pack_context(&initial_context, &cpu->con);
  ref_difftest_regcpy(&initial_context, DIFF_TO_REF);
}

extern Npc *npc;
void checkregs(context *ref_context) {
  int i = 0;

  // if (ref_context->pc != cpu->commit.pc) {
  //   printf("pc: 0x%08x -> 0x%08x\n", cpu->commit.pc, ref_context->pc);
  //   goto regdiferror;
  // }

  for (i = 1; i < 32; i++) {
    if (ref_context->gpr[i] != cpu->commit.gpr[i]) {
      goto regdiferror;
    }
  }

  CHECK_CSR(mstatus);
  CHECK_CSR(mepc);
  CHECK_CSR(mtvec);
  CHECK_CSR(mcause);
  return;

regdiferror:
  printf("the difftest failed at pc %08x\n", cpu->commit.pc);
  if (i < 32)
    printf("reg[%d]: 0x%08x -> 0x%08x\n", i, cpu->commit.gpr[i],
           ref_context->gpr[i]);
  for (i = 0; i < 32; i++) {
    printf("reg[%d] npc:0x%08x nemu:0x%08x\n", i, cpu->commit.gpr[i],
           ref_context->gpr[i]);
  }
  DIS_CSR(mstatus);
  DIS_CSR(mtvec);
  DIS_CSR(mepc);
  DIS_CSR(mcause);
  npc_diff_quit();
}

void diff_step() {
  if (inst_ref_skip == true) {
    // to skip the checking of an instruction, just copy the reg state to
    // reference design
    inst_ref_skip = false;
    inst_skip_nr = 1;
    DifftestContext cpu_commit{};
    pack_context(&cpu_commit, &cpu->commit);
    cpu_commit.pc =
        cpu_commit.pc + 4; // as every inst need tobe skip is load/store
    ref_difftest_regcpy(&cpu_commit, DIFF_TO_REF);
    return;
  }

  DifftestContext ref_context{};
  context ref_state{};
  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_context, DIFF_TO_DUT);

  if (cpu->inst == INST_ECALL || cpu->inst == INST_MRET) {
    // Preserve NEMU's post-trap PC and privilege while aligning compared state.
    std::memcpy(ref_context.gpr, cpu->commit.gpr,
                sizeof(ref_context.gpr));
    ref_context.csr.mstatus = cpu->commit.csr.mstatus;
    ref_context.csr.mtvec = cpu->commit.csr.mtvec;
    ref_context.csr.mepc = cpu->commit.csr.mepc;
    ref_context.csr.mcause = cpu->commit.csr.mcause;
    ref_difftest_regcpy(&ref_context, DIFF_TO_REF);
  }

  unpack_context(&ref_state, &ref_context);
  checkregs(&ref_state);
}

void difftest_check_mem(uint32_t addr, uint32_t npc, size_t size) {
  uint32_t ref = ref_difftest_get_mem(addr);
  if (size == 1) {
    ref = (uint8_t)ref;
  } else if (size == 2) {
    ref = (uint16_t)ref;
  } else if (size == 4) {
    ref = (uint32_t)ref;
  } else {
    assert(0);
  }
  if (npc != ref) {
    printf("difftest failed at mem 0x%08x\n", addr);
    printf("mem npc: 0x%08x nemu: 0x%08x\n", npc, ref);
    npc_diff_quit();
  }
}

#endif
