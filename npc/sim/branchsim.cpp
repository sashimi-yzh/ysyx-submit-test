// 这是一个分支预测算法的模拟器，用于评估静态预测算法的收益
// 暂时不考虑预测错误导致的缓存污染问题
// 具体的，每执行一条指令，我们需要根据设计的算法预测下一条的pc
// 如果pc序列中的实际pc与预测不同，则需要积累惩罚值(默认为1)
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#define BTB_SIZE_DIG 3
#define BTB_DIG (BTB_SIZE_DIG + 2)
#define BTB_SIZE (1 << BTB_SIZE_DIG)
bool btb_valid[BTB_SIZE] = {false};
uint32_t btb_tag[BTB_SIZE] = {0};
uint32_t btb_npc[BTB_SIZE] = {0};
const char *pc_inst_map_file = "microbench-riscv32e-ysyxsoc.txt";
const char *pc_queue_file = "pc.txt";
using namespace std;
unordered_map<uint32_t, uint32_t> pc_inst_map;
uint64_t mispredict_penalty = 0;
// 31-----------------------BTB_DIG+2----------
void load_pc_inst_map()
{
	ifstream file(pc_inst_map_file);
	if (!file.is_open())
	{
		cerr << "Failed to open file: " << pc_inst_map_file << endl;
		exit(1);
	}

	uint32_t pc, inst;
	string line;
	while (getline(file, line))
	{
		if (line[8] == ':' && line[9] == '\t')
		{
			sscanf(line.c_str(), "%x:\t%x", &pc, &inst);
			pc_inst_map[pc] = inst;
		}
	}
	file.close();
}
uint32_t always_step(uint32_t pc, uint32_t inst)
{
	return pc + 4;
}
uint32_t btb_predict(uint32_t pc, uint32_t inst)
{
	uint32_t index = (pc >> 2) & ((1 << BTB_SIZE_DIG) - 1);
	uint32_t tag = pc >> BTB_DIG;
	if (btb_valid[index] && btb_tag[index] == tag)
	{
		// printf("BTB hit: PC = %x, predicted NPC = %x\n", pc, btb_npc[index]);
		return btb_npc[index];
	}
	return pc + 4;
}
void sim_exec()
{
	ifstream pcfile(pc_queue_file);
	if (!pcfile.is_open())
	{
		cerr << "Failed to open file: " << pc_queue_file << endl;
		exit(1);
	}

	uint32_t pc = 0;
	uint32_t inst = 0;
	uint32_t pc_before = 0;
	uint32_t last_predict_pc = 0;
	uint64_t pc_count = 0;
	while (pcfile >> hex >> pc)
	{
		pc_count++;
		if (pc_inst_map.find(pc) != pc_inst_map.end())
		{
			inst = pc_inst_map[pc];
		}
		else
		{
			cerr << "PC not found in map: " << hex << pc << endl;
			continue;
		}

		if (last_predict_pc != 0 && last_predict_pc != pc)
		{
			mispredict_penalty++;
			uint32_t index = (pc_before >> 2) & ((1 << BTB_SIZE_DIG) - 1);
			uint32_t tag = pc_before >> BTB_DIG;
			btb_valid[index] = true;
			btb_tag[index] = tag;
			btb_npc[index] = pc; // 更新BTB
								 // printf("Mispredict at PC: %x, expected: %x, actual: %x\n", pc, last_predict_pc, pc);
		}
		pc_before = pc;
		last_predict_pc = btb_predict(pc, inst);
	}
	pcfile.close();
	cout << "Total mispredict penalty: " << mispredict_penalty << endl;
	cout << "Total PC count: " << pc_count << endl;
	cout << "Mispredict rate: " << (double)mispredict_penalty / pc_count << endl;
}
int main()
{
	load_pc_inst_map();
	sim_exec();
	return 0;
}