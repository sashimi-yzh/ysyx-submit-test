module lfsr_4bit (
    input   wire            clock       ,           // 时钟信号
    input   wire            reset       ,           // 复位信号，高电平有效
    input   wire            enable      ,           // 状态跳转使能信号，高电平有效
    output  wire    [3:0]   lfsr_out                // 4位LFSR输出
);

reg [3:0] lfsr_reg;      // 4位寄存器，用于存储LFSR的状态

// 在时钟上升沿或复位信号变化时触发
always @(posedge clock ) begin
    if (reset) begin
        lfsr_reg <= 4'b0001; // 当复位信号有效时，将LFSR状态设置为初始值
    end else if (enable) begin
        // 本原多项式 x^4 + x + 1 对应的反馈逻辑
        lfsr_reg <= {lfsr_reg[2:0], lfsr_reg[3] ^ lfsr_reg[0]};
    end
end

// 输出当前的LFSR状态
assign lfsr_out = lfsr_reg;

endmodule
