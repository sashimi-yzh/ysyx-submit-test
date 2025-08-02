module ysyx_23060299_ICACHE #(
    parameter WAY       =   1   , // 2 way set (could be 4 8)
    parameter INDEX     =   4   , // 2**4 = line num is 16
    parameter OFFSET    =   2     // 2**2 = 4 Byte
)(
    input   wire            clock       ,      
    input   wire            reset       ,       

    input   wire    [31:0]  cpu_cache_addr  ,
    input   wire            cpu_cache_valid ,
    output  reg     [31:0]  cache_cpu_data  ,
    output  wire            cache_cpu_ready ,
    output  wire            cache_cpu_valid ,  
    input   wire            cache_mask      ,
    input   wire            fence_i         ,

    output  wire    [31:0]  axi_araddr  ,       
    output  reg             axi_arvalid ,       
    input   wire            axi_arready , 
    output  reg     [7:0]   axi_arlen   ,
    output  wire    [2:0]   axi_arsize  ,
    output  wire    [1:0]   axi_arburst ,      
    input   wire    [31:0]  axi_rdata   ,       
    input   wire    [1:0]   axi_rresp   ,       
    input   wire            axi_rvalid  ,       
    output  reg             axi_rready  ,
    input   wire            axi_rlast        
);

localparam TREE_WIDTH = (WAY <= 2) ? 0 : WAY - 2;

assign  axi_arburst =   2'b01   ;
assign  axi_arsize  =   3'b010  ;

wire    axi_arhandshake     =   axi_arvalid     &&  axi_arready     ;
wire    axi_rhandshake      =   axi_rvalid      &&  axi_rready      ;
wire    cpu_cache_handshake =   cpu_cache_valid &&  cache_cpu_ready ;

reg     cpu_cache_handshake_d1  ;

reg     [TREE_WIDTH : 0]    tree    [(2 ** INDEX) - 1: 0];
wire    [TREE_WIDTH : 0]    tree_index  ;

wire    [WAY - 1: 0]    we_i    ;
wire    [WAY - 1: 0]    re_i    ;
wire    [WAY - 1: 0]    way_hit ;

reg     [(2 ** INDEX) - 1: 0]       valid   [WAY - 1: 0]    ;
wire    [(2 ** OFFSET)*8 - 1:0]     rdata_o [WAY - 1: 0]    ;
wire    [31: INDEX + OFFSET]        rtag_o  [WAY - 1: 0]    ;

wire                                hit     ;

// from read addr
wire    [31: INDEX + OFFSET]        tag         ;
wire    [INDEX - 1 :0]              rindex_i    ;
wire    [OFFSET - 1: 0]             offset      ;
reg     [INDEX - 1 :0]              rindex_i_d1 ;

wire    [INDEX - 1 :0]              windex_i    ;
wire    [31: INDEX + OFFSET]        wtag_i      ;

reg     [(2 ** OFFSET)/4 - 1:0]     wline_we_i  ;

reg     [31:0]                      cpu_cache_addr_d1   ;

reg                                 cache_cpu_ready_r   ;

// left 0 right 1
generate
    if(WAY == 1) begin
        
    end
    else begin
        assign tree_index = ~tree[rindex_i];
    end
endgenerate

assign windex_i     =   rindex_i    ;
assign wtag_i       =   tag         ;

always @(posedge clock ) begin
    if(reset)
        cpu_cache_handshake_d1  <=  1'b0    ;
    else 
        cpu_cache_handshake_d1  <=  cpu_cache_handshake ;
end

always @(posedge clock ) begin
    rindex_i_d1 <=  rindex_i    ;
end

always @(posedge clock ) begin
    if(cpu_cache_handshake)
        cpu_cache_addr_d1  <=  cpu_cache_addr ;
end

always @(posedge clock ) begin
    if(reset)
        axi_arvalid  <=  1'b0   ;
    else if(!hit && cpu_cache_handshake_d1)
        axi_arvalid  <=  1'b1   ;
    else if(axi_arhandshake)
        axi_arvalid  <=  1'b0   ;
end

always @(posedge clock ) begin
    if(reset)
        axi_rready  <=  1'b1    ;
end

assign  tag         =   cpu_cache_addr_d1   [31: INDEX + OFFSET]  ;
assign  rindex_i    =   cpu_cache_handshake ?   cpu_cache_addr  [INDEX - 1 + OFFSET: OFFSET]    :   cpu_cache_addr_d1  [INDEX - 1 + OFFSET: OFFSET];
assign  offset      =   cpu_cache_addr_d1   [OFFSET - 1: 0];

assign  re_i        =   {WAY{(cpu_cache_valid    &&  cache_cpu_ready)}} ;


assign hit = |way_hit   &&  cpu_cache_handshake_d1  ;

genvar i;
generate
    for (i = 0; i < WAY; i = i + 1) begin: gen_ICACHE_WAY
        ysyx_23060299_ICACHE_WAY    #(
            .WAY        (WAY)       ,
            .INDEX      (INDEX )    ,
            .OFFSET     (OFFSET)
        )ICACHE_WAY(
            .clock      (clock) ,

            .wtag_i     (wtag_i                         ),
            .windex_i   (windex_i                       ),
            .wline_we_i (wline_we_i                     ),
            .we_i       (we_i       [i] &&  !cache_mask ),
            .wdata_i    (axi_rdata                      ),
            .rindex_i   (rindex_i                       ),
            .re_i       (re_i       [i]                 ),
            .rtag_o     (rtag_o     [i]                 ),
            .rdata_o    (rdata_o    [i]                 )
        );

        always @(posedge clock ) begin
            if(reset)
                valid[i]    <=  'd0 ;
            else if(fence_i)
                valid[i]    <=  'd0 ;
            else if(we_i[i])
                valid[i][windex_i]    <=  1'b1 ;
        end

        assign way_hit[i]   =   ((tag == rtag_o[i])  &&  (valid[i][rindex_i_d1] == 1'b1));

    end
endgenerate

assign  cache_cpu_ready =   cache_cpu_ready_r   &&  !(!hit && cpu_cache_handshake_d1);

always @(posedge clock ) begin
    if(reset)
        cache_cpu_ready_r   <=  'd1 ;
    else if(!hit && cpu_cache_handshake_d1)    
        cache_cpu_ready_r   <=  'd0 ;
    else if(axi_rhandshake && axi_rlast)
        cache_cpu_ready_r   <=  'd1 ;
end

generate
    if(WAY == 1) begin
        if(OFFSET > 2) begin
            always @(*) begin
                if(hit)
                    cache_cpu_data =  rdata_o[0][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                else if(axi_rhandshake)
                    cache_cpu_data =  axi_rdata ;
                else
                    cache_cpu_data =  'd0   ;
            end

            assign axi_araddr   =   cpu_cache_addr_d1   &   32'hFFFF_FFF0;
            
            always @(posedge clock ) begin
                if(!hit && cpu_cache_handshake_d1)
                    axi_arlen   <=  3   ;
            end

            always @(posedge clock ) begin
                if(axi_arhandshake) begin
                    // case (axi_araddr[3:2])
                    //     2'b00:   wline_we_i  <=  4'b0001 ;
                    //     2'b01:   wline_we_i  <=  4'b0010 ;
                    //     2'b10:   wline_we_i  <=  4'b0100 ;
                    //     2'b11:   wline_we_i  <=  4'b1000 ;
                    // endcase
                    wline_we_i  <=  4'b0001 ;
                end
                else if(axi_rhandshake)
                    wline_we_i  <=  (wline_we_i  <<  1) ;
            end

            assign  cache_cpu_valid =   hit ||  (axi_rhandshake &&  (
                (cpu_cache_addr_d1[3:2] ==  2'b00   &&  wline_we_i == 4'b0001) ||
                (cpu_cache_addr_d1[3:2] ==  2'b01   &&  wline_we_i == 4'b0010) ||
                (cpu_cache_addr_d1[3:2] ==  2'b10   &&  wline_we_i == 4'b0100) ||
                (cpu_cache_addr_d1[3:2] ==  2'b11   &&  wline_we_i == 4'b1000)
            )) ;

        end
        else if(OFFSET == 2) begin
            always @(*) begin
                if(hit)
                    cache_cpu_data =  rdata_o[0]   ;
                else if(axi_rhandshake)
                    cache_cpu_data =  axi_rdata ;
                else
                    cache_cpu_data =  'd0   ;
            end

            assign  axi_araddr      =   cpu_cache_addr_d1   ;

            assign  cache_cpu_valid =   hit ||  axi_rhandshake  ;

        end

        assign we_i[0] = axi_rhandshake ;

    end
    /* verilator lint_off CASEINCOMPLETE */
    else if(WAY == 2) begin
        always @(posedge clock ) begin
            if(axi_rhandshake)
                case (we_i) 
                    2'b01 : tree[windex_i] <=  1'b0   ;
                    2'b10 : tree[windex_i] <=  1'b1   ;
                endcase
            else
                case (way_hit)
                    2'b01 : tree[rindex_i] <=  1'b0   ;
                    2'b10 : tree[rindex_i] <=  1'b1   ;
                endcase
        end
    /* verilator lint_on CASEINCOMPLETE */
    // generate
        if(OFFSET > 2) begin
            always @(*) begin
                if(hit)
                    case (way_hit)
                        2'b01 :   cache_cpu_data =  rdata_o[0][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        2'b10 :   cache_cpu_data =  rdata_o[1][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        default:    cache_cpu_data  =  'd0   ;
                    endcase
                else
                    cache_cpu_data =  'd0   ;
            end
        end
        else if(OFFSET == 2) begin
            always @(*) begin
                if(hit)
                    case (way_hit)
                        2'b01 :   cache_cpu_data  =  rdata_o[0] ;
                        2'b10 :   cache_cpu_data  =  rdata_o[1] ;
                        default:    cache_cpu_data  =  'd0   ;
                    endcase
                else if(axi_rhandshake)
                    cache_cpu_data =  axi_rdata ;
                else
                    cache_cpu_data =  'd0   ;
            end
        end

        assign we_i[0] = axi_rhandshake &&  (tree_index == 1'b0);
        assign we_i[1] = axi_rhandshake &&  (tree_index == 1'b1);
    end
    else if(WAY == 4) begin
        always @(posedge clock ) begin
            case (way_hit)
                4'b0001 :   begin  tree[2]  <=  1'b0    ;  tree[1]  <=  1'b0    ;   end
                4'b0010 :   begin  tree[2]  <=  1'b0    ;  tree[1]  <=  1'b1    ;   end
                4'b0100 :   begin  tree[2]  <=  1'b1    ;  tree[0]  <=  1'b0    ;   end
                4'b1000 :   begin  tree[2]  <=  1'b1    ;  tree[0]  <=  1'b1    ;   end
            endcase
        end
    // generate
        if(OFFSET > 2) begin
            always @(*) begin
                if(hit)
                    case (way_hit)
                        4'b0001 :   cache_cpu_data  =  rdata_o[0][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        4'b0010 :   cache_cpu_data  =  rdata_o[1][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        4'b0100 :   cache_cpu_data  =  rdata_o[2][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        4'b1000 :   cache_cpu_data  =  rdata_o[3][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        default:    cache_cpu_data  =  'd0   ;
                    endcase
            end
        end
        else if(OFFSET == 2) begin
            always @(*) begin
                if(hit)
                    case (way_hit)
                        4'b0001 :   cache_cpu_data  =  rdata_o[0]   ;
                        4'b0010 :   cache_cpu_data  =  rdata_o[1]   ;
                        4'b0100 :   cache_cpu_data  =  rdata_o[2]   ;
                        4'b1000 :   cache_cpu_data  =  rdata_o[3]   ;
                        default:    cache_cpu_data  =  'd0   ;
                    endcase
                else if(axi_rhandshake)
                    cache_cpu_data =  axi_rdata ;
                else
                    cache_cpu_data =  'd0   ;
            end
        end

        assign we_i[0] = axi_rhandshake &&  (tree_index[2] == 1'b0) &&  (tree_index[1] == 1'b0);
        assign we_i[1] = axi_rhandshake &&  (tree_index[2] == 1'b0) &&  (tree_index[1] == 1'b1);
        assign we_i[2] = axi_rhandshake &&  (tree_index[2] == 1'b1) &&  (tree_index[0] == 1'b0);
        assign we_i[3] = axi_rhandshake &&  (tree_index[2] == 1'b1) &&  (tree_index[0] == 1'b1);
    end
    else if(WAY == 8) begin
        always @(posedge clock ) begin
            case (way_hit)
                8'b0000_0001 :   begin  tree[6] <=  1'b0  ;  tree[5] <=  1'b0  ; tree[3] <=  1'b0  ;end
                8'b0000_0010 :   begin  tree[6] <=  1'b0  ;  tree[5] <=  1'b0  ; tree[3] <=  1'b1  ;end
                8'b0000_0100 :   begin  tree[6] <=  1'b0  ;  tree[5] <=  1'b1  ; tree[2] <=  1'b0  ;end
                8'b0000_1000 :   begin  tree[6] <=  1'b0  ;  tree[5] <=  1'b1  ; tree[2] <=  1'b1  ;end
                8'b0001_0000 :   begin  tree[6] <=  1'b0  ;  tree[4] <=  1'b0  ; tree[1] <=  1'b0  ;end
                8'b0010_0000 :   begin  tree[6] <=  1'b0  ;  tree[4] <=  1'b0  ; tree[1] <=  1'b1  ;end
                8'b0100_0000 :   begin  tree[6] <=  1'b0  ;  tree[4] <=  1'b1  ; tree[0] <=  1'b0  ;end
                8'b1000_0000 :   begin  tree[6] <=  1'b0  ;  tree[4] <=  1'b1  ; tree[0] <=  1'b1  ;end
            endcase
        end

        if(OFFSET > 2) begin
            always @(*) begin
                if(hit)
                    case (way_hit)
                        8'b0000_0001 :   cache_cpu_data =  rdata_o[0][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        8'b0000_0010 :   cache_cpu_data =  rdata_o[1][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        8'b0000_0100 :   cache_cpu_data =  rdata_o[2][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        8'b0000_1000 :   cache_cpu_data =  rdata_o[3][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        8'b0001_0000 :   cache_cpu_data =  rdata_o[4][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        8'b0010_0000 :   cache_cpu_data =  rdata_o[5][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        8'b0100_0000 :   cache_cpu_data =  rdata_o[6][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        8'b1000_0000 :   cache_cpu_data =  rdata_o[7][(32 * offset[OFFSET - 1: 2]) + 31 -: 32]   ;
                        default: cache_cpu_data =   'd0 ;
                    endcase
            end
        end
        else if(OFFSET == 2) begin
            always @(*) begin
                if(hit)
                    case (way_hit)
                        8'b0000_0001 :   cache_cpu_data =  rdata_o[0]   ;
                        8'b0000_0010 :   cache_cpu_data =  rdata_o[1]   ;
                        8'b0000_0100 :   cache_cpu_data =  rdata_o[2]   ;
                        8'b0000_1000 :   cache_cpu_data =  rdata_o[3]   ;
                        8'b0001_0000 :   cache_cpu_data =  rdata_o[4]   ;
                        8'b0010_0000 :   cache_cpu_data =  rdata_o[5]   ;
                        8'b0100_0000 :   cache_cpu_data =  rdata_o[6]   ;
                        8'b1000_0000 :   cache_cpu_data =  rdata_o[7]   ;
                        default: cache_cpu_data =   'd0 ;
                    endcase
                else if(axi_rhandshake)
                    cache_cpu_data =  axi_rdata ;
                else
                    cache_cpu_data =  'd0   ;
            end
        end

        assign we_i[0] = axi_rhandshake &&  (tree_index[6] == 1'b0) &&  (tree_index[5] == 1'b0) &&  (tree_index[3] == 1'b0);
        assign we_i[1] = axi_rhandshake &&  (tree_index[6] == 1'b0) &&  (tree_index[5] == 1'b0) &&  (tree_index[3] == 1'b1);
        assign we_i[2] = axi_rhandshake &&  (tree_index[6] == 1'b0) &&  (tree_index[5] == 1'b1) &&  (tree_index[2] == 1'b0);
        assign we_i[3] = axi_rhandshake &&  (tree_index[6] == 1'b0) &&  (tree_index[5] == 1'b1) &&  (tree_index[2] == 1'b1);
        assign we_i[0] = axi_rhandshake &&  (tree_index[6] == 1'b1) &&  (tree_index[4] == 1'b0) &&  (tree_index[1] == 1'b0);
        assign we_i[1] = axi_rhandshake &&  (tree_index[6] == 1'b1) &&  (tree_index[4] == 1'b0) &&  (tree_index[1] == 1'b1);
        assign we_i[2] = axi_rhandshake &&  (tree_index[6] == 1'b1) &&  (tree_index[4] == 1'b1) &&  (tree_index[0] == 1'b0);
        assign we_i[3] = axi_rhandshake &&  (tree_index[6] == 1'b1) &&  (tree_index[4] == 1'b1) &&  (tree_index[0] == 1'b1);
    end
endgenerate

`ifdef ysyx_23060299_PO  

import "DPI-C" function void icache_hit();
import "DPI-C" function void icache_cnt();

always @(posedge clock ) begin
    if(cpu_cache_handshake_d1 && hit)
        icache_hit();
end

always @(posedge clock ) begin
    if(cpu_cache_handshake_d1)
        icache_cnt();
end

`endif

endmodule