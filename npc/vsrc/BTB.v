module BTB
#(
    parameter ENTRY_NUM = 8
)(
    input clk,
    input reset,

    input [31:0] PC_r,

    input [31:0] PC_w,
    input [31:0] target,
    input [1:0] meta_data, //bit1 for branch/jump, bit0 for taken/not taken
    input write_en,

    output reg [31:0] target_BTB,
    output reg [1:0] meta_data_BTB,
    output reg hit_BTB
);

    reg [31:0] PC_reg [ENTRY_NUM-1:0];
    reg [31:0] target_reg [ENTRY_NUM-1:0];
    reg [1:0] meta_data_reg [ENTRY_NUM-1:0];

    reg [$clog2(ENTRY_NUM)-1:0] wptr;

    always @(posedge clk) begin
        if(reset) begin
            for(integer i = 0; i < ENTRY_NUM; i = i + 1) begin
                PC_reg[i] <= 32'b0;
                target_reg[i] <= 32'b0;
                meta_data_reg[i] <= 2'b0;
            end

            wptr <= {$clog2(ENTRY_NUM){1'b0}};
        end
        else if(write_en) begin
            PC_reg[wptr] <= PC_w;
            target_reg[wptr] <= target;
            meta_data_reg[wptr] <= meta_data;
            wptr <= wptr + 1;
        end
    end

    always @(*) begin
        hit_BTB = 1'b0;
        target_BTB = 32'b0;
        meta_data_BTB = 2'b0;
        for(integer i = 0; i < ENTRY_NUM; i = i + 1) begin
            if(PC_reg[i] == PC_r) begin
                hit_BTB = 1'b1;
                target_BTB = target_reg[i];
                meta_data_BTB = meta_data_reg[i];
            end
        end
    end

endmodule
