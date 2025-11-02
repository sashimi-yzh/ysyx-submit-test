`define ysyx_23060229_N 2
`define ysyx_23060229_M 3
`define ysyx_23060229_RESET_PC 32'h80000000

//-----------------------------------------II3:icache-----------------------------------------//
//在icache中offset不对齐不会报错
module ysyx_23060229_icache(
    input clk,
    input rst,//用于fencei的冲刷,并不是全局reset信号
    input wen,
    input [`ysyx_23060229_N-1:0] index,
    input [`ysyx_23060229_M-1:0] offset,
    inout valid_data,
    inout [31-`ysyx_23060229_M-`ysyx_23060229_N:0] tag_data,
    inout [31:0] data_data
);

    //parameter M = 3;//块大小为2^M = 8, 2 insts
    //parameter N = 2;//块数量为2^N = 4

    localparam block_size = (1 << `ysyx_23060229_M);
    localparam inst_num = (block_size >> 2);
    localparam block_num  = (1 << `ysyx_23060229_N);

    reg                         valid   [0:block_num-1];//用于存放每一个cache块的valid
    reg[31-`ysyx_23060229_M-`ysyx_23060229_N:0]             tag     [0:block_num-1];//用于存放每一个cache块的tag
    reg[31:0]                   data    [0:(block_num << (`ysyx_23060229_M-2))-1];//块大小为2^M,可以存放的指令数为2^M/4 = 2^(M-2)


    /* verilator lint_off WIDTHEXPAND */
    /* verilator lint_off WIDTHTRUNC */
    //这里要根据实际情况改动,延拓(M-2)个0
    wire [`ysyx_23060229_N+`ysyx_23060229_M-3:0] index_expanded = index;
    wire [`ysyx_23060229_N+`ysyx_23060229_M-3:0] n = (index_expanded << (`ysyx_23060229_M-2)) + (offset >> 2);

    integer i;

    always @(posedge clk) begin
        if(rst) begin
            for(i = 0; i < block_num; i = i + 1)
                valid[i] = 0;
        end

        else if(wen) begin
            valid[index] <= valid_data;
            tag[index] <= tag_data;
            data[n] <= data_data;//inst_num * index + offset / 4
        end
    end

    assign valid_data = (wen | rst)? 1'bz : valid[index];
    assign tag_data = (wen | rst) ? 32'bz : tag[index];
    assign data_data = (wen | rst) ? 32'bz : data[n];

endmodule
/* verilator lint_on WIDTHTRUNC */
/* verilator lint_on WIDTHEXPAND */
//-----------------------------------------end-of-icache-----------------------------------------//







//-----------------------------------------III2:IFU-----------------------------------------//
//采用icache后的IFU,IFU和icacheCtl合并后版本
module foo(
    input clock,
    input reset,
    input check_quest,
    input stall_quest_fencei,
    input [31:0] pc_jump,
    output reg check_assert,

    input stall_quest_exception_IFU,
    input [31:0] mtvec,

    input readyFromIDU,
    output validToIDU,

    output reg[31:0] pc,
    output reg[31:0] inst,

    //axi总线组1
    output [31:0] araddr,//本质为pc
    output arvalid,
    input arready,
    output [3:0] arid,
    output [7:0] arlen,
    output [2:0] arsize,
    output [1:0] arburst,

    //axi总线组2
    input [31:0] rdata,
    input [1:0] rresp,
    input rvalid,
    output rready,
    input rlast,
    input [3:0] rid,

    output rmem_quest

);

    localparam block_size = (1 << `ysyx_23060229_M);
    localparam block_num  = (1 << `ysyx_23060229_N);

    reg [`ysyx_23060229_M-1:0] tmp_offset;


    reg wen;

    wire valid = wen ? 1'b1 : 1'bz;
    //此处只要cache配置确定即可确定`bz位宽度
    /* verilator lint_off WIDTHTRUNC */
    wire [31-`ysyx_23060229_M-`ysyx_23060229_N:0] tag = wen ? araddr[31:`ysyx_23060229_M+`ysyx_23060229_N] : 27'bz;
    /* verilator lint_on WIDTHTRUNC */
    wire [31:0] data = wen ? rdata : 32'bz;

    wire [`ysyx_23060229_N-1:0] index = wen ? araddr[`ysyx_23060229_M+`ysyx_23060229_N-1:`ysyx_23060229_M] :
                                        pc[`ysyx_23060229_M+`ysyx_23060229_N-1:`ysyx_23060229_M];
    wire [`ysyx_23060229_M-1:0] offset = wen ? tmp_offset : pc[`ysyx_23060229_M-1:0];

    wire hit = ((tag === pc[31:`ysyx_23060229_M+`ysyx_23060229_N]) & valid);

    ysyx_23060229_icache myicache (clock, stall_quest_fencei, wen, index, offset, valid, tag, data);


    reg to_reset;

    parameter   Idle = 2'b00,
                Wait_Rvalid = 2'b01,
                Wait_IDU_Ready = 2'b10;

    reg [1:0] state;

    wire wrong_pred = (check_quest & (pc != pc_jump));

    //在第一个状态(Idle)上做好AXI4通信准备
    assign araddr = ((pc >> `ysyx_23060229_M) << `ysyx_23060229_M);
    assign arid = 1;
    assign arlen = (1 << (`ysyx_23060229_M - 2)) - 1;
    assign arsize = 3'b010;
    assign arburst = 2'b01;
    assign rready = (state == Idle & ~hit & ~stall_quest_fencei & ~reset) || (state == Wait_Rvalid);
    assign arvalid = (state == Idle) & (~stall_quest_fencei) & ~reset;

    //branch prediction
    wire [31:0] imm_branch = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
    wire [31:0] imm_jal = {{11{inst[31]}},inst[31],inst[19:12],inst[20],inst[30:21],1'b0};
    wire is_branch = (inst[6:0] == 7'b1100011);
    wire is_jal = (inst[6:0] == 7'b1101111);
    wire pred_jump = inst[31];//backward taken forward not taken
    wire [31:0] op = (is_branch & pred_jump) ? imm_branch :
                    (is_jal) ? imm_jal : 4;

    always @(posedge clock) begin
        if(reset) begin
            state <= Idle;
            pc <= `ysyx_23060229_RESET_PC; //inst <= 0;
            wen <= 0; tmp_offset <= 0;
            to_reset <= 0;
        end

        else begin
            if(stall_quest_exception_IFU) begin
                to_reset <= 1;
            end
            case(state)
                Idle: begin/*
                    check_assert <= 0;
                    if(~stall_quest_fencei) begin//确保未发生icache冲刷
                        if(hit) begin//击中
                            inst <= data;
                            state <= Wait_IDU_Ready;
                        end
                        else begin//未击中,准备访存
                            if(arready) begin
                                state <= Wait_Rvalid;
                                wen <= 1;
                            end
                        end
                    end*/
                end


                Wait_Rvalid: begin/*
                    if(rvalid && rresp == 0 && rlast == 0 && rid == arid) begin
                        tmp_offset <= tmp_offset + 4;//持续向icache进行写入
                        if(tmp_offset == pc[`ysyx_23060229_M-1:0])//同时获取可能传给ifu的inst
                            inst <= rdata;
                    end
                    if(rvalid && rresp == 0 && rlast && rid == arid) begin
                        state <= Wait_IDU_Ready; wen <= 0;
                        tmp_offset <= 0;//最后一次向icache进行写入
                        if(tmp_offset == pc[`ysyx_23060229_M-1:0])
                            inst <= rdata;
                    end*/
                end

                Wait_IDU_Ready: begin/*
                    if(readyFromIDU) begin
                        if(to_reset) begin//所有类型异常汇聚于此
                            pc <= mtvec; to_reset <= 0; wen <= 0; inst <= 0;
                        end
                        else if(wrong_pred) begin//实际上下游IDU未取指
                            check_assert <= 1;
                            pc <= pc_jump;
                        end
                        else begin//说明pc_previous对应的跳转指令正确预测了跳转地址
                            check_assert <= 1;
                            pc <= pc + op;
                        end
                        state <= Idle;
                    end*/
                end

                default: begin
                    state <= Idle;
                end
            endcase
        end
    end


    assign validToIDU = ((state == Wait_IDU_Ready) & ~to_reset & ~wrong_pred);
    assign rmem_quest = ((state == Idle && ~hit) || (state == Wait_Rvalid));

endmodule
//-----------------------------------------end-of-IFU---------------------------------------
