`define OPT_LEN 16
`define OPT_HIGH `OPT_LEN - 1

`define EMP   2'b00 
`define EMPTY 3'b000

// reg option
`define WXX 3'b001 
`define WFX 3'b011
`define WFS 3'b111
`define WXS 3'b101
`define XFS 3'b110
`define XFX 3'b010
`define XXS 3'b100

// alu args
`define PC_IM  2'b10
`define RF_RS  2'b01
`define RF_IM  2'b11

// alu option
`define ADD     3'b001
`define AND     3'b010
`define XOR     3'b011
`define LSHIFT  3'b100
`define RSHIFT  3'b101
`define COMPARE 3'b110 // v1 < v2 ret 1
`define EQUAL   3'b111 // v1 == v2 ret 1

// pc option
`define BRANCH  2'b00
`define SNPC    2'b01
`define INPC    2'b10
`define INRF    2'b11 

`define JECALL  2'b01  

// memory option
`define MSB  3'b001
`define MSH  3'b010
`define MSW  3'b011
`define MLB  3'b101
`define MLH  3'b110
`define MLW  3'b111
`define RDPC 3'b100 // SNPC TO RD 

// extern option
`define EXX  3'b001 // (sub | or) 
`define XSX  3'b010 // sign
`define ESX  3'b011 // (sub | or) & sign 
`define EXN  3'b101
`define ESN  3'b111
`define XXN  3'b100


// opt greantor
`define OPTG(reg_opt, alu_arg, alu_opt, pc_ctl, mem_ctl, ext_opt) \
    {ext_opt, mem_ctl, pc_ctl, alu_opt, alu_arg, reg_opt}

`define INVALID_INST `OPT_LEN'b0

`define EBREAK_INST  `OPT_LEN'h8002


// csr index
`define MSTATUS	12'h300
`define MTVEC	12'h305
`define MEPC	12'h341
`define MCAUSE	12'h342

`ifdef YOSYS_STA
`define STA_SOC 
`endif

`ifdef RUNSOC
`define STA_SOC
`endif

`ifdef STA_SOC
`define DEV_CLINT       (32'h02000048)
`define DEV_CLINT_END   (32'h0200004f)    
`else
`define DEV_CLINT       (32'ha0000048)
`define DEV_CLINT_END   (32'ha000004f)
`endif // RUNSOC


// OPT [15:0]
//      [0]: reg wirte en (write to rd)
//      [2:1]: reg read en [rs2, rs1]
//      [4:3]: alu arguments
//              00  empty
//              01  pc, imm (alu-eopt == 100 ? imm = 4 : imm)
//              10  rs1, rs2
//              11  rs1, imm
//      [7:5]: alu option
//              000 empty
//              001 add [13] sub
//              010 and [13] or
//              011 xor
//              100 lshift
//              101 rshift
//              110 compare
//              111 equal
//      [9:8]: pc update option              
//              00 empty                        
//              01 pc + 4                       
//              10 pc + imm                     
//              11 rs1 + imm                   
//      [12:10] memory control option       SYSTEM
//              000 empty                       [10] csr write en
//              001 sb                          [11] csr read en
//              010 sh                          [12] jump
//              011 sw
//              101 lb
//              110 lh
//              111 lw
//              100 opt[0] ? pc + 4 [alu-opt] : fence
//      [13]    [add:sub] | [and:or]
//      [14]    signed enable
//      [15]    [system opt] | [cmp-eq !res]
