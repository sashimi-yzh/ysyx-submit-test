/* ****************************************
    * iCache.v - 指令缓存模块（多路组相联版）
    * 
    * 该模块实现了支持多路组相联的指令缓存，采用LRU替换策略。
    * 参数WAYS可配置相联度（如2/4路），支持16字节块大小的突发传输。
    *
***************************************** */
module ICache #(
    parameter CACHE_SIZE = 64,    // 缓存总大小（字节）
    parameter BLOCK_SIZE = 16,     // 块大小（16字节）
    parameter WAYS       = 2      // 相联度（2路/4路等）
)(
    input             clk,        // 时钟信号
    input             reset,      // 复位信号
    input             is_fencei,   // 是否为fence.i指令
    input      [31:0] addr,       // 指令地址
    output reg [31:0] inst,       // 输出指令
    output reg        valid,      // 指令有效信号

    // AXI接口信号（支持突发传输）
    output reg [31:0] axi_araddr,  // AXI读地址
    output reg        axi_arvalid, // AXI读地址有效
    input             axi_arready, // AXI读地址就绪
    output reg [ 3:0] axi_arid,
    output reg [ 7:0] axi_arlen,   // 突发长度（数量-1）
    output reg [ 2:0] axi_arsize,  // 数据宽度（字节）
    output reg [ 1:0] axi_arburst, // 突发类型
    input             axi_rvalid,  // AXI读数据有效
    output reg        axi_rready,  // AXI读数据就绪
    input      [31:0] axi_rdata,   // AXI读数据
    input      [1:0]  axi_rresp,   // AXI读响应
    input      [ 3:0] axi_rid,
    input             axi_rlast // 突发传输结束标志
);
`ifdef VERILATOR
    // import "DPI-C" function void cache_counter(input bit ihit);
`endif

    // 地址划分 - 组相联结构（块大小16字节）
    // 31           标签         组索引      块内偏移(4位)  0
    // +-------------+-----------+------------+
    // |     tag     |  index    |  offset    |
    // +-------------+-----------+------------+
    localparam NUM_BLOCKS         = CACHE_SIZE / BLOCK_SIZE;  // 总块数 = 缓存大小/块大小
    localparam NUM_SETS           = NUM_BLOCKS / WAYS;        // 组数 = 总块数/相联度
    localparam SET_INDEX_WIDTH    = $clog2(NUM_SETS);         // 组索引宽度
    localparam BLOCK_OFFSET_WIDTH = $clog2(BLOCK_SIZE);       // 块内偏移宽度（4位 for 16字节）
    localparam TAG_WIDTH          = 32 - SET_INDEX_WIDTH - BLOCK_OFFSET_WIDTH; // 标签宽度
    localparam LRU_WIDTH          = $clog2(WAYS);             // LRU计数器宽度
    localparam BEATS_PER_BLOCK    = BLOCK_SIZE / 4;           // 每块的32位数据数（16/4=4）

    // 存储器定义 - 支持块内多数据
    reg [TAG_WIDTH-1:0]  tag_ram   [0:NUM_SETS-1][0:WAYS-1];  // 标签存储器（组×路）
    reg [31:0]           data_ram  [0:NUM_SETS-1][0:WAYS-1][0:BEATS_PER_BLOCK-1]; // 数据存储器（组×路×块内数据）
    reg                  valid_ram [0:NUM_SETS-1][0:WAYS-1];  // 有效位（组×路）
    reg [LRU_WIDTH-1:0]  lru_ram   [0:NUM_SETS-1][0:WAYS-1];  // LRU计数器（组×路）

    // 地址分解
    wire [         TAG_WIDTH-1:0] req_tag    = addr[31 : 32 - TAG_WIDTH];  // 标签
    wire [   SET_INDEX_WIDTH-1:0] req_index  = addr[SET_INDEX_WIDTH + BLOCK_OFFSET_WIDTH - 1 : BLOCK_OFFSET_WIDTH];  // 组索引
    wire [BLOCK_OFFSET_WIDTH-1:0] req_offset = addr[BLOCK_OFFSET_WIDTH - 1 : 0];  // 块内偏移（0-15）
    wire [                   1:0] beat_idx   = req_offset[3:2];  // 块内32位数据索引（0-3，因4字节对齐）

    // 命中检测信号
    reg                 hit;             // 命中标志
    reg [     WAYS-1:0] hit_way;         // 命中的路（独热码）
    reg [LRU_WIDTH-1:0] hit_way_idx;     // 命中的路索引（二进制）

    // 保存当前请求信息
    reg          [TAG_WIDTH-1:0] saved_tag;    // 保存标签
    reg [   SET_INDEX_WIDTH-1:0] saved_index;  // 保存组索引
    reg [BLOCK_OFFSET_WIDTH-1:0] saved_offset; // 保存偏移
    reg [                   1:0] saved_beat_idx; // 保存块内数据索引

    // 状态机定义
    localparam IDLE = 2'b00;
    localparam MISS = 2'b01;
    localparam READ = 2'b10;  // 接收突发传输数据
    localparam FILL = 2'b11;  // 填充缓存块

    reg [1:0] state, next_state;
    reg busy;  // 缓存忙信号

    // 替换逻辑信号
    reg [LRU_WIDTH-1:0] replace_way;  // 待替换的路索引
    reg found_invalid;                // 是否找到无效块

    // 突发传输相关信号
    reg [ 1:0] beat_cnt;  // 已接收的突发beat数（0-3）
    reg [31:0] block_data [0:BEATS_PER_BLOCK-1];  // 存储块内所有32位数据

    // 保存请求信息
    always @(posedge clk) begin
        if (reset) begin
            saved_tag      <= 0;
            saved_index    <= 0;
            saved_offset   <= 0;
            saved_beat_idx <= 0;
        end else if (!busy) begin
            saved_tag      <= req_tag;
            saved_index    <= req_index;
            saved_offset   <= req_offset;
            saved_beat_idx <= beat_idx; 
        end
    end

    // 状态寄存器
    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end

    // 状态转换逻辑（支持突发传输结束判断）
    always @(*) begin
        case (state)
            IDLE: next_state = hit ? IDLE : (!busy ? MISS : IDLE);
            MISS: next_state = (axi_arvalid && axi_arready) ? READ : MISS; 
            READ: next_state = (axi_rvalid && axi_rready && axi_rlast) ? FILL : READ;  // 接收完所有beat后填充
            FILL: next_state = IDLE; 
            default: next_state = IDLE;
        endcase
    end

    // 命中检测逻辑 - 遍历所有路检查标签匹配
    integer j;
    always @(*) begin
        hit      = 1'b0;
        hit_way  = {WAYS{1'b0}};
        hit_way_idx = 0;

        // 遍历当前组的所有路，检查标签匹配且有效
        for (j = 0; j < WAYS; j = j + 1) begin
            if (valid_ram[req_index][j] && (tag_ram[req_index][j] == req_tag) && !is_fencei) begin
                hit = 1'b1;
                hit_way[j] = 1'b1;          // 独热码标记命中路
                // hit_way_idx = LRU_WIDTH'(j); // 二进制索引
                hit_way_idx = j[LRU_WIDTH-1:0]; 
            end
        end
    end

    // LRU替换策略 - 选择待替换的路
    reg [LRU_WIDTH-1:0] min_lru_idx;
    always @(*) begin
        replace_way  = 0;
        found_invalid = 1'b0;
        min_lru_idx = 0;

        // 优先替换无效块（无需更新LRU）
        for (j = 0; j < WAYS; j = j + 1) begin
            if (!valid_ram[saved_index][j]) begin
                // replace_way = LRU_WIDTH'(j);
                replace_way = j[LRU_WIDTH-1:0];
                found_invalid = 1'b1;
                // break;  // 找到无效块后退出
            end
        end

        // 若无无效块，选择LRU值最小的路（最久未使用）
        if (!found_invalid) begin
            for (j = 1; j < WAYS; j = j + 1) begin
                if (lru_ram[saved_index][j] < lru_ram[saved_index][min_lru_idx]) begin
                    // min_lru_idx = LRU_WIDTH'(j);
                    min_lru_idx = j[LRU_WIDTH-1:0];
                end
            end
            replace_way = min_lru_idx;
        end
    end

    // AXI突发传输配置与控制
    always @(posedge clk) begin
        if (reset) begin
            axi_arvalid <= 1'b0;
            axi_araddr  <= 32'h0;
            axi_arid    <= 4'h0;
            axi_arlen   <= 8'h0;
            axi_arsize  <= 3'h0;
            axi_arburst <= 2'h0;
        end else if (state == MISS && !axi_arvalid) begin
            // 突发传输配置：16字节块=4个32位beat，arlen=3（数量-1）
            axi_araddr  <= {addr[31:BLOCK_OFFSET_WIDTH], {BLOCK_OFFSET_WIDTH{1'b0}}};  // 块对齐地址
            axi_arvalid <= 1'b1;
            axi_arid    <= 4'h1;  // 固定ID
            // axi_arlen   <= 8'(BEATS_PER_BLOCK - 1);  // 3（4个beat）
            axi_arlen   <= 8'h3;//////////////////////////////////////////////////////////////////注意修改！！！！！！！！！！！！！！！！！！
            axi_arsize  <= 3'b010;  // 4字节（32位）
            axi_arburst <= 2'b01;  // 递增突发（INCR）
        end else if (axi_arready) begin
            axi_arvalid <= 1'b0; 
        end
    end

    // AXI读数据通道控制与块数据接收
    integer i;
    always @(posedge clk) begin
        if (reset) begin
            axi_rready <= 1'b0;
            beat_cnt   <= 2'h0;
            for (i = 0; i < BEATS_PER_BLOCK; i++) begin
                block_data[i] <= 32'h0;
            end
        end else begin
            case (state)
                MISS: begin
                    axi_rready <= 1'b1;  // 准备接收数据
                    beat_cnt   <= 2'h0;  // 复位计数器
                end
                READ: begin
                    axi_rready <= 1'b1;  // 持续就绪接收所有beat
                    if (axi_rvalid) begin
                        // 按顺序存储突发数据（0-3）
                        block_data[beat_cnt] <= axi_rdata;
                        beat_cnt <= beat_cnt + 1'b1;  // 计数递增
                    end
                end
                default: begin
                    axi_rready <= 1'b0;  // 非读状态关闭就绪
                    beat_cnt   <= 2'h0;
                end
            endcase
        end
    end
    
    // 缓存填充与LRU更新逻辑
    integer s, w, b;  // 循环变量
    always @(posedge clk) begin
        if(is_fencei) begin
            for (s = 0; s < NUM_SETS; s = s + 1) begin
                for (w = 0; w < WAYS; w = w + 1) begin
                    valid_ram[s][w] <= 1'b0;
                end
            end
        end
    end
    
    always @(posedge clk) begin
        if (reset) begin
            // 初始化缓存：所有块无效，LRU初始化为路索引
            for (s = 0; s < NUM_SETS; s = s + 1) begin
                for (w = 0; w < WAYS; w = w + 1) begin
                    valid_ram[s][w] <= 1'b0;
                    tag_ram[s][w]   <= {TAG_WIDTH{1'b0}};
                    for (b = 0; b < BEATS_PER_BLOCK; b = b + 1) begin
                        data_ram[s][w][b] <= 32'h0;
                    end
                    // lru_ram[s][w]   <= LRU_WIDTH'(w);  // 初始LRU值为路索引
                    lru_ram[s][w] <= w[LRU_WIDTH-1:0];
                end
            end
            inst  <= 32'h0;
            valid <= 1'b0;
            busy  <= 1'b0;
        end else begin
            case (state)
                IDLE: begin
                    busy <= 1'b0;
                    valid <= 1'b0;
                    
                    if (hit) begin
                        // 命中：根据块内索引输出指令并更新LRU
                        inst <= data_ram[req_index][hit_way_idx][beat_idx];
                        valid <= 1'b1;
                    // `ifdef VERILATOR
                    //     cache_counter(1'b1);  // 统计命中
                    // `endif

                        // LRU更新：命中路设为最大值，其他路递减（若小于当前最大值）
                        for (j = 0; j < WAYS; j = j + 1) begin
                            if (j[$clog2(WAYS)-1:0] == hit_way_idx) begin
                                lru_ram[req_index][j] <= {LRU_WIDTH{1'b1}};  // 最近使用设为最大
                            end else if (lru_ram[req_index][j] > 0) begin
                                lru_ram[req_index][j] <= lru_ram[req_index][j] - 1'b1;  // 其他路递减
                            end
                        end
                    end else if (!busy) begin
                        // 未命中：进入MISS状态
                        busy <= 1'b1;
                        valid <= 1'b0;
                    // `ifdef VERILATOR
                    //     cache_counter(1'b0);  // 统计未命中
                    // `endif
                    end
                end

                MISS: begin
                    valid <= 1'b0;
                    busy <= 1'b1;
                end

                READ: begin
                    valid <= 1'b0;
                    busy <= 1'b1;
                    // 检查AXI响应错误（可扩展错误处理）
                    if (axi_rvalid && axi_rresp != 2'b00) begin
                        // 错误处理：如设置无效信号等
                    end
                end

                FILL: begin
                    // 填充缓存块到替换路（写入所有4个beat）
                    valid_ram[saved_index][replace_way] <= 1'b1;
                    tag_ram[saved_index][replace_way]   <= saved_tag;
                    for (b = 0; b < BEATS_PER_BLOCK; b = b + 1) begin
                        data_ram[saved_index][replace_way][b] <= block_data[b];
                    end
                    // 输出当前请求的指令（根据保存的块内索引）
                    inst <= block_data[saved_beat_idx];
                    valid <= 1'b1;
                    busy <= 1'b0;

                    // 更新LRU：新填充路设为最大值，其他路递减
                    for (j = 0; j < WAYS; j = j + 1) begin
                        if (j[$clog2(WAYS)-1:0] == replace_way) begin
                            lru_ram[saved_index][j] <= {LRU_WIDTH{1'b1}};  // 新块设为最近使用
                        end else if (lru_ram[saved_index][j] > 0) begin
                            lru_ram[saved_index][j] <= lru_ram[saved_index][j] - 1'b1;  // 其他路递减
                        end
                    end
                end
            endcase
        end
    end

endmodule