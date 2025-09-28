module ysyx_23060203_CPU (
  input clock, reset,

  // ysyx_23060203_axi_if.in io_in,
  ysyx_23060203_axi_if.out io_out
);

  wire [31:0] gpr_rdata1, gpr_rdata2;
  ysyx_23060203_GPR GPR (
    .clock(clock), .reset(reset),
    .raddr1(gpr_raddr1), .rdata1(gpr_rdata1),
    .raddr2(gpr_raddr2), .rdata2(gpr_rdata2),
    .wen(gpr_wen), .waddr(gpr_waddr), .wdata(gpr_wdata)
  );

  wire ifu_out_valid;
  wire [31:0] ifu_out_pc;
  wire [31:0] ifu_out_inst;
  ysyx_23060203_axi_if ifu_mem_r();
  ysyx_23060203_IFU IFU (
    .clock(clock), .reset(reset),

    .mem_r(ifu_mem_r),

    .jump_flush(jump_flush), .jump_dnpc(jump_dnpc),
    .cs_flush(cs_flush), .cs_dnpc(cs_dnpc),
    .fencei(fencei),

    .out_ready(idu_in_ready),
    .out_valid(ifu_out_valid),
    .out_pc(ifu_out_pc),
    .out_inst(ifu_out_inst)
  );

  wire [4:0] gpr_raddr1, gpr_raddr2;
  wire [11:0] csr_raddr;
  wire jump_flush;
  wire [31:0] jump_dnpc;
  wire idu_in_ready;
  wire idu_out_valid;
  wire [31:0] idu_out_pc;
  wire [31:0] idu_out_val_a;
  wire [31:0] idu_out_val_b;
  wire [31:0] idu_out_val_c;
  wire        idu_out_alu_src;
  wire [2:0]  idu_out_alu_funct;
  wire        idu_out_alu_sw;
  wire [4:0]  idu_out_rd;
  wire        idu_out_rd_src;
  wire [3:0]  idu_out_ls;
  wire idu_out_csr_wen;
  wire idu_out_csr_src;
  wire idu_out_exc;
  wire idu_out_ret;
  wire idu_out_fencei;
  `ifdef NPC_DEBUG
    wire [31:0] idu_out_inst;
    wire [31:0] idu_out_dnpc;
  `endif
  ysyx_23060203_IDU IDU (
    .clock(clock), .reset(reset),

    .flush(cs_flush),

    .rs1(gpr_raddr1), .src1(gpr_rdata1),
    .rs2(gpr_raddr2), .src2(gpr_rdata2),

    .csr_raddr(csr_raddr), .csr_rdata(csr_rdata),

    .exu_rd(exu_rd), .exu_rd_val(exu_rd_val),

    .jump_flush(jump_flush), .jump_dnpc(jump_dnpc),

    .in_ready(idu_in_ready),
    .in_valid(ifu_out_valid),
    .in_pc(ifu_out_pc),
    .in_inst(ifu_out_inst),

    .out_ready(exu_in_ready),
    .out_valid(idu_out_valid),
    .out_pc(idu_out_pc),
    .out_val_a(idu_out_val_a),
    .out_val_b(idu_out_val_b),
    .out_val_c(idu_out_val_c),
    .out_alu_funct(idu_out_alu_funct),
    .out_alu_sw(idu_out_alu_sw),
    .out_rd(idu_out_rd),
    .out_rd_src(idu_out_rd_src),
    .out_ls(idu_out_ls),
    .out_csr_wen(idu_out_csr_wen),
    .out_csr_src(idu_out_csr_src),
    .out_exc(idu_out_exc),
    .out_ret(idu_out_ret),
    .out_fencei(idu_out_fencei)
    `ifdef NPC_DEBUG
      ,
      .out_inst(idu_out_inst),
      .out_dnpc(idu_out_dnpc)
    `endif
  );

  wire [4:0] exu_rd;
  wire [31:0] exu_rd_val;
  ysyx_23060203_axi_if lsu_mem_r();
  wire exu_in_ready;
  wire exu_out_valid;
  wire [31:0] exu_out_pc;
  wire [4:0] exu_out_gpr_waddr;
  wire [31:0] exu_out_gpr_wdata;
  wire exu_out_csr_wen;
  wire [11:0] exu_out_csr_waddr;
  wire [31:0] exu_out_csr_wdata;
  wire exu_out_exc;
  wire exu_out_ret;
  wire exu_out_fencei;
  `ifdef NPC_DEBUG
    wire [31:0] exu_out_inst;
    wire [31:0] exu_out_dnpc;
  `endif
  ysyx_23060203_EXU EXU (
    .clock(clock), .reset(reset),

    .flush(cs_flush),

    .exu_rd(exu_rd), .exu_rd_val(exu_rd_val),

    .mem_r(lsu_mem_r),
    .mem_w(io_out),

    .in_ready(exu_in_ready),
    .in_valid(idu_out_valid),
    .in_pc(idu_out_pc),
    .in_val_a(idu_out_val_a),
    .in_val_b(idu_out_val_b),
    .in_val_c(idu_out_val_c),
    .in_alu_funct(idu_out_alu_funct),
    .in_alu_sw(idu_out_alu_sw),
    .in_rd(idu_out_rd),
    .in_rd_src(idu_out_rd_src),
    .in_ls(idu_out_ls),
    .in_csr_wen(idu_out_csr_wen),
    .in_csr_src(idu_out_csr_src),
    .in_exc(idu_out_exc),
    .in_ret(idu_out_ret),
    .in_fencei(idu_out_fencei),

    .out_ready(wbu_in_ready),
    .out_valid(exu_out_valid),
    .out_pc(exu_out_pc),
    .out_gpr_waddr(exu_out_gpr_waddr),
    .out_gpr_wdata(exu_out_gpr_wdata),
    .out_csr_wen(exu_out_csr_wen),
    .out_csr_waddr(exu_out_csr_waddr),
    .out_csr_wdata(exu_out_csr_wdata),
    .out_exc(exu_out_exc),
    .out_ret(exu_out_ret),
    .out_fencei(exu_out_fencei)
    `ifdef NPC_DEBUG
      ,
      .in_inst(idu_out_inst),
      .in_dnpc(idu_out_dnpc),
      .out_inst(exu_out_inst),
      .out_dnpc(exu_out_dnpc)
    `endif
  );

  wire gpr_wen;
  wire [4:0] gpr_waddr;
  wire [31:0] gpr_wdata;
  wire [31:0] csr_rdata;
  wire cs_flush;
  wire [31:0] cs_dnpc;
  wire fencei;
  wire wbu_in_ready;
  ysyx_23060203_WBU WBU(
    .clock(clock), .reset(reset),

    .gpr_wen(gpr_wen), .gpr_waddr(gpr_waddr), .gpr_wdata(gpr_wdata),
    .csr_raddr(csr_raddr), .csr_rdata(csr_rdata),

    .cs_flush(cs_flush), .cs_dnpc(cs_dnpc),
    .fencei(fencei),

    .in_ready(wbu_in_ready),
    .in_valid(exu_out_valid),
    .in_pc(exu_out_pc),
    .in_gpr_waddr(exu_out_gpr_waddr),
    .in_gpr_wdata(exu_out_gpr_wdata),
    .in_csr_wen(exu_out_csr_wen),
    .in_csr_waddr(exu_out_csr_waddr),
    .in_csr_wdata(exu_out_csr_wdata),
    .in_exc(exu_out_exc),
    .in_ret(exu_out_ret),
    .in_fencei(exu_out_fencei)

    `ifdef NPC_DEBUG
      ,
      .in_inst(exu_out_inst),
      .in_dnpc(exu_out_dnpc)
    `endif
  );

  ysyx_23060203_axi_if mem_r();
  ysyx_23060203_MemArb MemArb (
    .clock(clock), .reset(reset),
    .ifu_r(ifu_mem_r), .lsu_r(lsu_mem_r),
    .ram_r(mem_r)
  );

  ysyx_23060203_axi_if clint_r();
  ysyx_23060203_XBar Xbar (
    .clock(clock), .reset(reset),
    .read(mem_r),
    .soc_r(io_out), .clint_r(clint_r)
  );

  ysyx_23060203_CLINT CLINT (
    .clock(clock), .reset(reset),
    .read(clint_r)
  );

`ifdef YSYXSOC `ifdef NPC_DEBUG
  // SoC Access Fault 检查
  always @(posedge clock) begin
    if (io_out.rvalid & io_out.rresp[1]) begin
      abort_err(101); // read error
    end
    if (io_out.bvalid & io_out.bresp[1]) begin
      abort_err(102); // write error
    end
  end
`endif `endif

endmodule
