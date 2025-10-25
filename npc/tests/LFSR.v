module LFSR (
  input  wire clk,
  input  wire rst,
  input  wire en,            // 每次拉高，会触发产生一个新随机数
  output reg  [4:0] rand_out // 随机数输出，范围：1 ~ 31
);

  reg [4:0] lfsr;
	reg feedback;
  always @(posedge clk) begin
    if (rst) begin
      lfsr <= 5'b00001; // 不能全 0，初始值必须非零
    end else if (en) begin
      // 计算新 bit
      feedback <= lfsr[4] ^ lfsr[2];
      lfsr <= {lfsr[3:0], feedback};
    end
  end

  // LFSR 自身就是 1~31 的伪随机数
  always @(*) begin
    rand_out = lfsr;
  end

endmodule
