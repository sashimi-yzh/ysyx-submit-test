`include "npc_config.vh"

module ysyx_25040102_iCache(
    input               clock,
    input               reset, 

    // ifu
    input  [31:0]       in_paddr,
    input               in_psel,
    input               in_penable,
    output              in_pready,
    output [31:0]       in_prdata,
    output              in_pslverr,

    input               master_arready, 
    output              master_arvalid, 
    output  [31:0]      master_araddr,  
    output  [3:0]       master_arid,    
    output  [7:0]       master_arlen,   
    output  [2:0]       master_arsize,  
    output  [1:0]       master_arburst, 
    output              master_rready,  
    input               master_rvalid,  
    input   [1:0]       master_rresp,   
    input   [31:0]      master_rdata,   
    input               master_rlast,   
    input   [3:0]       master_rid      
);

    parameter   N = 4;
    parameter   M = 2; // 需要+2, 因为一个cache块4字节
    localparam  CACHE_SIZE  = 2**N; // 16
    localparam  BLOCK_SIZE  = 2**M; // 16
    localparam  TAG_WIDTH   = 32 - M -N - 2; 

    localparam  IDLE        = 0;
    localparam  BACK_INST   = 1;
    localparam  TO_MEM      = 2;
    localparam  WAIT_INST   = 3;
    
    reg [32 - 1:0]  icache  [CACHE_SIZE - 1:0][BLOCK_SIZE - 1 : 0]; // 16 blocks 16B
    // reg [32 - 1:0]  icache  [CACHE_SIZE - 1:0]; // 16 blocks 4B
    reg [TAG_WIDTH - 1 : 0]      cache_tag   [CACHE_SIZE - 1:0]; // 31-2-4

    wire    [TAG_WIDTH - 1 : 0]  pc_tag;
    wire    [N - 1:0]       pc_index;
    wire    [M - 1:0]       offset;

    wire            hit;
    reg     [M-1:0] cnt;
    // reg     [31:0]  inst_r;

    assign  pc_tag     = in_paddr[31 : M + N + 2];
    assign  pc_index   = in_paddr[M + N -1 +2 : M + 2];
    assign  offset     = in_paddr[M-1+2 : 2];

    reg     [1:0]   current_state;
    reg     [1:0]   next_state;

    always @(posedge clock) begin
        if(reset) begin
            current_state   <= IDLE;
        end
        else begin
            current_state   <= next_state;
        end
    end

    always @(*) begin
        case(current_state)
            
            IDLE: begin
                if(in_psel == 1'b1) begin
                    if(hit == 1'b1) begin
                        next_state  = BACK_INST;
                    end
                    else begin
                        next_state = TO_MEM;
                    end
                end
                else begin
                    next_state  = IDLE;
                end
            end

            BACK_INST: begin
                if(in_penable == 1'b1) begin
                    next_state  = IDLE;
                end
                else begin
                    next_state  = BACK_INST;
                end
            end

            TO_MEM: begin
                if(master_arready == 1'b1) begin
                    next_state = WAIT_INST;
                end
                else begin
                    next_state = TO_MEM;
                end
            end

            WAIT_INST: begin
                if(master_rlast == 1'b1 && master_rready == 1'b1 && master_rvalid == 1'b1) begin
                    next_state = BACK_INST;
                end
                else begin
                    next_state = WAIT_INST;
                end
            end

            default: next_state = IDLE;
            
        endcase
    end

    wire rec = (master_rvalid  == 1'b1 && master_rready  == 1'b1 && master_rresp == 2'b00);
    wire rst = (reset == 1'b1 || (in_prdata[6:2] == 5'b00011 && in_pready == 1'b1));

    assign  hit     = (cache_tag[pc_index] == pc_tag);
    
    always @(posedge clock) begin
        if(rst) begin
            for(integer i = 0; i < CACHE_SIZE; i = i + 1) begin
                cache_tag[i] <= {TAG_WIDTH{1'b1}};
            end
        end
        else begin
            if(rec) begin
                cache_tag[pc_index]         <= pc_tag;
            end
        end
    end

    always @(posedge clock) begin
        if(rec) begin
            icache[pc_index][cnt]       <= master_rdata;
        end
    end

    always @(posedge clock) begin
        if(rst) begin
            cnt     <= 0;
        end
        else begin
            if(rec) begin
                cnt     <= cnt + 1;
            end
        end
    end

    assign  in_pready = (current_state == BACK_INST && in_penable);
    assign  in_prdata = icache[pc_index][offset];

    assign  master_arvalid  = (current_state == TO_MEM);
    assign  master_araddr   = {in_paddr[31:4], 4'b0000};
    assign  master_arid     = 4'b0000;
    assign  master_arlen    = 8'h03;
    assign  master_arsize   = 3'b010;
    assign  master_arburst  = 2'b01;
    assign  master_rready   = (current_state == WAIT_INST);
    assign  in_pslverr      = (master_rresp == 2'b00) ? 1'b0 : 1'b1;

`ifdef ysyx_25040102_SIM
    always @(posedge clock) begin
        if(in_pready == 1'b1)begin
            icache_add(0);
        end
    end

    always @(posedge clock) begin
        if(hit == 1'b1 && current_state == IDLE && in_psel == 1'b1)begin
            icache_add(1);
        end
    end
`endif

`ifdef ysyx_25040102_SIM

    wire block = (current_state == BACK_INST && in_penable != 1'b1);

    reg     block_delay;
    wire    block_edge   = !block_delay & block;

    always @(posedge clock) begin
        block_delay      <= block;
    end

    always @(posedge clock) begin
        if(block_edge) begin
            time_add(0);
        end
    end

    always @(posedge clock) begin
        if(block == 1'b1) begin
            cycle_add(0);
        end
    end

    wire    miss = (current_state == TO_MEM || current_state == WAIT_INST);
    reg     miss_delay;
    wire    miss_edge   = !miss_delay & miss;

    always @(posedge clock) begin
        miss_delay      <= miss;
    end

    always @(posedge clock) begin
        if(miss_edge) begin
            time_add(1);
        end
    end

    always @(posedge clock) begin
        if(miss) begin
            cycle_add(1);
        end
    end

`endif

endmodule
