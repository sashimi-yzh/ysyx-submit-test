`include "MACRO.v"

module WBU(
    input clk,
    input reset,

    /*data to recv*/
    input [4:0] s_rd,
    input s_wb_en,
    input [2:0] s_wb_sel,
    input [11:0] s_csr_addr,
    input [31:0] s_csr_data,
    input s_csr_wr_sel,
    input s_csr_wen,
    input [31:0] s_srcR1,
    input [31:0] s_result,
    input [31:0] s_rdata,
    input [31:0] s_PC,
    input [31:0] s_imm,
    input s_has_exception,
    input [3:0] s_exception_code,

    input s_valid,
    output s_ready,
    /*data to recv end*/

    /*To GPR*/
    output wen,
    output reg [31:0] wdata,
    output [4:0] waddr,

    /*To CSR*/
    output [11:0] csr_addr_,
    output [31:0] csr_srcR1_,
    output [31:0] csr_alu_res_,
    output csr_wr_sel_,
    output csr_wen_,
    output csr_exception,
    output [31:0] csr_epc_,
    output [31:0] csr_cause_,

    /*To the RAW module*/
    output [4:0] rd_wbu,
    output rd_valid_wbu,
    output [11:0] csr_wbu,
    output csr_valid_wbu,

    /*For the load-use*/
    output [31:0] forward_data_wbu,
    output forward_ready_wbu,
    output [31:0] csr_forward_data_wbu,
    output csr_forward_ready_wbu,

    output exception_flush
);


    reg valid_reg;
    always @(posedge clk) begin
        if(reset) begin
            valid_reg <= 1'b0;
        end
        
        else if(exception_flush) begin
            valid_reg <= 1'b0;
        end

        else if(s_valid && s_ready) begin
            valid_reg <= 1'b1;
        end
        else begin
            valid_reg <= 1'b0;
        end
    end

    assign rd_wbu = rd;
    assign rd_valid_wbu = valid_reg && wb_en && (rd != 5'b0);
    assign csr_wbu = csr_addr;
    assign csr_valid_wbu = valid_reg && csr_wen;

    assign forward_data_wbu = wdata;

    always @(*) begin
        case(csr_wr_sel)
            `CSR_SEL_RS1: csr_forward_data_wbu = srcR1;
            `CSR_SEL_ALU: csr_forward_data_wbu = result;
            default: csr_forward_data_wbu = 32'b0;
        endcase
    end

    assign forward_ready_wbu = valid_reg;
    assign csr_forward_ready_wbu = valid_reg;

    /*logic to recv data*/
    reg [4:0] rd;
    reg wb_en;
    reg [2:0] wb_sel;
    reg [11:0] csr_addr;
    reg [31:0] csr_data;
    reg csr_wr_sel;
    reg csr_wen;
    reg [31:0] srcR1;
    reg [31:0] result;
    reg [31:0] rdata;
    reg [31:0] PC;
    reg [31:0] imm;
    reg has_exception_reg;
    reg [3:0] exception_code_reg;
    assign s_ready = 1'b1;
    always @(posedge clk) begin
        if(reset) begin
            rd <= 5'b0;
            wb_en <= 1'b0;
            wb_sel <= 3'b0;
            csr_addr <= 12'b0;
            csr_data <= 32'b0;
            csr_wr_sel <= 1'b0;
            csr_wen <= 1'b0;
            srcR1 <= 32'b0;
            result <= 32'b0;
            rdata <= 32'b0;
            PC <= 32'b0;
            imm <= 32'b0;
            has_exception_reg <= 1'b0;
            exception_code_reg <= 4'b0;
        end

        else if(s_valid && s_ready) begin
            rd <= s_rd;
            wb_en <= s_wb_en;
            wb_sel <= s_wb_sel;
            csr_addr <= s_csr_addr;
            csr_data <= s_csr_data;
            csr_wr_sel <= s_csr_wr_sel;
            csr_wen <= s_csr_wen;
            srcR1 <= s_srcR1;
            result <= s_result;
            rdata <= s_rdata;
            PC <= s_PC;
            imm <= s_imm;
            has_exception_reg <= s_has_exception;
            exception_code_reg <= s_exception_code;
        end
    end

    /*interact with GPR*/
    assign wen = wb_en & valid_reg & !has_exception_reg;
    assign waddr = rd;
    always @(*) begin
        case(wb_sel)
            `WB_SEL_IMM: wdata = imm;
            `WB_SEL_ALU: wdata = result;
            `WB_SEL_MEM: wdata = rdata;
            `WB_SEL_PC4: wdata = PC + 32'd4;
            `WB_SEL_CSR: wdata = csr_data;
            default: wdata = 32'b0;
        endcase
    end


    /*interact with CSR*/
    assign csr_addr_ = csr_addr;
    assign csr_srcR1_ = srcR1;
    assign csr_alu_res_ = result;
    assign csr_wr_sel_ = csr_wr_sel;
    assign csr_wen_ = csr_wen & valid_reg & !has_exception_reg;

    assign csr_exception = has_exception_reg & valid_reg;
    assign csr_epc_ = PC;
    assign csr_cause_ = {28'b0, exception_code_reg};

    assign exception_flush = has_exception_reg & valid_reg;


endmodule
