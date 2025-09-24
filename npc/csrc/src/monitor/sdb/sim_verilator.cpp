#include <common.h>
#include <sim_verilator.h>
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull__Syms.h"

extern VysyxSoCFull *ysyxSoCFull;

#ifdef CONFIG_FAST_SIM

uint32_t reg_value(int idx) {return ysyxSoCFull->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__gpr__DOT__rf[idx-1];} // 减1的原因是寄存器堆去掉了0号寄存器
uint32_t can_flush() {return ysyxSoCFull->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__can_flush;}
uint32_t r_mem_ren() {return ysyxSoCFull->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__r_mem_ren;}
uint32_t r_mem_wen() {return ysyxSoCFull->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__r_mem_wen;}
uint32_t Xbar_lsu_b_handshake() {return ysyxSoCFull->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__Xbar_lsu_b_handshake;}
uint32_t Xbar_lsu_r_handshake() {return ysyxSoCFull->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__Xbar_lsu_r_handshake;}
uint32_t lsu_valid() {return can_flush() && !(r_mem_ren() || r_mem_wen()) || Xbar_lsu_b_handshake() || Xbar_lsu_r_handshake();}
uint32_t lsu_wbu_pc() {return 0;}
uint32_t lsu_Xbar_aw_handshake() {return ysyxSoCFull->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__lsu_Xbar_aw_handshake;}
uint32_t lsu_Xbar_w_handshake()  {return ysyxSoCFull->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu__DOT__lsu_Xbar_w_handshake;}

#else

/** common signal value */
uint32_t reg_value(int idx) {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__gpr.rf[idx-1];} // 减1的原因是寄存器堆去掉了0号寄存器

/** IFU signal value */
uint32_t ifu_icache_pc()            {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__ifu.ifu_icache_pc;}
uint32_t ifu_icache_valid()         {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__ifu.ifu_icache_valid;}
uint32_t ifu_icache_handshake()     {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__ifu.ifu_icache_handshake;}
uint32_t xbar_icache_r_handshake()  {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__icache.Xbar_icache_r_handshake;}
uint32_t ifu_idu_pc()               {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__ifu.ifu_idu_pc;}
uint32_t xbar_icache_r_resp()       {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__icache.Xbar_icache_r_resp;}
uint32_t icache_hit()               {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__icache.icache_hit;}

/** IDU signal value */
uint32_t idu_exu_handshake() {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.idu_exu_handshake;}
uint32_t reg_ifu_idu_inst()  {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.reg_ifu_idu_inst;}
uint32_t idu_is_jump()       {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.is_jump;}
uint32_t idu_is_branch()     {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.is_B;}
uint32_t idu_is_load()       {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.is_load;}
uint32_t idu_is_store()      {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.is_S;}
uint32_t idu_is_alu()        {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.is_alu;}
uint32_t idu_is_csr()        {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.is_csr;}
uint32_t idu_is_trap()       {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.is_trap;}
uint32_t raw_stall()         {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__idu.raw_stall;}

/** EXU signal value */
uint32_t idu_valid()         {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__exu.idu_valid;}
uint32_t exu_lsu_handshake() {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__exu.exu_lsu_handshake;}
uint32_t is_control()        {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__exu.is_control;}

/** LSU signal value */
uint32_t r_exu_out()             {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.r_exu_out;}
uint32_t r_mem_ren()             {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.r_mem_ren;}
uint32_t r_mem_wen()             {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.r_mem_wen;}
uint32_t lsu_valid()             {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_valid;}
uint32_t lsu_flush()             {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_flush;}
uint32_t lsu_r_is_fencei()       {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.r_is_fencei;}
uint32_t xbar_lsu_r_handshake()  {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.Xbar_lsu_r_handshake;}
uint32_t xbar_lsu_b_handshake()  {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.Xbar_lsu_b_handshake;}
uint32_t lsu_Xbar_ar_handshake() {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_Xbar_ar_handshake;}
uint32_t lsu_Xbar_aw_handshake() {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_Xbar_aw_handshake;}
uint32_t lsu_Xbar_w_handshake()  {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_Xbar_w_handshake;}
uint32_t lsu_resp_exp()          {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_resp_exp;}
uint32_t addr_in_uart()          {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.addr_in_uart;}
uint32_t addr_in_clint()         {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.addr_in_clint;}
uint32_t lsu_wbu_pc()            {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_wbu_pc;}
uint32_t lsu_wbu_npc()           {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_wbu_npc;}
uint32_t lsu_wbu_inst()          {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_wbu_inst;}
uint32_t lsu_gpr_wen()           {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_gpr_wen;}
uint32_t lsu_gpr_waddr()         {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_gpr_waddr;}
uint32_t lsu_wbu_gpr_wdata()     {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_out;}
uint32_t lsu_csr_wen()           {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_csr_wen;}
uint32_t lsu_csr_waddr()         {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_csr_waddr;}
uint32_t lsu_csr_wdata()         {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_csr_wdata;}
uint32_t lsu_csr_excp()          {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_csr_excp;}
uint32_t lsu_csr_mcause()        {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__lsu.lsu_csr_mcause;}

/** Xbar */
uint32_t icache_acc_sram_grant() {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__Xbar.icache_acc_sram_grant;}

/** WBU signal value */
// uint32_t wbu_ifu_handshake()      {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__wbu.wbu_ifu_handshake;}
// uint32_t reg_lsu_wbu_gpr_wen()    {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__wbu.reg_lsu_wbu_gpr_wen;}
// uint32_t reg_lsu_wbu_gpr_wdata () {return ysyxSoCFull->rootp->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__wbu.wbu_gpr_wdata;}

#endif