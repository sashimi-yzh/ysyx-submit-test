`include "opcode_defines.v"
module ysyx_24110012_exu (
    // input
    input wire [31:0] idu_exu_pc,      // program counter
    input wire [ 6:0] idu_exu_opcode,  // opcode
    input wire [ 2:0] idu_exu_func3,   // func3
    input wire [ 6:0] idu_exu_func7,   // func7
    input wire [31:0] idu_exu_imm,
    input wire [31:0] idu_exu_rs1,
    input wire [31:0] idu_exu_rs2,
    input wire [3:0] idu_exu_rd_idx,
    input wire [11:0] idu_exu_csr_idx,
    input wire [31:0] idu_exu_csr_rdata,
    input wire idu_exu_ecall,
    input wire idu_exu_mret,
    input wire idu_exu_fencei,
    input wire idu_exu_cycle_done,

    input wire idu_exu_valid,
    output wire exu_idu_ready,

    // output
    output reg       exu_lsu_reg_wen,      // whether write reg
    output reg       exu_lsu_mem_w,        // whether write mem
    output reg       exu_lsu_mem_r,        // whether read mem
    output reg       exu_lsu_mem_sign_ext, // whether sign extend for mem read
    output reg [2:0] exu_lsu_mem_mask,     // mem width for read/write
    output reg [2:0] exu_lsu_func3,
    output reg [31:0] exu_lsu_result,
    output reg [31:0] exu_lsu_rs2,
    output reg [3:0] exu_lsu_rd_idx,
    output reg [11:0] exu_lsu_csr_idx,
    output reg [31:0] exu_lsu_csr_rdata,
    output reg        exu_lsu_ecall,
    output reg        exu_lsu_mret,
    output reg        exu_lsu_fencei,
    output reg         exu_lsu_branch,       // whether branch instruction
    output reg         exu_lsu_jump,         // whether JAL/JALR
    output wire        exu_lsu_wb_from_mem,  // 1 for mem, 0 for ALU
    output reg         exu_lsu_csr_wen,      // CSR write enable
    output reg  [31:0] exu_lsu_npc,
    output reg         exu_lsu_cycle_done,

    output wire exu_lsu_valid,
    input  wire lsu_exu_ready

);

// imm type for 000=I, 001=S, 010=B, 011=U, 100=J
reg [3:0] alu_type;  // alu type
reg [31:0] alu_p1;  // alu parameter 1
reg [31:0] alu_p2;  // alu parameter 2
wire [31:0] alu_out; // alu output from submodule

assign exu_lsu_csr_idx = idu_exu_csr_idx;
assign exu_lsu_csr_rdata = idu_exu_csr_rdata;
assign exu_lsu_ecall = idu_exu_ecall;
assign exu_lsu_mret = idu_exu_mret;
assign exu_lsu_fencei = idu_exu_fencei;
assign exu_lsu_rd_idx = idu_exu_rd_idx;
assign exu_lsu_rs2 = idu_exu_rs2;
assign exu_lsu_func3 = idu_exu_func3;

//valid/ready
assign exu_lsu_valid = idu_exu_valid;
assign exu_idu_ready = lsu_exu_ready;  // only combinational logic here

// parse control logic
always @(*) begin

    // provide default value
    exu_lsu_reg_wen = 1'b0;
    exu_lsu_mem_w = 1'b0;
    exu_lsu_mem_r  = 1'b0;
    exu_lsu_mem_mask = 3'b000;
    exu_lsu_mem_sign_ext = 1'b0;

    exu_lsu_branch   = 1'b0;
    exu_lsu_jump     = 1'b0;
    exu_lsu_wb_from_mem   = 1'b0;
    exu_lsu_csr_wen  = 1'b0;

    case (idu_exu_opcode)
        `OPT_R_LOGIC: begin // R-Type
            exu_lsu_reg_wen = 1;
        end
        `OPT_I_LOGIC: begin // I-Type (addi)
            exu_lsu_reg_wen = 1;
        end
        `OPT_I_LOAD: begin // I-Type (lw)
            exu_lsu_reg_wen = 1;
            exu_lsu_mem_r = 1; // read result from memory
            case (idu_exu_func3)
                3'b000: begin exu_lsu_mem_mask = 3'b001; exu_lsu_mem_sign_ext = 1'b1; end // lb
                3'b001: begin exu_lsu_mem_mask = 3'b011; exu_lsu_mem_sign_ext = 1'b1; end // lh
                3'b010: begin exu_lsu_mem_mask = 3'b111; exu_lsu_mem_sign_ext = 1'b1; end // lw
                3'b100: exu_lsu_mem_mask = 3'b001; // lbu
                3'b101: exu_lsu_mem_mask = 3'b011; // lhu
                default: begin exu_lsu_mem_mask =3'b000; exu_lsu_mem_sign_ext = 1'b0; end // default to lb
            endcase
            exu_lsu_wb_from_mem   = 1; // mem result
        end
        `OPT_I_JALR: begin // I-Type (jalr)
            exu_lsu_reg_wen = 1;
            exu_lsu_jump     = 1; // jalr
        end
        `OPT_I_EC: begin // I-Type (ecall/ebreak/csr)
            if (idu_exu_func3 != 3'b000)
              exu_lsu_csr_wen = 1'b1;
        end
        `OPT_S_STORE: begin // S-Type (sw)
            exu_lsu_mem_w = 1;
            case (idu_exu_func3)
                3'b000: exu_lsu_mem_mask =3'b001; // sb
                3'b001: exu_lsu_mem_mask =3'b011; // sh
                3'b010: exu_lsu_mem_mask =3'b111; // sw
                default: exu_lsu_mem_mask = 3'b000; // default to sb
            endcase
        end
        `OPT_B: begin // B-Type (beq, bne)
            // let it be decided later with alu result
        end
        `OPT_U_LUI, `OPT_U_AUIPC: begin // U-Type (lui, auipc)
            exu_lsu_reg_wen = 1;
        end
        `OPT_J_JAL: begin // J-Type (jal)
            exu_lsu_reg_wen = 1;
            exu_lsu_jump     = 1;
        end
        default: begin
            exu_lsu_reg_wen      = 1'b0;
            exu_lsu_mem_w        = 1'b0;
            exu_lsu_mem_r        = 1'b0;
            exu_lsu_mem_mask     = 3'b000;
            exu_lsu_mem_sign_ext = 1'b0;
            exu_lsu_branch       = 1'b0;
            exu_lsu_jump         = 1'b0;
            exu_lsu_wb_from_mem  = 1'b0;
      end
    endcase
end

// parse alu parameters and type
always @(*) begin

    // provide default value
    alu_type = 4'b0000;
    alu_p1 = 32'b0;
    alu_p2 = 32'b0;

    case (idu_exu_opcode)
        `OPT_R_LOGIC: begin // R-Type
            alu_p1 = idu_exu_rs1;
            alu_p2 = idu_exu_rs2;
            if (idu_exu_func3 == 3'b000) begin
                alu_type = `FUNC_ADD; // add
                if (idu_exu_func7[5]) begin // sub
                    alu_p2 = ~idu_exu_rs2 + 1;
                end
            end else if (idu_exu_func3 == 3'b001) begin
                alu_type = `FUNC_SH_L; // sll
            end else if (idu_exu_func3 == 3'b010) begin
                alu_type = `FUNC_LESS_SIGN; // slt
            end else if (idu_exu_func3 == 3'b011) begin
                alu_type = `FUNC_LESS; // sltu
            end else if (idu_exu_func3 == 3'b100) begin
                alu_type = `FUNC_XOR; // xor
            end else if (idu_exu_func3 == 3'b101) begin
                alu_type = `FUNC_SH_R; // srl/sra
                if (idu_exu_func7[5]) begin // sra
                    alu_type = `FUNC_SH_AR;
                end
            end else if (idu_exu_func3 == 3'b110) begin
                alu_type = `FUNC_OR; // or
            end else if (idu_exu_func3 == 3'b111) begin
                alu_type = `FUNC_AND; // and
            end
        end
        `OPT_I_LOGIC: begin // I-Type
            alu_p1 = idu_exu_rs1;
            alu_p2 = idu_exu_imm;
            case (idu_exu_func3)
            3'b000: alu_type = `FUNC_ADD; // addi
            3'b010: alu_type = `FUNC_LESS_SIGN; // slti
            3'b011: alu_type = `FUNC_LESS; // sltiu
            3'b100: alu_type = `FUNC_XOR; // xori
            3'b110: alu_type = `FUNC_OR; // ori
            3'b111: alu_type = `FUNC_AND; // andi
            3'b001: alu_type = `FUNC_SH_L; // slli
            3'b101: begin
                alu_type = `FUNC_SH_R; // srli
                if (idu_exu_func7[5] == 1'b1) // srai
                    alu_type = `FUNC_SH_AR;
            end
            endcase
        end
        `OPT_I_LOAD: begin // I-load Type
            alu_p1 = idu_exu_rs1;
            alu_p2 = idu_exu_imm;
            alu_type = `FUNC_ADD;
        end
        `OPT_I_JALR: begin // I-jalr Type
            alu_p1 = idu_exu_pc;
            alu_p2 = 32'h4;
            alu_type = `FUNC_ADD;
        end
        `OPT_S_STORE: begin // S-Type
            alu_p1 = idu_exu_rs1;
            alu_p2 = idu_exu_imm;
            alu_type = `FUNC_ADD;
        end
        `OPT_I_EC: begin // I-Type for csrrs
            if(idu_exu_func3 == 3'b010) begin // csrrs
                alu_p1 = idu_exu_rs1;
                alu_p2 = idu_exu_csr_rdata;
                alu_type = `FUNC_OR;
            end
            if(idu_exu_func3 == 3'b001) begin // csrrw
                alu_p1 = idu_exu_rs1;
                alu_p2 = 32'b0;
                alu_type = `FUNC_OR;
            end
        end
        `OPT_B: begin // B-Type
            alu_p1 = idu_exu_rs1;
            alu_p2 = idu_exu_rs2;
            case (idu_exu_func3)
            3'b000: alu_type = `FUNC_EQ; // beq
            3'b001: alu_type = `FUNC_NEQ; // bne
            3'b100: alu_type = `FUNC_LESS_SIGN; // blt
            3'b101: alu_type = `FUNC_BGE_SIGN; //bge
            3'b110: alu_type = `FUNC_LESS; // bltu
            3'b111: alu_type = `FUNC_BGE;  //bgeu
            default: begin
                alu_p1 = idu_exu_rs1;
                alu_p2 = idu_exu_rs2;
                alu_type = `FUNC_EQ;
            end
            endcase
        end
        `OPT_U_LUI: begin // U-Type, use add to implement lui
            alu_p1 = idu_exu_imm;
            alu_p2 = 32'b0;
            alu_type = `FUNC_ADD;
        end
        `OPT_U_AUIPC: begin // U-Type
            alu_p1 = idu_exu_pc;
            alu_p2 = idu_exu_imm;
            alu_type = `FUNC_ADD;
        end
        `OPT_J_JAL: begin // J-Type
            alu_p1 = idu_exu_pc;
            alu_p2 = 32'h4;
            alu_type = `FUNC_ADD;
        end
        default: begin
            alu_type = 4'b0000;
            alu_p1 = 32'b0;
            alu_p2 = 32'b0;
        end
    endcase
end

ysyx_24110012_alu u_alu (
    .alu_type(alu_type),
    .alu_p1(alu_p1),
    .alu_p2(alu_p2),
    .alu_out(alu_out)
);

assign exu_lsu_result = alu_out;

// update dynamic next pc
always @(*) begin
    exu_lsu_cycle_done = idu_exu_cycle_done;
    exu_lsu_branch = 0;
    exu_lsu_npc = idu_exu_pc;
    if (idu_exu_valid) begin
      case (idu_exu_opcode)
        `OPT_B: begin  // B-Type
          if (alu_out == 32'b1) exu_lsu_branch = 1;  // branch taken
          else exu_lsu_branch = 0;  // branch not taken
          exu_lsu_npc        = idu_exu_pc + idu_exu_imm;
          exu_lsu_cycle_done = idu_exu_cycle_done | 1'b1;
        end
        `OPT_I_JALR: begin
          exu_lsu_npc = (idu_exu_rs1 + idu_exu_imm) & ~32'h1;  // jalr, align to 2-byte boundary
        end
        `OPT_J_JAL: begin
          exu_lsu_npc = idu_exu_pc + idu_exu_imm;  // jal, jump to target address
        end
        default: begin
          exu_lsu_branch = 0;  // not a branch instruction
          exu_lsu_npc    = idu_exu_pc;  // default next pc is pc which used to store mepc in wbu
        end
      endcase
    end
  end

endmodule
