module ysyx_26040117_EXU(clk,rst,
    IDU_EXU_ready,IDU_EXU_valid,IDU_wrapper,
    EXU_LSU_ready,EXU_LSU_valid,exu_redirect_pc,EXU_wrapper,
    redirect_valid,EXU_IDU_wrapper,
    exu_btb_wen,exu_btb_waddr,exu_btb_wtarget
);
    input clk,rst;
    //IDU-EXU
    input IDU_EXU_valid;
    output IDU_EXU_ready;
    input [158:0]IDU_wrapper;
    //EXU-LSU
    input EXU_LSU_ready;
    output EXU_LSU_valid;
    output [31:0] exu_redirect_pc;
    output [84:0] EXU_wrapper;
    
    //FIFO
    reg[158:0] IDU_wrapper_reg;
    wire [8:0]mytype;
    wire [3:0]funct;
    wire [31:0] num1,num2,aux_num1,aux_num2,aux0;
    wire [31:0]aux/* verilator public_flat_rd */;
    wire sub,type_fence_i,register_wen_ok,register_wen_load,register_wen,pred_taken;
    wire[6:0] trap_info;
    wire [4:0] rd;
    reg [31:0]result;
    wire IDU_EXU_fire,EXU_LSU_fire/* verilator public_flat_rd */;
    always @(posedge clk) begin
        if(IDU_EXU_fire)begin
            IDU_wrapper_reg<=IDU_wrapper;
        end
    end
    assign {pred_taken,register_wen_load,register_wen_ok,register_wen,type_fence_i,trap_info,rd,funct,mytype,num1,num2,aux_num1,aux_num2,sub}=IDU_wrapper_reg;

    assign EXU_wrapper={register_wen_load,register_wen_ok,register_wen,type_fence_i,trap_info,rd,result,aux_num2,mytype[6:5],funct[2:0]};
    //EXU-IFU/IDU
    output redirect_valid;
    output[38:0] EXU_IDU_wrapper;
    assign EXU_IDU_wrapper={result,EXU_LSU_valid&&register_wen,EXU_LSU_valid&&register_wen_ok,rd};
    //EXU-BTB
    output exu_btb_wen;
    output [31:0] exu_btb_waddr,exu_btb_wtarget;
    assign exu_btb_waddr=aux_num1;
    assign exu_btb_wtarget=aux;
    assign exu_btb_wen=EXU_LSU_fire&&(mytype[2]||(mytype[4]&&aux_num2[31]));
    //state machine
    reg state;
    localparam IDLE=0,WAIT=1;
    always @(posedge clk) begin
        if(rst||redirect_valid)
            state<=IDLE;
        else if(IDU_EXU_fire)
            state<=WAIT;
        else if(EXU_LSU_fire)
            state<=IDLE;
    end
    assign IDU_EXU_ready=(state==IDLE)||EXU_LSU_fire;
    assign EXU_LSU_valid=state==WAIT;
    assign IDU_EXU_fire=IDU_EXU_ready&&IDU_EXU_valid;
    assign EXU_LSU_fire=EXU_LSU_ready&&EXU_LSU_valid;
    //result function
    wire carry,sless,less;
    wire[31:0] t_no_cin,result0;
    assign t_no_cin={32{sub}}^num2;
    assign {carry,result0}={1'b0,num1}+{1'b0,t_no_cin}+{32'd0,sub};//adder
    assign sless=(num1[31]^num2[31])?num1[31]:result0[31];
    assign less=~carry;
    //sll,sra,srl
    wire[31:0] num1_rev,shift_rev;
    wire signed [32:0] shift_src={funct[3]&funct[2]&num1[31],funct[2]?num1:num1_rev};
    wire [31:0] shift_16=num2[4]?{{16{shift_src[32]}},shift_src[31:16]}:shift_src[31:0];
    wire [31:0] shift_8 =num2[3]?{{8{shift_src[32]}},shift_16[31:8]}:shift_16;
    wire [31:0] shift_4 =num2[2]?{{4{shift_src[32]}},shift_8[31:4]}:shift_8;
    wire [31:0] shift_2 =num2[1]?{{2{shift_src[32]}},shift_4[31:2]}:shift_4;
    wire [31:0] shift_tmp =num2[0]?{{1{shift_src[32]}},shift_2[31:1]}:shift_2;
    //wire [32:0] shift_tmp=$signed(shift_src)>>>num2[4:0];
    genvar i;
    generate 
        for(i=0;i<32;i++)begin:shift_reverse
            assign num1_rev[i]=num1[31-i];
            assign shift_rev[i]=shift_tmp[31-i];
        end
    endgenerate

    //and-or-xor
    wire [31:0] num_and,num_or;
    assign num_and=num1&num2;
    assign num_or=num1|num2;
    wire [31:0] num_logic=((num_or &{32{!funct[0]}})|(num_and&{32{ funct[0]}}))& //xor:or,or:or,and:and
                            (~num_and|{32{funct[1]}});//xor:~and,or:1,and:1
    //assign num_xor=num_or&(~num_and);
    always @(*) begin
        result=result0;//load,store,jal,jalr
        if(mytype[8]||mytype[7])begin
            case(funct[2:0])
                3'b000:result=result0;//ADDI,ADD
                3'b010:result={31'd0,sless};//SLTI,SLT
                3'b011:result={31'd0,less};//SLTIU,SLTU
                3'b100,//XORI,XOR
                3'b110,//ORI,OR
                3'b111:result=num_logic;//ANDI,AND
                3'b001:result=shift_rev;//SLLI,SLL
                3'b101:result=shift_tmp[31:0];//1:SRAI,SRA;0:SRLI,SRL
                default:result=32'd0;
            endcase
        end
    end
    //branch function
    wire cmp_eq=num1==num2;
    wire cmp_lts=$signed(num1)<$signed(num2);
    wire cmp_ltu=num1<num2;
    //wire cmp_lts=(num1[31]^num2[31])?num1[31]:cmp_ltu;
    reg branch_decision0;
    wire branch_decision;
    always@(*)begin
        branch_decision0=1'b0;
        case(funct[2:1])
            2'b00:branch_decision0=cmp_eq;//BEQ,BNE
            2'b10:branch_decision0=cmp_lts;//BLT,BGE
            2'b11:branch_decision0=cmp_ltu;//BLTU,BGEU
            default:branch_decision0=1'd0;
        endcase
    end
    assign branch_decision=funct[0]^branch_decision0;
    //aux
    assign aux0=aux_num1+aux_num2;
    assign aux={aux0[31:1],aux0[0]&&~mytype[3]};
    //redirect
    wire actual_taken/* verilator public_flat_rd */;
    wire mispredict;
    assign actual_taken=(|mytype[3:2])||(mytype[4]&&branch_decision);
    assign mispredict=mytype[3]||(actual_taken^pred_taken);
    assign redirect_valid=mispredict&&EXU_LSU_fire;

    wire [31:0] branch_snpc;
    assign branch_snpc=aux_num1+32'd4;
    assign exu_redirect_pc=(mytype[4]&&pred_taken)?branch_snpc:aux;
endmodule
