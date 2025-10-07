module ysyx_24070003_icache(
    input clock,
    input reset,
    input fence_i,
    input flush,
    input  [31:0]  IFU_ICACHE_araddr,
    input          IFU_ICACHE_arvalid,
    // output reg        IFU_AXI4_rvalid,
    input             IFU_ICACHE_rready,
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
    output            ICACHE_AXI4_arvalid,
    input             ICACHE_AXI4_arready,
    input  [31:0]     ICACHE_AXI4_rdata,
    input             ICACHE_AXI4_rvalid,
    input             ICACHE_AXI4_rlast,
    output            ICACHE_IFU_stall,
    output            ICACHE_AXI4_rready,
    output     [7:0]  ICACHE_AXI4_arlen
    
);

parameter SDRAM_BLOCK_SIZE = 16;     
parameter SDRAM_NUM_BLOCKS = 2;    
parameter SDRAM_OFFSET_BITS = 4;    
parameter SDRAM_INDEX_BITS = 1;     
parameter SDRAM_TAG_BITS = 27;       


reg [SDRAM_TAG_BITS-1:0] tags [0:SDRAM_NUM_BLOCKS-1];  // 标签存储
reg [SDRAM_BLOCK_SIZE * 8-1:0] data [0:SDRAM_NUM_BLOCKS-1];           // 数据存储
reg [SDRAM_NUM_BLOCKS-1:0]valid ;                // 有效位

              // 有效位
parameter  IDLE = 3'd0,
            FLUSH_WAIT = 3'd1,
            AXI_WAIT = 3'd2,
            AXI_READ = 3'd3,
            UPDATED_CACHE = 3'd4;
reg [2:0] state;
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
wire hit;
wire hit_reg1;


reg [31:0] addr_reg3;
reg [31:0] data_reg3;
reg [31:0] per_pc_reg3;
reg data_valid;

reg flush_r;



wire [SDRAM_TAG_BITS-1:0] tag_reg1 = IFU_ICACHE_araddr[31:SDRAM_OFFSET_BITS+SDRAM_INDEX_BITS];
wire [SDRAM_INDEX_BITS-1:0] index_reg1 = IFU_ICACHE_araddr[SDRAM_OFFSET_BITS+SDRAM_INDEX_BITS-1:SDRAM_OFFSET_BITS];


wire icache_stall = LSU_IFU_stall || IDU_IFU_STALL;

assign hit = (valid[index_reg1] && (tags[index_reg1] == tag_reg1) && IFU_ICACHE_arvalid);


always @(posedge clock) begin
    if(!icache_stall && IFU_ICACHE_rready && hit && state == IDLE) begin
            case (IFU_ICACHE_araddr[3:2])
                2'b00: data_reg3 <= data[index_reg1][31:0];
                2'b01: data_reg3 <= data[index_reg1][63:32];
                2'b10: data_reg3 <= data[index_reg1][95:64];
                2'b11: data_reg3 <= data[index_reg1][127:96];
            endcase
            addr_reg3 <= IFU_ICACHE_araddr;
            //per_pc_reg3 <= reg1_pre_dnpc;
       
    end
    // else if(!icache_stall && state == AXI_READ && ICACHE_AXI4_rlast)begin
    //     case (IFU_ICACHE_araddr[3:2])
    //         2'b00: data_reg3 <= data[index_reg1][31:0];
    //         2'b01: data_reg3 <= data[index_reg1][63:32];
    //         2'b10: data_reg3 <= data[index_reg1][95:64];
    //         2'b11: data_reg3 <= ICACHE_AXI4_rdata;
    //     endcase
    //     addr_reg3 <= IFU_ICACHE_araddr;
    //     //per_pc_reg3 <= reg1_pre_dnpc;
    // end
end

assign ICACHE_IFU_rdata = data_reg3;
assign ICACHE_IFU_raddr = addr_reg3;
//assign ICACHE_IFU_pre_dnpc  = per_pc_reg3;
assign ICACHE_IFU_valid = data_valid & (~flush);

wire allow_update = (state == IDLE && !icache_stall && IFU_ICACHE_rready && hit) ;//|| (state == AXI_READ && ICACHE_AXI4_rlast);
assign ICACHE_IFU_stall = ~allow_update;


always @(posedge clock) begin
    if(reset)begin
        data_valid <= 0;
    end
    else if(flush || fence_i) begin
        data_valid <= 0;
    end
    else if((!icache_stall && state == IDLE && hit && (~flush))) begin
        data_valid <= 1'b1;
    end
    else if(IFU_ICACHE_rready)begin
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
            if(IFU_ICACHE_arvalid && (!icache_stall) && IFU_ICACHE_rready) begin
                if(hit)begin
                    state <= IDLE;
                end
                else if(!flush)begin
                    state <= FLUSH_WAIT;
                end
            end
        end
        FLUSH_WAIT: begin //防止前面最后一下指令需要冲刷，然后进入状态机，白跑一个访存
            if(flush) begin
                state <= IDLE;
            end
            else if(!icache_stall)begin
                state <= AXI_WAIT;
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
        UPDATED_CACHE: begin
            state <= IDLE;
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


assign ICACHE_AXI4_arvalid = (state == AXI_WAIT);
always @(posedge clock) begin
    if(reset)begin
        ICACHE_AXI4_araddr <= 0;
    end
    else if(state == FLUSH_WAIT && (!flush) && (!icache_stall))begin
        ICACHE_AXI4_araddr <= {IFU_ICACHE_araddr[31:4], 4'b0} ; 
    end
    
end



endmodule
