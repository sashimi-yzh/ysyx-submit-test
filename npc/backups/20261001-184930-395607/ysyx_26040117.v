
module ysyx_26040117 #(
    parameter [31:0] RESET_VECTOR=32'h3000_0000
)(
    input  wire         clock,
    input  wire         reset,          
    input  wire         io_interrupt,
    //Master
    input  wire         io_master_awready,
    output wire         io_master_awvalid,
    output wire [31:0]  io_master_awaddr,
    output wire [3:0]   io_master_awid,
    output wire [7:0]   io_master_awlen,
    output wire [2:0]   io_master_awsize,
    output wire [1:0]   io_master_awburst,

    input  wire         io_master_wready,
    output wire         io_master_wvalid,
    output wire [31:0]  io_master_wdata,
    output wire [3:0]   io_master_wstrb,
    output wire         io_master_wlast,

    output wire         io_master_bready,
    input  wire         io_master_bvalid,
    input  wire [1:0]   io_master_bresp,
    input  wire [3:0]   io_master_bid,

    input  wire         io_master_arready,
    output wire         io_master_arvalid,
    output wire [31:0]  io_master_araddr,
    output wire [3:0]   io_master_arid,
    output wire [7:0]   io_master_arlen,
    output wire [2:0]   io_master_arsize,
    output wire [1:0]   io_master_arburst,

    output wire         io_master_rready,
    input  wire         io_master_rvalid,
    input  wire [1:0]   io_master_rresp,
    input  wire [31:0]  io_master_rdata,
    input  wire         io_master_rlast,
    input  wire [3:0]   io_master_rid,
    //Slave
    output wire         io_slave_awready,
    input  wire         io_slave_awvalid,
    input  wire [31:0]  io_slave_awaddr,
    input  wire [3:0]   io_slave_awid,
    input  wire [7:0]   io_slave_awlen,
    input  wire [2:0]   io_slave_awsize,
    input  wire [1:0]   io_slave_awburst,

    output wire         io_slave_wready,
    input  wire         io_slave_wvalid,
    input  wire [31:0]  io_slave_wdata,
    input  wire [3:0]   io_slave_wstrb,
    input  wire         io_slave_wlast,

    input  wire         io_slave_bready,
    output wire         io_slave_bvalid,
    output wire [1:0]   io_slave_bresp,
    output wire [3:0]   io_slave_bid,

    output wire         io_slave_arready,
    input  wire         io_slave_arvalid,
    input  wire [31:0]  io_slave_araddr,
    input  wire [3:0]   io_slave_arid,
    input  wire [7:0]   io_slave_arlen,
    input  wire [2:0]   io_slave_arsize,
    input  wire [1:0]   io_slave_arburst,

    input  wire         io_slave_rready,
    output wire         io_slave_rvalid,
    output wire [1:0]   io_slave_rresp,
    output wire [31:0]  io_slave_rdata,
    output wire         io_slave_rlast,
    output wire [3:0]   io_slave_rid
);
    //Master
    wire[139:0] master_wrapper_out;
    wire[49:0] master_wrapper_in;
    assign master_wrapper_in={io_master_awready,io_master_wready,io_master_bvalid,io_master_bresp,io_master_bid,io_master_arready,
        io_master_rvalid,io_master_rresp,io_master_rdata,io_master_rlast,io_master_rid};
    assign {io_master_awvalid,io_master_awaddr,io_master_awid,io_master_awlen,io_master_awsize,io_master_awburst,
        io_master_wvalid,io_master_wdata,io_master_wstrb,io_master_wlast,io_master_bready,io_master_arvalid,
        io_master_araddr,io_master_arid,io_master_arlen,io_master_arsize,io_master_arburst,io_master_rready}=master_wrapper_out;
    //Slave
    assign io_slave_awready=1'b0;
    assign io_slave_wready=1'b0;
    assign io_slave_bvalid=1'b0;
    assign io_slave_bresp=2'b0;
    assign io_slave_bid=4'b0;
    assign io_slave_arready=1'b0;
    assign io_slave_rvalid=1'b0;
    assign io_slave_rresp=2'b0;
    assign io_slave_rdata=32'd0;
    assign io_slave_rlast=1'b0;
    assign io_slave_rid=4'b0;

    //WBU-data
    wire[31:0]trap_dnpc,redirect_dnpc;//result:ALU结果
    wire fence_i;
    wire trap_redirect_valid,exu_redirect_valid,redirect_valid;
    wire [31:0]exu_redirect_pc;
    assign redirect_valid=trap_redirect_valid||exu_redirect_valid;
    assign redirect_dnpc=trap_redirect_valid?trap_dnpc:exu_redirect_pc;
    //Instruction Fetch Unit
    wire IFU_IDU_ready,IFU_IDU_valid;
    wire[31:0]ifu_idu_pc,idu_ifu_pc;
    wire[31:0]inst;
    wire fence_done,pred_taken;
    wire WBU_IFU_ready=1;
    wire [34:0]MEM_ICACHE_wrapper;
    wire [44:0]ICACHE_MEM_wrapper;
    wire [66:0] ICACHE_IFU_wrapper;
    wire [66:0] IFU_ICACHE_wrapper;
    ysyx_26040117_IFU IFU1(
        .redirect_valid(redirect_valid),.dnpc(redirect_dnpc),.fence_i(fence_i),
        .IFU_IDU_ready(IFU_IDU_ready),.IFU_IDU_valid(IFU_IDU_valid),.inst(inst),.pc(ifu_idu_pc),.fence_done(fence_done),.pred_taken(pred_taken),
        .idu_pc(idu_ifu_pc),
        .MEM_IFU_wrapper(ICACHE_IFU_wrapper),.IFU_MEM_wrapper(IFU_ICACHE_wrapper)
    );
    wire [31:0] btb_araddr,btb_target;
    wire btb_hit;
    ysyx_26040117_ICache #(.RESET_VECTOR(RESET_VECTOR))ICache1(.clk(clock),.rst(reset),
        .IFU_ICACHE_wrapper(IFU_ICACHE_wrapper),.ICACHE_IFU_wrapper(ICACHE_IFU_wrapper),
        .MEM_ICACHE_wrapper(MEM_ICACHE_wrapper),.ICACHE_MEM_wrapper(ICACHE_MEM_wrapper),
        .btb_araddr(btb_araddr),.btb_hit(btb_hit),.btb_target(btb_target)
    );
    wire [31:0] exu_btb_waddr,exu_btb_wtarget;
    wire exu_btb_wen;
    ysyx_26040117_BTB BTB1(.clk(clock),.rst(reset),.flush(fence_i),
        .araddr(btb_araddr),.hit(btb_hit),.target(btb_target),
        .wen(exu_btb_wen),.waddr(exu_btb_waddr),.wtarget(exu_btb_wtarget)
    );
    //Instruction Decode Unit
    wire IDU_EXU_ready,IDU_EXU_valid;
    //mytype      0:lui;    1:auipc;    2:jal;  3:jalr;  4:跳转;  5:load;  6:store;  7:立即数计算;  8:寄存器计算
    wire[158:0]IDU_wrapper;
    wire[4:0] rs1,rs2;
    wire[31:0]src1,src2;
    wire [38:0] EXU_IDU_wrapper,LSU_IDU_wrapper;
    wire [37:0] WBU_IDU_wrapper;
    ysyx_26040117_IDU IDU1(.clk(clock),.rst(reset),
        .IFU_IDU_ready(IFU_IDU_ready),.IFU_IDU_valid(IFU_IDU_valid),.inst(inst),.pc(ifu_idu_pc),.fence_done(fence_done),.pred_taken(pred_taken),
        .redirect_valid(redirect_valid),.EXU_IDU_wrapper(EXU_IDU_wrapper),.LSU_IDU_wrapper(LSU_IDU_wrapper),.WBU_IDU_wrapper(WBU_IDU_wrapper),
        .pc_out(idu_ifu_pc),
        .IDU_EXU_ready(IDU_EXU_ready),.IDU_EXU_valid(IDU_EXU_valid),.IDU_wrapper(IDU_wrapper),
        .rs1(rs1),.rs2(rs2),.src1(src1),.src2(src2)
    );
    //Register block
    wire [4:0] wbu_register_rd;
    wire wbu_register_wen;
    wire [31:0] srcd;
    ysyx_26040117_RegisterFile Register1(.clk(clock),
        .raddr1(rs1[3:0]),.raddr2(rs2[3:0]),.rdata1(src1),.rdata2(src2),
        .wdata(srcd),.waddr(wbu_register_rd[3:0]),.wen(wbu_register_wen)
    );
    //Execution Unit
    wire EXU_LSU_ready,EXU_LSU_valid;
    wire [84:0]EXU_wrapper; 
    ysyx_26040117_EXU EXU1(.clk(clock),.rst(reset),
        .IDU_EXU_ready(IDU_EXU_ready),.IDU_EXU_valid(IDU_EXU_valid),.IDU_wrapper(IDU_wrapper),
        .EXU_LSU_ready(EXU_LSU_ready),.EXU_LSU_valid(EXU_LSU_valid),.EXU_wrapper(EXU_wrapper),
        .redirect_valid(exu_redirect_valid),.exu_redirect_pc(exu_redirect_pc),.EXU_IDU_wrapper(EXU_IDU_wrapper),
        .exu_btb_wen(exu_btb_wen),.exu_btb_waddr(exu_btb_waddr),.exu_btb_wtarget(exu_btb_wtarget)
    );
    //Load-Store Unit
    wire LSU_WBU_ready,LSU_WBU_valid;
    wire[51:0] LSU_wrapper;
    wire [40:0]MEM_LSU_wrapper;
    wire [110:0]LSU_MEM_wrapper;
    ysyx_26040117_LSU LSU1(.clk(clock),.rst(reset),
        .EXU_LSU_ready(EXU_LSU_ready),.EXU_LSU_valid(EXU_LSU_valid),.EXU_wrapper(EXU_wrapper),
        .LSU_WBU_ready(LSU_WBU_ready),.LSU_WBU_valid(LSU_WBU_valid),.LSU_wrapper(LSU_wrapper),
        .LSU_IDU_wrapper(LSU_IDU_wrapper),
        .MEM_LSU_wrapper(MEM_LSU_wrapper),.LSU_MEM_wrapper(LSU_MEM_wrapper)
    );
    ysyx_26040117_arbiter arbiter1(.clk(clock),.rst(reset),
        .MEM_IFU_wrapper(MEM_ICACHE_wrapper),.IFU_MEM_wrapper(ICACHE_MEM_wrapper),
        .MEM_LSU_wrapper(MEM_LSU_wrapper),.LSU_MEM_wrapper(LSU_MEM_wrapper),
        .master_wrapper_in(master_wrapper_in),.master_wrapper_out(master_wrapper_out)
    );

    //WriteBack Unit
    ysyx_26040117_WBU WBU1(.clk(clock),.rst(reset),
        .LSU_WBU_ready(LSU_WBU_ready),.LSU_WBU_valid(LSU_WBU_valid),.LSU_wrapper(LSU_wrapper),
        .WBU_IFU_ready(WBU_IFU_ready),.srcd(srcd),.fence_i(fence_i),.trap_dnpc(trap_dnpc),.trap_redirect_valid(trap_redirect_valid),.rd(wbu_register_rd),.register_wen_out(wbu_register_wen),
        .WBU_IDU_wrapper(WBU_IDU_wrapper)
    );

endmodule
module ysyx_26040117_IFU (
    redirect_valid,dnpc,fence_i,
    IFU_IDU_valid,IFU_IDU_ready,inst,pc,fence_done,idu_pc,pred_taken,
    MEM_IFU_wrapper,IFU_MEM_wrapper
);
    //WBU-IFU
    input redirect_valid;
    input[31:0]dnpc/* verilator public_flat_rd */;
    input fence_i;
    //IFU-IDU
    input IFU_IDU_ready;
    output IFU_IDU_valid;
    output [31:0]inst;
    output [31:0]pc;
    output fence_done,pred_taken;
    //IDU-IFU
    input [31:0] idu_pc;
    //IFU-MEM
    input [66:0] MEM_IFU_wrapper;
    output[66:0] IFU_MEM_wrapper;

    //state machine 
    wire rvalid,rready;
    assign rready=IFU_IDU_ready;
    assign IFU_IDU_valid=rvalid;
    //取指
    wire [31:0] rpc,rdata;
    assign IFU_MEM_wrapper={fence_i,redirect_valid,dnpc,idu_pc,rready};
    assign {pred_taken,fence_done,rvalid,rpc,rdata}=MEM_IFU_wrapper;
    assign inst=rdata;
    assign pc=rpc;
endmodule
module ysyx_26040117_ICache#(RESET_VECTOR=32'h30000000)(
    input wire clk,
    input wire rst,
    input [66:0]IFU_ICACHE_wrapper,
    output[66:0]ICACHE_IFU_wrapper,
    input [34:0]MEM_ICACHE_wrapper,
    output[44:0]ICACHE_MEM_wrapper,
    output [31:0]btb_araddr,
    input [31:0]btb_target,
    input btb_hit
);
    parameter OFFSET_WIDTH=4,INDEX_WIDTH=2;
    localparam DATA_DEPTH=2**(OFFSET_WIDTH+INDEX_WIDTH-2);
    localparam WORD_NUM=2**(OFFSET_WIDTH-2);
    localparam BURST_LEN=WORD_NUM-1;
    localparam [29:0] RESET_PC=RESET_VECTOR[31:2];
    wire arready,rready,rfire,arfire;
    reg rvalid;
    reg[31:0] rdata;
    wire [31:0] dnpc,idu_pc;
    wire[31:0] araddr_reg,araddr;
    wire fence_i,redirect_valid;
    reg flush_pending,fence_done,s1_btb_valid;
    assign rfire=rvalid&&rready;

    assign {fence_i,redirect_valid,dnpc,idu_pc,rready}=IFU_ICACHE_wrapper;
    assign ICACHE_IFU_wrapper={s1_btb_valid,fence_done,rvalid,araddr_reg,rdata};
    wire fence_clear=rst||fence_i||flush_pending||fence_done;
    wire pipe_clear=redirect_valid||fence_clear;
    localparam IDLE=0,MISS_AR=1,MISS_DATA=2;
    reg[1:0] state,next_state;
    reg[31:0] data_array[0:DATA_DEPTH-1];
    reg[31-OFFSET_WIDTH-INDEX_WIDTH:0] tag_array[0:(2**INDEX_WIDTH)-1];
    reg[DATA_DEPTH-1:0] valid_array;
    //S1-FIFO 
    reg s1_valid,s1_redirect;
    reg[29:0] s1_snpc,s1_dnpc;
    always @(posedge clk) begin
        if(redirect_valid)
            s1_dnpc<=dnpc[31:2];
        else if(btb_hit&&s1_valid&&arready)
            s1_dnpc<=btb_target[31:2];
    end
    wire[29:0] snpc_next=fence_done?idu_pc[31:2]:araddr[31:2];
    always @(posedge clk) begin
        if(rst)
            s1_snpc<=RESET_PC;
        else if(fence_done||(s1_valid&&arready))
            s1_snpc<=snpc_next+30'd1;
    end
    assign  araddr={(s1_redirect||s1_btb_valid)?s1_dnpc:s1_snpc,2'b00};
    always @(posedge clk) begin
        if(rst)
            s1_valid<=1'b1;
        else if(fence_i||flush_pending)
            s1_valid<=1'b0;
        else if(fence_done)
            s1_valid<=1'b1;
    end
    always @(posedge clk) begin
        if(fence_clear)begin
            s1_redirect<=1'b0;
        end else if(redirect_valid)begin 
            s1_redirect<=1'b1;
        end else if(arfire)begin
            s1_redirect<=1'b0;
        end
    end
    wire is_sdram =araddr[31:29]==3'b101;//SDRAM
    wire [OFFSET_WIDTH-3:0] req_offset;
    wire[INDEX_WIDTH-1:0] req_index;
    wire[31-OFFSET_WIDTH-INDEX_WIDTH:0] req_tag;
    wire hit;
    assign req_offset=araddr[OFFSET_WIDTH-1:2];
    assign req_index=araddr[OFFSET_WIDTH +: INDEX_WIDTH];
    assign req_tag=araddr[31:OFFSET_WIDTH+INDEX_WIDTH];
    wire req_tag_match=(tag_array[req_index]==req_tag)&&(|valid_array[req_index*WORD_NUM +: WORD_NUM]);
    assign hit=valid_array[{req_index,req_offset}]&&req_tag_match;
    wire arvalid=s1_valid&&!pipe_clear;
    //BTB
    assign btb_araddr=araddr;
    always @(posedge clk) begin
        if(pipe_clear)
            s1_btb_valid<=1'b0;
        else if(arfire)
            s1_btb_valid<=btb_hit;
    end
    //S2
    wire arready_MEM,arvalid_MEM,arfire_MEM;
    wire rready_MEM,rvalid_MEM,rfire_MEM,rlast;
    wire [31:0] rdata_MEM,araddr_MEM;

    reg miss_pending;
    wire out_ready=!rvalid||rready;
    assign  arready=out_ready&&((state==IDLE)||((state==MISS_DATA)&&!miss_pending&&hit));
    assign  arfire=arvalid&&arready;
    reg is_sdram_reg;
    
    wire  [OFFSET_WIDTH-3:0] offset_reg;
    reg  [OFFSET_WIDTH-3:0] offset_count;
    wire refill_data_en=rfire_MEM&&((offset_count==offset_reg)||!is_sdram_reg);
    always @(posedge clk) begin
        if(out_ready)
            rdata<=miss_pending?rdata_MEM:data_array[{req_index,req_offset}];
    end
    always @(posedge clk) begin
        if(pipe_clear)begin
            rvalid<=1'd0;
        end else begin
            if(hit&&arfire)begin 
                rvalid<=1'b1;
            end else if(refill_data_en&&miss_pending)begin
                rvalid<=1'b1;//delay rfire -fence_i
            end else if(rfire)begin
                rvalid<=1'b0;
            end
        end
    end
    //ICache

    wire[INDEX_WIDTH-1:0] index_reg;
    wire [31-OFFSET_WIDTH-INDEX_WIDTH:0] tag_reg;
    reg[29:0]araddr_word_reg;
    assign araddr_reg={araddr_word_reg,2'b00};
    reg [INDEX_WIDTH+OFFSET_WIDTH-3:0] miss_pos;
    reg req_tag_match_reg;

    assign tag_reg=araddr_reg[31:OFFSET_WIDTH+INDEX_WIDTH];
    assign {index_reg,offset_reg}=miss_pos;
    always @(posedge clk) begin
        if(s1_valid&&arready)begin 
            araddr_word_reg<=araddr[31:2];
        end
        if(s1_valid&&arready&&!hit)begin
            req_tag_match_reg<=req_tag_match;
            miss_pos<=araddr[INDEX_WIDTH+OFFSET_WIDTH-1:2];
        end
    end
    always @(posedge clk) begin
        if(pipe_clear)
            miss_pending<=1'b0;
        else if(s1_valid&&arready&&!hit)
            miss_pending<=1'b1;
        else if(refill_data_en)
            miss_pending<=1'b0;
    end
    wire [OFFSET_WIDTH-3:0] refill_offset=is_sdram_reg?offset_count:offset_reg;
    always @(posedge clk) begin
        if(rst||fence_i||flush_pending) begin
            valid_array<=0;
            is_sdram_reg<=1'b0;
        end else begin
            case(state)
                IDLE:if(s1_valid&&arready&&!hit)begin
                        is_sdram_reg<=is_sdram;
                        offset_count<=req_offset;
                end
                MISS_AR:begin
                    tag_array[index_reg]<=tag_reg;
                    if(!req_tag_match_reg)
                        valid_array[index_reg*WORD_NUM +: WORD_NUM]<=0;
                end
                MISS_DATA:if(rfire_MEM)begin
                            data_array[{index_reg,refill_offset}]<=rdata_MEM;
                            valid_array[{index_reg,refill_offset}]<=1'b1;
                            if(is_sdram_reg&&!rlast)
                                offset_count<=offset_count+1'b1;
                        end
                default:;
            endcase
        end
    end
    //state machine
    always @(posedge clk) begin
        if(rst)
            state<=IDLE;
        else 
            state<=next_state;
    end
    always @(*) begin
        next_state=state;
        case(state)
            IDLE:if(arfire&&!hit)next_state=MISS_AR;
            MISS_AR:if(arfire_MEM)next_state=MISS_DATA;
            MISS_DATA:if(rfire_MEM&&rlast)next_state=IDLE;
            default:next_state=IDLE;
        endcase
    end
    wire refill_done=(state==MISS_DATA)&&rfire_MEM&&rlast;
    always @(posedge clk) begin
        if(rst)
            {flush_pending,fence_done}<=2'b0;
        else begin
            fence_done<=1'b0;
            if(fence_i)begin
                if((state==IDLE)||refill_done)begin
                    flush_pending<=1'b0;
                    fence_done<=1'b1;
                end else begin
                    flush_pending<=1'b1;
                end
            end else if(flush_pending&&refill_done)begin
                flush_pending<=1'b0;
                fence_done<=1'b1;
            end
        end
    end
    //ICache-arbiter
    assign  arfire_MEM=arvalid_MEM&&arready_MEM;
    assign  rfire_MEM=rvalid_MEM&&rready_MEM;
    wire [7:0]arlen;
    assign arlen=is_sdram_reg?BURST_LEN:8'd0;
    assign araddr_MEM=araddr_reg;
    assign arvalid_MEM=state==MISS_AR;
    assign rready_MEM=state==MISS_DATA;
    assign ICACHE_MEM_wrapper={3'b010,arvalid_MEM,araddr_MEM,arlen,rready_MEM};
    assign {arready_MEM,rvalid_MEM,rdata_MEM,rlast}=MEM_ICACHE_wrapper;
endmodule
module ysyx_26040117_BTB(
    clk,rst,flush,
    araddr,hit,target,
    wen,waddr,wtarget
);
    localparam INDEX_WIDTH=1;
    localparam INDEX_LENGTH=1<<INDEX_WIDTH;
    input clk,rst;
    input flush;
    //ICache-BTB
    input [31:0] araddr;
    output hit;
    output [31:0] target;

    input wen;
    input [31:0] waddr,wtarget;

    reg [INDEX_LENGTH-1:0] btb_valid;
    reg [32-3-INDEX_WIDTH:0] btb_tag_array[INDEX_LENGTH-1:0];
    reg [29:0] btb_target_array[INDEX_LENGTH-1:0];

    wire [INDEX_WIDTH-1:0] rindex,windex;
    assign rindex=araddr[2 +: INDEX_WIDTH];
    assign windex=waddr[2 +: INDEX_WIDTH];

    assign hit=btb_valid[rindex]&&(btb_tag_array[rindex]==araddr[31:2+INDEX_WIDTH]);
    assign target={btb_target_array[rindex],2'b00};

    always @(posedge clk) begin
        if(rst||flush)
            btb_valid<=0;
        else if(wen)begin
            btb_valid[windex]<=1'b1;
            btb_tag_array[windex]<=waddr[31:2+INDEX_WIDTH];
            btb_target_array[windex]<=wtarget[31:2];
        end
    end
endmodule
module ysyx_26040117_IDU(clk,rst,
    IFU_IDU_valid,IFU_IDU_ready,inst,pc,fence_done,pred_taken,
    redirect_valid,EXU_IDU_wrapper,LSU_IDU_wrapper,WBU_IDU_wrapper,
    pc_out,
    IDU_EXU_ready,IDU_EXU_valid,IDU_wrapper,
    rs1,rs2,src1,src2
);
    input clk,rst;
    //IFU_IDU
    input IFU_IDU_valid;
    output IFU_IDU_ready;
    input [31:0] inst;
    input [31:0] pc;
    input fence_done,pred_taken;
    //EXU/LSU/WBU-IDU
    input redirect_valid;//control risk
    input[38:0] EXU_IDU_wrapper,LSU_IDU_wrapper;
    input[37:0] WBU_IDU_wrapper;//data risk
    //IDU-IFU
    output[31:0] pc_out/* verilator public_flat_rd */;
    //IDU_EXU
    input IDU_EXU_ready;
    output IDU_EXU_valid;
    output[158:0]IDU_wrapper;
    


    wire [3:0] funct;
    wire [8:0] mytype;
    wire [31:0] num1,num2;
    wire [31:0] aux_num1,aux_num2;
    wire [6:0] trap_info;
    wire [4:0] rd;
    wire sub,type_fence_i;
    wire register_wen,register_wen_ok,register_wen_load;
    wire[31:0] inst_out/* verilator public_flat_rd */;
    wire pred_taken_out;
    assign IDU_wrapper={pred_taken_out,register_wen_load,register_wen_ok,register_wen,type_fence_i,trap_info,rd,funct,mytype,num1,num2,aux_num1,aux_num2,sub};
    assign funct={inst_out[30],inst_out[14:12]};
    reg [3:0] exception_cause;
    wire type_mret,exception_valid,type_csr;
    wire raw;
    //IDU-REGISTERS
    input [31:0] src1,src2;
    output [4:0] rs1,rs2;
    //state machine
    wire IFU_IDU_fire,IDU_EXU_fire/* verilator public_flat_rd */;
    reg [1:0] state,next_state;
    localparam IDLE=2'b0,FENCE_PAUSE=2'd2,TRAP_PAUSE=2'd3;
    assign IFU_IDU_fire=IFU_IDU_ready&&IFU_IDU_valid;//IDU is empty,IFU pop->IDU push
    assign IDU_EXU_fire=IDU_EXU_ready&&IDU_EXU_valid;//EXU is empty,IDU pop->EXU push
    always @(posedge clk) begin
        if(rst||redirect_valid)
            state<=IDLE;
        else 
            state<=next_state;
    end
    always @(*) begin
        next_state=state;
        case(state)
            IDLE:if(IDU_EXU_fire) begin
                    if(type_fence_i)
                        next_state=FENCE_PAUSE;
                    else if(type_mret||exception_valid)
                        next_state=TRAP_PAUSE;
                end
            FENCE_PAUSE:if(fence_done) next_state=IDLE;
            TRAP_PAUSE:;
            default:next_state=IDLE;
        endcase
    end
    wire issue_pause=type_fence_i||type_mret||exception_valid;
    reg[1:0] buf_count;
    assign IFU_IDU_ready=(state==IDLE)&&(buf_count!=2'd2);
    assign IDU_EXU_valid=(state==IDLE)&&(buf_count!=2'd0)&&!raw; 
    //FIFO
    reg[62:0] idu_buf[1:0];
    wire [29:0]pc_word;
    always @(posedge clk) begin
        if(rst||redirect_valid)begin
            buf_count<=2'd0;
        end else if((IDU_EXU_fire&&issue_pause))begin
            buf_count<=2'd0;
        end else begin
            case({IFU_IDU_fire,IDU_EXU_fire})
                2'b10:begin 
                    if(buf_count==2'd0)
                        idu_buf[0]<={pred_taken,inst,pc[31:2]};
                    else 
                        idu_buf[1]<={pred_taken,inst,pc[31:2]};
                    buf_count<=buf_count+2'd1;
                end
                2'b01:begin 
                    if(buf_count==2'd2)
                        idu_buf[0]<=idu_buf[1];
                    buf_count<=buf_count-2'd1;
                end
                2'b11:idu_buf[0]<={pred_taken,inst,pc[31:2]};
                default:;
            endcase
        end
    end
    assign {pred_taken_out,inst_out,pc_word}=idu_buf[0];
    assign pc_out={pc_word,2'b00};
    //function logic
    wire type_I,type_S,type_B,type_U,type_J,type_R,type_I_compute,type_U_LUI,type_U_AUIPC,type_I_JALR,type_I_LOAD,type_I_privil;
    wire [6:0]opcode;
    wire [2:0]funct3;
    wire funct3_zero;
    wire [31:0]immI,immS,immB,immU,immJ,imm;
    assign funct3_zero=~(|funct3);
    assign opcode=inst_out[6:0];
    assign rd=inst_out[11:7];
    assign rs1=inst_out[19:15];
    assign rs2=inst_out[24:20];

    assign mytype={type_R,type_I_compute,type_S,type_I_LOAD,type_B,type_I_JALR,type_J,type_U_AUIPC,type_U_LUI};
    assign type_I_compute=(opcode==7'b0010011);//ADDI~SRAI
    assign type_I_JALR=(opcode==7'b1100111);//JALR
    assign type_I_LOAD=(opcode==7'b0000011);//LB~LHU
    assign type_I_privil=(opcode==7'b1110011);//CSRR,ECALL,MRET 
    assign type_U_LUI=opcode==7'b0110111;//LUI
    assign type_U_AUIPC=opcode==7'b0010111;//AUIPC
    assign type_R=(opcode==7'b0110011);//ADD~AND
    assign type_I=(type_I_JALR)||(type_I_LOAD)||(type_I_compute)||type_I_privil;
    assign type_S=(opcode==7'b0100011);//SB~SW
    assign type_B=(opcode==7'b1100011);//BEQ~BGEU
    assign type_U=type_U_LUI||type_U_AUIPC;
    assign type_J=(opcode==7'b1101111);//JAL
    assign type_fence_i=(opcode==7'b0001111)&&(funct3==3'b001);//fence.i
    
    assign immI={{20{inst_out[31]}},inst_out[31:20]};
    assign immS={{20{inst_out[31]}},inst_out[31:25],inst_out[11:7]};
    assign immB={{20{inst_out[31]}},inst_out[7],inst_out[30:25],inst_out[11:8],1'b0};
    assign immU={inst_out[31:12],12'b0};
    assign immJ={{12{inst_out[31]}},inst_out[19:12],inst_out[20],inst_out[30:21],1'b0};
    assign imm= (immI&{32{type_I}})|
                (immS&{32{type_S}})|
                (immB&{32{type_B}})|
                (immU&{32{type_U}})|
                (immJ&{32{type_J}});
    assign funct3=inst_out[14:12];

    wire[31:0] src1_forward,src2_forward;
    assign num1=({32{(|mytype[8:4]) ||type_csr}} & src1_forward)|//alu,alui,load,store,branch,csrr
                 ({32{(|mytype[3:1]) || exception_valid}} & pc_out);//jalr,jal,auipc,ecall
    assign num2= ({32{mytype[8]||mytype[4]}}&src2_forward)|//branch,alu
                 ({32{(|mytype[1:0])||(|mytype[7:5])}}&imm)|//lui,auipc,load,store,alui
                 ({29'd0,|mytype[3:2],2'd0});//jal,jalr
    assign aux_num1=({32{mytype[2]||mytype[4]}}&pc_out)|
                    ({32{mytype[3]}}&src1_forward);
    assign aux_num2=({32{mytype[6]}}&src2_forward)|
                     ({32{(|mytype[4:2])||type_csr}}&imm);
    wire is_slt =(~funct[2])&&funct[1];
    assign sub  =(mytype[8]&&funct[3])||((mytype[8]||mytype[7])&&is_slt);
    wire rd_valid=rd!=5'd0;
    assign register_wen_ok=((|mytype[3:0])||(|mytype[8:7]))&&(rd_valid);
    assign register_wen_load=rd_valid&&(mytype[5]);
    assign  register_wen=register_wen_ok||register_wen_load||(rd_valid&&type_csr);
    //Data adventure
    wire rs1_use,rs2_use;
    assign rs1_use=(|mytype[8:3])||type_csr;
    assign rs2_use=mytype[8]||mytype[6]||mytype[4];
    wire exu_pending,exu_ready,lsu_pending,lsu_ready,wbu_ready;
    wire [31:0] exu_data,lsu_data,wbu_data;
    wire[4:0] exu_rd,lsu_rd,wbu_rd;
    assign {exu_data,exu_pending,exu_ready,exu_rd}=EXU_IDU_wrapper;
    assign {lsu_data,lsu_pending,lsu_ready,lsu_rd}=LSU_IDU_wrapper;
    assign {wbu_data,wbu_ready,wbu_rd}=WBU_IDU_wrapper;
    wire rs1_exu=rs1_use&&exu_pending&&(exu_rd==rs1);
    wire rs1_lsu=rs1_use&&lsu_pending&&(lsu_rd==rs1);
    wire rs1_wbu=rs1_use&&wbu_ready&&(wbu_rd==rs1);
    wire rs2_exu=rs2_use&&exu_pending&&(exu_rd==rs2);
    wire rs2_lsu=rs2_use&&lsu_pending&&(lsu_rd==rs2);
    wire rs2_wbu=rs2_use&&wbu_ready&&(wbu_rd==rs2);

    wire rs1_wait=rs1_exu?!exu_ready:rs1_lsu?!lsu_ready:1'b0;
    wire rs2_wait=rs2_exu?!exu_ready:rs2_lsu?!lsu_ready:1'b0;
    assign raw=rs1_wait||rs2_wait;

    wire rs1_sel_exu=rs1_exu;
    wire rs1_sel_lsu=!rs1_exu&&rs1_lsu;
    wire rs1_sel_wbu=!rs1_exu&&!rs1_lsu&&rs1_wbu;
    wire rs1_sel_rf =!rs1_exu&&!rs1_lsu&&!rs1_wbu;
    assign src1_forward=
        ({32{rs1_sel_exu}}&exu_data)|
        ({32{rs1_sel_lsu}}&lsu_data)|
        ({32{rs1_sel_wbu}}&wbu_data)|
        ({32{rs1_sel_rf }}&src1);
    wire rs2_sel_exu=rs2_exu;
    wire rs2_sel_lsu=!rs2_exu&&rs2_lsu;
    wire rs2_sel_wbu=!rs2_exu&&!rs2_lsu&&rs2_wbu;
    wire rs2_sel_rf =!rs2_exu&&!rs2_lsu&&!rs2_wbu;
    assign src2_forward=
        ({32{rs2_sel_exu}}&exu_data)|
        ({32{rs2_sel_lsu}}&lsu_data)|
        ({32{rs2_sel_wbu}}&wbu_data)|
        ({32{rs2_sel_rf }}&src2);
    
    //Exception interrupt
    wire type_trap=type_I_privil&&funct3_zero;

    wire exception_illegal=1'b0;
    wire exception_breakpoint=type_trap&&(immI[11:0]==12'b1);
    wire exception_ecall=type_trap&&(immI[11:0]==12'b0);
    assign exception_valid=exception_illegal||exception_ecall||exception_breakpoint;
    assign type_mret=type_trap&&(immI[11:0]==12'b001100000010);
    assign  type_csr=~funct3_zero&type_I_privil;

    assign trap_info={exception_cause,exception_valid,type_mret,type_csr};
    always @(*) begin
        exception_cause=4'd0;
        if(exception_illegal)
            exception_cause=4'd2;
        else if(exception_breakpoint)
            exception_cause=4'd3;
        else if(exception_ecall)
            exception_cause=4'd11;
    end
endmodule
module ysyx_26040117_RegisterFile #(ADDR_WIDTH = 4, DATA_WIDTH = 32) (clk,
    raddr1,raddr2,rdata1,rdata2,
    wdata,waddr,wen
);
    input clk;
    input wen;
    input [ADDR_WIDTH-1:0] waddr,raddr1,raddr2;
    input [DATA_WIDTH-1:0] wdata;
    output [DATA_WIDTH-1:0] rdata1,rdata2;
    reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
    always @(posedge clk) begin
        if (wen&&(waddr != 0))begin
            rf[waddr] <= wdata;
        end
    end
    assign rdata1 = (raddr1 == 0) ? 32'b0 : rf[raddr1];
    assign rdata2 = (raddr2 == 0) ? 32'b0 : rf[raddr2];
endmodule
module ysyx_26040117_EXU(clk,rst,
    IDU_EXU_ready,IDU_EXU_valid,IDU_wrapper,
    EXU_LSU_ready,EXU_LSU_valid,exu_redirect_pc,EXU_wrapper,
    redirect_valid,EXU_IDU_wrapper,
    exu_btb_wen,exu_btb_waddr,exu_btb_wtarget
);
    input clk,rst;
    //IDU-EXU
    input IDU_EXU_valid;
    output IDU_EXU_ready;
    input [158:0]IDU_wrapper;
    //EXU-LSU
    input EXU_LSU_ready;
    output EXU_LSU_valid;
    output [31:0] exu_redirect_pc;
    output [84:0] EXU_wrapper;
    
    
    //FIFO
    reg[158:0] IDU_wrapper_reg;
    wire [8:0]mytype;
    wire [3:0]funct;
    wire [31:0] num1,num2,aux_num1,aux_num2,aux0;
    wire [31:0]aux/* verilator public_flat_rd */;
    wire sub,type_fence_i,register_wen_ok,register_wen_load,register_wen,pred_taken;
    wire[6:0] trap_info;
    wire [4:0] rd;
    reg [31:0]result;
    wire IDU_EXU_fire,EXU_LSU_fire/* verilator public_flat_rd */;
    always @(posedge clk) begin
        if(IDU_EXU_fire)begin
            IDU_wrapper_reg<=IDU_wrapper;
        end
    end
    assign {pred_taken,register_wen_load,register_wen_ok,register_wen,type_fence_i,trap_info,rd,funct,mytype,num1,num2,aux_num1,aux_num2,sub}=IDU_wrapper_reg;

    assign EXU_wrapper={register_wen_load,register_wen_ok,register_wen,type_fence_i,trap_info,rd,result,aux_num2,mytype[6:5],funct[2:0]};
    //EXU-IFU/IDU
    output redirect_valid;
    output[38:0] EXU_IDU_wrapper;
    assign EXU_IDU_wrapper={result,EXU_LSU_valid&&register_wen,EXU_LSU_valid&&register_wen_ok,rd};
    //EXU-BTB
    output exu_btb_wen;
    output [31:0] exu_btb_waddr,exu_btb_wtarget;
    assign exu_btb_waddr=aux_num1;
    assign exu_btb_wtarget=aux;
    assign exu_btb_wen=EXU_LSU_fire&&(mytype[2]||(mytype[4]&&aux_num2[31]));
    //state machine
    reg state;
    localparam IDLE=0,WAIT=1;
    always @(posedge clk) begin
        if(rst||redirect_valid)
            state<=IDLE;
        else if(IDU_EXU_fire)
            state<=WAIT;
        else if(EXU_LSU_fire)
            state<=IDLE;
    end
    assign IDU_EXU_ready=(state==IDLE)||EXU_LSU_fire;
    assign EXU_LSU_valid=state==WAIT;
    assign IDU_EXU_fire=IDU_EXU_ready&&IDU_EXU_valid;
    assign EXU_LSU_fire=EXU_LSU_ready&&EXU_LSU_valid;
    //result function
    wire carry,sless,less;
    wire[31:0] t_no_cin,result0;
    assign t_no_cin={32{sub}}^num2;
    assign {carry,result0}={1'b0,num1}+{1'b0,t_no_cin}+{32'd0,sub};//adder
    assign sless=(num1[31]^num2[31])?num1[31]:result0[31];
    assign less=~carry;
    
    wire signed [32:0] shift_src={funct[3]&num1[31],num1};
    wire [32:0] shift_tmp=$signed(shift_src)>>>num2[4:0];
    always @(*) begin
        result=result0;//load,store,jal,jalr
        if(mytype[8]||mytype[7])begin
            case(funct[2:0])
                3'b000:result=result0;//ADDI,ADD
                3'b010:result={31'd0,sless};//SLTI,SLT
                3'b011:result={31'd0,less};//SLTIU,SLTU
                3'b100:result=num1^num2;//XORI,XOR
                3'b110:result=num1|num2;//ORI,OR
                3'b111:result=num1&num2;//ANDI,AND
                3'b001:result=num1<<(num2[4:0]);//SLLI,SLL
                3'b101:result=shift_tmp[31:0];//1:SRAI,SRA;0:SRLI,SRL
                default:result=32'd0;
            endcase
        end
    end
    //branch function
    wire cmp_eq=num1==num2;
    wire cmp_lts=$signed(num1)<$signed(num2);
    wire cmp_ltu=num1<num2;
    //wire cmp_lts=(num1[31]^num2[31])?num1[31]:cmp_ltu;
    reg branch_decision0;
    wire branch_decision;
    always@(*)begin
        branch_decision0=1'b0;
        case(funct[2:1])
            2'b00:branch_decision0=cmp_eq;//BEQ,BNE
            2'b10:branch_decision0=cmp_lts;//BLT,BGE
            2'b11:branch_decision0=cmp_ltu;//BLTU,BGEU
            default:branch_decision0=1'd0;
        endcase
    end
    assign branch_decision=funct[0]^branch_decision0;
    //aux
    assign aux0=aux_num1+aux_num2;
    assign aux={aux0[31:1],aux0[0]&&~mytype[3]};
    //redirect
    wire actual_taken/* verilator public_flat_rd */;
    wire mispredict;
    assign actual_taken=(|mytype[3:2])||(mytype[4]&&branch_decision);
    assign mispredict=mytype[3]||(actual_taken^pred_taken);
    assign redirect_valid=mispredict&&EXU_LSU_fire;

    wire [31:0] branch_snpc;
    assign branch_snpc=aux_num1+32'd4;
    assign exu_redirect_pc=(mytype[4]&&!branch_decision)?branch_snpc:aux;
endmodule
module ysyx_26040117_LSU (clk,rst,
    EXU_LSU_ready,EXU_LSU_valid,EXU_wrapper,
    LSU_WBU_ready,LSU_WBU_valid,LSU_wrapper,
    LSU_IDU_wrapper,
    MEM_LSU_wrapper,LSU_MEM_wrapper
);
    input clk,rst;
    //EXU-LSU
    input EXU_LSU_valid;
    output EXU_LSU_ready;
    input [84:0]EXU_wrapper;
    //LSU-WBU
    input LSU_WBU_ready;
    output LSU_WBU_valid;
    output [51:0]LSU_wrapper;
    //LSU-IDU
    output [38:0] LSU_IDU_wrapper;
    //LSU-MEM
    input [40:0]MEM_LSU_wrapper;
    output[110:0] LSU_MEM_wrapper;

    //FIFO
    reg [84:0] wrapper_reg;
    wire register_wen_ok,register_wen_load,register_wen,type_fence_i,is_store,is_load;
    wire[31:0] aux;
    wire [31:0]result/* verilator public_flat_rd */;
    wire [2:0]funct3;
    wire [6:0]trap_info;
    wire [4:0]rd;
    wire [31:0] result_out;
    reg[2:0] csr_addr;
    wire EXU_LSU_fire,LSU_WBU_fire/* verilator public_flat_rd */;
    always @(posedge clk) begin
        if(EXU_LSU_fire)begin
            wrapper_reg<=EXU_wrapper;
        end
    end
    assign {register_wen_load,register_wen_ok,register_wen,type_fence_i,trap_info,rd,result,aux,is_store,is_load,funct3}=wrapper_reg;
    assign LSU_wrapper={register_wen,type_fence_i,trap_info,rd,result_out,csr_addr,funct3};
    wire rvalid,arready,rready,bvalid;;
    reg arvalid,awvalid,wvalid;
    reg lsu_valid;
    wire load_ready=register_wen_load&&!arvalid&&rvalid;
    assign LSU_IDU_wrapper={result_out,lsu_valid&&register_wen,lsu_valid&&(register_wen_ok||load_ready),rd};
    //
    wire wen,ren;
    wire [1:0]mytype_in=EXU_wrapper[4:3];
    assign wen=mytype_in[1]&&EXU_LSU_fire;//right now
    assign ren=mytype_in[0]&&EXU_LSU_fire;
    assign EXU_LSU_fire=EXU_LSU_ready&&EXU_LSU_valid;
    assign LSU_WBU_fire=LSU_WBU_ready&&LSU_WBU_valid;
    assign EXU_LSU_ready=!lsu_valid||LSU_WBU_fire;
    wire is_mem/* verilator public_flat_rd */;
    assign is_mem=is_load||is_store;
    assign LSU_WBU_valid=lsu_valid&&(!is_mem|| 
            (is_load&&!arvalid&&rvalid)||
            (is_store&&!awvalid&&!wvalid&&bvalid)
    );
    always @(posedge clk) begin
        if(rst)
            lsu_valid<=1'b0;
        else if(EXU_LSU_fire)
            lsu_valid<=1'b1;
        else if(LSU_WBU_fire)
            lsu_valid<=1'b0;
    end
    //read
    wire[31:0] rdata;
    wire[1:0] rresp;
    wire [31:0] araddr;
    wire [2:0] arsize;
    wire arfire;
    assign arfire=arvalid&&arready;
    always @(posedge clk) begin
        if(rst) arvalid<=1'b0;
        else if(arfire)
            arvalid<=1'b0;
        else if(ren)
            arvalid<=1'b1;
    end
    assign rready=lsu_valid&&is_load&&!arvalid&&LSU_WBU_ready;
    assign {araddr,arsize}={result,{1'b0,funct3[1:0]}};
    //read function
    reg[31:0] rdata_out;
    wire[1:0] raddr_shift;
    assign raddr_shift=araddr[1:0];
    reg[7:0] load_byte;
    wire[15:0]load_half=raddr_shift[1]?rdata[31:16]:rdata[15:0];
    always @(*) begin
        case(raddr_shift)
            2'b00:load_byte=rdata[7:0];
            2'b01:load_byte=rdata[15:8];
            2'b10:load_byte=rdata[23:16];
            2'b11:load_byte=rdata[31:24];
        endcase
    end
    always @(*) begin
        case(funct3)
            3'b000:rdata_out={{24{load_byte[7]}},load_byte};
            3'b001:rdata_out={{16{load_half[15]}},load_half};
            3'b010:rdata_out=rdata;
            3'b100:rdata_out={24'd0,load_byte};
            3'b101:rdata_out={16'd0,load_half};
            default:rdata_out=32'd0;
        endcase
    end
    //write
    wire awready,wready,bready;
    wire[1:0] bresp;
    wire [2:0] awsize;
    wire [31:0] awaddr,wdata;
    wire [3:0] wstrb;
    wire wfire,awfire;
    //aw
    assign awfire=awvalid&&awready;
    always @(posedge clk) begin
        if(rst) awvalid<=1'b0;
        else if(awfire)
            awvalid<=1'b0;
        else if(wen)
            awvalid<=1'b1;
    end
    //w
    assign wfire=wvalid&&wready;
    always @(posedge clk) begin
        if(rst) wvalid<=1'b0;
        else if(wfire)
            wvalid<=1'b0;
        else if(wen)
            wvalid<=1'b1;
    end
    //b
    assign bready=lsu_valid&&is_store&&!wvalid&&!awvalid&&LSU_WBU_ready;
    //write function
    wire[3:0] aw_mask;
    assign wdata=(funct3[1:0] == 2'b00) ? {4{aux[7:0]}} :   // sb
                        (funct3[1:0] == 2'b01) ? {2{aux[15:0]}} :  // sh
                        aux;//sw
    assign {awaddr,awsize}={result,{1'b0,funct3[1:0]}};
    assign aw_mask={awsize[1],awsize[1],awsize[1]|awsize[0],1'b1};
    assign wstrb=aw_mask<<awaddr[1:0];
    //interface
    assign LSU_MEM_wrapper={arsize,awsize,arvalid,araddr,rready,awvalid,awaddr,wvalid,wdata,wstrb,bready};
    assign {arready,rvalid,rdata,rresp,awready,wready,bvalid,bresp}=MEM_LSU_wrapper;//save rdata?

    //output
    assign result_out=is_load?rdata_out:result;
    localparam CSR_MCYCLE_LO = 3'd0;
    localparam CSR_MCYCLE_HI = 3'd1;
    localparam CSR_MEPC      = 3'd2;
    localparam CSR_MSTATUS   = 3'd3;
    localparam CSR_MCAUSE    = 3'd4;
    localparam CSR_MTVEC     = 3'd5;
    localparam CSR_MVENDORID = 3'd6;
    localparam CSR_MARCHID   = 3'd7;
    always @(*) begin
        csr_addr=3'd0;
        if(trap_info[0])begin
            case(aux[11:0])
                12'hb00:csr_addr={CSR_MCYCLE_LO};
                12'hb80:csr_addr={CSR_MCYCLE_HI};
                12'h341:csr_addr={CSR_MEPC};
                12'h300:csr_addr={CSR_MSTATUS};
                12'h342:csr_addr={CSR_MCAUSE};
                12'h305:csr_addr={CSR_MTVEC};
                12'hf11:csr_addr={CSR_MVENDORID};
                12'hf12:csr_addr={CSR_MARCHID};
                default:csr_addr=3'd0;
            endcase
        end
    end
endmodule
module ysyx_26040117_WBU(clk,rst,
    LSU_WBU_ready,LSU_WBU_valid,LSU_wrapper,
    WBU_IFU_ready,trap_dnpc,trap_redirect_valid,fence_i,srcd,rd,register_wen_out,
    WBU_IDU_wrapper
);
    input clk,rst;
    //LSU-WBU
    input LSU_WBU_valid;
    output LSU_WBU_ready;
    input [51:0]LSU_wrapper;
    //WBU-IFU
    input WBU_IFU_ready;
    output[31:0] srcd;
    output[31:0] trap_dnpc/* verilator public_flat_rd */;
    output trap_redirect_valid;
    output fence_i;
    output [4:0]rd;
    output register_wen_out;
    wire WBU_IFU_valid;
    //WBU-IDU
    output[37:0] WBU_IDU_wrapper;
    wire register_wen;
    assign WBU_IDU_wrapper={srcd,WBU_IFU_valid&&register_wen,rd};
    //state machine
    wire LSU_WBU_fire,WBU_IFU_fire/* verilator public_flat_rd */;
    reg state;
    localparam IDLE=1'd0,WAIT=1'd1;
    always @(posedge clk) begin
        if(rst)
            state<=IDLE;
        else if(LSU_WBU_fire)
            state<=WAIT;
        else if(WBU_IFU_fire)
            state<=IDLE;
    end
    assign LSU_WBU_fire=LSU_WBU_ready&&LSU_WBU_valid;
    assign WBU_IFU_fire=WBU_IFU_ready&&WBU_IFU_valid;
    assign LSU_WBU_ready=1;
    assign WBU_IFU_valid=state==WAIT;
    //FIFO
    reg [51:0] LSU_wrapper_reg;
    wire [31:0] result;
    wire [2:0] funct3;
    wire type_fence_i;
    wire [6:0]trap_info/* verilator public_flat_rd */;//0:csrr,1:ecall,2:mret,
    wire [2:0] csr_addr/* verilator public_flat_rd */;
    always @(posedge clk) begin
        LSU_wrapper_reg<=LSU_wrapper;
    end
    assign {register_wen,type_fence_i,trap_info,rd,result,csr_addr,funct3}=LSU_wrapper_reg;

    //function
    wire [31:0] csr_rdata;
    assign register_wen_out=register_wen&&(WBU_IFU_fire);
    assign srcd=trap_info[0]?csr_rdata:result;
    assign trap_redirect_valid=(|trap_info[2:1])&&WBU_IFU_fire;
    assign fence_i=type_fence_i&&(WBU_IFU_fire);
    //Control Status Register
    ysyx_26040117_CSR CSR1(.clk(clk),.rst(rst),
        .wen(WBU_IFU_fire),.trap_info(trap_info),.funct3(funct3),.csr_addr(csr_addr),.result(result),
        .rdata(csr_rdata),.trap_dnpc(trap_dnpc)
    );
    //ebreak
`ifdef __ICARUS__
    wire ebreak=trap_info[2]&&(trap_info[6:3]==4'd3);
    always @(posedge clk) begin
        if(ebreak&&!rst&&WBU_IFU_fire)begin
            $display("EBREAK finish");
            $finish;
        end
    end
`endif
endmodule
module ysyx_26040117_CSR(clk,rst,
    wen,trap_info,funct3,csr_addr,result,
    rdata,trap_dnpc
);
    localparam CSR_MCYCLE_LO = 3'd0;
    localparam CSR_MCYCLE_HI = 3'd1;
    localparam CSR_MEPC      = 3'd2;
    localparam CSR_MSTATUS   = 3'd3;
    localparam CSR_MCAUSE    = 3'd4;
    localparam CSR_MTVEC     = 3'd5;
    localparam CSR_MVENDORID = 3'd6;
    localparam CSR_MARCHID   = 3'd7;
    input clk,rst;
    input wen;
    input [2:0]funct3;//0:csrr,1:ecall,2:mret
    input [6:0] trap_info;
    input [2:0]csr_addr;
    input [31:0]result;
    output reg[31:0]rdata;
    output [31:0] trap_dnpc;
    reg[31:0]mcycle_lo,mcycle_hi;
    reg[31:0]wdata,mepc,mstatus,mcause,mtvec;
    //read
    assign trap_dnpc=trap_info[2]?{mtvec[31:2],2'd0}:mepc;
    always @(*)begin
        case(csr_addr)
            CSR_MCYCLE_LO:rdata=mcycle_lo;
            CSR_MCYCLE_HI:rdata=mcycle_hi;
            CSR_MEPC:     rdata=mepc;
            CSR_MSTATUS:  rdata=mstatus;
            CSR_MCAUSE:   rdata=mcause;
            CSR_MTVEC:    rdata=mtvec;
            CSR_MVENDORID:rdata=32'h79737978;
            CSR_MARCHID:  rdata=32'h18d5735;
            default:rdata=32'h0;
        endcase
    end
    always @(*)begin
        case(funct3)//src1
            3'b001:wdata=result;
            3'b010:wdata=result|rdata;
            default:wdata=0;
        endcase
    end
    reg lo_wrap;
    always @(posedge clk) begin
        if(rst)begin
            mcycle_lo<=32'd0;
            mcycle_hi<=32'd0;
            lo_wrap<=1'b0;
        end else begin
            mcycle_lo<=mcycle_lo+32'd1;
            lo_wrap<=(mcycle_lo==32'hfffffffe);
            mcycle_hi<=mcycle_hi+{31'd0,lo_wrap};
            if(wen&&trap_info[0]&&!trap_info[2])begin
                if(csr_addr==CSR_MCYCLE_LO) begin 
                    mcycle_lo<=wdata;
                    lo_wrap<=&wdata;
                end
                else if(csr_addr==CSR_MCYCLE_HI)mcycle_hi<=wdata;
            end
        end
    end
    always @(posedge clk) begin
        if(rst)begin
            mstatus<=32'h1800;
            mcause<=32'h0;
        end else begin
            //{mcycle_hi,mcycle_lo}<={mcycle_hi,mcycle_lo}+64'd1;
            if(wen)begin
                if(trap_info[2])begin//trap entry
                    mstatus[7]<=mstatus[3];//mpie=mie
                    mstatus[3]<=1'b0;
                    mstatus[12:11]<=2'b11;//MPP=3 from M mode
                    mepc<={result[31:2],2'd0};//pc
                    mcause<={28'd0,trap_info[6:3]};
                end if(trap_info[1])begin//trap return meret
                    mstatus[3]<=mstatus[7];
                    mstatus[7]<=1'b1;
                    mstatus[12:11]<=2'b11;
                end else if(trap_info[0])begin
                    case(csr_addr)
                        //CSR_MCYCLE_LO:mcycle_lo<=wdata;
                        //CSR_MCYCLE_HI:mcycle_hi<=wdata;
                        CSR_MEPC:     mepc<={wdata[31:2],2'd0};
                        CSR_MSTATUS:  mstatus<=wdata;
                        CSR_MCAUSE:   mcause<=wdata;
                        CSR_MTVEC:    mtvec<=wdata;
                        default:;
                    endcase
                end
            end
        end
    end
endmodule
module ysyx_26040117_arbiter(clk,rst,
    MEM_IFU_wrapper,IFU_MEM_wrapper,
    MEM_LSU_wrapper,LSU_MEM_wrapper,
    master_wrapper_in,master_wrapper_out
);
    input clk,rst;
    input [44:0] IFU_MEM_wrapper;
    input[110:0] LSU_MEM_wrapper;
    output [40:0] MEM_LSU_wrapper;
    output [34:0] MEM_IFU_wrapper;
    input [49:0]master_wrapper_in;
    output [139:0] master_wrapper_out;
    //unpack
    wire ifu_arvalid,ifu_rready,lsu_arvalid,lsu_rready;
    wire [31:0] ifu_araddr,lsu_araddr;
    wire [2:0] ifu_arsize,lsu_arsize,lsu_awsize;
    wire [7:0] ifu_arlen;

    wire arvalid,rready;
    wire [31:0] araddr;
    wire arready,rvalid;
    wire [31:0] rdata;
    wire[1:0] rresp;
    wire[2:0] arsize;
    wire rlast;
    wire [3:0]arid,rid;
    wire [7:0]arlen;

    wire lsu_fire,ifu_fire,resp_ifu,resp_lsu;
    assign {ifu_arsize,ifu_arvalid,ifu_araddr,ifu_arlen,ifu_rready}=IFU_MEM_wrapper;
    assign {lsu_arsize,lsu_awsize,lsu_arvalid,lsu_araddr,lsu_rready}=LSU_MEM_wrapper[110:71];
    assign MEM_IFU_wrapper={ifu_fire&&arready,resp_ifu&&rvalid,rdata,rlast};
    assign MEM_LSU_wrapper[40:5]={lsu_fire&&arready,resp_lsu&&rvalid,rdata,rresp};
    //state machine
    wire arfire=arvalid&&arready;
    reg [1:0] state,next_state;
    localparam IDLE=2'd0,WAIT_LSU=2'd1,WAIT_IFU=2'd2;
    always @(posedge clk) begin
        if(rst) state<=IDLE;
        else state<=next_state;
    end
    always @(*) begin
        next_state=state;
        case(state)
            IDLE: begin if(arvalid&&!arready)
                if(lsu_arvalid)next_state=WAIT_LSU;//0延迟会死锁
                else if(ifu_arvalid)next_state=WAIT_IFU;
            end
            WAIT_LSU:if(arfire) next_state=IDLE;
            WAIT_IFU:if(arfire) next_state=IDLE;
            default:next_state=state;
        endcase
    end
    assign lsu_fire=(state==IDLE&&lsu_arvalid)||state==WAIT_LSU;
    assign ifu_fire=(state==IDLE&&ifu_arvalid&&!lsu_arvalid)||state==WAIT_IFU;
    //read
    assign resp_ifu=!rid[0];
    assign resp_lsu=rid[0];
    assign {arsize,araddr}=lsu_fire?{lsu_arsize,lsu_araddr}:{ifu_arsize,ifu_araddr};
    assign arvalid=(lsu_fire&&lsu_arvalid)||(ifu_fire&&ifu_arvalid);
    assign rready=(resp_lsu&&lsu_rready)||(resp_ifu&&ifu_rready);
    assign arid={3'd0,lsu_fire};
    assign arlen={6'd0,lsu_fire?2'd0:ifu_arlen[1:0]};
    
    //write
    wire awvalid,wvalid,bready;
    wire [31:0] awaddr,wdata;
    wire [3:0] wstrb;
    wire awready,wready,bvalid;
    wire[1:0] bresp;
    wire[2:0] awsize;
    assign awsize=lsu_awsize;
    assign {awvalid,awaddr,wvalid,wdata,wstrb,bready}=LSU_MEM_wrapper[70:0];
    assign MEM_LSU_wrapper[4:0]={awready,wready,bvalid,bresp};

    ysyx_26040117_Xbar xbar1(.clk(clk),.rst(rst),
        .master_wrapper_in(master_wrapper_in),.master_wrapper_out(master_wrapper_out),
        .arvalid(arvalid),.arready(arready),.araddr(araddr),.arsize(arsize),.arid(arid),.arlen(arlen),
        .rvalid(rvalid),.rready(rready),.rdata(rdata),.rresp(rresp),.rlast(rlast),.rid(rid),
        .awvalid(awvalid),.awready(awready),.awaddr(awaddr),.awsize(awsize),
        .wvalid(wvalid),.wready(wready),.wdata(wdata),.wstrb(wstrb),
        .bvalid(bvalid),.bready(bready),.bresp(bresp)
);

endmodule
module ysyx_26040117_Xbar(clk,rst,
    master_wrapper_in,master_wrapper_out,
    arvalid,arready,araddr,arsize,arid,arlen,
    rvalid,rready,rdata,rresp,rlast,rid,
    awvalid,awready,awaddr,awsize,
    wvalid,wready,wdata,wstrb,
    bvalid,bready,bresp
);
    input clk,rst;
    //AXI-lite port
    input [49:0]master_wrapper_in;
    output [139:0] master_wrapper_out;
    input [2:0] awsize,arsize;
    //read
    input arvalid;
    output arready;
    input[31:0]araddr;
    input[3:0] arid;
    input[7:0] arlen;

    output rvalid;
    input rready;
    output [31:0]rdata;
    output[1:0] rresp;
    output rlast;
    output[3:0] rid;
    //write
    input awvalid;
    output awready;
    input [31:0] awaddr;

    input wvalid;
    output wready;
    input [31:0]wdata;
    input [3:0]wstrb;

    output bvalid;
    input bready;
    output[1:0] bresp;
    //AXI-lite
    wire         io_master_awready;
    wire         io_master_awvalid;
    wire [31:0]  io_master_awaddr;
    wire [3:0]   io_master_awid;
    wire [7:0]   io_master_awlen;
    wire [2:0]   io_master_awsize;
    wire [1:0]   io_master_awburst;

    wire         io_master_wready;
    wire         io_master_wvalid;
    wire [31:0]  io_master_wdata;
    wire [3:0]   io_master_wstrb;
    wire         io_master_wlast;

    wire         io_master_bready;
    wire         io_master_bvalid;
    wire [1:0]   io_master_bresp;
    wire [3:0]   io_master_bid;

    wire         io_master_arready;
    wire         io_master_arvalid;
    wire [31:0]  io_master_araddr;
    wire [3:0]   io_master_arid;
    wire [7:0]   io_master_arlen;
    wire [2:0]   io_master_arsize;
    wire [1:0]   io_master_arburst;

    wire         io_master_rready;
    wire         io_master_rvalid;
    wire [1:0]   io_master_rresp;
    wire [31:0]  io_master_rdata;
    wire         io_master_rlast;
    wire [3:0]   io_master_rid;


    //aw_choose
    wire dec_soc_w,sel_soc_w,dec_clint_w,sel_clint_w;
    reg reg_soc_w,reg_clint_w,w_routed;
    wire aw_in_clint;
    assign aw_in_clint =(awaddr[31:16]==16'h0200)&&(awaddr[15:14]!=2'b11);//CLINT 02000000~0200bfff
    assign dec_soc_w=awvalid&&!aw_in_clint;
    assign dec_clint_w=awvalid&&aw_in_clint;

    wire awfire,wfire,bfire;
    assign awfire=awvalid&&awready;
    assign wfire=wvalid&&wready;
    assign bfire=bvalid&&bready;
    always @(posedge clk) begin
        if(rst)begin
            reg_soc_w<=1'b0;
            reg_clint_w<=1'b0;
            w_routed<=1'b0;
        end else if(bfire)begin 
            reg_soc_w<=1'b0;
            reg_clint_w<=1'b0;
            w_routed<=1'b0;
        end else if(awfire&&~wfire)begin
            reg_soc_w<=dec_soc_w;
            reg_clint_w<=dec_clint_w;
            w_routed<=1;
        end else if(wfire)begin
            reg_soc_w<=1'b0;
            reg_clint_w<=1'b0;
            w_routed<=1'b0;
        end
    end
    assign sel_soc_w=w_routed?reg_soc_w:dec_soc_w;
    assign sel_clint_w=w_routed?reg_clint_w:dec_clint_w;
    //ar_choose
    wire dec_soc_r,dec_clint_r;
    wire ar_in_clint;
    assign ar_in_clint =(araddr[31:16]==16'h0200)&&(araddr[15:14]!=2'b11);//CLINT 02000000~0200bfff
    assign dec_soc_r=arvalid&&!ar_in_clint;
    assign dec_clint_r=arvalid&&ar_in_clint;
    //clint
    wire clint_awready,clint_wready,clint_bvalid,clint_awvalid,clint_wvalid;
    wire[1:0] clint_bresp,clint_rresp;
    wire clint_arvalid,clint_arready,clint_rvalid,clint_rready;
    wire [31:0] clint_rdata;
    wire [3:0] clint_rid;
    assign clint_arvalid=dec_clint_r;
    assign clint_awvalid=dec_clint_w;
    assign clint_wvalid=sel_clint_w&&wvalid;
    ysyx_26040117_CLINT clint1(.clk(clk),.rst(rst),
        .arvalid(clint_arvalid),.arready(clint_arready),.araddr(araddr),.arid(arid),
        .rvalid(clint_rvalid),.rready(clint_rready),.rdata(clint_rdata),.rresp(clint_rresp),.rid(clint_rid),
        .awvalid(clint_awvalid),.awready(clint_awready),.awaddr(awaddr),
        .wvalid(clint_wvalid),.wready(clint_wready),.wdata(wdata),.wstrb(wstrb),
        .bvalid(clint_bvalid),.bready(bready),.bresp(clint_bresp)
);
    //output
    reg hold_soc;
    wire sel_clint=clint_rvalid&&!hold_soc;
    assign arready=(dec_clint_r&&clint_arready)||(dec_soc_r&&io_master_arready);
    assign rvalid=sel_clint?clint_rvalid:io_master_rvalid;
    assign rdata =sel_clint?clint_rdata :io_master_rdata;
    assign rresp =sel_clint?clint_rresp :io_master_rresp;
    assign rlast =sel_clint?1'b1       :io_master_rlast;
    assign rid   =sel_clint?clint_rid:io_master_rid;

    assign clint_rready=sel_clint&&rready;
    assign io_master_rready=!sel_clint&&rready;

    assign awready=(dec_clint_w&&clint_awready)||(dec_soc_w&&io_master_awready);
    assign wready=(sel_clint_w&&clint_wready)||(sel_soc_w&&io_master_wready);
    assign bvalid=clint_bvalid||io_master_bvalid;
    assign bresp=clint_bvalid?clint_bresp:io_master_bresp;
    always @(posedge clk) begin
        if(rst)
            hold_soc<=1'b0;
        else
            hold_soc<=!sel_clint&&io_master_rvalid&&!rready;
    end
    //decomposition
    assign {io_master_awready,io_master_wready,io_master_bvalid,io_master_bresp,io_master_bid,io_master_arready,
        io_master_rvalid,io_master_rresp,io_master_rdata,io_master_rlast,io_master_rid}=master_wrapper_in;
    assign master_wrapper_out={io_master_awvalid,io_master_awaddr,io_master_awid,io_master_awlen,io_master_awsize,io_master_awburst,
        io_master_wvalid,io_master_wdata,io_master_wstrb,io_master_wlast,io_master_bready,io_master_arvalid,
        io_master_araddr,io_master_arid,io_master_arlen,io_master_arsize,io_master_arburst,io_master_rready};
    //connect
    assign io_master_awvalid=dec_soc_w;
    assign io_master_awaddr=awaddr;
    assign io_master_wvalid=sel_soc_w&&wvalid;
    assign io_master_wdata=wdata;
    assign io_master_wstrb=wstrb;
    assign io_master_bready=bready;
    assign io_master_arvalid=dec_soc_r;
    assign io_master_araddr=araddr;

    assign io_master_awid=4'd0;
    assign io_master_awlen=8'd0;
    assign io_master_awsize=awsize;
    assign io_master_awburst=2'd01;
    assign io_master_wlast=1'b1;

    assign io_master_arid=arid;
    assign io_master_arlen=arlen;
    assign io_master_arsize=arsize;
    assign io_master_arburst=(arlen[1:0]==2'd0)?2'b01:2'b10;
endmodule
module ysyx_26040117_CLINT(clk,rst,
    arvalid,arready,araddr,arid,
    rvalid,rready,rdata,rresp,rid,
    awvalid,awready,awaddr,
    wvalid,wready,wdata,wstrb,
    bvalid,bready,bresp
);
    input clk,rst;
    //read
    input arvalid;
    output arready;
    input[31:0]araddr;
    input[3:0] arid;

    output reg rvalid;
    input rready;
    output reg [31:0]rdata;
    output[1:0] rresp;
    output [3:0] rid;
    //write
    input awvalid;
    output awready;
    input [31:0] awaddr;

    input wvalid;
    output wready;
    input [31:0]wdata;
    input [3:0]wstrb;

    output bvalid;
    input bready;
    output[1:0] bresp;
    //read
    wire arfire,rfire;
    assign arfire=arvalid&&arready;
    assign rfire=rvalid&&rready;
    assign arready=!rvalid;
    assign rresp=2'b00;
    reg rid_reg;
    assign rid={3'd0,rid_reg};
    always @(posedge clk) begin
        if(arvalid&&arready)
            rid_reg<=arid[0];
    end
    //write
    reg aw_received,w_received;
    assign awready=!aw_received;
    assign wready =!w_received;
    assign bvalid=aw_received&&w_received;
    assign bresp =2'b00;
    always @(posedge clk) begin
        if(rst)begin
            aw_received<=1'b0;
            w_received <=1'b0;
        end else if(bvalid&&bready)begin
            aw_received<=1'b0;
            w_received <=1'b0;
        end else begin
            if(awvalid&&awready)
                aw_received<=1'b1;
            if(wvalid&&wready)
                w_received<=1'b1;
        end
    end
    reg [31:0]mtime_lo,mtime_hi;
    always @(posedge clk) begin
        if(rst) rvalid<=1'b0;
        else if(rfire) 
            rvalid<=1'b0;
        else if(arfire) begin
            rvalid<=1'b1;
            if(araddr[2])//0200bffc
                rdata<=mtime_hi;
            else //0200bff8
                rdata<=mtime_lo;
        end
    end
    //function
    reg lo_wrap;
    always @(posedge clk) begin
        if(rst)begin
            mtime_lo<=32'd0;
            mtime_hi<=32'd0;
            lo_wrap<=1'b0;
        end else begin
            mtime_lo<=mtime_lo+32'd1;
            lo_wrap<=(mtime_lo==32'hfffffffe);
            if(lo_wrap)
                mtime_hi<=mtime_hi+32'd1;
        end
    end
endmodule
