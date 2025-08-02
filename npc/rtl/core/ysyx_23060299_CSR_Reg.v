module ysyx_23060299_CSR_Reg(
    input   wire            clock       ,
    input   wire    [31:0]  csr_wdata   ,
    input   wire    [11:0]  csr_waddr   ,
    input   wire            csr_wen     ,
    output  reg     [31:0]  csr_rdata   ,
    input   wire    [11:0]  csr_raddr   ,
    input   wire            csr_ren     ,

    input   wire    [31:0]  pc          ,
    input   wire            ecall       ,
    input   wire            mret        
);

reg     [31:0]  mcause  ;
reg     [29:0]  mepc    ;
reg     [31:0]  mstatus ;
reg     [29:0]  mtvec   ;
wire    [31:0]  mvendorid   ;
wire    [31:0]  marchid     ;

assign  mvendorid   =   32'h79737978    ;
assign  marchid     =   32'h015FDF4B    ;

// write
always @(posedge clock ) begin
    if(ecall)
        mcause  <=  32'd11;
    else if(csr_wen && (csr_waddr == 12'h342))
        mcause  <=  csr_wdata;
end

always @(posedge clock ) begin
    if(ecall)
        mepc  <=  pc[31:2];
    else if(csr_wen && (csr_waddr == 12'h341))
        mepc  <=  csr_wdata[31:2];
end

always @(posedge clock ) begin
    if(ecall)
        mstatus  <=  32'h1800;
    else if(csr_wen && (csr_waddr == 12'h300))
        mstatus  <=  csr_wdata;
end

always @(posedge clock ) begin
    if(csr_wen && (csr_waddr == 12'h305))
        mtvec  <=  csr_wdata[31:2];
end

// read
always @(*) begin
    if(csr_ren)
        case (csr_raddr)
            12'hF11:    csr_rdata   =  mvendorid        ;
            12'hF12:    csr_rdata   =  marchid          ; 
            12'h342:    csr_rdata   =  mcause           ;
            12'h341:    csr_rdata   =  {mepc, 2'b0}     ;    
            12'h300:    csr_rdata   =  mstatus          ;    
            12'h305:    csr_rdata   =  {mtvec, 2'b0}    ;
            default:    csr_rdata   =  'd0              ;
        endcase
    else if(ecall)
        csr_rdata   =  {mtvec, 2'b0}    ;
    else if(mret)
        csr_rdata   =  {mepc, 2'b0} ;
    else
        csr_rdata   =  'd0  ;
end

endmodule
