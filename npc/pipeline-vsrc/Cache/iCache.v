/* ****************************************
    * iCache.v - 指令缓存模块
    * 
    * 该模块实现了一个简单的指令缓存，支持多路组相联缓存。
    * 包含地址分解、命中检测、LRU 替换策略等功能。
    * 
    *
    * 第一个icache不包含相联度以及lru替换策略，总共16块每块一条指令（比较简单）
    * 第二个icache比较完善，但是尚未进行测试
***************************************** */
module iCache #(
    parameter CACHE_SIZE = 64,    // 缓存大小（字节），16块 * 4字节
    parameter BLOCK_SIZE = 4      // 块大小（字节），1个32位字
)(
    input             clk,        // 时钟信号
    input             reset,      // 复位信号
    input      [31:0] addr,       // 指令地址
    output reg [31:0] inst,       // 输出指令
    output reg        valid,      // 指令有效信号

    // AXI接口信号
    output reg [31:0] axi_araddr,  // AXI读地址
    output reg        axi_arvalid, // AXI读地址有效
    input             axi_arready, // AXI读地址就绪
    input             axi_rvalid,  // AXI读数据有效
    output reg        axi_rready,  // AXI读数据就绪
    input      [31:0] axi_rdata,   // AXI读数据
    input      [1:0]  axi_rresp    // AXI读响应
);
    import "DPI-C" function void cache_counter(input bit ihit);
    // 地址划分 - 直接映射无ways参数
    //  31    m+n m+n-1   m m-1    0
    // +---------+---------+--------+
    // |   tag   |  index  | offset |
    // +---------+---------+--------+
    localparam NUM_BLOCKS         = CACHE_SIZE / BLOCK_SIZE; // 16块
    localparam SET_INDEX_WIDTH    = $clog2(NUM_BLOCKS);      // 4位（16块需要4位索引）
    localparam BLOCK_OFFSET_WIDTH = $clog2(BLOCK_SIZE);      // 2位
    localparam TAG_WIDTH          = 32 - SET_INDEX_WIDTH - BLOCK_OFFSET_WIDTH; // 26位

    // 存储器定义
    reg [TAG_WIDTH-1:0] tag_ram   [0:NUM_BLOCKS-1];  // 标签存储器
    reg [         31:0] data_ram  [0:NUM_BLOCKS-1]; // 数据存储器
    reg                 valid_ram [0:NUM_BLOCKS-1]; // 有效位

    // 地址分解
    wire [         TAG_WIDTH-1:0] req_tag    = addr[31:32-TAG_WIDTH];
    wire [   SET_INDEX_WIDTH-1:0] req_index  = addr[SET_INDEX_WIDTH + BLOCK_OFFSET_WIDTH - 1 : BLOCK_OFFSET_WIDTH];
    wire [BLOCK_OFFSET_WIDTH-1:0] req_offset = addr[BLOCK_OFFSET_WIDTH - 1 : 0];

    // 命中检测信号 - 无需way检测
    reg hit;
    
    // 保存当前请求信息
    reg [         TAG_WIDTH-1:0] saved_tag;
    reg [   SET_INDEX_WIDTH-1:0] saved_index;
    reg [BLOCK_OFFSET_WIDTH-1:0] saved_offset;

    // 状态机定义
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
            saved_offset <= 0;
        end else if (!busy) begin
            saved_tag <= req_tag;
            saved_index <= req_index;
            saved_offset <= req_offset;
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

    // 状态转换逻辑
    always @(*) begin
        case (state)
            IDLE: next_state = hit ? IDLE : (!busy ? MISS : IDLE);
            MISS: next_state = (axi_arvalid && axi_arready) ? READ : MISS;
            READ: next_state = (axi_rvalid && axi_rready) ? FILL : READ;
            FILL: next_state = IDLE;
            default: next_state = IDLE;
        endcase
    end

    // 命中检测逻辑 - 简化为单一路检测
    always @(*) begin
        // 直接映射只需检查当前索引的标签和有效位
        hit = valid_ram[req_index] && (tag_ram[req_index] == req_tag);
    end

    // 未命中处理：临时存储读取的指令
    reg [31:0] block_data;

    // 接收AXI数据
    always @(posedge clk) begin
        if (reset) begin
            block_data <= 32'h0;
        end else if (state == READ && axi_rvalid && axi_rready) begin
            block_data <= axi_rdata;
        end
    end

    // AXI读地址通道控制
    always @(posedge clk) begin
        if (reset) begin
            axi_arvalid <= 1'b0;
            axi_araddr <= 32'h0;
        end else if (state == MISS && !axi_arvalid) begin
            axi_araddr <= {addr[31:BLOCK_OFFSET_WIDTH], {BLOCK_OFFSET_WIDTH{1'b0}}};
            axi_arvalid <= 1'b1;
        end else if (axi_arready) begin
            axi_arvalid <= 1'b0;
        end
    end

    // AXI读数据通道控制
    always @(posedge clk) begin
        if (reset) begin
            axi_rready <= 1'b0;
        end else if (state == READ) begin
            axi_rready <= 1'b1;
        end else begin
            axi_rready <= 1'b0;
        end
    end

    // 缓存填充与更新逻辑 - 移除LRU相关代码
    integer s;
    
    always @(posedge clk) begin
        if (reset) begin
            // 初始化缓存
            for (s = 0; s < NUM_BLOCKS; s = s + 1) begin
                valid_ram[s] <= 1'b0;
                tag_ram[s] <= {TAG_WIDTH{1'b0}};
                data_ram[s] <= 32'h0;
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
                        // 命中时直接输出指令
                        inst <= data_ram[req_index];
                        valid <= 1'b1;
                        cache_counter(1'b1);
                    end else if (!busy) begin
                        busy <= 1'b1;
                        valid <= 1'b0;
                        cache_counter(1'b0);
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
                        // 错误处理
                    end
                end
                FILL: begin
                    // 填充缓存块 - 直接映射无需选择way
                    valid_ram[saved_index] <= 1'b1;
                    tag_ram[saved_index] <= saved_tag;
                    data_ram[saved_index] <= block_data;
                    inst <= block_data;
                    valid <= 1'b1;
                    busy <= 1'b0;
                end
            endcase
        end
    end

endmodule
    

module icache#(
    parameter BASE_ADDR         = 32'h40000000,//基准玛
    parameter CACHE_SIZE        = 1024,    //总的字节
    parameter SET_SIZE          = 32,      //每一块的字节
    parameter SET_ASSOCIATIVITY = 4,   //每一set里面的路数
    parameter DATA_WIDTH        = 32,      
    parameter ADDR_WIDTH        = 32       
)(
    // 系统信号
    input  wire                     M_AXI_ACLK,
    input  wire                     M_AXI_ARESETN,
    
    // CPU接口
    //cpu读地址
    input  wire [ADDR_WIDTH-1:0]    W_CPU_AXI_ARADDR,
    input  wire                     W_CPU_AXI_ARVALID,
    output wire                     W_CPU_AXI_ARREADY,

   //cpu读数据
    output wire [ADDR_WIDTH-1:0]    W_CPU_AXI_RDATA,
    output wire [1:0]               W_CPU_AXI_RRESP,
    output wire                     W_CPU_AXI_RVALID,
    input  wire                     W_CPU_AXI_RREADY,
    
    //merory接口
    // 读地址通道
    output wire [ADDR_WIDTH-1:0]    W_MEMORY_AXI_ARADDR1,
    output wire [ADDR_WIDTH-1:0]    W_MEMORY_AXI_ARADDR2,
    output wire                     W_MEMORY_AXI_ARVALID,
    input  wire                     W_MEMORY_AXI_ARREADY,
    
    // 读数据通道
    input  wire [DATA_WIDTH-1:0]    W_MEMORY_AXI_RDATA1,
    input  wire [ADDR_WIDTH-1:0]    W_MEMORY_AXI_RDATA2,
    /* verilator lint_off UNUSEDSIGNAL */
    input  wire [1:0]               W_MEMORY_AXI_RRESP,
    input  wire                     W_MEMORY_AXI_RVALID,
    output wire                     W_MEMORY_AXI_RREADY,

    output wire                     W_MEMORY_BREAK

);
/*****************功能函数******************/
function integer clogb2(input integer number);//计算以2为底的对数（向上取整）
begin
    for(clogb2 = 0; number > 0;clogb2 = clogb2 + 1)
        number =number >> 1; 
end
endfunction
// ========================= 参数计算 =========================
localparam SET_WORDS = SET_SIZE / (DATA_WIDTH / 8);                       //一个set可以储存的数据数量
localparam NUM_SETS = CACHE_SIZE / SET_SIZE;                              //set数量
localparam SET_INDEX_WIDTH = clogb2(NUM_SETS);                            //组索引位宽
localparam SET_OFFSET_WIDTH = clogb2(SET_WORDS / SET_ASSOCIATIVITY);      //块内偏移位宽
localparam TAG_WIDTH = ADDR_WIDTH - SET_INDEX_WIDTH - SET_OFFSET_WIDTH;   //tag标签索引
/**********************网表型变量*******************************/
wire                        w_system_rst;
wire [TAG_WIDTH-1:0]        req_tag;
wire [SET_INDEX_WIDTH-1:0]  req_set;
wire [SET_OFFSET_WIDTH-1:0] req_offset;
/*****************逻辑单元****************/
assign                   w_system_rst         = ~M_AXI_ARESETN;

assign                   W_CPU_AXI_ARREADY    = r_cpu_arready;

assign                   W_CPU_AXI_RDATA      = r_cpu_rdata;
assign                   W_CPU_AXI_RRESP      = r_cpu_rresp;

assign                   W_CPU_AXI_RVALID     = r_cpu_rvalid; 
assign                   W_MEMORY_AXI_ARADDR1 = r_memory_araddr1;
assign                   W_MEMORY_AXI_ARADDR2 = r_memory_araddr2;
assign                   W_MEMORY_AXI_ARVALID = r_memory_arvalid;
assign                   W_MEMORY_AXI_RREADY  = r_memory_rready;
assign                   W_MEMORY_BREAK       = r_memory_break;

assign req_tag    = W_CPU_AXI_ARADDR[ADDR_WIDTH-1 : SET_INDEX_WIDTH + SET_OFFSET_WIDTH + 2];
assign req_set    = W_CPU_AXI_ARADDR[SET_INDEX_WIDTH + SET_OFFSET_WIDTH + 2 : SET_OFFSET_WIDTH + 2];
assign req_offset = W_CPU_AXI_ARADDR[SET_OFFSET_WIDTH + 2];//以字为偏移单位                                 ;
/*********************寄存器***************************/
reg [TAG_WIDTH-1:0]        tag_ram [0:NUM_SETS-1][0:SET_ASSOCIATIVITY-1];
reg [DATA_WIDTH-1:0]       data_ram [0:NUM_SETS-1][0:SET_ASSOCIATIVITY-1][0:(SET_WORDS/SET_ASSOCIATIVITY)-1];
reg                        valid_ram [0:NUM_SETS-1][0:SET_ASSOCIATIVITY-1];
reg [1:0]                  lru_counter [0:NUM_SETS-1][0:SET_ASSOCIATIVITY-1];//  1024/32/4=8,每一组有四路，每一路有8个字节
reg                        r_cpu_arready;        
reg [DATA_WIDTH -1 : 0]    r_cpu_rdata;         
reg [1:0]                  r_cpu_rresp;                                 
reg                        r_cpu_rvalid;              
reg [ADDR_WIDTH -1:0]      r_memory_araddr1;
reg [ADDR_WIDTH -1:0]      r_memory_araddr2;        
reg                        r_memory_arvalid; 
reg                        r_memory_rready;   
reg [SET_INDEX_WIDTH-1:0]  saved_set;
reg [TAG_WIDTH-1:0]        saved_tag;
reg [SET_OFFSET_WIDTH-1:0] saved_offset;
reg [1:0]                  hit_way;
reg                        cache_hit;
reg [1:0]                  replace_way; 
reg [1:0]                  r_memory_break;
reg [31:0]                 min_val;
/**********************************进程*************************/
/********************************逻辑进程***********************/
initial begin
    r_cpu_arready    = 1;
    r_cpu_rvalid     = 0;
    r_memory_arvalid = 0;
    r_memory_rready  = 0;
    r_cpu_rresp      = 2'b00;
    hit_way          = 2'b00;
    r_memory_araddr1 = 32'b0;
    r_memory_araddr2 = 32'b0;
    
    saved_set    = {SET_INDEX_WIDTH{1'b0}};
    saved_tag    = {TAG_WIDTH{1'b0}};
    saved_offset = {SET_OFFSET_WIDTH{1'b0}};//存储
    r_memory_break = 2'b0;

    for (int i = 0; i < NUM_SETS; i++) begin
        for (int j = 0; j < SET_ASSOCIATIVITY; j++) begin
            tag_ram[i][j]     = 0;
            valid_ram[i][j]   = 0;
            lru_counter[i][j] = 0;
            for(int k = 0; k < SET_WORDS/SET_ASSOCIATIVITY; k++) begin
                data_ram[i][j][k] = {DATA_WIDTH{1'b0}};
            end
        end
    end
end
always @(posedge M_AXI_ACLK) begin
    if (w_system_rst) begin
        r_cpu_arready    <= 1;
        r_cpu_rvalid     <= 0;
        r_memory_arvalid <= 0;
        r_memory_rready  <= 0;
        r_memory_break   <= 2'b00;
        hit_way          <= 2'b00;

        for (int i = 0; i < NUM_SETS; i++) begin
            for (int j = 0; j < SET_ASSOCIATIVITY; j++) begin
                valid_ram[i][j]   <= 0;
                lru_counter[i][j] <= 0;
            end
        end
    end else begin
        if(W_CPU_AXI_ARVALID && r_cpu_arready && r_memory_break == 2'b00) begin
            saved_tag    <= req_tag;
            saved_set    <= req_set;
            saved_offset <= req_offset;//存储

            r_memory_arvalid <= 1;
            r_memory_araddr1 <= {W_CPU_AXI_ARADDR[31:3], 3'b000}; //对齐地址
            r_memory_araddr2 <= {W_CPU_AXI_ARADDR[31:3], 3'b100}; //下一个字地址
            
            r_cpu_arready <= 0;

            if (cache_hit) begin
                r_cpu_rdata      <= data_ram[req_set][hit_way][req_offset];
                r_cpu_rresp      <= 2'b00;
                r_cpu_rvalid     <= 1;
                r_memory_break   <= 2'b11;//设置命中状态
                r_memory_arvalid <= 0;    //取消内存请求
                for (int i = 0; i < SET_ASSOCIATIVITY; i++) begin
                        lru_counter[req_set][i] <= (i == hit_way) ? 2'b11 :  (lru_counter[req_set][i] > 0) ? lru_counter[req_set][i] - 1 : 0;
                    end
                end
            else begin
                r_memory_break  <= 2'b01; //设置未命中状态
                r_memory_rready <= 1;     //准备接受内存数据
            end
        end
    end

    if(W_MEMORY_AXI_ARREADY && r_memory_arvalid )begin
        r_memory_arvalid <= 0;
    end
    //缓存未命中处理
    if(r_cpu_arready == 0 && hit_way == 0 && r_memory_break == 2'b01 ) begin
        if(W_MEMORY_AXI_RVALID && r_memory_rready) begin
            r_memory_rready <= 0;
            //写入缓存
            data_ram[saved_set][replace_way][0] <= W_MEMORY_AXI_RDATA1;
            data_ram[saved_set][replace_way][1] <= W_MEMORY_AXI_RDATA2;
            //更新缓存状态
            valid_ram[saved_set][replace_way] <= 1;
            tag_ram[saved_set][replace_way]   <= saved_tag;
            for (int i = 0; i < SET_ASSOCIATIVITY; i++) begin
                lru_counter[saved_set][i] <= (i == replace_way) ? 2'b11 :  (lru_counter[saved_set][i] > 0) ? lru_counter[saved_set][i] - 1 : 0;
            end
            r_cpu_rdata    <= data_ram[saved_set][replace_way][saved_offset];
            r_cpu_rvalid   <= 1;
            r_cpu_rresp    <= 2'b00;
            r_memory_break <= 2'b00;
        end
    end
    if(r_cpu_rvalid && W_CPU_AXI_RREADY) begin
        r_cpu_rvalid<=0; 
        r_cpu_arready<=1;
        //重置命中状态
        hit_way  <=2'b00;
        cache_hit<=0;
        r_memory_arvalid<=0;
    end
end
//***********************lru替换策略以及命中检查*****************************//
always @(*) begin
    replace_way = 0;
    min_val = 30; 
    //遍历所有路，找到LRU计数器最小的路
    for (int i = 0; i < SET_ASSOCIATIVITY; i++) begin
        if (lru_counter[saved_set][i] < min_val) begin
            min_val = lru_counter[saved_set][i];
            replace_way = i;
        end
    end
end
//缓存命中检测
always @(*) begin
    cache_hit = 0;
    hit_way = 0;
    //遍历所有的路，检查是否命中
    for (int i = 0; i < SET_ASSOCIATIVITY; i++) begin
        if (valid_ram[req_set][i] && (tag_ram[req_set][i] == req_tag)) begin
            cache_hit = 1;
            hit_way = i;
        end
    end
end
endmodule



