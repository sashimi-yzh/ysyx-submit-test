module ysyx_24120011_IDU (
    input  clk,
    input  rst,
    //数据
    input  [31:0] i_pc,
    input  [31:0] i_inst,
    output [2:0]  o_pc_ctrl,
    output [2:0]  o_rd_ctrl,
    output [5:0]  o_ALU_ctrl,
    output [6:0] o_mem_ctrl,
    output [2:0]  o_csr_ctrl,
    output [31:0] o_pc,
    output [31:0] o_src1,
    output [31:0] o_src2,
    output [31:0] o_r_csr_data,
    output [31:0] o_imm,
    output [3:0]  o_rd,
    output [11:0] o_w_csr_addr,
    //握手
    input  i_IFU_valid,
    output o_IDU_ready,
    input  i_EXU_ready,
    output o_IDU_valid,
    //读寄存器
    output [3:0]  o_rs1,
    output [3:0]  o_rs2,
    input  [31:0] i_src1,
    input  [31:0] i_src2,
    output [11:0] o_r_csr_addr,
    input  [31:0] i_r_csr_data,
    //暂停流水线
    input i_stop_pipe,
    input [31:0] i_rd_data,
    input i_rs1_or_rs2,
    input i_bypass,
    //======================dpic========================//
    output [31:0] o_inst,
    //======================dpic========================//
    //冲刷流水线
    input i_flush
);

parameter ysyx_24120011_IDU_IDLE_EMPTY = 2'd0;
parameter ysyx_24120011_IDU_IDLE_FULL  = 2'd1;
parameter ysyx_24120011_IDU_WORKING    = 2'd2;

reg [31:0] inst;
reg [31:0] pc;
reg [1:0] state;
reg [1:0] next_state;

assign o_IDU_ready  = (state == ysyx_24120011_IDU_IDLE_EMPTY) ? 1'b1 : 1'b0;
assign o_IDU_valid  = !i_flush && (state == ysyx_24120011_IDU_IDLE_FULL && next_state == ysyx_24120011_IDU_IDLE_EMPTY) ? 1'b1 : 1'b0;
//======================dpic========================//
assign o_inst       = inst;
//======================dpic========================//
assign o_rs1        = rs1;
assign o_rs2        = rs2;
assign o_r_csr_addr = r_csr_addr;
assign o_pc_ctrl    = pc_ctrl;
assign o_rd_ctrl    = rd_ctrl;
assign o_ALU_ctrl   = ALU_ctrl;
assign o_mem_ctrl   = mem_ctrl;
assign o_csr_ctrl   = csr_ctrl;
assign o_pc         = pc;
assign o_src1       = !i_bypass ? i_src1 :((!i_rs1_or_rs2) ? i_rd_data : i_src1);
assign o_src2       = !i_bypass ? i_src2 :((i_rs1_or_rs2) ? i_rd_data : i_src2);
assign o_r_csr_data = i_r_csr_data;
assign o_imm        = imm;
assign o_rd         = rd;
assign o_w_csr_addr = w_csr_addr;

//指令锁存
always @(posedge clk) begin
    // if(rst) begin
    //     inst <= 32'h0000_0000;
    //     pc   <= 32'h0000_0000;
    // end
    //else begin
        //输入握手
        if(i_IFU_valid && o_IDU_ready) begin
            inst <= i_inst;
            pc   <= i_pc;
        end
    //end
end

// always @(*) begin
//             inst = i_inst;
//             pc   = i_pc;
// end
wire a;
assign a = i_stop_pipe && (state == ysyx_24120011_IDU_IDLE_FULL);
wire b;
assign b = i_bypass && o_IDU_valid;
//状态机跳转
always@(*)begin
    case(state)
        ysyx_24120011_IDU_IDLE_EMPTY : next_state = (!i_flush && i_IFU_valid && o_IDU_ready) ? ysyx_24120011_IDU_IDLE_FULL : ysyx_24120011_IDU_IDLE_EMPTY;
        ysyx_24120011_IDU_IDLE_FULL  : next_state = (i_flush || (!i_stop_pipe && i_EXU_ready)) ? ysyx_24120011_IDU_IDLE_EMPTY : ysyx_24120011_IDU_IDLE_FULL;
        ysyx_24120011_IDU_WORKING    : next_state = ysyx_24120011_IDU_IDLE_EMPTY;
        default                      : next_state = ysyx_24120011_IDU_IDLE_EMPTY;
    endcase
end
always@(posedge clk)begin
    if(rst) begin
        state <= ysyx_24120011_IDU_IDLE_EMPTY;
    end
    else begin
        state <= next_state;
    end
end

//指令解码
wire [6:0]  opcode;
wire [3:0]  rd    ;
wire [3:0]  rs1   ;
wire [3:0]  rs2   ;
wire [2:0]  func3 ;
wire [6:0]  func7 ;
reg  [2:0]  opcode_type;
reg  [31:0] imm;
reg  [2:0]  pc_ctrl;
reg  [2:0]  rd_ctrl;
reg  [5:0]  ALU_ctrl;
reg  [6:0] mem_ctrl;
reg  [11:0] r_csr_addr;
reg  [11:0] w_csr_addr;
reg  [2:0]  csr_ctrl;

assign opcode   = inst[6:0];
assign rd       = inst[10:7];
assign rs1      = inst[18:15];
assign rs2      = inst[23:20];
assign func3    = inst[14:12];
assign func7    = inst[31:25];

always@(*)begin
    case(opcode) 
        7'b0010011:opcode_type = 3'd0;//I-Type
        7'b1100111:opcode_type = 3'd0;//I-Type
        7'b0000011:opcode_type = 3'd0;//I-Type
        7'b1110011:opcode_type = 3'd0;//I-Type
        7'b0010111:opcode_type = 3'd1;//U-Type
        7'b0110111:opcode_type = 3'd1;//U-Type
        7'b1101111:opcode_type = 3'd2;//J-Type
        7'b0100011:opcode_type = 3'd3;//S-Type
        7'b0110011:opcode_type = 3'd4;//R-Type
        7'b1100011:opcode_type = 3'd5;//B-Type
        default   :opcode_type = 3'd7;//Unknown
    endcase
end

always@(*)begin
    case(opcode_type)
        3'd0      : imm = {{20{inst[31]}},inst[31:20]};//I-Type
        3'd1      : imm = {inst[31:12],12'b0};//U-Type
        3'd2      : imm = {{11{inst[31]}},inst[31],inst[19:12],inst[20],inst[30:21],1'b0};//J-Type
        3'd3      : imm = {{20{inst[31]}},inst[31:25],inst[11:7]};//S-Type
        3'd5      : imm = {{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0};//B-Type
        default   : imm = 32'h0000_0000;//Unknown/R-Type
    endcase
end

//--------------------PC---------------------//
//3'd0: pc_add_4;
//3'd1: pc_add_imme;
//3'd2: alu_result;
//3'd3: r_csr_data;
//3'd4: b_type;
always@(*)begin
    case(opcode_type)
        3'd0:begin //I-Type
            if(opcode == 7'b1100111 && func3 == 3'b000)begin//jalr
                 pc_ctrl = 3'd2;
            end
            else if(inst == 32'b00110000001000000000000001110011)begin//mret
                 pc_ctrl = 3'd3;
            end
            else if(inst == 32'b00000000000000000000000001110011)begin//ecall
                 pc_ctrl = 3'd3;
            end
            else begin
                 pc_ctrl = 3'd0;
            end
        end
        3'd2:    pc_ctrl = 3'd1;//J-Type jal
        3'd3:    pc_ctrl = 3'd0;//S-Type sw
        3'd4:    pc_ctrl = 3'd0;//R-Type
        3'd5:    pc_ctrl = 3'd4;//B-Type
        default: pc_ctrl = 3'd0;
    endcase
end
//--------------------PC---------------------//

//--------------------Rd---------------------//
//3'd0: pc_add_4;
//3'd1: pc_add_imme;
//3'd2: alu_result;
//3'd3: imme;
//3'd4: w_en = 1'd0;
//3'd5: rdata;
//3'd6: r_csr_data;
always@(*)begin
    if(rd == 4'b0000) begin
        rd_ctrl = 3'd4;
    end
    else begin
        case(opcode_type)
            3'd0:begin //I-Type
                if(opcode == 7'b1100111 && func3 == 3'b000)begin//jalr
                    rd_ctrl = 3'd0;
                end
                else if(opcode == 7'b0000011)begin//lb lbu lh lhu lw
                    rd_ctrl = 3'd5;
                end
                else if(opcode == 7'b1110011 && func3 == 3'b001)begin//csrrw
                    rd_ctrl = 3'd6;
                end
                else if(opcode == 7'b1110011 && func3 == 3'b010)begin//csrrs
                    rd_ctrl = 3'd6;
                end
                else begin
                    rd_ctrl = 3'd2;
                end
            end
            3'd1:begin //U-Type
                if(opcode == 7'b0010111)begin//auipc
                    rd_ctrl = 3'd1;
                end
                else if(opcode == 7'b0110111)begin//lui
                    rd_ctrl = 3'd3;
                end
                else begin
                    rd_ctrl = 3'd0;
                end
            end
            3'd2:    rd_ctrl = 3'd0;//J-Type jal
            3'd3:    rd_ctrl = 3'd4;//S-Type sw
            3'd4:    rd_ctrl = 3'd2;//R-Type
            3'd5:    rd_ctrl = 3'd4;//B-Type
            default: rd_ctrl = 3'd0;
        endcase
    end
end
//--------------------Rd---------------------//

//--------------------ALUB-------------------//
//ALU_ctrl[5:4] == 2'd0 -> imme
//ALU_ctrl[5:4] == 2'd1 -> src2
//ALU_ctrl[5:4] == 2'd2 -> r_csr_data
always@(*)begin
    case(opcode_type)//I-Type
        3'd0:begin
            if(opcode == 7'b1110011 && func3 == 3'b010)begin//csrrs
                ALU_ctrl[5:4] = 2'd2;
            end
            else begin
                ALU_ctrl[5:4] = 2'd0;
            end
        end
        3'd3:    ALU_ctrl[5:4] = 2'd0;//S-Type sw
        3'd4:    ALU_ctrl[5:4] = 2'd1;//R-Type
        3'd5:    ALU_ctrl[5:4] = 2'd1;//B-Type
        default: ALU_ctrl[5:4] = 2'd1;
    endcase
end
//--------------------ALUB-------------------//

//--------------------ALU--------------------//
// ALUctr[3]     ALUctr[2:0]     ALU操作
// 0             000             加法
// 1             000             A==B
// 0             001             减法
// 1             001             A!=B
// 0             010             异或
// 1             010             
// 0             011             带符号小于
// 1             011             无符号小于
// 0             100             逻辑右移
// 1             100             算术右移
// 0             101             或
// 1             101             与
// 0             110             逻辑左移
// 1             110             
// 0             111             带符号大于等于
// 1             111             无符号大于等于
always@(*)begin
    case(opcode_type)
        3'd0:begin//I-Type
            if(func3 == 3'b000 && opcode == 7'b0010011)begin//addi
                ALU_ctrl[3:0] = 4'b0000;
            end
            else if(func3 == 3'b011 && opcode == 7'b0010011)begin//sltiu
                ALU_ctrl[3:0] = 4'b1011;
            end
            else if(func3 == 3'b111 && opcode == 7'b0010011)begin//andi
                ALU_ctrl[3:0] = 4'b1101;
            end
            else if(func3 == 3'b100 && opcode == 7'b0010011)begin//xori
                ALU_ctrl[3:0] = 4'b0010;
            end
            else if(func3 == 3'b110 && opcode == 7'b0010011)begin//ori
                ALU_ctrl[3:0] = 4'b0101;
            end
            else if(func3 == 3'b101 && opcode == 7'b0010011 && func7 == 7'b0100000)begin//srai
                ALU_ctrl[3:0] = 4'b1100;
            end
            else if(func3 == 3'b101 && opcode == 7'b0010011 && func7 == 7'b0000000)begin//srli
                ALU_ctrl[3:0] = 4'b0100;
            end
            else if(func3 == 3'b001 && opcode == 7'b0010011 && func7 == 7'b0000000)begin//slli
                ALU_ctrl[3:0] = 4'b0110;
            end
            else if(opcode == 7'b1110011 && func3 == 3'b010)begin//csrrs
                ALU_ctrl[3:0] = 4'b0101;
            end
            else begin
                ALU_ctrl[3:0] = 4'b0000;
            end
        end
        3'd3:   ALU_ctrl[3:0] = 4'd0;//S-Type
        3'd4:begin//R-Type
            if(func3 == 3'b000 && func7 == 7'b0000000)begin//add
                ALU_ctrl[3:0] = 4'b0000;
            end
            else if(func3 == 3'b000 && func7 == 7'b0100000)begin//sub
                ALU_ctrl[3:0] = 4'b0001;
            end
            else if(func3 == 3'b011 && func7 == 7'b0000000)begin//sltu
                ALU_ctrl[3:0] = 4'b1011;
            end
            else if(func3 == 3'b010 && func7 == 7'b0000000)begin//slt
                ALU_ctrl[3:0] = 4'b0011;
            end
            else if(func3 == 3'b100 && func7 == 7'b0000000)begin//xor
                ALU_ctrl[3:0] = 4'b0010;
            end
            else if(func3 == 3'b001 && func7 == 7'b0000000)begin//sll
                ALU_ctrl[3:0] = 4'b0110;
            end
            else if(func3 == 3'b111 && func7 == 7'b0000000)begin//and
                ALU_ctrl[3:0] = 4'b1101;
            end
            else if(func3 == 3'b101 && func7 == 7'b0100000)begin//sra
                ALU_ctrl[3:0] = 4'b1100;
            end
            else if(func3 == 3'b110 && func7 == 7'b0000000)begin//or
                ALU_ctrl[3:0] = 4'b0101;
            end
            else if(func3 == 3'b101 && func7 == 7'b0000000)begin//srl
                ALU_ctrl[3:0] = 4'b0100;
            end
            else begin
                ALU_ctrl[3:0] = 4'b0000;
            end
        end
        3'd5:begin//B-Type
            if(func3 == 3'b000)begin//beq
                ALU_ctrl[3:0] = 4'b1000;
            end
            else if(func3 == 3'b001)begin//bne
                ALU_ctrl[3:0] = 4'b1001;
            end
            else if(func3 == 3'b101)begin//bge
                ALU_ctrl[3:0] = 4'b0111;
            end
            else if(func3 == 3'b111)begin//bgeu
                ALU_ctrl[3:0] = 4'b1111;
            end
            else if(func3 == 3'b100)begin//blt
                ALU_ctrl[3:0] = 4'b0011;
            end
            else if(func3 == 3'b110)begin//bltu
                ALU_ctrl[3:0] = 4'b1011;
            end
            else begin
                ALU_ctrl[3:0] = 4'b0000;
            end
        end
        default: ALU_ctrl[3:0] = 4'd0;
    endcase
end
//--------------------ALU--------------------//

//--------------------mem--------------------//
//Sign_extension R_mem_en R_mem_len W_mem_en W_men_len
//[18]           [17]     [16:9]    [8]      [7:0]
//Sign_extension R_mem_en R_mem_len W_mem_en W_men_len
//[6]            [5]      [4:3]     [2]      [1:0]
//len 0->1,1->2,2->4
//--------------------w_mem------------------//
always@(*)begin
    case(opcode_type)
        3'd3:begin //S-Type
            mem_ctrl[2] = 1'd1;

            if(func3 == 3'b000)begin//sb
                 mem_ctrl[1:0] = 2'd0;
            end
            else if(func3 == 3'b001)begin//sh
                 mem_ctrl[1:0] = 2'd1;
            end
            else if(func3 == 3'b010)begin//sw
                 mem_ctrl[1:0] = 2'd2;
            end
            else begin
                 mem_ctrl[1:0] = 2'd0;
            end
        end
        default: begin 
            mem_ctrl[2] = 1'd0;
            mem_ctrl[1:0] = 2'd0;
        end
    endcase
end
//--------------------w_mem------------------//
//--------------------r_mem------------------//
always@(*)begin
    case(opcode_type)
        3'd0:begin //I-Type
            if(opcode == 7'b0000011)begin//lb lbu lh lhu lw
                mem_ctrl[5] = 1'd1;

                if(func3 == 3'b000)begin//lb
                    mem_ctrl[4:3] = 2'd0;
                    mem_ctrl[6] = 1'd1;
                end
                else if(func3 == 3'b001)begin//lh
                    mem_ctrl[4:3] = 2'd1;
                    mem_ctrl[6] = 1'd1;
                end
                else if(func3 == 3'b010)begin//lw
                    mem_ctrl[4:3] = 2'd2;
                    mem_ctrl[6] = 1'd1;
                end
                else if(func3 == 3'b100)begin//lbu
                    mem_ctrl[4:3] = 2'd0;
                    mem_ctrl[6] = 1'd0;
                end
                else if(func3 == 3'b101)begin//lhu
                    mem_ctrl[4:3] = 2'd1;
                    mem_ctrl[6] = 1'd0;
                end
                else begin
                    mem_ctrl[4:3] = 2'd0;
                    mem_ctrl[6] = 1'd0;
                end
            end
            else begin
                mem_ctrl[5] = 1'd0;
                mem_ctrl[4:3] = 2'd0;
                mem_ctrl[6] = 1'd0;
            end
        end
        default: begin 
            mem_ctrl[5] = 1'd0;
            mem_ctrl[4:3] = 2'd0;
            mem_ctrl[6] = 1'd0;
        end
    endcase
end
//--------------------r_mem------------------//
//--------------------mem--------------------//

//--------------------CSR--------------------//
//2'd0 => 32'b0
//2'd1 => src1
//2'd2 => alu_result
//2'd3 => pc
always@(*)begin
    case(opcode_type)
        3'd0:begin //I-Type
            if(inst == 32'b00110000001000000000000001110011)begin//mret
                r_csr_addr  = 12'h341;//mepc
                w_csr_addr  = 12'b0;
                csr_ctrl    = {1'b0,2'd0};
            end
            else if(inst == 32'b00000000000000000000000001110011)begin//ecall
                //由于要同时写两个寄存器，但目前就传了一个地址mepc
                //对ecall进行特殊配置
                r_csr_addr  = 12'h305;//mtvec
                w_csr_addr  = 12'h341;//mepc
                csr_ctrl    = {1'b1,2'd3};
            end
            else if(opcode == 7'b1110011 && func3 == 3'b001)begin//csrrw
                r_csr_addr  = imm[11:0];
                w_csr_addr  = imm[11:0];
                csr_ctrl    = {1'b0,2'd1};
            end
            else if(opcode == 7'b1110011 && func3 == 3'b010)begin//csrrs
                r_csr_addr  = imm[11:0];
                w_csr_addr  = imm[11:0];
                csr_ctrl    = {1'b0,2'd2};
            end
            else begin
                r_csr_addr  = 12'b0;
                w_csr_addr  = 12'b0;
                csr_ctrl    = {1'b0,2'd0};
            end
        end
        default: begin 
            r_csr_addr  = 12'b0;
            w_csr_addr  = 12'b0;
            csr_ctrl    = {1'b0,2'd0};
        end
    endcase
end
//--------------------CSR--------------------//
endmodule