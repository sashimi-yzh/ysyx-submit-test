
/****************************************************
*
* Automatically generated file; DO NOT EDIT.
*
*****************************************************/

package  cpu


import chisel3._
import chisel3.util._
import insts._

object SigMap{


  import pc_sel._
  import A_sel._
  import B_sel._
  import imm_sel._
  import aluop._
  import wb_sel._
  import valid._
  import mask_sel._
  import st_sel._
  import ld_sel._
  import br_sel._
  import csr_cmd._
  import inst_type._

val map = Array(
	lui     ->  List(PC_4  , A_RS1, B_IMM, ALU_COPY_B, IMM_U, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , U_TYPE),
	auipc   ->  List(PC_4  , A_PC , B_IMM, ALU_ADD   , IMM_U, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , U_TYPE),
	addi    ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	andi    ->  List(PC_4  , A_RS1, B_IMM, ALU_AND   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	ori     ->  List(PC_4  , A_RS1, B_IMM, ALU_OR    , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	xori    ->  List(PC_4  , A_RS1, B_IMM, ALU_XOR   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	jalr    ->  List(PC_ALU, A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_PC4, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	jal     ->  List(PC_ALU, A_PC , B_IMM, ALU_ADD   , IMM_J, WB_PC4, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , J_TYPE),
	sb      ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_S, WB_XX , LD_XX , ST_SB, MASK_B , BR_XX , CSR_XX, INST_VALID  , S_TYPE),
	sh      ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_S, WB_XX , LD_XX , ST_SH, MASK_H , BR_XX , CSR_XX, INST_VALID  , S_TYPE),
	sw      ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_S, WB_XX , LD_XX , ST_SW, MASK_W , BR_XX , CSR_XX, INST_VALID  , S_TYPE),
	lw      ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_MEM, LD_LW , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	lhu     ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_MEM, LD_LHU, ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	lh      ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_MEM, LD_LH , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	lb      ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_MEM, LD_LB , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	lbu     ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_MEM, LD_LBU, ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	bne     ->  List(PC_4  , A_PC , B_IMM, ALU_ADD   , IMM_B, WB_XX , LD_XX , ST_XX, MASK_XX, BR_NE , CSR_XX, INST_VALID  , B_TYPE),
	beq     ->  List(PC_4  , A_PC , B_IMM, ALU_ADD   , IMM_B, WB_XX , LD_XX , ST_XX, MASK_XX, BR_EQ , CSR_XX, INST_VALID  , B_TYPE),
	blt     ->  List(PC_4  , A_PC , B_IMM, ALU_ADD   , IMM_B, WB_XX , LD_XX , ST_XX, MASK_XX, BR_LT , CSR_XX, INST_VALID  , B_TYPE),
	bltu    ->  List(PC_4  , A_PC , B_IMM, ALU_ADD   , IMM_B, WB_XX , LD_XX , ST_XX, MASK_XX, BR_LTU, CSR_XX, INST_VALID  , B_TYPE),
	bgeu    ->  List(PC_4  , A_PC , B_IMM, ALU_ADD   , IMM_B, WB_XX , LD_XX , ST_XX, MASK_XX, BR_GEU, CSR_XX, INST_VALID  , B_TYPE),
	bge     ->  List(PC_4  , A_PC , B_IMM, ALU_ADD   , IMM_B, WB_XX , LD_XX , ST_XX, MASK_XX, BR_GE , CSR_XX, INST_VALID  , B_TYPE),
	srli    ->  List(PC_4  , A_RS1, B_IMM, ALU_SRL   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	srai    ->  List(PC_4  , A_RS1, B_IMM, ALU_SRA   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	srl     ->  List(PC_4  , A_RS1, B_RS2, ALU_SRL   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	sra     ->  List(PC_4  , A_RS1, B_RS2, ALU_SRA   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	slli    ->  List(PC_4  , A_RS1, B_IMM, ALU_SLL   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	slt     ->  List(PC_4  , A_RS1, B_RS2, ALU_SLT   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	sltu    ->  List(PC_4  , A_RS1, B_RS2, ALU_SLTU  , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	slti    ->  List(PC_4  , A_RS1, B_IMM, ALU_SLT   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	sltiu   ->  List(PC_4  , A_RS1, B_IMM, ALU_SLTU  , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	sll     ->  List(PC_4  , A_RS1, B_RS2, ALU_SLL   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	add     ->  List(PC_4  , A_RS1, B_RS2, ALU_ADD   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	sub     ->  List(PC_4  , A_RS1, B_RS2, ALU_SUB   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	xor     ->  List(PC_4  , A_RS1, B_RS2, ALU_XOR   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	and     ->  List(PC_4  , A_RS1, B_RS2, ALU_AND   , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	or      ->  List(PC_4  , A_RS1, B_RS2, ALU_OR    , IMM_I, WB_ALU, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
	csrrw   ->  List(PC_4  , A_RS1, B_RS2, ALU_ADD   , IMM_I, WB_CSR, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_W , INST_VALID  , R_TYPE),
	csrrs   ->  List(PC_4  , A_RS1, B_RS2, ALU_ADD   , IMM_I, WB_CSR, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_S , INST_VALID  , R_TYPE),
	ecall   ->  List(PC_CSR, A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_CSR, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_P , INST_VALID  , N_TYPE),
	mret    ->  List(PC_CSR, A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_CSR, LD_XX , ST_XX, MASK_XX, BR_XX , CSR_P , INST_VALID  , N_TYPE),
	fencei  ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_XX , LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , I_TYPE),
	ebreak  ->  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_XX , LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_VALID  , R_TYPE),
)
val 
	default  =  List(PC_4  , A_RS1, B_IMM, ALU_ADD   , IMM_I, WB_XX , LD_XX , ST_XX, MASK_XX, BR_XX , CSR_XX, INST_INVALID, R_TYPE)

}


