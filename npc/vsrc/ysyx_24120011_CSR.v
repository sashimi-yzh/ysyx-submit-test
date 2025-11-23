
module ysyx_24120011_CSR(
    input clk,
    input rst,
    //读口
    input  [11:0]  i_r_csr_addr,
    output [31:0]  o_r_csr_data,
    //写口
    input  [11:0]  i_w_csr_addr,
    input  [31:0]  i_w_csr_data,
    input          i_w_csr_en,
    input          i_w_csr_ecall
);

reg [31:0] mepc;
reg [31:0] mstatus;
reg [31:0] mcause;
reg [31:0] mtvec; 

wire [31:0] mvendorid;
wire [31:0] marchid;
assign mvendorid = 32'h7973_7978;
assign marchid = 32'h0170_0ACB;

reg [31:0] r_csr_data;
assign o_r_csr_data = r_csr_data;

always@(*)begin
    case(i_r_csr_addr)
        12'h341: r_csr_data = mepc;
        12'h300: r_csr_data = mstatus;
        12'h342: r_csr_data = mcause;
        12'h305: r_csr_data = mtvec;
        12'hf11: r_csr_data = mvendorid;
        12'hf12: r_csr_data = marchid;
        default: begin
            r_csr_data   =  32'b0;
        end
    endcase
end

always@(posedge clk)begin
    // if(rst)begin
    //     mepc         <= 32'h0000_0000;
    //     mstatus      <= 32'h0000_0000;
    //     mcause       <= 32'h0000_0000;
    //     mtvec        <= 32'h0000_0000;
    // end
    //else begin
        if(i_w_csr_en)begin
            case(i_w_csr_addr)
                12'h341: mepc     <= i_w_csr_data;
                12'h300: mstatus  <= i_w_csr_data;
                12'h342: mcause   <= i_w_csr_data;
                12'h305: mtvec    <= i_w_csr_data;
                default: begin
                    mepc      <=  mepc;     
                    mstatus   <=  mstatus;  
                    mcause    <=  mcause;   
                    mtvec     <=  mtvec;  
                end
            endcase
        end
        if(i_w_csr_ecall)begin 
            mcause       <=  32'h000b;//11 
        end
    //end
end
endmodule