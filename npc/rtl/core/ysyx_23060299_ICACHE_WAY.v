module ysyx_23060299_ICACHE_WAY #(
    parameter WAY       =   2   ,
    parameter INDEX     =   4   , // 2**2 = 4 way
    parameter OFFSET    =   2     // 2**2 = 4 Byte
)(
    input   wire            clock       ,           

    input   wire    [32 - INDEX - OFFSET - 1: 0]    wtag_i      ,
    input   wire    [INDEX - 1 :0]                  windex_i    ,
    input   wire    [(2 ** OFFSET)/4 - 1:0]         wline_we_i  , // word enable
    input   wire                                    we_i        ,
    input   wire    [31:0]                          wdata_i     ,

    input   wire    [INDEX - 1 :0]                  rindex_i    ,
    input   wire                                    re_i        ,
    output  reg     [32 - INDEX - OFFSET - 1: 0]    rtag_o      ,
    output  reg     [(2 ** OFFSET)*8 - 1:0]         rdata_o     

);

reg [32 - INDEX - OFFSET - 1: 0]    tag_sram    [(2 ** INDEX) - 1: 0];
reg [(2 ** OFFSET) * 8 - 1:0]       data_sram   [(2 ** INDEX) - 1: 0];

always @(posedge clock ) begin
    if(re_i)
        rtag_o  <=  tag_sram[rindex_i]  ;
end

always @(posedge clock ) begin
    if(re_i)
        rdata_o  <=  data_sram[rindex_i]  ;
end

always @(posedge clock ) begin
    if(we_i)
        tag_sram[windex_i]  <=  wtag_i  ;
end

integer i;

always @(posedge clock ) begin
    if(we_i) begin
        for (i = 0; i < (2 ** OFFSET)/4; i = i + 1) begin
            if (wline_we_i[i])
                data_sram[windex_i][(32*i + 31) -: 32] <= wdata_i   ;
        end
    end
end

/*

         [0x1c, 0x34)           + 0x4   =   [0x20, 0x38)
+------+------+------+------+      +------+------+------+------+
|      |      |      | 0x1c |      | 0x20 | 0x24 | 0x28 | 0x2c |
+------+------+------+------+      +------+------+------+------+
| 0x20 | 0x24 | 0x28 | 0x2c |      | 0x30 | 0x34 |      |      |
+------+------+------+------+      +------+------+------+------+
| 0x30 |      |      |      |
+------+------+------+------+

*/
    
endmodule