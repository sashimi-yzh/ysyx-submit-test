#include <dlfcn.h>
#include <my_memory.h>
#include <common.h>
#include <circuit.h>

struct CPU_state {
  word_t gpr[REGNUM];
  word_t pc;
  word_t csr[4];
};
bool is_skip_diff = false;
void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;
bool (*ref_difftest_skip)() = NULL;

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

void init_difftest(char *ref_so_file, long img_size) {
    if(ref_so_file == NULL) return;

    void *handle;
    handle = dlopen(ref_so_file, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen failed: %s\n", dlerror());
        assert(0);
    }
    assert(handle);

    ref_difftest_memcpy = (void(*)(paddr_t,void *,size_t,bool))dlsym(handle, "difftest_memcpy");
    assert(ref_difftest_memcpy);

    ref_difftest_regcpy = (void(*)(void *,bool))dlsym(handle, "difftest_regcpy");
    assert(ref_difftest_regcpy);

    ref_difftest_exec = (void(*)(uint64_t))dlsym(handle, "difftest_exec");
    assert(ref_difftest_exec);

    ref_difftest_raise_intr = (void(*)(uint64_t))dlsym(handle, "difftest_raise_intr");
    assert(ref_difftest_raise_intr);

    void (*ref_difftest_init)() = (void(*)())dlsym(handle, "difftest_init");
    assert(ref_difftest_init);

    ref_difftest_skip = (bool(*)())dlsym(handle, "difftest_skip");
    assert(ref_difftest_skip);
    

    #ifdef CONFIG_TRACE
        Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
        Log("The result of every instruction will be compared with %s. "
            "This will help you a lot for debugging, but also significantly reduce the performance. "
            "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);
    #else
        Log("Differential testing: %s", ANSI_FMT("OFF", ANSI_FG_RED));
    #endif

    ref_difftest_init();
    ref_difftest_memcpy(RESET_VECTOR, (void *)guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
    //get dut reg into CPU_state struct
    CPU_state dut_r;
    dut_r.pc = RESET_VECTOR;
    for(int i = 0;i < REGNUM;i++)
        dut_r.gpr[i] = gpr[i];
    for(int i = 0;i < 4;i++){
        dut_r.csr[i] = csr[i];
    }
    ref_difftest_regcpy(&dut_r, DIFFTEST_TO_REF);

    printf("Difftests Init\n");
}

bool static checkregs(struct CPU_state *ref_r){
    bool flag = true;
    for(int i = 0;i < REGNUM;i++){
        // nemu的gpr与npc的gpr相比
        if(ref_r -> gpr[i] != gpr[i]){
            Log(ANSI_FMT("REF PC = 0x", ANSI_FG_RED)"%x, "ANSI_FMT("DUT PC = 0x", ANSI_FG_RED)"%x, "ANSI_FMT("Difftest GPR reg Compare failed at ", ANSI_FG_RED)" %s, "ANSI_FMT("Difftest GPR reg Get ", ANSI_FG_RED) FMT_WORD ", "ANSI_FMT("NPC GPR reg Get ", ANSI_FG_RED) FMT_WORD, ref_r->pc, npc_w, regs[i], ref_r->gpr[i], gpr[i]);
            flag = false;
        }
    }
    // Log(ANSI_FMT("REF PC = 0x", ANSI_FG_RED)"%x, "ANSI_FMT("DUT PC = 0x", ANSI_FG_RED)"%x, ", ref_r->pc, pc);
    for(int i = 0;i < 4;i++){
        if(ref_r -> csr[i] != csr[i]){
            Log(ANSI_FMT("PC = 0x", ANSI_FG_RED)"%x, "ANSI_FMT("Difftest CSR Compare failed at ", ANSI_FG_RED)" %s, "ANSI_FMT("Difftest CSR Get ", ANSI_FG_RED) FMT_WORD ", "ANSI_FMT("NPC CSR Get ", ANSI_FG_RED) FMT_WORD, npc_w, SysReg[i], ref_r->csr[i], csr[i]);
            flag = false;
        }
    }
    if(ref_r -> pc != npc_w){
        Log(ANSI_FMT("ref_r pc: ", ANSI_FG_RED) FMT_WORD "\t"ANSI_FMT("dut pc: ", ANSI_FG_RED) FMT_WORD "\t"ANSI_FMT("dut dnpc: ", ANSI_FG_RED) FMT_WORD, ref_r->pc, npc_w, dnpc);
        flag = false;
    }
    return flag;
}

void difftest_step() {
    if(ref_difftest_memcpy == NULL) return;

    CPU_state ref_r;
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    word_t pc_ref = ref_r.pc;
    // printf("此时的dut的pc为 %#x\tref执行前的 ref_r.pc: %#x\tis_skip_diff 为 %d\n",pc_w,pc_ref,is_skip_diff);
    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
#ifdef CONFIG_SOC
    is_skip_diff = ref_difftest_skip();
    // printf("此时的dut的pc为 %#x\tref执行前的 ref_r.pc: %#x\tis_skip_diff 为 %d\n",pc,ref_r.pc,is_skip_diff);
#endif
    // printf("is_skip_diff is %d\n",is_skip_diff);
    if(is_skip_diff == true){
        is_skip_diff = false;
        //get dut reg into CPU_state struct
        CPU_state dut_r;
        // 多周期需要给进行diff test的段的pc而不是npc，因为现在的pc就是原本的npc了
        // 单周期和多周期进入diff的时间不一样，导致pc的更新的时间不一样，之前是结束的进入，npc就是下一条要执行的指令的地址；
        // 现在是一开始进入的，pc才是下一条要执行的指令的地址
        dut_r.pc = npc_w;
        for(int i = 0;i < REGNUM;i++){
            dut_r.gpr[i] = gpr[i];
        }
        for(int i = 0;i < 4;i++){
            dut_r.csr[i] = csr[i];
        }
        //copy reg to ref to skip this inst
        ref_difftest_regcpy(&dut_r, DIFFTEST_TO_REF);
        return;
    }
    // printf("此时的dut的pc为 %#x\tref执行前的 ref_r.pc: %#x\tis_skip_diff 为 %d\n",npc_w,ref_r.pc,is_skip_diff);
    // while(pc_w != ref_r.pc){
    //     printf("此时的dut的pc为 %#x\tref执行前的 ref_r.pc: %#x\tis_skip_diff 为 %d\n",pc_w,ref_r.pc,is_skip_diff);
    //     ref_difftest_exec(1);
    //     ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    //     if(ref_r.pc == 0x80000060){
    //         break;
    //     }
    // }

    if(!checkregs(&ref_r)){
        isa_reg_display();
        #ifdef CONFIG_DUMP_WAVE
            dump_wave_inc();
            close_wave();
        #endif
        assert(0);
    }
}