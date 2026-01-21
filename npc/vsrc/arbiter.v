//----------------------------------------------------------
// CI测试不支持返回rid，所以简单仲裁
// 仅支持MASTER_NUM=2
// 仅支持读通道仲裁，写通道直通
// 想要改变MASTER_NUM参数，需要同步修改内部逻辑
//----------------------------------------------------------
module ysyx_25050136_ARBITER
    #(
        parameter MASTER_NUM = 2,
        parameter DATA_WIDTH = 32,
        parameter ADDR_WIDTH = 32
     )
     (
        input                                   clk         ,
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
        output    [3:0]                         s_bid_o     ,
        output    [1:0]                         s_bresp_o   ,
        // 读地址
        input     [MASTER_NUM-1:0]              s_arvalid_i ,
        output    [MASTER_NUM-1:0]              s_arready_o ,
        input     [MASTER_NUM*ADDR_WIDTH-1:0]   s_araddr_i  ,
        input     [MASTER_NUM*4-1:0]            s_arid_i    ,
        input     [MASTER_NUM*8-1:0]            s_arlen_i   ,
        input     [MASTER_NUM*3-1:0]            s_arsize_i  ,
        input     [MASTER_NUM*2-1:0]            s_arburst_i ,
        // 读数据
        output    [MASTER_NUM-1:0]              s_rvalid_o  ,
        input     [MASTER_NUM-1:0]              s_rready_i  ,
        output    [MASTER_NUM*DATA_WIDTH-1:0]   s_rdata_o   ,
        output    [MASTER_NUM*2-1:0]            s_rresp_o   ,
        output    [MASTER_NUM-1:0]              s_rlast_o   ,
        output    [MASTER_NUM*4-1:0]            s_rid_o     ,
        // 来自从设备的AXI信号
        // 写地址
        output                                  m_awvalid_o ,
        input                                   m_awready_i ,
        output    [ADDR_WIDTH-1:0]              m_awaddr_o  ,
        output    [3:0]                         m_awid_o    ,
        output    [7:0]                         m_awlen_o   ,
        output    [2:0]                         m_awsize_o  ,
        output    [1:0]                         m_awburst_o ,
        // 写数据
        output                                  m_wvalid_o  ,
        input                                   m_wready_i  ,
        output    [DATA_WIDTH-1:0]              m_wdata_o   ,
        output    [3:0]                         m_wstrb_o   ,
        output                                  m_wlast_o   ,
        // 写响应
        input                                   m_bvalid_i  ,
        output                                  m_bready_o  ,
        input     [3:0]                         m_bid_i     ,
        input     [1:0]                         m_bresp_i   ,
        // 读地址
        output                                  m_arvalid_o ,
        input                                   m_arready_i ,
        output    [ADDR_WIDTH-1:0]              m_araddr_o  ,
        output    [3:0]                         m_arid_o    ,
        output    [7:0]                         m_arlen_o   ,
        output    [2:0]                         m_arsize_o  ,
        output    [1:0]                         m_arburst_o ,
        // 读数据
        input                                   m_rvalid_i  ,
        output                                  m_rready_o  ,
        input     [DATA_WIDTH-1:0]              m_rdata_i   ,
        input     [1:0]                         m_rresp_i   ,
        input                                   m_rlast_i   ,
        input     [3:0]                         m_rid_i
     );
    // ========================读通道仲裁器===========================
    // 仲裁逻辑：
    // 1. 当没有传输时，从有效请求中选择优先级最高的一个作为当前传输者，进入忙态
    // 2. 当传输进行时，高优先级请求也不可以抢占，直到当前传输完成，释放忙态
    reg [MASTER_NUM-1:0] AR_owner;
    reg                  AR_busy;
    reg [MASTER_NUM-1:0] AR_hot;
    reg [$clog2(MASTER_NUM)-1:0] AR_bin;
    // 候选选择（固定优先级，从0到N-1的第一个有效者）
    reg [MASTER_NUM-1:0] AR_cand_hot;
    always @(*) begin
        AR_cand_hot = 0;
        if (s_arvalid_i[0]) begin
            AR_cand_hot[0] = 1;
        end else if (s_arvalid_i[1]) begin
            AR_cand_hot[1] = 1;
        end
    end

    // AR_hot 和 AR_bin 由 busy/owner 或 候选 决定
    integer a;
    always @(*) begin
        if (AR_busy) begin
            AR_hot = AR_owner;
        end else begin
            AR_hot = AR_cand_hot;
        end
        AR_bin = 0;
        for (a = 0; a < MASTER_NUM; a = a + 1) begin
            if (AR_hot[a]) begin
                AR_bin = a[$clog2(MASTER_NUM)-1:0];
            end
        end
    end

    wire R_fire  = |(s_rready_i & AR_hot) & m_rvalid_i & m_rlast_i; // 读通道最后一个数据握手完成
    //管理 AR_owner / AR_busy
    always @(posedge clk) begin
        if (reset) begin
            AR_owner <= 0;
            AR_busy  <= 0;
        end else begin
            // 当当前不忙且有候选请求时，占用者设为该候选并进入忙态
            if (!AR_busy) begin
                if (|AR_cand_hot) begin
                    AR_owner <= AR_cand_hot;
                    AR_busy  <= 1;
                end
            end
            // 当握手完成，释放忙态
            if (R_fire) begin
                AR_owner <= 0;
                AR_busy  <= 0;
            end
        end
    end
    
    // AR通道
    assign m_arvalid_o = |(s_arvalid_i & AR_hot);
    assign m_araddr_o  = s_araddr_i[AR_bin * ADDR_WIDTH +: ADDR_WIDTH];
    assign m_arid_o    = s_arid_i[AR_bin * 4 +: 4];
    assign m_arlen_o   = s_arlen_i[AR_bin * 8 +: 8];
    assign m_arsize_o  = s_arsize_i[AR_bin * 3 +: 3];
    assign m_arburst_o = s_arburst_i[AR_bin * 2 +: 2];

    genvar i;
    generate
        for (i = 0; i < MASTER_NUM ; i = i + 1) begin: AR_FOR
            assign s_arready_o[i] = m_arready_i & AR_hot[i];
        end
    endgenerate

    // R通道
    assign m_rready_o = |(s_rready_i & AR_hot);
    generate
        for (i = 0; i < MASTER_NUM ; i = i + 1) begin: R_FOR
            assign s_rvalid_o[i] = m_rvalid_i & AR_hot[i];
            assign s_rdata_o[i*DATA_WIDTH+:DATA_WIDTH] = AR_hot[i] ? m_rdata_i : 0;
            assign s_rresp_o[i*2+:2] = AR_hot[i] ? m_rresp_i : 0;
            assign s_rlast_o[i] = m_rlast_i & AR_hot[i];
            assign s_rid_o[i*4+:4] = AR_hot[i] ? m_rid_i : 0;
        end
    endgenerate
    // ========================写通道直通===========================
    // AW通道
    assign m_awvalid_o = s_awvalid_i;
    assign m_awaddr_o  = s_awaddr_i;
    assign m_awid_o    = s_awid_i;
    assign m_awlen_o   = s_awlen_i;
    assign m_awsize_o  = s_awsize_i;
    assign m_awburst_o = s_awburst_i;
    assign s_awready_o = m_awready_i;
    // W通道
    assign m_wvalid_o  = s_wvalid_i;
    assign m_wdata_o   = s_wdata_i;
    assign m_wstrb_o   = s_wstrb_i;
    assign m_wlast_o   = s_wlast_i;
    assign s_wready_o  = m_wready_i;
    // B通道
    assign s_bvalid_o  = m_bvalid_i;
    assign s_bid_o     = m_bid_i;
    assign s_bresp_o   = m_bresp_i;
    assign m_bready_o  = s_bready_i;
endmodule
