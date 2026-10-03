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
