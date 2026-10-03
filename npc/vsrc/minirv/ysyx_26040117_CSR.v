module ysyx_26040117_CSR(clk,rst,
    wen,trap_info,csrrs,csr_addr,result,
    rdata,trap_dnpc
);
    localparam CSR_MCYCLE_LO = 3'd0;
    localparam CSR_MCYCLE_HI = 3'd1;
    localparam CSR_MEPC      = 3'd2;
    localparam CSR_MSTATUS   = 3'd3;
    localparam CSR_MCAUSE    = 3'd4;
    localparam CSR_MTVEC     = 3'd5;
    localparam CSR_MVENDORID = 3'd6;
    localparam CSR_MARCHID   = 3'd7;
    input clk,rst;
    input wen;
    input csrrs;
    input [6:0] trap_info;
    input [2:0]csr_addr;
    input [31:0]result;
    output reg[31:0]rdata;
    output [31:0] trap_dnpc;
    //reg[31:0]mcycle_lo,mcycle_hi;
    reg mie,mpie;
    reg[29:0]mepc,mtvec;
    reg[3:0] mcause;
    //read
    assign trap_dnpc=trap_info[2]?{mtvec,2'd0}:{mepc,2'd0};
    always @(*)begin
        case(csr_addr)
            //CSR_MCYCLE_LO:rdata=mcycle_lo;
            //CSR_MCYCLE_HI:rdata=mcycle_hi;
            CSR_MEPC:     rdata={mepc,2'd0};
            CSR_MSTATUS:  rdata={19'd0, 2'b11, 3'd0, mpie, 3'd0, mie, 3'd0};
            CSR_MCAUSE:   rdata={28'd0,mcause};
            CSR_MTVEC:    rdata={mtvec,2'd0};
            CSR_MVENDORID:rdata=32'h79737978;
            CSR_MARCHID:  rdata=32'h18d5735;
            default:rdata=32'h0;
        endcase
    end
    /*
    reg lo_wrap;
    always @(posedge clk) begin
        if(rst)begin
            mcycle_lo<=32'd0;
            mcycle_hi<=32'd0;
            lo_wrap<=1'b0;
        end else begin
            mcycle_lo<=mcycle_lo+32'd1;
            lo_wrap<=(mcycle_lo==32'hfffffffe);
            mcycle_hi<=mcycle_hi+{31'd0,lo_wrap};
            if(wen&&trap_info[0]&&!trap_info[2])begin
                if(csr_addr==CSR_MCYCLE_LO) begin 
                    mcycle_lo<=wdata;
                    lo_wrap<=&wdata;
                end
                else if(csr_addr==CSR_MCYCLE_HI)mcycle_hi<=wdata;
            end
        end
    end
    */
    always @(posedge clk) begin
        if(rst)begin
            mie<=1'b0;
            mpie<=1'b0;
            mcause<=4'h0;
        end else if(wen)begin
            if(trap_info[2])begin//trap entry
                mpie<=mie;
                mie<=1'b0;
                mepc<={result[31:2]};//pc
                mcause<={trap_info[6:3]};
            end if(trap_info[1])begin//trap return meret
                mie<=mpie;
                mpie<=1'b1;
            end else if(trap_info[0])begin
                case(csr_addr)
                    CSR_MEPC:     mepc<=result[31:2]|(mepc&{30{csrrs}});
                    CSR_MSTATUS:  {mpie,mie}<={result[7],result[3]}|({mpie,mie}&{2{csrrs}});
                    CSR_MCAUSE:   mcause<=result[3:0]|(mcause&{4{csrrs}});
                    CSR_MTVEC:    mtvec<=result[31:2]|(mtvec&{30{csrrs}}); 
                    default:;
                endcase
            end
        end
    end
endmodule
