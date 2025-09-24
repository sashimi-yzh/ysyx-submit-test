
module ysyx_25010008 (
    input clock,
    input reset,
    input io_interrupt,

    input         io_master_awready,
    output        io_master_awvalid,
    output [ 3:0] io_master_awid,
    output [31:0] io_master_awaddr,
    output [ 7:0] io_master_awlen,
    output [ 2:0] io_master_awsize,
    output [ 1:0] io_master_awburst,
    input         io_master_wready,
    output        io_master_wvalid,
    output [31:0] io_master_wdata,
    output [ 3:0] io_master_wstrb,
    output        io_master_wlast,
    output        io_master_bready,
    input         io_master_bvalid,
    input  [ 3:0] io_master_bid,
    input  [ 1:0] io_master_bresp,
    input         io_master_arready,
    output        io_master_arvalid,
    output [ 3:0] io_master_arid,
    output [31:0] io_master_araddr,
    output [ 7:0] io_master_arlen,
    output [ 2:0] io_master_arsize,
    output [ 1:0] io_master_arburst,
    output        io_master_rready,
    input         io_master_rvalid,
    input  [ 3:0] io_master_rid,
    input  [31:0] io_master_rdata,
    input  [ 1:0] io_master_rresp,
    input         io_master_rlast,

    input         io_slave_awready,
    input         io_slave_awvalid,
    input  [ 3:0] io_slave_awid,
    input  [31:0] io_slave_awaddr,
    input  [ 7:0] io_slave_awlen,
    input  [ 2:0] io_slave_awsize,
    input  [ 1:0] io_slave_awburst,
    output        io_slave_wready,
    input         io_slave_wvalid,
    input  [31:0] io_slave_wdata,
    input  [ 3:0] io_slave_wstrb,
    input         io_slave_wlast,
    input         io_slave_bready,
    output        io_slave_bvalid,
    output [ 3:0] io_slave_bid,
    output [ 1:0] io_slave_bresp,
    output        io_slave_arready,
    input         io_slave_arvalid,
    input  [ 3:0] io_slave_arid,
    input  [31:0] io_slave_araddr,
    input  [ 7:0] io_slave_arlen,
    input  [ 2:0] io_slave_arsize,
    input  [ 1:0] io_slave_arburst,
    input         io_slave_rready,
    output        io_slave_rvalid,
    output [ 3:0] io_slave_rid,
    output [31:0] io_slave_rdata,
    output [ 1:0] io_slave_rresp,
    output        io_slave_rlast
);
  // pc
  wire [31:0] ifu_pc;
  wire [1:0] npc_sel;
  wire ifu_enable;
  wire inst_addr_misaligned;

  // instruction
  wire [31:0] inst;
  wire [31:0] imm;
  wire suffix_b;
  wire suffix_h;
  wire sext;
  wire inst_valid;
  wire ecall;
  wire ebreak;
  wire mret;
  wire fence_i;

  wire decode_valid;
  wire idu_ready;
  wire [31:0] idu_pc;
  wire [31:0] exu_r_wdata;
  wire [31:0] exu_pc;
  wire [31:0] exu_npc;
  wire execute_valid;
  wire is_wrong_prediction;

  // alu
  wire [7:0] alu_opcode;
  wire [1:0] alu_operand1_sel;
  wire [3:0] alu_operand2_sel;
  wire [31:0] alu_result;

  // lsu
  wire [31:0] wsrc;
  wire mem_ren, mem_wen;
  wire block;
  wire [31:0] lsu_pc;
  wire ls_valid;
  wire load_addr_misaligned;
  wire store_addr_misaligned;

  // gpr
  wire [4:0] rs1, rs2, rd;
  wire [31:0] src1, src2;
  wire r_wen;
  wire [1:0] exu_r_wdata_sel;
  wire [31:0] r_wdata;
  // csr
  wire [11:0] csr_s, csr_d;
  wire [1:0] csr_src_sel;
  wire [31:0] csr_src;
  wire csr_wen;
  wire [31:0] csr_wdata;

  wire clear_cache;
  wire clear_pipeline;
  wire [31:0] npc;
  wire npc_valid;

  wire [31:0] araddr_0;
  wire arvalid_0;
  wire arready_0;
  wire [7:0] arlen_0;

  wire rready_0;
  wire [31:0] rdata_0;
  wire [1:0] rresp_0;
  wire rvalid_0;
  wire rlast_0;

  wire [31:0] araddr_1;
  wire [2:0] arsize_1;
  wire arvalid_1;
  wire arready_1;

  wire rready_1;
  wire [31:0] rdata_1;
  wire [1:0] rresp_1;
  wire rvalid_1;

  wire [31:0] awaddr_1;
  wire [2:0] awsize_1;
  wire awvalid_1;
  wire awready_1;

  wire [31:0] wdata_1;
  wire [3:0] wstrb_1;
  wire wvalid_1;
  wire wready_1;

  wire bready_1;
  wire [1:0] bresp_1;
  wire bvalid_1;

  ysyx_25010008_IFU ifu (
      .clock(clock),
      .reset(reset),

      .npc(npc),
      .npc_valid(npc_valid),
      .ifu_pc(ifu_pc),

      .inst_valid(inst_valid),
      .inst(inst),
      .idu_ready(idu_ready),
      .block(block),

      .enable (ifu_enable),
      .araddr (araddr_0),
      .arvalid(arvalid_0),
      .arlen  (arlen_0),
      .arready(arready_0),

      .rready(rready_0),
      .rdata (rdata_0),
      .rresp (rresp_0),
      .rvalid(rvalid_0),
      .rlast (rlast_0),

      .inst_addr_misaligned(inst_addr_misaligned),
      .clear_cache(clear_cache),
      .clear_pipeline(clear_pipeline)
  );

  ysyx_25010008_IDU idu (
      .clock(clock),
      .reset(reset),

      .ifu_pc(ifu_pc),
      .inst(inst),
      .inst_valid(inst_valid),
      .block(block),

      .idu_ready(idu_ready),
      .decode_valid(decode_valid),
      .idu_pc(idu_pc),
      .npc_sel(npc_sel),

      .imm(imm),
      .alu_opcode(alu_opcode),
      .alu_operand1_sel(alu_operand1_sel),
      .alu_operand2_sel(alu_operand2_sel),

      .suffix_b(suffix_b),
      .suffix_h(suffix_h),
      .sext(sext),
      .mem_ren(mem_ren),
      .mem_wen(mem_wen),

      .rs1(rs1),
      .rs2(rs2),
      .rd(rd),
      .r_wen(r_wen),
      .exu_r_wdata_sel(exu_r_wdata_sel),

      .csr_s(csr_s),
      .csr_src_sel(csr_src_sel),
      .csr_d(csr_d),
      .csr_wen(csr_wen),

      .ecall(ecall),
      .ebreak(ebreak),
      .mret(mret),
      .fence_i(fence_i),
      .clear_pipeline(clear_pipeline)
  );

  ysyx_25010008_EXU exu (
      .clock(clock),
      .reset(reset),

      .block(block),

      .decode_valid(decode_valid),
      .execute_valid(execute_valid),
      .idu_pc(idu_pc),
      .exu_pc(exu_pc),
      .npc_sel(npc_sel),

      .imm(imm),

      .src1(src1),
      .src2(src2),
      .exu_r_wdata_sel(exu_r_wdata_sel),

      .csr_src(csr_src),
      .csr_src_sel(csr_src_sel),

      .alu_opcode(alu_opcode),
      .alu_operand1_sel(alu_operand1_sel),
      .alu_operand2_sel(alu_operand2_sel),
      .alu_result(alu_result),

      .forward_data(r_wdata),
      .wsrc(wsrc),

      .exu_npc(exu_npc),

      .exu_r_wdata(exu_r_wdata),
      .csr_wdata  (csr_wdata),

      .clear_pipeline  (clear_pipeline),
      .is_wrong_prediction(is_wrong_prediction)
  );

  ysyx_25010008_LSU lsu (
      .clock(clock),
      .reset(reset),

      .suffix_b(suffix_b),
      .suffix_h(suffix_h),
      .sext(sext),

      .ren(mem_ren),
      .wen(mem_wen),

      .exu_pc(exu_pc),
      .lsu_pc(lsu_pc),

      .addr(alu_result),
      .wsrc(wsrc),
      .exu_r_wdata(exu_r_wdata),
      .r_wdata(r_wdata),
      .block(block),

      .execute_valid(execute_valid),
      .ls_valid(ls_valid),

      .araddr (araddr_1),
      .arsize (arsize_1),
      .arvalid(arvalid_1),
      .arready(arready_1),

      .rready(rready_1),
      .rdata (rdata_1),
      .rresp (rresp_1),
      .rvalid(rvalid_1),

      .awaddr (awaddr_1),
      .awsize (awsize_1),
      .awvalid(awvalid_1),
      .awready(awready_1),

      .wdata (wdata_1),
      .wstrb (wstrb_1),
      .wvalid(wvalid_1),
      .wready(wready_1),

      .bready(bready_1),
      .bresp (bresp_1),
      .bvalid(bvalid_1),

      .clear_pipeline(clear_pipeline),
      .load_addr_misaligned(load_addr_misaligned),
      .store_addr_misaligned(store_addr_misaligned)
  );

  ysyx_25010008_RegFile reg_file (
      .clock(clock),
      .reset(reset),

      .rs1(rs1),
      .rs2(rs2),
      .rd (rd),

      .wen  (r_wen),
      .wdata(r_wdata),

      .csr_s(csr_s),
      .csr_d(csr_d),

      .csr_wen  (csr_wen),
      .csr_wdata(csr_wdata),

      .src1(src1),
      .src2(src2),
      .csr_src(csr_src),

      .ls_valid(ls_valid),
      .inst_addr_misaligned(inst_addr_misaligned),
      .ecall(ecall),
      .ebreak(ebreak),
      .mret(mret),
      .fence_i(fence_i),
      .load_addr_misaligned(load_addr_misaligned),
      .store_addr_misaligned(store_addr_misaligned),
      .is_wrong_prediction(is_wrong_prediction),
      .clear_pipeline(clear_pipeline),
      .clear_cache(clear_cache),

      .lsu_pc(lsu_pc),
      .exu_npc(exu_npc),
      .npc(npc),
      .npc_valid(npc_valid)
  );

  ysyx_25010008_Arbiter arbiter (
      .clock(clock),
      .reset(reset),

      .ifu_enable(ifu_enable),
      .araddr_0(araddr_0),
      .arvalid_0(arvalid_0),
      .arlen_0(arlen_0),
      .arready_0(arready_0),

      .rready_0(rready_0),
      .rdata_0 (rdata_0),
      .rresp_0 (rresp_0),
      .rvalid_0(rvalid_0),
      .rlast_0 (rlast_0),

      .lsu_enable(block),
      .araddr_1  (araddr_1),
      .arsize_1  (arsize_1),
      .arvalid_1 (arvalid_1),
      .arready_1 (arready_1),

      .rready_1(rready_1),
      .rdata_1 (rdata_1),
      .rresp_1 (rresp_1),
      .rvalid_1(rvalid_1),

      .awaddr_1 (awaddr_1),
      .awsize_1 (awsize_1),
      .awvalid_1(awvalid_1),
      .awready_1(awready_1),

      .wdata_1 (wdata_1),
      .wstrb_1 (wstrb_1),
      .wvalid_1(wvalid_1),
      .wready_1(wready_1),

      .bready_1(bready_1),
      .bresp_1 (bresp_1),
      .bvalid_1(bvalid_1),

      .io_master_awready(io_master_awready),
      .io_master_awvalid(io_master_awvalid),
      .io_master_awid   (io_master_awid),
      .io_master_awaddr (io_master_awaddr),
      .io_master_awlen  (io_master_awlen),
      .io_master_awsize (io_master_awsize),
      .io_master_awburst(io_master_awburst),
      .io_master_wready (io_master_wready),
      .io_master_wvalid (io_master_wvalid),
      .io_master_wdata  (io_master_wdata),
      .io_master_wstrb  (io_master_wstrb),
      .io_master_wlast  (io_master_wlast),
      .io_master_bready (io_master_bready),
      .io_master_bvalid (io_master_bvalid),
      .io_master_bid    (io_master_bid),
      .io_master_bresp  (io_master_bresp),
      .io_master_arready(io_master_arready),
      .io_master_arvalid(io_master_arvalid),
      .io_master_arid   (io_master_arid),
      .io_master_araddr (io_master_araddr),
      .io_master_arlen  (io_master_arlen),
      .io_master_arsize (io_master_arsize),
      .io_master_arburst(io_master_arburst),
      .io_master_rready (io_master_rready),
      .io_master_rvalid (io_master_rvalid),
      .io_master_rid    (io_master_rid),
      .io_master_rdata  (io_master_rdata),
      .io_master_rresp  (io_master_rresp),
      .io_master_rlast  (io_master_rlast)
  );

endmodule
