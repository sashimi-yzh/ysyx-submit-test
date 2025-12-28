module ysyx_24070003_ifu(
    input clock,
    input rstn,
    //input WBU_IFU_JUMP,
     //IDU是否准备好接收IFU的指令
    output IFU_IDU_valid, //IFU传递给IDU的指令是否有效
    input  IDU_IFU_ready, //IDU是否准备好接收IFU的指令
    input [31:0]EXU_IFU_pc,
    input       EXU_IFU_flush,
    //input [31:0] BTB_pred_pc,
    //input       BTB_pred_valid,
    input [1:0] resp,
    //output [31:0] inst_addr_o,
    output [31:0]IFU_IDU_INSTR,
    //input  [31:0] instr_in,
    output  [31:0] IFU_IDU_PC,
    output  [31:0] cur_pc,


    //input  EXU_LSU_valid,

    input  fence_i,
    input  stall,
    //output [31:0]     BTB_pre_DNPC,

    output reg [63:0] ifu_count,

    // AXI-Lite4 Interface
    output  [31:0] IFU_ICACHE_araddr,
    output            IFU_ICACHE_arvalid,
    // input             IFU_AXI4_arready,
    input  [31:0]     ICACHE_IFU_rdata,
    input             ICACHE_IFU_rvalid,
    output         IFU_ICACHE_rready,
    input  [31:0]     ICACHE_IFU_raddr,
    input             ICACHE_IFU_stall
    
);
reg [31:0] pc;



assign cur_pc = pc;
//assign BTB_pre_DNPC = BTB_pred_pc;
always@(posedge clock)
begin 
   if(rstn)begin
    `ifdef NPC_PC
    pc<=32'h80000000 ;
    `else
    pc<=32'h30000000 ;
   `endif
    end
    else if(EXU_IFU_flush)begin 
    pc <= EXU_IFU_pc;
    end
    else if(stall) begin
    pc <= pc;
    end
    //else if(BTB_pred_valid && IDU_IFU_ready && (~ICACHE_IFU_stall)) begin
    //pc <= BTB_pred_pc;
    //end
    else if(IDU_IFU_ready && (~ICACHE_IFU_stall))begin
    pc <= pc + 32'h4;
    end
end


assign IFU_IDU_valid = ICACHE_IFU_rvalid;

assign IFU_ICACHE_araddr = pc;

assign IFU_ICACHE_arvalid = (~stall && !EXU_IFU_flush && !fence_i);


assign IFU_IDU_INSTR = ICACHE_IFU_rdata;
assign IFU_IDU_PC   = ICACHE_IFU_raddr;   // 早就发出的地址


assign IFU_ICACHE_rready = IDU_IFU_ready;

always @(posedge clock) begin
    if (rstn) begin
        ifu_count <= 64'h0;
    end
    else if(IDU_IFU_ready && IFU_IDU_valid)begin
        ifu_count <= ifu_count + 1'b1;
    end
end


/*
sram_inst inst_sram(
    .CLK(clk),
    .wen(1'b0),
    .addr(inst_addr),
    .Q(instr)
);*/
endmodule
