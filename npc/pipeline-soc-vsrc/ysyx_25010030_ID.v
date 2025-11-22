`include "ysyx_25010030_define.vh"

module ysyx_25010030_ID (
    input             clk,                  
    input             reset,                
    input      [31:0] if_id_pc,              
    input      [31:0] if_id_inst,            
    input             ex_flush,             

    // 握手信号
    input             if_valid,               
    output reg        id_ready,               
    input             ex_ready,               
    output reg        id_valid,  

    output reg        sim_end,             

    output reg [31:0] id_ex_pc,             
    // output reg [31:0] id_ex_inst,         
    output reg        id_ex_RegWrite,       
    output reg [ 3:0] id_ex_rd,             
    output reg [ 3:0] id_wb_rs1,            
    output reg [ 3:0] id_wb_rs2,            
    output reg [ 4:0] id_ex_zimm,            
    output reg [31:0] id_ex_imm,            
    output reg [ 5:0] id_ex_shamt,         

    output reg [ 3:0] id_ex_alu_op,
    output reg [ 4:0] id_ex_MemLen,
    output reg        id_ex_MemWrite,
    output reg        id_ex_MemRead,
    output reg [ 6:0] id_ex_opcode,
    output reg [ 2:0] id_ex_func3,

    output reg        id_ex_jal,              
    output reg        id_ex_jalr,
    output reg        id_ex_fencei,    

`ifdef FPU
    output reg        id_ex_is_div,
    output reg        id_ex_is_rem,
    output reg        id_ex_is_signed,
    input             ex_stop,
`endif         

    // output reg        id_ex_csr,             
    output reg        id_ex_csr_wen1,         
    // output reg        id_ex_csr_wen2,        
    output reg        id_ex_csr_ecall,        
    output reg        id_ex_csr_mret,        
    output reg [ 1:0] id_ex_csr_op,

    output reg [11:0] id_ex_csr_wr_addr1,     
    // output reg [11:0] id_ex_csr_wr_addr2,    
    output reg [11:0] id_wb_csr_addr1,        
    output reg [11:0] id_wb_csr_addr2         
);
`ifdef VERILATOR
    // import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);
`endif
    // 指令字段提取
    localparam FENCEI = 32'h0000100f;
    wire [6:0] opcode = if_id_inst[ 6: 0];
    wire [3:0] rs1    = if_id_inst[18:15];
    wire [3:0] rs2    = if_id_inst[23:20];
    wire [3:0] rd     = if_id_inst[10: 7];
    wire [2:0] func3  = if_id_inst[14:12];
    // wire [6:0] func7  = if_id_inst[31:25];
    wire       func7_5 = if_id_inst[30];
    wire [5:0] shamt  = if_id_inst[25:20];
    wire [4:0] zimm   = if_id_inst[19:15];
    wire [4:0] get_opcode = opcode[ 6: 2];

    // 立即数生成
    wire [31:0] immI   = {{20{if_id_inst[31]}}, if_id_inst[31:20]};
    wire [31:0] immU   = {if_id_inst[31:12], 12'b0};
    wire [31:0] immS   = {{20{if_id_inst[31]}}, if_id_inst[31:25], if_id_inst[11:7]};
    wire [31:0] immB   = {{20{if_id_inst[31]}}, if_id_inst[7], if_id_inst[30:25], if_id_inst[11:8], 1'b0};
    wire [31:0] immJ   = {{12{if_id_inst[31]}}, if_id_inst[19:12], if_id_inst[20], if_id_inst[30:21], 1'b0};
    wire [31:0] immR   = 32'b0;
    wire [31:0] immCSR = {27'b0, if_id_inst[19:15]};

    // reg [31:0] inst_type;
`ifdef FPU
    wire [6:0] func7  = if_id_inst[31:25];
    wire       is_div = (get_opcode == `INST_TYPE_R) && (func7 == 7'b0000001) && (func3[2]);
    wire       is_rem = is_div && (func3[1]);
    wire       is_signed = is_div && (!func3[0]);

    always @(*) begin
        if(reset) begin
            id_ready = 1'b0;
        end
        else begin
            id_ready = (ex_ready || ~id_valid) && ~ex_flush && ~ex_stop;
        end
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

`else

    // 握手逻辑
    always @(*) begin
        if(reset) begin
            id_ready = 1'b0;
        end
        else begin
            id_ready = (ex_ready || ~id_valid) && ~ex_flush;
        end
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
`endif

    // 译码逻辑和输出信号赋值
    always @(posedge clk) begin
        if (reset) begin
            // inst_type <= 7;
            sim_end         <= 1'b0;

            id_ex_RegWrite  <= 1'b0;
            id_ex_MemWrite  <= 1'b0;
            id_ex_MemRead   <= 1'b0;
            id_ex_jal       <= 1'b0;
            id_ex_jalr      <= 1'b0;
            id_ex_fencei    <= 1'b0;
            // id_ex_csr       <= 1'b0;
            id_ex_csr_wen1  <= 1'b0;
            // id_ex_csr_wen2  <= 1'b0;
            id_ex_csr_ecall <= 1'b0;
            id_ex_csr_mret  <= 1'b0;
`ifdef FPU
            id_ex_is_div    <= 1'b0;
            id_ex_is_rem    <= 1'b0;
            id_ex_is_signed <= 1'b0;
`endif
            
            id_ex_rd    <= 4'b0;
            id_wb_rs1   <= 4'b0;
            id_wb_rs2   <= 4'b0;
            id_ex_zimm  <= 5'b0;
            id_ex_imm   <= 32'b0;
            id_ex_shamt <= 6'b0;
            
            id_ex_pc   <= 32'b0;
            // id_ex_inst <= 32'b0;
            
            id_ex_alu_op <= `ALU_ADD;
            id_ex_MemLen <= `Mem_Word;
            id_ex_opcode <= 7'b0;
            id_ex_func3  <= 3'b0;
            id_ex_csr_op <= `CSR_NONE;
            
            id_ex_csr_wr_addr1 <= 12'b0;
            // id_ex_csr_wr_addr2 <= 12'b0;
            id_wb_csr_addr1    <= 12'b0;
            id_wb_csr_addr2    <= 12'b0;
        end
        else if (if_valid && id_ready) begin
            sim_end <= (if_id_inst == 32'h00100073);
            // 传递基本信号
            id_ex_pc     <= if_id_pc;
            // id_ex_inst   <= if_id_inst;
            id_ex_rd     <= rd;
            id_wb_rs1    <= rs1;
            id_wb_rs2    <= rs2;
            id_ex_zimm   <= zimm;  
            id_ex_shamt  <= shamt;
            id_ex_opcode <= opcode;
            id_ex_func3  <= func3;

            // 初始化默认值
            id_ex_imm       <= 32'b0;
            id_ex_RegWrite  <= 1'b0;
            id_ex_MemWrite  <= 1'b0;
            id_ex_MemRead   <= 1'b0;
            id_ex_alu_op    <= `ALU_ADD;
            id_ex_MemLen    <= `Mem_Word;
            id_ex_csr_op    <= `CSR_NONE;
            id_ex_csr_wen1  <= 1'b0;
            // id_ex_csr_wen2  <= 1'b0;
            id_ex_csr_ecall <= 1'b0;
            id_ex_csr_mret  <= 1'b0;
            id_ex_jal       <= 1'b0;
            id_ex_jalr      <= 1'b0;
            id_ex_fencei    <= (if_id_inst == FENCEI);
`ifdef FPU
            id_ex_is_div    <= is_div;
            id_ex_is_rem    <= is_rem;
            id_ex_is_signed <= is_signed;
`endif

            id_ex_csr_wr_addr1 <= 12'b0;
            // id_ex_csr_wr_addr2 <= 12'b0;
            id_wb_csr_addr1    <= 12'b0;
            id_wb_csr_addr2    <= 12'b0;

            // 译码逻辑
            case (get_opcode)
                `INST_TYPE_LUI: begin
                    id_ex_imm      <= immU;
                    id_ex_RegWrite <= 1'b1;
                    // inst_type      <= 1;
                end
                `INST_TYPE_AUIPC: begin
                    id_ex_imm      <= immU;
                    id_ex_RegWrite <= 1'b1;
                    id_ex_alu_op   <= `ALU_ADD;  // PC + imm
                    // inst_type      <= 1;
                end
                `INST_TYPE_JAL: begin
                    id_ex_imm      <= immJ;
                    id_ex_RegWrite <= 1'b1;
                    id_ex_jal      <= 1'b1;
                    // inst_type      <= 2;
                end
                `INST_TYPE_JALR: begin
                    if (func3 == 3'b000) begin
                        id_ex_imm      <= immI;
                        id_ex_RegWrite <= 1'b1;
                        id_ex_jalr     <= 1'b1;
                        // inst_type      <= 2;
                    end
                end
                `INST_TYPE_S: begin
                    id_ex_imm      <= immS;
                    id_ex_MemWrite <= 1'b1;
                    case (func3)
                        `F3_SW: id_ex_MemLen <= `Mem_Word;
                        `F3_SH: id_ex_MemLen <= `Mem_Half;
                        `F3_SB: id_ex_MemLen <= `Mem_Bit;
                        default: begin end
                    endcase
                    // inst_type <= 5;
                end
                `INST_TYPE_L: begin
                    id_ex_imm      <= immI;
                    id_ex_RegWrite <= 1'b1;
                    id_ex_MemRead  <= 1'b1;
                    id_ex_alu_op   <= `ALU_ADD;
                    case (func3)
                        `F3_LW:  id_ex_MemLen <= `Mem_Word;
                        `F3_LH:  id_ex_MemLen <= `Mem_Half;
                        `F3_LB:  id_ex_MemLen <= `Mem_Bit;
                        `F3_LHU: id_ex_MemLen <= `Mem_UHalf;
                        `F3_LBU: id_ex_MemLen <= `Mem_UBit;
                        default: begin end
                    endcase
                    // inst_type <= 3;
                end
                `INST_TYPE_R: begin
                    id_ex_imm      <= immR;
                    id_ex_RegWrite <= 1'b1;
                    case (func3)
                        3'b000:   id_ex_alu_op <= (func7_5) ? `ALU_SUB : `ALU_ADD;
                        `F3_ANDI: id_ex_alu_op <= `ALU_AND;
                        `F3_ORI:  id_ex_alu_op <= `ALU_OR;
                        `F3_XORI: id_ex_alu_op <= `ALU_XOR;
                        `F3_SLTU: id_ex_alu_op <= `ALU_SLTU;
                        `F3_SLT:  id_ex_alu_op <= `ALU_SLT;
                        `F3_RSH:  id_ex_alu_op <= (func7_5) ? `ALU_SRA : `ALU_SRL;
                        `F3_LSH:  id_ex_alu_op <= `ALU_SLL;
                        default: begin end
                    endcase
                    // inst_type <= 0;/
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
                        `F3_RSH:  id_ex_alu_op <= (func7_5) ? `ALU_SRA : `ALU_SRL;
                        `F3_LSH:  id_ex_alu_op <= `ALU_SLL;
                        default: begin end
                    endcase
                    // inst_type <=1;
                end
                `INST_TYPE_B: begin
                    id_ex_imm <= immB;
                    case (func3)
                        `F3_BEQ, `F3_BNE:   id_ex_alu_op <= `ALU_SUB;
                        `F3_BLT, `F3_BGE:   id_ex_alu_op <= `ALU_SLT;
                        `F3_BLTU, `F3_BGEU: id_ex_alu_op <= `ALU_SLTU;
                        default: begin end
                    endcase
                    // inst_type <= 4;
                end
                `INST_TYPE_E: begin
                    if (opcode == `INST_CSR) begin
                        // id_ex_csr      <= 1'b1;
                        id_ex_csr_wen1 <= 1'b1;
                        case (func3)
                            `F3_CSRRW: begin
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op   <= `CSR_CSRRW;
                            end
                            `F3_CSRRS: begin
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op   <= `CSR_CSRRS;
                            end
                            // `F3_CSRRC: begin
                            //     id_ex_RegWrite <= 1'b1;
                            //     id_ex_csr_op   <= `CSR_CSRRC;
                            // end
                            `F3_CSRRWI: begin
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op   <= `CSR_CSRRW;
                                id_ex_imm      <= immCSR;
                            end
                            `F3_CSRRSI: begin
                                id_ex_RegWrite <= 1'b1;
                                id_ex_csr_op   <= `CSR_CSRRS;
                                id_ex_imm      <= immCSR;
                            end
                            // `F3_CSRRCI: begin
                            //     id_ex_RegWrite <= 1'b1;
                            //     id_ex_csr_op   <= `CSR_CSRRC;
                            //     id_ex_imm      <= immCSR;
                            // end
                            `F3_ECALL: begin
                                if (if_id_inst == `INST_ECALL) begin
                                    id_ex_csr_ecall <= 1'b1;
                                    // id_ex_csr_wen2  <= 1'b1;
                                    id_ex_imm       <= 32'h0;
                                end
                                else if (if_id_inst == `INST_MRET) begin
                                    id_ex_csr_mret <= 1'b1;
                                    id_ex_imm      <= 32'h0;
                                end
                            end
                            default: begin end
                        endcase
                        // id_ex_csr_wr_addr1 <= (if_id_inst == `INST_ECALL) ? `MCAUSE : ((if_id_inst == `INST_MRET) ? `MSTATUS : if_id_inst[31:20]);
                        id_ex_csr_wr_addr1 <= if_id_inst[31:20];
                        // id_ex_csr_wr_addr2 <= (if_id_inst == `INST_ECALL) ? `MEPC : 12'b0;
                        id_wb_csr_addr1    <= (if_id_inst == `INST_MRET) ? `MSTATUS : ((if_id_inst == `INST_ECALL) ? `MTVEC : if_id_inst[31:20]);
                        id_wb_csr_addr2    <= (if_id_inst == `INST_MRET) ? `MEPC : 12'b0;
                        // inst_type <= 6;
                    end
                end
                default: begin
                    // inst_type <= 7;
                end
            endcase
        // `ifdef VERILATOR
        //     if(inst_type != 7) begin
        //         counter(inst_type, 0, 0, 0);
        //     end
        // `endif
        end
    end
endmodule
