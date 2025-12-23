module control(
    input [31:0] instr,
    input [6:0] opcode,
    input [6:0] funct7,
    input [2:0] funct3,
    input zero,
    output  [1:0] alu_op,
    output        u_alu_type, //无符号运算
    output        mul_high, //乘法高位
    output        alu_src1,
    output        alu_src2,
    output        branch,
    //output        jump,
    output        mem_to_reg,
    output        mem_read,
    output        mem_write,
    output        reg_write,
    output        jal,
    output        jalr,
    output        lw,
    output        lh,
    output        lb,
    output        lbu,
    output        lhu,
    output        sw,
    output        sb,
    output        sh,
    output        csw,
    output        csc,
    output        css,
    output        ebreak,
    output        ecall,
    output        mret,
    output        U_type_1,
    output        J_type_1,
    output        pcsrc,
    output        C_type
);


wire U_type;
wire J_type;
wire S_type;
wire R_type;
wire B_type;
assign R_type = (opcode == 7'b0110011);
assign S_type = (opcode == 7'b0100011);
assign U_type = (opcode == 7'b0110111 || opcode == 7'b0010111);
assign B_type = (opcode == 7'b1100011);
assign J_type = (opcode == 7'b1101111 || opcode == 7'b1011111);
assign J_type_1 = (opcode == 7'b1101111) || I_type_2; 
assign C_type = (opcode == 7'b1110011);
wire I_type_1 = (opcode == 7'b0010011);
wire I_type_2 = (opcode == 7'b1100111);
wire I_type_3 = (opcode == 7'b0000011);
wire I_type_4 = (opcode == 7'b1010011);
assign jalr = (opcode == 7'b1100111);
assign jal  = (opcode == 7'b1101111);
assign U_type_1 = (opcode == 7'b0110111);

assign csw = ( C_type && funct3 == 3'b001 );
assign csc = ( C_type && funct3 == 3'b011 );
assign css = ( C_type && funct3 == 3'b010 );

assign lh   = (I_type_3 && funct3 == 3'b001);
assign lw   = (I_type_3 && funct3 == 3'b010);
assign lb   = (I_type_3 && funct3 == 3'b000);
assign lbu  = (I_type_3 && funct3 == 3'b100);
assign lhu  = (I_type_3 && funct3 == 3'b101);

assign sw   = (S_type && funct3 == 3'b010);
assign sb   = (S_type && funct3 == 3'b000);
assign sh   = (S_type && funct3 == 3'b001);


wire remu = (R_type && funct7 == 7'b0000001 && funct3 == 3'b111);
wire mulh = (R_type && funct7 == 7'b0000001 && funct3 == 3'b001);
wire mulhu= (R_type && funct7 == 7'b0000001 && funct3 == 3'b011);
wire divu = (R_type && funct7 == 7'b0000001 && funct3 == 3'b101);
wire sltu = (R_type && funct7 == 7'b0000000 && funct3 == 3'b011);
wire mul  = (R_type && funct7 == 7'b0000001 && funct3 == 3'b000);
wire sltiu= (I_type_1 && funct3 == 3'b011);
wire bltu = (B_type && funct3 == 3'b110);
wire bgeu = (B_type && funct3 == 3'b111);

assign u_alu_type = (mulhu | divu | sltu | mul | sltiu | bltu | bgeu | remu | lbu | lhu ) ? 1'b1 : 1'b0;
assign mul_high = mulh | mulhu;
wire jump = J_type | I_type_2;
assign mem_read = I_type_3;
assign mem_write = S_type;
assign  ebreak = ( instr == 32'b00000000000100000000000001110011 ) ;
assign ecall  = ( instr == 32'b00000000000000000000000001110011)  ;
assign mret   = ( instr == 32'b00110000001000000000000001110011 ) ;
assign reg_write = !B_type;
assign alu_src1 = R_type | I_type_1 | I_type_3 | I_type_4 | S_type;
assign alu_src2 = R_type;
assign mem_to_reg = (mem_read|mem_write);
assign branch = B_type;
assign alu_op = (R_type) ? 2'b10 :
                (B_type) ? 2'b01 :
                (S_type | U_type | I_type_3 | J_type) ? 2'b00 :
                2'b11;
assign pcsrc = (branch & zero) | jump | ecall | mret;
endmodule



