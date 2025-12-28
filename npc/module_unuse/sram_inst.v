module sram_inst #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input CLK,
    input rstn,
    //input [ADDR_WIDTH-1:0] addr,
    //output reg [DATA_WIDTH-1:0] Q

    // AXI-Lite4 Read Address Channel
    input [ADDR_WIDTH-1:0] IFU_AXI4_ARADDR,
    input                  IFU_AXI4_ARVALID,
    output reg             IFU_AXI4_ARREADY,
    
    // AXI-Lite4 Read Data Channel
    output reg [DATA_WIDTH-1:0] IFU_AXI4_RDATA,
    output reg                  IFU_AXI4_RVALID,
    input                       IFU_AXI4_RREADY
);
    //reg [DATA_WIDTH-1:0] mem [0:2**ADDR_WIDTH-1];


    import "DPI-C" function void vpmem_read(input int raddr,input byte ren,output int rdata);

    /*always @(posedge CLK) begin
        if (wen) begin
            mem[addr] <= data;
        end
    end*/
/*
    always @(posedge CLK) begin
        if (~wen) begin
            //Q <= mem[addr];
            vpmem_read(addr,{7'b0, 1'b1},Q);
        end
       // $display("Time=%0t addr=%h instr=%h", $time, addr, Q);
    end
*/
localparam IDLE        = 2'b00;
localparam READ_DATA  = 2'b01;
localparam READ_WAIT   = 2'b10;
reg [1:0] state;
reg [ADDR_WIDTH-1:0] read_addr_reg;

// DPI-C interface for instruction read
//import "DPI-C" function void vpmem_read(input int raddr, output int rdata);

// State machine
always @(posedge CLK) begin
    if (rstn) begin
        state <= IDLE;
        IFU_AXI4_ARREADY <= 1'b0;
        IFU_AXI4_RVALID <= 1'b0;
        
        read_addr_reg <= 'b0;
    end
    else begin
        case (state)
            IDLE: begin
                IFU_AXI4_ARREADY <= 1'b1;
                if (IFU_AXI4_ARVALID) begin
                    // Latch read address
                    read_addr_reg <= IFU_AXI4_ARADDR;
                    IFU_AXI4_ARREADY <= 1'b0;
                    state <= READ_DATA;
                end
            end
            
            READ_DATA: begin
                // Perform read operation using DPI-C
                vpmem_read(read_addr_reg, {7'b0, 1'b1},IFU_AXI4_RDATA);
                IFU_AXI4_RVALID <= 1'b1;
                state <= READ_WAIT;
            end
            
            READ_WAIT: begin
                if (IFU_AXI4_RREADY) begin
                    IFU_AXI4_RVALID <= 1'b0;
                    state <= IDLE;
                end
            end
            
            default: state <= IDLE;
        endcase
    end
end

endmodule
