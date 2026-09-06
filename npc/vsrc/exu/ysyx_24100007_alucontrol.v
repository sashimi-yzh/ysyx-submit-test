`define   ysyx_24100007_ADD       4'b0001
`define   ysyx_24100007_SUB       4'b0011
`define   ysyx_24100007_SLL       4'b1100
`define   ysyx_24100007_SLT       4'b1001
`define   ysyx_24100007_SLTU      4'b1000
`define   ysyx_24100007_XOR       4'b0110
`define   ysyx_24100007_SRL       4'b1101
`define   ysyx_24100007_SRA       4'b1110
`define   ysyx_24100007_OR        4'b0101
`define   ysyx_24100007_AND       4'b0100

module ysyx_24100007_alucontrol(
  input [2:0] func3,
  input func7,
  input [1:0] aluop,
  input jalrsig,
  input is_csr,
  
  output [4:0] aluopcode
);
  wire type_I, type_B, type_R;
  wire [3:0] branchop;
  reg [3:0] IRop;
  assign type_I = (aluop == 2'b01);
  assign type_B = (aluop == 2'b11);
  assign type_R = (aluop == 2'b10);
  
  assign branchop=(func3[2] & func3[1])? `ysyx_24100007_SLTU : (func3[2] ^ func3[1])? `ysyx_24100007_SLT : `ysyx_24100007_SUB;

  always @(*) begin
    case(func3)
    3'b000: begin
    if(type_R & func7) begin
      IRop = `ysyx_24100007_SUB;
    end else begin
      IRop = `ysyx_24100007_ADD;
    end
    end
    3'b001: IRop=`ysyx_24100007_SLL;
    3'b010: begin
      if(jalrsig)
        IRop = `ysyx_24100007_ADD;
      else
        IRop=`ysyx_24100007_SLT;
    end
		3'b011: IRop=`ysyx_24100007_SLTU;
		3'b100: IRop=`ysyx_24100007_XOR;
		3'b101: begin
    if(func7) begin
			IRop=`ysyx_24100007_SRA;
    end else
			IRop=`ysyx_24100007_SRL;
    end
		3'b110: IRop=`ysyx_24100007_OR;
		3'b111: IRop=`ysyx_24100007_AND;
		default:IRop=`ysyx_24100007_ADD;
    endcase
  end

  wire [4:0] aluopcode_I = {(type_I)? 1'b1:1'b0,(type_B==1)?branchop:(type_R|type_I == 1)?IRop:`ysyx_24100007_ADD};
  wire [4:0] aluopcode_csr = {1'b0, `ysyx_24100007_ADD};
  assign aluopcode = (is_csr) ? aluopcode_csr : aluopcode_I;
endmodule
