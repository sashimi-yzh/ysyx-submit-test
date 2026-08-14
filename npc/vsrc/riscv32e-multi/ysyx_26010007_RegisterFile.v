`include "ysyx_26010007_defines.v"
module ysyx_26010007_RegisterFile (
  input clock,
  input [`WORD_WIDTH-1:0] wdata,
  input [`REG_ADDR_WIDTH-1:0] waddr,
  input wen,
  input [`REG_ADDR_WIDTH-1:0] r1addr,
  output[`WORD_WIDTH-1:0] r1data,
  input [`REG_ADDR_WIDTH-1:0] r2addr,
  output[`WORD_WIDTH-1:0] r2data
);
  reg [`WORD_WIDTH-1:0] rf [2**`REG_ADDR_WIDTH-1:0];
  always @(posedge clock) begin
    if (wen && waddr != 0) rf[waddr] <= wdata;
  end
  assign r1data = rf[r1addr];
  assign r2data = rf[r2addr];
`ifdef debug
  export "DPI-C" function npc_regs;
  function int npc_regs(input int addr);
    if (addr >= 0 && addr < 16)
        npc_regs = rf[addr]; // 自动将 reg 转换为 int
    else
        npc_regs = 0;
  endfunction
`endif
endmodule