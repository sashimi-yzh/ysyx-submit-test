/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>


#define NPC_TO_NEMU 1
#define NEMU_TO_NPC 0


#define NR_GPR 32

struct npc_context_t {
	uint32_t gpr[NR_GPR];
	uint32_t pc;
};


//typedef CPU_state nemu_context_t;

//static nemu_context_t* nemu_ref;
//不能初始化为NULL

extern CPU_state cpu;


__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction) {
	if(direction == NPC_TO_NEMU){
		for(int i = 0; i < n; i++){
			//printf("addr: %x\n",addr);
			paddr_write(addr+i, 1, *(uint8_t*)(buf+i));
		}

	}
	else{
		for(int i = 0; i < n; i++){
			*((uint8_t*)(buf+i)) = paddr_read(addr+i, 1);
		}
	}
}


__EXPORT void difftest_regcpy(void *dut, bool direction) {
  	struct npc_context_t* npc_dut = (struct npc_context_t*) dut;
	if(direction == NPC_TO_NEMU){//由被测对象送给参考，即NPC送给NEMU	
		for(int i = 0; i < NR_GPR; i++){
			cpu.gpr[i] = npc_dut -> gpr[i];
		}
		cpu.pc = npc_dut -> pc;
	}
	else{//由参考送给被测对象，即NEMU送给NPC
		for(int i = 0; i < NR_GPR; i++)
			npc_dut -> gpr[i] = cpu.gpr[i];
		npc_dut -> pc = cpu.pc;
	}
}

__EXPORT void difftest_exec(uint64_t n) {
	cpu_exec(n);
}

__EXPORT void difftest_raise_intr(word_t NO) {
  assert(0);
}

__EXPORT void difftest_init(int port) {
  void init_mem();
  init_mem();
#ifdef CONFIG_DEVICE
  void init_device();
  init_device();//只有init_device，difftest才能启用nemu中的设备
#endif
  /* Perform ISA dependent initialization. */
  init_isa();
}
