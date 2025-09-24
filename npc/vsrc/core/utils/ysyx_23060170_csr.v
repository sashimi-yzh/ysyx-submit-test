module ysyx_23060170_csr #(
    parameter ADDR_WIDTH = 2,
    parameter DATA_WIDTH = 32
) (
    input                         clock ,
    input       [ADDR_WIDTH-1:0]  idu_csr_raddr ,
    input                         lsu_csr_wen ,
    input       [ADDR_WIDTH-1:0]  lsu_csr_waddr ,
    input       [DATA_WIDTH-1:0]  lsu_csr_wdata ,
    input                         lsu_csr_excp ,
    input       [3:0]             lsu_csr_mcause ,
    output      [DATA_WIDTH-1:0]  csr_idu_rdata ,
    output      [DATA_WIDTH-1:0]  csr_lsu_rdata 
);

reg  [DATA_WIDTH-1:0] mtvec;
reg  [DATA_WIDTH-1:0] mepc;
reg  [DATA_WIDTH-1:0] mcause;
wire [DATA_WIDTH-1:0] mstatus ;

assign mstatus = 32'h1800;

//-----------------------------------------------------------------
// Write
//-----------------------------------------------------------------
always @(posedge clock) begin
  if (lsu_csr_excp) begin
      mepc   <= lsu_csr_wdata;
      mcause <= {28'b0, lsu_csr_mcause};
  end else if (lsu_csr_wen) begin
    case (lsu_csr_waddr)
      2'd0: mtvec  <= lsu_csr_wdata;
      2'd1: mepc   <= lsu_csr_wdata;
      2'd2: mcause <= lsu_csr_wdata;
      default: ;
    endcase
  end
end

//-----------------------------------------------------------------
// Read
//-----------------------------------------------------------------
assign csr_idu_rdata = {32{(idu_csr_raddr == 2'd0)}} & mtvec
                     | {32{(idu_csr_raddr == 2'd1)}} & mepc
                     | {32{(idu_csr_raddr == 2'd2)}} & mcause
                     | {32{(idu_csr_raddr == 2'd3)}} & mstatus;
assign csr_lsu_rdata = mtvec;

endmodule
