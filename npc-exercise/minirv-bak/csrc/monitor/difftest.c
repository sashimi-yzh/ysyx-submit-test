#include "common.h"
#include "debug.h"
#include "cpu.h"
#include "mem.h"
#include <dlfcn.h>

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, void *pc, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;
static bool is_skip_ref = false;
#ifdef CONFIG_DIFFTEST_ENABLE
void init_difftest(char *diff_so_file, long img_size){
	assert(diff_so_file != NULL);

	void *handle;
	handle = dlopen(diff_so_file, RTLD_LAZY);
	assert(handle);

	ref_difftest_memcpy = (void (*)(uint32_t, void*, size_t, bool))dlsym(handle, "difftest_memcpy");
  	assert(ref_difftest_memcpy);

  	ref_difftest_regcpy = (void (*)(void*, void*, bool))dlsym(handle, "difftest_regcpy");
  	assert(ref_difftest_regcpy);

  	ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
  	assert(ref_difftest_exec);

  	ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
  	assert(ref_difftest_raise_intr);

	void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
  	assert(ref_difftest_init);

	Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  	Log("The result of every instruction will be compared with [%s]. ", diff_so_file);

	ref_difftest_init(0);
	ref_difftest_memcpy(RESET_VECTOR, &MEM(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  	ref_difftest_regcpy(cpu.gpr, &cpu.pc, DIFFTEST_TO_REF);
}

static void checkregs(CPUState *ref, uint32_t pc, uint32_t npc) {
	extern const char *regs[];
	bool success = true;
	for(int i=0;i<CONFIG_GPR_NUM;i++){
		if(cpu.gpr[i]!=ref->gpr[i]) {
			Log("%s REG[%02d](%s) DUT:%08x REF:%08x at pc:%08x",ANSI_FMT("Different GPR!", ANSI_FG_RED),i,regs[i],cpu.gpr[i],ref->gpr[i],pc);
			success = false;
		}
  	}
  	if(ref->pc != npc) {
    	//printf("===%08x===%08x===\n",ref_r->pc,pc);
    	Log("%s DUT:%08x REF:%08x at pc:%08x",ANSI_FMT("Different NEXT PC!", ANSI_FG_RED),npc,ref->pc,pc);
    	success = false;
  	}	

  	if (!success) {
    	cpu.state = NPC_ABORT;
    	//cpu.halt_pc = pc;
		reg_display(*ref);
		reg_display(cpu);
  	}
}

void difftest_step(uint32_t pc, uint32_t npc){
	CPUState ref;
	if(is_skip_ref){
		ref_difftest_regcpy(cpu.gpr, &npc, DIFFTEST_TO_REF);
		is_skip_ref = false;
		return;
	}
	ref_difftest_exec(1);
	ref_difftest_regcpy(ref.gpr, &ref.pc, DIFFTEST_TO_DUT);
	checkregs(&ref, pc, npc);
}
void difftest_skip_ref() {
	
  is_skip_ref = true;
}
#else
void init_difftest(char *diff_so_file, long img_size) { }
void difftest_skip_ref() { }
#endif

