module ysyx_26040117_LSU (clk,rst,
    EXU_LSU_ready,EXU_LSU_valid,EXU_wrapper,
    LSU_WBU_ready,LSU_WBU_valid,LSU_wrapper,
    LSU_IDU_wrapper,
    MEM_LSU_wrapper,LSU_MEM_wrapper
);
    input clk,rst;
    //EXU-LSU
    input EXU_LSU_valid;
    output EXU_LSU_ready;
    input [84:0]EXU_wrapper;
    //LSU-WBU
    input LSU_WBU_ready;
    output LSU_WBU_valid;
    output [49:0]LSU_wrapper;
    //LSU-IDU
    output [38:0] LSU_IDU_wrapper;
    //LSU-MEM
    input [40:0]MEM_LSU_wrapper;
    output[110:0] LSU_MEM_wrapper;

    //FIFO
    reg [84:0] wrapper_reg;
    wire register_wen_ok,register_wen_load,register_wen,type_fence_i,is_store,is_load;
    wire[31:0] aux;
    wire [31:0]result/* verilator public_flat_rd */;
    wire [2:0]funct3;
    wire [6:0]trap_info;
    wire [4:0]rd;
    wire [31:0] result_out;
    reg[2:0] csr_addr;
    wire csrrs;
    wire EXU_LSU_fire,LSU_WBU_fire/* verilator public_flat_rd */;
    always @(posedge clk) begin
        if(EXU_LSU_fire)begin
            wrapper_reg<=EXU_wrapper;
        end
    end
    assign csrrs=funct3==3'b010;
    assign {register_wen_load,register_wen_ok,register_wen,type_fence_i,trap_info,rd,result,aux,is_store,is_load,funct3}=wrapper_reg;
    assign LSU_wrapper={register_wen,type_fence_i,trap_info,rd,result_out,csr_addr,csrrs};
    wire rvalid,arready,rready,bvalid;;
    reg arvalid,awvalid,wvalid;
    reg lsu_valid;
    wire load_ready=register_wen_load&&!arvalid&&rvalid;
    assign LSU_IDU_wrapper={result_out,lsu_valid&&register_wen,lsu_valid&&(register_wen_ok||load_ready),rd};
    //
    wire wen,ren;
    wire [1:0]mytype_in=EXU_wrapper[4:3];
    assign wen=mytype_in[1]&&EXU_LSU_fire;//right now
    assign ren=mytype_in[0]&&EXU_LSU_fire;
    assign EXU_LSU_fire=EXU_LSU_ready&&EXU_LSU_valid;
    assign LSU_WBU_fire=LSU_WBU_ready&&LSU_WBU_valid;
    assign EXU_LSU_ready=!lsu_valid||LSU_WBU_fire;
    wire is_mem/* verilator public_flat_rd */;
    assign is_mem=is_load||is_store;
    assign LSU_WBU_valid=lsu_valid&&(!is_mem|| 
            (is_load&&!arvalid&&rvalid)||
            (is_store&&!awvalid&&!wvalid&&bvalid)
    );
    always @(posedge clk) begin
        if(rst)
            lsu_valid<=1'b0;
        else if(EXU_LSU_fire)
            lsu_valid<=1'b1;
        else if(LSU_WBU_fire)
            lsu_valid<=1'b0;
    end
    //read
    wire[31:0] rdata;
    wire[1:0] rresp;
    wire [31:0] araddr;
    wire [2:0] arsize;
    wire arfire;
    assign arfire=arvalid&&arready;
    always @(posedge clk) begin
        if(rst) arvalid<=1'b0;
        else if(arfire)
            arvalid<=1'b0;
        else if(ren)
            arvalid<=1'b1;
    end
    assign rready=lsu_valid&&is_load&&!arvalid&&LSU_WBU_ready;
    assign {araddr,arsize}={result,{1'b0,funct3[1:0]}};
    //read function
    reg[31:0] rdata_out;
    wire[1:0] raddr_shift;
    assign raddr_shift=araddr[1:0];
    wire[7:0] load_byte;
    wire[15:0]load_half=raddr_shift[1]?rdata[31:16]:rdata[15:0];
    assign load_byte=raddr_shift[0]?load_half[15:8]:load_half[7:0];
    always @(*) begin
        case(funct3)
            3'b000:rdata_out={{24{load_byte[7]}},load_byte};
            3'b001:rdata_out={{16{load_half[15]}},load_half};
            3'b010:rdata_out=rdata;
            3'b100:rdata_out={24'd0,load_byte};
            3'b101:rdata_out={16'd0,load_half};
            default:rdata_out=32'd0;
        endcase
    end
    //write
    wire awready,wready,bready;
    wire[1:0] bresp;
    wire [2:0] awsize;
    wire [31:0] awaddr,wdata;
    wire [3:0] wstrb;
    wire wfire,awfire;
    //aw
    assign awfire=awvalid&&awready;
    always @(posedge clk) begin
        if(rst) awvalid<=1'b0;
        else if(awfire)
            awvalid<=1'b0;
        else if(wen)
            awvalid<=1'b1;
    end
    //w
    assign wfire=wvalid&&wready;
    always @(posedge clk) begin
        if(rst) wvalid<=1'b0;
        else if(wfire)
            wvalid<=1'b0;
        else if(wen)
            wvalid<=1'b1;
    end
    //b
    assign bready=lsu_valid&&is_store&&!wvalid&&!awvalid&&LSU_WBU_ready;
    //write function
    wire[3:0] aw_mask;
    assign wdata=({32{funct3[1:0]==2'b00}}&{4{aux[7:0]}})|//sb
                 ({32{funct3[1:0]==2'b01}}&{2{aux[15:0]}})|// sh
                 ({32{funct3[1]}}&aux);//sw
    assign {awaddr,awsize}={result,{1'b0,funct3[1:0]}};
    assign aw_mask={awsize[1],awsize[1],awsize[1]|awsize[0],1'b1};
    assign wstrb=aw_mask<<awaddr[1:0];
    //interface
    assign LSU_MEM_wrapper={arsize,awsize,arvalid,araddr,rready,awvalid,awaddr,wvalid,wdata,wstrb,bready};
    assign {arready,rvalid,rdata,rresp,awready,wready,bvalid,bresp}=MEM_LSU_wrapper;//save rdata?

    //output
    assign result_out=is_load?rdata_out:result;
    localparam CSR_MCYCLE_LO = 3'd0;
    localparam CSR_MCYCLE_HI = 3'd1;
    localparam CSR_MEPC      = 3'd2;
    localparam CSR_MSTATUS   = 3'd3;
    localparam CSR_MCAUSE    = 3'd4;
    localparam CSR_MTVEC     = 3'd5;
    localparam CSR_MVENDORID = 3'd6;
    localparam CSR_MARCHID   = 3'd7;
    always @(*) begin
        csr_addr=3'd0;
        if(trap_info[0])begin
            case(aux[11:0])
                //12'hb00:csr_addr={CSR_MCYCLE_LO};
                //12'hb80:csr_addr={CSR_MCYCLE_HI};
                12'h341:csr_addr={CSR_MEPC};
                12'h300:csr_addr={CSR_MSTATUS};
                12'h342:csr_addr={CSR_MCAUSE};
                12'h305:csr_addr={CSR_MTVEC};
                12'hf11:csr_addr={CSR_MVENDORID};
                12'hf12:csr_addr={CSR_MARCHID};
                default:csr_addr=3'd0;
            endcase
        end
    end
endmodule
