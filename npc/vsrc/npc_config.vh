`ifndef NPC_CONFIG_VH
`define NPC_CONFIG_VH

`ifndef ysyx_25040102_NPC
    `define ysyx_25040102_NPC 32'h30000000
`endif

`define ysyx_25040102_ICACHE_N 1
`define ysyx_25040102_ICACHE_M 2

`ifdef ysyx_25040102_SIM
import "DPI-C" function void time_add(input int no);
import "DPI-C" function void cycle_add(input int no);
import "DPI-C" function void icache_add(input int no);
`endif

`ifdef ysyx_25040102_SIM
import "DPI-C" function void call_ebreak();
`endif

`ifdef ysyx_25040102_DIFFTEST
import "DPI-C" function void difftest_skip_ref();
import "DPI-C" function bit in_mem(input int addr);
`endif

`endif 
