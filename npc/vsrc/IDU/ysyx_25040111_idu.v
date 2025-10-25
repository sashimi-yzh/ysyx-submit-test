`ifndef NPC_IDU
`define NPC_IDU

`include "../HDR/ysyx_25040111_inc.vh"

module ysyx_25040111_idu(
    input               clock,
    input               reset,

    input [31:0]        idu_inst,
    input [31:0]        idu_pc,
    input               idu_ready,
    output              idu_valid,
    output              jump,

    output              exe_valid,
    input               exe_ready,

    // wire to case
    output reg [4:0]    rs1,
    output reg [4:0]    rs2,
    output reg [4:0]    rd,
    output reg [31:0]   imm,
    output reg [`OPT_HIGH:0] opt,
    // wire to case

    output [3:0]        err_type,
    output reg          err,

    output [11:0]       csrw, 
                        csrr,
    output [31:0]       exe_pc
);

//-----------------------------------------------------------------
// Register / Wire
//-----------------------------------------------------------------

    reg [31:0]  inst;
    reg [31:0]  pc;
    reg         decode_ok;

    wire        jmp_valid = |opt[2:0];
    wire        fencei = ~opt[0] & ~opt[15] & (opt[12:10] == 3'b100);
    
//-----------------------------------------------------------------
// External Interface
//-----------------------------------------------------------------

    assign exe_valid = decode_ok;
    assign idu_valid = ~decode_ok;
    assign jump      = (~(opt[9:8] == 2'b01) & jmp_valid) | (opt[12] & opt[15]) | fencei;
    assign exe_pc    = pc;
    
//-----------------------------------------------------------------
// State Machine
//-----------------------------------------------------------------

    // inst pc
    always @(posedge clock) begin
        if (reset) begin
            inst <= 0;
            pc <= 0;            
        end
        else if (idu_ready & idu_valid) begin
            inst <= idu_inst;
            pc <= idu_pc;            
        end
    end

    // decode_ok
    always @(posedge clock) begin
        if (reset)
            decode_ok <= 1'b0;
        else if (idu_ready & idu_valid)
            decode_ok <= 1'b1;
        else if (exe_valid & exe_ready)
            decode_ok <= 1'b0;
    end

//-----------------------------------------------------------------
// Module Instence
//-----------------------------------------------------------------

    // OP-IMM                         
    wire [4:0] rs1_opimm, rd_opimm;
    wire [31:0] imm_opimm;
    wire [`OPT_HIGH:0] opt_opimm;

    ysyx_25040111_opimm u_ysyx_25040111_opimm(
        .inst 	(inst[31:7]),
        .rs1  	(rs1_opimm ),
        .rd   	(rd_opimm  ),
        .imm  	(imm_opimm ),
        .opt    (opt_opimm )
    );

 
    // OP                      
    wire [4:0] rs1_op, rd_op, rs2_op;
    wire [`OPT_HIGH:0] opt_op;

    ysyx_25040111_op u_ysyx_25040111_op(
        .inst 	(inst[31:7] ),
        .rs1  	(rs1_op     ),
        .rs2    (rs2_op     ),
        .rd   	(rd_op      ),
        .opt    (opt_op     )
    );

 
    // AUIPC        LUI              
    wire [4:0] rd_auipc_lui;
    wire [31:0] imm_auipc_lui;
    wire [`OPT_HIGH:0] opt_auipc_lui;
    
    ysyx_25040111_auipc_lui u_ysyx_25040111_auipc_lui(
        .inst 	(inst[31:7]      ),
        .chos 	(inst[5]         ),
        .rd   	(rd_auipc_lui    ),
        .imm  	(imm_auipc_lui   ),
        .opt  	(opt_auipc_lui   )
    );

 
    // JALR             
    wire [4:0] rs1_jalr;
    wire [31:0] imm_jalr;
    wire [`OPT_HIGH:0] opt_jalr;
    wire [4:0] rd_jalr;
    
    ysyx_25040111_jalr u_ysyx_25040111_jalr(
        .inst 	(inst[31:7] ),
        .rs1  	(rs1_jalr   ),
        .imm  	(imm_jalr   ),
        .opt  	(opt_jalr   ),
        .rd   	(rd_jalr    )
    );

 
    // JALR             
    wire [4:0] rs1_branch;
    wire [4:0] rs2_branch;
    wire [31:0] imm_branch;
    wire [`OPT_HIGH:0] opt_branch;
    
    ysyx_25040111_branch u_ysyx_25040111_branch(
        .inst 	(inst[31:7]   ),
        .rs1  	(rs1_branch   ),
        .rs2  	(rs2_branch   ),
        .imm  	(imm_branch   ),
        .opt  	(opt_branch   )
    );

 
    // STORE
    wire [4:0] rs1_store;
    wire [4:0] rs2_store;
    wire [31:0] imm_store;
    wire [`OPT_HIGH:0] opt_store;
    
    ysyx_25040111_store u_ysyx_25040111_store(
        .inst 	(inst[31:7]  ),
        .rs1  	(rs1_store   ),
        .rs2  	(rs2_store   ),
        .imm  	(imm_store   ),
        .opt  	(opt_store   )
    );
    
 
    // LOAD
    wire [4:0] rs1_load;
    wire [4:0] rd_load;
    wire [31:0] imm_load;
    wire [`OPT_HIGH:0] opt_load;
    
    ysyx_25040111_load u_ysyx_25040111_load(
        .inst 	(inst[31:7] ),
        .rs1  	(rs1_load   ),
        .rd   	(rd_load    ),
        .imm  	(imm_load   ),
        .opt  	(opt_load   )
    );
    
 
    // JAL                     
    wire [31:0] imm_jal;
    wire [`OPT_HIGH:0] opt_jal;
    wire [4:0] rd_jal;
    
    ysyx_25040111_jal u_ysyx_25040111_jal (
        .inst 	(inst[31:7]  ),
        .imm  	(imm_jal     ),
        .opt  	(opt_jal     ),
        .rd   	(rd_jal      )
    );
    
 
    // SYSTEM                       
    wire [4:0] rs1_system, rd_system;
    wire [`OPT_HIGH:0] opt_system;
    wire [31:0] imm_system;
    wire errmux;

    ysyx_25040111_system u_ysyx_25040111_system(
        .inst 	    (inst[31:7]  ),
        .rs1        (rs1_system  ),
        .rd         (rd_system   ),
        .csrr       (csrr        ),
        .csrw       (csrw        ),
        .imm        (imm_system  ),
        .opt        (opt_system  ),
        .err_type   (err_type    ),
        .err        (errmux      )
    );
 
    // MISC-MEM                
    wire [4:0] rd_miscmem;
    wire [`OPT_HIGH:0] opt_miscmem;
    
    ysyx_25040111_miscmem u_ysyx_25040111_miscmem(
        .func3 	(inst[14:12]),
        .rd    	(rd_miscmem ),
        .opt   	(opt_miscmem)
    );
    

//-----------------------------------------------------------------
// Combinational Logic
//-----------------------------------------------------------------
    always @(*) begin
        rs1 = 5'b0;
        rs2 = 5'b0;
        rd  = 5'b0;
        imm = 32'b0;
        opt = `OPT_LEN'b0;
        err = 1'b0;

        case (inst[6:0])
            7'b0010011: begin
                rs1 = rs1_opimm;
                rs2 = 5'b0;
                rd  = rd_opimm;
                imm = imm_opimm;
                opt = opt_opimm;
            end

            7'b0010111: begin
                rs1 = 5'b0;
                rs2 = 5'b0;
                rd  = rd_auipc_lui;
                imm = imm_auipc_lui;
                opt = opt_auipc_lui;
            end

            7'b0110111: begin
                rs1 = 5'b0;
                rs2 = 5'b0;
                rd  = rd_auipc_lui;
                imm = imm_auipc_lui;
                opt = opt_auipc_lui;
            end

            7'b1100111: begin
                rs1 = rs1_jalr;
                rs2 = 5'b0;
                rd  = rd_jalr;
                imm = imm_jalr;
                opt = opt_jalr;
            end

            7'b1101111: begin
                rs1 = 5'b0;
                rs2 = 5'b0;
                rd  = rd_jal;
                imm = imm_jal;
                opt = opt_jal;
            end

            7'b1110011: begin
                rs1 = rs1_system;
                rs2 = 5'b0;
                rd  = rd_system;
                imm = imm_system;
                opt = opt_system;
                err = errmux;
            end

            7'b0100011: begin
                rs1 = rs1_store;
                rs2 = rs2_store;
                rd  = 5'b0;
                imm = imm_store;
                opt = opt_store;
            end

            7'b0000011: begin
                rs1 = rs1_load;
                rs2 = 5'b0;
                rd  = rd_load;
                imm = imm_load;
                opt = opt_load;
            end

            7'b0110011: begin
                rs1 = rs1_op;
                rs2 = rs2_op;
                rd  = rd_op;
                imm = 32'b0;
                opt = opt_op;
            end

            7'b1100011: begin
                rs1 = rs1_branch;
                rs2 = rs2_branch;
                rd  = 5'b0;
                imm = imm_branch;
                opt = opt_branch;
            end

            7'b0001111: begin
                rs1 = 5'b0;
                rs2 = 5'b0;
                rd  = rd_miscmem;
                imm = 32'b0;
                opt = opt_miscmem;    
            end

            default: begin
            end
        endcase
    end

endmodule

`endif
