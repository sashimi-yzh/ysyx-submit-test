module iverilog_top;
  reg reset = 1;
  initial begin
   # 20 reset = 0;
  end

  reg clock = 0;
  always #1 clock = !clock;

  // wire stop;
  wire        axi_awready;
  wire        axi_awvalid;
  wire [31:0] axi_awaddr;
  wire [3:0]  axi_awid;
  wire [7:0]  axi_awlen;
  wire [2:0]  axi_awsize;
  wire [1:0]  axi_awburst;
  wire        axi_wready;
  wire        axi_wvalid;
  wire [31:0] axi_wdata;
  wire [3:0]  axi_wstrb;
  wire        axi_wlast;
  wire        axi_bready;
  wire        axi_bvalid;
  wire [1:0]  axi_bresp;
  wire [3:0]  axi_bid;
  wire        axi_arready;
  wire        axi_arvalid;
  wire [31:0] axi_araddr;
  wire [3:0]  axi_arid;
  wire [7:0]  axi_arlen;
  wire [2:0]  axi_arsize;
  wire [1:0]  axi_arburst;
  wire        axi_rready;
  wire        axi_rvalid;
  wire [1:0]  axi_rresp;
  wire [31:0] axi_rdata;
  wire        axi_rlast;
  wire [3:0]  axi_rid;

  ysyx_26010008 cpu(
    .clock             (clock),
    .reset             (reset),
    // .io_stop           (stop),
    .io_interrupt      (0),
    .io_master_awready (axi_awready),
    .io_master_awvalid (axi_awvalid),
    .io_master_awaddr  (axi_awaddr),
    .io_master_awid    (axi_awid),
    .io_master_awlen   (axi_awlen),
    .io_master_awsize  (axi_awsize),
    .io_master_awburst (axi_awburst),
    .io_master_wready  (axi_wready),
    .io_master_wvalid  (axi_wvalid),
    .io_master_wdata   (axi_wdata),
    .io_master_wstrb   (axi_wstrb),
    .io_master_wlast   (axi_wlast),
    .io_master_bready  (axi_bready),
    .io_master_bvalid  (axi_bvalid),
    .io_master_bresp   (axi_bresp),
    .io_master_bid     (axi_bid),
    .io_master_arready (axi_arready),
    .io_master_arvalid (axi_arvalid),
    .io_master_araddr  (axi_araddr),
    .io_master_arid    (axi_arid),
    .io_master_arlen   (axi_arlen),
    .io_master_arsize  (axi_arsize),
    .io_master_arburst (axi_arburst),
    .io_master_rready  (axi_rready),
    .io_master_rvalid  (axi_rvalid),
    .io_master_rresp   (axi_rresp),
    .io_master_rdata   (axi_rdata),
    .io_master_rlast   (axi_rlast),
    .io_master_rid     (axi_rid),
    .io_slave_awready  (),
    .io_slave_awvalid  (0),
    .io_slave_awaddr   (0),
    .io_slave_awid    (0),
    .io_slave_awlen   (0),
    .io_slave_awsize  (0),
    .io_slave_awburst (0),
    .io_slave_wready   (),
    .io_slave_wvalid   (0),
    .io_slave_wdata    (0),
    .io_slave_wstrb    (0),
    .io_slave_wlast    (0),
    .io_slave_bready   (0),
    .io_slave_bvalid   (),
    .io_slave_bresp    (),
    .io_slave_bid      (),
    .io_slave_arready  (),
    .io_slave_arvalid  (0),
    .io_slave_araddr   (0),
    .io_slave_arid    (0),
    .io_slave_arlen   (0),
    .io_slave_arsize  (0),
    .io_slave_arburst (0),
    .io_slave_rready   (0),
    .io_slave_rvalid   (),
    .io_slave_rresp    (),
    .io_slave_rdata    (),
    .io_slave_rlast    (),
    .io_slave_rid      ()
  );

  AxiSimDevice device(
    .clock             (clock),
    .reset             (reset),
    .io_master_awready (axi_awready),
    .io_master_awvalid (axi_awvalid),
    .io_master_awaddr  (axi_awaddr),
    .io_master_awid    (axi_awid),
    .io_master_awlen   (axi_awlen),
    .io_master_awsize  (axi_awsize),
    .io_master_awburst (axi_awburst),
    .io_master_wready  (axi_wready),
    .io_master_wvalid  (axi_wvalid),
    .io_master_wdata   (axi_wdata),
    .io_master_wstrb   (axi_wstrb),
    .io_master_wlast   (axi_wlast),
    .io_master_bready  (axi_bready),
    .io_master_bvalid  (axi_bvalid),
    .io_master_bresp   (axi_bresp),
    .io_master_bid     (axi_bid),
    .io_master_arready (axi_arready),
    .io_master_arvalid (axi_arvalid),
    .io_master_araddr  (axi_araddr),
    .io_master_arid    (axi_arid),
    .io_master_arlen   (axi_arlen),
    .io_master_arsize  (axi_arsize),
    .io_master_arburst (axi_arburst),
    .io_master_rready  (axi_rready),
    .io_master_rvalid  (axi_rvalid),
    .io_master_rresp   (axi_rresp),
    .io_master_rdata   (axi_rdata),
    .io_master_rlast   (axi_rlast),
    .io_master_rid     (axi_rid)
  );

  // initial begin
  //   $dumpfile("iverilog.vcd");
  //   $dumpvars(0, cpu);
  // end

  // always @(posedge stop) begin
  //   if (!reset) begin
  //     $display("Sim stop by ebreak at %t", $time);
  //     #5
  //     $finish;
  //   end
  // end
endmodule
