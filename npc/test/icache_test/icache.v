module icache #(
    BLOCK_WIDTH  = 2,
    INDEX_WIDTH = 4
) (
    input                 clock /*verilator public*/,
    input                 reset /*verilator public*/,
    input                 ifu_icache_valid /*verilator public*/,
    input        [31 :0]  ifu_icache_pc /*verilator public*/,
    input                 Xbar_icache_ar_ready /*verilator public*/,
    input                 Xbar_icache_r_valid /*verilator public*/,
    input        [31 :0]  Xbar_icache_r_data /*verilator public*/,
    input        [1  :0]  Xbar_icache_r_resp /*verilator public*/,
    input                 Xbar_icache_r_last /*verilator public*/,
    input        [3  :0]  Xbar_icache_r_id /*verilator public*/,
    input                 Xbar_icache_aw_ready /*verilator public*/,
    input                 Xbar_icache_w_ready /*verilator public*/,
    input                 Xbar_icache_b_valid /*verilator public*/,
    input        [1  :0]  Xbar_icache_b_resp /*verilator public*/,
    input        [3  :0]  Xbar_icache_b_id /*verilator public*/,
    output                icache_ifu_ready /*verilator public*/,
    output       [31 :0]  icache_ifu_data /*verilator public*/,
    output  reg           icache_Xbar_ar_valid /*verilator public*/,
    output       [31 :0]  icache_Xbar_ar_addr /*verilator public*/,
    output       [3  :0]  icache_Xbar_ar_id /*verilator public*/,
    output       [7  :0]  icache_Xbar_ar_len /*verilator public*/,
    output       [2  :0]  icache_Xbar_ar_size /*verilator public*/,
    output       [1  :0]  icache_Xbar_ar_burst /*verilator public*/,
    output  reg           icache_Xbar_r_ready /*verilator public*/,
    output                icache_Xbar_aw_valid /*verilator public*/,
    output       [31 :0]  icache_Xbar_aw_addr /*verilator public*/,
    output       [3  :0]  icache_Xbar_aw_id /*verilator public*/,
    output       [7  :0]  icache_Xbar_aw_len /*verilator public*/,
    output       [2  :0]  icache_Xbar_aw_size /*verilator public*/,
    output       [1  :0]  icache_Xbar_aw_burst /*verilator public*/,
    output                icache_Xbar_w_valid /*verilator public*/,
    output       [31 :0]  icache_Xbar_w_data /*verilator public*/,
    output       [3  :0]  icache_Xbar_w_strb /*verilator public*/,
    output                icache_Xbar_w_last /*verilator public*/,
    output                icache_Xbar_b_ready /*verilator public*/
);

parameter TAG_ARRAY_SIZE = 32-BLOCK_WIDTH-INDEX_WIDTH+1;

wire                    icache_hit /*verilator public*/;
wire                    icache_miss /*verilator public*/;
wire [INDEX_WIDTH-1:0]  icache_index /*verilator public*/;
wire                    icache_Xbar_ar_handshake /*verilator public*/;
wire                    Xbar_icache_r_handshake /*verilator public*/;

reg  [8*2**BLOCK_WIDTH-1:0] data_array [0:2**INDEX_WIDTH-1];
reg  [TAG_ARRAY_SIZE-1:0] tag_array  [0:2**INDEX_WIDTH-1]; // MSB set valid infrormation

`ifdef ysyx_23060170_YOSYS
parameter ST_IDLE = 2'b0;
parameter ST_REQ_DATA = 2'b1;
parameter ST_WRITE_DATA = 2'b10;
reg  [1:0]  state /*verilator public*/;
reg  [1:0]  n_state /*verilator public*/;
`else
enum reg [1:0] { ST_IDLE, ST_REQ_DATA, ST_WRITE_DATA } state, n_state;
`endif

//-----------------------------------------------------------------
// Icache Access
//-----------------------------------------------------------------
assign icache_index     = ifu_icache_pc[INDEX_WIDTH+BLOCK_WIDTH-1:BLOCK_WIDTH];
assign icache_hit       = ifu_icache_valid && tag_array[icache_index][TAG_ARRAY_SIZE-1]
                          && tag_array[icache_index][TAG_ARRAY_SIZE-2:0] == ifu_icache_pc[31:INDEX_WIDTH+BLOCK_WIDTH];
assign icache_miss      = ifu_icache_valid && !icache_hit;
assign icache_ifu_data  =  data_array[icache_index];

//-----------------------------------------------------------------
// Icache State Machine
//-----------------------------------------------------------------
always @(posedge clock) begin
    if (reset) begin
        state <= ST_IDLE;
    end else begin
        state <= n_state;
    end
end

always @(*) begin
    case (state)
        //-----------------------------------------
        // STATE_IDLE
        //-----------------------------------------
        ST_IDLE: begin
            if (icache_miss) begin
                n_state = ST_REQ_DATA;
            end else begin
                n_state = ST_IDLE;
            end
        end
        //-----------------------------------------
        // STATE_REQ_DATA
        //-----------------------------------------
        ST_REQ_DATA: begin
            if (Xbar_icache_r_handshake) begin
                n_state = ST_WRITE_DATA;
            end else begin
                n_state = ST_REQ_DATA;
            end
        end
        //-----------------------------------------
        // STATE_REQ_DATA
        //-----------------------------------------
        ST_WRITE_DATA: begin
            n_state = ST_IDLE;
        end
        default: n_state = ST_IDLE;
    endcase
end

//-----------------------------------------------------------------
// Icache to Xbar and Output
//-----------------------------------------------------------------
// --- Unuse signal ------------------------------------
assign icache_Xbar_aw_id    = 4'd0;
assign icache_Xbar_aw_len   = 8'd0;
assign icache_Xbar_aw_size  = 3'b010;
assign icache_Xbar_aw_burst = 2'd0;
assign icache_Xbar_ar_id    = 4'd0;
assign icache_Xbar_ar_len   = 8'd0;
assign icache_Xbar_ar_size  = 3'b010;
assign icache_Xbar_ar_burst = 2'd0;
assign icache_Xbar_w_last   = 1'd1;

assign icache_Xbar_aw_valid =  1'h0;
assign icache_Xbar_aw_addr  = 32'h0;
assign icache_Xbar_w_valid  =  1'h0;
assign icache_Xbar_w_strb   =  4'h0;
assign icache_Xbar_w_data   = 32'h0;
assign icache_Xbar_b_ready  =  1'h0;

// --- AR CHANNEL ------------------------------------
assign icache_Xbar_ar_handshake = icache_Xbar_ar_valid && Xbar_icache_ar_ready;
assign icache_Xbar_ar_addr      = ifu_icache_pc;

always @(posedge clock) begin
  if (reset) begin
    icache_Xbar_ar_valid <= 1'b0;
  end else if (icache_Xbar_ar_handshake) begin // 同ifu_inst_valid
    icache_Xbar_ar_valid <= 1'b0;
  end else if (state == ST_IDLE && icache_miss) begin
    icache_Xbar_ar_valid <= 1'b1;
  end else begin
    icache_Xbar_ar_valid <= icache_Xbar_ar_valid;
  end
end

// --- R CHANNEL ------------------------------------
assign Xbar_icache_r_handshake = Xbar_icache_r_valid && icache_Xbar_r_ready;

always @(posedge clock) begin
  if (reset) begin
    icache_Xbar_r_ready   <= 1'b1;
  end else if (Xbar_icache_r_handshake) begin
    icache_Xbar_r_ready   <= 1'b0;
  end else if (icache_Xbar_ar_handshake) begin
    icache_Xbar_r_ready <= 1'b1;
  end else begin
    icache_Xbar_r_ready   <= icache_Xbar_r_ready;
  end
end

always @(posedge clock) begin
  if (Xbar_icache_r_handshake) begin
    data_array[icache_index] <= Xbar_icache_r_data;
    tag_array[icache_index] <= {1'b1, ifu_icache_pc[31:INDEX_WIDTH+BLOCK_WIDTH]};
  end
end

assign icache_ifu_ready = icache_hit || state == ST_WRITE_DATA;

endmodule
