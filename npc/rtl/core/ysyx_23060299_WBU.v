module ysyx_23060299_WBU (
    input   wire            clock           ,
    input   wire            reset           ,

    // from LSU
    input   wire                            wr_en_wbu       ,
    input   wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rd_idx_wbu      ,
    input   wire    [31:0]                  load_result     ,
    input   wire                            load_inst       ,
    input   wire    [31:0]                  exu_result_r    ,
    input   wire                            lsu_valid       ,
    output  wire                            wbu_ready       ,

    // to Reg
    output  wire    [31:0]                  wbu_result      ,
    output  wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rd_idx          ,
    output  wire                            reg_wren        

`ifdef ysyx_23060299_verilator_env 
    // signal to debug, can be removed
    ,
    input   wire    [31:0]  pc_WBU   
`endif             
);

wire    lsu_wbu_handshake   ;

assign  lsu_wbu_handshake   =   lsu_valid   &&  wbu_ready   ;

assign  wbu_ready   =   1'b1;

assign  reg_wren    =   (lsu_wbu_handshake  &&  !reset)   ?   wr_en_wbu   :   1'b0;

assign  wbu_result  =   load_inst   ?   load_result :   exu_result_r  ;

assign  rd_idx      =   rd_idx_wbu  ;

`ifdef ysyx_23060299_verilator_env 

reg         inst_commit     ;
reg [31:0]  pc_commit       ;
reg [31:0]  commit_counter  ;
reg         load_inst_diff  ;

always @(posedge clock ) begin
    if(reset)
        inst_commit <=  1'b0    ;
    else if(lsu_wbu_handshake)
        inst_commit <=  1'b1    ;
    else
        inst_commit <=  1'b0    ;
end

always @(posedge clock ) begin
    if(reset)
        commit_counter <=   'd0 ;
    else if(lsu_wbu_handshake)
        commit_counter <=   commit_counter  +   1;
end

always @(posedge clock ) begin
    if(lsu_wbu_handshake) begin
        pc_commit       <=  pc_WBU  ;
        load_inst_diff  <=  load_inst   ;
    end
end

`endif 

endmodule
