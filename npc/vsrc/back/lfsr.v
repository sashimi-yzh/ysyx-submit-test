module lfsr(
    input  wire       rst,      // 复位信号 (对应 btr)
    input  wire       step,     // 步进按钮 (对应 btc)
    output wire [6:0] hex0,         // 数码管 HEX0
    output wire [6:0] hex1          // 数码管 HEX1
);

    reg [7:0] lfsr_reg;
    always @(posedge step or posedge rst) begin
        if (rst) begin
            lfsr_reg <= 8'b0000_0001; // 初始值，不能为全零
        end else if (step) begin
            // 全零处理
            if (lfsr_reg == 8'b0000_0000) begin
                lfsr_reg <= 8'b0000_0001;
            end else begin
                // 多项式: x^8 + x^4 + x^3 + x^2 + 1
                // 抽头: bit 0, bit 2, bit 3, bit 4
                lfsr_reg <= {lfsr_reg[0] ^ lfsr_reg[2] ^ lfsr_reg[3] ^ lfsr_reg[4], lfsr_reg[7:1]};
            end
        end
    end

    hex u_hex0 (
        .hex(lfsr_reg[3:0]),
        .seg(hex0)
    );
    hex u_hex1 (
        .hex(lfsr_reg[7:4]),
        .seg(hex1)
    );

endmodule
