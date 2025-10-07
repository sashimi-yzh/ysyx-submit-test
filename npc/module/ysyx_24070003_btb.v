module ysyx_24070003_btb(
    input clock,
    input reset,
    input [31:0] cur_pc,
    input [31:0] update_pc,
    input [31:0] target_pc,
    input        update_valid,

    output [31:0] pred_pc,
    output        pred_valid
);


localparam WAY_NUM = 2;
localparam INDEX_WIDTH = 2;
localparam ADDR_WIDTH = 32;
localparam OFFSET_WITH = 2;
localparam TAG_WIDTH = ADDR_WIDTH - OFFSET_WITH - INDEX_WIDTH;

wire [INDEX_WIDTH-1:0] cur_index;
wire [TAG_WIDTH-1:0] cur_tag;
wire [INDEX_WIDTH-1:0] update_index;
wire [TAG_WIDTH-1:0] update_tag;
wire [WAY_NUM-1:0] hit;
wire [WAY_NUM-1:0] update_hit;
//wire cur_hit;
wire upd_hit;

reg [TAG_WIDTH-1:0] btb_tag [2 ** INDEX_WIDTH -1:0][WAY_NUM-1:0];     // 标签存储
reg [29:0] btb_target [2 ** INDEX_WIDTH -1:0][WAY_NUM-1:0];  // 目标地址存储
reg btb_valid [2 ** INDEX_WIDTH -1:0][WAY_NUM-1:0];          // 有效位

reg [3:0] hit_valid;
reg [3:0] hit_valid1;

assign cur_index = cur_pc[INDEX_WIDTH+OFFSET_WITH-1:OFFSET_WITH];
assign cur_tag = cur_pc[ADDR_WIDTH-1:INDEX_WIDTH+OFFSET_WITH];
assign update_index = update_pc[INDEX_WIDTH+OFFSET_WITH-1:OFFSET_WITH];
assign update_tag = update_pc[ADDR_WIDTH-1:INDEX_WIDTH+OFFSET_WITH];

assign hit[0] = btb_valid[cur_index][0] && (btb_tag[cur_index][0] == cur_tag);
assign hit[1] = btb_valid[cur_index][1] && (btb_tag[cur_index][1] == cur_tag);

assign pred_valid = (hit_valid[cur_index]) ? hit[0] : (hit_valid1[update_index]) ? hit[1] : 0;

assign update_hit[0] = ~btb_valid[update_index][0] ;
assign update_hit[1] = ~btb_valid[update_index][1] ;



assign pred_pc = (pred_valid) ? {btb_target[cur_index][hit[1]],2'b00} : cur_pc;

reg update_way;
always @(posedge clock) begin
    if(reset)begin 
        update_way <= 0;
    end
    else if(update_valid)begin
        update_way <= ~update_way;
    end
end

integer i,j;
always @(posedge clock) begin
    if(reset)begin
        hit_valid <= 4'b0000;
        hit_valid1 <= 4'b0000;
    end
    else if(update_valid)begin
        if(update_hit[0]) begin
            hit_valid[update_index] <= 1;
            btb_tag[update_index][0] <= update_tag;
            btb_target[update_index][0] <= target_pc[31:2];
            btb_valid[update_index][0] <= 1;
        end
        else if(update_hit[1]) begin
            hit_valid1[update_index] <= 1;
            btb_tag[update_index][1] <= update_tag;
            btb_target[update_index][1] <= target_pc[31:2];
            btb_valid[update_index][1] <= 1;
        end
        else begin
            btb_tag[update_index][update_way] <= update_tag;
            btb_target[update_index][update_way] <= target_pc[31:2];
            btb_valid[update_index][update_way] <= 1;
        end
    end
end

endmodule

