module ysyx_24110012_wbu(
  input wire clk,
  input wire reset,

  input wire lsu_wbu_reg_wen,
  input wire [2:0] lsu_wbu_func3,
  input wire [31:0] lsu_wbu_wdata,
  input wire [4:0] lsu_wbu_rd_idx,
  input wire [11:0] lsu_wbu_csr_idx,
  input wire [31:0] lsu_wbu_csr_rdata,
  input wire lsu_wbu_ecall,
  input wire lsu_wbu_mret,
  input wire lsu_wbu_fencei,
  input wire lsu_wbu_branch,
  input wire lsu_wbu_jump,
  input wire lsu_wbu_csr_wen,
  input wire [31:0] lsu_wbu_npc,
  input wire lsu_wbu_cycle_done,

  input wire lsu_wbu_valid,
  output wire wbu_lsu_ready,

  output reg [31:0] wbu_rf_wdata,
  output reg [31:0] wbu_csr_wdata,
  output wire [4:0] wbu_rf_idx,
  output reg [11:0] wbu_rf_csr_idx,
  output wire wbu_rf_csr_wen,
  output wire wbu_rf_reg_wen,
  output reg [31:0] wbu_ifu_pc,
  output reg wbu_redirect,
  output wire wbu_fencei,
  output wire wbu_cycle_done,

  input wire icache_flush_done
);
  wire wbu_redirect_i;

  assign wbu_rf_idx = lsu_wbu_rd_idx;
  // ecall needs to commit trap CSRs (mepc/mcause) even though it is not a CSR instruction.
  assign wbu_rf_csr_wen = lsu_wbu_valid && wbu_lsu_ready &&
                          (lsu_wbu_csr_wen || lsu_wbu_ecall);
  assign wbu_rf_reg_wen = lsu_wbu_valid && wbu_lsu_ready && lsu_wbu_reg_wen;
  assign wbu_fencei = lsu_wbu_valid && lsu_wbu_fencei;
  assign wbu_redirect_i = lsu_wbu_valid && wbu_lsu_ready &&
                          (lsu_wbu_ecall || lsu_wbu_mret);
  assign wbu_redirect = lsu_wbu_valid ? wbu_redirect_i : 1'b0;

  localparam CSR_MEPC    = 12'h341;

  reg cycle_done_r;

  //valid/ready
  assign wbu_lsu_ready = lsu_wbu_fencei ? icache_flush_done : 1'b1;

  always @(posedge clk) begin
    if (reset) begin
      cycle_done_r <= 1'b0;
    end else begin
      cycle_done_r <= lsu_wbu_valid && wbu_lsu_ready;
    end
  end

  assign wbu_cycle_done = cycle_done_r;

  always @(*) begin
    // Jump/Branch:
    // The PC should get from address from EXU
    wbu_ifu_pc = lsu_wbu_npc;

    // Provide default value
    wbu_csr_wdata = lsu_wbu_wdata;
    wbu_rf_csr_idx = lsu_wbu_csr_idx;

    // Ecall:
    // The PC should get from mtvec from CSR
    // And the PC should store to mepc
    if (lsu_wbu_ecall) begin
       wbu_csr_wdata = lsu_wbu_npc;
       wbu_rf_csr_idx = CSR_MEPC;
       wbu_ifu_pc = lsu_wbu_csr_rdata;
    end
    if (lsu_wbu_mret) begin
    // Eret:
    // The PC should get from mepc from CSR
       wbu_ifu_pc = lsu_wbu_csr_rdata;
    end

  end

  always @(*) begin
    // wb_from_mem is only set when read is done from lsu
    if (lsu_wbu_reg_wen) begin
      wbu_rf_wdata = lsu_wbu_wdata;
    end else if (lsu_wbu_csr_wen) begin
      wbu_rf_wdata = lsu_wbu_csr_rdata;
      // this is for csrrs instruction - csrrs, R(rd) = SR(csr); SR(csr) = src1|SR(csr);
      if (lsu_wbu_func3 == 3'b010) begin
        wbu_rf_wdata = lsu_wbu_wdata;
      end
    end else begin
      wbu_rf_wdata = lsu_wbu_wdata;
    end
  end
endmodule
