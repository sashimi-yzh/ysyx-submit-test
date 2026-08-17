import "DPI-C" function int pmem_read(
  input int raddr,
  input int clk,
  input int valid
);
import "DPI-C" function void pmem_write(
  input int  waddr,
  input int  wdata,
  input byte wmask
);
module Memory (
    clk,
    valid,
    wen,
    waddr,
    raddr,
    wmask,
    wdata,
    rdata
);
  input valid, wen, clk;
  input [31:0] waddr, raddr, wdata;
  input [3:0] wmask;
  output [31:0] rdata;
  // always @(clk, raddr) begin
  //   if (valid) begin  // 有读写请求时
  //     rdata = pmem_read(raddr);
  //   end else begin
  //     rdata = 0;
  //   end
  // end
  assign rdata = pmem_read(raddr, {31'b0, clk}, {31'b0, valid});
  always @(posedge clk) begin
    if (valid & wen) begin
      pmem_write(waddr, wdata, {4'h0, wmask});
    end
  end
endmodule
