`timescale 1ns/1ps
//32位带符号加法器
module adder32 #(
    parameter RV32_Width = 32
)(
    input       [RV32_Width-1:0] a,
    input       [RV32_Width-1:0] b,
    output wire [RV32_Width-1:0] sum,
    output wire                  overflow
);
    wire [RV32_Width-1:0] carry;
    wire                  a_sign;
    wire                  b_sign;

    //符号位
    assign a_sign = a[RV32_Width-1];
    assign b_sign = b[RV32_Width-1];

    //全加器
    genvar i;
    generate
        for (i = 0; i < RV32_Width; i = i + 1) begin : adder_gen
            if (i == 0) begin
                full_adder fa (
                    .a(a[i]),
                    .b(b[i]),
                    .cin(1'b0),
                    .sum(sum[i]),
                    .cout(carry[i])
                );
            end else begin
                full_adder fa (
                    .a(a[i]),
                    .b(b[i]),
                    .cin(carry[i-1]),
                    .sum(sum[i]),
                    .cout(carry[i])
                );
            end
        end
    endgenerate

    //溢出检测
    assign overflow = (a_sign == b_sign) && (a_sign != sum[RV32_Width-1]) && (carry[RV32_Width-1] != a_sign);
    //溢出检测是基于符号位的，如果两个操作数符号相同，而结果符号不同，则发生溢出
endmodule

//全加器
module full_adder(
    input  a,
    input  b,
    input  cin,
    output sum,
    output cout
);
    assign sum  = a ^ b ^ cin;
    assign cout = (a & b) | (cin & (a ^ b));
endmodule
