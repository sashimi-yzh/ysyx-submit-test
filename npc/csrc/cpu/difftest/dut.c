#include <dlfcn.h>

#include <isa.h>
#include <difftest-def.h>
#include <npc/cpu.h>
#include <npc/diagnostics.h>
#include <npc/memory.h>
#include <npc/platform.h>

#ifdef CONFIG_DIFFTEST

typedef struct {
  void (*copy_mem)(paddr_t, void *, size_t, bool);
  void (*copy_regs)(void *, bool);
  void (*step)(uint64_t);
} RefApi;

static RefApi ref_api = {0};
static bool difftest_active = false;

#define LOAD_OP  0x03u
#define STORE_OP 0x23u

#define CSR_OP   0x73u

/* These read-only identity CSRs are platform-specific in the SoC RTL.  The
 * reference model reports zero for them, so comparing their destination
 * registers would abort a valid run before any shared-memory instruction. */
static bool is_soc_identity_csr(uint32_t inst) {
  if ((inst & 0x7fu) != CSR_OP) return false;
  uint32_t csr = BITS(inst, 31, 20);
  return csr >= 0xf11u && csr <= 0xf14u;
}

static bool skip_ref(uint32_t inst) {
  switch (inst & 0x7fu) {
    case LOAD_OP:
    case STORE_OP:
      return true;
    default:
      return is_soc_identity_csr(inst);
  }
}

static bool touches_sdram(vaddr_t pc, vaddr_t dnpc) {
  return address_in_window(pc, NPC_SDRAM_BASE, NPC_SDRAM_SIZE) || address_in_window(dnpc, NPC_SDRAM_BASE, NPC_SDRAM_SIZE);
}

static void push_cpu(void) {
  ref_api.copy_regs(&cpu, DIFFTEST_TO_REF);
}

static void pull_cpu(CPU_state *snapshot) {
  ref_api.copy_regs(snapshot, DIFFTEST_TO_DUT);
}

/* Flash/MMIO boot code is intentionally mirrored until the first SDRAM PC. */
static bool leave_boot_phase(vaddr_t pc, vaddr_t dnpc) {
  if (difftest_active) return true;

  push_cpu();
  if (!touches_sdram(pc, dnpc)) return false;

  difftest_copy_sdram(ref_api.copy_mem, DIFFTEST_TO_REF);
  push_cpu();
  difftest_active = true;
  Log("Differential testing starts in SDRAM at pc=" FMT_WORD, dnpc);
  return false;
}

static bool execute_reference(vaddr_t pc, uint32_t inst, CPU_state *snapshot) {
  if (!address_in_window(pc, NPC_SDRAM_BASE, NPC_SDRAM_SIZE)
      || skip_ref(inst)) {
    push_cpu();
    return false;
  }

  ref_api.copy_mem(pc, &inst, sizeof(inst), DIFFTEST_TO_REF);
  ref_api.step(1);
  pull_cpu(snapshot);
  return true;
}

void init_difftest(char *so_file, long image_size, int port) {
  Assert(so_file != NULL, "DiffTest setup has no reference library");
  Assert(image_size >= 0, "DiffTest image length is negative: size=%ld", image_size);

  void *so = dlopen(so_file, RTLD_LAZY);
  Assert(so != NULL, "DiffTest cannot load reference '%s': %s", so_file, dlerror());

  ref_api.copy_mem = dlsym(so, "difftest_memcpy");
  ref_api.copy_regs = dlsym(so, "difftest_regcpy");
  ref_api.step = dlsym(so, "difftest_exec");
  void (*init_ref)(int) = dlsym(so, "difftest_init");
  void (*enable_soc)(void) = dlsym(so, "difftest_enable_ysyxsoc_paddr");
  Assert(ref_api.copy_mem && ref_api.copy_regs && ref_api.step && init_ref,
      "DiffTest reference is missing a required callback");

  Log("DiffTest reference mode: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  difftest_enable_soc(enable_soc);
  init_ref(port);
  difftest_active = false;
  difftest_copy_memory(ref_api.copy_mem, DIFFTEST_TO_REF);
  push_cpu();
}

static void check_state(CPU_state *ref, vaddr_t pc) {
  if (isa_difftest_checkregs(ref, pc)) return;
  npc_state.state = NPC_ABORT;
  npc_state.halt_pc = pc;
  isa_reg_display();
}

void difftest_step(vaddr_t pc, vaddr_t dnpc, uint32_t inst) {
  CPU_state ref;
  Assert((pc & 3u) == 0 && (dnpc & 3u) == 0, "DiffTest step has an unaligned address: pc=" FMT_WORD " dnpc=" FMT_WORD " inst=0x%08x", pc, dnpc, inst);

  if (!leave_boot_phase(pc, dnpc)) return;
  if (!execute_reference(pc, inst, &ref)) return;

  Assert((ref.pc & 3u) == 0, "DiffTest reference returned an unaligned pc: ref_pc=" FMT_WORD " dut_pc=" FMT_WORD " dut_npc=" FMT_WORD " inst=0x%08x", ref.pc, pc, dnpc, inst);
  check_state(&ref, pc);
}

#else
void init_difftest(char *so_file, long image_size, int port) {
  (void)so_file; (void)image_size; (void)port;
}
#endif
