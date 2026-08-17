import "DPI-C" function void notify_bus_read(
  input int id,
  input int addr,
  input int len,
  input int rsize
);
import "DPI-C" function void notify_bus_write(
  input int id,
  input int addr,
  input int len,
  input int wsize
);

module mtracer_soc (
    input clock,
    input reset,
    input arvalid,
    input arready,
    input [3:0] arid,
    input [31:0] araddr,
    input [7:0] arlen,
    input [2:0] arsize,
    input awvalid,
    input awready,
    input [3:0] awid,
    input [31:0] awaddr,
    input [7:0] awlen,
    input [2:0] awsize
);

  reg ar_busy, aw_busy;

  always @(posedge clock) begin
    if (reset) begin
      ar_busy <= 1'b0;
      aw_busy <= 1'b0;
    end else begin
      if (arvalid) begin
        if (arready) ar_busy <= 1'b0;
        else ar_busy <= 1'b1;
      end
      if (awvalid) begin
        if (awready) aw_busy <= 1'b0;
        else aw_busy <= 1'b1;
      end
    end
  end

  always @(posedge clock) begin
    if (!reset) begin
      if (arvalid && !ar_busy)
        notify_bus_read({28'b0, arid}, araddr, {24'b0, arlen}, {29'b0, arsize});
      if (awvalid && !aw_busy)
        notify_bus_write({28'b0, awid}, awaddr, {24'b0, awlen}, {29'b0, awsize});
    end
  end

endmodule

