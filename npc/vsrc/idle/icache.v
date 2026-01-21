// // 要求OFFSET_WIDTH > 2
// module ysyx_25050136_ICACHE
// #(
//     parameter OFFSET_WIDTH = 4,
//     parameter NUM_WAY = 1,
//     parameter INDEX_WIDTH = 1
// )
// (
//     input                                      clk          ,
//     input                                      reset        ,
//     // ICACHE与CPU接口
//     input                                   ic_flush_i      ,
//     input                                   ic_fencei_i     ,  // 新增：fence.i 信号       
//     input                                   ic_req_valid_i  ,
//     input    [31:0]                         ic_req_addr_i   ,
//     input    [31:0]                         ic_req_prepc_i  ,  // 新增：预测 PC
//     input                                   ic_req_taken_i  ,  // 新增：预测跳转
//     input                                   ic_req_btb_hit_i,  // 新增：BTB 命中
//     output                                  ic_req_ready_o  ,
//     input                                   ic_ret_ready_i  ,
//     output   [31:0]                         ic_ret_rdata_o  ,
//     output   [31:0]                         ic_ret_addr_o   ,
//     output   [31:0]                         ic_ret_prepc_o  ,  // 新增：返回预测 PC
//     output                                  ic_ret_taken_o  ,  // 新增：返回预测跳转
//     output                                  ic_ret_btb_hit_o,  // 新增：返回 BTB 命中
//     output                                  ic_ret_valid_o  ,                           
//     // ICACHE与AXI接口                                        
//     output                                  ia_flush_o      ,
//     output                                  ia_rd_req_o     ,
//     output   [31:0]                         ia_rd_addr_o    ,
//     input                                   ia_ret_valid_i  ,
//     input                                   ia_ret_last_i   ,
//     input    [31:0]                         ia_ret_data_i   
//     // 内部
// );

//     // ==================== cache内部信号定义 =============================
//     parameter LINE_WIDTH   = 8 << OFFSET_WIDTH;                // cacheline宽度
//     parameter WORDS        = 1 << (OFFSET_WIDTH - 2);          // cacheline的字数
//     parameter TAG_WIDTH    = 32 - OFFSET_WIDTH - INDEX_WIDTH;  // tag的宽度
//     parameter NUM_SET      = 1 << INDEX_WIDTH;                 // set的数量
//     parameter WAY_WIDTH    = (NUM_WAY > 1) ? $clog2(NUM_WAY) : 1; // way的数量
//     parameter OFFSET_INDEX = (OFFSET_WIDTH > 2) ? OFFSET_WIDTH-2 : 1; // 用于索引的offset的位宽
//     // icache存储阵列
//     reg [LINE_WIDTH-1:0] cache_data  [0:NUM_WAY-1][0:NUM_SET-1]; 
//     reg [TAG_WIDTH-1 :0] cache_tag   [0:NUM_WAY-1][0:NUM_SET-1];
//     reg                  cache_valid [0:NUM_WAY-1][0:NUM_SET-1];
//     // 第一级流水线
//     reg idle_1;
//     reg [31:0] addr_1;
//     reg [31:0] prepc_1;  // 新增：预测 PC
//     reg taken_1;         // 新增：预测跳转
//     reg btb_hit_1;       // 新增：BTB 命中
    
//     reg [NUM_WAY-1:0] hit_mask_1;
//     wire in_fire_1 = ic_req_valid_i & ic_req_ready_o;
//     wire [INDEX_WIDTH-1:0] addr_index_1;
//     wire [TAG_WIDTH-1:0] addr_tag_1;
//     // 第一第二级流水线握手信号
//     wire temp_valid, temp_ready;
//     wire [31:0] temp_addr;
//     wire [31:0] temp_prepc;
//     wire temp_taken;       
//     wire temp_btb_hit;     
//     wire [NUM_WAY-1:0] temp_hit_mask;
//     wire temp_fire = temp_valid & temp_ready;
//     // 第二级流水线
//     // HIT 时
//     reg idle_2;
//     reg [31:0] addr_2;
//     reg [31:0] prepc_2;
//     reg taken_2;       
//     reg btb_hit_2;     
//     reg [NUM_WAY-1:0] hit_mask_2;

//     wire ready_go_2;
//     wire out_fire_2 = ic_ret_valid_o & ic_ret_ready_i;
//     wire [INDEX_WIDTH-1:0]  addr_index_2 ;
//     wire [TAG_WIDTH-1:0]    addr_tag_2   ;
//     wire [OFFSET_INDEX-1:0] addr_offset_2;
//     reg [LINE_WIDTH-1:0] selected_line;
//     wire [31:0] line_word [0:WORDS-1];
//     wire [31:0] hit_word;
//     // MISS 时
//     localparam IDLE       = 1'd0;
//     localparam MISS       = 1'd1;
//     reg state;
//     reg [WAY_WIDTH-1:0] replace_way;
//     reg [WAY_WIDTH-1:0] miss_way;
    
//     wire miss;
//     wire [31:0] buf_word [0:WORDS-1];
//     wire [31:0] miss_word;
//     // ==================== 代码实现 =============================
//     // 第一级流水线
//     always @(posedge clk) begin
//         if(reset) begin
//             idle_1 <= 1;
//             // addr_1 <= 0;
//             // prepc_1 <= 0;
//             // taken_1 <= 0;
//             // btb_hit_1 <= 0;
//         end else begin
//             if(ic_flush_i) begin
//                 idle_1 <= 1;                
//             end else if(in_fire_1) begin
//                 idle_1 <= 0;
//                 addr_1 <= ic_req_addr_i;
//                 prepc_1 <= ic_req_prepc_i;
//                 taken_1 <= ic_req_taken_i;
//                 btb_hit_1 <= ic_req_btb_hit_i;
//             end else if(temp_fire) begin
//                 idle_1 <= 1;
//             end
//         end
//     end
//     // 地址decoder
//     assign addr_index_1 = addr_1[OFFSET_WIDTH+INDEX_WIDTH-1:OFFSET_WIDTH];
//     assign addr_tag_1 = addr_1[31:OFFSET_WIDTH+INDEX_WIDTH];
//     // 判断是否命中
//     integer k;
//     always @(*) begin
//         hit_mask_1 = {NUM_WAY{1'b0}};
//         for (k = 0; k < NUM_WAY; k = k + 1) begin
//             if (cache_valid[k][addr_index_1] && (cache_tag[k][addr_index_1] == addr_tag_1))
//                 hit_mask_1[k] = 1'b1;
//         end
//     end
//     assign temp_addr = addr_1;
//     assign temp_prepc = prepc_1;
//     assign temp_taken = taken_1;
//     assign temp_btb_hit = btb_hit_1;
//     assign temp_hit_mask = hit_mask_1;
//     assign ic_req_ready_o = idle_1 || temp_fire;
//     assign temp_valid = !(idle_1 || ic_flush_i);

//     // 第二级流水线
//     always @(posedge clk) begin
//         if(reset) begin
//             idle_2 <= 1;
//             // addr_2 <= 0;
//             // prepc_2 <= 0;
//             // taken_2 <= 0;
//             // btb_hit_2 <= 0;
//             // hit_mask_2 <= 0;
//         end else begin
//             if(ic_flush_i) begin
//                 idle_2 <= 1;
//             end else if(temp_fire) begin
//                 idle_2 <= 0;
//                 addr_2 <= temp_addr;
//                 prepc_2 <= temp_prepc;
//                 taken_2 <= temp_taken;
//                 btb_hit_2 <= temp_btb_hit;
//                 hit_mask_2 <= temp_hit_mask;
//             end else if(out_fire_2) begin
//                 idle_2 <= 1;
//             end
//         end
//     end
//     // 地址decoder
//     assign addr_index_2 = addr_2[OFFSET_WIDTH+INDEX_WIDTH-1:OFFSET_WIDTH];
//     assign addr_tag_2 = addr_2[31:OFFSET_WIDTH+INDEX_WIDTH];
//     assign addr_offset_2 = (OFFSET_WIDTH > 2) ? addr_2[OFFSET_WIDTH-1:2] : 0;
//     // 读data_sram
//     always @(*) begin
//         selected_line = {LINE_WIDTH{1'b0}};
//         for (k = 0; k < NUM_WAY; k = k + 1) begin
//             if (hit_mask_2[k]) selected_line = cache_data[k][addr_index_2];
//         end
//     end
//     generate
//     for (genvar i = 0; i < WORDS; i = i + 1) begin : SPLIT_0
//         assign line_word[i] = selected_line[i*32 +: 32];
//     end
//     endgenerate
//     assign hit_word = line_word[addr_offset_2];
//     // MISS时阻塞逻辑
//     // 命中冲突
//     assign miss = ~(|temp_hit_mask);
//     always @(posedge clk) begin
//         if(reset) begin
//             state <= IDLE;
//             replace_way <= 0;
//             miss_way <= 0;
//         end else begin
//             if(ic_flush_i) begin
//                 if(ic_fencei_i) begin
//                     integer m,n;
//                     for (m = 0; m < NUM_WAY; m = m + 1) begin: FENCEI_LOOP
//                         for (n = 0; n < NUM_SET; n = n + 1) begin
//                             cache_valid[m][n] <= 1'b0;
//                         end
//                     end
//                 end else if(state == MISS) begin
//                     cache_valid[replace_way][addr_index_2] <= 1'b0;
//                 end
//                 state <= IDLE;
//             end else begin
//                 case(state)
//                     IDLE: begin
//                         if(miss & temp_fire) begin
//                             state <= MISS;
//                         end
//                         replace_way <= (NUM_WAY == 1) ? 0 : replace_way + 1;
//                     end
//                     MISS: begin
//                         if(ia_ret_valid_i) begin
//                             cache_data[replace_way][addr_index_2] <= {ia_ret_data_i, cache_data[replace_way][addr_index_2][LINE_WIDTH-1:32]};
//                             if(ia_ret_last_i) begin
//                                 cache_tag[replace_way][addr_index_2] <= addr_tag_2;
//                                 cache_valid[replace_way][addr_index_2] <= 1'b1;
//                                 miss_way <= replace_way;
//                                 state <= IDLE;
//                             end
//                         end
//                     end
//                 endcase    
//             end

//         end
//     end
    
//     generate
//     for (genvar i = 0; i < WORDS; i = i + 1) begin : SPLIT_1
//         assign buf_word[i] = cache_data[miss_way][addr_index_2][i*32 +: 32];
//     end
//     endgenerate
//     assign miss_word = buf_word[addr_offset_2];

//     assign ia_flush_o  = ic_flush_i;
//     assign ia_rd_req_o = (state == MISS);
//     assign ia_rd_addr_o = addr_2;
//     assign ready_go_2 = (state == IDLE);

//     assign ic_ret_rdata_o = |hit_mask_2 ? hit_word : miss_word;
//     assign ic_ret_addr_o = addr_2;
//     assign ic_ret_prepc_o = prepc_2;
//     assign ic_ret_taken_o = taken_2;
//     assign ic_ret_btb_hit_o = btb_hit_2;
//     assign temp_ready = idle_2 || out_fire_2;
//     assign ic_ret_valid_o = !(idle_2 || ic_flush_i) && ready_go_2;

// `ifdef YSYXSOC
//     reg [31:0] mem_type;
//     always @(posedge clk) begin
//         if(reset) begin

//         end else begin
//             if(state == MISS) begin
//                 icache_misscycle(mem_type);
//             end 
//             if(ic_flush_i) begin

//             end else if(temp_fire) begin
//                 if(temp_addr >= 32'ha0000000) begin mem_type <= 32'd2; icache_get(2); if(miss) icache_miss(2); end
//                 else if(temp_addr >= 32'h30000000) begin mem_type <= 32'd1; icache_get(1); if(miss) icache_miss(1); end
//                 else if(temp_addr >= 32'h0f000000) begin mem_type <= 32'd0; icache_get(0); if(miss) icache_miss(0); end
//             end
//         end
//     end

// `endif
// `ifdef verilator
//     reg [79:0] dbg_state;
//     always @(*) begin
//         case (state)
//             IDLE        : dbg_state = "IDLE"      ;
//             MISS        : dbg_state = "MISS"      ;
//             default     : dbg_state = "UNKNOW"    ;
//         endcase
//     end
// `endif    
// endmodule //ysyx_25050136_ICACHE
