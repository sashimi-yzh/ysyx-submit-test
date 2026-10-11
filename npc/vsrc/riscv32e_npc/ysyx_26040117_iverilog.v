module ysyx_26040117_iverilog(
    input clock,
    input reset
);
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
    reg          io_master_bvalid;
    wire [1:0]   io_master_bresp;
    reg [3:0]    io_master_bid;

    wire         io_master_arready;
    wire         io_master_arvalid;
    wire [31:0]  io_master_araddr;
    wire [3:0]   io_master_arid;
    wire [7:0]   io_master_arlen;
    wire [2:0]   io_master_arsize;
    wire [1:0]   io_master_arburst;

    wire         io_master_rready;
    reg          io_master_rvalid;
    wire [1:0]   io_master_rresp;
    reg  [31:0]  io_master_rdata;
    wire         io_master_rlast;
    reg [3:0]    io_master_rid;
    
    assign io_master_awready=!io_master_bvalid;
    assign io_master_wready=!io_master_bvalid;
    assign io_master_arready=!io_master_rvalid;
    assign io_master_bresp=2'b0;
    assign io_master_rresp=2'b0;
    assign io_master_rlast=(io_master_arlen==8'd0);
    wire awfire,wfire,arfire,rfire,bfire;
    assign awfire=io_master_awvalid&&io_master_awready;
    assign wfire =io_master_wvalid &&io_master_wready;
    assign bfire =io_master_bvalid &&io_master_bready;
    assign arfire=io_master_arvalid&&io_master_arready;
    assign rfire =io_master_rvalid &&io_master_rready;
    always @(posedge clock) begin
        if(reset)begin
            io_master_bvalid<=1'b0;
            io_master_rvalid<=1'b0;
        end else begin
            if(bfire)
                io_master_bvalid<=1'b0;
            else if(awfire&&wfire)
                io_master_bvalid<=1'b1;
            if(rfire)
                io_master_rvalid<=1'b0;
            else if(arfire)
                io_master_rvalid<=1'b1;
            if(awfire&&wfire)
                io_master_bid<=io_master_awid;
            if(arfire)
                io_master_rid<=io_master_arid;
        end
    end
    localparam MEM_WIDTH=20;
    localparam MEM_DEPTH=2**MEM_WIDTH;
    reg[31:0] mem[0:MEM_DEPTH-1];
    integer i;
    initial begin
        for(i=0;i<MEM_DEPTH;i=i+1)
            mem[i]=32'b0;
        $readmemh("build/iverilog.hex",mem);
    end
    always @(posedge clock) begin
        if(reset)
            io_master_rdata <= 32'b0;
        else if(arfire) begin
            case(io_master_araddr)
                32'h30000000: io_master_rdata <= 32'h800002b7;//lui t0, 0x80000
                32'h30000004: io_master_rdata <= 32'h00028067;//jalr zero, 0(t0)
                default:io_master_rdata <= mem[io_master_araddr[2 +: MEM_WIDTH]];
            endcase
        end
    end
    wire[31:0]data_replace,data_origin;
    wire [31:0]mask_replace,mask_origin;
    assign mask_replace={{8{io_master_wstrb[3]}},{8{io_master_wstrb[2]}},{8{io_master_wstrb[1]}},{8{io_master_wstrb[0]}}};
    assign mask_origin=~mask_replace;
    assign data_origin=mem[io_master_awaddr[2 +: MEM_WIDTH]]&mask_origin;
    assign data_replace=io_master_wdata&mask_replace;
    always @(posedge clock) begin
        if(!reset&&awfire&&wfire)begin
            if(io_master_awaddr>=32'h80000000&&io_master_awaddr<=32'h9fffffff)
                mem[io_master_awaddr[2 +: MEM_WIDTH]]<=data_origin|data_replace;
            else if(io_master_awaddr==32'h10000000)begin
                if(io_master_wstrb[0])begin
                    $write("%c",io_master_wdata[7:0]);
                    $fflush();
                end
            end
        end
    end


    ysyx_26040117 cpu (
    .clock                   (clock),
    .reset                   (reset),
    .io_interrupt            (1'h0),	
    .io_master_awready      (io_master_awready),
    .io_master_awvalid      (io_master_awvalid),
    .io_master_awid    (io_master_awid),
    .io_master_awaddr  (io_master_awaddr),
    .io_master_awlen   (io_master_awlen),
    .io_master_awsize  (io_master_awsize),
    .io_master_awburst (io_master_awburst),
    .io_master_wready       (io_master_wready),
    .io_master_wvalid       (io_master_wvalid),
    .io_master_wdata   (io_master_wdata),
    .io_master_wstrb   (io_master_wstrb),
    .io_master_wlast   (io_master_wlast),
    .io_master_bready       (io_master_bready),
    .io_master_bvalid       (io_master_bvalid),
    .io_master_bid     (io_master_bid),
    .io_master_bresp   (io_master_bresp),
    .io_master_arready      (io_master_arready),
    .io_master_arvalid      (io_master_arvalid),
    .io_master_arid    (io_master_arid),
    .io_master_araddr  (io_master_araddr),
    .io_master_arlen   (io_master_arlen),
    .io_master_arsize  (io_master_arsize),
    .io_master_arburst (io_master_arburst),
    .io_master_rready       (io_master_rready),
    .io_master_rvalid       (io_master_rvalid),
    .io_master_rid     (io_master_rid),
    .io_master_rdata   (io_master_rdata),
    .io_master_rresp   (io_master_rresp),
    .io_master_rlast   (io_master_rlast),
    .io_slave_awready       (/* unused */),
    .io_slave_awvalid       (1'h0),	
    .io_slave_awid     (4'h0),
    .io_slave_awaddr   (32'h0),	
    .io_slave_awlen    (8'h0),	
    .io_slave_awsize   (3'h0),	
    .io_slave_awburst  (2'h0),	
    .io_slave_wready        (/* unused */),
    .io_slave_wvalid        (1'h0),	
    .io_slave_wdata    (32'h0),	
    .io_slave_wstrb    (4'h0),	
    .io_slave_wlast    (1'h0),	
    .io_slave_bready        (1'h0),	
    .io_slave_bvalid        (/* unused */),
    .io_slave_bid      (/* unused */),
    .io_slave_bresp    (/* unused */),
    .io_slave_arready       (/* unused */),
    .io_slave_arvalid       (1'h0),	
    .io_slave_arid     (4'h0),	
    .io_slave_araddr   (32'h0),	
    .io_slave_arlen    (8'h0),	
    .io_slave_arsize   (3'h0),	
    .io_slave_arburst  (2'h0),	
    .io_slave_rready        (1'h0),	
    .io_slave_rvalid        (/* unused */),
    .io_slave_rid      (/* unused */),
    .io_slave_rdata    (/* unused */),
    .io_slave_rresp    (/* unused */),
    .io_slave_rlast    (/* unused */)
  );


endmodule
