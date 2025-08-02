module SRAM(
    input   wire            clock           ,
    input   wire            reset           ,
    
    // AR Channel
    input   wire    [31:0]  sram_araddr     ,
    input   wire            sram_arvalid    ,
    output  reg             sram_arready    ,
    input   wire    [2:0]   sram_arsize     ,

    // R Channel
    output  reg     [31:0]  sram_rdata      ,
    output  wire    [1:0]   sram_rresp      ,
    output  reg             sram_rvalid     ,
    input   wire            sram_rready     ,

    // AW Channel
    input   wire    [31:0]  sram_awaddr     ,
    input   wire            sram_awvalid    ,
    output  reg             sram_awready    ,
    input   wire    [2:0]   sram_awsize     ,
    // W Channel    
    input   wire    [31:0]  sram_wdata      ,
    input   wire    [3:0]   sram_wstrb      ,
    input   wire            sram_wvalid     ,
    output  reg             sram_wready     ,

    // B Channel    
    output  wire    [1:0]   sram_bresp      ,
    output  reg             sram_bvalid     ,
    input   wire            sram_bready  

);

import "DPI-C" function void store_word(int waddr, int wdata);
import "DPI-C" function void store_half(int waddr, int wdata);
import "DPI-C" function void store_byte(int waddr, int wdata);
import "DPI-C" function int load_word(int raddr);
import "DPI-C" function shortint load_half(int raddr);
import "DPI-C" function byte load_byte(int raddr);
import "DPI-C" function int inst_fetch(int pc);

wire            ar_handshake    ;
wire            r_handshake     ;
wire            aw_handshake    ;
wire            w_handshake     ;
wire            b_handshake     ;
reg     [31:0]  waddr_r         ;

assign  ar_handshake    =   sram_arvalid    &&  sram_arready    ;
assign  r_handshake     =   sram_rvalid     &&  sram_rready     ;
assign  aw_handshake    =   sram_awvalid    &&  sram_awready    ;
assign  w_handshake     =   sram_wvalid     &&  sram_wready     ;
assign  b_handshake     =   sram_bvalid     &&  sram_bready     ;

always @(posedge clock ) begin
    if(ar_handshake) begin
        if(sram_arsize == 3'b010)
            sram_rdata   <=  load_word(sram_araddr);
        else if(sram_arsize == 3'b001) begin
            if(sram_araddr[1:0] == 2'b10)
                sram_rdata   <=  {load_half(sram_araddr), 16'd0};
            else if(sram_araddr[1:0] == 2'b00)
                sram_rdata   <=  {16'd0, load_half(sram_araddr)};
        end
        else if(sram_arsize == 3'b000) begin
            if(sram_araddr[1:0] == 2'b11)
                sram_rdata   <=  {load_byte(sram_araddr), 24'd0};
            else if(sram_araddr[1:0] == 2'b01)
                sram_rdata   <=  {16'd0, load_byte(sram_araddr), 8'd0};
            else if(sram_araddr[1:0] == 2'b10)
                sram_rdata   <=  {8'd0, load_byte(sram_araddr), 16'd0};
            else if(sram_araddr[1:0] == 2'b00)
                sram_rdata   <=  {24'd0, load_byte(sram_araddr)};
        end
            
    end
        
end

always @(posedge clock ) begin
    if(aw_handshake)
        waddr_r <=  sram_awaddr ;
end

always @(posedge clock ) begin
    if(w_handshake) begin
        if(sram_wstrb == 4'b1111)
            store_word(waddr_r, sram_wdata);
        else if(sram_wstrb == 4'b0011)
            store_half(waddr_r, {16'd0,sram_wdata[15:0]});
        else if(sram_wstrb == 4'b1100)
            store_half(waddr_r, {16'd0,sram_wdata[31:16]});
        else if(sram_wstrb == 4'b1000)
            store_byte(waddr_r, {24'd0,sram_wdata[31:24]});
        else if(sram_wstrb == 4'b0100)
            store_byte(waddr_r, {24'd0,sram_wdata[23:16]});
        else if(sram_wstrb == 4'b0010)
            store_byte(waddr_r, {24'd0,sram_wdata[15:8]});
        else if(sram_wstrb == 4'b0001)
            store_byte(waddr_r, {24'd0,sram_wdata[7:0]});
    end
end

always @(posedge clock ) begin
    if(reset)
        sram_arready    <=  'd1 ;
    else if(ar_handshake)
        sram_arready    <=  'd0 ;
    else if(r_handshake)
        sram_arready    <=  'd1 ;
end

assign  sram_rresp  =   2'b00   ;

always @(posedge clock ) begin
    if(reset)
        sram_rvalid <=  'd0 ;
    else if(ar_handshake)
        sram_rvalid <=  'd1 ;
    else if(r_handshake)
        sram_rvalid <=  'd0 ;
end

always @(posedge clock ) begin
    if(reset)
        sram_awready    <=  'd1 ;
    else if(aw_handshake)
        sram_awready    <=  'd0 ;
    else if(b_handshake)
        sram_awready    <=  'd1 ;
end

always @(posedge clock ) begin
    if(reset)
        sram_wready    <=  'd0 ;
    else if(aw_handshake)
        sram_wready    <=  'd1 ;
    else if(w_handshake)
        sram_wready    <=  'd0 ;
end

assign  sram_bresp  =   2'b00   ;

always @(posedge clock ) begin
    if(reset)
        sram_bvalid <=  'd0 ;
    else if(w_handshake)
        sram_bvalid <=  'd1 ;
    else if(b_handshake)
        sram_bvalid <=  'd0 ;
end

// wire    [3:0]   lfsr_out        ;
// reg     [3:0]   lfsr_cnt        ;
// reg             lfsr_shifting   ;
// wire            delay_done      ;

// reg     [31:0]  araddr_r        ;

// assign  delay_done      =   (lfsr_cnt    ==  lfsr_out);

// lfsr_4bit   lfsr_4bit   (
//     .clock      (clock          ),
//     .reset      (reset          ),
//     .enable     (r_handshake    ),
//     .lfsr_out   (lfsr_out       )
// );

// always @(posedge clock ) begin
//     if(delay_done)
//         rdata    <=  inst_fetch(araddr_r);
// end

// always @(posedge clock ) begin
//     if(reset)
//         lfsr_shifting   <=  1'b0    ;
//     else if(ar_handshake)
//         lfsr_shifting   <=  1'b1    ;
//     else if(delay_done)
//         lfsr_shifting   <=  1'b0    ;
// end

// always @(posedge clock ) begin
//     if(reset)
//         lfsr_cnt    <=  'd0 ;
//     else if(delay_done)
//         lfsr_cnt    <=  'd0 ;
//     else if(lfsr_shifting)
//         lfsr_cnt    <=  lfsr_cnt    +   1'b1    ;
// end

// assign  rresp   =   2'b00   ;

// always @(posedge clock ) begin
//     if(reset)
//         arready <=  'd1 ;
//     else if(ar_handshake)
//         arready <=  'd0 ;
//     else if(r_handshake)
//         arready <=  'd1 ;
// end

// always @(posedge clock ) begin
//     if(ar_handshake)
//         araddr_r    <=  araddr  ;
// end

// always @(posedge clock ) begin
//     if(reset)
//         rvalid  <=  1'b0;
//     else if(delay_done)
//         rvalid  <=  1'b1;
//     else if(r_handshake)
//         rvalid  <=  1'b0;
// end

endmodule
