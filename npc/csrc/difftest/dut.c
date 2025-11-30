#include <dlfcn.h>
#include "./../include/common.h"

extern bool RUNNING;
extern uint8_t mem[CONFIG_MSIZE];
extern CPU_state cpu;
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;//中断

#ifdef CONFIG_DIFFTEST

static int is_skip_ref = 0;

void difftest_skip_ref() {
	is_skip_ref = 2;//下一周期的regs变
}

void init_difftest(char *ref_so_file, long img_size, int port) {
	assert(ref_so_file != NULL);
	void *handle;
	handle = dlopen(ref_so_file, RTLD_LAZY);//动态库加载函数
	if((handle = dlopen(ref_so_file, RTLD_LAZY)) == NULL) {
        printf("dlopen - %sn", dlerror());
        exit(-1);
  }
	ref_difftest_memcpy = (void (*)(paddr_t addr, void *buf, size_t n, bool direction))dlsym(handle, "difftest_memcpy");//获取ref函数地址
	assert(ref_difftest_memcpy);
	ref_difftest_regcpy = (void (*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
	assert(ref_difftest_regcpy);
	ref_difftest_exec = (void (*)(uint64_t n))dlsym(handle, "difftest_exec");
	assert(ref_difftest_exec);
	ref_difftest_raise_intr = (void (*)(uint64_t NO))dlsym(handle, "difftest_raise_intr");
	assert(ref_difftest_raise_intr);
	void (*ref_difftest_init)(int) = (void (*)(int port))dlsym(handle, "difftest_init");
	assert(ref_difftest_init);
	Log("The result of every instruction will be compared with %s. "
		"This will help you a lot for debugging, but also significantly reduce the performance. "
		"If it is not necessary, you can turn it off in menuconfig.", ref_so_file);
	
	ref_difftest_init(port);//调用ref_init
	ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);//from mymem to ref IM
	ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);//reg from myreg to ref
}

static bool flag;
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  int reg_num = ARRLEN(cpu.gpr);
	flag = true;
	for(int i = 0; i < reg_num; i ++) {
		if(ref_r->gpr[i] != cpu.gpr[i]) {
			Log("npc: %s at pc = " FMT_WORD, (ANSI_FMT("REG DIFF", ANSI_FG_RED)), pc);
			printf("gpr_x[%d]:%08x   diff with   ref_x[%d]:%08x\n", i, cpu.gpr[i], i, ref_r->gpr[i]);
			flag = false;
		}
	}
	if(ref_r->pc != cpu.pc) {
		printf("pc diff ref\nref_pc= %08x\tcpu.pc = %08x\n", ref_r->pc, cpu.pc);
		flag = false;
	}
/* risv_e volatile("li a5, -1; ecall") else volatile("li a7, -1; ecall") */

	if(ref_r->csr.mepc != cpu.csr.mepc) {
		Log("npc: %s at pc = " FMT_WORD, (ANSI_FMT("MEPC DIFF", ANSI_FG_RED)), pc);
		printf("mepc diff ref\nref_mepc= %08x\tcpu.mepc = %08x\n", ref_r->csr.mepc, cpu.csr.mepc);
		return false;
	}

//nemu un restart or init
if(ref_r->csr.mstatus != cpu.csr.mstatus) {
    Log("npc: %s at pc = " FMT_WORD, (ANSI_FMT("MSTATUS DIFF", ANSI_FG_RED)), pc);
		printf("mstatus diff ref\nref_mstatus= %08x\tcpu.mstatus = %08x\n", ref_r->csr.mstatus, cpu.csr.mstatus);
    return false;
  }

	if(ref_r->csr.mcause != cpu.csr.mcause) {
		Log("npc: %s at pc = " FMT_WORD, (ANSI_FMT("MCAUSE DIFF", ANSI_FG_RED)), pc);
    printf("mcause diff ref\nref_mcause= %08x\tcpu.mcause = %08x\n", ref_r->csr.mcause, cpu.csr.mcause);
    return false;
  }
	if(ref_r->csr.mtvec != cpu.csr.mtvec) {
		Log("npc: %s at pc = " FMT_WORD, (ANSI_FMT("MTVEC DIFF", ANSI_FG_RED)), pc);
    printf("pc diff ref\nref_mtvec= %08x\tcpu.mtvec = %08x\n", ref_r->csr.mtvec, cpu.csr.mtvec);
    return false;
  }

	return flag;
}

void isa_difftest_attach() {
}

static void checkregs(CPU_state *ref, vaddr_t pc) {//check regs
	if(!isa_difftest_checkregs(ref, pc)) {
		RUNNING = false;
		isa_regs_display();
	}
}

void difftest_step(vaddr_t pc, vaddr_t npc) {//执行一步差异测试
	CPU_state ref_r;
	
	if(is_skip_ref > 0) {
		ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
		is_skip_ref --;
		return;
	}

	ref_difftest_exec(1);//ref 执行1
	ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);//regs from ref to dut
	checkregs(&ref_r, pc);//check regs dut:myregs
}

#else
void init_difftest(char *ref_so_file, long img_size, int port) {
}
void difftest_skip_ref() {
}
#endif
