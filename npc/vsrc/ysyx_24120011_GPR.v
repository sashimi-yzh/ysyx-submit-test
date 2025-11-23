
import "DPI-C" function void reg_out(input int array[15:0]);
module ysyx_24120011_GPR(
    input clk,
    input rst,
    //读口
    input  [3:0]   i_rs1,
    input  [3:0]   i_rs2,
    output [31:0]  o_src1,
    output [31:0]  o_src2,
    //写口
    input  [3:0]   i_rd,
    input  [31:0]  i_rd_data,
    input          i_rd_en,
    output [31:0] a0
);

reg [31:0] GPRs [15:0];

assign o_src1 = GPRs[i_rs1];
assign o_src2 = GPRs[i_rs2];
assign a0     = GPRs[10];

//======================dpic========================//
int regout[15:0];

genvar i, j;
generate
  for (i = 0; i < 16; i = i + 1) begin : outer
      always @(*) begin
        regout[i] = GPRs[i];
      end
  end
endgenerate

always@(*)begin
    reg_out(regout);
end
//======================dpic========================//

always@(posedge clk)begin
    if(rst)begin
         GPRs[0]  <= 32'h0000_0000;
        GPRs[1]  <= 32'h0000_0000;
        GPRs[2]  <= 32'h0000_0000;
        GPRs[3]  <= 32'h0000_0000;
        GPRs[4]  <= 32'h0000_0000;
        GPRs[5]  <= 32'h0000_0000;
        GPRs[6]  <= 32'h0000_0000;
        GPRs[7]  <= 32'h0000_0000;
        GPRs[8]  <= 32'h0000_0000;
        GPRs[9]  <= 32'h0000_0000;
        GPRs[10] <= 32'h0000_0000;
        GPRs[11] <= 32'h0000_0000;
        GPRs[12] <= 32'h0000_0000;
        GPRs[13] <= 32'h0000_0000;
        GPRs[14] <= 32'h0000_0000;
        GPRs[15] <= 32'h0000_0000;
    end
    else begin
        if(i_rd_en)begin
            if (i_rd == 'd0) begin
                GPRs[0]  <= 32'h0000_0000;
            end else begin
                GPRs[i_rd] <= i_rd_data;
            end
        end
    end
end

endmodule
