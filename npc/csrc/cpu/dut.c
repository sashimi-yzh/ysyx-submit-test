#include <dlfcn.h>

#include <cpu/cpu.h>
#include <memory/paddr.h>
#include <utils.h>
#include <difftest-def.h>
#include <cpu/difftest.h>
#include <isa/isa_def.h>
#include <isa/reg.h>


void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

#if CONFIG_DIFFTEST

void isa_reg_display();
extern CPU_state dut;

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  // printf("\n");
  for(int i = 0; i < 16; i ++){
    uint32_t ref_value = ref_r->gpr[i];
    uint32_t value = gpr(i);
    if(value != ref_value) {
    printf("gpr[%d] \33[1;31mdut:0x%08x \33[1;32mref:0x%08x\n", i, value, ref_value);
    return false;
    }
  }
  // if(ref_r->pc != pc){
  //   printf("PC \33[1;31mdut:0x%08x \33[1;32mref:0x%08x\n", pc, ref_r->pc);
  //   return false;
  // }

  return true;
}

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;
static int skip_counter = 0;

// this is used to let ref skip instructions which
// can not produce consistent behavior with NPC
void difftest_skip_ref() {
  is_skip_ref = true;
  // If such an instruction is one of the instruction packing in QEMU
  // (see below), we end the process of catching up with QEMU's pc to
  // keep the consistent behavior in our best.
  // Note that this is still not perfect: if the packed instructions
  // already write some memory, and the incoming instruction in NPC
  // will load that memory, we will encounter false negative. But such
  // situation is infrequent.
  
    skip_counter ++;
  
  skip_dut_nr_inst = 0;
}

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NPC's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
void difftest_skip_dut(int nr_ref, int nr_dut) {
  skip_dut_nr_inst += nr_dut;
  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

extern char img_file[256];
void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(paddr_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in autoconf.h.", ref_so_file);

  ref_difftest_init(port);
  #ifdef PLATFORM_YSYXSOC
  ref_difftest_memcpy(CONFIG_FLASH_BASE, flash_guest_to_host(FLASH_RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  #else 
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  #endif
  //printf("0x%08x\n", dut->de_pc);
  ref_difftest_regcpy(&dut, DIFFTEST_TO_REF);
}

static void checkregs(CPU_state *ref, vaddr_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    isa_reg_display();
  }
}

void difftest_step(vaddr_t pc, vaddr_t npc) {
    CPU_state ref_r;
  if (skip_dut_nr_inst > 0) {
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    if (ref_r.pc == npc) {
      skip_dut_nr_inst = 0;
      checkregs(&ref_r, npc);
      return;
    }
    skip_dut_nr_inst --;
    if (skip_dut_nr_inst == 0)
      printf("can not catch up with ref.pc = " FMT_WORD " at pc = " FMT_WORD, ref_r.pc, pc);
    return;
  }

  if (is_skip_ref) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    ref_difftest_regcpy(&dut, DIFFTEST_TO_REF);
    is_skip_ref = false;
      
    return;
  }
    //printf("0x%08x 0x%08x\n", pc, npc);
  
  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
  checkregs(&ref_r, npc);
}
#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
#endif


