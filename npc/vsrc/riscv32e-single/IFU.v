`include "defines.v"
module IFU (
  input clk,
  input rst_n,
  output [`INST_ADDR_WIDTH-1:0] if_pc,
  input [`INST_ADDR_WIDTH-1:0] jump_addr,
  input jump_flag,
  input [`INST_ADDR_WIDTH-1:0] exc_jump_addr,
  input exc_jump_flag,
  output reg [`INST_DATA_WIDTH-1:0] inst
);
  reg [`INST_ADDR_WIDTH-1:0] pc = `INIT_PC;
  wire [`INST_ADDR_WIDTH-1:0] next_pc = exc_jump_flag ? exc_jump_addr : jump_flag ? jump_addr : (pc + 32'd4);
  always @(posedge clk) begin
    if(~rst_n) pc <= `INIT_PC;
    else pc <= next_pc;
  end
  always @(*) begin
    inst = pmem_read(pc, 1, 0);
  end
  assign if_pc = pc;
endmodule