`ifndef SYNTHESIS
    import "DPI-C" function void ihit_num();
    import "DPI-C" function void ifetch_num();
`endif
module ICACHE#(
    parameter LINE_NUM = 4,
    parameter LINE_SIZE = 16
)(
    input clk,
    input reset,

    input cache_flush,
    input flush,
    input exception_flush,

    /*axi stream bus*/
    input  [31:0] s_raddr,
    input  [1:0]  s_meta_data_BTB,
    input         s_hit_BTB,
    input         s_valid,
    output        s_ready,

    output [31:0] m_data,
    output [31:0] m_pc,
    output [1:0]  m_meta_data_BTB,
    output        m_hit_BTB,
    output        m_has_exception,
    output reg [3:0] m_exception_code,
    output        m_valid,
    input         m_ready,


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
    /*verilator lint_on UNUSED */
    input m_axi_rlast,
    input m_axi_rvalid,
    output m_axi_rready,

    /*verilator lint_off UNUSED */
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
    input [3:0] m_axi_bid,
    output m_axi_bready
    /*verilator lint_on UNUSED */
);

    `ifndef SYNTHESIS
        always @(posedge clk) begin
            if(s_valid && s_ready) begin
                if(hit) begin
                    ihit_num();
                end
                ifetch_num();
            end
        end
    `endif


    localparam TAG_SIZE = 32 - $clog2(LINE_NUM) - $clog2(LINE_SIZE);
    localparam WORDS_PER_LINE = LINE_SIZE / 4;
    localparam WORDS_SEL_SIZE = $clog2(WORDS_PER_LINE);
    /*unused axi signal(write channel)*/
    assign m_axi_awaddr = 32'b0;
    assign m_axi_awvalid = 1'b0;
    assign m_axi_awid = 4'b0000;
    assign m_axi_awlen = 8'b0;
    assign m_axi_awsize = 3'b0;
    assign m_axi_awburst = 2'b0;
    assign m_axi_wdata = 32'b0;
    assign m_axi_wstrb = 4'b0;
    assign m_axi_wvalid = 1'b0;
    assign m_axi_wlast = 1'b0;
    assign m_axi_bready = 1'b0;

    reg [LINE_SIZE*8-1:0] cache [LINE_NUM-1:0];
    reg [TAG_SIZE-1:0] tags [LINE_NUM-1:0];
    reg valid [LINE_NUM-1:0];

    wire [$clog2(LINE_NUM)-1:0] index = s_raddr[$clog2(LINE_SIZE)+$clog2(LINE_NUM)-1:$clog2(LINE_SIZE)];
    wire [TAG_SIZE-1:0] tag = s_raddr[31:$clog2(LINE_SIZE)+$clog2(LINE_NUM)];
    wire hit = valid[index] && tags[index] == tag;
    wire misaligned = s_raddr[1:0] != 2'b00;

    localparam HIT = 2'd0, REQ = 2'd1, WAIT = 2'd2, EXCEPTION = 2'd3;
    reg [1:0] state, next_state;

    always @(*) begin
        case(state)
            HIT: begin
                if(s_valid & s_ready) begin
                    if(misaligned) begin
                        next_state = EXCEPTION;
                    end
                    else if(hit) begin
                        next_state = HIT;
                    end
                    else begin
                        next_state = REQ;
                    end
                end
                else begin
                    next_state = state;
                end
            end
            
            REQ: begin
                if(flush || exception_flush) begin
                    next_state = HIT;
                end
                else if(m_axi_arvalid && m_axi_arready) begin
                    next_state = WAIT;
                end
                else begin
                    next_state = state;
                end
            end
            WAIT: begin
                if(m_axi_rvalid && m_axi_rready) begin
                    if(m_axi_rresp != 2'b00) begin
                        next_state = EXCEPTION;
                    end
                    else if(m_axi_rlast) begin
                        next_state = HIT;
                    end
                    else begin
                        next_state = state;
                    end
                end
                else begin
                    next_state = state;
                end
            end
            
            EXCEPTION: begin
                if(s_valid & s_ready) begin
                    if(misaligned) begin
                        next_state = EXCEPTION;
                    end
                    else if(hit) begin
                        next_state = HIT;
                    end
                    else begin
                        next_state = REQ;
                    end
                end
                else begin
                    next_state = state;
                end
            end
            default: next_state = HIT;
        endcase
    end

    always @(posedge clk) begin
        if(reset) begin
            state <= HIT;
        end
        else begin
            state <= next_state;
        end
    end

    /*handle the exception*/
    always @(posedge clk) begin
        if(reset) begin
            m_exception_code <= 4'b0;
        end
        
        else if(s_valid && s_ready && misaligned) begin
            m_exception_code <= 4'd0; // fetch address misaligned
        end

        else if(m_axi_rvalid && m_axi_rready && m_axi_rresp != 2'b00) begin
            m_exception_code <= 4'd1; // fetch access fault
        end
    end


    /*logic to latch data*/
    reg valid_reg;

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

        else if(m_valid && m_ready) begin
            valid_reg <= 1'b0;
        end
    end

    reg [31:0] addr_reg;
    reg [1:0] meta_data_BTB_reg;
    reg hit_BTB_reg;
    wire [$clog2(LINE_NUM)-1:0] index_reg = addr_reg[$clog2(LINE_SIZE)+$clog2(LINE_NUM)-1:$clog2(LINE_SIZE)];
    wire [TAG_SIZE-1:0] tag_reg = addr_reg[31:$clog2(LINE_SIZE)+$clog2(LINE_NUM)];
    wire [WORDS_SEL_SIZE-1:0] word_sel = addr_reg[$clog2(LINE_SIZE)-1:2];
    always @(posedge clk) begin
        if(reset) begin
            addr_reg <= 32'b0;
            meta_data_BTB_reg <= 2'b0;
            hit_BTB_reg <= 1'b0;
        end
        else if(s_valid && s_ready) begin
            addr_reg <= s_raddr;
            meta_data_BTB_reg <= s_meta_data_BTB;
            hit_BTB_reg <= s_hit_BTB;
        end
    end


    /*logic to update cache*/
    integer i;
    reg [3:0] recv_counter;
    always @(posedge clk) begin
        if(reset || cache_flush) begin
            for(i = 0; i < LINE_NUM; i = i + 1) begin
                valid[i] <= 1'b0;
                tags[i] <= {TAG_SIZE{1'b0}};
                cache[i] <= {(LINE_SIZE*8){1'b0}};
            end
            recv_counter <= 4'b0;
        end
        else if(m_axi_rvalid && m_axi_rready) begin
            cache[index_reg][recv_counter*32 +: 32] <= m_axi_rdata;
            tags[index_reg] <= tag_reg;
            valid[index_reg] <= 1'b1;
            if(m_axi_rlast) begin
                recv_counter <= 4'b0;
            end
            else begin
                recv_counter <= recv_counter + 1;
            end
        end
    end

    assign s_ready = (state == HIT || state == EXCEPTION) && (!valid_reg || (m_valid && m_ready));
    assign m_data = cache[index_reg][word_sel*32 +: 32];
    assign m_has_exception = state == EXCEPTION;
    assign m_valid = (state == HIT || state == EXCEPTION) && valid_reg;
    assign m_pc = addr_reg;
    assign m_meta_data_BTB = meta_data_BTB_reg;
    assign m_hit_BTB = hit_BTB_reg;

    assign m_axi_araddr = {addr_reg[31:4], 4'b0};
    assign m_axi_arvalid = (state == REQ) && !flush && !exception_flush;
    assign m_axi_arid = 4'b0;
    assign m_axi_arlen = WORDS_PER_LINE-1;
    assign m_axi_arsize = 3'd2;
    assign m_axi_arburst = 2'b01; // INCR
    assign m_axi_rready = state == WAIT;
endmodule
