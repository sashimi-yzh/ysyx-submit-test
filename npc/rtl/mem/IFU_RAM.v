module IFU_RAM (
    input   wire            clock       ,      
    input   wire            reset       ,       

    input   wire    [31:0]  cpu_cache_addr  ,
    input   wire            cpu_cache_valid ,
    output  reg     [31:0]  cache_cpu_data  ,
    output  wire            cache_cpu_ready ,
    output  reg             cache_cpu_valid   
);

assign  cache_cpu_ready =   1'b1    ;

import "DPI-C" function int inst_fetch(int pc);

always @(posedge clock ) begin
    if(cpu_cache_valid)
        cache_cpu_data    <=  inst_fetch(cpu_cache_addr);
end

always @(posedge clock ) begin
    if(reset)
        cache_cpu_valid <=  1'b0    ;
    else if(cpu_cache_valid && cache_cpu_ready) 
        cache_cpu_valid <=  1'b1    ;
    else
        cache_cpu_valid <=  1'b0    ;
end
    
endmodule


// module IFU_RAM(
//     input   wire            clock   ,
//     input   wire            reset   ,

//     // AR Channel
//     input   wire    [31:0]  araddr  ,
//     input   wire            arvalid ,
//     output  reg             arready ,

//     // R Channel
//     output  reg     [31:0]  rdata   ,
//     output  wire    [1:0]   rresp   ,
//     output  reg             rvalid  ,
//     input   wire            rready  
// );

// wire    [3:0]   lfsr_out        ;
// reg     [3:0]   lfsr_cnt        ;
// reg             lfsr_shifting   ;
// wire            delay_done      ;

// reg     [31:0]  araddr_r        ;
// wire            ar_handshake    ;
// wire            r_handshake     ;

// assign  delay_done      =   (lfsr_cnt    ==  lfsr_out);

// assign  ar_handshake    =   arvalid &&  arready ;
// assign  r_handshake     =   rvalid  &&  rready  ;

// lfsr_4bit   lfsr_4bit   (
//     .clock      (clock          ),
//     .reset      (reset          ),
//     .enable     (r_handshake    ),
//     .lfsr_out   (lfsr_out       )
// );

// import "DPI-C" function int inst_fetch(int pc);

// always @(posedge clock ) begin
//     if(delay_done)
//         rdata    <=  inst_fetch(araddr_r);
// end

// // always @(posedge clock ) begin
// //     if(ar_handshake)
// //         rdata    <=  inst_fetch(araddr);
// // end

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

// // always @(posedge clock ) begin
// //     if(reset)
// //         rvalid  <=  1'b0;
// //     else if(ar_handshake)
// //         rvalid  <=  1'b1;
// //     else if(r_handshake)
// //         rvalid  <=  1'b0;
// // end

// endmodule
