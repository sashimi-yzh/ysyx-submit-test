module ysyx_25020037_uart(
    input  wire         clk,
    input  wire         rst,

    output reg          awready,
    input  wire         awvalid,
    input  wire [31: 0] awaddr,
    input  wire [ 3: 0] awid,
    input  wire [ 7: 0] awlen,
    input  wire [ 2: 0] awsize,
    input  wire [ 1: 0] awburst,
    output reg          wready,
    input  wire         wvalid,
    input  wire [31: 0] wdata,
    input  wire [ 3: 0] wstrb,
    input  wire         wlast,
    input  wire         bready,
    output reg          bvalid,
    output reg  [ 1: 0] bresp,
    output reg  [ 3: 0] bid,
    output reg          arready,
    input  wire         arvalid,
    input  wire [31: 0] araddr,
    input  wire [ 3: 0] arid,
    input  wire [ 7: 0] arlen,
    input  wire [ 2: 0] arsize,
    input  wire [ 1: 0] arburst,
    input  wire         rready,
    output reg          rvalid,
    output reg  [ 1: 0] rresp,
    output reg  [31: 0] rdata,
    output reg          rlast,
    output reg  [ 3: 0] rid
);
    localparam IDLE         = 1'b0;
    localparam BUSY         = 1'b1;
    reg          state, next_state;
    reg  [31: 0] read_addr, write_addr;
    reg          is_read_req, is_write_req;
    reg  [ 3: 0] read_id, write_id;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;   
            arready <= 1'b1;
            rdata <= 32'b0;
            rresp <= 2'b00;
            rvalid <= 1'b0;
            rlast <= 1'b0;
            rid <= 4'h0;
            awready <= 1'b1;
            wready <= 1'b0;
            bresp <= 2'b00;
            bvalid <= 1'b0;
            bid <= 4'h0;
            is_read_req <= 1'b0;
            is_write_req <= 1'b0;
            read_addr <= 32'h0;
            write_addr <= 32'h0;
            read_id <= 4'h0;
            write_id <= 4'h0;
        end else begin
            state <= next_state;
            
            case (state)
                IDLE: begin
                    rvalid <= 1'b0;
                    bvalid <= 1'b0;
                    rlast <= 1'b0;
                    is_read_req <= 1'b0;
                    is_write_req <= 1'b0;
                    wready <= 1'b0;

                    if (arvalid) begin
                        read_addr <= araddr;
                        read_id <= arid;
                        arready <= 1'b1;
                        is_read_req <= 1'b1;
                    end else if (awvalid & wvalid) begin
                        write_addr <= awaddr;
                        write_id <= awid;
                        awready <= 1'b1;
                        wready <= 1'b1;
                        is_write_req <= 1'b1;
                    end
                end
                BUSY: begin
                    if (is_read_req) begin
                        rvalid <= 1'b1;
                        rresp <= 2'b00;
                        rlast <= 1'b1;
                        rid <= read_id;
                        if (rvalid & rready) begin
                            rvalid <= 1'b0;
                            rlast <= 1'b0;
                        end
                    end else if (is_write_req) begin
                        if (wvalid & wready) begin
                            wready <= 1'b0;
                            $write("%c", wdata[7:0]);
                            $fflush();
                            bvalid <= 1'b1;
                            bresp <= 2'b00;
                            bid <= write_id;
                        end
                        if (bvalid & bready) begin
                            awready <= 1'b0;
                            bvalid <= 1'b0;
                        end
                    end
                end
            endcase
        end
    end

    always @(*) begin
        case (state)
            IDLE: next_state = (arvalid | awvalid) ? BUSY : IDLE;      
            BUSY: begin
                if ((is_read_req && rlast && rvalid) || (is_write_req && bvalid && bready)) begin
                    next_state = IDLE;
                end else begin
                    next_state = BUSY;
                end
            end
            default: next_state = IDLE;
        endcase
    end

endmodule