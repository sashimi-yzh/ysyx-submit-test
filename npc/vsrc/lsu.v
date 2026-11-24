//`define LFSR_SIM_LSU
//`define DIFF_TEST

`ifdef DIFF_TEST
import "DPI-C" function void difftest_skip_ref();
`endif
module ysyx_24110012_lsu(
  input clk,

  input exu_lsu_reg_wen,
  input exu_lsu_mem_r,
  input exu_lsu_mem_w,
  input exu_lsu_mem_sign_ext,
  input [2:0] exu_lsu_mem_mask,
  input [31:0] exu_lsu_mem_addr,
  input [2:0] exu_lsu_func3,
  input [31:0] exu_lsu_result,
  input [31:0] exu_lsu_mem_wdata,
  input [3:0] exu_lsu_rd_idx,
  input [11:0] exu_lsu_csr_idx,
  input [31:0] exu_lsu_csr_rdata,
  input exu_lsu_ecall,
  input exu_lsu_mret,
  input exu_lsu_fencei,
  input exu_lsu_branch,
  input exu_lsu_jump,
  input exu_lsu_wb_from_mem,
  input exu_lsu_csr_wen,
  input [31:0] exu_lsu_npc,
  input exu_lsu_cycle_done,

  input wire exu_lsu_valid,
  output wire lsu_exu_ready,

  output wire lsu_wbu_reg_wen,
  output wire [2:0] lsu_wbu_func3,
  output wire [31:0] lsu_wbu_wdata,
  output wire [3:0] lsu_wbu_rd_idx,
  output wire [11:0] lsu_wbu_csr_idx,
  output wire [31:0] lsu_wbu_csr_rdata,
  output wire lsu_wbu_ecall,
  output wire lsu_wbu_mret,
  output wire lsu_wbu_fencei,
  output wire lsu_wbu_branch,
  output wire lsu_wbu_jump,
  output wire lsu_wbu_csr_wen,
  output wire [31:0] lsu_wbu_npc,
  output wire lsu_wbu_cycle_done,

  output wire lsu_wbu_valid,
  input wire wbu_lsu_ready,

  // AR
  output reg [31:0] araddr,
  output reg arvalid,
  output reg [2:0] arsize,
  input wire arready,
  // R
  input wire [31:0] rdata,
  input wire rvalid,
  output reg rready,
  // AW
  output reg [31:0] awaddr,
  output reg awvalid,
  output reg [2:0] awsize,
  input wire awready,
  // W
  output reg [31:0] wdata,
  output reg [3:0] wstrb,
  output reg wvalid,
  input wire wready,
  // B
  input wire [1:0] bresp,
  input wire bvalid,
  output reg bready
);

reg [31:0] rdata_ext;
reg [31:0] lsu_wbu_mem_rdata;
reg [2:0] mem_rmask_q;  // hold this incase mem_mask changes
reg mem_sign_ext_q;

wire io_r_done;
reg io_w_done;
reg w_active, r_active;

// the device(sram/flash) value is returned by 4byte aligned
wire [4:0] offset = {araddr[1:0], 3'b000};
wire [31:0] rdata_sh = rdata >> offset;

localparam [31:0] SKIP_START = 32'h02000000;
localparam [31:0] SKIP_R1    = 32'h0200ffff;
localparam [31:0] SKIP_R2    = 32'h10000000;
localparam [31:0] SKIP_END   = 32'h22000000;

assign io_r_done = rvalid && rready;
assign lsu_wbu_reg_wen = exu_lsu_reg_wen;
assign lsu_wbu_func3 = exu_lsu_func3;
assign lsu_wbu_wdata = exu_lsu_wb_from_mem ? lsu_wbu_mem_rdata : exu_lsu_result;
assign lsu_wbu_rd_idx = exu_lsu_rd_idx;
assign lsu_wbu_csr_idx = exu_lsu_csr_idx;
assign lsu_wbu_csr_rdata = exu_lsu_csr_rdata;
assign lsu_wbu_ecall = exu_lsu_ecall;
assign lsu_wbu_mret = exu_lsu_mret;
assign lsu_wbu_fencei = exu_lsu_fencei;
assign lsu_wbu_branch = exu_lsu_branch;
assign lsu_wbu_jump = exu_lsu_jump;
assign lsu_wbu_csr_wen = exu_lsu_csr_wen;
assign lsu_wbu_npc = exu_lsu_npc;
// read data will be set to rd regs so it does not affect cycle_done signal
assign lsu_wbu_cycle_done = exu_lsu_cycle_done | io_w_done;

always @(*) begin
  case (mem_rmask_q)
    3'b001: begin // lb
      rdata_ext = mem_sign_ext_q ? {{24{rdata_sh[7]}}, rdata_sh[7:0]} : {24'b0, rdata_sh[7:0]};
    end
    3'b011: begin // lu
      rdata_ext = mem_sign_ext_q ? {{16{rdata_sh[15]}}, rdata_sh[15:0]} : {16'b0, rdata_sh[15:0]};
    end
    default: begin // lw
      rdata_ext = rdata;
    end
  endcase
end

//valid/ready
// Check whether LSU current task is completed (read done / write done / non-memory inst directly done)
wire lsu_done = exu_lsu_mem_r ? io_r_done :
                exu_lsu_mem_w ? io_w_done : 1'b1;

// LSU output is valid only when upstream input is valid/ready recieved and current stage execution is done
assign lsu_wbu_valid = exu_lsu_valid && lsu_done;

// Ready to accept next request only when current task is done and downstream is ready
assign lsu_exu_ready = lsu_done && wbu_lsu_ready;

`ifdef DIFF_TEST
wire ar_skip_region =
  (araddr >= SKIP_START && araddr <= SKIP_R1) ||
  (araddr >= SKIP_R2 && araddr <= SKIP_END);
wire aw_skip_region =
  (awaddr >= SKIP_START && awaddr <= SKIP_R1) ||
  (awaddr >= SKIP_R2 && awaddr <= SKIP_END);

always @(posedge clk) begin
  // Skip only when this LSU instruction is actually accepted by downstream.
  if (lsu_wbu_valid && wbu_lsu_ready) begin
    if ((exu_lsu_mem_r && ar_skip_region) || (exu_lsu_mem_w && aw_skip_region)) begin
      difftest_skip_ref();
    end
  end
end
`endif

// No LSU LFSR simulation
`ifndef LFSR_SIM_LSU

always@(posedge clk) begin

  if (exu_lsu_valid && exu_lsu_mem_r && !r_active) begin
    araddr <= exu_lsu_mem_addr;
    mem_rmask_q <= exu_lsu_mem_mask;
    mem_sign_ext_q <= exu_lsu_mem_sign_ext;
    arvalid <= 1'b1;
    case (exu_lsu_mem_mask)
      3'b001: begin  // lb
        awsize    = 3'b000;
        arsize    = 3'b000;
      end
      3'b011: begin  // lu
        awsize = 3'b001;
        arsize = 3'b001;
      end
      default: begin  // lw
        awsize    = 3'b010;
        arsize    = 3'b010;
      end
    endcase
  end

  if (arvalid && arready) begin
    arvalid <= 1'b0;
    r_active <= 1'b1;
  end

  if (rvalid) begin
    arvalid <= 1'b0;
    rready <= 1'b1;
    lsu_wbu_mem_rdata <= rdata_ext;
  end

  if (rvalid && rready) begin
    rready <= 1'b0;
    araddr <= 32'b0;
    mem_rmask_q <= 3'b000;
    mem_sign_ext_q <= 1'b0;
    r_active <= 1'b0;
  end
end

always@(posedge clk) begin

  if (exu_lsu_valid && exu_lsu_mem_w && !w_active) begin
    awaddr <= exu_lsu_mem_addr;
    awvalid <= 1'b1;
    wdata <= (exu_lsu_mem_mask == 3'b111) ? exu_lsu_mem_wdata:
      (exu_lsu_mem_wdata << {exu_lsu_mem_addr[1:0], 3'b000});
    wstrb <= (exu_lsu_mem_mask == 3'b111) ? 4'b1111 :
      ({1'b0, exu_lsu_mem_mask} << exu_lsu_mem_addr[1:0]);
  end


  if (awvalid) begin
   wvalid <= 1'b1;
  end

  if (awready && awvalid) begin
    awvalid <= 1'b0;
    w_active <= 1'b1;
  end

  if (wvalid && wready) begin
    wvalid <= 1'b0;
    wstrb <= 4'b0;  // prevent continuous writing
  end

  if (bvalid) begin
    bready <= 1'b1;
    io_w_done <= 1'b1;
  end

  if (bvalid && bready) begin
    bready <= 1'b0;
    awaddr <= 32'b0;
    w_active <= 1'b0;
    io_w_done <= 1'b0;
  end
end

`else

reg [4:0] arvalid_lfsr = 5'b00101;
reg [4:0] arvalid_delay_cnt;
reg arvalid_start;

reg [4:0] rready_lfsr = 5'b00101;
reg [4:0] rready_delay_cnt;
reg rready_start;

always@(posedge clk) begin

  if (exu_lsu_mem_r) begin
    araddr <= exu_lsu_mem_addr;
    mem_rmask_q <= exu_lsu_mem_mask;
    mem_sign_ext_q <= exu_lsu_mem_sign_ext;
`ifdef LFSR_SIM_LSU
    arvalid_lfsr <= {arvalid_lfsr[3:0], arvalid_lfsr[2] ^ arvalid_lfsr[0]};
    arvalid_start <= 1'b1;
    arvalid_delay_cnt <= 5'b0;
`else
    arvalid <= 1'b1;
    case (exu_lsu_mem_mask)
      3'b001: begin  // lb
        awsize    = 3'b000;
        arsize    = 3'b000;
      end
      3'b011: begin  // lu
        awsize = 3'b001;
        arsize = 3'b001;
      end
      default: begin  // lw
        awsize    = 3'b010;
        arsize    = 3'b010;
      end
    endcase
`endif
  end

  if (arvalid_start) begin
    arvalid_delay_cnt <= arvalid_delay_cnt + 1'b1;
    if (arvalid_delay_cnt == arvalid_lfsr) begin
      arvalid <= 1'b1;
      arvalid_start <= 1'b0;
      arvalid_delay_cnt <= 5'b0;
    end
  end

  if (arvalid && arready) begin
    arvalid <= 1'b0;
  end

  if (rvalid) begin
    lsu_wbu_mem_rdata <= rdata_ext;
    arvalid <= 1'b0;
    if (rready_start == 1'b0) begin
      rready_lfsr <= {rready_lfsr[3:0], rready_lfsr[2] ^ rready_lfsr[0]};
    end
    rready_start <= 1'b1;
  end

  if (rready_start) begin
    rready_delay_cnt <= rready_delay_cnt + 1'b1;
    if (rready_delay_cnt == rready_lfsr) begin
      rready <= 1'b1;
      rready_start <= 1'b0;
      rready_delay_cnt <= 5'b0;
    end
  end

  if (rvalid && rready) begin
    rready <= 1'b0;
    araddr <= 32'b0;
    mem_rmask_q <= 3'b000;
    mem_sign_ext_q <= 1'b0;
    arvalid_start <= 1'b0;
  end
end

reg [4:0] awvalid_lfsr = 5'b00110;
reg [4:0] awvalid_delay_cnt;
reg awvalid_start;

reg [4:0] wvalid_lfsr = 5'b00010;
reg [4:0] wvalid_delay_cnt;
reg wvalid_start;

reg [4:0] bready_lfsr = 5'b00011;
reg [4:0] bready_delay_cnt;
reg bready_start;

always@(posedge clk) begin

  if (exu_lsu_mem_w) begin
    awaddr <= exu_lsu_mem_addr;
    awvalid <= 1'b1;
    wdata <= (exu_lsu_mem_mask == 3'b111) ? exu_lsu_mem_wdata:
      (exu_lsu_mem_wdata << {exu_lsu_mem_addr[1:0], 3'b000});
    wstrb <= (exu_lsu_mem_mask == 3'b111) ? 4'b1111 :
      ({1'b0, exu_lsu_mem_mask} << exu_lsu_mem_addr[1:0]);

    awvalid_lfsr <= {awvalid_lfsr[3:0], awvalid_lfsr[2] ^ awvalid_lfsr[0]};
    awvalid_start <= 1'b1;
    awvalid_delay_cnt <= 5'b0;
  end

  if (awvalid_start) begin
    awvalid_delay_cnt <= awvalid_delay_cnt + 1'b1;
    if (awvalid_delay_cnt == awvalid_lfsr) begin
      awvalid <= 1'b1;
      awvalid_start <= 1'b0;
      awvalid_delay_cnt <= 5'b0;
    end
  end

  if (awvalid) begin
   wvalid <= 1'b1;
  end

  if (awready && awvalid) begin
    awvalid <= 1'b0;
    wvalid_start <= 1'b1;
    wvalid_lfsr <= {wvalid_lfsr[3:0], wvalid_lfsr[2] ^ wvalid_lfsr[0]};
    wvalid_delay_cnt <= 5'b0;
  end

  if (wvalid_start) begin
    wvalid_delay_cnt <= wvalid_delay_cnt + 1'b1;
    if (wvalid_delay_cnt == wvalid_lfsr) begin
      wvalid <= 1'b1;
      wvalid_start <= 1'b0;
      wvalid_delay_cnt <= 5'b0;
    end
  end

  if (wvalid && wready) begin
    wvalid <= 1'b0;
    wstrb <= 4'b0;  // prevent continuous writing
  end

  if (bvalid) begin
    // no handling for bresp now
    if (bready_start == 1'b0) begin
      bready_lfsr <= {bready_lfsr[3:0], bready_lfsr[2] ^ bready_lfsr[0]};
    end
    if (bready == 1'b0) begin
      bready_start <= 1'b1;
    end
  end

  if (bready_start) begin
    bready_delay_cnt <= bready_delay_cnt + 1'b1;
    if (bready_delay_cnt == bready_lfsr) begin
      bready <= 1'b1;
      bready_start <= 1'b0;
      bready_delay_cnt <= 5'b0;
    end
  end

  if (bvalid && bready) begin
    bready <= 1'b0;
    awaddr <= 32'b0;
    awvalid_start <= 1'b0;
  end
end
`endif

endmodule
