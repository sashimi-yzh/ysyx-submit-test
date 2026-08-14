`include "ysyx_26010007_defines.v"
module ysyx_26010007_IFU (
  input clock,
  input reset,
  // 握手信号
  output                    ifu_valid_o,
  input                     ifu_ready_o,

  // icache与IFU的握手接口
  output                     ifu_arvalid,
  output  [`ysyx_26010007_PADDR_WIDTH-1:0] ifu_araddr,
  input                      icache_iarready,
  input                      icache_irvalid, // 指令有效信号
  input   [`ysyx_26010007_WORD_WIDTH-1:0]  icache_irdata, // 指令数据
  input   [`ysyx_26010007_WORD_WIDTH-1:0]  icache_ipc,

  // 传输至idu的数据
  output [`ysyx_26010007_PADDR_WIDTH-1:0] ifu_inst,
  output [`ysyx_26010007_PADDR_WIDTH-1:0] ifu_pc,

  // Jump Target
  input [`ysyx_26010007_PADDR_WIDTH-1:0]  jump_addr,
  input                     jump_flag,

  input [`ysyx_26010007_PADDR_WIDTH-1:0]  exc_jump_addr,
  input                     exc_jump_flag,

  input [`ysyx_26010007_WORD_WIDTH-1:0]   idu_pc,
  input                     fence_flush
);
  // 上电初始化
  reg [`ysyx_26010007_PADDR_WIDTH-1:0] pc;
  wire [`ysyx_26010007_PADDR_WIDTH-1:0] plus4 = pc + 32'd4;
  
  // FETCH: 发送取指请求
  // WAIT: 等待指令返回
  // JUMP: 指令有效，执行指令
  localparam FETCH = 2'b00, WAIT = 2'b01, JUMP = 2'b10;
  reg [1:0] state;
  always @(posedge clock) begin
    if(reset) begin
      state <= FETCH;
    end
    else if(exc_jump_flag | jump_flag | fence_flush) begin
      state <= JUMP;
    end
    else begin 
      case (state)
        FETCH : state <= icache_iarready & !ifu_ready_o ? WAIT : FETCH;
        WAIT : state <= ifu_ready_o ? FETCH : WAIT;
        JUMP : state <= icache_iarready ? FETCH : JUMP;
        default: state <= FETCH;
      endcase
    end
  end

  assign ifu_arvalid  = ifu_ready_o;
  assign ifu_araddr   = pc;

  always @(posedge clock) begin
    if(reset) pc <= `ysyx_26010007_INIT_PC;
    else if(exc_jump_flag) pc <= exc_jump_addr;
    else if(jump_flag) pc <= jump_addr;
    else if(fence_flush) pc <= idu_pc + 32'd4;
    else if(ifu_arvalid && icache_iarready) pc <= plus4;
  end

  assign ifu_valid_o = ((state == FETCH) && icache_irvalid) || (state == WAIT);
  assign ifu_pc = icache_ipc;
  assign ifu_inst = icache_irdata;
  
`ifdef ysyx_26010007_debug
  always @(posedge clock) begin
    if(reset) event_count(27);
    else begin
      if(ifu_arvalid & icache_iarready) event_count(0);
      if(ifu_valid_o & ifu_ready_o) event_count(28);
      if(state == FETCH) event_count(15);
      if(state == WAIT) event_count(16);
      if((state == JUMP)) event_count(30);
    end
  end
`endif
endmodule