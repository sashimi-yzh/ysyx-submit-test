module ysyx_26030082_ifu #(
    parameter [31:0] RESET_PC = 32'h3000_0000,
    parameter integer LINE_WORDS = 4,
    parameter integer LINE_COUNT = 4
) (
    input             clock,
    input             reset,

    // EX retire feedback
    input             ex_out_valid,
    input             ex_redirect,
    input      [31:0] ex_redirect_pc,
    input             ex_fence_i,

    // IF output interface
    output            if_out_valid,
    input             if_out_ready,
    output reg [31:0] if_pc,
    output     [31:0] if_inst,

    // AXI4 read master interface
    output     [31:0] ifu_master_araddr,
    output     [ 7:0] ifu_master_arlen,
    output     [ 1:0] ifu_master_arburst,
    output            ifu_master_arvalid,
    input             ifu_master_arready,
    input      [31:0] ifu_master_rdata,
    input      [ 1:0] ifu_master_rresp,
    input             ifu_master_rlast,
    input             ifu_master_rvalid,
    output            ifu_master_rready
);
    localparam integer BYTE_OFF_W   = 2;
    localparam integer WORD_INDEX_W = $clog2(LINE_WORDS);
    localparam integer LINE_INDEX_W = $clog2(LINE_COUNT);
    localparam integer LINE_OFF_W   = BYTE_OFF_W + WORD_INDEX_W;
    localparam integer TAG_W        = 32 - LINE_INDEX_W - LINE_OFF_W;

    localparam [WORD_INDEX_W-1:0] LINE_LAST_WORD = {WORD_INDEX_W{1'b1}};

    localparam [1:0] S_LOOKUP  = 2'd0;
    localparam [1:0] S_MISS_AR = 2'd1;
    localparam [1:0] S_MISS_R  = 2'd2;
    localparam [1:0] S_DROP_R  = 2'd3;

    reg [1:0] state;

    reg [31:0] icache_data [0:LINE_COUNT*LINE_WORDS-1];
    reg [TAG_W-1:0] icache_tag [0:LINE_COUNT-1];
    reg [LINE_COUNT-1:0] icache_valid;

    reg [WORD_INDEX_W-1:0] refill_word_idx;

    wire [WORD_INDEX_W-1:0] lookup_word_idx = if_pc[BYTE_OFF_W + WORD_INDEX_W - 1 : BYTE_OFF_W];
    wire [LINE_INDEX_W-1:0] lookup_index = if_pc[LINE_OFF_W + LINE_INDEX_W - 1 : LINE_OFF_W];
    wire [TAG_W-1:0] lookup_tag = if_pc[31 : LINE_OFF_W + LINE_INDEX_W];
    wire [LINE_INDEX_W+WORD_INDEX_W-1:0] lookup_data_idx = {lookup_index, lookup_word_idx};
    wire [LINE_INDEX_W+WORD_INDEX_W-1:0] refill_data_idx = {lookup_index, refill_word_idx};

    wire icache_hit = icache_valid[lookup_index] && (icache_tag[lookup_index] == lookup_tag);

    wire flush = ex_out_valid && ex_redirect;
    wire invalidate = ex_out_valid && ex_fence_i;
    assign if_out_valid = (state == S_LOOKUP) && icache_hit;
    assign if_inst = icache_data[lookup_data_idx];

    assign ifu_master_araddr = {if_pc[31:LINE_OFF_W], {LINE_OFF_W{1'b0}}};
    assign ifu_master_arlen = LINE_WORDS[7:0] - 8'd1;
    assign ifu_master_arburst = 2'b01;
    assign ifu_master_arvalid = (state == S_MISS_AR);
    assign ifu_master_rready = (state == S_MISS_R) || (state == S_DROP_R);

    wire ar_fire = ifu_master_arvalid && ifu_master_arready;
    wire r_fire = ifu_master_rvalid && ifu_master_rready;

    always @(posedge clock) begin
        if (reset || invalidate) begin
            icache_valid <= 0;
        end else if (ar_fire) begin
            icache_valid[lookup_index] <= 1'b0;
        end else if ((state == S_MISS_R) && r_fire && !flush) begin
            icache_valid[lookup_index] <= ifu_master_rlast;
        end
    end

    always @(posedge clock) begin
        if (reset) begin
            state <= S_LOOKUP;
            if_pc <= RESET_PC;
            refill_word_idx <= 0;
        end else begin
            if (flush) begin
                if_pc <= ex_redirect_pc;
            end else if (if_out_valid && if_out_ready) begin
                if_pc <= if_pc + 32'd4;
            end

            case (state)
                S_LOOKUP: begin
                    if (!icache_hit && !flush) begin
                        refill_word_idx <= 0;
                        state <= S_MISS_AR;
                    end
                end

                S_MISS_AR: begin
                    if (ar_fire) begin
                        icache_tag[lookup_index] <= lookup_tag;
                        state <= flush ? S_DROP_R : S_MISS_R;
                    end else if (flush) begin
                        state <= S_LOOKUP;
                    end
                end

                S_MISS_R: begin
                    if (flush) begin
                        state <= (r_fire && ifu_master_rlast) ? S_LOOKUP : S_DROP_R;
                    end else if (r_fire) begin
                        icache_data[refill_data_idx] <= ifu_master_rdata;
                        if (ifu_master_rlast) begin
                            state <= S_LOOKUP;
                        end else begin
                            refill_word_idx <= refill_word_idx + 1'b1;
                        end
                    end
                end

                S_DROP_R: begin
                    if (r_fire && ifu_master_rlast) begin
                        state <= S_LOOKUP;
                    end
                end

                default: begin
                    state <= S_LOOKUP;
                end
            endcase
        end
    end

`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
`ifndef __ICARUS__
    initial begin
        if ((LINE_WORDS < 2) || ((LINE_WORDS & (LINE_WORDS - 1)) != 0) || (LINE_WORDS > 256)) begin
            $fatal(1, "icache LINE_WORDS != 2**n (1 <= n <= 8)");
        end
        if ((LINE_COUNT < 2) || ((LINE_COUNT & (LINE_COUNT - 1)) != 0)) begin
            $fatal(1, "icache LINE_COUNT != 2**n (n >= 1)");
        end
        if (LINE_OFF_W + LINE_INDEX_W >= 32) begin
            $fatal(1, "ifu geometry is too large for ADDR_WIDTH");
        end
    end

    always @(posedge clock) begin
        if (!reset && if_out_valid && (if_pc[1:0] != 2'b00)) begin
            $fatal(1, "unaligned ifu fetch pc=%08x", if_pc);
        end
        if (!reset && ifu_master_arvalid &&
            (ifu_master_araddr[1:0] != 2'b00 ||
             ifu_master_arburst != 2'b01 ||
             ifu_master_arlen != LINE_WORDS[7:0] - 8'd1)) begin
            $fatal(1, "ifu: bad AR request pc=%08x araddr=%08x arlen=%0d arburst=%0b",
                if_pc, ifu_master_araddr, ifu_master_arlen, ifu_master_arburst);
        end
        if (!reset && (state == S_MISS_R) && r_fire) begin
            if ((refill_word_idx == LINE_LAST_WORD) && !ifu_master_rlast) begin
                $fatal(1, "ifu burst refill missing rlast on final beat line=%08x", ifu_master_araddr);
            end
            if ((refill_word_idx != LINE_LAST_WORD) && ifu_master_rlast) begin
                $fatal(1, "ifu burst refill saw early rlast line=%08x beat=%0d", ifu_master_araddr, refill_word_idx);
            end
        end
    end
`endif
`endif
`endif

    wire _unused_ok = &{1'b0, ifu_master_rresp};

endmodule
