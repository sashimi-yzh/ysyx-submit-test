`ifdef YSYXSOC
import "DPI-C" function void find_addr_0(); 
import "DPI-C" function void find_ebreak();
import "DPI-C" function void find_resp();
import "DPI-C" function void find_diff_skip();
import "DPI-C" function void find_diff_mem(input int addr, input int data, input byte len, input byte mem_type);
// DPI-C 函数导入声明
import "DPI-C" function void fetch_get();
import "DPI-C" function void commit_get();
import "DPI-C" function void load_get();
import "DPI-C" function void store_get();
import "DPI-C" function void jump_get();
import "DPI-C" function void branch_get();
import "DPI-C" function void alu_get();
import "DPI-C" function void system_get();
import "DPI-C" function void predict_miss_count();
import "DPI-C" function void predict_not_jump_count();
import "DPI-C" function void related_delay_get();
import "DPI-C" function void icache_get(input int cache_type);
import "DPI-C" function void icache_miss(input int cache_type);
import "DPI-C" function void icache_misscycle(input int cache_type);
import "DPI-C" function void dcache_get(input int cache_type);
import "DPI-C" function void dcache_misscycle(input int cache_type);
`endif

module ysyx_25050136(
    input               clock             ,
    input               reset             ,
    input               io_interrupt      ,

    // AXI4 Master接口
    // 写地址通道
    input               io_master_awready ,
    output              io_master_awvalid ,
    output      [31:0]  io_master_awaddr  ,
    output      [3:0]   io_master_awid    ,
    output      [7:0]   io_master_awlen   ,
    output      [2:0]   io_master_awsize  ,
    output      [1:0]   io_master_awburst ,
    // 写数据通道
    input               io_master_wready  ,
    output              io_master_wvalid  ,
    output      [31:0]  io_master_wdata   ,
    output      [3:0]   io_master_wstrb   ,
    output              io_master_wlast   ,
    // 写响应通道
    output              io_master_bready  ,
    input               io_master_bvalid  ,
    input       [1:0]   io_master_bresp   ,
    input       [3:0]   io_master_bid     ,
    // 读地址通道
    input               io_master_arready ,
    output              io_master_arvalid ,
    output      [31:0]  io_master_araddr  ,
    output      [3:0]   io_master_arid    ,
    output      [7:0]   io_master_arlen   ,
    output      [2:0]   io_master_arsize  ,
    output      [1:0]   io_master_arburst ,
    // 读数据通道
    output              io_master_rready  ,
    input               io_master_rvalid  ,
    input       [1:0]   io_master_rresp   ,
    input       [31:0]  io_master_rdata   ,
    input               io_master_rlast   ,
    input       [3:0]   io_master_rid     ,
    // AXI4 Slave接口
    // 写地址通道
    output              io_slave_awready  ,
    input               io_slave_awvalid  ,
    input       [31:0]  io_slave_awaddr   ,
    input       [3:0]   io_slave_awid     ,
    input       [7:0]   io_slave_awlen    ,
    input       [2:0]   io_slave_awsize   ,
    input       [1:0]   io_slave_awburst  ,
    // 写数据通道
    output              io_slave_wready   ,
    input               io_slave_wvalid   ,
    input       [31:0]  io_slave_wdata    ,
    input       [3:0]   io_slave_wstrb    ,
    input               io_slave_wlast    ,
    // 写响应通道
    input               io_slave_bready   ,
    output              io_slave_bvalid   ,
    output      [1:0]   io_slave_bresp    ,
    output      [3:0]   io_slave_bid      ,
    // 读地址通道
    output              io_slave_arready  ,
    input               io_slave_arvalid  ,
    input       [31:0]  io_slave_araddr   ,
    input       [3:0]   io_slave_arid     ,
    input       [7:0]   io_slave_arlen    ,
    input       [2:0]   io_slave_arsize   ,
    input       [1:0]   io_slave_arburst  ,
    // 读数据通道
    input               io_slave_rready   ,
    output              io_slave_rvalid   ,
    output      [1:0]   io_slave_rresp    ,
    output      [31:0]  io_slave_rdata    ,
    output              io_slave_rlast    ,
    output      [3:0]   io_slave_rid
);
`ifdef YSYXSOC
`ifdef EVENT_COUNTER
    always @(*) begin
        if ((io_master_awvalid & io_master_awready & (io_master_awaddr == 0)) |
            (io_master_arvalid & io_master_arready & (io_master_araddr == 0)) )
        begin
            find_addr_0();
        end
    end
`endif
`endif
    localparam TOP_MASTER_NUM = 2 ; // 顶层总线主设备数量
    // 顶层仲裁器只对读信号进行二选一仲裁，写信号直接连接(也是被后仿逼得)
    // 仲裁器信号
    wire [TOP_MASTER_NUM-1:0]               s_arvalid    ;
    wire [TOP_MASTER_NUM-1:0]               s_arready    ;
    wire [TOP_MASTER_NUM*32-1:0]            s_araddr     ;
    wire [TOP_MASTER_NUM*4-1:0]             s_arid       ;
    wire [TOP_MASTER_NUM*8-1:0]             s_arlen      ;
    wire [TOP_MASTER_NUM*3-1:0]             s_arsize     ;
    wire [TOP_MASTER_NUM*2-1:0]             s_arburst    ;
    wire [TOP_MASTER_NUM-1:0]               s_rvalid     ;
    wire [TOP_MASTER_NUM-1:0]               s_rready     ;
    wire [TOP_MASTER_NUM*32-1:0]            s_rdata      ;
    wire [TOP_MASTER_NUM*2-1:0]             s_rresp      ;
    wire [TOP_MASTER_NUM-1:0]               s_rlast      ;
    wire [TOP_MASTER_NUM*4-1:0]             s_rid        ;
    // 主设备信号        
    wire                                    inst_arvalid ;
    wire                                    inst_arready ;
    wire [31:0]                             inst_araddr  ;
    wire [3:0]                              inst_arid    ;
    wire [7:0]                              inst_arlen   ;
    wire [2:0]                              inst_arsize  ;
    wire [1:0]                              inst_arburst ;
    wire                                    inst_rvalid  ;
    wire                                    inst_rready  ;
    wire [31:0]                             inst_rdata   ;
    wire [1:0]                              inst_rresp   ;
    wire                                    inst_rlast   ;
    wire [3:0]                              inst_rid     ;
    wire                                    mem_awvalid  ;
    wire                                    mem_awready  ;
    wire [31:0]                             mem_awaddr   ;
    wire [3:0]                              mem_awid     ;
    wire [7:0]                              mem_awlen    ;
    wire [2:0]                              mem_awsize   ;
    wire [1:0]                              mem_awburst  ;
    wire                                    mem_wvalid   ;
    wire                                    mem_wready   ;
    wire [31:0]                             mem_wdata    ;
    wire [3:0]                              mem_wstrb    ;
    wire                                    mem_wlast    ;
    wire                                    mem_bvalid   ;
    wire                                    mem_bready   ;
    wire [1:0]                              mem_bresp    ;
    wire [3:0]                              mem_bid      ;
    wire                                    mem_arvalid  ;
    wire                                    mem_arready  ;
    wire [31:0]                             mem_araddr   ;
    wire [3:0]                              mem_arid     ;
    wire [7:0]                              mem_arlen    ;
    wire [2:0]                              mem_arsize   ;
    wire [1:0]                              mem_arburst  ;
    wire                                    mem_rvalid   ;
    wire                                    mem_rready   ;
    wire [31:0]                             mem_rdata    ;
    wire [1:0]                              mem_rresp    ;
    wire                                    mem_rlast    ;
    wire [3:0]                              mem_rid      ;
   
    // 主设备到仲裁器信号连接 -- 仅读事务仲裁
    assign s_arvalid   = {inst_arvalid, mem_arvalid} ;
    assign s_araddr    = {inst_araddr,  mem_araddr}  ;
    assign s_arid      = {inst_arid,    mem_arid}    ;
    assign s_arlen     = {inst_arlen,   mem_arlen}   ;
    assign s_arsize    = {inst_arsize,  mem_arsize}  ;
    assign s_arburst   = {inst_arburst, mem_arburst} ;
    assign s_rready    = {inst_rready,  mem_rready}  ;
    
    // 仲裁器到主设备信号连接
    assign mem_arready  = s_arready[0]  ;
    assign mem_rvalid   = s_rvalid[0]   ;
    assign mem_rdata    = s_rdata[31:0] ;
    assign mem_rresp    = s_rresp[1:0]  ;
    assign mem_rlast    = s_rlast[0]    ;
    assign mem_rid      = s_rid[3:0]    ;
    assign inst_arready = s_arready[1]  ;
    assign inst_rvalid  = s_rvalid[1]   ;
    assign inst_rdata   = s_rdata[63:32];
    assign inst_rresp   = s_rresp[3:2]  ;
    assign inst_rlast   = s_rlast[1]    ;
    assign inst_rid     = s_rid[7:4]    ;

    // 顶层AXI SLAVER接口
    assign io_slave_awready = 0;
    assign io_slave_wready = 0;
    assign io_slave_bvalid = 0;
    assign io_slave_bvalid = 0;
    assign io_slave_bresp = 0; 
    assign io_slave_bid = 0;   
    assign io_slave_arready = 0;
    assign io_slave_rvalid = 0;
    assign io_slave_rresp = 0; 
    assign io_slave_rdata = 0; 
    assign io_slave_rlast = 0; 
    assign io_slave_rid = 0;

    // NPC模块实例化
    ysyx_25050136_NPC 
    u_ysyx_25050136_NPC (
        .clk            	(clock           ),
        .reset          	(reset           ),
        .inst_arvalid_o 	(inst_arvalid  ),
        .inst_arready_i 	(inst_arready  ),
        .inst_araddr_o  	(inst_araddr   ),
        .inst_arid_o    	(inst_arid     ),
        .inst_arlen_o   	(inst_arlen    ),
        .inst_arsize_o  	(inst_arsize   ),
        .inst_arburst_o 	(inst_arburst  ),
        .inst_rvalid_i  	(inst_rvalid   ),
        .inst_rready_o  	(inst_rready   ),
        .inst_rdata_i   	(inst_rdata    ),
        .inst_rresp_i   	(inst_rresp    ),
        .inst_rlast_i   	(inst_rlast    ),
        .inst_rid_i     	(inst_rid      ),
        .mem_awvalid_o  	(mem_awvalid   ),
        .mem_awready_i  	(mem_awready   ),
        .mem_awaddr_o   	(mem_awaddr    ),
        .mem_awid_o     	(mem_awid      ),
        .mem_awlen_o    	(mem_awlen     ),
        .mem_awsize_o   	(mem_awsize    ),
        .mem_awburst_o  	(mem_awburst   ),
        .mem_wvalid_o   	(mem_wvalid    ),
        .mem_wready_i   	(mem_wready    ),
        .mem_wdata_o    	(mem_wdata     ),
        .mem_wstrb_o    	(mem_wstrb     ),
        .mem_wlast_o    	(mem_wlast     ),
        .mem_bvalid_i   	(mem_bvalid    ),
        .mem_bready_o   	(mem_bready    ),
        .mem_bresp_i    	(mem_bresp     ),
        .mem_bid_i      	(mem_bid       ),
        .mem_arvalid_o  	(mem_arvalid   ),
        .mem_arready_i  	(mem_arready   ),
        .mem_araddr_o   	(mem_araddr    ),
        .mem_arid_o     	(mem_arid      ),
        .mem_arlen_o    	(mem_arlen     ),
        .mem_arsize_o   	(mem_arsize    ),
        .mem_arburst_o  	(mem_arburst   ),
        .mem_rvalid_i   	(mem_rvalid    ),
        .mem_rready_o   	(mem_rready    ),
        .mem_rdata_i    	(mem_rdata     ),
        .mem_rresp_i    	(mem_rresp     ),
        .mem_rlast_i    	(mem_rlast     ),
        .mem_rid_i      	(mem_rid       )
    );
    
    // 仲裁器模块实例化
    ysyx_25050136_ARBITER #(
        .MASTER_NUM     (TOP_MASTER_NUM    )
    ) u_ysyx_25050136_ARBITER( 
        .clk        	(clock              ),
        .reset      	(reset              ),
        .s_awvalid_i 	(mem_awvalid        ),
        .s_awready_o 	(mem_awready        ),
        .s_awaddr_i  	(mem_awaddr         ),
        .s_awid_i    	(mem_awid           ),
        .s_awlen_i   	(mem_awlen          ),
        .s_awsize_i  	(mem_awsize         ),
        .s_awburst_i 	(mem_awburst        ),
        .s_wvalid_i  	(mem_wvalid         ),
        .s_wready_o  	(mem_wready         ),
        .s_wdata_i   	(mem_wdata          ),
        .s_wstrb_i   	(mem_wstrb          ),
        .s_wlast_i   	(mem_wlast          ),
        .s_bvalid_o  	(mem_bvalid         ),
        .s_bready_i  	(mem_bready         ),
        .s_bresp_o   	(mem_bresp          ),
        .s_bid_o     	(mem_bid            ),
        .s_arvalid_i 	(s_arvalid          ),
        .s_arready_o 	(s_arready          ),
        .s_araddr_i  	(s_araddr           ),
        .s_arid_i    	(s_arid             ),
        .s_arlen_i   	(s_arlen            ),
        .s_arsize_i  	(s_arsize           ),
        .s_arburst_i 	(s_arburst          ),
        .s_rvalid_o  	(s_rvalid           ),
        .s_rready_i  	(s_rready           ),
        .s_rdata_o   	(s_rdata            ),
        .s_rresp_o   	(s_rresp            ),
        .s_rlast_o   	(s_rlast            ),
        .s_rid_o     	(s_rid              ),
        .m_awvalid_o 	(io_master_awvalid  ),
        .m_awready_i 	(io_master_awready  ),
        .m_awaddr_o  	(io_master_awaddr   ),
        .m_awid_o    	(io_master_awid     ),
        .m_awlen_o   	(io_master_awlen    ),
        .m_awsize_o  	(io_master_awsize   ),
        .m_awburst_o 	(io_master_awburst  ),
        .m_wvalid_o  	(io_master_wvalid   ),
        .m_wready_i  	(io_master_wready   ),
        .m_wdata_o   	(io_master_wdata    ),
        .m_wstrb_o   	(io_master_wstrb    ),
        .m_wlast_o   	(io_master_wlast    ),
        .m_bvalid_i  	(io_master_bvalid   ),
        .m_bready_o  	(io_master_bready   ),
        .m_bresp_i   	(io_master_bresp    ),
        .m_bid_i     	(io_master_bid      ),
        .m_arvalid_o 	(io_master_arvalid  ),
        .m_arready_i 	(io_master_arready  ),
        .m_araddr_o  	(io_master_araddr   ),
        .m_arid_o    	(io_master_arid     ),
        .m_arlen_o   	(io_master_arlen    ),
        .m_arsize_o  	(io_master_arsize   ),
        .m_arburst_o 	(io_master_arburst  ),
        .m_rvalid_i  	(io_master_rvalid   ),
        .m_rready_o  	(io_master_rready   ),
        .m_rdata_i   	(io_master_rdata    ),
        .m_rresp_i   	(io_master_rresp    ),
        .m_rlast_i   	(io_master_rlast    ),
        .m_rid_i     	(io_master_rid      )
    );
    
endmodule
