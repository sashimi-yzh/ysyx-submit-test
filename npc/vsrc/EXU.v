`include "MACRO.v"
`ifndef SYNTHESIS
    import PKG::perf_cnt_update;
    import PKG::flush_num;
    import PKG::branch_num;
`endif
module EXU(
    input clk,
    input reset,

    /*recv data*/
    input [4:0] s_rd,
    input [31:0] s_srcR1,
    input [31:0] s_srcR2,
    input [31:0] s_imm,

    input [3:0] s_alu_op,
    input [1:0] s_alu_sel0, //sel the ALU A port is srcR1(0) or PC(1)
    input [1:0] s_alu_sel1, //sel the ALU B port is srcR2(0) or imm(1) or csr(2)

    input s_wb_en,
    input s_mem_en,
    input s_mem_write_en,

    input [1:0] s_op_width,
    input [2:0] s_wb_sel, //imm, alu, mem, PC+4

    input [2:0] s_brju,
    input s_mem_signext,

    input [11:0] s_csr_addr,
    input [31:0] s_csr_data,
    input s_csr_wr_sel, //0: write srcR1, 1: write alu_res
    input s_csr_wen,

    input [31:0] s_PC,
    input s_fencei,
    input s_has_exception,
    input [3:0] s_exception_code,

    input [1:0] s_meta_data_BTB,
    input s_hit_BTB,

    input s_valid,
    output s_ready,
    /*recv data end*/


    /*send data*/
    output [4:0] m_rd,
    output m_wb_en,
    output m_mem_en,
    output m_mem_write_en,
    output [1:0] m_op_width,
    output [2:0] m_wb_sel,
    output m_mem_signext,
    output [11:0] m_csr_addr,
    output [31:0] m_csr_data,
    output m_csr_wr_sel,
    output m_csr_wen,
    output [31:0] m_srcR1,
    output [31:0] m_srcR2,
    output [31:0] m_result,
    output [31:0] m_PC,
    output [31:0] m_imm,
    output m_has_exception,
    output [3:0] m_exception_code,

    output m_valid,
    input m_ready,
    /*send data end*/

    output [4:0] rd_exu,
    output rd_valid_exu,
    output [11:0] csr_exu,
    output csr_valid_exu,

    output reg [31:0] forward_data_exu,
    output forward_ready_exu,
    output reg [31:0] csr_forward_data_exu,
    output csr_forward_ready_exu,

    /*To PCR*/
    output [31:0] pcr_exu_result,
    output [31:0] pcr_imm,
    output [2:0] pcr_behavior,
    output [31:0] pcr_pc_now,

    output reg flush,
    output cache_flush,
    input exception_flush,

    /*To the update of the BTB*/
    output [31:0] PC_w,
    output reg [31:0] target,
    output reg [1:0] meta_data,
    output reg write_en
);
`ifndef SYNTHESIS
    always @(posedge clk) begin
        if(m_valid & m_ready) begin
            perf_cnt_update(2);
            if(flush) begin
                flush_num();
            end
            if(brju != `PC_NORMAL) begin
                branch_num();
            end
        end
    end
`endif

    /*logic to flush*/
    always @(*) begin
        if(m_valid && m_ready) begin
            if(hit_BTB) begin
                // if is jal, not flush
                if(meta_data_BTB[1]) begin
                    flush = 1'b0;
                end
                // if is branch
                else begin
                    // if predicted taken, but actually not taken, then flush
                    if(meta_data_BTB[0]) begin
                        flush = (m_result == 32'b0);
                    end

                    // if predicted not taken, but actually taken, then flush
                    else begin
                        flush = (m_result == 32'b1);
                    end
                end
            end

            else begin
                flush = fencei || (brju == `PC_BRANCH && m_result == 32'b1) || (brju == `PC_FAR) || (brju == `PC_NEAR) || (brju == `PC_MRET);
            end
        end

        else begin
            flush = 1'b0;
        end
    end

    /*logic to update BTB*/
    assign PC_w = PC_reg;
    always @(*) begin
        write_en = 1'b0;
        target = 32'b0;
        meta_data = 2'b0;
        if(m_valid && m_ready && !hit_BTB && (brju == `PC_BRANCH || brju == `PC_NEAR)) begin
            write_en = 1'b1;
            if(brju == `PC_BRANCH) begin
                /*Use the BTFN(Backward Taken, Forward Not-taken)*/
                target = imm[31] ? PC_reg + imm : PC_reg + 32'd4;
                meta_data[1] = 1'b0;
                meta_data[0] = imm[31] ? 1'b1 : 1'b0;
            end

            else begin
                target = PC_reg + imm;
                meta_data[1] = 1'b1;
                meta_data[0] = 1'b1; // near jump is always taken
            end
        end
    end

    
    assign cache_flush = m_valid && m_ready && fencei;

    assign pcr_exu_result = m_result;
    assign pcr_imm = imm;
    assign pcr_behavior = brju;
    assign pcr_pc_now = PC_reg;

    assign rd_exu = rd;
    assign rd_valid_exu = valid_reg && wb_en && (rd != 5'b0);
    assign csr_exu = csr_addr;
    assign csr_valid_exu = valid_reg && csr_wen;

    always @(*) begin
        case(wb_sel)
            `WB_SEL_IMM: forward_data_exu = imm;
            `WB_SEL_ALU: forward_data_exu = m_result;
            `WB_SEL_PC4: forward_data_exu = PC_reg + 4;
            `WB_SEL_CSR: forward_data_exu = csr_data;
            default: forward_data_exu = 32'b0;
        endcase
    end

    always @(*) begin
        case(csr_wr_sel)
            `CSR_SEL_RS1: csr_forward_data_exu = srcR1;
            `CSR_SEL_ALU: csr_forward_data_exu = m_result;
            default: csr_forward_data_exu = 32'b0;
        endcase
    end
    assign forward_ready_exu = m_valid && (wb_sel != `WB_SEL_MEM); //load instruction need to wait for MEM stage
    assign csr_forward_ready_exu = m_valid;

    reg [4:0] rd;
    reg [31:0] srcR1;
    reg [31:0] srcR2;
    reg [31:0] imm;

    reg [3:0] alu_op;
    reg [1:0] alu_sel0; //sel the ALU A port is srcR1(0) or PC(1)
    reg [1:0] alu_sel1; //sel the ALU B port is srcR2(0) or imm(1) or csr(2)

    reg wb_en;
    reg mem_en;
    reg mem_write_en;

    reg [1:0] op_width;
    reg [2:0] wb_sel; //imm; alu; mem; PC+4

    reg [2:0] brju;
    reg mem_signext;

    reg [11:0] csr_addr;
    reg [31:0] csr_data;
    reg csr_wr_sel; //0: write srcR1; 1: write alu_res
    reg csr_wen;

    reg [31:0] PC_reg;
    reg fencei;
    reg has_exception_reg;
    reg [3:0] exception_code_reg;

    reg [1:0] meta_data_BTB;
    reg hit_BTB;

    /*logic to recv data*/
    assign s_ready = !m_valid || (m_valid & m_ready);
    always @(posedge clk) begin
        if(reset) begin
            rd <= 5'b0;
            srcR1 <= 32'b0;
            srcR2 <= 32'b0;
            imm <= 32'b0;

            alu_op <= 4'b0;
            alu_sel0 <= 2'b0; //sel the ALU A port is srcR1(0) or PC(1)
            alu_sel1 <= 2'b0; //sel the ALU B port is srcR2(0) or imm(1) or csr(2)

            wb_en <= 1'b0;
            mem_en <= 1'b0;
            mem_write_en <= 1'b0;

            op_width <= 2'b0;
            wb_sel <= 3'b0; //imm; alu; mem; PC+4

            brju <= 3'b0;
            mem_signext <= 1'b0;

            csr_addr <= 12'b0;
            csr_data <= 32'b0;
            csr_wr_sel <= 1'b0; //0: write srcR1; 1: write alu_res
            csr_wen <= 1'b0;

            PC_reg <= 32'b0;
            fencei <= 1'b0;
            has_exception_reg <= 1'b0;
            exception_code_reg <= 4'b0;

            meta_data_BTB <= 2'b0;
            hit_BTB <= 1'b0;
        end

        else if(s_valid && s_ready) begin
            rd <= s_rd;
            srcR1 <= s_srcR1;
            srcR2 <= s_srcR2;
            imm <= s_imm;

            alu_op <= s_alu_op;
            alu_sel0 <= s_alu_sel0;
            alu_sel1 <= s_alu_sel1;

            wb_en <= s_wb_en;
            mem_en <= s_mem_en;
            mem_write_en <= s_mem_write_en;

            op_width <= s_op_width;
            wb_sel <= s_wb_sel;

            brju <= s_brju;
            mem_signext <= s_mem_signext;

            csr_addr <= s_csr_addr;
            csr_data <= s_csr_data;
            csr_wr_sel <= s_csr_wr_sel;
            csr_wen <= s_csr_wen;

            PC_reg <= s_PC;
            fencei <= s_fencei;
            has_exception_reg <= s_has_exception;
            exception_code_reg <= s_exception_code;

            meta_data_BTB <= s_meta_data_BTB;
            hit_BTB <= s_hit_BTB;
        end
    end


    /*logic to send data*/
    assign m_rd = rd;
    assign m_wb_en = wb_en;
    assign m_mem_en = mem_en;
    assign m_mem_write_en = mem_write_en;
    assign m_op_width = op_width;
    assign m_wb_sel = wb_sel;
    assign m_mem_signext = mem_signext;
    assign m_csr_addr = csr_addr;
    assign m_csr_data = csr_data;
    assign m_csr_wr_sel = csr_wr_sel;
    assign m_csr_wen = csr_wen;
    assign m_srcR1 = srcR1;
    assign m_srcR2 = srcR2;
    assign m_PC = PC_reg;
    assign m_imm = imm;
    assign m_exception_code = exception_code_reg;
    assign m_has_exception = has_exception_reg;

    reg valid_reg;
    assign m_valid = valid_reg;

    always @(posedge clk) begin
        if(reset) begin
            valid_reg <= 1'b0;
        end
        else if(flush || exception_flush) begin
            valid_reg <= 1'b0;
        end
        else if(s_valid && s_ready) begin
            valid_reg <= 1'b1;
        end
        else if(m_ready && m_valid) begin
            valid_reg <= 1'b0;
        end

    end

    wire [31:0] alu_src1;
    wire [31:0] alu_src2;

    assign alu_src1 = (alu_sel0 == `ALU_SEL_RS1) ? srcR1 :
                      (alu_sel0 == `ALU_SEL_PC) ? PC_reg : 32'b0;
    assign alu_src2 = (alu_sel1 == `ALU_SEL_RS2) ? srcR2 :
                      (alu_sel1 == `ALU_SEL_IMM) ? imm :
                      (alu_sel1 == `ALU_SEL_CSR) ? csr_data : 32'b0;

    ALU alu(
        .A(alu_src1),
        .B(alu_src2),
        .Opcode(alu_op),
        .Result(m_result)
    );

endmodule
