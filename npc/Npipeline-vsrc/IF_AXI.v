`timescale 1ns/1ns
`include "/home/furina/ysyx-workbench/npc/Npipeline-vsrc/defines/defines.v"

// 取指模块
module IF_AXI (
    input             clk,
    input             reset,

    input             EX_flush,
    input      [31:0] EX_flush_pc,

    input             ID_ready,
    output reg        IF_valid,

    output reg [31:0] IF_ID_pc,
    output reg [31:0] IF_ID_inst,

    // AXI4-Lite 接口信号（与 SRAM 连接）
    output reg        if_sram_arvalid,       // 读地址有效
    input             sram_if_arready,       // 读地址就绪
    output reg [31:0] if_sram_araddr,        // 读地址
    input      [31:0] sram_if_rdata,         // 读数据
    input             sram_if_rvalid,        // 读数据有效
    output reg        if_sram_rready,        // 读数据就绪
    input      [1:0]  sram_if_rresp,         // 读响应

    output reg [31:0] ifu_active_cycles
);

    import "DPI-C" function void ebreak(input int station, input int inst);
    import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);

    reg [1:0] state;
    localparam IDLE = 2'b00;
    localparam AR_WAIT = 2'b01;
    localparam R_WAIT  = 2'b10;

    reg [31:0] next_pc;
    reg once;
    reg flush_reg, flush_once;
    reg [31:0] flush_pc_reg;

    always @(posedge clk) begin
        if (reset) begin
            ifu_active_cycles <= 0;
        end else if (state == AR_WAIT || state == R_WAIT) begin
            ifu_active_cycles <= ifu_active_cycles + 1;
        end
    end

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            IF_ID_pc <= 32'h8000_0000;
            next_pc  <= 32'h8000_0000;
            if_sram_arvalid  <= 0;
            if_sram_araddr   <= 0;
            if_sram_rready   <= 0;
            IF_ID_inst <= 0;
            IF_valid <= 0;
            state    <= IDLE;
            once <= 1;
        end
        else begin
            if (EX_flush) begin
                IF_valid <= 0;
                next_pc <= EX_flush_pc;
                if_sram_arvalid <= 1;
                if_sram_araddr  <= EX_flush_pc;
                if_sram_rready <= 1;      
                state <= AR_WAIT;      
            end
            case (state)
                IDLE: begin
                    // // IF_valid <= 0;
                    // if (EX_flush || flush_reg) begin
                    //     IF_valid <= 0;
                    //     next_pc <= flush_reg ? flush_pc_reg : EX_flush_pc;
                    //     if_sram_arvalid <= 1;
                    //     if_sram_araddr  <= flush_reg ? flush_pc_reg : EX_flush_pc;
                    //     // IF_ID_inst <= 32'h0;
                    //     // IF_valid <= ID_ready;
                    //     state   <= AR_WAIT;
                    // end
                    // else 
                    if ((IF_valid && ID_ready) || once) begin
                        once <= 0;
                        IF_valid <= 0;
                        if_sram_arvalid <= 1;
                        if_sram_araddr  <= next_pc;
                        state   <= AR_WAIT;
                    end
                end

                AR_WAIT: begin
                    if (sram_if_arready && if_sram_arvalid) begin
                        if_sram_arvalid <= 0;
                        if_sram_rready  <= 1;
                        IF_valid <= 0;
                        state   <= R_WAIT;
                    end
                end

                R_WAIT: begin
                    if (sram_if_rvalid && if_sram_rready) begin
                        if_sram_rready <= 0;
                        IF_ID_inst <= sram_if_rdata;
                        IF_ID_pc   <= next_pc;
                        IF_valid   <= (EX_flush) ? 0 : 1;
                        next_pc    <= (EX_flush) ? EX_flush_pc : next_pc + 4;
                        state      <= IDLE;

                        counter(7, 1, 0, 0);
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule
