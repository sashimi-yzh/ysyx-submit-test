module ysyx_24100012_regfiles #(
    ADDR_WIDTH=32,
    DATA_WIDTH=32,
    N_REG=32,
    INPUT_INDEX_LEN=5,
    INDEX_LEN=5)(
    input clk,
    input rst,
    input [DATA_WIDTH-1:0] RegWriteData,
    input [INPUT_INDEX_LEN-1:0] RegWriteIndex,
    input [INPUT_INDEX_LEN-1:0] RegReadIndex1,
    input [INPUT_INDEX_LEN-1:0] RegReadIndex2,
    input RegWEn,
    output [DATA_WIDTH-1:0] RegReadData1,
    output [DATA_WIDTH-1:0] RegReadData2
);

wire [DATA_WIDTH-1:0] reg_input_list[N_REG-1:0];
wire [DATA_WIDTH-1:0] reg_output_list[N_REG-1:0];
wire  WEn_list[N_REG-1:0];
wire [INDEX_LEN-1:0] readIdx1,readIdx2,writeIdx;

assign readIdx1 = RegReadIndex1[INDEX_LEN-1:0];
assign readIdx2 = RegReadIndex2[INDEX_LEN-1:0];
assign writeIdx = RegWriteIndex[INDEX_LEN-1:0];


// zero register should equal to zero anytime.
ysyx_24100012_Reg #(DATA_WIDTH,0) x0 (
    clk,1'b1,
    reg_input_list[0],
    reg_output_list[0],
    1'b0);

genvar i;
generate
    for (i=1;i<N_REG;i=i+1) begin: x
    ysyx_24100012_Reg #(DATA_WIDTH,0) x (clk,rst,
        reg_input_list[i],
        reg_output_list[i],
        WEn_list[i]);
    end
endgenerate

assign WEn_list[writeIdx] = RegWEn;
assign reg_input_list[writeIdx] = RegWriteData;
assign RegReadData1 = reg_output_list[readIdx1];
assign RegReadData2 = reg_output_list[readIdx2];

endmodule
