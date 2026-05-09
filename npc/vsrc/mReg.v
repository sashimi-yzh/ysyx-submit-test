`include "npc_config.vh"

module ysyx_25040102_mReg (
    input           clk,
    input           mret,
    input           mcause_wr, // ecall
    input   [3:0]   mcause,

    input   [7:0]   imm,
    input   [31:0]  pc,
    input           mRegwr, // 写使能
    input   [31:0]  wrData, // write this mreg
    input           mcause_pc,

    output  [31:0]  mretPc,
    output          mpcWr,
    output  [31:0]  mRegData // to reg
    // output  [31:0]  mWr_Data  // to mReg
);

    reg     [3:0]   mcause_r;
    reg     [31:0]  mepc_r;
    reg     [31:0]  mstatus_r;
    reg     [31:0]  mtvec_r;

    reg     [31:0]  mRegData_r;
    reg     [31:0]  mretPc_r;
    reg             mpcWr_r;
    wire    [31:0]  mvendorid;
    wire    [31:0]  marchid;

    assign  mRegData        = mRegData_r;
    assign  mretPc          = mretPc_r;
    assign  mpcWr           = mpcWr_r;

    assign  mvendorid       = 32'h79737978;
    assign  marchid         = 32'h017e14e6;

    // read
    always @(*) begin // 给通用寄存器
        case (imm)
            8'h41: mRegData_r = mepc_r;
            8'h42: mRegData_r = {28'h0, mcause_r};
            8'h00: mRegData_r = mstatus_r;
            8'h05: mRegData_r = mtvec_r;
            8'h11: mRegData_r = mvendorid;
            8'h12: mRegData_r = marchid;
            default: mRegData_r = 32'h00;
        endcase
    end

    // mcause_r
    always @(posedge clk) begin
        if(mcause_wr == 1'b1) begin
            mcause_r    <= mcause;
        end
        else if(mRegwr == 1'b1 && imm == 8'h42) begin
            mcause_r    <= wrData[3:0];
        end
    end

    // mepc_r
    always @(posedge clk) begin
        if(mcause_wr == 1'b1) begin
            mepc_r    <= pc;
        end
        else if(mRegwr == 1'b1 && imm == 8'h41) begin
            mepc_r    <= wrData;
        end
    end

    // mtvec_r
    always @(posedge clk) begin
        if(mRegwr == 1'b1 && imm == 8'h05) begin
            mtvec_r     <= wrData;
        end
    end

    // mstatus_r
    always @(posedge clk) begin
        if(mRegwr == 1'b1 && imm == 8'h00) begin
            mstatus_r   <= wrData;
        end
    end

    // // read next_pc
    always @(*) begin // mretPc_r
        if(mret == 1'b1) begin       // mret
            mretPc_r = mepc_r;
            mpcWr_r = 1'b1;
        end
        else if(mcause_pc == 1'b1) begin  // ecall
            mretPc_r = mtvec_r;
            mpcWr_r = 1'b1;
        end
        else begin
            mretPc_r = 32'h00000000;
            mpcWr_r = 1'b0;
        end
    end

endmodule
