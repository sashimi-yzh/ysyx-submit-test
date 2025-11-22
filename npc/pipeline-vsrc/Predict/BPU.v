`timescale 1ns/1ns

module BPU (
    input             clk,
    input             reset,
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
    localparam BHT_INDEX_BITS = 10;
    localparam BHR_BITS = 10;
    localparam PHT_INDEX_BITS = 10;

    localparam RE_CPHT = 2'b01;
    localparam RE_LOCAL = 2'b10;
    localparam RE_GLOBAL = 2'b10;

    reg [1:0] cpht [0:(1<<BHT_INDEX_BITS)-1];
    reg [BHR_BITS-1:0] local_bht [0:(1<<BHT_INDEX_BITS)-1];
    reg [1:0] local_pht [0:(1<<PHT_INDEX_BITS)-1];
    reg [BHR_BITS-1:0] global_bhr;
    reg [1:0] global_pht [0:(1<<PHT_INDEX_BITS)-1];
    reg [31:0] btb [0:(1<<BHT_INDEX_BITS)-1];
    reg valid [0:(1<<BHT_INDEX_BITS)-1];

    integer i;
    initial begin
        for (i = 0; i < (1<<BHT_INDEX_BITS); i = i + 1) begin
            cpht[i] = RE_CPHT;
            local_bht[i] = {BHR_BITS{1'b0}};
            btb[i] = 32'h8000_0000 + (i << 2);
            valid[i] = 1'b0;
        end
        for (i = 0; i < (1<<PHT_INDEX_BITS); i = i + 1) begin
            local_pht[i] = RE_LOCAL;
            global_pht[i] = RE_GLOBAL;
        end
        global_bhr = 0;
        correct_predictions = 0;
        total_predictions = 0;
    end

    reg [BHT_INDEX_BITS-1:0] bht_index;
    reg [PHT_INDEX_BITS-1:0] local_pht_index, global_pht_index;
    reg local_predict, global_predict;

    always @(*) begin
        bht_index = if_pc[BHT_INDEX_BITS+1:2];
        local_pht_index = local_bht[bht_index] ^ if_pc[PHT_INDEX_BITS+1:2];
        global_pht_index = global_bhr ^ if_pc[PHT_INDEX_BITS+1:2];

        local_predict = local_pht[local_pht_index][1];
        global_predict = global_pht[global_pht_index][1];

        if (cpht[bht_index] < 2'b10)
            predict_taken = local_predict && valid[bht_index];
        else
            predict_taken = global_predict && valid[bht_index];

        predict_target = valid[bht_index] ? btb[bht_index] : (if_pc + 4);
    end

    reg [BHT_INDEX_BITS-1:0] ex_bht_index;
    reg [PHT_INDEX_BITS-1:0] ex_local_pht_index, ex_global_pht_index;
    reg local_correct, global_correct;

    always @(posedge clk) begin
        if (reset) begin
            for (i = 0; i < (1<<BHT_INDEX_BITS); i = i + 1) begin
                cpht[i] = RE_CPHT;
                local_bht[i] = 0;
                btb[i] = 32'h8000_0000 + (i << 2);
                valid[i] = 1'b0;
            end
            for (i = 0; i < (1<<PHT_INDEX_BITS); i = i + 1) begin
                local_pht[i] = RE_LOCAL;
                global_pht[i] = RE_GLOBAL;
            end
            global_bhr <= 0;
            correct_predictions <= 0;
            total_predictions <= 0;
        end
        else if (ex_bpu_update) begin
            total_predictions <= total_predictions + 1;
            if (ex_bpu_correct)
                correct_predictions <= correct_predictions + 1;

            ex_bht_index = ex_bpu_pc[BHT_INDEX_BITS+1:2];
            ex_local_pht_index = local_bht[ex_bht_index] ^ ex_bpu_pc[PHT_INDEX_BITS+1:2];
            ex_global_pht_index = global_bhr ^ ex_bpu_pc[PHT_INDEX_BITS+1:2];

            local_correct = (local_pht[ex_local_pht_index][1] == ex_bpu_taken);
            global_correct = (global_pht[ex_global_pht_index][1] == ex_bpu_taken);

            // 替代 CPHT 更新策略：基于预测正确性而非失败计数
            if (local_correct && !global_correct && cpht[ex_bht_index] > 2'b00)
                cpht[ex_bht_index] <= cpht[ex_bht_index] - 1;
            else if (!local_correct && global_correct && cpht[ex_bht_index] < 2'b11)
                cpht[ex_bht_index] <= cpht[ex_bht_index] + 1;

            // 更新局部预测器
            if (ex_bpu_taken && local_pht[ex_local_pht_index] < 2'b11)
                local_pht[ex_local_pht_index] <= local_pht[ex_local_pht_index] + 1;
            else if (!ex_bpu_taken && local_pht[ex_local_pht_index] > 2'b00)
                local_pht[ex_local_pht_index] <= local_pht[ex_local_pht_index] - 1;

            local_bht[ex_bht_index] <= {local_bht[ex_bht_index][BHR_BITS-2:0], ex_bpu_taken};

            // 更新全局预测器
            if (ex_bpu_taken && global_pht[ex_global_pht_index] < 2'b11)
                global_pht[ex_global_pht_index] <= global_pht[ex_global_pht_index] + 1;
            else if (!ex_bpu_taken && global_pht[ex_global_pht_index] > 2'b00)
                global_pht[ex_global_pht_index] <= global_pht[ex_global_pht_index] - 1;

            global_bhr <= {global_bhr[BHR_BITS-2:0], ex_bpu_taken};

            // 只在跳转时更新 BTB
            if (ex_bpu_taken) begin
                btb[ex_bht_index] <= ex_bpu_target;
                valid[ex_bht_index] <= 1'b1;
            end
            // btb[ex_bht_index] <= ex_bpu_taken ? ex_bpu_target : (ex_bpu_pc + 4);
            // valid[ex_bht_index] <= 1'b1;
        end
    end
endmodule
