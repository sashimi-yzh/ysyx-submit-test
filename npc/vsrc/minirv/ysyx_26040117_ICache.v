module ysyx_26040117_ICache(
    input wire clk,
    input wire rst,
    input [37:0]IFU_ICACHE_wrapper,
    output[67:0]ICACHE_IFU_wrapper,
    input [34:0]MEM_ICACHE_wrapper,
    output[44:0]ICACHE_MEM_wrapper
);
    parameter OFFSET_WIDTH=4,INDEX_WIDTH=2;
    localparam DATA_DEPTH=2**(OFFSET_WIDTH+INDEX_WIDTH-2);
    localparam WORD_NUM=2**(OFFSET_WIDTH-2);
    localparam BURST_LEN=WORD_NUM-1;
    wire arready,arvalid,rready,rfire,arfire;
    reg rvalid;
    reg[31:0] rdata;
    wire[31:0] s2_araddr,araddr;
    wire fence_i,pipe_clear,cache_clear,s1_valid;
    reg flush_pending,fence_done;

    assign {fence_i,pipe_clear,cache_clear,s1_valid,arvalid,araddr,rready}=IFU_ICACHE_wrapper;
    assign ICACHE_IFU_wrapper={flush_pending,fence_done,arready,rvalid,s2_araddr,rdata};
    localparam IDLE=0,MISS_AR=1,MISS_DATA=2;
    reg[1:0] state,next_state;
    reg[29:0] data_array[0:DATA_DEPTH-1];
    reg[31-OFFSET_WIDTH-INDEX_WIDTH:0] tag_array[0:(2**INDEX_WIDTH)-1];
    reg[DATA_DEPTH-1:0] valid_array;
    //ifu-interface
    wire [OFFSET_WIDTH-3:0] req_offset;
    wire[INDEX_WIDTH-1:0] req_index;
    wire[31-OFFSET_WIDTH-INDEX_WIDTH:0] req_tag;
    wire req_tag_match,hit,is_sdram;
    reg req_tag_match_reg,is_sdram_reg;
    assign req_offset=araddr[OFFSET_WIDTH-1:2];
    assign req_index=araddr[OFFSET_WIDTH +: INDEX_WIDTH];
    assign req_tag=araddr[31:OFFSET_WIDTH+INDEX_WIDTH];
    assign req_tag_match=(tag_array[req_index]==req_tag);
    assign hit=valid_array[{req_index,req_offset}]&&req_tag_match;
    assign is_sdram =araddr[31:29]==3'b101;//SDRAM

    wire arready_MEM,arvalid_MEM,arfire_MEM;
    wire rready_MEM,rvalid_MEM,rfire_MEM,rlast;
    wire [31:0] rdata_MEM,araddr_MEM;

    reg miss_pending;
    wire out_ready=!rvalid||rready;
    assign  arready=out_ready&&((state==IDLE)||((state==MISS_DATA)&&!miss_pending&&hit));
    assign  arfire=arvalid&&arready;
    
    //r channel
    reg[29:0] hit_rdata;
    integer i;
    always @(*) begin
        hit_rdata=30'd0;
        for(i=0;i<DATA_DEPTH;i++)begin
            hit_rdata=hit_rdata|(data_array[i]&{30{{req_index,req_offset}==i[INDEX_WIDTH+OFFSET_WIDTH-3:0]}});
        end
    end
    always @(posedge clk) begin
        if(out_ready)
            rdata<=miss_pending?{rdata_MEM[31:2],2'b11}:{hit_rdata,2'b11};
    end
    always @(posedge clk) begin
        if(pipe_clear)begin
            rvalid<=1'd0;
        end else begin
            if(hit&&arfire)begin 
                rvalid<=1'b1;
            end else if(rfire_MEM&&miss_pending)begin
                rvalid<=1'b1;//delay rfire -fence_i
            end else if(rfire)begin
                rvalid<=1'b0;
            end
        end
    end
    always @(posedge clk) begin
        if(pipe_clear)
            miss_pending<=1'b0;
        else if(arfire&&!hit)
            miss_pending<=1'b1;
        else if(rfire_MEM)
            miss_pending<=1'b0;
    end
    assign rfire=rvalid&&rready;

    //ICache

    reg[INDEX_WIDTH-1:0] index_reg;
    reg[OFFSET_WIDTH-3:0] offset_count;
    reg[29:0]araddr_reg;
    wire [31-OFFSET_WIDTH-INDEX_WIDTH:0] tag_reg;
    assign s2_araddr={araddr_reg,2'b00};
    assign tag_reg=s2_araddr[31:OFFSET_WIDTH+INDEX_WIDTH];

    always @(posedge clk) begin
        if(s1_valid&&arready)begin 
            araddr_reg<=araddr[31:2];
        end
        if(s1_valid&&arready&&!hit)begin
            req_tag_match_reg<=req_tag_match;
            index_reg<=req_index;
        end
    end
    always @(posedge clk) begin
        if(cache_clear) begin
            valid_array<=0;
        end else if(!flush_pending)begin
            case(state)
                IDLE:if(s1_valid&&arready&&!hit)begin
                        offset_count<=req_offset;
                end
                MISS_AR:begin
                    tag_array[index_reg]<=tag_reg;
                    if(!req_tag_match_reg)
                        valid_array[index_reg*WORD_NUM +: WORD_NUM]<=0;
                end
                MISS_DATA:if(rfire_MEM)begin
                            data_array[{index_reg,offset_count}]<=rdata_MEM[31:2];
                            valid_array[{index_reg,offset_count}]<=1'b1;
                            if(is_sdram_reg&&!rlast)
                                offset_count<=offset_count+1'b1;
                        end
                default:;
            endcase
        end
    end
    always @(posedge clk) begin
        if(rst)
            is_sdram_reg<=1'b0;
        else if(arfire&&!hit)
            is_sdram_reg<=is_sdram;
    end
    //state machine
    always @(posedge clk) begin
        if(rst)
            state<=IDLE;
        else 
            state<=next_state;
    end
    always @(*) begin
        next_state=state;
        case(state)
            IDLE:if(arfire&&!hit)next_state=MISS_AR;
            MISS_AR:if(arfire_MEM)next_state=MISS_DATA;
            MISS_DATA:if(rfire_MEM&&rlast)next_state=IDLE;
            default:next_state=IDLE;
        endcase
    end
    //fence
    wire refill_done=(state==MISS_DATA)&&rfire_MEM&&rlast;
    always @(posedge clk) begin
        if(rst)
            {flush_pending,fence_done}<=2'b0;
        else begin
            fence_done<=1'b0;
            if(fence_i)begin
                if((state==IDLE)||refill_done)begin
                    flush_pending<=1'b0;
                    fence_done<=1'b1;
                end else begin
                    flush_pending<=1'b1;
                end
            end else if(flush_pending&&refill_done)begin
                flush_pending<=1'b0;
                fence_done<=1'b1;
            end
        end
    end
    //ICache-arbiter
    assign  arfire_MEM=arvalid_MEM&&arready_MEM;
    assign  rfire_MEM=rvalid_MEM&&rready_MEM;
    wire [7:0]arlen;
    assign arlen=is_sdram_reg?BURST_LEN:8'd0;
    assign araddr_MEM=s2_araddr;
    assign arvalid_MEM=state==MISS_AR;
    assign rready_MEM=state==MISS_DATA;
    assign ICACHE_MEM_wrapper={3'b010,arvalid_MEM,araddr_MEM,arlen,rready_MEM};
    assign {arready_MEM,rvalid_MEM,rdata_MEM,rlast}=MEM_ICACHE_wrapper;
endmodule
