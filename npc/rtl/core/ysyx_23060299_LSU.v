`include "../include/ysyx_23060299_npc_defines.v"

module ysyx_23060299_LSU (
    input   wire            clock           ,
    input   wire            reset           ,

    // from EXU
    input   wire                                wr_en_lsu       ,
    input   wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0]     rd_idx_lsu      ,
    input   wire                                lw_lsu          ,
    input   wire                                lbu_lsu         ,
    input   wire                                lb_lsu          ,
    input   wire                                lh_lsu          ,
    input   wire                                lhu_lsu         ,
    input   wire                                sw_lsu          ,
    input   wire                                sh_lsu          ,
    input   wire                                sb_lsu          ,
    input   wire    [31:0]                      exu_result      ,
    input   wire    [31:0]                      rs2_lsu         ,
    input   wire                                idexu_valid     ,
    output  wire                                lsu_ready       ,

    // to LSU-RAM
    output  reg             lsu_awvalid     , 
    input   wire            lsu_awready     , 
    output  reg     [31:0]  lsu_awaddr      , 
    output  reg     [2:0]   lsu_awsize      ,
    output  reg             lsu_wvalid      , 
    input   wire            lsu_wready      , 
    output  reg     [31:0]  lsu_wdata       ,
    output  reg     [3:0]   lsu_wstrb       , 
    input   wire    [1:0]   lsu_bresp       , 
    input   wire            lsu_bvalid      , 
    output  reg             lsu_bready      , 
    output  reg             lsu_arvalid     , 
    input   wire            lsu_arready     , 
    output  reg     [31:0]  lsu_araddr      /* verilator public_flat_rd */,
    output  reg     [2:0]   lsu_arsize      , 
    input   wire    [31:0]  lsu_rdata       ,
    input   wire    [1:0]   lsu_rresp       , 
    input   wire            lsu_rvalid      , 
    output  reg             lsu_rready      , 

    // to WBU
    output  reg     [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rd_idx_wbu      ,
    output  reg                             wr_en_wbu       ,
    output  reg     [31:0]                  load_result     ,
    output  wire                            load_inst_wbu   ,
    output  reg     [31:0]                  exu_result_wbu  ,
    output  reg                             lsu_valid       ,
    input   wire                            wbu_ready       ,

    // to EXU for Data Hazard
    output  wire            lsu_rhandshake_d1   

`ifdef ysyx_23060299_verilator_env  
    // signal to debug, can be removed
    ,input   wire    [31:0]  pc_LSU          
    ,output  reg     [31:0]  pc_WBU          
 `endif
);

wire    exu_lsu_handshake   ;
wire    lsu_wbu_handshake   ;

wire    ar_handshake        ;
wire    r_handshake         ;
reg     r_handshake_r       ;
wire    aw_handshake        ;
wire    w_handshake         ;
wire    b_handshake         ;

reg     [3:0]   wmask   ;

wire    [31:0]  lw_result       ;
wire    [15:0]  lh_result       ;
wire    [7:0]   lbu_result      ;
wire    [7:0]   lb_result       ;
wire    [15:0]  lhu_result      ;
wire    [31:0]  load_result_w   ;

reg     [1:0]   lsu_araddr_l2b  ;
wire    [1:0]   lsu_awaddr_l2b  ;

wire            load_inst   /* verilator public_flat_rd */;
reg             load_inst_r     ;
wire            store_inst      ;
reg             store_inst_r    ;

reg             lw_r      ;
reg             lbu_r     ;
reg             lb_r      ;
reg             lh_r      ;
reg             lhu_r     ;

reg             lsu_ready_r ;

assign  exu_lsu_handshake   =   idexu_valid   &&  lsu_ready   ;
assign  lsu_wbu_handshake   =   lsu_valid   &&  wbu_ready   ;

always @(posedge clock ) begin
    if(reset)
        lsu_ready_r   <=  1'b1    ;
    else if(idexu_valid && (store_inst ||  load_inst))
        lsu_ready_r   <=  1'b0    ;
    else if((store_inst_r   &&  b_handshake)    ||  (load_inst_r    &&  r_handshake_r   ))
        lsu_ready_r   <=  1'b1    ;
end

assign  lsu_ready           =   (store_inst_r   &&  b_handshake     )   ||
                                (load_inst_r    &&  r_handshake_r   )   || 
                                (!store_inst_r  && !load_inst_r     )   ||
                                lsu_ready_r ;

assign  ar_handshake        =   lsu_arvalid &&  lsu_arready ;
assign  r_handshake         =   lsu_rvalid  &&  lsu_rready  ;
assign  aw_handshake        =   lsu_awvalid &&  lsu_awready ;
assign  w_handshake         =   lsu_wvalid  &&  lsu_wready  ;
assign  b_handshake         =   lsu_bvalid  &&  lsu_bready  ;

always @(posedge clock ) begin
    if(reset)
        r_handshake_r   <=  1'b0    ;
    else
        r_handshake_r   <=  r_handshake ;
end

always @(posedge clock ) begin
    if(reset)
        lsu_valid   <=  'd0 ;
    else if(r_handshake ||  (exu_lsu_handshake  &&  !load_inst))
        lsu_valid   <=  'd1 ;
    else if(lsu_wbu_handshake)
        lsu_valid   <=  'd0 ;
end

always @(posedge clock ) begin
    if(reset) begin
        load_inst_r     <=  'd0 ;
        store_inst_r    <=  'd0 ;
        lw_r            <=  'd0 ;
        lbu_r           <=  'd0 ;
        lb_r            <=  'd0 ;
        lh_r            <=  'd0 ;
        lhu_r           <=  'd0 ;
        wr_en_wbu       <=  'd0 ;
    end
    else if(exu_lsu_handshake) begin
        load_inst_r     <=  load_inst   ;
        store_inst_r    <=  store_inst  ;
        lw_r            <=  lw_lsu      ;
        lbu_r           <=  lbu_lsu     ;
        lb_r            <=  lb_lsu      ;
        lh_r            <=  lh_lsu      ;
        lhu_r           <=  lhu_lsu     ;
        wr_en_wbu       <=  wr_en_lsu   ;
        rd_idx_wbu      <=  rd_idx_lsu  ;
    end
end

assign  load_inst_wbu   =   load_inst_r ;

always @(posedge clock ) begin
    if(reset)
        lsu_awvalid <=  'd0 ;
    else if(exu_lsu_handshake    &&  store_inst)
        lsu_awvalid <=  'd1 ;
    else if(lsu_awvalid &&  lsu_awready)
        lsu_awvalid <=  'd0 ;
end

always @(posedge clock ) begin
    if(exu_lsu_handshake    &&  store_inst) begin
        if(sb_lsu)
            lsu_awsize  <=  3'b000  ;
        else if(sh_lsu)
            lsu_awsize  <=  3'b001  ;
        else if(sw_lsu)
            lsu_awsize  <=  3'b010  ;
    end
end

always @(posedge clock ) begin
    if(exu_lsu_handshake    &&  store_inst)
        lsu_awaddr  <=  exu_result  ;
end

assign  lsu_awaddr_l2b  =   exu_result[1:0] ;

always @(posedge clock ) begin
    if(exu_lsu_handshake    &&  store_inst) begin
        case (lsu_awaddr_l2b)
            2'b00:  lsu_wdata    <=  rs2_lsu ;
            2'b01:  lsu_wdata    <=  (rs2_lsu    <<  8  ) ;
            2'b10:  lsu_wdata    <=  (rs2_lsu    <<  16 ) ;
            2'b11:  lsu_wdata    <=  (rs2_lsu    <<  24 ) ;
            // default: lsu_wdata    <=  rs2_lsu ;
        endcase
    end
end

always @(posedge clock ) begin
    if(reset)
        lsu_wvalid  <=  'd0 ;
    else if(exu_lsu_handshake    &&  store_inst)
        lsu_wvalid  <=  'd1 ;
    else if(w_handshake)
        lsu_wvalid  <=  'd0 ;
end

always @(posedge clock ) begin
    if(exu_lsu_handshake    &&  store_inst)
        lsu_wstrb   <=  wmask   ;
end

always @(posedge clock ) begin
    if(reset)
        lsu_bready  <=  'd0 ;
    else if(w_handshake)
        lsu_bready  <=  'd1 ;
    else if(lsu_bready  &&  lsu_bvalid  &&  (lsu_bresp  ==  2'b00))
        lsu_bready  <=  'd0 ;
end

always @(posedge clock ) begin
    if(reset)
        lsu_arvalid <=  'd0 ;
    else if(exu_lsu_handshake    &&  load_inst)
        lsu_arvalid <=  'd1 ;
    else if(ar_handshake)
        lsu_arvalid <=  'd0 ;
end

always @(posedge clock ) begin
    if(exu_lsu_handshake    &&  load_inst) begin
        if(lb_lsu   ||  lbu_lsu)
            lsu_arsize  <=  3'b000  ;
        else if(lh_lsu  ||  lhu_lsu)
            lsu_arsize  <=  3'b001  ;
        else if(lw_lsu)
            lsu_arsize  <=  3'b010  ;
    end
end

always @(posedge clock ) begin
    if(exu_lsu_handshake    &&  load_inst)
        lsu_araddr  <=  exu_result  ;
end

always @(posedge clock ) begin
    if(ar_handshake)
        lsu_araddr_l2b  <=  lsu_araddr[1:0]  ;
end

always @(posedge clock ) begin
    if(reset)
        lsu_rready  <=  'd0 ;
    else if(exu_lsu_handshake    &&  load_inst)
        lsu_rready  <=  'd1 ;
    else if(r_handshake)
        lsu_rready  <=  'd0 ;
end

assign  load_inst   =   lw_lsu  ||  lbu_lsu ||  lb_lsu  ||  lh_lsu  ||  lhu_lsu ;
assign  store_inst  =   sw_lsu  ||  sh_lsu  ||  sb_lsu  ;

always @(*) begin
    if(sw_lsu)
        wmask   =  4'b1111 ;
    else if(sh_lsu) begin
        if(lsu_awaddr_l2b  ==  2'b00)
            wmask   =  4'b0011 ;
        else if(lsu_awaddr_l2b  ==  2'b10)
            wmask   =  4'b1100 ;
        else
            wmask   =  4'b0000 ;
    end
    else if(sb_lsu) begin
        case (lsu_awaddr_l2b)
            2'b00:  wmask   =  4'b0001 ;
            2'b01:  wmask   =  4'b0010 ;
            2'b10:  wmask   =  4'b0100 ;
            2'b11:  wmask   =  4'b1000 ;
            // default: wmask  =  4'b0000 ;
        endcase
    end
    else
        wmask  =  4'b0000 ;
end

assign  lw_result   =   lsu_rdata;
assign  lbu_result  =   ({8{(lsu_araddr_l2b  ==  2'b00)}}    &   lsu_rdata[7:0]     )
                    |   ({8{(lsu_araddr_l2b  ==  2'b01)}}    &   lsu_rdata[15:8]    )
                    |   ({8{(lsu_araddr_l2b  ==  2'b10)}}    &   lsu_rdata[23:16]   )
                    |   ({8{(lsu_araddr_l2b  ==  2'b11)}}    &   lsu_rdata[31:24]   )
                    ;
assign  lb_result   =   lbu_result  ;
assign  lhu_result  =   ({16{(lsu_araddr_l2b  ==  2'b00)}}    &   lsu_rdata[15:0]    )
                    |   ({16{(lsu_araddr_l2b  ==  2'b10)}}    &   lsu_rdata[31:16]   )
                    |   16'd0   ;
assign  lh_result   =   lhu_result  ;

assign  load_result_w   =   ({32{lw_r   }}  &   lw_result           )
                        |   ({32{lbu_r  }}  &   {24'b0, lbu_result} )
                        |   ({32{lb_r   }}  &   {{24{lb_result[7]   }}, lb_result } )
                        |   ({32{lh_r   }}  &   {{16{lh_result[15]  }}, lh_result } )
                        |   ({32{lhu_r  }}  &   {16'b0, lhu_result} )
                        |   32'd0   ;

assign  lsu_rhandshake_d1  =   r_handshake_r    ;

always @(posedge clock ) begin
    if(r_handshake)
        load_result <=  load_result_w   ;
end

always @(posedge clock ) begin
    if(exu_lsu_handshake)
        exu_result_wbu    <=  exu_result  ;
end

`ifdef ysyx_23060299_verilator_env

always @(posedge clock ) begin
    if(exu_lsu_handshake)
        pc_WBU  <=  pc_LSU  ;
end

// `ifdef ysyx_23060299_verilator_env  

// // for verilator
// // yosys-sta need to mask

// import "DPI-C" function void lsu_lw();

// always @(posedge clock ) begin
//     if(r_handshake)
//         lsu_lw();
// end

// `endif

`ifdef ysyx_23060299_PO  

reg [31:0]  lsu_cyc ;

import "DPI-C" function void lsu_addCyc(int lsu_cyc);
import "DPI-C" function void lsu_addTimes();

always @(posedge clock ) begin
    if(reset)
        lsu_cyc <=  'd0 ;
    else if(ar_handshake) begin
        lsu_cyc <=  'd0 ;
        lsu_addTimes();
    end
    else if(r_handshake)
        lsu_addCyc(lsu_cyc);
    else
        lsu_cyc <=  lsu_cyc + 1'b1 ;
end

`endif
`endif

endmodule
