`include "ysyx_25010030_define.vh"

module ysyx_25010030_EX (
    input             clk,
    input             reset,
    // input             id_ready,        // ID -> IF
    input             id_valid,
    output reg        ex_ready,
    input             lsu_ready,
    output reg        ex_lsu_valid,

    input      [ 3:0] id_wb_rs1,
    input      [ 3:0] id_wb_rs2,
    input      [ 3:0] lsu_ex_forward_rd,
    input             lsu_ex_forward_RegWrite,
    input             lsu_ex_forward_MemRead,
    input      [31:0] lsu_wb_wdata,
    input      [ 3:0] lsu_wb_rd,
    input             lsu_wb_RegWrite,
    input             lsu_wb_valid,
    output reg        ex_lsu_forward_las,

    // input      [31:0] id_ex_inst,
    input      [31:0] id_ex_pc,
    input      [31:0] id_ex_imm,
    input      [ 4:0] id_ex_zimm,
    input      [ 5:0] id_ex_shamt,
    input      [31:0] wb_ex_src1,
    input      [31:0] wb_ex_src2,
    input             id_ex_RegWrite,
    input      [ 3:0] id_ex_rd,
    input      [ 6:0] id_ex_opcode,
    input      [ 2:0] id_ex_func3,
    input      [ 3:0] id_ex_alu_op,

    input             id_ex_jal,
    input             id_ex_jalr,
    input             id_ex_fencei,
    input             id_ex_MemRead,
    input             id_ex_MemWrite,
    input      [ 4:0] id_ex_MemLen,

    input      [31:0] wb_ex_csr_num1,
    input      [31:0] wb_ex_csr_num2,
     
    // input             id_ex_csr,
    input             id_ex_csr_wen1,
    // input             id_ex_csr_wen2,
    input      [11:0] id_ex_csr_wr_addr1,
    // input      [11:0] id_ex_csr_wr_addr2,
    input             id_ex_csr_ecall,
    input             id_ex_csr_mret,
    input      [ 1:0] id_ex_csr_op,

    output reg        ex_flush,
    output reg [31:0] ex_flush_pc,
    output reg        ex_fencei,
`ifdef FPU
    input             id_ex_is_div,
    input             id_ex_is_rem,
    input             id_ex_is_signed,
    output reg        ex_stop,
`endif

    // output reg [31:0] ex_lsu_inst,
    // output reg [31:0] ex_lsu_pc,
    output reg [31:0] ex_lsu_src2,
    output reg        ex_lsu_RegWrite,
    output reg [ 3:0] ex_lsu_rd,
    output reg        ex_lsu_MemRead,
    output reg        ex_lsu_MemWrite,
    output reg [ 4:0] ex_lsu_MemLen,

    output reg        ex_lsu_csr,
    output reg        ex_lsu_csr_wen1,
    // output reg        ex_lsu_csr_wen2,
    output reg [11:0] ex_lsu_csr_wr_addr1,
    // output reg [11:0] ex_lsu_csr_wr_addr2,
    output reg [31:0] ex_lsu_csr_wr_data1,
    output reg [31:0] ex_lsu_csr_wr_data2,
    output reg [31:0] ex_lsu_csr_rdata,

    output reg        ex_lsu_csr_ecall,
    output reg        ex_lsu_csr_mret,
`ifdef DIFFTEST
    output reg [31:0] ex_lsu_pc,
`endif
    output reg [31:0] ex_lsu_process_result

);
// `ifdef VERILATOR
    // import "DPI-C" function void ebreak(input int station, input int inst);
    // import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);
// `endif
    
    // EXU 活跃周期计数
    // always @(posedge clk) begin
    //     if (reset) begin
    //         exu_active_cycles <= 0;
    //     end else if (id_valid && ex_ready) begin
    //         exu_active_cycles <= exu_active_cycles + 1;
    //     end
    // end

    // 前递后的源寄存器值
    // wire [31:0] src1 = (forward_rs1[1] ? ex_lsu_process_result : 
    //                    (forward_rs1[0] | load_use_flag[1]) ? lsu_wb_wdata : 
    //                    wb_ex_src1);
    // wire [31:0] src2 = (forward_rs2[1] ? ex_lsu_process_result : 
    //                    (forward_rs2[0] | load_use_flag[0]) ? lsu_wb_wdata : 
    //                    wb_ex_src2);
    // 前递信号定义
    wire [1:0] forward_rs1;
    wire [1:0] forward_rs2;
    wire       forward_las;
    wire [3:0] load_use_flag;
    
    wire [31:0] src1 = (forward_rs1[1])   ? ex_lsu_process_result : 
                       (forward_rs1[0])   ? lsu_wb_wdata : 
                       (load_use_flag[3]) ? lsu_wb_wdata : wb_ex_src1;

    wire [31:0] src2 = (forward_rs2[1])   ? ex_lsu_process_result : 
                       (forward_rs2[0])   ? lsu_wb_wdata : 
                       (load_use_flag[2]) ? lsu_wb_wdata : wb_ex_src2;

    // ALU 操作中间变量
    reg [31:0] ex_num1;
    reg [31:0] ex_num2;
    reg [31:0] process_result;

    // ALU 输入选择
    always @(*) begin
        ex_num1 = src1;
        if (id_ex_MemRead | id_ex_MemWrite) begin
            ex_num2 = id_ex_imm;
        end
        else if (id_ex_jal | id_ex_jalr) begin
            ex_num1 = id_ex_pc;
            ex_num2 = 32'd4;
        end
        else if(id_ex_opcode == `INST_LUI) begin
            ex_num1 = id_ex_imm;
            ex_num2 = 32'd0;
        end
        else if(id_ex_opcode == `INST_AUIPC) begin
            ex_num1 = id_ex_pc;
            ex_num2 = id_ex_imm;
        end
        else if(id_ex_alu_op == `ALU_SLL || id_ex_alu_op == `ALU_SRL || id_ex_alu_op == `ALU_SRA) begin
            ex_num2 = (id_ex_opcode[6:2] == `INST_TYPE_I && !id_ex_shamt[5]) ? {27'd0, id_ex_shamt[4:0]} :
                      (id_ex_opcode[6:2] == `INST_TYPE_R)                    ? {27'd0, src2[4:0]}        : 32'd0;
        end
        else begin
            ex_num2 = (id_ex_opcode[6:2] == `INST_TYPE_R || id_ex_opcode[6:2] == `INST_TYPE_B) ? src2 : id_ex_imm;
        end
    end

    // ALU 操作
    reg        alu_zero;
    reg        alu_less;

    reg sign1, sign2;
    reg [31:0] sub_result;

    always @(*) begin
        sign1 = ex_num1[31];
        sign2 = ex_num2[31];
        sub_result = ex_num1 - ex_num2;
        case (id_ex_alu_op)
            `ALU_ADD:  process_result = ex_num1 + ex_num2;
            `ALU_SUB:  process_result = sub_result;
            `ALU_AND:  process_result = ex_num1 & ex_num2;
            `ALU_OR:   process_result = ex_num1 | ex_num2;
            `ALU_XOR:  process_result = ex_num1 ^ ex_num2;
            `ALU_SLTU: process_result = (ex_num1 < ex_num2) ? {31'b0, 1'b1} : 32'b0;
            // `ALU_SLT:  process_result = ($signed(ex_num1) < $signed(ex_num2)) ? {31'b0, 1'b1} : 32'b0;
            `ALU_SLT: begin
                if(sign1 != sign2) begin
                    process_result = sign1 ? {31'b0, 1'b1} : 32'b0;
                end
                else begin
                    process_result = sub_result[31] ? {31'b0, 1'b1} : 32'b0;
                end
            end
            `ALU_SRA:  process_result = $signed(ex_num1) >>> ex_num2[4:0];
            `ALU_SLL:  process_result = ex_num1 << ex_num2[4:0];
            `ALU_SRL:  process_result = ex_num1 >> ex_num2[4:0];
            default:   begin 
                process_result = 32'b0; 
            // `ifdef VERILATOR
            //     $display("Unkonw alu_op"); 
            // `endif
            end
        endcase
        alu_zero = (process_result == 32'b0);
        // alu_less = (id_ex_alu_op == `ALU_SLT)  ? ($signed(ex_num1) < $signed(ex_num2)) :
        //            (id_ex_alu_op == `ALU_SLTU) ? (ex_num1 < ex_num2) : 1'b0;
        alu_less = process_result[0];
    end

`ifdef FPU
    reg         div_start;  
    reg         div_computing;  
    wire [31:0] div_quotient;  // 从divider输出的商
    wire [31:0] div_remainder;  // 从divider输出的余数
    wire        div_valid;  

    always @(posedge clk) begin
        if (reset) begin
            div_start     <= 1'b0;
            div_computing <= 1'b0;
            ex_stop       <= 1'b0;
        end else begin
            div_start     <= (id_valid && ex_ready && id_ex_is_div && !div_computing); 
            div_computing <= (id_valid && ex_ready && id_ex_is_div) || (div_computing && !div_valid); 
            ex_stop       <= div_computing;  
        end
    end

    ysyx_25010030_divider u_divider (
        .clk      (clk & (div_start | div_computing | reset)),   // 除法器时钟，在开始除法运算时启动
        .reset    (reset                                    ),
        .start    (div_start                                ),
        .dividend (src1                                     ),   // 被除数
        .divisor  (src2                                     ),   // 除数
        .is_signed(id_ex_is_signed                          ),
        .quotient (div_quotient                             ),   // 商
        .remainder(div_remainder                            ),   // 余数
        .valid    (div_valid                                )
    );
`endif

    // 分支和跳转逻辑
    // reg [31:0] jal_target;
    reg [31:0] fencei_target;
    reg [31:0] jalr_target;
    reg        take_branch;
    reg        ex_flush_condition;

    // wire [31:0] jalr_target = (src1 + id_ex_imm) & ~32'h1;
    // wire        take_branch = (id_ex_opcode == `INST_B) && (
    //                     (id_ex_func3 == `F3_BNE  && !alu_zero) ||  
    //                     (id_ex_func3 == `F3_BEQ  &&  alu_zero) ||  
    //                     (id_ex_func3 == `F3_BLT  &&  alu_less) || 
    //                     (id_ex_func3 == `F3_BGE  && !alu_less) ||  
    //                     (id_ex_func3 == `F3_BLTU &&  alu_less) ||  
    //                     (id_ex_func3 == `F3_BGEU && !alu_less));

    always @(*) begin
        // jal_target  = id_ex_pc + id_ex_imm;
        ex_flush    = (reset) ? 1'b0 : (ex_flush_condition & (~|load_use_flag));
        ex_fencei   = id_ex_fencei;
        fencei_target = id_ex_pc + 32'h4;
        jalr_target = (src1 + id_ex_imm) & 32'hfffffffe;
        take_branch = (id_ex_opcode == `INST_B) && (
                    (id_ex_func3 == `F3_BNE  && !alu_zero) ||  // bne
                    (id_ex_func3 == `F3_BEQ  &&  alu_zero) ||  // beq
                    ( alu_less && (id_ex_func3 == `F3_BLT || id_ex_func3 == `F3_BLTU)) || // blt/bltu
                    (!alu_less && (id_ex_func3 == `F3_BGE || id_ex_func3 == `F3_BGEU))    // bge/bgeu 
        );
        case(1'b1)
            // id_ex_jal: begin
            //     // ex_flush    = 1'b1 & ex_flush_condition & (~(|load_use_flag));
            //     // ex_flush_pc = jal_target;
            //     ex_flush = 1'b0;
            //     ex_flush_pc = 32'h0;
            // end
            id_ex_fencei: begin
                ex_flush_pc = fencei_target;
            end
            id_ex_jalr: begin
                ex_flush_pc = jalr_target;
            end
            id_ex_csr_ecall : begin
                ex_flush_pc = wb_ex_csr_num1;
            end
            id_ex_csr_mret: begin
                ex_flush_pc = wb_ex_csr_num2;
            end
            take_branch: begin
                ex_flush_pc = id_ex_pc + id_ex_imm;   
            end
            default: begin
                ex_flush    = 1'b0; // 非分支指令不需要冲刷
                ex_flush_pc = 32'h0;
            end
        endcase
    end
    
    always @(posedge clk)begin
        if(reset)begin
            ex_flush_condition <= 1'b1;
        end
        else if(ex_flush)begin
            ex_flush_condition <= 1'b0;
        end
        else if(id_valid)begin
            ex_flush_condition <= 1'b1;
        end
    end

    // reg [31:0] csr_write_ecall;
    // always @(*) begin
    //     if (id_ex_csr_ecall) begin
    //         csr_write_ecall = id_ex_pc;
    //     end
    //     else begin
    //         csr_write_ecall = 32'b0;
    //     end
    // end

    // wire [31:0] mstatus;
    wire [31:0] mpie;
    wire [31:0] zimm;
    assign mpie = (wb_ex_csr_num1 >> 7) & 32'h1;
    // assign mstatus = (((wb_ex_csr_num1 & ~(32'h3 << 11)) & ~(32'h1 << 3)) | (mpie << 3)) | (32'h1 << 7);
    assign zimm = {27'b0, id_ex_zimm};

    reg [31:0] csr_write_data;
    always @(*) begin
        case(1'b1)
            (id_ex_csr_op == `CSR_CSRRW && id_ex_func3 == `F3_CSRRW) : csr_write_data = src1;
            // (id_ex_csr_op == `CSR_CSRRC && id_ex_func3 == `F3_CSRRC): csr_write_data = (wb_ex_csr_num1 & ~src1);
            (id_ex_csr_op == `CSR_CSRRS && id_ex_func3 == `F3_CSRRS) : csr_write_data = (wb_ex_csr_num1 | src1);
            (id_ex_csr_op == `CSR_CSRRW && id_ex_func3 == `F3_CSRRWI): csr_write_data = zimm;
            // (id_ex_csr_op == `CSR_CSRRC && id_ex_func3 == `F3_CSRRCI):csr_write_data = wb_ex_csr_num1 & ~zimm;
            (id_ex_csr_op == `CSR_CSRRS && id_ex_func3 == `F3_CSRRSI): csr_write_data = wb_ex_csr_num1 | zimm;
            (                                        id_ex_csr_ecall): csr_write_data = 32'd11;
            // (                                         id_ex_csr_mret): csr_write_data = mstatus;
            default:                                                   csr_write_data = 32'b0;
        endcase
    end

    // wire [31:0] csr_write_data = (id_ex_csr_op == `CSR_CSRRW && id_ex_func3 == `F3_CSRRW) ? src1                                   :
    //                              (id_ex_csr_op == `CSR_CSRRC && id_ex_func3 == `F3_CSRRC) ? (wb_ex_csr_num1 & ~src1)               :
    //                              (id_ex_csr_op == `CSR_CSRRS && id_ex_func3 == `F3_CSRRS) ? (wb_ex_csr_num1 | src1)                :
    //                              (id_ex_csr_op == `CSR_CSRRW && id_ex_func3 == `F3_CSRRWI)? zimm                                   :
    //                              (id_ex_csr_op == `CSR_CSRRC && id_ex_func3 == `F3_CSRRCI)? wb_ex_csr_num1 & ~zimm                 :
    //                              (id_ex_csr_op == `CSR_CSRRS && id_ex_func3 == `F3_CSRRSI)? wb_ex_csr_num1 | zimm                  :
    //                              (                                        id_ex_csr_ecall)? 32'd11                                 :
    //                              (                                         id_ex_csr_mret)? mstatus                                :
    //                                                                                         32'b0;

    wire forward_flag1 = ex_lsu_RegWrite & (|ex_lsu_rd) & ex_lsu_valid;
    wire forward_flag2 = lsu_wb_RegWrite & (|lsu_wb_rd) & lsu_wb_valid;
    wire use_flag1 = lsu_ex_forward_MemRead & lsu_ex_forward_RegWrite & (|lsu_ex_forward_rd);
    wire use_flag2 = ex_lsu_MemRead & ex_lsu_RegWrite & (|ex_lsu_rd) & ex_lsu_valid;


    assign forward_rs1[1] = forward_flag1 & (ex_lsu_rd == id_wb_rs1);
    assign forward_rs1[0] = forward_flag2 & (lsu_wb_rd == id_wb_rs1);
    assign forward_rs2[1] = forward_flag1 & (ex_lsu_rd == id_wb_rs2);
    assign forward_rs2[0] = forward_flag2 & (lsu_wb_rd == id_wb_rs2);

    assign forward_las = id_ex_MemWrite & ex_lsu_MemRead & ex_lsu_RegWrite & ex_lsu_valid &
                         (|ex_lsu_rd) & (ex_lsu_rd != id_wb_rs1) & (ex_lsu_rd == id_wb_rs2);

    assign load_use_flag[3] = use_flag1 & (lsu_ex_forward_rd == id_wb_rs1);
    assign load_use_flag[2] = use_flag1 & (lsu_ex_forward_rd == id_wb_rs2);
    assign load_use_flag[1] = use_flag2 & (ex_lsu_rd == id_wb_rs1);
    assign load_use_flag[0] = use_flag2 & (ex_lsu_rd == id_wb_rs2);

    // 流水线控制
`ifdef FPU
    always @(*) begin
        if(reset) begin
            ex_ready = 1'b0;
        end
        else begin
            ex_ready = (lsu_ready || ~ex_lsu_valid) && (load_use_flag == 4'b0) && (!div_computing || div_valid);
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            ex_lsu_valid <= 1'b0;
        end
        else if (((id_valid && ex_ready && !id_ex_is_div) || (div_valid))&& (lsu_ready || ~ex_lsu_valid)) begin
            ex_lsu_valid <= 1'b1;
        end
        else if (~(id_valid && ex_ready) && lsu_ready) begin
            ex_lsu_valid <= 1'b0;
        end
    end
`else
    always @(*) begin
        if(reset) begin
            ex_ready = 1'b0;
        end
        else begin
            ex_ready = (lsu_ready || ~ex_lsu_valid) && (load_use_flag == 4'b0);
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            ex_lsu_valid <= 1'b0;
        end
        else if ((id_valid && ex_ready) && (lsu_ready || ~ex_lsu_valid)) begin
            ex_lsu_valid <= 1'b1;
        end
        else if (~(id_valid && ex_ready) && lsu_ready) begin
            ex_lsu_valid <= 1'b0;
        end
    end
`endif

    // 输出信号赋值
    always @(posedge clk) begin
        if (reset) begin
            ex_lsu_src2           <= 32'h0;
            ex_lsu_RegWrite       <= 1'b0;
            ex_lsu_rd             <= 4'b0;
            ex_lsu_MemRead        <= 1'b0;
            ex_lsu_MemWrite       <= 1'b0;
            ex_lsu_MemLen         <= 5'b0;
            ex_lsu_process_result <= 32'h0;
            ex_lsu_forward_las    <= 1'b0;
            ex_lsu_csr            <= 1'b0;
            ex_lsu_csr_wen1       <= 1'b0;
            ex_lsu_csr_wr_addr1   <= 12'b0;
            ex_lsu_csr_wr_data1   <= 32'h0;
            ex_lsu_csr_wr_data2   <= 32'h0;
            ex_lsu_csr_rdata      <= 32'h0;
            ex_lsu_csr_ecall      <= 1'b0;
            ex_lsu_csr_mret       <= 1'b0;
`ifdef DIFFTEST
            ex_lsu_pc            <= 32'h0;
`endif
        end
        else if (id_valid && ex_ready) begin
            ex_lsu_src2           <= src2;
            ex_lsu_RegWrite       <= id_ex_RegWrite;
            ex_lsu_rd             <= id_ex_rd;
            ex_lsu_MemRead        <= id_ex_MemRead;
            ex_lsu_MemWrite       <= id_ex_MemWrite;
            ex_lsu_MemLen         <= id_ex_MemLen;
`ifdef FPU
            ex_lsu_process_result <= (div_valid ? (id_ex_is_rem ? div_remainder : div_quotient) : process_result);
`else
            ex_lsu_process_result <= process_result;
`endif
            ex_lsu_forward_las    <= forward_las;
            ex_lsu_csr            <= (id_ex_csr_wen1 | id_ex_csr_ecall | id_ex_csr_mret);
            ex_lsu_csr_wen1       <= id_ex_csr_wen1;
            ex_lsu_csr_wr_addr1   <= id_ex_csr_wr_addr1;
            ex_lsu_csr_wr_data1   <= csr_write_data;
            ex_lsu_csr_wr_data2   <= (id_ex_csr_ecall) ? id_ex_pc : 32'b0;
            ex_lsu_csr_rdata      <= wb_ex_csr_num1;
            ex_lsu_csr_ecall      <= id_ex_csr_ecall;
            ex_lsu_csr_mret       <= id_ex_csr_mret;
`ifdef DIFFTEST
            ex_lsu_pc            <= id_ex_pc;
`endif
        end
    end
endmodule
