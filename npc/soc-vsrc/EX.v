`include "/home/furina/ysyx-workbench/npc/soc-vsrc/defines.v"
module EX (
    input             clk,
    input             reset,
    input             id_valid,//reg模块的输出是否有效
    output reg        ex_ready,//ex就绪状态
    input      [6:0]  opcode,
    input      [31:0] rs1_val,
    input      [31:0] rs2_val,
    input      [31:0] imm,
    input      [3:0]  alu_op,
    input             mem_ready,//下游mem是否就绪
    output reg        ex_valid,//ex输出是否有效
    output reg [31:0] alu_result,
    output reg        alu_zero,
    output reg        alu_less,

    input      [31:0] id_start_cycle,
    input      [31:0] id_inst_type,
    output reg [31:0] ex_start_cycle,
    output reg [31:0] ex_inst_type
);
`ifdef VERILATOR
    import "DPI-C" function void counter(input int inst_type, input int cycles, input int ifu_inc, input int lsu_inc, input int exu_inc);
`endif
    typedef enum { IDLE, STALL } state_t;
    state_t state, next_state;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state = IDLE;
            ex_ready = 1'b1;
            ex_valid = 1'b0;
            alu_result = 32'b0;
            alu_zero = 1'b0;
            alu_less = 1'b0;
            
            ex_inst_type = 32'd7;
            ex_start_cycle = 32'b0;
        end else begin
            state = next_state;
            case (state)
                IDLE: begin
                    ex_ready = 1'b1;
                    ex_valid = 1'b0;
                    if(id_valid) begin
                        ex_ready = 1'b0;
                        ex_valid = 1'b0;
                        case (alu_op)
                             `ALU_ADD:  alu_result = rs1_val + ((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm);
                            `ALU_SUB:  alu_result = rs1_val - ((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm);
                            `ALU_AND:  alu_result = rs1_val & ((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm);
                            `ALU_OR:   alu_result = rs1_val | ((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm);
                            `ALU_XOR:  alu_result = rs1_val ^ ((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm);
                            `ALU_SLTU: alu_result = (rs1_val < ((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm)) ? {31'b0, 1'b1} : 32'b0;
                            `ALU_SLT:  alu_result = ($signed(rs1_val) < $signed((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm)) ? {31'b0, 1'b1} : 32'b0;
                            `ALU_SRA:  alu_result = $signed(rs1_val) >>> ((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val[4:0] : imm[4:0]);
                            `ALU_SLL:  alu_result = rs1_val << ((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val[4:0] : imm[4:0]);
                            `ALU_SRL:  alu_result = rs1_val >> ((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val[4:0] : imm[4:0]);
                            default:   alu_result = 32'b0;
                        endcase
                        alu_zero = (alu_result == 32'b0);
                        case(alu_op)
                            `ALU_SLT:  alu_less = ($signed(rs1_val) < $signed((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm));
                             `ALU_SLTU: alu_less = (rs1_val < rs2_val);
                            default:   alu_less = ($signed(rs1_val) < $signed((opcode[6:2] == `INST_TYPE_R || opcode[6:2] == `INST_TYPE_B) ? rs2_val : imm));
                        endcase
                        next_state = mem_ready ? STALL : IDLE;

                        // ex_start_cycle <= id_start_cycle;
                        // ex_inst_type <= id_inst_type;
                    end
                    else begin
                        next_state = IDLE;
                    end
                end
                STALL: begin
                    ex_ready = 1'b0;
                    ex_valid = 1'b1;
                    ex_start_cycle = id_start_cycle;
                    ex_inst_type = id_inst_type;
                `ifdef VERILATOR
                    counter(7, 0, 0, 0, 1);
                `endif
                    next_state = mem_ready ? IDLE : STALL;
                end
                default: begin
                    ex_ready = 1'b0;
                    ex_valid = 1'b0;
                    next_state = IDLE;
                end
            endcase
        end
    end
    
endmodule