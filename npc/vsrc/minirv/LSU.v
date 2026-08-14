`include "defines.v"
module LSU (
  input clk,
  input [`DATA_ADDR_WIDTH-1:0] alu_res,
  input [`DATA_DATA_WIDTH-1:0] rd2,
  output [`WORD_WIDTH-1:0] mwd,
  output mwreg,
  input [3:0] ls_inst
);
wire lw_inst = ls_inst[3];
wire lbu_inst = ls_inst[2];
wire sb_inst = ls_inst[1];
wire sw_inst = ls_inst[0];

wire [`DATA_ADDR_WIDTH-1:0] daddr = alu_res;
wire [`DATA_DATA_WIDTH-1:0] wdata = sw_inst ? rd2 : 
                                    sb_inst ? {4{rd2[7:0]}} : 0;
wire valid = lw_inst | lbu_inst | sb_inst | sw_inst;
wire wen = sw_inst | sb_inst;
wire [7:0] wmask;
assign wmask[7] = 0;
assign wmask[6] = 0;
assign wmask[5] = 0;
assign wmask[4] = 0;
assign wmask[3] = sw_inst | (sb_inst && daddr[1:0] == 2'b11);
assign wmask[2] = sw_inst | (sb_inst && daddr[1:0] == 2'b10);
assign wmask[1] = sw_inst | (sb_inst && daddr[1:0] == 2'b01);
assign wmask[0] = sw_inst | (sb_inst && daddr[1:0] == 2'b00);
reg [31:0] rdata;
always @(*) begin
  if (valid) begin // 有读写请求时
    rdata = pmem_read(daddr, {32{valid}});
    if (wen) begin // 有写请求时
      pmem_write(daddr, wdata, wmask);
    end
  end
  else begin
    rdata = 0;
  end
end

assign mwreg = lw_inst | lbu_inst;
assign mwd =  lw_inst ? rdata :
              (lbu_inst && daddr[1:0] == 2'b11) ? {24'd0, rdata[31:24]} :
              (lbu_inst && daddr[1:0] == 2'b10) ? {24'd0, rdata[23:16]} :
              (lbu_inst && daddr[1:0] == 2'b01) ? {24'd0, rdata[15: 8]} :
              (lbu_inst && daddr[1:0] == 2'b00) ? {24'd0, rdata[ 7: 0]} : 0;

endmodule