`timescale 1ns/1ns

module Local_BPU (
    input             clk,
    input             reset,
    input      [31:0] if_pc,              // 当前取指PC
    output reg        predict_taken,      // 预测是否跳转
    output reg [31:0] predict_target,     // 预测目标地址

    input             ex_bpu_update,      // EX阶段更新信号
    input      [31:0] ex_bpu_pc,          // EX阶段分支指令的PC
    input             ex_bpu_taken,       // EX阶段实际跳转结果
    input      [31:0] ex_bpu_target,      // EX阶段实际目标地址
    input             ex_bpu_correct,
    output reg [31:0] correct_predictions,
    output reg [31:0] total_predictions
);
    localparam BHT_INDEX_BITS = 10;       // BHT索引位数 (1024项)
    localparam BHR_BITS = 10;             // BHR历史记录位数
    
    localparam PHT_INDEX_BITS = 10;       // PHT索引位数 (1024项)
    
    reg [BHR_BITS-1:0] bht [0:(1<<BHT_INDEX_BITS)-1]; // BHT表：存储分支历史寄存器(BHR)
    
    reg [1:0] pht [0:(1<<PHT_INDEX_BITS)-1];          // PHT表：存储饱和计数器
    
    reg [31:0] btb [0:(1<<BHT_INDEX_BITS)-1];         // BTB表：存储目标地址

    reg valid [0:(1<<BHT_INDEX_BITS)-1]; // BTB有效位
    
    integer i;
    initial begin
        for (i = 0; i < (1<<BHT_INDEX_BITS); i = i + 1) begin
            bht[i] = {BHR_BITS{1'b0}};    
            pht[i] = 2'b10;               
            btb[i] = 32'h8000_0000 + (i << 2); // 初始化BTB为默认地址 
            valid[i] = 1'b0; // 初始化BTB的有效位
        end
    end

    reg [BHT_INDEX_BITS-1:0] bht_index;
    reg [BHR_BITS-1:0] bhr;
    reg [PHT_INDEX_BITS-1:0] pht_index;
    reg [1:0] sat_counter;

    // 预测逻辑
    always @(*) begin
        // BHT索引：PC的哈希处理
        bht_index = if_pc[BHT_INDEX_BITS+1:2];    // 使用PC[11:2]
        
        // 获取BHR
        bhr = bht[bht_index];
        
        // PHT索引：BHR与PC部分位的异或
        pht_index = bhr ^ if_pc[PHT_INDEX_BITS+1:2];
        
        // 获取饱和计数器状态
        sat_counter = pht[pht_index];
        
        // 预测跳转（高位为1）
        predict_taken = sat_counter[1] && valid[bht_index]; // 仅当BTB有效时才预测跳转
        
        // 预测目标地址
        predict_target = valid[bht_index] ? btb[bht_index] : (if_pc + 4); // 如果BTB有效，则使用BTB，否则使用PC+4
        // predict_target = predict_taken ? btb[bht_index] : (if_pc + 4); // 如果预测跳转，则使用BTB，否则使用PC+4
        // $display("[BTB] predict_target=%h predict_taken=%b", btb[bht_index], predict_taken);
    end
    
    reg [BHT_INDEX_BITS-1:0] ex_bht_index;
    reg [BHT_INDEX_BITS-1:0] ex_pht_index;
    reg [BHR_BITS-1:0] current_bhr;

    // 更新逻辑
    always @(posedge clk) begin
        if (reset) begin
            // 复位初始化
            for (i = 0; i < (1<<BHT_INDEX_BITS); i = i + 1) begin
                bht[i] = {BHR_BITS{1'b0}};
                pht[i] = 2'b10;
                btb[i] = 32'h8000_0000 + (i << 2); // 初始化BTB为默认地址
                valid[i] = 1'b0; // 初始化BTB的有效位
            end
            correct_predictions <= 0;
            total_predictions <= 0;
        end
        else if (ex_bpu_update) begin
            total_predictions <= total_predictions + 1;
            if(ex_bpu_correct) correct_predictions <= correct_predictions + 1;
            // 计算BHT索引
            ex_bht_index = ex_bpu_pc[BHT_INDEX_BITS+1:2];
            
            // 获取当前BHR
            current_bhr = bht[ex_bht_index];
            
            // 计算PHT索引
            ex_pht_index = current_bhr ^ ex_bpu_pc[PHT_INDEX_BITS+1:2];
            
            // 更新PHT（饱和计数器）
            if (ex_bpu_taken) begin
                if (pht[ex_pht_index] < 2'b11) 
                    pht[ex_pht_index] <= pht[ex_pht_index] + 1;
            end else begin
                if (pht[ex_pht_index] > 2'b00) 
                    pht[ex_pht_index] <= pht[ex_pht_index] - 1;
            end
            
            // 更新BHR：移位新结果
            bht[ex_bht_index] <= {current_bhr[BHR_BITS-2:0], ex_bpu_taken};
            
            // 更新BTB：仅当实际跳转时更新目标地址
            // if (ex_bpu_taken) begin
            //     btb[ex_bht_index] <= ex_bpu_target;
            //     valid[ex_bht_index] <= 1'b1; // 标记BTB条目为有效
            // end
            valid[ex_bht_index] <= ex_bpu_taken;
            btb[ex_bht_index] <= ex_bpu_taken ? ex_bpu_target : (ex_bpu_pc + 4);
        end
    end
endmodule