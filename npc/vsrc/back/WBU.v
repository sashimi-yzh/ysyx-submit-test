module WBU(
  input [31:0] pc,            
  input [31:0] alu_result,    
  input [31:0] rdata,     
  input [31:0] imm_u,         
  input [31:0] jump_target,   
  input [31:0] branch_target, 
  input [31:0] csr_rdata,
  input [31:0] mepc,
  input [31:0] mtvec,
  input branch_taken,         
  
  // U型指令
  input is_lui,
  input is_auipc,
  
  // J型指令
  input is_jal,
  input is_jalr,
  
  // 系统指令
  input is_ebreak,
  input is_ecall,
  input is_mret,
  input is_csr,
  input op_load,
  input is_jump,
  
  // 输出
  output reg [31:0] rd_data,      
  output reg [31:0] pc_next       
);

  always @(*) begin
    case (1'b1)
      is_csr : rd_data = csr_rdata;
      is_jump : rd_data = pc + 4; 
      is_lui  : rd_data = imm_u;  
      is_auipc: rd_data = pc + imm_u;
      op_load : rd_data = rdata;  
      default : rd_data = alu_result; 
    endcase
  end

  always @(*) begin
    case (1'b1)
      is_ebreak: pc_next = pc; 
      is_ecall : pc_next = mtvec;
      is_mret  : pc_next = mepc;
      is_jalr: pc_next = jump_target; 
      is_jal: pc_next = branch_target; 
      branch_taken: pc_next = branch_target; 
      default: pc_next = pc + 4; 
    endcase
  end

endmodule
