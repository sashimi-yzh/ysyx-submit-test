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
uint32_t SDRAM[CONFIG_SDRAMSIZE>>2];
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

	

	ref_difftest_init(0);
	Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  	Log("The result of every instruction will be compared with [%s]. ", diff_so_file);
	ref_difftest_memcpy(CONFIG_MROMBASE, &MROM(CONFIG_MROMBASE), CONFIG_MROMSIZE, DIFFTEST_TO_REF);
	ref_difftest_memcpy(CONFIG_FLASHBASE, &FLASH(CONFIG_FLASHBASE), CONFIG_FLASHSIZE, DIFFTEST_TO_REF);
	ref_difftest_memcpy(CONFIG_SRAMBASE, &MEM(CONFIG_SRAMBASE), CONFIG_SRAMSIZE, DIFFTEST_TO_REF);
	ref_difftest_memcpy(CONFIG_PSRAMBASE, &PSRAM(CONFIG_PSRAMBASE), CONFIG_PSRAMSIZE, DIFFTEST_TO_REF);
	
	// for(int i=0;i<CONFIG_SDRAMSIZE>>2;i++){
	// 	SDRAM[i] = (uint32_t)SDRAML((uint32_t)(i*4 + CONFIG_SDRAMBASE)) | ((uint32_t)SDRAMH((uint32_t)(i*4 + CONFIG_SDRAMBASE)) << 16);
	// }
	// ref_difftest_memcpy(CONFIG_SDRAMBASE, SDRAM, CONFIG_SDRAMSIZE, DIFFTEST_TO_REF);
	
  	// ref_difftest_regcpy(cpu.gpr, &cpu.pc, DIFFTEST_TO_REF);
	Log("Finished initializing differential testing.");
}

static bool checkregs(CPUState *ref, uint32_t pc, uint32_t npc) {
	extern const char *regs[];
	bool success = true;
	for(int i=0;i<CONFIG_GPR_NUM;i++){
		if(cpu.gpr[i]!=ref->gpr[i]) {
			Log("%s REG[%02d](%s) DUT:%08x REF:%08x at pc:%08x",ANSI_FMT("Different GPR!", ANSI_FG_RED),i,regs[i],cpu.gpr[i],ref->gpr[i],pc);
			success = false;
		}
  	}
  	if(ref->tb_FINAL_npc != npc) {
    	Log("%s DUT:%08x REF:%08x at pc:%08x",ANSI_FMT("Different NEXT PC!", ANSI_FG_RED),npc,ref->tb_FINAL_npc,pc);
    	success = false;
  	}	
	return success;
}

void difftest_step(uint32_t pc, uint32_t npc, uint32_t mem_addr) {;
	CPUState ref;
	if(is_skip_ref){
		// Log("Skipping reference CPU state update at pc:%08x. ", pc);
		ref_difftest_regcpy(cpu.gpr, &npc, DIFFTEST_TO_REF);
		is_skip_ref = false;
		return;
	}
	ref_difftest_exec(1);
	ref_difftest_regcpy(ref.gpr, &ref.tb_FINAL_npc, DIFFTEST_TO_DUT);
	// Log("d pc=%08x", pc);
	bool success = checkregs(&ref, pc, npc);
	if(mem_addr != 0 && success) {
		// Log("Check memory at address " FMT_WORD, mem_addr);
		if(1){
			uint32_t ref_mem,dut_mem;
			ref_difftest_memcpy((mem_addr&~0x03), (void *)&ref_mem, 4, DIFFTEST_TO_DUT);
			dut_mem = pmem_read(mem_addr&~0x03);
			if(ref_mem != dut_mem) {
				Log("%s DUT MEM[" FMT_WORD "] = %08x REF MEM[" FMT_WORD "] = %08x at pc:%08x",ANSI_FMT("Different Memory!", ANSI_FG_RED),mem_addr, dut_mem, mem_addr, ref_mem, pc);
				success = false;
			}else{
				// Log("Memory at address " FMT_WORD " is the same: %08x", mem_addr, dut_mem);
			}
		}
	}
	if (!success) {
    	cpu.state = NPC_ABORT;
    	//cpu.halt_pc = pc;
		printf("===REF CPU State===\n");
		reg_display(ref);
		printf("===DUT CPU State===\n");
		reg_display(cpu);
  	}
}
void difftest_skip_ref(int reason) {
	if(reason >= 0x10000000 && reason <= 0x10000005){

	}else{
		Log("Differential testing: %s because of %08x", ANSI_FMT("REF is skipped", ANSI_FG_YELLOW), reason);
	}
	
  is_skip_ref = true;
}
void difftest_mem_set(int addr){
	#ifdef CONFIG_DIFFTEST_MEM_ENABLE
	// Log("Differential testing: Set memory address " FMT_WORD, addr);
	cpu.mem_access_addr = (uint32_t)addr;
	#endif
}
#else
void init_difftest(char *diff_so_file, long img_size) { }
void difftest_skip_ref(int reason) { }
void difftest_mem_set(int addr) { }
#endif

