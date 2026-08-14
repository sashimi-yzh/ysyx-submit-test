#ifndef __CPU_H__
#define __CPU_H__

#include<common.h>

extern long long reset_cycles;
extern long long ifu_counter;
extern long long ifu_valid_inst;
extern long long flush_inst;
extern long long ifu_jump_wait;

extern long long load_counter;
extern long long store_counter;
extern long long exu_counter;
extern long long idu_load;
extern long long idu_store;
extern long long idu_jalr;
extern long long idu_jal;
extern long long idu_branch;
extern long long idu_csr;
extern long long idu_mret;
extern long long idu_ecall;
extern long long idu_alu;
extern long long lsu_load_delay;
extern long long lsu_store_delay;
extern long long ifu_fetch_delay;
extern long long ifu_wait_delay;
extern long long jump_re_wait;
extern long long jump_fail;
extern long long miss_penalty;
extern long long ifu_req;
extern long long icache_hit;
extern long long data_risk;
extern long long load_use;
extern long long struct_load_risk;
extern long long struct_store_risk;
extern long long struct_ifu_risk;

extern int invalid_inst;
#endif
