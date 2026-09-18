module ysyx_26010027_IDU (
    input             clock,
    input             reset,

    input             ifu_idu_valid,
    output            idu_ifu_ready,
    input  [31:0]     ifu_idu_pc,
    input  [31:0]     ifu_idu_inst,

    // IDU - EXU
    input             exu_idu_ready,
    output reg        idu_exu_valid,
    output reg [31:0] idu_exu_pc,
    output reg [31:0] idu_exu_inst,

    output reg [31:0] idu_exu_target,
    output reg [31:0] idu_exu_imm,
    output reg [ 3:0] idu_exu_alu_op,
    output reg [ 1:0] idu_exu_mem_w,
    output reg [ 2:0] idu_exu_mem_r,
    output reg        idu_exu_alu_arc1,
    output reg        idu_exu_alu_arc2,
    output reg        idu_exu_reg_w,
    output reg [ 1:0] idu_exu_rf_res,
    output reg [ 3:0] idu_exu_waddr,

    output reg [ 1:0] idu_exu_jump,
    output reg [ 2:0] idu_exu_branch,
    output reg        idu_exu_fencei,
    input             exu_flush,

    output reg [ 3:0] idu_exu_raddr1, idu_exu_raddr2,

    output reg [11:0] idu_exu_csr_addr,
    output reg        idu_exu_csr_we,
    output reg        idu_exu_csr_ecall,
    output reg        idu_exu_csr_mret

);

    // ----- Instruction decoding -----
    wire [31:0] inst   = ifu_idu_inst;
    wire [ 6:0] opcode = inst[6:0];
    wire [ 2:0] funct3 = inst[14:12];
    wire [ 6:0] funct7 = inst[31:25];

    // Instruction type
    wire inst_I = (opcode == 7'b0010011) || (opcode == 7'b0000011) ||
                  (opcode == 7'b1100111) || (opcode == 7'b1110011);
    wire inst_U = (opcode == 7'b0110111) || (opcode == 7'b0010111);
    wire inst_B = (opcode == 7'b1100011);
    wire inst_S = (opcode == 7'b0100011);
    wire inst_J = (opcode == 7'b1101111);
    wire inst_R = (opcode == 7'b0110011);

    // Sub-type
    wire I_a = (opcode == 7'b0010011);  // arithmetic I-type
    wire I_b = (opcode == 7'b0000011);  // load
    wire I_c = (opcode == 7'b1110011);  // CSR

    // I-type instructions
    wire addi  = I_a && (funct3 == 3'b000);
    wire slti  = I_a && (funct3 == 3'b010);
    wire slli  = I_a && (funct3 == 3'b001);
    wire srli  = I_a && (funct3 == 3'b101) && (funct7 == 7'b0000000);
    wire srai  = I_a && (funct3 == 3'b101) && (funct7 == 7'b0100000);
    wire sltiu = I_a && (funct3 == 3'b011);
    wire xori  = I_a && (funct3 == 3'b100);
    wire ori   = I_a && (funct3 == 3'b110);
    wire andi  = I_a && (funct3 == 3'b111);
    wire lbu   = I_b && (funct3 == 3'b100);
    wire lhu   = I_b && (funct3 == 3'b101);
    wire lw    = I_b && (funct3 == 3'b010);
    wire lh    = I_b && (funct3 == 3'b001);
    wire lb    = I_b && (funct3 == 3'b000);
    wire jalr  = (opcode == 7'b1100111);

    wire ld_type = lbu || lhu || lw || lh || lb;

    // R-type instructions
    wire add   = inst_R && (funct3 == 3'b000) && (funct7 == 7'b0000000);
    wire sub   = inst_R && (funct3 == 3'b000) && (funct7 == 7'b0100000);
    wire sll   = inst_R && (funct3 == 3'b001);
    wire slt   = inst_R && (funct3 == 3'b010);
    wire sltu  = inst_R && (funct3 == 3'b011);
    wire srl   = inst_R && (funct3 == 3'b101) && (funct7 == 7'b0000000);
    wire sra   = inst_R && (funct3 == 3'b101) && (funct7 == 7'b0100000);
    wire r_xor = inst_R && (funct3 == 3'b100);
    wire r_or  = inst_R && (funct3 == 3'b110);
    wire r_and = inst_R && (funct3 == 3'b111);

    // S-type instructions
    wire sw = inst_S && (funct3 == 3'b010);
    wire sb = inst_S && (funct3 == 3'b000);
    wire sh = inst_S && (funct3 == 3'b001);

    // B-type instructions
    wire bne  = inst_B && (funct3 == 3'b001);
    wire beq  = inst_B && (funct3 == 3'b000);
    wire blt  = inst_B && (funct3 == 3'b100);
    wire bge  = inst_B && (funct3 == 3'b101);
    wire bltu = inst_B && (funct3 == 3'b110);
    wire bgeu = inst_B && (funct3 == 3'b111);

    // U-type & J-type
    wire lui   = (opcode == 7'b0110111);
    wire auipc = (opcode == 7'b0010111);
    wire jal   = inst_J;

    // Immediate generation
    wire [31:0] imm = (inst_I) ? {{20{inst[31]}}, inst[31:20]} :
                (inst_S) ? {{20{inst[31]}}, inst[31:25], inst[11:7]} :
                (inst_U) ? {inst[31:12], 12'b0} :
                (inst_J) ? {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0} :
                32'b0;
    wire [31:0] b_imm = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};

    // CSR instructions
    wire csrrw    = I_c && (funct3 == 3'b001);
    wire csrrs    = I_c && (funct3 == 3'b010);
    wire csrrc    = I_c && (funct3 == 3'b011);
    wire csr_ecall = (inst == 32'h00000073);
    wire csr_mret  = (inst == 32'h30200073);
    wire [11:0] csr_addr = imm[11:0];

    // --------------------------


    // Control signals
    wire [1:0] jump = jalr      ? 2'b01 :
                      csr_ecall ? 2'b10 :
                      csr_mret  ? 2'b11 :
                      2'b00; // jal

    wire [2:0] branch = bne  ? 3'd0 :
                        beq  ? 3'd1 :
                        blt  ? 3'd2 :
                        bge  ? 3'd3 :
                        bltu ? 3'd4 :
                        bgeu ? 3'd5 :
                        3'd6;

    wire [1:0] rf_res = ld_type                   ? 2'b01 :  // memory
                        (csrrw || csrrs || csrrc) ? 2'b10 :  // CSR
                        (jal || jalr)             ? 2'b11 :  // PC+4
                        2'b00; // ALU

    wire [3:0] alu_op = sub             ? 4'd1  :
                        lui             ? 4'd2  :
                        (sll || slli)   ? 4'd3  :
                        (srl || srli)   ? 4'd4  :
                        (sra || srai)   ? 4'd5  :
                        (slt || slti)   ? 4'd6  :
                        (sltiu || sltu) ? 4'd7  :
                        (r_xor || xori) ? 4'd8  :
                        (r_and || andi) ? 4'd9  :
                        (r_or  || ori)  ? 4'd10 :
                        inst_B          ? 4'd11 :
                        csrrw           ? 4'd12 :
                        csrrs           ? 4'd13 :
                        4'd0; // 加法alu

    wire alu_arc1 = (jal || auipc);                        // 0: src1, 1: pc
    wire alu_arc2 = (inst_I || inst_S || auipc || inst_J); // 0: src2, 1: imm

    wire reg_w = (inst_I || inst_R || inst_J || inst_U);

    wire [1:0] mem_w = sw ? 2'b00 :
                       sb ? 2'b01 :
                       sh ? 2'b10 :
                       2'b11;

    wire [2:0] mem_r = lw  ? 3'd0 :
                       lb  ? 3'd1 :
                       lh  ? 3'd2 :
                       lbu ? 3'd3 :
                       lhu ? 3'd4 :
                       3'd5;

    wire fence_i = (inst == 32'h0000100F);
    wire ebreak  = (inst == 32'h00100073);
    
    wire [31:0] target = ifu_idu_pc + b_imm; // branch
    wire [ 3:0] raddr1 = inst[18:15];
    wire [ 3:0] raddr2 = inst[23:20];
    wire [ 3:0] waddr  = inst[10:7];

  // handshake
    assign idu_ifu_ready = exu_idu_ready | !idu_exu_valid;
    always @(posedge clock or posedge reset) begin
      if (reset) begin
        idu_exu_valid <= 1'b0;
      end 
      else if (exu_flush) begin
        idu_exu_valid <= 1'b0;
      end 
      else if (ifu_idu_valid & idu_ifu_ready) begin
        idu_exu_valid <= 1'b1;
      end 
      else if (exu_idu_ready) begin
        idu_exu_valid <= 1'b0;
      end
    end

    always @(posedge clock, posedge reset) begin
      if (reset) begin
        idu_exu_raddr1 <= 4'b0;
        idu_exu_raddr2 <= 4'b0;
      end
      else if (ifu_idu_valid && idu_ifu_ready) begin
        idu_exu_pc       <= ifu_idu_pc;
        idu_exu_inst     <= ifu_idu_inst;
        idu_exu_target   <= target; // pc + imm
        idu_exu_imm      <= imm;
        idu_exu_alu_op   <= alu_op; // ALU 算术选择
        idu_exu_mem_w    <= mem_w;
        idu_exu_mem_r    <= mem_r;
        idu_exu_alu_arc1 <= alu_arc1; // ALU 源操作数选择
        idu_exu_alu_arc2 <= alu_arc2;
        idu_exu_reg_w    <= reg_w;
        idu_exu_rf_res   <= rf_res; // GPR的rf-result 写入结果选择
        idu_exu_waddr    <= waddr;
        idu_exu_jump     <= jump; // 跳转 包括异常
        idu_exu_branch   <= branch; // 分支
        idu_exu_fencei   <= fence_i;

        idu_exu_raddr1    <= raddr1;
        idu_exu_raddr2    <= raddr2;

        idu_exu_csr_addr  <= csr_addr;
        idu_exu_csr_we    <= csrrw;
        idu_exu_csr_ecall <= csr_ecall;
        idu_exu_csr_mret  <= csr_mret;

      end

    end


`ifdef NPC_SIM
    // Illegal instruction detection
    wire i_inst  = addi || slti || slli || srli || srai || sltiu ||
                   xori || ori || andi || lbu || lhu || lw || lh || lb || jalr;

    wire r_inst = add || sub || sll || slt || sltu || srl || sra ||
                  r_xor || r_or || r_and;

    wire s_inst = sw || sb || sh;

    wire b_inst = bne || beq || blt || bge || bltu || bgeu;

    wire csr_inst  = csrrw || csrrs || csrrc || csr_ecall || csr_mret;

    wire illegal = !(i_inst || r_inst || s_inst || b_inst ||
                     lui || auipc || jal || csr_inst || ebreak || fence_i);

    always @(posedge clock)
      if (ifu_idu_valid && idu_ifu_ready && !exu_flush && illegal && (inst != 32'b0))
        is_illegal_inst();
`endif

endmodule
