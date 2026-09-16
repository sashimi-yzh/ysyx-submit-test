module crossbar (
    // cpu
    input  [31:0]       io_araddr,
    input               io_arvalid,
    output reg          io_arready,

    output reg [31:0]   io_rdata,
    output reg          io_rvalid,
    output reg[1:0]     io_rresp,
    input               io_rready,

    input  [31:0]       io_awaddr,
    input               io_awvalid,
    output  reg         io_awready,

    input  [31:0]       io_wdata,
    input  [3:0]        io_wstrb,
    input               io_wvalid,
    output  reg         io_wready,

    output  reg         io_bvalid,
    input               io_bready,
    output reg[1:0]     io_bresp,

    // uart
    output  reg [31:0]   io_uart_araddr,
    output  reg          io_uart_arvalid,
    input                io_uart_arready,

    input [31:0]         io_uart_rdata,
    input                io_uart_rvalid,
    input[1:0]           io_uart_rresp,
    output   reg         io_uart_rready,

    output  reg [31:0]   io_uart_awaddr,
    output  reg          io_uart_awvalid,
    input                io_uart_awready,

    output  reg [31:0]   io_uart_wdata,
    output  reg [3:0]    io_uart_wstrb,
    output  reg          io_uart_wvalid,
    input                io_uart_wready,

    input                io_uart_bvalid,
    output reg           io_uart_bready,
    input [1:0]          io_uart_bresp,

    // clint
    output  reg [31:0]   io_clint_araddr,
    output  reg          io_clint_arvalid,
    input                io_clint_arready,

    input [31:0]         io_clint_rdata,
    input                io_clint_rvalid,
    input[1:0]           io_clint_rresp,
    output   reg         io_clint_rready,

    output  reg [31:0]   io_clint_awaddr,
    output  reg          io_clint_awvalid,
    input                io_clint_awready,

    output  reg [31:0]   io_clint_wdata,
    output  reg [3:0]    io_clint_wstrb,
    output  reg          io_clint_wvalid,
    input                io_clint_wready,

    input                io_clint_bvalid,
    output reg           io_clint_bready,
    input [1:0]          io_clint_bresp,

    // memory
    output  reg [31:0]   io_mem_araddr,
    output  reg          io_mem_arvalid,
    input                io_mem_arready,

    input [31:0]         io_mem_rdata,
    input                io_mem_rvalid,
    input[1:0]           io_mem_rresp,
    output   reg         io_mem_rready,

    output  reg [31:0]   io_mem_awaddr,
    output  reg          io_mem_awvalid,
    input                io_mem_awready,

    output  reg [31:0]   io_mem_wdata,
    output  reg [3:0]    io_mem_wstrb,
    output  reg          io_mem_wvalid,
    input                io_mem_wready,

    input                io_mem_bvalid,
    output reg           io_mem_bready,
    input [1:0]          io_mem_bresp
);

localparam CLINT_ADDR_START = 32'ha0000048;
localparam UART_ADDR_START  = 32'ha00003f8;

always @(*) begin
    io_arready = 1'b0;
    io_rdata = 32'b0;
    io_rvalid = 1'b0;
    io_rresp = 2'b0;
    io_awready = 1'b0;
    io_wready = 1'b0;
    io_bvalid = 1'b0;
    io_bresp = 2'b0;
    io_uart_araddr = 32'b0;
    io_uart_arvalid = 1'b0;
    io_uart_awvalid = 1'b0;
    io_uart_awaddr = 32'b0;
    io_uart_rready = 1'b0;
    io_uart_bready = 1'b0;
    io_uart_wdata = 32'b0;
    io_uart_wstrb = 4'b0;
    io_uart_wvalid = 1'b0;
    
    io_clint_araddr = 32'b0;
    io_clint_arvalid = 1'b0;
    io_clint_awvalid = 1'b0;
    io_clint_awaddr = 32'b0;
    io_clint_rready = 1'b0;
    io_clint_bready = 1'b0;
    io_clint_wdata = 32'b0;
    io_clint_wstrb = 4'b0;
    io_clint_wvalid = 1'b0;
    
    io_mem_araddr = 32'b0;
    io_mem_arvalid = 1'b0;
    io_mem_awvalid = 1'b0;
    io_mem_awaddr = 32'b0;
    io_mem_rready = 1'b0;
    io_mem_bready = 1'b0;
    io_mem_wdata = 32'b0;
    io_mem_wstrb = 4'b0;
    io_mem_wvalid = 1'b0;

    if (io_araddr >= CLINT_ADDR_START && io_araddr < CLINT_ADDR_START + 32'h8
        || io_awaddr >= CLINT_ADDR_START && io_awaddr < CLINT_ADDR_START + 32'h8) begin
        io_clint_araddr = io_araddr;
        io_clint_awaddr = io_awaddr;
        io_clint_rready = io_rready;
        io_clint_bready = io_bready;
        io_clint_wdata = io_wdata;
        io_clint_wstrb = io_wstrb;
        io_clint_wvalid = io_wvalid;
        io_clint_arvalid = io_arvalid;
        io_clint_awvalid = io_awvalid;
        io_arready = io_clint_arready;
        io_awready = io_clint_awready;
        io_rvalid = io_clint_rvalid;
        io_rresp = io_clint_rresp;
        io_bvalid = io_clint_bvalid;
        io_bresp = io_clint_bresp;
        io_rdata = io_clint_rdata;
        io_wready = io_clint_wready;

    end
    else if (io_araddr >= UART_ADDR_START && io_araddr < UART_ADDR_START + 32'h8
        || io_awaddr >= UART_ADDR_START && io_awaddr < UART_ADDR_START + 32'h8) begin
        io_uart_araddr = io_araddr;
        io_uart_awaddr = io_awaddr;
        io_uart_rready = io_rready;
        io_uart_bready = io_bready;
        io_uart_wdata = io_wdata;
        io_uart_wstrb = io_wstrb;
        io_uart_wvalid = io_wvalid;
        io_uart_arvalid = io_arvalid;
        io_uart_awvalid = io_awvalid;
        io_arready = io_uart_arready;
        io_awready = io_uart_awready;
        io_rvalid = io_uart_rvalid;
        io_rresp = io_uart_rresp;
        io_bvalid = io_uart_bvalid;
        io_bresp = io_uart_bresp;
        io_rdata = io_uart_rdata;
        io_wready = io_uart_wready;
    end
    else begin
        io_mem_araddr = io_araddr;
        io_mem_awaddr = io_awaddr;
        io_mem_rready = io_rready;
        io_mem_bready = io_bready;
        io_mem_wdata = io_wdata;
        io_mem_wstrb = io_wstrb;
        io_mem_wvalid = io_wvalid;
        io_mem_arvalid = io_arvalid;
        io_mem_awvalid = io_awvalid;
        io_arready = io_mem_arready;
        io_awready = io_mem_awready;
        io_rvalid = io_mem_rvalid;
        io_rresp = io_mem_rresp;
        io_bvalid = io_mem_bvalid;
        io_bresp = io_mem_bresp;
        io_rdata = io_mem_rdata;
        io_wready = io_mem_wready;
    end
end


endmodule
