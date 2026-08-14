`include "ysyx_26010007_defines.v"

module ysyx_26010007_riscv32e(
  input clock,
  input reset,

  output                    icache_arvalid,
  input                     icache_arready,
  output [`PADDR_WIDTH-1:0] icache_araddr,
  output [7:0]              icache_arlen,
  output [2:0]              icache_arsize,
  output [3:0]              icache_arid,
  output [1:0]              icache_arburst,

  input                     icache_rvalid,
  output                    icache_rready,
  input [`WORD_WIDTH-1:0]   icache_rdata,
  input [1:0]               icache_rresp,
  input                     icache_rlast,
  input [3:0]               icache_rid,

  output                    icache_awvalid,
  input                     icache_awready,
  output [`PADDR_WIDTH-1:0] icache_awaddr,
  output [7:0]              icache_awlen,
  output [2:0]              icache_awsize,
  output [3:0]              icache_awid,
  output [1:0]              icache_awburst,

  output                    icache_wvalid,
  input                     icache_wready,
  output [`WORD_WIDTH-1:0]  icache_wdata,
  output [3:0]              icache_wstrb,
  output                    icache_wlast,

  input                     icache_bvalid,
  output                    icache_bready,
  input  [1:0]              icache_bresp,
  input  [3:0]              icache_bid,

  output                    lsu_arvalid,
  input                     lsu_arready,
  output [`PADDR_WIDTH-1:0] lsu_araddr,
  output [7:0]              lsu_arlen,
  output [2:0]              lsu_arsize,
  output [3:0]              lsu_arid,
  output [1:0]              lsu_arburst,

  input                     lsu_rvalid,
  output                    lsu_rready,
  input [`WORD_WIDTH-1:0]   lsu_rdata,
  input [1:0]               lsu_rresp,
  input                     lsu_rlast,
  input [3:0]               lsu_rid,

  output                    lsu_awvalid,
  input                     lsu_awready,
  output [`PADDR_WIDTH-1:0] lsu_awaddr,
  output [7:0]              lsu_awlen,
  output [2:0]              lsu_awsize,
  output [3:0]              lsu_awid,
  output [1:0]              lsu_awburst,

  output                    lsu_wvalid,
  input                     lsu_wready,
  output [`WORD_WIDTH-1:0]  lsu_wdata,
  output [3:0]              lsu_wstrb,
  output                    lsu_wlast,

  input                     lsu_bvalid,
  output                    lsu_bready,
  input  [1:0]              lsu_bresp,
  input  [3:0]              lsu_bid
);
  // icache 只读AXI接口
  assign icache_awvalid = 0;
  assign icache_awaddr = 0;
  assign icache_awlen = 0;
  assign icache_awsize = 0;
  assign icache_awid = 0;
  assign icache_awburst = 0;
  assign icache_wvalid = 0;
  assign icache_wdata = 0;
  assign icache_wstrb = 0;
  assign icache_wlast = 0;
  assign icache_bready = 0;

  // 握手信号
  wire ifu_valid;
  wire idu_ready;
  wire idu_valid;
  wire exu_ready;
  wire exu_valid;
  wire lsu_ready;
  wire lsu_valid;
  wire wbu_ready;

  // ifu - icache
  wire ifu_arvalid;
  wire [`WORD_WIDTH-1:0] ifu_araddr;
  wire icache_irvalid;
  wire [`WORD_WIDTH-1:0] icache_irdata;
  // fence
  wire flush_icache;

  wire [`PADDR_WIDTH-1:0] ifu_pc;
  wire [`WORD_WIDTH-1:0]  ifu_inst;
  wire [`WORD_WIDTH-1:0] rd1;
  wire [`WORD_WIDTH-1:0] rd2;
  wire [`REG_ADDR_WIDTH-1:0] ra1;
  wire [`REG_ADDR_WIDTH-1:0] ra2;
  wire [`CSR_ADDR_WIDTH-1:0] csra;
  wire [`WORD_WIDTH-1:0] csrrd;
  wire [`WORD_WIDTH-1:0] csrwd;
  wire csrwen;
  wire [`WORD_WIDTH-1:0] idu_src1;
  wire [`WORD_WIDTH-1:0] idu_src2;
  wire [`ALU_OP_WIDTH-1:0] idu_alu_op;
  wire [`WORD_WIDTH-1:0] idu_alu_res;
  wire [`REG_ADDR_WIDTH-1:0] idu_wa;
  wire [`WORD_WIDTH-1:0] wd;
  wire [`REG_ADDR_WIDTH-1:0] wa;
  wire wreg;
  wire idu_wreg;
  wire [`WORD_WIDTH-1:0] exu_alu_res;
  wire                   exu_wreg;
  wire [`REG_ADDR_WIDTH-1:0] exu_wa;
  wire [7:0] exu_ls_inst;
  wire [`WORD_WIDTH-1:0] idu_store_data;
  wire [`WORD_WIDTH-1:0] exu_store_data;
  wire [`PADDR_WIDTH-1:0] jump_addr;
  wire jump_flag;
  wire [7:0] idu_ls_inst;
  wire [`EXC_EVENT_WIDTH-1:0] exc_event;
  wire [`WORD_WIDTH-1:0] lsu_alu_res;
  wire                   lsu_wreg;
  wire [`REG_ADDR_WIDTH-1:0] lsu_wa;
  wire lsu_mwreg;
  wire [`WORD_WIDTH-1:0] lsu_mwd;
  wire exc_jump_flag;
  wire [`PADDR_WIDTH-1:0] exc_jump_addr;

  ysyx_26010007_icache ICACHE0(
    .clock(clock),
    .reset(reset),
    .flush_icache(flush_icache),

    .ifu_arvalid(ifu_arvalid),
    .ifu_araddr(ifu_araddr),
    .icache_irvalid(icache_irvalid),
    .icache_irdata(icache_irdata),

    .icache_arvalid(icache_arvalid),
    .icache_arready(icache_arready),
    .icache_araddr(icache_araddr),
    .icache_arlen(icache_arlen),
    .icache_arsize(icache_arsize),
    .icache_arid(icache_arid),
    .icache_arburst(icache_arburst),
    .icache_rvalid(icache_rvalid),
    .icache_rready(icache_rready),
    .icache_rdata(icache_rdata),
    .icache_rresp(icache_rresp),
    .icache_rlast(icache_rlast),
    .icache_rid(icache_rid)
  );
  
  ysyx_26010007_IFU IFU0(
    .clock(clock),
    .reset(reset),
    // 握手信号
    .ifu_valid(ifu_valid),
    .idu_ready(idu_ready),
    // ifu - icache
    .ifu_arvalid(ifu_arvalid),
    .ifu_araddr(ifu_araddr),
    .icache_irvalid(icache_irvalid),
    .icache_irdata(icache_irdata),
    // 传输至idu的数据
    .ifu_inst(ifu_inst),
    .ifu_pc(ifu_pc),
    // Jump Target
    .jump_addr(jump_addr),
    .jump_flag(jump_flag),
    .exc_jump_addr(exc_jump_addr),
    .exc_jump_flag(exc_jump_flag)
  );

  ysyx_26010007_CSR CSR0(
    .clock(clock),
    .pc(ifu_pc),
    .csrwdata(csrwd),
    .csrwen(csrwen),
    .csraddr(csra),
    .csrrdata(csrrd),
    .exc_event(exc_event),
    .exc_jump_addr(exc_jump_addr),
    .exc_jump_flag(exc_jump_flag)
  );

  ysyx_26010007_RegisterFile RegisterFile0(
    .clock(clock),
    .wdata(wd),
    .waddr(wa),
    .wen(wreg),
    .r1addr(ra1),
    .r2addr(ra2),
    .r1data(rd1),
    .r2data(rd2)
  );

  ysyx_26010007_IDU IDU0(
`ifdef debug
    .clock(clock),
`endif
    // 握手信号
    .ifu_valid(ifu_valid),
    .idu_ready(idu_ready),
    .idu_valid(idu_valid),
    .exu_ready(exu_ready),
    // 来自ifu的数据
    .ifu_inst(ifu_inst),
    .ifu_pc(ifu_pc),
    // 传输到ifu的数据（target addr）
    .jump_addr(jump_addr),
    .jump_flag(jump_flag),
    // 传输到exu的数据
    .idu_src1(idu_src1),
    .idu_src2(idu_src2),
    .idu_alu_op(idu_alu_op),
    .idu_wreg(idu_wreg),
    .idu_wa(idu_wa),
    .idu_ls_inst(idu_ls_inst),
    .idu_store_data(idu_store_data),
    // 读通用寄存器的信号
    .rd1(rd1),
    .rd2(rd2),
    .ra1(ra1),
    .ra2(ra2),
    // 读写CSR的信号
    .csra(csra),
    .csrrd(csrrd),
    .csrwd(csrwd),
    .csrwen(csrwen),
    .exc_event(exc_event),
    // fence
    .flush_icache(flush_icache)
  );

  ysyx_26010007_EXU EXU0(
    // 握手信号
    .idu_valid(idu_valid),
    .exu_ready(exu_ready),
    .exu_valid(exu_valid),
    .lsu_ready(lsu_ready),
    // 来自idu的信号
    .idu_src1(idu_src1),
    .idu_src2(idu_src2),
    .idu_alu_op(idu_alu_op),
    .idu_wreg(idu_wreg),
    .idu_wa(idu_wa),
    .idu_ls_inst(idu_ls_inst),
    .idu_store_data(idu_store_data),
    // 传输到lsu的信号
    .exu_alu_res(exu_alu_res),
    .exu_wreg(exu_wreg),
    .exu_wa(exu_wa),
    .exu_ls_inst(exu_ls_inst),
    .exu_store_data(exu_store_data)
  );

  ysyx_26010007_LSU LSU0(
    .clock(clock),
    .reset(reset),
    // 握手信号
    .exu_valid(exu_valid),
    .lsu_ready(lsu_ready),
    .lsu_valid(lsu_valid),
    .wbu_ready(wbu_ready),
    // 来自exu的信号
    .exu_alu_res(exu_alu_res),
    .exu_wreg(exu_wreg),
    .exu_wa(exu_wa),
    .exu_ls_inst(exu_ls_inst),
    .exu_store_data(exu_store_data),
    // 传输到wbu的信号
    .lsu_mwd(lsu_mwd),
    .lsu_mwreg(lsu_mwreg),
    .lsu_alu_res(lsu_alu_res),
    .lsu_wreg(lsu_wreg),
    .lsu_wa(lsu_wa),
    // DRAM
    .lsu_arvalid(lsu_arvalid),
    .lsu_arready(lsu_arready),
    .lsu_araddr(lsu_araddr),
    .lsu_arlen(lsu_arlen),
    .lsu_arsize(lsu_arsize),
    .lsu_arid(lsu_arid),
    .lsu_arburst(lsu_arburst),
    .lsu_rvalid(lsu_rvalid),
    .lsu_rready(lsu_rready),
    .lsu_rdata(lsu_rdata),
    .lsu_rresp(lsu_rresp),
    .lsu_rlast(lsu_rlast),
    .lsu_rid(lsu_rid),
    .lsu_awvalid(lsu_awvalid),
    .lsu_awready(lsu_awready),
    .lsu_awaddr(lsu_awaddr),
    .lsu_awlen(lsu_awlen),
    .lsu_awsize(lsu_awsize),
    .lsu_awid(lsu_awid),
    .lsu_awburst(lsu_awburst),
    .lsu_wvalid(lsu_wvalid),
    .lsu_wready(lsu_wready),
    .lsu_wdata(lsu_wdata),
    .lsu_wstrb(lsu_wstrb),
    .lsu_wlast(lsu_wlast),
    .lsu_bvalid(lsu_bvalid),
    .lsu_bready(lsu_bready),
    .lsu_bresp(lsu_bresp),
    .lsu_bid(lsu_bid)
  );

  ysyx_26010007_WBU WBU0(
    // 握手信号
    .lsu_valid(lsu_valid),
    .wbu_ready(wbu_ready),
    // 来自lsu的信号
    .lsu_mwd(lsu_mwd),
    .lsu_mwreg(lsu_mwreg),
    .lsu_alu_res(lsu_alu_res),
    .lsu_wreg(lsu_wreg),
    .lsu_wa(lsu_wa),
    // 写通用寄存器信号
    .wa(wa),
    .wreg(wreg),
    .wd(wd)
  );
`ifdef debug
  always @(posedge clock) begin
    if(icache_irvalid && ifu_arvalid) event_count(0);
    if(lsu_rready && lsu_rvalid) event_count(1);
    if(lsu_bready && lsu_bvalid) event_count(2);
    if(exu_valid && exu_ready) event_count(3);
  end
`endif
endmodule