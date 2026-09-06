module reh_test (
  input        clk,
  input        rst_n,

  // Optional observation ports for synthesis/timing analysis
  output [31:0] regout1_q,
  output [31:0] regout2_q,
  output [31:0] mepc_q,
  output [31:0] mtvec_q
);

  // ---------------------------------------------------------------------------
  // Input registers (drive REGHEAP through a registered interface)
  // ---------------------------------------------------------------------------
  reg        ew_r;
  reg [4:0]  addr_r;
  reg [4:0]  src1_r;
  reg [4:0]  src2_r;
  reg [11:0] csr_r;
  reg [31:0] data_r;
  reg        csrrw_r;
  reg        csrrs_r;
  reg        ecallsig_r;
  reg        valid_r;

  // rst in regheap is 高有效，这里用 rst = ~rst_n
  wire rst = ~rst_n;

  // 简单激励：不断写不同寄存器和 CSR，使寄存器堆读写路径处于激活状态
  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      ew_r       <= 1'b0;
      addr_r     <= 5'd0;
      src1_r     <= 5'd0;
      src2_r     <= 5'd1;
      csr_r      <= 12'h300;   // mstatus
      data_r     <= 32'h0;
      csrrw_r    <= 1'b0;
      csrrs_r    <= 1'b0;
      ecallsig_r <= 1'b0;
      valid_r    <= 1'b0;
    end
    else begin
      // 总是有效，保持时序路径忙碌
      valid_r <= 1'b1;

      // 循环写不同通用寄存器
      ew_r   <= 1'b1;
      addr_r <= addr_r + 5'd1;
      data_r <= data_r + 32'd4;

      // 切换读口地址，观察读路径时序
      src1_r <= src1_r + 5'd1;
      src2_r <= src2_r + 5'd2;

      // 简单访问 CSR：在 mstatus / mtvec / mepc 之间切换
      case (csr_r)
        12'h300: csr_r <= 12'h305; // mtvec
        12'h305: csr_r <= 12'h341; // mepc
        default: csr_r <= 12'h300;
      endcase

      // 偶尔做一次 csrrw，其余时间保持普通寄存器写
      csrrw_r <= (csr_r == 12'h341);
      csrrs_r <= 1'b0;

      // 这里不触发 ecall，只保持为 0
      ecallsig_r <= 1'b0;
    end
  end

  // ---------------------------------------------------------------------------
  // REGHEAP instance (combinational datapath between input and output registers)
  // ---------------------------------------------------------------------------
  wire [31:0] regout1_w;
  wire [31:0] regout2_w;
  wire [31:0] mepc_w;
  wire [31:0] mtvec_w;

  ysyx_24100007_regheap u_reh (
    .clk    (clk),
    .rst    (rst),
    .ew     (ew_r),
    .addr   (addr_r),
    .src1   (src1_r),
    .src2   (src2_r),
    .csr    (csr_r),
    .data   (data_r),
    .csrrw  (csrrw_r),
    .csrrs  (csrrs_r),
    .ecallsig(ecallsig_r),
    .valid  (valid_r),
    .regout1(regout1_w),
    .regout2(regout2_w),
    .mepc   (mepc_w),
    .mtvec  (mtvec_w)
  );

  // ---------------------------------------------------------------------------
  // Output registers (capture REGHEAP results at the clock edge)
  // These define the timing path: input_regs -> REGHEAP -> output_regs.
  // ---------------------------------------------------------------------------
  reg [31:0] regout1_r_q;
  reg [31:0] regout2_r_q;
  reg [31:0] mepc_r_q;
  reg [31:0] mtvec_r_q;

  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      regout1_r_q <= 32'h0;
      regout2_r_q <= 32'h0;
      mepc_r_q    <= 32'h0;
      mtvec_r_q   <= 32'h0;
    end
    else begin
      regout1_r_q <= regout1_w;
      regout2_r_q <= regout2_w;
      mepc_r_q    <= mepc_w;
      mtvec_r_q   <= mtvec_w;
    end
  end

  assign regout1_q = regout1_r_q;
  assign regout2_q = regout2_r_q;
  assign mepc_q    = mepc_r_q;
  assign mtvec_q   = mtvec_r_q;

endmodule


