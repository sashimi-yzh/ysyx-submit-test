module ysyx_23060170_uart (
  // input
  clock,
  reset,
  Xbar_uart_ar_valid,
  Xbar_uart_ar_addr,
  Xbar_uart_ar_id,
  Xbar_uart_ar_len,
  Xbar_uart_ar_size,
  Xbar_uart_ar_burst,
  Xbar_uart_r_ready,
  Xbar_uart_aw_valid,
  Xbar_uart_aw_addr,
  Xbar_uart_aw_id,
  Xbar_uart_aw_len,
  Xbar_uart_aw_size,
  Xbar_uart_aw_burst,
  Xbar_uart_w_valid,
  Xbar_uart_w_data,
  Xbar_uart_w_strb,
  Xbar_uart_w_last,
  Xbar_uart_b_ready,
  // output
  uart_Xbar_ar_ready,
  uart_Xbar_r_valid,
  uart_Xbar_r_data,
  uart_Xbar_r_resp,
  uart_Xbar_r_last,
  uart_Xbar_r_id,
  uart_Xbar_aw_ready,
  uart_Xbar_w_ready,
  uart_Xbar_b_valid,
  uart_Xbar_b_resp,
  uart_Xbar_b_id
);

input            clock;
input            reset;
input            Xbar_uart_ar_valid;
input   [31 :0]  Xbar_uart_ar_addr;
input   [3  :0]  Xbar_uart_ar_id;
input   [7  :0]  Xbar_uart_ar_len;
input   [2  :0]  Xbar_uart_ar_size;
input   [1  :0]  Xbar_uart_ar_burst;
input            Xbar_uart_r_ready;
input            Xbar_uart_aw_valid;
input   [31 :0]  Xbar_uart_aw_addr;
input   [3  :0]  Xbar_uart_aw_id;
input   [7  :0]  Xbar_uart_aw_len;
input   [2  :0]  Xbar_uart_aw_size;
input   [1  :0]  Xbar_uart_aw_burst;
input            Xbar_uart_w_valid;
input   [31 :0]  Xbar_uart_w_data;
input   [3  :0]  Xbar_uart_w_strb;
input            Xbar_uart_w_last;
input            Xbar_uart_b_ready;
output           uart_Xbar_ar_ready;
output           uart_Xbar_r_valid;
output  [31 :0]  uart_Xbar_r_data;
output  [1  :0]  uart_Xbar_r_resp;
output           uart_Xbar_r_last;
output  [3  :0]  uart_Xbar_r_id;
output           uart_Xbar_aw_ready;
output           uart_Xbar_w_ready;
output           uart_Xbar_b_valid;
output  [1  :0]  uart_Xbar_b_resp;
output  [3  :0]  uart_Xbar_b_id;

reg              uart_Xbar_ar_ready ;
reg              uart_Xbar_r_valid ;
reg     [31 :0]  uart_Xbar_r_data ;
reg              uart_Xbar_aw_ready ;
reg              uart_Xbar_w_ready ;
reg              uart_Xbar_b_valid ;
reg              uart_ar_valid ;
reg              uart_aw_valid ;
reg              uart_w_valid ;
reg     [7  :0]  uart_out_data;

wire             Xbar_uart_ar_handshake ;
wire             uart_Xbar_r_handshake ;
wire             Xbar_uart_aw_handshake ;
wire             Xbar_uart_w_handshake ;
wire             uart_Xbar_b_handshake ;


//======================================================
//                   unuse signal
//======================================================

assign uart_Xbar_r_resp = 2'd0;
assign uart_Xbar_r_last = 1'd1;
assign uart_Xbar_r_id   = 4'd0;
assign uart_Xbar_b_resp = 2'd0;
assign uart_Xbar_b_id   = 4'd0;

//======================================================
//           uart interface of sys bus
//======================================================

// =============== AR CHANNEL ==========================
assign Xbar_uart_ar_handshake = Xbar_uart_ar_valid && uart_Xbar_ar_ready;

// --------------- control part ------------------------

always @(posedge clock) begin

  if (reset) begin
    uart_Xbar_ar_ready <= 1'd1;
    uart_ar_valid     <= 1'd0;
  end
  else if (Xbar_uart_ar_handshake) begin
    uart_Xbar_ar_ready <= 1'd0;
    uart_ar_valid     <= 1'd1;
  end
  else if (uart_Xbar_r_handshake) begin
    uart_Xbar_ar_ready <= 1'd1;
    uart_ar_valid     <= 1'd0;
  end
  else begin
    uart_Xbar_ar_ready <= uart_Xbar_ar_ready;
    uart_ar_valid     <= uart_ar_valid;
  end

end

// =============== R CHANNEL ==========================
assign uart_Xbar_r_handshake = uart_Xbar_r_valid && Xbar_uart_r_ready;

// --------------- control part ------------------------

// =============== AW CHANNEL ==========================
assign Xbar_uart_aw_handshake = Xbar_uart_aw_valid && uart_Xbar_aw_ready;

// --------------- control part ------------------------

always @(posedge clock) begin

  if (reset) begin
    uart_Xbar_aw_ready <= 1'd1;
    uart_aw_valid     <= 1'd0;
  end
  else if (Xbar_uart_aw_handshake) begin
    uart_Xbar_aw_ready <= 1'd0;
    uart_aw_valid     <= 1'd1;
  end
  else if (uart_Xbar_b_handshake) begin
    uart_Xbar_aw_ready <= 1'd1;
    uart_aw_valid     <= 1'd0;
  end
  else begin
    uart_Xbar_aw_ready <= uart_Xbar_aw_ready;
    uart_aw_valid     <= uart_aw_valid;
  end

end

// =============== W CHANNEL ===========================
assign Xbar_uart_w_handshake = Xbar_uart_w_valid && uart_Xbar_w_ready;

// --------------- control part ------------------------

always @(posedge clock) begin

  if (reset) begin
    uart_Xbar_w_ready <= 1'd1;
    uart_w_valid     <= 1'd0;
  end
  else if (Xbar_uart_w_handshake) begin
    uart_Xbar_w_ready <= 1'd0;
    uart_w_valid     <= 1'd1;
  end
  else if (uart_Xbar_b_handshake) begin
    uart_Xbar_w_ready <= 1'd1;
    uart_w_valid     <= 1'd0;
  end
  else begin
    uart_Xbar_w_ready <= uart_Xbar_w_ready;
    uart_w_valid     <= uart_w_valid;
  end

end

// =============== B CHANNEL ===========================
assign uart_Xbar_b_handshake = uart_Xbar_b_valid && Xbar_uart_b_ready;

// --------------- control part ------------------------

// ----------------- data part ------------------------

// +-----------+
// | verilator |
// +-----------+

always @(posedge clock) begin
  if (reset) begin
    uart_Xbar_r_data  <= 32'd0;
    uart_Xbar_r_valid <=  1'd0;
  end
  else if (uart_Xbar_r_handshake) begin
    uart_Xbar_r_valid <=  1'd0;
  end
  else if (Xbar_uart_ar_handshake || uart_ar_valid) begin
    uart_Xbar_r_data  <= 32'd0;
    uart_Xbar_r_valid <=  1'd1;
  end
  else begin
    uart_Xbar_r_data  <= uart_Xbar_r_data;
    uart_Xbar_r_valid <= uart_Xbar_r_valid;
  end
end

always @(*) begin
  case (Xbar_uart_w_strb)
    4'b0001: uart_out_data = Xbar_uart_w_data[7:0];
    4'b0010: uart_out_data = Xbar_uart_w_data[15:8];
    4'b0100: uart_out_data = Xbar_uart_w_data[23:16];
    4'b1000: uart_out_data = Xbar_uart_w_data[31:24];
    default: uart_out_data = Xbar_uart_w_data[7:0];
  endcase
end

always @(posedge clock) begin
  if (reset) begin
    uart_Xbar_b_valid <= 1'd0;
  end
  else if (uart_Xbar_b_handshake) begin
    uart_Xbar_b_valid <= 1'd0;
  end
  else if ( (Xbar_uart_aw_handshake && Xbar_uart_w_handshake)
             || (uart_aw_valid && uart_w_valid) ) begin
    $write("%c", uart_out_data);
    $fflush();
    uart_Xbar_b_valid <= 1'd1;
  end
  else begin
    uart_Xbar_b_valid <= uart_Xbar_b_valid;
  end
end

endmodule
