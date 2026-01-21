module ysyx_25050136_NPC
(
    input                                     clk,
    input                                   reset,
    // 指令相关
    // 读地址
    output                        inst_arvalid_o ,
    input                         inst_arready_i ,
    output   [31:0]               inst_araddr_o  ,
    output   [3:0]                inst_arid_o    ,
    output   [7:0]                inst_arlen_o   ,
    output   [2:0]                inst_arsize_o  ,
    output   [1:0]                inst_arburst_o ,
    // 读数据
    input                         inst_rvalid_i  ,
    output                        inst_rready_o  ,
    input    [31:0]               inst_rdata_i   ,
    input    [1:0]                inst_rresp_i   ,
    input                         inst_rlast_i   ,
    input    [3:0]                inst_rid_i     ,
    // 数据相关
    // 写地址                     
    output                        mem_awvalid_o  ,
    input                         mem_awready_i  ,
    output   [31:0]               mem_awaddr_o   ,
    output   [3:0]                mem_awid_o     ,
    output   [7:0]                mem_awlen_o    ,
    output   [2:0]                mem_awsize_o   ,
    output   [1:0]                mem_awburst_o  ,
    // 写数据                      
    output                        mem_wvalid_o   ,
    input                         mem_wready_i   ,
    output   [31:0]               mem_wdata_o    ,
    output   [3:0]                mem_wstrb_o    ,
    output                        mem_wlast_o    ,
    // 写响应                          
    input                         mem_bvalid_i   ,
    output                        mem_bready_o   ,
    input    [1:0]                mem_bresp_i    ,
    input    [3:0]                mem_bid_i      ,
    // 读地址                         
    output                        mem_arvalid_o  ,
    input                         mem_arready_i  ,
    output   [31:0]               mem_araddr_o   ,
    output   [3:0]                mem_arid_o     ,
    output   [7:0]                mem_arlen_o    ,
    output   [2:0]                mem_arsize_o   ,
    output   [1:0]                mem_arburst_o  ,
    // 读数据                         
    input                         mem_rvalid_i   ,
    output                        mem_rready_o   ,
    input    [31:0]               mem_rdata_i    ,
    input    [1:0]                mem_rresp_i    ,
    input                         mem_rlast_i    ,
    input    [3:0]                mem_rid_i      
);
`ifdef YSYXSOC
`ifdef EVENT_COUNTER
    always @(*) begin
        if(((inst_rresp_i != 2'd0) & inst_rvalid_i & inst_rready_o) | 
           ((mem_rresp_i != 2'd0) & mem_rvalid_i & mem_rready_o) | 
           ((mem_bresp_i != 2'd0) & mem_bvalid_i & mem_bready_o))
            find_resp();
    end
`endif
`endif
    // 内部信号定义
    wire inst_flush;
    wire inst_req_valid;
    wire [31:0] inst_req_addr;
    wire inst_ret_valid;
    wire inst_ret_last;
    wire [31:0] inst_ret_data;
    wire [31:0] mem_req_addr;
    wire [31:0] mem_ret_rdata;
    wire mem_ret_ready;
    wire mem_req_valid;
    wire mem_req_ren;
    wire mem_req_wen;
    wire [3:0]  mem_req_mask;
    wire [2:0]  mem_req_size;
    wire mem_req_use;
    wire [31:0] mem_req_wdata;
    
    ysyx_25050136_DCACHE 
    u_ysyx_25050136_DCACHE(
        .clk         	(clk              ),
        .reset       	(reset            ),
        .m_awvalid_o 	(mem_awvalid_o    ),
        .m_awready_i 	(mem_awready_i    ),
        .m_awaddr_o  	(mem_awaddr_o     ),
        .m_awid_o    	(mem_awid_o       ),
        .m_awlen_o   	(mem_awlen_o      ),
        .m_awsize_o  	(mem_awsize_o     ),
        .m_awburst_o 	(mem_awburst_o    ),
        .m_wvalid_o  	(mem_wvalid_o     ),
        .m_wready_i  	(mem_wready_i     ),
        .m_wdata_o   	(mem_wdata_o      ),
        .m_wstrb_o   	(mem_wstrb_o      ),
        .m_wlast_o   	(mem_wlast_o      ),
        .m_bvalid_i  	(mem_bvalid_i     ),
        .m_bready_o  	(mem_bready_o     ),
        .m_bresp_i   	(mem_bresp_i      ),
        .m_bid_i     	(mem_bid_i        ),
        .m_arvalid_o 	(mem_arvalid_o    ),
        .m_arready_i 	(mem_arready_i    ),
        .m_araddr_o  	(mem_araddr_o     ),
        .m_arid_o    	(mem_arid_o       ),
        .m_arlen_o   	(mem_arlen_o      ),
        .m_arsize_o  	(mem_arsize_o     ),
        .m_arburst_o 	(mem_arburst_o    ),
        .m_rvalid_i  	(mem_rvalid_i     ),
        .m_rready_o  	(mem_rready_o     ),
        .m_rdata_i   	(mem_rdata_i      ),
        .m_rresp_i   	(mem_rresp_i      ),
        .m_rlast_i   	(mem_rlast_i      ),
        .m_rid_i     	(mem_rid_i        ),
        .req_addr_i  	(mem_req_addr     ),
        .req_valid_i 	(mem_req_valid    ),
        .req_ren_i   	(mem_req_ren      ),
        .req_wen_i   	(mem_req_wen      ),
        .req_mask_i  	(mem_req_mask     ),
        .req_size_i  	(mem_req_size     ),
        .req_use_i   	(mem_req_use      ),
        .req_wdata_i 	(mem_req_wdata    ),
        .req_rdata_o 	(mem_ret_rdata    ),
        .req_ready_o 	(mem_ret_ready    )
    );

    ysyx_25050136_NPCCORE
    u_ysyx_25050136_NPCCORE(
        .clk              	(clk             ),
        .reset            	(reset           ),
        .inst_flush_o     	(inst_flush      ),
        .inst_req_valid_o 	(inst_req_valid  ),
        .inst_req_addr_o  	(inst_req_addr   ),
        .inst_ret_valid_i  	(inst_ret_valid  ),
        .inst_ret_last_i   	(inst_ret_last   ),
        .inst_ret_data_i   	(inst_ret_data   ),        
        .mem_ret_rdata_i  	(mem_ret_rdata   ),
        .mem_ret_ready_i  	(mem_ret_ready   ),
        .mem_req_addr_o   	(mem_req_addr    ),
        .mem_req_valid_o  	(mem_req_valid   ),
        .mem_req_ren_o    	(mem_req_ren     ),
        .mem_req_wen_o    	(mem_req_wen     ),
        .mem_req_mask_o   	(mem_req_mask    ),
        .mem_req_size_o   	(mem_req_size    ),
        .mem_req_use_o    	(mem_req_use     ),
        .mem_req_wdata_o  	(mem_req_wdata   )
    );
    
    ysyx_25050136_IMEM2AXI 
    #(
        .OFFSET_WIDTH 	(4  )
    )
    u_ysyx_25050136_IMEM2AXI(
        .clk         	(clk                ),
        .reset       	(reset              ),
        .flush_i        (inst_flush         ),
        .m_arvalid_o 	(inst_arvalid_o     ),
        .m_arready_i 	(inst_arready_i     ),
        .m_araddr_o  	(inst_araddr_o      ),
        .m_arid_o    	(inst_arid_o        ),
        .m_arlen_o   	(inst_arlen_o       ),
        .m_arsize_o  	(inst_arsize_o      ),
        .m_arburst_o 	(inst_arburst_o     ),
        .m_rvalid_i  	(inst_rvalid_i      ),
        .m_rready_o  	(inst_rready_o      ),
        .m_rdata_i   	(inst_rdata_i       ),
        .m_rresp_i   	(inst_rresp_i       ),
        .m_rlast_i   	(inst_rlast_i       ),
        .m_rid_i     	(inst_rid_i         ),
        .req_valid_i    (inst_req_valid     ),
        .req_addr_i   	(inst_req_addr      ),
        .ret_valid_o 	(inst_ret_valid     ),
        .ret_last_o  	(inst_ret_last      ),
        .ret_data_o  	(inst_ret_data      )
    );
    
endmodule
