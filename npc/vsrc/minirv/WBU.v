`include "defines.v"
module WBU (
  input [`WORD_WIDTH-1:0] alu_res,
  input [`WORD_WIDTH-1:0] mwd,
  input mwreg,
  output [`WORD_WIDTH-1:0] wd
);
  assign wd = mwreg ? mwd : alu_res;
endmodule