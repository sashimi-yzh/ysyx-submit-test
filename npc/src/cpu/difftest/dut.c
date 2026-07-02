#include <dlfcn.h>

#include <isa.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>
#include <utils.h>
#include <difftest-def.h>
#include <platform/platform.h>

#ifdef CONFIG_DIFFTEST

static void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
static void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
static void (*ref_difftest_exec)(uint64_t n) = NULL;

#define OPCODE_LOAD  0x03u
#define OPCODE_STORE 0x23u

static inline sword_t sext(uint32_t val, int bits) {
  uint32_t mask = 1u << (bits - 1);
  return (sword_t)((val ^ mask) - mask);
}

static bool should_skip_ref(uint32_t inst, const CPU_state *ref) {
  uint32_t opcode = inst & 0x7fu;
  if (opcode != OPCODE_LOAD && opcode != OPCODE_STORE) {
    return false;
  }

  uint32_t rs1 = BITS(inst, 19, 15);
  sword_t imm = 0;
  if (opcode == OPCODE_LOAD) {
    imm = sext(BITS(inst, 31, 20), 12);
  } else {
    imm = sext((BITS(inst, 31, 25) << 5) | BITS(inst, 11, 7), 12);
  }

  return !platform_in_comparable_mem(ref->gpr[rs1] + imm);
}

void init_difftest(char *ref_so_file, long img_size, int port) {
  Assert(ref_so_file != NULL, "DiffTest is enabled but ref_so_file is NULL");
  Assert(img_size >= 0,
      "DiffTest image size is negative: img_size=%ld", img_size);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  Assert(handle != NULL, "Can not open DiffTest reference '%s': %s",
      ref_so_file, dlerror());

  ref_difftest_memcpy = dlsym(handle, "difftest_memcpy");
  Assert(ref_difftest_memcpy, "Can not find DiffTest symbol 'difftest_memcpy'");

  ref_difftest_regcpy = dlsym(handle, "difftest_regcpy");
  Assert(ref_difftest_regcpy, "Can not find DiffTest symbol 'difftest_regcpy'");

  ref_difftest_exec = dlsym(handle, "difftest_exec");
  Assert(ref_difftest_exec, "Can not find DiffTest symbol 'difftest_exec'");

  void (*ref_difftest_init)(int) = dlsym(handle, "difftest_init");
  Assert(ref_difftest_init, "Can not find DiffTest symbol 'difftest_init'");
  void (*ref_enable_ysyxsoc_paddr)(void) = dlsym(handle, "difftest_enable_ysyxsoc_paddr");

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));

  platform_enable_ref_paddr(ref_enable_ysyxsoc_paddr);
  ref_difftest_init(port);
  platform_difftest_memcpy(ref_difftest_memcpy, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

static void checkregs(CPU_state *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    isa_reg_display();
  }
}

void difftest_step(vaddr_t pc, vaddr_t dnpc, uint32_t inst) {
  CPU_state ref_r;
  Assert((pc & 0x3) == 0 && (dnpc & 0x3) == 0,
      "DiffTest step pc is unaligned: pc=" FMT_WORD " dnpc=" FMT_WORD
      " inst=0x%08x",
      pc, dnpc, inst);

  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  if (should_skip_ref(inst, &ref_r)) {
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    return;
  }

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  Assert((ref_r.pc & 0x3) == 0,
      "DiffTest ref pc is unaligned: ref_pc=" FMT_WORD
      " dut_pc=" FMT_WORD " dut_npc=" FMT_WORD " inst=0x%08x",
      ref_r.pc, pc, dnpc, inst);

  checkregs(&ref_r, pc);
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) {
  (void)ref_so_file;
  (void)img_size;
  (void)port;
}
#endif
