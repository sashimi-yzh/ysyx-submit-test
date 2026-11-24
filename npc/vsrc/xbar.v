module ysyx_24110012_xbar #(
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
    input reg [NUM_MASTERS-1:0] m_wready,
    output wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_wdata,
    output wire [NUM_MASTERS-1:0][DATA_WIDTH/8-1:0] m_wstrb,
    input wire [NUM_MASTERS-1:0][1:0] m_bresp,
    input reg [NUM_MASTERS-1:0] m_bvalid,
    output wire [NUM_MASTERS-1:0] m_bready,
    output wire [NUM_MASTERS-1:0] m_arvalid,
    input reg [NUM_MASTERS-1:0] m_arready,
    output wire [NUM_MASTERS-1:0][ADDR_WIDTH-1:0] m_araddr,
    output wire [NUM_MASTERS-1:0] [2:0] m_arsize,
    output wire [NUM_MASTERS-1:0] [1:0] m_arburst,
    output wire [NUM_MASTERS-1:0] [7:0] m_arlen,
    input wire [NUM_MASTERS-1:0] m_rvalid,
    output wire [NUM_MASTERS-1:0] m_rready,
    input wire [NUM_MASTERS-1:0][DATA_WIDTH-1:0] m_rdata,
    input wire [NUM_MASTERS-1:0] m_rlast

);

  // parameter P_MEM_START = 32'h8000_0000;
  // parameter P_MEM_END = 32'h8100_0000;

  // parameter P_DEV_BASE = 32'ha000_0000;
  // parameter P_UART_START = P_DEV_BASE + 32'h0000_03f8;
  // parameter P_UART_END = P_UART_START + 32'h8;

  parameter P_SOC_START = 32'h0f00_0000;
  parameter P_SOC_END = 32'hffff_ffff;

  parameter P_CLINT_START = 32'h0200_0000;
  parameter P_CLINT_END = P_CLINT_START + 32'hffff;

  // indicate the write/read operation is done for all dev io
  // 0 -> mem, 1 -> uart, 2 -> clint
  // function automatic logic addr_is_uart(input [DATA_WIDTH-1:0] addr);
  //   return (addr >= P_UART_START) && (addr <= P_UART_END);
  // endfunction

  // function automatic logic addr_is_mem(input [DATA_WIDTH-1:0] addr);
  //   return (addr >= P_MEM_START) && (addr < P_MEM_END);
  // endfunction

  // 0 -> soc, 1 -> clint
  function automatic logic addr_is_clint(input [DATA_WIDTH-1:0] addr);
    addr_is_clint = (addr >= P_CLINT_START) && (addr < P_CLINT_END);
  endfunction

  function automatic logic addr_is_soc(input [DATA_WIDTH-1:0] addr);
    addr_is_soc = (addr >= P_SOC_START) && (addr < P_SOC_END);
  endfunction

  localparam MASTER_INDEX_WIDTH = $clog2(NUM_MASTERS);

  wire [MASTER_INDEX_WIDTH-1:0] master_index_aw;
  wire [MASTER_INDEX_WIDTH-1:0] master_index_ar;

  // write op
  // this to consider the s_awaddr no change
  // wire aw_sel_uart = addr_is_uart(s_awaddr);
  // wire aw_sel_mem = addr_is_mem(s_awaddr);
  wire aw_sel_soc = addr_is_soc(s_awaddr);
  wire aw_sel_clint = addr_is_clint(s_awaddr);

  // 0 stands for mem, 1 stands for uart
  assign master_index_aw = aw_sel_clint ? 1'b1 : 1'b0;

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
  // wire ar_sel_uart = addr_is_uart(s_araddr);
  // wire ar_sel_mem = addr_is_mem(s_araddr);
  wire ar_sel_soc = addr_is_soc(s_araddr);
  wire ar_sel_clint = addr_is_clint(s_araddr);
  // 0 stands for mem, 1 stands for uart
  assign master_index_ar = ar_sel_clint ? 1'b1 : (ar_sel_soc ? 1'b0 : 1'bx);


  genvar i_ar;
  generate
    for (i_ar = 0; i_ar < NUM_MASTERS; i_ar = i_ar + 1) begin : gen_xbar_r
      assign m_araddr[i_ar]  = (i_ar == master_index_ar) ? s_araddr : '0;
      assign m_arsize[i_ar]  = (i_ar == master_index_ar) ? s_arsize : '0;
      assign m_arvalid[i_ar] = (i_ar == master_index_ar) ? s_arvalid : 1'b0;
      assign m_rready[i_ar]  = (i_ar == master_index_ar) ? s_rready : 1'b0;
      assign m_arburst[i_ar]  = (i_ar == master_index_ar) ? s_arburst : 2'b0;
      assign m_arlen[i_ar]  = (i_ar == master_index_ar) ? s_arlen : 8'b0;
    end
  endgenerate

  assign s_arready = m_arready[master_index_ar];
  assign s_rdata   = m_rdata[master_index_ar];
  assign s_rlast   = m_rlast[master_index_ar];
  assign s_rvalid  = m_rvalid[master_index_ar];

endmodule
