

module ysyx_25020042_alu (
    input [31:0] data1,
    input [31:0] data2,
    input [3:0] ALUctrl,
    output reg [31:0] o_data
);

wire [31:0] adder_out;
wire [31:0] shift_out;
wire        less_out;
wire        is_right;
assign is_right = ALUctrl[2:0] == 3'b101;

always @(*) begin
    o_data = 32'h00000000;
    case (ALUctrl[2:0])
        3'b000: o_data = adder_out;
        3'b001: o_data = shift_out;
        3'b010: o_data = {31'b0, less_out};
        3'b011: o_data = data2;
        3'b100: o_data = data1 ^ data2;
        3'b101: o_data = shift_out;
        3'b110: o_data = data1 | data2;
        3'b111: o_data = data1 & data2;
    endcase
end

ysyx_25020042_adder u_adder (
    .Add(~ALUctrl[3]),
    .x(data1),
    .y(data2),
    .sum(adder_out)
);

ysyx_25020042_barrel_shifter_param u_shift (
    .logic_en(~ALUctrl[3]),
    .Right(is_right),
    .data_i(data1),   
    .shift_amt(data2[4:0]), 
    .data_o(shift_out)  
);

ysyx_25020042_comparer u_comparer (
    .sign(~ALUctrl[3]),
    .x(data1),
    .y(data2),
    .less_out(less_out)
);

endmodule

module ysyx_25020042_comparer (
    input sign,
    input [31:0] x,
    input [31:0] y,
    output        less_out
);
wire [31:0] x_cmp = {x[31] ^ sign, x[30:0]};
wire [31:0] y_cmp = {y[31] ^ sign, y[30:0]};
assign less_out = (x_cmp < y_cmp) ? 1'b1 : 1'b0;

endmodule

module ysyx_25020042_adder (
    input Add,
    input [31:0] x,
    input [31:0] y,
    output wire [31:0] sum
);

assign sum = Add ? x + y : x + ~y + 1;

endmodule

module ysyx_25020042_barrel_shifter_param (
    input  logic_en,
    input  Right,
    input  [31:0] data_i,
    input  [4:0]  shift_amt,
    output [31:0] data_o
);

wire sign = logic_en ? 1'b0 : data_i[31];

wire [31:0] data_rev = {
    data_i[ 0], data_i[ 1], data_i[ 2], data_i[ 3],
    data_i[ 4], data_i[ 5], data_i[ 6], data_i[ 7],
    data_i[ 8], data_i[ 9], data_i[10], data_i[11],
    data_i[12], data_i[13], data_i[14], data_i[15],
    data_i[16], data_i[17], data_i[18], data_i[19],
    data_i[20], data_i[21], data_i[22], data_i[23],
    data_i[24], data_i[25], data_i[26], data_i[27],
    data_i[28], data_i[29], data_i[30], data_i[31]
};

wire        eff_sign   = Right ? sign   : 1'b0;
wire [31:0] shift_in   = Right ? data_i : data_rev;

wire [31:0] stage0, stage1, stage2, stage3, stage4;
assign stage0 = shift_amt[0] ? {{1{eff_sign}}, shift_in[31:1]}   : shift_in;
assign stage1 = shift_amt[1] ? {{2{eff_sign}}, stage0[31:2]}     : stage0;
assign stage2 = shift_amt[2] ? {{4{eff_sign}}, stage1[31:4]}     : stage1;
assign stage3 = shift_amt[3] ? {{8{eff_sign}}, stage2[31:8]}     : stage2;
assign stage4 = shift_amt[4] ? {{16{eff_sign}}, stage3[31:16]}   : stage3;

wire [31:0] stage4_rev = {
    stage4[ 0], stage4[ 1], stage4[ 2], stage4[ 3],
    stage4[ 4], stage4[ 5], stage4[ 6], stage4[ 7],
    stage4[ 8], stage4[ 9], stage4[10], stage4[11],
    stage4[12], stage4[13], stage4[14], stage4[15],
    stage4[16], stage4[17], stage4[18], stage4[19],
    stage4[20], stage4[21], stage4[22], stage4[23],
    stage4[24], stage4[25], stage4[26], stage4[27],
    stage4[28], stage4[29], stage4[30], stage4[31]
};

assign data_o = Right ? stage4 : stage4_rev;

endmodule
