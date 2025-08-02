module LSU_RAM(
    input   wire            clock   ,
    
    // // AR Channel
    // input   wire    [31:0]  araddr  ,
    // input   wire            arvalid ,
    // output  wire            arready ,

    // // R Channel
    // output  wire    [31:0]  rdata   ,
    // output  wire            rresp   ,
    // output  wire            rvalid  ,
    // input   wire            rready  ,

    // // AW Channel
    // input   wire    [31:0]  awaddr  ,
    // input   wire            awvalid ,
    // output  wire            awready ,

    // // W Channel
    // input   wire    [31:0]  wdata   ,
    // input   wire            wstrb   ,
    // input   wire            wvalid  ,
    // output  wire            wready  ,

    // // B Channel
    // output  wire            bresp   ,
    // output  wire            bvalid  ,
    // input   wire            bready  ,

    input   wire    [31:0]  waddr   ,
    input   wire    [31:0]  wdata   ,
    input   wire            wen     ,
    input   wire    [3:0]   wmask   ,

    input   wire    [31:0]  raddr   ,
    input   wire            ren     ,
    output  reg     [31:0]  rdata   
);

// for verilator
import "DPI-C" function int load_word(int raddr);

import "DPI-C" function void store_word(int waddr, int wdata);
import "DPI-C" function void store_half(int waddr, int wdata);
import "DPI-C" function void store_byte(int waddr, int wdata);

always @(posedge clock ) begin
    if(ren)
        rdata   <=  load_word(raddr);
end

always @(posedge clock ) begin
    if(wen) begin
        if(wmask == 4'b1111)
            store_word(waddr, wdata);
        else if(wmask == 4'b0011)
            store_half(waddr, wdata);
        else if(wmask == 4'b0001)
            store_byte(waddr, wdata);
    end
end

endmodule
