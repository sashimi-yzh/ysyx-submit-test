`timescale 1ns / 1ns

module Top_sim;
  reg clock;
  reg reset;
  initial clock = 0;
  always #1 clock = ~clock;

  initial begin
    reset = 1;
    #20 reset = 0;
  end

  // initial begin
  //   $dumpfile("waveform.vcd");
  //   $dumpvars(0, Top_sim);
  // end

  wire                          io_interrupt;

  wire                          io_master_awvalid;
  wire                          io_master_awready;
  wire [31:0]                   io_master_awaddr;
  wire [ 3:0]                   io_master_awid;
  wire [ 7:0]                   io_master_awlen;
  wire [ 2:0]                   io_master_awsize;
  wire [ 1:0]                   io_master_awburst;
  wire                          io_master_wvalid;
  wire                          io_master_wready;
  wire [31:0]                   io_master_wdata;
  wire [ 3:0]                   io_master_wstrb;
  wire                          io_master_wlast;
  wire                          io_master_bvalid;
  wire                          io_master_bready;
  wire [ 1:0]                   io_master_bresp;
  wire [ 3:0]                   io_master_bid;
  wire                          io_master_arvalid;
  wire                          io_master_arready;
  wire [31:0]                   io_master_araddr;
  wire [ 3:0]                   io_master_arid;
  wire [ 7:0]                   io_master_arlen;
  wire [ 2:0]                   io_master_arsize;
  wire [ 1:0]                   io_master_arburst;
  wire                          io_master_rvalid;
  wire                          io_master_rready;
  wire [ 1:0]                   io_master_rresp;
  wire [31:0]                   io_master_rdata;
  wire                          io_master_rlast;
  wire [ 3:0]                   io_master_rid;

  wire                          io_slave_awvalid;
  wire                          io_slave_awready;
  wire [31:0]                   io_slave_awaddr;
  wire [ 3:0]                   io_slave_awid;
  wire [ 7:0]                   io_slave_awlen;
  wire [ 2:0]                   io_slave_awsize;
  wire [ 1:0]                   io_slave_awburst;
  wire                          io_slave_wvalid;
  wire                          io_slave_wready;
  wire [31:0]                   io_slave_wdata;
  wire [ 3:0]                   io_slave_wstrb;
  wire                          io_slave_wlast;
  wire                          io_slave_bvalid;
  wire                          io_slave_bready;
  wire [ 1:0]                   io_slave_bresp;
  wire [ 3:0]                   io_slave_bid;
  wire                          io_slave_arvalid;
  wire                          io_slave_arready;
  wire [31:0]                   io_slave_araddr;
  wire [ 3:0]                   io_slave_arid;
  wire [ 7:0]                   io_slave_arlen;
  wire [ 2:0]                   io_slave_arsize;
  wire [ 1:0]                   io_slave_arburst;
  wire                          io_slave_rvalid;
  wire                          io_slave_rready;
  wire [ 1:0]                   io_slave_rresp;
  wire [31:0]                   io_slave_rdata;
  wire                          io_slave_rlast;
  wire [ 3:0]                   io_slave_rid;

  ysyx_25060161 dut (
    .clock              (clock),
    .reset              (reset),
    .io_interrupt       (io_interrupt),

    .io_master_awvalid  (io_master_awvalid),
    .io_master_awready  (io_master_awready),
    .io_master_awaddr   (io_master_awaddr),
    .io_master_awid     (io_master_awid),
    .io_master_awlen    (io_master_awlen),
    .io_master_awsize   (io_master_awsize),
    .io_master_awburst  (io_master_awburst),
    .io_master_wvalid   (io_master_wvalid),
    .io_master_wready   (io_master_wready),
    .io_master_wdata    (io_master_wdata),
    .io_master_wstrb    (io_master_wstrb),
    .io_master_wlast    (io_master_wlast),
    .io_master_bvalid   (io_master_bvalid),
    .io_master_bready   (io_master_bready),
    .io_master_bresp    (io_master_bresp),
    .io_master_bid      (io_master_bid),
    .io_master_arvalid  (io_master_arvalid),
    .io_master_arready  (io_master_arready),
    .io_master_araddr   (io_master_araddr),
    .io_master_arid     (io_master_arid),
    .io_master_arlen    (io_master_arlen),
    .io_master_arsize   (io_master_arsize),
    .io_master_arburst  (io_master_arburst),
    .io_master_rvalid   (io_master_rvalid),
    .io_master_rready   (io_master_rready),
    .io_master_rresp    (io_master_rresp),
    .io_master_rdata    (io_master_rdata),
    .io_master_rlast    (io_master_rlast),
    .io_master_rid      (io_master_rid),

    .io_slave_awvalid   (io_slave_awvalid),
    .io_slave_awready   (io_slave_awready),
    .io_slave_awaddr    (io_slave_awaddr),
    .io_slave_awid      (io_slave_awid),
    .io_slave_awlen     (io_slave_awlen),
    .io_slave_awsize    (io_slave_awsize),
    .io_slave_awburst   (io_slave_awburst),
    .io_slave_wvalid    (io_slave_wvalid),
    .io_slave_wready    (io_slave_wready),
    .io_slave_wdata     (io_slave_wdata),
    .io_slave_wstrb     (io_slave_wstrb),
    .io_slave_wlast     (io_slave_wlast),
    .io_slave_bvalid    (io_slave_bvalid),
    .io_slave_bready    (io_slave_bready),
    .io_slave_bresp     (io_slave_bresp),
    .io_slave_bid       (io_slave_bid),
    .io_slave_arvalid   (io_slave_arvalid),
    .io_slave_arready   (io_slave_arready),
    .io_slave_araddr    (io_slave_araddr),
    .io_slave_arid      (io_slave_arid),
    .io_slave_arlen     (io_slave_arlen),
    .io_slave_arsize    (io_slave_arsize),
    .io_slave_arburst   (io_slave_arburst),
    .io_slave_rvalid    (io_slave_rvalid),
    .io_slave_rready    (io_slave_rready),
    .io_slave_rresp     (io_slave_rresp),
    .io_slave_rdata     (io_slave_rdata),
    .io_slave_rlast     (io_slave_rlast),
    .io_slave_rid       (io_slave_rid)
  );

  assign io_slave_awvalid = 1'b0;
  assign io_slave_wvalid  = 1'b0;
  assign io_slave_wlast   = 1'b0;
  assign io_slave_bready  = 1'b0;
  assign io_slave_arvalid = 1'b0;
  assign io_slave_rready  = 1'b0;
  assign io_slave_awaddr  = 32'h0;
  assign io_slave_awid    = 4'h0;
  assign io_slave_awlen   = 8'h0;
  assign io_slave_awsize  = 3'h0;
  assign io_slave_awburst = 2'h0;
  assign io_slave_wdata   = 32'h0;
  assign io_slave_wstrb   = 4'h0;
  assign io_slave_araddr  = 32'h0;
  assign io_slave_arid    = 4'h0;
  assign io_slave_arlen   = 8'h0;
  assign io_slave_arsize  = 3'h0;
  assign io_slave_arburst = 2'h0;

  assign io_interrupt = 1'b0;

  AXIMemory #(
    .RESET_VECTOR(32'h8000_0000)
  ) memory (
    .clock     (clock),
    .reset     (reset),
    .awvalid   (io_master_awvalid),
    .awready   (io_master_awready),
    .awaddr    (io_master_awaddr),
    .awid      (io_master_awid),
    .awlen     (io_master_awlen),
    .awsize    (io_master_awsize),
    .awburst   (io_master_awburst),
    .wvalid    (io_master_wvalid),
    .wready    (io_master_wready),
    .wdata     (io_master_wdata),
    .wstrb     (io_master_wstrb),
    .wlast     (io_master_wlast),
    .bvalid    (io_master_bvalid),
    .bready    (io_master_bready),
    .bresp     (io_master_bresp),
    .bid       (io_master_bid),
    .arvalid   (io_master_arvalid),
    .arready   (io_master_arready),
    .araddr    (io_master_araddr),
    .arid      (io_master_arid),
    .arlen     (io_master_arlen),
    .arsize    (io_master_arsize),
    .arburst   (io_master_arburst),
    .rvalid    (io_master_rvalid),
    .rready    (io_master_rready),
    .rresp     (io_master_rresp),
    .rdata     (io_master_rdata),
    .rlast     (io_master_rlast),
    .rid       (io_master_rid)
  );

reg [31:0] axi_ar_count;
reg [31:0] axi_aw_count;
reg [31:0] cycle_count;
reg [31:0] idle_cycles;
reg [31:0] last_araddr;

reg [31:0] uart_awaddr;
always @(posedge clock) begin
  if (reset) begin
    uart_awaddr <= 32'h0;
  end else begin
    if (io_master_awvalid && io_master_awready)
      uart_awaddr <= io_master_awaddr;
    if (io_master_wvalid && io_master_wready && io_master_wstrb[0]) begin
      if ((io_master_awvalid && io_master_awready ? io_master_awaddr : uart_awaddr) == 32'ha00003f8)
        $write("%c", io_master_wdata[7:0]);
    end
  end
end

wire axi_active = io_master_arvalid || io_master_awvalid ||
                  io_master_rvalid  || io_master_bvalid;

always @(posedge clock) begin
  if (reset) begin
    axi_ar_count <= 0;
    axi_aw_count <= 0;
    cycle_count  <= 0;
    idle_cycles  <= 0;
    last_araddr  <= 0;
  end else begin
    cycle_count <= cycle_count + 1;
    if (io_master_arvalid && io_master_arready) begin
      axi_ar_count <= axi_ar_count + 1;
      last_araddr  <= io_master_araddr;
    end
    if (io_master_awvalid && io_master_awready)
      axi_aw_count <= axi_aw_count + 1;
    if (axi_active)
      idle_cycles <= 0;
    else
      idle_cycles <= idle_cycles + 1;
  end
end

parameter AXI_STALL_THRESHOLD = 100000;
always @(posedge clock) begin
  if (!reset && idle_cycles > AXI_STALL_THRESHOLD) begin
    $display("TIMEOUT: no AXI activity for %0d cycles at cycle %0d",
              idle_cycles, cycle_count);
    $display("  ar_count=%0d  aw_count=%0d  last_araddr=%h",
              axi_ar_count, axi_aw_count, last_araddr);
    $finish;
  end
end

always @(posedge clock) begin
  if (!reset && cycle_count > 100000000) begin
    $display("MAXCYCLES: %0d cycles reached. ar=%0d aw=%0d",
              cycle_count, axi_ar_count, axi_aw_count);
    $finish;
  end
end

`ifndef NETLIST
  reg [31:0] inst_count;
  always @(posedge clock) begin
    if (reset)
      inst_count <= 0;
    else if (dut._mau_io_wbu_valid && dut._wbu_io_mau_ready)
      inst_count <= inst_count + 1;
  end
`endif

`ifndef NETLIST
  reg [31:0] last_x10_write_data, last_x10_write_inst, last_x10_write_pc;
  reg [31:0] last_axi_araddr_r;
  reg [31:0] x10_write_history_data [0:3];
  reg [31:0] x10_write_history_inst [0:3];
  reg [31:0] x10_write_history_pc   [0:3];
  integer    x10_write_cnt;
  reg [31:0] last_axi_araddrs [0:3];
  integer    axi_ar_wr_ptr;
  always @(posedge clock) begin
    if (reset) begin
      last_x10_write_data <= 0;
      last_x10_write_inst <= 0;
      last_x10_write_pc   <= 0;
      last_axi_araddr_r   <= 0;
      x10_write_cnt       <= 0;
      axi_ar_wr_ptr       <= 0;
    end else begin
      if (io_master_arvalid && io_master_arready) begin
        last_axi_araddr_r                    <= io_master_araddr;
        last_axi_araddrs[axi_ar_wr_ptr]      <= io_master_araddr;
        axi_ar_wr_ptr                        <= (axi_ar_wr_ptr + 1) % 4;
      end
      if (dut.regFile.io_wbReq_writeEn && dut.regFile.io_wbReq_rd == 4'd10 &&
          !$isunknown(dut.regFile.io_wbReq_writeEn) && !$isunknown(dut.regFile.io_wbReq_rd)) begin
        last_x10_write_data <= dut.regFile.io_wbReq_writeData;
        last_x10_write_inst <= inst_count;
        last_x10_write_pc   <= dut._wbu_io_pc;
        if (x10_write_cnt < 4) begin
          x10_write_history_data[x10_write_cnt] <= dut.regFile.io_wbReq_writeData;
          x10_write_history_inst[x10_write_cnt] <= inst_count;
          x10_write_history_pc  [x10_write_cnt] <= dut._wbu_io_pc;
        end
        x10_write_cnt <= x10_write_cnt + 1;
      end
    end
  end
`endif

`ifndef NETLIST
  reg [31:0] csr_wr_cnt;
  always @(posedge clock) begin
    if (reset) begin
      csr_wr_cnt <= 0;
    end else begin
      if (dut._wbu_io_CsrFileReq_regWriteEn && !$isunknown(dut._wbu_io_CsrFileReq_regWriteEn)) begin
        csr_wr_cnt <= csr_wr_cnt + 1;
        if (csr_wr_cnt < 5) begin
          $display("CSR_WR[%0d]: addr=%h data=%h at %0t",
                   csr_wr_cnt,
                   dut._wbu_io_CsrFileReq_regAddr,
                   dut._wbu_io_CsrFileReq_regWriteData,
                   $time);
        end
      end
    end
  end
`endif

`ifdef NETLIST
  `define GET_EXCEPTION dut._wbu_io_exception
  `define GET_EXCEPTION_NUM dut._wbu_io_exceptionNum
  `define REG_10 (dut.\regFile/regs_10 )
  // `define GET_EXCEPTION (dut.\wbu.mauReq_exception && dut.\wbu.state )
  // `define GET_EXCEPTION_NUM dut._wbu_io_exceptionNum
  // `define GET_EXCEPTION_NUM {dut._wbu_io_exceptionNum_3_, \
  //                            dut._wbu_io_exceptionNum_2_, \
  //                            dut._wbu_io_exceptionNum_1_, \
  //                            dut._wbu_io_exceptionNum_0_}
  // `define REG_10 dut.\regFile.regs_10
  // `define REG_10 {dut.\regFile.regs_10_31_ , \
  //                 dut.\regFile.regs_10_30_ , \
  //                 dut.\regFile.regs_10_29_ , \
  //                 dut.\regFile.regs_10_28_ , \
  //                 dut.\regFile.regs_10_27_ , \
  //                 dut.\regFile.regs_10_26_ , \
  //                 dut.\regFile.regs_10_25_ , \
  //                 dut.\regFile.regs_10_24_ , \
  //                 dut.\regFile.regs_10_23_ , \
  //                 dut.\regFile.regs_10_22_ , \
  //                 dut.\regFile.regs_10_21_ , \
  //                 dut.\regFile.regs_10_20_ , \
  //                 dut.\regFile.regs_10_19_ , \
  //                 dut.\regFile.regs_10_18_ , \
  //                 dut.\regFile.regs_10_17_ , \
  //                 dut.\regFile.regs_10_16_ , \
  //                 dut.\regFile.regs_10_15_ , \
  //                 dut.\regFile.regs_10_14_ , \
  //                 dut.\regFile.regs_10_13_ , \
  //                 dut.\regFile.regs_10_12_ , \
  //                 dut.\regFile.regs_10_11_ , \
  //                 dut.\regFile.regs_10_10_ , \
  //                 dut.\regFile.regs_10_9_ , \
  //                 dut.\regFile.regs_10_8_ , \
  //                 dut.\regFile.regs_10_7_ , \
  //                 dut.\regFile.regs_10_6_ , \
  //                 dut.\regFile.regs_10_5_ , \
  //                 dut.\regFile.regs_10_4_ , \
  //                 dut.\regFile.regs_10_3_ , \
  //                 dut.\regFile.regs_10_2_ , \
  //                 dut.\regFile.regs_10_1_ , \
  //                 dut.\regFile.regs_10_0_ }
`else
  `define GET_EXCEPTION dut._wbu_io_exception
  `define GET_EXCEPTION_NUM dut._wbu_io_exceptionNum
  `define REG_10 dut.regFile.regs_10
`endif
`define GET_EBREAK_DETECTED `GET_EXCEPTION && (`GET_EXCEPTION_NUM == 4'd3)
always @(posedge clock) begin
  if (!reset && `GET_EXCEPTION) begin
    $display("[%0d] exceptionNum=%b", cycle_count, `GET_EXCEPTION_NUM);
    if(`GET_EXCEPTION_NUM == 4'd3) begin
      if(`REG_10 == 0) begin
        $display("HIT GOOD TRAP");
      end else begin
        $display("HIT BAD TRAP");
      end
      $finish;
    end else if(`GET_EXCEPTION_NUM == 4'd2) begin
      $display("HIT BAD TRAP");
      $finish;
    end
  end
end

`ifndef NETLIST
  parameter PIPELINE_STALL_THRESHOLD = 4096;
  reg [1:0]  last_ifu_state;
  reg [2:0]  last_idu_state;
  reg [1:0]  last_exu_state;
  reg [2:0]  last_mau_state;
  reg        last_wbu_state;
  reg [31:0] stall_cycles;
  wire       pipeline_x = $isunknown(dut.ifu.state) || $isunknown(dut.idu.state) ||
                          $isunknown(dut.exu.state) || $isunknown(dut.mau.state) ||
                          $isunknown(dut.wbu.state);
  always @(posedge clock) begin
    if (reset) begin
      last_ifu_state <= 0; last_idu_state <= 0; last_exu_state <= 0;
      last_mau_state <= 0; last_wbu_state <= 0; stall_cycles <= 0;
    end else if (pipeline_x) begin
      $display("TIMEOUT: pipeline X at inst %0d", inst_count);
      $display("  ifu: state=%b pc=%h npc_ifu2idu=%h inst=%h",
               dut.ifu.state, dut.ifu.pcReg,
               dut._ifu_io_idu_bits_npc, dut.ifu.instReg);
      $display("  idu: state=%b pc=%h npc_idu2exu=%h",
               dut.idu.state, dut._idu_io_toEXU_bits_pc,
               dut._idu_io_toEXU_bits_npc);
      $display("  exu: state=%b pc=%h npc=%h redirect_valid=%0d redirect_npc=%h",
               dut.exu.state, dut._exu_io_mau_bits_pc,
               dut._exu_io_mau_bits_npc,
               dut._exu_io_pcRedirect_valid, dut._exu_io_pcRedirect_npc);
      $display("       rs1Data=%h rs2Data=%h branchTaken=%0d predictFail=%0d",
               dut.exu.decodeInfo_rs1Data, dut.exu.decodeInfo_rs2Data,
               dut.exu.branchTaken, dut.exu.predictFail);
      $display("       isBranch=%0d isJal=%0d isJalr=%0d isCtrl=%0d",
               dut.exu.decodeInfo_isBranch, dut.exu.decodeInfo_isJal,
               dut.exu.decodeInfo_isJalr, dut.exu.isControlTransfer);
      $display("  mau: state=%b pc=%h npc_mau2wbu=%h",
               dut.mau.state, dut._mau_io_wbu_bits_pc,
               dut._mau_io_wbu_bits_npc);
      $display("  wbu: state=%b pc=%h exc=%0d excNum=%0d",
               dut.wbu.state, dut._wbu_io_pc,
               dut._wbu_io_exception, dut._wbu_io_exceptionNum);
      $display("  csr: redirect_valid=%0d npc=%h mtvec=%h mepc=%h",
               dut._csrRegFile_pcRedirect_valid, dut._csrRegFile_pcRedirect_npc,
               dut.csrRegFile.mtvecReg, dut.csrRegFile.mepcReg);
      $display("  bp: predict_npc=%h predict_pc=%h",
               dut.ifu.io_predict_npc, dut.ifu.io_predict_pc);
      // dump all registers
      $display("--- regFile dump (all 16 regs) ---");
      $display("  x0 =%h  ra=%h  sp=%h  gp=%h",
               dut.regFile.regs_0, dut.regFile.regs_1, dut.regFile.regs_2, dut.regFile.regs_3);
      $display("  tp =%h  t0=%h  t1=%h  t2=%h",
               dut.regFile.regs_4, dut.regFile.regs_5, dut.regFile.regs_6, dut.regFile.regs_7);
      $display("  s0 =%h  s1=%h  a0=%h  a1=%h",
               dut.regFile.regs_8, dut.regFile.regs_9, dut.regFile.regs_10, dut.regFile.regs_11);
      $display("  a2 =%h  a3=%h  a4=%h  a5=%h",
               dut.regFile.regs_12, dut.regFile.regs_13, dut.regFile.regs_14, dut.regFile.regs_15);
      $display("--- last write to x10 ---");
      $display("  inst=%0d pc=%h data=%h",
               last_x10_write_inst, last_x10_write_pc, last_x10_write_data);
      $display("  x10 write history (most recent first):");
      $display("    [0] inst=%0d pc=%h data=%h",
               x10_write_history_inst[0], x10_write_history_pc[0], x10_write_history_data[0]);
      $display("    [1] inst=%0d pc=%h data=%h",
               x10_write_history_inst[1], x10_write_history_pc[1], x10_write_history_data[1]);
      $display("    [2] inst=%0d pc=%h data=%h",
               x10_write_history_inst[2], x10_write_history_pc[2], x10_write_history_data[2]);
      $display("    [3] inst=%0d pc=%h data=%h",
               x10_write_history_inst[3], x10_write_history_pc[3], x10_write_history_data[3]);
      $display("--- recent AXI read addresses (loads) ---");
      $display("  last: ar=%h", last_axi_araddr_r);
      $display("  [0] %h  [1] %h  [2] %h  [3] %h",
               last_axi_araddrs[0], last_axi_araddrs[1],
               last_axi_araddrs[2], last_axi_araddrs[3]);
      $finish;
    end else begin
      if (dut.ifu.state        === last_ifu_state &&
          dut.idu.state        === last_idu_state &&
          dut.exu.state        === last_exu_state &&
          dut.mau.state        === last_mau_state &&
          dut.wbu.state        === last_wbu_state) begin
        if (stall_cycles < PIPELINE_STALL_THRESHOLD)
          stall_cycles <= stall_cycles + 1;
        else begin
          $display("TIMEOUT: pipeline stalled %0d cycles, inst=%0d",
                   PIPELINE_STALL_THRESHOLD, inst_count);
          $display("  ifu=%0d pc=%h  idu=%0d pc=%h  exu=%0d pc=%h  mau=%0d pc=%h  wbu=%0d pc=%h",
                   dut.ifu.state, dut.ifu.pcReg,
                   dut.idu.state, dut._idu_io_toEXU_bits_pc,
                   dut.exu.state, dut._exu_io_mau_bits_pc,
                   dut.mau.state, dut._mau_io_wbu_bits_pc,
                   dut.wbu.state, dut._wbu_io_pc);
          $finish;
        end
      end else begin
        stall_cycles   <= 0;
        last_ifu_state <= dut.ifu.state;
        last_idu_state <= dut.idu.state;
        last_exu_state <= dut.exu.state;
        last_mau_state <= dut.mau.state;
        last_wbu_state <= dut.wbu.state;
      end
    end
  end
`endif

endmodule
