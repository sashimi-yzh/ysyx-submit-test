`ifdef NPC

`ifndef __ICARUS__
`ifndef SYNTHESIS
import "DPI-C" function int npc_pmem_read(
  input int  raddr,
  input byte rmask
);
import "DPI-C" function void npc_pmem_write(
  input int  waddr,
  input int  wdata,
  input byte wmask
);
`endif
`endif

module ysyx_24110012_mem (
  input clk,
  input reset,

  // AR
  input wire [31:0] araddr,
  input wire arvalid,
  input wire [7:0] arlen,
  output reg arready,

  // R
  output reg [31:0] rdata,
  output reg rvalid,
  output reg rlast,
  input wire rready,

  // AW
  input wire [31:0] awaddr,
  input wire awvalid,
  output reg awready,

  // W
  input wire [31:0] wdata,
  input wire [3:0] wstrb,
  input wire wvalid,
  output reg wready,

  // B
  output reg [1:0] bresp,
  output reg bvalid,
  input wire bready
);

`ifdef __ICARUS__
  localparam integer MEM_BYTES = 4 * 1024 * 1024;
  localparam integer MEM_WORDS = MEM_BYTES/4;
  reg [31:0] mem_iverilog [0:MEM_WORDS-1];  // 4KB memory
  reg [1023:0] mem_file;

  function automatic [31:0] le_word;
    input [31:0] w;
    begin
      le_word = {w[7:0], w[15:8], w[23:16], w[31:24]};
    end
  endfunction

`ifndef SYNTHESIS
  initial begin
    integer i;
    for (i = 0; i < MEM_WORDS; i = i + 1) begin
      mem_iverilog[i] = 32'b0;
    end
    if (!$value$plusargs("mem=%s", mem_file)) mem_file = "build/mem_iverilog.txt";
    $readmemh(mem_file, mem_iverilog);
    for (i = 0; i < MEM_WORDS; i = i + 1) begin
      mem_iverilog[i] = le_word(mem_iverilog[i]);
    end
    $display("MEM INIT %m addr=803fffc4 index=ffff1 data=%08h",
             mem_iverilog[20'hffff1]);
  end
`endif
`endif

  // mem write operation which requires all 4 byte aligned
`ifndef SYNTHESIS
    // assert (awaddr[1:0] == 2'b00) else
    //   $error("awaddr is %h not 4-byte aligned.", awaddr);
`endif
  localparam S_W_IDLE = 2'b00, S_W_AW = 2'b01, S_W_W = 2'b10, S_W_B = 2'b11;
  reg [1:0] w_state, w_next_state;

  always @(posedge clk) begin
    if (reset) begin
        w_state <= S_W_IDLE;
    end else begin
        w_state <= w_next_state;
    end
  end

  always @(*) begin
    case (w_state)
      S_W_IDLE: begin
        if (awvalid) begin
          w_next_state = S_W_AW;
        end else begin
          w_next_state = S_W_IDLE;
        end
      end
      S_W_AW: begin
        if (awvalid && awready) begin
          w_next_state = S_W_W;
        end else begin
          w_next_state = S_W_AW;
        end
      end
      S_W_W: begin
        if (wvalid && wready) begin
          w_next_state = S_W_B;
        end else begin
          w_next_state = S_W_W;
        end
      end
      S_W_B: begin
        if (bready) begin
          w_next_state = S_W_IDLE;
        end else begin
          w_next_state = S_W_B;
        end
      end
      default: w_next_state = S_W_IDLE;
    endcase
  end

   always @(posedge clk) begin
    if (reset) begin
      awready <= 1'b0;
      wready  <= 1'b0;
      bvalid  <= 1'b0;
      bresp   <= 2'b00;
    end else begin
      case (w_state)
        S_W_IDLE: begin
          awready <= 1'b0;
          wready  <= 1'b0;
          bvalid  <= 1'b0;
          bresp   <= 2'b00;
        end
        S_W_AW: begin
          awready <= 1'b1;
          if (awvalid && awready) begin
            awready <= 1'b0;
          end
        end
        S_W_W: begin
          wready <= 1'b1;
          if (wvalid && wready) begin
`ifndef __ICARUS__
`ifndef SYNTHESIS
            npc_pmem_write(awaddr, wdata, {4'b0, wstrb});
`endif
`else
            if (wstrb[0]) mem_iverilog[awaddr[21:2]][7:0]   <= wdata[7:0];
            if (wstrb[1]) mem_iverilog[awaddr[21:2]][15:8]  <= wdata[15:8];
            if (wstrb[2]) mem_iverilog[awaddr[21:2]][23:16] <= wdata[23:16];
            if (wstrb[3]) mem_iverilog[awaddr[21:2]][31:24] <= wdata[31:24];
`endif
            wready <= 1'b0;
            awready <= 1'b0;
          end
        end
        S_W_B: begin
          bvalid  <= 1'b1;  // indicate write response is valid
          bresp   <= 2'b00;  // OKAY response
          if (bvalid && bready) begin
            bvalid <= 1'b0;  // clear bvalid when bready is asserted
          end
        end
      endcase
    end
  end

// mem read operation only supports 4-byte aligned read
  localparam S_IDLE = 2'b00, S_AR = 2'b01, S_R = 2'b10;
  reg [1:0] state, next_state;
  reg [7:0] r_cnt;
  reg [7:0] len_reg;
  reg [31:0] read_addr;
  reg mem_r_active;

  always @(posedge clk) begin
    if (reset) begin
      state <= S_IDLE;
    end else begin
      state <= next_state;
    end
  end

  always @(*) begin
    case (state)
      S_IDLE: begin
        if (arvalid && !mem_r_active) begin
          next_state = S_AR;
        end else begin
          next_state = S_IDLE;
        end
      end
      S_AR: begin
        if (arvalid && arready) begin
          next_state = S_R;
        end else begin
          next_state = S_AR;
        end
      end
      S_R: begin
        if (rlast) begin
          next_state = S_IDLE;
        end else begin
          next_state = S_R;
        end
      end
      default: next_state = S_IDLE;
    endcase
  end

  always @(posedge clk) begin
    if (reset) begin
      mem_r_active <= 1'b0;
    end else begin
      if (state == S_IDLE && arvalid && !mem_r_active) begin
        mem_r_active <= 1'b1;
      end else if (state == S_R && rlast) begin
        mem_r_active <= 1'b0;
      end
    end
  end

  always @(posedge clk) begin
    if (reset) begin
      r_cnt <= 8'b0;
      len_reg <= 8'b0;
      read_addr <= 32'b0;
    end else begin
      case (state)
        S_IDLE: begin
          r_cnt <= 8'b0;
          len_reg <= 8'b0;
          arready <= 1'b0;
          rvalid <= 1'b0;
          rlast  <= 1'b0;
          rdata <= 32'b0;
        end
        S_AR: begin
          arready <= 1'b1;
          if (arvalid && arready) begin
            len_reg <= arlen;
            read_addr <= araddr;
            arready <= 1'b0;
          end
        end
        S_R: begin
          if (!rlast) begin
            rvalid <= 1'b1;
`ifndef __ICARUS__
`ifndef SYNTHESIS
            rdata <= npc_pmem_read(read_addr, {5'b0, 3'b111});
`endif
`else
            rdata <= mem_iverilog[read_addr[21:2]];
`endif
          end
          if (rready) begin
            rlast  <= (r_cnt == len_reg);
          end
          if (rvalid && rready) begin
            rvalid <= 1'b0;
            r_cnt <= r_cnt + 8'd1;
            read_addr <= read_addr + 32'd4;
            rdata <= 32'b0;
          end
        end
        default: begin
          r_cnt <= 8'b0;
          len_reg <= 8'b0;
          read_addr <= 32'b0;
          arready <= 1'b0;
          rvalid <= 1'b0;
          rlast  <= 1'b0;
        end
      endcase
    end
  end

endmodule

module ysyx_24110012_vuart (
    input clk,
    input reset,

    // AR
    input wire [31:0] araddr,
    input wire arvalid,
    output reg arready,

    // R
    output reg [31:0] rdata,
    output reg rvalid,
    input wire rready,

    // AW
    input wire [31:0] awaddr,
    input wire awvalid,
    output reg awready,

    // W
    input wire [31:0] wdata,
    input wire [3:0] wstrb,
    input wire wvalid,
    output reg wready,

    // B
    output reg [1:0] bresp,
    output reg bvalid,
    input wire bready
);

  reg wvalid_q;
  always @(posedge clk) begin
    if (reset) begin
      awready <= 1'b0;
      wready <= 1'b0;
      bresp <= 2'b00;
      bvalid <= 1'b0;
      wvalid_q <= 1'b0;
    end else begin
`ifndef SYNTHESIS
    if (awvalid) begin
      assert (awaddr[1:0] == 2'b00) else
      $error("awaddr is %h not 4-byte aligned.", awaddr);
    end
`endif

    if (awvalid) begin
      awready  <= 1'b1;
    end else begin
      awready <= 1'b0;
    end

    wvalid_q <= wvalid;
    if (!wvalid_q &&wvalid) begin
`ifndef SYNTHESIS
      if (awaddr[2] == 1'b0) begin
        // offset 0x0: uart data
        $write("%c", wdata[7:0]);
        $fflush;  // flush now, stdout is line-buffered (e.g. 'y' in yield has no newline)
      end else begin
        // offset 0x4: finisher, written by halt() in AM with the exit code.
        // Only ends iverilog sim; verilator flow still ends at ebreak (DPI).
`ifdef __ICARUS__
        if (wdata == 32'b0) $display("[TB INFO] HIT GOOD TRAP");
        else $display("[TB INFO] HIT BAD TRAP, exit code = %0d", wdata);
        $finish;
`endif
      end
`endif
      wready <= 1'b1;
    end

    if (wready) begin
      bresp   <= 2'b00;  // OKAY response
      bvalid  <= 1'b1;  // indicate write response is valid
      wready  <= 1'b0;
      awready <= 1'b0;
    end else if (bready) begin
      wready <= 1'b0;
      bvalid <= 1'b0;  // clear bvalid when bready is asserted
    end
    end
  end

  // should not be used for uart read in current design
  always @(posedge clk) begin
    if (reset) begin
      arready <= 1'b0;
      rdata <= 32'b0;
      rvalid <= 1'b0;
    end else begin
    if (arvalid) begin
      arready  <= 1'b1;
    end else begin
      arready <= 1'b0;
    end

    if (arvalid && arready) begin
      rdata   <= 32'b0;
      arready <= 1'b0;
      rvalid  <= 1'b1;
    end


    if (rvalid && rready) begin
      rvalid <= 1'b0;
      rdata  <= 32'b0;
    end
    end
  end

endmodule

module ysyx_24110012_ext_xbar #(
  parameter ADDR_WIDTH  = 32,
  parameter DATA_WIDTH  = 32,
  parameter NUM_MASTERS = 2
) (
  input clk,

  // slave interface
  input wire s_awvalid,
  output wire s_awready,
  input wire [ADDR_WIDTH-1:0] s_awaddr,
  input wire [2:0] s_awsize,
  input wire s_wvalid,
  output reg s_wready,
  input wire [DATA_WIDTH-1:0] s_wdata,
  input wire [DATA_WIDTH/8-1:0] s_wstrb,
  output wire [1:0] s_bresp,
  output reg s_bvalid,
  input wire s_bready,
  input wire s_arvalid,
  output reg s_arready,
  input wire [ADDR_WIDTH-1:0] s_araddr,
  input wire [2:0] s_arsize,
  input wire [1:0] s_arburst,
  input wire [7:0] s_arlen,
  output wire s_rvalid,
  input wire s_rready,
  output wire [DATA_WIDTH-1:0] s_rdata,
  output wire s_rlast,

  // master interface
  output wire [NUM_MASTERS-1:0] m_awvalid,
  input wire [NUM_MASTERS-1:0] m_awready,
  output wire [NUM_MASTERS-1:0][ADDR_WIDTH-1:0] m_awaddr,
  output wire [NUM_MASTERS-1:0][2:0] m_awsize,
  output wire [NUM_MASTERS-1:0] m_wvalid,
  input wire [NUM_MASTERS-1:0] m_wready,
  output wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_wdata,
  output wire [NUM_MASTERS-1:0][DATA_WIDTH/8-1:0] m_wstrb,
  input wire [NUM_MASTERS-1:0][1:0] m_bresp,
  input wire [NUM_MASTERS-1:0] m_bvalid,
  output wire [NUM_MASTERS-1:0] m_bready,
  output wire [NUM_MASTERS-1:0] m_arvalid,
  input wire [NUM_MASTERS-1:0] m_arready,
  output wire [NUM_MASTERS-1:0][ADDR_WIDTH-1:0] m_araddr,
  output wire [NUM_MASTERS-1:0][2:0] m_arsize,
  output wire [NUM_MASTERS-1:0][1:0] m_arburst,
  output wire [NUM_MASTERS-1:0][7:0] m_arlen,
  input wire [NUM_MASTERS-1:0] m_rvalid,
  output wire [NUM_MASTERS-1:0] m_rready,
  input wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_rdata,
  input wire [NUM_MASTERS-1:0] m_rlast

);

`ifdef NPC
  parameter P_MEM_START = 32'h8000_0000;
  parameter P_MEM_END = 32'h8100_0000;

`else
  parameter P_MEM_START = 32'h0f00_0000;
  parameter P_MEM_END = 32'hffff_ffff;
`endif

  parameter P_DEV_BASE = 32'ha000_0000;

  parameter P_UART_START = P_DEV_BASE + 32'h0000_03f8;
  parameter P_UART_END = P_UART_START + 32'h8;

  function automatic logic addr_is_mem(input [DATA_WIDTH-1:0] addr);
    addr_is_mem = (addr >= P_MEM_START) && (addr < P_MEM_END);
  endfunction

  // indicate the write/read operation is done for all dev io
  // 0 -> mem, 1 -> uart
  function automatic logic addr_is_uart(input [DATA_WIDTH-1:0] addr);
    addr_is_uart = (addr >= P_UART_START) && (addr <= P_UART_END);
  endfunction

  localparam MASTER_INDEX_WIDTH = $clog2(NUM_MASTERS);

  wire [MASTER_INDEX_WIDTH-1:0] master_index_aw;
  wire [MASTER_INDEX_WIDTH-1:0] master_index_ar;

  // write op
  // this to consider the s_awaddr no change
  wire aw_sel_uart = addr_is_uart(s_awaddr);
  wire aw_sel_mem = addr_is_mem(s_awaddr);

  // 0 stands for mem, 1 stands for uart
  assign master_index_aw = aw_sel_uart ? 1'b1 : 1'b0;

  genvar i_aw;
  generate
    for (i_aw = 0; i_aw < NUM_MASTERS; i_aw = i_aw + 1) begin : gen_xbar_w
      assign m_awaddr[i_aw]  = (i_aw == master_index_aw) ? s_awaddr : '0;
      assign m_awsize[i_aw]  = (i_aw == master_index_aw) ? s_awsize : '0;
      assign m_awvalid[i_aw] = (i_aw == master_index_aw) ? s_awvalid : 1'b0;
      assign m_wdata[i_aw]   = (i_aw == master_index_aw) ? s_wdata : '0;
      assign m_wstrb[i_aw]   = (i_aw == master_index_aw) ? s_wstrb : '0;
      assign m_wvalid[i_aw]  = (i_aw == master_index_aw) ? s_wvalid : 1'b0;
      assign m_bready[i_aw]  = (i_aw == master_index_aw) ? s_bready : 1'b0;
    end
  endgenerate

  assign s_awready = m_awready[master_index_aw];
  assign s_wready  = m_wready[master_index_aw];
  assign s_bresp   = m_bresp[master_index_aw];
  assign s_bvalid  = m_bvalid[master_index_aw];

  // read op
  // this to consider the s_araddr no change
  wire ar_sel_uart = addr_is_uart(s_araddr);
  wire ar_sel_mem = addr_is_mem(s_araddr);

  assign master_index_ar = ar_sel_uart ? 1'b1 : 1'b0;

  genvar i_ar;
  generate
    for (i_ar = 0; i_ar < NUM_MASTERS; i_ar = i_ar + 1) begin : gen_xbar_r
      assign m_araddr[i_ar]  = (i_ar == master_index_ar) ? s_araddr : '0;
      assign m_arsize[i_ar]  = (i_ar == master_index_ar) ? s_arsize : '0;
      assign m_arvalid[i_ar] = (i_ar == master_index_ar) ? s_arvalid : 1'b0;
      assign m_rready[i_ar]  = (i_ar == master_index_ar) ? s_rready : 1'b0;
      assign m_arburst[i_ar] = (i_ar == master_index_ar) ? s_arburst : 2'b0;
      assign m_arlen[i_ar]   = (i_ar == master_index_ar) ? s_arlen : 8'b0;
    end
  endgenerate

  assign s_arready = m_arready[master_index_ar];
  assign s_rdata   = m_rdata[master_index_ar];
  assign s_rlast   = m_rlast[master_index_ar];
  assign s_rvalid  = m_rvalid[master_index_ar];

endmodule

module ysyxSoCFull (
  input clock,
  input reset,
  input io_interrupt
);

  // AXI master
  wire        io_master_awready;
  wire        io_master_awvalid;
  wire [31:0] io_master_awaddr;
  wire [ 3:0] io_master_awid;
  wire [ 7:0] io_master_awlen;
  wire [ 2:0] io_master_awsize;
  wire [ 1:0] io_master_awburst;
  wire        io_master_wready;
  wire        io_master_wvalid;
  wire [31:0] io_master_wdata;
  wire [ 3:0] io_master_wstrb;
  wire        io_master_wlast;
  wire        io_master_bready;
  wire        io_master_bvalid;
  wire [ 1:0] io_master_bresp;
  wire [ 3:0] io_master_bid;
  wire        io_master_arready;
  wire        io_master_arvalid;
  wire [31:0] io_master_araddr;
  wire [ 3:0] io_master_arid;
  wire [ 7:0] io_master_arlen;
  wire [ 2:0] io_master_arsize;
  wire [ 1:0] io_master_arburst;
  wire        io_master_rready;
  wire        io_master_rvalid;
  wire [ 1:0] io_master_rresp;
  wire [31:0] io_master_rdata;
  wire        io_master_rlast;
  wire [ 3:0] io_master_rid;

  // AXI slave (unused in NPC top)
  wire        io_slave_awready;
  wire        io_slave_wready;
  wire        io_slave_bvalid;
  wire [ 1:0] io_slave_bresp;
  wire [ 3:0] io_slave_bid;
  wire        io_slave_arready;
  wire        io_slave_rvalid;
  wire [ 1:0] io_slave_rresp;
  wire [31:0] io_slave_rdata;
  wire        io_slave_rlast;
  wire [ 3:0] io_slave_rid;

  assign io_master_bid   = 4'b0;
  assign io_master_rresp = 2'b00;
  assign io_master_rid   = 4'b0;

  ysyx_24110012 cpu (
  .clock       (clock),
  .reset       (reset),
  .io_interrupt(io_interrupt),

  .io_master_awready(io_master_awready),
  .io_master_awvalid(io_master_awvalid),
  .io_master_awaddr (io_master_awaddr),
  .io_master_awid   (io_master_awid),
  .io_master_awlen  (io_master_awlen),
  .io_master_awsize (io_master_awsize),
  .io_master_awburst(io_master_awburst),

  .io_master_wready(io_master_wready),
  .io_master_wvalid(io_master_wvalid),
  .io_master_wdata (io_master_wdata),
  .io_master_wstrb (io_master_wstrb),
  .io_master_wlast (io_master_wlast),

  .io_master_bready(io_master_bready),
  .io_master_bvalid(io_master_bvalid),
  .io_master_bresp (io_master_bresp),
  .io_master_bid   (io_master_bid),

  .io_master_arready(io_master_arready),
  .io_master_arvalid(io_master_arvalid),
  .io_master_araddr (io_master_araddr),
  .io_master_arid   (io_master_arid),
  .io_master_arlen  (io_master_arlen),
  .io_master_arsize (io_master_arsize),
  .io_master_arburst(io_master_arburst),

  .io_master_rready(io_master_rready),
  .io_master_rvalid(io_master_rvalid),
  .io_master_rresp (io_master_rresp),
  .io_master_rdata (io_master_rdata),
  .io_master_rlast (io_master_rlast),
  .io_master_rid   (io_master_rid),

  .io_slave_awready(io_slave_awready),
  .io_slave_awvalid(1'b0),
  .io_slave_awaddr (32'b0),
  .io_slave_awid   (4'b0),
  .io_slave_awlen  (8'b0),
  .io_slave_awsize (3'b0),
  .io_slave_awburst(2'b0),

  .io_slave_wready(io_slave_wready),
  .io_slave_wvalid(1'b0),
  .io_slave_wdata (32'b0),
  .io_slave_wstrb (4'b0),
  .io_slave_wlast (1'b0),

  .io_slave_bready(1'b0),
  .io_slave_bvalid(io_slave_bvalid),
  .io_slave_bresp (io_slave_bresp),
  .io_slave_bid   (io_slave_bid),

  .io_slave_arready(io_slave_arready),
  .io_slave_arvalid(1'b0),
  .io_slave_araddr (32'b0),
  .io_slave_arid   (4'b0),
  .io_slave_arlen  (8'b0),
  .io_slave_arsize (3'b0),
  .io_slave_arburst(2'b0),

  .io_slave_rready(1'b0),
  .io_slave_rvalid(io_slave_rvalid),
  .io_slave_rresp (io_slave_rresp),
  .io_slave_rdata (io_slave_rdata),
  .io_slave_rlast (io_slave_rlast),
  .io_slave_rid   (io_slave_rid)
  );

  localparam integer NUM_XBAR_MASTERS = 2;
  wire [NUM_XBAR_MASTERS-1:0] m_xbar_awvalid, m_xbar_awready, m_xbar_wvalid, m_xbar_wready,
  m_xbar_bvalid, m_xbar_bready;
  wire [NUM_XBAR_MASTERS-1:0][1:0] m_xbar_bresp;
  wire [NUM_XBAR_MASTERS-1:0][31:0] m_xbar_awaddr, m_xbar_wdata;
  wire [NUM_XBAR_MASTERS-1:0][3:0] m_xbar_wstrb;
  wire [NUM_XBAR_MASTERS-1:0][2:0] m_xbar_awsize, m_xbar_arsize;
  wire [NUM_XBAR_MASTERS-1:0] m_xbar_arvalid, m_xbar_arready, m_xbar_rvalid, m_xbar_rready;
  wire [NUM_XBAR_MASTERS-1:0][31:0] m_xbar_araddr, m_xbar_rdata;
  wire [NUM_XBAR_MASTERS-1:0][1:0] m_xbar_arburst;
  wire [NUM_XBAR_MASTERS-1:0][7:0] m_xbar_arlen;
  wire [NUM_XBAR_MASTERS-1:0] m_xbar_rlast;

  ysyx_24110012_ext_xbar #(32, 32, NUM_XBAR_MASTERS) u_xbar (
  .clk      (clock),
  .s_awvalid(io_master_awvalid),
  .s_awready(io_master_awready),
  .s_awaddr (io_master_awaddr),
  .s_awsize (io_master_awsize),
  .s_wvalid (io_master_wvalid),
  .s_wready (io_master_wready),
  .s_wdata  (io_master_wdata),
  .s_wstrb  (io_master_wstrb),
  .s_bresp  (io_master_bresp),
  .s_bvalid (io_master_bvalid),
  .s_bready (io_master_bready),
  .s_arvalid(io_master_arvalid),
  .s_arsize (io_master_arsize),
  .s_arburst(io_master_arburst),
  .s_arlen  (io_master_arlen),
  .s_arready(io_master_arready),
  .s_araddr (io_master_araddr),
  .s_rvalid (io_master_rvalid),
  .s_rready (io_master_rready),
  .s_rdata  (io_master_rdata),
  .s_rlast  (io_master_rlast),
  .m_awvalid(m_xbar_awvalid),
  .m_awready(m_xbar_awready),
  .m_awaddr (m_xbar_awaddr),
  .m_awsize (m_xbar_awsize),
  .m_wvalid (m_xbar_wvalid),
  .m_wready (m_xbar_wready),
  .m_wdata  (m_xbar_wdata),
  .m_wstrb  (m_xbar_wstrb),
  .m_bresp  (m_xbar_bresp),
  .m_bvalid (m_xbar_bvalid),
  .m_bready (m_xbar_bready),
  .m_arvalid(m_xbar_arvalid),
  .m_arready(m_xbar_arready),
  .m_araddr (m_xbar_araddr),
  .m_arsize (m_xbar_arsize),
  .m_arburst(m_xbar_arburst),
  .m_arlen  (m_xbar_arlen),
  .m_rvalid (m_xbar_rvalid),
  .m_rready (m_xbar_rready),
  .m_rdata  (m_xbar_rdata),
  .m_rlast  (m_xbar_rlast)
  );

  ysyx_24110012_mem my_mem (
  .clk    (clock),
  .reset  (reset),
  .araddr (m_xbar_araddr[0]),
  .arvalid(m_xbar_arvalid[0]),
  .arlen  (m_xbar_arlen[0]),
  .arready(m_xbar_arready[0]),
  .rdata  (m_xbar_rdata[0]),
  .rvalid (m_xbar_rvalid[0]),
  .rlast  (m_xbar_rlast[0]),
  .rready (m_xbar_rready[0]),
  .awaddr (m_xbar_awaddr[0]),
  .awvalid(m_xbar_awvalid[0]),
  .awready(m_xbar_awready[0]),
  .wdata  (m_xbar_wdata[0]),
  .wstrb  (m_xbar_wstrb[0]),
  .wvalid (m_xbar_wvalid[0]),
  .wready (m_xbar_wready[0]),
  .bresp  (m_xbar_bresp[0]),
  .bvalid (m_xbar_bvalid[0]),
  .bready (m_xbar_bready[0])
  );

  ysyx_24110012_vuart u_vuart (
  .clk    (clock),
  .reset  (reset),
  .araddr (m_xbar_araddr[1]),
  .arvalid(m_xbar_arvalid[1]),
  .arready(m_xbar_arready[1]),
  .rdata  (m_xbar_rdata[1]),
  .rvalid (m_xbar_rvalid[1]),
  .rready (m_xbar_rready[1]),
  .awaddr (m_xbar_awaddr[1]),
  .awvalid(m_xbar_awvalid[1]),
  .awready(m_xbar_awready[1]),
  .wdata  (m_xbar_wdata[1]),
  .wstrb  (m_xbar_wstrb[1]),
  .wvalid (m_xbar_wvalid[1]),
  .wready (m_xbar_wready[1]),
  .bresp  (m_xbar_bresp[1]),
  .bvalid (m_xbar_bvalid[1]),
  .bready (m_xbar_bready[1])
  );

endmodule

`endif
