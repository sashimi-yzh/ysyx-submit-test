module ysyx_23060299_CLINT(
    input   wire            clock           ,
    input   wire            reset           ,
    
    // AR Channel
    input   wire    [31:0]  clint_araddr    ,
    input   wire            clint_arvalid   ,
    output                  clint_arready   ,
    input   wire    [2:0]   clint_arsize    ,

    // R Channel
    output  reg     [31:0]  clint_rdata     ,
    output  wire    [1:0]   clint_rresp     ,
    output  reg             clint_rvalid    ,
    input   wire            clint_rready    ,

    // AW Channel
    input   wire    [31:0]  clint_awaddr    ,
    input   wire            clint_awvalid   ,
    output                  clint_awready   ,
    input   wire    [2:0]   clint_awsize    ,

    // W Channel    
    input   wire    [31:0]  clint_wdata     ,
    input   wire    [3:0]   clint_wstrb     ,
    input   wire            clint_wvalid    ,
    output  reg             clint_wready    ,

    // B Channel    
    output  wire    [1:0]   clint_bresp     ,
    output  reg             clint_bvalid    ,
    input   wire            clint_bready    

);

wire            ar_handshake    ;
wire            r_handshake     ;
wire            aw_handshake    ;
wire            w_handshake     ;
wire            b_handshake     ;
reg     [1:0]   waddr_r         ;
reg             cnt_en          ;
// reg     [63:0]  cnt             ;
reg     [47:0]  cnt             ;

assign  ar_handshake    =   clint_arvalid    &&  clint_arready    ;
assign  r_handshake     =   clint_rvalid     &&  clint_rready     ;
assign  aw_handshake    =   clint_awvalid    &&  clint_awready    ;
assign  w_handshake     =   clint_wvalid     &&  clint_wready     ;
assign  b_handshake     =   clint_bvalid     &&  clint_bready     ;

always @(posedge clock ) begin
    if(reset)
        cnt <=  'd0 ;
    else    if(cnt_en)
        cnt <=  cnt +   1'b1;
end

always @(posedge clock ) begin
    if(ar_handshake) begin
        case (clint_araddr[3:2])
            2'd0 : clint_rdata    <=  cnt[31:0]         ;  
            // 2'd1 : clint_rdata    <=  cnt[63:32]        ;  
            2'd1 : clint_rdata    <=  {16'd0, cnt[47:32]}   ; 
            2'd2 : clint_rdata    <=  {31'd0, cnt_en}   ;
            default: clint_rdata    <=  'd0 ;
        endcase
    end
end

always @(posedge clock ) begin
    if(aw_handshake)
        waddr_r <=  clint_awaddr [3:2];
end

`ifndef ysyx_23060299_NPC
always @(posedge clock ) begin
    if(reset)
        cnt_en  <=  1'b0    ;
    else if(w_handshake && (|clint_wstrb)) begin
        if(waddr_r == 2'd2)
            cnt_en  <=  clint_wdata[0]  ;
    end
end
`endif

// always @(posedge clock ) begin
//     if(reset)
//         clint_arready    <=  'd1 ;
//     else if(ar_handshake)
//         clint_arready    <=  'd0 ;
//     else if(r_handshake)
//         clint_arready    <=  'd1 ;
// end

assign  clint_arready   =   1'b1    ;

assign  clint_rresp  =   2'b00   ;

always @(posedge clock ) begin
    if(reset)
        clint_rvalid <=  'd0 ;
    else if(ar_handshake)
        clint_rvalid <=  'd1 ;
    else if(r_handshake)
        clint_rvalid <=  'd0 ;
end

// always @(posedge clock ) begin
//     if(reset)
//         clint_awready    <=  'd1 ;
//     else if(aw_handshake)
//         clint_awready    <=  'd0 ;
//     else if(b_handshake)
//         clint_awready    <=  'd1 ;
// end

assign  clint_awready   =   1'b1    ;

// always @(posedge clock ) begin
//     if(reset)
//         clint_wready    <=  'd0 ;
//     else if(aw_handshake)
//         clint_wready    <=  'd1 ;
//     else if(w_handshake)
//         clint_wready    <=  'd0 ;
// end

assign  clint_wready    =   1'b1    ;

assign  clint_bresp  =   2'b00   ;

always @(posedge clock ) begin
    if(reset)
        clint_bvalid <=  'd0 ;
    else if(w_handshake)
        clint_bvalid <=  'd1 ;
    else if(b_handshake)
        clint_bvalid <=  'd0 ;
end

`ifdef ysyx_23060299_verilator_env  

// for verilator 
// yosys-sta need to mask
import "DPI-C" function void uart_putchar(input int data);

always @(posedge clock) begin
    if(w_handshake  &&   waddr_r == 2'd3)
        uart_putchar(clint_wdata);
end

`endif

endmodule
