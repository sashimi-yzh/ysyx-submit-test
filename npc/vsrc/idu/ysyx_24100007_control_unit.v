`ifdef VERILATOR
// synopsys translate_off
import "DPI-C" function void ret(int pc);
// synopsys translate_on
`endif
module ysyx_24100007_control_unit(
  input [6:0] opcode,
  input [2:0] func3,
  input func7,

  input ebreaksig,
  input ecallsig,
  input mretsig,
  input [5:0] inst_type,
  output memew,
  output [2:0] muxsig,
  output memer,
  output regew,
  output muximm,
  output btypebranch,
  output jalrsig,
  output jalsig,
  output [1:0] aluop,
  output auipcsig,
  output csrrw,
  output csrrs,
  output [2:0] memmask,
  output memsextsig
);
  wire type_I, type_R, type_U, type_S, type_J, type_B;
  assign {type_I, type_B, type_J, type_S, type_R, type_U} = inst_type;
  
  wire load, store;
  wire regwritepc, regwritemem, luisig;

  assign load = (opcode == 7'b0000011);
  assign store = (opcode == 7'b0100011);

  assign btypebranch = type_B;
  assign memew = store;
  assign memer = load;
  assign regew = (type_I | type_R | type_J | type_U);
  assign jalsig = type_J;
  assign jalrsig = (opcode == 7'b1100111);
  assign muximm = (load | store | type_I | jalrsig) & !(csrrs | csrrw);
  assign regwritemem = load;
  assign regwritepc = jalrsig | jalsig | auipcsig | ecallsig;
  assign auipcsig = (opcode == 7'b0010111);
  assign luisig = (opcode == 7'b0110111);

  assign aluop[1] = type_R | type_B;
  assign aluop[0] = (type_I | type_B) & ~load;

  assign muxsig = {regwritepc, luisig, regwritemem};

  assign csrrs = (opcode == 7'b1110011) & (func3 == 3'b010);
  assign csrrw = (opcode == 7'b1110011) & (func3 == 3'b001);

  assign memmask = (func3 == 3'b000) ? 3'b001 :
               (func3 == 3'b001) ? 3'b010 :
               (func3 == 3'b010) ? 3'b100 :
               (func3 == 3'b100) ? 3'b001 :
               (func3 == 3'b101) ? 3'b010 :
               3'b000;

  assign memsextsig = (func3 == 3'b100) ? 1'b0 :
                      (func3 == 3'b101) ? 1'b0 :
                      1'b1;
  
  // synopsys translate_off
  `ifdef VERILATOR
  always @(*) begin
    if(ebreaksig)
      ret(0);
  end
  `endif
  
  // `ifdef __ICARUS__
  // always @(*) begin
  //   if(ebreak)
  //     $finish;
  // end
  // `endif
  // synopsys translate_on
endmodule


