module ysyx_25050136_UART
    #(
        parameter ADDR_WIDTH    = 32,
        parameter DATA_WIDTH    = 32
     )
     (
        // 通用数据
        input                                clk,
        input                                reset,
        // 写地址
        input                                s_awvalid_i,
        output                               s_awready_o,
        input      [ADDR_WIDTH-1:0]          s_awaddr_i,
        input      [3:0]                     s_awid_i,    
        input      [7:0]                     s_awlen_i,   
        input      [2:0]                     s_awsize_i,  
        input      [1:0]                     s_awburst_i, 
        // 写数据
        input                                s_wvalid_i,
        output                               s_wready_o,
        input      [DATA_WIDTH-1:0]          s_wdata_i,
        input      [3:0]                     s_wstrb_i,
        input                                s_wlast_i, 
        // 写响应
        output                               s_bvalid_o,
        input                                s_bready_i,
        output     [1:0]                     s_bresp_o,
        output     [3:0]                     s_bid_o,
        // 读地址
        input                                s_arvalid_i,
        output                               s_arready_o,
        input      [ADDR_WIDTH-1:0]          s_araddr_i,
        input      [3:0]                     s_arid_i,
        input      [7:0]                     s_arlen_i,
        input      [2:0]                     s_arsize_i,
        input      [1:0]                     s_arburst_i,
        // 读数据
        output                               s_rvalid_o,
        input                                s_rready_i,
        output                               s_rlast_o,
        output     [DATA_WIDTH-1:0]          s_rdata_o,
        output     [1:0]                     s_rresp_o,
        output     [3:0]                     s_rid_o
     );

    
    
    // ====== 信号定义 ======
    reg                     aw_pending;
    reg                      w_pending;
    reg                     ar_pending;
    // handshake wires
    wire aw_fire = s_awvalid_i & s_awready_o;
    wire w_fire  = s_wvalid_i  & s_wready_o;
    wire ar_fire = s_arvalid_i & s_arready_o;
    wire b_fire  = s_bvalid_o  & s_bready_i;
    wire r_fire  = s_rvalid_o  & s_rready_i;
    // 请求/缓冲寄存器
    reg  [ADDR_WIDTH-1:0]   araddr_r;
    reg  [3:0]              arid_r;
    reg  [7:0]              arlen_r;
    reg  [2:0]              arsize_r;
    reg  [1:0]              arburst_r;
    reg                     rvalid_r;
    reg                     rlast_r;
    reg  [DATA_WIDTH-1:0]   rdata_r;
    reg  [1:0]              rresp_r;
    reg  [3:0]              rid_r;
    // 请求/缓冲寄存器
    reg  [ADDR_WIDTH-1:0]   awaddr_r;
    reg  [3:0]              awid_r;
    reg  [7:0]              awlen_r;
    reg  [2:0]              awsize_r;
    reg  [1:0]              awburst_r;
    reg  [DATA_WIDTH-1:0]   wdata_r;
    reg  [3:0]              wstrb_r;
    reg                     wlast_r;
    reg                     bvalid_r;
    reg  [1:0]              bresp_r;
    reg  [3:0]              bid_r;
    // 地址生成
    wire [1:0] aw_misalign = awaddr_r[1:0] & ((1 << awsize_r) - 1);
    wire aw_overstep = awaddr_r != 32'h1000_0000;
    // ====== 逻辑实现 ======
    // 读操作
    always @(posedge clk) begin
        if (reset) begin
            ar_pending <= 0;
            araddr_r   <= 0;
            arid_r     <= 0;
            arlen_r    <= 0;
            arsize_r   <= 0;
            arburst_r  <= 0;
            rvalid_r   <= 0;
            rlast_r    <= 0;
            rdata_r    <= 0;
            rresp_r    <= 0;
            rid_r      <= 0;
        end else begin
            if (ar_fire) begin
                ar_pending <= 1;
                araddr_r   <= s_araddr_i;
                arid_r     <= s_arid_i;
                arlen_r    <= s_arlen_i;
                arsize_r   <= s_arsize_i;
                arburst_r  <= s_arburst_i;
                $display("你不应该读串口吧");
                $stop;
            end
            if (r_fire) begin
                ar_pending <= 0;
                araddr_r   <= 0;
                arid_r     <= 0;
                arlen_r    <= 0;
                arsize_r   <= 0;
                arburst_r  <= 0;
                rvalid_r   <= 0;
                rlast_r    <= 0;
                rdata_r    <= 0;
                rresp_r    <= 0;
                rid_r      <= 0;
            end
        end
    end

    // 写操作
    always @(posedge clk) begin
        if(reset) begin
            aw_pending  <= 0;
            w_pending   <= 0;
            awaddr_r    <= 0;
            awid_r      <= 0;
            awlen_r     <= 0;
            awsize_r    <= 0;
            awburst_r   <= 0;
            wdata_r     <= 0;
            wstrb_r     <= 0;
            wlast_r     <= 0;
            bvalid_r    <= 0;
            bresp_r     <= 0;
            bid_r       <= 0;
        end else begin
            if (aw_fire) begin
                aw_pending <= 1'b1       ;
                awaddr_r   <= s_awaddr_i ;
                awid_r     <= s_awid_i   ;
                awlen_r    <= s_awlen_i  ; 
                awsize_r   <= s_awsize_i ;
                awburst_r  <= s_awburst_i;
            end
            if (w_fire) begin
                w_pending  <= 1'b1       ;
                wdata_r    <= s_wdata_i  ;
                wstrb_r    <= s_wstrb_i  ;
                wlast_r    <= s_wlast_i  ;
            end
            if (aw_pending && w_pending && ~bvalid_r) begin
                // 对齐检查：地址低位必须为 0
                if (aw_misalign != 0) begin
                    $display("你在写串口的时候好像没有对齐地址");
                    $stop;
                end else if(aw_overstep) begin
                    $display("写串口地址错误,读地址为:%08x",awaddr_r);
                    $stop;
                end else begin
                    if(wstrb_r[0]) begin
                        $write("%c",wdata_r[7:0]);
                        $fflush();  
                    end else begin
                        $display("写串口时的wstrb好像没有设置好");
                        $stop;
                    end
                    bresp_r <= 2'b00; // OKAY
                end
                bid_r   <= awid_r;
                bvalid_r <= 1'b1;
            end
            if (b_fire) begin
                aw_pending  <= 0;
                w_pending   <= 0;
                awaddr_r    <= 0;
                awid_r      <= 0;
                awlen_r     <= 0;
                awsize_r    <= 0;
                awburst_r   <= 0;
                wdata_r     <= 0;
                wstrb_r     <= 0;
                wlast_r     <= 0;
                bvalid_r    <= 0;
                bresp_r     <= 0;
                bid_r       <= 0;
            end
        end
    end

    // ready/valid 输出连接
    assign s_awready_o = ~aw_pending;
    assign s_wready_o  = ~w_pending;
    assign s_arready_o = ~ar_pending;

    assign s_bvalid_o  = bvalid_r;
    assign s_bresp_o   = bresp_r;
    assign s_bid_o     = bid_r;

    assign s_rvalid_o  = rvalid_r;
    assign s_rlast_o   = rlast_r; 
    assign s_rdata_o   = rdata_r;
    assign s_rresp_o   = rresp_r;
    assign s_rid_o     = rid_r;
endmodule // ysyx_25050136_SRAM
