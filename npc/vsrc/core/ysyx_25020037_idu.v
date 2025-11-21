`include "ysyx_25020037_config.vh"

module ysyx_25020037_idu (
    input  wire         clk,
    input  wire         rst,
    input  wire         ifu_valid,
    input  wire         exu_ready,
    output reg          idu_valid,
    output wire         idu_ready,
    input  wire         exu_dnpc_valid,
    input  wire [31: 0] pc,
    input  wire [31: 0] inst,
    output reg  [`DU_TO_EU_BUS_WD -1:0] du_to_eu_bus
);
    wire [`DU_TO_LU_BUS_WD -1:0] du_to_lu_bus;
    wire  gpr_we;

    wire [ 4: 0] rs1;
    wire [ 4: 0] rs2;
    wire [ 4: 0] rd;
    wire [31: 0] imm;
    wire [16: 0] alu_op;
    wire         rlsu_we;
    wire         wlsu_we;
    wire [ 1: 0] lw_lh_lb;
    wire [ 1: 0] sw_sh_sb;
    wire         src1_is_pc;
    wire         src2_is_imm;
    wire         is_pc_jump;
    wire         inst_not_realize;

    wire [ 6:0] opcode_31_25;
    wire [ 5:0] opcode_31_26;
    wire [ 2:0] opcode_14_12;
    wire [ 6:0] opcode_06_00;
    wire [31:0] immI;
    wire [31:0] immS;
    wire [31:0] immB;
    wire [31:0] immU;
    wire [31:0] immJ;

    wire        inst_add;
    wire        inst_and;
    wire        inst_or;
    wire        inst_ori;
    wire        inst_xor;
    wire        inst_xori;
    wire        inst_sub;
    wire        inst_slt;
    wire        inst_sltu;
    wire        inst_addi;
    wire        inst_andi;
    wire        inst_jarl;
    wire        inst_lb;
    wire        inst_lbu;
    wire        inst_lh;
    wire        inst_lhu;
    wire        inst_lw;
    wire        inst_sll;
    wire        inst_slli;
    wire        inst_slti;
    wire        inst_sltiu;
    wire        inst_sra;
    wire        inst_srai;
    wire        inst_srl;
    wire        inst_srli;
    wire        inst_csrrw;
    wire        inst_csrrs;
    wire        inst_ecall;
    wire        inst_mret;
    wire        inst_sb;
    wire        inst_sh;
    wire        inst_sw;
    wire        inst_beq;
    wire        inst_bne;
    wire        inst_bge;
    wire        inst_bgeu;
    wire        inst_blt;
    wire        inst_bltu;
    wire        inst_auipc;
    wire        inst_lui;
    wire        inst_jal;
    wire        inst_fence_i;
    wire        inst_ebreak;
    wire        inst_waiting;

    wire        TYPE_R;
    wire        TYPE_I;
    wire        TYPE_S;
    wire        TYPE_B;
    wire        TYPE_U;
    wire        TYPE_J;
    wire        TYPE_N;

    assign du_to_lu_bus = {
        inst_lb,        
        inst_lh
    };

    assign opcode_31_25  = inst[31:25];
    assign opcode_31_26  = inst[31:26];
    assign opcode_14_12  = inst[14:12];
    assign opcode_06_00  = inst[ 6: 0];

    assign rs1     = inst[19:15];
    assign rs2     = inst[24:20];
    assign rd      = inst[11: 7];

    assign immI  = {{20{inst[31]}}, inst[31:20]};
    assign immS  = {{20{inst[31]}}, inst[31:25], inst[11:7]};
    assign immB  = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
    assign immU  = {inst[31:12], 12'b0};
    assign immJ  = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};

    assign inst_add       = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h0) & (opcode_31_25 == 7'h00);
    assign inst_and       = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h7) & (opcode_31_25 == 7'h00);
    assign inst_or        = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h6) & (opcode_31_25 == 7'h00);
    assign inst_xor       = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h4) & (opcode_31_25 == 7'h00);
    assign inst_sll       = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h1) & (opcode_31_25 == 7'h00);
    assign inst_sub       = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h0) & (opcode_31_25 == 7'h20);
    assign inst_slt       = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h2) & (opcode_31_25 == 7'h00);
    assign inst_sltu      = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h3) & (opcode_31_25 == 7'h00);
    assign inst_addi      = (opcode_06_00 == 7'h13) & (opcode_14_12 == 3'h0);
    assign inst_andi      = (opcode_06_00 == 7'h13) & (opcode_14_12 == 3'h7);
    assign inst_jarl      = (opcode_06_00 == 7'h67) & (opcode_14_12 == 3'h0);
    assign inst_lb        = (opcode_06_00 == 7'h03) & (opcode_14_12 == 3'h0);
    assign inst_lbu       = (opcode_06_00 == 7'h03) & (opcode_14_12 == 3'h4);
    assign inst_lh        = (opcode_06_00 == 7'h03) & (opcode_14_12 == 3'h1);
    assign inst_lhu       = (opcode_06_00 == 7'h03) & (opcode_14_12 == 3'h5);
    assign inst_lw        = (opcode_06_00 == 7'h03) & (opcode_14_12 == 3'h2);
    assign inst_slti      = (opcode_06_00 == 7'h13) & (opcode_14_12 == 3'h2);
    assign inst_sltiu     = (opcode_06_00 == 7'h13) & (opcode_14_12 == 3'h3);
    assign inst_slli      = (opcode_06_00 == 7'h13) & (opcode_14_12 == 3'h1) & (opcode_31_26 == 6'h00);
    assign inst_sra       = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h5) & (opcode_31_26 == 6'h10);
    assign inst_srai      = (opcode_06_00 == 7'h13) & (opcode_14_12 == 3'h5) & (opcode_31_26 == 6'h10);
    assign inst_srl       = (opcode_06_00 == 7'h33) & (opcode_14_12 == 3'h5) & (opcode_31_26 == 6'h00);
    assign inst_srli      = (opcode_06_00 == 7'h13) & (opcode_14_12 == 3'h5) & (opcode_31_26 == 6'h00);
    assign inst_ori       = (opcode_06_00 == 7'h13) & (opcode_14_12 == 3'h6);
    assign inst_xori      = (opcode_06_00 == 7'h13) & (opcode_14_12 == 3'h4);
    assign inst_csrrw     = (opcode_06_00 == 7'h73) & (opcode_14_12 == 3'h1);
    assign inst_csrrs     = (opcode_06_00 == 7'h73) & (opcode_14_12 == 3'h2);
    assign inst_sb        = (opcode_06_00 == 7'h23) & (opcode_14_12 == 3'h0);
    assign inst_sh        = (opcode_06_00 == 7'h23) & (opcode_14_12 == 3'h1);
    assign inst_sw        = (opcode_06_00 == 7'h23) & (opcode_14_12 == 3'h2);
    assign inst_beq       = (opcode_06_00 == 7'h63) & (opcode_14_12 == 3'h0);
    assign inst_bne       = (opcode_06_00 == 7'h63) & (opcode_14_12 == 3'h1);
    assign inst_bge       = (opcode_06_00 == 7'h63) & (opcode_14_12 == 3'h5);
    assign inst_bgeu      = (opcode_06_00 == 7'h63) & (opcode_14_12 == 3'h7);
    assign inst_blt       = (opcode_06_00 == 7'h63) & (opcode_14_12 == 3'h4);
    assign inst_bltu      = (opcode_06_00 == 7'h63) & (opcode_14_12 == 3'h6);
    assign inst_auipc     = (opcode_06_00 == 7'h17);
    assign inst_lui       = (opcode_06_00 == 7'h37);
    assign inst_jal       = (opcode_06_00 == 7'h6f);
    assign inst_fence_i   = (opcode_06_00 == 7'h0f) & (rd == 5'h00) & (opcode_14_12 == 3'h1) & (rs1 == 5'h00) & (rs2 == 5'h00) & (opcode_31_25 == 7'h00);
    assign inst_mret      = (opcode_06_00 == 7'h73) & (rd == 5'h00) & (opcode_14_12 == 3'h0) & (rs1 == 5'h00) & (rs2 == 5'h02) & (opcode_31_25 == 7'h18);
    assign inst_ecall     = (opcode_06_00 == 7'h73) & (rd == 5'h00) & (opcode_14_12 == 3'h0) & (rs1 == 5'h00) & (rs2 == 5'h00) & (opcode_31_25 == 7'h00);
    assign inst_ebreak    = (opcode_06_00 == 7'h73) & (rd == 5'h00) & (opcode_14_12 == 3'h0) & (rs1 == 5'h00) & (rs2 == 5'h01) & (opcode_31_25 == 7'h00);
    assign inst_waiting   = (opcode_06_00 == 7'h00) & (rd == 5'h00) & (opcode_14_12 == 3'h0) & (rs1 == 5'h00) & (rs2 == 5'h00) & (opcode_31_25 == 7'h00);

    assign TYPE_R = (opcode_06_00 == 7'h33);
    assign TYPE_I = (opcode_06_00 == 7'h13) | rlsu_we | inst_jarl | inst_csrrw | inst_csrrs | inst_fence_i; 
    assign TYPE_S = (opcode_06_00 == 7'h23);
    assign TYPE_B = (opcode_06_00 == 7'h63);
    assign TYPE_U = inst_auipc  | inst_lui;
    assign TYPE_J = inst_jal;
    assign TYPE_N = inst_ebreak | inst_waiting;

    assign alu_op[ 0] = inst_add  | inst_addi | inst_auipc | inst_jal | inst_sb  |
                        inst_jarl | inst_lw   | inst_lbu   | inst_lh  | inst_lhu |
                        inst_sw   | inst_sh   | inst_lb    | TYPE_B;
    assign alu_op[ 1] = inst_sub;
    assign alu_op[ 2] = inst_slt  | inst_slti;
    assign alu_op[ 3] = inst_sltu | inst_sltiu;
    assign alu_op[ 4] = inst_and  | inst_andi;
    assign alu_op[ 5] = inst_or   | inst_ori;
    assign alu_op[ 6] = inst_xor  | inst_xori;
    assign alu_op[ 7] = inst_slli | inst_sll;
    assign alu_op[ 8] = inst_srli | inst_srl;
    assign alu_op[ 9] = inst_srai | inst_sra;
    assign alu_op[10] = inst_lui;

    assign alu_op[11] = inst_bne;
    assign alu_op[12] = inst_beq;
    assign alu_op[13] = inst_bge;
    assign alu_op[14] = inst_bgeu;
    assign alu_op[15] = inst_blt;
    assign alu_op[16] = inst_bltu;

    assign imm = ({32{TYPE_I}} & immI)
               | ({32{TYPE_S}} & immS)
               | ({32{TYPE_B}} & immB)
               | ({32{TYPE_U}} & immU)
               | ({32{TYPE_J}} & immJ);

    assign gpr_we = TYPE_R    | rlsu_we   |
                    inst_addi | inst_jarl | inst_sltiu| inst_srai  | inst_andi | 
                    inst_xori | inst_srli | inst_slli | inst_ori   | inst_csrrw|
                    inst_csrrs| inst_jal  | inst_auipc| inst_lui   | inst_slti;
    assign sw_sh_sb = opcode_14_12[1:0];
    assign lw_lh_lb = {inst_lw, (inst_lh | inst_lhu)};
    assign wlsu_we = TYPE_S;
    assign rlsu_we = (opcode_06_00 == 7'h03);

    assign src1_is_pc    = inst_jal | TYPE_B | inst_auipc;
    assign src2_is_imm   = TYPE_I   | TYPE_S | TYPE_J | TYPE_B | inst_lui | inst_auipc | inst_jarl;

    assign is_pc_jump   = inst_jal | inst_jarl;

    assign idu_ready = exu_ready;
    assign inst_not_realize = ~(TYPE_B | TYPE_I | TYPE_J | TYPE_N | TYPE_R | TYPE_S | TYPE_U | inst_mret | inst_ecall);

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            du_to_eu_bus <= 'b0;
        end else begin
            if (exu_ready) begin
                if (ifu_valid) begin
                    idu_valid <= ~exu_dnpc_valid;
                    du_to_eu_bus <= {
                        du_to_lu_bus,
                        pc,
                        lw_lh_lb,
                        sw_sh_sb,
                        inst_fence_i,         
                        imm,
                        rd[3:0],
                        rs1[3:0],
                        rs2[3:0],
                        wlsu_we,
                        rlsu_we,
                        gpr_we,  
                        alu_op,             
                        src1_is_pc,      
                        src2_is_imm,     
                        is_pc_jump,   
                        inst_ecall,
                        inst_mret,
                        inst_csrrs,
                        inst_csrrw,
                        inst_ebreak
                    };
                end else begin
                    idu_valid <= 1'b0;
                    du_to_eu_bus <= 'b0;
                end
            end
        end
    end

endmodule
