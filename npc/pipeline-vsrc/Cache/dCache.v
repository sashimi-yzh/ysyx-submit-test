/* ***********************************
    * dCache.v - 数据缓存模块（草稿）
    * 
    * 该模块实现了一个简单的直接映射数据缓存，支持读写操作。
    * 缓存行大小为16字节，总大小为1024字节，支持1、2或4字节的访问长度。
    * 使用DPI-C接口与主存进行交互。
    *
    * DPI-C内存访问函数暂不支持dCache的操作，需要另外实现
************************************ */
module dCache (
    input wire clk,               
    input wire reset,              
    input wire [31:0] addr,        
    input wire read_en,           
    input wire write_en,        
    input wire [31:0] write_data, 
    input wire [1:0] len,          // 访问长度（1、2或4字节）
    output reg [31:0] read_data,   
    output reg hit,                // 缓存命中信号
    output reg ready               // CPU就绪信号
);

    // 缓存参数
    parameter CACHE_SIZE = 1024;   // 缓存总大小（字节）
    parameter LINE_SIZE = 16;      // 缓存行大小（字节，4个字）
    parameter NUM_LINES = CACHE_SIZE / LINE_SIZE; // 缓存行数

    // 地址字段
    localparam OFFSET_WIDTH = $clog2(LINE_SIZE);  // 4位，16字节行
    localparam INDEX_WIDTH = $clog2(NUM_LINES);   // 6位，64行
    localparam TAG_WIDTH = 32 - INDEX_WIDTH - OFFSET_WIDTH; // 22位

    wire [TAG_WIDTH-1:0] tag = addr[31:INDEX_WIDTH+OFFSET_WIDTH];
    wire [INDEX_WIDTH-1:0] index = addr[INDEX_WIDTH+OFFSET_WIDTH-1:OFFSET_WIDTH];
    wire [OFFSET_WIDTH-1:0] offset = addr[OFFSET_WIDTH-1:0];

    // 缓存存储
    reg [LINE_SIZE*8-1:0] data_array [0:NUM_LINES-1];  // 数据存储（每行128位）
    reg [TAG_WIDTH-1:0] tag_array [0:NUM_LINES-1];     // 标签存储
    reg valid_array [0:NUM_LINES-1];                   // 有效位
    reg dirty_array [0:NUM_LINES-1];                   // 脏位

    import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    import "DPI-C" function void pmem_write(input int unsigned waddr, input int unsigned wdata, input int len);

    // 内部信号
    reg [31:0] pmem_data;  // 主存数据
    reg [1:0] state;       // 状态机状态
    localparam IDLE = 2'b00, READ_MEM = 2'b01, WRITE_MEM = 2'b10;// 状态定义

    // 缓存操作
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            hit <= 0;
            ready <= 0;
            read_data <= 0;
            for (int i = 0; i < NUM_LINES; i++) begin
                valid_array[i] <= 0;
                dirty_array[i] <= 0;
            end
        end else begin
            case (state)
                IDLE: begin
                    ready <= 0;
                    if (read_en) begin
                        // 检查缓存命中
                        if (valid_array[index] && (tag_array[index] == tag)) begin//有效位和标签匹配
                            hit <= 1;
                            read_data <= data_array[index][offset*8 +: 32]; // 提取32位数据
                            ready <= 1;
                        end else begin
                            hit <= 0;
                            state <= READ_MEM; // 未命中：从内存
                        end
                    end else if (write_en) begin
                        if (valid_array[index] && (tag_array[index] == tag)) begin
                            hit <= 1;
                            data_array[index][offset*8 +: 32] <= write_data; // 写入缓存
                            dirty_array[index] <= 1; // 标记为脏
                            ready <= 1;
                        end else begin
                            hit <= 0;
                            if (valid_array[index] && dirty_array[index]) begin
                                state <= WRITE_MEM; // 写回脏数据
                            end else begin
                                state <= READ_MEM; // 获取新行
                            end
                        end
                    end
                end

                READ_MEM: begin
                    // 从主存获取一行
                    pmem_data = pmem_read({addr[31:OFFSET_WIDTH], {OFFSET_WIDTH{1'b0}}}, LINE_SIZE);
                    data_array[index] <= {{(LINE_SIZE-4)*8{1'b0}}, pmem_data}; // 对齐数据
                    tag_array[index] <= tag;
                    valid_array[index] <= 1;
                    dirty_array[index] <= 0;
                    if (write_en) begin
                        data_array[index][offset*8 +: 32] <= write_data;
                        dirty_array[index] <= 1;
                    end else begin
                        read_data <= data_array[index][offset*8 +: 32];
                    end
                    state <= IDLE;
                    ready <= 1;
                end

                WRITE_MEM: begin
                    // 写回脏行到主存
                    pmem_write({tag_array[index], index, {OFFSET_WIDTH{1'b0}}}, 
                               data_array[index][31:0], LINE_SIZE);
                    dirty_array[index] <= 0;
                    state <= READ_MEM; // 获取新行
                end

                default: state <= IDLE;
            endcase
        end
    end
endmodule