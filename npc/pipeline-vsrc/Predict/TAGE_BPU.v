`timescale 1ns/1ps

module TAGE_BPU #(
    parameter NUM_TABLES = 4,
    parameter ENTRY_NUM = 64,
    parameter TAG_WIDTH = 8,
    parameter CNT_WIDTH = 2,
    parameter GHR_WIDTH = 16
)(
    input             clk, reset,
    input      [31:0] if_pc,
    output reg        predict_taken,
    output reg [31:0] predict_target,

    input             ex_bpu_update,
    input      [31:0] ex_bpu_pc,
    input             ex_bpu_taken,
    input      [31:0] ex_bpu_target,
    input             ex_bpu_correct,

    output reg [31:0] correct_predictions,
    output reg [31:0] total_predictions
);

    // 全局历史寄存器
    reg [GHR_WIDTH-1:0] ghr;

    // 表项结构
    typedef struct packed {
        logic [TAG_WIDTH-1:0] tag;
        logic [CNT_WIDTH-1:0] ctr;
        logic [31:0] target;
        logic                valid;
    } tage_entry_t;

    // 每张表不同历史长度
    integer history_lengths[NUM_TABLES-1:0];
    initial begin
        history_lengths[0] = 0;
        history_lengths[1] = 4;
        history_lengths[2] = 8;
        history_lengths[3] = 16;
    end

    // 表结构
    tage_entry_t tables[NUM_TABLES-1:0][ENTRY_NUM-1:0];

    // 索引和tag计算函数
    function [5:0] compute_index(input [31:0] pc, input integer history_len);
        reg [31:0] ghr_ext;
        reg [31:0] temp;
        begin
            ghr_ext = {{(32-GHR_WIDTH){1'b0}}, ghr}; // zero-extend ghr to 32位
            temp = ((pc ^ (ghr_ext >> (GHR_WIDTH - history_len))) % ENTRY_NUM); 
            compute_index = temp[5:0];
        end
    endfunction

    function [TAG_WIDTH-1:0] compute_tag(input [31:0] pc, input integer history_len);
        reg [TAG_WIDTH-1:0] ghr_sel;
        reg [15:0] temp;
        begin
            temp = ghr >> history_len;
            ghr_sel = temp[TAG_WIDTH-1:0];
            compute_tag = pc[15:8] ^ ghr_sel[TAG_WIDTH-1:0];
        end
    endfunction


    // 预测逻辑
    integer i;
    reg [5:0] idx;
    reg hit;
    reg hit_done;
    reg [TAG_WIDTH-1:0] tag;
    reg [CNT_WIDTH-1:0] best_ctr;
    reg [31:0] best_target;

    always @(*) begin
        hit = 0;
        best_ctr = 0;
        best_target = 0;
        predict_taken = 0;

        hit_done = 0;
        for (i = NUM_TABLES-1; i >= 0; i = i - 1) begin
            if (!hit_done) begin
                idx = compute_index(if_pc, history_lengths[i]);
                tag = compute_tag(if_pc, history_lengths[i]);
                if (tables[i][idx].valid && tables[i][idx].tag == tag) begin
                    best_ctr = tables[i][idx].ctr;
                    best_target = tables[i][idx].target;
                    hit = 1;
                    hit_done = 1; // 标志命中，后续循环跳过
                end
            end
        end


        predict_taken = (best_ctr[CNT_WIDTH-1] == 1); // 高位为1表示Taken
        predict_target = hit ? best_target : if_pc + 4; // 默认顺序执行
    end

    // 更新逻辑
    reg update_done;
    always @(posedge clk) begin
        if (reset) begin
            correct_predictions <= 0;
            total_predictions <= 0;
            ghr <= 0;
        end else begin
            if (ex_bpu_update) begin
                total_predictions <= total_predictions + 1;
                if (ex_bpu_correct)
                    correct_predictions <= correct_predictions + 1;

                // GHR 更新
                ghr <= {ghr[GHR_WIDTH-2:0], ex_bpu_taken};

                // 寻找是否命中，更新计数器
               
                update_done = 0;
                for (i = NUM_TABLES-1; i >= 0; i = i - 1) begin
                    if (!update_done) begin
                        idx = compute_index(ex_bpu_pc, history_lengths[i]);
                        tag = compute_tag(ex_bpu_pc, history_lengths[i]);
                        if (tables[i][idx].valid && tables[i][idx].tag == tag) begin
                            if (ex_bpu_taken && tables[i][idx].ctr != {CNT_WIDTH{1'b1}})
                                tables[i][idx].ctr <= tables[i][idx].ctr + 1;
                            else if (!ex_bpu_taken && tables[i][idx].ctr != 0)
                                tables[i][idx].ctr <= tables[i][idx].ctr - 1;
                            update_done = 1; // 命中一次即停止后续匹配
                        end
                    end
                end

                // 若未命中则分配新表项（简化分配策略）
                if (!hit) begin
                    idx = compute_index(ex_bpu_pc, history_lengths[0]);
                    tables[0][idx].valid <= 1;
                    tables[0][idx].tag <= compute_tag(ex_bpu_pc, history_lengths[0]);
                    tables[0][idx].ctr <= ex_bpu_taken ? 2'b10 : 2'b01;
                    tables[0][idx].target <= ex_bpu_target;
                end
            end
        end
    end

endmodule
