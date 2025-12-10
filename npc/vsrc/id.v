module ysyx_25050136_ID
    #(
        parameter ADDR_WIDTH = 4
    )
    (
        input                                                   clk,
        input                                                 reset,
        input                                                 flush,
        input                                            in_valid_i,
        input      [31:0]                                 in_inst_i,
        input      [31:0]                                   in_pc_i,
        input      [31:0]                                in_prepc_i,
        input                                            in_taken_i,
        input                                          in_btb_hit_i,
        output                                           in_ready_o,
        input                                           out_ready_i,
`ifdef YSYXSOC
        output     [31:0]                            out_dbg_inst_o,
        output     [5:0]                           out_dbg_optype_o,
`endif
        // 读操作数以及解决数据冒险
        input                                           ex_wvalid_i,
        input                                              ex_wen_i,
        input      [ADDR_WIDTH-1:0]                      ex_waddr_i,
        input      [31:0]                                ex_wdata_i,
        input                                          mem_wvalid_i,
        input                                             mem_wen_i,
        input      [ADDR_WIDTH-1:0]                     mem_waddr_i,
        input      [31:0]                               mem_wdata_i,
        input      [31:0]                              out_rdata1_i,
        output     [ADDR_WIDTH-1:0]                    out_raddr1_o,
        input      [31:0]                              out_rdata2_i,
        output     [ADDR_WIDTH-1:0]                    out_raddr2_o,
        // 分支预测
        output                                       branch_flush_o,
        output     [31:0]                              branch_npc_o,
        output                                         pht_update_o,
        output     [31:0]                                  pht_pc_o,
        output                                          pht_taken_o,
        // fence.i
        output                                       fencei_flush_o,
        // 传递给EX
        output     [31:0]                                  out_pc_o,
        output     [31:0]                                 out_npc_o,
        output                                         out_ebreak_o,
        output     [31:0]                               out_prepc_o,
        output                                        out_btb_hit_o,
        output     [31:0]                              out_rdata1_o,
        output     [31:0]                              out_rdata2_o,
        output     [31:0]                                 out_imm_o,
        output     [3:0]                               out_alu_op_o,
        output     [`ysyx_25050136_CSRU_OP_NUM-1:0]   out_csru_op_o,
        output                                 out_alu_op1_use_pc_o,
        output                                out_alu_op2_use_imm_o,
        output                                           out_jump_o,
        output                                     out_mispredict_o,
        output                                           out_jalr_o,
        output                                        out_lsu_ren_o,
        output                                        out_lsu_wen_o,
        output     [3:0]                             out_lsu_mask_o,
        output                                     out_lsu_signed_o,
        output     [11:0]                            out_csr_addr_o,
        output                                        out_csr_ren_o,
        output                                        out_csr_wen_o,
        output                              out_csr_wdata_use_rs1_o,
        output     [4:0]                                  out_rs1_o,
        output                                         out_rd_npc_o,
        output     [ADDR_WIDTH-1:0]                        out_rd_o,
        output                                          out_rd_en_o,
        output                                          out_valid_o
    );
    // ==== 信号定义 ====
    // 时序逻辑
    reg idle;
    reg in_pulse;
    reg [31:0] id_pc;
    reg [31:0] id_inst;
    reg [31:0] id_prepc;
    reg        id_taken;
    reg        id_btb_hit;
    // 组合逻辑
    wire in_fire = in_valid_i & in_ready_o;
    wire out_fire = out_valid_o & out_ready_i;
    wire ready_go;
    //=== 指令各段分解 ===
    wire [6:0] opcode = id_inst[6:0];
    wire [4:0] rd = id_inst[11:7];
    wire [4:0] rs1 = id_inst[19:15];
    wire [4:0] rs2 = id_inst[24:20];
    wire [2:0] funct3 = id_inst[14:12];
    wire [6:0] funct7 = id_inst[31:25];
    //=== opcode判断 ===
    wire type_load     = (opcode == 7'b0000011);
    wire type_op_imm   = (opcode == 7'b0010011);
    wire type_auipc    = (opcode == 7'b0010111);
    wire type_store    = (opcode == 7'b0100011);
    wire type_op       = (opcode == 7'b0110011);
    wire type_lui      = (opcode == 7'b0110111);
    wire type_branch   = (opcode == 7'b1100011);
    wire type_jalr     = (opcode == 7'b1100111);
    wire type_jal      = (opcode == 7'b1101111);
    wire type_system   = (opcode == 7'b1110011);
    // wire type_misc_lsu = (opcode == 7'b0001111);
    //=== funct3判断 ===
    wire funct3_000  = (funct3 == 3'b000);
    wire funct3_001  = (funct3 == 3'b001);
    wire funct3_010  = (funct3 == 3'b010);
    wire funct3_011  = (funct3 == 3'b011);
    wire funct3_100  = (funct3 == 3'b100);
    wire funct3_101  = (funct3 == 3'b101);
    wire funct3_110  = (funct3 == 3'b110);
    wire funct3_111  = (funct3 == 3'b111);
    // === funt7判断 ===
    wire funct7_0000000 = (funct7 == 7'b0000000);
    wire funct7_0100000 = (funct7 == 7'b0100000);
    // === 指令判断 ===
    // wire inst_lui = type_lui;
    // wire inst_auipc = type_auipc;
    // wire inst_jal = type_jal;
    // wire inst_jalr = type_jalr;
    wire inst_beq = type_branch & funct3_000;
    wire inst_bne = type_branch & funct3_001;
    wire inst_blt = type_branch & funct3_100;
    wire inst_bge = type_branch & funct3_101;
    wire inst_bltu = type_branch & funct3_110;
    wire inst_bgeu = type_branch & funct3_111;
    wire inst_lb = type_load & funct3_000;
    wire inst_lh = type_load & funct3_001;
    wire inst_lw = type_load & funct3_010;
    wire inst_lbu = type_load & funct3_100;
    wire inst_lhu = type_load & funct3_101;
    wire inst_sb = type_store & funct3_000;
    wire inst_sh = type_store & funct3_001;
    wire inst_sw = type_store & funct3_010;
    wire inst_addi = type_op_imm & funct3_000;
    wire inst_slti = type_op_imm & funct3_010;
    wire inst_sltiu = type_op_imm & funct3_011;
    wire inst_xori = type_op_imm & funct3_100;
    wire inst_ori = type_op_imm & funct3_110;
    wire inst_andi = type_op_imm & funct3_111;
    wire inst_slli = type_op_imm & funct3_001;
    wire inst_srli = type_op_imm & funct3_101 & funct7_0000000;
    wire inst_srai = type_op_imm & funct3_101 & funct7_0100000;
    wire inst_add = type_op & funct3_000 & funct7_0000000;
    wire inst_sub = type_op & funct3_000 & funct7_0100000;
    wire inst_sll = type_op & funct3_001;
    wire inst_slt = type_op & funct3_010;
    wire inst_sltu = type_op & funct3_011;
    wire inst_xor = type_op & funct3_100;
    wire inst_srl = type_op & funct3_101;
    wire inst_sra = type_op & funct3_101 & funct7_0100000;
    wire inst_or = type_op & funct3_110;
    wire inst_and = type_op & funct3_111;
    wire inst_csrrw = type_system & funct3_001;
    wire inst_csrrs = type_system & funct3_010;
    wire inst_csrrc = type_system & funct3_011;
    wire inst_csrrwi = type_system & funct3_101;
    wire inst_csrrsi = type_system & funct3_110;
    wire inst_csrrci = type_system & funct3_011;
    wire inst_mret = (id_inst == 32'h30200073);
    wire inst_ecall = (id_inst == 32'h00000073);
    wire inst_ebreak = (id_inst == 32'h00100073);
    wire inst_fence_i = (id_inst == 32'h0000100F);
    // === 指令类型判断 ===
    // wire inst_Rtype = type_op;
    wire inst_Itype = type_op_imm | type_load | type_jalr;
    wire inst_Stype = type_store;
    wire inst_Utype = type_auipc | type_lui;
    wire inst_Btype = type_branch;
    wire inst_Jtype = type_jal;
    // === 用于得到立即数和读操作数 ===
    wire [31:0] immI = inst_srai ? {27'd0, id_inst[24:20]} : {{20{id_inst[31]}}, id_inst[31:20]};
    wire [31:0] immS = {{20{id_inst[31]}}, id_inst[31:25], id_inst[11:7]};
    wire [31:0] immB = {{20{id_inst[31]}}, id_inst[7], id_inst[30:25], id_inst[11:8], 1'b0};
    wire [31:0] immU = {id_inst[31:12], 12'h0};
    wire [31:0] immJ = {{12{id_inst[31]}}, id_inst[19:12], id_inst[20], id_inst[30:21], 1'b0};
    // === 跳转相关 ===
    wire [31:0] bqu_op1;
    wire [31:0] bqu_op2;
    wire [5:0]  bqu_op;
    wire        bqu_out;
    // === 数据冒险 ===
    wire raw1_hazard;
    wire raw2_hazard;
    wire ren1, ren2;
    // ==== 逻辑实现 ====
    always @(posedge clk) begin
        if(reset) begin
            idle <= 1;
            in_pulse <= 0;
            // id_pc <= 0;
            // id_inst <= 0;
            // id_prepc <= 0;
            // id_taken <= 0;
            // id_btb_hit <= 0;
        end else begin
            idle <= (flush) | (!in_fire & out_fire) | (!in_fire & !flush & idle);
            in_pulse <= !flush & in_fire;
            if(in_fire) begin
                id_pc <= in_pc_i;
                id_inst <= in_inst_i;
                id_prepc <= in_prepc_i;
                id_taken <= in_taken_i;
                id_btb_hit <= in_btb_hit_i;
            end
        end
    end
    // === 读操作数与数据冒险 ===
    assign raw1_hazard = (out_raddr1_o != 0) && ren1 && (((out_raddr1_o == ex_waddr_i)  && !ex_wvalid_i  && ex_wen_i) ||
                                                         ((out_raddr1_o == mem_waddr_i) && !mem_wvalid_i && mem_wen_i));
    assign raw2_hazard = (out_raddr2_o != 0) && ren2 && (((out_raddr2_o == ex_waddr_i)  && !ex_wvalid_i  && ex_wen_i) ||
                                                         ((out_raddr2_o == mem_waddr_i) && !mem_wvalid_i && mem_wen_i));
    assign ready_go = !(raw1_hazard | raw2_hazard);
    assign out_raddr1_o = rs1[ADDR_WIDTH-1:0];
    assign out_raddr2_o = rs2[ADDR_WIDTH-1:0];
    assign ren1 = ~(type_lui | type_auipc | type_jal | inst_csrrwi | inst_csrrsi | inst_csrrci);
    assign ren2 = type_branch | type_store | type_op;
    // === 选择ALU相关操作 ===
    assign out_alu_op_o = 
        (type_auipc | type_store | type_load | inst_addi | inst_add | type_jalr | type_jal | type_branch) ? 4'd1 :
        (inst_sub)                               ? 4'd2 :
        (inst_xor | inst_xori)                   ? 4'd3 :
        (inst_or  | inst_ori)                    ? 4'd4 :
        (inst_and | inst_andi)                   ? 4'd5 :
        (inst_sltiu | inst_sltu)                 ? 4'd6 :
        (inst_slti | inst_slt)                   ? 4'd7 :
        (inst_srai | inst_sra)                   ? 4'd8 :
        (inst_slli | inst_sll)                   ? 4'd9 :
        (inst_srli | inst_srl)                   ? 4'd10 :
        (type_lui)                               ? 4'd11 :
                                                   0; // 默认操作，例如对于无效指令

    // === 选择CSRU相关操作 ===
    assign out_csru_op_o[`ysyx_25050136_CSRU_CSRRW] = inst_csrrw | inst_csrrwi;
    assign out_csru_op_o[`ysyx_25050136_CSRU_CSRRS] = inst_csrrs | inst_csrrsi;
    assign out_csru_op_o[`ysyx_25050136_CSRU_CSRRC] = inst_csrrc | inst_csrrci;
    assign out_csru_op_o[`ysyx_25050136_CSRU_MRET]  = inst_mret;
    assign out_csru_op_o[`ysyx_25050136_CSRU_ECALL] = inst_ecall;
    // === 选择ALU的操作数 ===
    assign out_alu_op1_use_pc_o = type_auipc | type_branch | type_jal;
    assign out_alu_op2_use_imm_o = type_load | type_store | type_op_imm | type_auipc | type_lui | type_branch | type_jalr | type_jal;
    // === 选择BQU的操作数, 并判断跳转 ===
    assign bqu_op1 = out_rdata1_o;
    assign bqu_op2 = out_rdata2_o;
    assign bqu_op = {inst_bgeu, inst_bltu, inst_bge, inst_blt, inst_bne, inst_beq};
    ysyx_25050136_BQU u_bqu (
        .op1_i      (bqu_op1),
        .op2_i      (bqu_op2),
        .op_i       (bqu_op),
        .out_o      (bqu_out)
    );
    assign pht_update_o = (type_branch | type_jal | type_jalr | inst_ecall | inst_mret) & in_pulse;
    assign pht_pc_o = id_pc;
    assign pht_taken_o = out_jump_o;
    assign out_jump_o = bqu_out | type_jal | type_jalr | inst_ecall | inst_mret;
    assign branch_flush_o = !(type_branch | type_jal | type_jalr | inst_ecall | inst_mret) && id_btb_hit && id_taken && in_pulse;
    assign branch_npc_o = out_npc_o;
    assign out_jalr_o = type_jalr;
    assign out_mispredict_o = (type_branch | type_jal | type_jalr | inst_ecall | inst_mret) & (out_jump_o ^ (id_taken & id_btb_hit)); // 预测错误
    assign out_prepc_o = id_prepc;
    assign out_btb_hit_o = id_btb_hit;
    // === fence.i ===
    assign fencei_flush_o = inst_fence_i & in_pulse;
    assign out_ebreak_o = inst_ebreak & in_pulse;
    // === 访存相关 ===
    assign out_lsu_ren_o = type_load;
    assign out_lsu_wen_o = type_store;
    assign out_lsu_mask_o = (inst_lw | inst_sw) ? 4'hF :
           ((inst_sh | inst_lhu | inst_lh) ? 4'h3 :
            ((inst_sb | inst_lbu | inst_lb) ? 4'h1 : 0));
    assign out_lsu_signed_o = (inst_lhu | inst_lbu) ? 0 : 1;
    // === 选择CSR的操作数 ===
    assign out_csr_addr_o = inst_ecall ? 12'h305: (inst_mret ? 12'h341 : id_inst[31:20]);// 作为csr指令的地址，以及ecall/mret的读地址
    assign out_csr_ren_o = (type_system & ~inst_ebreak) & !((inst_csrrw | inst_csrrwi) && (rd == 0));
    assign out_csr_wen_o = (type_system & ~inst_ebreak) & !((inst_csrrs | inst_csrrsi | inst_csrrc | inst_csrrci) && (rs1 == 0));
    assign out_csr_wdata_use_rs1_o = inst_csrrw | inst_csrrs | inst_csrrc;
    // === 写回寄存器地址 ===
    assign out_rd_npc_o = type_jalr | type_jal;
    assign out_rd_o  = rd[ADDR_WIDTH-1:0];
    assign out_rd_en_o = type_op_imm | type_auipc | type_lui | type_op | type_system | type_load | type_jalr | type_jal;
    // === 操作数 ===
    assign out_pc_o = id_pc;
    assign out_npc_o = id_pc + 4;
    assign out_rdata1_o = ((out_raddr1_o != 0) && (out_raddr1_o == ex_waddr_i) && ex_wvalid_i) ? ex_wdata_i :
                          ((out_raddr1_o != 0) && (out_raddr1_o == mem_waddr_i) && mem_wvalid_i) ? mem_wdata_i :
                          out_rdata1_i;
    assign out_rdata2_o =((out_raddr2_o != 0) && (out_raddr2_o == ex_waddr_i) && ex_wvalid_i) ? ex_wdata_i :
                         ((out_raddr2_o != 0) && (out_raddr2_o == mem_waddr_i) && mem_wvalid_i) ? mem_wdata_i :
                         out_rdata2_i;
    assign out_imm_o = inst_Itype ? immI :
                          (inst_Stype ? immS :
                          (inst_Utype ? immU :
                          (inst_Btype ? immB :
                          (inst_Jtype ? immJ :
                            32'b0))));
    assign out_rs1_o = rs1;
    // === 握手信号 ===
    assign in_ready_o = idle || out_fire;
    assign out_valid_o = !(idle || flush) && ready_go;
`ifdef YSYXSOC
    wire [31:0] id_dbg_pc = out_pc_o;
    assign out_dbg_inst_o = id_inst;
    assign out_dbg_optype_o = {type_jalr | type_jal, type_branch, type_load, type_store, type_system, type_op_imm | type_auipc | type_lui | type_op};
`ifdef EVENT_COUNTER
    always @(posedge clk) begin
        if(!reset) begin
            if(!ready_go) related_delay_get();
            if(branch_flush_o) predict_not_jump_count();
        end
    end
`endif
`endif

endmodule
