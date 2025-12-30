#include <dlfcn.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "npc.h"
#include "difftest.h"
#include "sdb.h"

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;

void init_difftest(char *ref_so_file, long img_size, int port) {
	assert(ref_so_file != NULL);

	void *handle;
	handle = dlopen(ref_so_file, RTLD_LAZY);
	assert(handle);

	ref_difftest_memcpy = (void (*)(uint32_t, void*, size_t, bool)) dlsym(handle, "difftest_memcpy");
	assert(ref_difftest_memcpy);

	ref_difftest_regcpy =  (void (*)(void*, bool)) dlsym(handle, "difftest_regcpy");
	assert(ref_difftest_regcpy);

	ref_difftest_exec = (void (*)(uint64_t)) dlsym(handle, "difftest_exec");
	assert(ref_difftest_exec);

	ref_difftest_raise_intr = (void (*)(uint64_t)) dlsym(handle, "difftest_raise_intr");
	assert(ref_difftest_raise_intr);

	void (*ref_difftest_init)(int) = (void (*)(int)) dlsym(handle, "difftest_init");
	assert(ref_difftest_init);

	Log("Differential testing: %s", "\33[1;32m" "ON" "\33[0m");
	Log("The result of every instruction will be compared with %s. "
			"This will help you a lot for debugging, but also significantly reduce the performance. "
			"If it is not necessary, you can turn it off by changing the NPC_DIFFTEST in <difftest.h>.", ref_so_file);
	
	ref_difftest_init(port);
	Log("Initialized the difftest.");

	if(npc_without_soc == false){ //make ARCH=riscv32e-ysyxSoC run
		ref_difftest_memcpy( (uint32_t)NPC_FLASH_MBASE, (void*)(paddr_read(NPC_FLASH_MBASE)), img_size, DIFFTEST_TO_REF);
	} else {//make ARCH=riscv32e-npc run 没有soc
		ref_difftest_memcpy( (uint32_t)0X80000000, (void*)(paddr_read(0X80000000)), img_size, DIFFTEST_TO_REF);
	}
	
	ref_difftest_regcpy(&npc, DIFFTEST_TO_REF);

	
	
}

bool isa_difftest_checkregs(CPU_state *ref_r, uint32_t pc) {
	if(ref_r->pc != pc){
		printf("difftest:npc.pc=0X%08X\tref.pc=0X%08X\n", pc, ref_r->pc);
		return false;
	}
	int reg_num = ARRLEN(npc.gpr);
	for(int i = 0; i < reg_num; i++){
		if(ref_r->gpr[i] != npc.gpr[i]){
			printf("difftest:npc.gpr[%d]=0X%08X\tref.gpr[%d]=0X%08X\n", i, npc.gpr[i], i, ref_r->gpr[i]);
			return false;
		}
			
	}
	return true;
}

static void checkregs(CPU_state *ref, uint32_t pc) {
	if (!isa_difftest_checkregs(ref, pc)) {
		npc_state = NPC_ABORT;
		npc.pc = pc;
		isa_reg_display();
	}
}

void difftest_step(uint32_t pc, uint32_t npc) {//pc:执行指令前的当前pc,npc是执行指令后的动态下一个pc
	CPU_state ref_r;

	if (skip_dut_nr_inst > 0) {//跳过指令的处理(几条指令打包一起执行时进行校准) 
		ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
		if (ref_r.pc == npc) {
			skip_dut_nr_inst = 0;
			checkregs(&ref_r, npc);
			return;
		}
		skip_dut_nr_inst --;
		if (skip_dut_nr_inst == 0)
			panic("can not catch up with ref.pc = 0X%08X at pc = 0X%08X", ref_r.pc, pc);
		return;
	}

	if (is_skip_ref) {//有的指令不能让REF直接执行, 或者执行后的行为肯定与NEMU不同时候进行校准
		// to skip the checking of an instruction, just copy the reg state to reference design
		ref_difftest_regcpy(&npc, DIFFTEST_TO_REF);
		is_skip_ref = false;
		return;
	}

	ref_difftest_exec(1); //让参考模型 REF 单步执行一条指令。
	ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);//从 REF 读取其所有寄存器的状态，保存到本地变量 ref_r 中

	checkregs(&ref_r, npc);//比较
}











// // this is used to let ref skip instructions which
// // can not produce consistent behavior with NEMU
// /*有的指令不能让REF直接执行, 或者执行后的行为肯定与NEMU不同时候进行校准
// 在difftest_step()中会让REF跳过当前指令的执行, 同时把NEMU的当前的寄存器状态直接同步到REF中,
//  效果相当于"该指令的执行结果以NEMU的状态为准".*/
// void difftest_skip_ref() {
//   is_skip_ref = true;
//   // If such an instruction is one of the instruction packing in QEMU
//   // (see below), we end the process of catching up with QEMU's pc to
//   // keep the consistent behavior in our best.
//   // Note that this is still not perfect: if the packed instructions
//   // already write some memory, and the incoming instruction in NEMU
//   // will load that memory, we will encounter false negative. But such
//   // situation is infrequent.
//   skip_dut_nr_inst = 0;
// }

// // this is used to deal with instruction packing in QEMU.
// // Sometimes letting QEMU step once will execute multiple instructions.
// // We should skip checking until NEMU's pc catches up with QEMU's pc.
// // The semantic is
// //   Let REF run `nr_ref` instructions first.
// //   We expect that DUT will catch up with REF within `nr_dut` instructions.
// /*几条指令打包一起执行时进行校准，让REF单步执行nr_ref次, 
// 然后期望NEMU可以在nr_dut条指令之内追上REF的状态, 期间会跳过其中所有指令的检查.*/
// void difftest_skip_dut(int nr_ref, int nr_dut) {
//   skip_dut_nr_inst += nr_dut;

//   while (nr_ref -- > 0) {
//     ref_difftest_exec(1);
//   }
// }
