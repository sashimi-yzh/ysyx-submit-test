`include "/home/furina/ysyx-workbench/npc/minirv-vsrc/defines.v"
module rv32e (
    input         clk,
    input         reset
);

    wire [31:0]  pc;
    wire [31:0]  instr;
    wire [6:0]   opcode;
    wire [4:0]   rs1, rs2, rd;
    wire [31:0]  imm;
    wire [2:0]   func3;
    wire [6:0]   func7;
    wire         RegWrite;
    wire         MemWrite;
    wire         MemRead;
    wire [31:0]  rs1_val, rs2_val;
    wire [31:0]  wb_data;
    wire [31:0]  jalr_target;
    wire         is_jalr;
    wire [31:0]  data_out;
    wire [3:0]   alu_op;
    wire [31:0]  alu_result;
    wire         take_branch;
    wire [2:0]   MemLen;

    wire [31:0] branch_target;
    assign branch_target = jalr_target;

    // 取指模块
    IF if_stage (
        .clk(clk),
        .reset(reset),
        .branch_target(branch_target),
        .pc_src(is_jalr),
        .pc(pc),
        .instr(instr)
    );

    // 译码模块
    ID id_stage (
        .instr(instr),
        .opcode(opcode),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .imm(imm),
        .func3(func3),
        .func7(func7),
        .RegWrite(RegWrite),
        .MemWrite(MemWrite),
        .MemRead(MemRead),
        .alu_op(alu_op),
        .MemLen(MemLen)
    );

    // 寄存器文件
    RegFile regfile (
        .clk(clk),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .we(RegWrite),
        .wd(wb_data),
        .rs1_val(rs1_val),
        .rs2_val(rs2_val)
    );

    // ALU模块
    ALU alu (
        .alu_op(alu_op),
        .a(rs1_val),
        .b((opcode[6:2] == `INST_TYPE_R) ? rs2_val : imm), 
        .result(alu_result)
    );

    // 内存访问模块
    MEM mem_stage (
        .clk(clk),
        .MemRead(MemRead),
        .MemWrite(MemWrite),
        .addr(rs1_val + imm),
        .data_in(rs2_val),
        .MemLen(MemLen),
        .data_out(data_out)
    );

    // 写回模块
    WB wb_stage (
        .pc(pc),
        .imm(imm),
        .rs1_val(rs1_val),
        .alu_result(alu_result),
        .opcode(opcode),
        .func3(func3),
        .data_out(data_out),
        .jalr_target(jalr_target),
        .is_jalr(is_jalr),
        .wb_data(wb_data)
    );


endmodule
