module npc_top(
    input       clk,
    input       reset
);

    // output declaration of module cpu_top
    wire            io_master_awvalid;
    wire [31:0]     io_master_awaddr;
    wire [3:0]      io_master_awid;
    wire [7:0]      io_master_awlen;
    wire [2:0]      io_master_awsize;
    wire [1:0]      io_master_awburst;
    wire            io_master_wvalid;
    wire [31:0]     io_master_wdata;
    wire [3:0]      io_master_wstrb;
    wire            io_master_wlast;
    wire            io_master_bready;
    wire            io_master_arvalid;
    wire [31:0]     io_master_araddr;
    wire [3:0]      io_master_arid;
    wire [7:0]      io_master_arlen;
    wire [2:0]      io_master_arsize;
    wire [1:0]      io_master_arburst;
    wire            io_master_rready;
    wire            io_master_awready;
    wire            io_master_wready;
    wire            io_master_bvalid;
    wire [1:0]      io_master_bresp;
    wire [3:0]      io_master_bid;
    wire            io_master_arready;
    wire            io_master_rvalid;
    wire [1:0]      io_master_rresp;
    wire [31:0]     io_master_rdata;
    wire            io_master_rlast;
    wire [3:0]      io_master_rid;

    wire            io_slave_awready;
    wire            io_slave_wready;
    wire            io_slave_bvalid;
    wire [1:0]      io_slave_bresp;
    wire [3:0]      io_slave_bid;
    wire            io_slave_arready;
    wire            io_slave_rvalid;
    wire [1:0]      io_slave_rresp;
    wire [31:0]     io_slave_rdata;
    wire            io_slave_rlast;
    wire [3:0]      io_slave_rid;

    wire io_interrupt = 1'b0;
    
    ysyx_25040102 u_cpu_top(
        .io_master_awready 	(io_master_awready  ),
        .io_master_awvalid 	(io_master_awvalid  ),
        .io_master_awaddr  	(io_master_awaddr   ),
        .io_master_awid    	(io_master_awid     ),
        .io_master_awlen   	(io_master_awlen    ),
        .io_master_awsize  	(io_master_awsize   ),
        .io_master_awburst 	(io_master_awburst  ),
        .io_master_wready  	(io_master_wready   ),
        .io_master_wvalid  	(io_master_wvalid   ),
        .io_master_wdata   	(io_master_wdata    ),
        .io_master_wstrb   	(io_master_wstrb    ),
        .io_master_wlast   	(io_master_wlast    ),
        .io_master_bready  	(io_master_bready   ),
        .io_master_bvalid  	(io_master_bvalid   ),
        .io_master_bresp   	(io_master_bresp    ),
        .io_master_bid     	(io_master_bid      ),
        .io_master_arready 	(io_master_arready  ),
        .io_master_arvalid 	(io_master_arvalid  ),
        .io_master_araddr  	(io_master_araddr   ),
        .io_master_arid    	(io_master_arid     ),
        .io_master_arlen   	(io_master_arlen    ),
        .io_master_arsize  	(io_master_arsize   ),
        .io_master_arburst 	(io_master_arburst  ),
        .io_master_rready  	(io_master_rready   ),
        .io_master_rvalid  	(io_master_rvalid   ),
        .io_master_rresp   	(io_master_rresp    ),
        .io_master_rdata   	(io_master_rdata    ),
        .io_master_rlast   	(io_master_rlast    ),
        .io_master_rid     	(io_master_rid      ),
        .io_slave_awready  	(io_slave_awready   ),
        .io_slave_awvalid  	(0                  ),
        .io_slave_awaddr   	(0                  ),
        .io_slave_awid     	(0                  ),
        .io_slave_awlen    	(0                  ),
        .io_slave_awsize   	(0                  ),
        .io_slave_awburst  	(0                  ),
        .io_slave_wready   	(io_slave_wready    ),
        .io_slave_wvalid   	(0                  ),
        .io_slave_wdata    	(0                  ),
        .io_slave_wstrb    	(0                  ),
        .io_slave_wlast    	(0                  ),
        .io_slave_bready   	(0                  ),
        .io_slave_bvalid   	(io_slave_bvalid    ),
        .io_slave_bresp    	(io_slave_bresp     ),
        .io_slave_bid      	(io_slave_bid       ),
        .io_slave_arready  	(io_slave_arready   ),
        .io_slave_arvalid  	(0                  ),
        .io_slave_araddr   	(0                  ),
        .io_slave_arid     	(0                  ),
        .io_slave_arlen    	(0                  ),
        .io_slave_arsize   	(0                  ),
        .io_slave_arburst  	(0                  ),
        .io_slave_rready   	(0                  ),
        .io_slave_rvalid   	(io_slave_rvalid    ),
        .io_slave_rresp    	(io_slave_rresp     ),
        .io_slave_rdata    	(io_slave_rdata     ),
        .io_slave_rlast    	(io_slave_rlast     ),
        .io_slave_rid      	(io_slave_rid       ),
        .clock             	(clk                ),
        .reset             	(reset              ),
        .io_interrupt      	(io_interrupt       )
    );

    wire            axi_slave_awvalid;
    wire [26:0]     axi_slave_awaddr;
    wire [3:0]      axi_slave_awid;
    wire [7:0]      axi_slave_awlen;
    wire [2:0]      axi_slave_awsize;
    wire [1:0]      axi_slave_awburst;
    wire            axi_slave_wvalid;
    wire [31:0]     axi_slave_wdata;
    wire [3:0]      axi_slave_wstrb;
    wire            axi_slave_wlast;
    wire            axi_slave_bready;
    wire            axi_slave_awready;
    wire            axi_slave_wready;
    wire            axi_slave_bvalid;
    wire [1:0]      axi_slave_bresp;
    wire [3:0]      axi_slave_bid;

    wire            axi_slave_arvalid;
    wire [26:0]     axi_slave_araddr;
    wire [3:0]      axi_slave_arid;
    wire [7:0]      axi_slave_arlen;
    wire [2:0]      axi_slave_arsize;
    wire [1:0]      axi_slave_arburst;
    wire            axi_slave_rready;
    wire            axi_slave_arready;
    wire            axi_slave_rvalid;
    wire [1:0]      axi_slave_rresp;
    wire [31:0]     axi_slave_rdata;
    wire            axi_slave_rlast;
    wire [3:0]      axi_slave_rid;

    wire            uart_slave_awvalid;
    wire [26:0]     uart_slave_awaddr;
    wire [3:0]      uart_slave_awid;
    wire [7:0]      uart_slave_awlen;
    wire [2:0]      uart_slave_awsize;
    wire [1:0]      uart_slave_awburst;
    wire            uart_slave_wvalid;
    wire [31:0]     uart_slave_wdata;
    wire [3:0]      uart_slave_wstrb;
    wire            uart_slave_wlast;
    wire            uart_slave_bready;
    wire            uart_slave_awready;
    wire            uart_slave_wready;
    wire            uart_slave_bvalid;
    wire [1:0]      uart_slave_bresp;
    wire [3:0]      uart_slave_bid;

    
    axi4_delayer u_axi4_delayer(
        .clock       	(clk                ),
        .reset       	(reset              ),
        .in_arready  	(io_master_arready  ),
        .in_arvalid  	(io_master_arvalid  ),
        .in_arid     	(io_master_arid     ),
        .in_araddr   	(io_master_araddr   ),
        .in_arlen    	(io_master_arlen    ),
        .in_arsize   	(io_master_arsize   ),
        .in_arburst  	(io_master_arburst  ),
        .in_rready   	(io_master_rready   ),
        .in_rvalid   	(io_master_rvalid   ),
        .in_rid      	(io_master_rid      ),
        .in_rdata    	(io_master_rdata    ),
        .in_rresp    	(io_master_rresp    ),
        .in_rlast    	(io_master_rlast    ),
        .in_awready  	(io_master_awready  ),
        .in_awvalid  	(io_master_awvalid  ),
        .in_awid     	(io_master_awid     ),
        .in_awaddr   	(io_master_awaddr   ),
        .in_awlen    	(io_master_awlen    ),
        .in_awsize   	(io_master_awsize   ),
        .in_awburst  	(io_master_awburst  ),
        .in_wready   	(io_master_wready   ),
        .in_wvalid   	(io_master_wvalid   ),
        .in_wdata    	(io_master_wdata    ),
        .in_wstrb    	(io_master_wstrb    ),
        .in_wlast    	(io_master_wlast    ),
        .in_bready   	(io_master_bready   ),
        .in_bvalid   	(io_master_bvalid   ),
        .in_bid      	(io_master_bid      ),
        .in_bresp    	(io_master_bresp    ),
        .out_arready 	(axi_slave_arready  ),
        .out_arvalid 	(axi_slave_arvalid  ),
        .out_arid    	(axi_slave_arid     ),
        .out_araddr  	(axi_slave_araddr   ),
        .out_arlen   	(axi_slave_arlen    ),
        .out_arsize  	(axi_slave_arsize   ),
        .out_arburst 	(axi_slave_arburst  ),
        .out_rready  	(axi_slave_rready   ),
        .out_rvalid  	(axi_slave_rvalid   ),
        .out_rid     	(axi_slave_rid      ),
        .out_rdata   	(axi_slave_rdata    ),
        .out_rresp   	(axi_slave_rresp    ),
        .out_rlast   	(axi_slave_rlast    ),
        .out_awready 	(axi_slave_awready  ),
        .out_awvalid 	(axi_slave_awvalid  ),
        .out_awid    	(axi_slave_awid     ),
        .out_awaddr  	(axi_slave_awaddr   ),
        .out_awlen   	(axi_slave_awlen    ),
        .out_awsize  	(axi_slave_awsize   ),
        .out_awburst 	(axi_slave_awburst  ),
        .out_wready  	(axi_slave_wready   ),
        .out_wvalid  	(axi_slave_wvalid   ),
        .out_wdata   	(axi_slave_wdata    ),
        .out_wstrb   	(axi_slave_wstrb    ),
        .out_wlast   	(axi_slave_wlast    ),
        .out_bready  	(axi_slave_bready   ),
        .out_bvalid  	(axi_slave_bvalid   ),
        .out_bid     	(axi_slave_bid      ),
        .out_bresp   	(axi_slave_bresp    ),
        .uart_awready   (uart_slave_awready),
        .uart_awvalid   (uart_slave_awvalid),
        .uart_awid      (uart_slave_awid   ),
        .uart_awaddr    (uart_slave_awaddr ),
        .uart_awlen     (uart_slave_awlen  ),
        .uart_awsize    (uart_slave_awsize ),
        .uart_awburst   (uart_slave_awburst),
        .uart_wready    (uart_slave_wready ),
        .uart_wvalid    (uart_slave_wvalid ),
        .uart_wdata     (uart_slave_wdata  ),
        .uart_wstrb     (uart_slave_wstrb  ),
        .uart_wlast     (uart_slave_wlast  ),
        .uart_bready    (uart_slave_bready ),
        .uart_bvalid    (uart_slave_bvalid ),
        .uart_bid       (uart_slave_bid    ),
        .uart_bresp     (uart_slave_bresp  )
    );

    
    axi_ram u_axi_ram
    (
        .clk              	(clk                ),
        .rst            	(reset              ),
        .s_axi_awready 	    (axi_slave_awready  ),
        .s_axi_awvalid 	    (axi_slave_awvalid  ),
        .s_axi_awaddr  	    (axi_slave_awaddr   ),
        .s_axi_awid    	    (axi_slave_awid     ),
        .s_axi_awlen   	    (axi_slave_awlen    ),
        .s_axi_awsize  	    (axi_slave_awsize   ),
        .s_axi_awburst 	    (axi_slave_awburst  ),
        .s_axi_wready  	    (axi_slave_wready   ),
        .s_axi_wvalid  	    (axi_slave_wvalid   ),
        .s_axi_wdata   	    (axi_slave_wdata    ),
        .s_axi_wstrb   	    (axi_slave_wstrb    ),
        .s_axi_wlast   	    (axi_slave_wlast    ),
        .s_axi_bready  	    (axi_slave_bready   ),
        .s_axi_bvalid  	    (axi_slave_bvalid   ),
        .s_axi_bresp   	    (axi_slave_bresp    ),
        .s_axi_bid     	    (axi_slave_bid      ),
        .s_axi_arready 	    (axi_slave_arready  ),
        .s_axi_arvalid 	    (axi_slave_arvalid  ),
        .s_axi_araddr  	    (axi_slave_araddr   ),
        .s_axi_arid    	    (axi_slave_arid     ),
        .s_axi_arlen   	    (axi_slave_arlen    ),
        .s_axi_arsize  	    (axi_slave_arsize   ),
        .s_axi_arburst 	    (axi_slave_arburst  ),
        .s_axi_rready  	    (axi_slave_rready   ),
        .s_axi_rvalid  	    (axi_slave_rvalid   ),
        .s_axi_rresp   	    (axi_slave_rresp    ),
        .s_axi_rdata   	    (axi_slave_rdata    ),
        .s_axi_rlast   	    (axi_slave_rlast    ),
        .s_axi_rid     	    (axi_slave_rid      )
    );

    uart_npc u_uart_npc(
        .clk                (clk),
        .reset              (reset),
        .s_axi_awready 	    (uart_slave_awready         ),
        .s_axi_awvalid 	    (uart_slave_awvalid         ),
        .s_axi_awaddr  	    (uart_slave_awaddr          ),
        .s_axi_awid    	    (uart_slave_awid            ),
        .s_axi_awlen   	    (uart_slave_awlen           ),
        .s_axi_awsize  	    (uart_slave_awsize          ),
        .s_axi_awburst 	    (uart_slave_awburst         ),
        .s_axi_wready  	    (uart_slave_wready          ),
        .s_axi_wvalid  	    (uart_slave_wvalid          ),
        .s_axi_wdata   	    (uart_slave_wdata           ),
        .s_axi_wstrb   	    (uart_slave_wstrb           ),
        .s_axi_wlast   	    (uart_slave_wlast           ),
        .s_axi_bready  	    (uart_slave_bready          ),
        .s_axi_bvalid  	    (uart_slave_bvalid          ),
        .s_axi_bresp   	    (uart_slave_bresp           ),
        .s_axi_bid     	    (uart_slave_bid             )
    );
    
    


endmodule

