#include <stdint.h>
#include "Sdb.h"
extern Sdb *sdb;
enum INST_TYPE
{
	CALCULATE = 0,
	LOAD_STORE = 1,
	BRANCH = 2,
	CSR = 3,
	SYSTEM = 4,
	OTHER = 5
};
extern uint64_t cycle_count;
extern uint64_t pc_count;
uint64_t fetch_count = 0; // 前端指令
uint64_t fetch_cycle = 0; // 前端周期
uint64_t execute_count = 0;
uint64_t execute_cycle = 0;
uint64_t load_count = 0;
uint64_t load_cycle = 0;
uint64_t store_count = 0;
uint64_t store_cycle = 0;
uint64_t calculate_inst_count = 0; // 检测指令执行总周期中，采用在IDU中打入DPI-C函数的形式
uint64_t calculate_inst_cycle = 0;
uint64_t load_store_inst_count = 0;
uint64_t load_store_inst_cycle = 0;
uint64_t branch_inst_count = 0;
uint64_t branch_inst_cycle = 0;
uint64_t csr_inst_count = 0;
uint64_t csr_inst_cycle = 0;
uint64_t icache_miss_count = 0;
uint64_t icache_miss_cycle = 0;
uint64_t icache_hit_count = 0;
uint64_t icache_hit_cycle = 0;

void print_performance_counters()
{
	double fetch_cpi = fetch_cycle / (double)fetch_count;
	double execute_cpi = execute_cycle / (double)execute_count;
	double frontend_cpi = (double)fetch_cycle / fetch_count + (double)execute_cycle / execute_count;
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "total inst:", pc_count, "total cycles:", cycle_count, cycle_count / (double)pc_count);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "fetch act count:", fetch_count, "fetch cycle:", fetch_cycle, fetch_cpi);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "execute act count:", execute_count, "execute cycle:", execute_cycle, execute_cpi);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "load act count:", load_count, "load cycle:", load_cycle, (double)load_cycle / load_count);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "store act count:", store_count, "store cycle:", store_cycle, (double)store_cycle / store_count);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "calculate count:", calculate_inst_count, "calculate cycle:", calculate_inst_cycle,
		   (double)calculate_inst_cycle / calculate_inst_count);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "load/store inst count:", load_store_inst_count, "load/store cycle:", load_store_inst_cycle,
		   (double)load_store_inst_cycle / load_store_inst_count);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "branch inst count:", branch_inst_count, "branch cycle:", branch_inst_cycle,
		   (double)branch_inst_cycle / branch_inst_count);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "csr inst count:", csr_inst_count, "csr cycle:", csr_inst_cycle,
		   (double)csr_inst_cycle / csr_inst_count);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "icache hit count:", icache_hit_count, "icache hit cycle:", icache_hit_cycle,
		   (double)icache_hit_cycle / icache_hit_count);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "icache miss count:", icache_miss_count, "icache miss cycle:", icache_miss_cycle,
		   (double)icache_miss_cycle / icache_miss_count);
	printf("%-22s %10lu, %-20s %10lu, per %10.6lf cycles\n",
		   "icache aver count:", (icache_hit_count + icache_miss_count),
		   "icache aver cycle:", (icache_hit_cycle + icache_miss_cycle),
		   (double)(icache_hit_cycle + icache_miss_cycle) / (icache_hit_count + icache_miss_count));
	printf("%-22s %%%10.2lf\n",
		   "icache miss rate:",
		   (double)icache_miss_count * 100 / (icache_hit_count + icache_miss_count));
	// printf("calculate inst count: %10lu, calculate inst cycle: %10lu, per %10lf cycles\n", calculate_inst_count, calculate_inst_cycle, (double)calculate_inst_cycle / calculate_inst_count);
	// printf("load/store inst count: %10lu, load/store inst cycle: %10lu, per %10lf cycles\n", load_store_inst_count, load_store_inst_cycle, (double)load_store_inst_cycle / load_store_inst_count);
	// printf("branch inst count: %10lu, branch inst cycle: %10lu, per %10lf cycles\n", branch_inst_count, branch_inst_cycle, (double)branch_inst_cycle / branch_inst_count);
	// printf("csr inst count: %10lu, csr inst cycle: %10lu, per %10lf cycles\n", csr_inst_count, csr_inst_cycle, (double)csr_inst_cycle / csr_inst_count);
}
#define IFU_IDLE 0
#define IFU_WAIT_MMEM_READY 1
#define IFU_WAIT_MMEM_REQ 2
#define IFU_WAIT_IDU_READY 3
#define ICACHE_IDLE 0
extern "C" void record_pc(uint32_t pc)
{
	fprintf(stderr, "%x\n", pc);
}
extern "C" void record_load_store(uint32_t addr, int is_load)
{
	fprintf(stderr, "%c %x\n", is_load ? 'L' : 'S', addr);
}
extern "C" void icache_count_inc(char icache_state, bool ifu_arvalid, bool is_hit)
{
	static int is_icache_working = 0;
	static int is_icache_hit = 0;
	if (is_icache_working)
	{
		if (is_icache_hit)
			icache_hit_cycle++;
		else
			icache_miss_cycle++;
		if (icache_state == ICACHE_IDLE)
		{
			is_icache_working = 0;
			if (is_icache_hit)
				icache_hit_count++;
			else
				icache_miss_count++;
		}
	}
	else
	{
		if (icache_state == ICACHE_IDLE & ifu_arvalid)
		{
			is_icache_working = 1;
			is_icache_hit = is_hit;
		}
	}
}
extern "C" void fetch_count_inc(char ifu_state)
{
	static int is_ifu_working = 0;
	if (is_ifu_working)
	{
		fetch_cycle++;
		if (ifu_state == IFU_IDLE)
		{
			is_ifu_working = 0;
			fetch_count++;
		}
	}
	else if (ifu_state != IFU_IDLE)
	{
		is_ifu_working = 1;
	}
}
#define EXU_IDLE 0
#define EXU_EXECUTE 1
extern "C" void execute_count_inc(char exu_state)
{
	static int is_exu_working = 0;
	if (is_exu_working)
	{
		execute_cycle++;
		if (exu_state == EXU_IDLE)
		{
			is_exu_working = 0;
			execute_count++;
		}
	}
	else if (exu_state != EXU_IDLE)
	{
		is_exu_working = 1;
	}
}
#define LSU_IDLE 0
#define LSU_WAIT_REQ_READ 1
#define LSU_WAIT_REQ_AW_WRITE 2
#define LSU_WAIT_RSP_READ 3
#define LSU_WAIT_RSP_WRITE 4
#define LSU_WAIT_WBU_READY 5
#define LSU_WAIT_REQ_W_WRITE 6
#define LSU_WAIT_REQ_WRITE 7
extern "C" void load_store_count_inc(char lsu_state)
{
	static int is_lsu_reading = 0;
	static int is_lsu_writing = 0;
	assert((!(is_lsu_reading && is_lsu_writing)) && "LSU can not read and write at the same time,damn it!");
	if (is_lsu_reading)
	{
		load_cycle++;
		if (lsu_state == LSU_IDLE)
		{
			is_lsu_reading = 0;
			load_count++;
		}
	}
	else if (lsu_state == LSU_WAIT_REQ_READ)
	{
		is_lsu_reading = 1;
	}
	if (is_lsu_writing)
	{
		store_cycle++;
		if (lsu_state == LSU_IDLE)
		{
			is_lsu_writing = 0;
			store_count++;
		}
	}
	else if (lsu_state == LSU_WAIT_REQ_WRITE)
	{
		is_lsu_writing = 1;
	}
}
#define IDU_IDLE 0
#define IDU_DECODE 1
#define I_TYPE_IMM 0b0010011
#define B_TYPE_IMM 0b1100011
#define I_TYPE_LOAD 0b0000011
#define S_TYPE 0b0100011
#define J_TYPE 0b1101111
#define I_TYPE_JALR 0b1100111
#define I_TYPE_SYSTEM 0b1110011
#define R_TYPE 0b0110011
#define U_TYPE_LUI 0b0110111
#define U_TYPE_AUIPC 0b0010111
#define I_TYPE_FENCE 0b0001111
extern "C" void track_inst_in_idu(char idu_state, char inst_type)
{
	static int inst = OTHER;
	if (idu_state == IDU_DECODE)
	{
		switch (inst_type)
		{
		case I_TYPE_IMM:
		case R_TYPE:
		case U_TYPE_AUIPC:
		case U_TYPE_LUI:
			calculate_inst_count++;
			inst = CALCULATE;
			break;
		case B_TYPE_IMM:
		case J_TYPE:
		case I_TYPE_JALR:
			branch_inst_count++;
			inst = BRANCH;
			break;
		case I_TYPE_LOAD:
		case S_TYPE:
			load_store_inst_count++;
			inst = LOAD_STORE;
			break;
		case I_TYPE_SYSTEM:
			csr_inst_count++;
			inst = CSR;
			break;
		case I_TYPE_FENCE:
			break;
		default:
			inst = OTHER;
			printf("Unknown instruction type in IDU: %d\n", inst_type);
#ifdef WAVE
			sdb->npc.tfp->flush();
#endif
			assert(0 && "Unknown instruction type in IDU");
			break;
		}
	}
	switch (inst)
	{
	case CALCULATE:
		calculate_inst_cycle++;
		break;
	case LOAD_STORE:
		load_store_inst_cycle++;
		break;
	case BRANCH:
		branch_inst_cycle++;
		break;
	case CSR:
		csr_inst_cycle++;
		break;
	default:
		break;
	}
}