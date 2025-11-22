`timescale 1ns/1ps

module fpu_tb (
    input clk,
    input reset,
    // fregs 控制信号
    input [4:0] freg_rs1,
    input [4:0] freg_rs2,
    input [4:0] freg_rd,
    input [31:0] freg_write_data,
    input freg_write_en,
    output [31:0] freg_read_data1,
    output [31:0] freg_read_data2,
    // FPU 控制信号
    input fpu_op_valid,
    input [5:0] fpu_op_type,
    input [2:0] fpu_op_round,
    input [31:0] operand1_fp,
    input [31:0] operand2_fp,
    input [31:0] operand3_fp,
    input [31:0] operand4_int,
    input downstream_valid,
    output fpu_ready,
    output [31:0] fpu_result,
    output [31:0] int_result,
    output [4:0] exception_flags,
    output fpu_result_valid
);

    // 实例化 fregs
    fregs freg_inst (
        .clk(clk),
        .reset(reset),
        .rs1(freg_rs1),
        .rs2(freg_rs2),
        .rd(freg_rd),
        .write_data(freg_write_data),
        .write_en(freg_write_en),
        .read_data1(freg_read_data1),
        .read_data2(freg_read_data2)
    );

    // 实例化 FPU
    fpu fpu_inst (
        .clk(clk),
        .reset(reset),
        .flush(1'b0),
        .fpu_op_valid(fpu_op_valid),
        .fpu_op_type(fpu_op_type),
        .fpu_op_round(fpu_op_round),
        .operand1_fp(operand1_fp),
        .operand2_fp(operand2_fp),
        .operand3_fp(operand3_fp),
        .operand4_int(operand4_int),
        .fpu_ready(fpu_ready),
        .downstream_valid(downstream_valid),
        .fpu_result(fpu_result),
        .int_result(int_result),
        .exception_flags(exception_flags),
        .fpu_result_valid(fpu_result_valid)
    );

   
endmodule
