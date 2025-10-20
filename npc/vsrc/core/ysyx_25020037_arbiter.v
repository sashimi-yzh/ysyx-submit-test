module ysyx_25020037_arbiter (
    input  wire         clk,
    input  wire         rst,

    output wire         ifu_arready,
    input  wire         ifu_arvalid,
    input  wire [31: 0] ifu_araddr,
    input  wire [ 3: 0] ifu_arid,
    input  wire [ 7: 0] ifu_arlen,
    input  wire [ 2: 0] ifu_arsize,
    input  wire [ 1: 0] ifu_arburst,
    input  wire         ifu_rready,
    output wire         ifu_rvalid,
    output wire [ 1: 0] ifu_rresp,
    output wire [31: 0] ifu_rdata,
    output wire         ifu_rlast,
    output wire [ 3: 0] ifu_rid,

    output wire         lsu_awready,
    input  wire         lsu_awvalid,
    input  wire [31: 0] lsu_awaddr,
    input  wire [ 3: 0] lsu_awid,
    input  wire [ 7: 0] lsu_awlen,
    input  wire [ 2: 0] lsu_awsize,
    input  wire [ 1: 0] lsu_awburst,
    output wire         lsu_wready,
    input  wire         lsu_wvalid,
    input  wire [31: 0] lsu_wdata,
    input  wire [ 3: 0] lsu_wstrb,
    input  wire         lsu_wlast,
    input  wire         lsu_bready,
    output wire         lsu_bvalid,
    output wire [ 1: 0] lsu_bresp,
    output wire [ 3: 0] lsu_bid,
    output wire         lsu_arready,
    input  wire         lsu_arvalid,
    input  wire [31: 0] lsu_araddr,
    input  wire [ 3: 0] lsu_arid,
    input  wire [ 7: 0] lsu_arlen,
    input  wire [ 2: 0] lsu_arsize,
    input  wire [ 1: 0] lsu_arburst,
    input  wire         lsu_rready,
    output wire         lsu_rvalid,
    output wire [ 1: 0] lsu_rresp,
    output wire [31: 0] lsu_rdata,
    output wire         lsu_rlast,
    output wire [ 3: 0] lsu_rid,

    input  wire         io_master_awready,
    output wire         io_master_awvalid,
    output wire [31: 0] io_master_awaddr,
    output wire [ 3: 0] io_master_awid,
    output wire [ 7: 0] io_master_awlen,
    output wire [ 2: 0] io_master_awsize,
    output wire [ 1: 0] io_master_awburst,
    input  wire         io_master_wready,
    output wire         io_master_wvalid,
    output wire [31: 0] io_master_wdata,
    output wire [ 3: 0] io_master_wstrb,
    output wire         io_master_wlast,
    output wire         io_master_bready,
    input  wire         io_master_bvalid,
    input  wire [ 1: 0] io_master_bresp,
    input  wire [ 3: 0] io_master_bid,
    input  wire         io_master_arready,
    output wire         io_master_arvalid,
    output wire[31: 0]  io_master_araddr,
    output wire[ 3: 0]  io_master_arid,
    output wire[ 7: 0]  io_master_arlen,
    output wire[ 2: 0]  io_master_arsize,
    output wire[ 1: 0]  io_master_arburst,
    output wire         io_master_rready,
    input  wire         io_master_rvalid,
    input  wire [ 1: 0] io_master_rresp,
    input  wire [31: 0] io_master_rdata,
    input  wire         io_master_rlast,
    input  wire [ 3: 0] io_master_rid,

    input  wire         clint_arready,
    output wire         clint_arvalid,
    output wire [31: 0] clint_araddr,
    output wire [ 3: 0] clint_arid,
    output wire [ 7: 0] clint_arlen,
    output wire [ 2: 0] clint_arsize,
    output wire [ 1: 0] clint_arburst,
    output wire         clint_rready,
    input  wire         clint_rvalid,
    input  wire [ 1: 0] clint_rresp,
    input  wire [31: 0] clint_rdata,
    input  wire         clint_rlast,
    input  wire [ 3: 0] clint_rid
);

localparam CLINT_BASE      = 16'h0200; // 0200_0000-0200_ffff

localparam IDLE        = 2'b00;
localparam IFU_ACCESS  = 2'b01;
localparam LSU_ACCESS  = 2'b10;

reg       is_clint_addr;
reg [1:0] current_master, next_master;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        current_master <= IDLE;
    end else begin
        case (next_master)
            IDLE      : current_master <= next_master;
            IFU_ACCESS: current_master <= next_master;
            LSU_ACCESS: current_master <= next_master;
            default   : current_master <= current_master;
        endcase
        case (current_master)
            IDLE: begin
                is_clint_addr <= (lsu_arvalid & ((lsu_araddr[31:16] == CLINT_BASE)));
            end
            default: begin is_clint_addr <= is_clint_addr; end
        endcase
    end
end

always @(*) begin
    case (current_master)
        IDLE       : next_master = (lsu_arvalid || lsu_awvalid) ? LSU_ACCESS  :
                            (ifu_arvalid) ? IFU_ACCESS : IDLE;
        IFU_ACCESS : next_master = (ifu_rvalid && ifu_rready && ifu_rlast) ? IDLE : IFU_ACCESS;
        LSU_ACCESS : next_master = (((lsu_rvalid && lsu_rready && lsu_rlast) || (io_master_bvalid & io_master_bready)) |
                                    (clint_rvalid & clint_rready)) ? IDLE : LSU_ACCESS;
        default: next_master = IDLE;
    endcase
end

    assign ifu_arready       = current_master == IFU_ACCESS ? io_master_arready : 'b0;
    assign ifu_rdata         = current_master == IFU_ACCESS ? io_master_rdata   : 'b0;
    assign ifu_rresp         = current_master == IFU_ACCESS ? io_master_rresp   : 'b0;
    assign ifu_rlast         = current_master == IFU_ACCESS ? io_master_rlast   : 'b0;
    assign ifu_rvalid        = current_master == IFU_ACCESS ? io_master_rvalid  : 'b0;
    assign ifu_rid           = current_master == IFU_ACCESS ? io_master_rid     : 'b0;

    assign lsu_arready       = current_master == LSU_ACCESS ? is_clint_addr ? clint_arready : io_master_arready : 'b0;
    assign lsu_rdata         = current_master == LSU_ACCESS ? is_clint_addr ? clint_rdata   : io_master_rdata   : 'b0;
    assign lsu_rresp         = current_master == LSU_ACCESS ? is_clint_addr ? clint_rresp   : io_master_rresp   : 'b0;
    assign lsu_rlast         = current_master == LSU_ACCESS ? is_clint_addr ? clint_rlast   : io_master_rlast   : 'b0;
    assign lsu_rvalid        = current_master == LSU_ACCESS ? is_clint_addr ? clint_rvalid  : io_master_rvalid  : 'b0;
    assign lsu_rid           = current_master == LSU_ACCESS ? is_clint_addr ? clint_rid     : io_master_rid     : 'b0;
    assign lsu_awready       = current_master == LSU_ACCESS ? is_clint_addr ? 'b0           : io_master_awready : 'b0;
    assign lsu_wready        = current_master == LSU_ACCESS ? is_clint_addr ? 'b0           : io_master_wready  : 'b0;
    assign lsu_bvalid        = current_master == LSU_ACCESS ? is_clint_addr ? 'b0           : io_master_bvalid  : 'b0;
    assign lsu_bresp         = current_master == LSU_ACCESS ? is_clint_addr ? 'b0           : io_master_bresp   : 'b0;
    assign lsu_bid           = current_master == LSU_ACCESS ? is_clint_addr ? 'b0           : io_master_bid     : 'b0;

    assign clint_arvalid     = (current_master == LSU_ACCESS) && is_clint_addr ? lsu_arvalid : 'b0;
    assign clint_araddr      = (current_master == LSU_ACCESS) && is_clint_addr ? lsu_araddr  : 'b0;
    assign clint_arid        = (current_master == LSU_ACCESS) && is_clint_addr ? lsu_arid    : 'b0;
    assign clint_arlen       = (current_master == LSU_ACCESS) && is_clint_addr ? lsu_arlen   : 'b0;
    assign clint_arsize      = (current_master == LSU_ACCESS) && is_clint_addr ? lsu_arsize  : 'b0;
    assign clint_arburst     = (current_master == LSU_ACCESS) && is_clint_addr ? lsu_arburst : 'b0;
    assign clint_rready      = (current_master == LSU_ACCESS) && is_clint_addr ? lsu_rready  : 'b0;

    assign io_master_arvalid = current_master == IFU_ACCESS ? ifu_arvalid : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_arvalid : 'b0;
    assign io_master_araddr  = current_master == IFU_ACCESS ? ifu_araddr  : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_araddr  : 'b0;
    assign io_master_arid    = current_master == IFU_ACCESS ? ifu_arid    : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_arid    : 'b0;
    assign io_master_arlen   = current_master == IFU_ACCESS ? ifu_arlen   : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_arlen   : 'b0;
    assign io_master_arsize  = current_master == IFU_ACCESS ? ifu_arsize  : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_arsize  : 'b0;
    assign io_master_arburst = current_master == IFU_ACCESS ? ifu_arburst : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_arburst : 'b0;
    assign io_master_rready  = current_master == IFU_ACCESS ? ifu_rready  : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_rready  : 'b0;
    assign io_master_awvalid = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_awvalid : 'b0;
    assign io_master_awaddr  = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_awaddr  : 'b0;
    assign io_master_awid    = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_awid    : 'b0;
    assign io_master_awlen   = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_awlen   : 'b0;
    assign io_master_awsize  = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_awsize  : 'b0;
    assign io_master_awburst = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_awburst : 'b0;
    assign io_master_wvalid  = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_wvalid  : 'b0;
    assign io_master_wdata   = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_wdata   : 'b0;
    assign io_master_wstrb   = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_wstrb   : 'b0;
    assign io_master_wlast   = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_wlast   : 'b0;
    assign io_master_bready  = current_master == IFU_ACCESS ? 'b0         : (current_master == LSU_ACCESS) && ~is_clint_addr ? lsu_bready  : 'b0;

endmodule
