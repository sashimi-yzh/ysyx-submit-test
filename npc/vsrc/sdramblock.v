module sdramblock(
    input wire clock,
    input wire [1:0] bank,
    input wire [12:0] row,
    input wire [8:0] col,
    input wire [1:0] block_num,
    input wire we,
    input wire [15:0] wdata,
    input wire [1:0] dqm,
    output reg [15:0] rdata
);

   import "DPI-C" function int sdram_read(input byte bank, input int row, input int col,
                                                input byte block_num);
   import "DPI-C" function void sdram_write(input byte bank, input int row, input int col,
                                            input int wdata, input byte wmask, input byte block_num);
    always @(posedge clock) begin
           if(we) begin
                sdram_write({6'b0,bank}, {19'b0,row}, {23'b0,col}, {16'b0,wdata}, {6'b0,~dqm}, {6'b0,block_num});
          end
    end
    always @(posedge clock) begin
`ifdef VERILATOR
           rdata <= sdram_read({6'b0,bank}, {19'b0,row}, {23'b0,col}, {6'b0,block_num})[15:0];
`else
           rdata <= sdram_read({6'b0,bank}, {19'b0,row}, {23'b0,col}, {6'b0,block_num});
`endif 
    end
endmodule
