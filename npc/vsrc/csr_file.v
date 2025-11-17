module ysyx_24100012_csrfiles #(
    ADDR_WIDTH=32,
    DATA_WIDTH=32,
    N_REG=5,
    INPUT_INDEX_LEN=12,
    INDEX_LEN=3)(
    input clk,
    input rst,
    input RegWEn,
    input [1:0] csrType,          // 00 csrrw, 01 ecall, 10 mret
    input [1:0] PCType,
    input [INPUT_INDEX_LEN-1:0] RegIndex,
    input [DATA_WIDTH-1:0] RegWriteData,
    input [ADDR_WIDTH-1:0] pc,
    output [DATA_WIDTH-1:0] RegReadData,
    output [ADDR_WIDTH-1:0] csrPC
);

    parameter [INDEX_LEN-1:0] STAP=3'h0,MSTATUS=3'h1,MTVEC=3'h2,MEPC=3'h3,MCAUSE=3'h4;
    parameter [1:0] ECALL=2'b01, MRET=2'b10, CSRRW=2'b00;

    wire [DATA_WIDTH-1:0] reg_input_list[N_REG-1:0];
    wire [DATA_WIDTH-1:0] reg_output_list[N_REG-1:0];
    wire  WEn_list[N_REG-1:0];
    wire [INDEX_LEN-1:0] readIdx,writeIdx;

    genvar i;
    generate
        for (i=0;i<N_REG;i=i+1) begin: csr
        ysyx_24100012_Reg #(DATA_WIDTH,0) csr (clk,rst,
            reg_input_list[i],
            reg_output_list[i],
            WEn_list[i]);
        end
    endgenerate

    ysyx_24100012_MuxKey  #(N_REG,INPUT_INDEX_LEN,INDEX_LEN) mul_readindex (
        readIdx,
        RegIndex,{
           12'h180, STAP,
           12'h300, MSTATUS,
           12'h305, MTVEC, 
           12'h341, MEPC,
           12'h342, MCAUSE
        }
    );

    ysyx_24100012_MuxKey  #(N_REG,INPUT_INDEX_LEN,INDEX_LEN) mul_writeindex (
        writeIdx,
        RegIndex,{
           12'h180, STAP,
           12'h300, MSTATUS,
           12'h305, MTVEC, 
           12'h341, MEPC,
           12'h342, MCAUSE
        }
    );

    ysyx_24100012_MuxKeyWithDefault  #(2,2,ADDR_WIDTH) mul_pc (
        csrPC,
        csrType,
        32'h0,{
            ECALL, reg_output_list[MTVEC],
            MRET, reg_output_list[MEPC]
        }
    );
    // ecall procedure
    ysyx_24100012_MuxKeyWithDefault  #(2,2,ADDR_WIDTH) mul_mepc(
        reg_input_list[MEPC],
        csrType,
        32'h0,{
            ECALL, pc,
            CSRRW, writeIdx==MEPC?RegWriteData:reg_output_list[MEPC]
        }
    );

    ysyx_24100012_MuxKeyWithDefault  #(2,2,ADDR_WIDTH) mul_mcause(
        reg_input_list[MCAUSE],
        csrType,
        32'h0,{
            ECALL, 32'hb,
            CSRRW, writeIdx==MCAUSE?RegWriteData:reg_output_list[MCAUSE]
        }
    );

    ysyx_24100012_MuxKeyWithDefault  #(2,2,1) mul_mepcWEn(
        WEn_list[MEPC],
        csrType,
        1'h0,{
            ECALL, 1'b1,
            CSRRW, writeIdx==MEPC? 1'b1: 1'b0
        }
    );

    ysyx_24100012_MuxKeyWithDefault  #(2,2,1) mul_mcauseWEn(
        WEn_list[MCAUSE],
        csrType,
        1'h0,{
            ECALL, 1'b1,
            CSRRW, writeIdx==MCAUSE? 1'b1: 1'b0

        }
    );
    // end of ecall procedure

    assign WEn_list[writeIdx] = RegWEn;
    assign reg_input_list[writeIdx] = RegWriteData;
    assign RegReadData = reg_output_list[readIdx];
    // always@(*)
    //     if (pc==32'h800013a0||pc==32'h800013a4||pc==32'h8000139c)
    //         $display("csr csrType: %x, write: %x, WEn_list[writeIdx]: %b, writeIdx: %x", csrType, reg_output_list[MEPC], WEn_list[writeIdx], writeIdx);

endmodule