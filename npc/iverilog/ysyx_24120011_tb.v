`timescale 1ns / 1ns
module ysyx_24120011_tb;
    parameter WAVE = 0;
    parameter CLOCK_PERIOD = 10;
    reg clock;
    reg reset;
    reg 	      awready	;
    reg 	      awvalid	;
    reg [31:0]	  awaddr	;
    reg [3:0]	  awid	    ;
    reg [7:0]	  awlen	    ;
    reg [2:0]	  awsize	;
    reg [1:0]	  awburst	;
    reg 	      wready	;
    reg 	      wvalid	;
    reg [31:0]	  wdata	    ;
    reg [3:0]	  wstrb	    ;
    reg 	      wlast	    ;
    reg 	      bready	;
    reg 	      bvalid	;
    reg [1:0]	  bresp	    ;
    reg [3:0]	  bid	    ;
    reg 	      arready	;
    reg 	      arvalid	;
    reg [31:0]	  araddr	;
    reg [3:0]	  arid	    ;
    reg [7:0]	  arlen	    ;
    reg [2:0]	  arsize	;
    reg [1:0]	  arburst	;
    reg 	      rready	;
    reg 	      rvalid	;
    reg [1:0]	  rresp	    ;
    reg [31:0]	  rdata	    ;
    reg 	      rlast	    ;
    reg [3:0]	  rid	    ;

    ysyx_24120011 u_ysyx_24120011(
        .clock              ( clock    ),
        .reset              ( reset    ),
        .io_interrupt       (          ),
        .io_master_awready  ( awready  ),
        .io_master_awvalid  ( awvalid  ),
        .io_master_awaddr   ( awaddr   ),
        .io_master_awid     ( awid     ),
        .io_master_awlen    ( awlen    ),
        .io_master_awsize   ( awsize   ),
        .io_master_awburst  ( awburst  ),
        .io_master_wready   ( wready   ),
        .io_master_wvalid   ( wvalid   ),
        .io_master_wdata    ( wdata    ),
        .io_master_wstrb    ( wstrb    ),
        .io_master_wlast    ( wlast    ),
        .io_master_bready   ( bready   ),
        .io_master_bvalid   ( bvalid   ),
        .io_master_bresp    ( bresp    ),
        .io_master_bid      ( bid      ),
        .io_master_arready  ( arready  ),
        .io_master_arvalid  ( arvalid  ),
        .io_master_araddr   ( araddr   ),
        .io_master_arid     ( arid     ),
        .io_master_arlen    ( arlen    ),
        .io_master_arsize   ( arsize   ),
        .io_master_arburst  ( arburst  ),
        .io_master_rready   ( rready   ),
        .io_master_rvalid   ( rvalid   ),
        .io_master_rresp    ( rresp    ),
        .io_master_rdata    ( rdata    ),
        .io_master_rlast    ( rlast    ),
        .io_master_rid      ( rid      ),
        .io_slave_awready   ( ),
        .io_slave_awvalid   ( ),
        .io_slave_awaddr    ( ),
        .io_slave_awid      ( ),
        .io_slave_awlen     ( ),
        .io_slave_awsize    ( ),
        .io_slave_awburst   ( ),
        .io_slave_wready    ( ),
        .io_slave_wvalid    ( ),
        .io_slave_wdata     ( ),
        .io_slave_wstrb     ( ),
        .io_slave_wlast     ( ),
        .io_slave_bready    ( ),
        .io_slave_bvalid    ( ),
        .io_slave_bresp     ( ),
        .io_slave_bid       ( ),
        .io_slave_arready   ( ),
        .io_slave_arvalid   ( ),
        .io_slave_araddr    ( ),
        .io_slave_arid      ( ),
        .io_slave_arlen     ( ),
        .io_slave_arsize    ( ),
        .io_slave_arburst   ( ),
        .io_slave_rready    ( ),
        .io_slave_rvalid    ( ),
        .io_slave_rresp     ( ),
        .io_slave_rdata     ( ),
        .io_slave_rlast     ( ),
        .io_slave_rid       ( )
    );
    ysyx_24120011_SRAMUART u_ysyx_24120011_SRAMUART(
        .clk     ( clock   ),
        .rst     ( reset   ),
        .araddr  ( araddr  ),
        .arvalid ( arvalid ),
        .arready ( arready ),
        .arid    ( arid    ),
        .arlen   ( arlen   ),
        .arsize  ( arsize  ),
        .arburst ( arburst ),
        .rdata   ( rdata   ),
        .rresp   ( rresp   ),
        .rvalid  ( rvalid  ),
        .rready  ( rready  ),
        .rlast   ( rlast   ),
        .rid     ( rid     ),
        .awaddr  ( awaddr  ),
        .awvalid ( awvalid ),
        .awready ( awready ),
        .awid    ( awid    ),
        .awlen   ( awlen   ),
        .awsize  ( awsize  ),
        .awburst ( awburst ),
        .wdata   ( wdata   ),
        .wstrb   ( wstrb   ),
        .wvalid  ( wvalid  ),
        .wready  ( wready  ),
        .wlast   ( wlast   ),
        .bresp   ( bresp   ),
        .bvalid  ( bvalid  ),
        .bready  ( bready  ),
        .bid     ( bid     )
    );


    initial begin
        clock = 0;
        forever #(CLOCK_PERIOD/2) clock = ~clock;
    end

    initial begin
        reset = 1;
        #15 reset = 0; 
    end

    generate
        if (WAVE == 1) begin
            initial begin
                $dumpfile("./log/iverilog.vcd");
                $dumpvars(0, ysyx_24120011_tb); 
            end
        end
    endgenerate

endmodule
