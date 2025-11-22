module ysyx_25010030_dCache #(
    parameter CACHE_SIZE = 64,
    parameter BLOCK_SIZE = 16
)(
    input              clk                ,
    input              rst                ,
    input       [31:0] lsu_addr           ,
    input              lsu_req            ,
    input              lsu_we             ,
    output reg         dcache_valid       ,
    input       [31:0] lsu_wdata          ,
    input       [ 3:0] lsu_wstrb          ,
    input       [ 2:0] lsu_arsize         ,
    input       [ 2:0] lsu_awsize         ,
    output reg  [31:0] dcache_rdata       ,
    input              is_fencei          , 

    // AXI4 <R> Channel
    output reg         dcache_axi_arvalid ,
    input              axi_dcache_arready ,
    output wire [31:0] dcache_axi_araddr  ,
    output wire [ 3:0] dcache_axi_arid    ,
    output wire [ 7:0] dcache_axi_arlen   ,
    output wire [ 2:0] dcache_axi_arsize  ,
    output wire [ 1:0] dcache_axi_arburst ,
    input              axi_dcache_rvalid  ,
    output reg         dcache_axi_rready  ,
    input       [31:0] axi_dcache_rdata   ,
    input       [ 3:0] axi_dcache_rid     ,
    input              axi_dcache_rlast   ,
    input       [ 1:0] axi_dcache_rresp   ,

    // AXI4 <W> Channel
    output reg         dcache_axi_awvalid ,
    input              axi_dcache_awready ,
    output wire [31:0] dcache_axi_awaddr  ,
    output wire [ 3:0] dcache_axi_awid    ,
    output wire [ 7:0] dcache_axi_awlen   ,
    output wire [ 2:0] dcache_axi_awsize  ,
    output wire [ 1:0] dcache_axi_awburst ,
    output reg         dcache_axi_wvalid  ,
    input              axi_dcache_wready  ,
    output wire [31:0] dcache_axi_wdata   ,
    output wire [ 3:0] dcache_axi_wstrb   ,
    output reg         dcache_axi_wlast   ,

    // AXI4 <B> Channel
    input              axi_dcache_bvalid  ,
    output wire        dcache_axi_bready  ,
    input       [ 3:0] axi_dcache_bid     ,
    input       [ 1:0] axi_dcache_bresp
);

    localparam CACHE_LINES       = CACHE_SIZE / BLOCK_SIZE;
    localparam OFFSET_WIDTH      = $clog2(BLOCK_SIZE);
    localparam INDEX_WIDTH       = $clog2(CACHE_LINES);
    localparam TAG_WIDTH         = 32 - INDEX_WIDTH - OFFSET_WIDTH;

    localparam SDRAM_BASE        = 32'hA0000000;
    localparam SDRAM_END         = 32'hBFFFFFFF;
    localparam SRAM_BASE         = 32'h0F000000;
    localparam SRAM_END          = 32'h0FFFFFFF;
    localparam PSRAM_BASE        = 32'h80000000;
    localparam PSRAM_END         = 32'h9FFFFFFF;
    localparam FLASH_BASE        = 32'h30000000;
    localparam FLASH_END         = 32'h3FFFFFFF;

    localparam AXI_BURST_FIXED   = 2'b00;
    localparam AXI_BURST_INCR    = 2'b01;
    localparam AXI_SIZE_BYTE     = 3'h0;
    localparam AXI_SIZE_HALF     = 3'h1;
    localparam AXI_SIZE_WORD     = 3'h2;
    localparam AXI_ID            = 4'h0;
    localparam AXI_BURST_LEN     = 4;

    // 判断地址是否在缓存管理的内存区域
`ifdef YSYXSOC
    // wire in_dmem = ((saved_addr >= SDRAM_BASE) && (saved_addr <= SDRAM_END) ||
    //                 (saved_addr >= SRAM_BASE ) && (saved_addr <= SRAM_END ) ||
    //                 (saved_addr >= PSRAM_BASE) && (saved_addr <= PSRAM_END) ||
    //                 (saved_addr >= FLASH_BASE) && (saved_addr <= FLASH_END));
    wire in_dmem = ((lsu_addr >= SDRAM_BASE) && (lsu_addr <= SDRAM_END) ||
                    (lsu_addr >= SRAM_BASE ) && (lsu_addr <= SRAM_END ) ||
                    (lsu_addr >= PSRAM_BASE) && (lsu_addr <= PSRAM_END) ||
                    (lsu_addr >= FLASH_BASE) && (lsu_addr <= FLASH_END));
`else
    wire in_dmem = 0;
`endif

    reg [   TAG_WIDTH-1:0] cache_tag   [0:CACHE_LINES-1];
    reg                    cache_valid [0:CACHE_LINES-1];
    reg                    cache_dirty [0:CACHE_LINES-1];
    reg [BLOCK_SIZE*8-1:0] cache_data  [0:CACHE_LINES-1];

    localparam IDLE          = 3'b000;
    localparam LOOKUP        = 3'b001;
    localparam HIT_HANDLE    = 3'b010;
    localparam MISS_WB       = 3'b011;  // 正常替换写回
    localparam MISS_LOAD     = 3'b100;
    localparam FENCEI_DIRTY  = 3'b101;  // 遍历脏块
    localparam FENCEI_WB     = 3'b110;  // fencei 专用写回状态

    reg [2:0] state, next_state;

    reg [            31:0] saved_addr;
    reg [            31:0] saved_wdata;
    reg [             3:0] saved_wstrb;
    reg                    saved_we;
    reg [   TAG_WIDTH-1:0] req_tag;
    reg [ INDEX_WIDTH-1:0] req_index;
    reg [OFFSET_WIDTH-1:0] req_offset;

    reg [             7:0] burst_cnt;
    reg ar_done, aw_done, w_done, b_done;

    // fencei 专用
    reg [            31:0] fencei_cnt;//计数器
    reg [ INDEX_WIDTH-1:0] fencei_index;
    reg                    fencei_active;
    reg                    wb_is_fencei;  // 当前写回是否为 fencei 触发

    // 当前写回使用的索引
    wire [INDEX_WIDTH-1:0] wb_index = wb_is_fencei ? fencei_index : req_index;

    always @(posedge clk) begin
        if (rst) state <= IDLE;
        else     state <= next_state;
    end

    always @(*) begin
        case (state)
            IDLE: begin
                // next_state = is_fencei ? FENCEI_DIRTY : (lsu_req ? LOOKUP : IDLE);
                if (is_fencei) begin
                    next_state = FENCEI_DIRTY;
                end
                else if (lsu_req) begin
                    next_state = in_dmem ? LOOKUP : (lsu_we ? MISS_WB : MISS_LOAD);
                end
                else begin
                    next_state = IDLE;
                end
            end
            LOOKUP: begin
                next_state = (cache_valid[req_index] && cache_tag[req_index] == req_tag)
                           ? HIT_HANDLE
                           : (cache_dirty[req_index] ? MISS_WB : MISS_LOAD);
            end
            HIT_HANDLE: next_state = IDLE;

            MISS_WB:  // 正常替换写回 → 必须加载新块
                // next_state = (aw_done && w_done && b_done) ? MISS_LOAD : MISS_WB;
                next_state = (aw_done && w_done && b_done) ? (in_dmem ? MISS_LOAD : IDLE) : MISS_WB;

            FENCEI_WB:  // fencei 写回 → 不加载，直接回到 FENCEI_DIRTY
                next_state = (aw_done && w_done && b_done) ? FENCEI_DIRTY : FENCEI_WB;

            MISS_LOAD:
                next_state = (axi_dcache_rvalid && dcache_axi_rready && axi_dcache_rlast) ? (in_dmem ? LOOKUP : IDLE) : MISS_LOAD;

            FENCEI_DIRTY: begin
                if (fencei_cnt < CACHE_LINES) begin
                    if (cache_dirty[fencei_index])
                        next_state = FENCEI_WB;
                    else
                        next_state = FENCEI_DIRTY;
                end else
                    next_state = IDLE;
            end

            default: next_state = IDLE;
        endcase
    end

    integer i;
    always @(posedge clk) begin
        if (rst) begin
            for (i = 0; i < CACHE_LINES; i = i + 1) begin
                cache_valid[i] <= 1'b0;
                cache_dirty[i] <= 1'b0;
            end
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            fencei_cnt    <= 0;
            fencei_index  <= 0;
            fencei_active <= 0;
            wb_is_fencei  <= 0;
        end
        else if (state == IDLE && is_fencei) begin
            fencei_cnt    <= 0;
            fencei_index  <= 0;
            fencei_active <= 1;
            wb_is_fencei  <= 1;
        end
        else if (state == FENCEI_DIRTY) begin
            if (fencei_cnt < CACHE_LINES) begin
                if (cache_dirty[fencei_index] && aw_done && w_done && b_done) begin
                    fencei_cnt   <= fencei_cnt + 1;
                    fencei_index <= fencei_index + 1;
                end
                else if (!cache_dirty[fencei_index]) begin
                    fencei_cnt   <= fencei_cnt + 1;
                    fencei_index <= fencei_index + 1;
                end
            end 
            else begin
                fencei_active <= 0;
                wb_is_fencei  <= 0;
            end
        end
        else if (state == MISS_WB && aw_done && w_done && b_done) begin
            wb_is_fencei <= 0;  // 正常写回结束
        end
        else begin
            fencei_active <= 0;
        end
    end

    always @(posedge clk) begin
        if (rst) begin
            saved_addr  <= 0;
            saved_wdata <= 0;
            saved_wstrb <= 0;
            saved_we    <= 0;
            req_tag     <= 0;
            req_index   <= 0;
            req_offset  <= 0;
        end
        else if (state == IDLE && lsu_req) begin
            saved_addr  <= lsu_addr;
            saved_wdata <= lsu_wdata;
            saved_wstrb <= lsu_wstrb;
            saved_we    <= lsu_we;
            req_tag     <= lsu_addr[31 -: TAG_WIDTH];
            req_index   <= lsu_addr[OFFSET_WIDTH +: INDEX_WIDTH];
            req_offset  <= lsu_addr[0 +: OFFSET_WIDTH];
        end
    end

    wire [OFFSET_WIDTH-1:0] aligned_offset = req_offset & ~{{(OFFSET_WIDTH-2){1'b0}}, 2'b11};
    always @(posedge clk) begin
        if (rst) begin
            dcache_valid <= 0;
            dcache_rdata <= 0;
        end
        else if (state == HIT_HANDLE) begin
            dcache_valid <= 1;
            if (!saved_we) begin
                // dcache_rdata <= cache_data[req_index][req_offset*8 +: 32];
                dcache_rdata <= cache_data[req_index][aligned_offset*8 +: 32];
            end
            else begin
                // if (saved_wstrb[0]) cache_data[req_index][   req_offset*8 +: 8] <= saved_wdata[7:0];
                // if (saved_wstrb[1]) cache_data[req_index][ req_offset*8+8 +: 8] <= saved_wdata[15:8];
                // if (saved_wstrb[2]) cache_data[req_index][req_offset*8+16 +: 8] <= saved_wdata[23:16];
                // if (saved_wstrb[3]) cache_data[req_index][req_offset*8+24 +: 8] <= saved_wdata[31:24];
                if (saved_wstrb[0]) cache_data[req_index][ (aligned_offset + 0)*8 +: 8] <= saved_wdata[ 7:0];
                if (saved_wstrb[1]) cache_data[req_index][ (aligned_offset + 1)*8 +: 8] <= saved_wdata[15:8];
                if (saved_wstrb[2]) cache_data[req_index][ (aligned_offset + 2)*8 +: 8] <= saved_wdata[23:16];
                if (saved_wstrb[3]) cache_data[req_index][ (aligned_offset + 3)*8 +: 8] <= saved_wdata[31:24];
                cache_dirty[req_index] <= 1;
            end
        end
        else begin
            dcache_valid <= (state == MISS_WB && aw_done && w_done && b_done && !in_dmem);
        end
    end

    assign dcache_axi_araddr  = in_dmem ? {saved_addr[31:OFFSET_WIDTH], {OFFSET_WIDTH{1'b0}}} : saved_addr;
    assign dcache_axi_arid    = AXI_ID;
    assign dcache_axi_arsize  = in_dmem ? AXI_SIZE_WORD : lsu_arsize;
    assign dcache_axi_arlen   = in_dmem ? AXI_BURST_LEN - 1 : 8'h0;
    assign dcache_axi_arburst = in_dmem ? AXI_BURST_INCR : AXI_BURST_FIXED;

    always @(posedge clk) begin
        if (rst) begin
            dcache_axi_arvalid <= 0;
            dcache_axi_rready  <= 0;
            burst_cnt          <= 0;
            ar_done            <= 0;
        end
        else if (state == MISS_LOAD) begin
            dcache_axi_rready <= 1;
            if (!dcache_axi_arvalid && !ar_done) dcache_axi_arvalid <= 1;
            else if (dcache_axi_arvalid && axi_dcache_arready) begin
                dcache_axi_arvalid <= 0;
                ar_done            <= 1;
            end

            if (axi_dcache_rvalid && dcache_axi_rready) begin
                if (in_dmem) begin
                    cache_data[req_index][burst_cnt*32 +: 32] <= axi_dcache_rdata;
                    burst_cnt <= burst_cnt + 1;
                end
                else begin
                    // cache_data[req_index][req_offset*8 +: 32] <= axi_dcache_rdata;
                    dcache_rdata <= axi_dcache_rdata;
                end

                if (axi_dcache_rlast) begin
                    if (in_dmem) begin
                        cache_tag[req_index]   <= req_tag;
                        cache_valid[req_index] <= 1;
                        cache_dirty[req_index] <= 0;
                        burst_cnt              <= 0;
                    end
                    else begin
                        dcache_valid <= 1;
                    end
                end
            end
        end
        else begin
            dcache_axi_arvalid <= 0;
            dcache_axi_rready  <= 0;
            ar_done            <= 0;
        end
    end

    assign dcache_axi_awaddr  = in_dmem ? {cache_tag[wb_index], wb_index, {OFFSET_WIDTH{1'b0}}} : saved_addr;
    assign dcache_axi_awid    = AXI_ID;
    assign dcache_axi_awsize  = in_dmem ? AXI_SIZE_WORD : lsu_awsize;
    assign dcache_axi_awlen   = in_dmem ? AXI_BURST_LEN - 1 : 8'h0;
    assign dcache_axi_awburst = in_dmem ? AXI_BURST_INCR : AXI_BURST_FIXED;

    assign dcache_axi_wdata   = in_dmem ? cache_data[wb_index][burst_cnt*32 +: 32] : saved_wdata;
    assign dcache_axi_wstrb   = in_dmem ? 4'b1111 : saved_wstrb;
    assign dcache_axi_bready  = 1'b1;

    always @(posedge clk) begin
        if (rst) begin
            dcache_axi_awvalid <= 0;
            dcache_axi_wvalid  <= 0;
            dcache_axi_wlast   <= 0;
            burst_cnt          <= 0;
            aw_done            <= 0; 
            w_done             <= 0; 
            b_done             <= 0;
        end
        else if (state == MISS_WB || state == FENCEI_WB) begin
            // 发送 AW
            if (!dcache_axi_awvalid && !aw_done) begin
                dcache_axi_awvalid <= 1;
            end
            else if (dcache_axi_awvalid && axi_dcache_awready) begin
                dcache_axi_awvalid <= 0;
                aw_done            <= 1;
            end

            // 发送 W
            if (!dcache_axi_wvalid && !w_done) begin
                dcache_axi_wvalid <= 1;
                dcache_axi_wlast  <= in_dmem ? (burst_cnt == AXI_BURST_LEN - 1) : 1;
            end
            else if (dcache_axi_wvalid && axi_dcache_wready) begin
                dcache_axi_wvalid <= 0;
                burst_cnt         <= burst_cnt + 1;
                if (dcache_axi_wlast) begin
                    dcache_axi_wlast <= 0;
                    w_done           <= 1;
                    burst_cnt        <= 0;
                end
            end

            // 接收 B
            if (axi_dcache_bvalid && dcache_axi_bready) begin
                cache_dirty[wb_index] <= 0;
                b_done                <= 1;
            end
        end
        else begin
            dcache_axi_awvalid <= 0;
            dcache_axi_wvalid  <= 0;
            dcache_axi_wlast   <= 0;
            aw_done            <= 0; 
            w_done             <= 0; 
            b_done             <= 0;
        end
    end

endmodule