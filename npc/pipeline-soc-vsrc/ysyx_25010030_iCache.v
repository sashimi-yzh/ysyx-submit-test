
module ysyx_25010030_iCache #(
    parameter CACHE_SIZE = 32,   
    parameter BLOCK_SIZE = 16    
)(
    input wire        clk,       
    input wire        reset,     
    input wire        is_fencei,  
    input wire [31:0] addr,      
    output reg [31:0] inst,      
    output reg        valid,     

    // AXI接口信号（支持突发传输）
    output reg  [31:0] axi_araddr,  
    output reg         axi_arvalid, 
    input  wire        axi_arready, 
    output wire [ 3:0] axi_arid,
    output wire [ 7:0] axi_arlen,   
    output wire [ 2:0] axi_arsize,  
    output wire [ 1:0] axi_arburst, 
    input  wire        axi_rvalid,  
    output reg         axi_rready,  
    input  wire [31:0] axi_rdata,   
    input  wire [ 1:0] axi_rresp,   
    input  wire [ 3:0] axi_rid,
    input  wire        axi_rlast    
);
`ifdef VERILATOR
    // import "DPI-C" function void cache_counter(input bit ihit);
`endif

    // 地址划分 - 直接映射结构（块大小16字节）
    // 31           标签         直接映射索引    块内偏移(4位)  0
    // +-------------+-----------+------------+
    // |     tag     |  index    |  offset    |
    // +-------------+-----------+------------+
    localparam NUM_BLOCKS         = CACHE_SIZE / BLOCK_SIZE;  // 总块数
    localparam BLOCK_OFFSET_WIDTH = $clog2(BLOCK_SIZE);       // 块内偏移宽度（4位 for 16字节）
    localparam INDEX_WIDTH        = $clog2(NUM_BLOCKS);       // 直接映射索引宽度
    localparam TAG_WIDTH          = 32 - INDEX_WIDTH - BLOCK_OFFSET_WIDTH; // 标签宽度
    localparam BEATS_PER_BLOCK    = BLOCK_SIZE / 4;           // 每块的32位数据数（16/4=4）

    // 存储器定义 
    reg [TAG_WIDTH-1:0] tag_ram   [0:NUM_BLOCKS-1];          // 标签存储器
    reg [         31:0] data_ram  [0:NUM_BLOCKS-1][0:BEATS_PER_BLOCK-1]; // 数据存储器
    reg                 valid_ram [0:NUM_BLOCKS-1];          // 有效位       

    // 地址分解
    wire [         TAG_WIDTH-1:0] req_tag    = addr[31 : 32 - TAG_WIDTH];
    wire [       INDEX_WIDTH-1:0] req_index  = addr[INDEX_WIDTH + BLOCK_OFFSET_WIDTH - 1 : BLOCK_OFFSET_WIDTH];
    wire [                   1:0] beat_idx   = addr[3:2];  // 块内32位数据索引

    // reg hit;   

    // 保存当前请求信息
    reg [         TAG_WIDTH-1:0] saved_tag;      // 保存标签
    reg [       INDEX_WIDTH-1:0] saved_index;    // 保存索引
    reg [                   1:0] saved_beat_idx; // 保存块内数据索引

    // 状态机定义
    localparam IDLE = 2'b00;
    // localparam MISS = 2'b01;
    localparam READ = 2'b11;  // 接收突发传输数据
    localparam FILL = 2'b10;  // 填充缓存块

    reg [1:0] state, next_state;

    reg [ 1:0] beat_cnt;  // 已接收的突发beat数（0-3）
    reg [31:0] block_data [0:BEATS_PER_BLOCK-1];  // 存储块内所有32位数据
    reg        ar_done;

    localparam SDRAM_BASE        = 32'hA0000000;  
    localparam SDRAM_END         = 32'hBFFFFFFF;
`ifdef YSYXSOC
    // wire in_sdram = (addr >= SDRAM_BASE) && (addr <= SDRAM_END);
    wire in_sdram = 1;
`else
    wire in_sdram = 0;
`endif

    // 状态寄存器
    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end

    // 状态转换逻辑
    wire hit;
    always @(*) begin
        case (state)
            IDLE: next_state = hit ? IDLE : READ;
        `ifdef YSYXSOC
            READ: next_state = (axi_rvalid && axi_rready && axi_rlast) ? FILL : READ;
        `else
            READ: next_state = (axi_rvalid && axi_rready && axi_rlast) ? IDLE : READ;
        `endif
            FILL: next_state = IDLE; 
            default: next_state = IDLE;
        endcase
    end

    assign hit = valid_ram[req_index] && (tag_ram[req_index] == req_tag) && !is_fencei && in_sdram;

    // AXI突发传输配置与控制
    assign axi_arid    = 4'h0;    // 固定ID
    assign axi_arlen   = in_sdram ? 8'h3   : 8'b0;    // 突发长度4拍（16字节块）
    assign axi_arburst = in_sdram ? 2'b01 : 2'b00;   // 递增突发
    assign axi_arsize  = 3'b010;  // 4字节
    
    // FENCE.I指令处理：清空所有缓存块的有效位
    integer idx;
    // always @(posedge clk) begin
    //     if(is_fencei || reset) begin
    //         for (idx = 0; idx < NUM_BLOCKS; idx = idx + 1) begin
    //             valid_ram[idx] <= 1'b0;
    //         end
    //     end
    // end
    
    // 缓存初始化、命中处理、填充处理（无LRU逻辑）
    integer b;
    always @(posedge clk) begin
        if (reset) begin
            // 初始化缓存：所有块无效
            for (idx = 0; idx < NUM_BLOCKS; idx = idx + 1) begin
                valid_ram[idx] <= 1'b0;
            end
            inst  <= 32'h0;
            valid <= 1'b0;

            axi_rready <= 1'b0;
            axi_arvalid <= 1'b0;
        end else begin
            if (is_fencei) begin
                for (idx = 0; idx < NUM_BLOCKS; idx = idx + 1) begin
                    valid_ram[idx] <= 1'b0;
                end
            end
            case (state)
                IDLE: begin
                    axi_rready <= 1'b0;
                    beat_cnt   <= 2'h0;
                    ar_done    <= 1'b0;

                    saved_tag      <= req_tag;
                    saved_index    <= req_index;
                    saved_beat_idx <= beat_idx; 
                    
                    if (hit) begin
                        inst  <= data_ram[req_index][beat_idx];
                        valid <= 1'b1;
                    end 
                    else begin
                        valid <= 1'b0;
                    end
                end

                READ: begin
                    valid <= 1'b0;
                    axi_rready <= 1'b1;
                    if(!axi_arvalid && !ar_done) begin 
                        axi_arvalid <= 1'b1;
                        axi_araddr  <= in_sdram ? {addr[31:BLOCK_OFFSET_WIDTH], {BLOCK_OFFSET_WIDTH{1'b0}}} : addr;
                    end
                    else if(axi_arready) begin
                        axi_arvalid <= 1'b0;
                        ar_done <= 1'b1;
                    end
                    if (axi_rvalid) begin
                    `ifdef YSYXSOC
                        block_data[beat_cnt] <= axi_rdata;
                        beat_cnt <= in_sdram ? beat_cnt + 1'b1 : 2'b0;
                    `else
                        inst <= axi_rdata;
                        valid <= 1'b1;
                    `endif
                    end
                end

                FILL: begin
                    axi_rready <= 1'b0;
                    valid_ram[saved_index] <= 1'b1;
                    tag_ram[saved_index]   <= saved_tag;
                    for (b = 0; b < BEATS_PER_BLOCK; b = b + 1) begin
                        data_ram[saved_index][b] <= block_data[b];
                    end
                    inst  <= in_sdram ? block_data[saved_beat_idx] : block_data[2'b0];
                    valid <= 1'b1;
                end
                default: begin end
            endcase
        end
    end

endmodule
