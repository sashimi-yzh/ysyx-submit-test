#include <circuit.h>
#include <my_memory.h>
#include <common.h>
#include <ftrace.h>
#include <device.h>
#include <../monitor/sdb/sdb.h>
#include <pcounter.h>

CPU *cpu;

#ifdef CONFIG_ITRACE
extern "C" void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
#endif
static void statistic();
void difftest_step();

#define MAX_INST_TO_PRINT 10
#define LOG_BUF_SIZE 256
uint64_t g_nr_guest_inst = 0;


uint64_t cycle = 0;
double avg_cycle[5] = {0};


static bool g_print_step = false;
word_t pc, snpc, dnpc, inst, prev_pc, PCW, if_valid, wb_ready;
word_t mtvec, mepc, mcause, mstatus;
word_t pc_w, npc_w;
uint64_t timer_start, timer_end,g_timer;	// 测试运行的时间的
static uint8_t opcode;

// TAG: 判断一条指令是否卡死使用
word_t prev_inst;
uint32_t ins_counter;	// 计数这个指令运行了多少个周期,超过一定的周期就停止

static bool is_change = false;	// 监视点是否有改变

void single_cycle(){  //  0 --> 0 > 1 --> 1 > 0 this is a cycle in cpu  _|-|_|-
	cpu->clock=0;   //negedge 1->0 no
    cpu->eval();  //process 0->0 refresh combination logic and make them stable
	#ifdef CONFIG_DUMP_WAVE
	// if(pc >= 0xa0000000){
		dump_wave_inc();
	// }
	#endif
	cpu->clock=1;   //posedge 0->1 refresh sequential logic
    cpu->eval();  //process 1->1 refresh sequential logic(sim)
	#ifdef CONFIG_DUMP_WAVE
	// if(pc >= 0xa0000000){
		dump_wave_inc();
	// }
	#endif
}

void reset_cpu(int n) {
	cpu->reset = 1;
 	while (n -- > 0) single_cycle();
	cpu->reset = 0;
}

void assert_fail_msg() {
#ifdef CONFIG_SOC
	nvboard_quit();
#endif
	isa_reg_display();
	statistic();
}

/**
 * 反汇编以及写文件
 */
#ifdef CONFIG_ITRACE
void instruction_disassemble(char *p, uint8_t *inst){
	char *ps = p;
	p += snprintf(p, LOG_BUF_SIZE, "%#x:",pc);
	int ilen = 4;
	int i;
	for (i = ilen - 1; i >= 0; i --) {
		p += snprintf(p, 4, " %02x", inst[i]);
	}
	int ilen_max = 4;
	int space_len = ilen_max - ilen;
	if (space_len < 0) space_len = 0;
	space_len = space_len * 3 + 1;
	memset(p, ' ', space_len);
	p += space_len;
	
	disassemble(p, ps + LOG_BUF_SIZE - p, (uint64_t)pc, inst, ilen);
}
#endif

/**
 * DiffTest
 */
static void trace_and_difftest() {

	/**
	 * 1、监视点的比较测试
	 */
	#ifdef CONFIG_CC_WATCHPOINT
		bool point_diff = point_difftest();
		if(point_diff == true){
			is_change = true;
		}
	#endif

	/**
	 * 2、是否开启instruction trace
	 */
	#ifdef CONFIG_ITRACE
		if(if_valid == 1){
			char log_buf[LOG_BUF_SIZE] = {0};
			
			// TAG:这里是为了找bug加入的,后面可以删除
			// printf("if_valid is %d\n",if_valid);
			// uint8_t *ptr = (uint8_t*)&inst; // 将指针转为uint8_t类型
			// for(int i=0; i<4; i++) {
			// 	printf("%02x", ptr[i]); // 通过索引访问连续字节
			// }
			// printf("\n");


			instruction_disassemble(log_buf, (uint8_t *)&inst);
			// 输出到屏幕
			if (g_print_step) { puts(log_buf); }
			// Write the log buffer to the log file
			log_write("%s\n", log_buf);
		}
	#endif

	/**
	 * 3、是否开启function trace
	 */
	#ifdef CONFIG_FTRACE
		opcode = BITS(inst, 6, 0);	
		if(opcode == 0b1101111){
			ftrace_function_call(pc, dnpc, false);
		}
		else if(opcode == 0b1100111){
  			int rd = BITS(inst, 11, 7);
			uint32_t imm = SEXT(BITS(inst, 31, 20), 12);
			if(inst == 0x00008067){
				ftrace_function_ret(pc);	// ret -> jalr x0, 0(x1)
			}else if(rd == 0 && imm == 0){
				ftrace_function_call(pc,dnpc,true);	// jr rs1 -> jalr x0, 0(rs1)
			}else {
				ftrace_function_call(pc,dnpc,false);
			}
		}
	#endif

	/**
	 * 4、是否开启diff test测试
	 */
	#ifdef CONFIG_DIFFTEST
		// 	更改进行diff test的时机，之前在if_valid==1的时候diff，现在在wb_ready==1的时候进行diff test，表示NPC这边已经执行完了
		if(wb_ready == 1){
			// printf("NPC: %x: %08x\n",pc,inst);
			difftest_step();
		}
	#endif

	/**
	 * 5、是否开启performance trace
	 */
	#ifdef CONFIG_CSV
		record_performance_trace(cycle, g_nr_guest_inst);
	#endif
}


/* cpu single cycle in exec */
static void exec_once(){
#ifdef CONFIG_SOC
	nvboard_update();
#endif
	single_cycle();
}
extern bool is_skip_diff;
// TAG：这里如果执行的程序很大，需要改为uint64或者uint128，因为uint32可能不够
void cpu_exec(uint64_t n){
	//max inst to print to stdout
	g_print_step = (n < MAX_INST_TO_PRINT);
	
	// TAG: 判断一条指令是否卡死使用
	prev_inst	 = -1;
	ins_counter  = 0;

	while(n > 0){
		
		exec_once();
		g_timer		+= timer_end - timer_start;
		
		snpc = pc + 4;
		get_reg();
		
		// 多周期CPU运行的指令的数量应该是if_valid有效一次记录一次
		cycle++;		// 记录运行的周期数

		// 记录每种指令的运行时间
		// (可以使用verilator的contextp->time()获取当前的仿真时间减去开始指令时的仿真时间然后除2，这是因为在我的代码中时2ps一个周期)
		// 上面的方式需要和波形强相关，所以我直接使用当前周期数来当作时间，加2是因为在使用DPI-C的时候，没有计数

		#ifdef CONFIG_TRACE
			trace_and_difftest();
			if(is_change){
				is_change = false;
				break;
			}
		#endif
		IFDEF(CONFIG_DEVICE, device_update());
		n--;

	}
}


static void statistic() {
	uint64_t instruction_idu = idu_cal_type + idu_mem_type + idu_jump_type + idu_csr_type;
	// 下面两个加法是因为最后一个ebreak语句没有被统计进来，所以需要单独的统计
	avg_cycle[4] += 10;
	instruction_idu++;
	
	uint64_t total_time = avg_cycle[0] + avg_cycle[1] + avg_cycle[2] + avg_cycle[3] + avg_cycle[4] + avg_cycle[5];
	double jump_pro 	= (double)avg_cycle[0] * 100 / (double)total_time; 	// 跳转操作
	double store_pro	= (double)avg_cycle[1] * 100 / (double)total_time;	// 读操作
	double load_pro		= (double)avg_cycle[2] * 100 / (double)total_time; 	// 写操作
	double cal_pro		= (double)avg_cycle[3] * 100 / (double)total_time; 	// 计算操作
	double csr_pro		= (double)avg_cycle[4] * 100 / (double)total_time;	// csr操作
	// 访问cache命中的次数
	double cache_hit_ratio 		= (double)cache_hit_cnt / (double)ifu_r_counter;
	// 单次的cache访问时间
	double cache_access_time	= (double)cache_access_time_all / (double)cache_hit_cnt;
	// 单次的sdram访问时间
	double mem_access_time		= (double)read_time / (double)lsu_r_counter;
	// 单次cache miss的总时间
	double cache_miss_time		= (double)cache_miss_time_all / (double)cache_miss_cnt;
	// AMAT
	double AMAT					= cache_access_time + (1-cache_hit_ratio) * mem_access_time;
	
	Log("total guest instructions = %lu", g_nr_guest_inst);
	Log("CPU IPC is = %lf",(double)g_nr_guest_inst / (double)cycle);
	Log("CPU CPI is = %lf",(double)cycle / (double)g_nr_guest_inst);
	Log("IFU Read : %lu", ifu_r_counter);
	Log("IDU translate instruction is : %ld",instruction_idu);
	Log("EXU Finish : %lu", exeu_counter);
	Log("LSU Write : %lu", lsu_w_counter);
	Log("LSU Read : %lu", lsu_r_counter);
	Log("IDU Cal : %lu, the ratio : %.4lf%%, total time : %.0f, average execution cycle : %.4f", idu_cal_type, (double)idu_cal_type  * 100.0 / (double)g_nr_guest_inst, avg_cycle[0], avg_cycle[0] / idu_cal_type);
	Log("IDU Mem : %lu, the ratio : %.4lf%%, total time : %.0f, average execution cycle : %.4f", idu_mem_type, (double)idu_mem_type  * 100.0 / (double)g_nr_guest_inst, (avg_cycle[1] + avg_cycle[2]), (avg_cycle[1] + avg_cycle[2]) / idu_mem_type);
	Log("IDU Jump : %lu, the ratio : %.4lf%%, total time : %.0f, average execution cycle : %.4f", idu_jump_type, (double)idu_jump_type  * 100.0 / (double)g_nr_guest_inst, avg_cycle[3], avg_cycle[3] / idu_jump_type);
	Log("IDU Csr : %lu, the ratio : %.4lf%%, total time : %.0f, average execution cycle : %.4f", idu_csr_type, (double)idu_csr_type  * 100.0 / (double)g_nr_guest_inst, avg_cycle[4], avg_cycle[4] / idu_csr_type);
	Log("LSU Read access latency : %lu",read_time);
	Log("LSU Write access latency : %lu",write_time);
	Log("LSU average memory access latency : %lf",(double)(read_time + write_time) / (double)(lsu_w_counter + lsu_r_counter));
	Log("iCache hit ratio is %2.4lf",cache_hit_ratio);
	Log("iCache access time all is %lu, iCache hit cnt is %lu",cache_access_time_all,cache_hit_cnt);
	Log("single cache access time is %lf, single sdram access time is %lf",cache_access_time,mem_access_time);
	Log("iCache miss time all is %lu, iCache miss cnt is %lu",cache_miss_time_all,cache_miss_cnt);
	Log("single cache miss time is %lf", cache_miss_time);
	Log("AMAT is %lf",AMAT);
	Log("proportion Jump | Store | Load | Cal | Csr");
	Log("   	 %2.4lf%% %2.4lf%% %2.4lf%% %2.4lf%% %2.4lf%%", jump_pro, store_pro, load_pro, cal_pro, csr_pro);
	Log("host time spent = %lu us",g_timer);
	Log("total cycle spent = %lu",cycle);
	#ifdef CONFIG_CSV
		fprintf(perf_time_fp, "%lu,%.4f,%.4f,%.4f,%.4f\n", cycle, avg_cycle[0], (avg_cycle[1] + avg_cycle[2]), avg_cycle[3], avg_cycle[4] );
		close_csv();	// 关闭文件流
	#endif
	if (g_timer > 0) Log("simulation frequency = %.f inst/s", (double)cycle * 1000000 / (double)g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

extern "C" void npc_trap(){
#ifdef CONFIG_SOC
	nvboard_quit();
#endif

	#ifdef CONFIG_DUMP_WAVE
		dump_wave_inc();
		close_wave();
	#endif
	bool success;
	word_t code = isa_reg_str2val("a0",&success);
	if(code == 0)
		printf("\033[1;32mHIT GOOD TRAP\033[0m\n");
	else
		printf("\033[1;31mHIT BAD TRAP\033[0m exit code = %x\n",code);
	printf("trap in %#x\n",pc);
	// statistic();
	exit(0);
}
