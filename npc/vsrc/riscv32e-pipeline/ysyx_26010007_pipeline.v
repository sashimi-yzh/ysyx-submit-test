`include "ysyx_26010007_defines.v"
module ysyx_26010007_ifu2idu (
  input wire                 clock,
  input wire                 reset,
  input wire                 flush,

  input wire                    ifu_valid_o,
  output wire                   ifu_ready_o,
  output reg                    idu_valid_i,
  input wire                    idu_ready_i,
  
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]  ifu_pc,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]  ifu_inst,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]  idu_pc,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]  idu_inst
);
  always @(posedge clock) begin
    if (reset || flush) begin
      idu_pc <= 0;
      idu_inst <= `ysyx_26010007_INST_NOP;
    end
    else if(ifu_valid_o & ifu_ready_o) begin // stall disable IFU -> IDU
      idu_pc <= ifu_pc;
      idu_inst <= ifu_inst;
    end
  end

  always @(posedge clock) begin
    if(reset || flush) begin
      idu_valid_i <= 0;
    end
    else if(ifu_ready_o)begin
      idu_valid_i <= ifu_valid_o;
    end
  end
  assign ifu_ready_o = !idu_valid_i || idu_ready_i;
`ifdef ysyx_26010007_debug
  always @(posedge clock) begin
    if(ifu_valid_o & ifu_ready_o & flush) event_count(29);
  end
`endif
endmodule

module ysyx_26010007_idu2exu(
`ifdef ysyx_26010007_debug
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_idu_pc,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_idu_inst,
  input wire                      debug_idu_is_call,
  input wire                      debug_idu_is_ret,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    debug_exu_pc,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    debug_exu_inst,
  output reg                      debug_exu_is_call,
  output reg                      debug_exu_is_ret,
`endif
  input wire clock,
  input wire reset,
  input wire flush,

  input wire                    idu_valid_o,
  output wire                   idu_ready_o,
  output reg                    exu_valid_i,
  input wire                    exu_ready_i,
  
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_SrcA,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_SrcB,
  input wire [`ysyx_26010007_ALU_OP_WIDTH-1:0]  idu_ALU_OP,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_pc,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_plusImm,
  input wire [1:0]                idu_jump_op,
  input wire                      idu_wreg,
  input wire [`ysyx_26010007_REG_ADDR_WIDTH-1:0]idu_wa,
  input wire [4:0]                idu_MemMask,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_MemWdata,
  input wire                      idu_csrwen,
  input wire [11:0]               idu_csra,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    idu_csrwd,
  input wire [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] idu_exc_event,

  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    exu_SrcA,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    exu_SrcB,
  output reg [`ysyx_26010007_ALU_OP_WIDTH-1:0]  exu_ALU_OP,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    exu_pc,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    exu_plusImm,
  output reg [1:0]                exu_jump_op,
  output reg                      exu_wreg,
  output reg [`ysyx_26010007_REG_ADDR_WIDTH-1:0]exu_wa,
  output reg [4:0]                exu_MemMask,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    exu_MemWdata,
  output reg                      exu_csrwen,
  output reg [11:0]               exu_csra,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    exu_csrwd,
  output reg [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] exu_exc_event
);
  always @(posedge clock) begin
    if(flush) begin
      exu_wreg <= 0;
      exu_wa <= 0;
      exu_MemWdata <= 0;
      exu_MemMask <= 0;
      exu_csrwen <= 0;
      exu_csra <= 0;
      exu_csrwd <= 0;
      exu_exc_event <= 0;
      exu_pc <= 0;
      exu_plusImm <= 0;
    end
    else if(idu_valid_o && idu_ready_o) begin
      exu_wreg      <= idu_wreg;
      exu_wa        <= idu_wa;
      exu_MemWdata  <= idu_MemWdata;
      exu_MemMask   <= idu_MemMask;
      exu_csrwen    <= idu_csrwen;
      exu_csra      <= idu_csra;
      exu_csrwd     <= idu_csrwd;
      exu_exc_event <= idu_exc_event;
      exu_pc        <= idu_pc;
      exu_plusImm   <= idu_plusImm;
    end
  end

  always @(posedge clock) begin
    if(reset || flush) begin
      exu_SrcA <= 0;
      exu_SrcB <= 0;
      exu_ALU_OP <= 0;
      exu_jump_op <= 0;
`ifdef ysyx_26010007_debug
      debug_exu_pc <= 0;
      debug_exu_inst <= 0;
      debug_exu_is_call <= 0;
      debug_exu_is_ret <= 0;
`endif
    end
    else if(idu_valid_o && idu_ready_o) begin
      exu_SrcA      <= idu_SrcA;
      exu_SrcB      <= idu_SrcB;
      exu_ALU_OP    <= idu_ALU_OP;
      exu_jump_op   <= idu_jump_op;
`ifdef ysyx_26010007_debug
      debug_exu_pc <= debug_idu_pc;
      debug_exu_inst <= debug_idu_inst;
      debug_exu_is_call <= debug_idu_is_call;
      debug_exu_is_ret <= debug_idu_is_ret;
`endif
    end
  end
  always @(posedge clock) begin
    if(reset || flush) begin
      exu_valid_i <= 1'b0;
    end
    else if(idu_ready_o) begin
      exu_valid_i <= idu_valid_o;
    end
  end
assign idu_ready_o = !exu_valid_i || exu_ready_i;
`ifdef ysyx_26010007_debug
  always @(posedge clock) begin
    if(idu_valid_o && idu_ready_o & flush) event_count(29);
  end
`endif
endmodule

module ysyx_26010007_exu2lsu (
`ifdef ysyx_26010007_debug
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_exu_pc,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_exu_inst,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_exu_jaddr,
  input wire                      debug_exu_is_call,
  input wire                      debug_exu_is_ret,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    debug_lsu_pc,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    debug_lsu_inst,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    debug_lsu_jaddr,
  output reg                      debug_lsu_is_call,
  output reg                      debug_lsu_is_ret,
`endif
  input wire clock,
  input wire reset,
  input wire flush,

  input wire                    exu_valid_o,
  output wire                   exu_ready_o,
  output reg                    lsu_valid_i,
  input wire                    lsu_ready_i,
  
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_pc,
  input wire                      exu_wreg,
  input wire [`ysyx_26010007_REG_ADDR_WIDTH-1:0]exu_wa,
  input wire [4:0]                exu_MemMask,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_MemWdata,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_res,
  input wire                      exu_csrwen,
  input wire [11:0]               exu_csra,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    exu_csrwd,
  input wire [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] exu_exc_event,

  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    lsu_pc,
  output reg                      lsu_wreg,
  output reg [`ysyx_26010007_REG_ADDR_WIDTH-1:0]lsu_wa,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    lsu_addr,
  output reg [4:0]                lsu_MemMask,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    lsu_MemWdata,
  output reg                      lsu_csrwen,
  output reg [11:0]               lsu_csra,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    lsu_csrwd,
  output reg [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] lsu_exc_event
);

always @(posedge clock) begin
  if(flush) begin
    lsu_pc <= 0;
    lsu_wreg <= 0;
    lsu_wa <= 0;
    lsu_MemMask <= 0;
    lsu_MemWdata <= 0;
    lsu_addr <= 0;
    lsu_csrwen <= 0;
    lsu_csra <= 0;
    lsu_csrwd <= 0;
    lsu_exc_event <= 0;
`ifdef ysyx_26010007_debug
    debug_lsu_pc <= 0;
    debug_lsu_inst <= 0;
    debug_lsu_jaddr <= 0;
    debug_lsu_is_call <= 0;
    debug_lsu_is_ret <= 0;
`endif
  end
  else if(exu_valid_o && exu_ready_o) begin
    lsu_pc <= exu_pc;
    lsu_wreg <= exu_wreg;
    lsu_wa <= exu_wa;
    lsu_MemMask <= exu_MemMask;
    lsu_MemWdata <= exu_MemWdata;
    lsu_addr <= exu_res;
    lsu_csrwen <= exu_csrwen;
    lsu_csra <= exu_csra;
    lsu_csrwd <= exu_csrwd;
    lsu_exc_event <= exu_exc_event;
`ifdef ysyx_26010007_debug
    debug_lsu_pc <= debug_exu_pc;
    debug_lsu_inst <= debug_exu_inst;
    debug_lsu_jaddr <= debug_exu_jaddr;
    debug_lsu_is_call <= debug_exu_is_call;
    debug_lsu_is_ret <= debug_exu_is_ret;
`endif
  end
end
always @(posedge clock) begin
  if(reset || flush) begin
    lsu_valid_i <= 0;
  end
  else if(exu_ready_o) begin
    lsu_valid_i <= exu_valid_o;
  end
end
assign exu_ready_o = !lsu_valid_i || lsu_ready_i;
`ifdef ysyx_26010007_debug
  always @(posedge clock) begin
    if(exu_valid_o && lsu_ready_i && flush) event_count(29);
  end
`endif
endmodule

module ysyx_26010007_lsu2wbu (
`ifdef ysyx_26010007_debug
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_lsu_pc,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_lsu_inst,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]    debug_lsu_jaddr,
  input wire                      debug_lsu_is_call,
  input wire                      debug_lsu_is_ret,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    debug_wbu_pc,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    debug_wbu_inst,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]    debug_wbu_jaddr,
  output reg                      debug_wbu_is_call,
  output reg                      debug_wbu_is_ret,
`endif
  input wire clock,
  input wire reset,
  input wire flush,
  
  input wire                    lsu_valid_o,
  output wire                   lsu_ready_o,
  output reg                    wbu_valid_i,
  input wire                    wbu_ready_i,

  input wire [`ysyx_26010007_WORD_WIDTH-1:0]      lsu_pc,
  input wire [`ysyx_26010007_REG_ADDR_WIDTH-1:0]  lsu_wa,
  input wire                        lsu_wreg,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]      lsu_wd,
  input wire                        lsu_csrwen,
  input wire [11:0]                 lsu_csra,
  input wire [`ysyx_26010007_WORD_WIDTH-1:0]      lsu_csrwd,
  input wire [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] lsu_exc_event,

  output reg [`ysyx_26010007_WORD_WIDTH-1:0]      wbu_pc,
  output reg [`ysyx_26010007_REG_ADDR_WIDTH-1:0]  wbu_wa,
  output reg                        wbu_wreg,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]      wbu_wd,
  output reg                        wbu_csrwen,
  output reg [11:0]                 wbu_csra,
  output reg [`ysyx_26010007_WORD_WIDTH-1:0]      wbu_csrwd,
  output reg [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] wbu_exc_event
);
always @(posedge clock) begin
  if (flush) begin
    wbu_pc <= 0;
    wbu_wa <= 0;
    wbu_wreg <= 0;
    wbu_wd <= 0;
    wbu_csrwen <= 0;
    wbu_csra <= 0;
    wbu_csrwd <= 0;
    wbu_exc_event <= 0;
`ifdef ysyx_26010007_debug
    debug_wbu_pc <= 0;
    debug_wbu_inst <= 0;
    debug_wbu_jaddr <= 0;
    debug_wbu_is_call <= 0;
    debug_wbu_is_ret <= 0;
`endif
  end
  else if(lsu_valid_o & lsu_ready_o) begin
    wbu_pc <= lsu_pc;
    wbu_wa <= lsu_wa;
    wbu_wreg <= lsu_wreg;
    wbu_wd <= lsu_wd;
    wbu_csrwen <= lsu_csrwen;
    wbu_csra <= lsu_csra;
    wbu_csrwd <= lsu_csrwd;
    wbu_exc_event <= lsu_exc_event;
`ifdef ysyx_26010007_debug
    debug_wbu_pc <= debug_lsu_pc;
    debug_wbu_inst <= debug_lsu_inst;
    debug_wbu_jaddr <= debug_lsu_jaddr;
    debug_wbu_is_call <= debug_lsu_is_call;
    debug_wbu_is_ret <= debug_lsu_is_ret;
`endif
  end
end

  always @(posedge clock) begin
    if(reset || flush) begin
      wbu_valid_i <= 0; // 写寄存器不会阻塞
    end
    else begin
      wbu_valid_i <= lsu_valid_o; // 写寄存器不会阻塞
    end
  end
assign lsu_ready_o = wbu_ready_i;
`ifdef ysyx_26010007_debug
  always @(posedge clock) begin
    if(lsu_valid_o & lsu_ready_o && flush) event_count(29);
  end
`endif
endmodule