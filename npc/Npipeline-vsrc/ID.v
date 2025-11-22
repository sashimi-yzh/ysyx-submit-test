`timescale 1ns/1ns
`include "/home/furina/ysyx-workbench/npc/Npipeline-vsrc/defines/defines.v"
module ID (
    input             clk,                    // 时钟信号
    input             reset,                  // 复位信号
    input      [31:0] if_id_pc,               // 从IFU传递的PC值
    input      [31:0] if_id_inst,             // 从IFU传递的指令
    input             ex_flush,               // 执行单元的冲刷信号

    // 握手信号
    input             if_valid,               // IFU到ID的有效信号
    output reg        id_ready,               // ID到IFU的就绪信号
    input             ex_ready,               // EXU到ID的就绪信号
    output reg        id_valid,               // ID到EXU的有效信号

    output reg [31:0] id_ex_pc,               // 传递到EXU的PC值
    output reg [31:0] id_ex_inst,             // 传递到EXU的指令
    output reg        id_ex_RegWrite,         // 寄存器写使能
    output reg [4:0]  id_ex_rd,               // 寄存器写地址
    output reg [4:0]  id_wb_rs1,              // 源寄存器1地址
    output reg [4:0]  id_wb_rs2,              // 源寄存器2地址
    output reg [4:0]  id_ex_zimm,             // CSR立即数（zimm）
    output reg [31:0] id_ex_imm,              // 立即数值
    output reg [5:0]  id_ex_shamt,            // 移位量

    output reg [3:0]  id_ex_alu_op,
    output reg [2:0]  id_ex_MemLen,
    output reg        id_ex_MemWrite,
    output reg        id_ex_MemRead,
    output reg [6:0]  id_ex_opcode,
    output reg [2:0]  id_ex_func3,

    output reg        id_ex_jal,              // JAL跳转信号
    output reg        id_ex_jalr,             // JALR跳转信号
    // input             predict_taken,         // 分支预测输入
    // output reg        id_ex_predict_taken,       // 分支预测输出

    output reg        id_ex_csr,              // CSR指令信号
    output reg        id_ex_csr_wen1,         // CSR写使能1
    output reg        id_ex_csr_wen2,         // CSR写使能2
    output reg        id_ex_csr_ecall,        // ECALL信号
    output reg        id_ex_csr_mret,         // MRET信号
    output reg [1:0]  id_ex_csr_op,

    output reg [11:0] id_ex_csr_wr_addr1,     // CSR写地址1
    output reg [11:0] id_ex_csr_wr_addr2,     // CSR写地址2
    output reg [11:0] id_wb_csr_addr1,        // CSR读地址1
    output reg [11:0] id_wb_csr_addr2         // CSR读地址2
);
    import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);
    // 指令字段提取
    wire [6:0] opcode = if_id_inst[6:0];
    wire [4:0] rs1    = if_id_inst[19:15];
    wire [4:0] rs2    = if_id_inst[24:20];
    wire [4:0] rd     = if_id_inst[11:7];
    wire [2:0] func3  = if_id_inst[14:12];
    wire [6:0] func7  = if_id_inst[31:25];
    wire [5:0] shamt  = if_id_inst[25:20];
    wire [4:0] get_opcode = opcode[6:2];

    // 立即数生成
    wire [31:0] immI = {{20{if_id_inst[31]}}, if_id_inst[31:20]};
    wire [31:0] immU = {if_id_inst[31:12], 12'b0};
    wire [31:0] immS = {{20{if_id_inst[31]}}, if_id_inst[31:25], if_id_inst[11:7]};
    wire [31:0] immB = {{20{if_id_inst[31]}}, if_id_inst[7], if_id_inst[30:25], if_id_inst[11:8], 1'b0};
    wire [31:0] immJ = {{12{if_id_inst[31]}}, if_id_inst[19:12], if_id_inst[20], if_id_inst[30:21], 1'b0};
    wire [31:0] immR = 32'b0;
    wire [31:0] immCSR = {27'b0, if_id_inst[19:15]};

    reg [31:0] inst_type;

    // 握手逻辑
    always @(*) begin
        id_ready = (ex_ready || ~id_valid) && ~ex_flush;
    end

    always @(posedge clk) begin
        if (reset) begin
            id_valid <= 1'b0;
        end
        else if ((if_valid && id_ready) && (ex_ready || ~id_valid)) begin
            id_valid <= 1'b1;
        end
        else if ((~(if_valid && id_ready)) && ex_ready) begin
            id_valid <= 1'b0;
        end
    end

    // 译码逻辑和输出信号赋值
    always @(posedge clk) begin
        if (reset) begin
            inst_type <= 7;

            // 第一组: 控制信号
            id_ex_RegWrite <= 1'b0;
            id_ex_MemWrite <= 1'b0;
            id_ex_MemRead <= 1'b0;
            id_ex_jal <= 1'b0;
            id_ex_jalr <= 1'b0;
            id_ex_csr <= 1'b0;
            id_ex_csr_wen1 <= 1'b0;
            id_ex_csr_wen2 <= 1'b0;
            id_ex_csr_ecall <= 1'b0;
            id_ex_csr_mret <= 1'b0;
            
            // 第二组: 地址和立即数
            id_ex_rd <= 5'b0;
            id_wb_rs1 <= 5'b0;
            id_wb_rs2 <= 5'b0;
            id_ex_zimm <= 5'b0;
            id_ex_imm <= 32'b0;
            id_ex_shamt <= 6'b0;
            
            // 第三组: 指令和PC
            id_ex_pc <= 32'b0;
            // id_ex_pc2 <= 32'b0;
            id_ex_inst <= 32'b0;
            
            // 第四组: ALU和功能信号
            id_ex_alu_op <= 4'b0;
            id_ex_MemLen <= 3'b0;
            id_ex_opcode <= 7'b0;
            id_ex_func3 <= 3'b0;
            id_ex_csr_op <= 2'b0;
            
            // 第五组: CSR地址
            id_ex_csr_wr_addr1 <= 12'b0;
            id_ex_csr_wr_addr2 <= 12'b0;
            id_wb_csr_addr1 <= 12'b0;
            id_wb_csr_addr2 <= 12'b0;
            
            // 第六组: 分支预测
            // id_ex_predict_taken <= 1'b0;
            // id_ex_predict_target <= 32'b0;
        end
        else if (if_valid && id_ready) begin
            // 传递基本信号
            id_ex_pc <= if_id_pc;
            // id_ex_pc2 <= if_id_pc2;
            id_ex_inst <= if_id_inst;
            id_ex_rd <= rd;
            id_wb_rs1 <= rs1;
            id_wb_rs2 <= rs2;
            id_ex_zimm <= rs1;  // CSR zimm
            id_ex_shamt <= shamt;
            id_ex_opcode <= opcode;
            id_ex_func3 <= func3;
            // id_ex_predict_taken <= predict_taken & (get_opcode == `INST_TYPE_B || (opcode == `INST_JALR && func3 == 3'b000) || opcode == `INST_JAL);
            // id_ex_predict_target <= predict_target;

            // 初始化默认值
            id_ex_imm <= 32'b0;
            id_ex_RegWrite <= 1'b0;
            id_ex_MemWrite <= 1'b0;
            id_ex_MemRead <= 1'b0;
            id_ex_alu_op <= `ALU_ADD;
            id_ex_MemLen <= `Mem_Word;
            id_ex_csr_op <= `CSR_NONE;
            id_ex_csr <= 1'b0;
            id_ex_csr_wen1 <= 1'b0;
            id_ex_csr_wen2 <= 1'b0;
            id_ex_csr_ecall <= 1'b0;
            id_ex_csr_mret <= 1'b0;
            id_ex_jal <= 1'b0;
            id_ex_jalr <= 1'b0;

            // 译码逻辑
            case (get_opcode)
                `INST_TYPE_LUI: begin
                    id_ex_imm <= immU;
                    id_ex_RegWrite <= 1'b1;
                    inst_type <= 1;
                end
                `INST_TYPE_AUIPC: begin
                    id_ex_imm <= immU;
                    id_ex_RegWrite <= 1'b1;
                    id_ex_alu_op <= `ALU_ADD;  // PC + imm
                    inst_type <= 1;
                end
                `INST_TYPE_JAL: begin
                    id_ex_imm <= immJ;
                    id_ex_RegWrite <= 1'b1;
                    id_ex_jal <= 1'b1;
                    inst_type <= 2;
                end
                `INST_TYPE_JALR: begin
                    if (func3 == 3'b000) begin
                        id_ex_imm <= immI;
                        id_ex_RegWrite <= 1'b1;
                        id_ex_jalr <= 1'b1;
                        inst_type <= 2;
                    end
                end
                `INST_TYPE_S: begin
                    id_ex_imm <= immS;
                    id_ex_MemWrite <= 1'b1;
                    case (func3)
                        `F3_SW: id_ex_MemLen <= `Mem_Word;
                        `F3_SH: id_ex_MemLen <= `Mem_Half;
                        `F3_SB: id_ex_MemLen <= `Mem_Bit;
                        default: begin
                            // 可添加错误处理逻辑
                        end
                    endcase
                    inst_type <= 5;
                end
                `INST_TYPE_L: begin
                    id_ex_imm <= immI;
                    id_ex_RegWrite <= 1'b1;
                    id_ex_MemRead <= 1'b1;
                    id_ex_alu_op <= `ALU_ADD;
                    case (func3)
                        `F3_LW:  id_ex_MemLen <= `Mem_Word;
                        `F3_LH:  id_ex_MemLen <= `Mem_Half;
                        `F3_LB:  id_ex_MemLen <= `Mem_Bit;
                        `F3_LHU: id_ex_MemLen <= `Mem_UHalf;
                        `F3_LBU: id_ex_MemLen <= `Mem_UBit;
                        default: begin
                            // 可添加错误处理逻辑
                        end
                    endcase
                    inst_type <= 3;
                end
                `INST_TYPE_R: begin
                    id_ex_imm <= immR;
                    id_ex_RegWrite <= 1'b1;
                    case (func3)
                        3'b000: id_ex_alu_op <= (func7[5]) ? `ALU_SUB : `ALU_ADD;
                        `F3_ANDI: id_ex_alu_op <= `ALU_AND;
                        `F3_ORI:  id_ex_alu_op <= `ALU_OR;
                        `F3_XORI: id_ex_alu_op <= `ALU_XOR;
                        `F3_SLTU: id_ex_alu_op <= `ALU_SLTU;
                        `F3_SLT:  id_ex_alu_op <= `ALU_SLT;
                        `F3_RSH:  id_ex_alu_op <= (func7[5]) ? `ALU_SRA : `ALU_SRL;
                        `F3_LSH:  id_ex_alu_op <= `ALU_SLL;
                        default: begin
                            // 可添加错误处理逻辑
                        end
                    endcase
                    inst_type <= 0;
                end
                `INST_TYPE_I: begin
                    id_ex_imm <= immI;
                    id_ex_RegWrite <= 1'b1;
                    case (func3)
                        `F3_ADDI: id_ex_alu_op <= `ALU_ADD;
                        `F3_ANDI: id_ex_alu_op <= `ALU_AND;
                        `F3_ORI:  id_ex_alu_op <= `ALU_OR;
                        `F3_SLTU: id_ex_alu_op <= `ALU_SLTU;
                        `F3_SLTI: id_ex_alu_op <= `ALU_SLT;
                        `F3_XORI: id_ex_alu_op <= `ALU_XOR;
                        `F3_RSH:  id_ex_alu_op <= (func7[5]) ? `ALU_SRA : `ALU_SRL;
                        `F3_LSH:  id_ex_alu_op <= `ALU_SLL;
                        default: begin
                            // 可添加错误处理逻辑
                        end
                    endcase
                    inst_type <=1;
                end
                `INST_TYPE_B: begin
                    id_ex_imm <= immB;
                    case (func3)
                        `F3_BEQ:  id_ex_alu_op <= `ALU_SUB;
                        `F3_BNE:  id_ex_alu_op <= `ALU_SUB;
                        `F3_BLT:  id_ex_alu_op <= `ALU_SLT;
                        `F3_BGE:  id_ex_alu_op <= `ALU_SLT;
                        `F3_BLTU: id_ex_alu_op <= `ALU_SLTU;
                        `F3_BGEU: id_ex_alu_op <= `ALU_SLTU;
                        default: begin
                            // 可添加错误处理逻辑
                        end
                    endcase
                    inst_type <= 4;
                end
                `INST_TYPE_E: begin
                    if (opcode == `INST_CSR) begin
                        id_ex_csr <= 1'b1;
                        id_ex_csr_wen1 <= 1'b1;
                        case (func3)
                            `F3_CSRRW: begin
                                // id_ex_csr_wen1 <= 1'b1;
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op <= `CSR_CSRRW;
                            end
                            `F3_CSRRS: begin
                                // id_ex_csr_wen1 <= 1'b1;
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op <= `CSR_CSRRS;
                            end
                            `F3_CSRRC: begin
                                // id_ex_csr_wen1 <= 1'b1;
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op <= `CSR_CSRRC;
                            end
                            `F3_CSRRWI: begin
                                // id_ex_csr_wen1 <= 1'b1;
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op <= `CSR_CSRRW;
                                id_ex_imm <= immCSR;
                            end
                            `F3_CSRRSI: begin
                                // id_ex_csr_wen1 <= 1'b1;
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op <= `CSR_CSRRS;
                                id_ex_imm <= immCSR;
                            end
                            `F3_CSRRCI: begin
                                // id_ex_csr_wen1 <= 1'b1;
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op <= `CSR_CSRRC;
                                id_ex_imm <= immCSR;
                            end
                            `F3_ECALL: begin
                                if (if_id_inst == `INST_ECALL) begin
                                    id_ex_csr_ecall <= 1'b1;
                                    // id_ex_csr_wen1 <= 1'b1;
                                    id_ex_csr_wen2 <= 1'b1;
                                    id_ex_imm <= 32'h0;
                                end
                                else if (if_id_inst == `INST_MRET) begin
                                    id_ex_csr_mret <= 1'b1;
                                    // id_ex_csr_wen1 <= 1'b1;
                                    id_ex_imm <= 32'h0;
                                end
                            end
                            default: begin
                                // 可添加错误处理逻辑
                            end
                        endcase
                        id_ex_csr_wr_addr1 <= (if_id_inst == `INST_ECALL) ? `MCAUSE : ((if_id_inst == `INST_MRET) ? `MSTATUS : if_id_inst[31:20]);
                        id_ex_csr_wr_addr2 <= (if_id_inst == `INST_ECALL) ? `MEPC : 12'b0;
                        id_wb_csr_addr1 <= (if_id_inst == `INST_MRET) ? `MSTATUS : ((if_id_inst == `INST_ECALL) ? `MTVEC : if_id_inst[31:20]);
                        id_wb_csr_addr2 <= (if_id_inst == `INST_MRET) ? `MEPC : 12'b0;
                        inst_type <= 6;
                    end
                end
                default: begin
                    // 可添加错误处理逻辑
                    inst_type <= 7;
                end
            endcase

            if(inst_type != 7) begin
                counter(inst_type, 0, 0, 0);
            end
        end
    end
endmodule