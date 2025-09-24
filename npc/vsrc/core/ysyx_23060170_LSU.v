module ysyx_23060170_LSU (
  input                 clock ,
  input                 reset ,
  input                 exu_valid ,
  input                 exu_lsu_excp ,
  input        [3  :0]  exu_lsu_excp_code ,
  input                 exu_lsu_is_fencei ,
  input                 exu_lsu_br_mispred ,
  input        [31 :0]  exu_lsu_pc ,
  input        [31 :0]  exu_lsu_npc ,
  input        [31 :0]  exu_lsu_out ,
  input        [2  :0]  exu_lsu_mem_func3 ,
  input                 exu_lsu_mem_ren ,
  input                 exu_lsu_mem_wen ,
  input        [4  :0]  exu_lsu_gpr_waddr ,
  input                 exu_lsu_gpr_wen ,
  input        [1  :0]  exu_lsu_csr_waddr ,
  input        [31 :0]  exu_lsu_csr_or_mem_wdata ,
  input                 exu_lsu_csr_wen ,
  input        [31 :0]  csr_lsu_rdata ,
  input                 Xbar_lsu_ar_ready ,
  input                 Xbar_lsu_r_valid ,
  input        [31 :0]  Xbar_lsu_r_data ,
  input        [1  :0]  Xbar_lsu_r_resp ,
  input                 Xbar_lsu_r_last ,
  input        [3  :0]  Xbar_lsu_r_id ,
  input                 Xbar_lsu_aw_ready ,
  input                 Xbar_lsu_w_ready ,
  input                 Xbar_lsu_b_valid ,
  input        [1  :0]  Xbar_lsu_b_resp ,
  input        [3  :0]  Xbar_lsu_b_id ,
`ifdef ysyx_23060170_SIM_INFO
  input        [31 :0]  exu_lsu_tpc ,
  input        [31 :0]  exu_lsu_inst ,
  output                lsu_valid /*verilator public*/,
  output                lsu_ebreak ,
  output       [31 :0]  lsu_wbu_pc /*verilator public*/,
  output       [31 :0]  lsu_wbu_npc /*verilator public*/,
  output       [31 :0]  lsu_wbu_inst /*verilator public*/,
`endif
  output                lsu_ready ,
  output  reg           lsu_flush /*verilator public*/,
  output  reg  [31 :0]  lsu_flush_pc ,
  output  reg           lsu_ifu_fencei ,
  output       [31 :0]  lsu_out /*verilator public*/,
  output                lsu_gpr_wen /*verilator public*/,
  output       [4  :0]  lsu_gpr_waddr /*verilator public*/,
  output                lsu_csr_wen /*verilator public*/,
  output       [1  :0]  lsu_csr_waddr /*verilator public*/,
  output       [31 :0]  lsu_csr_wdata /*verilator public*/,
  output                lsu_csr_excp /*verilator public*/,
  output       [3  :0]  lsu_csr_mcause /*verilator public*/,
  output  reg           lsu_Xbar_ar_valid ,
  output       [31 :0]  lsu_Xbar_ar_addr ,
  output       [3  :0]  lsu_Xbar_ar_id ,
  output       [7  :0]  lsu_Xbar_ar_len ,
  output  reg  [2  :0]  lsu_Xbar_ar_size ,
  output       [1  :0]  lsu_Xbar_ar_burst ,
  output  reg           lsu_Xbar_r_ready ,
  output  reg           lsu_Xbar_aw_valid ,
  output       [31 :0]  lsu_Xbar_aw_addr ,
  output       [3  :0]  lsu_Xbar_aw_id ,
  output       [7  :0]  lsu_Xbar_aw_len ,
  output  reg  [2  :0]  lsu_Xbar_aw_size ,
  output       [1  :0]  lsu_Xbar_aw_burst ,
  output  reg           lsu_Xbar_w_valid ,
  output       [31 :0]  lsu_Xbar_w_data ,
  output       [3  :0]  lsu_Xbar_w_strb ,
  output                lsu_Xbar_w_last ,
  output  reg           lsu_Xbar_b_ready ,
  output       [3  :0]  lsu_idu_gpr_waddr 
);

parameter MEM_B  = 3'b000;
parameter MEM_H  = 3'b001;
parameter MEM_BU = 3'b100;
parameter MEM_HU = 3'b101;

// pipeline signal
`ifdef ysyx_23060170_SIM_INFO
reg     [31 :0]  r_tpc ;
reg     [31 :0]  r_inst ;
`endif
reg     [31 :0]  r_exu_out /*verilator public*/;
reg     [2  :0]  r_mem_func3 ;
reg              r_mem_ren /*verilator public*/;
reg              r_mem_wen /*verilator public*/;
reg     [4  :0]  r_gpr_waddr ;
reg              r_gpr_wen ;
reg     [1  :0]  r_csr_waddr ;
reg     [31 :0]  r_csr_or_mem_wdata ;
reg              r_csr_wen ;
reg              r_exu_lsu_excp ;
reg     [3  :0]  r_exu_lsu_excp_code ;
reg              r_is_fencei /*verilator public*/;
reg              r_br_mispred ;
reg     [31 :0]  r_pc ;
reg     [31 :0]  r_npc ;
reg              lsu_pipe_valid ;
reg              lsu_pipe_ready ;
reg              r_ar_valid ;
reg              r_aw_valid ;
reg              r_w_valid ;
// lsu signal
reg     [3  :0]  mem_msk;
reg     [31 :0]  reg_Xbar_lsu_r_data ;
reg              can_flush ;

// pipeline control
wire             exu_lsu_handshake ;
wire             lsu_wen ;
wire             gen_flush ;
// lsu signal
wire             mem_ld_h;
wire             mem_ld_w;
wire             mem_st_h;
wire             mem_st_w;
wire             mem_lb;
wire             mem_lh;
wire    [31 :0]  mem_mask_rdata ;
wire    [31 :0]  mem_rdata_final ;
wire    [31 :0]  mem_rdata_msk ;
wire    [31 :0]  mem_rdata ;
wire             excp_ld_addr_misalign ;
wire             excp_ld_acc_fault ;
wire             excp_st_addr_misalign ;
wire             excp_st_acc_fault ;
wire             excp ;
wire    [3  :0]  excp_code ;
// axi signal
wire             lsu_Xbar_ar_handshake /*verilator public*/;
wire             Xbar_lsu_r_handshake /*verilator public*/;
wire             lsu_Xbar_aw_handshake /*verilator public*/;
wire             lsu_Xbar_w_handshake /*verilator public*/;
wire             Xbar_lsu_b_handshake /*verilator public*/;
wire    [1  :0]  addr_offset ;

//-----------------------------------------------------------------
// Flush due to Exception or Misprediction
//-----------------------------------------------------------------
// lsu exception
assign mem_ld_h = r_mem_ren && (r_mem_func3 == 3'b001 || r_mem_func3 == 3'b101);
assign mem_ld_w = r_mem_ren && (r_mem_func3 == 3'b010);
assign mem_st_h = r_mem_wen && (r_mem_func3 == 3'b001);
assign mem_st_w = r_mem_wen && (r_mem_func3 == 3'b010);

assign excp_ld_addr_misalign = mem_ld_h && (r_exu_out[0] != 1'b0)
                             || mem_ld_w && (r_exu_out[1:0] != 2'b00);
assign excp_st_addr_misalign = mem_st_h && (r_exu_out[0] != 1'b0)
                             || mem_st_w && (r_exu_out[1:0]!= 2'b00);
assign excp_ld_acc_fault     = Xbar_lsu_r_resp[1];
assign excp_st_acc_fault     = Xbar_lsu_b_resp[1];

// exception process
assign excp           = lsu_pipe_valid && (r_exu_lsu_excp || excp_ld_addr_misalign || excp_st_addr_misalign
                                          || excp_ld_acc_fault || excp_st_acc_fault);
assign excp_code      = {4{r_exu_lsu_excp}} & r_exu_lsu_excp_code
                      | {4{excp_ld_addr_misalign && !r_exu_lsu_excp}} & 4'd4
                      | {4{excp_ld_acc_fault && (!r_exu_lsu_excp || !excp_ld_addr_misalign)}} & 4'd5
                      | {4{excp_st_addr_misalign && !r_exu_lsu_excp}} & 4'd6
                      | {4{excp_st_acc_fault && (!r_exu_lsu_excp || !excp_st_addr_misalign)}} & 4'd7;
assign lsu_csr_excp   = excp;
assign lsu_csr_mcause = excp_code;
assign lsu_csr_wen    = lsu_pipe_valid && (r_csr_wen || excp);
assign lsu_csr_waddr  = excp ? 2'b1 : r_csr_waddr; // mepc or other
assign lsu_csr_wdata  = excp ? r_pc : r_csr_or_mem_wdata;

assign gen_flush = (can_flush || Xbar_lsu_r_handshake || Xbar_lsu_b_handshake)
                    && (excp || r_br_mispred || r_is_fencei);

always @(posedge clock) begin
  if (reset) begin
    can_flush <= 1'b0;
  end else if (exu_lsu_handshake) begin
    can_flush <= 1'b1;
  end else begin
    can_flush <= 1'b0;
  end
end

always @(posedge clock) begin
  if (reset) begin
    lsu_flush      <= 1'b0;
    lsu_ifu_fencei <= 1'b0;
  end
  else if (gen_flush) begin
    lsu_flush      <= 1'b1;
    lsu_ifu_fencei <= r_is_fencei;
    lsu_flush_pc   <= excp ? csr_lsu_rdata : r_npc;
  end
  else begin
    lsu_flush      <= 1'b0;
    lsu_flush_pc   <= 32'b0;
  end
end

//-----------------------------------------------------------------
// Misc Signal
//-----------------------------------------------------------------
assign lsu_Xbar_aw_id    = 4'd0;
assign lsu_Xbar_aw_len   = 8'd0;
assign lsu_Xbar_aw_burst = 2'd0;
assign lsu_Xbar_ar_id    = 4'd0;
assign lsu_Xbar_ar_len   = 8'd0;
assign lsu_Xbar_ar_burst = 2'd0;
assign lsu_Xbar_w_last   = 1'd1;

//-----------------------------------------------------------------
// Pipe Logic
//-----------------------------------------------------------------
assign exu_lsu_handshake  = exu_valid && lsu_ready;
assign lsu_wen            = exu_lsu_handshake;
assign lsu_ready          = lsu_pipe_ready || Xbar_lsu_r_handshake || Xbar_lsu_b_handshake;

// --------------- control part ------------------------
always @(posedge clock) begin
  if (reset) begin
    lsu_pipe_valid <= 1'b0;
  end else if (gen_flush) begin
    lsu_pipe_valid <= 1'b0;
  end else if (exu_lsu_handshake) begin
    lsu_pipe_valid <= 1'b1;
  end else if (!(r_mem_wen || r_mem_ren) || Xbar_lsu_r_handshake || Xbar_lsu_b_handshake) begin
    lsu_pipe_valid <= 1'b0;
  end else begin
    lsu_pipe_valid <= lsu_pipe_valid;
  end
end

always @(posedge clock) begin
  if (reset) begin
    lsu_pipe_ready <= 1'b1;
  end else if (exu_lsu_handshake && !(exu_lsu_mem_ren || exu_lsu_mem_wen) 
                || !exu_lsu_handshake && (Xbar_lsu_r_handshake || Xbar_lsu_b_handshake)) begin
    lsu_pipe_ready <= 1'b1;
  end else if (exu_lsu_handshake) begin
    lsu_pipe_ready <= 1'b0;
  end else begin
    lsu_pipe_ready <= lsu_pipe_ready;
  end
end

// ----------------- data part ------------------------
always @(posedge clock) begin
  if (reset) begin
`ifdef ysyx_23060170_SIM_INFO
    r_tpc            <= 32'h0;
    r_inst           <= 32'h0;
`endif
    r_exu_out                  <= 32'h0;
    r_mem_func3                <=  3'h0;
    r_mem_ren                  <=  1'h0;
    r_mem_wen                  <=  1'h0;
    r_gpr_waddr                <=  5'h0;
    r_gpr_wen                  <=  1'h0;
    r_csr_waddr                <=  2'h0;
    r_csr_or_mem_wdata         <= 32'h0;
    r_csr_wen                  <=  1'h0;
    r_exu_lsu_excp             <=  1'h0;
    r_exu_lsu_excp_code        <=  4'h0;
    r_is_fencei                <=  1'h0;
    r_br_mispred               <=  1'h0;
    r_pc                       <= 32'h0;
    r_npc                      <= 32'h0;
  end
  else if (lsu_wen) begin
`ifdef ysyx_23060170_SIM_INFO
    r_tpc            <= exu_lsu_tpc;
    r_inst           <= exu_lsu_inst;
`endif
    r_exu_out                  <= exu_lsu_out;
    r_mem_func3                <= exu_lsu_mem_func3;
    r_mem_ren                  <= exu_lsu_mem_ren;
    r_mem_wen                  <= exu_lsu_mem_wen;
    r_gpr_waddr                <= exu_lsu_gpr_waddr;
    r_gpr_wen                  <= exu_lsu_gpr_wen;
    r_csr_waddr                <= exu_lsu_csr_waddr;
    r_csr_or_mem_wdata         <= exu_lsu_csr_or_mem_wdata;
    r_csr_wen                  <= exu_lsu_csr_wen;
    r_exu_lsu_excp             <= exu_lsu_excp;
    r_exu_lsu_excp_code        <= exu_lsu_excp_code;
    r_is_fencei                <= exu_lsu_is_fencei;
    r_br_mispred               <= exu_lsu_br_mispred;
    r_pc                       <= exu_lsu_pc;
    r_npc                      <= exu_lsu_npc;
  end
  else begin
`ifdef ysyx_23060170_SIM_INFO
    r_tpc            <= r_tpc;
    r_inst           <= r_inst;
`endif
    r_exu_out                  <= r_exu_out;
    r_mem_func3                <= r_mem_func3;
    r_mem_ren                  <= r_mem_ren;
    r_mem_wen                  <= r_mem_wen;
    r_gpr_waddr                <= r_gpr_waddr;
    r_gpr_wen                  <= r_gpr_wen;
    r_csr_waddr                <= r_csr_waddr;
    r_csr_or_mem_wdata         <= r_csr_or_mem_wdata;
    r_csr_wen                  <= r_csr_wen;
    r_exu_lsu_excp             <= r_exu_lsu_excp;
    r_exu_lsu_excp_code        <= r_exu_lsu_excp_code;
    r_is_fencei                <= r_is_fencei;
    r_br_mispred               <= r_br_mispred;
    r_pc                       <= r_pc;
    r_npc                      <= r_npc;
  end
end

assign lsu_gpr_waddr     = r_gpr_waddr;
assign lsu_gpr_wen       = lsu_pipe_valid && r_gpr_wen;
assign lsu_idu_gpr_waddr = {4{r_gpr_wen && lsu_pipe_valid}} & r_gpr_waddr[3:0];

//-----------------------------------------------------------------
// Lsu Request
//-----------------------------------------------------------------
// =============== AR CHANNEL ==========================
assign lsu_Xbar_ar_handshake = r_ar_valid && Xbar_lsu_ar_ready;

// --------------- control part ------------------------
always @(posedge clock) begin
  if (reset) begin
    r_ar_valid <= 1'b0;
  end else if (r_ar_valid && excp_ld_addr_misalign) begin
    r_ar_valid <= 1'b0;
  end else if (lsu_Xbar_ar_handshake) begin
    r_ar_valid <= 1'b0;
  end else if (exu_lsu_handshake && exu_lsu_mem_ren && !lsu_flush && !excp) begin
    r_ar_valid <= 1'b1;
  end else begin
    r_ar_valid <= r_ar_valid;
  end
end

assign lsu_Xbar_ar_valid = r_ar_valid && ~excp_ld_addr_misalign;

// =============== R CHANNEL ===========================
assign Xbar_lsu_r_handshake = Xbar_lsu_r_valid && lsu_Xbar_r_ready;

// --------------- control part ------------------------
always @(posedge clock) begin
  if (reset) begin
    lsu_Xbar_r_ready <= 1'b1;
  end
  else if (lsu_Xbar_ar_handshake) begin
    lsu_Xbar_r_ready <= 1'b1;
  end
  else if (Xbar_lsu_r_handshake) begin
    lsu_Xbar_r_ready <= 1'b0;
  end
  else begin
    lsu_Xbar_r_ready <= lsu_Xbar_r_ready;
  end
end

// --------------- data part ---------------------------
always @( posedge clock) begin
  if (reset) begin
    reg_Xbar_lsu_r_data <= 32'd0;
  end
  else if (Xbar_lsu_r_handshake) begin
    reg_Xbar_lsu_r_data <= Xbar_lsu_r_data;
  end
  else begin
    reg_Xbar_lsu_r_data <= reg_Xbar_lsu_r_data;
  end
end

// =============== AW CHANNEL ==========================
assign lsu_Xbar_aw_handshake = r_aw_valid && Xbar_lsu_aw_ready;

// --------------- control part ------------------------
always @(posedge clock) begin
  if (reset) begin
    r_aw_valid <= 1'b0;
  end else if (r_aw_valid && excp_st_addr_misalign) begin
    r_aw_valid <= 1'b0;
  end else if (lsu_Xbar_aw_handshake) begin
    r_aw_valid <= 1'b0;
  end else if (exu_lsu_handshake && exu_lsu_mem_wen && !lsu_flush && !excp) begin
    r_aw_valid <= 1'b1;
  end else begin
    r_aw_valid <= r_aw_valid;
  end
end

assign lsu_Xbar_aw_valid = r_aw_valid && ~excp_st_addr_misalign;

// =============== W CHANNEL ===========================
assign lsu_Xbar_w_handshake = r_w_valid && Xbar_lsu_w_ready;

// --------------- control part ------------------------
always @(posedge clock) begin
  if (reset) begin
    r_w_valid <= 1'b0;
  end else if (r_w_valid && excp_st_addr_misalign) begin
    r_w_valid <= 1'b0;
  end else if (lsu_Xbar_w_handshake) begin
    r_w_valid <= 1'b0;
  end else if (exu_lsu_handshake && exu_lsu_mem_wen && !lsu_flush && !excp) begin
    r_w_valid <= 1'b1;
  end else begin
    r_w_valid <= r_w_valid;
  end
end

assign lsu_Xbar_w_valid = r_w_valid && ~excp_st_addr_misalign;

// =============== B CHANNEL ===========================
assign Xbar_lsu_b_handshake = Xbar_lsu_b_valid && lsu_Xbar_b_ready;

// --------------- control part ------------------------
always @(posedge clock) begin
  if (reset) begin
    lsu_Xbar_b_ready <= 1'b1;
  end
  else if (Xbar_lsu_b_handshake) begin
    lsu_Xbar_b_ready <= 1'b0;
  end
  else if (lsu_Xbar_aw_handshake || lsu_Xbar_w_handshake) begin
    lsu_Xbar_b_ready <= 1'b1;
  end
  else begin
    lsu_Xbar_b_ready <= lsu_Xbar_b_ready;
  end
end

//-----------------------------------------------------------------
// Access memory address align
//-----------------------------------------------------------------
always @(*) begin
  if (r_mem_func3 == MEM_B || r_mem_func3 == MEM_BU) begin
    lsu_Xbar_ar_size = 3'b000;
    lsu_Xbar_aw_size = 3'b000;
    case (r_exu_out[1:0])
      2'b00: mem_msk = 4'b0001;
      2'b01: mem_msk = 4'b0010;
      2'b10: mem_msk = 4'b0100;
      2'b11: mem_msk = 4'b1000;
      default: mem_msk = 4'b0000;
    endcase
  end
  else if (r_mem_func3 == MEM_H || r_mem_func3 == MEM_HU) begin
    lsu_Xbar_ar_size = 3'b001;
    lsu_Xbar_aw_size = 3'b001;
    case (r_exu_out[1])
      1'b0: mem_msk = 4'b0011;
      1'b1: mem_msk = 4'b1100;
      default: mem_msk = 4'b0000;
    endcase
  end
  else begin
    lsu_Xbar_ar_size = 3'b010;
    lsu_Xbar_aw_size = 3'b010;
    mem_msk = 4'b1111;
  end
end

assign mem_lb           = r_mem_func3 == MEM_B;
assign mem_lh           = r_mem_func3 == MEM_H;
assign addr_offset      = r_exu_out[1:0];
assign lsu_Xbar_aw_addr = r_exu_out;
assign lsu_Xbar_w_strb  = mem_msk;
assign lsu_Xbar_w_data  = r_csr_or_mem_wdata << {addr_offset, 3'b0};
assign lsu_Xbar_ar_addr = r_exu_out;

//-----------------------------------------------------------------
// Output
//-----------------------------------------------------------------
assign mem_rdata       = Xbar_lsu_r_handshake ? Xbar_lsu_r_data : reg_Xbar_lsu_r_data;
assign mem_rdata_msk   = { {8{mem_msk[3]}}, {8{mem_msk[2]}},
                           {8{mem_msk[1]}}, {8{mem_msk[0]}} };
assign mem_mask_rdata  = (mem_rdata_msk & mem_rdata) >> {addr_offset, 3'b0};
assign mem_rdata_final = { 32{!mem_lb && !mem_lh } } & mem_mask_rdata
                       | { 32{mem_lb} } & { {24{mem_mask_rdata[7]}}, mem_mask_rdata[7:0] }
                       | { 32{mem_lh} } & { {16{mem_mask_rdata[15]}}, mem_mask_rdata[15:0] };

assign lsu_out = r_mem_ren ? mem_rdata_final : r_exu_out;

//-----------------------------------------------------------------
// Monitor
//-----------------------------------------------------------------
`ifdef ysyx_23060170_SIM_INFO

assign lsu_ebreak    = excp && (excp_code == 4'd3);
wire   addr_in_clint /*verilator public*/;
wire   addr_in_uart /*verilator public*/;
wire   lsu_resp_exp /*verilator public*/;

assign addr_in_clint = lsu_Xbar_aw_addr >= 32'h2000000 && lsu_Xbar_aw_addr < 32'h2010000;
assign addr_in_uart  = lsu_Xbar_aw_addr >= 32'h10000000 && lsu_Xbar_aw_addr < 32'h10001000;
assign lsu_resp_exp = (Xbar_lsu_r_resp != 2'h0) || (Xbar_lsu_b_resp != 2'h0);
assign lsu_valid    = can_flush && !(r_mem_ren || r_mem_wen) || Xbar_lsu_b_handshake || Xbar_lsu_r_handshake;

assign lsu_wbu_pc        = r_pc;
assign lsu_wbu_npc       = excp ? csr_lsu_rdata : r_npc;
assign lsu_wbu_inst      = r_inst;

`endif

`ifdef ysyx_23060170_EBREAK

import "DPI-C" function void Ebreak();
always @(*) begin
  if (excp && (excp_code == 4'd3)) Ebreak();
end

`endif

endmodule
