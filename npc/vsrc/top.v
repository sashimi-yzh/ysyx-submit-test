module ysyx_24100012_top (
  input clk,
  input rst,
  output io_halt,
  output ecall
);
  parameter ADDR_WIDTH=32,DATA_WIDTH = 32,N_REG=16,N_CSR=5,CSR_INPUT_INDEXLEN=12,CSR_INDEXLEN=3, REG_INDEX_LEN=4,INPUT_INDEX_LEN=5;
  parameter [ADDR_WIDTH-1:0] MEM_SIZE = 32'h08000000;
  parameter [ADDR_WIDTH-1:0] ORIGIN_ADDR=32'h80000000;

  reg [DATA_WIDTH-1:0] inst,AluOut,DMemLoad,DMemStore;
  reg [ADDR_WIDTH-1:0] pc,PCNext,csrPC;

  wire WEn,ASel,BSel,MemWEn,MemREn,CSRWEn,csrASel,csrBSel;
  wire [1:0] WBSel,PCType,csrType,branchPCSel,PCSel;
  wire [2:0] func3;
  wire [3:0] ALUSel;
  wire [4:0] rs1,rs2,rd;
  wire [DATA_WIDTH-1:0] imm,alu_a,alu_b,aSelOut,bSelOut;
  wire [DATA_WIDTH-1:0] readData1,readData2,writeData;
  wire [DATA_WIDTH-1:0]  csrReadData;
  wire [CSR_INPUT_INDEXLEN-1:0] csr_index;
      
  ysyx_24100012_inst_fetch #(
    ADDR_WIDTH,
    DATA_WIDTH,
    ORIGIN_ADDR) ifu (
      clk,
      rst,
      PCSel,
      AluOut,
      csrPC,
      pc,
      PCNext);
  ysyx_24100012_ram  #(
    ADDR_WIDTH,
    DATA_WIDTH,
    ORIGIN_ADDR,
    MEM_SIZE) IMem (clk,1'b0,1'b1,32'h4,32'h0,32'h0,pc,inst);

  // ysyx_24100012_rom  #(ADDR_WIDTH,DATA_WIDTH) mem (pc,inst);
  ysyx_24100012_inst_decode #(DATA_WIDTH,CSR_INPUT_INDEXLEN)idu (
    clk,
    inst,
    imm,
    func3,
    ALUSel,
    PCType,
    rs1,rs2,rd,
    csr_index,
    ASel,
    BSel,
    csrASel,
    csrBSel,
    WEn,
    CSRWEn,
    MemWEn,
    MemREn,
    WBSel,
    csrType);
  
  ysyx_24100012_regfiles #(
    ADDR_WIDTH,
    DATA_WIDTH,
    N_REG,
    INPUT_INDEX_LEN,
    REG_INDEX_LEN) regfiles (
      clk,rst,
      writeData,
      rd,rs1,rs2,
      WEn,readData1,readData2);
  
  ysyx_24100012_csrfiles #(
      ADDR_WIDTH,
      DATA_WIDTH,
      N_CSR,
      CSR_INPUT_INDEXLEN,
      CSR_INDEXLEN) csrfiles (
      clk,
      rst,
      CSRWEn,
      csrType,
      PCType,
      csr_index,
      AluOut,
      pc,
      csrReadData,
      csrPC
  );

  ysyx_24100012_MuxKey #(2,1,DATA_WIDTH) mulA (
    aSelOut,
    ASel,{ 
      1'b0, readData1,
      1'b1, pc
    }); 

  ysyx_24100012_MuxKey #(2,1,DATA_WIDTH) mulB (
    bSelOut,
    BSel,{ 
      1'b0, readData2,
      1'b1, imm
    }); 
  
  ysyx_24100012_MuxKey #(2,1,DATA_WIDTH) mul_csrA (
    alu_a,
    csrASel,{ 
      1'b0, aSelOut,
      1'b1, csrReadData
    }); 

  ysyx_24100012_MuxKey #(2,1,DATA_WIDTH) mul_csrB (
    alu_b,
    csrBSel,{ 
      1'b0, bSelOut,
      1'b1, csrReadData
    }); 
  
  ysyx_24100012_branch_comp #(ADDR_WIDTH,DATA_WIDTH) branch_comp (
    clk,
    func3,
    PCType,
    readData1,
    readData2,
    branchPCSel
  ) ;


  ysyx_24100012_alu #(DATA_WIDTH,4)alu (
    clk,rst,
    csrType,
    alu_a,
    alu_b,
    ALUSel,AluOut);
  
   ysyx_24100012_partial_load #(ADDR_WIDTH,DATA_WIDTH) partial_load (
    clk,
    rst,
    MemREn,
    func3,
    AluOut,
    DMemLoad
  );
  ysyx_24100012_partial_store #(ADDR_WIDTH,DATA_WIDTH) partial_store (
    clk,
    rst,
    MemWEn,
    func3,
    AluOut,
    readData2
  );

  ysyx_24100012_MuxKeyWithDefault #(
        3,2,2) mul_pc (
        PCSel,
        PCType,
        2'b0,{
        2'b10, branchPCSel,        // B_Type
        2'b01, 2'b01,              // J_Type
        2'b11, 2'b11              // CSR_Type
    });

  ysyx_24100012_MuxKey #(4,2,DATA_WIDTH) mulWB (
    writeData,
    WBSel,{ 
      2'b00, AluOut,
      2'b01, PCNext,
      2'b10, DMemLoad,
      2'b11, csrReadData
    }); 
  // wire [DATA_WIDTH-1:0] a,b;
  // YSYX2400012Mem  #(ADDR_WIDTH,DATA_WIDTH) test (
  //   clk,
  //   32'h80000000,
  //   32'h80000000,
  //   1'b0,
  //   32'h80000000,
  //   32'h80000000,
  //   32'h80000000,
  //   a,b
  // );

  assign io_halt = inst== 32'h00100073;
endmodule



module ysyx_24100012_inst_fetch #(ADDR_WIDTH=32,DATA_WIDTH=32,ORIGIN_ADDR=32'h80000000,WORD_SIZE=4) (
  input clk,
  input rst,
  input [1:0] PCSel,
  input [DATA_WIDTH-1:0] AluOut,
  input [DATA_WIDTH-1:0] CsrPc,
  output [ADDR_WIDTH-1:0] PCOut,
  output [ADDR_WIDTH-1:0] PCNext

);
  wire [ADDR_WIDTH-1:0] PCIn;
  // wire pcWEn = ;
  ysyx_24100012_MuxKey #(3,2,DATA_WIDTH) mulPC (
    PCIn,
    PCSel,{ 
      2'b00, PCNext,       
      2'b01, AluOut,
      2'b11, CsrPc
    }); 
  ysyx_24100012_Reg #(
    ADDR_WIDTH,
    ORIGIN_ADDR) pcReg (
      clk,
      rst,
      PCIn,
      PCOut,
      1'b1
    );

  assign PCNext = PCOut + WORD_SIZE;

endmodule



