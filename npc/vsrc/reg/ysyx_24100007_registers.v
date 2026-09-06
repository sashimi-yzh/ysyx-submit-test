`ifdef VERILATOR
// synopsys translate_off
import "DPI-C" function void host_get_reg(
  int regval,
  int regnum
);
import "DPI-C" function void host_get_csr(
  int csrval,
  int csrnum
);
// synopsys translate_on
`endif
module ysyx_24100007_registers (
    input clk,
    input rst,
    input ew,
    input csrrw,
    input csrrs,
    input ecall,
    input [2:0] csr_choose,
    input [4:0] addr,
    input [31:0] data,
    output [32*15-1:0] gr_flat,
    output [32*6-1:0] csr_flat
);

  reg [31:0] gr[15:1];
  reg [31:0] csr_mstatus;
  reg [31:0] csr_mtvec;
  reg [31:0] csr_mepc;
  reg [31:0] csr_mcause;

  localparam [31:0] CSR_MVENDORID = 32'h79737978;
  localparam [31:0] CSR_MARCHID   = 32'h016FBCA7;

  wire [3:0] reg_addr = addr[3:0];
  reg [31:0] csr_rdata;

  // write op
  always @(*) begin
    case (csr_choose)
      3'b000:  csr_rdata = csr_mstatus;
      3'b001:  csr_rdata = csr_mtvec;
      3'b010:  csr_rdata = csr_mepc;
      3'b011:  csr_rdata = csr_mcause;
      3'b100:  csr_rdata = CSR_MVENDORID;
      3'b101:  csr_rdata = CSR_MARCHID;
      default: csr_rdata = 32'b0;
    endcase
  end

  always @(posedge clk) begin
    if (rst) begin
      gr[1] <= 0;
      gr[2] <= 0;
      gr[3] <= 0;
      gr[4] <= 0;
      gr[5] <= 0;
      gr[6] <= 0;
      gr[7] <= 0;
      gr[8] <= 0;
      gr[9] <= 0;
      gr[10] <= 0;
      gr[11] <= 0;
      gr[12] <= 0;
      gr[13] <= 0;
      gr[14] <= 0;
      gr[15] <= 0;

      csr_mstatus <= 0;
      csr_mtvec <= 0;
      csr_mepc <= 0;
      csr_mcause <= 0;
    end else begin
      if (csrrw) begin
        if (reg_addr != 4'b0) begin
          gr[reg_addr] <= csr_rdata;
        end
        case (csr_choose)
          3'b000:  csr_mstatus <= data;
          3'b001:  csr_mtvec <= data;
          3'b010:  csr_mepc <= data;
          3'b011:  csr_mcause <= data;
          default: ;
        endcase
      end else if (csrrs) begin
        if (reg_addr != 4'b0) begin
          gr[reg_addr] <= csr_rdata;
        end
        case (csr_choose)
          3'b000:  csr_mstatus <= data | csr_mstatus;
          3'b001:  csr_mtvec <= data | csr_mtvec;
          3'b010:  csr_mepc <= data | csr_mepc;
          3'b011:  csr_mcause <= data | csr_mcause;
          default: ;
        endcase
      end else if (ew && reg_addr != 4'b0) begin
        gr[reg_addr] <= data;
      end

      if (ecall) begin
        csr_mepc   <= data;
        csr_mcause <= 32'd11;
      end
    end
  end

  // synopsys translate_off
`ifdef VERILATOR
  always @(*) begin
    integer i;
    host_get_reg(0, 0);
    for (i = 1; i < 16; i = i + 1) begin
      host_get_reg(gr[i], i);
    end

    for (i = 0; i < 4; i++) begin
      case (i)
        0: host_get_csr(csr_mstatus, i);
        1: host_get_csr(csr_mtvec, i);
        2: host_get_csr(csr_mepc, i);
        3: host_get_csr(csr_mcause, i);
      endcase
    end
  end
`endif
  // synopsys translate_on

  genvar gi;
  generate
    for (gi = 1; gi < 16; gi = gi + 1) begin : PACK_GR
      assign gr_flat[(gi-1)*32+:32] = gr[gi];
    end
  endgenerate

  assign csr_flat[0*32+:32] = csr_mstatus;
  assign csr_flat[1*32+:32] = csr_mtvec;
  assign csr_flat[2*32+:32] = csr_mepc;
  assign csr_flat[3*32+:32] = csr_mcause;
  assign csr_flat[4*32+:32] = CSR_MVENDORID;
  assign csr_flat[5*32+:32] = CSR_MARCHID;

endmodule
