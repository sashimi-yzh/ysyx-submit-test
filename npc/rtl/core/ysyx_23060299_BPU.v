module ysyx_23060299_BPU (
    input   wire            clock           ,
    input   wire            reset           ,

    input   wire    [31:0]  cache_cpu_data  ,
    input   wire            cache_cpu_valid ,
    input   wire    [31:0]  pc_BPU          ,
    input   wire            need_jump_ifu   ,
    input   wire            branch_inst_ifu ,

    input   wire            cache_mask      ,
    input   wire            cache_mask_en   ,

    output  wire            stall_ifetch    ,
    output  wire            branch_inst     ,
    output  wire    [31:0]  pc_predict      ,
    output  wire            predict_taken   ,
    output  wire            predict_wrong   ,

    output  wire            fence_i         
);

wire            jal             ;
wire            jalr            ;
wire            ecall           ;
wire            mret            ;
wire            taken           ;
wire    [2:0]   func3           ;
wire            func3_000       ;
wire            func3_001       ;
wire    [6:0]   op_code         ;
wire    [31:0]  imm_B           ;
reg             stall_ifetch_r  ;
wire            stall_ifetch_w  ;
reg             predict_taken_r ;

assign  func3           =   cache_cpu_data[14:12]                               ;
assign  func3_000       =   (func3  ==  3'b000)                                 ;
assign  func3_001       =   (func3  ==  3'b001)                                 ;
assign  op_code         =   cache_cpu_data[6:0]                                 ;
assign  jal             =   (op_code    ==  7'b1101111)                         ;
assign  jalr            =   (op_code    ==  7'b1100111) &&  func3_000           ;
assign  ecall           =   (op_code    ==  7'b1110011) &&  (cache_cpu_data[31:7] == 25'd0) ;
assign  mret            =   (op_code    ==  7'b1110011) &&  (cache_cpu_data[31:7] == 25'b0011000_00010_00000_000_00000);
assign  branch_inst     =   (op_code    ==  7'b1100011) &&  cache_cpu_valid     &&  !predict_wrong  ;
assign  fence_i         =   (op_code    ==  7'b0001111) &&  func3_001   &&  cache_cpu_valid &&  !(cache_mask    ||  cache_mask_en);

// B type inst
assign  imm_B           =   {{20{cache_cpu_data[31]}}, cache_cpu_data[7], cache_cpu_data[30:25], cache_cpu_data[11:8], 1'b0};
assign  taken           =   cache_cpu_data[31]    ;

assign  pc_predict      =   taken   ?   (pc_BPU +   imm_B)  :   'd0 ;  
assign  predict_taken   =   branch_inst &&  taken   &&  !(cache_mask    ||  cache_mask_en);
assign  stall_ifetch_w  =   (jal    ||  jalr    ||  ecall   ||  mret)   &&  cache_cpu_valid &&  !(cache_mask    ||  cache_mask_en);
assign  stall_ifetch    =   stall_ifetch_w  ||  stall_ifetch_r  ;

always @(posedge clock ) begin
    if(reset)
        stall_ifetch_r  <=  1'b0    ;
    else if(stall_ifetch_w)
        stall_ifetch_r  <=  1'b1    ;
    else if(need_jump_ifu)
        stall_ifetch_r  <=  1'b0    ;
end

always @(posedge clock ) begin
    if(reset)
        predict_taken_r <=  1'b0    ;
    else if(branch_inst)
        if(taken)
            predict_taken_r <=  1'b1    ;
        else
            predict_taken_r <=  1'b0    ;
end

assign  predict_wrong   =   branch_inst_ifu &&  (need_jump_ifu  !=  predict_taken_r)    ;


endmodule
