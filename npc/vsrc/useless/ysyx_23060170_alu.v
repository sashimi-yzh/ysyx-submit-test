module ysyx_23060170_alu (
    input   [31:0]             operand1 ,
    input   [31:0]             operand2 ,
    input   [9:0]              op ,
    input   [2:0]              br_code ,
    output  [31:0]             out ,
    output                     br_taken 
);

// wire
wire             op_add ;
wire             op_sub ;
wire             op_sll ;
wire             op_slt ;
wire             op_sltu ;
wire             op_xor ;
wire             op_srl ;
wire             op_sra ;
wire             op_or ;
wire             op_and ;
wire  [31:0]     adder_src1 ;
wire  [31:0]     adder_src2 ;
wire  [31:0]     adder_cin ;
wire             adder_cout ;
wire  [31:0]     adder_res ;
wire  [31:0]     add_sub_res ;
wire  [31:0]     shift_res ;
wire  [31:0]     slt_res ;
wire  [31:0]     sltu_res ;
wire  [31:0]     xor_res ;
wire  [31:0]     or_res ;
wire  [31:0]     and_res ;

assign op_add  = op[0];
assign op_sub  = op[1];
assign op_sll  = op[2];
assign op_slt  = op[3];
assign op_sltu = op[4];
assign op_xor  = op[5];
assign op_srl  = op[6];
assign op_sra  = op[7];
assign op_or   = op[8];
assign op_and  = op[9];

//-----------------------------------------------------------------
// Result
//-----------------------------------------------------------------
// adder
assign adder_src1               = operand1;
assign adder_src2               = (op_sub | op_slt | op_sltu)
                                    ? ~operand2 : operand2;
assign adder_cin[31:1]          = 31'h0;
assign adder_cin[0]             = (op_sub | op_slt | op_sltu) ? 1'b1 : 1'b0;
assign {adder_cout, adder_res}  = adder_src1 + adder_src2 + adder_cin;
// result
assign add_sub_res              = adder_res;
assign shift_res                = op_sll ? (operand1 << operand2[4:0]) :
                                  op_srl ? (operand1 >> operand2[4:0]) :
                                  op_sra ? $unsigned($signed(operand1) >>> operand2[4:0]) : 32'h0;
assign slt_res[31:1]            = 31'h0;
assign slt_res[0]               = (operand1[31] && ~operand2[31]) |
                                 (~(operand1[31] ^ operand2[31]) && adder_res[31]);
assign sltu_res[31:1]           = 31'b0;
assign sltu_res[0]              = ~(adder_cout);
assign xor_res                  = operand1 ^ operand2;
assign or_res                   = operand1 | operand2;
assign and_res                  = operand1 & operand2;

//-----------------------------------------------------------------
// ALU
//-----------------------------------------------------------------
assign out = ( {32{op_add | op_sub         }} & add_sub_res )
           | ( {32{op_sll | op_srl | op_sra}} & shift_res   )
           | ( {32{op_slt                  }} & slt_res     )
           | ( {32{op_sltu                 }} & sltu_res    )
           | ( {32{op_xor                  }} & xor_res     )
           | ( {32{op_or                   }} & or_res      )
           | ( {32{op_and                  }} & and_res     );

//-----------------------------------------------------------------
// Branch
//-----------------------------------------------------------------
assign br_taken =  br_code == 3'b000 && ~|add_sub_res
                || br_code == 3'b001 && |add_sub_res
                || br_code == 3'b100 && slt_res[0]
                || br_code == 3'b101 && ~slt_res[0]
                || br_code == 3'b110 && ~adder_cout
                || br_code == 3'b111 && adder_cout;


endmodule
