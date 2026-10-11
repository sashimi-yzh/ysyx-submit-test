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
    assign awready=1'b0;
    assign wready =1'b0;
    assign bvalid=1'b0;;
    assign bresp =2'b00;

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
    /*
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
    */
    always @(posedge clk) begin
        if(rst)
            {mtime_hi,mtime_lo}<=64'd0;
        else 
            {mtime_hi,mtime_lo}<={mtime_hi,mtime_lo}+64'd1;
    end
endmodule
