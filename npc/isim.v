`timescale 1ns / 1ps

module isim();

  // 驱动信号
  reg clock;
  reg reset;

  wire [31:0] us_awaddr;
  wire        su_awready;
  wire        us_awvalid;
  wire [2:0]  us_awsize;
  wire        su_wready;
  wire        us_wvalid;
  wire [31:0] us_wdata;
  wire [3:0]  us_wstrb;
  wire        us_wlast;
  wire        us_bready;
  wire        su_bvalid;
  wire        su_arready;
  wire        us_arvalid;
  wire [31:0] us_araddr;
  wire [2:0]  us_arsize;
  wire        us_rready;
  wire        su_rvalid;
  wire [31:0] su_rdata;
  wire [1:0]  us_arburst;
  wire [7:0]  us_arlen;

  // 生成时钟
  initial clock = 0;
  always #5 clock = ~clock; // 10ns周期 = 100MHz

  // 生成复位
  initial begin
    $display("start to reset...");
    reset = 1;
    #100;        // 100ns
    reset = 0;
  end

  ysyx_25040111 u_ysyx_25040111(
    .clock (clock),
    .reset (reset)
    ,.io_interrupt           (1'h0),	
    .io_master_awready      (su_awready),
    .io_master_awvalid      (us_awvalid),
    .io_master_awid         (/* unused */),
    .io_master_awaddr       (us_awaddr),
    .io_master_awlen        (/* unused */),
    .io_master_awsize       (us_awsize),
    .io_master_awburst      (/* unused */),
    .io_master_wready       (su_wready),
    .io_master_wvalid       (us_wvalid),
    .io_master_wdata        (us_wdata),
    .io_master_wstrb        (us_wstrb),
    .io_master_wlast        (us_wlast),
    .io_master_bready       (us_bready),
    .io_master_bvalid       (su_bvalid),
    .io_master_bid          (/* unused */),
    .io_master_bresp        (/* unused */),
    .io_master_arready      (su_arready),
    .io_master_arvalid      (us_arvalid),
    .io_master_arid         (/* unused */),
    .io_master_araddr       (us_araddr),
    .io_master_arlen        (us_arlen),
    .io_master_arsize       (us_arsize),
    .io_master_arburst      (us_arburst),
    .io_master_rready       (us_rready),
    .io_master_rvalid       (su_rvalid),
    .io_master_rid          (/* unused */),
    .io_master_rdata        (su_rdata),
    .io_master_rresp        (/* unused */),
    .io_master_rlast        (/* unused */),
    .io_slave_awready       (/* unused */),
    .io_slave_awvalid       (1'h0),
    .io_slave_awid          (4'h0),	
    .io_slave_awaddr        (32'h0),	
    .io_slave_awlen         (8'h0),	
    .io_slave_awsize        (3'h0),	
    .io_slave_awburst       (2'h0),	
    .io_slave_wready        (/* unused */),
    .io_slave_wvalid        (1'h0),
    .io_slave_wdata         (32'h0),	
    .io_slave_wstrb         (4'h0),	
    .io_slave_wlast         (1'h0),
    .io_slave_bready        (1'h0),
    .io_slave_bvalid        (/* unused */),
    .io_slave_bid           (/* unused */),
    .io_slave_bresp         (/* unused */),
    .io_slave_arready       (/* unused */),
    .io_slave_arvalid       (1'h0),
    .io_slave_arid          (4'h0),	
    .io_slave_araddr        (32'h0),	
    .io_slave_arlen         (8'h0),	
    .io_slave_arsize        (3'h0),	
    .io_slave_arburst       (2'h0),	
    .io_slave_rready        (1'h0),
    .io_slave_rvalid        (/* unused */),
    .io_slave_rid           (/* unused */),
    .io_slave_rdata         (/* unused */),
    .io_slave_rresp         (/* unused */),
    .io_slave_rlast         (/* unused */)
  );

  ysyx_25040111_sram u_ysyx_25040111_sram(
    .clock   	(clock       ),
    .reset   	(reset       ),
    .arburst  (us_arburst  ),
    .arlen    (us_arlen),
    .araddr  	(us_araddr   ),
    .arsize  	(us_arsize   ),
    .arvalid 	(us_arvalid  ),
    .arready 	(su_arready  ),
    .rdata   	(su_rdata    ),
    .rvalid  	(su_rvalid   ),
    .rready  	(us_rready   ),
    .awaddr  	(us_awaddr   ),
    .awvalid 	(us_awvalid  ),
    .awsize  	(us_awsize   ),
    .awready 	(su_awready  ),
    .wdata   	(us_wdata    ),
    .wstrb   	(us_wstrb    ),
    .wvalid  	(us_wvalid   ),
    .wlast   	(us_wlast    ),
    .wready  	(su_wready   ),
    .bvalid  	(su_bvalid   ),
    .bready  	(us_bready   )
  );

`ifdef NETLIST
initial begin
  // $dumpfile("waveform/fixed.vcd");
  // $dumpvars(0, isim);
end  
`else
// initial begin
//   $dumpfile("waveform/four.vcd");
//   $dumpvars(0, isim);
// end
`endif

  // 仿真运行时间
  //   initial begin
  //     #20000; // 20us
  
  //     $finish;
  //   end

endmodule
