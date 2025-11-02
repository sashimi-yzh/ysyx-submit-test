#include "difftest.h"


void (*difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*difftest_regcpy)(void *dut, bool direction) = NULL;
void (*difftest_exec)(uint64_t n) = NULL;
void (*difftest_raise_intr)(uint64_t NO) = NULL;


extern bool is_simulating;
extern bool difftest_to_skip;
extern bool difftest_skipping;
extern Vysyx_23060229_top* top;
extern uint8_t memory2[];
extern char* regname[];


//static struct npc_context_t npc_cpu;


void init_difftest(const char* ref_so_file, long img_size, int port){
	assert(ref_so_file != NULL);

	void* handler;
	handler = dlopen(ref_so_file, RTLD_LAZY);
	assert(handler);

	difftest_memcpy = reinterpret_cast<void (*)(uint32_t, void*, size_t, bool)> (dlsym(handler, "difftest_memcpy"));
	assert(difftest_memcpy);
	
	difftest_regcpy = reinterpret_cast<void (*)(void*, bool)> (dlsym(handler, "difftest_regcpy"));
	assert(difftest_regcpy);

	difftest_exec = reinterpret_cast<void (*)(uint64_t)> (dlsym(handler, "difftest_exec"));
	assert(difftest_exec);

	difftest_raise_intr = reinterpret_cast<void (*)(uint64_t)> (dlsym(handler, "difftest_raise_intr"));
	assert(difftest_raise_intr);

	void (*difftest_init)(int) = reinterpret_cast<void (*)(int)> (dlsym(handler, "difftest_init"));
	assert(difftest_init);

	difftest_init(port);
	
	difftest_memcpy(RESET_VECTOR, memory2, img_size, NPC_TO_NEMU);
	
	//初始化npc_cpu
	struct npc_context_t npc_cpu;//只使用一次
	for(int i = 0; i < 32; i++)
		npc_cpu.gpr[i] = top -> regs[i];
	//npc_cpu.pc = top -> pc;
	npc_cpu.pc = 0x80000000;

	difftest_regcpy(&npc_cpu, NPC_TO_NEMU);

}



void difftest_step(){
	if(difftest_skipping){
		//if(top -> one_inst_done)//由于stall的原因，read_mem_可能被多次执行，因而导致difftest_skipping多次拉高
		difftest_exec(1);//为避免NEMU在此期间执行多条指令，只有在第一次（top->one_inst_done==1）时执行一条指令
		struct npc_context_t npc_cpu;
    	for(int i = 0; i < 32; i++)
        	npc_cpu.gpr[i] = top -> regs[i];
    	npc_cpu.pc = top -> pc;
		difftest_regcpy(&npc_cpu, NPC_TO_NEMU);
		difftest_skipping = false;
	}

	else{
		struct npc_context_t tmp;
		difftest_exec(1);
		difftest_regcpy(&tmp, NEMU_TO_NPC);

		//printf("top->pc: %x\n", top -> pc);
		//printf("tmp.pc: %x\n", tmp.pc);

		bool tag = true;
		if(tmp.pc != top -> pc)//由于pc的特殊性，暂时不比较pc
			;//tag = false;
		for(int i = 0; i < 32; i++)
			if(tmp.gpr[i] != top -> regs[i])
				tag = false;


		if(!tag){
        	printf("\033[31m--------------------- Difftest Failure! ------------------------\n");
        	printf("inst at addr %#8.8x produces different results!\n", top -> pc - 4);
        	printf("----------------------------------------------------------------\033[0m\n");
        	printf("    REF(NEMU)   	      DUT(NPC)\n");
        	for(int j = 0; j < 32; ++j)
				if(tmp.gpr[j] != top -> regs[j])
            		printf("\033[31m%3s : 0x%8.8x           0x%8.8x\033[0m\n",regname[j],tmp.gpr[j],top -> regs[j]);
				else
					printf("\033[32m%3s : 0x%8.8x           0x%8.8x\033[0m\n",regname[j],tmp.gpr[j],top -> regs[j]);
        
			if(tmp.pc != top -> pc)
				printf("\033[31m%3s : 0x%8.8x           0x%8.8x\033[0m\n","pc",tmp.pc, top -> pc);
			else
				printf("\033[32m%3s : 0x%8.8x           0x%8.8x\033[0m\n","pc",tmp.pc ,top -> pc);

			printf("\033[31m----------------------------------------------------------------\033[0m\n");
    		is_simulating = false;
		}
	}

}





