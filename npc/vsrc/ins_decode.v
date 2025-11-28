module ysyx_24100012_inst_decode #(DATA_WIDTH=32,CSR_INDEXLEN=12) (
    input clk,
    input [DATA_WIDTH-1:0] instruction,
    output reg [DATA_WIDTH-1:0]  imm ,
    output reg [2:0]                func3,
    output reg [3:0]                ALUSel,
    output reg [1:0]                PCType,
    output reg [4:0]                rs1,
    output reg [4:0]                rs2,
    output reg [4:0]                rd,
    output reg [CSR_INDEXLEN-1:0]   csr_index,
    output reg                      ASel,
    output reg                      BSel,
    output reg                      csrAsel,
    output reg                      csrBSel,
    output reg                      WEn,
    output reg                      CSRWEn,
    output reg                      MemWEn,
    output reg                      MemREn,
    output reg [1:0]                WBSel,
    output reg [1:0]                csrType
);
    parameter [1:0] WBALU=2'b00, WBPc=2'b01,WBLoad=2'b10,WBNone=2'b11;
    parameter [1:0] PCNext=2'b00,PCTypeJ=2'b01, PCTypeB=2'b10,PCTypeCSR=2'b11;
    parameter [1:0]  CSRNormal=2'b00, ECALL=2'b01, MRET=2'b10, NoCSR=2'b11;
    wire csrWB;
    wire [1:0] csrTypeNoOpcode,csrPC;
    wire [6:0] opcode; 
    wire [7:0] sels,csr_sels; 
    wire [3:0] ALUSel_I;
    wire [DATA_WIDTH-1:0] imm_S,imm_I,imm_Is,imm_B,imm_J,imm_U,imm_Z,imm_I_temp;
    assign opcode = instruction[6:0];
    assign func3  = instruction[14:12];
    assign imm_S = { {21{instruction[31]}},instruction[30:25],instruction[11:7]};
    assign imm_I = { {21{instruction[31]}}, instruction[30:20]};
    assign imm_Is = {27'b0,instruction[24:20]};
    assign imm_B = { {20{instruction[31]}},instruction[7],instruction[30:25],instruction[11:8],1'b0};
    assign imm_J = { {12{instruction[31]}},instruction[19:12],instruction[20],instruction[30:21],1'b0};
    assign imm_U =  { instruction[31:12],12'b0};
    assign imm_Z =  { 27'b0,instruction[19:15]};            // csr(rw)i
    assign csr_index = instruction[31:20];

    ysyx_24100012_MuxKey #(1,7) mul_MemREn  (
        MemREn,
        opcode,{
            7'b0000011,1'b1
        }); 
    ysyx_24100012_MuxKey #(1,7) mul_MemWEn (
        MemWEn,
        opcode,{
            7'b0100011,1'b1
        }); 
    
    ysyx_24100012_MuxKeyWithDefault #(2,32,2) mul_CSRType (
        csrTypeNoOpcode,
        instruction,
        CSRNormal,{
            32'h00000073, ECALL,
            32'h30200073, MRET
        }); 
    ysyx_24100012_MuxKeyWithDefault #(1,7,2) mul_isPriv (
        csrType,
        opcode,
        NoCSR,{
            7'b1110011,csrTypeNoOpcode
        }); 
    
    ysyx_24100012_MuxKeyWithDefault #(2,2,2) mul_csrPC(
        csrPC,
        csrTypeNoOpcode,
        PCNext,{
            ECALL,PCTypeCSR,
            MRET, PCTypeCSR
        });
    
    ysyx_24100012_MuxKeyWithDefault #(4,7,2) mul_PCType (
        PCType,
        opcode,
        PCNext,{
            7'b1101111,PCTypeJ,
            7'b1100111,PCTypeJ,
            7'b1100011,PCTypeB,
            7'b1110011,csrPC
        }); 


    ysyx_24100012_MuxKeyWithDefault #(2,3,4) mul_ALUSel_I (
        ALUSel_I,
        func3,
        {1'b0, func3},{
            3'b101,{instruction[30], func3},
            3'b001,{instruction[30], func3}
        }); 
    ysyx_24100012_MuxKeyWithDefault #(3,7,4) mul_ALUSel (
        ALUSel,
        opcode,
        4'h0,{
            7'b0110011,     {instruction[30], func3},
            7'b0010011,     ALUSel_I,
            7'b1110011,     {1'b0,func3}
        }); 
    ysyx_24100012_MuxKeyWithDefault #(2,3,32) mul_immI (
        imm_I_temp,
        func3,
        imm_I,{
            3'b101,imm_Is,
            3'b001,imm_Is
        }); 
    
    ysyx_24100012_MuxKeyWithDefault #(9,7,8) mul_nopriv_sels (
        sels,
        opcode,
        8'h0,{
            7'b0110011, 8'b01000000,                 // R Type
            7'b0010011, 8'b01000100,                 // I type
            7'b1100011, 8'b00001100,                 // B type
            7'b0000011, 8'b01000110,                 // L type
            7'b0100011, 8'b00000100,                 // S type
            7'b1101111, 8'b01001101,                 // jal 
            7'b1100111, 8'b01000101,                 // jalr
            7'b0010111, 8'b01001100,                 // auipc
            7'b0110111, 8'b01000100                 // lui
        });

    // csrASel 1 chose csr,else chose asel_out, csrBsel 1 chose csr else chose bsel_out
    ysyx_24100012_MuxKeyWithDefault #(6,3,8) mul_csrSel (
        csr_sels,
        func3,
        8'b00000111,{
            3'b001,8'b11010011,             
            3'b010,8'b11010011,             
            3'b011,8'b11010011,
            3'b101,8'b11100111,
            3'b110,8'b11100111,
            3'b111,8'b11100111
        });
    ysyx_24100012_MuxKeyWithDefault #(2,2,8) mul_sel (
        {CSRWEn, WEn,csrAsel,csrBSel,ASel,BSel,WBSel},
        csrType,
        8'b00000111,{
            NoCSR,sels,
            CSRNormal,csr_sels             
        });
    ysyx_24100012_MuxKeyWithDefault #(10,7,15) mul_rs (
        {rs2,rs1,rd},
        opcode,
        15'h0,{
            7'b0110011, {instruction[24:20],instruction[19:15],instruction[11:7]},  // R Type
            7'b0010011, {5'b0,instruction[19:15],instruction[11:7]},                // I type
            7'b1100011, {instruction[24:20],instruction[19:15],instruction[11:7]},  // B type
            7'b0100011, {instruction[24:20],instruction[19:15],instruction[11:7]},  // S type
            7'b0000011, {5'b0,instruction[19:15],instruction[11:7]},                // L type
            7'b1101111, {5'b0,5'b0,instruction[11:7]},                              // jal 
            7'b1100111, {5'b0,instruction[19:15],instruction[11:7]},                // jalr
            7'b0010111, {5'b0,5'b0,instruction[11:7]},                              // auipc
            7'b0110111, {5'b0,5'b0,instruction[11:7]},                              // lui
            7'b1110011, {5'b0,instruction[19:15],instruction[11:7]}                 // ebreak, ecall
        });  
    ysyx_24100012_MuxKeyWithDefault #(10,7,32) mul_imm (
        imm,
        opcode,
        32'h0,{
            7'b0110011, 32'b0,                 // R Type
            7'b0010011, imm_I_temp,            // I type
            7'b1100011, imm_B,                 // B type
            7'b0000011, imm_I,                 // L type
            7'b0100011, imm_S,                 // S type
            7'b1101111, imm_J,                 // jal 
            7'b1100111, imm_I,                 // jalr
            7'b0010111, imm_U,                 // auipc
            7'b0110111, imm_U,                 // lui
            7'b1110011, imm_Z                  // csr(rw)i
        }); 
endmodule // ysyx_24100012_inst_decode_mul_only
