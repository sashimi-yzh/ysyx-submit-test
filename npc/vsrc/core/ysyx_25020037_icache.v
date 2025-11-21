`include "ysyx_25020037_config.vh"

module ysyx_25020037_icache #(
    parameter ADDR_WIDTH    = 32,
    parameter DATA_WIDTH    = 32,
    parameter CACHE_BLOCKS  = 16,
    parameter BLOCK_SIZE    = 16,
    parameter OFFSET_WIDTH  = $clog2(BLOCK_SIZE),
    parameter INDEX_WIDTH   = $clog2(CACHE_BLOCKS),
    parameter TAG_WIDTH     = ADDR_WIDTH - INDEX_WIDTH - OFFSET_WIDTH
) (
    input  wire         clk,
    input  wire         rst,

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
    input  wire [ 3: 0] rid,

    input  wire [`EU_TO_IC_BUS_WD -1:0] eu_to_ic_bus,

    input  wire [ADDR_WIDTH-1:0] cpu_addr,
    input  wire                  cpu_valid,
    output wire [DATA_WIDTH-1:0] inst,
    output wire                  cpu_hit
);
wire is_fence_i = eu_to_ic_bus;

localparam SDRAM_BASE = 4'hA; // A000_0000-BFFF_FFFF
localparam SDRAM_END  = 4'hB;

localparam IDLE    = 1'b0;
localparam BUSY    = 1'b1;

reg         state, next_state;
wire [31:0] mem_addr = {cpu_addr[31:OFFSET_WIDTH], {OFFSET_WIDTH{1'b0}}};
wire        is_sdram = (mem_addr[31:28] == SDRAM_BASE) | (mem_addr[31:28] == SDRAM_END);
reg  [1:0]  burst_cnt;

wire [OFFSET_WIDTH-1:0]   offset;
wire [ INDEX_WIDTH-1:0]   index;
wire [   TAG_WIDTH-1:0]   tag;

assign offset = cpu_addr[OFFSET_WIDTH-1 : 0];
assign index  = cpu_addr[OFFSET_WIDTH + INDEX_WIDTH - 1 : OFFSET_WIDTH];
assign tag    = cpu_addr[ADDR_WIDTH-1 : OFFSET_WIDTH + INDEX_WIDTH];

reg [   TAG_WIDTH-1:0]  tag_array  [CACHE_BLOCKS-1:0];
reg [BLOCK_SIZE*8-1:0]  data_array [CACHE_BLOCKS-1:0];
reg [CACHE_BLOCKS-1:0]  valid_array;

assign cpu_hit = valid_array[index] && (tag_array[index] == tag);
assign inst    = data_array[index][offset*8 +: DATA_WIDTH];
always @(*) begin
    case (state)
        IDLE:  begin next_state = cpu_valid ? (cpu_hit) ? IDLE : BUSY : IDLE; end
        BUSY:  begin next_state = (cpu_hit) ? IDLE : BUSY; end
        default: next_state = IDLE;
    endcase
end
always @(posedge clk or posedge rst) begin
    if (rst) begin
        state <= IDLE;
        arvalid <= 1'b0;
        valid_array <= 'b0;
        burst_cnt <= 2'd0;
    end else begin
        state <= next_state;
        valid_array <= is_fence_i ? 'b0 : valid_array;
        case (state)
            IDLE: begin
                if (~cpu_hit & cpu_valid) begin
                    araddr <= mem_addr;
                    arvalid <= 1'b1;
                    arid <= 4'h0;
                    arsize <= 3'h2;
                    if (is_sdram) begin
                        arlen <= 8'h3;
                        arburst <= 2'h1;
                    end else begin
                        arlen <= 8'h0;
                        arburst <= 2'h0;
                    end
                end
            end
            BUSY: begin
                if (arvalid && arready) begin
                    arvalid <= 1'b0;
                    rready <= 1'b1;
                end
                if (rvalid && rready) begin
                    case(burst_cnt)
                        2'd0: data_array[index][ 31: 0] <= rdata;
                        2'd1: data_array[index][ 63:32] <= rdata;
                        2'd2: data_array[index][ 95:64] <= rdata;
                        2'd3: data_array[index][127:96] <= rdata;
                    endcase
                    burst_cnt <= burst_cnt + 2'b1;
                    if (is_sdram) begin
                        if (rlast) begin
                            rready <= 1'b0;
                            tag_array[index]    <= tag;
                            valid_array[index]  <= 1'b1;
                        end
                    end else begin
                        if (burst_cnt == 2'b11) begin
                            rready <= 1'b0;
                            tag_array[index]    <= tag;
                            valid_array[index]  <= 1'b1;
                        end else begin
                            araddr <= araddr + 32'h4;
                            arvalid <= 1'b1;
                        end
                    end
                end
            end
        endcase
    end
end

endmodule
