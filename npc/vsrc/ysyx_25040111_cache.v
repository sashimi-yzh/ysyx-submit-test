`include "HDR/ysyx_25040111_dpic.vh"

module ysyx_25040111_cache(
    input           clock,
    input           reset,

    input   [31:0]  addr,       // 访问地址
    output  [31:0]  data,       // 返回数据
    
    output          chburst,    // 是否突发读取
    output reg      chvalid,    // 传输开始控制信号
    input           chready,    // 一次传输完成信号
    output [31:0]   chaddr,     // 访问地址
    output [7:0]    chlen,      // 访问次数
    input  [31:0]   chdata,     // 一次传输完成数据

    input           ifu_valid,  // 使能
    output          ifu_ready,  // 完成

    input           err
);

//-----------------------------------------------------------------
// Key Params
//-----------------------------------------------------------------
    
    parameter CACHE_Ls = 4; // Block len sqrt   16
    parameter BLOCK_Ls = 3; // Byte len sqrt    4

//-----------------------------------------------------------------
// Local Params
//-----------------------------------------------------------------

    localparam TAG_IDX = BLOCK_Ls + CACHE_Ls;
    localparam TAG_HIG = 31 - TAG_IDX;

    localparam BLOCK_L = 1 << (CACHE_Ls + BLOCK_Ls - 2);
    localparam COUNT_L = BLOCK_Ls - 2;
    localparam DATA_L  = 1 << COUNT_L;
    localparam CACHE_L = 1 << CACHE_Ls;
    localparam IDX_L   = COUNT_L + CACHE_Ls;

//-----------------------------------------------------------------
// Register / Wire
//-----------------------------------------------------------------

    reg [31:0]           cblocks [BLOCK_L-1 : 0];
    reg [TAG_HIG:0]      ctags   [CACHE_L-1 : 0];
    reg [CACHE_L-1 : 0]  cvalids;

    reg  [COUNT_L   : 0] count;
    wire [IDX_L-1   : 0] bidx;
    wire [IDX_L-1   : 0] sidx;
    
    reg  [31:0]          caddr;
    reg                  cready;
    reg  [31:0]          cdata;
    reg                  ended;

    wire [COUNT_L:0]     nup = DATA_L;
    
//-----------------------------------------------------------------
// External Interface
//-----------------------------------------------------------------

    wire [TAG_HIG:0]      tag    = addr[31:TAG_IDX]; 
    wire [CACHE_Ls-1 : 0] index  = addr[TAG_IDX-1 : BLOCK_Ls];
    wire [BLOCK_Ls-1 : 0] offset = addr[BLOCK_Ls-1 : 0];

    wire        hit    = (ctags[index] == tag) & (cvalids[index]);
    wire        update = count == nup;
    wire        rend   = (count == chlen[COUNT_L:0]) & chready & chvalid;

    generate
        if (BLOCK_Ls > 2) begin
            assign bidx = {index, offset[BLOCK_Ls-1:2]};
            assign sidx = {index, count[COUNT_L-1:0]};
        end
        else begin
            assign bidx = index;
            assign sidx = index;
        end
    endgenerate
    
    assign ifu_ready    = cready;
    assign data         = cdata;
    assign chlen        = DATA_L - 1;
    assign chaddr       = caddr;

`ifdef STA_SOC
    assign chburst      = 1'b1;
`else
    assign chburst      = 1'b1;
`endif

//-----------------------------------------------------------------
// State Machine
//-----------------------------------------------------------------

    // cdata
    always @(posedge clock) begin
        if ((ifu_valid & hit & ~cready) | update) begin
        `ifndef YOSYS_STA
        `ifndef __ICARUS__ 
            if (ifu_valid & hit) cache_hit();
        `endif
        `endif
            cdata <= cblocks[bidx];
        end
    end

    // chvalid
    always @(posedge clock) begin
        if (reset)
            chvalid <= 1'b0;
        else if (ifu_valid & ~hit & ~chvalid & ~ended)
            chvalid <= 1'b1;
        else if (rend)
            chvalid <= 1'b0;
    end

    // counter
    always @(posedge clock) begin
        if (reset) 
            count <= {(COUNT_L+1){1'b0}};
        else if (chready) 
            count <= count + 1;
        else if (update)
            count <= {(COUNT_L+1){1'b0}};
    end
    
    // main cache
    always @(posedge clock) begin
        if (reset) begin
            cvalids <= {CACHE_L{1'b0}};
        end
        else if (update) begin
            ctags[index] <= tag;
            cvalids[index] <= 1'b1;    
        end
    end

    always @(posedge clock) begin
        if (chready) cblocks[sidx] <= chdata;        
    end

    // cready
    always @(posedge clock) begin
        if (reset | err)
            cready <= 1'b0;
        else if ((ifu_valid & hit & ~cready) | update)
            cready <= 1'b1;
        else
            cready <= 1'b0;
    end

    // caddr
    always @(posedge clock) begin
        if (ifu_valid & ~hit & ~chvalid & ~ended)
            caddr <= {addr[31:BLOCK_Ls], {BLOCK_Ls{1'b0}}};
        else if (chready & ~chburst)
            caddr <= caddr + 32'd4;
    end

    // ended
    always @(posedge clock) begin
        if (reset | err)
            ended <= 1'b0;
        else if (rend)
            ended <= 1'b1;
        else if (ifu_ready & ifu_valid)
            ended <= 0;
    end

endmodule
