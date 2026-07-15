`ifndef SYNTHESIS
    import PKG::perf_cnt_update;
    import PKG::sim_exit;
`endif
module IFU(
    input clk,
    input reset,

    output [31:0] m_Inst,
    output [31:0] m_PC,
    output [1:0] m_meta_data_BTB,
    output m_hit_BTB,
    output m_has_exception,
    output [3:0] m_exception_code,
    output m_valid,
    input m_ready,

    input [31:0] PC,
    input [1:0] meta_data_BTB,
    input hit_BTB,

    input flush,
    input cache_flush,
    input exception_flush,

    //axi interface to RAM
    output [31:0] m_axi_araddr,
    output m_axi_arvalid,
    input m_axi_arready,
    output [3:0] m_axi_arid,
    output [7:0] m_axi_arlen,
    output [2:0] m_axi_arsize,
    output [1:0] m_axi_arburst,

    input [31:0] m_axi_rdata,
    input [1:0] m_axi_rresp,
    input [3:0] m_axi_rid,
    input m_axi_rlast,
    input m_axi_rvalid,
    output m_axi_rready,

    output [31:0] m_axi_awaddr,
    output m_axi_awvalid,
    input m_axi_awready,
    output [3:0] m_axi_awid,
    output [7:0] m_axi_awlen,
    output [2:0] m_axi_awsize,
    output [1:0] m_axi_awburst,

    output [31:0] m_axi_wdata,
    output [3:0] m_axi_wstrb,
    output m_axi_wvalid,
    output m_axi_wlast,
    input m_axi_wready,

    input [1:0] m_axi_bresp,
    input m_axi_bvalid,
    input [3:0] m_axi_bid,
    output m_axi_bready,
    /*verilator lint_on UNUSED*/

    output pc_en
);
`ifndef SYNTHESIS
    always @(posedge clk) begin
        if(m_valid && m_ready) begin
            perf_cnt_update(0);
        end
    end

    always @(*) begin
        if(PC==32'h00000010) begin
            sim_exit();
        end
    end
`endif


    wire s_ready;
    wire s_valid = 1'b1;

    ICACHE #(
        .LINE_NUM  	( 4  ),
        .LINE_SIZE 	( 16  ))
    u_ICACHE(
        .clk            	( clk             ),
        .reset          	( reset           ),
        .cache_flush    	( cache_flush     ),
        .flush          	( flush           ),
        .exception_flush    ( exception_flush ),

        .s_raddr            ( PC    ),
        .s_meta_data_BTB    ( meta_data_BTB    ),
        .s_hit_BTB          ( hit_BTB         ),
        .s_valid            ( s_valid   ),
        .s_ready            ( s_ready   ),
        .m_data             ( m_Inst     ),
        .m_pc               ( m_PC  ),
        .m_meta_data_BTB    ( m_meta_data_BTB ),
        .m_hit_BTB          ( m_hit_BTB         ),
        .m_has_exception    ( m_has_exception ),
        .m_exception_code   ( m_exception_code ),
        .m_valid            ( m_valid    ),
        .m_ready            ( m_ready    ),

        .m_axi_araddr   	( m_axi_araddr    ),
        .m_axi_arvalid  	( m_axi_arvalid   ),
        .m_axi_arready  	( m_axi_arready   ),
        .m_axi_arid     	( m_axi_arid      ),
        .m_axi_arlen    	( m_axi_arlen     ),
        .m_axi_arsize   	( m_axi_arsize    ),
        .m_axi_arburst  	( m_axi_arburst   ),
        .m_axi_rdata    	( m_axi_rdata     ),
        .m_axi_rresp    	( m_axi_rresp     ),
        .m_axi_rid      	( m_axi_rid       ),
        .m_axi_rlast    	( m_axi_rlast     ),
        .m_axi_rvalid   	( m_axi_rvalid    ),
        .m_axi_rready   	( m_axi_rready    ),
        .m_axi_awaddr   	( m_axi_awaddr    ),
        .m_axi_awvalid  	( m_axi_awvalid   ),
        .m_axi_awready  	( m_axi_awready   ),
        .m_axi_awid     	( m_axi_awid      ),
        .m_axi_awlen    	( m_axi_awlen     ),
        .m_axi_awsize   	( m_axi_awsize    ),
        .m_axi_awburst  	( m_axi_awburst   ),
        .m_axi_wdata    	( m_axi_wdata     ),
        .m_axi_wstrb    	( m_axi_wstrb     ),
        .m_axi_wvalid   	( m_axi_wvalid    ),
        .m_axi_wlast    	( m_axi_wlast     ),
        .m_axi_wready   	( m_axi_wready    ),
        .m_axi_bresp    	( m_axi_bresp     ),
        .m_axi_bvalid   	( m_axi_bvalid    ),
        .m_axi_bid      	( m_axi_bid       ),
        .m_axi_bready   	( m_axi_bready    )
    );


    assign pc_en = s_valid && s_ready;



endmodule
