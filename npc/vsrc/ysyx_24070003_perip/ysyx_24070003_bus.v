module ysyx_24070003_bus (
    input  wire          clk,
    input  wire          rst,

    output  wire         io_master_awready,
    input   wire         io_master_awvalid,
    input   wire [31: 0] io_master_awaddr,
    input   wire [ 3: 0] io_master_awid, 
    input   wire [ 7: 0] io_master_awlen,  
    input   wire [ 2: 0] io_master_awsize,
    input   wire [ 1: 0] io_master_awburst,
    output  wire         io_master_wready,
    input   wire         io_master_wvalid, 
    input   wire [31: 0] io_master_wdata, 
    input   wire [ 3: 0] io_master_wstrb,  
    input   wire         io_master_wlast,  
    input   wire         io_master_bready, 
    output  wire         io_master_bvalid, 
    output  wire [ 1: 0] io_master_bresp, 
    output  wire [ 3: 0] io_master_bid,  
    output  wire         io_master_arready,
    input   wire         io_master_arvalid,
    input   wire [31: 0] io_master_araddr,
    input   wire [ 3: 0] io_master_arid, 
    input   wire [ 7: 0] io_master_arlen,  
    input   wire [ 2: 0] io_master_arsize, 
    input   wire [ 1: 0] io_master_arburst,
    input   wire         io_master_rready,
    output  wire         io_master_rvalid, 
    output  wire [ 1: 0] io_master_rresp, 
    output  wire [31: 0] io_master_rdata,  
    output  wire         io_master_rlast,  
    output  wire [ 3: 0] io_master_rid,

    input   wire         io_slave_awready,
    output  wire         io_slave_awvalid,
    output  wire [31: 0] io_slave_awaddr,
    output  wire [ 3: 0] io_slave_awid, 
    output  wire [ 7: 0] io_slave_awlen,  
    output  wire [ 2: 0] io_slave_awsize, 
    output  wire [ 1: 0] io_slave_awburst,
    input   wire         io_slave_wready,
    output  wire         io_slave_wvalid, 
    output  wire [31: 0] io_slave_wdata, 
    output  wire [ 3: 0] io_slave_wstrb,  
    output  wire         io_slave_wlast,  
    output  wire         io_slave_bready, 
    input   wire         io_slave_bvalid, 
    input   wire [ 1: 0] io_slave_bresp, 
    input   wire [ 3: 0] io_slave_bid,  
    input   wire         io_slave_arready,
    output  wire         io_slave_arvalid,
    output  wire [31: 0] io_slave_araddr,
    output  wire [ 3: 0] io_slave_arid, 
    output  wire [ 7: 0] io_slave_arlen,  
    output  wire [ 2: 0] io_slave_arsize, 
    output  wire [ 1: 0] io_slave_arburst,
    output  wire         io_slave_rready,
    input   wire         io_slave_rvalid, 
    input   wire [ 1: 0] io_slave_rresp, 
    input   wire [31: 0] io_slave_rdata,  
    input   wire         io_slave_rlast,  
    input   wire [ 3: 0] io_slave_rid  
);
wire [31:0] uart_araddr,sram_araddr;
wire [31:0] uart_awaddr,sram_awaddr;
wire [31:0] uart_wdata,sram_wdata;
wire [3:0] uart_wstrb,sram_wstrb;
wire [31:0] uart_rdata,sram_rdata;
wire [1:0] uart_rresp,sram_rresp;
wire uart_rvalid,sram_rvalid;
wire uart_rlast,sram_rlast;
wire uart_awready,sram_awready;
wire uart_wready,sram_wready;
wire uart_bvalid,sram_bvalid;
wire [1:0] uart_bresp,sram_bresp;
wire [3:0] uart_bid,sram_bid;
wire uart_arready,sram_arready;
wire uart_rready,sram_rready;
wire uart_bready,sram_bready;
wire uart_arvalid,sram_arvalid;
wire [7:0] uart_arlen,sram_arlen;
wire [2:0] uart_arsize,sram_arsize;
wire [1:0] uart_arburst,sram_arburst;
wire [3:0] uart_arid,sram_arid;
wire [7:0] uart_awlen,sram_awlen;
wire        uart_awvalid,sram_awvalid;
wire        uart_wvalid,sram_wvalid;
wire [2:0]  uart_awsize,sram_awsize;
wire [1:0]  uart_awburst,sram_awburst;
wire       uart_wlast,sram_wlast;

assign io_slave_awvalid = 1'b0;
assign io_slave_awaddr  = 32'b0;
assign io_slave_awid    = 4'b0;
assign io_slave_awlen   = 8'b0;
assign io_slave_awsize  = 3'b0;
assign io_slave_awburst = 2'b0;
assign io_slave_wvalid  = 1'b0;
assign io_slave_wdata   = 32'b0;
assign io_slave_wstrb   = 4'b0;
assign io_slave_wlast   = 1'b0;
assign io_slave_bready  = 1'b0;
assign io_slave_arvalid = 1'b0;
assign io_slave_araddr  = 32'b0;
assign io_slave_arid    = 4'b0;
assign io_slave_arlen   = 8'b0;
assign io_slave_arsize  = 3'b0;
assign io_slave_arburst = 2'b0;
assign io_slave_rready  = 1'b0;

ysyx_24070003_uart uart(
   .clk                  (clk),
   .rst                  (rst),
   .araddr               (uart_araddr ),
   .arlen                (uart_arlen ),
   .arsize               (uart_arsize ),
   .arburst              (uart_arburst ),
   .arvalid              (uart_arvalid ),
   .arready              (uart_arready ),
   .rdata                (uart_rdata ),
   .rresp                (uart_rresp ),
   .rlast                (uart_rlast ),
   .rvalid               (uart_rvalid ),
   .rready               (uart_rready ),
   .awaddr               (uart_awaddr ),
   .awlen                (uart_awlen ),
   .awsize               (uart_awsize ),
   .awburst              (uart_awburst ),
   .awvalid              (uart_awvalid ),
   .awready              (uart_awready ),
   .wdata                (uart_wdata ),
   .wstrb                (uart_wstrb ),
   .wlast                (uart_wlast ),
   .wvalid               (uart_wvalid ),
   .wready               (uart_wready ),
   .bresp                (uart_bresp ),
   .bvalid               (uart_bvalid ),
   .bready               (uart_bready )
);


ysyx_24070003_ram ram(
   .clk                  (clk),
   .rst                  (rst),
   .araddr               (sram_araddr ),
   .arlen                (sram_arlen ),
   .arsize               (sram_arsize ),
   .arburst              (sram_arburst ),
   .arvalid              (sram_arvalid ),
   .arready              (sram_arready ),
   .rdata                (sram_rdata ),
   .rresp                (sram_rresp ),
   .rlast                (sram_rlast ),
   .rvalid               (sram_rvalid ),
   .rready               (sram_rready ),
   .awaddr               (sram_awaddr ),
   .awlen                (sram_awlen ),
   .awsize               (sram_awsize ),
   .awburst              (sram_awburst ),
   .awvalid              (sram_awvalid ),
   .awready              (sram_awready ),
   .wdata                (sram_wdata ),
   .wstrb                (sram_wstrb ),
   .wlast                (sram_wlast ),
   .wvalid               (sram_wvalid ),
   .wready               (sram_wready ),
   .bresp                (sram_bresp ),
   .bvalid               (sram_bvalid ),
   .bready               (sram_bready )
);
wire is_sram,is_uart;

assign is_sram = (io_master_awaddr >= 32'h80000000 && io_master_awaddr < 32'h8fffffff) || (io_master_araddr >= 32'h80000000 && io_master_araddr < 32'h8fffffff);
assign is_uart = (io_master_awaddr >= 32'ha00003f4 && io_master_awaddr < 32'ha00003f8);

assign sram_awvalid = io_master_awvalid && is_sram;
assign uart_awvalid = io_master_awvalid && is_uart;
assign sram_awaddr  = io_master_awaddr;
assign uart_awaddr  = io_master_awaddr;
assign sram_awlen   = io_master_awlen;
assign uart_awlen   = io_master_awlen;
assign sram_awsize  = io_master_awsize;
assign uart_awsize  = io_master_awsize;
assign sram_awburst = io_master_awburst;
assign uart_awburst = io_master_awburst;
assign io_master_awready = (is_sram && sram_awready) || (is_uart && uart_awready);

assign sram_wvalid = io_master_wvalid && is_sram;
assign uart_wvalid = io_master_wvalid && is_uart;
assign sram_wdata  = io_master_wdata;
assign uart_wdata  = io_master_wdata;
assign sram_wstrb  = io_master_wstrb;
assign uart_wstrb  = io_master_wstrb;
assign sram_wlast  = io_master_wlast;
assign uart_wlast  = io_master_wlast;
assign io_master_wready = (is_sram && sram_wready) || (is_uart && uart_wready);

assign sram_bready = io_master_bready && is_sram;
assign uart_bready = io_master_bready && is_uart;
assign io_master_bvalid = (is_sram && sram_bvalid) || (is_uart && uart_bvalid);
assign io_master_bresp  = 0;
assign io_master_bid    = 0;

assign sram_arvalid = io_master_arvalid && is_sram;
assign uart_arvalid = io_master_arvalid && is_uart;
assign sram_araddr  = io_master_araddr;
assign uart_araddr  = io_master_araddr;
assign sram_arid    = io_master_arid;
assign uart_arid    = io_master_arid;
assign sram_arlen   = io_master_arlen;
assign uart_arlen   = io_master_arlen;
assign sram_arsize  = io_master_arsize;
assign uart_arsize  = io_master_arsize;
assign sram_arburst = io_master_arburst;
assign uart_arburst = io_master_arburst;
assign io_master_arready = (is_sram && sram_arready) || (is_uart && uart_arready);

assign sram_rready = io_master_rready && is_sram;
assign uart_rready = io_master_rready && is_uart;
assign io_master_rvalid = (is_sram && sram_rvalid) || (is_uart && uart_rvalid);
assign io_master_rresp  = 0;
assign io_master_rdata  = is_sram ? sram_rdata : uart_rdata;
assign io_master_rlast  = is_sram ? sram_rlast : uart_rlast;
assign io_master_rid    = 0;


endmodule
