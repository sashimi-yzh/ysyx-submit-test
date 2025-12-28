module ysyx_24070003_clint #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input clock,
    input rstn,


    // AXI-Lite4 Read Address Channel
    input [ADDR_WIDTH-1:0] AXI4_CLINT_ARADDR,
    output              AXI4_CLINT_ARREADY,
    
    // AXI-Lite4 Read Data Channel
    output  [DATA_WIDTH-1:0] AXI4_CLINT_RDATA,
    output                   AXI4_CLINT_RVALID
    //output reg [1:0]       AXI4_SRAM_BRESP 
);
    //reg [DATA_WIDTH-1:0] mem [0:2**ADDR_WIDTH-1];


//import "DPI-C" function void vpmem_read(input int raddr,input byte ren,output int rdata);
//import "DPI-C" function void vpmem_write(input int waddr, input byte wmask,input int wdata,input byte wen);


reg [31:0] mtime_low;
reg [31:0] mtime_high;
always @(posedge clock) begin
    if (rstn) begin
        mtime_low <= 32'b0;
    end else if(mtime_low == 32'hffffffff) begin
        mtime_low <= 32'b0;
    end else begin
        mtime_low <= mtime_low + 32'b1;
    end
end
always @(posedge clock) begin
    if (rstn) begin
        mtime_high <= 32'b0;
    end else if (mtime_low == 32'hffffffff)begin
            mtime_high <= mtime_high + 32'b1;
    end else begin
        mtime_high <= mtime_high;
    end
end

// wire [31:0] rdata;
assign AXI4_CLINT_RDATA = (AXI4_CLINT_ARADDR[2:0] == 4'h0) ? mtime_low : mtime_high;

assign AXI4_CLINT_RVALID = 1'b1;
assign AXI4_CLINT_ARREADY = 1'b1;



// // DPI-C interface for instruction read
// //import "DPI-C" function void vpmem_read(input int raddr, output int rdata);

// // State machine
// always @(posedge clock) begin
//     if (rstn) begin
//         state_read <= RIDLE;
//         AXI4_CLINT_ARREADY <= 1'b0;
//         AXI4_CLINT_RVALID <= 1'b0;
        
//         read_addr_reg <= 'b0;
//     end
//     else begin
//         case (state_read)
//             RIDLE: begin
//                 AXI4_CLINT_ARREADY <= 1'b1;
//                 if (AXI4_CLINT_ARVALID) begin
//                     // Latch read address
//                     read_addr_reg <= AXI4_CLINT_ARADDR;
//                     AXI4_CLINT_ARREADY <= 1'b0;
//                     state_read <= READ_DATA;
//                 end
//             end
            
//             READ_DATA: begin
//                 // Perform read operation using DPI-C
//                 //vpmem_read(read_addr_reg, {7'b0, 1'b1}, AXI4_CLINT_RDATA);
//                 AXI4_CLINT_RDATA <= rdata;
//                 AXI4_CLINT_RVALID <= 1'b1;
//                 state_read <= READ_WAIT;
//             end
            
//             READ_WAIT: begin
//                 if (AXI4_CLINT_RREADY) begin
//                     AXI4_CLINT_RVALID <= 1'b0;
//                     state_read <= RIDLE;
//                 end
//             end
            
//             default: state_read <= RIDLE;
//         endcase
//     end
// end


endmodule

