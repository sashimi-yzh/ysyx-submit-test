module FormalTop (
    input clk,
    input reset
);
    // DUT输入
    reg         req_valid;
    reg [31:0]  req_pc;

    wire        dut_ready;
    wire [31:0] dut_data;

    wire [31:0] ref_data;

    // DUT
    icache #(
        .BLOCK_WIDTH(2),
        .INDEX_WIDTH(4)
    ) dut (
        .clock(clk),
        .reset(reset),
        .ifu_icache_valid(req_valid),
        .ifu_icache_pc(req_pc),
        .icache_ifu_ready(dut_ready),
        .icache_ifu_data(dut_data),

        // AXI channel 模拟阻塞
        .Xbar_icache_ar_ready(1'b1),
        .Xbar_icache_r_valid(1'b1),
        .Xbar_icache_r_data(ref_data), // REF数据作为主存数据
        .Xbar_icache_r_resp(2'b00),
        .Xbar_icache_r_last(1'b1),
        .Xbar_icache_r_id(4'd0),

        // unused AXI写接口
        .Xbar_icache_aw_ready(1'b0),
        .Xbar_icache_w_ready(1'b0),
        .Xbar_icache_b_valid(1'b0),
        .Xbar_icache_b_resp(2'b00),
        .Xbar_icache_b_id(4'd0),
        .icache_Xbar_ar_valid(),
        .icache_Xbar_ar_addr(),
        .icache_Xbar_ar_id(),
        .icache_Xbar_ar_len(),
        .icache_Xbar_ar_size(),
        .icache_Xbar_ar_burst(),
        .icache_Xbar_r_ready(),
        .icache_Xbar_aw_valid(),
        .icache_Xbar_aw_addr(),
        .icache_Xbar_aw_id(),
        .icache_Xbar_aw_len(),
        .icache_Xbar_aw_size(),
        .icache_Xbar_aw_burst(),
        .icache_Xbar_w_valid(),
        .icache_Xbar_w_data(),
        .icache_Xbar_w_strb(),
        .icache_Xbar_w_last(),
        .icache_Xbar_b_ready()
    );

    // REF
    reg ref_en;
    FormalMem mem (
        .clk(clk),
        .en(ref_en),
        .addr(req_pc),
        .rdata(ref_data)
    );

    // 请求序列控制
    reg [2:0] state;
    localparam S_IDLE = 0, S_REQ = 1, S_WAIT = 2, S_CHECK = 3;

    reg [31:0] last_pc;
    reg [31:0] last_ref_data;

    always @(posedge clk) begin
        if (reset) begin
            state <= S_IDLE;
            req_valid <= 0;
            ref_en <= 0;
            last_ref_data <= 0;
        end else begin
            case (state)
                S_IDLE: begin
                    // 产生一个新的请求
                    req_pc <= $anyconst;  // 任意地址
                    req_valid <= 1;
                    ref_en <= 1;
                    state <= S_REQ;
                end
                S_REQ: begin
                    req_valid <= 0;
                    ref_en <= 0;
                    last_pc <= req_pc;
                    last_ref_data <= ref_data;
                    state <= S_WAIT;
                end
                S_WAIT: begin
                    if (dut_ready) begin
                        state <= S_CHECK;
                    end
                end
                S_CHECK: begin
                    assert(dut_data == last_ref_data);
                    state <= S_IDLE;
                end
            endcase
        end
    end

endmodule
