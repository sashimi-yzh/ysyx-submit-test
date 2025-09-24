#ifndef __DPI_C_H__
#define __DPI_C_H__

#include <stdint.h>

/** common signal value */
uint32_t reg_value(int idx);

/** IFU signal value */
uint32_t ifu_icache_pc();
uint32_t ifu_icache_valid();
uint32_t ifu_icache_handshake();
uint32_t xbar_icache_r_handshake();
uint32_t ifu_idu_pc();
uint32_t xbar_icache_r_resp();
uint32_t icache_hit();

/** IDU signal value */
uint32_t idu_exu_handshake();
uint32_t reg_ifu_idu_inst();
uint32_t idu_is_jump();
uint32_t idu_is_branch();
uint32_t idu_is_load();
uint32_t idu_is_store();
uint32_t idu_is_alu();
uint32_t idu_is_csr();
uint32_t idu_is_trap();
uint32_t raw_stall();

/** EXU signal value */
uint32_t idu_valid();
uint32_t exu_lsu_handshake();
uint32_t is_control();

/** LSU signal value */
uint32_t r_exu_out();
uint32_t r_mem_ren();
uint32_t r_mem_wen();
uint32_t lsu_valid();
uint32_t lsu_flush();
uint32_t lsu_r_is_fencei();
uint32_t xbar_lsu_r_handshake();
uint32_t xbar_lsu_b_handshake();
uint32_t lsu_Xbar_ar_handshake();
uint32_t lsu_Xbar_aw_handshake();
uint32_t lsu_Xbar_w_handshake();
uint32_t lsu_resp_exp();
uint32_t addr_in_uart();
uint32_t addr_in_clint();
uint32_t lsu_wbu_pc();
uint32_t lsu_wbu_npc();
uint32_t lsu_wbu_inst();
uint32_t lsu_gpr_wen();
uint32_t lsu_gpr_waddr();
uint32_t lsu_wbu_gpr_wdata();
uint32_t lsu_csr_wen();
uint32_t lsu_csr_waddr();
uint32_t lsu_csr_wdata();
uint32_t lsu_csr_excp();
uint32_t lsu_csr_mcause();

/** Xbar */
uint32_t icache_acc_sram_grant();

#endif
