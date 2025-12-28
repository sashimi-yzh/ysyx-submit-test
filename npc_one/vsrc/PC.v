module PC(
    input clk,
    input rstn,
    input pcsrc,
    input [31:0] imm,
    input [31:0] rs1_data,
    input [31:0] alu_out,
    input zero,
    input jalr,
    input jal,
    input ecall,
    input mret,
    input [31:0] csr_data,
    output reg[31:0] dnpc,
    output [31:0] inst_addr_o
);
reg [31:0] pc;
wire [31:0] d_pc;

assign d_pc = (ecall)? csr_data : (mret) ? csr_data : (jal) ? pc + imm : (jalr) ? rs1_data + imm : (zero) ? alu_out : pc + 4;
always @(pc) begin
    case(pcsrc)
        1'b0: dnpc <= pc + 32'h4;
        1'b1: dnpc <= d_pc;
        default: dnpc <= pc + 32'h4;
    endcase
end

assign inst_addr_o = pc;

always@(posedge clk)
begin 
   if(!rstn)begin
    pc<=32'h80000000 - 32'h4;
    end
    else begin
    pc<=dnpc;
    end
end

endmodule

