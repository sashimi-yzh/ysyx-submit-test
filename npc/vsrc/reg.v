module Reg #(WIDTH = 1, RESET_VAL = 0) (
  input clk,
  input rst,
  input [WIDTH-1:0] din,
  output reg [WIDTH-1:0] dout,
  input wen
);
  always @(posedge clk) begin
    if (rst) dout <= RESET_VAL;
    else if (wen) dout <= din;
  end
endmodule

module ysyx_24110012_GPR_CSR_File #(
  GPR_ADDR_WIDTH = 1,
  GPR_DATA_WIDTH = 1,
  CSR_ADDR_WIDTH = 1,
  CSR_DATA_WIDTH = 1,
  MASTER_INDEX_WIDTH = 1
) (
  input clk,
  input reset,

  input rf_wen,
  input [GPR_ADDR_WIDTH-1:0] rd_idx,
  input [GPR_DATA_WIDTH-1:0] rd,
  input [GPR_ADDR_WIDTH-1:0] rs1_idx, rs2_idx,
  output [GPR_DATA_WIDTH-1:0] rs1, rs2, rdata_x,

  input csr_wen,
  input [CSR_ADDR_WIDTH-1:0] csr_r_idx,
  input [CSR_ADDR_WIDTH-1:0] csr_w_idx,
  input [CSR_DATA_WIDTH-1:0] csr_wdata,
  output reg [CSR_DATA_WIDTH-1:0] csr_rdata
);

  // GPR registers
  reg [GPR_DATA_WIDTH-1:0] rf [2**GPR_ADDR_WIDTH-1:0];

  // write
  always @(posedge clk) begin
    if (rf_wen) begin
      if (rd_idx == {GPR_ADDR_WIDTH{1'b0}}) begin
        rf[rd_idx] <= {GPR_DATA_WIDTH{1'b0}};
      end else begin
        rf[rd_idx] <= rd;
      end
    end else if (csr_wen == 1'b1) begin
      rf[rd_idx] <= rd;
    end
  end

  // read with internal write-first forwarding (WBU to IDU hazard resolution)
  assign rs1 = (rs1_idx == {GPR_ADDR_WIDTH{1'b0}}) ?
  {GPR_DATA_WIDTH{1'b0}} : (rf_wen && (rd_idx == rs1_idx)) ? rd : rf[rs1_idx];
  assign rs2 = (rs2_idx == {GPR_ADDR_WIDTH{1'b0}}) ?
  {GPR_DATA_WIDTH{1'b0}} : (rf_wen && (rd_idx == rs2_idx)) ? rd : rf[rs2_idx];
  assign rdata_x = rf[{GPR_ADDR_WIDTH{1'b0}}+10];


  // CSR registers
  parameter CSR_MVENDORID = 12'hF11;
  parameter CSR_MARCHID = 12'hF12;
  parameter CSR_MSTATUS = 12'h300;
  parameter CSR_MTVEC   = 12'h305;
  parameter CSR_MEPC    = 12'h341;
  parameter CSR_MCAUSE  = 12'h342;
  parameter CSR_MSTATUS_DIFF = 32'h00001800;
  parameter [CSR_DATA_WIDTH-1:0] CSR_MVENDORID_VAL = 32'h79737978;
  parameter [CSR_DATA_WIDTH-1:0] CSR_MARCHID_VAL = 32'h24110012;

  reg [CSR_DATA_WIDTH-1:0] csr_mstatus;
  reg [CSR_DATA_WIDTH-1:0] csr_mtvec;
  reg [CSR_DATA_WIDTH-1:0] csr_mepc;
  reg [CSR_DATA_WIDTH-1:0] csr_mcause;

  always @(posedge clk) begin
    if (reset) begin
      csr_mstatus   <= CSR_MSTATUS_DIFF;
    end else begin
      if (csr_wen) begin
      case (csr_w_idx)
        CSR_MSTATUS: begin
          csr_mstatus <= csr_wdata;
        end
        CSR_MTVEC  :
          csr_mtvec <= csr_wdata;
        CSR_MEPC   : begin
          csr_mepc <=  csr_wdata;
          csr_mcause <= {28'b0, 4'b1011}; // set mcause to 1 for ecall
        end
        CSR_MCAUSE : begin
          csr_mcause <= csr_wdata;
        end
        default    : ;
      endcase
      end
    end
  end

  always @(*) begin
    case (csr_r_idx)
      CSR_MSTATUS   : csr_rdata = CSR_MSTATUS_DIFF;
      CSR_MTVEC     : csr_rdata = (csr_wen && (csr_w_idx == CSR_MTVEC))  ? csr_wdata : csr_mtvec;
      CSR_MEPC      : csr_rdata = (csr_wen && (csr_w_idx == CSR_MEPC))   ? csr_wdata : csr_mepc;
      CSR_MCAUSE    : csr_rdata = (csr_wen && (csr_w_idx == CSR_MCAUSE)) ? csr_wdata : csr_mcause;
      CSR_MVENDORID : csr_rdata = CSR_MVENDORID_VAL;
      CSR_MARCHID   : csr_rdata = CSR_MARCHID_VAL;
      default       : csr_rdata = {CSR_DATA_WIDTH{1'b0}};
    endcase
  end



`ifndef SYNTHESIS
  // DPI-C function to access rf
  export "DPI-C" function get_gpr_npc;

  // Task to provide rf value to C++
  function int get_gpr_npc(input int index);
    if (index == 0) begin
      return 0; // return 0 for x0
    end else if (index >= 0 && index < 2**GPR_ADDR_WIDTH) begin
      return rf[index];
    end else begin
      return 0; // Return 0 for invalid index
    end
  endfunction
`endif

`ifndef SYNTHESIS
  // DPI-C function to access csr
  export "DPI-C" function get_csr_npc;

  // Task to provide csr value to C++
  function int get_csr_npc(input int index);
    case (index)
      0: return csr_mstatus;
      1: return csr_mtvec;
      2: return csr_mepc;
      3: return csr_mcause;
      default: return 0;
    endcase
  endfunction
`endif

endmodule
