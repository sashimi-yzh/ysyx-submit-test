`include "defines.v"
module IFU (
  input clk,
  input rst_n,
  output [`INST_ADDR_WIDTH-1:0] if_pc,
  input [`INST_ADDR_WIDTH-1:0] jump_addr,
  input jump_flag,
  output [`INST_DATA_WIDTH-1:0] inst
);
  reg [`INST_ADDR_WIDTH-1:0] pc = `INIT_PC;
  wire [`INST_ADDR_WIDTH-1:0] next_pc = jump_flag ? jump_addr : (pc + 32'd4);
  always @(posedge clk) begin
    if(~rst_n) pc <= `INIT_PC;
    else pc <= next_pc;
  end
  assign inst = pmem_read(pc, 0);
  assign if_pc = pc;
endmodule