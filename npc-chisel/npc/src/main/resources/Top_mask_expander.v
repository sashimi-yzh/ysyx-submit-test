module Top_mask_expander #(parameter DATA_WIDTH = 32) (
    input [DATA_WIDTH/8-1:0] mask,
    output [DATA_WIDTH-1:0] mask_wide
);

function [DATA_WIDTH-1:0] expand_mask;
    input [DATA_WIDTH/8-1:0] mask_in;
    integer i;
    begin
        for (i = 0; i < DATA_WIDTH/8; i = i+1) begin
            expand_mask[i*8 +: 8] = {8{mask_in[i]}}; // 每个掩码位扩展为8比特
        end
    end
endfunction

assign mask_wide = expand_mask(mask); // 调用函数

endmodule