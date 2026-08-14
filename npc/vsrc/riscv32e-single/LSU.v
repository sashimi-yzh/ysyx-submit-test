`include "defines.v"
module LSU (
  input clk,
  input [`DATA_ADDR_WIDTH-1:0] alu_res,
  input [`DATA_DATA_WIDTH-1:0] rd2,
  output [`WORD_WIDTH-1:0] mwd,
  output mwreg,
  input [7:0] ls_inst
);
wire lw_inst = ls_inst[7];
wire lbu_inst = ls_inst[6];
wire lb_inst = ls_inst[5];
wire lhu_inst = ls_inst[4];
wire lh_inst = ls_inst[3];
wire sw_inst = ls_inst[2];
wire sb_inst = ls_inst[1];
wire sh_inst = ls_inst[0];

wire [`DATA_ADDR_WIDTH-1:0] daddr = alu_res;
wire [`DATA_DATA_WIDTH-1:0] wdata = sw_inst ? rd2 : sb_inst ? {4{rd2[7:0]}} : sh_inst ? {2{rd2[15:0]}} : 0;
wire valid = lw_inst | lbu_inst | sb_inst | sw_inst | sh_inst | lb_inst | lhu_inst | lh_inst;
wire wen = sw_inst | sb_inst | sh_inst;
wire [7:0] wmask;
assign wmask[7:4] = 4'b0;
assign wmask[3] = sw_inst | (sb_inst && daddr[1:0] == 2'b11) | (sh_inst && daddr[1:0] == 2'b10);
assign wmask[2] = sw_inst | (sb_inst && daddr[1:0] == 2'b10) | (sh_inst && daddr[1:0] == 2'b10);
assign wmask[1] = sw_inst | (sb_inst && daddr[1:0] == 2'b01) | (sh_inst && daddr[1:0] == 2'b00);
assign wmask[0] = sw_inst | (sb_inst && daddr[1:0] == 2'b00) | (sh_inst && daddr[1:0] == 2'b00);
reg [31:0] rdata;

always @(*) begin
  rdata = pmem_read(daddr, {31'd0, valid}, 1);
end

always @(posedge clk) begin
  if(valid && wen) begin
    pmem_write(daddr, wdata, wmask);
  end
end

assign mwreg = lw_inst | lbu_inst | lh_inst | lhu_inst | lb_inst;
assign mwd =  lw_inst ? rdata :
              (lbu_inst && daddr[1:0] == 2'b11) ? {24'd0, rdata[31:24]} :
              (lbu_inst && daddr[1:0] == 2'b10) ? {24'd0, rdata[23:16]} :
              (lbu_inst && daddr[1:0] == 2'b01) ? {24'd0, rdata[15: 8]} :
              (lbu_inst && daddr[1:0] == 2'b00) ? {24'd0, rdata[ 7: 0]} :
              (lb_inst  && daddr[1:0] == 2'b11) ? {{24{rdata[31]}}, rdata[31:24]} :
              (lb_inst  && daddr[1:0] == 2'b10) ? {{24{rdata[23]}}, rdata[23:16]} :
              (lb_inst  && daddr[1:0] == 2'b01) ? {{24{rdata[15]}}, rdata[15: 8]} :
              (lb_inst  && daddr[1:0] == 2'b00) ? {{24{rdata[ 7]}}, rdata[ 7: 0]} :
              (lhu_inst && daddr[1:0] == 2'b10) ? {16'd0, rdata[31:16]} :
              (lhu_inst && daddr[1:0] == 2'b00) ? {16'd0, rdata[15: 0]} :
              (lh_inst  && daddr[1:0] == 2'b10) ? {{16{rdata[31]}}, rdata[31:16]} :
              (lh_inst  && daddr[1:0] == 2'b00) ? {{16{rdata[15]}}, rdata[15: 0]} : 0;

endmodule