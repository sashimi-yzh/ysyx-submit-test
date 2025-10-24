//非恢复除法算法
module divider (
    input              clk,
    input              reset,
    input  wire [31:0] dividend,  //被除数
    input  wire [31:0] divisor,   //除数
    input  wire        is_signed, //是否为有符号运算
    output reg  [31:0] quotient,  //商
    output reg  [31:0] remainder, //余数
    output reg         valid      //计算结果是否有效（除数为0或溢出时为无效）
);

    reg [31:0] abs_divisor;       //除数绝对值
    reg [63:0] temp_dividend;     //64位临时被除数
    reg [31:0] temp_quotient;     //临时商
    reg        quotient_sign;     //商的符号
    reg        remainder_sign;    //余数的符号
    reg [5:0]  cycle_count;       //计数器
    reg        computing;         //正在计算标志
    reg [31:0] pos_mask;          //位掩码

    always @(posedge clk) begin
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
        end else if (!computing) begin
            quotient       <= 32'b0;
            remainder      <= 32'b0;
            temp_quotient  <= 32'b0;
            pos_mask       <= 32'h80000000;
            cycle_count    <= 6'b0;
            valid          <= 1'b0;

            // 除零检测
            if (divisor == 32'b0) begin
                quotient  <= 32'hFFFFFFFF;
                remainder <= dividend;
                valid     <= 1'b0;
            end else if (is_signed && dividend == 32'h80000000 && divisor == 32'hFFFFFFFF) begin
                // 溢出 MIN_INT / -1
                quotient  <= 32'h80000000;
                remainder <= 32'b0;
                valid     <= 1'b0;
            end else begin
                // 初始化绝对值和符号
                abs_divisor    <= (is_signed && divisor[31]) ? (~divisor + 1) : divisor;
                quotient_sign  <= is_signed && (dividend[31] ^ divisor[31]);
                remainder_sign <= is_signed && dividend[31];
                temp_dividend  <= {32'b0, (is_signed && dividend[31]) ? (~dividend + 1) : dividend};
                computing      <= 1'b1;
            end
        end else begin
            // 计算移位值
            reg [63:0] temp_dividend_shifted;
            reg [31:0] next_remainder;
            reg [31:0] next_quotient;
            temp_dividend_shifted = {temp_dividend[62:0], 1'b0};
            next_quotient = temp_quotient; // 默认保持当前商

            // 比较和减法
            if (temp_dividend_shifted[63:32] >= abs_divisor) begin
                next_remainder = temp_dividend_shifted[63:32] - abs_divisor;
                temp_dividend  <= {next_remainder, temp_dividend_shifted[31:0]};
                next_quotient  = temp_quotient | pos_mask;
                // $display("中间临时商: %h", next_quotient);
            end else begin
                next_remainder = temp_dividend_shifted[63:32];
                temp_dividend  <= temp_dividend_shifted;
            end
            // $display("中间余数：  %h", next_remainder);

            temp_quotient <= next_quotient;
            pos_mask      <= pos_mask >> 1;
            cycle_count   <= cycle_count + 1;

            if (cycle_count == 6'd31) begin
                // $display("最终临时商: %h", next_quotient);
                quotient  <= quotient_sign ? (~next_quotient + 1) : next_quotient;
                remainder <= remainder_sign ? (~next_remainder + 1) : next_remainder;
                valid     <= 1'b1;
                computing <= 1'b0;
            end
            if(temp_dividend[63]) begin
                
            end
        end
    end
endmodule
