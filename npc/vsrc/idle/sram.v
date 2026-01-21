module ysyx_25050136_SRAM
    #(
        parameter ADDR_WIDTH    = 32,
        parameter DATA_WIDTH    = 32,
        parameter INIT_FILE     = "default.hex"  // 初始化文件路径
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

    
    localparam MEM_SIZE_BYTES = 4 * 1024 * 1024; // 4 MB
    localparam MEM_WIDTH      = $clog2(MEM_SIZE_BYTES);
    
    // ====== 信号定义 ======
    reg [7:0] mem [0:MEM_SIZE_BYTES-1];
    reg [31:0] flash [0:15]; // 用于让程序从3000_0000跳转到8000_0000
    reg                     aw_pending;
    reg                      w_pending;
    reg                     ar_pending;
    // 握手信号
    wire aw_fire = s_awvalid_i & s_awready_o;
    wire w_fire  = s_wvalid_i  & s_wready_o;
    wire ar_fire = s_arvalid_i & s_arready_o;
    wire b_fire  = s_bvalid_o    & s_bready_i;
    wire r_fire  = s_rvalid_o    & s_rready_i;
    // 读寄存器
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
    // 写寄存器
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
    wire aw_overstep = (awaddr_r < 32'h8000_0000) || (awaddr_r >= (32'h8000_0000 + MEM_SIZE_BYTES));
    wire [MEM_WIDTH -1:0] aw_memaddr = {awaddr_r[MEM_WIDTH-1:2], 2'b00};
    wire [1:0] ar_misalign = araddr_r[1:0] & ((1 << arsize_r) - 1);
    wire ar_overstep = (araddr_r < 32'h8000_0000) || (araddr_r >= (32'h8000_0000 + MEM_SIZE_BYTES));
    wire ar_inflash = (araddr_r >= 32'h3000_0000) && (araddr_r < 32'h3000_0000 + 64);
    wire [3:0] ar_flashaddr = araddr_r[5:2];
    wire [MEM_WIDTH -1:0] ar_memaddr = {araddr_r[MEM_WIDTH-1:2], 2'b00};
    // ====== 逻辑实现 ======
    integer i;
    // 初始化内存：优先使用 INIT_FILE，否则清 0
    initial begin
        $readmemh(INIT_FILE, mem);
        for (i = 0; i < 200 * 4; i = i + 4) begin
            // $display("mem[%0d-%0d] = %h", i, i+3, {mem[i+3], mem[i+2], mem[i+1], mem[i]});
        end
        // 初始化 flash 跳转代码
        flash[0]  = 32'h80000437; // lui s0,0x80000
        flash[1]  = 32'h00040067; // jr s0 #8000_0000
        for (i = 2; i < 16; i = i + 1) begin
            flash[i] = 32'h00000013; // nop
        end
    end

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
            end
            if (ar_pending && ~rvalid_r) begin
                if (ar_misalign != 0) begin
                    $display("非对齐读RAM");
                    $stop;
                end else if(ar_inflash) begin
                    rresp_r <= 2'b00;
                    rdata_r <= flash[ar_flashaddr];
                end else if(ar_overstep)begin
                    $display("读RAM地址越界,读地址为:%08x",araddr_r);
                    $stop;
                end else begin
                    rresp_r <= 2'b00; 
                    rdata_r <= {mem[ar_memaddr + 3],
                                mem[ar_memaddr + 2],
                                mem[ar_memaddr + 1],
                                mem[ar_memaddr + 0]};
                end
                rvalid_r    <= 1'b1;
                rlast_r     <= 1'b1;
                rid_r       <= arid_r; // 返回请求 id
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
                    $display("非对齐写RAM");
                    $stop;
                end else if(aw_overstep) begin
                    $display("写RAM地址越界,写地址为:%08x",awaddr_r);
                    $stop;
                end else begin
                    if(wstrb_r[0]) mem[aw_memaddr + 0] <= wdata_r[7:0];
                    if(wstrb_r[1]) mem[aw_memaddr + 1] <= wdata_r[15:8];
                    if(wstrb_r[2]) mem[aw_memaddr + 2] <= wdata_r[23:16];
                    if(wstrb_r[3]) mem[aw_memaddr + 3] <= wdata_r[31:24];
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
