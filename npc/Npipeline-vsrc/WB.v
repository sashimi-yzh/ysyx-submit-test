`timescale 1ns/1ps
`include "/home/furina/ysyx-workbench/npc/Npipeline-vsrc/defines/defines.v"
module WBU #(
  parameter ADDR_WIDTH = 5,
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
  
  output reg              wb_valid,
  input                   lsu_wb_flush,
  input  [31:0]           lsu_wb_pc,

  input  [11:0]           raddr_csr1,   
  input  [11:0]           raddr_csr2,   
  input                   wen_csr1,     
  input                   wen_csr2,     
  input  [31:0]           wdata_csr1,
  input  [31:0]           wdata_csr2,
  input  [11:0]           waddr_csr1,
  input  [11:0]           waddr_csr2,
  output [31:0]           rdata_csr1,
  output [31:0]           rdata_csr2     
);
reg [31:0] CSR[2**12-1:0];

reg [DATA_WIDTH-1:0] regs [2**ADDR_WIDTH-1:0];

assign wb_lsu_ready = 1;
reg    flush;
integer i;
always @(posedge clk) begin
    if(rst)begin
        for(i = 0; i < 32;i = i + 1)begin
            regs[i] <= 32'b0;
        end
    end
    else if (lsu_wb_valid && wen && (waddr != 5'b0)) begin
        // if (regs[waddr] != wdata) begin
        //     $display("[WBU] Reg x%d changed to 0x%h",  waddr, wdata);
        // end
        regs[waddr] <= wdata;
    end
end

always @(posedge clk) begin
    if (rst) begin
        wb_valid <= 1'b0;
    end
    else if (lsu_wb_valid && wb_lsu_ready) begin
        wb_valid <= 1'b1;
        flush <= lsu_wb_flush;
    end
    else begin
        wb_valid <= 1'b0;
        flush <= lsu_wb_flush;
    end
end

assign src1 = (rs1 == 5'b0) ? 32'b0 : regs[rs1];
assign src2 = (rs2 == 5'b0) ? 32'b0 : regs[rs2];


integer k;
initial begin
    for (k = 0; k < 4096; k = k + 1) begin
        if(k == 768) begin
            CSR[k] = 32'h1800;
        end
        else begin
            CSR[k] = 32'b0; 
        end
    end
end
always @(posedge clk) begin
    if (rst) begin
        CSR[32'h300] <= 32'h1800;
    end
    else if (lsu_wb_valid && (wen_csr1 | wen_csr2)) begin
        if (wen_csr2) begin
            CSR[waddr_csr1] <= wdata_csr1;
            CSR[waddr_csr2] <= wdata_csr2;
        end
        else begin
            CSR[waddr_csr1] <= wdata_csr1;
        end
    end
end
assign rdata_csr1 = CSR[raddr_csr1];
assign rdata_csr2 = CSR[raddr_csr2];
endmodule


