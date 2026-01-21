module ysyx_25050136_ICACHE
#(
    parameter OFFSET_WIDTH = 4,
    parameter NUM_WAY = 1,
    parameter INDEX_WIDTH = 2
)
(
    input                                      clk          ,
    input                                      reset        ,
    // CPU 接口
    input                                   flush           ,
    input                                   fencei          ,
    input                                   in_valid_i      ,
    input    [31:0]                         in_pc_i         ,
    input    [31:0]                         in_prepc_i      ,
    input                                   in_taken_i      ,
    input                                   in_btb_hit_i    ,
    output                                  in_ready_o      ,
    input                                   out_ready_i     ,
    output   [31:0]                         out_inst_o      ,
    output   [31:0]                         out_pc_o        ,
    output   [31:0]                         out_prepc_o     ,
    output                                  out_taken_o     ,
    output                                  out_btb_hit_o   ,
    output                                  out_valid_o     ,
    // AXI 接口
    output                                  req_valid_o     ,
    // output   [31:0]                         req_addr_o      ,
    input                                   ret_valid_i     ,
    input                                   ret_last_i      ,
    input    [31:0]                         ret_data_i   
);

    // ==================== 参数 ====================
    parameter LINE_WIDTH   = 8 << OFFSET_WIDTH;
    parameter WORDS        = 1 << (OFFSET_WIDTH - 2);
    parameter TAG_WIDTH    = 32 - OFFSET_WIDTH - INDEX_WIDTH;
    parameter NUM_SET      = 1 << INDEX_WIDTH;
    parameter WAY_WIDTH    = (NUM_WAY > 1) ? $clog2(NUM_WAY) : 1;
    parameter OFFSET_INDEX = (OFFSET_WIDTH > 2) ? OFFSET_WIDTH-2 : 1;
    localparam IDLE = 1'd0;
    localparam MISS = 1'd1;

    // ==================== 信号定义 ====================
    
    // 存储阵列
    reg [LINE_WIDTH-1:0] cache_data  [0:NUM_WAY-1][0:NUM_SET-1]; 
    reg [TAG_WIDTH-1 :0] cache_tag   [0:NUM_WAY-1][0:NUM_SET-1];
    reg                  cache_valid [0:NUM_WAY-1][0:NUM_SET-1];

    // 流水寄存器
    reg        idle;
    reg [31:0] ic_addr;
    reg [31:0] ic_prepc;
    reg        ic_taken;
    reg        ic_btb_hit;

    // 状态机寄存器
    reg state;
    reg [WAY_WIDTH-1:0] replace_way; 
    reg [WAY_WIDTH-1:0] miss_way;    

    // 中间信号
    wire in_fire;
    wire out_fire;
    wire ready_go;
    wire miss;
    
    wire [INDEX_WIDTH-1:0]  addr_index;
    wire [TAG_WIDTH-1:0]    addr_tag;
    wire [OFFSET_INDEX-1:0] addr_offset;

    reg  [NUM_WAY-1:0]    hit_mask;
    reg  [LINE_WIDTH-1:0] selected_line;
    
    wire [31:0] line_word [0:WORDS-1];
    wire [31:0] buf_word  [0:WORDS-1];
    wire [31:0] hit_word;
    wire [31:0] miss_word;

    // 循环变量
    integer k, m, n;
    genvar i;

    // ==================== 逻辑赋值 ====================

    // --- 1. 地址解析与握手 ---
    assign addr_index  = ic_addr[OFFSET_WIDTH+INDEX_WIDTH-1:OFFSET_WIDTH];
    assign addr_tag    = ic_addr[31:OFFSET_WIDTH+INDEX_WIDTH];
    assign addr_offset = (OFFSET_WIDTH > 2) ? ic_addr[OFFSET_WIDTH-1:2] : 0;

    assign in_fire  = in_valid_i & in_ready_o;
    assign out_fire = out_valid_o & out_ready_i;

    // --- 2. 输入流水寄存器更新 ---
    always @(posedge clk) begin
        if (reset) begin
            idle    <= 1'b1;
        end else begin
            idle <= (flush) | (!in_fire & out_fire) | (!in_fire & !flush & idle);
            if (in_fire) begin
                ic_addr    <= in_pc_i;
                ic_prepc   <= in_prepc_i;
                ic_taken   <= in_taken_i;
                ic_btb_hit <= in_btb_hit_i;
            end
        end
    end

    // --- 3. TAG 比较与数据选取（组合逻辑） ---
    always @(*) begin
        hit_mask = {NUM_WAY{1'b0}};
        for (k = 0; k < NUM_WAY; k = k + 1) begin
            if (cache_valid[k][addr_index] && (cache_tag[k][addr_index] == addr_tag))
                hit_mask[k] = 1'b1;
        end
    end

    assign miss = ~(|hit_mask);

    always @(*) begin
        selected_line = {LINE_WIDTH{1'b0}};
        for (k = 0; k < NUM_WAY; k = k + 1) begin
            if (hit_mask[k]) selected_line = cache_data[k][addr_index];
        end
    end

    generate
        for (i = 0; i < WORDS; i = i + 1) begin : SPLIT_HIT
            assign line_word[i] = selected_line[i*32 +: 32];
        end
        for (i = 0; i < WORDS; i = i + 1) begin : SPLIT_MISS
            assign buf_word[i] = cache_data[miss_way][addr_index][i*32 +: 32];
        end
    endgenerate

    assign hit_word  = line_word[addr_offset];
    assign miss_word = buf_word[addr_offset];

    // --- 4. 状态机与 Cache 维护 ---
    always @(posedge clk) begin
        if (reset) begin
            state       <= IDLE;
            replace_way <= 0;
            miss_way    <= 0;
            for (m = 0; m < NUM_WAY; m = m + 1) begin
                for (n = 0; n < NUM_SET; n = n + 1) begin
                    cache_valid[m][n] <= 1'b0;
                end
            end
        end else begin
            if (flush) begin
                if (fencei) begin
                    for (m = 0; m < NUM_WAY; m = m + 1) begin
                        for (n = 0; n < NUM_SET; n = n + 1) begin
                            cache_valid[m][n] <= 1'b0;
                        end
                    end
                end else if (state == MISS) begin
                    cache_valid[miss_way][addr_index] <= 1'b0;
                end
                state <= IDLE;
            end else begin
                case (state)
                    IDLE: begin
                        if (!idle && miss) begin
                            state    <= MISS;
                            miss_way <= replace_way;
                        end
                        replace_way <= (NUM_WAY == 1) ? 0 : replace_way + 1;
                    end

                    MISS: begin
                        if (ret_valid_i) begin
                            cache_data[miss_way][addr_index] <= {ret_data_i, cache_data[miss_way][addr_index][LINE_WIDTH-1:32]};
                            if (ret_last_i) begin
                                cache_tag[miss_way][addr_index]   <= addr_tag;
                                cache_valid[miss_way][addr_index] <= 1'b1;
                                state <= IDLE;
                            end
                        end
                    end
                endcase
            end
        end
    end

    // --- 5. 输出信号 ---
    assign ready_go = (state == IDLE) && !miss;

    assign in_ready_o   = out_fire || idle;
    assign out_valid_o   = !(idle || flush) && ready_go;
    
    assign out_inst_o   = hit_word;
    assign out_pc_o    = ic_addr;
    assign out_prepc_o   = ic_prepc;
    assign out_taken_o   = ic_taken;
    assign out_btb_hit_o = ic_btb_hit;

    assign req_valid_o      = (state == MISS);
    // assign req_addr_o     = ic_addr;

`ifdef YSYXSOC
`ifdef EVENT_COUNTER
    reg [31:0] mem_type;
    reg in_pulse;
        always @(posedge clk) begin
        if (reset) begin
            in_pulse <= 1'b0;
        end else begin
            if (in_fire) begin
                in_pulse <= 1'b1;
            end else begin
                in_pulse <= 1'b0;
            end
        end
    end
    always @(posedge clk) begin
        if(!reset && in_pulse) begin
            if(ic_addr >= 32'ha0000000) begin mem_type <= 32'd2; icache_get(2); if(miss) icache_miss(2); end
            else if(ic_addr >= 32'h30000000) begin mem_type <= 32'd1; icache_get(1); if(miss) icache_miss(1); end
            else if(ic_addr >= 32'h0f000000) begin mem_type <= 32'd0; icache_get(0); if(miss) icache_miss(0); end
        end
        if(!reset && !ready_go) begin
            icache_misscycle(mem_type);
        end
    end
`endif
`endif
endmodule
