#ifndef __PCOUNTER_H__
#define __PCOUNTER_H__

#include <common.h>
#include <circuit.h>
#include "verilated_dpi.h"

extern uint64_t ifu_r_counter;
extern uint64_t lsu_r_counter;
extern uint64_t lsu_w_counter;
extern uint64_t exeu_counter;
extern uint64_t idu_cal_type;
extern uint64_t idu_mem_type;
extern uint64_t idu_jump_type;
extern uint64_t idu_csr_type;

// 指令的类别
extern uint64_t ins_type;
// 指令开始的时间
extern uint64_t ins_start_time;

// 读开始的时间
extern uint64_t read_start;
// 读取用的总时间
extern uint64_t read_time;

// 写开始的时间
extern uint64_t write_start;
// 写用的总时间
extern uint64_t write_time;

// cache命中的总次数
extern uint64_t cache_hit_cnt;
// cache 开始访问的时间
extern uint64_t cache_access_start;
// cache 命中用的总时间，没有命中的使用读取所用的总时间就可以了
extern uint64_t cache_access_time_all;

// cache miss的总次数
extern uint64_t cache_miss_cnt;
// cache miss了之后访问sdram的开始时间
extern uint64_t cache_miss_start;
// cache miss后fill用的总时间
extern uint64_t cache_miss_time_all;

extern FILE *perf_time_fp;

void record_performance_trace(uint64_t cycle, uint64_t instCnt);
void close_csv();

#endif
