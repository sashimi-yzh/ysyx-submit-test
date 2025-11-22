`timescale 1ns/1ps
module divider (
    input              clk,
    input              reset,
    input  wire [31:0] dividend,  // 被除数（24 位尾数，高 8 位为 0）
    input  wire [31:0] divisor,   // 除数（24 位尾数，高 8 位为 0）
    input  wire        is_signed, // 是否为有符号运算
    output reg  [31:0] quotient,  // 商（定点小数，1 位整数 + 31 位小数）
    output reg  [31:0] remainder, // 余数
    output reg         valid      // 计算结果是否有效
);

    reg [31:0] abs_divisor;       // 除数绝对值
    /* verilator lint_off UNUSEDSIGNAL */
    reg [63:0] temp_dividend;     // 64 位临时被除数
    /* verilator lint_on UNUSEDSIGNAL */
    reg [31:0] temp_quotient;     // 临时商
    reg        quotient_sign;     // 商的符号
    reg        remainder_sign;    // 余数的符号
    reg [5:0]  cycle_count;       // 计数器
    reg        computing;         // 正在计算标志
    reg [31:0] pos_mask;          // 位掩码

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            quotient       <= 32'b0;
            remainder      <= 32'b0;
            temp_quotient  <= 32'b0;
            temp_dividend  <= 64'b0;
            pos_mask       <= 32'h80000000;
            quotient_sign  <= 1'b0;
            remainder_sign <= 1'b0;
            valid          <= 1'b0;
            cycle_count    <= 6'b0;
            computing      <= 1'b0;
            abs_divisor    <= 32'b0;
        end else if (!computing) begin
            quotient       <= 32'b0;
            remainder      <= 32'b0;
            temp_quotient  <= 32'b0;
            pos_mask       <= 32'h80000000;
            cycle_count    <= 6'b0;
            valid          <= 1'b0;

            if (divisor == 32'b0) begin
                quotient  <= 32'h7FFFFFFF; // NaN 或 Inf
                remainder <= dividend;
                valid     <= 1'b1; // 立即完成
            end else if (is_signed && dividend == 32'h80000000 && divisor == 32'hFFFFFFFF) begin
                quotient  <= 32'h80000000;
                remainder <= 32'b0;
                valid     <= 1'b1;
            end else begin
                abs_divisor    <= (is_signed && divisor[31]) ? (~divisor + 1) : divisor;
                quotient_sign  <= is_signed && (dividend[31] ^ divisor[31]);
                remainder_sign <= is_signed && dividend[31];
                // 修复宽度不匹配问题
                temp_dividend  <= {1'b0, (is_signed && dividend[31]) ? (~dividend + 1) : dividend, 31'b0};
                computing      <= 1'b1;
            end
        end else begin
            // 计算移位值
            reg [63:0] temp_dividend_shifted;
            reg [31:0] next_remainder;
            reg [31:0] next_quotient;

            temp_dividend_shifted = {temp_dividend[62:0], 1'b0};
            next_quotient = temp_quotient;

            // 比较和减法
            if (temp_dividend_shifted[63:32] >= abs_divisor) begin
                next_remainder = temp_dividend_shifted[63:32] - abs_divisor;
                temp_dividend  <= {next_remainder, temp_dividend_shifted[31:0]};
                next_quotient  = temp_quotient | pos_mask;
            end else begin
                next_remainder = temp_dividend_shifted[63:32];
                temp_dividend  <= temp_dividend_shifted;
            end

            temp_quotient <= next_quotient;
            pos_mask      <= pos_mask >> 1;
            cycle_count   <= cycle_count + 1;

            if (cycle_count == 6'd31) begin
                quotient  <= quotient_sign ? (~next_quotient + 1) : next_quotient;
                remainder <= remainder_sign ? (~next_remainder + 1) : next_remainder;
                valid     <= 1'b1;
                computing <= 1'b0;
            end
        end
    end
endmodule