`include "ysyx_26010007_defines.v"
module ysyx_26010007_CSR (
  input clock,
  input reset,
  
  input [`ysyx_26010007_WORD_WIDTH-1:0] pc,
  input [`ysyx_26010007_CSR_ADDR_WIDTH-1:0] csrraddr,
  input [`ysyx_26010007_CSR_ADDR_WIDTH-1:0] csrwaddr,
  input [`ysyx_26010007_WORD_WIDTH-1:0] csrwdata,
  input csrwen,
  output[`ysyx_26010007_WORD_WIDTH-1:0] csrrdata,
  output [`ysyx_26010007_PADDR_WIDTH-1:0] exc_jump_addr,
  output exc_jump_flag,
  input [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] exc_event
);
  wire [`ysyx_26010007_WORD_WIDTH-1:0] mvendorid = 32'h79737978;
  wire [`ysyx_26010007_WORD_WIDTH-1:0] marchid = 32'h018CE197;
  reg [`ysyx_26010007_WORD_WIDTH-1:0] mtvec;
  reg [`ysyx_26010007_WORD_WIDTH-1:0] mcause;
  reg [`ysyx_26010007_WORD_WIDTH-1:0] mepc;
  reg [`ysyx_26010007_WORD_WIDTH-1:0] mstatus;
  // csr read
  wire [`ysyx_26010007_WORD_WIDTH-1:0] csrrd;
  ysyx_26010007_MuxKeyWithDefault #(6, `ysyx_26010007_CSR_ADDR_WIDTH, `ysyx_26010007_WORD_WIDTH) i0 (csrrd, csrraddr, 0, {
    `ysyx_26010007_CSR_MVENDORID, mvendorid,
    `ysyx_26010007_CSR_MARCHID, marchid,
    `ysyx_26010007_CSR_MSTATUS, mstatus,
    `ysyx_26010007_CSR_MEPC, mepc,
    `ysyx_26010007_CSR_MCAUSE, mcause,
    `ysyx_26010007_CSR_MTVEC, mtvec
  });
  assign csrrdata = (csrwen && csrwaddr == csrraddr) ? csrwdata : csrrd;

  // csr write
  always @(posedge clock) begin
    if(reset) begin
      mstatus <= 32'h1800;
    end
    else if(csrwen) begin
      case (csrwaddr)
        `ysyx_26010007_CSR_MSTATUS: mstatus <= csrwdata;
        `ysyx_26010007_CSR_MEPC: mepc <= csrwdata;
        `ysyx_26010007_CSR_MCAUSE: mcause <= csrwdata;
        `ysyx_26010007_CSR_MTVEC: mtvec <= csrwdata;
        default: ;
      endcase
    end
    else begin
      case (exc_event)
        `ysyx_26010007_EXC_ECALL: begin
          mepc <= pc;
          mcause <= 32'hb;
        end
        default: ;
      endcase
    end
  end

  wire ecall_flag = (exc_event == `ysyx_26010007_EXC_ECALL);
  wire mret_flag = (exc_event == `ysyx_26010007_EXC_MRET);
  assign exc_jump_addr = {32{ecall_flag}} & mtvec | {32{mret_flag}} & mepc;
  assign exc_jump_flag = ecall_flag | mret_flag;
`ifdef ysyx_26010007_debug
  export "DPI-C" function npc_csrs;
  function int npc_csrs(input int addr);
    if (addr == {20'd0, `ysyx_26010007_CSR_MVENDORID}) npc_csrs = mvendorid;
    else if (addr == {20'd0, `ysyx_26010007_CSR_MARCHID  }) npc_csrs = marchid;
    else if (addr == {20'd0, `ysyx_26010007_CSR_MSTATUS  }) npc_csrs = mstatus;
    else if (addr == {20'd0, `ysyx_26010007_CSR_MEPC     }) npc_csrs = mepc;
    else if (addr == {20'd0, `ysyx_26010007_CSR_MCAUSE   }) npc_csrs = mcause;
    else if (addr == {20'd0, `ysyx_26010007_CSR_MTVEC    }) npc_csrs = mtvec;
  endfunction
`endif
endmodule