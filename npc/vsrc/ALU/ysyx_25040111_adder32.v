`ifndef NPC_ADDER32
`define NPC_ADDER32

module ysyx_25040111_adder32 (
    input [31:0] ina,
    input [31:0] inb,
    input sub,
    output [31:0] sout,
    output overflow,
    output cout
);

    // wire [7:0] cin;
    // wire [31:0] inbt;
    // assign inbt = sub ? ~inb : inb;
    
    // generate
    //     genvar i;
    //     for (i = 0; i < 8; i++) begin
    //         wire gcin = i == 0 ? sub : cin[i - 1];
    //         ysyx_25040111_adder4 u_ysyx_25040111_adder4(
    //             .ina  	(ina[(4 * i + 3):(4 * i)]),
    //             .inb  	(inbt[(4 * i + 3):(4 * i)]),
    //             .cin  	(gcin),
    //             .cout 	(cin[i]),
    //             .sout 	(sout[(4 * i + 3):(4 * i)])
    //         );
    //     end
    // endgenerate

    // // 无符号数进位
    // assign cout = cin[7];
    // // 有符号溢出：两个操作数符号相同，结果符号不同
    // assign overflow = (~(ina[31] ^ inbt[31])) & (ina[31] ^ sout[31]);

    wire [31:0] inbt;
    assign inbt = sub ? ~inb : inb;
    
    // 无符号数进位
    assign {cout, sout} = ina + inbt + {31'b0, sub};
    // 有符号溢出：两个操作数符号相同，结果符号不同
    assign overflow = (~(ina[31] ^ inbt[31])) & (ina[31] ^ sout[31]);

endmodule

`endif
