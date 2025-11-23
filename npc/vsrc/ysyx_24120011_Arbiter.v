
module ysyx_24120011_Arbiter (
    input clk,
    input rst,
    //============M0=============//        
    //AR-axi4lite
    input  [31:0]     M0_araddr,
    input             M0_arvalid,
    output            M0_arready,
    //AR-axi4
    input  [3:0]      M0_arid,
    input  [7:0]      M0_arlen,
    input  [2:0]      M0_arsize,
    input  [1:0]      M0_arburst,
    //R-axi4lite               
    output [31:0]     M0_rdata,
    output [1:0]      M0_rresp,
    output            M0_rvalid,
    input             M0_rready,
    //R-axi4
    output            M0_rlast,
    output [3:0]      M0_rid,
    //AW-axi4lite
    input  [31:0]     M0_awaddr,
    input             M0_awvalid,
    output            M0_awready,
    //AW-axi4
    input  [3:0]      M0_awid,
    input  [7:0]      M0_awlen,
    input  [2:0]      M0_awsize,
    input  [1:0]      M0_awburst,
    //W-axi4lite
    input  [31:0]     M0_wdata,
    input  [3:0]      M0_wstrb,
    input             M0_wvalid,
    output            M0_wready,
    //W-axi4
    input             M0_wlast,
    //B-axi4lite
    output [1:0]      M0_bresp,
    output            M0_bvalid,
    input             M0_bready,
    //B-axi4
    output [3:0]	  M0_bid,
    //============M1=============//        
    //AR-axi4lite
    input  [31:0]     M1_araddr,
    input             M1_arvalid,
    output            M1_arready,
    //AR-axi4
    input  [3:0]      M1_arid,
    input  [7:0]      M1_arlen,
    input  [2:0]      M1_arsize,
    input  [1:0]      M1_arburst,
    //R-axi4lite               
    output [31:0]     M1_rdata,
    output [1:0]      M1_rresp,
    output            M1_rvalid,
    input             M1_rready,
    //R-axi4
    output            M1_rlast,
    output [3:0]      M1_rid,
    //AW-axi4lite
    input  [31:0]     M1_awaddr,
    input             M1_awvalid,
    output            M1_awready,
    //AW-axi4
    input  [3:0]      M1_awid,
    input  [7:0]      M1_awlen,
    input  [2:0]      M1_awsize,
    input  [1:0]      M1_awburst,
    //W-axi4lite
    input  [31:0]     M1_wdata,
    input  [3:0]      M1_wstrb,
    input             M1_wvalid,
    output            M1_wready,
    //W-axi4
    input             M1_wlast,
    //B-axi4lite
    output [1:0]      M1_bresp,
    output            M1_bvalid,
    input             M1_bready,
    //B-axi4
    output [3:0]	  M1_bid,
    //============S0=============//        
    //AR-axi4lite
    output  [31:0]     S0_araddr,
    output             S0_arvalid,
    input              S0_arready,
    //AR-axi4
    output  [3:0]      S0_arid,
    output  [7:0]      S0_arlen,
    output  [2:0]      S0_arsize,
    output  [1:0]      S0_arburst,
    //R-axi4lite               
    input   [31:0]     S0_rdata,
    input   [1:0]      S0_rresp,
    input              S0_rvalid,
    output             S0_rready,
    //R-axi4
    input              S0_rlast,
    input   [3:0]      S0_rid,
    //AW-axi4lite
    output  [31:0]     S0_awaddr,
    output             S0_awvalid,
    input              S0_awready,
    //AW-axi4
    output  [3:0]      S0_awid,
    output  [7:0]      S0_awlen,
    output  [2:0]      S0_awsize,
    output  [1:0]      S0_awburst,
    //W-axi4lite
    output  [31:0]     S0_wdata,
    output  [3:0]      S0_wstrb,
    output             S0_wvalid,
    input              S0_wready,
    //W-axi4
    output             S0_wlast,
    //B-axi4lite
    input   [1:0]      S0_bresp,
    input              S0_bvalid,
    output             S0_bready,
    //B-axi4
    input   [3:0]	  S0_bid
);

    parameter ysyx_24120011_Arbiter_IDLE = 3'b000;
    parameter ysyx_24120011_Arbiter_M0 = 3'b001;
    parameter ysyx_24120011_Arbiter_M1 = 3'b010;

    reg [2:0] state;
    reg [2:0] next_state;

    reg [2:0] last_master;

    wire done;

    wire [2:0] choose;

    assign done = (S0_rlast && S0_rready && S0_rvalid) || (S0_bready && S0_bvalid);
    //AR-AXILITE
    assign S0_araddr  = (state == ysyx_24120011_Arbiter_M0 ? M0_araddr :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_araddr : 'b0));
    assign S0_arvalid = (state == ysyx_24120011_Arbiter_M0 ? M0_arvalid :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_arvalid : 'b0));
    assign M0_arready = (state == ysyx_24120011_Arbiter_M0 ? S0_arready :'b0);
    assign M1_arready = (state == ysyx_24120011_Arbiter_M1 ? S0_arready :'b0);
    //AR-AXI
    assign S0_arid  = (state == ysyx_24120011_Arbiter_M0 ? M0_arid :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_arid : 'b0));
    assign S0_arlen  = (state == ysyx_24120011_Arbiter_M0 ? M0_arlen :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_arlen : 'b0));
    assign S0_arsize  = (state == ysyx_24120011_Arbiter_M0 ? M0_arsize :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_arsize : 'b0));
    assign S0_arburst  = (state == ysyx_24120011_Arbiter_M0 ? M0_arburst :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_arburst : 'b0));
    //R-AXILITE
    assign M0_rdata   = (state == ysyx_24120011_Arbiter_M0 ? S0_rdata :'b0);
    assign M1_rdata   = (state == ysyx_24120011_Arbiter_M1 ? S0_rdata :'b0);       
    assign M0_rresp   = (state == ysyx_24120011_Arbiter_M0 ? S0_rresp :'b0);
    assign M1_rresp   = (state == ysyx_24120011_Arbiter_M1 ? S0_rresp :'b0); 
    assign M0_rvalid  = (state == ysyx_24120011_Arbiter_M0 ? S0_rvalid :'b0);
    assign M1_rvalid  = (state == ysyx_24120011_Arbiter_M1 ? S0_rvalid :'b0); 
    assign S0_rready  = (state == ysyx_24120011_Arbiter_M0 ? M0_rready :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_rready : 'b0));
    //R-AXI
    assign M0_rlast   = (state == ysyx_24120011_Arbiter_M0 ? S0_rlast :'b0);
    assign M1_rlast   = (state == ysyx_24120011_Arbiter_M1 ? S0_rlast :'b0);  
    assign M0_rid   = (state == ysyx_24120011_Arbiter_M0 ? S0_rid :'b0);
    assign M1_rid   = (state == ysyx_24120011_Arbiter_M1 ? S0_rid :'b0);  
    //AW-AXILITE
    assign S0_awaddr  = (state == ysyx_24120011_Arbiter_M0 ? M0_awaddr :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_awaddr : 'b0));
    assign S0_awvalid = (state == ysyx_24120011_Arbiter_M0 ? M0_awvalid :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_awvalid : 'b0));
    assign M0_awready = (state == ysyx_24120011_Arbiter_M0 ? S0_awready :'b0);
    assign M1_awready = (state == ysyx_24120011_Arbiter_M1 ? S0_awready :'b0); 
    //AW-AXI
    assign S0_awid  = (state == ysyx_24120011_Arbiter_M0 ? M0_awid :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_awid : 'b0));
    assign S0_awlen  = (state == ysyx_24120011_Arbiter_M0 ? M0_awlen :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_awlen : 'b0));
    assign S0_awsize  = (state == ysyx_24120011_Arbiter_M0 ? M0_awsize :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_awsize : 'b0));
    assign S0_awburst  = (state == ysyx_24120011_Arbiter_M0 ? M0_awburst :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_awburst : 'b0));
    //W-AXILITE
    assign S0_wdata   = (state == ysyx_24120011_Arbiter_M0 ? M0_wdata :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_wdata : 'b0));
    assign S0_wstrb   = (state == ysyx_24120011_Arbiter_M0 ? M0_wstrb :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_wstrb : 'b0));
    assign S0_wvalid  = (state == ysyx_24120011_Arbiter_M0 ? M0_wvalid :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_wvalid : 'b0));
    assign M0_wready  = (state == ysyx_24120011_Arbiter_M0 ? S0_wready :'b0);
    assign M1_wready  = (state == ysyx_24120011_Arbiter_M1 ? S0_wready :'b0);
    //W-AXI
    assign S0_wlast  = (state == ysyx_24120011_Arbiter_M0 ? M0_wlast :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_wlast : 'b0));
    //B-AXILITE
    assign M0_bresp   = (state == ysyx_24120011_Arbiter_M0 ? S0_bresp :'b0);
    assign M1_bresp   = (state == ysyx_24120011_Arbiter_M1 ? S0_bresp :'b0);
    assign M0_bvalid  = (state == ysyx_24120011_Arbiter_M0 ? S0_bvalid :'b0);
    assign M1_bvalid  = (state == ysyx_24120011_Arbiter_M1 ? S0_bvalid :'b0);
    assign S0_bready  = (state == ysyx_24120011_Arbiter_M0 ? M0_bready :
                       (state == ysyx_24120011_Arbiter_M1 ? M1_bready : 'b0));
    //B-AXI
    assign M0_bid   = (state == ysyx_24120011_Arbiter_M0 ? S0_bid :'b0);
    assign M1_bid   = (state == ysyx_24120011_Arbiter_M1 ? S0_bid :'b0);
    
    //状态跳转
    always@(posedge clk)begin
        if(rst)begin
            state <= ysyx_24120011_Arbiter_IDLE;
        end
        else begin
            state <= next_state;
        end
    end
    //保存上一次连通的主机
    always@(posedge clk)begin
        if(rst)begin
            last_master <= 3'd1;//use highest index to start from M0
        end
        else begin
            if (done) begin
                if (state == ysyx_24120011_Arbiter_M0)
                    last_master <= 'd0;
                else if (state == ysyx_24120011_Arbiter_M1)
                    last_master <= 'd1;
            end
        end
    end
    //next_state切换
    always@(*)begin
        case(state)
            ysyx_24120011_Arbiter_IDLE:begin
                if(last_master == 3'd1)begin
                    if(M0_arvalid || M0_awvalid)begin
                        next_state = ysyx_24120011_Arbiter_M0;
                    end
                    else if(M1_arvalid || M1_awvalid)begin
                        next_state = ysyx_24120011_Arbiter_M1;
                    end
                    else begin
                        next_state = ysyx_24120011_Arbiter_IDLE;
                    end
                end
                else if(last_master == 3'd0)begin
                    if(M1_arvalid || M1_awvalid)begin
                        next_state = ysyx_24120011_Arbiter_M1;
                    end
                    else if(M0_arvalid || M0_awvalid)begin
                        next_state = ysyx_24120011_Arbiter_M0;
                    end
                    else begin
                        next_state = ysyx_24120011_Arbiter_IDLE;
                    end
                end
                else begin
                    next_state = ysyx_24120011_Arbiter_IDLE;
                end
            end
            ysyx_24120011_Arbiter_M0:begin
                if(done)begin
                    if(M1_arvalid || M1_awvalid)begin
                        next_state = ysyx_24120011_Arbiter_M1;
                    end
                    else if(M0_arvalid || M0_awvalid)begin
                        next_state = ysyx_24120011_Arbiter_M0;
                    end
                    else begin
                        next_state = ysyx_24120011_Arbiter_IDLE;
                    end
                end
                else begin
                    next_state = ysyx_24120011_Arbiter_M0;
                end
            end
            ysyx_24120011_Arbiter_M1:begin
                if(done)begin
                    if(M0_arvalid || M0_awvalid)begin
                        next_state = ysyx_24120011_Arbiter_M0;
                    end
                    else if(M1_arvalid ||M1_awvalid)begin
                        next_state = ysyx_24120011_Arbiter_M1;
                    end
                    else begin
                        next_state = ysyx_24120011_Arbiter_IDLE;
                    end
                end
                else begin
                    next_state = ysyx_24120011_Arbiter_M1;
                end
            end
            default:next_state = ysyx_24120011_Arbiter_IDLE;
        endcase
    end
endmodule