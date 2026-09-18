module ysyx_26010027_WBU (
    input             clock,
    input             reset,

    input      [ 3:0] exu_wbu_raddr1, exu_wbu_raddr2, 
    input      [ 1:0] lsu_wbu_rf_res, // reg 的 wdata 选择

    output     [31:0] wbu_exu_rdata1,
    output     [31:0] wbu_exu_rdata2,
    output     [31:0] wbu_exu_csr_rdata,
    output     [31:0] csr_mtvec,
    output     [31:0] csr_mepc,

    input             lsu_wbu_valid,
    output            wbu_lsu_ready,
    input      [31:0] lsu_wbu_pc,
    input      [31:0] lsu_wbu_snpc,
    input             lsu_wbu_reg_w,
    input      [ 3:0] lsu_wbu_waddr,
    input      [31:0] lsu_wbu_alu_result,
    input      [31:0] lsu_wbu_mem_result,

    input      [11:0] csr_raddr,
    input      [11:0] csr_waddr,
    input      [31:0] csr_wdata,
    input             csr_we,
    input             csr_ecall,
    input             csr_mret

);

    wire [31:0] wdata;
    wire [ 3:0] waddr;

    assign wdata = (lsu_wbu_rf_res == 2'b00 | lsu_wbu_rf_res == 2'b10) ? lsu_wbu_alu_result : // ALU | CSR
                   (lsu_wbu_rf_res == 2'b01) ? lsu_wbu_mem_result : // MEM
                   lsu_wbu_snpc; // SNPC
    assign waddr = lsu_wbu_waddr;
    assign wbu_lsu_ready = lsu_wbu_valid;

    ysyx_26010027_GPR my_gpr (
        .clock (clock),
        .reset (reset),
        .waddr (waddr),
        .wdata (wdata),
        .wen   (lsu_wbu_reg_w),

        .raddr1(exu_wbu_raddr1),
        .raddr2(exu_wbu_raddr2),
        .rdata1(wbu_exu_rdata1),
        .rdata2(wbu_exu_rdata2)
    );

    ysyx_26010027_CSR my_csr (
        .clock       (clock),
        .reset       (reset),
        .csr_ecall   (csr_ecall),
        .csr_mret    (csr_mret),
        .csr_raddr   (csr_raddr),
        .csr_waddr   (csr_waddr),
        .csr_wdata   (csr_wdata),
        .csr_rdata   (wbu_exu_csr_rdata),
        .csr_mtvec   (csr_mtvec),
        .csr_mepc    (csr_mepc),
        .pc          (lsu_wbu_pc),
        .csr_we      (csr_we)

    );

endmodule
