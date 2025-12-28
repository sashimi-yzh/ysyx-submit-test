module csr_reg #(
    parameter ADDR_WIDTH = 5,  
    parameter DATA_WIDTH = 32
) (
    input clk,
    input [DATA_WIDTH-1:0] wdata,
    input ecall,
    input [31:0] pc,
    input [ADDR_WIDTH-1:0] waddr,
    input wen,
    
    output [DATA_WIDTH-1:0] rdata1,
    
    input [ADDR_WIDTH-1:0] raddr1
);

    reg [DATA_WIDTH-1:0] csr[3:0];
    import "DPI-C" function void set_csr_ptr(input logic [31:0] a []);
    initial set_csr_ptr(csr); // set the pointer to the CSR array
    initial csr[1] = 'h1800;
    always @(posedge clk) begin
        if (ecall) begin 
            csr[2] <= 'd11; 
            csr[0] <= pc; 
        end // ECALL: set PC and cause to 11 (Environment Call)
        if (wen) csr[waddr] <= wdata; // write to CSR
    end
    
    assign rdata1 = csr[raddr1];

    

endmodule

