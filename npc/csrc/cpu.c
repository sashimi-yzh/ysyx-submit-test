#include "common.h"
#include "VysyxSoCFull__Dpi.h"
#include "svdpi.h"
#include "cpu.h"
#include "mem.h"
#include "trace.h"
CPUState cpu;
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
void ebreak(){
	Log("ebreak at pc = " FMT_WORD, cpu.pc);
	cpu.state=NPC_END;
}
static void cpu_get_state(){
	cpu.ifu_pc = CPUTop->IFU_0->ifu_out_bus_pc;
	cpu.idu_pc = CPUTop->IF_ID_inst->idu_in_bus_pc;
	cpu.exu_pc = CPUTop->ID_EX_inst->exu_in_bus_pc;
	cpu.lsu_pc = CPUTop->EX_LS_inst->lsu_in_bus_pc;
	cpu.wbu_pc = CPUTop->LS_WB_inst->wbu_in_bus_pc;
	cpu.isRAW  = CPUTop->IDU_0->idu_isRAW;
	cpu.ifu_valid = CPUTop->IFU_0->ifu_out_valid;
	cpu.idu_valid = CPUTop->IF_ID_inst->idu_in_valid;
	cpu.exu_valid = CPUTop->ID_EX_inst->exu_in_valid;
	cpu.lsu_valid = CPUTop->EX_LS_inst->lsu_in_valid;
	cpu.wbu_valid = CPUTop->LS_WB_inst->wbu_in_valid;
	cpu.tb_isFINAL = CPUTop->tb_isFINAL;
	cpu.tb_FINAL_pc = CPUTop->tb_FINAL_pc;
	cpu.tb_FINAL_npc = CPUTop->tb_FINAL_npc;
	cpu.tb_dnpc_valid = CPUTop->tb_dnpc_valid;
	cpu.tb_isMEM = CPUTop->tb_isMEM;
	cpu.tb_FINAL_inst = CPUTop->tb_FINAL_inst;

	// cpu.pc = cpu.dnpc;
	// cpu.dnpc = top->top->student_top_inst->pc;
	for(int i=0;i<CONFIG_GPR_NUM;i++){
		cpu.gpr[i] = CPUTop->GPR_0->GPR[i];
	}
}

static void cpu_exec_once(){
	top->clock=1;
	top->eval();
	#ifdef CONFIG_WAVE_ENABLE
	// if(cpu.count > 4450000) DUMP();
	DUMP();
	#endif
	contextp->timeInc(1);
	
	top->clock=0;
	top->eval();
	#ifdef CONFIG_WAVE_ENABLE
	// if(cpu.count > 4450000) DUMP();
	DUMP();
	#endif
	contextp->timeInc(1);
}
void cpu_exec(uint64_t n){
	switch (cpu.state)
	{
		case NPC_ABORT:
		case NPC_END:
		case NPC_QUIT:
			printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
			return;
		default:
			cpu.state = NPC_RUNNING;
	}
	
	// while(cpu.ifu_state != 0 || CPUTop->reset){
	// 	cpu_exec_once();
	// }
	// int this_cnt = 0;
	// static uint64_t cyc_cnt = 0;
	while(n > 0){
		cpu_exec_once();
		#ifdef CONFIG_NVBOARD_ENABLE
			nvboard_update();
		#endif
		cpu_get_state();

		if(!CPUTop->IFU_0->ifu_out_valid) cpu.counter_IFU_get_inst_cyc ++;
		cpu.counter_cycle++;
		if(CPUTop->IFU_0->debug_IFU_get_inst) {
			cpu.counter_IFU_get_inst ++;
		}
		if(CPUTop->IFU_0->debug_IFU_is_hit_inst) cpu.counter_IFU_ichache_hit++;
		if(!CPUTop->IFU_0->debug_IFU_is_hit && !CPUTop->IFU_0->ifu_out_valid) cpu.counter_IFU_get_inst_miss_cyc ++;


		if(cpu.isRAW) cpu.counter_raw++;

		if(cpu.tb_isMEM) cpu.counter_LSU_mem++;
		if(CPUTop->LSU_0->debug_LSU_LOADING && !CPUTop->LSU_0->lsu_out_valid) cpu.counter_LSU_load_cyc++;
		else if(CPUTop->LSU_0->debug_LSU_WRITING && !CPUTop->LSU_0->lsu_out_valid) cpu.counter_LSU_store_cyc++;
		if(CPUTop->LSU_0->debug_LSU_LOAD_FINAL)	cpu.counter_LSU_get_data++;
		else if(CPUTop->LSU_0->debug_LSU_WRITE_FINAL) cpu.counter_LSU_put_data++;

		if(CPUTop->flush_valid) cpu.counter_flush++;
		if(0){
			Log("\nifu_pc= " FMT_WORD " %d\n\
				 idu_pc= " FMT_WORD " %d\n\
				 exu_pc= " FMT_WORD " %d\n\
				 lsu_pc= " FMT_WORD " %d\n\
				 wbu_pc= " FMT_WORD " %d", \
				cpu.ifu_pc, cpu.ifu_valid, \
				cpu.idu_pc, cpu.idu_valid, cpu.exu_pc, cpu.exu_valid, \
				cpu.lsu_pc, cpu.lsu_valid, cpu.wbu_pc, cpu.wbu_valid);
			// Log("isRAW= %d\n [%c]final_pc= " FMT_WORD " [%c]npc= " FMT_WORD, \
			// 	cpu.isRAW, cpu.tb_isFINAL ? 'Y' : 'N', cpu.tb_FINAL_pc, \
			// 	cpu.tb_dnpc_valid ? 'd' : 's', cpu.tb_FINAL_npc);
			// Log("cycle=%lu inst=%lu bubble=%lu raw=%lu jump=%lu mem=%lu", cpu.inst_count + cpu.bubble_count, cpu.inst_count, cpu.bubble_count, cpu.raw_count, cpu.jump_count, cpu.mem_count);

		}
		if(cpu.tb_isFINAL){
			// this_cnt = 0;
			// Log("PC=" FMT_WORD "INST=" FMT_WORD, cpu.tb_FINAL_pc, cpu.tb_FINAL_inst);
			n--;
			// cpu.FINAL_inst = cpu.tb_FINAL_inst;
			cpu.counter_inst++;
			if(cpu.tb_FINAL_inst==_EBREAK && cpu.tb_isFINAL){
				ebreak();
			}else{
				trace_and_difftest();
			}
			
			static int cnt=0;
			if(cnt++ >= 100000 || (cpu.state != NPC_RUNNING)){
				Log("\n[cyc=%ld][inst=%lu][AvgIPC=%.2f][Raw%ld][flush=%ld][PC=0x%08X]\n[GetI=%lu AvgCyc=%.2f Hit=%.2f HC=%.2f Miss=%.2f MC=%.2f]\n[MemI=%lu Avg=%.2f|LI=%lu Avg=%.2f|SI=%lu Avg=%.2f]",
					cpu.counter_cycle,cpu.counter_inst,(float)((float)cpu.counter_inst/(float)cpu.counter_cycle),cpu.counter_raw,cpu.counter_flush,cpu.tb_FINAL_pc,

					cpu.counter_IFU_get_inst,
					(float)(cpu.counter_IFU_get_inst_cyc)/(float)(cpu.counter_IFU_get_inst),
					(float)(cpu.counter_IFU_ichache_hit)/(float)(cpu.counter_IFU_get_inst),
					(float)(cpu.counter_IFU_get_inst_cyc - cpu.counter_IFU_get_inst_miss_cyc)/(float)(cpu.counter_IFU_ichache_hit),
					(float)(cpu.counter_IFU_get_inst-cpu.counter_IFU_ichache_hit)/(float)(cpu.counter_IFU_get_inst),
					(float)(cpu.counter_IFU_get_inst_miss_cyc)/(float)((cpu.counter_IFU_get_inst-cpu.counter_IFU_ichache_hit)),

					cpu.counter_LSU_mem, ((float)(cpu.counter_LSU_load_cyc+cpu.counter_LSU_store_cyc)/(float)(cpu.counter_LSU_mem)),
					cpu.counter_LSU_get_data, (float)((float)(cpu.counter_LSU_load_cyc)/(float)(cpu.counter_LSU_get_data)),
					cpu.counter_LSU_put_data, (float)((float)(cpu.counter_LSU_store_cyc)/(float)(cpu.counter_LSU_put_data))
				);
				cnt=0;
			}
			
			// cpu.mem_access_addr = 0;
			if(cpu.state != NPC_RUNNING) break;
		}
		else{
			continue;
		}
		// Log("MROM[0]=" FMT_WORD ,MROM[0]);
		// Log("RPC = " FMT_WORD,cpu.pc);

	}
	
	switch (cpu.state)
	{
		case NPC_ABORT:
		case NPC_END: {
			contextp->timeInc(1);DUMP();
			contextp->timeInc(1);DUMP();
			contextp->timeInc(1);DUMP();
			bool success = true;
			cpu.halt_ret = reg_str2val("$a0", &success);
			Assert(success, "Cannot to get the value of '$a0'");
			#ifdef CONFIG_FTRACE_ENABLE
			printf("===\n%s\n===\n",ftrace_log.buf);
			#endif
			Log("npc: %s at pc = " FMT_WORD, \
				(cpu.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) : \
				(cpu.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : \
				ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))), \
				cpu.tb_FINAL_pc);
			Log("Halt code = " FMT_WORD, cpu.halt_ret);
			Log("Total instruction = %lu", cpu.count);
			break;
		}
		case NPC_RUNNING:
			cpu.state = NPC_STOP;
			break;
	}
}


void reg_display(CPUState cpu) {
  for(int i=0;i<CONFIG_GPR_NUM;i++){
    printf("%02d $%s\t" FMT_WORD "\t%d\n",i,regs[i],cpu.gpr[i],cpu.gpr[i]);
  }
  printf("$pc\t0x%08x\t%d\n",cpu.tb_FINAL_pc,cpu.tb_FINAL_pc);
}

uint32_t reg_str2val(const char *s, bool *success) {
  if(s[0]=='$') s++;
  else{
    *success=false;
    return 0;
  }
  if(strcmp(s,"0")==0)  return cpu.gpr[0];
  for(int i=0;i<CONFIG_GPR_NUM;i++){
    if(strcmp(s,regs[i])==0)  return cpu.gpr[i];
  }
  if(strcmp(s,"pc")==0) return cpu.pc;
  *success=false;
  return 0;
}



void assert_fail_msg() {
  reg_display(cpu);
}

