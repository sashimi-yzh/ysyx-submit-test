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
