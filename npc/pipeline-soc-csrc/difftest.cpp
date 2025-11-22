#include "../include/common.h"
#include "../include/conf.h"
#include "../include/difftest.h"
#include "../include/utils.h"
#include <dlfcn.h>

#ifdef YSYXSOC
#include "VysyxSoCFull.h"
#include "../obj_dir/VysyxSoCFull___024root.h"
extern VysyxSoCFull *top;
#define top_pc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__IF_ID_pc
#define top_regs top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu__DOT__regs
#else
#include "Vysyx_25010030_npc.h"
#include "../obj_dir/Vysyx_25010030_npc___024root.h"
extern Vysyx_25010030_npc *top;
#define top_pc top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__IF_ID_pc
#define top_regs top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__wbu__DOT__regs
// #define top_mepc top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__wbu__DOT__mepc
// #define top_mtvec top->rootp->ysyx_25010030_npc__DOT__cpu__DOT__wbu__DOT__mtvec

#endif

extern NPCState npc_state;
extern uint8_t* guest_to_host(paddr_t paddr);

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

// extern "C" void difftest_skip_ref() {
//   is_skip_ref = true;
//   skip_dut_nr_inst = 0;
// }

#ifdef CONFIG_DIFFTEST

CPU_state cpu;
static int skip_cnt_ref = 0;   // the amount to skip the ref
static bool skip_flag = false; // the flag   to skip the ref 
static bool rst_flag = true;
vaddr_t last_ref_pc;

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;

void difftest_skip_ref() {
//   skip_cnt_ref++;
    is_skip_ref = true;
}


const char *ref_regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
//   "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
//   "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};


void update_cpu_state(CPU_state *cpu)
{
    cpu->pc = top_pc;
    last_ref_pc = cpu->pc;
    for(int i = 0; i < 16; i++)
        cpu->gpr[i] = top_regs[i];
    // cpu->csr.mcause = 0xb;
    // cpu->csr.mstatus = 0x1800;
}


void init_difftest(char *ref_so_file, long img_size, int port) 
{
    // update_cpu_state(&cpu);
    // printf("%s\n",ref_so_file);
    assert(ref_so_file != NULL);
    // printf("%s\n",ref_so_file);
    void *handle;
    handle = dlopen(ref_so_file, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        exit(1);
    }
    printf("%s\n",ref_so_file);
    assert(handle);

    ref_difftest_memcpy = (void (*)(uint32_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
    assert(ref_difftest_memcpy);

    ref_difftest_regcpy = (void (*)(void*, bool))dlsym(handle, "difftest_regcpy");
    assert(ref_difftest_regcpy);

    ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
    assert(ref_difftest_exec);

    // ref_difftest_raise_intr = dlsym(handle, "difftest_raise_intr");
    // assert(ref_difftest_raise_intr);

    void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
    assert(ref_difftest_init);

    Log("The result of every instruction will be compared with %s. "
        "This will help you a lot for debugging, but also significantly reduce the performance. ", ref_so_file);

    ref_difftest_init(port);
    ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);

    CPU_state ref_r;
    ref_r.pc = CONFIG_MBASE;//复位的时候默认为npc架构
    last_ref_pc = CONFIG_MBASE;
    for(int i = 0; i < 16; i++)
        ref_r.gpr[i] = 0;
    // ref_r.csr.mstatus = 0x1800;
    // ref_r.csr.mcause = 0xb;
}


bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) 
{
    bool success = true;

    //check pc
    if(last_ref_pc != pc)
    {
        _Log(ANSI_FG_YELLOW "[difftest]" ANSI_NONE   ANSI_FG_RED "pc" 
             ANSI_NONE "  dut:0x%08x   ref:0x%08x\n", pc, last_ref_pc);
        success = false;
    }
    last_ref_pc = ref_r->pc;

    //check general purpose registers
    for(int i = 0; i < 16; i++)
        if(top_regs[i] != ref_r->gpr[i])
        {
            _Log(ANSI_FG_YELLOW "[difftest]" ANSI_NONE   ANSI_FG_RED "%s" 
                 ANSI_NONE "  dut:0x%08x   ref:0x%08x\n", ref_regs[i], top_regs[i], ref_r->gpr[i]);
            success = false;
        }
    
    return success;
}

static void checkregs(CPU_state *ref, vaddr_t pc) 
{
    if (!isa_difftest_checkregs(ref, pc)) 
    {
        npc_state.state = NPC_ABORT;
        npc_state.halt_pc = pc;
        Log("Differential test %s at pc = 0x%08x." , (ANSI_FMT("fails", ANSI_FG_RED)), npc_state.halt_pc);
        printf("\033[33m[DUT->GPR]\t\t[REF->GPR]\033[0m\n");
        for(int i = 0; i < 16; i++)
        {
            printf("%s:\t0x%08x\t0x%08x\n", ref_regs[i], top_regs[i], ref->gpr[i]);
        }
        // printf("mepc   :\t0x%08x\t0x%08x\n", top_mepc, ref->csr.mepc);
        // printf("mtvec  :\t0x%08x\t0x%08x\n", top_mtvec, ref->csr.mtvec);
        // printf("mcause :\t0x%08x\t0x%08x\n", 0xb, ref->csr.mcause);
        // printf("mstatus:\t0x%08x\t0x%08x\n", 0x1800, ref->csr.mstatus);
        printf("\npc:\t0x%08x\t0x%08x\n", pc, ref->pc);
    }
}


void difftest_step(vaddr_t pc, vaddr_t npc) 
{
    if(is_skip_ref){
        CPU_state ref_r;
        update_cpu_state(&ref_r);
        ref_difftest_regcpy(&ref_r, DIFFTEST_TO_REF);
        is_skip_ref = false;
        return;
    }
    ref_difftest_exec(1);
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_DUT);
    checkregs(&cpu, pc);
}

#else
void init_difftest(char *ref_so_file, long img_size, int port) { }
void difftest_skip_ref() { }
#endif