module ysyx_25050136_EX
    #(
        parameter ADDR_WIDTH = 4
     )
     (
        // 内部
        input                                                clk,
        input                                              reset,
        input                                              flush,
        input                                         in_valid_i,
        input     [31:0]                                 in_pc_i,
        input     [31:0]                                in_npc_i,
        input                                        in_ebreak_i,
        input     [31:0]                              in_prepc_i,
        input                                       in_btb_hit_i,
        input     [31:0]                             in_rdata1_i,
        input     [31:0]                             in_rdata2_i,
        input     [31:0]                                in_imm_i,
        input     [3:0]                              in_alu_op_i,
        input     [`ysyx_25050136_CSRU_OP_NUM-1:0]  in_csru_op_i,
        input                                in_alu_op1_use_pc_i,
        input                               in_alu_op2_use_imm_i,
        input                                          in_jump_i,
        input                                    in_mispredict_i,
        input                                          in_jalr_i,
        input                                       in_lsu_ren_i,
        input                                       in_lsu_wen_i,
        input     [3:0]                            in_lsu_mask_i,
        input                                    in_lsu_signed_i,
        input     [11:0]                           in_csr_addr_i,
        input                                       in_csr_ren_i,
        input                                       in_csr_wen_i,
        input                             in_csr_wdata_use_rs1_i,
        input     [4:0]                                 in_rs1_i,
        input                                        in_rd_npc_i,
        input     [ADDR_WIDTH-1:0]                       in_rd_i,
        input                                         in_rd_en_i,
        output                                        in_ready_o,
`ifdef YSYXSOC
        input      [31:0]                          in_dbg_inst_i,
        input      [5:0]                         in_dbg_optype_i,
        output     [31:0]                           out_dbg_pc_o,
        output reg [31:0]                         out_dbg_inst_o,
        output reg [5:0]                        out_dbg_optype_o,
`endif
        input                                        out_ready_i,
        output                                      out_ebreak_o,
        output    [ADDR_WIDTH-1:0]                      out_rd_o,
        output                                       out_rd_en_o,
        output    [31:0]                         out_gpr_wdata_o,
        output                                     out_lsu_ren_o,
        output                                     out_lsu_wen_o,
        output    [3:0]                           out_lsu_mask_o,
        output                                  out_lsu_signed_o,
        output    [31:0]                          out_lsu_addr_o,
        output    [31:0]                         out_lsu_wdata_o,
        output                                       out_valid_o,
        // 分支
        output                                      btb_update_o,
        output    [31:0]                                btb_pc_o,
        output    [31:0]                            btb_target_o,
        output                                    branch_flush_o,
        output    [31:0]                            branch_npc_o,
        // 旁路
        output                                             wen_o,
        output                                          wvalid_o,   
        output    [ADDR_WIDTH-1:0]                       waddr_o,
        output    [31:0]                                 wdata_o    
     );
    // ==== 信号定义 ====
    // 时序逻辑
    reg idle;
    reg in_pulse;
    reg [31:0] ex_pc;
    reg [31:0] ex_npc;
    reg ex_ebreak;
    reg [31:0] ex_prepc;
    reg ex_btb_hit;
    reg [31:0] ex_rdata1;
    reg [31:0] ex_rdata2;
    reg [31:0] ex_imm;
    reg [3:0] ex_alu_op;
    reg [`ysyx_25050136_CSRU_OP_NUM-1:0] ex_csru_op;
    reg ex_alu_op1_use_pc;
    reg ex_alu_op2_use_imm;
    reg ex_jump;
    reg ex_mispredict;
    reg ex_jalr;
    reg ex_lsu_ren;
    reg ex_lsu_wen;
    reg [3:0] ex_lsu_mask;
    reg ex_lsu_signed;
    reg [11:0] ex_csr_addr;
    reg ex_csr_ren;
    reg ex_csr_wen;
    reg ex_csr_wdata_use_rs1;
    reg [4:0] ex_rs1;
    reg ex_rd_npc;
    reg [ADDR_WIDTH-1:0] ex_rd;
    reg ex_rd_en;
    // 组合逻辑
    wire in_fire = in_valid_i & in_ready_o;
    wire out_fire = out_valid_o & out_ready_i;

    // === ALU ===
    wire [31:0] alu_opd1;
    wire [31:0] alu_opd2;
    wire [31:0] alu_out; 
    // === 跳转 ===
    wire [31:0] branch_npc;
    wire target_mismatch = (ex_prepc != branch_npc);  // 预测目标与实际目标不匹配
    wire [31:0] bqu_opd1;
    wire [31:0] bqu_opd2;
    wire [31:0] bqu_add_result;
    wire [31:0] bqu_out;
    // === CSRU ===
    wire [31:0] csru_wdata;
    wire [31:0] csru_out;
    
    // ==== 逻辑实现 ====
    always @(posedge clk) begin
        if(reset) begin
            idle <= 1;
            in_pulse <= 0;
        end else begin
            idle <= (flush) | (!in_fire & out_fire) | (!in_fire & !flush & idle);
            in_pulse <= !flush & in_fire;
            if(in_fire) begin
                ex_pc <= in_pc_i;
                ex_npc <= in_npc_i;
                ex_ebreak <= in_ebreak_i;
                ex_prepc <= in_prepc_i;
                ex_btb_hit <= in_btb_hit_i;
                ex_rdata1 <= in_rdata1_i;
                ex_rdata2 <= in_rdata2_i;
                ex_imm <= in_imm_i;
                ex_alu_op <= in_alu_op_i;
                ex_csru_op <= in_csru_op_i;
                ex_alu_op1_use_pc <= in_alu_op1_use_pc_i;
                ex_alu_op2_use_imm <= in_alu_op2_use_imm_i;
                ex_jump <= in_jump_i;
                ex_mispredict <= in_mispredict_i;
                ex_jalr <= in_jalr_i;
                ex_lsu_ren <= in_lsu_ren_i;
                ex_lsu_wen <= in_lsu_wen_i;
                ex_lsu_mask <= in_lsu_mask_i;
                ex_lsu_signed <= in_lsu_signed_i;
                ex_csr_addr <= in_csr_addr_i;
                ex_csr_ren <= in_csr_ren_i;
                ex_csr_wen <= in_csr_wen_i;
                ex_csr_wdata_use_rs1 <= in_csr_wdata_use_rs1_i;
                ex_rs1 <= in_rs1_i;
                ex_rd_npc <= in_rd_npc_i;
                ex_rd <= in_rd_i;
                ex_rd_en <= in_rd_en_i;
            end
        end
    end
    // === ALU ===
    assign alu_opd1 = ex_alu_op1_use_pc ? ex_pc : ex_rdata1;
    assign alu_opd2 = ex_alu_op2_use_imm ? ex_imm : ex_rdata2;
    ysyx_25050136_ALU u_ysyx_25050136_ALU(
        .op1_i          (alu_opd1     ),
        .op2_i          (alu_opd2     ),
        .op_i 	        (ex_alu_op    ),
        .out_o       	(alu_out      )
    );
    // === BQU ===
    assign bqu_out = ex_jalr ? (alu_out & ~32'h1) : alu_out;
    assign branch_npc = (ex_csru_op[`ysyx_25050136_CSRU_ECALL] | ex_csru_op[`ysyx_25050136_CSRU_MRET]) ? csru_out : bqu_out;
    assign branch_flush_o = (ex_mispredict | (ex_jump & target_mismatch))  & in_pulse;
    assign branch_npc_o = ex_jump ? branch_npc : ex_npc;
    assign btb_update_o =  ex_jump & (!ex_btb_hit | target_mismatch) & in_pulse;
    assign btb_target_o = branch_npc;
    assign btb_pc_o = ex_pc;
    // === CSR ===
    assign csru_wdata = ex_csr_wdata_use_rs1 ? ex_rdata1 : {{32-5{1'b0}},ex_rs1};
    ysyx_25050136_CSRU u_ysyx_25050136_CSRU(
        .clk          	(clk         ),
        .pc_i         	(ex_pc       ),
        .operation_i  	(ex_csru_op  ),
        .csru_wdata_i 	(csru_wdata  ),
        .csru_addr_i  	(ex_csr_addr ),
        .csru_ren_i   	(ex_csr_ren  ),
        .csru_wen_i   	(ex_csr_wen  ),
        .csru_rdata_o 	(csru_out    )
    );
    // === 访存 ===
    assign out_lsu_ren_o = ex_lsu_ren;
    assign out_lsu_wen_o = ex_lsu_wen;
    assign out_lsu_mask_o = ex_lsu_mask;
    assign out_lsu_signed_o = ex_lsu_signed;
    assign out_lsu_addr_o = alu_out;
    assign out_lsu_wdata_o = ex_rdata2;
    // === 写回 ===
    assign out_ebreak_o = ex_ebreak;
    assign out_rd_o = ex_rd;
    assign out_rd_en_o = ex_rd_en;
    assign out_gpr_wdata_o = ex_rd_npc ? ex_npc : (ex_csr_ren ? csru_out : alu_out);
    assign wen_o = ex_rd_en & out_valid_o;
    assign wvalid_o = ex_rd_en & ex_rd_npc & out_valid_o;
    assign waddr_o = ex_rd;
    assign wdata_o = ex_npc;
    // === 流水线控制 ===
    assign in_ready_o = idle || out_fire;
    assign out_valid_o = !(idle || flush);
`ifdef YSYXSOC
    always @(posedge clk) begin
        if(reset) begin
            out_dbg_inst_o <= 0;
        end else begin
            if(flush) begin
            end else if(in_fire) begin
                out_dbg_inst_o <= in_dbg_inst_i;
                out_dbg_optype_o <= in_dbg_optype_i;
            end if(out_fire) begin
            end 
        end
    end
    assign out_dbg_pc_o = ex_pc;
`ifdef EVENT_COUNTER
    always @(posedge clk) begin
        if(!reset) begin
            if(branch_flush_o) predict_miss_count();
        end
    end
`endif
`endif
endmodule
