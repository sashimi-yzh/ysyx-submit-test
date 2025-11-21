module ysyx_25020037_axi4_crossbar (
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

localparam SRAM_BASE_START = 32'h80000000;
localparam SRAM_BASE_END   = 32'h8fffffff;
localparam FLASH_INIT1     = 32'h30000000;
localparam FLASH_INIT2     = 32'h3000000c;
localparam UART_BASE       = 32'h10000000;

wire sram_awready, sram_awvalid;
wire [31:0] sram_awaddr;
wire [3:0] sram_awid;
wire [7:0] sram_awlen;
wire [2:0] sram_awsize;
wire [1:0] sram_awburst;
wire sram_wready, sram_wvalid;
wire [31:0] sram_wdata;
wire [3:0] sram_wstrb;
wire sram_wlast;
wire sram_bready, sram_bvalid;
wire [1:0] sram_bresp;
wire [3:0] sram_bid;
wire sram_arready, sram_arvalid;
wire [31:0] sram_araddr;
wire [3:0] sram_arid;
wire [7:0] sram_arlen;
wire [2:0] sram_arsize;
wire [1:0] sram_arburst;
wire sram_rready, sram_rvalid;
wire [1:0] sram_rresp;
wire [31:0] sram_rdata;
wire sram_rlast;
wire [3:0] sram_rid;

wire uart_awready, uart_awvalid;
wire [31:0] uart_awaddr;
wire [3:0] uart_awid;
wire [7:0] uart_awlen;
wire [2:0] uart_awsize;
wire [1:0] uart_awburst;
wire uart_wready, uart_wvalid;
wire [31:0] uart_wdata;
wire [3:0] uart_wstrb;
wire uart_wlast;
wire uart_bready, uart_bvalid;
wire [1:0] uart_bresp;
wire [3:0] uart_bid;
wire uart_arready, uart_arvalid;
wire [31:0] uart_araddr;
wire [3:0] uart_arid;
wire [7:0] uart_arlen;
wire [2:0] uart_arsize;
wire [1:0] uart_arburst;
wire uart_rready, uart_rvalid;
wire [1:0] uart_rresp;
wire [31:0] uart_rdata;
wire uart_rlast;
wire [3:0] uart_rid;

localparam IDLE    = 1'b0;
localparam BUSY    = 1'b1;
reg       is_uart_addr;
reg       is_sram_addr;
reg       state, next_state;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        state <= IDLE;
        is_sram_addr   <= 1'b0;
        is_uart_addr   <= 1'b0;
    end else begin
        state <= next_state;
        case (state)
            IDLE: begin
                is_uart_addr  <= (io_master_arvalid & (io_master_araddr == UART_BASE)) |
                                 (io_master_awvalid & (io_master_awaddr == UART_BASE));
                is_sram_addr  <= (io_master_arvalid & ((io_master_araddr >= SRAM_BASE_START) & (io_master_araddr <= SRAM_BASE_END))) |
                                 (io_master_awvalid & ((io_master_awaddr >= SRAM_BASE_START) & (io_master_awaddr <= SRAM_BASE_END))) |
                                 (io_master_arvalid & ((io_master_araddr >= FLASH_INIT1    ) | (io_master_araddr <= FLASH_INIT2)));
            end
            default: begin end
        endcase
    end
end

always @(*) begin
    case (state)
        IDLE: next_state = (io_master_arvalid || io_master_awvalid) ? BUSY : IDLE;
        BUSY: next_state = ((sram_rvalid & sram_rready) || (sram_bvalid & sram_bready)) |
                           ((uart_rvalid & uart_rready) || (uart_bvalid & uart_bready)) ? IDLE : BUSY;
        default: next_state = IDLE;
    endcase
end

ysyx_25020037_sram sram_cpu(
    .clk            (clk             ),
    .rst            (rst             ),
    .awready        (sram_awready    ),
    .awvalid        (sram_awvalid    ),
    .awaddr         (sram_awaddr     ),
    .awid           (sram_awid       ),
    .awlen          (sram_awlen      ),
    .awsize         (sram_awsize     ),
    .awburst        (sram_awburst    ),
    .wready         (sram_wready     ),
    .wvalid         (sram_wvalid     ),
    .wdata          (sram_wdata      ),
    .wstrb          (sram_wstrb      ),
    .wlast          (sram_wlast      ),
    .bready         (sram_bready     ),
    .bvalid         (sram_bvalid     ),
    .bresp          (sram_bresp      ),
    .bid            (sram_bid        ),
    .arready        (sram_arready    ),
    .arvalid        (sram_arvalid    ),
    .araddr         (sram_araddr     ),
    .arid           (sram_arid       ),
    .arlen          (sram_arlen      ),
    .arsize         (sram_arsize     ),
    .arburst        (sram_arburst    ),
    .rready         (sram_rready     ),
    .rvalid         (sram_rvalid     ),
    .rresp          (sram_rresp      ),
    .rdata          (sram_rdata      ),
    .rlast          (sram_rlast      ),
    .rid            (sram_rid        )
);

ysyx_25020037_uart uart_cpu(
    .clk            (clk             ),
    .rst            (rst             ),
    .awready        (uart_awready    ),
    .awvalid        (uart_awvalid    ),
    .awaddr         (uart_awaddr     ),
    .awid           (uart_awid       ),
    .awlen          (uart_awlen      ),
    .awsize         (uart_awsize     ),
    .awburst        (uart_awburst    ),
    .wready         (uart_wready     ),
    .wvalid         (uart_wvalid     ),
    .wdata          (uart_wdata      ),
    .wstrb          (uart_wstrb      ),
    .wlast          (uart_wlast      ),
    .bready         (uart_bready     ),
    .bvalid         (uart_bvalid     ),
    .bresp          (uart_bresp      ),
    .bid            (uart_bid        ),
    .arready        (uart_arready    ),
    .arvalid        (uart_arvalid    ),
    .araddr         (uart_araddr     ),
    .arid           (uart_arid       ),
    .arlen          (uart_arlen      ),
    .arsize         (uart_arsize     ),
    .arburst        (uart_arburst    ),
    .rready         (uart_rready     ),
    .rvalid         (uart_rvalid     ),
    .rresp          (uart_rresp      ),
    .rdata          (uart_rdata      ),
    .rlast          (uart_rlast      ),
    .rid            (uart_rid        )
);

assign sram_awvalid = io_master_awvalid && is_sram_addr;
assign uart_awvalid = io_master_awvalid && is_uart_addr;
assign sram_awaddr  = io_master_awaddr;
assign uart_awaddr  = io_master_awaddr;
assign sram_awid    = io_master_awid;
assign uart_awid    = io_master_awid;
assign sram_awlen   = io_master_awlen;
assign uart_awlen   = io_master_awlen;
assign sram_awsize  = io_master_awsize;
assign uart_awsize  = io_master_awsize;
assign sram_awburst = io_master_awburst;
assign uart_awburst = io_master_awburst;
assign io_master_awready = (is_sram_addr && sram_awready) || (is_uart_addr && uart_awready);

assign sram_wvalid = io_master_wvalid && is_sram_addr;
assign uart_wvalid = io_master_wvalid && is_uart_addr;
assign sram_wdata  = io_master_wdata;
assign uart_wdata  = io_master_wdata;
assign sram_wstrb  = io_master_wstrb;
assign uart_wstrb  = io_master_wstrb;
assign sram_wlast  = io_master_wlast;
assign uart_wlast  = io_master_wlast;
assign io_master_wready = (is_sram_addr && sram_wready) || (is_uart_addr && uart_wready);

assign sram_bready = io_master_bready && is_sram_addr;
assign uart_bready = io_master_bready && is_uart_addr;
assign io_master_bvalid = (is_sram_addr && sram_bvalid) || (is_uart_addr && uart_bvalid);
assign io_master_bresp  = is_sram_addr ? sram_bresp : uart_bresp;
assign io_master_bid    = is_sram_addr ? sram_bid   : uart_bid;

assign sram_arvalid = io_master_arvalid && is_sram_addr;
assign uart_arvalid = io_master_arvalid && is_uart_addr;
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
assign io_master_arready = (is_sram_addr && sram_arready) || (is_uart_addr && uart_arready);

assign sram_rready = io_master_rready && is_sram_addr;
assign uart_rready = io_master_rready && is_uart_addr;
assign io_master_rvalid = (is_sram_addr && sram_rvalid) || (is_uart_addr && uart_rvalid);
assign io_master_rresp  = is_sram_addr ? sram_rresp : uart_rresp;
assign io_master_rdata  = is_sram_addr ? sram_rdata : uart_rdata;
assign io_master_rlast  = is_sram_addr ? sram_rlast : uart_rlast;
assign io_master_rid    = is_sram_addr ? sram_rid   : uart_rid;

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

endmodule