module ysyx_23060203_EXU (
  input clock, reset,

  // 冲刷信号
  input flush,

  // EXU将要写入但还没写入的寄存器
  output [4:0] exu_rd,
  output [31:0] exu_rd_val,

  // 访存AXI接口
  ysyx_23060203_axi_if.out mem_r,
  ysyx_23060203_axi_if.out mem_w,

  // 上游IDU输入
  output in_ready,
  input in_valid,
  input [31:0] in_pc,
  input [31:0] in_val_a,
  input [31:0] in_val_b,
  input [31:0] in_val_c,
  input [ 2:0] in_alu_funct,
  input        in_alu_sw,
  input [ 4:0] in_rd,
  input        in_rd_src,
  input [ 3:0] in_ls,
  input        in_csr_wen,
  input        in_csr_src,
  input        in_exc,
  input        in_ret,
  input        in_fencei,

  // 下游WBU输出
  input out_ready,
  output out_valid,
  output [31:0] out_pc,
  output [4:0] out_gpr_waddr,
  output [31:0] out_gpr_wdata,
  output out_csr_wen,
  output [11:0] out_csr_waddr,
  output [31:0] out_csr_wdata,
  output out_exc,
  output out_ret,
  output out_fencei

  `ifdef NPC_DEBUG
    ,
    input [31:0] in_inst,
    input [31:0] in_dnpc,
    output [31:0] out_inst,
    output [31:0] out_dnpc
  `endif
);

  reg valid;
  reg [31:0] pc;
  reg [31:0] val_a, val_b, val_c;
  reg [ 2:0] alu_funct;
  reg        alu_sw;
  reg [ 4:0] rd;
  reg        rd_src;
  reg [ 3:0] ls;
  reg        csr_wen;
  reg        csr_src;
  reg        exc;
  reg        ret;
  reg        fencei;

  `ifdef NPC_DEBUG
    reg [31:0] inst;
    reg [31:0] dnpc;
    assign out_inst = inst;
    assign out_dnpc = dnpc;
  `endif

  always @(posedge clock)
  if (reset) begin
    valid <= 0;
  end else begin
    if (flush) begin
      valid <= 0;
    end if (in_ready & in_valid) begin
      valid <= 1;
      pc <= in_pc;
      val_a <= in_val_a;
      val_b <= in_val_b;
      val_c <= in_val_c;
      alu_funct <= in_alu_funct;
      alu_sw <= in_alu_sw;
      rd <= in_rd;
      rd_src <= in_rd_src;
      ls <= in_ls;
      csr_wen <= in_csr_wen;
      csr_src <= in_csr_src;
      exc <= in_exc;
      ret <= in_ret;
      fencei <= in_fencei;
      `ifdef NPC_DEBUG
        inst <= in_inst;
        dnpc <= in_dnpc;
      `endif
    end else if (out_ready & out_valid) begin
      valid <= 0;
    end
  end

  // 对于不需要功能单元的指令，EXU只需要一周期，而且WBU从不阻塞
  assign in_ready = lsu_in_ready; // & mul_in_ready & div_in_ready;
  assign out_valid = ~flush & valid & exec_out_valid;

  assign out_pc = pc;

  reg exec_out_valid;
  always_comb begin
    exec_out_valid = 1;
    if (|ls) exec_out_valid = lsu_out_valid;
    // else if (mul) exec_out_valid = alu_funct[2] ? div_out_valid : mul_out_valid;
  end

  wire exec_in_en = ~flush & in_valid & in_ready;

  // -------------------- ALU --------------------
  wire [31:0] alu_val;
  ysyx_23060203_ALU ALU (
    .alu_a(val_a), .alu_b(val_b),
    .funct(alu_funct), .sw(alu_sw),
    .val(alu_val)
  );

  // -------------------- LSU --------------------
  wire lsu_in_en = |in_ls;
  wire lsu_in_ready, lsu_out_valid;
  wire [31:0] lsu_out_rdata;
  ysyx_23060203_LSU LSU (
    .clock(clock), .reset(reset), .flush(flush),
    .mem_r(mem_r), .mem_w(mem_w),
    .in_ready(lsu_in_ready), .in_valid(exec_in_en & lsu_in_en),
    .ls(ls), .alu_val(alu_val), .val_c(val_c),
    .out_ready(out_ready), .out_valid(lsu_out_valid),
    .out_rdata(lsu_out_rdata)
  );

  // -------------------- MUL --------------------
  // wire mul_in_en = in_mul & ~in_alu_funct[2];
  // wire [1:0] mul_in_sign = {^in_alu_funct[1:0], ~in_alu_funct[1] & in_alu_funct[0]};
  // wire mul_in_ready, mul_out_valid;
  // wire [63:0] mul_out_prod;
  // wire [31:0] mul_val = (|alu_funct[1:0]) ? mul_out_prod[63:32] : mul_out_prod[31:0];
  // MUL_test MUL (
  //   .clock(clock), .reset(reset), .flush(0),
  //   .in_ready(mul_in_ready), .in_valid(exec_in_en & mul_in_en),
  //   .in_sign(mul_in_sign), .in_a(in_val_a), .in_b(in_val_b),
  //   .out_ready(out_ready), .out_valid(mul_out_valid),
  //   .out_prod(mul_out_prod)
  // );

  // -------------------- DIV --------------------
  // wire div_in_en = in_mul & in_alu_funct[2];
  // wire div_in_sign = ~in_alu_funct[0];
  // wire div_in_ready, div_out_valid;
  // wire [31:0] div_out_quot, div_out_rem;
  // wire [31:0] div_val = alu_funct[1] ? div_out_rem : div_out_quot;
  // DIV_test DIV (
  //   .clock(clock), .reset(reset), .flush(0),
  //   .in_ready(div_in_ready), .in_valid(exec_in_en & div_in_en),
  //   .in_sign(div_in_sign), .in_a(in_val_a), .in_b(in_val_b),
  //   .out_ready(out_ready), .out_valid(div_out_valid),
  //   .out_quot(div_out_quot), .out_rem(div_out_rem)
  // );

  // -------------------- GPR写回 --------------------
  assign out_gpr_waddr = rd;
  assign out_gpr_wdata = ls[3] ? lsu_out_rdata : (
    rd_src ? val_a : alu_val
  );

  assign exu_rd = rd & {5{valid}};
  // assign exu_rd_val = out_gpr_wdata;
  // TEMP: 只有CSR指令的rd_src为1，反正要被冲刷掉，前递错误也没关系
  // WARN: 数据通路修改可能会导致错误
  assign exu_rd_val = ls[3] ? lsu_out_rdata : alu_val;

  // -------------------- CSR写回 --------------------
  assign out_csr_wen = csr_wen;
  assign out_csr_waddr = val_c[11:0];
  assign out_csr_wdata = csr_src ? val_b : alu_val;

  // -------------------- sys --------------------
  assign out_exc = exc;
  assign out_ret = ret;
  assign out_fencei = fencei;

  // -------------------- 性能计数器 --------------------
`ifdef NPC_DEBUG
  always @(posedge clock) if (~reset) begin
    if (out_ready & out_valid) begin
      perf_event(PERF_EXU_INST);
    end
    if (~valid) begin
      perf_event(PERF_EXU_IDLE);
    end
  end
`endif

endmodule
