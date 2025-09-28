module ysyx_23060203_WBU (
  input clock, reset,

  // GPR
  output gpr_wen, // 写入使能
  output [4:0] gpr_waddr, // 写入地址
  output [31:0] gpr_wdata, // 写入数据

  // CSR
  input [11:0] csr_raddr, // 读取地址
  output reg [31:0] csr_rdata, // 读出数据

  // CSU
  output cs_flush,
  output reg [31:0] cs_dnpc,
  output fencei,

  // 上游EXU输入
  output in_ready,
  input in_valid,
  input [31:0] in_pc,
  input [4:0] in_gpr_waddr,
  input [31:0] in_gpr_wdata,
  input in_csr_wen,
  input [11:0] in_csr_waddr,
  input [31:0] in_csr_wdata,
  input in_exc,
  input in_ret,
  input in_fencei

  `ifdef NPC_DEBUG
    ,
    input [31:0] in_inst,
    input [31:0] in_dnpc
  `endif
);

  // CSR寄存器地址常量
  parameter CSR_MSTATUS  = 12'h300;
  parameter CSR_MTVEC    = 12'h305;
  parameter CSR_MEPC     = 12'h341;
  parameter CSR_MCAUSE   = 12'h342;

  parameter CSR_MVENDORID = 12'hf11;
  parameter CSR_MARCHID   = 12'hf12;

  assign in_ready = 1;

  // -------------------- GPR --------------------
  assign gpr_wen = in_valid;
  assign gpr_waddr = in_gpr_waddr;
  assign gpr_wdata = in_gpr_wdata;

  // -------------------- CSU --------------------
  reg valid;
  reg [31:0] pc;
  reg csr_wen, exc, ret, fencei_r;

  always @(posedge clock)
  if (reset) begin
    valid <= 0;
  end else begin
    if (in_valid) begin
      valid <= 1;
      pc <= in_pc;
      csr_wen <= in_csr_wen;
      exc <= in_exc;
      ret <= in_ret;
      fencei_r <= in_fencei;
    end else begin
      valid <= 0;
    end
  end

  assign cs_flush = valid & (csr_wen | exc | ret | fencei_r);
  assign fencei = valid & fencei_r;

  always_comb begin
    case (1'b1)
      exc     : cs_dnpc = mtvec;
      ret     : cs_dnpc = mepc;
      default : cs_dnpc = pc + 4;
    endcase
  end

  // -------------------- CSR --------------------
  reg [31:0] mtvec, mepc;

  always @(posedge clock)
  begin
    if (in_valid) begin
      if (in_csr_wen) begin
        case (in_csr_waddr)
          CSR_MTVEC   : mtvec   <= in_csr_wdata;
          CSR_MEPC    : mepc    <= in_csr_wdata;
          default: ;
        endcase
      end else if (in_exc) begin
        mepc <= in_pc;
      end
    end
  end

  always_comb begin
    case (csr_raddr)
      CSR_MTVEC   : csr_rdata = mtvec;
      CSR_MEPC    : csr_rdata = mepc;

      CSR_MSTATUS   : csr_rdata = 32'h1800;
      CSR_MCAUSE    : csr_rdata = 32'd11;
      CSR_MVENDORID : csr_rdata = 32'h79737978;
      CSR_MARCHID   : csr_rdata = 32'h015fdeeb;

      default: csr_rdata = 32'b0;
    endcase
  end

  // -------------------- 仿真环境 --------------------
  `ifdef NPC_DEBUG
    always @(posedge clock) begin
      if (in_valid) begin
        if (in_exc) inst_complete(mtvec, in_inst);
        else if (in_ret) inst_complete(mepc, in_inst);
        else inst_complete(in_dnpc, in_inst);
        if (in_exc & in_ret) halt(); // ebreak
      end
    end
  `endif
endmodule
