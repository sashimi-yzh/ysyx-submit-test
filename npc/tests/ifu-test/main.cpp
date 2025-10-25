#include <verilated.h>
#include "Vysyx_25040129_IFU.h"
#include <iostream>
#include <random>
#include <iomanip>

// 宏定义（需与RTL一致）
#define START_ADDR 0x80000000
#define WORD_T 4

vluint64_t main_time = 0; // 当前仿真时间
Vysyx_25040129_IFU *top;  // 顶层模块实例

// 生成随机32位数
uint32_t rand_uint32()
{
	return static_cast<uint32_t>(rand() % 0xFFFFFFFF);
}

// 时钟周期函数
void clock_cycle()
{
	top->clock = 0;
	top->eval();

	top->clock = 1;
	top->eval();
}

// 重置系统
void reset()
{
	top->reset = 1;
	top->clock = 0;
	top->eval();
	top->reset = 1;
	top->clock = 1;
	top->eval();
	top->reset = 0; // 释放复位
}

// 打印状态名
const char *state_name(uint8_t state)
{
	switch (state)
	{
	case 0:
		return "IDLE";
	case 1:
		return "WAIT_MMEM_READY";
	case 2:
		return "WAIT_MMEM_REQ";
	case 3:
		return "WAIT_IDU_READY";
	default:
		return "UNKNOWN";
	}
}

void print_state()
{
	std::cout << "--------------------- IFU State --------------------" << std::endl;
	std::cout << "State: " << state_name(top->state) << std::endl;
	std::cout << "PC: 0x" << std::hex << std::setw(8) << std::setfill('0') << top->pc << std::dec << std::endl;
	std::cout << "Instruction to IDU: 0x" << std::hex << std::setw(8) << std::setfill('0') << top->inst_to_idu << std::dec << std::endl;
	std::cout << "Jump Target: 0x" << std::hex << std::setw(8) << std::setfill('0') << top->jump_target << std::dec << std::endl;
	std::cout << "is_branch: " << static_cast<int>(top->is_branch) << std::endl;
}

void test_one_cycle()
{
	// 首先 模拟WBU,随机延迟一段时间后发送valid信号
	// 约定，在进入测试时，top处在IDLE状态
	print_state();			  // 打印初始状态
	assert(top->state == 0);  // 确保初始状态为IDLE
	int delay = rand() % 5;	  // 随机延迟0-4个周期
	uint32_t pc_in = top->pc; // 记录当前PC
	top->is_req_valid_from_wbu = 0;
	for (int i = 0; i < delay; ++i)
	{
		clock_cycle();			 // 检查状态，不应该发生更新
		assert(top->state == 0); // 确保仍在IDLE状态
	}
	top->is_req_valid_from_wbu = 1;		  // 模拟WBU发送请求
	uint32_t jump_target = rand_uint32(); // 随机跳转目标
	uint32_t is_branch = rand() % 2;	  // 随机是否为分支指令
	top->jump_target = jump_target;
	top->is_branch = is_branch;
	clock_cycle();
	top->is_req_valid_from_wbu = 0;								 // 清除WBU请求信号
	print_state();												 // 进入下一个周期,检查pc和状态
	assert(top->state == 1);									 // 应该进入WAIT_MMEM_READY状态
	assert(top->pc == is_branch ? jump_target : pc_in + WORD_T); // PC更新逻辑

	top->is_req_valid_from_wbu = 0; // 清除WBU请求信号
	delay = rand() % 5;				// 再次随机延迟0-4个周期
	for (int i = 0; i < delay; ++i)
	{
		clock_cycle();			 // 检查状态，不应该发生更新
		assert(top->state == 1); // 确保仍在WAIT_MMEM_READY状态
	}
	// 模拟MMEM响应
	top->is_req_ready_from_mmem = 1; // 模拟MMEM准备好
	clock_cycle();					 // 进入下一个周期
	top->is_req_ready_from_mmem = 0; // 清除MMEM准备信号
	print_state();					 // 检查状态
	assert(top->state == 2);		 // 应该进入WAIT_MMEM_REQ状态
	delay = rand() % 5;				 // 再次随机延迟0-4个周期
	for (int i = 0; i < delay; ++i)
	{
		clock_cycle();			 // 检查状态，不应该发生更新
		assert(top->state == 2); // 确保仍在WAIT_MMEM_REQ状态
	}
	// 模拟MMEM请求
	top->is_rsp_valid_from_mmem = 1; // 模拟MMEM发送指令
	uint32_t inst = rand_uint32();	 // 随机指令
	top->inst_from_mmem = inst;
	clock_cycle();					  // 进入下一个周期
	top->is_rsp_valid_from_mmem = 0;  // 清除MMEM响应信号
	print_state();					  // 检查状态
	assert(top->state == 3);		  // 应该进入WAIT_IDU_READY状态
	assert(top->inst_to_idu == inst); // 指令应该传递到IDU
	top->is_rsp_valid_from_mmem = 0;  // 清除MMEM响应信
	delay = rand() % 5;				  // 再次随机延迟0-4个周期
	for (int i = 0; i < delay; ++i)
	{
		clock_cycle();			 // 检查状态，不应该发生更新
		assert(top->state == 3); // 确保仍在WAIT_IDU_READY状态
	}
	// 模拟IDU响应
	top->is_req_ready_from_idu = 1; // 模拟IDU准备好
	clock_cycle();					// 进入下一个周期
	top->is_req_ready_from_idu = 0; // 清除IDU准备信号
	assert(top->state == 0);		// 应该回到IDLE状态
}

// 主测试函数
int main(int argc, char **argv)
{
	Verilated::commandArgs(argc, argv);
	top = new Vysyx_25040129_IFU;
	reset(); // 重置系统
	for (int i = 0; i < 1000; ++i)
	{
		test_one_cycle(); // 执行一个测试周期
	}
}