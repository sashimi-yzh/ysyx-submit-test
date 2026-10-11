
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
    wire [67:0] ICACHE_IFU_wrapper;
    wire [37:0] IFU_ICACHE_wrapper;

    wire [31:0] btb_araddr,btb_target;
    wire btb_hit;
    ysyx_26040117_IFU #(.RESET_VECTOR(RESET_VECTOR)) IFU1(.clk(clock),.rst(reset),
        .redirect_valid(redirect_valid),.dnpc(redirect_dnpc),.fence_i(fence_i),
        .IFU_IDU_ready(IFU_IDU_ready),.IFU_IDU_valid(IFU_IDU_valid),.inst(inst),.pc(ifu_idu_pc),.fence_done(fence_done),.pred_taken(pred_taken),
        .idu_pc(idu_ifu_pc),
        .MEM_IFU_wrapper(ICACHE_IFU_wrapper),.IFU_MEM_wrapper(IFU_ICACHE_wrapper),
        .btb_araddr(btb_araddr),.btb_hit(btb_hit),.btb_target(btb_target)
    );
    ysyx_26040117_ICache ICache1(.clk(clock),.rst(reset),
        .IFU_ICACHE_wrapper(IFU_ICACHE_wrapper),.ICACHE_IFU_wrapper(ICACHE_IFU_wrapper),
        .MEM_ICACHE_wrapper(MEM_ICACHE_wrapper),.ICACHE_MEM_wrapper(ICACHE_MEM_wrapper)
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
    wire[49:0] LSU_wrapper;
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
