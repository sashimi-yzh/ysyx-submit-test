module ysyx_23060170_icache #(
    parameter SET_NUM  = 16, // number of set in cache
    parameter SET_SIZE = 4 // number of instruction in one set
)(
    input                 clock ,
    input                 reset ,
    input                 ifu_icache_valid ,
    input        [31 :0]  ifu_icache_pc ,
    input                 Xbar_icache_ar_ready ,
    input                 Xbar_icache_r_valid ,
    input        [31 :0]  Xbar_icache_r_data ,
    input        [1  :0]  Xbar_icache_r_resp ,
    input                 Xbar_icache_r_last ,
    input        [3  :0]  Xbar_icache_r_id ,
    input                 Xbar_icache_aw_ready ,
    input                 Xbar_icache_w_ready ,
    input                 Xbar_icache_b_valid ,
    input        [1  :0]  Xbar_icache_b_resp ,
    input        [3  :0]  Xbar_icache_b_id ,
    output                icache_ifu_ready ,
    output       [31 :0]  icache_ifu_data ,
    output  reg           icache_Xbar_ar_valid ,
    output       [31 :0]  icache_Xbar_ar_addr ,
    output       [3  :0]  icache_Xbar_ar_id ,
    output       [7  :0]  icache_Xbar_ar_len ,
    output       [2  :0]  icache_Xbar_ar_size ,
    output       [1  :0]  icache_Xbar_ar_burst ,
    output  reg           icache_Xbar_r_ready ,
    output                icache_Xbar_aw_valid ,
    output       [31 :0]  icache_Xbar_aw_addr ,
    output       [3  :0]  icache_Xbar_aw_id ,
    output       [7  :0]  icache_Xbar_aw_len ,
    output       [2  :0]  icache_Xbar_aw_size ,
    output       [1  :0]  icache_Xbar_aw_burst ,
    output                icache_Xbar_w_valid ,
    output       [31 :0]  icache_Xbar_w_data ,
    output       [3  :0]  icache_Xbar_w_strb ,
    output                icache_Xbar_w_last ,
    output                icache_Xbar_b_ready 
);

parameter INDEX_WIDTH           = $clog2(SET_NUM);
parameter OFFSET_WIDTH          = $clog2(SET_SIZE);
parameter TAG_WIDTH             = 32-INDEX_WIDTH-OFFSET_WIDTH-2;
parameter TAG_ENTRY_SIZE        = TAG_WIDTH+1;
parameter DATA_ENTRY_SIZE       = 32*SET_SIZE;
parameter BUFFER_SIZE           = DATA_ENTRY_SIZE-32;

wire                     icache_hit ;
wire                     icache_miss ;
wire [INDEX_WIDTH-1 :0]  icache_index ;
wire [OFFSET_WIDTH-1:0]  icache_offset ;
wire [TAG_WIDTH-1   :0]  icache_tag ;
wire                     icache_Xbar_ar_handshake ;
wire                     Xbar_icache_r_handshake ;
wire [BUFFER_SIZE-1:0]   n_ifetch_buffer ;

reg  [DATA_ENTRY_SIZE-1:0] data_array [0:SET_NUM-1];
reg  [TAG_ENTRY_SIZE-1 :0] tag_array  [0:SET_NUM-1]; // MSB set valid infrormation
reg  [SET_SIZE-1       :0] w_ptr;
reg  [BUFFER_SIZE-1    :0] ifetch_buffer;
reg  [31               :0] icache_data ;

`ifdef ysyx_23060170_VERILATOR
enum reg [1:0] { ST_IDLE,
                 ST_REQ_DATA,
                 ST_WRITE_DATA } state, n_state;
`else
parameter ST_IDLE       = 2'b0;
parameter ST_REQ_DATA   = 2'b1;
parameter ST_WRITE_DATA = 2'b10;
reg  [1:0]  state ;
reg  [1:0]  n_state ;
`endif

//-----------------------------------------------------------------
// Icache Access
//-----------------------------------------------------------------
assign icache_index     = ifu_icache_pc[OFFSET_WIDTH+2 +: INDEX_WIDTH];
assign icache_offset    = ifu_icache_pc[2 +: OFFSET_WIDTH];
assign icache_tag       = ifu_icache_pc[31:INDEX_WIDTH+OFFSET_WIDTH+2];
assign icache_hit       = ifu_icache_valid
                          && tag_array[icache_index][TAG_ENTRY_SIZE-1]
                          && icache_tag == tag_array[icache_index][TAG_ENTRY_SIZE-2:0];
assign icache_miss      = ifu_icache_valid && !icache_hit;
// assign icache_ifu_data  = {32{icache_offset == 2'b00}} & data_array[icache_index][31:0]
//                         | {32{icache_offset == 2'b01}} & data_array[icache_index][63:32]
//                         | {32{icache_offset == 2'b10}} & data_array[icache_index][95:64]
//                         | {32{icache_offset == 2'b11}} & data_array[icache_index][127:96];
always @(*) begin
    icache_data = 32'h0;
    for(integer i=0; i<SET_SIZE; i=i+1) begin
        if(icache_offset == i[$clog2(SET_SIZE)-1:0]) begin
            icache_data = data_array[icache_index][32*(i+1)-1 -: 32];
        end
    end
end

assign icache_ifu_data = icache_data;

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
            if (Xbar_icache_r_handshake && Xbar_icache_r_last) begin
                n_state = ST_WRITE_DATA;
            end else begin
                n_state = ST_REQ_DATA;
            end
        end
        //-----------------------------------------
        // STATE_WRITE_DATA
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
assign icache_Xbar_ar_len   = SET_SIZE-1;
assign icache_Xbar_ar_size  = 3'b010;
assign icache_Xbar_ar_burst = 2'd1;
assign icache_Xbar_w_last   = 1'd1;

assign icache_Xbar_aw_valid =  1'h0;
assign icache_Xbar_aw_addr  = 32'h0;
assign icache_Xbar_w_valid  =  1'h0;
assign icache_Xbar_w_strb   =  4'h0;
assign icache_Xbar_w_data   = 32'h0;
assign icache_Xbar_b_ready  =  1'h0;

// --- AR CHANNEL ------------------------------------
assign icache_Xbar_ar_handshake = icache_Xbar_ar_valid && Xbar_icache_ar_ready;
assign icache_Xbar_ar_addr      = {ifu_icache_pc[31:OFFSET_WIDTH+2], {(OFFSET_WIDTH+2){1'b0}}};

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
  end else if (n_state == ST_WRITE_DATA) begin
    icache_Xbar_r_ready   <= 1'b0;
  end else if (icache_Xbar_ar_handshake) begin
    icache_Xbar_r_ready <= 1'b1;
  end else begin
    icache_Xbar_r_ready <= icache_Xbar_r_ready;
  end
end

always @(posedge clock) begin
  if (reset) begin
    w_ptr <= {{(SET_SIZE-1){1'b0}}, 1'b1};
  end else if (Xbar_icache_r_handshake) begin
    w_ptr <= {w_ptr[SET_SIZE-2:0], w_ptr[SET_SIZE-1]};
  end
end

always @(posedge clock) begin
  if (n_state == ST_WRITE_DATA) begin
    data_array[icache_index] <= {Xbar_icache_r_data, ifetch_buffer};
    tag_array[icache_index]  <= {1'b1, icache_tag};
  end else if (Xbar_icache_r_handshake) begin
    for(int i=0; i<SET_SIZE; i=i+1) begin
      if (w_ptr[i])
        ifetch_buffer[i*32 +: 32] <= Xbar_icache_r_data;
    end
  end
end

// assign n_ifetch_buffer = {96{burst_cnt == 8'd0}} & {ifetch_buffer[95:32], Xbar_icache_r_data}
//                        | {96{burst_cnt == 8'd1}} & {ifetch_buffer[95:64], Xbar_icache_r_data, ifetch_buffer[31:0]}
//                        | {96{burst_cnt == 8'd2}} & {Xbar_icache_r_data, ifetch_buffer[63:0]};

assign icache_ifu_ready = icache_hit || state == ST_WRITE_DATA;

endmodule
