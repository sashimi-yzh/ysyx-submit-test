module addr_decoder #(
    parameter ADDR_WIDTH = 32,
    parameter NUM_SLAVES = 2,
    parameter [(NUM_SLAVES*ADDR_WIDTH)-1:0] BASE_ADDR = {32'h80000000, 32'ha00003f8},
    parameter [(NUM_SLAVES*ADDR_WIDTH)-1:0] ADDR_MASK = {32'hF8000000, 32'hFFFFFFF8}
)(
    input [ADDR_WIDTH-1:0] addr,
    output reg [NUM_SLAVES-1:0] slave_select,
    output reg error
);

// 提取基地址和地址掩码
wire [ADDR_WIDTH-1:0] base_addr [0:NUM_SLAVES-1];
wire [ADDR_WIDTH-1:0] addr_mask [0:NUM_SLAVES-1];

generate
    genvar i;
    for (i = 0; i < NUM_SLAVES; i = i + 1) begin 
        assign base_addr[i] = BASE_ADDR[i*ADDR_WIDTH +: ADDR_WIDTH];
        assign addr_mask[i] = ADDR_MASK[i*ADDR_WIDTH +: ADDR_WIDTH];
    end
endgenerate

// 地址译码逻辑
reg flag;
integer j;
always @(*) begin
    slave_select = {NUM_SLAVES{1'b0}};
    error = 1'b0;
    flag = 1'b0;
    for (j = 0; j < NUM_SLAVES; j = j + 1) begin
        if(!flag) begin
            if ((addr & addr_mask[j]) == base_addr[j]) begin
                slave_select[j] = 1'b1;
                flag = 1'b1;
            end
        end
    end
    if(slave_select == {NUM_SLAVES{1'b0}})begin
    // 没有匹配的地址范围
        error = 1'b1;
    end
end

endmodule
