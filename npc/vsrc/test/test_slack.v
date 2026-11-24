module regfile_read_top (
    input clock,
    input rst_n, // 增加复位，尽管 DUT 没用，但有利于 STA 同步
    input [31:0] raw_input_bus, // 用一个宽总线引入随机源
    output [31:0] final_check_sum  // 压缩后的输出
);

    localparam AW = 5; 
    localparam DW = 32;

    reg [255:0] noise_reg;
    always @(posedge clock) noise_reg <= {noise_reg[223:0], raw_input_bus};

    wire [DW-1:0] rd1, rd2, rdx;
    wire done;

    ysyx_24110012_RegisterFile #(
        .ADDR_WIDTH(AW),
        .DATA_WIDTH(DW),
        .MASTER_INDEX_WIDTH(1)
    ) dut (
        .clk(clock),
        .waddr(noise_reg[4:0]),
        .w_from_exu(noise_reg[31:0]),
        .w_from_mem(noise_reg[63:32]),
        .w_from_csr(noise_reg[95:64]),
        .wen(noise_reg[96]),
        .wb_sel(noise_reg[97]),
        .csr_wen(noise_reg[98]),
        .io_r_done(noise_reg[99]),
        .rs1_idx(noise_reg[105:101]),
        .rs2_idx(noise_reg[110:106]),
        .rs1(rd1),
        .rs2(rd2),
        .rdata_x(rdx),
        .reg_done(done)
    );

    // --- 关键：防止输出被优化掉 ---
    reg [DW-1:0] q_rd;
    always @(posedge clock) begin
        // 将所有输出混合，确保 STA 必须分析每一根地址线和数据线
        q_rd <= rd1 ^ rd2 ^ rdx ^ {31'b0, done};
    end

    assign final_check_sum = q_rd;

endmodule

module adder_top (
    input clock,
    input [31:0] raw_a,
    input [31:0] raw_b,
    output reg [31:0] q_sum,
    output reg q_carry
);

    // --- 输入触发器层 (Launch Path) ---
    reg [31:0] a_reg;
    reg [31:0] b_reg;

    always @(posedge clock) begin
        a_reg <= raw_a;
        b_reg <= raw_b;
    end

    // --- 实例化待测加法器 (DUT) ---
    wire [31:0] w_sum;
    wire w_carry;

    adder dut (
        .a(a_reg),
        .b(b_reg),
        .sum(w_sum),
        .carry(w_carry)
    );

    // --- 输出触发器层 (Capture Path) ---
    always @(posedge clock) begin
        q_sum   <= w_sum;
        q_carry <= w_carry;
    end

endmodule