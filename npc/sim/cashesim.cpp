#include <fstream>
#include <iostream>
#include <cstring>
#define PC_QUEUE "pc.txt"
#define LS_QUEUE "ls.txt"
#define CYCLE_BEAT 9.5
#define CYCLE_HANDSHAKE 12
#define LS_LOAD_COST 143
#define LS_HANDSHAKE 12
#define BLOCK_SIZE_DIG_WORD 2
#define BLOCK_NUM_DIG 1
#define BLOCK_SIZE_DIG (2 + BLOCK_SIZE_DIG_WORD) // 2^BLOCK_SIZE_DIG = 4, // block size = 4B //最多开到3
#define BLOCK_SIZE_WORD (1 << BLOCK_SIZE_DIG_WORD)
using namespace std;
#define BLOCK_SIZE (1 << BLOCK_SIZE_DIG)
#define BLOCK_NUM (1 << BLOCK_NUM_DIG)
uint64_t extra_cycle = 0;
uint64_t pc_hit = 0;
uint64_t pc_miss = 0;
uint64_t load_hit = 0;
uint64_t load_miss = 0;
uint64_t inst_count = 0;
long long ls_cycle_decline = 0;
uint32_t icache_tag[BLOCK_NUM] = {0};
bool icache_valid[BLOCK_NUM] = {false};
void check_icache(uint32_t pc)
{
	uint32_t tag = pc >> (BLOCK_SIZE_DIG + BLOCK_NUM_DIG);
	uint32_t index = (pc >> BLOCK_SIZE_DIG) & ((1 << BLOCK_NUM_DIG) - 1);
	if (icache_valid[index] && icache_tag[index] == tag)
	{
		pc_hit++;
	}
	else
	{
		pc_miss++;
		icache_valid[index] = true;
		icache_tag[index] = tag;
		extra_cycle += CYCLE_BEAT * BLOCK_SIZE_WORD + CYCLE_HANDSHAKE;
	}
}
void check_dcache(uint32_t addr, bool is_load)
{
	// 目前，认为dcache的写入是写直达
	if (is_load)
	{
		uint32_t tag = addr >> (BLOCK_SIZE_DIG + BLOCK_NUM_DIG);
		uint32_t index = (addr >> BLOCK_SIZE_DIG) & ((1 << BLOCK_NUM_DIG) - 1);
		if (icache_valid[index] && icache_tag[index] == tag)
		{
			load_hit++;
			ls_cycle_decline += LS_LOAD_COST;
		}
		else
		{
			load_miss++;
			icache_valid[index] = true;
			icache_tag[index] = tag;
			ls_cycle_decline -= ((LS_LOAD_COST - LS_HANDSHAKE) * (BLOCK_SIZE_WORD) + LS_HANDSHAKE - LS_LOAD_COST);
		}
	}
}
void icache_sim()
{
	ifstream pcfile(PC_QUEUE);
	if (!pcfile.is_open())
	{
		cerr << "Failed to open PC queue file: " << PC_QUEUE << endl;
		exit(1);
	}

	uint32_t pc = 0;
	while (pcfile)
	{
		pcfile >> hex >> pc;
		check_icache(pc);
	}
	pcfile.close();
	cout << "miss count: " << pc_miss << endl;
	cout << "hit count: " << pc_hit << endl;
	cout << "total count: " << (pc_hit + pc_miss) << endl;
	cout << "miss rate: " << (double)pc_miss / (pc_hit + pc_miss) << endl;
	cout << "extra cycle per pc: " << (double)extra_cycle / (pc_hit + pc_miss) << endl;
}

void dcache_sim()
{
	ifstream lsfile(LS_QUEUE);
	if (!lsfile.is_open())
	{
		cerr << "Failed to open LS queue file: " << LS_QUEUE << endl;
		exit(1);
	}

	uint32_t addr = 0;
	uint32_t addr_pre = -1;
	char type = 0;
	while (lsfile)
	{
		lsfile >> type >> hex >> addr;
		if (addr == addr_pre)
		{
			continue; // 跳过重复的地址
		}
		addr_pre = addr;
		if (type == 'L')
			check_dcache(addr, true);
		else if (type == 'S')
			check_dcache(addr, false);
		else
		{
			cerr << "Invalid type in LS queue: " << type << endl;
			exit(1);
		}
	}
	ifstream pcfile(PC_QUEUE);
	if (!pcfile.is_open())
	{
		cerr << "Failed to open PC queue file: " << PC_QUEUE << endl;
		exit(1);
	}

	uint32_t pc = 0;
	while (pcfile)
	{
		pcfile >> hex >> pc;
		inst_count++;
	}
	lsfile.close();
	cout << "load hit count: " << load_hit << endl;
	cout << "load miss count: " << load_miss << endl;
	cout << "total load count: " << (load_hit + load_miss) << endl;
	cout << "load miss rate: " << (double)load_miss / (load_hit + load_miss) << endl;
	cout << "inst count: " << inst_count << endl;
	cout << "cycle decline: " << ls_cycle_decline << endl;
	cout << "average cycle per inst: " << (double)ls_cycle_decline / inst_count << endl;
}
int main(int argc, char **argv)
{
	if (argc < 2)
	{
		cerr << "Usage: " << argv[0] << " <i\\d>" << endl;
		return 1;
	}
	if (argv[1][0] == 'i')
		icache_sim();
	else if (argv[1][0] == 'd')
		dcache_sim();
	else
	{
		cerr << "Invalid argument: " << argv[1] << ". Use 'i'(icache) or 'd'(dcache)." << endl;
		return 1;
	}
}