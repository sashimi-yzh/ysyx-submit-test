module uart_npc #
(
    // Width of data bus in bits
    parameter DATA_WIDTH = 32,
    // Width of address bus in bits
    parameter ADDR_WIDTH = 27,
    // Width of wstrb (width of data bus in words)
    parameter STRB_WIDTH = (DATA_WIDTH/8),
    // Width of ID signal
    parameter ID_WIDTH = 4
)
(
    input       clk,
    input       reset,

    input  wire [ID_WIDTH-1:0]    s_axi_awid,
    input  wire [ADDR_WIDTH-1:0]  s_axi_awaddr,
    input  wire [7:0]             s_axi_awlen,
    input  wire [2:0]             s_axi_awsize,
    input  wire [1:0]             s_axi_awburst,
    // input  wire                   s_axi_awlock,
    // input  wire [3:0]             s_axi_awcache,
    // input  wire [2:0]             s_axi_awprot,
    input  wire                   s_axi_awvalid,
    output wire                   s_axi_awready,
    input  wire [DATA_WIDTH-1:0]  s_axi_wdata,
    input  wire [STRB_WIDTH-1:0]  s_axi_wstrb,
    input  wire                   s_axi_wlast,
    input  wire                   s_axi_wvalid,
    output wire                   s_axi_wready,
    output wire [ID_WIDTH-1:0]    s_axi_bid,
    output wire [1:0]             s_axi_bresp,
    output wire                   s_axi_bvalid,
    input  wire                   s_axi_bready 
);


    localparam  WAIT_AWVALID    = 0;
    localparam  WAIT_WVALID     = 1;
    localparam  WAIT_BREADY     = 2;

    reg     [1:0]   current_state;
    reg     [1:0]   next_state;


    assign  s_axi_awready   = (current_state == WAIT_AWVALID);
    assign  s_axi_wready    = (current_state == WAIT_WVALID);
    assign  s_axi_bid       = 4'h1;
    assign  s_axi_bresp     = 2'b00;
    assign  s_axi_bvalid    = (current_state == WAIT_BREADY);


    always @(posedge clk) begin
        if(reset) begin
            current_state   <= WAIT_AWVALID;
        end
        else begin
            current_state   <= next_state;
        end
    end

    always @(*) begin
        case(current_state)
            
            WAIT_AWVALID: begin
                if(s_axi_awvalid == 1'b1 && s_axi_awaddr[11:0] == 12'h3f8) begin
                    next_state  = WAIT_WVALID;
                end
                else begin
                    next_state  = WAIT_AWVALID;
                end
            end

            WAIT_WVALID: begin
                if(s_axi_wvalid == 1'b1) begin
                    next_state  = WAIT_BREADY;
                end
                else begin
                    next_state  = WAIT_WVALID;
                end
            end

            WAIT_BREADY: begin
                if(s_axi_bready == 1'b1) begin
                    next_state  = WAIT_AWVALID;
                end
                else begin
                    next_state  = WAIT_BREADY;
                end
            end
            
            default: next_state = WAIT_AWVALID;
        endcase
    end

    // always @(posedge clk) begin
    //     if(s_axi_awready && s_axi_awvalid) begin
    //         wstrb       <= s_axi_wstrb;
    //     end
    // end

    always @(posedge clk) begin
        if(s_axi_wready && s_axi_wvalid) begin
            $write("%c", s_axi_wdata[7:0]);
            $fflush();
        end
    end



endmodule
