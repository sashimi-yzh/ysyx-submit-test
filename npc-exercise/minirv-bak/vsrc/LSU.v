

module LSU(
    input [31:0]address,
    output reg [31:0]rdata,

    input [31:0]wdata,
    input [3:0]rmask,
    input [3:0]wmask,
    input isSigned,
    input clk,
    input writeEN,
    input readEN
);

    wire [31:0]val0,val1,val2,val3,rdata1,rdata2,rdata4;
    reg [31:0]val;
    // reg [31:0]pmem;
    // always @(posedge clk)begin
    //     pmem <= (readEN)?pmem_read(address):32'b0;
    // end
    // assign val0=pmem;
    assign val0=(readEN)?pmem_read(address):32'b0;
    assign val1={{8{val0[31]}},val0[31:8]};
    assign val2={{8{val1[31]}},val1[31:8]};
    assign val3={{8{val2[31]}},val2[31:8]};
    always @(*) begin
        case(address[1:0])
            2'b00:val=val0;
            2'b01:val=val1;
            2'b10:val=val2;
            2'b11:val=val3;
        endcase
    end
    
    assign rdata1=(isSigned)?{{24{val[7:7]}},val[7:0]}:{{24{1'b0}},val[7:0]};
    assign rdata2=(isSigned)?{{16{val[15:15]}},val[15:0]}:{{16{1'b0}},val[15:0]};
    assign rdata4=val[31:0];
    
    always @(*) begin
        case(rmask)
            4'b0001:rdata=rdata1;
            4'b0011:rdata=rdata2;
            4'b0111:rdata=32'hffffffff;
            4'b1111:rdata=rdata4;
            default:rdata=32'hffffffff;
        endcase
    end

    wire [31:0]wdata0,wdata1,wdata2,wdata3;
    reg [31:0] w;
    assign wdata0=wdata;
    assign wdata1={wdata[23:0],{8{1'b0}}};
    assign wdata2={wdata[15:0],{16{1'b0}}};
    assign wdata3={wdata[ 7:0],{24{1'b0}}};
    always @(*) begin
        case(address[1:0])
            2'b00:w=wdata0;
            2'b01:w=wdata1;
            2'b10:w=wdata2;
            2'b11:w=wdata3;
        endcase
    end
    always @(posedge clk) begin
        if(writeEN)begin
            pmem_write(address,w,{4'h0,wmask});
        end
    end
    // assign LSU_address=address;
    // assign data=LSU_data;
    // assign LSU_PC_address=PC_address;
    // assign PC_data=LSU_PC_data;

endmodule