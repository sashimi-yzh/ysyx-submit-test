module ysyx_25050136_XBAR
    #(
        parameter SLAVER_NUM = 2,
        parameter DATA_WIDTH = 32,
        parameter ADDR_WIDTH = 32
     )
     (
        // 通用数据
        input                                   aclk        ,
        input                                   reset       ,
        // 来自主设备的AXI信号
        // 写地址
        input                                   s_awvalid_i ,
        output                                  s_awready_o ,
        input     [ADDR_WIDTH-1:0]              s_awaddr_i  ,
        input     [3:0]                         s_awid_i    ,
        input     [7:0]                         s_awlen_i   ,
        input     [2:0]                         s_awsize_i  ,
        input     [1:0]                         s_awburst_i ,
        // 写数据
        input                                   s_wvalid_i  ,
        output                                  s_wready_o  ,
        input     [DATA_WIDTH-1:0]              s_wdata_i   ,
        input     [3:0]                         s_wstrb_i   ,
        input                                   s_wlast_i   ,
        // 写响应
        output                                  s_bvalid_o  ,
        input                                   s_bready_i  ,
        output    [1:0]                         s_bresp_o   ,
        output    [3:0]                         s_bid_o     ,
        // 读地址
        input                                   s_arvalid_i ,
        output                                  s_arready_o ,
        input     [ADDR_WIDTH-1:0]              s_araddr_i  ,
        input     [3:0]                         s_arid_i    ,
        input     [7:0]                         s_arlen_i   ,
        input     [2:0]                         s_arsize_i  ,
        input     [1:0]                         s_arburst_i ,
        // 读数据
        output                                  s_rvalid_o  ,
        input                                   s_rready_i  ,
        output    [DATA_WIDTH-1:0]              s_rdata_o   ,
        output    [1:0]                         s_rresp_o   ,
        output                                  s_rlast_o   ,
        output    [3:0]                         s_rid_o     ,
        // 来自从设备的AXI信号
        // 写地址
        output    [SLAVER_NUM-1:0]              m_awvalid_o ,
        input     [SLAVER_NUM-1:0]              m_awready_i ,
        output    [SLAVER_NUM*ADDR_WIDTH-1:0]   m_awaddr_o  ,
        output    [SLAVER_NUM*4-1:0]            m_awid_o    ,
        output    [SLAVER_NUM*8-1:0]            m_awlen_o   ,
        output    [SLAVER_NUM*3-1:0]            m_awsize_o  ,
        output    [SLAVER_NUM*2-1:0]            m_awburst_o ,
        // 写数据
        output    [SLAVER_NUM-1:0]              m_wvalid_o  ,
        input     [SLAVER_NUM-1:0]              m_wready_i  ,
        output    [SLAVER_NUM*DATA_WIDTH-1:0]   m_wdata_o   ,
        output    [SLAVER_NUM*4-1:0]            m_wstrb_o   ,
        output    [SLAVER_NUM-1:0]              m_wlast_o   ,
        // 写响应
        input     [SLAVER_NUM-1:0]              m_bvalid_i  ,
        output    [SLAVER_NUM-1:0]              m_bready_o  ,
        input     [SLAVER_NUM*2-1:0]            m_bresp_i   ,
        input     [SLAVER_NUM*4-1:0]            m_bid_i     ,
        // 读地址
        output    [SLAVER_NUM-1:0]              m_arvalid_o ,
        input     [SLAVER_NUM-1:0]              m_arready_i ,
        output    [SLAVER_NUM*ADDR_WIDTH-1:0]   m_araddr_o  ,
        output    [SLAVER_NUM*4-1:0]            m_arid_o    ,
        output    [SLAVER_NUM*8-1:0]            m_arlen_o   ,
        output    [SLAVER_NUM*3-1:0]            m_arsize_o  ,
        output    [SLAVER_NUM*2-1:0]            m_arburst_o ,
        // 读数据
        input     [SLAVER_NUM-1:0]              m_rvalid_i  ,
        output    [SLAVER_NUM-1:0]              m_rready_o  ,
        input     [SLAVER_NUM*DATA_WIDTH-1:0]   m_rdata_i   ,
        input     [SLAVER_NUM*2-1:0]            m_rresp_i   ,
        input     [SLAVER_NUM-1:0]              m_rlast_i   ,
        input     [SLAVER_NUM*4-1:0]            m_rid_i
     );

    localparam s0_Laddr = 32'h10000000;
    localparam s0_Raddr = 32'h10000004;

    // ==================================================================
    // 写通道仲裁 (Write Channel Arbitration)
    // ==================================================================
    reg [SLAVER_NUM-1:0] w_slaver_grand;      
    reg [$clog2(SLAVER_NUM)-1:0] w_slaver_id; 
    reg [SLAVER_NUM-1:0] w_current_slaver;   
    reg [$clog2(SLAVER_NUM)-1:0] w_current_slaver_id; 

    always @(*) begin
        w_slaver_grand = 0;
        w_slaver_id = 0;
        if(s_awvalid_i) begin
            if(s_awaddr_i >= s0_Laddr && s_awaddr_i <= s0_Raddr) begin
                w_slaver_grand[0] = 1;
                w_slaver_id = 0;
            end
            else begin
                w_slaver_grand[1] = 1;
                w_slaver_id = 1;
            end
        end
    end

    always @(posedge aclk) begin
        if (reset) begin
            w_current_slaver <= 0;
            w_current_slaver_id <= 0;
        end else begin
            if(|w_current_slaver == 0 || (s_bvalid_o && s_bready_i)) begin
                w_current_slaver <= w_slaver_grand;
                w_current_slaver_id <= w_slaver_id;
            end
        end
    end

    // ==================================================================
    // 读通道仲裁 (Read Channel Arbitration)
    // ==================================================================
    reg [SLAVER_NUM-1:0] r_slaver_grand;      
    reg [$clog2(SLAVER_NUM)-1:0] r_slaver_id; 
    reg [SLAVER_NUM-1:0] r_current_slaver;    
    reg [$clog2(SLAVER_NUM)-1:0] r_current_slaver_id; 

    always @(*) begin
        r_slaver_grand = 0;
        r_slaver_id = 0;
        if(s_arvalid_i) begin
            if(s_araddr_i >= s0_Laddr && s_araddr_i <= s0_Raddr) begin
                r_slaver_grand[0] = 1;
                r_slaver_id = 0;
            end
            else begin
                r_slaver_grand[1] = 1;
                r_slaver_id = 1;
            end
        end
    end

    always @(posedge aclk) begin
        if (reset) begin
            r_current_slaver <= 0;
            r_current_slaver_id <= 0;
        end else begin
            if(|r_current_slaver == 0 || (s_rvalid_o && s_rready_i && s_rlast_o)) begin
                r_current_slaver <= r_slaver_grand;
                r_current_slaver_id <= r_slaver_id;
            end
        end
    end

    // ==================================================================
    // 写地址通道 (AW Channel)
    // ==================================================================
    assign s_awready_o = |(m_awready_i & w_current_slaver);
    genvar j_aw;
    generate
        for(j_aw = 0; j_aw < SLAVER_NUM; j_aw = j_aw + 1) begin
            assign m_awvalid_o[j_aw]      = s_awvalid_i & w_current_slaver[j_aw];
            assign m_awaddr_o[j_aw*ADDR_WIDTH+:ADDR_WIDTH] = w_current_slaver[j_aw] ? s_awaddr_i : 0;
            assign m_awid_o[j_aw*4+:4]    = w_current_slaver[j_aw] ? s_awid_i : 0;
            assign m_awlen_o[j_aw*8+:8]   = w_current_slaver[j_aw] ? s_awlen_i : 0;
            assign m_awsize_o[j_aw*3+:3]  = w_current_slaver[j_aw] ? s_awsize_i : 0;
            assign m_awburst_o[j_aw*2+:2] = w_current_slaver[j_aw] ? s_awburst_i : 0;
        end
    endgenerate

    // ==================================================================
    // 写数据通道 (W Channel)
    // ==================================================================
    assign s_wready_o  = |(m_wready_i & w_current_slaver);
    genvar j_w;
    generate
        for(j_w = 0; j_w < SLAVER_NUM; j_w = j_w + 1) begin
            assign m_wvalid_o[j_w]       = s_wvalid_i & w_current_slaver[j_w];
            assign m_wdata_o[j_w*DATA_WIDTH+:DATA_WIDTH] = w_current_slaver[j_w] ? s_wdata_i : 0;
            assign m_wstrb_o[j_w*4+:4]   = w_current_slaver[j_w] ? s_wstrb_i : 0;
            assign m_wlast_o[j_w]        = s_wlast_i & w_current_slaver[j_w];
        end
    endgenerate

    // ==================================================================
    // 写响应通道 (B Channel)
    // ==================================================================
    assign s_bvalid_o  = |(m_bvalid_i & w_current_slaver);
    assign s_bresp_o   = m_bresp_i[w_current_slaver_id * 2 +: 2];
    assign s_bid_o     = m_bid_i[w_current_slaver_id * 4 +: 4];
    genvar j_b;
    generate
        for(j_b = 0; j_b < SLAVER_NUM; j_b = j_b + 1) begin
            assign m_bready_o[j_b] = s_bready_i & w_current_slaver[j_b];
        end
    endgenerate

    // ==================================================================
    // 读地址通道 (AR Channel)
    // ==================================================================
    assign s_arready_o = |(m_arready_i & r_current_slaver);
    genvar j_ar;
    generate
        for(j_ar = 0; j_ar < SLAVER_NUM; j_ar = j_ar + 1) begin
            assign m_arvalid_o[j_ar]      = s_arvalid_i & r_current_slaver[j_ar];
            assign m_araddr_o[j_ar*ADDR_WIDTH+:ADDR_WIDTH] = r_current_slaver[j_ar] ? s_araddr_i : 0;
            assign m_arid_o[j_ar*4+:4]    = r_current_slaver[j_ar] ? s_arid_i : 0;
            assign m_arlen_o[j_ar*8+:8]   = r_current_slaver[j_ar] ? s_arlen_i : 0;
            assign m_arsize_o[j_ar*3+:3]  = r_current_slaver[j_ar] ? s_arsize_i : 0;
            assign m_arburst_o[j_ar*2+:2] = r_current_slaver[j_ar] ? s_arburst_i : 0;
        end
    endgenerate

    // ==================================================================
    // 读数据通道 (R Channel)
    // ==================================================================
    assign s_rvalid_o  = |(m_rvalid_i & r_current_slaver);
    assign s_rdata_o   = m_rdata_i[r_current_slaver_id * DATA_WIDTH +: DATA_WIDTH];
    assign s_rresp_o   = m_rresp_i[r_current_slaver_id * 2 +: 2];
    assign s_rlast_o   = |(m_rlast_i & r_current_slaver);
    assign s_rid_o     = m_rid_i[r_current_slaver_id * 4 +: 4];
    genvar j_r;
    generate
        for(j_r = 0; j_r < SLAVER_NUM; j_r = j_r + 1) begin
            assign m_rready_o[j_r] = s_rready_i & r_current_slaver[j_r];
        end
    endgenerate

endmodule