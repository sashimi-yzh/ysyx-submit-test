`include "ysyx_26010007_defines.v"
module ysyx_26010007_WBU (
  // 握手信号
  input lsu_valid,
  output wbu_ready,
  
  input [`WORD_WIDTH-1:0]      lsu_mwd,
  input reg                    lsu_mwreg,
  input [`WORD_WIDTH-1:0]      lsu_alu_res,
  input                        lsu_wreg,
  input [`REG_ADDR_WIDTH-1:0]  lsu_wa,

  output [`WORD_WIDTH-1:0] wd,
  output                   wreg,
  output [`REG_ADDR_WIDTH-1:0] wa
);
  assign wd = lsu_mwreg ? lsu_mwd : lsu_alu_res;
  assign wa = lsu_wa;
  assign wreg = lsu_valid && lsu_wreg;
  assign wbu_ready = 1'b1;
endmodule