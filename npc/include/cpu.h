#ifndef __CPU_H__
#define __CPU_H__

extern uint32_t pc__;         // 执行完指令后的PC值
extern vluint64_t sim_time;   // 记录仿真时间
extern vluint64_t stop_time;  // 暂停时间点
extern uint64_t g_timer;      // 程序运行时间
extern vluint64_t inst_count; //指令数量
void reset();
void cpu_exec(uint32_t inst_num);
int batch_mainloop();

#endif