`include "ysyx_26010007_defines.v"
module ysyx_26010007_CSR (
  input clock,
  input [`WORD_WIDTH-1:0] pc,
  input [`CSR_ADDR_WIDTH-1:0] csraddr,
  input [`WORD_WIDTH-1:0] csrwdata,
  input csrwen,
  output[`WORD_WIDTH-1:0] csrrdata,
  output reg [`PADDR_WIDTH-1:0] exc_jump_addr,
  output reg exc_jump_flag,
  input [`EXC_EVENT_WIDTH-1:0] exc_event
);
  reg [`WORD_WIDTH-1:0] mcycle = `ZERO_WORD;
  reg [`WORD_WIDTH-1:0] mcycleh = `ZERO_WORD;
  reg [`WORD_WIDTH-1:0] mvendorid = 32'h79737978;
  reg [`WORD_WIDTH-1:0] marchid = 32'h018CE197;
  reg [`WORD_WIDTH-1:0] mtvec;
  reg [`WORD_WIDTH-1:0] mcause;
  reg [`WORD_WIDTH-1:0] mepc;
  reg [`WORD_WIDTH-1:0] mstatus = 32'h1800;
  // csr read
  ysyx_26010007_MuxKeyWithDefault #(8, `CSR_ADDR_WIDTH, `WORD_WIDTH) i0 (csrrdata, csraddr, 0, {
    `CSR_MCYCLE, mcycle,
    `CSR_MCYCLEH, mcycleh,
    `CSR_MVENDORID, mvendorid,
    `CSR_MARCHID, marchid,
    `CSR_MSTATUS, mstatus,
    `CSR_MEPC, mepc,
    `CSR_MCAUSE, mcause,
    `CSR_MTVEC, mtvec
  });

  // csr write
  always @(posedge clock) begin
    {mcycleh, mcycle} <= {mcycleh, mcycle} + 64'd1;
    if(csrwen) begin
      case (csraddr)
        `CSR_MSTATUS: mstatus <= csrwdata;
        `CSR_MEPC: mepc <= csrwdata;
        `CSR_MCAUSE: mcause <= csrwdata;
        `CSR_MTVEC: mtvec <= csrwdata;
        default: ;
      endcase
    end
    else begin
      case (exc_event)
        `EXC_ECALL: begin
          mepc <= pc;
          mcause <= 32'hb;
        end
        default: ;
      endcase
    end
  end

  always @(*) begin
    case (exc_event)
      `EXC_ECALL: begin
        exc_jump_addr = mtvec;
        exc_jump_flag = 1'b1;
      end
      `EXC_MRET: begin
        exc_jump_addr = mepc;
        exc_jump_flag = 1'b1;
      end
      default: begin exc_jump_addr = 32'd0; exc_jump_flag = 1'b0; end
    endcase
  end
`ifdef debug
  export "DPI-C" function npc_csrs;
  function int npc_csrs(input int addr);
    if (addr == {20'd0, `CSR_MCYCLE   }) npc_csrs = mcycle;
    else if (addr == {20'd0, `CSR_MCYCLEH  }) npc_csrs = mcycleh;
    else if (addr == {20'd0, `CSR_MVENDORID}) npc_csrs = mvendorid;
    else if (addr == {20'd0, `CSR_MARCHID  }) npc_csrs = marchid;
    else if (addr == {20'd0, `CSR_MSTATUS  }) npc_csrs = mstatus;
    else if (addr == {20'd0, `CSR_MEPC     }) npc_csrs = mepc;
    else if (addr == {20'd0, `CSR_MCAUSE   }) npc_csrs = mcause;
    else if (addr == {20'd0, `CSR_MTVEC    }) npc_csrs = mtvec;
  endfunction
`endif
endmodule