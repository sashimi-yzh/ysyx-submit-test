#include <stdio.h>
#include <stdlib.h>

#include "VysyxSoCFull.h"
#include <verilated.h>

#include "npc.h"
#include "sdb.h"
#include "trace.h"
#include "difftest.h"

#ifdef WAVE
	#include "verilated_vcd_c.h"   //用来生成vcd
	VerilatedVcdC *tfp = new VerilatedVcdC;   //初始化VCD对象指针
#endif

TOP_NAME* top; //声明全局模块实例 
VerilatedContext* contextp = new VerilatedContext;  //管理仿真时间、命令行参数等全局状态。

#ifdef NVBOARD
	#include <nvboard.h>   //启用nvboard
	void nvboard_bind_all_pins(TOP_NAME* top);//声明 NVBoard 引脚绑定函数
#endif

CPU_state npc;
int npc_state = NPC_RUNNING;
static int instruction_fin = 0; 
static int bootloader_sdram = 1;

//性能计数器
static uint64_t cycle_count = 0; 	//运行周期数
//static uint64_t exu_count = 0; 		//EXU完成计算
static uint64_t ifu_count = 0; 		//IFU取到指令
static uint64_t ifu_start = 0; 		//IFU取指令的开始周期
static uint64_t ifu_cycle = 0; 		//IFU取到指令所需周期数
static uint64_t ifu_flash_count = 0; //IFU向flash取值的次数
static uint64_t ifu_sram_count = 0;  //IFU向fsram取值的次数
static uint64_t ifu_sdram_count = 0; //IFU向sdram取值的次数
static uint64_t ifu_flash_cycle = 0;	//IFU向flash取值的所需周期数
static uint64_t ifu_sram_cycle = 0;	//IFU向sram取值的所需周期数
static uint64_t ifu_sdram_cycle = 0;	//IFU向sdram取值的所需周期数(ebreak指令没有被通记录，8个周期) 

static uint64_t icache_count = 0; 		//icache接收访存请求
static uint64_t icache_start = 0; 		//icache接收访存请求的开始周期
static uint64_t icache_cycle = 0; 		//icache所需全部周期数
static uint64_t icache_check_count = 0; //icache命中的次数
static uint64_t icache_sdram_count = 0;  //icache访问DRAM的时间的次数
static uint64_t icache_check_cycle = 0;	//从cache接收访存请求到得出命中结果所需的时间
static uint64_t icache_sdram_cycle = 0;	//cache缺失时的代价, 此处即访问DRAM的时间.

static uint64_t lsu_count = 0; 		//LSU访存的次数
static uint64_t lsu_load_count = 0; 	//LSU取到数据的次数
static uint64_t lsu_store_count = 0; //LS写入数据的次数
static uint64_t lsu_start = 0; 		//LSU访存的开始周期
static uint64_t lsu_cycle = 0; 		//LSU访存的所需周期数
static uint64_t lsu_load_cycle = 0; 	//LSU取到数据的所需周期数
static uint64_t lsu_store_cycle = 0; //LS写入数据的所需周期数
static uint64_t inst_count = 0; 		//共计指令
//static uint64_t inst_start = 0;			//译码出各种类别的指令
static uint64_t alui_count = 0;		
static uint64_t loadi_count = 0; 
static uint64_t storei_count = 0; 
static uint64_t csri_count = 0; 
static uint64_t loadi_cycle = 0; 	//各种类别的指令需要执行多少个周期
static uint64_t storei_cycle = 0; 
static uint64_t csri_cycle = 0; 
static uint64_t alui_cycle = 0;	

typedef struct {
    uint64_t start;
    int type;
} InstEntry;
static InstEntry inst_buf[10] = {{0}};  // 全部初始化为0
enum { INST_ALU, INST_CSR, INST_LOAD, INST_STORE};	
static uint64_t inst_buf_rptr = 0;	
static uint64_t inst_buf_wptr = 0;	
static uint64_t inst_buf_wptr2 = 0;	

bool npc_without_soc = false; 
#ifdef NPC_WITHOUT_SOC
static int ren = 0;	
static int wen = 0;
static int burst = 0;
static uint32_t addr = 0;	
#endif

//性能计数器(性能事件的检测信号通过DPI-C接入到仿真环境, 在仿真环境中实现性能计数器. )
extern "C" void NPC_Cloud_ifu_count(uint32_t addr){
	//printf("ifu_addr=0x%x\n",addr);
	ifu_count++;
	ifu_cycle += cycle_count- ifu_start;
	if(addr >> 28 == 0x3){
		ifu_flash_count++;
		ifu_flash_cycle += cycle_count- ifu_start;
	} else if(addr >> 24 == 0x0f){
		ifu_sram_count++;
		ifu_sram_cycle += cycle_count- ifu_start;
	} else if(addr >> 28 == 0xa){
		ifu_sdram_count++;
		ifu_sdram_cycle += cycle_count- ifu_start;
	} 
	// else{
	// 	if(npc_without_soc == false){panic("ifu error addr:0x%x",addr);}
	// }
}

extern "C" void NPC_Cloud_ifu_start(uint32_t addr){ 
	ifu_start = cycle_count;	
	//printf("ifu_addr=0x%x\n",addr);
	// if( (addr >> 28 != 0x3) && (addr >> 24 != 0x0f) && (addr >> 28 != 0xa) ){
	// 	if(npc_without_soc == false){panic("ifu error addr:0x%x",addr);}
	// }
	/*记录目前周期数*/
	inst_buf[inst_buf_wptr].start = cycle_count; 
	if(inst_buf_wptr == 9) {inst_buf_wptr = 0;}
	else {inst_buf_wptr++; }	
	//printf("inst_start[%ld] = %ld\n",inst_buf_wptr, cycle_count);
}

extern "C" void NPC_Cloud_icache_start(uint32_t addr){ 
	if( (addr >> 28 != 0xa) ){return;}
	//icache_count++;	
	icache_start = cycle_count;	
}


extern "C" void NPC_Cloud_icache_check(uint32_t addr){ 
	if( (addr >> 28 != 0xa) ){return;}
	icache_count++;	
	icache_check_count++;	
	icache_cycle += cycle_count - icache_start;	
	icache_check_cycle += cycle_count - icache_start;	
}

extern "C" void NPC_Cloud_icache_sdram(uint32_t addr){ 
	if( (addr >> 28 != 0xa) ){return;}
	icache_count++;	
	icache_sdram_count++;	
	icache_cycle += cycle_count - icache_start;	
	icache_sdram_cycle += cycle_count - icache_start;	
}

extern "C" void NPC_Cloud_lsu_start(){ lsu_count++; lsu_start = cycle_count;}
extern "C" void NPC_Cloud_lsu_rcount(){ 
	lsu_load_count++; 
	lsu_cycle += cycle_count- lsu_start; 
	lsu_load_cycle += cycle_count- lsu_start; 
	inst_buf[inst_buf_wptr2].type = INST_LOAD;
	if(inst_buf_wptr2 == 9) {inst_buf_wptr2 = 0;}
	else {inst_buf_wptr2++; }	
}
extern "C" void NPC_Cloud_lsu_wcount(){ 
	lsu_store_count++; 
	lsu_cycle += cycle_count- lsu_start; 
	lsu_store_cycle += cycle_count- lsu_start; 
	inst_buf[inst_buf_wptr2].type = INST_STORE;
	if(inst_buf_wptr2 == 9) {inst_buf_wptr2 = 0;}
	else {inst_buf_wptr2++; }	
}

extern "C" void NPC_Cloud_alu_count(){ 
	alui_count++; 
	inst_buf[inst_buf_wptr2].type = INST_ALU;
	if(inst_buf_wptr2 == 9) {inst_buf_wptr2 = 0;}
	else {inst_buf_wptr2++; }	
}
//extern "C" void NPC_Cloud_load_count(){	loadi_count++; inst_buf[inst_buf_wptr] = INST_ALU;}
//extern "C" void NPC_Cloud_store_count(){ storei_count++; inst_buf[inst_buf_wptr] = INST_ALU;}
extern "C" void NPC_Cloud_csr_count(){ 
	csri_count++; 
	inst_buf[inst_buf_wptr2].type = INST_CSR;
	if(inst_buf_wptr2 == 9) {inst_buf_wptr2 = 0;}
	else {inst_buf_wptr2++; }	
}

//在RTL代码中利用DPI-C机制, 使得在NPC执行ebreak指令时结束仿真
extern "C" void NPC_Cloud_trap_ebreak(){ 
	npc_state = NPC_END;
}

extern "C" void NPC_Cloud_itrace(uint32_t top_pc, uint32_t top_inst, uint32_t top_dnpc){
	npc.pc = top_pc;
	npc.inst = top_inst;
	npc.dnpc = top_dnpc;
	instruction_fin = 1;
	
	inst_count++;

	/*根据指令类型，增加对应指令周期数*/
	if(inst_buf[inst_buf_rptr].type == INST_ALU){
		alui_cycle += cycle_count- inst_buf[inst_buf_rptr].start; 
		//printf("ALU_cycle:%ld\n", cycle_count- inst_buf[inst_buf_rptr].start);
	}
	else if(inst_buf[inst_buf_rptr].type == INST_CSR){
		csri_cycle += cycle_count- inst_buf[inst_buf_rptr].start; 
		//printf("CSR_cycle:%ld\n", cycle_count- inst_buf[inst_buf_rptr].start);
	}
	else if(inst_buf[inst_buf_rptr].type == INST_LOAD){
		loadi_cycle += cycle_count- inst_buf[inst_buf_rptr].start; 
		//printf("LOAD_cycle:%ld\n", cycle_count- inst_buf[inst_buf_rptr].start);
	}
	else if(inst_buf[inst_buf_rptr].type == INST_STORE){
		storei_cycle += cycle_count- inst_buf[inst_buf_rptr].start; 
		//printf("store_cycle:%ld\n", cycle_count- inst_buf[inst_buf_rptr].start);
	}
	if(inst_buf_rptr == 9) {inst_buf_rptr = 0;}
	else {inst_buf_rptr++; }

	


	if(npc_state == NPC_END) {npc.dnpc = 0;}
	//exu_count++;
	// if((csri_cycle + storei_cycle + loadi_cycle + alui_cycle) != cycle_count){
	// 	panic("Total Cycle:%ld\nalui_cycle=%ld csri_cycle=%ld storei_cycle=%ld loadi_cycle=%ld\n",
	// 			cycle_count, alui_cycle, csri_cycle, storei_cycle, loadi_cycle);
	// }

	//ftrace
	if(NPC_FTRACE){
		// 从指令中提取字段
    	uint32_t inst = npc.inst ;
    	uint8_t opcode = inst & 0x7F;
    	uint8_t rd = (inst >> 7) & 0x1F;
		if( (opcode == 0x67) && ( ( (inst >> 12) & 0x7) == 0x0 ) ){//jalr指令
			int32_t imm = (int32_t)(inst & 0xFFF00000) >> 20;
			if(rd == 1) {  /*跳转到目标地址,保存返回地址(pc+4)到 ra(x1)*/
				trace_func_call(npc.pc, npc.dnpc, false);
			} 
			else if  (inst == 0x00008067) {  /*ret: 函数返回,跳转回ra*/\
				trace_func_ret(npc.pc);
			} 
			else if (rd == 0 && imm == 0) { /* 尾调用: 不保存返回地址 */
				trace_func_call(npc.pc, npc.dnpc, true);
			}
		}
		if (opcode == 0x6F){
			if(rd == 1) {/*跳转到目标地址,保存返回地址(pc+4)到 ra(x1)*/
				trace_func_call(npc.pc, npc.dnpc, false);
			} 
			else if(rd == 0) {trace_func_call(npc.pc, npc.dnpc, true);} /* 尾调用: 不保存返回地址 */
		}
	}
}//在RTL代码中利用DPI-C机制, 访问pc和指令

extern "C" void NPC_Cloud_reg(uint32_t top_rf, int i){//在RTL代码中利用DPI-C机制, 访问寄存器
	if(i != 0){npc.gpr[i] = top_rf;}
	if(NPC_RTRACE && bootloader_sdram) printf("[NPC_Cloud_reg]%s:gpr[%d] = 0X%08X\n",regs[i], i, npc.gpr[i]);
}

void single_cycle() {//模拟一个时钟周期：
	top->clock = 0; top->eval();
	#ifdef WAVE
		contextp->timeInc(1); tfp->dump(contextp->time());//仿真时间+1, 记录当前时间点的信号波形到VCD文件
	#endif

	top->clock = 1; top->eval();
	#ifdef WAVE
		contextp->timeInc(1); tfp->dump(contextp->time());//仿真时间+1, 记录当前时间点的信号波形到VCD文件
	#endif

}

void reset(int n) {
  top->reset = 1;
  while (n -- > 0) single_cycle();
  top->reset = 0;
}//初始化模块状态,复位


void exec_once(){//单次激励
	cycle_count++; //if(NPC_ITRACE) printf("第%ld周期\n", cycle_count);
	single_cycle();

	#ifdef NVBOARD
		nvboard_update();   //更新NVBoard各组件状态	
	#endif

	//assert(cycle_count < 30100);
}


void exec_once_npc(){//单次激励，没有soc
#ifdef NPC_WITHOUT_SOC
	//printf("make ARCH=riscv32e-npc run\n");
	cycle_count++; //if(NPC_ITRACE) printf("第%ld周期\n", cycle_count);
	//int burst = 0;

	//single_cycle();	
	top->clock = 0; top->eval();
	#ifdef WAVE
		contextp->timeInc(1); tfp->dump(contextp->time());//仿真时间+1, 记录当前时间点的信号波形到VCD文件
	#endif


 	/*在clk上升沿翻转*/
	top->io_master_awready = true;
	top->io_master_wready = true;
	top->io_master_bvalid = false;
	top->io_master_bresp = 0;
	top->io_master_bid = 0;
	top->io_master_arready = true;
	top->io_master_rvalid = false;
	top->io_master_rresp = 0;
	top->io_master_rdata = 0;
	top->io_master_rlast = false;
	top->io_master_rid = 0;


	if(wen > 0){ //写入数据，下一个周期返回bvalid
		pmem_write((addr >> 2) << 2, top->io_master_wdata, top->io_master_wstrb);
		top->io_master_bvalid = true;
		wen = 0;
	}

	if(ren > 0){  //读取数据，每隔一周期返回一次数据
		ren++;
		if(ren % 2 == 0){
			//printf("raddr = 0x%x ren =%d", top->io_master_araddr , ren);
			top->io_master_rdata = pmem_read( ((addr >> 2) << 2) + 2*(ren-2));
			//printf("pc:[0x%x]=0x%08x\n", (top->io_master_araddr >> 2) << 2,top->io_master_rdata);
			top->io_master_rvalid = true;		
			if(ren /2 == (top->io_master_arlen + 1)){//突发传输则标记
				top->io_master_rlast = true;
				ren = 0;
			}
		}
	}
	
	if(top->io_master_arvalid){  //读取数据，下一个周期写入并返回rvalid
		ren++;
		addr = top->io_master_araddr;
		//if(top->io_master_arlen != 0){burst++;} //突发传输则标记
	}
	if(top->io_master_awvalid && top->io_master_wvalid){ //写入数据，下一个周期返回bvalid
		wen++;
		addr = top->io_master_awaddr;
	}

	// if(ren > 0){  //读取数据，下一个周期写入并返回rvalid
	// 		printf("raddr = 0x%x ren =%d addr = 0x%x\n", top->io_master_araddr , ren, ((top->io_master_araddr >> 2) << 2) + 4*(ren-1) );
	// 		top->io_master_rdata = pmem_read( ((top->io_master_araddr >> 2) << 2) + 4*(ren-1));
	// 		//printf("pc:[0x%x]=0x%08x\n", (top->io_master_araddr >> 2) << 2,top->io_master_rdata);
	// 		top->io_master_rvalid = true;		
	// 		if(ren  == (top->io_master_arlen + 1)){//突发传输则标记
	// 			top->io_master_rlast = true;
	// 			ren = 0;
	// 		} else {
	// 			ren++;
	// 		}
		
	// }

	top->clock = 1; top->eval();
	#ifdef WAVE
		contextp->timeInc(1); tfp->dump(contextp->time());//仿真时间+1, 记录当前时间点的信号波形到VCD文件
	#endif


#endif
// AXI写地址通道
            // printf("Write Address Channel:\n");
            // printf("  awvalid=%d, awaddr=0x%08x, awid=%d\n",
            //        top->io_master_awvalid, top->io_master_awaddr, top->io_master_awid);
            // printf("  awlen=%d, awsize=%d, awburst=%d, awready=%d\n",
            //        top->io_master_awlen, top->io_master_awsize, 
            //        top->io_master_awburst, top->io_master_awready);
            
            // // AXI写数据通道
            // printf("Write Data Channel:\n");
            // printf("  wvalid=%d, wdata=0x%08x, wstrb=0x%x\n",
            //        top->io_master_wvalid, top->io_master_wdata, top->io_master_wstrb);
            // printf("  wlast=%d, wready=%d\n",
            //        top->io_master_wlast, top->io_master_wready);
            
            // // AXI写响应通道
            // printf("Write Response Channel:\n");
            // printf("  bready=%d, bvalid=%d, bresp=%d, bid=%d\n",
            //        top->io_master_bready, top->io_master_bvalid,
            //        top->io_master_bresp, top->io_master_bid);
            
            // // AXI读地址通道
            // printf("Read Address Channel:\n");
            // printf("  arvalid=%d, araddr=0x%08x, arid=%d\n",
            //        top->io_master_arvalid, top->io_master_araddr, top->io_master_arid);
            // printf("  arlen=%d, arsize=%d, arburst=%d, arready=%d\n",
            //        top->io_master_arlen, top->io_master_arsize,
            //        top->io_master_arburst, top->io_master_arready);
            
            // //AXI读数据通道
            // printf("Read Data Channel:\n");
            // printf("  rready=%d, rvalid=%d, rresp=%d\n",
            //        top->io_master_rready, top->io_master_rvalid, top->io_master_rresp);
            // printf("  rdata=0x%08x, rlast=%d, rid=%d\n",
            //        top->io_master_rdata, top->io_master_rlast, top->io_master_rid);
            
            // 监控特定事件
            // if (top->io_master_awvalid && top->io_master_awready) {
            //     printf("[EVENT] Write address accepted: 0x%08x\n", top->io_master_awaddr);
            // }
            // if (top->io_master_wvalid && top->io_master_wready && top->io_master_wlast) {
            //     printf("[EVENT] Write burst completed\n");
            // }
            // if (top->io_master_arvalid && top->io_master_arready) {
            //     printf("[EVENT] Read address accepted: 0x%08x\n", top->io_master_araddr);
            // }
            // if (top->io_master_rvalid && top->io_master_rready && top->io_master_rlast) {
            //     printf("[EVENT] Read burst completed, data=0x%08x\n", top->io_master_rdata);
            // }

	// #ifdef NVBOARD
	// 	nvboard_update();   //更新NVBoard各组件状态	
	// #endif

	//assert(cycle_count < 100);
}


void cpu_exec(uint64_t n) {//执行指令

	//printf("pc[0X%08X]\n",top->io_pc);
	for (;n > 0; n --) {

		if(npc_without_soc == false){ //make ARCH=riscv32e-ysyxSoC run
			exec_once();
		} else {//make ARCH=riscv32e-npc run 没有soc
			exec_once_npc();
		}

		if(npc.dnpc >= 0xa0000000){bootloader_sdram = 1;}
		if(bootloader_sdram && instruction_fin){
			//printf("npc.pc=0x%x, npc.inst=0x%x, npc.dnpc=0x%x\n", npc.pc, npc.inst, npc.dnpc);
			#ifdef NPC_ITRACE 
				instruction_trace(npc.pc, npc.inst, npc.dnpc);//指令trace&&反汇编	
			#endif	
			if(NPC_DIFFTEST) {	difftest_step(npc.pc, npc.dnpc); }//差分测试
			instruction_fin = 0;
		}
		//assert(npc.pc != 0x30000054);
		if(SCAN_WATCHPOINT){//设置监视点
			if( (scan_watchpoint()) && (npc_state != NPC_END) ){
				break;
			}
		}
		if(npc_state == NPC_END || npc_state == NPC_ABORT){
			Log("Simulation terminated by EBREAK instruction.");		
			
			printf("=== CPU Performance Summary ===\n");
			printf("Total Cycle:\t\t\t%lu\nEXU Instructions Executed:\t%lu\n", cycle_count, inst_count);
			printf("IPC(Instructions Per Cycle):\t%.2f%%\n", (double)inst_count/cycle_count * 100); 
			
			printf("\n=== IFU (Instruction Fetch Unit) Analysis ===\n");
			printf("- Total Fetch Count:\t%lu\t\t",ifu_count);
			printf("Average Latency: %.2f\t", (double)ifu_cycle/ifu_count);
			printf("Total Latency:%ld\n", ifu_cycle);
			printf("- Flash Accesses:\t%lu(%.2f%%)\t",ifu_flash_count, (double)ifu_flash_count/ifu_count * 100);
			printf("Average Latency: %.2f\t", (double)ifu_flash_cycle/ifu_flash_count);
			printf("Total Latency:%ld\n", ifu_flash_cycle);
			printf("- SRAM Accesses:\t%lu(%.2f%%)\t",ifu_sram_count, (double)ifu_sram_count/ifu_count * 100);
			printf("Average Latency: %.2f  \t", (double)ifu_sram_cycle/ifu_sram_count);
			printf("Total Latency:%ld\n", ifu_sram_cycle);
			printf("- SDRAM Accesses:\t%lu(%.2f%%)\t",ifu_sdram_count, (double)ifu_sdram_count/ifu_count * 100);
			printf("Average Latency: %.2f\t", (double)ifu_sdram_cycle/ifu_sdram_count);
			printf("Total Latency:%ld\n", ifu_sdram_cycle);

			printf("\n=== Instruction Cache (Only SDRAM) Analysis ===\n");
			printf("- Total Accesses:\t%lu\t\t",icache_count);
			printf("Average Latency: %.2f\tTotal Latency:%ld\n", (double)icache_cycle/icache_count, icache_cycle);
			printf("- Cache Hits:    \t%lu(%.2f%%)\t",icache_check_count, (double)icache_check_count/icache_count * 100);
			printf("Average Latency: %.2f\tTotal Latency:%ld\n", (double)icache_check_cycle/icache_check_count, icache_check_cycle);
			printf("- Cache Misses:  \t%lu(%.2f%%)\t",icache_sdram_count, (double)icache_sdram_count/icache_count * 100);
			printf("Average Latency: %.2f\tTotal Latency:%ld\n", (double)icache_sdram_cycle/icache_sdram_count, icache_sdram_cycle);
			printf("- AMAT(Average Memory Access Time):\t%lf\n",(double)icache_check_cycle/icache_check_count + ((double)icache_sdram_cycle/icache_sdram_count) * ((double)icache_sdram_count/icache_count));
			
			printf("\n=== LSU (Load Store Unit) Analysis ===\n");
			printf("- Total Operations:\t%lu\t\t",lsu_count);
			printf("Average Latency: %.2f\tTotal Latency:%ld\n", (double)lsu_cycle/lsu_count, lsu_cycle);
			printf("- Load Operations:\t%lu\t\t",lsu_load_count);
			printf("Average Latency: %.2f\tTotal Latency:%ld\n", (double)lsu_load_cycle/lsu_load_count, lsu_load_cycle);
			printf("- Store Operations:\t%lu\t\t",lsu_store_count);
			printf("Average Latency: %.2f\tTotal Latency:%ld\n", (double)lsu_store_cycle/lsu_store_count, lsu_store_cycle);

			printf("\n=== Instruction Type Analysis ===\n");
			printf("- Total Instruction:\t%lu\n",inst_count);
			printf("- ALU Instruction:\t%lu(%.2f%%)\t",alui_count, (double)alui_count/inst_count * 100 );
			//printf("\n");
			printf("Average Cycles:  %.2f\tTotal Cycles:%ld\n",  (double)alui_cycle/alui_count, alui_cycle);
			printf("- CSR Instruction:\t%lu(%.2f%%)\t",csri_count, (double)csri_count/inst_count * 100);
			//printf("\n");
			printf("Average Cycles:  %.2f\tTotal Cycles:%ld\n", (double)csri_cycle/csri_count, csri_cycle);
			printf("- Memory Access:\t%lu(%.2f%%)\t",lsu_load_count + lsu_store_count, (double)(lsu_load_count + lsu_store_count)/inst_count * 100);
			//printf("\n");
			printf("Average Cycles:  %.2f\tTotal Cycles:%ld\n", (double)(loadi_cycle + storei_cycle)/(lsu_load_count + lsu_store_count), (loadi_cycle + storei_cycle));
			printf("  - Load Instruction:\t%lu(%.2f%%)\t",lsu_load_count, (double)lsu_load_count/inst_count * 100);
			//printf("\n");
			printf("Average Cycles:  %.2f\tTotal Cycles:%ld\n", (double)loadi_cycle/lsu_load_count, loadi_cycle);
			printf("  - Store Instruction:\t%lu(%.2f%%)\t",lsu_store_count, (double)lsu_store_count/inst_count * 100);
			printf("Average Cycles:  %.2f\tTotal Cycles:%ld\n", (double)storei_cycle/lsu_store_count, storei_cycle);
			printf("\n");

			if(npc_state == NPC_ABORT){
				Log("\33[1;31m" "Invalid opcode" "\33[0m" "(PC = 0X%08X inst = 0X%08X)", npc.pc, npc.inst);
				return;
			} else if(npc.gpr[10] == 0){    //a0:函数参数/返回值寄存器,为0则正常结束
				Log("NPC_Cloud execution terminated: " "\33[1;32m" "HIT GOOD TRAP " "\33[0m" "at pc = 0x%08x", npc.dnpc);
				return;
			} else{
				Log("NPC_Cloud execution terminated: " "\33[1;31m" "Fault " "\33[0m" "at pc = 0x%08x" " (a0 = %d)", npc.dnpc, npc.gpr[10]);
				return;
			}
		}
		// if(npc_state == NPC_ABORT){
		// 	Log("Simulation terminated by EBREAK instruction.");	
		// 	Log("\33[0m" "Total Cycle Count:%d",cycle_count);
		// 	Log("33[0m" "Total Instruction Count:%d",inst_count);
		// 	Log("\33[1;31m" "invalid opcode" "\33[0m" "(PC = 0X%08X inst = 0X%08X)", npc.pc, npc.inst);
		// 	return;
		// }
	}
}


int main(int argc,char *argv[])
{
	/*初始化 Verilator*/
	//VerilatedContext* contextp = new VerilatedContext; //管理仿真时间、命令行参数等全局状态。
	contextp->commandArgs(argc, argv);//解析命令行
	top = new VysyxSoCFull{contextp}; //实例化模块.用contextp初始化Vtop对象（传递仿真上下文）

	/*初始化波形记录（VCD 文件）*/
	#ifdef WAVE
		Verilated::traceEverOn(true);// 启用波形跟踪
	//VerilatedVcdC *tfp= new VerilatedVcdC;   //初始化VCD对象指针，在全局变量中定义
		top->trace(tfp,99);// 绑定模块信号到 VCD 文件（99=递归跟踪深度）
		tfp->open("wave.vcd");  //保存位置
		Log("Waveform recorder initialized!");
	#endif

	/*接入nvboard（例程中copy）*/
	#ifdef NVBOARD
		nvboard_bind_all_pins(top);//绑定引脚,完成所有信号的绑定
		nvboard_init();//初始化NVBoard
		Log("NVBoard initialized!");
	#endif

	
	Verilated::commandArgs(argc, argv);/*接入ysyxSoC*/

	/*导入.bin .elf等文件*/
	const char* img_file = NULL; 
	const char* elf_file = NULL; 
	static char *diff_so_file = NULL;
	static int difftest_port = 1234;
	if (argc > 1) {
        img_file = argv[1];
        Log("Load img_file: %s", img_file);
    	for (int i = 1; i < argc; i++) {
        	if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            	elf_file = argv[++i];
            	Log("Load elf_file: %s", elf_file);
        	} else if (strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
            	diff_so_file = argv[++i];
            	Log("Load diff_so_file: %s", diff_so_file);
        	} else if (strcmp(argv[i], "-b") == 0) {
				sdb_set_batch_mode();
            	Log("Batch processing mode");
        	}else if (strcmp(argv[i], "npc") == 0) {
				npc_without_soc = true;
            	Log("Running NPC_cloud without SoC");
        	}
    	}
    } else {Log("No command line arguments provided.");}

	if(npc_without_soc == false) Log("Running NPC_cloud with SoC");

	long img_size = load_img(img_file);//导入镜像文件（.bin）,初始化存储器和寄存器
	
	if (NPC_FTRACE) {load_elf(elf_file);}/* Initialize .elf */
	if (NPC_DIFFTEST) init_difftest(diff_so_file, img_size, difftest_port);//difftest初始化
	
	/* Initialize the simple debugger. */
	init_regex(); /* Compile the regular expressions. */
	init_wp_pool();/* Initialize the watchpoint pool. */

	
	#ifdef NPC_ITRACE 
		init_disasm();//反汇编初始化
	#endif

	reset(10);  // 复位10个周期s
	if(npc_without_soc == false){
		for(int i = 0; i < 10; i++){single_cycle();}  //SoC(MROM)有10周期延迟的reset，通过移位器实现
	}

	Log("NPC_Cloud begins to execute instructions:");
	sdb_mainloop();
 		
	#ifdef WAVE 
		tfp->close();// 关闭波形文件
	#endif

	delete top;// 释放模块
	delete contextp; // 释放仿真上下文

	#ifdef NVBOARD
		nvboard_quit();//退出NVBoard
	#endif
	
	int good = (npc_state == NPC_END) || (npc_state == NPC_QUIT);
	return !good;
}
