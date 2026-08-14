`include "ysyx_26010007_defines.v"
module ysyx_26010007_IFU (
  input clock,
  input reset,
  // 握手信号
  output                    ifu_valid,
  input                     idu_ready,

  // icache与IFU的握手接口
  output                     ifu_arvalid,
  output  [`PADDR_WIDTH-1:0] ifu_araddr,
  input                      icache_irvalid, // 指令有效信号
  input   [`WORD_WIDTH-1:0]  icache_irdata, // 指令数据

  // 传输至idu的数据
  output reg [`PADDR_WIDTH-1:0] ifu_inst,
  output [`PADDR_WIDTH-1:0] ifu_pc,
  // Jump Target
  input [`PADDR_WIDTH-1:0] jump_addr,
  input jump_flag,
  input [`PADDR_WIDTH-1:0] exc_jump_addr,
  input exc_jump_flag
);
  // 上电初始化
  reg [`PADDR_WIDTH-1:0] pc = `INIT_PC;
  wire [`PADDR_WIDTH-1:0] next_pc = exc_jump_flag ? exc_jump_addr : jump_flag ? jump_addr : (pc + 32'd4);
  
  // C1: 发送取指请求
  // C2: 等待指令返回
  // C3: 指令有效，执行指令
  localparam C0 = 2'b00, C1 = 2'b01, C2 = 2'b10, C3 = 2'b11;
  reg [1:0] state;
  always @(posedge clock) begin
    if(reset) begin
      state <= C0;
    end
    else begin 
      case (state)
        C1: state <= icache_irvalid ? C2 : C1;
        C2: state <= idu_ready ? C1 : C2;
        default: state <= C1;
      endcase
    end
  end

  assign ifu_arvalid  = (state == C1);
  assign ifu_araddr   = pc;

  always @(posedge clock) begin
    if(reset) pc <= `INIT_PC;
    else if(state == C2 && idu_ready == 1'b1) pc <= next_pc;
  end

  assign ifu_valid = (state == C2);
  assign ifu_pc = pc;
  always @(posedge clock) begin
    if(reset) ifu_inst <= 32'd0;
    else if(icache_irvalid) ifu_inst <= icache_irdata;
  end
`ifdef debug
  export "DPI-C" function npc_pc;
  function int npc_pc();
    npc_pc = pc;
  endfunction

  export "DPI-C" function npc_ifu_state;
  function int npc_ifu_state();
    npc_ifu_state = {30'd0, state};
  endfunction

  always @(posedge clock) begin
    if(state == C1) event_count(15);
    else if(state == C2) event_count(16); 
  end
`endif
endmodule