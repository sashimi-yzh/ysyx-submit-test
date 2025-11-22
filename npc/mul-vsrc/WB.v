`include "/home/furina/ysyx-workbench/npc/mul-vsrc/defines.v"
module WB (
    input              clk,
    input              reset,
    input              mem_valid,
    input              if_ready,
    input       [6:0]  opcode,
    input       [2:0]  func3,
    input       [4:0]  id_rd,
    input              id_RegWrite,
    input       [4:0]  rs1,
    input       [4:0]  rs2,
    input       [31:0] pc,
    input       [31:0] imm,
    input              alu_zero,
    input              alu_less,
    input       [31:0] alu_result,
    input       [31:0] data_out,
    // input              predict_taken,
    // input       [1:0]  ghr,
    output wire [31:0] rs1_val,
    output wire [31:0] rs2_val,
    output reg         wb_ready,
    output reg         wb_valid,
    output reg [31:0]  jal_target,
    output reg [31:0]  jalr_target,
    output reg         is_jal,
    output reg         is_jalr,
    output reg         take_branch,
    output reg [31:0]  wb_data
    // output reg         flush,
    // output reg [31:0]  actual_target,
    // output reg [31:0]  branch_total,   // 总分支次数
    // output reg [31:0]  branch_correct, // 预测正确次数
    // output reg [1:0]   ghr_update
);
    typedef enum {IDLE, STALL} state_t;
    state_t state, next_state;

    reg        RegWrite_wb;
    reg [4:0]  rd_wb;
    reg [4:0]  rd_wb_pre;
    reg [31:0] regs [0:31];
    assign rs1_val = (rs1 != 0) ? regs[rs1] : 0;
    assign rs2_val = (rs2 != 0) ? regs[rs2] : 0;

    // BTB
    reg [31:0] btb_pc [0:63];
    reg [31:0] btb_target [0:63];
    reg [1:0]  btb_state [0:63];
    reg [63:0] btb_valid;
    reg [1:0]  btb_type [0:63]; // 00: INST_B, 01: jal, 10: jalr
    wire [5:0] btb_index = pc[7:2];

    // PHT
    reg [1:0]  pht_counters [0:63][0:3];
    integer i, j;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state = STALL;
            wb_ready = 1'b1;
            wb_valid = 1'b1;
            jal_target = 32'h0;
            jalr_target = 32'h0;
            is_jal = 1'b0;
            is_jalr = 1'b0;
            take_branch = 1'b0;
            wb_data = 32'h0;
            // flush <= 1'b0;
            // actual_target <= 32'h0;
            // branch_total <= 32'h0;
            // branch_correct <= 32'h0;
            for(i = 0; i < 32; i = i + 1) begin
                regs[i] <= 32'h0;
            end
            // for (i = 0; i < 64; i = i + 1) begin
            //     btb_pc[i] <= 32'h0;
            //     btb_target[i] <= 32'h0;
            //     btb_state[i] <= 2'b00;
            //     btb_valid[i] <= 1'b0;
            //     btb_type[i] <= 2'b00;
            //     for (j = 0; j < 4; j = j + 1) begin
            //         pht_counters[i][j] <= 2'b00;
            //     end
            // end
        end else begin
            state = next_state;
            case (state)
                IDLE: begin
                    wb_ready = 1'b1;
                    wb_valid = 1'b0;
                    if(mem_valid) begin
                        wb_ready = 1'b0;
                        wb_valid = 1'b0;
                        jal_target = pc + imm;
                        jalr_target = (rs1_val + imm) & ~32'h1;
                        is_jal = (opcode == `INST_JAL);
                        is_jalr = (opcode == `INST_JALR) & (func3 == 3'b000);
                        take_branch = (opcode == `INST_B) && (
                            (func3 == `F3_BNE && !alu_zero) || // bne
                            (func3 == `F3_BEQ && alu_zero) ||  // beq
                            (func3 == `F3_BLT && alu_less) ||  // blt
                            (func3 == `F3_BGE && !alu_less) || // bge
                            (func3 == `F3_BLTU && alu_less) || // bltu
                            (func3 == `F3_BGEU && !alu_less)   // bgeu
                        );

                        // 写回数据选择
                        wb_data = (opcode == `INST_LUI) ? imm :                   // LUI
                                        (opcode == `INST_AUIPC) ? (pc + imm) :          // AUIPC
                                        (opcode == `INST_JAL || opcode == `INST_JALR) ? (pc + 4) : // JAL, JALR
                                        (opcode == `INST_LW) ? data_out :              // LW
                                        (opcode == `INST_R || opcode == `INST_I) ? alu_result : 32'b0; // R-type, I-type
                        //=====写回数据=====
                        rd_wb = id_rd;
                        rd_wb_pre = rd_wb;
                        RegWrite_wb = id_RegWrite;
                        if(RegWrite_wb && rd_wb_pre != 0) begin
                            regs[rd_wb_pre] <= wb_data;
                        end

                    //    // BTB、PHT 和分支统计更新
                    //     if (opcode == `INST_B) begin
                    //         btb_pc[btb_index] <= pc;
                    //         btb_target[btb_index] <= pc + imm;
                    //         btb_valid[btb_index] <= 1'b1;
                    //         btb_state[btb_index] <= take_branch ?
                    //             (btb_state[btb_index] == 2'b11 ? 2'b11 : btb_state[btb_index] + 2'b01) :
                    //             (btb_state[btb_index] == 2'b00 ? 2'b00 : btb_state[btb_index] - 2'b01);
                    //         pht_counters[btb_index][ghr] <= take_branch ?
                    //             (pht_counters[btb_index][ghr] == 2'b11 ? 2'b11 : pht_counters[btb_index][ghr] + 2'b01) :
                    //             (pht_counters[btb_index][ghr] == 2'b00 ? 2'b00 : pht_counters[btb_index][ghr] - 2'b01);
                    //         branch_total <= branch_total + 1;
                    //         if (take_branch == predict_taken) begin
                    //             branch_correct <= branch_correct + 1;
                    //         end
                    //         flush <= (take_branch != predict_taken);
                    //         actual_target <= take_branch ? (pc + imm) : (pc + 4);
                    //         ghr_update <= {ghr[0], take_branch};
                    //     end else if (opcode == `INST_JAL) begin
                    //         flush <= 1'b1; // jal 不预测，强制冲刷
                    //         actual_target <= pc + imm;
                    //         ghr_update <= ghr;
                    //     end else if (opcode == `INST_JALR && func3 == 3'b000) begin
                    //         flush <= 1'b1; // jalr 不预测，强制冲刷
                    //         actual_target <= (rs1_val + imm) & ~32'h1;
                    //         ghr_update <= ghr;
                    //     end else begin
                    //         flush <= 1'b0;
                    //         actual_target <= pc + 4;
                    //         ghr_update <= ghr;
                    //     end

                        next_state = if_ready ? STALL : IDLE;
                    end else begin
                        // flush <= 1'b0;
                        // actual_target <= pc + 4;
                        // ghr_update <= ghr;
                        next_state = IDLE;
                    end
                end
                STALL: begin
                    wb_ready = 1'b0;
                    wb_valid = 1'b1;
                    next_state = if_ready ? IDLE : STALL;
                end
                default: begin
                    wb_ready = 1'b0;
                    wb_valid = 1'b0;
                    // flush <= 1'b0;
                    // actual_target <= 32'h0;
                    next_state = IDLE;
                end
            endcase
        end
    end

endmodule