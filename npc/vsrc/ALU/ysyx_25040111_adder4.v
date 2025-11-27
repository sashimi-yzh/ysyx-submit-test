module ysyx_25040111_adder4(
    input [3:0] ina,
    input [3:0] inb,
    input cin,
    output cout,
    output [3:0] sout
);

    wire [3:0] p, g;
    wire [4:0] c;

    assign p = ina ^ inb;
    assign g = ina & inb;
    assign c[0] = cin;

    ysyx_25040111_carry u_carry(
        .p    	(p),
        .g    	(g),
        .cin    (cin),
        .cout 	(c[4:1])
    );

    // 进位与结果
    assign cout = c[4];
    assign sout = p ^ c[3:0];

endmodule
