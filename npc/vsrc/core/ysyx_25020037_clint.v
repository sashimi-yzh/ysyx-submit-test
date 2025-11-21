module ysyx_25020037_clint(
    input  wire         clk,
    input  wire         rst,

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
    reg  [31: 0] mtimel, mtimeh;
    wire [ 3: 0] clint_offset;
    assign  clint_offset = araddr[3:0];

    localparam IDLE         = 1'b0;
    localparam BUSY         = 1'b1;
    reg          state, next_state;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;   
            arready <= 1'b1;
            rvalid <= 1'b0;
            rid <= 4'b0;
            rresp <= 2'b00;
            mtimel <= 32'h0;
            mtimeh <= 32'h0;
        end else begin
            state <= next_state;
            if (mtimel == 32'hFFFFFFFF) begin
                mtimel <= 32'h0;
                mtimeh <= mtimeh + 1;
            end else begin
                mtimel <= mtimel + 1;
            end
            case (state)
                IDLE: begin
                    rvalid <= 1'b0;
                    rlast <= 1'b0;
                    if (arvalid & arready) begin
                        arready <= 1'b0;
                    end
                end
                
                BUSY: begin
                    arready <= 1'b1;
                    rdata <= (clint_offset == 4'h0) ? mtimel : mtimeh;
                    rvalid <= 1'b1;
                    rlast <= 1'b1;
                end
            endcase
        end
    end

    always @(*) begin
        case (state)
            IDLE: next_state = (arvalid) ? BUSY : IDLE;      
            BUSY: next_state = (rready & rlast) ? IDLE : BUSY; 
            default: next_state = IDLE;
        endcase
    end

endmodule
