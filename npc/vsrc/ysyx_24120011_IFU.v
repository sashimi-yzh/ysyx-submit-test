import "DPI-C" function void IFU_clktime_count(input int ifu_clk_count,input int hit);
import "DPI-C" function void icahce_miss_count(input int miss_count);
module ysyx_24120011_IFU(
    input clk,
    input rst,
    //数据
    input  [31:0] i_pc,
    output [31:0] o_pc,
    output [31:0] o_inst,
    //握手
    input  i_EXU_valid,
    output o_IFU_ready,
    input  i_IDU_ready,
    output o_IFU_valid,
    //AR-axi4lite
    output  [31:0]     M0_araddr,
    output             M0_arvalid,
    input            M0_arready,
    //AR-axi4
    output  [3:0]      M0_arid,
    output  [7:0]      M0_arlen,
    output  [2:0]      M0_arsize,
    output  [1:0]      M0_arburst,
    //R-axi4lite               
    input [31:0]     M0_rdata,
    input [1:0]      M0_rresp,
    input            M0_rvalid,
    output             M0_rready,
    //R-axi4
    input              M0_rlast,
    input   [3:0]      M0_rid,
    //AW-axi4lite
    output  [31:0]     M0_awaddr,
    output             M0_awvalid,
    input            M0_awready,
    //AW-axi4
    output  [3:0]      M0_awid,
    output  [7:0]      M0_awlen,
    output  [2:0]      M0_awsize,
    output  [1:0]      M0_awburst,
    //W-axi4lite
    output  [31:0]     M0_wdata,
    output  [3:0]      M0_wstrb,
    output             M0_wvalid,
    input            M0_wready,
    //W-axi4
    output             M0_wlast,
    //B-axi4lite
    input [1:0]      M0_bresp,
    input            M0_bvalid,
    output             M0_bready,
    //B-axi4
    input	[3:0]	   M0_bid,
    //flush
    input i_flush
);
parameter ysyx_24120011_PC_INITIAL  = 32'h3000_0000;
reg [31:0] pc;
reg [31:0] inst;

assign o_pc = pc;
assign o_inst = inst;

reg flushing;
always @(posedge clk) begin
    if (rst) begin
        flushing <= 1'b0;
    end else begin
        if (i_flush) begin
            flushing <= 1'b1;
        end
        else begin
            if (state == ysyx_24120011_IFU_IDLE_FULL) begin
                flushing <= 1'b0;
            end
        end
    end
end

//指令锁存
always @(posedge clk) begin
    if(rst) begin
        pc         <=  ysyx_24120011_PC_INITIAL;
    end
    else begin
        //输入握手
        if(!i_flush && !flushing) begin
            if(o_IFU_valid && o_IFU_ready) begin
                //pc         <=  i_pc        ;
                if ((inst[6:0] == 7'b1100011) && inst[31]) begin//B-Type,inst[31]是1，则imm为负数，则跳转
                    pc <= pc + {{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0};
                end 
                else if (inst[6:0] == 7'b1101111) begin//jal
                    pc <= pc + {{11{inst[31]}},inst[31],inst[19:12],inst[20],inst[30:21],1'b0};
                end
                else begin
                    pc <= pc + 32'd4;
                end
            end
        end
        else begin
            if(state == ysyx_24120011_IFU_IDLE_EMPTY || state == ysyx_24120011_IFU_IDLE_FULL) begin
                pc <= i_pc;//写入EXU的npc
            end
        end
    end
end
// always @(*) begin
//     pc         =  i_pc        ;
// end
//IFU逻辑
parameter ysyx_24120011_IFU_IDLE_EMPTY      = 3'b000;
parameter ysyx_24120011_IFU_IDLE_FULL       = 3'b001;
parameter ysyx_24120011_IFU_LOOKUP          = 3'b010;
parameter ysyx_24120011_IFU_AXI_RADDR       = 3'b011;
parameter ysyx_24120011_IFU_AXI_RDATA       = 3'b100;

//======================dpic========================//
reg [31:0] cycle_counter;  // 时钟周期计数器
reg [31:0] miss_counter;
always @(posedge clk) begin
    if (rst) begin
        cycle_counter <= 0;
    end else begin
        if (state == ysyx_24120011_IFU_IDLE_EMPTY) begin
            cycle_counter <= 0;
        end
        else begin
            cycle_counter <= cycle_counter + 1'b1;
        end
        if (o_IFU_valid) begin
            if(cache_IFU_valid) begin
                IFU_clktime_count(cycle_counter,1);
            end
            else begin
                IFU_clktime_count(cycle_counter,0);
            end
        end
    end
end
always @(posedge clk) begin
    if (rst) begin
        miss_counter <= 0;
    end else begin
        icahce_miss_count(miss_counter);
        if (state == ysyx_24120011_IFU_LOOKUP && next_state == ysyx_24120011_IFU_AXI_RADDR) begin
            miss_counter <= miss_counter + 1;
        end
        else begin
            miss_counter <= miss_counter;
        end
    end
end
//======================dpic========================//

//====================IFU====================//
reg [2:0] state;
reg [2:0] next_state;
reg cache_IFU_valid;

assign o_IFU_valid  = !i_flush && !flushing && cache_IFU_valid;
assign o_IFU_ready  = (state == ysyx_24120011_IFU_IDLE_EMPTY) ? 1'b1 : 1'b0;
//====================IFU====================//

// //====================icache====================//
// parameter ysyx_24120011_ICACHE_SIZE   = 32'd8;
// parameter ysyx_24120011_ICACHE_NUM    = 32'd2;
// //  valid                                       tag                                                 data
// reg [(1) + (32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))) + (8*ysyx_24120011_ICACHE_SIZE)-1:0] icache [ysyx_24120011_ICACHE_NUM-1 : 0];

// wire [32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))-1:0] tag;
// wire [$clog2(ysyx_24120011_ICACHE_NUM)-1:0] index;
// wire [$clog2(ysyx_24120011_ICACHE_SIZE)-1:0] offset;
// wire [31:0] inst_cache;
// wire hit;
// wire hit_valid;
// wire hit_tag;
// assign {tag,index,offset} = pc;
// //assign hit = 1'b0;
// assign hit_valid = (state == ysyx_24120011_IFU_LOOKUP) ? (icache[index][(1) + (32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))) + (8*ysyx_24120011_ICACHE_SIZE)-1] == 1'b1) : 1'b0;
// assign hit_tag = (state == ysyx_24120011_IFU_LOOKUP) ? (tag == icache[index][(32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))) + (8*ysyx_24120011_ICACHE_SIZE)-1:(8*ysyx_24120011_ICACHE_SIZE)]) : 1'b0;
// assign hit = hit_valid && hit_tag;
// //assign inst_cache = hit ? icache[index][31+offset*32 -: 32] : 32'b0;
// assign inst_cache = hit ? icache[index][31+offset[$clog2(ysyx_24120011_ICACHE_SIZE)-1:2]*32 -: 32] : 32'b0;
// //====================icache====================//

//====================icache_num1====================//
parameter ysyx_24120011_ICACHE_SIZE   = 32'd8;
parameter ysyx_24120011_ICACHE_NUM    = 32'd1;
//  valid                                       tag                                                 data
reg [(1) + (32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))) + (8*ysyx_24120011_ICACHE_SIZE)-1:0] icache;

wire [32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))-1:0] tag;
wire [$clog2(ysyx_24120011_ICACHE_SIZE)-1:0] offset;
wire [31:0] inst_cache;
wire hit;
wire hit_valid;
wire hit_tag;
assign {tag,offset} = pc;
//assign hit = 1'b0;
assign hit_valid = (state == ysyx_24120011_IFU_LOOKUP) ? (icache[(1) + (32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))) + (8*ysyx_24120011_ICACHE_SIZE)-1] == 1'b1) : 1'b0;
assign hit_tag = (state == ysyx_24120011_IFU_LOOKUP) ? (tag == icache[(32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))) + (8*ysyx_24120011_ICACHE_SIZE)-1:(8*ysyx_24120011_ICACHE_SIZE)]) : 1'b0;
assign hit = hit_valid && hit_tag;
//assign inst_cache = hit ? icache[index][31+offset*32 -: 32] : 32'b0;
//assign inst_cache = hit ? icache[31+offset[$clog2(ysyx_24120011_ICACHE_SIZE)-1:2]*32 -: 32] : 32'b0;
assign inst_cache = hit ? (offset[2] ? icache[63:32] : icache[31:0]) : 32'b0;//面积优化，并不通用
//====================icache====================//

//====================axi====================//
wire arvalid;
reg rready;
reg [31:0] araddr;
reg [31:0] cached_size;
reg rready_delay;
wire arready;
wire [1:0] rresp;
wire awready;
wire wready;
wire [1:0] bresp;
wire bvalid;
wire rvalid;

assign arvalid = (state == ysyx_24120011_IFU_AXI_RADDR) ? 1'b1 : 1'b0;
// assign rready = (state == ysyx_24120011_IFU_AXI_RDATA) ? 1'b1 :1'b0;
assign M0_araddr  = araddr      ;
assign M0_arvalid = arvalid ;
assign arready    = M0_arready;
assign rresp      = M0_rresp ;
assign rvalid     = M0_rvalid;
assign M0_rready  = (state == ysyx_24120011_IFU_AXI_RDATA) ? 1'b1 : 1'b0  ;
assign M0_awaddr  = 32'b0   ;
assign M0_awvalid = 1'b0    ;
assign awready    = M0_awready;
assign M0_wdata   = 32'b0   ;
assign M0_wstrb   = 4'b1111 ;
assign M0_wvalid  = 1'b0    ;
assign wready     = M0_wready;
assign bresp      = M0_bresp;
assign bvalid     = M0_bvalid;
assign M0_bready  = 1'b1    ;
assign M0_arid    = 'd0       ;
assign M0_arlen   = (pc >= 32'hA000_0000 && pc <= 32'hBFFF_FFFF) ? 'd1 : 'd0;//A000_0000-BFFF_FFFF
//assign M0_arlen   = 'd0;
assign M0_arburst = 'b01      ;
assign M0_arsize  = 3'b010    ;
assign M0_awid    = 'd0       ;
assign M0_awlen   = 'd0       ;
assign M0_awburst = 'd0       ;
assign M0_awsize  = 3'b010    ;
assign M0_wlast   = M0_wvalid ;
//====================axi====================//


// always @(posedge clk) begin
//     if(rst) begin
//         rready <= 1'b0;
//         rready_delay <= 1'b0;
//     end
//     else begin
//         rready <= (rvalid) & ~rready_delay;
//         rready_delay <= rvalid;
//     end
// end

always @(posedge clk) begin
    if(rst) begin
        inst <= 32'b0;
        cache_IFU_valid <= 1'b0;
    end
    else begin
        if(state == ysyx_24120011_IFU_IDLE_EMPTY) begin
            cache_IFU_valid <= 1'b0;
        end
        else if(state == ysyx_24120011_IFU_IDLE_FULL) begin
            cache_IFU_valid <= 1'b0;
        end
        else if(state == ysyx_24120011_IFU_LOOKUP) begin
            if(hit) begin
                inst <= inst_cache;
                cache_IFU_valid <= 1'b1;
            end
            else begin
                cache_IFU_valid <= 1'b0;
            end
        end
        else if(state == ysyx_24120011_IFU_AXI_RADDR) begin
            cache_IFU_valid <= 1'b0;
        end
        else if(state == ysyx_24120011_IFU_AXI_RDATA) begin
            cache_IFU_valid <= 1'b0;
            // if(rvalid && cached_size == 'd0) begin
            //     inst <= M0_rdata;
            // end
            // else begin
            // end
        end
        else begin //不应该进入
            cache_IFU_valid <= 1'b0;
        end
    end
end

always @(posedge clk) begin
    if(rst) begin
        araddr <= 'd0;
    end
    else begin
        if(state == ysyx_24120011_IFU_LOOKUP && next_state == ysyx_24120011_IFU_AXI_RADDR) begin
            //araddr <= pc;
            araddr <= pc & 32'hFFFFFFFF << $clog2(ysyx_24120011_ICACHE_SIZE);
        end
        else if(state == ysyx_24120011_IFU_AXI_RDATA && next_state == ysyx_24120011_IFU_AXI_RADDR) begin
            //araddr <= pc + 'd4;
            if(pc >= 32'hA000_0000 && pc <= 32'hBFFF_FFFF) begin
                araddr <= araddr;
            end
            else begin
                araddr <= araddr + 'd4;
            end
        end
        else if(state == ysyx_24120011_IFU_AXI_RADDR) begin
            araddr <= araddr;
        end
        else begin
            araddr <= araddr;
        end
    end
end

always @(posedge clk) begin
    if(rst) begin
        cached_size <= 'd0;
    end
    else begin
        if(rvalid) begin
            cached_size <= cached_size + 'd4;
        end
        else if(state == ysyx_24120011_IFU_IDLE_EMPTY) begin
            cached_size <= 'd0;
        end
        else begin
            cached_size <= cached_size;
        end
    end
end

// genvar j;
// generate
//     for (j = 0; j < ysyx_24120011_ICACHE_NUM; j = j + 1) begin : gen_reset
//         always @(posedge clk) begin
//             if (rst) begin
//                 icache[j] <= 'b0;
//             end
//             else begin
//                 if(inst_cache == 32'h0000100f)begin//fence.i
//                     icache[j] <= 'b0;
//                 end
//                 else begin
//                 end
//             end
//         end
//     end
// endgenerate
// always @(posedge clk) begin
//     if (rst) begin
//         icache <= 'b0;
//     end
//     else begin
//         if(inst_cache == 32'h0000100f)begin//fence.i
//             icache <= 'b0;
//         end
//         else begin
//             icache <= icache;
//         end
//     end
// end
always @(posedge clk) begin
    if(rst) begin
        icache <= 'b0;
    end
    else begin
        if(inst_cache == 32'h0000100f)begin//fence.i
            icache <= 'b0;
        end else begin
            if(state == ysyx_24120011_IFU_IDLE_EMPTY) begin
            end
            if(state == ysyx_24120011_IFU_IDLE_FULL) begin
            end
            else if(state == ysyx_24120011_IFU_LOOKUP) begin
            end
            else if(state == ysyx_24120011_IFU_AXI_RADDR) begin
            end
            else if(state == ysyx_24120011_IFU_AXI_RDATA) begin
                if(rvalid  && M0_rready) begin
                    // icache[index][(1) + (32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))) + (8*ysyx_24120011_ICACHE_SIZE)-1: (8*ysyx_24120011_ICACHE_SIZE)] <= {1'b1, tag};
                    // icache[index][31+(cached_size[31:2])*32 -: 32] <= M0_rdata;

                    icache[(1) + (32-($clog2(ysyx_24120011_ICACHE_SIZE)+$clog2(ysyx_24120011_ICACHE_NUM))) + (8*ysyx_24120011_ICACHE_SIZE)-1: (8*ysyx_24120011_ICACHE_SIZE)] <= {1'b1, tag};
                    icache[31+(cached_size[31:2])*32 -: 32] <= M0_rdata;
                end
                else begin
                end
            end
            else begin //不应该进入
            end
        end
        
    end
end

always@(*)begin
    case(state)
        ysyx_24120011_IFU_IDLE_EMPTY:      next_state = ((o_IFU_valid && o_IFU_ready) || (i_flush || flushing)) ? ysyx_24120011_IFU_IDLE_FULL    : ysyx_24120011_IFU_IDLE_EMPTY;
        ysyx_24120011_IFU_IDLE_FULL:      next_state = (i_IDU_ready) ? ysyx_24120011_IFU_LOOKUP    : ysyx_24120011_IFU_IDLE_FULL;
        ysyx_24120011_IFU_LOOKUP:    next_state = hit                      ? ysyx_24120011_IFU_IDLE_EMPTY      : ysyx_24120011_IFU_AXI_RADDR;//1周期内要确定有没有命中
        ysyx_24120011_IFU_AXI_RADDR: next_state = (arvalid && arready)     ? ysyx_24120011_IFU_AXI_RDATA : ysyx_24120011_IFU_AXI_RADDR;
        ysyx_24120011_IFU_AXI_RDATA: next_state = (rvalid  && M0_rready )     ? (cached_size == ysyx_24120011_ICACHE_SIZE - 'd4 ? ysyx_24120011_IFU_LOOKUP : (pc >= 32'hA000_0000 && pc <= 32'hBFFF_FFFF ? ysyx_24120011_IFU_AXI_RDATA :ysyx_24120011_IFU_AXI_RADDR)) : ysyx_24120011_IFU_AXI_RDATA;
        default : next_state = ysyx_24120011_IFU_IDLE_EMPTY;
    endcase
end

always@(posedge clk)begin
    if(rst) begin
        state <= ysyx_24120011_IFU_IDLE_FULL;
    end
    else begin
        state <= next_state;
    end
end
endmodule