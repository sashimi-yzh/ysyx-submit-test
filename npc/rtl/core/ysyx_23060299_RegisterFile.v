module ysyx_23060299_RegisterFile #(
    parameter   ADDR_WIDTH  =   4   ,
    parameter   DATA_WIDTH  =   32  
) (
    input   wire                        clock       ,

`ifdef __ICARUS__
	output          [DATA_WIDTH-1:0]    return_value,
`endif

    input   wire    [DATA_WIDTH-1:0]    wdata       ,
    input   wire    [ADDR_WIDTH-1:0]    waddr       ,
    input   wire                        wen         ,

    input   wire    [ADDR_WIDTH-1:0]    rs1_raddr   ,
    output  wire    [DATA_WIDTH-1:0]    rs1_rdata   ,
    input   wire                        rs1_ren     ,

    input   wire    [ADDR_WIDTH-1:0]    rs2_raddr   ,
    output  wire    [DATA_WIDTH-1:0]    rs2_rdata   ,
    input   wire                        rs2_ren     
);

reg [DATA_WIDTH -   1:  0]  reg_files   [2**ADDR_WIDTH  -   1:  1]  ;

wire    rs1_RAW_hazard  ;
wire    rs2_RAW_hazard  ;

assign  rs1_RAW_hazard  =   wen &&  (rs1_raddr  ==  waddr)  &&  (waddr  !=  0)  ;
assign  rs2_RAW_hazard  =   wen &&  (rs2_raddr  ==  waddr)  &&  (waddr  !=  0)  ;

always @(posedge clock) begin
    if(wen)
        reg_files[waddr]    <=  wdata   ;
end

assign  rs1_rdata   =   ({32{rs1_ren    &&  !rs1_RAW_hazard &&  (rs1_raddr  !=  0)}}    &   reg_files[rs1_raddr]  )   |
                        ({32{rs1_ren    &&   rs1_RAW_hazard &&  (rs1_raddr  !=  0)}}    &   wdata                 )   |
                        32'd0   ;

assign  rs2_rdata   =   ({32{rs2_ren    &&  !rs2_RAW_hazard &&  (rs2_raddr  !=  0)}}    &   reg_files[rs2_raddr]  )   |
                        ({32{rs2_ren    &&   rs2_RAW_hazard &&  (rs2_raddr  !=  0)}}    &   wdata                 )   |
                        32'd0   ;

`ifdef __ICARUS__
	assign return_value = reg_files[10];
`endif
    
endmodule


