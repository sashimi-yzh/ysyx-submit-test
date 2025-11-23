import "DPI-C" function void branch_count(input int all_counter_branch,input int miss_counter_branch);
import "DPI-C" function void get_pc_inst(input int pc, input int dnpc, input int inst, input int EXU_valid_int);
module ysyx_24120011_EXU (
    input  clk,
    input  rst,
    //数据
    input  [2:0]  i_pc_ctrl,
    input  [2:0]  i_rd_ctrl,
    input  [5:0]  i_ALU_ctrl,
    input  [6:0] i_mem_ctrl,
    input  [2:0]  i_csr_ctrl,
    input  [31:0] i_pc,
    input  [31:0] i_src1,
    input  [31:0] i_src2,
    input  [31:0] i_r_csr_data,
    input  [31:0] i_imm,
    input  [3:0]  i_rd,
    input  [11:0] i_w_csr_addr,

    //output [2:0]  o_rd_ctrl,
    output [6:0] o_mem_ctrl,
    //output [2:0]  o_csr_ctrl,
    //output [31:0] o_pc,
    //output [31:0] o_src1,
    output [31:0] o_src2,
    //output [31:0] o_r_csr_data,
    //output [31:0] o_imm,
    output [3:0]  o_rd,
    output [11:0] o_w_csr_addr,
    output [31:0] o_ALU_result,

    output [31:0] o_rd_data,
    output [1:0]  o_rd_data_type,
    output [31:0] o_w_csr_data,
    output o_w_csr_en,
    output o_w_csr_ecall,

    output [31:0] o_npc,
    //握手
    input  i_IDU_valid,
    output o_EXU_ready,
    input  i_MEM_ready,
    output o_EXU_valid,
    //======================dpic========================//
    input [31:0] i_inst,
    //======================dpic========================//
    //flush
    output o_flush,
    input [31:0] i_IFU_pc,
    input  i_IDU_empty
);
//======================dpic========================//
wire [31:0] EXU_valid_int;
assign EXU_valid_int    = {31'b0,o_EXU_valid};
reg [31:0] miss_counter_branch;
reg [31:0] all_counter_branch;
always @(posedge clk ) begin
    branch_count(all_counter_branch,miss_counter_branch);
end
always@(negedge clk) begin
    get_pc_inst(pc,npc,inst,EXU_valid_int);
end
always @(posedge clk) begin
    if (rst) begin
        miss_counter_branch <= 'd0;
        all_counter_branch  <= 'd0;
    end else begin
        if(o_EXU_valid) begin
            all_counter_branch <= all_counter_branch + 1;
            if (i_IDU_empty) begin
                if (i_IFU_pc != npc) begin
                    miss_counter_branch <= miss_counter_branch + 1;
                end 
            end else begin
                if (i_pc != npc) begin
                    miss_counter_branch <= miss_counter_branch + 1;
                end 
            end
        end
    end
end
//======================dpic========================//
parameter ysyx_24120011_EXU_IDLE_EMPTY = 2'd0;
parameter ysyx_24120011_EXU_IDLE_FULL  = 2'd1;
parameter ysyx_24120011_EXU_WORKING    = 2'd2;

reg [2:0]  pc_ctrl;
reg [2:0]  rd_ctrl;
reg [5:0]  ALU_ctrl;
reg [6:0] mem_ctrl;
reg [2:0]  csr_ctrl;
reg [31:0] pc;
reg [31:0] src1;
reg [31:0] src2;
reg [31:0] r_csr_data;
reg [31:0] imm;
reg [3:0]  rd;
reg [11:0] w_csr_addr;

//======================dpic========================//
reg [31:0] inst;
//======================dpic========================//

reg [1:0] state;
reg [1:0] next_state;

assign o_flush = flush;
reg flush;
always @(posedge clk) begin
    if(o_EXU_valid) begin
        if (i_IDU_empty) begin
            if (i_IFU_pc != npc) begin
                flush <= 1'b1;
            end else begin
                flush <= 1'b0;
            end
        end else begin
            if (i_pc != npc) begin
                flush <= 1'b1;
            end else begin
                flush <= 1'b0;
            end
        end
    end
    else begin
        flush <= 1'b0;
    end
end
//assign o_flush = !o_EXU_valid ? 1'b0 : (i_IDU_empty ? (i_IFU_pc != npc ? 1'b1 : 1'b0) : (i_pc != npc ? 1'b1 : 1'b0));

assign o_EXU_ready  = (state == ysyx_24120011_EXU_IDLE_EMPTY) ? 1'b1 : 1'b0;
assign o_EXU_valid  = (state == ysyx_24120011_EXU_IDLE_FULL && next_state == ysyx_24120011_EXU_IDLE_EMPTY) ? 1'b1 : 1'b0;

//assign o_rd_ctrl    = rd_ctrl     ;
assign o_mem_ctrl   = mem_ctrl    ;
//assign o_csr_ctrl   = csr_ctrl    ;
//assign o_pc         = pc          ;
//assign o_src1       = src1        ;
assign o_src2       = src2        ;
//assign o_r_csr_data = r_csr_data  ;
//assign o_imm        = imm         ;
assign o_rd         = rd          ;
assign o_w_csr_addr = w_csr_addr  ;
assign o_ALU_result = ALU_result  ;
assign o_npc        = npc         ;

assign o_rd_data    = rd_data     ;
assign o_w_csr_data = w_csr_data  ;

//指令锁存
always @(posedge clk) begin
    // if(rst) begin
    //     pc_ctrl    <=  'd0;
    //     rd_ctrl    <=  'd0;
    //     ALU_ctrl   <=  'd0;
    //     mem_ctrl   <=  'd0;
    //     csr_ctrl   <=  'd0;
    //     pc         <=  'd0;
    //     src1       <=  'd0;
    //     src2       <=  'd0;
    //     r_csr_data <=  'd0;
    //     imm        <=  'd0;
    //     rd         <=  'd0;
    //     w_csr_addr <=  'd0;
    // end
    //else begin
        //输入握手
        if(i_IDU_valid && o_EXU_ready) begin
            pc_ctrl    <=  i_pc_ctrl   ;
            rd_ctrl    <=  i_rd_ctrl   ;
            ALU_ctrl   <=  i_ALU_ctrl  ;
            mem_ctrl   <=  i_mem_ctrl  ;
            csr_ctrl   <=  i_csr_ctrl  ;
            pc         <=  i_pc        ;
            src1       <=  i_src1      ;
            src2       <=  i_src2      ;
            r_csr_data <=  i_r_csr_data;
            imm        <=  i_imm       ;
            rd         <=  i_rd        ;
            w_csr_addr <=  i_w_csr_addr;
            //======================dpic========================//
            inst       <= i_inst;
            //======================dpic========================//
        end
    //end
end
// always @(*) begin
//             pc_ctrl    =  i_pc_ctrl   ;
//             rd_ctrl    =  i_rd_ctrl   ;
//             ALU_ctrl   =  i_ALU_ctrl  ;
//             mem_ctrl   =  i_mem_ctrl  ;
//             csr_ctrl   =  i_csr_ctrl  ;
//             pc         =  i_pc        ;
//             src1       =  i_src1      ;
//             src2       =  i_src2      ;
//             r_csr_data =  i_r_csr_data;
//             imm        =  i_imm       ;
//             rd         =  i_rd        ;
//             w_csr_addr =  i_w_csr_addr;
// end

//状态机跳转
always@(*)begin
    case(state)
        ysyx_24120011_EXU_IDLE_EMPTY : next_state = (i_IDU_valid && o_EXU_ready) ? ysyx_24120011_EXU_IDLE_FULL : ysyx_24120011_EXU_IDLE_EMPTY;
        ysyx_24120011_EXU_IDLE_FULL  : next_state = (i_MEM_ready) ? ysyx_24120011_EXU_IDLE_EMPTY : ysyx_24120011_EXU_IDLE_FULL;
        ysyx_24120011_EXU_WORKING    : next_state = ysyx_24120011_EXU_IDLE_EMPTY;
        default                      : next_state = ysyx_24120011_EXU_IDLE_EMPTY;
    endcase
end
always@(posedge clk)begin
    if(rst) begin
        state <= ysyx_24120011_EXU_IDLE_EMPTY;
    end
    else begin
        state <= next_state;
    end
end

//ALU逻辑
wire [31:0] A;
reg  [31:0] B;
reg  [31:0] ALU_result;

assign A = src1;
//多路选择器，选择B
always@(*)begin
    case(ALU_ctrl[5:4])
        2'd0: B = imm;
        2'd1: B = src2;
        2'd2: B = r_csr_data;
        default: B = 32'b0;
    endcase
end
//ALU
wire [31:0] B_in;
wire [31:0] B_in_used_for_overflow;
wire [31:0] ALUout_tmp;
wire carry;
wire overflow;
wire uless;
wire sless;
wire a_is_b;
wire a_not_b;
assign B_in = ALU_ctrl[0] ? ((B^{32{ALU_ctrl[0]}}) + 1'b1) : B;
assign B_in_used_for_overflow = ALU_ctrl[0] ? B^{32{ALU_ctrl[0]}} : B;
assign uless = ~carry;//无符号a<b标志
assign sless = ALUout_tmp[31] ^ overflow;
assign overflow = (A[31]==B_in_used_for_overflow[31]) && (A[31]!=ALUout_tmp[31]);
assign a_is_b  = A == B ? 1 : 0;
assign a_not_b = A != B ? 1 : 0;

assign {carry, ALUout_tmp} = A + B_in;

always @(*) begin
    case (ALU_ctrl[3:0])
        //4'b0000, 4'b0001, 4'b1010, 4'b1110: ALU_result = ALUout_tmp;
        4'b1000: ALU_result = {31'b0, a_is_b};
        4'b1001: ALU_result = {31'b0, a_not_b};
        4'b0011: ALU_result = {31'b0, sless};
        4'b1011: ALU_result = (B == 32'b0) ? 32'b0 : {31'b0, uless};
        4'b0111: ALU_result = {31'b0, ~sless};
        4'b1111: ALU_result = (B == 32'b0) ? 32'h1 : {31'b0, ~uless};
        4'b0010: ALU_result = A ^ B;
        4'b0100: ALU_result = A >> B[4:0]; //逻辑右移
        4'b1100: ALU_result = (B[4:0] == 0) ? A :  (A >> B[4:0]) | ({32{A[31]}} << (32-B[4:0]));//算术右移 //算术右移
        4'b0101: ALU_result = A | B;
        4'b1101: ALU_result = A & B;
        4'b0110: ALU_result = A << B[4:0]; //左移
        default: ALU_result = ALUout_tmp;
    endcase
end


//pc逻辑
reg  [31:0] npc;
always@(*)begin
    case(pc_ctrl)
        3'd0: npc = pc + 32'd4;
        3'd1: npc = pc + imm;
        3'd2: npc = ALU_result;
        3'd3: npc = r_csr_data;
        3'd4: begin
            if(ALU_result[0] == 1'b1)begin
                npc = pc + imm;
            end
            else begin
                npc = pc + 32'd4;
            end
        end
        default: npc = 32'h0000_0000;
    endcase
end

//rd_data解码
reg [31:0] rd_data;
assign o_rd_data_type = (rd_ctrl == 3'd4) ? 2'd0 : (rd_ctrl == 3'd5 ? 2'd1 : 2'd2);
//0:不写入　1:应在MEM写入i_r_mem_data 2:已写好
always@(*)begin
    case(rd_ctrl)
        3'd0: rd_data = pc + 32'd4;
        3'd1: rd_data = pc + imm;
        3'd2: rd_data = ALU_result;
        3'd3: rd_data = imm;
        3'd4: rd_data = 32'h0000_0000;
        3'd5: rd_data = 32'h0000_0000;
        3'd6: rd_data = r_csr_data;
        default: rd_data = 32'h0000_0000;
    endcase
end
//csr_data解码
reg [31:0] w_csr_data;
assign o_w_csr_en =  csr_ctrl[1:0] == 2'd0 ? 1'b0 : 1'b1;
assign o_w_csr_ecall =  csr_ctrl[2] == 1'd0 ? 1'b0 : 1'b1;

always@(*)begin
    case(csr_ctrl[1:0])
        //2'd0:    w_csr_data = 32'b0;
        2'd1:    w_csr_data = src1;
        2'd2:    w_csr_data = ALU_result;
        2'd3:    w_csr_data = pc;
        default: w_csr_data = 32'b0;
    endcase
end
endmodule