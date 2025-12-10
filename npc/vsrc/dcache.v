module ysyx_25050136_DCACHE
(
    input                                      clk          ,
    input                                      reset        ,
    // 写地址                     
    output                                     m_awvalid_o  ,
    input                                      m_awready_i  ,
    output   [31:0]                            m_awaddr_o   ,
    output   [3:0]                             m_awid_o     ,
    output   [7:0]                             m_awlen_o    ,
    output   [2:0]                             m_awsize_o   ,
    output   [1:0]                             m_awburst_o  ,
    // 写数据                                    
    output                                     m_wvalid_o   ,
    input                                      m_wready_i   ,
    output   [31:0]                            m_wdata_o    ,
    output   [3:0]                             m_wstrb_o    ,
    output                                     m_wlast_o    ,
    // 写响应                                        
    input                                      m_bvalid_i   ,
    output                                     m_bready_o   ,
    input    [1:0]                             m_bresp_i    ,
    input    [3:0]                             m_bid_i      ,
    // 读地址                                        
    output                                     m_arvalid_o  ,
    input                                      m_arready_i  ,
    output   [31:0]                            m_araddr_o   ,
    output   [3:0]                             m_arid_o     ,
    output   [7:0]                             m_arlen_o    ,
    output   [2:0]                             m_arsize_o   ,
    output   [1:0]                             m_arburst_o  ,
    // 读数据                                        
    input                                      m_rvalid_i   ,
    output                                     m_rready_o   ,
    input    [31:0]                            m_rdata_i    ,
    input    [1:0]                             m_rresp_i    ,
    input                                      m_rlast_i    ,
    input    [3:0]                             m_rid_i      ,
    // 内部
    input    [31:0]                            req_addr_i   ,
    input                                      req_valid_i  ,
    input                                      req_ren_i    ,
    input                                      req_wen_i    ,
    input    [3:0]                             req_mask_i   ,
    input    [2:0]                             req_size_i   ,
    input                                      req_use_i    ,
    input    [31:0]                            req_wdata_i  ,
    output   [31:0]                            req_rdata_o  ,
    output                                     req_ready_o  
);
    // ==================== cache内部信号定义 ==============================
    // DCACHE状态机
    parameter IDLE  = 2'd0;
    parameter READ  = 2'd1;
    parameter WRITE = 2'd2;
    parameter ACK   = 2'd3;
    // Dcache存储阵列
    reg [31:0] cache_data_temp;
    // Dcache与CPU交互信号
    reg [1:0] state;
    reg [31:0] req_rdata_r;
    reg req_ready_r;
    // 读写使能信号
    wire ren = req_valid_i & req_ren_i;
    wire wen = req_valid_i & req_wen_i;
    // ==================== axi读信号定义 ==============================
    localparam READ_IDLE = 2'd0;
    localparam READ_ADDR = 2'd1;
    localparam READ_DATA = 2'd2;
    // axi读事务信号
    reg [1:0] state_read;
    reg m_rready_r;
    reg [31:0] m_araddr_r;
    reg [3:0] m_arid_r;
    reg [7:0] m_arlen_r;
    reg [2:0] m_arsize_r;
    reg [1:0] m_arburst_r;
    wire ar_fire, r_fire;
    // ==================== axi写信号定义 ==============================
    localparam WRITE_IDLE      = 2'd0;
    localparam WRITE_DATA_ADDR = 2'd1;
    localparam WRITE_WAIT      = 2'd2;
    // axi写事务信号
    reg [1:0] state_write;
    reg m_bready_r;
    reg [31:0] m_awaddr_r;
    reg [3:0] m_awid_r;
    reg [7:0] m_awlen_r;
    reg [2:0] m_awsize_r;
    reg [1:0] m_awburst_r;
    reg [31:0] m_wdata_r;
    reg [3:0] m_wstrb_r;
    reg m_wlast_r;
    reg aw_en, w_en;
    wire aw_fire, w_fire, b_fire;
    // ==================== dcache逻辑实现 ==============================
    // dcache总状态机
    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            case (state)
                IDLE: begin
                    if(req_valid_i) begin
                        if(req_ren_i) begin
                            state <= READ;
                        end else if(req_wen_i) begin
                            state <= WRITE;
                        end
                    end
                end 
                READ: begin
                    if(r_fire && m_rlast_i) begin
                        state <= ACK;
                    end
                end
                WRITE: begin
                    if(b_fire) begin
                        state <= ACK;
                    end
                end
                ACK: begin
                    state <= IDLE;
                end 
            endcase
        end
    end
    // 输出信号
    always @(*) begin
        req_rdata_r = 0;
        req_ready_r = 0;
        if(state == ACK) begin
            req_rdata_r = cache_data_temp;
            req_ready_r = 1;
        end
    end
    assign req_rdata_o = req_rdata_r;
    assign req_ready_o = req_ready_r;
    // ==================== AXI读操作 ==============================
    always @(posedge clk) begin
        if (reset) begin
            state_read   <= READ_IDLE;
            cache_data_temp <= 0;
            m_araddr_r   <= 0;
            m_arid_r     <= 0;
            m_arlen_r    <= 0;
            m_arsize_r   <= 0;
            m_arburst_r  <= 0;
            m_rready_r   <= 0;
        end else begin
            case (state_read)
                READ_IDLE: begin
                    m_rready_r <= 1;
                    if ((state == IDLE) && ren) begin
                        state_read  <= READ_ADDR;
                        m_araddr_r  <= req_addr_i;
                        m_arid_r    <= 4'b0100;
                        m_arlen_r   <= 0;
                        m_arsize_r  <= req_size_i;
                        m_arburst_r <= 0;
                    end
                end 
                READ_ADDR: begin
                    m_rready_r <= 1;
                    if (ar_fire) begin
                        m_araddr_r  <= 0;
                        m_arlen_r   <= 0;
                        m_arsize_r  <= 0;
                        m_arburst_r <= 0;
                        state_read <= READ_DATA;                        
                    end
                end 
                READ_DATA: begin
                    if (r_fire) begin
                        cache_data_temp <= m_rdata_i;
                        if(m_rlast_i) begin
                            m_arid_r <= 0;
                            state_read <= READ_IDLE;
                        end
                        m_rready_r <= 0;
                    end else begin
                        m_rready_r <= 1;                        
                    end
                end 
                default: ;
            endcase
        end
    end

    assign m_arvalid_o = (state_read == READ_ADDR);
    assign m_araddr_o  = m_araddr_r;
    assign m_arid_o = m_arid_r;
    assign m_arlen_o = m_arlen_r;
    assign m_arsize_o = m_arsize_r;
    assign m_arburst_o = m_arburst_r;
    assign m_rready_o = m_rready_r;
    assign ar_fire = m_arvalid_o & m_arready_i;
    assign r_fire = m_rvalid_i & m_rready_o;
    // ==================== AXI写操作 ==============================
    always @(posedge clk) begin
        if(reset) begin
            state_write <= WRITE_IDLE;
            aw_en       <= 0;
            w_en        <= 0;
            m_awaddr_r  <= 0;
            m_awid_r    <= 0;
            m_awlen_r   <= 0;
            m_awsize_r  <= 0;
            m_awburst_r <= 0;
            m_wdata_r   <= 0;
            m_wstrb_r   <= 0;
            m_wlast_r   <= 0;
            m_bready_r  <= 0;
        end else begin
            case (state_write)
                WRITE_IDLE: begin
                    m_bready_r <= 1;
                    aw_en <= 0;
                    w_en  <= 0;
                    if((state == IDLE) && wen) begin
                        state_write <= WRITE_DATA_ADDR;
                        m_awaddr_r  <= req_addr_i;
                        m_awid_r    <= 0;
                        m_awlen_r   <= 0;
                        m_awsize_r  <= req_size_i;
                        m_awburst_r <= 0;
                        m_wdata_r   <= req_wdata_i;
                        m_wstrb_r   <= req_mask_i;
                        m_wlast_r   <= 1;
                    end
                end
                WRITE_DATA_ADDR: begin
                    m_bready_r <= 1;
                    if(aw_fire) begin
                        m_awaddr_r  <= 0;
                        m_awlen_r   <= 0;
                        m_awsize_r  <= 0;
                        m_awburst_r <= 0;
                        aw_en <= 1;
                    end
                    if(w_fire) begin
                        m_wdata_r   <= 0;
                        m_wstrb_r   <= 0;
                        m_wlast_r   <= 0;
                        w_en  <= 1;
                    end
                    if((aw_fire & w_fire) | (aw_en & w_fire) | (w_en & aw_fire)) begin
                        state_write <= WRITE_WAIT;
                    end
                end
                WRITE_WAIT: begin
                    if(b_fire) begin
                        m_bready_r  <= 0;
                        m_awid_r    <= 0;
                        state_write <= WRITE_IDLE;
                    end 
                end
                default:;    
            endcase
        end
    end

    assign m_awvalid_o = (state_write == WRITE_DATA_ADDR) && ~aw_en;
    assign m_awaddr_o  = m_awaddr_r;
    assign m_awid_o    = m_awid_r;
    assign m_awlen_o   = m_awlen_r;
    assign m_awsize_o  = m_awsize_r;
    assign m_awburst_o = m_awburst_r;
    assign m_wvalid_o  = (state_write == WRITE_DATA_ADDR) && ~w_en;
    assign m_wlast_o   = m_wlast_r;
    assign m_wdata_o   = m_wdata_r;
    assign m_wstrb_o   = m_wstrb_r;
    assign m_bready_o  = m_bready_r;    
    assign aw_fire     = m_awvalid_o & m_awready_i;
    assign w_fire      = m_wvalid_o & m_wready_i;
    assign b_fire      = m_bvalid_i & m_bready_o;

`ifdef YSYXSOC
`ifdef EVENT_COUNTER
    wire [31:0] mem_type;
    assign mem_type = (req_addr_i >= 32'ha0000000) ? 32'd2 :
                      (req_addr_i >= 32'h30000000) ? 32'd1 :
                      (req_addr_i >= 32'h0f000000) ? 32'd0 : 32'd10;
    always @(posedge clk) begin
        if(wen) begin
            dcache_misscycle(mem_type+32'd3);
            if(state == ACK) dcache_get(mem_type+32'd3);
        end
        if(ren) begin
            dcache_misscycle(mem_type);
            if(state == ACK) dcache_get(mem_type);
        end
    end
`endif
`endif
endmodule
