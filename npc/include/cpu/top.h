#ifndef __TOP__H
#define __TOP__H
#include "verilated_fst_c.h"
#include <generated/autoconf.h>

#ifdef CONFIG_NPC_VERILOG
#include "VysyxSoCFull_top.h"
#include "VysyxSoCFull_top___024root.h"

typedef VysyxSoCFull_top Top;
typedef VysyxSoCFull_top___024root Top_rootp;
#endif

#ifdef CONFIG_NPC_CHISEL
#ifdef CONFIG_SOC
#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
typedef VysyxSoCFull Top;
typedef VysyxSoCFull___024root Top_rootp;
#else 
#include "VTop.h"
#include "VTop___024root.h"
typedef VTop Top;
typedef VTop___024root Top_rootp;
#endif

uint32_t top_state();
#endif
#define NPCTRAP(thispc, code) set_npc_state(NPC_END, thispc, code)

typedef VerilatedFstC Tfp;
enum LSU_FCN {
    LSU_FCN_LOAD,
    LSU_FCN_STORE,
};

enum LSU_TYP {
   MT_X  ,
   MT_B  ,
   MT_H  ,
   MT_W  ,
   MT_D  ,
   MT_BU ,
   MT_HU ,
   MT_WU ,
};

typedef struct {
  uint32_t addr;
  uint32_t data;
  uint32_t enable;
  uint32_t fcn; 
  uint32_t typ;
} mem_access_t;

typedef struct {
  uint32_t csr_count  ; 
  uint32_t store_count; 
  uint32_t load_count ; 
  uint32_t itype_count; 
  uint32_t rtype_count; 
  uint32_t jtype_count; 
  uint32_t utype_count; 
  uint32_t other_count; 
} ctrl_perf_event_t;

// extern uint32_t lsu_store_count;
// extern uint32_t lsu_load_count ;
// extern uint32_t ifu_fetch_count;
// extern uint32_t wbu_wb_count   ;
// extern ctrl_perf_event_t ctrl_perf_event;


Top* top();
Tfp* tfp();


uint32_t top_gpr(int i);

uint32_t top_csr(int i);

uint32_t top_pc();

uint32_t top_wb_pc();

uint32_t top_mem_pc();

uint32_t top_halt();

uint32_t top_inst();

uint32_t top_dnpc();

uint32_t top_wb_inst();

mem_access_t top_lsu_state();

void clear_top_lsu_state();

void delete_top();

void watch_top();

void top_perf_event_display(FILE *fp);

#endif
