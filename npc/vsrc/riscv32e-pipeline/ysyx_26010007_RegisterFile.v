`include "ysyx_26010007_defines.v"
module ysyx_26010007_RegisterFile (
  input clock,
  input [`ysyx_26010007_WORD_WIDTH-1:0] wdata,
  input [`ysyx_26010007_REG_ADDR_WIDTH-1:0] waddr,
  input wen,
  input [`ysyx_26010007_REG_ADDR_WIDTH-1:0] r1addr,
  output[`ysyx_26010007_WORD_WIDTH-1:0] r1data,
  input [`ysyx_26010007_REG_ADDR_WIDTH-1:0] r2addr,
  output[`ysyx_26010007_WORD_WIDTH-1:0] r2data
);
  reg [`ysyx_26010007_WORD_WIDTH-1:0] rf [2**`ysyx_26010007_REG_ADDR_WIDTH-1:1];
  always @(posedge clock) begin
    if (wen && waddr != 0) rf[waddr] <= wdata;
  end
  assign r1data = r1addr == 0 ? 32'd0 : wen && waddr == r1addr ? wdata : rf[r1addr];
  assign r2data = r2addr == 0 ? 32'd0 : wen && waddr == r2addr ? wdata : rf[r2addr];
`ifdef ysyx_26010007_debug
  export "DPI-C" function npc_regs;
  function int npc_regs(input int addr);
    if (addr >= 0 && addr < 16)
        npc_regs = rf[addr]; // 自动将 reg 转换为 int
    else
        npc_regs = 0;
  endfunction
`endif
endmodule