module ysyx_24070003_lsu(
    input           clock,
    input           rst_n,
   // input           EXU_LSU_JUMP,
    //output        reg  LSU_WBU_JUMP,
    //input  [31:0]   EXU_IFU_pc,
    //output reg [31:0]   LSU_WBU_pc,

    input           EXU_LSU_valid,
    output           LSU_EXU_ready,
    output     reg      LSU_WBU_valid,
    input           LSU_WBU_ready,
    input       [8:0] EXU_LSU_RW_sign,
    // input           EXU_LSU_lw,
    // input           EXU_LSU_lh,
    // input           EXU_LSU_lb,
    // input           EXU_LSU_lbu,
    // input           EXU_LSU_lhu,
    // input           EXU_LSU_sw,
    // input           EXU_LSU_sb,
    // input           EXU_LSU_sh,
    input      [31:0] EXU_LSU_PC,
    input      [31:0] EXU_LSU_dnpc,
    input      [31:0] EXU_LSU_csr_data,
    input      [31:0] EXU_LSU_csr_in,
    input           EXU_LSU_ecall,
    input           EXU_LSU_mret,
    input           EXU_LSU_C_type,
    input      [2:0] EXU_LSU_csr_rst,

    input           EXU_LSU_ren,
    //input           EXU_LSU_wen,
//input           IDU_EXU_ren,
    //input           IDU_EXU_wen,
    
    input           EXU_LSU_reg,
    input           EXU_LSU_ebreak,
    input      [31:0] EXU_LSU_result,
    output      [31:0] LSU_WBU_DATA,
    output   reg[31:0] LSU_WBU_PC,
    input    [4:0]  EXU_LSU_rd,
    //input    [31:0] alu_result,
    input    [31:0] rs2_data,
    output   reg    LSU_WBU_reg,
    output   reg    LSU_WBU_ebreak,
    //output   [31:0] rdata,
    output   reg [4:0]  LSU_WBU_rd,
    //output   reg [31:0] LSU_WBU_csr_data,
    output   reg [31:0] LSU_WBU_csr_in,
    output   reg    LSU_WBU_ecall,
    output   reg    LSU_WBU_mret,
    output   reg    LSU_WBU_C_type,
    output   reg [2:0] LSU_WBU_csr_rst,
    output   reg [31:0] LSU_WBU_dnpc,
    output   reg LSU_WBU_skip,
    //output   [3:0]  LSU_WLEN,
   // output    [31:0] LSU_WDATA,
    //input    [31:0] LSU_RDATA,

    output      LSU_IFU_stall,

    output reg [32-1:0] LSU_AXI4_ARADDR,
    output reg                  LSU_AXI4_ARVALID,
    input                       LSU_AXI4_ARREADY,
    
    // 读数据通道
    input  [32-1:0]     LSU_AXI4_RDATA,
    input                       LSU_AXI4_RVALID,
    output reg                  LSU_AXI4_RREADY,
    
    // 写地址通道
    output reg [32-1:0] LSU_AXI4_AWADDR,
    output reg                  LSU_AXI4_AWVALID,
    input                       LSU_AXI4_AWREADY,
    
    // 写数据通道
    output reg [32-1:0] LSU_AXI4_WDATA,
    output reg [3:0]            LSU_AXI4_WSTRB,
    output reg                  LSU_AXI4_WVALID,
    input                       LSU_AXI4_WREADY,
    
    // 写响应通道
    input                       LSU_AXI4_BVALID,
    output reg                  LSU_AXI4_BREADY,
    output reg                  LSU_AXI_wlast,
    output reg [2:0]            LSU_AXI4_wsize,
    // output reg [63:0]           lsu_count,
    // output reg [63:0]           lsu_during_count,
    // output reg [63:0]           lsu_load_count,
    // output reg [63:0]           lsu_store_count,
    output reg [2:0]            LSU_AXI4_ARSIZE,


    output     [31:0]           LSU_forward_data,
    output [4:0]            LSU_IDU_REG_ADDR,
    output                  LSU_IDU_REG_WEN
    //output                  LSU_IDU_REN
      //input  [1:0]                LSU_AXI4_BRESP
);

assign LSU_IDU_REG_ADDR = EXU_LSU_rd;
assign LSU_IDU_REG_WEN = EXU_LSU_reg && LSU_EXU_ready && EXU_LSU_valid;
//assign LSU_IDU_REN   = EXU_LSU_ren && LSU_EXU_ready && EXU_LSU_valid;
assign LSU_forward_data = LSU_WBU_DATA;
wire EXU_LSU_wen,EXU_LSU_lh,EXU_LSU_lw,EXU_LSU_lb,EXU_LSU_lbu,EXU_LSU_lhu,EXU_LSU_sw,EXU_LSU_sb,EXU_LSU_sh;
assign {EXU_LSU_wen,EXU_LSU_lh,EXU_LSU_lw,EXU_LSU_lb,EXU_LSU_lbu,EXU_LSU_lhu,EXU_LSU_sw,EXU_LSU_sb,EXU_LSU_sh} = EXU_LSU_RW_sign;
parameter  IDLE = 0,
            START = 1,
            READ_START = 2,
            WRITE_WIRE_1 = 3,
            WRITE_WIRE_2 = 4,
            WRITE_DATA = 5;
reg [2:0] state;

    //reg [63:0] lsu_count;
    reg LSU_REN;
    //wire [3:0]  wlen;
    //wire [31:0] addr;
    //wire [31:0] wdata;
    //reg  [31:0]rdata_in,rdata;
    wire [3:0] LSU_WLEN;
    wire [31:0] rdata;
    reg [31:0] LSU_RDATA,LSU_WDATA;
    wire [3:0] lsu_wstrb;
    wire [31:0] lsu_wdata;
    wire [31:0] lsu_rdata;
    wire [2:0] lsu_arsize;
    reg skip;
    wire skip1 = (((EXU_LSU_result >= 32'h10000000) && (EXU_LSU_result < 32'h30000000)) && (EXU_LSU_ren || EXU_LSU_wen)) ? 1'b1 : 1'b0;
    wire skip2 = (((EXU_LSU_result >= 32'h02000000) && (EXU_LSU_result < 32'h0200ffff)) && (EXU_LSU_ren || EXU_LSU_wen)) ? 1'b1 : 1'b0;
    wire EXU_skip = skip1 | skip2;
    assign LSU_WDATA = ( {32{EXU_LSU_sb}} & {24'b0,rs2_data[7:0]}) |
                   ( {32{EXU_LSU_sh}} & {16'b0,rs2_data[15:0]}) |
                   ( {32{EXU_LSU_sw}} & rs2_data);

    // assign lsu_rdata = (LSU_AXI4_ARADDR[1:0]  == 2'b00) ? (LSU_RDATA >> 32'd0) :
    //                    (LSU_AXI4_ARADDR[1:0]  == 2'b01) ? (LSU_RDATA >> 32'd8) :
    //                    (LSU_AXI4_ARADDR[1:0]  == 2'b10) ? (LSU_RDATA >> 32'd16) :
    //                    (LSU_AXI4_ARADDR[1:0]  == 2'b11) ? (LSU_RDATA >> 32'd24) : (LSU_RDATA >> 32'd0);

 ysyx_24070003_mux4_32bit my6(
    .sel            (LSU_AXI4_ARADDR[1:0]),
    .a              (LSU_RDATA >> 32'd0), 
    .b              (LSU_RDATA >> 32'd8),
    .c              (LSU_RDATA >> 32'd16),
    .d              (LSU_RDATA >> 32'd24),
    .out            (lsu_rdata)
);

    //assign lsu_rdata = (LSU_RDATA >> (LSU_AXI4_ARADDR[1:0] << 3));

    reg LSU_WBU_lb,LSU_WBU_lh,LSU_WBU_lw,LSU_WBU_lbu,LSU_WBU_lhu;
always @(posedge clock) begin
    if(rst_n)begin
        LSU_WBU_lb <= 1'b0;
        LSU_WBU_lh <= 1'b0;
        LSU_WBU_lw <= 1'b0;
        LSU_WBU_lbu <= 1'b0;
        LSU_WBU_lhu <= 1'b0;
    end else if((LSU_EXU_ready && EXU_LSU_valid) ) begin
        LSU_WBU_lb <= EXU_LSU_lb;
        LSU_WBU_lh <= EXU_LSU_lh;
        LSU_WBU_lw <= EXU_LSU_lw;
        LSU_WBU_lbu <= EXU_LSU_lbu;
        LSU_WBU_lhu <= EXU_LSU_lhu;

    end 
end

    assign rdata = ( {32{LSU_WBU_lb}} & {{24{lsu_rdata[7]}},lsu_rdata[7:0]}) |
                   ( {32{LSU_WBU_lh}} & {{16{lsu_rdata[15]}}, (lsu_rdata[15:0])}) |
                   ( {32{LSU_WBU_lw}} & lsu_rdata) |
                   ( {32{LSU_WBU_lbu}} & {24'b0,lsu_rdata[7:0]}) |
                   ( {32{LSU_WBU_lhu}} & {16'b0,lsu_rdata[15:0]});

    assign  LSU_WLEN = ( {4{EXU_LSU_sb}} & 4'b1 )  |
                   ( {4{EXU_LSU_sh}} & 4'b11 )  |
                   ( {4{EXU_LSU_sw}} & 4'b1111 ) ;
    wire [2:0] awsize;

    assign  awsize = ( {3{EXU_LSU_sb}} & 3'b0 )  |
                   ( {3{EXU_LSU_sh}} & 3'b01 )  |
                   ( {3{EXU_LSU_sw}} & 3'b10 ) ;
    
    
    assign lsu_arsize = ( {3{LSU_WBU_lb}} & 3'b0) |
                   ( {3{LSU_WBU_lh}} & 3'b01) |
                   ( {3{LSU_WBU_lw}} & 3'b10) |
                   ( {3{LSU_WBU_lbu}} & 3'b0) |
                   ( {3{LSU_WBU_lhu}} & 3'b01);
                   
    // wire is_sdram = ((LSU_AXI4_ARADDR >= 32'ha0000000) && (LSU_AXI4_ARADDR < 32'hc0000000));
    // assign lsu_arsize = (is_sdram) ? arsize : 3'b00;
    // always @(posedge clk) begin
    //     if(EXU_LSU_wen) begin
    //     $write("lsu_wstrb = %04b,EXU_LSU_result = %08x\n",lsu_wstrb,EXU_LSU_result);
    //     end
    // end
    assign lsu_wstrb = (EXU_LSU_result[1:0]  == 2'b00) ? (LSU_WLEN << 2'd0) :
                       (EXU_LSU_result[1:0]  == 2'b01) ? (LSU_WLEN << 2'd1) :
                       (EXU_LSU_result[1:0]  == 2'b10) ? (LSU_WLEN << 2'd2) :
                       (EXU_LSU_result[1:0]  == 2'b11) ? (LSU_WLEN << 2'd3) : (LSU_WLEN << 2'd0);

// ysyx_24070003_mux4_32bit my7(
//     .sel            (EXU_LSU_result[1:0]),
//     .a              (LSU_WLEN << 32'd0), 
//     .b              (LSU_WLEN << 32'd1),
//     .c              (LSU_WLEN << 32'd2),
//     .d              (LSU_WLEN << 32'd3),
//     .out            (lsu_wstrb)
// );

    //assign lsu_wstrb = (LSU_WLEN << EXU_LSU_result[1:0] );
    // assign lsu_wdata = (EXU_LSU_result[1:0]  == 2'b00) ? (LSU_WDATA << 32'd0) :
    //                    (EXU_LSU_result[1:0]  == 2'b01) ? (LSU_WDATA << 32'd8) :
    //                    (EXU_LSU_result[1:0]  == 2'b10) ? (LSU_WDATA << 32'd16) :
    //                    (EXU_LSU_result[1:0]  == 2'b11) ? (LSU_WDATA << 32'd24) : (LSU_WDATA << 32'd0);

ysyx_24070003_mux4_32bit my8(
    .sel            (EXU_LSU_result[1:0]),
    .a              (LSU_WDATA << 32'd0), 
    .b              (LSU_WDATA << 32'd8),
    .c              (LSU_WDATA << 32'd16),
    .d              (LSU_WDATA << 32'd24),
    .out            (lsu_wdata)
);

    //assign lsu_wdata = (LSU_WDATA << (EXU_LSU_result[1:0] << 3));
    //wire [31:0] LSU_WBU_DATA;
    reg [31:0] LSU_WBU_result;
    assign LSU_WBU_DATA = (LSU_REN) ? rdata : LSU_WBU_result;


    //assign addr = alu_result;


assign LSU_IFU_stall = (state != IDLE);



always @(posedge clock) begin
    if (rst_n) begin
        state <= IDLE;
        
        // AXI 信号复位
        LSU_AXI4_ARVALID <= 1'b0;
        LSU_AXI4_RREADY <= 1'b0;
        LSU_AXI4_AWVALID <= 1'b0;
        LSU_AXI4_WVALID <= 1'b0;
        LSU_AXI4_BREADY <= 1'b0;

    

        LSU_AXI_wlast <= 1'b0;
        // lsu_count <=  64'd0;
        // lsu_during_count <= 64'd0;
        // lsu_load_count <= 64'd0;
        // lsu_store_count <= 64'd0;
        LSU_AXI4_ARSIZE <= 3'b0;
    end
    else begin
        case (state)
            IDLE: begin
                LSU_AXI_wlast <= 1'b0;
                
                if((!(EXU_LSU_ren || EXU_LSU_wen))) begin
                    state <= IDLE;
                end else if (EXU_LSU_wen && LSU_EXU_ready && EXU_LSU_valid ) begin
                    LSU_AXI4_AWADDR <= EXU_LSU_result;
                    LSU_AXI4_WDATA <= lsu_wdata;
                    LSU_AXI4_WSTRB <= lsu_wstrb;
                    LSU_AXI4_AWVALID <= 1'b1;
                    LSU_AXI4_WVALID <= 1'b1;
                    LSU_AXI_wlast <= 1'b1; 
                    LSU_AXI4_wsize <= awsize;
                    state <= START;
                end else if ((EXU_LSU_ren && LSU_EXU_ready && EXU_LSU_valid)) begin
                    LSU_AXI4_ARADDR <= EXU_LSU_result;
                    LSU_AXI4_ARSIZE <= lsu_arsize;
                    LSU_AXI4_ARVALID <= 1'b1;
                    state <= START;
                end
            end
                    
            
            START: begin
                if(LSU_AXI4_AWVALID && LSU_AXI4_AWREADY && LSU_AXI4_WVALID && LSU_AXI4_WREADY) begin
                            // lsu_during_count <= lsu_during_count + 1'b1;
                            // lsu_store_count <= lsu_store_count + 1'b1;
                            // lsu_count <= lsu_count + 1'b1;
                            LSU_AXI_wlast <= 1'b1;
                            LSU_AXI4_BREADY <= 1'b1;
                            state <= WRITE_DATA;
                            LSU_AXI4_AWVALID <= 1'b0;
                            LSU_AXI4_WVALID <= 1'b0;
                end else if(LSU_AXI4_AWVALID && LSU_AXI4_AWREADY ) begin
                            LSU_AXI_wlast <= 1'b1;
                            state <= WRITE_WIRE_1;
                            LSU_AXI4_AWVALID <= 1'b0;
                end else if(LSU_AXI4_WVALID && LSU_AXI4_WREADY ) begin
                            LSU_AXI_wlast <= 1'b1;
                            state <= WRITE_WIRE_2;
                            LSU_AXI4_WVALID <= 1'b0;
                end else if(LSU_AXI4_ARVALID && LSU_AXI4_ARREADY) begin
                            // lsu_load_count <= lsu_load_count + 1'b1;
                            // lsu_during_count <= lsu_during_count + 1'b1;
                            LSU_AXI4_RREADY <= 1'b1;
                            state <= READ_START;
                            LSU_AXI4_ARVALID <= 1'b0;
                end else 
                    state <= START;
            end
            
            // 读操作 ------------------------------------------------------
            READ_START: begin
                // 发送读地址
                
                if (LSU_AXI4_RREADY && LSU_AXI4_RVALID) begin
                    //lsu_count <= lsu_count + 1'b1;
                    LSU_AXI4_RREADY <= 1'b0;
                    LSU_RDATA <= LSU_AXI4_RDATA;
                    state <= IDLE;
                end
                else begin
                    //lsu_during_count <= lsu_during_count + 1'b1;
                    //lsu_load_count <= lsu_load_count + 1'b1;
                    state <= READ_START;
                end
            end
            
            // 写操作 ------------------------------------------------------
            WRITE_WIRE_1: begin
                // 发送写地址
                
                if(LSU_AXI4_WVALID && LSU_AXI4_WREADY ) begin
                    //lsu_count <= lsu_count + 1'b1;
                    LSU_AXI_wlast <= 1'b1;
                    state <= WRITE_WIRE_2;
                    LSU_AXI4_WVALID <= 1'b0;
                    LSU_AXI4_BREADY <= 1'b1;
                    state <= WRITE_DATA;
                end else begin
                    
                    state <= WRITE_WIRE_1;
                end
            end
            
            WRITE_WIRE_2: begin
                // 等待另一个握手完成
                if(LSU_AXI4_AWVALID && LSU_AXI4_AWREADY ) begin
                    state <= WRITE_WIRE_1;
                    LSU_AXI4_AWVALID <= 1'b0;
                    LSU_AXI4_BREADY <= 1'b1;
                    state <= WRITE_DATA;
                end else begin
                    state <= WRITE_WIRE_2;
                end
            end
            
            WRITE_DATA: begin   
                
                LSU_AXI_wlast <= 1'b0;
                if(LSU_AXI4_BVALID && LSU_AXI4_BREADY) begin
                    LSU_AXI4_BREADY <= 1'b0;
                    state <= IDLE;  
                end
                else begin
                    state <= WRITE_DATA;
                    //lsu_during_count <= lsu_during_count + 1'b1;
                    //lsu_store_count <= lsu_store_count + 1'b1;
                end
            end
            
            default: state <= IDLE;
        endcase
    end
end

always @(posedge clock) begin
    if(rst_n) begin
        LSU_WBU_valid <= 1'b0;
    end
    else if((LSU_AXI4_RREADY && LSU_AXI4_RVALID) || (LSU_AXI4_BVALID && LSU_AXI4_BREADY)) begin
        LSU_WBU_valid <= 1'b1;
    end
    else if((LSU_EXU_ready && EXU_LSU_valid) && (~(EXU_LSU_ren || EXU_LSU_wen))) begin
        LSU_WBU_valid <= 1'b1;
    end
    else begin
        LSU_WBU_valid <= 1'b0;
    end
end

//import "DPI-C" function void vpmem_read(input int raddr,input byte ren,output int rdata);
//import "DPI-C" function void vpmem_write(input int waddr, input byte wmask,input int wdata,input byte wen);
//reg [31:0] RDATAIN,WDATA;

always @(posedge clock) begin
    if(rst_n)begin
        //RDATAIN <= 32'b0;
        //WDATA   <= 32'b0;
        LSU_WBU_rd <= 5'b0;
        LSU_WBU_result <= 32'b0;
        LSU_WBU_reg <= 1'b0;
        LSU_WBU_ebreak <= 1'b0;
        //LSU_WBU_csr_data <= 32'b0;
        LSU_WBU_ecall <= 1'b0;
        LSU_WBU_mret <= 1'b0;
        LSU_WBU_C_type <= 1'b0;
        LSU_WBU_csr_rst <= 3'b0;
        LSU_WBU_csr_in <= 32'b0;
        //LSU_WBU_JUMP <= 1'b0;
        //LSU_WBU_pc <= 32'b0;
        LSU_REN      <= 1'b0;
        LSU_WBU_skip <= 1'b0;
        LSU_WBU_PC <= 32'b0;
        LSU_WBU_dnpc <= 32'b0;
    end else if((LSU_EXU_ready && EXU_LSU_valid) ) begin
        //RDATAIN <= rdata_in;
        //WDATA   <= wdata;
        LSU_WBU_result <= (EXU_LSU_C_type) ? EXU_LSU_csr_data : EXU_LSU_result;
        LSU_REN      <= EXU_LSU_ren;
        LSU_WBU_rd <= EXU_LSU_rd;
        LSU_WBU_reg<= EXU_LSU_reg;
        LSU_WBU_ebreak<= EXU_LSU_ebreak;
        //LSU_WBU_csr_data <= EXU_LSU_csr_data;
        LSU_WBU_ecall <= EXU_LSU_ecall;
        LSU_WBU_mret <= EXU_LSU_mret;
        LSU_WBU_C_type <= EXU_LSU_C_type;
        LSU_WBU_csr_rst <= EXU_LSU_csr_rst;
        LSU_WBU_csr_in <= EXU_LSU_csr_in;
        //LSU_WBU_JUMP <= EXU_LSU_JUMP;
        //LSU_WBU_pc <= EXU_IFU_pc;
        LSU_WBU_PC <= EXU_LSU_PC;
        LSU_WBU_dnpc <= EXU_LSU_dnpc;
        LSU_WBU_skip <= EXU_skip ;

    end 
end


assign LSU_EXU_ready = ((state == IDLE) && LSU_WBU_ready);
/*
sram_data data_sram(
    .CLK(clk),
    .wen(EXU_LSU_wen),
    .ren(EXU_LSU_ren),
    .wlen(wlen),
    .addr(addr),
    .data(wdata),
    .Q(rdata_in)
);
*/

endmodule
