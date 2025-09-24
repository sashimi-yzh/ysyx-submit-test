module ysyx_23060170_IFU (
  input                 clock ,
  input                 reset ,
  input                 idu_ready ,
  input                 lsu_ifu_flush ,
  input        [31 :0]  lsu_ifu_flush_pc ,
  input                 lsu_ifu_fencei  ,
  input                 icache_ifu_ready ,
  input        [31 :0]  icache_ifu_data ,
  input                 icache_ifu_acc_fault ,
  output                ifu_valid ,
  output                ifu_idu_excp ,
  output       [3  :0]  ifu_idu_excp_code ,
  output  reg  [31 :0]  ifu_idu_pc /*verilator public*/,
  output       [31 :0]  ifu_idu_tpc ,
  output       [31 :0]  ifu_idu_inst ,
  output                ifu_icache_flush ,
  output                ifu_icache_rls ,
  output  reg           ifu_icache_valid /*verilator public*/,
  output       [31 :0]  ifu_icache_pc /*verilator public*/
);

reg              ifu_pc_valid ;
reg     [31 :0]  reg_lsu_ifu_flush_pc ;
reg              reg_lsu_ifu_fencei ;

wire             ifu_icache_handshake /*verilator public*/;
wire             ifu_idu_handshake ;
wire    [31 :0]  npc ;
wire             excp_addr_missalign;
wire             excp_acc_fault;

`ifdef ysyx_23060170_VERILATOR
enum reg [2:0] { ST_IDLE,
                 ST_SEND_PC,
                 ST_WAIT_INST,
                 ST_WAIT_SEND_INST,
                 ST_WAIT_FLUSH } state, n_state;
`else
parameter ST_IDLE           = 3'd0;
parameter ST_SEND_PC        = 3'd1;
parameter ST_WAIT_INST      = 3'd2;
parameter ST_WAIT_SEND_INST = 3'd3;
parameter ST_WAIT_FLUSH     = 3'd4;
reg  [2:0]  state ;
reg  [2:0]  n_state ;
`endif

//-----------------------------------------------------------------
// Exception
//-----------------------------------------------------------------
assign ifu_icache_rls      = ifu_idu_handshake;
assign excp_addr_missalign = |ifu_idu_pc[1:0];
assign excp_acc_fault      = icache_ifu_acc_fault;
assign ifu_idu_excp        = excp_addr_missalign | excp_acc_fault;
assign ifu_idu_excp_code   = {4{excp_addr_missalign}} & 4'd0
                           | {4{excp_acc_fault && !excp_addr_missalign}} & 4'd1;

//-----------------------------------------------------------------
// Useful signal
//-----------------------------------------------------------------
assign ifu_icache_handshake  = ifu_icache_valid && icache_ifu_ready;
assign ifu_idu_handshake     = ifu_valid && idu_ready;
assign npc = {32{state == ST_WAIT_FLUSH}} & reg_lsu_ifu_flush_pc
           | {32{lsu_ifu_flush}} & lsu_ifu_flush_pc
           | {32{~(lsu_ifu_flush | state == ST_WAIT_FLUSH)}} & ifu_idu_pc + 32'd4;
assign ifu_idu_tpc = npc;

//-----------------------------------------------------------------
// Register
//-----------------------------------------------------------------
always @(posedge clock) begin
  if (reset) begin
    reg_lsu_ifu_flush_pc    <= 32'b0;
  end
  else if (lsu_ifu_flush) begin
    reg_lsu_ifu_flush_pc    <= lsu_ifu_flush_pc;
  end
  else begin
    reg_lsu_ifu_flush_pc    <= reg_lsu_ifu_flush_pc;
  end
end

always @(posedge clock) begin
  if (reset) begin
    reg_lsu_ifu_fencei <= 1'b0;
  end else if (ifu_icache_flush) begin
    reg_lsu_ifu_fencei <= 1'b0;
  end else if (lsu_ifu_fencei) begin
    reg_lsu_ifu_fencei <= 1'b1;
  end
end

always @(posedge clock) begin
  if (reset) begin
    `ifdef ysyx_23060170_NPC
    ifu_idu_pc              <= 32'h80000000;
    `else
    ifu_idu_pc              <= 32'h30000000;
    `endif
  end
  else if (n_state == ST_SEND_PC && state != ST_IDLE) begin
    ifu_idu_pc              <= npc;
  end
  else begin
    ifu_idu_pc              <= ifu_idu_pc;
  end
end

//-----------------------------------------------------------------
// Access Icache State Machine
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
        // ST_IDLE
        //-----------------------------------------
        ST_IDLE: begin
              n_state = ST_SEND_PC;
        end
        //-----------------------------------------
        // ST_SEND_PC
        //-----------------------------------------
        ST_SEND_PC: begin
            if (!icache_ifu_ready) begin
                if (lsu_ifu_flush) n_state = ST_WAIT_FLUSH;
                else n_state = ST_WAIT_INST;
            end else if (ifu_icache_handshake && !idu_ready) begin
                if (lsu_ifu_flush) n_state = ST_SEND_PC;
                else n_state = ST_WAIT_SEND_INST;
            end else begin
                n_state = ST_SEND_PC;
            end
        end
        //-----------------------------------------
        // ST_WAIT_INST
        //-----------------------------------------
        ST_WAIT_INST: begin
            if (lsu_ifu_flush) begin
                n_state = ST_WAIT_FLUSH;
            end else if (ifu_icache_handshake && !idu_ready) begin
                n_state = ST_WAIT_SEND_INST;
            end else if (ifu_icache_handshake) begin
                n_state = ST_SEND_PC;
            end else begin
                n_state = ST_WAIT_INST;
            end
        end
        //-----------------------------------------
        // ST_WAIT_SEND_INST
        //-----------------------------------------
        ST_WAIT_SEND_INST: begin
            if (idu_ready || lsu_ifu_flush) begin
                n_state = ST_SEND_PC;
            end else begin
                n_state = ST_WAIT_SEND_INST;
            end
        end
        //-----------------------------------------
        // ST_WAIT_FLUSH
        //-----------------------------------------
        ST_WAIT_FLUSH: begin
            if (ifu_icache_handshake) begin
                n_state = ST_SEND_PC;
            end else begin
                n_state = ST_WAIT_FLUSH;
            end
        end
        //-----------------------------------------
        // Default
        //-----------------------------------------
        default: n_state = ST_SEND_PC;
    endcase
end

//-----------------------------------------------------------------
// Output
//-----------------------------------------------------------------
assign ifu_valid         = ~(
                             state == ST_IDLE
                             || n_state == ST_WAIT_INST
                             || n_state == ST_WAIT_FLUSH
                             || state == ST_WAIT_FLUSH
                             || lsu_ifu_flush
                           );
assign ifu_pc_valid      = state == ST_SEND_PC
                           || state == ST_WAIT_INST
                           || state == ST_WAIT_FLUSH;
assign ifu_icache_valid  = ifu_pc_valid;
assign ifu_icache_pc     = ifu_idu_pc;
assign ifu_idu_inst      = icache_ifu_data;
assign ifu_icache_flush  = lsu_ifu_fencei && lsu_ifu_flush && (n_state == ST_SEND_PC)
                         || (lsu_ifu_fencei || reg_lsu_ifu_fencei) && (state == ST_WAIT_FLUSH) && (n_state == ST_SEND_PC);

endmodule
