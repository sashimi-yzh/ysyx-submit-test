module IDU(
    input [31:0]command,
    output [ 6: 0]opcode,
    output [ 4: 0]rd,
    output [ 4: 0]rs1,
    output [ 4: 0]rs2,
    output [ 2: 0]funct3,
    output [ 6: 0]funct7,
    output [11: 0]immI,
    output [11: 0]immS,
    output [12: 1]immB,
    output [31:12]immU,
    output [20: 1]immJ,
    output reg [31: 0]imm,
/////////////////////////
    output isEBREAK,
    output isADDI,
    output isJALR,
    output isADD,
    output isLUI,
    output isLW,
    output isLBU,
    output isLB,
    output isSW,
    output isSB,

    output isLOAD,
    output isWRITE,
    output isJUMP,
    output isSigned,
    output LSU_WEN,
    output LSU_REN,
    output [9:0]op,
    output [3:0]LSU_rmask,
    output [3:0]LSU_wmask,
    output [5:0]ctype
);
    wire isR,isI,isS,isB,isU,isJ;
    assign ctype={isR,isI,isS,isB,isU,isJ};
    assign opcode=  command[ 6: 0];
    assign rd=      command[11: 7];
    assign rs1=     command[19:15];
    assign rs2=     command[24:20];
    assign funct3=  command[14:12];
    assign funct7=  command[31:25];
    
    assign immI = {command[31:20]                                             };
    assign immS = {command[31:25],command[11: 7]                              };
    assign immB = {command[31:31],command[ 7: 7],command[30:25],command[11: 8]};
    assign immU = {command[31:12]                                             };
    assign immJ = {command[31:31],command[19:12],command[20:20],command[30:21]};

/////////////////////////
    assign isADDI   = (opcode == 7'b0010011 && funct3 == 3'b000                         ) ? 1 : 0;
    assign isJALR   = (opcode == 7'b1100111 && funct3 == 3'b000                         ) ? 1 : 0;
    assign isADD    = (opcode == 7'b0110011 && funct3 == 3'b000 && funct7 == 7'b0000000 ) ? 1 : 0;
    assign isLUI    = (opcode == 7'b0110111                                             ) ? 1 : 0;
    assign isLW     = (opcode == 7'b0000011 && funct3 == 3'b010                         ) ? 1 : 0;
    assign isLBU    = (opcode == 7'b0000011 && funct3 == 3'b100                         ) ? 1 : 0;
    assign isLB     = (opcode == 7'b0000011 && funct3 == 3'b000                         ) ? 1 : 0;
    assign isSW     = (opcode == 7'b0100011 && funct3 == 3'b010                         ) ? 1 : 0;
    assign isSB     = (opcode == 7'b0100011 && funct3 == 3'b000                         ) ? 1 : 0;
    assign isEBREAK = (command==32'b00000000000100000000000001110011                    ) ? 1 : 0;
/////////////////////////
    assign isLOAD = (isLW|isLBU|isLB)?1:0;
    assign isWRITE = (isADDI|isJALR|isADD|isLUI)?1:0;
    assign isJUMP= (isJALR)?1:0;


/////////////////////////
    assign isI=(isADDI|isJALR|isLW|isLBU|isLB)?1:0;
    assign isR=(isADD)?1:0;
    assign isS=(isSW|isSB)?1:0;
    assign isB=(0)?1:0;
    assign isU=(isLUI)?1:0;
    assign isJ=(0)?1:0;

    always @(*) begin
        if     (isI)    imm={{20{immI[11:11]}},immI[11:0]};
        else if(isJ)    imm={{11{immJ[20:20]}},immJ[20:1],1'b0};
        else if(isS)    imm={{20{immS[11:11]}},immS[11:0]};
        else if(isU)    imm={   {immU[31:12]} ,{12{1'b0}}};
        else if(isB)    imm={{19{immB[12:12]}},immB[12:1],1'b0};
        else imm=0;

    end
    //9-add sub mul div LL LR AR AND OR XOR-0
    /////////////////////////
    assign op[9]=(isADDI|isJALR|isADD|isLW|isLBU|isLB|isSW|isSB)?1:0;
    assign op[8]=(0)?1:0;
    assign op[7]=(0)?1:0;
    assign op[6]=(0)?1:0;
    assign op[5]=(0)?1:0;
    assign op[4]=(0)?1:0;
    assign op[3]=(0)?1:0;
    assign op[2]=(0)?1:0;
    assign op[1]=(0)?1:0;
    assign op[0]=(0)?1:0;

    /////////////////////////
    assign LSU_rmask=(isLW)?4'b1111:((isLBU|isLB)?4'b0001:0);
    assign LSU_wmask=(isSW)?4'b1111:((isSB)?4'b0001:0);
    assign LSU_WEN=(isSW|isSB)?1:0;
    assign LSU_REN=(isLB|isLBU|isLW)?1:0;
    /////////////////////////
    assign isSigned=(isLBU)?0:1;
endmodule