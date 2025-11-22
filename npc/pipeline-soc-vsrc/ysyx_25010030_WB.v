`include "ysyx_25010030_define.vh"

module ysyx_25010030_WB #(
  parameter ADDR_WIDTH = 4,
  parameter DATA_WIDTH = 32)(
  input 		  clk,
  input 		  rst,
  input			  wen,
  input           lsu_wb_valid,
  output          wb_lsu_ready,

  input  [DATA_WIDTH-1:0] wdata,
  input  [ADDR_WIDTH-1:0] waddr,
  input  [ADDR_WIDTH-1:0] rs1,      
  input  [ADDR_WIDTH-1:0] rs2,      
  output [DATA_WIDTH-1:0] src1,     
  output [DATA_WIDTH-1:0] src2,     
  
`ifdef DIFFTEST
  output reg              wb_valid,
  input  [31:0]           lsu_wb_pc,
  output reg [31:0]       wb_pc,
`endif

  input  [11:0]           raddr_csr1,   
  input  [11:0]           raddr_csr2,   
  input                   wen_csr1,     
//   input                   wen_csr2, 
  input                   is_ecall,    
  input  [31:0]           wdata_csr1,
  input  [31:0]           wdata_csr2,
  input  [11:0]           waddr_csr1,
//   input  [11:0]           waddr_csr2,
  output [31:0]           rdata_csr1,
  output [31:0]           rdata_csr2     
);
// reg [31:0] CSR[2**12-1:0];
// reg [31:0] mstatus;
reg [31:0] mtvec;
reg [31:0] mepc;
// reg [31:0] mcause;
wire [31:0] mcause = 32'hb;
wire [31:0] mstatus = 32'h1800;
// wire [31:0] mvendorid = 32'h79737978;
// wire [31:0] marchid = 32'h17d9f6e;

localparam MSTATUS = 12'h300;
localparam MTVEC   = 12'h305;
localparam MEPC    = 12'h341;
localparam MCAUSE  = 12'h342;
// localparam MVENDORID = 12'hf11;
// localparam MARCHID   = 12'hf12;

reg [DATA_WIDTH-1:0] regs [2**ADDR_WIDTH-1:0];

assign wb_lsu_ready = 1;

integer i;
always @(posedge clk) begin
    if(rst)begin
        for(i = 0; i < 16; i = i + 1)begin
            regs[i] <= 32'b0;
        end
    end
    else if (lsu_wb_valid & wen & (waddr != 4'b0)) begin
        regs[waddr] <= wdata;
    end
end

`ifdef DIFFTEST
always @(posedge clk) begin
    wb_pc <= lsu_wb_pc;
    if (rst) begin
        wb_valid <= 1'b0;
    end
    else if (wb_valid) begin
        wb_valid <= 1'b0;
    end
    else if (lsu_wb_valid && wb_lsu_ready) begin
        wb_valid <= 1'b1;
    end
    else begin
        wb_valid <= 1'b0;
    end
end
`endif

assign src1 = (rs1 == 4'b0) ? 32'b0 : regs[rs1];
assign src2 = (rs2 == 4'b0) ? 32'b0 : regs[rs2];

always @(posedge clk) begin
    if (rst) begin
        // mvendorid <= 32'h79737978;
        // marchid   <= 32'h17d9f6e;

        // mstatus <= 32'h1800;
        mtvec   <= 32'h0;
        mepc    <= 32'h0;
        // mcause  <= 32'h0;
    end
    else if (lsu_wb_valid) begin
        if (wen_csr1) begin
            case(waddr_csr1)
                // MSTATUS: mstatus <= wdata_csr1;
                MTVEC:   mtvec   <= wdata_csr1;
                MEPC:    mepc    <= wdata_csr1;
                // MCAUSE:  mcause  <= wdata_csr1;
                default: ;
            endcase
        end
        if (is_ecall) begin
            // case(waddr_csr2)
            //     MSTATUS: mstatus <= wdata_csr2;
            //     MTVEC:   mtvec   <= wdata_csr2;
            //     MEPC:    mepc    <= wdata_csr2;
            //     // MCAUSE:  mcause  <= wdata_csr2;
            //     default: ;
            // endcase
            mepc <= wdata_csr2;
        end
    end
end

// assign rdata_csr1 = (raddr_csr1 == MSTATUS) ? mstatus :
//                     // (raddr_csr1 == MVENDORID) ? mvendorid :
//                     // (raddr_csr1 == MARCHID)   ? marchid   :
//                     (raddr_csr1 == MTVEC)   ? mtvec   :
//                     (raddr_csr1 == MEPC)    ? mepc    :
//                     (raddr_csr1 == MCAUSE)  ? mcause  : 32'h0;

// assign rdata_csr2 = (raddr_csr2 == MSTATUS) ? mstatus :
//                     // (raddr_csr1 == MVENDORID) ? mvendorid :
//                     // (raddr_csr1 == MARCHID)   ? marchid   :
//                     (raddr_csr2 == MTVEC)   ? mtvec   :
//                     (raddr_csr2 == MEPC)    ? mepc    :
//                     (raddr_csr2 == MCAUSE)  ? mcause  : 32'h0;
function [31:0] csr_read;
    input [11:0] addr;
    begin
    case (addr)
        MSTATUS: csr_read = mstatus;
        MTVEC:   csr_read = mtvec;
        MEPC:    csr_read = mepc;
        MCAUSE:  csr_read = mcause;
        default: csr_read = 32'h0;
    endcase
    end
endfunction

assign rdata_csr1 = csr_read(raddr_csr1);
assign rdata_csr2 = csr_read(raddr_csr2);

endmodule
