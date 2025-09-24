module ysyx_23060170_clint (
  input                 clock ,
  input                 reset ,
  input                 Xbar_clint_ar_valid ,
  input        [31 :0]  Xbar_clint_ar_addr ,
  input        [3  :0]  Xbar_clint_ar_id ,
  input        [7  :0]  Xbar_clint_ar_len ,
  input        [2  :0]  Xbar_clint_ar_size ,
  input        [1  :0]  Xbar_clint_ar_burst ,
  input                 Xbar_clint_r_ready ,
  input                 Xbar_clint_aw_valid ,
  input        [31 :0]  Xbar_clint_aw_addr ,
  input        [3  :0]  Xbar_clint_aw_id ,
  input        [7  :0]  Xbar_clint_aw_len ,
  input        [2  :0]  Xbar_clint_aw_size ,
  input        [1  :0]  Xbar_clint_aw_burst ,
  input                 Xbar_clint_w_valid ,
  input        [31 :0]  Xbar_clint_w_data ,
  input        [3  :0]  Xbar_clint_w_strb ,
  input                 Xbar_clint_w_last ,
  input                 Xbar_clint_b_ready ,
  output  reg           clint_Xbar_ar_ready ,
  output  reg           clint_Xbar_r_valid ,
  output  reg  [31 :0]  clint_Xbar_r_data ,
  output       [1  :0]  clint_Xbar_r_resp ,
  output                clint_Xbar_r_last ,
  output       [3  :0]  clint_Xbar_r_id ,
  output  reg           clint_Xbar_aw_ready ,
  output  reg           clint_Xbar_w_ready ,
  output  reg           clint_Xbar_b_valid ,
  output       [1  :0]  clint_Xbar_b_resp ,
  output       [3  :0]  clint_Xbar_b_id 
);


reg            clint_ar_valid ;
reg            clint_aw_valid ;
reg            clint_w_valid ;
reg   [63: 0]  mtime ;

wire           Xbar_clint_ar_handshake ;
wire           clint_Xbar_r_handshake ;
wire           Xbar_clint_aw_handshake ;
wire           Xbar_clint_w_handshake ;
wire           clint_Xbar_b_handshake ;
wire           addr_is_lower ;

//======================================================
//                   unuse signal
//======================================================

assign clint_Xbar_r_resp = 2'd0;
assign clint_Xbar_r_last = 1'd1;
assign clint_Xbar_r_id   = 4'd0;
assign clint_Xbar_b_resp = 2'd0;
assign clint_Xbar_b_id   = 4'd0;

//======================================================
//           clint interface of sys bus
//======================================================

// =============== AR CHANNEL ==========================
assign Xbar_clint_ar_handshake = Xbar_clint_ar_valid && clint_Xbar_ar_ready;

// --------------- control part ------------------------

always @(posedge clock) begin

  if (reset) begin
    clint_Xbar_ar_ready <= 1'd1;
    clint_ar_valid     <= 1'd0;
  end
  else if (Xbar_clint_ar_handshake) begin
    clint_Xbar_ar_ready <= 1'd0;
    clint_ar_valid     <= 1'd1;
  end
  else if (clint_Xbar_r_handshake) begin
    clint_Xbar_ar_ready <= 1'd1;
    clint_ar_valid     <= 1'd0;
  end
  else begin
    clint_Xbar_ar_ready <= clint_Xbar_ar_ready;
    clint_ar_valid     <= clint_ar_valid;
  end

end

// =============== R CHANNEL ==========================
assign clint_Xbar_r_handshake = clint_Xbar_r_valid && Xbar_clint_r_ready;

// --------------- control part ------------------------

// =============== AW CHANNEL ==========================
assign Xbar_clint_aw_handshake = Xbar_clint_aw_valid && clint_Xbar_aw_ready;

// --------------- control part ------------------------

always @(posedge clock) begin

  if (reset) begin
    clint_Xbar_aw_ready <= 1'd1;
    clint_aw_valid     <= 1'd0;
  end
  else if (Xbar_clint_aw_handshake) begin
    clint_Xbar_aw_ready <= 1'd0;
    clint_aw_valid     <= 1'd1;
  end
  else if (clint_Xbar_b_handshake) begin
    clint_Xbar_aw_ready <= 1'd1;
    clint_aw_valid     <= 1'd0;
  end
  else begin
    clint_Xbar_aw_ready <= clint_Xbar_aw_ready;
    clint_aw_valid     <= clint_aw_valid;
  end

end

// =============== W CHANNEL ===========================
assign Xbar_clint_w_handshake = Xbar_clint_w_valid && clint_Xbar_w_ready;

// --------------- control part ------------------------

always @(posedge clock) begin

  if (reset) begin
    clint_Xbar_w_ready <= 1'd1;
    clint_w_valid     <= 1'd0;
  end
  else if (Xbar_clint_w_handshake) begin
    clint_Xbar_w_ready <= 1'd0;
    clint_w_valid     <= 1'd1;
  end
  else if (clint_Xbar_b_handshake) begin
    clint_Xbar_w_ready <= 1'd1;
    clint_w_valid     <= 1'd0;
  end
  else begin
    clint_Xbar_w_ready <= clint_Xbar_w_ready;
    clint_w_valid     <= clint_w_valid;
  end

end

// =============== B CHANNEL ===========================
assign clint_Xbar_b_handshake = clint_Xbar_b_valid && Xbar_clint_b_ready;

// --------------- control part ------------------------

// ----------------- data part ------------------------
assign addr_is_lower = Xbar_clint_ar_addr == 32'h200bff8;

always @(posedge clock) begin
  if (reset) begin
    mtime <= 64'd0;
  end
  else begin
    mtime <= mtime + 64'd1;
  end
end

always @(posedge clock) begin
  if (reset) begin
    clint_Xbar_r_data  <= 32'd0;
    clint_Xbar_r_valid <=  1'd0;
  end else if (clint_Xbar_r_handshake) begin
    clint_Xbar_r_valid <=  1'd0;
  end else if (Xbar_clint_ar_handshake || clint_ar_valid) begin
    if (addr_is_lower) begin
      clint_Xbar_r_data  <= mtime[31:0];
    end else begin
      clint_Xbar_r_data  <= mtime[63:32];
    end
    clint_Xbar_r_valid <=  1'd1;
  end else begin
    clint_Xbar_r_data  <= clint_Xbar_r_data;
    clint_Xbar_r_valid <= clint_Xbar_r_valid;
  end
end

always @(posedge clock) begin
  if (reset) begin
    clint_Xbar_b_valid <= 1'd0;
  end else if (clint_Xbar_b_handshake) begin
    clint_Xbar_b_valid <= 1'd0;
  end else if ( (Xbar_clint_aw_handshake && Xbar_clint_w_handshake)
             || (clint_aw_valid && clint_w_valid) ) begin
    clint_Xbar_b_valid <= 1'd1;
  end else begin
    clint_Xbar_b_valid <= clint_Xbar_b_valid;
  end
end

endmodule
