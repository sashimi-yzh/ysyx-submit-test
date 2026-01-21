module fullsoc
#(
    parameter INIT_FILE = "default.hex"  // 初始化文件路径
)
(
    input         clk,
    input         reset
);

// AXI signals between CPU and XBAR
// CPU is master, XBAR is slave
wire cpu_awvalid;
wire cpu_awready;
wire [31:0] cpu_awaddr;
wire [3:0] cpu_awid;
wire [7:0] cpu_awlen;
wire [2:0] cpu_awsize;
wire [1:0] cpu_awburst;
wire cpu_wvalid;
wire cpu_wready;
wire [31:0] cpu_wdata;
wire [3:0] cpu_wstrb;
wire cpu_wlast;
wire cpu_bvalid;
wire cpu_bready;
wire [1:0] cpu_bresp;
wire [3:0] cpu_bid;
wire cpu_arvalid;
wire cpu_arready;
wire [31:0] cpu_araddr;
wire [3:0] cpu_arid;
wire [7:0] cpu_arlen;
wire [2:0] cpu_arsize;
wire [1:0] cpu_arburst;
wire cpu_rvalid;
wire cpu_rready;
wire [31:0] cpu_rdata;
wire [1:0] cpu_rresp;
wire cpu_rlast;
wire [3:0] cpu_rid;

ysyx_25050136 u_ysyx_25050136(
    .clock             	(clk              ),
    .reset             	(reset            ),
    .io_interrupt      	(1'b0             ), // Tie off interrupt
    .io_master_awready 	(cpu_awready      ),
    .io_master_awvalid 	(cpu_awvalid      ),
    .io_master_awaddr  	(cpu_awaddr       ),
    .io_master_awid    	(cpu_awid         ),
    .io_master_awlen   	(cpu_awlen        ),
    .io_master_awsize  	(cpu_awsize       ),
    .io_master_awburst 	(cpu_awburst      ),
    .io_master_wready  	(cpu_wready       ),
    .io_master_wvalid  	(cpu_wvalid       ),
    .io_master_wdata   	(cpu_wdata        ),
    .io_master_wstrb   	(cpu_wstrb        ),
    .io_master_wlast   	(cpu_wlast        ),
    .io_master_bready  	(cpu_bready       ),
    .io_master_bvalid  	(cpu_bvalid       ),
    .io_master_bresp   	(cpu_bresp        ),
    .io_master_bid     	(cpu_bid          ),
    .io_master_arready 	(cpu_arready      ),
    .io_master_arvalid 	(cpu_arvalid      ),
    .io_master_araddr  	(cpu_araddr       ),
    .io_master_arid    	(cpu_arid         ),
    .io_master_arlen   	(cpu_arlen        ),
    .io_master_arsize  	(cpu_arsize       ),
    .io_master_arburst 	(cpu_arburst      ),
    .io_master_rready  	(cpu_rready       ),
    .io_master_rvalid  	(cpu_rvalid       ),
    .io_master_rresp   	(cpu_rresp        ),
    .io_master_rdata   	(cpu_rdata        ),
    .io_master_rlast   	(cpu_rlast        ),
    .io_master_rid     	(cpu_rid          ),
    // Unused slave interface, tie off inputs
    .io_slave_awready       (/* unused */),
    .io_slave_awvalid       (1'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_awid     (4'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_awaddr   (32'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_awlen    (8'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_awsize   (3'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_awburst  (2'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_wready        (/* unused */),
    .io_slave_wvalid        (1'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_wdata    (32'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_wstrb    (4'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_wlast    (1'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_bready        (1'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_bvalid        (/* unused */),
    .io_slave_bid      (/* unused */),
    .io_slave_bresp    (/* unused */),
    .io_slave_arready       (/* unused */),
    .io_slave_arvalid       (1'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_arid     (4'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_araddr   (32'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_arlen    (8'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_arsize   (3'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_arburst  (2'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
    .io_slave_rready        (1'h0),	// home/yunhai/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_rvalid        (/* unused */),
    .io_slave_rid      (/* unused */),
    .io_slave_rdata    (/* unused */),
    .io_slave_rresp    (/* unused */),
    .io_slave_rlast    (/* unused */)
);

// AXI signals between XBAR and Slaves (SRAM, UART)
// XBAR is master, Slaves are slaves
localparam SLAVER_NUM = 2;
localparam ADDR_WIDTH = 32;
localparam DATA_WIDTH = 32;

// XBAR to Slaves
wire [SLAVER_NUM-1:0] m_awvalid;
wire [SLAVER_NUM-1:0] m_awready;
wire [SLAVER_NUM*ADDR_WIDTH-1:0] m_awaddr;
wire [SLAVER_NUM*4-1:0] m_awid;
wire [SLAVER_NUM*8-1:0] m_awlen;
wire [SLAVER_NUM*3-1:0] m_awsize;
wire [SLAVER_NUM*2-1:0] m_awburst;
wire [SLAVER_NUM-1:0] m_wvalid;
wire [SLAVER_NUM-1:0] m_wready;
wire [SLAVER_NUM*DATA_WIDTH-1:0] m_wdata;
wire [SLAVER_NUM*4-1:0] m_wstrb;
wire [SLAVER_NUM-1:0] m_wlast;
wire [SLAVER_NUM-1:0] m_bvalid;
wire [SLAVER_NUM-1:0] m_bready;
wire [SLAVER_NUM*2-1:0] m_bresp;
wire [SLAVER_NUM*4-1:0] m_bid;
wire [SLAVER_NUM-1:0] m_arvalid;
wire [SLAVER_NUM-1:0] m_arready;
wire [SLAVER_NUM*ADDR_WIDTH-1:0] m_araddr;
wire [SLAVER_NUM*4-1:0] m_arid;
wire [SLAVER_NUM*8-1:0] m_arlen;
wire [SLAVER_NUM*3-1:0] m_arsize;
wire [SLAVER_NUM*2-1:0] m_arburst;
wire [SLAVER_NUM-1:0] m_rvalid;
wire [SLAVER_NUM-1:0] m_rready;
wire [SLAVER_NUM*DATA_WIDTH-1:0] m_rdata;
wire [SLAVER_NUM*2-1:0] m_rresp;
wire [SLAVER_NUM-1:0] m_rlast;
wire [SLAVER_NUM*4-1:0] m_rid;

ysyx_25050136_XBAR #(
    .SLAVER_NUM 	(SLAVER_NUM ),
    .DATA_WIDTH 	(DATA_WIDTH ),
    .ADDR_WIDTH 	(ADDR_WIDTH ))
u_ysyx_25050136_XBAR(
    .aclk        	(clk          ),
    .reset      	(reset        ),
    // Slave Interface (from CPU)
    .s_awvalid_i 	(cpu_awvalid  ),
    .s_awready_o 	(cpu_awready  ),
    .s_awaddr_i  	(cpu_awaddr   ),
    .s_awid_i    	(cpu_awid     ),
    .s_awlen_i   	(cpu_awlen    ),
    .s_awsize_i  	(cpu_awsize   ),
    .s_awburst_i 	(cpu_awburst  ),
    .s_wvalid_i  	(cpu_wvalid   ),
    .s_wready_o  	(cpu_wready   ),
    .s_wdata_i   	(cpu_wdata    ),
    .s_wstrb_i   	(cpu_wstrb    ),
    .s_wlast_i   	(cpu_wlast    ),
    .s_bvalid_o  	(cpu_bvalid   ),
    .s_bready_i  	(cpu_bready   ),
    .s_bresp_o   	(cpu_bresp    ),
    .s_bid_o     	(cpu_bid      ),
    .s_arvalid_i 	(cpu_arvalid  ),
    .s_arready_o 	(cpu_arready  ),
    .s_araddr_i  	(cpu_araddr   ),
    .s_arid_i    	(cpu_arid     ),
    .s_arlen_i   	(cpu_arlen    ),
    .s_arsize_i  	(cpu_arsize   ),
    .s_arburst_i 	(cpu_arburst  ),
    .s_rvalid_o  	(cpu_rvalid   ),
    .s_rready_i  	(cpu_rready   ),
    .s_rdata_o   	(cpu_rdata    ),
    .s_rresp_o   	(cpu_rresp    ),
    .s_rlast_o   	(cpu_rlast    ),
    .s_rid_o     	(cpu_rid      ),
    // Master Interface (to Slaves)
    .m_awvalid_o 	(m_awvalid    ),
    .m_awready_i 	(m_awready    ),
    .m_awaddr_o  	(m_awaddr     ),
    .m_awid_o    	(m_awid       ),
    .m_awlen_o   	(m_awlen      ),
    .m_awsize_o  	(m_awsize     ),
    .m_awburst_o 	(m_awburst    ),
    .m_wvalid_o  	(m_wvalid     ),
    .m_wready_i  	(m_wready     ),
    .m_wdata_o   	(m_wdata      ),
    .m_wstrb_o   	(m_wstrb      ),
    .m_wlast_o   	(m_wlast      ),
    .m_bvalid_i  	(m_bvalid     ),
    .m_bready_o  	(m_bready     ),
    .m_bresp_i   	(m_bresp      ),
    .m_bid_i     	(m_bid        ),
    .m_arvalid_o 	(m_arvalid    ),
    .m_arready_i 	(m_arready    ),
    .m_araddr_o  	(m_araddr     ),
    .m_arid_o    	(m_arid       ),
    .m_arlen_o   	(m_arlen      ),
    .m_arsize_o  	(m_arsize     ),
    .m_arburst_o 	(m_arburst    ),
    .m_rvalid_i  	(m_rvalid     ),
    .m_rready_o  	(m_rready     ),
    .m_rdata_i   	(m_rdata      ),
    .m_rresp_i   	(m_rresp      ),
    .m_rlast_i   	(m_rlast      ),
    .m_rid_i     	(m_rid        )
);

// Slave 0: SRAM
ysyx_25050136_SRAM #(
    .ADDR_WIDTH 	(ADDR_WIDTH ),
    .DATA_WIDTH 	(DATA_WIDTH ),
    .INIT_FILE  	(INIT_FILE   ))
u_ysyx_25050136_SRAM(
    .clk         	(clk                                    ),
    .reset       	(reset                                  ),
    .s_awvalid_i 	(m_awvalid[1]                           ),
    .s_awready_o 	(m_awready[1]                           ),
    .s_awaddr_i  	(m_awaddr[2*ADDR_WIDTH-1:ADDR_WIDTH]    ),
    .s_awid_i    	(m_awid[7:4]                            ),
    .s_awlen_i   	(m_awlen[15:8]                          ),
    .s_awsize_i  	(m_awsize[5:3]                          ),
    .s_awburst_i 	(m_awburst[3:2]                         ),
    .s_wvalid_i  	(m_wvalid[1]                            ),
    .s_wready_o  	(m_wready[1]                            ),
    .s_wdata_i   	(m_wdata[2*DATA_WIDTH-1:DATA_WIDTH]     ),
    .s_wstrb_i   	(m_wstrb[7:4]                           ),
    .s_wlast_i   	(m_wlast[1]                             ),
    .s_bvalid_o  	(m_bvalid[1]                            ),
    .s_bready_i  	(m_bready[1]                            ),
    .s_bresp_o   	(m_bresp[3:2]                           ),
    .s_bid_o     	(m_bid[7:4]                             ),
    .s_arvalid_i 	(m_arvalid[1]                           ),
    .s_arready_o 	(m_arready[1]                           ),
    .s_araddr_i  	(m_araddr[2*ADDR_WIDTH-1:ADDR_WIDTH]    ),
    .s_arid_i    	(m_arid[7:4]                            ),
    .s_arlen_i   	(m_arlen[15:8]                          ),
    .s_arsize_i  	(m_arsize[5:3]                          ),
    .s_arburst_i 	(m_arburst[3:2]                         ),
    .s_rvalid_o  	(m_rvalid[1]                            ),
    .s_rready_i  	(m_rready[1]                            ),
    .s_rlast_o   	(m_rlast[1]                             ),
    .s_rdata_o   	(m_rdata[2*DATA_WIDTH-1:DATA_WIDTH]     ),
    .s_rresp_o   	(m_rresp[3:2]                           ),
    .s_rid_o     	(m_rid[7:4]                             )
);

// Slave 1: UART
ysyx_25050136_UART #(
    .ADDR_WIDTH 	(ADDR_WIDTH ),
    .DATA_WIDTH 	(DATA_WIDTH ))
u_ysyx_25050136_UART(
    .clk         	(clk                                    ),
    .reset       	(reset                                  ),
    .s_awvalid_i 	(m_awvalid[0]                           ),
    .s_awready_o 	(m_awready[0]                           ),
    .s_awaddr_i  	(m_awaddr[ADDR_WIDTH-1:0]               ),
    .s_awid_i    	(m_awid[3:0]                            ),
    .s_awlen_i   	(m_awlen[7:0]                           ),
    .s_awsize_i  	(m_awsize[2:0]                          ),
    .s_awburst_i 	(m_awburst[1:0]                         ),
    .s_wvalid_i  	(m_wvalid[0]                            ),
    .s_wready_o  	(m_wready[0]                            ),
    .s_wdata_i   	(m_wdata[DATA_WIDTH-1:0]                ),
    .s_wstrb_i   	(m_wstrb[3:0]                           ),
    .s_wlast_i   	(m_wlast[0]                             ),
    .s_bvalid_o  	(m_bvalid[0]                            ),
    .s_bready_i  	(m_bready[0]                            ),
    .s_bresp_o   	(m_bresp[1:0]                           ),
    .s_bid_o     	(m_bid[3:0]                             ),
    .s_arvalid_i 	(m_arvalid[0]                           ),
    .s_arready_o 	(m_arready[0]                           ),
    .s_araddr_i  	(m_araddr[ADDR_WIDTH-1:0]               ),
    .s_arid_i    	(m_arid[3:0]                            ),
    .s_arlen_i   	(m_arlen[7:0]                           ),
    .s_arsize_i  	(m_arsize[2:0]                          ),
    .s_arburst_i 	(m_arburst[1:0]                         ),
    .s_rvalid_o  	(m_rvalid[0]                            ),
    .s_rready_i  	(m_rready[0]                            ),
    .s_rlast_o   	(m_rlast[0]                             ),
    .s_rdata_o   	(m_rdata[DATA_WIDTH-1:0]                ),
    .s_rresp_o   	(m_rresp[1:0]                           ),
    .s_rid_o     	(m_rid[3:0]                             )
);

endmodule