module sram #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input CLK,
    input rstn,
    //input wen,
    //input ren,
    //input [ADDR_WIDTH-1:0] addr,
    //input [3:0] wlen,
    //input [DATA_WIDTH-1:0] data,
    //output reg [DATA_WIDTH-1:0] Q,


    // AXI-Lite4 Read Address Channel
    input [ADDR_WIDTH-1:0] AXI4_SRAM_ARADDR,
    input                  AXI4_SRAM_ARVALID,
    output reg             AXI4_SRAM_ARREADY,
    
    // AXI-Lite4 Read Data Channel
    output reg [DATA_WIDTH-1:0] AXI4_SRAM_RDATA,
    output reg                  AXI4_SRAM_RVALID,
    input                       AXI4_SRAM_RREADY,

    // AXI-Lite4 Write Address Channel
    input [ADDR_WIDTH-1:0] AXI4_SRAM_AWADDR,
    input                  AXI4_SRAM_AWVALID,
    output reg             AXI4_SRAM_AWREADY,
   
    // AXI-Lite4 Write Data Channel
    input [DATA_WIDTH-1:0] AXI4_SRAM_WDATA,
    input [3:0]            AXI4_SRAM_WSTRB,  
    input                  AXI4_SRAM_WVALID,
    output reg             AXI4_SRAM_WREADY,
   
    // AXI-Lite4 Write Response Channel
    output reg             AXI4_SRAM_BVALID,
    input                  AXI4_SRAM_BREADY
    //output reg [1:0]       AXI4_SRAM_BRESP 
);
    //reg [DATA_WIDTH-1:0] mem [0:2**ADDR_WIDTH-1];


import "DPI-C" function void vpmem_read(input int raddr,input byte ren,output int rdata);
import "DPI-C" function void vpmem_write(input int waddr, input byte wmask,input int wdata,input byte wen);

/*
    always @(posedge CLK) begin
        
            vpmem_write(addr, {4'b0, wlen},data,{7'b0, wen});
        
    end

    always @(posedge CLK) begin
        
            //Q <= mem[addr];
            vpmem_read(addr,{7'b0, ren},Q);
        
    end
*/


localparam RIDLE        = 2'b00;
localparam READ_DATA  = 2'b01;
localparam READ_WAIT   = 2'b10;

localparam WIDLE        = 2'b00;
localparam WRITE_WAIT_1  = 2'b01;
localparam WRITE_WAIT_2  = 2'b10;
localparam WRITE_DATA  = 2'b11;

reg [1:0] state_read, state_write;
reg [ADDR_WIDTH-1:0] read_addr_reg;

// DPI-C interface for instruction read
//import "DPI-C" function void vpmem_read(input int raddr, output int rdata);

// State machine
always @(posedge CLK) begin
    if (rstn) begin
        state_read <= RIDLE;
        AXI4_SRAM_ARREADY <= 1'b0;
        AXI4_SRAM_RVALID <= 1'b0;
        
        read_addr_reg <= 'b0;
    end
    else begin
        case (state_read)
            RIDLE: begin
                AXI4_SRAM_ARREADY <= 1'b1;
                if (AXI4_SRAM_ARVALID) begin
                    // Latch read address
                    read_addr_reg <= AXI4_SRAM_ARADDR;
                    AXI4_SRAM_ARREADY <= 1'b0;
                    state_read <= READ_DATA;
                end
            end
            
            READ_DATA: begin
                // Perform read operation using DPI-C
                vpmem_read(read_addr_reg, {7'b0, 1'b1}, AXI4_SRAM_RDATA);
                AXI4_SRAM_RVALID <= 1'b1;
                state_read <= READ_WAIT;
            end
            
            READ_WAIT: begin
                if (AXI4_SRAM_RREADY) begin
                    AXI4_SRAM_RVALID <= 1'b0;
                    state_read <= RIDLE;
                end
            end
            
            default: state_read <= RIDLE;
        endcase
    end
end

reg [31:0] write_addr_reg, write_data;
reg [3:0] wirte_wstrb;
always @(posedge CLK) begin
    if (rstn) begin
        state_write <= WIDLE;
        AXI4_SRAM_AWREADY <= 1'b0;
        AXI4_SRAM_WREADY <= 1'b0;
        AXI4_SRAM_BVALID <= 1'b0;
        //LSU_AXI4_BRESP <= 2'b0;
        write_addr_reg <= 'b0;
        write_data <= 'b0;
        wirte_wstrb <= 'b0;
    end
    else begin
        case (state_write)
            WIDLE: begin
                AXI4_SRAM_AWREADY <= 1'b1;
                AXI4_SRAM_WREADY <= 1'b1;
                //LSU_AXI4_BRESP <= 2'b0;
                AXI4_SRAM_BVALID <= 1'b0;
                if (AXI4_SRAM_AWVALID && AXI4_SRAM_WVALID) begin
                    // Latch read address
                    write_addr_reg <= AXI4_SRAM_AWADDR;
                    write_data <= AXI4_SRAM_WDATA;
                    wirte_wstrb <= AXI4_SRAM_WSTRB;
                    AXI4_SRAM_AWREADY <= 1'b0;
                    AXI4_SRAM_WREADY <= 1'b0;
                    state_write <= WRITE_DATA;
                end

                else if (AXI4_SRAM_AWVALID ) begin
                    // Latch read address
                    write_addr_reg <= AXI4_SRAM_AWADDR;
                    AXI4_SRAM_AWREADY <= 1'b0;
                    state_write <= WRITE_WAIT_1;
                end

                else if (AXI4_SRAM_WVALID ) begin
                    // Latch read address
                    write_data <= AXI4_SRAM_WDATA;
                    wirte_wstrb <= AXI4_SRAM_WSTRB;
                    AXI4_SRAM_WREADY <= 1'b0;
                    state_write <= WRITE_WAIT_2;
                end
            end
            
            WRITE_WAIT_1: begin
                if (AXI4_SRAM_WVALID ) begin
                    // Latch read address
                    write_data <= AXI4_SRAM_WDATA;
                    wirte_wstrb <= AXI4_SRAM_WSTRB;
                    AXI4_SRAM_WREADY <= 1'b0;
                    state_write <= WRITE_DATA;
                end
            end
            
            WRITE_WAIT_2: begin
                if (AXI4_SRAM_AWVALID ) begin
                    // Latch read address
                    write_addr_reg <= AXI4_SRAM_ARADDR;
                    AXI4_SRAM_AWREADY <= 1'b0;
                    state_write <= WRITE_DATA;
                end
            end
            
            WRITE_DATA: begin
                AXI4_SRAM_BVALID <= 1'b1;
                vpmem_write(write_addr_reg, {4'b0, wirte_wstrb},write_data,{7'b0, 1'b1});
                if(AXI4_SRAM_BVALID && AXI4_SRAM_BREADY) begin
                    AXI4_SRAM_BVALID <= 1'b0;
                    state_write <= WIDLE;
                end
            end
            default: state_write <= WIDLE;
        endcase
    end
end



endmodule
