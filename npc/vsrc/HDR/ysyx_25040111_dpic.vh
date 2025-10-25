`ifndef __ICARUS__ 

`ifndef NPC_DPIC
`define NPC_DPIC

`ifndef YOSYS_STA
import "DPI-C" function void ebreak(input int code);
import "DPI-C" function int pmem_read(input int raddr);
import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
import "DPI-C" function void cache_hit();
`define PMC_EN
`endif // YOSYS_STA

`define IOPT    0
`define IJUMP   1
`define IMEM    2
`define ICSR    3

`endif // NPC_DPIC

`endif // __ICARUS__
