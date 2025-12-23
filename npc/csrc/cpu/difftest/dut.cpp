#include <dlfcn.h>
#include <mem.h>
#include <wave.h>
#include <common.h>
#include <circuit.h>
#include <utils.h>
#include <lightsss.h>

extern uint64_t light_cycle_num;
extern LightSSS lightsss;

#ifdef NPCCONFIG_TOP_IS_YSYXSOC
word_t ref_pre_pc = 0x30000000;
word_t comp_pc = 0x30000000;
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
word_t ref_pre_pc = 0x80000000;
word_t comp_pc = 0x80000000;
#endif

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
    printf("==============ref文件是 %s================\n", ref_so_file);

    void *handle;
    handle = dlopen(ref_so_file, RTLD_LAZY);
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

    ref_difftest_init();
#ifdef NPCCONFIG_TOP_IS_YSYXSOC
    ref_difftest_memcpy(FLASH_BASE, (void *)guest_to_host(FLASH_BASE), img_size, DIFFTEST_TO_REF);
    CPU_state dut_r;
    dut_r.pc = FLASH_BASE;
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
    ref_difftest_memcpy(CONFIG_MBASE, (void *)guest_to_host(CONFIG_MBASE), img_size, DIFFTEST_TO_REF);
    CPU_state dut_r;
    dut_r.pc = CONFIG_MBASE;
#endif
    for(int i = 0;i < REGNUM;i++)
      dut_r.gpr[i] = gpr[i];
    dut_r.csr[0] = 0x1800;
    for(int i = 1;i < 4;i++)
      dut_r.csr[i] = csr[i];
    ref_difftest_regcpy(&dut_r, DIFFTEST_TO_REF);
}






bool static checkregs(struct CPU_state *ref_r){
    bool flag = true;
    int i;

    if(comp_pc != PC) flag = false;

    if(INSTR == 0) flag = false;

    for(i = 0;i < REAL_REGNUM; i++){
      if(ref_r -> gpr[i] != gpr[i])
        flag = false;
    }
    for(i = 0;i < 4; i++){
      if(ref_r -> csr[i] != csr[i])
        flag = false;
    }

    if(flag == false){
      printf("ref - pc = 0x%x\n",comp_pc);
      printf("cpu - pc = 0x%x\n",PC);
      for(i = 0;i < REAL_REGNUM; i++){
          printf("ref - %3s = %-#11x", regs[i], ref_r -> gpr[i]);
          printf("       ");
          printf("cpu - %3s = %-#11x", regs[i], gpr[i]);
          printf("\n");
      }
      printf("\n");
      printf("ref - mstatus = %-#11x\n", ref_r -> csr[0]);
      printf("ref - mtvec = %-#11x\n", ref_r -> csr[1]);
      printf("ref - mepc = %-#11x\n", ref_r -> csr[2]);
      printf("ref - mcause = %-#11x\n", ref_r -> csr[3]);
      printf("\n");
      printf("cpu - mstatus = %-#11x\n", csr[0]);
      printf("cpu - mtvec = %-#11x\n", csr[1]);
      printf("cpu - mepc = %-#11x\n", csr[2]);
      printf("cpu - mcause = %-#11x\n", csr[3]);
      printf("\n");
    }
    return flag;
}






void difftest_step() {
    comp_pc = ref_pre_pc;
    if(ref_difftest_memcpy == NULL) return;

    CPU_state ref_r;
    ref_difftest_exec(1);
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

    ref_pre_pc = ref_r.pc;

    is_skip_diff = ref_difftest_skip();

    if(is_skip_diff == true){
      is_skip_diff = false;
      int i;
      //get dut reg into CPU_state struct
      CPU_state dut_r;
      dut_r.pc = ref_r.pc;
      for(i = 0;i < REAL_REGNUM; i++)
        dut_r.gpr[i] = gpr[i];
      for(i = 0;i < 4; i++)
        dut_r.csr[i] = csr[i];
      //copy reg to ref to skip this inst
      ref_difftest_regcpy(&dut_r, DIFFTEST_TO_REF);
      return;
    }

    if(!checkregs(&ref_r)){
    printf("=====================触发了DIFFTEST错误=====================\n");

#ifdef NPCCONFIG_ITRACE
	itrace_init(PC, INSTR);
	display_inst();
#endif

#if defined(NPCCONFIG_DUMPWAVE) || defined(NPCCONFIG_LIGHTSSS)
#ifdef NPCCONFIG_LIGHTSSS
    if(lightsss.is_child()){
        dump_wave();
	    close_wave(2);
        printf("=====================波形因触发DIFFTEST而退出, 查看child波形=====================\n");
    }else{
        lightsss.wakeup_child(light_cycle_num);
    }
#else
    dump_wave();
	close_wave(2);
    printf("=====================波形因触发DIFFTEST而退出, 查看father波形=====================\n");
#endif
#endif

    exit(-1);
  }
}