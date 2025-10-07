module ysyx_24070003_csr_reg #(
    parameter ADDR_WIDTH = 5,  
    parameter DATA_WIDTH = 32
) (
    input clock,
    input [DATA_WIDTH-1:0] wdata,
    input ecall,
    input [31:0] pc,
    input [ADDR_WIDTH-1:0] waddr,
    input wen,
    
    output [DATA_WIDTH-1:0] rdata1,
    
    input [ADDR_WIDTH-1:0] raddr1
);

    //reg [DATA_WIDTH-1:0] csr[5:0];
    reg [DATA_WIDTH-1:0] csr[3:0];
    
    // initial begin
    //     csr[4] = 32'h79737978; // zero register
    //     csr[5] = 32'h016e38bf; // zero register
    // end
    //  import "DPI-C" function void set_csr_ptr(input logic [31:0] a []);
    //  initial set_csr_ptr(csr); // set the pointer to the CSR array
    initial csr[1] = 'h1800;
    always @(posedge clock) begin
        if (ecall) begin 
            csr[2] <= 'd11; 
            csr[0] <= pc; 
        end // ECALL: set PC and cause to 11 (Environment Call)
        if (wen) csr[waddr[1:0]] <= wdata; // write to CSR
    end
    
    assign rdata1 = (raddr1 == 'd4) ? 32'h79737978 : (raddr1 == 'd5) ? 32'h016e38bf : csr[raddr1[1:0]];

    

endmodule
