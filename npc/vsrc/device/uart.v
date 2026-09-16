`timescale 1ns/1ns 
module uart(
    input clock,
    /* verilator lint_off UNUSEDSIGNAL */
    input reset,
    // axi 握手信号
    
    input [31:0] slave_araddr,
    input slave_arvalid,
    output reg slave_arready,

    output reg [31:0] slave_rdata,
    output reg slave_rvalid,
    output reg [1:0] slave_rresp,
    input slave_rready,

    input [31:0] slave_awaddr,
    input slave_awvalid,
    output reg slave_awready,

    input [31:0] slave_wdata,
    input [3:0] slave_wstrb,
    input slave_wvalid,
    output reg slave_wready,

    output reg slave_bvalid,
    input slave_bready,
    output reg [1:0] slave_bresp
    /* verilator lint_on UNUSEDSIGNAL */
);


reg [2:0] state;
localparam IDLE = 3'd0;
localparam READ = 3'd1;
localparam READ_WAIT = 3'd2;
localparam WRITE = 3'd3;
localparam WRITE_WAIT = 3'd4;

always @(posedge clock) begin
    case (state)
        IDLE: begin
            if (slave_arvalid) begin
                slave_arready <= 1'b1;
                state <= READ;
            end
            else if (slave_awvalid && slave_wvalid) begin
                slave_awready <= 1'b1;
                slave_wready <= 1'b1;
                state <= WRITE;
            end
        end
        READ: begin
            if (slave_arready) begin
                slave_arready <= 1'b0;
            end
                slave_rdata <= 32'b0;
            slave_rvalid <= 1'b1;
            slave_rresp <= 2'b00;
            state <= READ_WAIT;
        end
        READ_WAIT: begin
            if (slave_rready) begin
                slave_rvalid <= 1'b0;
                slave_rresp <= 2'b00;
                slave_rdata <= 32'b0;
                state <= IDLE;
            end
        end
        WRITE: begin
            if (slave_awready || slave_wready) begin
                slave_awready <= 1'b0;
                slave_wready <= 1'b0;
            end
            case(slave_wstrb) 
            4'b0001: $write("%c", slave_wdata[7:0]);
            4'b0010: $write("%c", slave_wdata[15:8]);
            4'b0100: $write("%c", slave_wdata[23:16]);
            4'b1000: $write("%c", slave_wdata[31:24]);
            default: $write("%c", slave_wdata[7:0]);
            endcase
            
            state <= WRITE_WAIT;
            slave_bresp <= 2'b00;
            slave_bvalid <= 1'b1;
        end
        WRITE_WAIT: begin
            if (slave_bready) begin
                slave_bvalid <= 1'b0;
                slave_bresp <= 2'b00;
                state <= IDLE;
            end
        end
        default: begin
            state <= IDLE;
        end
    endcase 
end


endmodule
