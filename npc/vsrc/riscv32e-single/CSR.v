`include "defines.v"
module CSR (
  input clk,
  input rst_n,
  input [`WORD_WIDTH-1:0] pc,
  input [`CSR_ADDR_WIDTH-1:0] csraddr,
  input [`REG_DATA_WIDTH-1:0] csrwdata,
  input csrwen,
  output[`REG_DATA_WIDTH-1:0] csrrdata,
  output reg [`INST_ADDR_WIDTH-1:0] exc_jump_addr,
  output reg exc_jump_flag,
  input [`EXC_EVENT_WIDTH-1:0] exc_event
);
  reg [`REG_DATA_WIDTH-1:0] mcycle;
  reg [`REG_DATA_WIDTH-1:0] mcycleh;
  reg [`REG_DATA_WIDTH-1:0] mvendorid;
  reg [`REG_DATA_WIDTH-1:0] marchid;
  reg [`REG_DATA_WIDTH-1:0] mtvec;
  reg [`REG_DATA_WIDTH-1:0] mcause;
  reg [`REG_DATA_WIDTH-1:0] mepc;
  reg [`REG_DATA_WIDTH-1:0] mstatus;
  // csr read
  MuxKeyWithDefault #(8, `CSR_ADDR_WIDTH, `WORD_WIDTH) i0 (csrrdata, csraddr, 0, {
    `CSR_MCYCLE, mcycle,
    `CSR_MCYCLEH, mcycleh,
    `CSR_MVENDORID, mvendorid,
    `CSR_ARCHID, marchid,
    `CSR_MSTATUS, mstatus,
    `CSR_MEPC, mepc,
    `CSR_MCAUSE, mcause,
    `CSR_MTVEC, mtvec
  });

  // csr write
  always @(posedge clk) begin
    if(~rst_n) begin
      mcycle <= `ZERO_WORD;
      mcycleh <= `ZERO_WORD;
      mvendorid <= 32'h79737978;
      marchid <= 32'h018CE197;
      mstatus <= 32'h1800;
    end
    else begin
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

endmodule