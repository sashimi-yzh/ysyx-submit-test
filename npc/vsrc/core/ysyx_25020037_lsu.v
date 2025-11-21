`include "ysyx_25020037_config.vh"
module ysyx_25020037_lsu (
    input  wire         clk,
    input  wire         rst,
    input  wire         exu_valid,
    output wire         lsu_ready,
    output reg          lsu_valid,
    input  wire         exu_dnpc_valid,
    output reg  [31: 0] rdata_processed,
`ifdef VERILATOR
    input  wire [31: 0] diff_pc_i,
    output reg  [31: 0] diff_pc_o,
`endif
    input  wire [`EU_TO_LU_BUS_WD -1:0] eu_to_lu_bus,
    output reg  [`LU_TO_WU_BUS_WD -1:0] lu_to_wu_bus,

    input  wire         awready,
    output reg          awvalid,
    output reg  [31: 0] awaddr,
    output reg  [ 3: 0] awid,
    output reg  [ 7: 0] awlen,
    output reg  [ 2: 0] awsize,
    output reg  [ 1: 0] awburst,
    input  wire         wready,
    output reg          wvalid,
    output reg  [31: 0] wdata,
    output reg  [ 3: 0] wstrb,
    output reg          wlast,
    output reg          bready,
    input  wire         bvalid,
    input  wire [ 1: 0] bresp,
    input  wire [ 3: 0] bid,
    input  wire         arready,
    output reg          arvalid,
    output reg  [31: 0] araddr,
    output reg  [ 3: 0] arid,
    output reg  [ 7: 0] arlen,
    output reg  [ 2: 0] arsize,
    output reg  [ 1: 0] arburst,
    output reg          rready,
    input  wire         rvalid,
    input  wire [ 1: 0] rresp,
    input  wire [31: 0] rdata,
    input  wire         rlast,
    input  wire [ 3: 0] rid
);
    localparam IDLE    = 1'b0;
    localparam BUSY    = 1'b1;
    reg        state, next_state;

    localparam SDRAM_BASE = 4'hA; // A000_0000-BFFF_FFFF
    localparam SDRAM_END  = 4'hB; 

    localparam AXI_LEN_SINGLE = 8'h0;
    reg         exu_dnpc_valid_r;
    wire [ 3:0] rd;
    wire [`EU_TO_WU_BUS_WD -1:0] eu_to_wu_bus;
    wire [ 1:0] data_rop;
    wire [ 1:0] data_wop;
    wire        is_write;
    wire        is_read;
    wire [`DU_TO_LU_BUS_WD -1:0] du_to_lu_bus;
    wire        gpr_we;
    wire [31:0] addr;
    wire [31:0] data_channel;
    wire [31:0] addr_off = addr & 32'b11;
    wire [31:0] aligned_wdata = data_channel << (addr_off << 3);
    assign {rd,
            eu_to_wu_bus,
            data_rop,
            data_wop,
            is_write,
            is_read,
            du_to_lu_bus,
            gpr_we,
            data_channel,     
            addr
           } = eu_to_lu_bus;

    wire        bit_sext;
    wire        half_sext;
    assign {bit_sext,
            half_sext
           } = du_to_lu_bus;

    wire is_sdram = (addr[31:28] == SDRAM_BASE) | (addr[31:28] == SDRAM_END);

    always @(*) begin
        case (state)
            IDLE: begin next_state = (exu_valid & (is_write | is_read)) ? BUSY : IDLE; end
            BUSY: begin next_state = ((bvalid & wlast) | (rvalid & rlast)) ? IDLE : BUSY; end
            default: next_state = IDLE;
        endcase
    end

    wire [31: 0] lsu_rdata;
    assign lsu_rdata = rdata >> (addr_off << 3);
    always @(*) begin
        case (data_rop)
            2'b00: begin rdata_processed = bit_sext  ? {{24{lsu_rdata[ 7]}}, lsu_rdata[ 7:0]} : {24'b0, lsu_rdata[ 7:0]}; end
            2'b01: begin rdata_processed = half_sext ? {{16{lsu_rdata[15]}}, lsu_rdata[15:0]} : {16'b0, lsu_rdata[15:0]}; end
            default: begin rdata_processed = lsu_rdata; end
        endcase
    end

    assign lsu_ready = ((bvalid & wlast) | (rvalid & rlast) | exu_dnpc_valid_r) ? 1'b1 : ~(is_write | is_read);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
            awvalid <= 1'b0;
            arvalid <= 1'b0;
        end else begin
            state <= next_state;
            exu_dnpc_valid_r <= exu_dnpc_valid;
            case (state)
                IDLE: begin
`ifdef VERILATOR
                    diff_pc_o <= diff_pc_i;
`endif
                    lu_to_wu_bus <= 'b0;
                    lsu_valid <= 1'b0;
                    if (exu_valid) begin
                        if (is_read) begin
                            araddr  <= addr;
                            arvalid <= 1'b1;
                            arid <= 4'h0;
                            arlen <= AXI_LEN_SINGLE;
                            arsize <= {1'b0, data_rop};
                            arburst <= {1'b0, is_sdram};
                        end else if (is_write) begin
                            awvalid <= 1'b1;
                            wvalid <= 1'b1;
                            awaddr  <= addr;
                            wdata   <= aligned_wdata;
                            awid <= 4'h0;
                            awlen <= AXI_LEN_SINGLE;
                            awsize <= {1'b0, data_wop};
                            awburst <= {1'b0, is_sdram};
                            wlast <= 1'b1;
                            case (data_wop)
                                2'b00: wstrb <= (4'b0001 << addr_off);
                                2'b01: wstrb <= (4'b0011 << addr_off);
                                2'b10: wstrb <= (4'b1111 << addr_off);
                                default: wstrb <= 4'b0000;
                            endcase
                        end else begin
                            lsu_valid <= 1'b1;
                            lu_to_wu_bus <= {
                                rd,
                                eu_to_wu_bus,
                                gpr_we,
                                data_channel,
                                addr
                            };
                        end
                    end
                end
                BUSY: begin
                    lu_to_wu_bus <= 'b0;
                    lsu_valid <= 1'b0;
                    if (is_read) begin
                        if (arvalid && arready) begin
                            arvalid <= 1'b0;
                            rready <= 1'b1;
                        end
                        if (rvalid && rready) begin
                            lsu_valid <= 1'b1;
                            lu_to_wu_bus <= {
                                rd,
                                eu_to_wu_bus,
                                gpr_we,
                                data_channel,
                                rdata_processed
                                };
                            rready <= 1'b0;
                        end
                    end else if (is_write) begin 
                        if (awvalid && awready && wvalid && wready) begin
                            awvalid <= 1'b0;
                            wvalid <= 1'b0;
                            bready <= 1'b1;
                        end
                        if (bvalid && bready) begin
                            lsu_valid <= 1'b1;
                            bready <= 1'b0;
                        end
                    end
                end
            endcase
        end
    end

endmodule
