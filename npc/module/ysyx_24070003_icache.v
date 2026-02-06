module ysyx_24070003_icache(
    input clock,
    input reset,
    input fence_i,
    input flush,
    input  [31:0]  IFU_AXI4_araddr,
    input          IFU_AXI4_arvalid,
    // output reg        IFU_AXI4_rvalid,
    input             IFU_AXI4_rready,
    //input  [31:0]     BTB_pre_DNPC,
    input             IDU_IFU_STALL,
    input             LSU_IFU_stall,

    output    [31:0]  ICACHE_IFU_rdata,
    output    [31:0]  ICACHE_IFU_raddr,
    //output    [31:0]  ICACHE_IFU_pre_dnpc,
    output            ICACHE_IFU_valid,

    // output reg [63:0] ICACHE_hit_count,
    // output reg [63:0] ICACHE_miss_count,
    // output reg [63:0] total_access,
    // output reg [63:0] access_time,
    // output reg [63:0] miss_penalty,
    // output reg [63:0] ifu_during_count,

    output reg [31:0] ICACHE_AXI4_araddr,
    output reg        ICACHE_AXI4_arvalid,
    input             ICACHE_AXI4_arready,
    input  [31:0]     ICACHE_AXI4_rdata,
    input             ICACHE_AXI4_rvalid,
    input             ICACHE_AXI4_rlast,
    output            ICACHE_IFU_stall,
    output            ICACHE_AXI4_rready,
    output reg [7:0]  ICACHE_AXI4_arlen
    
);

parameter SDRAM_BLOCK_SIZE = 16;     
parameter SDRAM_NUM_BLOCKS = 4;    
parameter SDRAM_OFFSET_BITS = 4;    
parameter SDRAM_INDEX_BITS = 2;     
parameter SDRAM_TAG_BITS = 26;       


reg [SDRAM_TAG_BITS-1:0] tags [0:SDRAM_NUM_BLOCKS-1];  // 标签存储
reg [SDRAM_BLOCK_SIZE * 8-1:0] data [0:SDRAM_NUM_BLOCKS-1];           // 数据存储
reg [SDRAM_NUM_BLOCKS-1:0]valid ;                // 有效位

              // 有效位
parameter  IDLE = 0,
            AXI_WAIT = 1,
            AXI_READ = 2;
reg [1:0] state;
// typedef enum logic [2:0] {
//     IDLE,        // 空闲状态
//     AXI_WAIT,
//     AXI_READ    // 
// } state_t;


// state_t state;

reg [1:0] burst_count;
integer i;

//reg hit_reg1;
reg [31:0]  pc_reg1;
reg reg1_valid;
reg [31:0] reg1_pre_dnpc;

wire hit_reg1;


reg [31:0] addr_reg3;
reg [31:0] data_reg3;
reg [31:0] per_pc_reg3;
reg data_valid;

reg flush_r;



wire [SDRAM_TAG_BITS-1:0] tag_reg1 = pc_reg1[31:SDRAM_OFFSET_BITS+SDRAM_INDEX_BITS];
wire [SDRAM_INDEX_BITS-1:0] index_reg1 = pc_reg1[SDRAM_OFFSET_BITS+SDRAM_INDEX_BITS-1:SDRAM_OFFSET_BITS];


wire icache_stall = LSU_IFU_stall || IDU_IFU_STALL;

assign hit_reg1 = (valid[index_reg1] && (tags[index_reg1] == tag_reg1));
reg first_req;
always @(posedge clock) begin
    if (reset | flush | flush_r)                    first_req <= 1'b1;
    else if (reg1_valid && hit_reg1)
                                  first_req <= 1'b0;  // 只要曾经命中过，就退出首次
end

// 更新条件
wire allow_update;
assign allow_update = (!icache_stall && IFU_AXI4_rready && !fence_i &&
                      (state == IDLE) &&
                      (first_req & (~reg1_valid) || hit_reg1)) | (!icache_stall && state == AXI_READ && ICACHE_AXI4_rlast & ~(flush | flush_r)); 

always @(posedge clock) begin
    if(reset) begin
        pc_reg1 <= 0;
        //reg1_pre_dnpc <= 0;
    end
    else if(allow_update) begin
        pc_reg1 <= IFU_AXI4_araddr;
        //reg1_pre_dnpc <= BTB_pre_DNPC;
    end
end

always @(posedge clock) begin
    if(reset) begin
        reg1_valid  <= 0;
    end
    else if(flush) begin
        reg1_valid <= 0;
    end
    else if(!icache_stall && IFU_AXI4_rready && !fence_i) begin
        reg1_valid <= 1'b1;
    end
end

always @(posedge clock) begin
    if(!icache_stall && IFU_AXI4_rready && reg1_valid && hit_reg1 && state == IDLE) begin
            case (pc_reg1[3:2])
                2'b00: data_reg3 <= data[index_reg1][31:0];
                2'b01: data_reg3 <= data[index_reg1][63:32];
                2'b10: data_reg3 <= data[index_reg1][95:64];
                2'b11: data_reg3 <= data[index_reg1][127:96];
            endcase
            addr_reg3 <= pc_reg1;
            //per_pc_reg3 <= reg1_pre_dnpc;
       
    end
    else if(!icache_stall && state == AXI_READ && ICACHE_AXI4_rlast)begin
        case (pc_reg1[3:2])
            2'b00: data_reg3 <= data[index_reg1][31:0];
            2'b01: data_reg3 <= data[index_reg1][63:32];
            2'b10: data_reg3 <= data[index_reg1][95:64];
            2'b11: data_reg3 <= ICACHE_AXI4_rdata;
        endcase
        addr_reg3 <= pc_reg1;
        //per_pc_reg3 <= reg1_pre_dnpc;
    end
end

assign ICACHE_IFU_rdata = data_reg3;
assign ICACHE_IFU_raddr = addr_reg3;
//assign ICACHE_IFU_pre_dnpc  = per_pc_reg3;
assign ICACHE_IFU_valid = data_valid & (~flush);

assign ICACHE_IFU_stall = ~allow_update;


always @(posedge clock) begin
    if(reset)begin
        data_valid <= 0;
    end
    else if(flush || flush_r || fence_i) begin
        data_valid <= 0;
    end
    else if((!icache_stall && state == IDLE && reg1_valid && hit_reg1 && (~flush)) || (!icache_stall && state == AXI_READ && ICACHE_AXI4_rlast)) begin
        data_valid <= 1'b1;
    end
    else if(ICACHE_IFU_valid && IFU_AXI4_rready)begin
        data_valid <= 1'b0;
    end
end

always @(posedge clock) begin
    if(reset) begin
        flush_r <= 0;
    end
    else if(state != IDLE && flush) begin
        flush_r <= flush;
    end
    else if(state == IDLE) begin
        flush_r <= 0;
    end
end

always @(posedge clock) begin
    if(reset) begin
        state <= IDLE;
    end
    else begin
        case (state)
        IDLE: begin
            if(reg1_valid && (!(LSU_IFU_stall || IDU_IFU_STALL)) && IFU_AXI4_rready) begin
                if(hit_reg1)begin
                    state <= IDLE;
                end
                else if(!flush)begin
                    state <= AXI_WAIT;
                end
            end
        end
        AXI_WAIT: begin
            if(ICACHE_AXI4_arready && ICACHE_AXI4_arvalid) begin
                state <= AXI_READ;
            end
            else begin
                state <= AXI_WAIT;
            end
        end
        AXI_READ: begin
            if(ICACHE_AXI4_rvalid && ICACHE_AXI4_rlast) begin
                state <= IDLE; 
            end
            else begin
                state <= AXI_READ;
            end
        end
        default: begin
            state <= IDLE;
        end
        endcase
    end
end

// always @(posedge clock) begin
//     if(reset) begin
//         ICACHE_hit_count <= 0;
//     end
//     else if(hit_reg2 && reg2_valid && (!stall) && IFU_AXI4_rready)begin
//         ICACHE_hit_count <= ICACHE_hit_count + 1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         ICACHE_miss_count <= 0;
//     end
//     else if(ICACHE_AXI4_arready && ICACHE_AXI4_arvalid && state == AXI_WAIT)begin
//         ICACHE_miss_count <= ICACHE_miss_count + 1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         access_time <= 0;
//     end
//     else if(state == IDLE && IFU_AXI4_arvalid) begin
//         access_time <= access_time + 1'b1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         total_access <= 0;
//     end
//     else if(reg2_valid && (!stall) && IFU_AXI4_rready) begin
//         total_access <= total_access + 1'b1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         miss_penalty <= 0;
//     end
//     else if(((!hit_reg2) && reg2_valid && (!stall) && IFU_AXI4_rready && state == IDLE) || state == AXI_READ || state == AXI_WAIT) begin
//         miss_penalty <= miss_penalty + 1'b1;
//     end
// end

// always @(posedge clock) begin
//     if(reset) begin
//         ifu_during_count <= 0;
//     end
//     else if((reg2_valid && (!stall) && IFU_AXI4_rready) || state == AXI_READ || state == AXI_WAIT || state == UPDATED_CACHE ) begin
//         ifu_during_count <= ifu_during_count + 1;
//     end
// end




assign ICACHE_AXI4_rready = 1'b1;
assign ICACHE_AXI4_arlen = 8'b11;  // 一次读取4个数据
//assign ICACHE_AXI4_araddr = (is_sdram_reg2) ? {pc_reg2[31:4], 4'b0} : {pc_reg2[31:2], 2'b0};  // 地址对齐到16字节边界

always @(posedge clock)begin
    if(state == AXI_READ && ICACHE_AXI4_rvalid) begin
        case (burst_count)
            2'b00: data[index_reg1][31:0] <= ICACHE_AXI4_rdata;
            2'b01: data[index_reg1][63:32] <= ICACHE_AXI4_rdata;
            2'b10: data[index_reg1][95:64] <= ICACHE_AXI4_rdata;
            2'b11: data[index_reg1][127:96] <= ICACHE_AXI4_rdata;
        endcase
        
    end
end

always @(posedge clock)begin
    if(reset) begin
        burst_count <= 0;
    end 
    else if(state == AXI_READ && ICACHE_AXI4_rvalid) begin
        burst_count <= burst_count + 1;
    end
end



always @(posedge clock) begin
    if(fence_i | reset) begin
        valid <= 0;  // 复位时所有块无效
    end
    else if(state == AXI_READ) begin
        valid[index_reg1] <= 1'b1;
        tags[index_reg1] <= tag_reg1;
    end
end



always @(posedge clock) begin
    if(reset)begin
        ICACHE_AXI4_arvalid <= 0;
        ICACHE_AXI4_araddr <= 0;
    end
    else if((ICACHE_AXI4_arready && ICACHE_AXI4_arvalid))begin
        ICACHE_AXI4_arvalid <= 1'b0;
    end
    else  if(state == IDLE && (!hit_reg1) && reg1_valid && (!flush) && IFU_AXI4_rready)begin
        ICACHE_AXI4_arvalid <= 1'b1;
        ICACHE_AXI4_araddr <= {pc_reg1[31:4], 4'b0} ; 
    end
    
end



endmodule
