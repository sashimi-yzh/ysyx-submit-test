`include "pipe_def.svh"

module ysyx_24110012 (
    input clock,
    input reset,
    input io_interrupt,

    // AXI4 Master Interface
    // Write Address Channel
    input         io_master_awready,
    output        io_master_awvalid,
    output [31:0] io_master_awaddr,
    output [3:0]  io_master_awid,
    output [7:0]  io_master_awlen,
    output [2:0]  io_master_awsize,
    output [1:0]  io_master_awburst,

    // Write Data Channel
    input         io_master_wready,
    output        io_master_wvalid,
    output [31:0] io_master_wdata,
    output [3:0]  io_master_wstrb,
    output        io_master_wlast,

    // Write Response Channel
    output        io_master_bready,
    input         io_master_bvalid,
    input  [1:0]  io_master_bresp,
    input  [3:0]  io_master_bid,

    // Read Address Channel
    input         io_master_arready,
    output        io_master_arvalid,
    output [31:0] io_master_araddr,
    output [3:0]  io_master_arid,
    output [7:0]  io_master_arlen,
    output [2:0]  io_master_arsize,
    output [1:0]  io_master_arburst,

    // Read Data Channel
    output        io_master_rready,
    input         io_master_rvalid,
    input  [1:0]  io_master_rresp,
    input  [31:0] io_master_rdata,
    input         io_master_rlast,
    input  [3:0]  io_master_rid,

    // AXI4 Slave Interface
    // Write Address Channel
    output        io_slave_awready,
    input         io_slave_awvalid,
    input  [31:0] io_slave_awaddr,
    input  [3:0]  io_slave_awid,
    input  [7:0]  io_slave_awlen,
    input  [2:0]  io_slave_awsize,
    input  [1:0]  io_slave_awburst,

    // Write Data Channel
    output        io_slave_wready,
    input         io_slave_wvalid,
    input  [31:0] io_slave_wdata,
    input  [3:0]  io_slave_wstrb,
    input         io_slave_wlast,

    // Write Response Channel
    input         io_slave_bready,
    output        io_slave_bvalid,
    output [1:0]  io_slave_bresp,
    output [3:0]  io_slave_bid,

    // Read Address Channel
    output        io_slave_arready,
    input         io_slave_arvalid,
    input  [31:0] io_slave_araddr,
    input  [3:0]  io_slave_arid,
    input  [7:0]  io_slave_arlen,
    input  [2:0]  io_slave_arsize,
    input  [1:0]  io_slave_arburst,

    // Read Data Channel
    input         io_slave_rready,
    output        io_slave_rvalid,
    output [1:0]  io_slave_rresp,
    output [31:0] io_slave_rdata,
    output        io_slave_rlast,
    output [3:0]  io_slave_rid
);

`ifndef SYNTHESIS
// DPI-C
// Function to get PC value from C++
export "DPI-C" function get_pc;
function int get_pc();
    return done_pc;
endfunction

// Function to get NPC value from C++
export "DPI-C" function get_npc;
function int get_npc();
  return done_npc;
endfunction

// Function to get instruction value from C++
export "DPI-C" function get_inst;
function int get_inst();
    return done_inst;
endfunction


export "DPI-C" function get_cycle_done;
function bit get_cycle_done();
    return cycle_done;
endfunction

export "DPI-C" function get_lsu_wbu_valid_o;
function bit get_lsu_wbu_valid_o();
    return lsu_wbu_valid_o;
endfunction

import "DPI-C" function void ebreak_catch(input int pc, input int rdata_x);
// DPI-C end

// add error handler for AXI illegal access
always @(posedge clock) begin
  // AXI4 Master Write Response
  if (io_master_bvalid && io_master_bready && io_master_bresp != 2'b00) begin
    $fatal("AXI4 Master Write Response Error: io_master_bresp = %b", io_master_bresp);
  end

  // AXI4 Master Read Response
  if (io_master_rvalid && io_master_rready && io_master_rresp != 2'b00) begin
    $fatal("AXI4 Master Read Response Error: io_master_rresp = %b", io_master_rresp);
  end

  // AXI4 Slave Write Response
  if (io_slave_bvalid && io_slave_bready && io_slave_bresp != 2'b00) begin
    $fatal("AXI4 Slave Write Response Error: io_slave_bresp = %b", io_slave_bresp);
  end

  // AXI4 Slave Read Response
  if (io_slave_rvalid && io_slave_rready && io_slave_rresp != 2'b00) begin
    $fatal("AXI4 Slave Read Response Error: io_slave_rresp = %b", io_slave_rresp);
  end
end
`endif

wire cycle_done, wbu_cycle_done;
assign cycle_done = wbu_cycle_done;

// IFU AR/R
wire [31:0] ifu_araddr, ifu_rdata;
wire ifu_arvalid, ifu_arready, ifu_rvalid, ifu_rready;
wire [2:0] ifu_arsize;

// IFU AW/W/B
wire [31:0] ifu_awaddr,ifu_wdata;
wire ifu_awvalid, ifu_awready, ifu_wvalid, ifu_wready, ifu_bvalid, ifu_bready;
wire [3:0] ifu_wstrb;
wire [1:0] ifu_bresp;
wire [2:0] ifu_awsize;

// pipeline stage handshake
wire ifu_idu_valid_i, idu_ifu_ready_i;
wire ifu_idu_valid_o, idu_ifu_ready_o;

// wires from WBU & EXU for redirect
wire wbu_redirect;
wire [31:0] wbu_ifu_npc;
wire exu_redirect;
wire [31:0] exu_redirect_pc;

wire redirect = wbu_redirect | exu_redirect;
wire [31:0] redirect_pc = wbu_redirect ? wbu_ifu_npc : exu_redirect_pc;

wire [31:0] ifu_idu_pc_o;
wire [31:0] ifu_idu_inst_o;
wire ifu_idu_cycle_done_o;
wire icache_flush_done;

ysyx_24110012_ifu my_ifu(
    .clk(clock),
    .reset(reset),
    .cycle_done(cycle_done),


    .ifu_idu_pc(ifu_idu_pc_o),
    .ifu_idu_inst(ifu_idu_inst_o),
    .ifu_idu_cycle_done(ifu_idu_cycle_done_o),

    .ifu_idu_valid(ifu_idu_valid_i),
    .idu_ifu_ready(idu_ifu_ready_o),

    .wbu_ifu_npc(redirect_pc),
    .wbu_redirect(redirect),
    .flush(wbu_fencei),

    .araddr(ifu_araddr),
    .arvalid(ifu_arvalid),
    .arsize(ifu_arsize),
    .arready(ifu_arready),
    .rdata(ifu_rdata),
    .rvalid(ifu_rvalid),
    .rready(ifu_rready),
    .awaddr(ifu_awaddr),
    .awvalid(ifu_awvalid),
    .awsize(ifu_awsize),
    .awready(ifu_awready),
    .wdata(ifu_wdata),
    .wstrb(ifu_wstrb),
    .wvalid(ifu_wvalid),
    .wready(ifu_wready),
    .bresp(ifu_bresp),
    .bvalid(ifu_bvalid),
    .bready(ifu_bready)
);

// ICACHE <-> MEM AR/R
wire [31:0] icache_araddr, icache_rdata;
wire icache_arvalid, icache_arready, icache_rvalid, icache_rready, icache_rlast;
wire [2:0] icache_arsize;
wire [1:0] icache_arburst;
wire [7:0] icache_arlen;

`ifdef ICACHE_SIM_LARGE
localparam integer ICACHE_BLOCK_BYTES = 32;
localparam integer ICACHE_NUM_LINES   = 64;
`else
localparam integer ICACHE_BLOCK_BYTES = 8;
localparam integer ICACHE_NUM_LINES   = 4;
`endif

// Wires from WBU
wire wbu_fencei;

ysyx_24110012_icache #(
  .BLOCK_BYTES(ICACHE_BLOCK_BYTES),
  .NUM_LINES  (ICACHE_NUM_LINES)
  ) my_icache (
  .clk           (clock),
  .reset         (reset),
  .flush         (wbu_fencei),
  .flush_done    (icache_flush_done),
  .ifu_req_valid (ifu_arvalid),
  .ifu_req_ready (ifu_arready),
  .ifu_req_addr  (ifu_araddr),
  .ifu_resp_valid(ifu_rvalid),
  .ifu_resp_ready(ifu_rready),
  .ifu_resp_data (ifu_rdata),
  .mem_araddr    (icache_araddr),
  .mem_arvalid   (icache_arvalid),
  .mem_arburst   (icache_arburst),
  .mem_arlen     (icache_arlen),
  .mem_arsize    (icache_arsize),
  .mem_arready   (icache_arready),
  .mem_rdata     (icache_rdata),
  .mem_rvalid    (icache_rvalid),
  .mem_rlast     (icache_rlast),
  .mem_rready    (icache_rready)
);

wire [31:0] rf_idu_rs1, rf_idu_rs2, rf_idu_reg_x;
wire [31:0] hazard_idu_rs1, hazard_idu_rs2;
wire [31:0] rf_idu_csr_rdata;
wire [11:0] idu_rf_csr_idx;
wire [3:0] idu_rs1_idx, idu_rs2_idx, rd_idx;

// wires from WBU
wire [11:0] wbu_rf_csr_idx;
wire [3:0] wbu_rf_idx;
wire [31:0] wbu_rf_wdata;
wire [31:0] wbu_csr_wdata;
wire wbu_rf_reg_wen;
wire wbu_rf_csr_wen;
wire rf_wbu_done;

wire hazard_raw_stall;
wire [31:0] hazard_ex_wdata = exu_lsu_result_o;
wire [31:0] hazard_ls_wdata = lsu_wbu_wdata_o;
wire [31:0] hazard_wb_wdata = wbu_rf_wdata;

ysyx_24110012_GPR_CSR_File #(4, 32, 12, 32) regfile(
  .clk    (clock),
  .reset  (reset),

  .rf_wen   (wbu_rf_reg_wen),
  .rd_idx   (wbu_rf_idx),
  .rd       (wbu_rf_wdata),
  .rs1_idx  (idu_rs1_idx),
  .rs2_idx  (idu_rs2_idx),
  .rs1      (rf_idu_rs1),
  .rs2      (rf_idu_rs2),
  .rdata_x  (rf_idu_reg_x),

  .csr_wen(wbu_rf_csr_wen),
  .csr_w_idx   (wbu_rf_csr_idx),
  .csr_r_idx   (idu_rf_csr_idx),
  .csr_wdata (wbu_csr_wdata),
  .csr_rdata (rf_idu_csr_rdata)
);

hazard #(
  .ADDR_WIDTH(4),
  .DATA_WIDTH(32)
) my_hazard (
  .rs1_idx   (idu_rs1_idx),
  .rs2_idx   (idu_rs2_idx),
  .rs1_rf    (rf_idu_rs1),
  .rs2_rf    (rf_idu_rs2),

  .ex_valid  (idu_exu_valid_o),
  .ex_wen    (exu_lsu_reg_wen_o),
  .ex_is_load(exu_lsu_wb_from_mem_o),
  .ex_rd_idx (id_ex_packet_o.rd_idx),
  .ex_wdata  (hazard_ex_wdata),

  .ls_valid  (exu_lsu_valid_o),
  .ls_wen    (exu_lsu_reg_wen_i),
  .ls_is_load(exu_lsu_wb_from_mem_i),
  .ls_rd_idx (exu_lsu_rd_idx_i),
  .ls_wdata  (hazard_ls_wdata),

  .wb_valid  (lsu_wbu_valid_o),
  .wb_wen    (wbu_rf_reg_wen),
  .wb_rd_idx (wbu_rf_idx),
  .wb_wdata  (hazard_wb_wdata),

  .rs1_fwd   (hazard_idu_rs1),
  .rs2_fwd   (hazard_idu_rs2),
  .raw_stall (hazard_raw_stall)
);

  wire [31:0] ifu_idu_pc_i;
  wire [31:0] ifu_idu_inst_i;
  wire ifu_idu_cycle_done_i;

  if_id_packet_t if_id_packet_i, if_id_packet_o;

  assign if_id_packet_i.pc = ifu_idu_pc_o;
  assign if_id_packet_i.inst = ifu_idu_inst_o;
  assign if_id_packet_i.cycle_done = ifu_idu_cycle_done_o;
  ppconn #(
  .WIDTH($bits(if_id_packet_i))
  ) if_id_ppconn (
  .clk  (clock),
  .reset(reset),
  .flush(redirect | wbu_fencei),

  .in_valid(ifu_idu_valid_i),
  .in_ready(idu_ifu_ready_o),
  .in_data (if_id_packet_i),

  .out_valid(ifu_idu_valid_o),
  .out_ready(idu_ifu_ready_i),
  .out_data (if_id_packet_o)
  );

  assign ifu_idu_pc_i = if_id_packet_o.pc;
  assign ifu_idu_inst_i = if_id_packet_o.inst;
  assign ifu_idu_cycle_done_i = if_id_packet_o.cycle_done;

  // pipeline stage handshake for idu/exu
  wire idu_exu_valid_i, exu_idu_ready_i;
  wire idu_exu_valid_o, exu_idu_ready_o;
  wire my_idu_exu_valid, my_idu_ifu_ready;

  wire [31:0] idu_exu_pc_o;
  wire [ 6:0] idu_exu_opcode_o;
  wire [ 2:0] idu_exu_func3_o;
  wire [ 6:0] idu_exu_func7_o;
  wire [31:0] idu_exu_rs1_o, idu_exu_rs2_o;
  wire [ 3:0] idu_exu_rd_idx_o;
  wire [31:0] idu_exu_imm_o;
  wire [11:0] idu_exu_csr_idx_o;
  wire [31:0] idu_exu_csr_rdata_o;
  wire idu_exu_ecall_o, idu_exu_mret_o, idu_exu_fencei_o, idu_exu_cycle_done_o;

  /* generate addr for rs1 rs2 rd and
   * func imm values */
  ysyx_24110012_idu my_idu (

  .ifu_idu_pc        (ifu_idu_pc_i),
  .ifu_idu_inst      (ifu_idu_inst_i),
  .ifu_idu_cycle_done(ifu_idu_cycle_done_i),

  .ifu_idu_valid(ifu_idu_valid_o),
  .idu_ifu_ready(my_idu_ifu_ready),

  // get rs values from rf
  .idu_rf_rs1_idx  (idu_rs1_idx),
  .idu_rf_rs2_idx  (idu_rs2_idx),
  .idu_rf_csr_idx  (idu_rf_csr_idx),
  .rf_idu_rs1      (hazard_idu_rs1),
  .rf_idu_rs2      (hazard_idu_rs2),
  .rf_idu_csr_rdata(rf_idu_csr_rdata),

  .idu_exu_pc        (idu_exu_pc_o),
  .idu_exu_opcode    (idu_exu_opcode_o),
  .idu_exu_func3     (idu_exu_func3_o),
  .idu_exu_func7     (idu_exu_func7_o),
  .idu_exu_imm       (idu_exu_imm_o),
  .idu_exu_rs1       (idu_exu_rs1_o),
  .idu_exu_rs2       (idu_exu_rs2_o),
  .idu_exu_rd_idx    (idu_exu_rd_idx_o),
  .idu_exu_csr_idx   (idu_exu_csr_idx_o),
  .idu_exu_csr_rdata (idu_exu_csr_rdata_o),
  .idu_exu_ecall     (idu_exu_ecall_o),
  .idu_exu_mret      (idu_exu_mret_o),
  .idu_exu_fencei    (idu_exu_fencei_o),
  .idu_exu_cycle_done(idu_exu_cycle_done_o),

  .idu_exu_valid(my_idu_exu_valid),
  .exu_idu_ready(exu_idu_ready_o)
  );

  wire priv_stall =
    (idu_exu_valid_o && (id_ex_packet_o.ecall || id_ex_packet_o.mret )) ||
    (exu_lsu_valid_o && (ex_ls_packet_o.ecall || ex_ls_packet_o.mret )) ||
    (lsu_wbu_valid_o && (ls_wb_packet_o.ecall || ls_wb_packet_o.mret ));

  wire hazard_stall = hazard_raw_stall;

  assign idu_ifu_ready_i = my_idu_ifu_ready & !priv_stall & !hazard_stall;
  assign idu_exu_valid_i = my_idu_exu_valid & !priv_stall & !hazard_stall;

  id_ex_packet_t id_ex_packet_i, id_ex_packet_o;

  assign id_ex_packet_i.pc         = idu_exu_pc_o;
`ifndef SYNTHESIS
  assign id_ex_packet_i.inst       = ifu_idu_inst_i;
`endif
  assign id_ex_packet_i.opcode     = idu_exu_opcode_o;
  assign id_ex_packet_i.func3      = idu_exu_func3_o;
  assign id_ex_packet_i.func7      = idu_exu_func7_o;
  assign id_ex_packet_i.imm        = idu_exu_imm_o;
  assign id_ex_packet_i.rs1        = idu_exu_rs1_o;
  assign id_ex_packet_i.rs2        = idu_exu_rs2_o;
  assign id_ex_packet_i.rd_idx     = idu_exu_rd_idx_o;
  assign id_ex_packet_i.csr_idx    = idu_exu_csr_idx_o;
  assign id_ex_packet_i.csr_rdata  = idu_exu_csr_rdata_o;
  assign id_ex_packet_i.ecall      = idu_exu_ecall_o;
  assign id_ex_packet_i.mret       = idu_exu_mret_o;
  assign id_ex_packet_i.fencei     = idu_exu_fencei_o;
  assign id_ex_packet_i.cycle_done = idu_exu_cycle_done_o;

  ppconn #(
  .WIDTH($bits(id_ex_packet_i))
  ) id_ex_ppconn (
  .clk  (clock),
  .reset(reset),
  .flush(redirect | wbu_fencei),

  .in_valid(idu_exu_valid_i),
  .in_ready(exu_idu_ready_o),
  .in_data (id_ex_packet_i),

  .out_valid(idu_exu_valid_o),
  .out_ready(exu_idu_ready_i),
  .out_data (id_ex_packet_o)
  );

  wire [31:0] idu_exu_pc_i;
  wire [ 6:0] idu_exu_opcode_i;
  wire [ 2:0] idu_exu_func3_i;
  wire [ 6:0] idu_exu_func7_i;
  wire [31:0] idu_exu_rs1_i, idu_exu_rs2_i;
  wire [ 3:0] idu_exu_rd_idx_i;
  wire [31:0] idu_exu_imm_i;
  wire [11:0] idu_exu_csr_idx_i;
  wire [31:0] idu_exu_csr_rdata_i;
  wire idu_exu_ecall_i, idu_exu_mret_i, idu_exu_fencei_i, idu_exu_cycle_done_i;

  assign idu_exu_pc_i         = id_ex_packet_o.pc;
  assign idu_exu_opcode_i     = id_ex_packet_o.opcode;
  assign idu_exu_func3_i      = id_ex_packet_o.func3;
  assign idu_exu_func7_i      = id_ex_packet_o.func7;
  assign idu_exu_imm_i        = id_ex_packet_o.imm;
  assign idu_exu_rs1_i        = id_ex_packet_o.rs1;
  assign idu_exu_rs2_i        = id_ex_packet_o.rs2;
  assign idu_exu_rd_idx_i     = id_ex_packet_o.rd_idx;
  assign idu_exu_csr_idx_i    = id_ex_packet_o.csr_idx;
  assign idu_exu_csr_rdata_i  = id_ex_packet_o.csr_rdata;
  assign idu_exu_ecall_i      = id_ex_packet_o.ecall;
  assign idu_exu_mret_i       = id_ex_packet_o.mret;
  assign idu_exu_fencei_i     = id_ex_packet_o.fencei;
  assign idu_exu_cycle_done_i = id_ex_packet_o.cycle_done;

  wire exu_lsu_valid_i, lsu_exu_ready_o;
  wire exu_lsu_reg_wen_o;
  wire [31:0] exu_lsu_rs2_o, exu_lsu_npc_o;
  wire [31:0] exu_lsu_result_o;
  wire [ 3:0] exu_lsu_rd_idx_o;
  wire [11:0] exu_lsu_csr_idx_o;
  wire [31:0] exu_lsu_csr_rdata_o;
  wire exu_lsu_ecall_o, exu_lsu_mret_o, exu_lsu_fencei_o, exu_lsu_cycle_done_o;
  wire exu_lsu_branch_o, exu_lsu_jump_o, exu_lsu_wb_from_mem_o, exu_lsu_csr_wen_o;
  wire exu_lsu_mem_w_o, exu_lsu_mem_r_o;
  wire [2:0] exu_lsu_mem_mask_o;
  wire exu_lsu_mem_sign_ext_o;
  wire [2:0] exu_lsu_func3_o;

  ysyx_24110012_exu my_exu (

  .idu_exu_pc        (idu_exu_pc_i),
  .idu_exu_opcode    (idu_exu_opcode_i),
  .idu_exu_func3     (idu_exu_func3_i),
  .idu_exu_func7     (idu_exu_func7_i),
  .idu_exu_imm       (idu_exu_imm_i),
  .idu_exu_rs1       (idu_exu_rs1_i),
  .idu_exu_rs2       (idu_exu_rs2_i),
  .idu_exu_rd_idx    (idu_exu_rd_idx_i),
  .idu_exu_csr_idx   (idu_exu_csr_idx_i),
  .idu_exu_csr_rdata (idu_exu_csr_rdata_i),
  .idu_exu_ecall     (idu_exu_ecall_i),
  .idu_exu_mret      (idu_exu_mret_i),
  .idu_exu_fencei    (idu_exu_fencei_i),
  .idu_exu_cycle_done(idu_exu_cycle_done_i),

  .idu_exu_valid(idu_exu_valid_o),
  .exu_idu_ready(exu_idu_ready_i),

  .exu_lsu_reg_wen     (exu_lsu_reg_wen_o),
  .exu_lsu_mem_w       (exu_lsu_mem_w_o),
  .exu_lsu_mem_r       (exu_lsu_mem_r_o),
  .exu_lsu_mem_sign_ext(exu_lsu_mem_sign_ext_o),
  .exu_lsu_mem_mask    (exu_lsu_mem_mask_o),
  .exu_lsu_func3       (exu_lsu_func3_o),
  .exu_lsu_result      (exu_lsu_result_o),
  .exu_lsu_rs2         (exu_lsu_rs2_o),
  .exu_lsu_rd_idx      (exu_lsu_rd_idx_o),
  .exu_lsu_csr_idx     (exu_lsu_csr_idx_o),
  .exu_lsu_csr_rdata   (exu_lsu_csr_rdata_o),
  .exu_lsu_ecall       (exu_lsu_ecall_o),
  .exu_lsu_mret        (exu_lsu_mret_o),
  .exu_lsu_fencei      (exu_lsu_fencei_o),
  .exu_lsu_branch      (exu_lsu_branch_o),
  .exu_lsu_jump        (exu_lsu_jump_o),
  .exu_lsu_wb_from_mem (exu_lsu_wb_from_mem_o),
  .exu_lsu_csr_wen     (exu_lsu_csr_wen_o),
  .exu_lsu_npc         (exu_lsu_npc_o),
  .exu_lsu_cycle_done  (exu_lsu_cycle_done_o),

  .exu_lsu_valid(exu_lsu_valid_i),
  .lsu_exu_ready(lsu_exu_ready_o)
  );

  assign exu_redirect = idu_exu_valid_o && lsu_exu_ready_o && (exu_lsu_branch_o || exu_lsu_jump_o);
  assign exu_redirect_pc = exu_lsu_npc_o;

wire lsu_arvalid, lsu_arready, lsu_rvalid, lsu_rready;
wire [31:0] lsu_araddr, lsu_rdata;
wire lsu_awrvalid, lsu_awrready, lsu_wvalid, lsu_wready;
wire [31:0] lsu_awaddr, lsu_wdata;
wire [3:0] lsu_wstrb;
wire [1:0] lsu_bresp;
wire [2:0] lsu_arsize, lsu_awsize;
wire lsu_bvalid, lsu_bready;

  ex_ls_packet_t ex_ls_packet_i, ex_ls_packet_o;

`ifndef SYNTHESIS
  assign ex_ls_packet_i.pc         = idu_exu_pc_i;
  assign ex_ls_packet_i.inst       = id_ex_packet_o.inst;
`endif
  assign ex_ls_packet_i.reg_wen = exu_lsu_reg_wen_o;
  assign ex_ls_packet_i.mem_w = exu_lsu_mem_w_o;
  assign ex_ls_packet_i.mem_r = exu_lsu_mem_r_o;
  assign ex_ls_packet_i.mem_sign_ext = exu_lsu_mem_sign_ext_o;
  assign ex_ls_packet_i.mem_mask = exu_lsu_mem_mask_o;
  assign ex_ls_packet_i.func3 = exu_lsu_func3_o;
  assign ex_ls_packet_i.result = exu_lsu_result_o;
  assign ex_ls_packet_i.rs2 = exu_lsu_rs2_o;
  assign ex_ls_packet_i.rd_idx = exu_lsu_rd_idx_o;
  assign ex_ls_packet_i.csr_idx = exu_lsu_csr_idx_o;
  assign ex_ls_packet_i.csr_rdata = exu_lsu_csr_rdata_o;
  assign ex_ls_packet_i.ecall = exu_lsu_ecall_o;
  assign ex_ls_packet_i.mret = exu_lsu_mret_o;
  assign ex_ls_packet_i.fencei = exu_lsu_fencei_o;
  assign ex_ls_packet_i.branch = exu_lsu_branch_o;
  assign ex_ls_packet_i.jump = exu_lsu_jump_o;
  assign ex_ls_packet_i.wb_from_mem = exu_lsu_wb_from_mem_o;
  assign ex_ls_packet_i.csr_wen = exu_lsu_csr_wen_o;
  assign ex_ls_packet_i.npc = exu_lsu_npc_o;
  assign ex_ls_packet_i.cycle_done = exu_lsu_cycle_done_o;

  ppconn #(
  .WIDTH($bits(ex_ls_packet_i))
  ) ex_ls_ppconn (
  .clk  (clock),
  .reset(reset),
  .flush(wbu_redirect | wbu_fencei),

  .in_valid(exu_lsu_valid_i),
  .in_ready(lsu_exu_ready_o),
  .in_data (ex_ls_packet_i),

  .out_valid(exu_lsu_valid_o),
  .out_ready(lsu_exu_ready_i),
  .out_data (ex_ls_packet_o)
  );

  wire exu_lsu_valid_o, lsu_exu_ready_i;
  wire exu_lsu_reg_wen_i;
  wire [31:0] exu_lsu_rs2_i, exu_lsu_npc_i;
  wire [31:0] exu_lsu_result_i;
  wire [ 3:0] exu_lsu_rd_idx_i;
  wire [11:0] exu_lsu_csr_idx_i;
  wire [31:0] exu_lsu_csr_rdata_i;
  wire exu_lsu_ecall_i, exu_lsu_mret_i, exu_lsu_fencei_i, exu_lsu_cycle_done_i;
  wire exu_lsu_branch_i, exu_lsu_jump_i, exu_lsu_wb_from_mem_i, exu_lsu_csr_wen_i;
  wire exu_lsu_mem_w_i, exu_lsu_mem_r_i;
  wire [2:0] exu_lsu_mem_mask_i;
  wire exu_lsu_mem_sign_ext_i;
  wire [2:0] exu_lsu_func3_i;

  assign exu_lsu_reg_wen_i = ex_ls_packet_o.reg_wen;
  assign exu_lsu_mem_w_i = ex_ls_packet_o.mem_w;
  assign exu_lsu_mem_r_i = ex_ls_packet_o.mem_r;
  assign exu_lsu_mem_sign_ext_i = ex_ls_packet_o.mem_sign_ext;
  assign exu_lsu_mem_mask_i = ex_ls_packet_o.mem_mask;
  assign exu_lsu_func3_i = ex_ls_packet_o.func3;
  assign exu_lsu_result_i = ex_ls_packet_o.result;
  assign exu_lsu_rs2_i = ex_ls_packet_o.rs2;
  assign exu_lsu_rd_idx_i = ex_ls_packet_o.rd_idx;
  assign exu_lsu_csr_idx_i = ex_ls_packet_o.csr_idx;
  assign exu_lsu_csr_rdata_i = ex_ls_packet_o.csr_rdata;
  assign exu_lsu_ecall_i = ex_ls_packet_o.ecall;
  assign exu_lsu_mret_i = ex_ls_packet_o.mret;
  assign exu_lsu_fencei_i = ex_ls_packet_o.fencei;
  assign exu_lsu_branch_i = ex_ls_packet_o.branch;
  assign exu_lsu_jump_i = ex_ls_packet_o.jump;
  assign exu_lsu_wb_from_mem_i = ex_ls_packet_o.wb_from_mem;
  assign exu_lsu_csr_wen_i = ex_ls_packet_o.csr_wen;
  assign exu_lsu_npc_i = ex_ls_packet_o.npc;
  assign exu_lsu_cycle_done_i = ex_ls_packet_o.cycle_done;

  wire lsu_wbu_valid_i, wbu_lsu_ready_o;
  wire lsu_wbu_valid_o, wbu_lsu_ready_i;
  wire [31:0] lsu_wbu_wdata_o, lsu_wbu_npc_o, lsu_wbu_csr_rdata_o;
  wire [ 4:0] lsu_wbu_rd_idx_o;
  wire [11:0] lsu_wbu_csr_idx_o;
  wire [ 2:0] lsu_wbu_func3_o;
  wire lsu_wbu_reg_wen_o, lsu_wbu_ecall_o, lsu_wbu_mret_o, lsu_wbu_fencei_o, lsu_wbu_cycle_done_o;
  wire lsu_wbu_branch_o, lsu_wbu_jump_o, lsu_wbu_csr_wen_o;

  ysyx_24110012_lsu my_lsu (
  .clk(clock),

  .exu_lsu_reg_wen     (exu_lsu_reg_wen_i),
  .exu_lsu_mem_w       (exu_lsu_mem_w_i),
  .exu_lsu_mem_r       (exu_lsu_mem_r_i),
  .exu_lsu_mem_sign_ext(exu_lsu_mem_sign_ext_i),
  .exu_lsu_mem_mask    (exu_lsu_mem_mask_i),
  .exu_lsu_mem_addr    (exu_lsu_result_i),
  .exu_lsu_func3       (exu_lsu_func3_i),
  .exu_lsu_result      (exu_lsu_result_i),
  .exu_lsu_mem_wdata   (exu_lsu_rs2_i),
  .exu_lsu_rd_idx      (exu_lsu_rd_idx_i),
  .exu_lsu_csr_idx     (exu_lsu_csr_idx_i),
  .exu_lsu_csr_rdata   (exu_lsu_csr_rdata_i),
  .exu_lsu_ecall       (exu_lsu_ecall_i),
  .exu_lsu_mret        (exu_lsu_mret_i),
  .exu_lsu_fencei      (exu_lsu_fencei_i),
  .exu_lsu_branch      (exu_lsu_branch_i),
  .exu_lsu_jump        (exu_lsu_jump_i),
  .exu_lsu_wb_from_mem (exu_lsu_wb_from_mem_i),
  .exu_lsu_csr_wen     (exu_lsu_csr_wen_i),
  .exu_lsu_npc         (exu_lsu_npc_i),
  .exu_lsu_cycle_done  (exu_lsu_cycle_done_i),

  .exu_lsu_valid(exu_lsu_valid_o),
  .lsu_exu_ready(lsu_exu_ready_i),

  .lsu_wbu_reg_wen    (lsu_wbu_reg_wen_o),
  .lsu_wbu_func3      (lsu_wbu_func3_o),
  .lsu_wbu_wdata      (lsu_wbu_wdata_o),
  .lsu_wbu_rd_idx     (lsu_wbu_rd_idx_o),
  .lsu_wbu_csr_idx    (lsu_wbu_csr_idx_o),
  .lsu_wbu_csr_rdata  (lsu_wbu_csr_rdata_o),
  .lsu_wbu_ecall      (lsu_wbu_ecall_o),
  .lsu_wbu_mret       (lsu_wbu_mret_o),
  .lsu_wbu_fencei     (lsu_wbu_fencei_o),
  .lsu_wbu_branch     (lsu_wbu_branch_o),
  .lsu_wbu_jump       (lsu_wbu_jump_o),
  .lsu_wbu_csr_wen    (lsu_wbu_csr_wen_o),
  .lsu_wbu_npc        (lsu_wbu_npc_o),
  .lsu_wbu_cycle_done (lsu_wbu_cycle_done_o),

  .lsu_wbu_valid(lsu_wbu_valid_i),
  .wbu_lsu_ready(wbu_lsu_ready_o),

  .araddr (lsu_araddr),
  .arvalid(lsu_arvalid),
  .arsize (lsu_arsize),
  .arready(lsu_arready),
  .rdata  (lsu_rdata),
  .rvalid (lsu_rvalid),
  .rready (lsu_rready),
  .awaddr (lsu_awaddr),
  .awvalid(lsu_awrvalid),
  .awsize (lsu_awsize),
  .awready(lsu_awrready),
  .wdata  (lsu_wdata),
  .wstrb  (lsu_wstrb),
  .wvalid (lsu_wvalid),
  .wready (lsu_wready),
  .bresp  (lsu_bresp),
  .bvalid (lsu_bvalid),
  .bready (lsu_bready)
  );

  ls_wb_packet_t ls_wb_packet_i, ls_wb_packet_o;

`ifndef SYNTHESIS
  assign ls_wb_packet_i.pc         = ex_ls_packet_o.pc;
  assign ls_wb_packet_i.inst       = ex_ls_packet_o.inst;
`endif
  assign ls_wb_packet_i.reg_wen     = lsu_wbu_reg_wen_o;
  assign ls_wb_packet_i.func3       = lsu_wbu_func3_o;
  assign ls_wb_packet_i.wdata       = lsu_wbu_wdata_o;
  assign ls_wb_packet_i.rd_idx      = lsu_wbu_rd_idx_o;
  assign ls_wb_packet_i.csr_idx     = lsu_wbu_csr_idx_o;
  assign ls_wb_packet_i.csr_rdata   = lsu_wbu_csr_rdata_o;
  assign ls_wb_packet_i.ecall       = lsu_wbu_ecall_o;
  assign ls_wb_packet_i.mret        = lsu_wbu_mret_o;
  assign ls_wb_packet_i.fencei      = lsu_wbu_fencei_o;
  assign ls_wb_packet_i.branch      = lsu_wbu_branch_o;
  assign ls_wb_packet_i.jump        = lsu_wbu_jump_o;
  assign ls_wb_packet_i.csr_wen     = lsu_wbu_csr_wen_o;
  assign ls_wb_packet_i.npc         = lsu_wbu_npc_o;
  assign ls_wb_packet_i.cycle_done  = lsu_wbu_cycle_done_o;

  ppconn #(
  .WIDTH($bits(ls_wb_packet_i))
  ) ls_wb_ppconn (
  .clk  (clock),
  .reset(reset),
  .flush(wbu_redirect | wbu_fencei),

  .in_valid(lsu_wbu_valid_i),
  .in_ready(wbu_lsu_ready_o),
  .in_data (ls_wb_packet_i),

  .out_valid(lsu_wbu_valid_o),
  .out_ready(wbu_lsu_ready_i),
  .out_data (ls_wb_packet_o)
  );

  wire [31:0] lsu_wbu_wdata_i, lsu_wbu_npc_i, lsu_wbu_csr_rdata_i;
  wire [ 4:0] lsu_wbu_rd_idx_i;
  wire [11:0] lsu_wbu_csr_idx_i;
  wire [ 2:0] lsu_wbu_func3_i;
  wire lsu_wbu_reg_wen_i, lsu_wbu_ecall_i, lsu_wbu_mret_i, lsu_wbu_fencei_i, lsu_wbu_cycle_done_i;
  wire lsu_wbu_branch_i, lsu_wbu_jump_i, lsu_wbu_csr_wen_i;

  assign lsu_wbu_reg_wen_i = ls_wb_packet_o.reg_wen;
  assign lsu_wbu_func3_i = ls_wb_packet_o.func3;
  assign lsu_wbu_wdata_i = ls_wb_packet_o.wdata;
  assign lsu_wbu_rd_idx_i = ls_wb_packet_o.rd_idx;
  assign lsu_wbu_csr_idx_i = ls_wb_packet_o.csr_idx;
  assign lsu_wbu_csr_rdata_i = ls_wb_packet_o.csr_rdata;
  assign lsu_wbu_ecall_i = ls_wb_packet_o.ecall;
  assign lsu_wbu_mret_i = ls_wb_packet_o.mret;
  assign lsu_wbu_fencei_i = ls_wb_packet_o.fencei;
  assign lsu_wbu_branch_i = ls_wb_packet_o.branch;
  assign lsu_wbu_jump_i = ls_wb_packet_o.jump;
  assign lsu_wbu_csr_wen_i = ls_wb_packet_o.csr_wen;
  assign lsu_wbu_npc_i = ls_wb_packet_o.npc;
  assign lsu_wbu_cycle_done_i = ls_wb_packet_o.cycle_done;

ysyx_24110012_wbu my_wbu(
    .clk(clock),
    .reset(reset),

    .lsu_wbu_reg_wen(lsu_wbu_reg_wen_i),
    .lsu_wbu_func3(lsu_wbu_func3_i),
    .lsu_wbu_wdata(lsu_wbu_wdata_i),
    .lsu_wbu_rd_idx(lsu_wbu_rd_idx_i),
    .lsu_wbu_csr_idx(lsu_wbu_csr_idx_i),
    .lsu_wbu_csr_rdata(lsu_wbu_csr_rdata_i),
    .lsu_wbu_ecall(lsu_wbu_ecall_i),
    .lsu_wbu_mret(lsu_wbu_mret_i),
    .lsu_wbu_fencei(lsu_wbu_fencei_i),
    .lsu_wbu_branch(lsu_wbu_branch_i),
    .lsu_wbu_jump(lsu_wbu_jump_i),
    .lsu_wbu_csr_wen(lsu_wbu_csr_wen_i),
    .lsu_wbu_npc(lsu_wbu_npc_i),
    .lsu_wbu_cycle_done(lsu_wbu_cycle_done_i),

    .lsu_wbu_valid(lsu_wbu_valid_o),
    .wbu_lsu_ready(wbu_lsu_ready_i),

    .wbu_rf_wdata(wbu_rf_wdata),
    .wbu_csr_wdata(wbu_csr_wdata),
    .wbu_rf_idx(wbu_rf_idx),
    .wbu_rf_csr_idx(wbu_rf_csr_idx),
    .wbu_rf_csr_wen(wbu_rf_csr_wen),
    .wbu_rf_reg_wen(wbu_rf_reg_wen),
    .wbu_ifu_pc(wbu_ifu_npc),
    .wbu_redirect(wbu_redirect),
    .wbu_fencei(wbu_fencei),
    .wbu_cycle_done(wbu_cycle_done),

    .icache_flush_done(icache_flush_done)
);

`ifndef SYNTHESIS
  localparam [31:0] EBREAK = 32'h00100073;
  reg [31:0] done_inst;
  reg [31:0] done_pc;
  reg [31:0] done_npc;
  always @(posedge clock) begin
    if (lsu_wbu_valid_o && wbu_lsu_ready_i) begin
      done_inst <= ls_wb_packet_o.inst;
      done_pc <= ls_wb_packet_o.pc;
      if (ls_wb_packet_o.ecall || ls_wb_packet_o.mret) begin
        done_npc <= ls_wb_packet_o.csr_rdata;
      end else begin
        done_npc <= ls_wb_packet_o.npc + 32'd4;
      end
      if (ls_wb_packet_o.inst == EBREAK) begin
        ebreak_catch(ls_wb_packet_o.pc, rf_idu_reg_x);
      end
    end
  end
`endif

// AXI arbiter
parameter NUM_MASTERS = 2'b10;
parameter MASTER_INDEX_WIDTH = NUM_MASTERS == 1 ? 1 : $clog2(NUM_MASTERS);
wire [MASTER_INDEX_WIDTH-1:0] mem_r_grant;

wire [NUM_MASTERS-1:0] m_arb_awvalid, m_arb_awready, m_arb_wvalid, m_arb_wready, m_arb_bvalid, m_arb_bready;
wire [NUM_MASTERS-1:0] [1:0] m_arb_bresp;
wire [NUM_MASTERS-1:0] [31:0] m_arb_awaddr, m_arb_wdata;
wire [NUM_MASTERS-1:0] [3:0] m_arb_wstrb;
wire [NUM_MASTERS-1:0] m_arb_arvalid, m_arb_arready, m_arb_rvalid, m_arb_rready;
wire [NUM_MASTERS-1:0] [31:0] m_arb_araddr, m_arb_rdata;
wire [NUM_MASTERS-1:0] [2:0] m_arb_arsize, m_arb_awsize;
wire [NUM_MASTERS-1:0] [1:0] m_arb_arburst;
wire [NUM_MASTERS-1:0] [7:0] m_arb_arlen;
wire [NUM_MASTERS-1:0] m_arb_rlast;

assign m_arb_awvalid = {ifu_awvalid, lsu_awrvalid};
assign m_arb_awsize = {ifu_awsize, lsu_awsize};
assign m_arb_awaddr = {ifu_awaddr, lsu_awaddr};
assign {ifu_awready, lsu_awrready} = m_arb_awready;
assign m_arb_wvalid = {ifu_wvalid, lsu_wvalid};
assign m_arb_wdata = {ifu_wdata, lsu_wdata};
assign m_arb_wstrb = {ifu_wstrb, lsu_wstrb};
assign {ifu_wready, lsu_wready} = m_arb_wready;
assign {ifu_bvalid, lsu_bvalid} = m_arb_bvalid;
assign {ifu_bresp, lsu_bresp} = m_arb_bresp;
assign m_arb_bready = {ifu_bready, lsu_bready};

// read channel go with icache first
assign m_arb_arvalid = {icache_arvalid, lsu_arvalid};
assign m_arb_arsize = {icache_arsize, lsu_arsize};
assign m_arb_arburst = {icache_arburst, 2'b00}; // Only icache uses burst
assign m_arb_arlen = {icache_arlen, 8'b0}; // Only icache uses burst
assign icache_rlast = m_arb_rlast[1];
assign {icache_arready, lsu_arready} = m_arb_arready;
assign m_arb_araddr = {icache_araddr, lsu_araddr};
assign {icache_rvalid, lsu_rvalid} = m_arb_rvalid;
assign m_arb_rready = {icache_rready, lsu_rready};
assign {icache_rdata, lsu_rdata} = m_arb_rdata;

wire s_arb_awvalid, s_arb_awready, s_arb_wvalid, s_arb_wready, s_arb_bvalid, s_arb_bready;
wire [1:0] s_arb_bresp;
wire [31:0] s_arb_awaddr, s_arb_wdata;
wire [3:0] s_arb_wstrb;
wire [2:0] s_arb_awsize, s_arb_arsize;
wire [1:0] s_arb_arburst;
wire [7:0] s_arb_arlen;
wire s_arb_arvalid, s_arb_arready, s_arb_rvalid, s_arb_rready, s_arb_rlast;
wire [31:0] s_arb_araddr, s_arb_rdata;

ysyx_24110012_arbiter #(32, 32, 2) mem_arbiter(
  .clk(clock),
  .reset(reset),
  .mem_r_grant(mem_r_grant),
  .m_awvalid(m_arb_awvalid),
  .m_awsize(m_arb_awsize),
  .m_awready(m_arb_awready),
  .m_awaddr(m_arb_awaddr),
  .m_wvalid(m_arb_wvalid),
  .m_wready(m_arb_wready),
  .m_wdata(m_arb_wdata),
  .m_wstrb(m_arb_wstrb),
  .m_bresp(m_arb_bresp),
  .m_bvalid(m_arb_bvalid),
  .m_bready(m_arb_bready),
  .m_arvalid(m_arb_arvalid),
  .m_arsize(m_arb_arsize),
  .m_arburst(m_arb_arburst),
  .m_arlen(m_arb_arlen),
  .m_arready(m_arb_arready),
  .m_araddr(m_arb_araddr),
  .m_rvalid(m_arb_rvalid),
  .m_rready(m_arb_rready),
  .m_rdata(m_arb_rdata),
  .m_rlast(m_arb_rlast),
  .s_awvalid(s_arb_awvalid),
  .s_awsize(s_arb_awsize),
  .s_awready(s_arb_awready),
  .s_awaddr(s_arb_awaddr),
  .s_wvalid(s_arb_wvalid),
  .s_wready(s_arb_wready),
  .s_wdata(s_arb_wdata),
  .s_wstrb(s_arb_wstrb),
  .s_bresp(s_arb_bresp),
  .s_bvalid(s_arb_bvalid),
  .s_bready(s_arb_bready),
  .s_arvalid(s_arb_arvalid),
  .s_arsize(s_arb_arsize),
  .s_arburst(s_arb_arburst),
  .s_arlen(s_arb_arlen),
  .s_arready(s_arb_arready),
  .s_araddr(s_arb_araddr),
  .s_rvalid(s_arb_rvalid),
  .s_rready(s_arb_rready),
  .s_rdata(s_arb_rdata),
  .s_rlast(s_arb_rlast)
);

// let SOC to handle it
/*********************
module top (
    input clock,
    input reset
);

// XBAR
parameter NUM_XBAR_MASTERS = 2'b11;
wire [NUM_XBAR_MASTERS-1:0] m_xbar_awvalid, m_xbar_awready, m_xbar_wvalid, m_xbar_wready, m_xbar_bvalid, m_xbar_bready;
wire [NUM_XBAR_MASTERS-1:0] [1:0] m_xbar_bresp;
wire [NUM_XBAR_MASTERS-1:0] [31:0] m_xbar_awaddr, m_xbar_wdata;
wire [NUM_XBAR_MASTERS-1:0] [3:0] m_xbar_wstrb;
wire [NUM_XBAR_MASTERS-1:0] m_xbar_arvalid, m_xbar_arready, m_xbar_rvalid, m_xbar_rready;
wire [NUM_XBAR_MASTERS-1:0] [31:0] m_xbar_araddr, m_xbar_rdata;
// XBAR end

// AXI master
wire io_m_awvalid, io_m_awready, io_m_wvalid, io_m_wready, io_m_wlast, io_m_bvalid, io_m_bready;
wire [1:0] io_m_bresp, io_m_awburst;
wire [31:0] io_m_awaddr, io_m_wdata;
wire [3:0] io_m_awid, io_m_wstrb, io_m_bid;
wire [7:0] io_m_awlen;
wire [2:0] io_m_awsize;
wire io_m_arvalid, io_m_arready, io_m_rvalid, io_m_rready;
wire [3:0] io_m_arid, io_m_rid;
wire [7:0] io_m_arlen;
wire [2:0] io_m_arsize;
wire io_m_rlast;
wire [1:0] io_m_rresp, io_m_arburst;
wire [31:0] io_m_araddr, io_m_rdata;
// AXI master end

// AXI slave unused signals
wire        unused_awready;
wire        unused_wready;
wire        unused_bvalid;
wire [1:0]  unused_bresp;
wire [3:0]  unused_bid;
wire        unused_arready;
wire        unused_rvalid;
wire [1:0]  unused_rresp;
wire [31:0] unused_rdata;
wire        unused_rlast;
wire [3:0]  unused_rid;
// AXI slave unused signals end

ysyx_24110012 u_cpu (
    .clock(clock),
    .reset(reset),
    .io_interrupt(1'b0),

    // AXI4 Master Interface
    // Write Address Channel
    .io_master_awready(io_m_awready),
    .io_master_awvalid(io_m_awvalid),
    .io_master_awaddr(io_m_awaddr),
    .io_master_awid(io_m_awid),
    .io_master_awlen(io_m_awlen),
    .io_master_awsize(io_m_awsize),
    .io_master_awburst(io_m_awburst),

    // Write Data Channel
    .io_master_wready(io_m_wready),
    .io_master_wvalid(io_m_wvalid),
    .io_master_wdata(io_m_wdata),
    .io_master_wstrb(io_m_wstrb),
    .io_master_wlast(io_m_wlast),

    // Write Response Channel
    .io_master_bready(io_m_bready),
    .io_master_bvalid(io_m_bvalid),
    .io_master_bresp(io_m_bresp),
    .io_master_bid(io_m_bid),

    // Read Address Channel
    .io_master_arready(io_m_arready),
    .io_master_arvalid(io_m_arvalid),
    .io_master_araddr(io_m_araddr),
    .io_master_arid(io_m_arid),
    .io_master_arlen(io_m_arlen),
    .io_master_arsize(io_m_arsize),
    .io_master_arburst(io_m_arburst),

    // Read Data Channel
    .io_master_rready(io_m_rready),
    .io_master_rvalid(io_m_rvalid),
    .io_master_rresp(io_m_rresp),
    .io_master_rdata(io_m_rdata),
    .io_master_rlast(io_m_rlast),
    .io_master_rid(io_m_rid),

    // AXI4 m Interface
    // Write Address Channel
    .io_slave_awready(unused_awready),
    .io_slave_awvalid(1'b0),
    .io_slave_awaddr(32'b0),
    .io_slave_awid(4'b0),
    .io_slave_awlen(8'b0),
    .io_slave_awsize(3'b0),
    .io_slave_awburst(2'b0),

    // Write Data Channel
    .io_slave_wready(unused_wready),
    .io_slave_wvalid(1'b0),
    .io_slave_wdata(32'b0),
    .io_slave_wstrb(4'b0),
    .io_slave_wlast(1'b0),
    // Write Response Channel
    .io_slave_bready(1'b0),
    .io_slave_bvalid(unused_bvalid),
    .io_slave_bresp(unused_bresp),
    .io_slave_bid(unused_bid),
    // Read Address Channel
    .io_slave_arready(unused_arready),
    .io_slave_arvalid(1'b0),
    .io_slave_araddr(32'b0),
    .io_slave_arid(4'b0),
    .io_slave_arlen(8'b0),
    .io_slave_arsize(3'b0),
    .io_slave_arburst(2'b0),
    // Read Data Channel
    .io_slave_rready(1'b0),
    .io_slave_rvalid(unused_rvalid),
    .io_slave_rresp(unused_rresp),
    .io_slave_rdata(unused_rdata),
    .io_slave_rlast(unused_rlast),
    .io_slave_rid(unused_rid)
);

ysyx_24110012_xbar #(32, 32, 3) u_xbar(
  .clk(clock),
  .s_awvalid(io_m_awvalid),
  .s_awready(io_m_awready),
  .s_awaddr(io_m_awaddr),
  .s_wvalid(io_m_wvalid),
  .s_wready(io_m_wready),
  .s_wdata(io_m_wdata),
  .s_wstrb(io_m_wstrb),
  .s_bresp(io_m_bresp),
  .s_bvalid(io_m_bvalid),
  .s_bready(io_m_bready),
  .s_arvalid(io_m_arvalid),
  .s_arready(io_m_arready),
  .s_araddr(io_m_araddr),
  .s_rvalid(io_m_rvalid),
  .s_rready(io_m_rready),
  .s_rdata(io_m_rdata),
  .m_awvalid(m_xbar_awvalid),
  .m_awready(m_xbar_awready),
  .m_awaddr(m_xbar_awaddr),
  .m_wvalid(m_xbar_wvalid),
  .m_wready(m_xbar_wready),
  .m_wdata(m_xbar_wdata),
  .m_wstrb(m_xbar_wstrb),
  .m_bresp(m_xbar_bresp),
  .m_bvalid(m_xbar_bvalid),
  .m_bready(m_xbar_bready),
  .m_arvalid(m_xbar_arvalid),
  .m_arready(m_xbar_arready),
  .m_araddr(m_xbar_araddr),
  .m_rvalid(m_xbar_rvalid),
  .m_rready(m_xbar_rready),
  .m_rdata(m_xbar_rdata)
);

mem my_mem(
    .clk(clock),
    .araddr(m_xbar_araddr[0]),
    .arvalid(m_xbar_arvalid[0]),
    .arready(m_xbar_arready[0]),
    .rdata(m_xbar_rdata[0]),
    .rvalid(m_xbar_rvalid[0]),
    .rready(m_xbar_rready[0]),
    .awaddr(m_xbar_awaddr[0]),
    .awvalid(m_xbar_awvalid[0]),
    .awready(m_xbar_awready[0]),
    .wdata(m_xbar_wdata[0]),
    .wstrb(m_xbar_wstrb[0]),
    .wvalid(m_xbar_wvalid[0]),
    .wready(m_xbar_wready[0]),
    .bresp(m_xbar_bresp[0]),
    .bvalid(m_xbar_bvalid[0]),
    .bready(m_xbar_bready[0])
);

ysyx_24110012_vuart u_vuart(
    .clk(clock),
    .araddr(m_xbar_araddr[1]),
    .arvalid(m_xbar_arvalid[1]),
    .arready(m_xbar_arready[1]),
    .rdata(m_xbar_rdata[1]),
    .rvalid(m_xbar_rvalid[1]),
    .rready(m_xbar_rready[1]),
    .awaddr(m_xbar_awaddr[1]),
    .awvalid(m_xbar_awvalid[1]),
    .awready(m_xbar_awready[1]),
    .wdata(m_xbar_wdata[1]),
    .wstrb(m_xbar_wstrb[1]),
    .wvalid(m_xbar_wvalid[1]),
    .wready(m_xbar_wready[1]),
    .bresp(m_xbar_bresp[1]),
    .bvalid(m_xbar_bvalid[1]),
    .bready(m_xbar_bready[1])
);
*********************/
  // XBAR
  parameter NUM_XBAR_MASTERS = 2'b10;
  wire [NUM_XBAR_MASTERS-1:0] m_xbar_awvalid, m_xbar_awready, m_xbar_wvalid, m_xbar_wready,
  m_xbar_bvalid, m_xbar_bready;
  wire [NUM_XBAR_MASTERS-1:0][1:0] m_xbar_bresp;
  wire [NUM_XBAR_MASTERS-1:0][31:0] m_xbar_awaddr, m_xbar_wdata;
  wire [NUM_XBAR_MASTERS-1:0][3:0] m_xbar_wstrb;
  wire [NUM_XBAR_MASTERS-1:0][2:0] m_xbar_awsize, m_xbar_arsize;
  wire [NUM_XBAR_MASTERS-1:0] m_xbar_arvalid, m_xbar_arready, m_xbar_rvalid, m_xbar_rready;
  wire [NUM_XBAR_MASTERS-1:0][31:0] m_xbar_araddr, m_xbar_rdata;
  wire [NUM_XBAR_MASTERS-1:0][1:0] m_xbar_arburst;
  wire [NUM_XBAR_MASTERS-1:0][7:0] m_xbar_arlen;
  wire [NUM_XBAR_MASTERS-1:0] m_xbar_rlast;
  // XBAR end

  // write address channel
  assign m_xbar_awready[0] = io_master_awready;
  assign io_master_awvalid = m_xbar_awvalid[0];
  assign io_master_awaddr  = m_xbar_awaddr[0];
  assign io_master_awid    = 4'b0;
  assign io_master_awlen   = 8'b0;
  assign io_master_awsize  = m_xbar_awsize[0];
  assign io_master_awburst = 2'b00;

  // write data channel
  assign m_xbar_wready[0]  = io_master_wready;
  assign io_master_wvalid  = m_xbar_wvalid[0];
  assign io_master_wdata   = m_xbar_wdata[0];
  assign io_master_wstrb   = m_xbar_wstrb[0];
  assign io_master_wlast   = 1'b1;

  // write response channel
  assign io_master_bready  = m_xbar_bready[0];
  assign m_xbar_bvalid[0]  = io_master_bvalid;
  assign m_xbar_bresp[0]   = io_master_bresp;

  // read address channel
  assign m_xbar_arready[0] = io_master_arready;
  assign io_master_arvalid = m_xbar_arvalid[0];
  assign io_master_araddr  = m_xbar_araddr[0];
  assign io_master_arid    = 4'b0;
  assign io_master_arlen   = m_xbar_arlen[0];
  assign io_master_arsize  = m_xbar_arsize[0];
  assign io_master_arburst = m_xbar_arburst[0];

  // read data channel
  assign io_master_rready  = m_xbar_rready[0];
  assign m_xbar_rvalid[0]  = io_master_rvalid;
  assign m_xbar_rdata[0]   = io_master_rdata;
  assign m_xbar_rlast[0]   = io_master_rlast;
  // AXI arbiter end

  ysyx_24110012_xbar #(32, 32, 2) u_xbar (
  .clk      (clock),
  .s_awvalid(s_arb_awvalid),
  .s_awready(s_arb_awready),
  .s_awaddr (s_arb_awaddr),
  .s_awsize (s_arb_awsize),
  .s_wvalid (s_arb_wvalid),
  .s_wready (s_arb_wready),
  .s_wdata  (s_arb_wdata),
  .s_wstrb  (s_arb_wstrb),
  .s_bresp  (s_arb_bresp),
  .s_bvalid (s_arb_bvalid),
  .s_bready (s_arb_bready),
  .s_arvalid(s_arb_arvalid),
  .s_arsize (s_arb_arsize),
  .s_arburst(s_arb_arburst),
  .s_arlen  (s_arb_arlen),
  .s_arready(s_arb_arready),
  .s_araddr (s_arb_araddr),
  .s_rvalid (s_arb_rvalid),
  .s_rready (s_arb_rready),
  .s_rdata  (s_arb_rdata),
  .s_rlast  (s_arb_rlast),
  .m_awvalid(m_xbar_awvalid),
  .m_awready(m_xbar_awready),
  .m_awaddr (m_xbar_awaddr),
  .m_awsize (m_xbar_awsize),
  .m_wvalid (m_xbar_wvalid),
  .m_wready (m_xbar_wready),
  .m_wdata  (m_xbar_wdata),
  .m_wstrb  (m_xbar_wstrb),
  .m_bresp  (m_xbar_bresp),
  .m_bvalid (m_xbar_bvalid),
  .m_bready (m_xbar_bready),
  .m_arvalid(m_xbar_arvalid),
  .m_arready(m_xbar_arready),
  .m_araddr (m_xbar_araddr),
  .m_arsize (m_xbar_arsize),
  .m_arburst(m_xbar_arburst),
  .m_arlen  (m_xbar_arlen),
  .m_rvalid (m_xbar_rvalid),
  .m_rready (m_xbar_rready),
  .m_rdata  (m_xbar_rdata),
  .m_rlast  (m_xbar_rlast)
  );

  ysyx_24110012_vclint u_vclint (
  .clk    (clock),
  .araddr (m_xbar_araddr[1]),
  .arvalid(m_xbar_arvalid[1]),
  .arready(m_xbar_arready[1]),
  .rdata  (m_xbar_rdata[1]),
  .rvalid (m_xbar_rvalid[1]),
  .rready (m_xbar_rready[1]),
  .awaddr (m_xbar_awaddr[1]),
  .awvalid(m_xbar_awvalid[1]),
  .awready(m_xbar_awready[1]),
  .wdata  (m_xbar_wdata[1]),
  .wstrb  (m_xbar_wstrb[1]),
  .wvalid (m_xbar_wvalid[1]),
  .wready (m_xbar_wready[1]),
  .bresp  (m_xbar_bresp[1]),
  .bvalid (m_xbar_bvalid[1]),
  .bready (m_xbar_bready[1])
  );

// idu/exu is combinational, so we calc their cnt here.
`ifdef PERF
`ifndef SYNTHESIS
  reg [63:0] lsu_cnt = 64'b0;
  reg [63:0] ifu_cnt = 64'b0;
  reg [63:0] idu_cnt = 64'b0;
  reg [63:0] idu_calc_cnt = 64'b0;
  reg [63:0] idu_mem_cnt = 64'b0;
  reg [63:0] idu_csr_cnt = 64'b0;
  reg [63:0] idu_br_cnt = 64'b0;
  reg [63:0] exu_cnt = 64'b0;
  reg [63:0] redirect_cnt = 64'b0;
  reg [63:0] exu_redirect_cnt = 64'b0;
  reg [63:0] branch_redirect_cnt = 64'b0;
  reg [63:0] jump_redirect_cnt = 64'b0;
  reg [63:0] jal_redirect_cnt = 64'b0;
  reg [63:0] jalr_redirect_cnt = 64'b0;
  reg [63:0] wbu_redirect_cnt = 64'b0;
  reg [63:0] redirect_cycles = 64'b0;
  reg [63:0] exu_redirect_cycles = 64'b0;
  reg [63:0] branch_redirect_cycles = 64'b0;
  reg [63:0] jump_redirect_cycles = 64'b0;
  reg [63:0] jal_redirect_cycles = 64'b0;
  reg [63:0] jalr_redirect_cycles = 64'b0;
  reg [63:0] wbu_redirect_cycles = 64'b0;
  reg        exu_redirect_busy = 1'b0;
  reg [1:0]  exu_redirect_type = 2'b00;
  reg        wbu_redirect_busy = 1'b0;
  reg [63:0] hazard_event_cnt = 64'b0;
  reg [63:0] hazard_cycles = 64'b0;
  reg        hazard_raw_stall_prev = 1'b0;

  reg [63:0] calc_cycles = 64'b0;
  reg [63:0] mem_cycles = 64'b0;
  reg [63:0] csr_cycles = 64'b0;
  reg [63:0] br_cycles = 64'b0;
  reg [63:0] ifu_cycles = 64'b0;
  reg [63:0] lsu_cycles = 64'b0;

  reg calc_busy = 1'b0;
  reg mem_busy = 1'b0;
  reg csr_busy = 1'b0;
  reg br_busy = 1'b0;
  reg ifu_busy = 1'b0;
  reg lsu_busy = 1'b0;

  wire ifu_req_fire = ifu_arvalid && ifu_arready;
  wire ifu_rsp_fire = ifu_rvalid && ifu_rready;
  wire lsu_req_fire = (lsu_arvalid && lsu_arready) || (lsu_awrvalid && lsu_awrready);
  wire lsu_rsp_fire = (lsu_rvalid && lsu_rready) || (lsu_bvalid && lsu_bready);

  always @(posedge clock) begin
    if (reset) begin
      exu_redirect_busy <= 1'b0;
      exu_redirect_type <= 2'b00;
      wbu_redirect_busy <= 1'b0;
    end else begin
      if (wbu_redirect) begin
        wbu_redirect_busy <= 1'b1;
        exu_redirect_busy <= 1'b0;
        exu_redirect_type <= 2'b00;
      end else if (exu_redirect) begin
        exu_redirect_busy <= 1'b1;
        if (exu_lsu_branch_o) begin
          exu_redirect_type <= 2'b01;
        end else if (idu_exu_opcode_i == `OPT_J_JAL) begin
          exu_redirect_type <= 2'b10;
        end else begin
          exu_redirect_type <= 2'b11;
        end
      end else if (idu_exu_valid_o) begin
        exu_redirect_busy <= 1'b0;
        exu_redirect_type <= 2'b00;
        wbu_redirect_busy <= 1'b0;
      end
    end
  end

  always @(posedge clock) begin
    if (!reset) begin
      if (wbu_redirect_busy && !idu_exu_valid_o) begin
        wbu_redirect_cycles <= wbu_redirect_cycles + 64'd1;
      end
      if (exu_redirect_busy && !idu_exu_valid_o) begin
        exu_redirect_cycles <= exu_redirect_cycles + 64'd1;
        if (exu_redirect_type == 2'b01) begin
          branch_redirect_cycles <= branch_redirect_cycles + 64'd1;
        end else begin
          jump_redirect_cycles <= jump_redirect_cycles + 64'd1;
          if (exu_redirect_type == 2'b10) begin
            jal_redirect_cycles <= jal_redirect_cycles + 64'd1;
          end else if (exu_redirect_type == 2'b11) begin
            jalr_redirect_cycles <= jalr_redirect_cycles + 64'd1;
          end
        end
      end
      if ((wbu_redirect_busy || exu_redirect_busy) && !idu_exu_valid_o) begin
        redirect_cycles <= redirect_cycles + 64'd1;
      end
    end

    if (redirect) begin
      redirect_cnt <= redirect_cnt + 64'd1;
    end
    if (exu_redirect) begin
      exu_redirect_cnt <= exu_redirect_cnt + 64'd1;
      if (exu_lsu_branch_o) begin
        branch_redirect_cnt <= branch_redirect_cnt + 64'd1;
      end
      if (exu_lsu_jump_o) begin
        jump_redirect_cnt <= jump_redirect_cnt + 64'd1;
        if (idu_exu_opcode_i == `OPT_J_JAL) begin
          jal_redirect_cnt <= jal_redirect_cnt + 64'd1;
        end else if (idu_exu_opcode_i == `OPT_I_JALR) begin
          jalr_redirect_cnt <= jalr_redirect_cnt + 64'd1;
        end
      end
    end
    if (wbu_redirect) begin
      wbu_redirect_cnt <= wbu_redirect_cnt + 64'd1;
    end

    if (hazard_raw_stall && !hazard_raw_stall_prev) begin
      hazard_event_cnt <= hazard_event_cnt + 64'd1;
    end
    if (hazard_raw_stall) begin
      hazard_cycles <= hazard_cycles + 64'd1;
    end
    hazard_raw_stall_prev <= hazard_raw_stall;
  end

  always @(posedge clock) begin
    if (ifu_rvalid && ifu_rready) begin
      ifu_cnt <= ifu_cnt + 64'd1;
      idu_cnt <= idu_cnt + 64'd1;
      exu_cnt <= exu_cnt + 64'd1;
      case (ifu_rdata[6:0])
        `OPT_U_AUIPC, `OPT_I_LOGIC, `OPT_U_LUI, `OPT_R_LOGIC: begin
          idu_calc_cnt <= idu_calc_cnt + 64'd1;
          calc_busy <= 1'b1;
        end
        `OPT_I_LOAD, `OPT_S_STORE: begin
          idu_mem_cnt <= idu_mem_cnt + 64'd1;
          mem_busy <= 1'b1;
        end
        `OPT_I_EC: begin
          if (ifu_rdata[14:12] != 3'b000) begin
            idu_csr_cnt <= idu_csr_cnt + 64'd1;
            csr_busy <= 1'b1;
          end
        end
        `OPT_B, `OPT_J_JAL, `OPT_I_JALR: begin
          idu_br_cnt <= idu_br_cnt + 64'd1;
          br_busy <= 1'b1;
        end
        default: begin
          // do nothing
        end
      endcase
    end else if (lsu_rvalid && lsu_rready) begin
      lsu_cnt <= lsu_cnt + 64'd1;
    end
  end

  always @(posedge clock) begin
    // IFU cycles: from fetch request handshake to fetch response handshake.
    if (ifu_busy || ifu_req_fire) begin
      ifu_cycles <= ifu_cycles + 64'd1;
    end
    if (ifu_req_fire) begin
      ifu_busy <= 1'b1;
    end
    if (ifu_rsp_fire) begin
      ifu_busy <= 1'b0;
    end

    // LSU cycles: from LSU request handshake to LSU response handshake.
    if (lsu_busy || lsu_req_fire) begin
      lsu_cycles <= lsu_cycles + 64'd1;
    end
    if (lsu_req_fire) begin
      lsu_busy <= 1'b1;
    end
    if (lsu_rsp_fire) begin
      lsu_busy <= 1'b0;
    end
  end

  always @(posedge clock) begin
    if (!cycle_done) begin
      if (calc_busy) begin
        calc_cycles <= calc_cycles + 64'd1;
      end
      if (mem_busy) begin
        mem_cycles <= mem_cycles + 64'd1;
      end
      if (csr_busy) begin
        csr_cycles <= csr_cycles + 64'd1;
      end
      if (br_busy) begin
        br_cycles <= br_cycles + 64'd1;
      end
    end else begin
      calc_busy <= 1'b0;
      mem_busy <= 1'b0;
      csr_busy <= 1'b0;
      br_busy <= 1'b0;
    end
  end

  export "DPI-C" function get_lsu_cnt;
  function longint unsigned get_lsu_cnt();
    return lsu_cnt;
  endfunction

  export "DPI-C" function get_ifu_cnt;
  function longint unsigned get_ifu_cnt();
    return ifu_cnt;
  endfunction

  export "DPI-C" function get_idu_cnt;
  function longint unsigned get_idu_cnt();
    return idu_cnt;
  endfunction

  export "DPI-C" function get_exu_cnt;
  function longint unsigned get_exu_cnt();
    return exu_cnt;
  endfunction

  export "DPI-C" function get_redirect_cnt;
  function longint unsigned get_redirect_cnt();
    return redirect_cnt;
  endfunction

  export "DPI-C" function get_exu_redirect_cnt;
  function longint unsigned get_exu_redirect_cnt();
    return exu_redirect_cnt;
  endfunction

  export "DPI-C" function get_branch_redirect_cnt;
  function longint unsigned get_branch_redirect_cnt();
    return branch_redirect_cnt;
  endfunction

  export "DPI-C" function get_jump_redirect_cnt;
  function longint unsigned get_jump_redirect_cnt();
    return jump_redirect_cnt;
  endfunction

  export "DPI-C" function get_jal_redirect_cnt;
  function longint unsigned get_jal_redirect_cnt();
    return jal_redirect_cnt;
  endfunction

  export "DPI-C" function get_jalr_redirect_cnt;
  function longint unsigned get_jalr_redirect_cnt();
    return jalr_redirect_cnt;
  endfunction

  export "DPI-C" function get_wbu_redirect_cnt;
  function longint unsigned get_wbu_redirect_cnt();
    return wbu_redirect_cnt;
  endfunction

  export "DPI-C" function get_redirect_cycles;
  function longint unsigned get_redirect_cycles();
    return redirect_cycles;
  endfunction

  export "DPI-C" function get_exu_redirect_cycles;
  function longint unsigned get_exu_redirect_cycles();
    return exu_redirect_cycles;
  endfunction

  export "DPI-C" function get_branch_redirect_cycles;
  function longint unsigned get_branch_redirect_cycles();
    return branch_redirect_cycles;
  endfunction

  export "DPI-C" function get_jump_redirect_cycles;
  function longint unsigned get_jump_redirect_cycles();
    return jump_redirect_cycles;
  endfunction

  export "DPI-C" function get_jal_redirect_cycles;
  function longint unsigned get_jal_redirect_cycles();
    return jal_redirect_cycles;
  endfunction

  export "DPI-C" function get_jalr_redirect_cycles;
  function longint unsigned get_jalr_redirect_cycles();
    return jalr_redirect_cycles;
  endfunction

  export "DPI-C" function get_wbu_redirect_cycles;
  function longint unsigned get_wbu_redirect_cycles();
    return wbu_redirect_cycles;
  endfunction

  export "DPI-C" function get_idu_calc_cnt;
  function longint unsigned get_idu_calc_cnt();
    return idu_calc_cnt;
  endfunction

  export "DPI-C" function get_idu_mem_cnt;
  function longint unsigned get_idu_mem_cnt();
    return idu_mem_cnt;
  endfunction

  export "DPI-C" function get_idu_csr_cnt;
  function longint unsigned get_idu_csr_cnt();
    return idu_csr_cnt;
  endfunction

  export "DPI-C" function get_idu_br_cnt;
  function longint unsigned get_idu_br_cnt();
    return idu_br_cnt;
  endfunction

  export "DPI-C" function get_calc_cycles;
  function longint unsigned get_calc_cycles();
    return calc_cycles;
  endfunction

  export "DPI-C" function get_mem_cycles;
  function longint unsigned get_mem_cycles();
    return mem_cycles;
  endfunction

  export "DPI-C" function get_csr_cycles;
  function longint unsigned get_csr_cycles();
    return csr_cycles;
  endfunction

  export "DPI-C" function get_br_cycles;
  function longint unsigned get_br_cycles();
    return br_cycles;
  endfunction

  export "DPI-C" function get_ifu_cycles;
  function longint unsigned get_ifu_cycles();
    return ifu_cycles;
  endfunction

  export "DPI-C" function get_lsu_cycles;
  function longint unsigned get_lsu_cycles();
    return lsu_cycles;
  endfunction

  export "DPI-C" function get_hazard_event_cnt;
  function longint unsigned get_hazard_event_cnt();
    return hazard_event_cnt;
  endfunction

  export "DPI-C" function get_hazard_cycles;
  function longint unsigned get_hazard_cycles();
    return hazard_cycles;
  endfunction
`endif

`endif

endmodule

`ifdef NPC
module ysyxSoCFull(
    input clock,
    input reset,
    input io_interrupt
);

// AXI master
wire        io_master_awready;
wire        io_master_awvalid;
wire [31:0] io_master_awaddr;
wire [3:0]  io_master_awid;
wire [7:0]  io_master_awlen;
wire [2:0]  io_master_awsize;
wire [1:0]  io_master_awburst;
wire        io_master_wready;
wire        io_master_wvalid;
wire [31:0] io_master_wdata;
wire [3:0]  io_master_wstrb;
wire        io_master_wlast;
wire        io_master_bready;
wire        io_master_bvalid;
wire [1:0]  io_master_bresp;
wire [3:0]  io_master_bid;
wire        io_master_arready;
wire        io_master_arvalid;
wire [31:0] io_master_araddr;
wire [3:0]  io_master_arid;
wire [7:0]  io_master_arlen;
wire [2:0]  io_master_arsize;
wire [1:0]  io_master_arburst;
wire        io_master_rready;
wire        io_master_rvalid;
wire [1:0]  io_master_rresp;
wire [31:0] io_master_rdata;
wire        io_master_rlast;
wire [3:0]  io_master_rid;

// AXI slave (unused in NPC top)
wire        io_slave_awready;
wire        io_slave_wready;
wire        io_slave_bvalid;
wire [1:0]  io_slave_bresp;
wire [3:0]  io_slave_bid;
wire        io_slave_arready;
wire        io_slave_rvalid;
wire [1:0]  io_slave_rresp;
wire [31:0] io_slave_rdata;
wire        io_slave_rlast;
wire [3:0]  io_slave_rid;

assign io_master_bid   = 4'b0;
assign io_master_rresp = 2'b00;
assign io_master_rlast = io_master_rvalid;
assign io_master_rid   = 4'b0;

ysyx_24110012 cpu(
    .clock(clock),
    .reset(reset),
    .io_interrupt(io_interrupt),

    .io_master_awready(io_master_awready),
    .io_master_awvalid(io_master_awvalid),
    .io_master_awaddr(io_master_awaddr),
    .io_master_awid(io_master_awid),
    .io_master_awlen(io_master_awlen),
    .io_master_awsize(io_master_awsize),
    .io_master_awburst(io_master_awburst),

    .io_master_wready(io_master_wready),
    .io_master_wvalid(io_master_wvalid),
    .io_master_wdata(io_master_wdata),
    .io_master_wstrb(io_master_wstrb),
    .io_master_wlast(io_master_wlast),

    .io_master_bready(io_master_bready),
    .io_master_bvalid(io_master_bvalid),
    .io_master_bresp(io_master_bresp),
    .io_master_bid(io_master_bid),

    .io_master_arready(io_master_arready),
    .io_master_arvalid(io_master_arvalid),
    .io_master_araddr(io_master_araddr),
    .io_master_arid(io_master_arid),
    .io_master_arlen(io_master_arlen),
    .io_master_arsize(io_master_arsize),
    .io_master_arburst(io_master_arburst),

    .io_master_rready(io_master_rready),
    .io_master_rvalid(io_master_rvalid),
    .io_master_rresp(io_master_rresp),
    .io_master_rdata(io_master_rdata),
    .io_master_rlast(io_master_rlast),
    .io_master_rid(io_master_rid),

    .io_slave_awready(io_slave_awready),
    .io_slave_awvalid(1'b0),
    .io_slave_awaddr(32'b0),
    .io_slave_awid(4'b0),
    .io_slave_awlen(8'b0),
    .io_slave_awsize(3'b0),
    .io_slave_awburst(2'b0),

    .io_slave_wready(io_slave_wready),
    .io_slave_wvalid(1'b0),
    .io_slave_wdata(32'b0),
    .io_slave_wstrb(4'b0),
    .io_slave_wlast(1'b0),

    .io_slave_bready(1'b0),
    .io_slave_bvalid(io_slave_bvalid),
    .io_slave_bresp(io_slave_bresp),
    .io_slave_bid(io_slave_bid),

    .io_slave_arready(io_slave_arready),
    .io_slave_arvalid(1'b0),
    .io_slave_araddr(32'b0),
    .io_slave_arid(4'b0),
    .io_slave_arlen(8'b0),
    .io_slave_arsize(3'b0),
    .io_slave_arburst(2'b0),

    .io_slave_rready(1'b0),
    .io_slave_rvalid(io_slave_rvalid),
    .io_slave_rresp(io_slave_rresp),
    .io_slave_rdata(io_slave_rdata),
    .io_slave_rlast(io_slave_rlast),
    .io_slave_rid(io_slave_rid)
);

  ysyx_24110012_mem my_mem(
    .clk(clock),
    .araddr(io_master_araddr),
    .arvalid(io_master_arvalid),
    .arready(io_master_arready),
    .rdata(io_master_rdata),
    .rvalid(io_master_rvalid),
    .rready(io_master_rready),
    .awaddr(io_master_awaddr),
    .awvalid(io_master_awvalid),
    .awready(io_master_awready),
    .wdata(io_master_wdata),
    .wstrb(io_master_wstrb),
    .wvalid(io_master_wvalid),
    .wready(io_master_wready),
    .bresp(io_master_bresp),
    .bvalid(io_master_bvalid),
    .bready(io_master_bready)
 );

endmodule

`endif
