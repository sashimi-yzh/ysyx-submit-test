module ysyx_25050136_IF
    (
        input         clk           ,
        input         reset         ,
        input         flush         ,
        input  [31:0] branch_npc_i  ,
        input  [31:0] pht_pc_i      ,
        input         pht_update_i  ,
        input         pht_taken_i   ,
        input  [31:0] btb_pc_i      ,
        input         btb_update_i  ,
        input  [31:0] btb_target_i  , // 为了时序，暂时未使用，btb更新值就是branch_npc_i
        input         out_ready_i   ,
        output [31:0] out_pc_o      ,
        output [31:0] out_prepc_o   ,
        output        out_taken_o   ,
        output        out_btb_hit_o ,
        output        out_valid_o
    );
     
    localparam RESET_PC = 32'h30000000;  

    localparam PHT_INDEX = 4;
    localparam BTB_INDEX = 4;
    localparam BTB_TAG   = 9;
    // ==== 信号定义 ====
    // 时序逻辑
    reg [31:0] pc;
    wire out_fire = out_ready_i & out_valid_o;
    wire [PHT_INDEX-1:0] pht_pc_index_w = pht_pc_i[2+:PHT_INDEX];
    wire [PHT_INDEX-1:0] pht_pc_index_r = pc[2+:PHT_INDEX];
    wire [BTB_INDEX-1:0] btb_pc_index_w = btb_pc_i[2+:BTB_INDEX] ^ btb_pc_i[2+BTB_INDEX+:BTB_INDEX];
    wire [BTB_TAG-1:0]   btb_pc_tag_w   = btb_pc_i[2+BTB_INDEX+:BTB_TAG] ^ btb_pc_i[9+BTB_INDEX+:BTB_TAG];
    wire [BTB_INDEX-1:0] btb_pc_index_r = pc[2+:BTB_INDEX] ^ pc[2+BTB_INDEX+:BTB_INDEX];
    wire [BTB_TAG-1:0]   btb_pc_tag_r   = pc[2+BTB_INDEX+:BTB_TAG] ^ pc[9+BTB_INDEX+:BTB_TAG];
    wire        pht_pred_taken;
    wire [31:0] btb_pred_npc;

    wire [31:0] next_pc = (pht_pred_taken && out_btb_hit_o) ? btb_pred_npc : (pc + 4);
`ifdef YSYXSOC
    wire [31:0] if_dbg_pc = out_pc_o;
`ifdef EVENT_COUNTER
    always @(posedge clk) begin
        if(out_fire) fetch_get();
    end
`endif
`endif

    // ==== 逻辑实现 ====
    always @(posedge clk) begin
        if(reset) begin
            pc <= RESET_PC;
        end else begin
            if(flush) begin
                pc <= branch_npc_i;
            end else if(out_fire) begin
                pc <= next_pc;
            end
        end
    end

    assign out_pc_o = pc;
    assign out_prepc_o = next_pc; 
    assign out_taken_o = pht_pred_taken;  
    assign out_valid_o = !flush;

    ysyx_25050136_PHT 
    #(
        .INDEX_WIDTH (PHT_INDEX  )
    ) u_PHT (
        .clk          (clk            ),
        .reset        (reset          ),
        .index_w      (pht_pc_index_w   ),
        .index_r      (pht_pc_index_r   ),
        .pred_taken_i (pht_taken_i    ),
        .update_en_i  (pht_update_i   ),
        .pred_taken_o (pht_pred_taken)
    );

    ysyx_25050136_BTB
    #(
        .INDEX_WIDTH (BTB_INDEX     ),
        .TAG_WIDTH   (BTB_TAG       )
    ) u_BTB (
        .clk          (clk             ),
        .reset        (reset           ),
        .index_r      (btb_pc_index_r  ),
        .tag_r        (btb_pc_tag_r    ),
        .index_w      (btb_pc_index_w  ),
        .tag_w        (btb_pc_tag_w    ),
        .update_en_i  (btb_update_i    ),
        .target_pc_i  (branch_npc_i    ),
        .hit_o        (out_btb_hit_o   ),
        .target_pc_o  (btb_pred_npc)
    );


endmodule

module ysyx_25050136_PHT
    #(
        parameter INDEX_WIDTH = 10
    )
    (
        input                     clk         ,
        input                     reset       ,
        input  [INDEX_WIDTH-1:0]  index_w     ,
        input  [INDEX_WIDTH-1:0]  index_r     ,
        input                     pred_taken_i,
        input                     update_en_i ,
        output                    pred_taken_o
    );
    localparam PHT_SIZE = 1 << INDEX_WIDTH;
    // ==== 信号定义 ====
    reg [1:0] pht_array [0:PHT_SIZE-1]; // 2-bit saturating counter
    integer i;
    // ==== 逻辑实现 ====
    // PHT 初始化
    always @(posedge clk) begin
        if(reset) begin
            for(i = 0; i < PHT_SIZE; i = i + 1) begin
                pht_array[i] <= 2'b01; // 初始状态为弱不跳转
            end
        end else if(update_en_i) begin
            if(pred_taken_i) begin
                // 实际跳转，状态加1，饱和在11
                if(pht_array[index_w] != 2'b11)
                    pht_array[index_w] <= pht_array[index_w] + 2'b01;
            end else begin
                // 实际不跳转，状态减1，饱和在00
                if(pht_array[index_w] != 2'b00)
                    pht_array[index_w] <= pht_array[index_w] - 2'b01;
            end
        end
    end
    // 输出预测结果
    assign pred_taken_o = (pht_array[index_r][1] == 1'b1) ? 1'b1 : 1'b0;

endmodule

module ysyx_25050136_BTB
    #(
        parameter INDEX_WIDTH = 10,
        parameter TAG_WIDTH   = 20
    )
    (
        input                     clk         ,
        input                     reset       ,
        input  [INDEX_WIDTH-1:0]  index_r     ,
        input  [TAG_WIDTH-1:0]    tag_r       ,
        input  [INDEX_WIDTH-1:0]  index_w     ,
        input  [TAG_WIDTH-1:0]    tag_w       ,
        input                     update_en_i ,
        input  [31:0]             target_pc_i ,
        output                    hit_o       ,
        output [31:0]             target_pc_o
    );
    localparam BTB_SIZE = 1 << INDEX_WIDTH;
    // ==== 信号定义 ====
    reg btb_valid [0:BTB_SIZE-1];
    reg [TAG_WIDTH-1:0] btb_tag [0:BTB_SIZE-1];
    reg [31:0] btb_target [0:BTB_SIZE-1];
    // 查找逻辑
    integer i;
    // ==== 逻辑实现 ====
    // BTB 初始化
    always @(posedge clk) begin
        if(reset) begin
            for(i = 0; i < BTB_SIZE; i = i + 1) begin
                btb_valid[i] <= 0;
            end
        end else if(update_en_i) begin
            btb_valid[index_w]  <= 1'b1;
            btb_tag[index_w]    <= tag_w;
            btb_target[index_w] <= target_pc_i;
        end
    end
    // 输出目标地址
    assign hit_o = btb_valid[index_r] && (btb_tag[index_r] == tag_r);
    assign target_pc_o = hit_o ? btb_target[index_r] : 32'b0;

endmodule
