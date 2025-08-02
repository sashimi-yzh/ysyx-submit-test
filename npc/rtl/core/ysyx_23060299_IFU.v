`include "../include/ysyx_23060299_npc_defines.v"

module ysyx_23060299_IFU (
    input   wire            clock       ,
    input   wire            reset       ,

    ///   ----  IFU CACHE   ----  ///
    output  wire    [31:0]  cpu_cache_addr  ,
    output  wire            cpu_cache_valid ,
    input   wire    [31:0]  cache_cpu_data  ,
    input   wire            cache_cpu_ready ,
    input   wire            cache_cpu_valid , 
    output  reg             cache_mask      ,
    output  wire            fence_i         ,
    ///   ----  IFU CACHE   ----  ///

    // from IDEXU
    input   wire            need_jump_ifu   ,
    input   wire            branch_inst_ifu ,
    input   wire    [31:0]  pc_jump         ,
    input   wire            jump_inst       ,

    // to IDU
    output  reg     [31:0]  inst_idu        ,
    output  reg     [31:0]  pc_IDEXU        ,
    output  wire            ifu_valid       ,
    input   wire            idexu_ready     
   
);

reg     [31:0]      pc              ;
reg     [31:0]      pc_BPU          ;

wire                cache_mask_en       ;
wire                cache_handshake     ;
reg                 predict_cache_handshake ;

reg                 ifu_valid_r             ;
wire                ifu_idexu_handshake     ;

reg     [31:0]      inst_idu_r      ;

wire                store_pc_inst   ;
reg                 store_pc_inst_r ;

// branch logic 
wire                stall_ifetch        ;
wire    [31:0]      pc_predict          ;
wire                predict_taken       ;
wire                predict_wrong       ;
reg                 predict_wrong_d1    ;

wire                branch_inst         ;
reg                 already_predict     ;

assign  cache_handshake =   cpu_cache_valid &&  cache_cpu_ready ;

assign  ifu_idexu_handshake   =   ifu_valid   &&  idexu_ready   ;

assign  store_pc_inst   =   (ifu_valid   &&  !idexu_ready) ;

assign  cpu_cache_addr  = pc    ;

assign  cpu_cache_valid =   (
                                !stall_ifetch                           //  没有停顿  jal jalr
                            &&  !store_pc_inst_r                        //  没有存储的指令
                            &&  !(branch_inst   &&  predict_taken)      //  没有预测为跳的分支
                            &&  !(branch_inst   &&  branch_inst)        //  没有连续的分支指令
                            &&  !predict_wrong                          //  没有预测错误
                            ) ?   idexu_ready   :   1'b0    ;     

assign  cache_mask_en   =   predict_wrong   &&  already_predict &&  predict_cache_handshake ;   // 1 预测 2 预测后cache握手 3预测错误 ----> mask cache

always @(posedge clock ) begin
    if(reset)
        cache_mask    <=  1'b0    ;
    else if(cache_mask_en)
        cache_mask    <=  1'b1    ;
    else if(cache_mask    &&  cache_cpu_ready)
        cache_mask    <=  1'b0    ;
end

always @(posedge clock) begin
    if(reset)
        pc  <=  `ysyx_23060299_RESET_PC   ;
    else if(need_jump_ifu   &&  !branch_inst_ifu)  // jal jalr ecall mret
        pc  <=  pc_jump ;
    else if(need_jump_ifu   &&  predict_wrong)  // 预测不跳 实际跳转错误
        pc  <=  pc_jump ;
    else if(predict_taken   &&  !predict_wrong_d1)  // 防止预测后跳转的指令后马上出现跳转指令导致的错误
        pc  <=  pc_predict ;
    else if(!need_jump_ifu  &&  predict_wrong)  // 预测跳转 实际不跳错误
        pc  <=  pc_IDEXU    +   4   ;
    else if(cache_handshake)
        pc  <=  pc  + 4 ;
end

always @(posedge clock ) begin
    if(cache_handshake)
        pc_BPU      <=  pc      ;
end

always @(posedge clock ) begin
    if(cache_cpu_valid  &&  !store_pc_inst)
        pc_IDEXU    <=  pc_BPU  ;
    else if(ifu_idexu_handshake &&  store_pc_inst_r)
        pc_IDEXU    <=  pc_BPU  ;
end

always @(posedge clock ) begin
    if(cache_cpu_valid  &&  store_pc_inst)
        inst_idu_r <=   cache_cpu_data  ;
end

always @(posedge clock ) begin
    if(cache_cpu_valid  &&  !store_pc_inst)
        inst_idu    <=  cache_cpu_data  ;
    else if(ifu_idexu_handshake &&  store_pc_inst_r)
        inst_idu    <=  inst_idu_r  ;
end

always @(posedge clock ) begin
    if(reset)
        ifu_valid_r   <=  1'b0    ;
    else if(predict_wrong   ||  predict_wrong_d1)   // 冲刷两个周期
        ifu_valid_r   <=  1'b0    ;
    else if((cache_cpu_valid ||  store_pc_inst_r)   &&  !cache_mask)
        ifu_valid_r   <=  1'b1    ;
    else if(!cache_cpu_valid    &&  ifu_idexu_handshake)
        ifu_valid_r   <=  1'b0    ;
end

assign  ifu_valid   =   ifu_valid_r &&  !predict_wrong  ;

always @(posedge clock ) begin
    predict_wrong_d1    <=  predict_wrong   ;   // 无效化预测失败后取得的废指令
end

always @(posedge clock ) begin
    if(reset)
        already_predict <=  1'b0    ;
    else if(branch_inst_ifu && branch_inst) // 应对连续的分支指令
        already_predict <=  1'b1    ;
    else if(branch_inst_ifu)
        already_predict <=  1'b0    ;
    else if(branch_inst &&  !predict_wrong_d1)
        already_predict <=  1'b1    ;
end

always @(posedge clock ) begin
    if(reset)
        predict_cache_handshake <=  1'b0    ;
    else if(branch_inst_ifu)
        predict_cache_handshake <=  1'b0    ;
    else if((branch_inst ||  already_predict)   &&  cache_handshake &&  !predict_wrong_d1)
        predict_cache_handshake <=  1'b1    ;
end

always @(posedge clock ) begin
    if(reset)
        store_pc_inst_r <=  1'b0    ;
    else if(cache_cpu_valid  &&  store_pc_inst)
        store_pc_inst_r <=  1'b1    ;
    else if(ifu_idexu_handshake &&  store_pc_inst_r)
        store_pc_inst_r <=  1'b0    ;
end

ysyx_23060299_BPU BPU(
    .clock              (clock              ),
    .reset              (reset              ),

    .cache_cpu_data     (cache_cpu_data     ),
    .cache_cpu_valid    (cache_cpu_valid    ),
    .pc_BPU             (pc_BPU             ),
    .need_jump_ifu      (need_jump_ifu      ),
    .branch_inst_ifu    (branch_inst_ifu    ),
    .cache_mask         (cache_mask         ),
    .cache_mask_en      (cache_mask_en      ),

    .stall_ifetch       (stall_ifetch       ),
    .branch_inst        (branch_inst        ),
    .pc_predict         (pc_predict         ),
    .predict_taken      (predict_taken      ),
    .predict_wrong      (predict_wrong      ),

    .fence_i            (fence_i            )     
);

`ifdef ysyx_23060299_PO  

reg [31:0]  ifu_cyc ;

import "DPI-C" function void ifu_addCyc(int ifu_cyc);

always @(posedge clock ) begin
    if(reset)
        ifu_cyc <=  'd0 ;
    else if(cache_handshake)
        ifu_cyc <=  'd0 ;
    else if(cache_cpu_valid)
        ifu_addCyc(ifu_cyc);
    else
        ifu_cyc <=  ifu_cyc + 1'b1 ;
end


`endif

endmodule
