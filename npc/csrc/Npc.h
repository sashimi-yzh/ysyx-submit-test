#pragma once
#include "VysyxSoCFull.h"
#include "verilated.h"

#include "verilated_fst_c.h"
#include "verilated_vcd_c.h"

#include "Iringbuf.h"
#include "Difftest.h"
#include "config.h"
#include <stdio.h>
#ifndef IS_NPC
#include <nvboard.h>
#endif
#define DIFFTEST_TO_REF 1
#define DIFFTEST_TO_DUT 0

extern uint8_t pmem[];
extern void init_disasm();
extern void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void nvboard_bind_all_pins(VysyxSoCFull *top);
static char regs[16][8] = {
	"$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
	"s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"};

class Npc
{
public:
	Npc(int argc, char **argv)
	{
		Verilated::commandArgs(argc, argv);
		top = new VysyxSoCFull;
#ifdef WAVE
#ifdef FST
		tfp = new VerilatedFstC;
		Verilated::traceEverOn(true);
		top->trace(tfp, 99);
		tfp->open("top.fst");
#else
		tfp = new VerilatedVcdC;
		Verilated::traceEverOn(true);
		top->trace(tfp, 99);
		tfp->open("top.vcd");
#endif

#endif
		init_disasm();
#ifndef IS_NPC
		nvboard_bind_all_pins(top);
		nvboard_init();
#endif
	}
	~Npc()
	{
		delete top;
	}
	void dump()
	{
#ifdef WAVE
		tfp->dump(main_time++);
#endif
	}
	void reset_top()
	{
		int i = 10;
		while (i--)
		{
			top->clock = 0;
			top->reset = 1;
#ifndef IS_NPC
			top->externalPins_uart_rx = 1;	// reset uart rx
			top->externalPins_ps2_data = 1; // reset ps2 data
#endif
			top->eval();
			dump();
			top->clock = 1;
			top->eval();
			dump();
			top->reset = 0;
#ifndef IS_NPC
			nvboard_update();
#endif
		}
#ifdef TRACE
		update_messages();
#endif
	}
	void step_top()
	{

		top->clock = 0;
		top->eval();
		dump();
		top->clock = 1;
		top->eval();
		dump();
#ifndef IS_NPC
		nvboard_update();
#endif
#ifdef TRACE
		update_messages();
#endif
#ifdef WAVE
		tfp->flush();
#endif
	}

	void reg_display()
	{
		printf("pc= %010u\t0x%08x\n", regs_val[0], regs_val[0]);
		for (int i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
		{
			printf("%s= %010u\t0x%08x\t", regs[i], regs_val[i + 1], regs_val[i + 1]);
			if (i % 2 == 1)
				printf("\n");
		}
	}
	void init_difftest(long img_size)
	{
		assert(ref_so_file != NULL);

		void *handle;
		handle = dlopen(ref_so_file, RTLD_LAZY);
		assert(handle);

		ref_difftest_memcpy = (void (*)(uint32_t addr, void *buf, size_t n, bool direction))dlsym(handle, "difftest_memcpy");
		assert(ref_difftest_memcpy);
		// a value of type "void *" cannot be assigned to an entity of type "void (*)(uint32_t addr, void *buf, size_t n, bool direction)"
		ref_difftest_regcpy = (void (*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
		assert(ref_difftest_regcpy);
		ref_difftest_exec = (void (*)(uint64_t n))dlsym(handle, "difftest_exec");
		// a value of type "void *" cannot be assigned to an entity of type "void (*)(void *dut, bool direction)" ref_difftest_exec = dlsym(handle, "difftest_exec");
		assert(ref_difftest_exec);

		void (*ref_difftest_init)(int) = (void (*)(int))dlsym(handle, "difftest_init");
		assert(ref_difftest_init);
		// a value of type "void *" cannot be used to initialize an entity of type "void (*)(int)"
		ref_difftest_init(port);
		ref_difftest_memcpy(0, pmem, img_size, DIFFTEST_TO_REF);
		uint32_t regs[17];
		memcpy(regs, regs_val, sizeof(regs_val));
		regs[0] = 0x30000000;
		ref_difftest_regcpy(regs, DIFFTEST_TO_REF);
	}
	void difftest_step()
	{
		if (is_skip_ref)
		{
			is_skip_ref = 0;
			// ref_difftest_memcpy(0, pmem, 0x8000000, DIFFTEST_TO_REF);

			ref_difftest_regcpy(regs_val, DIFFTEST_TO_REF);

			return;
		}
		else
		{
			ref_difftest_exec(1);
			uint32_t ref_regs[17];
			ref_difftest_regcpy(ref_regs, DIFFTEST_TO_DUT);
			if (regs_val[0] != ref_regs[0])
			{
				printf("pc is different, ref %x, dut %x\n", ref_regs[0], regs_val[0]);
				irbuf->print_iringbuf();
				printf("\n");
#ifdef WAVE
				tfp->flush();
#endif
				assert(0);
			}
			for (int i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
			{
				if (regs_val[i + 1] != ref_regs[i + 1])
				{
					printf("reg %s is different, ref %u, dut %u,pc = %x\n", regs[i], ref_regs[i + 1], regs_val[i + 1], regs_val[0]);
					irbuf->print_iringbuf();
					printf("\n");
#ifdef WAVE
					tfp->flush();
#endif
					assert(0);
				}
			}
		}
	}
	void difftest_skip_ref()
	{
		is_skip_ref = 1;
	}
	static uint32_t get_reg(char *name, bool *success)
	{
		if (strcmp(name, "pc") == 0)
		{
			if (success != NULL)
				*success = true;
			return regs_val[0];
		}
		for (int i = 0; i < sizeof(regs) / sizeof(regs[0]); i++)
		{
			if (strcmp(name, regs[i]) == 0)
			{
				if (success != NULL)
					*success = true;
				return regs_val[i + 1];
			}
		}
		if (success != NULL)
			*success = false;
		return 0;
	}
	void update_messages()
	{
		disassemble(disasm, sizeof(disasm), pc_before, (uint8_t *)&inst, 4);
		sprintf(message, "pc 0x%08x inst 0x%08x %s\n", pc_before, inst, disasm);
		pc_before = regs_val[0];
	}
	static VysyxSoCFull *top;
#ifdef WAVE
	uint32_t main_time = 0;
#ifdef FST
	VerilatedFstC *tfp;
#else
	VerilatedVcdC *tfp;
#endif
#endif
	uint32_t pc_before = 0;
	void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
	void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
	void (*ref_difftest_exec)(uint64_t n) = NULL;
	Iringbuf *irbuf = NULL;
	char ref_so_file[256] = "/home/pglzjz/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so";
	int port = 0;
	char message[64];
	char disasm[32];
	static uint32_t regs_val[17];
	static uint32_t inst;
	static bool is_device;
	static bool wbu_state;
	int is_skip_ref = 0;
};
