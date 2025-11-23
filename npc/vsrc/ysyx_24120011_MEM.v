import "DPI-C" function void LSU_clktime_count(input int lsu_clk_count);

module ysyx_24120011_MEM(
    input clk,
    input rst,
    //数据
    input [6:0]  i_mem_ctrl,
    input [31:0] i_src2,
    input [3:0]  i_rd,
    input [11:0] i_w_csr_addr,
    input [31:0] i_ALU_result,

    input [31:0] i_rd_data,
    input [1:0]  i_rd_data_type,
    input [31:0] i_w_csr_data,
    input i_w_csr_en,
    input i_w_csr_ecall,


    output [3:0]  o_rd,
    output [11:0] o_w_csr_addr,

    output [31:0] o_rd_data,
    output        o_rd_data_en,
    output [31:0] o_w_csr_data,
    output o_w_csr_en,
    output o_w_csr_ecall,
    output [1:0] o_rd_data_type,
    //握手
    input  i_EXU_valid,
    output o_MEM_ready,
    input  i_WBU_ready,
    output o_MEM_valid,
    //============M1=============//        
    //AR-axi4lite
    output  [31:0]     M1_araddr,
    output             M1_arvalid,
    input              M1_arready,
    //AR-axi4
    output  [3:0]      M1_arid,
    output  [7:0]      M1_arlen,
    output  [2:0]      M1_arsize,
    output  [1:0]      M1_arburst,
    //R-axi4lite            
    input   [31:0]     M1_rdata,
    input   [1:0]      M1_rresp,
    input              M1_rvalid,
    output             M1_rready,
    //R-axi4
    input              M1_rlast,
    input   [3:0]      M1_rid,
    //AW-axi4lite
    output  [31:0]     M1_awaddr,
    output             M1_awvalid,
    input              M1_awready,
    //AW-axi4
    output  [3:0]      M1_awid,
    output  [7:0]      M1_awlen,
    output  [2:0]      M1_awsize,
    output  [1:0]      M1_awburst,
    //W-axi4lite
    output  [31:0]     M1_wdata,
    output  [3:0]      M1_wstrb,
    output             M1_wvalid,
    input              M1_wready,
    //W-axi4
    output             M1_wlast,
    //B-axi4lite
    input   [1:0]      M1_bresp,
    input              M1_bvalid,
    output             M1_bready,
    //B-axi4
    input	[3:0]	   M1_bid
);

reg [6:0]  mem_ctrl;
reg [31:0] src2;
reg [3:0]  rd;
reg [11:0] w_csr_addr;
reg [31:0] ALU_result;
reg [31:0] r_mem_data;

reg [31:0] rd_data;
reg [1:0]  rd_data_type;
reg [31:0] w_csr_data;
reg w_csr_en;
reg w_csr_ecall;

assign o_MEM_ready  = (state == ysyx_24120011_LSU_M_AXI_IDLE_EMPTY) ? 1'b1 : 1'b0;
assign o_MEM_valid  = (state != ysyx_24120011_LSU_M_AXI_IDLE_EMPTY) && (next_state == ysyx_24120011_LSU_M_AXI_IDLE_EMPTY) ? 1'b1 : 1'b0;
assign o_rd         = rd        ;
assign o_w_csr_addr = w_csr_addr;

assign  o_rd_data = rd_data_type == 2'd1 ? r_mem_data : rd_data;
assign  o_rd_data_en = (rd_data_type != 2'd0 && o_MEM_valid) ? 1'b1 : 1'b0;
assign  o_w_csr_data = w_csr_data;
assign  o_w_csr_en = w_csr_en;
assign  o_w_csr_ecall = w_csr_ecall;


assign o_rd_data_type = rd_data_type;
//指令锁存
always @(posedge clk) begin
    // if(rst) begin
    //     mem_ctrl   <=  'd0;
    //     src2       <=  'd0;
    //     rd         <=  'd0;
    //     w_csr_addr <=  'd0;
    //     ALU_result <=  'd0;

    //     rd_data      <=  'd0;
    //     rd_data_type <=  'd0;
    //     w_csr_data   <=  'd0;
    //     w_csr_en     <=  'd0;
    //     w_csr_ecall  <=  'd0;
    // end
    //else begin
        //输入握手
        if(i_EXU_valid && o_MEM_ready) begin
            mem_ctrl   <=  i_mem_ctrl  ;
            src2       <=  i_src2      ;
            rd         <=  i_rd        ;
            w_csr_addr <=  i_w_csr_addr;
            ALU_result <=  i_ALU_result;

            rd_data      <=  i_rd_data     ;
            rd_data_type <=  i_rd_data_type;
            w_csr_data   <=  i_w_csr_data  ;
            w_csr_en     <=  i_w_csr_en    ;
            w_csr_ecall  <=  i_w_csr_ecall ;
        end
    //end
end


    assign M1_araddr  = araddr    ;
    assign M1_arvalid = arvalid   ;
    assign arready    = M1_arready;
    assign rdata       = M1_rdata ;
    assign rresp      = M1_rresp  ;
    assign rvalid     = M1_rvalid ;
    assign M1_rready  = rready    ;
    assign M1_awaddr  = awaddr    ;
    assign M1_awvalid = awvalid   ;
    assign awready    = M1_awready;
    assign M1_wdata   = wdata     ;
    assign M1_wstrb   = wstrb     ;
    assign M1_wvalid  = wvalid    ;
    assign wready     = M1_wready ;
    assign bresp      = M1_bresp  ;
    assign bvalid     = M1_bvalid ;
    assign M1_bready  = bready    ;   

    assign M1_arid    = 'd0       ;
    assign M1_arlen   = 'd0       ;
    assign M1_arburst = 'd0       ;
    assign M1_arsize  = ~M1_arvalid ? 3'b010 : (
           ({3{mem_ctrl[4:3] == 2'd0}} & 3'b000) |
           ({3{mem_ctrl[4:3] == 2'd1}} & 3'b001) |
           ({3{mem_ctrl[4:3] == 2'd2}} & 3'b010) |
           (3'b000)
         );
    assign M1_awid    = 'd0       ;
    assign M1_awlen   = 'd0       ;
    assign M1_awburst = 'd0       ;
    assign M1_awsize  = ~M1_awvalid ? 3'b010 : (
           ({3{mem_ctrl[1:0] == 2'd0}} & 3'b000) |
           ({3{mem_ctrl[1:0] == 2'd1}} & 3'b001) |
           ({3{mem_ctrl[1:0] == 2'd2}} & 3'b010) |
           (3'b000)
         );
    assign M1_wlast   = M1_wvalid ;


    parameter ysyx_24120011_LSU_M_AXI_IDLE_EMPTY = 3'b000;
    parameter ysyx_24120011_LSU_M_AXI_IDLE_FULL  = 3'b001;
    parameter ysyx_24120011_LSU_M_AXI_RWCHECK    = 3'b010;
    parameter ysyx_24120011_LSU_M_AXI_RADDR      = 3'b011;
    parameter ysyx_24120011_LSU_M_AXI_RDATA      = 3'b100;
    parameter ysyx_24120011_LSU_M_AXI_WADDR      = 3'b101;
    parameter ysyx_24120011_LSU_M_AXI_WDATA      = 3'b110;
    parameter ysyx_24120011_LSU_M_AXI_WRESP      = 3'b111;
    parameter ysyx_24120011_LSU_M_AXI_RESP_OKAY  = 2'b00;

    reg [2:0] state;
    reg [2:0] next_state;

    wire [31:0] araddr;
    reg arvalid;
    wire arready;
    reg rready;
    wire [1:0] rresp;
    wire rvalid;
    reg awvalid;
    wire awready;
    wire [31:0] awaddr;
    reg wvalid;
    wire wready;
    wire [31:0] wdata;
    wire [1:0] bresp;
    wire [3:0] wstrb;
    wire bready;
    wire [31:0] rdata;
    wire bvalid;


    reg [3:0] reg_wstrb;
    reg [31:0] reg_wdata;
    reg [5:0] wdata_format;
    reg [31:0] rdata_mask;

    //AR
    assign araddr = ALU_result;
    //assign arvalid = (state == ysyx_24120011_LSU_M_AXI_RADDR) ? 1 : 0;

    //R
    //assign rready = (state == ysyx_24120011_LSU_M_AXI_RDATA) ? 1 : 0;

    //AW
    //assign awvalid = (state == ysyx_24120011_LSU_M_AXI_WADDR) ? 1 : 0;
    //assign awaddr = (state == ysyx_24120011_LSU_M_AXI_WADDR) ? w_mem_addr : 32'b0;
    assign awaddr = ALU_result;

    //W
    //assign wvalid = (state == ysyx_24120011_LSU_M_AXI_WDATA) ? 1 : 0;
    assign wdata = reg_wdata; //(state == ysyx_24120011_LSU_M_AXI_WDATA) ? src2 : 32'b0;
    assign wstrb = reg_wstrb;
    //B
    assign bready = (state == ysyx_24120011_LSU_M_AXI_WRESP || state == ysyx_24120011_LSU_M_AXI_WDATA) ? 1 : 0;

//======================dpic========================//
reg [31:0] cycle_counter;  // 时钟周期计数器
reg LSU_working_delay;
always @(posedge clk) begin
    if (rst) begin
        cycle_counter <= 0;
        LSU_working_delay <= 0;
    end else begin
        LSU_working_delay <= ~o_MEM_ready;

        if (state == ysyx_24120011_LSU_M_AXI_IDLE_EMPTY) begin
            LSU_clktime_count(cycle_counter);
            cycle_counter <= 0;
        end
        else begin
            cycle_counter <= cycle_counter + 1'b1;
        end
    end
end
//======================dpic========================//


    always@(*)begin
        if(mem_ctrl[4:3] == 2'd0) begin
            if(araddr[1:0] == 2'd0)begin
                rdata_mask = {24'b0,rdata[7:0]};
            end
            else if(araddr[1:0] == 2'd1)begin
                rdata_mask = {24'b0,rdata[15:8]};
            end
            else if(araddr[1:0] == 2'd2)begin
                rdata_mask = {24'b0,rdata[23:16]};
            end
            else begin
                rdata_mask = {24'b0,rdata[31:24]};
            end
        end
        else if(mem_ctrl[4:3] == 2'd1)begin
            rdata_mask = rdata;
            if(araddr[1:0] == 2'd0)begin
                rdata_mask = {16'b0,rdata[15:0]};
            end
            else if(araddr[1:0] == 2'd1)begin
                rdata_mask = {16'b0,rdata[23:8]};
            end
            else if(araddr[1:0] == 2'd2)begin
                rdata_mask = {16'b0,rdata[31:16]};
            end
            else begin
                rdata_mask = 32'hdeadbeef;
            end
        end
        else if(mem_ctrl[4:3] == 2'd2) begin
            rdata_mask = rdata;
        end
        else begin
            rdata_mask = rdata;
        end
    end
    always@(*)begin
        case(wdata_format)
        'd0:reg_wdata = {24'b0,src2[7:0]};
        'd1:reg_wdata = {16'b0,src2[7:0],8'b0};
        'd2:reg_wdata = {8'b0,src2[7:0],16'b0};
        'd3:reg_wdata = {src2[7:0],24'b0};
        'd4:reg_wdata = {16'b0,src2[15:0]};
        'd5:reg_wdata = {8'b0,src2[15:0],8'b0};
        'd6:reg_wdata = {src2[15:0],16'b0};
        'd7:reg_wdata = src2;
        default:reg_wdata = 32'hdeadbeef;
        endcase
    end
    always@(*)begin
        if(mem_ctrl[1:0] == 2'd0) begin
            if(awaddr[1:0] == 2'd0)begin
                reg_wstrb = 4'b0001;
                wdata_format = 'd0;
            end
            else if(awaddr[1:0] == 2'd1)begin
                reg_wstrb = 4'b0010;
                wdata_format = 'd1;
            end
            else if(awaddr[1:0] == 2'd2)begin
                reg_wstrb = 4'b0100;
                wdata_format = 'd2;
            end
            else begin
                reg_wstrb = 4'b1000;
                wdata_format = 'd3;
            end
        end
        else if(mem_ctrl[1:0] == 2'd1)begin
            if(awaddr[1:0] == 2'd0)begin
                reg_wstrb = 4'b0011;
                wdata_format = 'd4;
            end
            else if(awaddr[1:0] == 2'd1)begin
                reg_wstrb = 4'b0110;
                wdata_format = 'd5;
            end
            else if(awaddr[1:0] == 2'd2)begin
                reg_wstrb = 4'b1100;
                wdata_format = 'd6;
            end
            else begin
                reg_wstrb = 4'b0000;
                wdata_format = 'd63;
            end
        end
        else if(mem_ctrl[1:0] == 2'd2) begin
            reg_wstrb = 4'b1111;
            wdata_format = 'd7;
        end
        else begin
            reg_wstrb = 4'b0000;//shouldnt enter
            wdata_format = 'd63;
        end
    end
    //arvalid
    always@(posedge clk)begin
        if(state == ysyx_24120011_LSU_M_AXI_RADDR)begin
            if(arready)begin
                arvalid <= 0;
            end
            else begin
                arvalid <= 1;
            end
        end
        else begin
            arvalid <= 0;
        end
    end
    

    //awvalid
    always@(posedge clk)begin
        if(state == ysyx_24120011_LSU_M_AXI_WADDR)begin
            if(awready)begin
                awvalid <= 0;
                wvalid <= 0;
            end
            else begin
                awvalid <= 1;
                wvalid <= 1;
            end
        end
        else begin
            awvalid <= 0;
            wvalid <= 0;
        end
    end

    //rready
    always@(posedge clk)begin
        if(state == ysyx_24120011_LSU_M_AXI_RDATA)begin
            if(rvalid == 1) begin
                rready <= 1;
            end
            else begin
                rready <= 0;
            end
        end
        else begin
            rready <= 0;
        end
    end



    always@(posedge clk)begin
        if(rst) begin
            r_mem_data <= 32'b0;
        end
        else begin
            if(state == ysyx_24120011_LSU_M_AXI_RDATA) begin
                if(mem_ctrl[4:3] == 2'd0)begin
                    if(mem_ctrl[6])begin
                        r_mem_data <= {{24{rdata_mask[7]}},rdata_mask[7:0]};
                    end
                    else begin
                        r_mem_data <= {24'b0,rdata_mask[7:0]};
                    end
                end
                else if(mem_ctrl[4:3] == 2'd1)begin
                    if(mem_ctrl[6])begin
                        r_mem_data <= {{16{rdata_mask[15]}},rdata_mask[15:0]};
                    end
                    else begin
                        r_mem_data <= {16'b0,rdata_mask[15:0]};
                    end
                end
                else if(mem_ctrl[4:3] == 2'd2)begin
                    r_mem_data <= rdata_mask;
                end
                else begin//shouldn't in
                    r_mem_data <= 32'b11111111;
                end
            end
        end
    end

    always@(*)begin
        case(state)
            ysyx_24120011_LSU_M_AXI_IDLE_EMPTY: next_state = (i_EXU_valid && o_MEM_ready) ? ysyx_24120011_LSU_M_AXI_IDLE_FULL : ysyx_24120011_LSU_M_AXI_IDLE_EMPTY;
            ysyx_24120011_LSU_M_AXI_IDLE_FULL : next_state = (i_WBU_ready) ? ysyx_24120011_LSU_M_AXI_RWCHECK : ysyx_24120011_LSU_M_AXI_IDLE_FULL;
            ysyx_24120011_LSU_M_AXI_RWCHECK   : next_state = (mem_ctrl[5]) ? 
                                                       ysyx_24120011_LSU_M_AXI_RADDR : 
                                                       ((mem_ctrl[2]) ? ysyx_24120011_LSU_M_AXI_WADDR : ysyx_24120011_LSU_M_AXI_IDLE_EMPTY);
            ysyx_24120011_LSU_M_AXI_RADDR     : next_state = (arvalid && arready) ? ysyx_24120011_LSU_M_AXI_RDATA      : ysyx_24120011_LSU_M_AXI_RADDR;
            ysyx_24120011_LSU_M_AXI_RDATA     : next_state = (rvalid  && rready ) ? ysyx_24120011_LSU_M_AXI_IDLE_EMPTY : ysyx_24120011_LSU_M_AXI_RDATA;
            ysyx_24120011_LSU_M_AXI_WADDR     : begin 
                if (wvalid  && wready ) begin 
                    next_state = ysyx_24120011_LSU_M_AXI_WRESP;
                end
                else begin
                    next_state = (awvalid && awready) ? ysyx_24120011_LSU_M_AXI_WDATA : ysyx_24120011_LSU_M_AXI_WADDR;
                end
            end
            ysyx_24120011_LSU_M_AXI_WDATA     : next_state = (wvalid  && wready )? ysyx_24120011_LSU_M_AXI_WRESP      : ysyx_24120011_LSU_M_AXI_WDATA;
            ysyx_24120011_LSU_M_AXI_WRESP     : next_state = (bvalid  && bready )? ysyx_24120011_LSU_M_AXI_IDLE_EMPTY : ysyx_24120011_LSU_M_AXI_WRESP;
            default                           : next_state = ysyx_24120011_LSU_M_AXI_IDLE_EMPTY;
        endcase
    end

    always@(posedge clk)begin
        if(rst) begin
            state <= ysyx_24120011_LSU_M_AXI_IDLE_EMPTY;
        end
        else begin
            state <= next_state;
        end
    end
endmodule