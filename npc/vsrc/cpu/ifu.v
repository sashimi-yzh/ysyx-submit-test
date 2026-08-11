module ysyx_26010028_ifu #(
    parameter [31:0] RESET_PC = 32'h3000_0000
) (
    input             clock,
    input             reset,

    input             exu_allow_in,
    input             exu_redirect,
    input      [31:0] exu_redirect_pc,
    input             exu_fence,

    output            if_valid,
    input             if_ready,
    output     [31:0] inst_pc,
    output     [31:0] inst,

    output     [31:0] ifu_araddr,
    output     [ 7:0] ifu_arlen,
    output     [ 1:0] ifu_arburst,
    output            ifu_arvalid,
    input             ifu_arready,

    input      [31:0] ifu_rdata,
    input      [ 1:0] ifu_rresp,
    input             ifu_rlast,
    input             ifu_rvalid,
    output            ifu_rready
);

    // A word cache keeps the bus protocol deliberately simple: every miss is
    // one AXI beat, so no refill counter or burst-boundary state is required.
    localparam integer ENTRY_COUNT = 4;
    localparam integer INDEX_BITS  = 2;
    localparam integer TAG_BITS    = 32 - INDEX_BITS - 2;

    localparam [1:0] LOOKUP   = 2'd0;
    localparam [1:0] SEND_AR  = 2'd1;
    localparam [1:0] WAIT_R   = 2'd2;
    localparam [1:0] DISCARD  = 2'd3;

    reg [1:0] state;
    reg [31:0] pc_q;
    reg cancel_pending;

    reg [31:0] cache_data [0:ENTRY_COUNT-1];
    reg [TAG_BITS-1:0] cache_tag [0:ENTRY_COUNT-1];
    reg [ENTRY_COUNT-1:0] cache_valid;

    reg [31:0] miss_pc_q;
    reg [INDEX_BITS-1:0] miss_index_q;
    reg [TAG_BITS-1:0] miss_tag_q;

    wire redirect_event = exu_allow_in && exu_redirect;
    wire fence_event    = exu_allow_in && exu_fence;
    wire control_event  = redirect_event || fence_event;

    wire [INDEX_BITS-1:0] lookup_index = pc_q[INDEX_BITS+1:2];
    wire [TAG_BITS-1:0] lookup_tag = pc_q[31:INDEX_BITS+2];
    wire lookup_hit = cache_valid[lookup_index] && (cache_tag[lookup_index] == lookup_tag);

    wire consume_inst = if_valid && if_ready;
    wire ar_fire = ifu_arvalid && ifu_arready;
    wire fetch_rsp_hs  = ifu_rvalid && ifu_rready;

    assign inst_pc = pc_q;
    assign inst = cache_data[lookup_index];
    // IF is an independent stage.  IDU owns the IF/ID register and applies
    // back-pressure whenever EX is stalled, so a cached instruction may be
    // presented every cycle after the cache is warm.
    assign if_valid = (state == LOOKUP) && lookup_hit && !control_event;

    assign ifu_araddr  = {miss_pc_q[31:2], 2'b00};
    assign ifu_arlen   = 8'd0;
    assign ifu_arburst = 2'b01;
    assign ifu_arvalid = state == SEND_AR;
    assign ifu_rready  = (state == WAIT_R) || (state == DISCARD);

    always @(posedge clock) begin
        if (reset) begin
            state       <= LOOKUP;
            pc_q        <= RESET_PC;
            cache_valid <= {ENTRY_COUNT{1'b0}};
            miss_pc_q   <= 32'b0;
            miss_index_q <= {INDEX_BITS{1'b0}};
            miss_tag_q   <= {TAG_BITS{1'b0}};
            cancel_pending <= 1'b0;
        end else begin
            if (redirect_event) begin
                pc_q <= exu_redirect_pc;
            end else if (consume_inst) begin
                pc_q <= pc_q + 32'd4;
            end

            if (fence_event) begin
                cache_valid <= {ENTRY_COUNT{1'b0}};
            end

            case (state)
                LOOKUP: begin
                    if (!control_event && !lookup_hit) begin
                        miss_pc_q    <= pc_q;
                        miss_index_q <= lookup_index;
                        miss_tag_q   <= lookup_tag;
                        cancel_pending <= 1'b0;
                        state        <= SEND_AR;
                    end
                end

                SEND_AR: begin
                    if (control_event) begin
                        // AXI requires ARVALID and ARADDR to remain stable until
                        // the address handshake.  Remember the cancellation and
                        // discard its response instead of withdrawing the request.
                        cancel_pending <= 1'b1;
                        state <= ar_fire ? DISCARD : SEND_AR;
                    end else if (ar_fire) begin
                        if (cancel_pending) begin
                            state <= DISCARD;
                        end else begin
                            cache_valid[miss_index_q] <= 1'b0;
                            state <= WAIT_R;
                        end
                    end
                end

                WAIT_R: begin
                    if (control_event) begin
                        state <= fetch_rsp_hs ? LOOKUP : DISCARD;
                    end else if (fetch_rsp_hs) begin
                        cache_data[miss_index_q]  <= ifu_rdata;
                        cache_tag[miss_index_q]   <= miss_tag_q;
                        cache_valid[miss_index_q] <= 1'b1;
                        state <= LOOKUP;
                    end
                end

                DISCARD: begin
                    if (fetch_rsp_hs) begin
                        cancel_pending <= 1'b0;
                        state <= LOOKUP;
                    end
                end

                default: begin
                    cancel_pending <= 1'b0;
                    state <= LOOKUP;
                end
            endcase
        end
    end

`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
    always @(posedge clock) begin
        if (!reset && fetch_rsp_hs && (ifu_rresp !== 2'b00)) begin
            $fatal(1, "ifu: read response=%0b pc=%08x", ifu_rresp, miss_pc_q);
        end
        if (!reset && fetch_rsp_hs && !ifu_rlast) begin
            $fatal(1, "ifu: single-beat request returned RLAST=0 pc=%08x", miss_pc_q);
        end
    end
`endif
`endif

endmodule
