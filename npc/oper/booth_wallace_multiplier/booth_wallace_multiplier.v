module booth_wallace_multiplier (
    input wire clk,
    input wire rst_n,
    input wire signed [31:0] multiplicand,//X
    input wire signed [31:0] multiplier,//Y
    input wire is_signed,  // 1表示有符号乘法，0表示无符号乘法
    output reg signed [63:0] product,
    output reg valid
);
// 扩展被乘数和乘数
wire signed [31:0] multiplicand_signed = multiplicand[31:0];
wire signed [31:0] multiplier_signed = multiplier[31:0];

wire signed [67:0] multiplicand_ext = is_signed ? {{36{multiplicand_signed[31]}}, multiplicand_signed}
                                                : {36'd0, multiplicand[31:0]};
wire signed [34:0] multiplier_ext = is_signed ? {{2{multiplier_signed[31]}}, multiplier_signed, 1'b0}
                                              : {2'b0, multiplier[31:0], 1'b0};

//wire signed [67:0] multiplicand_ext= is_signed? {{36{multiplicand[31]}}, multiplicand} : {36'd0, multiplicand};//{{36{multiplicand[31]}}, multiplicand}
//wire signed [34:0] multiplier_ext = is_signed ? {{2{multiplier[31]}}, multiplier,1'b0} :  {2'b0, multiplier,1'b0};  //{{2{multiplier[31]}}, multiplier} 
// Booth两位乘法部分积生成模块
initial begin
    $display("multiplicand = %h, multiplier = %h, is_signed = %b", 
             multiplicand, multiplier, is_signed);
end
wire signed [67:0] partial_products [16:0];
genvar i;
generate
    for (i = 0; i < 17; i = i + 1) begin : gen_partial_products
        wire [2:0] y_group = {multiplier_ext[i*2+2], multiplier_ext[i*2+1], multiplier_ext[i*2]};
        wire signed [67:0] x_shifted = multiplicand_ext << (i*2);
        
        wire sel_negative, sel_double_negative, sel_positive, sel_double_positive;
        assign {sel_negative, sel_double_negative, sel_positive, sel_double_positive} = 
            {y_group[2] & (y_group[1] ^ y_group[0]), y_group[2] & ~y_group[1] & ~y_group[0], 
             ~y_group[2] & (y_group[1] ^ y_group[0]), ~y_group[2] & y_group[1] & y_group[0]};
        assign partial_products[i] = (sel_negative? -x_shifted : (sel_double_negative? (-x_shifted) << 1 : 
                                 (sel_positive? x_shifted : (sel_double_positive? (x_shifted << 1) : 68'd0))));
    end
endgenerate
wire [16:0] switch_outputs [67:0];
genvar j, k;
generate
    for (j = 0; j < 68; j = j + 1) begin : gen_switch
        for (k = 0; k < 17; k = k + 1) begin
            assign switch_outputs[j][k] = partial_products[k][j];
        end
    end
endgenerate
wire [13:0] cout_group [67:0];
wire  cout  [67:0];
wire [67:0] cout2  ;
wire [67:0] s ;
genvar l;
generate
    for (l = 0; l < 68; l = l + 1) begin : gen_wallace
        walloc_17bits uut (
           .src_in(switch_outputs[l]),
           .cin(l ==0? 14'd0: cout_group[l-1] ),
           .cout_group(cout_group[l]),
           .cout(cout[l]),
           .s(s[l])
        );
        assign cout2[l]=cout[l];
    end
endgenerate
always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        product <= 64'd0;
        valid <= 1'b0;
    end else begin
        if (is_signed) begin
            product <= $signed({{1'b0, s} + {cout2, 1'b0}}[63:0]); // 有符号截断
        end else begin
            product <= {{1'b0, s} + {cout2, 1'b0}}[63:0]; // 无符号截断
        end
        valid <= 1'b1;
    end
end
endmodule
/* verilator lint_off DECLFILENAME */
module walloc_17bits(
    input [16:0] src_in,
    input [13:0] cin,
    output [13:0] cout_group,
    output cout, s
);
    wire [13:0] c;
    wire [4:0] first_s;
    csa csa0 (.in (src_in[16:14]),.cout (c[4]),.s (first_s[4]) );
    csa csa1 (.in (src_in[13:11]),.cout (c[3]),.s (first_s[3]) );
    csa csa2 (.in (src_in[10:08]),.cout (c[2]),.s (first_s[2]) );
    csa csa3 (.in (src_in[07:05]),.cout (c[1]),.s (first_s[1]) );
    csa csa4 (.in (src_in[04:02]),.cout (c[0]),.s (first_s[0]) );
    wire [3:0] secnod_s;
    csa csa5 (.in ({first_s[4:2]}),.cout (c[8]),.s (secnod_s[3]));
    csa csa6 (.in ({first_s[1:0],src_in[1]}),.cout (c[7]),.s (secnod_s[2]));
    csa csa7 (.in ({src_in[0],cin[4:3]}),.cout (c[6]),.s (secnod_s[1]));
    csa csa8 (.in ({cin[2:0]}),.cout (c[5]),.s (secnod_s[0]));
    wire [1:0] thrid_s;
    csa csa9 (.in (secnod_s[3:1]),.cout (c[10]),.s (thrid_s[1]));
    csa csaA (.in ({secnod_s[0],cin[6:5]}),.cout (c[09]),.s (thrid_s[0]));
    wire [1:0] fourth_s;
    csa csaB (.in ({thrid_s[1:0],cin[10]}),.cout (c[12]),.s (fourth_s[1]));
    csa csaC (.in ({cin[9:7]}),.cout (c[11]),.s (fourth_s[0]));
    wire fifth_s;
    csa csaD (.in ({fourth_s[1:0],cin[11]}),.cout (c[13]),.s (fifth_s));
    csa csaE (.in ({fifth_s,cin[13:12]}),.cout (cout),.s (s));
    assign cout_group = c;
endmodule
/* verilator lint_off DECLFILENAME */
module csa(
    input [2:0] in,
    output cout, s
);
    wire a,b,cin;
    assign a = in[2];
    assign b = in[1];
    assign cin = in[0];
    assign s = a ^ b ^ cin;
    assign cout = a & b | b & cin | a & cin;
endmodule



