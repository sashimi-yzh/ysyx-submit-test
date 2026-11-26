module PMEM(
  input clk,
  input rst,

  // AXI4 AR
  input mem_arvalid,
  output mem_arready,
  input [31:0] mem_araddr,
  input [3:0] mem_arid,
  input [7:0] mem_arlen,
  input [2:0] mem_arsize,
  input [1:0] mem_arburst,

  // AXI4 R
  output mem_rvalid,
  input mem_rready,
  output [1:0] mem_rresp,
  output [31:0] mem_rdata,
  output mem_rlast,
  output [3:0] mem_rid,

  // AXI4 AW
  input mem_awvalid,
  output mem_awready,
  input [31:0] mem_awaddr,
  input [3:0] mem_awid,
  input [7:0] mem_awlen,
  input [2:0] mem_awsize,
  input [1:0] mem_awburst,

  // AXI4 W
  input mem_wvalid,
  output mem_wready,
  input [31:0] mem_wdata,
  input [3:0] mem_wstrb,
  input mem_wlast,

  // AXI4 B
  output mem_bvalid,
  input mem_bready,
  output [1:0] mem_bresp,
  output [3:0] mem_bid
);

  import "DPI-C" function int pmem_read(input int raddr);
  import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

  localparam IDLE = 1'b0;
  localparam WAIT = 1'b1;

  reg read_state;
  reg write_state;
  reg aw_done;
  reg w_done;

  reg [31:0] rdata_reg;
  reg [3:0] rid_reg;
  reg [3:0] bid_reg;
  reg [31:0] awaddr_reg;
  reg [3:0] awid_reg;
  reg [31:0] wdata_reg;
  reg [3:0] wstrb_reg;

  reg [7:0]  rd_left;
  reg [31:0] rd_addr;

  wire r_fire = mem_rvalid && mem_rready;
  wire read_ready = (read_state == IDLE) || (r_fire && (rd_left == 8'd0));

  assign mem_arready = !rst && read_ready;
  assign mem_rvalid = !rst && (read_state == WAIT);
  assign mem_rresp = 2'b00;
  assign mem_rdata = rdata_reg;
  assign mem_rlast = !rst && (read_state == WAIT) && (rd_left == 8'd0);
  assign mem_rid = rid_reg;

  assign mem_awready = !rst && (write_state == IDLE) && !aw_done;
  assign mem_wready = !rst && (write_state == IDLE) && !w_done;
  assign mem_bvalid = !rst && (write_state == WAIT);
  assign mem_bresp = 2'b00;
  assign mem_bid = bid_reg;

  wire ar_fire = mem_arvalid && mem_arready;
  wire aw_fire = mem_awvalid && mem_awready;
  wire w_fire = mem_wvalid && mem_wready;
  wire aw_complete = aw_done || aw_fire;
  wire w_complete = w_done || w_fire;
  wire b_fire = mem_bvalid && mem_bready;

  always @(posedge clk) begin
    if (rst) begin
      read_state <= IDLE;
      write_state <= IDLE;
      aw_done <= 1'b0;
      w_done <= 1'b0;
      rdata_reg <= 32'b0;
      rid_reg <= 4'b0;
      bid_reg <= 4'b0;
      awaddr_reg <= 32'b0;
      awid_reg <= 4'b0;
      wdata_reg <= 32'b0;
      wstrb_reg <= 4'b0;
      rd_left <= 8'd0;
      rd_addr <= 32'b0;
    end else begin
      // 读通道独立工作，允许与写通道并行
      case (read_state)
        IDLE: begin
          if (ar_fire) begin
            rdata_reg <= pmem_read(mem_araddr);
            rid_reg   <= mem_arid;
            rd_addr   <= mem_araddr;
            rd_left   <= mem_arlen;      // 后续还需要的 beat 数
            read_state <= WAIT;
          end
        end
        WAIT: begin
          if (r_fire) begin
            if (rd_left != 8'd0) begin
              // 多 beat 突发：继续返回下一个 32 位字，保持 WAIT
              rdata_reg <= pmem_read(rd_addr + 32'd4);
              rd_addr   <= rd_addr + 32'd4;
              rd_left   <= rd_left - 8'd1;
            end else if (ar_fire) begin
              // 单 beat 完成且总线已给出下一个 AR：背靠背受理
              rdata_reg <= pmem_read(mem_araddr);
              rid_reg   <= mem_arid;
              rd_addr   <= mem_araddr;
              rd_left   <= mem_arlen;
              read_state <= WAIT;
            end else begin
              read_state <= IDLE;
            end
          end
        end
        default: read_state <= IDLE;
      endcase

      // 写通道独立工作，AW/W 可以在不同周期握手
      case (write_state)
        IDLE: begin
          if (aw_fire) begin
            awaddr_reg <= mem_awaddr;
            awid_reg <= mem_awid;
            aw_done <= 1'b1;
          end
          if (w_fire) begin
            wdata_reg <= mem_wdata;
            wstrb_reg <= mem_wstrb;
            w_done <= 1'b1;
          end

          if (aw_complete && w_complete) begin
            pmem_write(
              aw_done ? awaddr_reg : mem_awaddr,
              w_done ? wdata_reg : mem_wdata,
              {4'b0, w_done ? wstrb_reg : mem_wstrb}
            );
            bid_reg <= aw_done ? awid_reg : mem_awid;
            aw_done <= 1'b0;
            w_done <= 1'b0;
            write_state <= WAIT;
          end
        end
        WAIT: begin
          if (b_fire) begin
            write_state <= IDLE;
          end
        end
        default: write_state <= IDLE;
      endcase
    end
  end

endmodule
