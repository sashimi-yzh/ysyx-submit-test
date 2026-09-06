8 4; module icache_smt_test(
    input clk,
    input rst,
    input [4:0]block
);
    // Test parameters
    parameter MEM_SIZE = 128;  // bytes
    parameter MEM_DEPTH = MEM_SIZE / 4;  // 32 words

    wire req_addr = block << 2;

    // Shared memory model (used by both DUT and REF)
    reg [31:0] mem [0:MEM_DEPTH-1];

    // DUT instance - icache
    wire dut_hit;
    wire [31:0] dut_data_r;
    // 屏蔽写操作：写使能信号始终为0
    wire dut_w_valid = 1'b0;
    wire [31:0] dut_w_data = 32'h0;

    // TODO add the axi module make it fit to the pattern of 
    // the npc
    ysyx_24100007_icache #(
        .INDEX_LEN(3),
        .OFFSET_LEN(2)
    ) dut (
        .clk(clk),
        .rst(rst),
        .addr(req_addr),
        .w_valid(dut_w_valid),  // 始终为0，屏蔽写操作
        .w_data(dut_w_data),     // 始终为0
        .hit(dut_hit),
        .data_r(dut_data_r)
    );

    // REF: 直接从mem中读出数据（无延迟）
    wire [31:0] ref_data;
    assign ref_data = mem[req_addr];  // 地址对齐到字边界

    always @(*) begin
        c_assert: assert(ref_data == dut_data_r);
    end

endmodule