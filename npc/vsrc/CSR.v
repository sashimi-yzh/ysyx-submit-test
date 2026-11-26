module CSR(
  input clk,
  input rst,
  
  input [11:0] csr_addr,      
  input [31:0] csr_wdata,     
  input csr_wen,              
  output reg [31:0] csr_rdata,

  input is_ecall,             
  input [31:0] pc,            
  
  output reg [31:0] mepc,     
  output reg [31:0] mtvec,
  output [31:0] mstatus_out,
  output [31:0] mcause_out,
  output [31:0] mcycle_lo_out,
  output [31:0] mcycle_hi_out
);

  reg [1:0]  mstatus;   // 0x300
  //reg [31:0] mtvec;     // 0x305 
  //reg [31:0] mepc;      // 0x341 
  reg [4:0]  mcause;    // 0x342
  reg [31:0] mcycle_lo;
  reg [31:0] mcycle_hi;
  
  always @(*) begin
    case (csr_addr)
      12'h300: csr_rdata = {19'b0, mstatus, 11'b0};
      12'h305: csr_rdata = mtvec;             
      12'h341: csr_rdata = mepc;              
      12'h342: csr_rdata = {27'b0, mcause};
      12'hb00: csr_rdata = mcycle_lo;
      12'hb80: csr_rdata = mcycle_hi;
      default: csr_rdata = 32'b0;
    endcase
  end
  
  always @(posedge clk) begin
    if (rst) begin
      mstatus <= 2'b11;   // 0x1800, MPP = M-mode
      mtvec   <= 32'b0;
      mepc    <= 32'b0;
      mcause  <= 5'b0;
      mcycle_lo <= 32'b0;
      mcycle_hi <= 32'b0;
    end else begin
      mcycle_lo <= mcycle_lo + 32'd1;
      if (mcycle_lo == 32'hffff_ffff)
        mcycle_hi <= mcycle_hi + 32'd1;
      if (is_ecall) begin
        mepc   <= pc;
        mcause <= 5'd11;
      end
      else if (csr_wen) begin
        case (csr_addr)
          12'h300: mstatus <= csr_wdata[12:11];
          12'h305: mtvec   <= csr_wdata;
          12'h341: mepc    <= csr_wdata;
          12'h342: mcause  <= csr_wdata[4:0];
          default: ;
        endcase
      end
    end
  end
  
  assign mstatus_out = {19'b0, mstatus, 11'b0};
  assign mcause_out  = {27'b0, mcause};
  assign mcycle_lo_out = mcycle_lo;
  assign mcycle_hi_out = mcycle_hi;

endmodule
