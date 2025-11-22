`include "/home/furina/ysyx-workbench/npc/single-vsrc/defines.v"
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
    wire [31:0]  jal_target;
    wire [31:0]  jalr_target;
    wire         is_jal, is_jalr;
    wire [31:0]  data_out;
    wire [3:0]   alu_op;
    wire [31:0]  alu_result;
    wire         alu_zero;
    wire         alu_less;
    wire         take_branch;
    wire [2:0]   MemLen;

    wire [11:0] csr_raddr;
    wire [1:0]  csr_op;
    wire [31:0] csr_rdata;
    wire [31:0] csr_wdata;
    wire [31:0] ecall_pc;
    wire [31:0] mret_pc;
    wire        is_ecall;
    wire        is_mret;
    wire        csrWrite;

    wire [31:0] branch_target;
    // assign branch_target=is_jalr ? jalr_target : jal_target;
    assign branch_target = (is_ecall) ? ecall_pc : 
                            (is_mret) ? mret_pc :
                            (is_jalr) ? jalr_target : jal_target;
    // 取指模块
    IF if_stage (
        .clk(clk),
        .reset(reset),
        // .branch_target(is_jalr ? jalr_target : jal_target),
        .branch_target(branch_target),
        .pc_src(is_jal | is_jalr | take_branch | is_ecall | is_mret),
        // .pc_src(is_jal | is_jalr | take_branch),
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
        .MemLen(MemLen),
        .csrWrite(csrWrite),
        .csr_op(csr_op),
        .is_mret(is_mret),
        .is_ecall(is_ecall)
    );

    assign csr_raddr = instr[31:20];
    
    // CSR模块
    CSR csr (
        .clk(clk),
        .reset(reset),
        .csrWrite(csrWrite),
        .addr(csr_raddr),
        .wdata(csr_wdata),
        .op(csr_op),
        .rdata(csr_rdata),
        .ecall(is_ecall),
        .mret(is_mret),
        .pc(pc),
        .mret_pc(mret_pc),
        .ecall_pc(ecall_pc)
    );

    // 寄存器文件
    RegFile regfile (
        .clk(clk),
        // .reset(reset),
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
        .b((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm), // R-type用rs2_val，I-type用imm
        .result(alu_result),
        .zero(alu_zero),
        .less(alu_less)
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
        .alu_zero(alu_zero),
        .alu_less(alu_less),
        .data_out(data_out),
        .csr_rdata(csr_rdata),
        .jal_target(jal_target),
        .jalr_target(jalr_target),
        .is_jal(is_jal),
        .is_jalr(is_jalr),
        .take_branch(take_branch),
        .wb_data(wb_data)
    );
    
    //CSR数据写回
    assign csr_wdata = (func3 == `F3_CSRRWI || func3 == `F3_CSRRSI || func3 == `F3_CSRRCI) ? imm : rs1_val;

    // always @(posedge clk) begin
    //     if(is_ecall) begin
    //         $display("[ECALL] ecall_pc = 0x%h", ecall_pc);
    //     end
    //     if(is_mret) begin
    //         $display("[MRET] mret_pc = 0x%h", mret_pc);
    //     end
    // end

endmodule
