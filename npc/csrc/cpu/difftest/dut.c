#include <dlfcn.h>

#include "difftest_def.h"
#include "utils.h"

paddr_t *guest_to_host(paddr_t paddr);
void reg_display();
bool difftest_checkregs(CPU_state *ref_r, paddr_t pc);

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

// #define CONFIG_DIFFTEST
#ifdef CONFIG_DIFFTEST

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

// this is used to let ref skip instructions which
// can not produce consistent behavior with NEMU
void difftest_skip_ref()
{
    is_skip_ref = true;
    // If such an instruction is one of the instruction packing in QEMU
    // (see below), we end the process of catching up with QEMU's pc to
    // keep the consistent behavior in our best.
    // Note that this is still not perfect: if the packed instructions
    // already write some memory, and the incoming instruction in NEMU
    // will load that memory, we will encounter false negative. But such
    // situation is infrequent.
    skip_dut_nr_inst = 0;
}

// this is used to deal with instruction packing in QEMU.
// Sometimes letting QEMU step once will execute multiple instructions.
// We should skip checking until NEMU's pc catches up with QEMU's pc.
// The semantic is
//   Let REF run `nr_ref` instructions first.
//   We expect that DUT will catch up with REF within `nr_dut` instructions.
void difftest_skip_dut(int nr_ref, int nr_dut)
{
    skip_dut_nr_inst += nr_dut;

    while (nr_ref-- > 0) {
        ref_difftest_exec(1);
    }
}

void init_difftest(char *ref_so_file, long img_size, int port)
{
    assert(ref_so_file != NULL);

    void *handle;
    handle = dlopen(ref_so_file, RTLD_LAZY);
    assert(handle);

    ref_difftest_memcpy = (void (*)(paddr_t addr, void *buf, size_t n, bool direction))dlsym(handle, "difftest_memcpy");
    assert(ref_difftest_memcpy);

    ref_difftest_regcpy = (void (*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
    assert(ref_difftest_regcpy);

    ref_difftest_exec = (void (*)(uint64_t n))dlsym(handle, "difftest_exec");
    assert(ref_difftest_exec);

    ref_difftest_raise_intr = (void (*)(uint64_t NO))dlsym(handle, "difftest_raise_intr");
    assert(ref_difftest_raise_intr);

    void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
    assert(ref_difftest_init);

    printf("Differential testing: " COLOR_GREEN "%s\n" COLOR_END, "ON");
    // printf("The result of every instruction will be compared with %s. "
    //        "This will help you a lot for debugging, but also significantly reduce the performance. "
    //        "If it is not necessary, you can turn it off in menuconfig.",
    //        ref_so_file);

    CPU_state cpu_r = {.pc = RESET_VECTOR};

    ref_difftest_init(port);
    ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
    ref_difftest_regcpy(&cpu_r, DIFFTEST_TO_REF);
    // printf("cpu.pc = 0x%08x\n", cpu_r.pc);
}

static void checkregs(CPU_state *ref, paddr_t pc)
{
    if (!difftest_checkregs(ref, pc)) {
        npc_state.state = NPC_ABORT;
        npc_state.halt_pc = pc;
        reg_display();
    }
}

void difftest_step(paddr_t pc, paddr_t npc)
{
    CPU_state ref_r;

    if (skip_dut_nr_inst > 0) {
        ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
        if (ref_r.pc == npc) {
            skip_dut_nr_inst = 0;
            checkregs(&ref_r, npc);
            return;
        }
        skip_dut_nr_inst--;
        if (skip_dut_nr_inst == 0)
            printf("can not catch up with ref.pc = 0x%08x at pc = 0x%08x\n", ref_r.pc, pc);
        return;
    }

    if (is_skip_ref) {
        // printf("aaaaaa Difftest: skip ref at pc: 0x%08x\n", pc);
        // to skip the checking of an instruction, just copy the reg state to reference design
        ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
        is_skip_ref = false;
        return;
    }
    // printf("difftest_step at pc: 0x%08x\n", pc);
    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

    checkregs(&ref_r, pc);

}
#else
void init_difftest(char *ref_so_file, long img_size, int port)
{
    printf("Differential testing: " COLOR_RED "%s" COLOR_END "\n", "OFF");
}
#endif
