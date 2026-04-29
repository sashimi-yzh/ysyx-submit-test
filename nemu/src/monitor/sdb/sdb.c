/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
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
#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <memory/paddr.h>
#include "sdb.h"
#include "utils.h"
#include "cpu/difftest.h"

#include <sdbc.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

static sdb_debuger dbg;
static bool _sdb_inited=false;
#define _skip_when_noinit() do{if(!_sdb_inited)return;}while(0)

void sync_sdb_state_to_nemu(){
	_skip_when_noinit();
	sdbc_cpu_state sdb_s=sdb_get_state(dbg);
	nemu_state.state=sdb_s.state;
	nemu_state.halt_pc=sdb_s.pc;
	nemu_state.halt_ret=sdb_s.halt_ret;
}
void sync_nemu_state_to_sdb(){
	_skip_when_noinit();
	sdbc_cpu_state sdb_s;
	sdb_s.state=nemu_state.state;
	sdb_s.pc=nemu_state.halt_pc;
	sdb_s.halt_ret=nemu_state.halt_ret;
	sdb_set_state(dbg, sdb_s);
}
void set_nemu_state(int state, vaddr_t pc, int halt_ret)
{
	_skip_when_noinit();
	IFDEF(CONFIG_DIFFTEST,sdb_skip_difftest_ref(dbg));
  nemu_state.state = state;
  nemu_state.halt_pc = pc;
  nemu_state.halt_ret = halt_ret;
	sync_nemu_state_to_sdb();
}

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
		sdb_exec(dbg, "c");
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
		sdb_exec(dbg, str);
		sync_sdb_state_to_nemu();
		if(nemu_state.state==NEMU_QUIT)break;

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

  }
}

sdb_paddr_t cpu_exec_wrapper(size_t nstep) {
	cpu_exec(nstep);
	return cpu.pc;
}
uint8_t* wrap_mem_loader(sdb_paddr_t addr, size_t nbyte){
	return (uint8_t*)guest_to_host(addr);
}
void wrap_shotreg(uint32_t* reg_snapshot){
	memcpy(reg_snapshot, cpu.gpr, sizeof(cpu.gpr));
}
sdbc_vlen_inst wrap_fetch_inst(sdb_paddr_t pc){
	sdbc_vlen_inst	inst_code;
	inst_code.data=(uint8_t*)guest_to_host(pc);
	if(inst_code.data==NULL){
		printf("\nFailed to fetch instruction at pc = " FMT_PADDR "\n", pc);
	}
	inst_code.len=4;
	return inst_code;
}

sdb_debuger get_debuger(){
	return dbg;
}

void init_sdb() {

  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();

	extern const char* regs[32];
	extern long img_size;

	dbg=sdb_create_debuger(
			CONFIG_MBASE,img_size,
			cpu_exec_wrapper,
			wrap_mem_loader,
			wrap_shotreg,
		 	regs, 32, 
			wrap_fetch_inst);
	assert(dbg);
	_sdb_inited=true;
	uint32_t flags=0;
#ifdef CONFIG_ITRACE
	flags|=SDB_ENTRACE_INST;
#ifdef CONFIG_DIFFTEST
	flags|=SDB_ENTRACE_DIFFTEST;
#endif
#ifdef CONFIG_FTRACE
	flags|=SDB_ENTRACE_FUNC;
#endif
#else
#ifdef CONFIG_DIFFTEST
	printf("[W] difftest unwork when itrace turn off\n");
#endif
#endif
	sdb_enable_entrace(dbg, flags);
}
