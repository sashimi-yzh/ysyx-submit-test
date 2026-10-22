
module ysyx_25020042_icache(
    input              clock            ,
    input              reset            ,
    input              pc_valid         ,
    input   [31:0]     pc_addr          ,
    output reg         instruction_ready,
    output reg [31:0]  instruction      ,
    output             Instruction_access_fault,
    `ifdef VERILATOR
    output reg [63:0]  icache_hit_count ,
    `endif

    input              io_icache_arready,
    input              fencei_signal    ,
    output reg         io_icache_arvalid,
    output reg [31:0]  io_icache_araddr ,
    output wire [3:0]  io_icache_arid   ,
    output reg [7:0]   io_icache_arlen  ,
    output wire [2:0]  io_icache_arsize ,
    output reg [1:0]   io_icache_arburst,
    output reg         io_icache_rready ,
    input              io_icache_rvalid ,
    input   [1:0]      io_icache_rresp  ,
    input   [31:0]     io_icache_rdata  ,
    input              io_icache_rlast  ,
    input   [3:0]      io_icache_rid    
);

`ifdef VERILATOR

always @(posedge clock) begin
    if (reset) begin
        icache_hit_count <= 0;
    end
    else begin
        if (hit & pc_valid)
            icache_hit_count <= icache_hit_count + 1;
    end
end

`endif

parameter CACHE_BLOCK_SIZE  = 16;
parameter CACHE_BLOCK_BANK  = 4;
parameter CACHE_BLOCK_COUNT = CACHE_BLOCK_SIZE / 4;
// parameter m                 = $clog2(CACHE_BLOCK_SIZE);
// parameter n                 = $clog2(CACHE_BLOCK_BANK);
parameter m                 = 4;
parameter n                 = 1;
/* verilator lint_off UNUSEDPARAM */
parameter SDRAM_BASE_ADDR   = 32'ha0000000;
parameter SDRAM_SIZE        = 32'h20000000;
/* verilator lint_on UNUSEDPARAM */

// 展平为一维：索引 {bank_index, word_offset}，等价于原 [bank][word] 二维写法
reg [32-1:0]                 icache_data[0:CACHE_BLOCK_BANK*CACHE_BLOCK_COUNT-1];
reg [32-1:0]                 icache_addr[0:CACHE_BLOCK_BANK-1];
reg                          icache_valid[0:CACHE_BLOCK_BANK-1];
reg                          state;
reg [m-1:2]                  burst_count;
reg                          instr_access_fault;

// 发起 AR 时锁存本次请求的信息。READ 期间 pc_addr 可能因跳转改变，
// 若直接用组合的 index/offset/sdram_valid 会填错 bank 或误拒填充。
reg                          req_sdram_valid;
reg [m+n-1:m]                req_index;
reg [m-1:2]                  req_offset;

`ifdef PLATFORM_YSYXSOC
wire                          sdram_valid    = (pc_addr >= SDRAM_BASE_ADDR) && (pc_addr < SDRAM_BASE_ADDR + SDRAM_SIZE);
`else 
wire                          sdram_valid = 1;
`endif
wire [31:m+n]                 addr_tag       = pc_addr[31:m+n];
wire [m+n-1:m]                index          = pc_addr[m+n-1:m];
wire [m-1:2]                  offset         = pc_addr[m-1:2];
wire [31:m+n]                 icache_tag     = icache_addr[index][31:m+n];
wire                          hit            = (icache_tag == addr_tag) && (icache_valid[index]);
wire [31:m]                   burst_addr     = io_icache_araddr[31:m];
wire [m-1:2]                  burst_offset   = burst_count;


localparam IDLE = 1'b0;
localparam READ = 1'b1;

// 只在交付指令时刷新，避免一次 access fault 之后永久粘滞
assign Instruction_access_fault = instr_access_fault;

always @(posedge clock) begin
    state <= state;
    if (reset) begin
        state <= IDLE;
    end
    else begin
        case(state)
            IDLE: begin
                if (pc_valid) begin
                    if(hit)
                        state <= IDLE;
                    else 
                        state <= READ;
                end
                else 
                    state <= IDLE;
            end
            READ: begin
                if (io_icache_rlast && io_icache_rvalid && io_icache_rid == io_icache_arid)
                    state <= IDLE;
                else 
                    state <= READ;
            end
            default: begin
                state <= state;
            end
        endcase
    end
end

//  31    m+n m+n-1   m m-1    0
// +---------+---------+--------+
// |   tag   |  index  | offset |
// +---------+---------+--------+

always @(posedge clock) begin
    burst_count <= burst_count;
    if (reset) begin
        burst_count <= 0;
    end
    else begin
        if (io_icache_rlast & req_sdram_valid)
            burst_count <= 0;
        else if (io_icache_rvalid & req_sdram_valid)
            burst_count <= burst_count + 1;
    end
end

// 发起 AR 时锁存请求信息，READ 期间不再依赖 pc_addr
always @(posedge clock) begin
    if (reset) begin
        req_sdram_valid <= 1'b0;
        req_index       <= 0;
        req_offset      <= 0;
    end
    else if (state == IDLE && !hit && pc_valid) begin
        req_sdram_valid <= sdram_valid;
        req_index       <= index;
        req_offset      <= offset;
    end
end



always @(posedge clock) begin
    if (reset) begin
        icache_valid[0] <= 1'b0;
        icache_valid[1] <= 1'b0;
        instruction_ready <= 1'b0;
        instr_access_fault <= 1'b0;
    end
    else begin
        if (state == READ) begin
            if (io_icache_rvalid) begin
                if (req_sdram_valid) begin
                    icache_valid[req_index]                         <= 1'b1;
                    icache_addr[req_index][31:m+n]                  <= burst_addr[31:m+n];
                    icache_addr[req_index][m+n-1:m]                 <= burst_addr[m+n-1:m];
                    icache_addr[req_index][m-1:0]                   <= {m{1'b0}};
                    icache_data[{req_index, burst_offset}]          <= io_icache_rdata;
                end
                if (io_icache_rlast) begin
                    instruction_ready            <= 1'b1;
                    instr_access_fault           <= io_icache_rresp[1] | io_icache_rresp[0];
                    if (req_sdram_valid) begin
                        instruction <= (req_offset == {(m-2){1'b1}})? io_icache_rdata : icache_data[{req_index, req_offset}];
                    end
                    else begin
                        instruction <= io_icache_rdata;
                    end
                end
            end
        end
        if (state == IDLE) begin
            if (hit & pc_valid) begin
                instruction_ready  <= 1'b1;
                instr_access_fault <= 1'b0;
                instruction        <= icache_data[{index, offset}];
            end
            if (instruction_ready)
                instruction_ready <= 1'b0;
        end
        // fencei 无条件生效（包括填充进行中），放在最后以免被上面的写回覆盖
        if (fencei_signal) begin
            icache_valid[0] <= 1'b0;
            icache_valid[1] <= 1'b0;
        end
    end
end

assign io_icache_arid = 4'b0;
assign io_icache_arsize = 3'b010; // 4byte

always @(posedge clock) begin
    if (reset) begin
        // io_icache_araddr <= 32'h0;
        io_icache_arvalid <= 1'b0;
        io_icache_rready <= 1'b0;
        // io_icache_arid <= 4'h0;
        // io_icache_arsize <= 3'b010;
        io_icache_arburst <= 2'b00;
        io_icache_arlen <= 8'h0;
    end
    else begin
        if (state == IDLE && !hit && pc_valid) begin
            if (sdram_valid) begin
                io_icache_araddr  <= {pc_addr[31:m], {m{1'b0}}};
                io_icache_arvalid <= 1'b1;
                io_icache_arburst <= 2'b01; // INCR 01
                io_icache_arlen   <= CACHE_BLOCK_COUNT - 1; // 覆盖整个 cache block
            end
            else begin
                io_icache_arburst <= 2'b00;
                io_icache_arlen   <= 8'h0;
                io_icache_araddr  <= pc_addr;
                io_icache_arvalid <= 1'b1;
            end
        end

        if (io_icache_arvalid & io_icache_arready) begin
            io_icache_arvalid <= 1'b0;
            io_icache_rready <= 1'b1;
        end
            
        if (io_icache_rlast && io_icache_rvalid && io_icache_rid == io_icache_arid) begin
            io_icache_rready <= 1'b0;
        end
    end
end

endmodule
