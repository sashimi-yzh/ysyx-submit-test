#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#include <verilated.h>
#include <verilated_fst_c.h>

#include "config.h"

extern  VysyxSoCFull *top 	  ;
extern  VerilatedFstC *m_trace  ;

#ifdef ysyx_23060299_PO

uint32_t idu_cal_cnt        =   0;
uint32_t idu_sw_cnt         =   0;
uint32_t idu_csr_cnt        =   0;
uint32_t idu_jump_cnt       =   0;
uint64_t ifu_sumCyc         =   0;
uint64_t lsu_sumCyc         =   0;
uint32_t lsu_times          =   0;
uint32_t icache_hit_cnt     =   0;
uint32_t icache_all_cnt     =   0;

extern "C" void idu_cal(void) {
    idu_cal_cnt++;
}

extern "C" void idu_sw(void) {
    idu_sw_cnt++;
}

extern "C" void idu_csr(void) {
    idu_csr_cnt++;
}

extern "C" void idu_jump(void) {
    idu_jump_cnt++;
}

extern "C" void ifu_addCyc(int Cyc) {
    ifu_sumCyc = Cyc    +   ifu_sumCyc;
}

extern "C" void lsu_addCyc(int Cyc) {
    lsu_sumCyc = Cyc    +   lsu_sumCyc;
}

extern "C" void lsu_addTimes(int Cyc) {
    lsu_times++;
}

extern "C" void icache_hit(void) {
    icache_hit_cnt++;
}

extern "C" void icache_cnt(void) {
    icache_all_cnt++;
}

#endif
