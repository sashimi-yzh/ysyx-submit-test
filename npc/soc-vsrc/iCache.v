module iCache #(
    parameter CACHE_SIZE = 1024,  // 缓存大小（字节）
    parameter BLOCK_SIZE = 32,    // 块大小（字节）
    parameter WAYS       = 2      // 相联度
)(
    input             clk,        // 时钟信号
    input             reset,      // 复位信号
    input      [31:0] addr,       // 指令地址
    output reg [31:0] inst,       // 输出指令
    output reg        valid,      // 指令有效信号

    // AXI接口信号
    output reg [31:0] axi_araddr, // AXI读地址
    output reg        axi_arvalid,// AXI读地址有效
    input             axi_arready,// AXI读地址就绪
    input             axi_rvalid, // AXI读数据有效
    output reg        axi_rready, // AXI读数据就绪
    input      [31:0] axi_rdata,  // AXI读数据
    input      [1:0]  axi_rresp   // AXI读响应
);
    // 地址划分
    //  31    m+n m+n-1   m m-1    0
    // +---------+---------+--------+
    // |   tag   |  index  | offset |
    // +---------+---------+--------+
    localparam NUM_BLOCKS         = CACHE_SIZE / BLOCK_SIZE;
    localparam NUM_SETS           = NUM_BLOCKS / WAYS;
    localparam SET_INDEX_WIDTH    = $clog2(NUM_SETS);
    localparam BLOCK_OFFSET_WIDTH = $clog2(BLOCK_SIZE);
    localparam TAG_WIDTH          = 32 - SET_INDEX_WIDTH - BLOCK_OFFSET_WIDTH;
    localparam LRU_WIDTH          = $clog2(WAYS);  // 根据相联度动态调整LRU宽度

    // 存储器定义
    reg [  TAG_WIDTH-1:0] tag_ram [0:NUM_SETS-1][0:WAYS-1];//标签存储器
    reg [           31:0] data_ram [0:NUM_SETS-1][0:WAYS-1][0:(BLOCK_SIZE/4)-1];//数据存储器
    reg                   valid_ram [0:NUM_SETS-1][0:WAYS-1];//有效位
    reg [  LRU_WIDTH-1:0] lru_counter [0:NUM_SETS-1][0:WAYS-1];//LRU计数器

    // 地址分解
    wire [         TAG_WIDTH-1:0] req_tag = addr[31:32-TAG_WIDTH];
    wire [   SET_INDEX_WIDTH-1:0] req_index = addr[SET_INDEX_WIDTH + BLOCK_OFFSET_WIDTH - 1 : BLOCK_OFFSET_WIDTH];
    wire [BLOCK_OFFSET_WIDTH-1:0] req_offset = addr[BLOCK_OFFSET_WIDTH - 1 : 0];
    wire [                   2:0] word_offset = req_offset[4:2];  // 字偏移 (32位字)

    // 命中检测信号
    reg                       hit;
    reg [           WAYS-1:0] hit_way;
    
    // 保存当前请求信息
    reg [      TAG_WIDTH-1:0] saved_tag;
    reg [SET_INDEX_WIDTH-1:0] saved_index;
    reg [                2:0] saved_word_offset;

    // ========================= 状态机 =========================
    localparam IDLE = 2'b00;
    localparam MISS = 2'b01;
    localparam READ = 2'b10;
    localparam FILL = 2'b11;

    reg [1:0] state, next_state;
    reg busy;  // 缓存忙信号

    // 保存请求信息
    always @(posedge clk) begin
        if (reset) begin
            saved_tag <= 0;
            saved_index <= 0;
            saved_word_offset <= 0;
        end 
        else if (!busy) begin
            saved_tag <= req_tag;
            saved_index <= req_index;
            saved_word_offset <= word_offset;
        end
    end

    // 状态寄存器
    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
        end 
        else begin
            state <= next_state;
        end
    end

    // 状态转换逻辑
    always @(*) begin
        case (state)
            IDLE: begin
                if (hit) begin
                    next_state = IDLE;
                end else begin
                    next_state = MISS;
                end
            end
            
            MISS: begin
                if (axi_arvalid && axi_arready) begin
                    next_state = READ;
                end else begin
                    next_state = MISS;
                end
            end
            
            READ: begin
                // 等待接收完整个块（BLOCK_SIZE/4个字）
                if (word_count == (BLOCK_SIZE/4 - 1) && axi_rvalid && axi_rready) begin
                    next_state = FILL;
                end else begin
                    next_state = READ;
                end
            end
            
            FILL: begin
                next_state = IDLE;
            end
            
            default: next_state = IDLE;
        endcase
    end

    // ========================= 命中检测逻辑 =========================
    always @(*) begin
        hit = 1'b0;
        hit_way = {WAYS{1'b0}};  // 初始化
        
        for (integer j = 0; j < WAYS; j = j + 1) begin
            // 标签匹配且有效，即为命中
            if (valid_ram[req_index][j] && (tag_ram[req_index][j] == req_tag)) begin
                hit = 1'b1;
                hit_way = (1 << j);  // 标记命中的路
            end
        end
    end

    // ========================= 未命中处理 =========================
    reg [BLOCK_OFFSET_WIDTH-1:0] word_count;  // 字计数器
    reg [31:0] block_data [0:(BLOCK_SIZE/4)-1];  // 临时块数据存储
    
    // 字计数器逻辑
    always @(posedge clk) begin
        if (reset) begin
            word_count <= 0;
        end else if (state == READ && axi_rvalid && axi_rready) begin
            if (word_count == (BLOCK_SIZE/4 - 1)) begin
                word_count <= 0;
            end else begin
                word_count <= word_count + 1;
            end
        end else if (state == IDLE) begin
            word_count <= 0;
        end
    end

    // 接收AXI数据并暂存到block_data
    always @(posedge clk) begin
        if (reset) begin
            for (integer b = 0; b < (BLOCK_SIZE/4); b = b + 1) begin
                block_data[b] <= 32'h0;
            end
        end else if (state == READ && axi_rvalid && axi_rready) begin
            // 按顺序存储整个块的数据
            block_data[word_count] <= axi_rdata;
        end
    end

    // ========================= AXI接口控制 =========================
    // AXI读地址通道控制
    always @(posedge clk) begin
        if (reset) begin
            axi_arvalid <= 1'b0;
            axi_araddr <= 32'h0;
        end else if (state == MISS && !axi_arvalid) begin
            // 发送块地址（块对齐）
            axi_araddr <= {addr[31:BLOCK_OFFSET_WIDTH], {BLOCK_OFFSET_WIDTH{1'b0}}};
            axi_arvalid <= 1'b1;  // 发起读请求
        end else if (axi_arready) begin
            axi_arvalid <= 1'b0;  // 地址通道握手完成
        end
    end

    // AXI读数据通道控制
    always @(posedge clk) begin
        if (reset) begin
            axi_rready <= 1'b0;
        end else if (state == READ) begin
            axi_rready <= 1'b1;  // 准备接收数据
        end else begin
            axi_rready <= 1'b0;
        end
    end

    // ========================= LRU替换策略 =========================
    reg [WAYS-1:0] replace_way;
    
    // 找到要替换的路：优先替换无效块，否则按LRU
    always @(*) begin
        replace_way = 0;
        
        // 优先选择无效块
        for (integer j = 0; j < WAYS; j = j + 1) begin
            if (!valid_ram[saved_index][j]) begin
                replace_way = j;
                return;  // 找到无效块后直接返回
            end
        end
        
        // 若无无效块，选择LRU值最小的路
        for (integer j = 1; j < WAYS; j = j + 1) begin
            if (lru_counter[saved_index][j] < lru_counter[saved_index][replace_way]) begin
                replace_way = j;
            end
        end
    end

    // ========================= 缓存填充与更新逻辑 =========================
    always @(posedge clk) begin
        if (reset) begin
            // 初始化缓存
            for (integer s = 0; s < NUM_SETS; s = s + 1) begin
                for (integer w = 0; w < WAYS; w = w + 1) begin
                    valid_ram[s][w] <= 1'b0;
                    tag_ram[s][w] <= {TAG_WIDTH{1'b0}};
                    lru_counter[s][w] <= LRU_WIDTH'(w); // 初始LRU值
                    for (integer b = 0; b < (BLOCK_SIZE/4); b = b + 1) begin
                        data_ram[s][w][b] <= 32'h0;
                    end
                end
            end
            inst <= 32'h0;
            valid <= 1'b0;
            busy <= 1'b0;
        end else begin
            case (state)
                IDLE: begin
                    busy <= 1'b0;
                    valid <= 1'b0;
                    
                    if (hit) begin
                        // 命中：输出指令并更新LRU
                        inst <= data_ram[req_index][hit_way][word_offset];
                        valid <= 1'b1;
                        
                        // 更新LRU：命中的路设置为最大值
                        lru_counter[req_index][hit_way] <= {LRU_WIDTH{1'b1}};
                        
                        // 其他路的LRU递减
                        for (integer k = 0; k < WAYS; k = k + 1) begin
                            if (k != hit_way && lru_counter[req_index][k] > 0) begin
                                lru_counter[req_index][k] <= lru_counter[req_index][k] - 1;
                            end
                        end
                    end else if (!busy) begin
                        // 未命中且不忙，准备处理
                        busy <= 1'b1;
                        valid <= 1'b0;
                    end
                end
                
                MISS: begin
                    valid <= 1'b0;
                    busy <= 1'b1;
                end
                
                READ: begin
                    valid <= 1'b0;
                    busy <= 1'b1;
                    
                    // 检查AXI响应错误
                    if (axi_rvalid && axi_rresp != 2'b00) begin
                        // 可扩展错误处理逻辑
                    end
                end
                
                FILL: begin
                    // 填充缓存块
                    valid_ram[saved_index][replace_way] <= 1'b1;
                    tag_ram[saved_index][replace_way] <= saved_tag;
                    
                    // 复制整个块数据
                    for (integer b = 0; b < (BLOCK_SIZE/4); b = b + 1) begin
                        data_ram[saved_index][replace_way][b] <= block_data[b];
                    end
                    
                    // 输出请求的指令
                    inst <= block_data[saved_word_offset];
                    valid <= 1'b1;
                    
                    // 更新LRU：新填充的路设置为最大值
                    lru_counter[saved_index][replace_way] <= {LRU_WIDTH{1'b1}};
                    
                    // 其他路的LRU递减
                    for (integer k = 0; k < WAYS; k = k + 1) begin
                        if (k != replace_way && lru_counter[saved_index][k] > 0) begin
                            lru_counter[saved_index][k] <= lru_counter[saved_index][k] - 1;
                        end
                    end
                    
                    busy <= 1'b0;
                end
            endcase
        end
    end

endmodule
