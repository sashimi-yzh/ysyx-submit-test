`define ysyx_26010027_ICACHE
module ysyx_26010027_icache (
    input             clock,
    input             reset,
    input             flush_i, // fence.i 清空 cache

    // ----- IFU -----
    input         ifu_arvalid,
    output        ifu_arready,
    input  [31:0] ifu_araddr,
    output        ifu_rvalid,
    input         ifu_rready,
    output [31:0] ifu_rdata,
    output [ 1:0] ifu_rresp,

    // ----- Arbiter -----
    output        arb_arvalid,
    input         arb_arready,
    output [31:0] arb_araddr,
    output [ 3:0] arb_arid,
    input         arb_rvalid,
    output        arb_rready,
    input  [31:0] arb_rdata,
    input  [ 1:0] arb_rresp,
    output [ 7:0] arb_arlen,
    output [ 2:0] arb_arsize,
    output [ 1:0] arb_arburst
);

`ifdef ysyx_26010027_ICACHE
    // ----- cache parameters -----
    parameter BLOCK_SIZE = 8; // 块大小 8B
    parameter BLOCK_NUMS = 2; // cache 块数
    parameter WAYS       = 1;  // 组内的相联度

    parameter SET_NUMS   = BLOCK_NUMS / WAYS; // 组数
    parameter INDEX_W    = $clog2(SET_NUMS);
    parameter BLK_OFF_W  = $clog2(BLOCK_SIZE);
    parameter TAG_W      = 32 - INDEX_W - BLK_OFF_W;
    parameter BEATS      = BLOCK_SIZE / 4; // burst 拍数
    // 自适应位宽
    localparam BURST_W   = (BEATS == 1) ? 1 : $clog2(BEATS);
    localparam WAY_W     = (WAYS  == 1) ? 1 : $clog2(WAYS);
    localparam WORD_W    = (BEATS == 1) ? 1 : BLK_OFF_W - 2;
    localparam LAST_BEAT = BEATS - 1;   // 末拍拍号
    localparam [7:0] BURST_LEN = BEATS - 1; // arlen 用, 8bit 避免 lint

    // ----- cache regs -----
    reg                    valid [SET_NUMS-1:0][WAYS-1:0];
    reg [TAG_W-1:0]        tag   [SET_NUMS-1:0][WAYS-1:0];
    reg [BLOCK_SIZE*8-1:0] data  [SET_NUMS-1:0][WAYS-1:0];

    // ----- state -----
    reg [1:0] state;
    localparam IDLE  = 2'b00;
    localparam WAIT  = 2'b01;
    localparam BURST = 2'b10;

    wire [INDEX_W-1:0] index_q = ifu_araddr[BLK_OFF_W + INDEX_W - 1 : BLK_OFF_W]; // addr[7:4]
    wire [TAG_W-1:0]   tag_q   = ifu_araddr[31 : BLK_OFF_W + INDEX_W]; // addr[31:8]

    // ----- 组相联 -----
    reg hit;
    reg [WAY_W-1:0] hit_way; // 记录命中的 way
    reg [WAY_W-1:0] miss_way; // 记录替换的 way (RR 替换)
    integer nway; // 中间变量
    reg [WAY_W-1:0]   repl_cnt [SET_NUMS-1:0]; //  RR 替换
    always @(*) begin
        hit      = 1'b0;
        hit_way  = 0;
        /*verilator lint_off WIDTHEXPAND*/ 
        miss_way = repl_cnt[index_q];
        for (nway = 0; nway < WAYS; nway++) begin
            if (valid[index_q][nway] && (tag[index_q][nway] == tag_q)) begin
                hit = 1'b1;
                hit_way = nway[WAY_W-1:0];
            end else if (!valid[index_q][nway]) begin
                miss_way = nway[WAY_W-1:0];
            end
        end
    end

    // ----- out to Arb -----
    reg [31:0] araddr_o;
    reg        arvalid_o;
    reg        rready_o;
    reg [ 7:0] arlen_o;
    assign arb_araddr  = araddr_o;
    assign arb_arvalid = arvalid_o;
    assign arb_rready  = rready_o;
    assign arb_arlen   = arlen_o; // 拍数动态变化
    assign arb_arsize  = 3'd2; // 4B
    assign arb_arburst = 2'b01; // INCR
    assign arb_arid    = 4'b0; // 硬编码

    // ----- out to IFU -----
    reg [31:0] rdata_o;
    reg        rvalid_o;
    assign ifu_rvalid  = rvalid_o;
    assign ifu_rdata   = rdata_o;
    assign ifu_rresp   = (state == BURST && arb_rvalid) ? arb_rresp : 2'b00;
    assign ifu_arready = (state == IDLE) && ifu_arvalid;

    wire handshake_ar = arb_arvalid && arb_arready;
    wire handshake_r  = arb_rvalid  && arb_rready;
    wire [WORD_W-1:0] word_sel = ifu_araddr[BLK_OFF_W-1 : 2]; // 块内字选择

    // 计数
    reg [BURST_W-1:0] burst_count;
    integer i;
    integer j;

    // ----- FSM -----
    always @(posedge clock, posedge reset) begin
        if (reset) begin
            state     <= IDLE;
            araddr_o  <= 32'b0;
            arvalid_o <= 1'b0;
            rready_o  <= 1'b0;
            arlen_o   <= 8'b0;
            rvalid_o  <= 1'b0;
            rdata_o   <= 32'b0;
            for (i = 0; i < SET_NUMS; i++) begin
                for (j = 0; j < WAYS; j++)
                    valid[i][j] <= 1'b0;
                repl_cnt[i] <= {WAY_W{1'b0}};
            end
        end else begin
            if (rvalid_o && ifu_rready) rvalid_o <= 1'b0;
            // fence.i 清空 cache
            if (flush_i) begin
                for (i = 0; i < SET_NUMS; i = i + 1)
                    for (j = 0; j < WAYS; j = j + 1)
                        valid[i][j] <= 1'b0;
            end
            case (state)
                IDLE: begin
                    if (ifu_arvalid) begin
                        if (hit) begin
                            // HIT
                            rvalid_o  <= 1'b1;
                            rdata_o   <= data[index_q][hit_way][word_sel*32 +: 32];
                        end else begin
                            // MISS
                            araddr_o   <= {ifu_araddr[31:BLK_OFF_W], {BLK_OFF_W{1'b0}}}; // 地址对齐
                            arvalid_o  <= 1'b1;
                            arlen_o    <= BURST_LEN; // BEATS-1
                            state       <= WAIT;
                            burst_count <= {BURST_W{1'b0}};
                        end
                    end
                end
                WAIT: begin
                    if (handshake_ar) begin
                        arvalid_o <= 1'b0;
                        rready_o  <= 1'b1;
                        state     <= BURST;
                    end
                end
                BURST: begin
                    if (handshake_r) begin
                        // 每拍数据写入 cache line 对应位置
                        data[index_q][miss_way][burst_count*32 +: 32] <= arb_rdata;
                        // 返回 IFU 所需字数据
                        if (burst_count == word_sel) begin
                            rdata_o  <= arb_rdata;
                        end
                        // 最后一拍: 填 tag/valid, 记录延迟, 返回 IDLE
                        if (burst_count == LAST_BEAT) begin
                            tag[index_q][miss_way]   <= tag_q;
                            repl_cnt[index_q] <= (miss_way == WAYS - 1) ? {WAY_W{1'b0}} : (miss_way + 1'b1);

                            valid[index_q][miss_way] <= 1'b1;
                            rvalid_o <= 1'b1;
                            rready_o <= 1'b0;
                            state <= IDLE;
                        end else begin
                            burst_count <= burst_count + 1;
                        end
                    end
                end
                default: state <= IDLE;
            endcase
        end
    end

    wire unused_ok = &{ifu_araddr[1:0], 1'b1};

`else
    assign arb_arvalid = ifu_arvalid;
    assign arb_araddr  = ifu_araddr;
    assign arb_arid    = 4'b0; // 硬编码
    assign arb_arlen   = 8'd0;
    assign arb_arsize  = 3'd2;
    assign arb_arburst = 2'b01; // INCR
    assign arb_rready  = ifu_rready;
    assign ifu_arready = arb_arready;
    assign ifu_rvalid  = arb_rvalid;
    assign ifu_rdata   = arb_rdata;
    assign ifu_rresp   = arb_rresp;
    wire unused_ok = &{flush_i, clock, reset, 1'b1};

`endif

endmodule
