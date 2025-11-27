module ysyx_25040111_carry(
    input [3:0] p, 
    input [3:0] g,
    input cin,
    output [4:1] cout
);

    assign cout[1] = g[0] | (p[0] & cin);
    assign cout[2] = g[1] | (p[1] & g[0]) | (&p[1:0] & cin);
    assign cout[3] = g[2] | (p[2] & g[1]) | (&p[2:1] & g[0]) | (&p[2:0] & cin);
    assign cout[4] = g[3] | (p[3] & g[2]) | (&p[3:2] & g[1]) | (&p[3:1] & g[0]) | (&p[3:0] & cin);

endmodule
