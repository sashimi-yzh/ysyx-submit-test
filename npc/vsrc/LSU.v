`include "MACRO.v"
`ifndef SYNTHESIS
    import PKG::perf_cnt_update;
`endif
module LSU(
    input clk,
    input reset,

    /*data to recv*/
    input [4:0] s_rd,
    input s_wb_en,
    input s_mem_en,
    input s_mem_write_en,
    input [1:0] s_op_width,
    input [2:0] s_wb_sel,
    input s_mem_signext,
    input [11:0] s_csr_addr,
    input [31:0] s_csr_data,
    input s_csr_wr_sel,
    input s_csr_wen,
    input [31:0] s_srcR1,
    input [31:0] s_srcR2,
    input [31:0] s_result,
    input [31:0] s_PC,
    input [31:0] s_imm,
    input s_has_exception,
    input [3:0] s_exception_code,

    input s_valid,
    output s_ready,
    /*data to recv end*/

    /*data to send*/
    output [4:0] m_rd,
    output m_wb_en,
    output [2:0] m_wb_sel,
    output [11:0] m_csr_addr,
    output [31:0] m_csr_data,
    output m_csr_wr_sel,
    output m_csr_wen,
    output [31:0] m_srcR1,
    output [31:0] m_result,
    output [31:0] m_rdata,
    output [31:0] m_PC,
    output [31:0] m_imm,
    output m_has_exception,
    output reg [3:0] m_exception_code,

    output m_valid,
    input m_ready,
    /*data to send end*/

    //bus to interact with RAM
    output [31:0] m_axi_araddr,
    output m_axi_arvalid,
    input m_axi_arready,
    output [3:0] m_axi_arid,
    output [7:0] m_axi_arlen,
    output [2:0] m_axi_arsize,
    output [1:0] m_axi_arburst,

    input [31:0] m_axi_rdata,
    input [1:0] m_axi_rresp,
    /*verilator lint_off UNUSED */
    input [3:0] m_axi_rid,
    input m_axi_rlast,
    /*verilator lint_on UNUSED */
    input m_axi_rvalid,
    output m_axi_rready,

    output [31:0] m_axi_awaddr,
    output m_axi_awvalid,
    input m_axi_awready,
    output [3:0] m_axi_awid,
    output [7:0] m_axi_awlen,
    output [2:0] m_axi_awsize,
    output [1:0] m_axi_awburst,

    output [31:0] m_axi_wdata,
    output [3:0] m_axi_wstrb,
    output m_axi_wvalid,
    output m_axi_wlast,
    input m_axi_wready,

    input [1:0] m_axi_bresp,
    input m_axi_bvalid,
    /*verilator lint_off UNUSED */
    input [3:0] m_axi_bid,
    output m_axi_bready,
    /*verilator lint_on UNUSED */

    /*To the RAW module*/
    output [4:0] rd_lsu,
    output rd_valid_lsu,
    output [11:0] csr_lsu,
    output csr_valid_lsu,

    /*For the load-use*/
    output reg [31:0] forward_data_lsu,
    output forward_ready_lsu,
    output reg [31:0] csr_forward_data_lsu,
    output csr_forward_ready_lsu,

    input exception_flush
);
`ifndef SYNTHESIS
    always @(posedge clk) begin
        if(m_valid & m_ready) begin
            perf_cnt_update(3);
        end
    end
`endif

    reg [3:0] exception_code;
    /*handle the exception*/
    always @(posedge clk) begin
        if(reset) begin
            exception_code <= 4'b0;
        end
        
        else if(s_mem_en && 
            ((s_op_width == `OP_WIDTH_HALF && s_result[0] != 1'b0) || 
            (s_op_width == `OP_WIDTH_WORD && s_result[1:0] != 2'b00))) begin
            if(s_mem_write_en) exception_code <= 4'd6;
            else exception_code <= 4'd4;
        end

        else if(m_axi_rvalid && m_axi_rready && m_axi_rresp != 2'b00) begin
            exception_code <= 4'd5; // load access fault
        end

        else if(m_axi_bvalid && m_axi_bready && m_axi_bresp != 2'b00) begin
            exception_code <= 4'd7; //store access fault
        end
    end

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
        else if(m_ready && m_valid) begin
            valid_reg <= 1'b0;
        end
    end

    assign rd_lsu = rd;
    assign rd_valid_lsu = valid_reg && wb_en && (rd != 5'b0);
    assign csr_lsu = csr_addr;
    assign csr_valid_lsu = valid_reg && csr_wen;

    always @(*) begin
        case(wb_sel)
            `WB_SEL_IMM: forward_data_lsu = imm;
            `WB_SEL_ALU: forward_data_lsu = m_result;
            `WB_SEL_PC4: forward_data_lsu = PC + 4;
            `WB_SEL_MEM: forward_data_lsu = m_rdata;
            `WB_SEL_CSR: forward_data_lsu = csr_data;
            default: forward_data_lsu = 32'b0;
        endcase
    end

    always @(*) begin
        case(csr_wr_sel)
            `CSR_SEL_RS1: csr_forward_data_lsu = srcR1;
            `CSR_SEL_ALU: csr_forward_data_lsu = m_result;
            default: csr_forward_data_lsu = 32'b0;
        endcase
    end

    assign forward_ready_lsu = m_valid;
    assign csr_forward_ready_lsu = m_valid;


    localparam EXCEPTION = 3'b000, PASS = 3'b001, READ_WAIT = 3'b010, WRITE_WAIT = 3'b011,
                READ_REQ = 3'b100, WRITE_ADDR_REQ = 3'b101, WRITE_DATA_REQ = 3'b110, 
                WRITE_REQ = 3'b111;
    reg [2:0] state, next_state;

    always @(*) begin
        case(state)
            EXCEPTION: begin
                if(s_valid && s_ready) begin
                    if(s_has_exception) begin
                        next_state = EXCEPTION;
                    end
                    else if(s_mem_en) begin
                        if((s_op_width == `OP_WIDTH_HALF && s_result[0] != 1'b0) || 
                        (s_op_width == `OP_WIDTH_WORD && s_result[1:0] != 2'b00)) begin
                            next_state = EXCEPTION;
                        end
                        else if(s_mem_write_en) begin
                            next_state = WRITE_REQ;
                        end
                        else begin
                            next_state = READ_REQ;
                        end
                    end
                    else begin
                        next_state = PASS;
                    end
                end
                else begin
                    next_state = state;
                end
            end

            PASS: begin
                if(s_valid && s_ready) begin
                    if(s_has_exception) begin
                        next_state = EXCEPTION;
                    end
                    else if(s_mem_en) begin
                        if((s_op_width == `OP_WIDTH_HALF && s_result[0] != 1'b0) || 
                        (s_op_width == `OP_WIDTH_WORD && s_result[1:0] != 2'b00)) begin
                            next_state = EXCEPTION;
                        end
                        else if(s_mem_write_en) begin
                            next_state = WRITE_REQ;
                        end
                        else begin
                            next_state = READ_REQ;
                        end
                    end
                    else begin
                        next_state = PASS;
                    end
                end
                
                else begin
                    next_state = state;
                end
            end

            READ_WAIT: begin
                if(m_axi_rvalid && m_axi_rready) begin
                    if(m_axi_rresp != 2'b00) begin
                        next_state = EXCEPTION;
                    end
                    else begin
                        next_state = PASS;
                    end
                end
                else begin
                    next_state = READ_WAIT;
                end
            end

            WRITE_WAIT: begin
                if(m_axi_bvalid && m_axi_bready) begin
                    if(m_axi_bresp != 2'b00) begin
                        next_state = EXCEPTION;
                    end
                    else begin
                        next_state = PASS;
                    end
                end
                else begin
                    next_state = WRITE_WAIT;
                end
            end

            READ_REQ: begin
                if(exception_flush) begin
                    next_state = PASS;
                end
                else if(m_axi_arvalid && m_axi_arready) begin
                    next_state = READ_WAIT;
                end
                else begin
                    next_state = state;
                end
            end

            WRITE_REQ: begin
                if(exception_flush) begin
                    next_state = PASS;
                end
                else if(m_axi_awvalid && m_axi_awready && m_axi_wvalid && m_axi_wready) begin
                    next_state = WRITE_WAIT;
                end

                else if(m_axi_awvalid && m_axi_awready) begin
                    next_state = WRITE_DATA_REQ;
                end

                else if(m_axi_wvalid && m_axi_wready) begin
                    next_state = WRITE_ADDR_REQ;
                end

                else begin
                    next_state = state;
                end
            end

            WRITE_ADDR_REQ: begin
                if(m_axi_awvalid && m_axi_awready) begin
                    next_state = WRITE_WAIT;
                end

                else begin
                    next_state = state;
                end
            end

            WRITE_DATA_REQ: begin
                if(m_axi_wvalid && m_axi_wready) begin
                    next_state = WRITE_WAIT;
                end

                else begin
                    next_state = state;
                end
            end

            default: next_state = PASS;
        endcase
    end

    always @(posedge clk) begin
        if(reset) begin
            state <= PASS;
        end
        else begin
            state <= next_state;
        end
    end

    reg [4:0] rd;
    reg wb_en;
    reg [1:0] op_width;
    reg [2:0] wb_sel;
    reg mem_signext;
    reg [11:0] csr_addr;
    reg [31:0] csr_data;
    reg csr_wr_sel;
    reg csr_wen;
    reg [31:0] srcR1;
    reg [31:0] srcR2;
    reg [31:0] result;
    reg [31:0] PC;
    reg [31:0] imm;
    reg has_exception_reg;
    reg [3:0] exception_code_reg;
    
    /*logic to recv data*/
    assign s_ready = !valid_reg || (m_ready && m_valid);
    always @(posedge clk) begin
        if(reset) begin
            rd <= 5'b0;
            wb_en <= 1'b0;
            op_width <= 2'b0;
            wb_sel <= 3'b0;
            mem_signext <= 1'b0;
            csr_addr <= 12'b0;
            csr_data <= 32'b0;
            csr_wr_sel <= 1'b0;
            csr_wen <= 1'b0;
            srcR1 <= 32'b0;
            srcR2 <= 32'b0;
            result <= 32'b0;
            PC <= 32'b0;
            imm <= 32'b0;
            has_exception_reg <= 1'b0;
            exception_code_reg <= 4'b0;
        end

        else if(s_valid && s_ready) begin
            rd <= s_rd;
            wb_en <= s_wb_en;
            op_width <= s_op_width;
            wb_sel <= s_wb_sel;
            mem_signext <= s_mem_signext;
            csr_addr <= s_csr_addr;
            csr_data <= s_csr_data;
            csr_wr_sel <= s_csr_wr_sel;
            csr_wen <= s_csr_wen;
            srcR1 <= s_srcR1;
            srcR2 <= s_srcR2;
            result <= s_result;
            PC <= s_PC;
            imm <= s_imm;
            has_exception_reg <= s_has_exception;
            exception_code_reg <= s_exception_code;
        end
    end

    /*logic to send data*/
    assign m_rd = rd;
    assign m_wb_en = wb_en;
    assign m_wb_sel = wb_sel;
    assign m_csr_addr = csr_addr;
    assign m_csr_data = csr_data;
    assign m_csr_wr_sel = csr_wr_sel;
    assign m_csr_wen = csr_wen;
    assign m_srcR1 = srcR1;
    assign m_result = result;
    assign m_PC = PC;
    assign m_imm = imm;
    assign m_valid = (state == PASS || state == EXCEPTION) && valid_reg;
    assign m_has_exception = (state == EXCEPTION);
    always @(*) begin
        if(has_exception_reg) begin
            m_exception_code = exception_code_reg;
        end
        else begin
            m_exception_code = exception_code;
        end
    end
    

    /*logic to send read addr*/
    assign m_axi_araddr = result;
    assign m_axi_arvalid = (state == READ_REQ) && !exception_flush;
    assign m_axi_arid = 4'b0;
    assign m_axi_arlen = 8'b0;
    assign m_axi_arsize = {1'b0, op_width}; //4 bytes
    assign m_axi_arburst = 2'b01; //INCR

    /*logic to send write addr*/
    assign m_axi_awaddr = result;
    assign m_axi_awvalid = (state == WRITE_ADDR_REQ || state == WRITE_REQ) && !exception_flush;
    assign m_axi_awid = 4'b0;
    assign m_axi_awlen = 8'b0;
    assign m_axi_awsize = {1'b0, op_width}; //4 bytes
    assign m_axi_awburst = 2'b01; //INCR

    /*logic to send write data*/
    wire [31:0] wdata_ = srcR2 << (result[1:0]*8);
    assign m_axi_wdata = wdata_;
    assign m_axi_wstrb = (op_width == `OP_WIDTH_BYTE) ? 4'b0001 << result[1:0] :
                         (op_width == `OP_WIDTH_HALF) ? 4'b0011 << result[1:0] : 4'b1111;
    assign m_axi_wvalid = (state == WRITE_DATA_REQ || state == WRITE_REQ) && !exception_flush;
    assign m_axi_wlast = (state == WRITE_DATA_REQ || state == WRITE_REQ);

    /*logic to recv read data*/
    assign m_axi_rready = (state == READ_WAIT);
    reg [31:0] rdata_reg;
    always @(posedge clk) begin
        if(reset) begin
            rdata_reg <= 32'b0;
        end
        else if(m_axi_rvalid && m_axi_rready) begin
            rdata_reg <= m_axi_rdata;
        end
    end


    reg [7:0] data8;
    reg [15:0] data16;

    always @(*) begin
        case(result[1:0])
            2'b00: data8 = rdata_reg[7:0];
            2'b01: data8 = rdata_reg[15:8];
            2'b10: data8 = rdata_reg[23:16];
            2'b11: data8 = rdata_reg[31:24];
        endcase
    end

    always @(*) begin
        case(result[1])
            1'b0: data16 = rdata_reg[15:0];
            1'b1: data16 = rdata_reg[31:16];
        endcase
    end

    wire [31:0] rdata_ext8;
    wire [31:0] rdata_ext16;


    ext8 u_ext8(
        .data_i 	( data8  ),
        .sign   	( mem_signext    ),
        .data_o 	( rdata_ext8  )
    );

    ext16 u_ext16(
        .data_i 	( data16  ),
        .sign   	( mem_signext    ),
        .data_o 	( rdata_ext16  )
    );
    wire [31:0] rdata_ext;
    assign rdata_ext = (op_width == `OP_WIDTH_BYTE) ? rdata_ext8 :
                       (op_width == `OP_WIDTH_HALF) ? rdata_ext16 :
                       (op_width == `OP_WIDTH_WORD) ? rdata_reg :
                       32'b0;

    assign m_rdata = rdata_ext;

    /*logic to recv write response*/
    assign m_axi_bready = (state == WRITE_WAIT);

endmodule

/* verilator lint_off DECLFILENAME */
module ext8(
/* verilator lint_on DECLFILENAME */
    input [7:0] data_i,
    input sign,
    output [31:0] data_o
);

   assign data_o = sign ? {{24{data_i[7]}}, data_i} : {24'b0, data_i};
    
endmodule

module ext16(
    input [15:0] data_i,
    input sign,
    output [31:0] data_o
);

   assign data_o = sign ? {{16{data_i[15]}}, data_i} : {16'b0, data_i};
    
endmodule
