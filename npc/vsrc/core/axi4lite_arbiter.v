module ysyx_26030082_axi4lite_arbiter (
    input         clock,
    input         reset,
    // IFU master interface
    input  [31:0] ifu_master_araddr,
    input  [ 7:0] ifu_master_arlen,
    input  [ 1:0] ifu_master_arburst,
    input         ifu_master_arvalid,
    output        ifu_master_arready,
    output [31:0] ifu_master_rdata,
    output [ 1:0] ifu_master_rresp,
    output        ifu_master_rlast,
    output        ifu_master_rvalid,
    input         ifu_master_rready,
    // LSU master interface
    input  [31:0] lsu_master_araddr,
    input  [ 2:0] lsu_master_arsize,
    input         lsu_master_arvalid,
    output        lsu_master_arready,
    output [31:0] lsu_master_rdata,
    output [ 1:0] lsu_master_rresp,
    output        lsu_master_rvalid,
    input         lsu_master_rready,
    input  [31:0] lsu_master_awaddr,
    input  [ 2:0] lsu_master_awsize,
    input         lsu_master_awvalid,
    output        lsu_master_awready,
    input  [31:0] lsu_master_wdata,
    input  [ 3:0] lsu_master_wstrb,
    input         lsu_master_wvalid,
    output        lsu_master_wready,
    output [ 1:0] lsu_master_bresp,
    output        lsu_master_bvalid,
    input         lsu_master_bready,
    // Shared IO master interface
    output [31:0] io_master_araddr,
    output [ 3:0] io_master_arid,
    output [ 7:0] io_master_arlen,
    output [ 2:0] io_master_arsize,
    output [ 1:0] io_master_arburst,
    output        io_master_arvalid,
    input         io_master_arready,
    input  [31:0] io_master_rdata,
    input  [ 3:0] io_master_rid,
    input  [ 1:0] io_master_rresp,
    input         io_master_rlast,
    input         io_master_rvalid,
    output        io_master_rready,
    output [31:0] io_master_awaddr,
    output [ 3:0] io_master_awid,
    output [ 7:0] io_master_awlen,
    output [ 2:0] io_master_awsize,
    output [ 1:0] io_master_awburst,
    output        io_master_awvalid,
    input         io_master_awready,
    output [31:0] io_master_wdata,
    output [ 3:0] io_master_wstrb,
    output        io_master_wlast,
    output        io_master_wvalid,
    input         io_master_wready,
    input  [ 3:0] io_master_bid,
    input  [ 1:0] io_master_bresp,
    input         io_master_bvalid,
    output        io_master_bready
);

    localparam R_IDLE = 2'd0;
    localparam R_AR   = 2'd1;
    localparam R_DATA = 2'd2;

    reg [1:0] rd_state;
    reg       rd_owner_ifu;

    wire rd_sel_lsu = ((rd_state == R_IDLE) && lsu_master_arvalid) ||
                      ((rd_state == R_AR) && ~rd_owner_ifu);
    wire rd_sel_ifu = ((rd_state == R_IDLE) && ~lsu_master_arvalid && ifu_master_arvalid) ||
                      ((rd_state == R_AR) && rd_owner_ifu);
    wire rd_data_lsu = (rd_state == R_DATA) && ~rd_owner_ifu;
    wire rd_data_ifu = (rd_state == R_DATA) && rd_owner_ifu;

    wire lsu_ar_fire = rd_sel_lsu && lsu_master_arvalid && io_master_arready;
    wire ifu_ar_fire = rd_sel_ifu && ifu_master_arvalid && io_master_arready;
    wire lsu_r_fire = rd_data_lsu && io_master_rvalid && lsu_master_rready;
    wire ifu_r_fire = rd_data_ifu && io_master_rvalid && ifu_master_rready;

    assign ifu_master_arready = rd_sel_ifu && io_master_arready;
    assign ifu_master_rdata = io_master_rdata;
    assign ifu_master_rresp = io_master_rresp;
    assign ifu_master_rlast = io_master_rlast;
    assign ifu_master_rvalid = rd_data_ifu && io_master_rvalid;

    assign lsu_master_arready = rd_sel_lsu && io_master_arready;
    assign lsu_master_rdata = io_master_rdata;
    assign lsu_master_rresp = io_master_rresp;
    assign lsu_master_rvalid = rd_data_lsu && io_master_rvalid;

    assign lsu_master_awready = io_master_awready;
    assign lsu_master_wready = io_master_wready;
    assign lsu_master_bresp = io_master_bresp;
    assign lsu_master_bvalid = io_master_bvalid;

    assign io_master_araddr = rd_sel_ifu ? ifu_master_araddr : lsu_master_araddr;
    assign io_master_arid = 4'h0;
    assign io_master_arlen = rd_sel_ifu ? ifu_master_arlen : 8'h00;
    assign io_master_arsize = rd_sel_ifu ? 3'b010 : lsu_master_arsize;
    assign io_master_arburst = rd_sel_ifu ? ifu_master_arburst : 2'b00;
    assign io_master_arvalid = (rd_sel_ifu && ifu_master_arvalid) ||
                             (rd_sel_lsu && lsu_master_arvalid);
    assign io_master_rready = rd_owner_ifu ?
                            (rd_data_ifu && ifu_master_rready) :
                            (rd_data_lsu && lsu_master_rready);

    assign io_master_awaddr = lsu_master_awaddr;
    assign io_master_awid = 4'h0;
    assign io_master_awlen = 8'h00;
    assign io_master_awsize = lsu_master_awsize;
    assign io_master_awburst = 2'b00;
    assign io_master_awvalid = lsu_master_awvalid;
    assign io_master_wdata = lsu_master_wdata;
    assign io_master_wstrb = lsu_master_wstrb;
    assign io_master_wlast = 1'b1;
    assign io_master_wvalid = lsu_master_wvalid;
    assign io_master_bready = lsu_master_bready;

	    always @(posedge clock) begin
	        if (reset) begin
	            rd_state <= R_IDLE;
            rd_owner_ifu <= 1'b0;
        end else begin
            case (rd_state)
                R_IDLE: begin
                    if (lsu_master_arvalid) begin
                        rd_owner_ifu <= 1'b0;
                        rd_state <= lsu_ar_fire ? R_DATA : R_AR;
                    end else if (ifu_master_arvalid) begin
                        rd_owner_ifu <= 1'b1;
                        rd_state <= ifu_ar_fire ? R_DATA : R_AR;
                    end else begin
                        rd_owner_ifu <= 1'b0;
                    end
                end

                R_AR: begin
                    if (lsu_ar_fire || ifu_ar_fire) begin
                        rd_state <= R_DATA;
                    end
                end

                R_DATA: begin
                    if ((lsu_r_fire || ifu_r_fire) && io_master_rlast) begin
                        rd_state <= R_IDLE;
                        rd_owner_ifu <= 1'b0;
                    end
                end

                default: begin
                    rd_state <= R_IDLE;
                    rd_owner_ifu <= 1'b0;
                end
            endcase
        end
    end

`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
`ifndef __ICARUS__
    always @(posedge clock) begin
        if (!reset) begin
            if (ifu_master_arvalid &&
                (ifu_master_araddr[1:0] != 2'b00 ||
                 ifu_master_arburst != 2'b01 ||
                 ifu_master_arlen != 8'd3)) begin
                $fatal(1, "arbiter: bad IFU read request addr=%08x len=%0d burst=%0b",
                    ifu_master_araddr, ifu_master_arlen, ifu_master_arburst);
            end
            if (lsu_master_arvalid && lsu_master_arsize > 3'd2) begin
                $fatal(1, "arbiter: bad LSU read size addr=%08x size=%0d",
                    lsu_master_araddr, lsu_master_arsize);
            end
            if (lsu_r_fire && !io_master_rlast) begin
                $fatal(1, "arbiter: LSU single-beat read response without rlast");
            end
            if (lsu_master_awvalid && lsu_master_awsize > 3'd2) begin
                $fatal(1, "arbiter: bad LSU write size addr=%08x size=%0d",
                    lsu_master_awaddr, lsu_master_awsize);
            end
            if (lsu_master_wvalid && lsu_master_wstrb == 4'b0000) begin
                $fatal(1, "arbiter: zero LSU write strobe addr=%08x data=%08x",
                    lsu_master_awaddr, lsu_master_wdata);
            end
        end
    end
`endif
`endif
`endif

    wire _unused_ok = &{1'b0, io_master_rid, io_master_bid};

endmodule
