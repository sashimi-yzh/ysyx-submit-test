package npc

import chisel3._
import chisel3.util._

import npc.common.Instructions._
import npc.common._
import npc.Constants._

class DecPipeIO(implicit val conf: Config) extends Bundle()
{
   val inst             = Output(UInt(conf.xlen.W))
   val pc               = Output(UInt(conf.xprlen.W))
   val pc_valid         = Output(Bool())
   val wbaddr           = Output(UInt(5.W))
   val rs1_addr         = Output(UInt(5.W))
   val rs2_addr         = Output(UInt(5.W))
   val op1_data         = Output(UInt(conf.xprlen.W))
   val op2_data         = Output(UInt(conf.xprlen.W))
   val rs2_data         = Output(UInt(conf.xprlen.W))
   val br_type          = Output(UInt(BR_N.getWidth.W))
   val op2_sel          = Output(UInt(OP2_X.getWidth.W))
   val alu_fun          = Output(UInt(ALU_X.getWidth.W))
   val ctrl_wb_sel      = Output(UInt(WB_X.getWidth.W))
   val ctrl_rf_wen      = Output(Bool())
   val ctrl_mem_val     = Output(Bool())
   val ctrl_mem_fcn     = Output(UInt(M_X.getWidth.W)) 
   val ctrl_mem_typ     = Output(UInt(MT_X.getWidth.W))
   val ctrl_csr_cmd     = Output(UInt(CSR.N.getWidth.W))
   val exception        = Output(UInt(EXC_NORMAL.getWidth.W))
}


class CtrlSignalIO(implicit val conf: Config) extends Bundle() {
  val exe_pc_sel           =   Input(UInt(PC_4.getWidth.W))
  val pipeline_kill        =   Input(Bool())
  val if_kill              =   Input(Bool())
  val dec_kill             =   Input(Bool())
  val fencei               =   Input(Bool())
}

class CtrlDebugPort(implicit val conf: Config) extends Bundle()
{ 
   val csrCount      = Output(UInt(conf.perfCountBits.W))   
   val storeCount    = Output(UInt(conf.perfCountBits.W)) 
   val loadCount     = Output(UInt(conf.perfCountBits.W))  
   val itypeCount    = Output(UInt(conf.perfCountBits.W)) 
   val rtypeCount    = Output(UInt(conf.perfCountBits.W)) 
   val jtypeCount    = Output(UInt(conf.perfCountBits.W)) 
   val utypeCount    = Output(UInt(conf.perfCountBits.W)) 
   val otherCount    = Output(UInt(conf.perfCountBits.W)) 
}

class CpathIo(implicit val conf: Config) extends Bundle()
{
   val dec_reg       =  Flipped(new RegFilePipeIn())
   val ifu_dec       =  Flipped(new DecoupledIO(new IFUPipeIO))
   val dec_exe       =  new DecoupledIO( new DecPipeIO)
   val reg_in        =  Flipped(new RegFileOut())
   val ctl_sign      =  Flipped(new CtrlSignalIO)
   val lsu_ctl       =  Flipped(new LSUTOCtlIO)
   val exe_ctl       =  Flipped(new EXUToCTLIO())
   val wb_ctl        =  Flipped(new WBToCTLIO)
   val debug         =  new CtrlDebugPort
}

class Decoder(implicit val conf: Config) extends Module
{
   val io = IO(new CpathIo())
   val dec_reg_inst = io.ifu_dec.bits.inst
   val dec_reg_pc = io.ifu_dec.bits.pc

   // Control Signals
   val csignals =
      ListLookup(dec_reg_inst,
                             List(N, BR_N  , OP1_X , OP2_X    , OEN_0, OEN_0, ALU_X   , WB_X  ,  REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
               Array(       /* val  |  BR  |  op1  |   op2     |  R1  |  R2  |  ALU    |  wb   | rf   | mem  | mem  | mask | csr | fence.i */
                            /* inst | type |   sel |    sel    |  oen |  oen |   fcn   |  sel  | wen  |  en  |  wr  | type | cmd |         */
                  LW     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_W, CSR.N, N),
                  LB     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_B, CSR.N, N),
                  LBU    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_BU,CSR.N, N),
                  LH     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_H, CSR.N, N),
                  LHU    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_HU,CSR.N, N),
                  SW     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_W, CSR.N, N),
                  SB     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_B, CSR.N, N),
                  SH     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_H, CSR.N, N),

                  AUIPC  -> List(Y, BR_N  , OP1_PC , OP2_UTYPE , OEN_0, OEN_0, ALU_ADD   ,WB_ALU,REN_1, MEN_0, M_X , MT_X,  CSR.N, N),
                  LUI    -> List(Y, BR_N  , OP1_X  , OP2_UTYPE , OEN_0, OEN_0, ALU_COPY_2,WB_ALU,REN_1, MEN_0, M_X , MT_X,  CSR.N, N),

                  ADDI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  ANDI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_AND , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  ORI    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_OR  , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  XORI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_XOR , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLTI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SLT , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLTIU  -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SLTU, WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLLI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SLL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SRAI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SRA , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SRLI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SRL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),

                  SLL    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SLL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  ADD    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_ADD , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SUB    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SUB , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLT    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SLT , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLTU   -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SLTU, WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  AND    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_AND , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  OR     -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_OR  , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  XOR    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_XOR , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SRA    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SRA , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SRL    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SRL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),

                  JAL    -> List(Y, BR_J  , OP1_RS1, OP2_UJTYPE, OEN_0, OEN_0, ALU_X   , WB_PC4, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  JALR   -> List(Y, BR_JR , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_X   , WB_PC4, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  BEQ    -> List(Y, BR_EQ , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BNE    -> List(Y, BR_NE , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BGE    -> List(Y, BR_GE , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BGEU   -> List(Y, BR_GEU, OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BLT    -> List(Y, BR_LT , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BLTU   -> List(Y, BR_LTU, OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),

                  CSRRW  -> List(Y, BR_N  , OP1_RS1, OP2_X     , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, CSR.W, N),
                  CSRRS  -> List(Y, BR_N  , OP1_RS1, OP2_X     , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, CSR.S, N),
                  // CSRRWI -> List(Y, BR_N  , OP1_IMZ, OP2_X     , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, CSR.W, N),
                  // CSRRSI -> List(Y, BR_N  , OP1_IMZ, OP2_X     , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, CSR.S, N),
                  // CSRRC  -> List(Y, BR_N  , OP1_RS1, OP2_X     , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, CSR.C, N),
                  // CSRRCI -> List(Y, BR_N  , OP1_IMZ, OP2_X     , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, CSR.C, N),

                  ECALL  -> List(Y, BR_N  , OP1_X  , OP2_X     , OEN_0, OEN_0, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.I, N),
                  MRET   -> List(Y, BR_N  , OP1_X  , OP2_X     , OEN_0, OEN_0, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.I, N),
                  EBREAK -> List(Y, BR_N  , OP1_X  , OP2_X     , OEN_0, OEN_0, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.I, N),

                  FENCE_I-> List(Y, BR_N  , OP1_X  , OP2_X     , OEN_0, OEN_0, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, Y),
                  // kill pipeline and refetch instructions since the pipeline will be holding stall instructions.
                  // FENCE  -> List(Y, BR_N  , OP1_X  , OP2_X     , OEN_0, OEN_0, ALU_X   , WB_X  , REN_0, MEN_1, M_X  , MT_X, CSR.N, N)
                  // we are already sequentially consistent, so no need to honor the fence instruction
                  ))

   // Put these control signals in variables
   val (cs_val_inst: Bool) :: (cs_br_type:UInt) :: (cs_op1_sel:UInt) :: (cs_op2_sel:UInt) :: (cs_rs1_oen: Bool) :: (cs_rs2_oen: Bool) :: cs0 = csignals
   val cs_alu_fun :: cs_wb_sel :: (cs_rf_wen: Bool) :: (cs_mem_en: Bool) :: cs_mem_fcn :: cs_msk_sel :: cs_csr_cmd :: (cs_fencei: Bool) :: Nil = cs0

              
   
   /////// Register File Interface //////
   val dec_rs1_addr = dec_reg_inst(RS1_MSB, RS1_LSB)
   val dec_rs2_addr = dec_reg_inst(RS2_MSB, RS2_LSB)
   val dec_wbaddr   = dec_reg_inst(RD_MSB, RD_LSB)
   val rf_rs1_data = io.reg_in.rs1_data
   val rf_rs2_data = io.reg_in.rs2_data
   io.dec_reg.rs1_addr := dec_rs1_addr
   io.dec_reg.rs2_addr := dec_rs2_addr
   
   ////// Branch Logic
   val pipeline_kill = Wire(Bool())
   val exe_br_type = io.exe_ctl.br_type
   // val ctrl_exe_pc_sel = Mux(pipeline_kill         , PC_EXC,
   //                       Mux(exe_br_type === BR_N  , PC_4,
   //                       Mux(exe_br_type === BR_NE , Mux(!io.exe_ctl.br_eq,  PC_BRJMP, PC_4),
   //                       Mux(exe_br_type === BR_EQ , Mux( io.exe_ctl.br_eq,  PC_BRJMP, PC_4),
   //                       Mux(exe_br_type === BR_GE , Mux(!io.exe_ctl.br_lt,  PC_BRJMP, PC_4),
   //                       Mux(exe_br_type === BR_GEU, Mux(!io.exe_ctl.br_ltu, PC_BRJMP, PC_4),
   //                       Mux(exe_br_type === BR_LT , Mux( io.exe_ctl.br_lt,  PC_BRJMP, PC_4),
   //                       Mux(exe_br_type === BR_LTU, Mux( io.exe_ctl.br_ltu, PC_BRJMP, PC_4),
   //                       Mux(exe_br_type === BR_J  , PC_BRJMP,
   //                       Mux(exe_br_type === BR_JR , PC_JALR,
   //                                                          PC_4
   //                   ))))))))))  

   val cond_met = MuxLookup(exe_br_type, false.B)( Seq(
      BR_NE  -> !io.exe_ctl.br_eq,
      BR_EQ  -> io.exe_ctl.br_eq,
      BR_GE  -> !io.exe_ctl.br_lt,
      BR_GEU -> !io.exe_ctl.br_ltu,
      BR_LT  -> io.exe_ctl.br_lt,
      BR_LTU -> io.exe_ctl.br_ltu
   ))

   val base_sel = MuxLookup(exe_br_type, PC_4)(Seq(
      BR_J  -> PC_BRJMP,
      BR_JR -> PC_JALR
   ))

   val cond_sel = Mux(cond_met, PC_BRJMP, PC_4)

   val is_cond_br = exe_br_type === BR_NE || exe_br_type === BR_EQ ||
                  exe_br_type === BR_GE || exe_br_type === BR_GEU ||
                  exe_br_type === BR_LT || exe_br_type === BR_LTU

   val ctrl_exe_pc_sel = Mux(pipeline_kill, PC_EXC,
                        Mux(exe_br_type === BR_N, PC_4,
                        Mux(is_cond_br, cond_sel, base_sel)))



   val ifkill     = (ctrl_exe_pc_sel =/= PC_4)  || cs_fencei 
   val deckill    = (ctrl_exe_pc_sel =/= PC_4)

   // Exception Handling ---------------------

   // NOTE: initialization 0 will error 
   val dec_exception = io.ifu_dec.bits.exception

   val mem_exception = io.lsu_ctl.mem_exception 
   pipeline_kill :=  (io.lsu_ctl.csr_eret || mem_exception) 
   io.ctl_sign.pipeline_kill := pipeline_kill
   
   // Stall Signal Logic --------------------
   
   val stall   = Wire(Bool())

   val dec_rs1_oen  = Mux(deckill, false.B, cs_rs1_oen)
   val dec_rs2_oen  = Mux(deckill, false.B, cs_rs2_oen)

   io.ctl_sign.exe_pc_sel := ctrl_exe_pc_sel
   io.ctl_sign.if_kill := ifkill
   io.ctl_sign.dec_kill := deckill
   io.ctl_sign.pipeline_kill := pipeline_kill
   io.ctl_sign.fencei := cs_fencei 

   // immediates
   val imm_i = dec_reg_inst(31, 20) 
   val imm_s = Cat(dec_reg_inst(31, 25), dec_reg_inst(11,7))
   val imm_b = Cat(dec_reg_inst(31), dec_reg_inst(7), dec_reg_inst(30,25), dec_reg_inst(11,8))
   val imm_u = dec_reg_inst(31, 12)
   val imm_j = Cat(dec_reg_inst(31), dec_reg_inst(19,12), dec_reg_inst(20), dec_reg_inst(30,21))
   val imm_z = Cat(Fill(27,0.U), dec_reg_inst(19,15))

   // sign-extend immediates
   val imm_i_sext = Cat(Fill(20,imm_i(11)), imm_i)
   val imm_s_sext = Cat(Fill(20,imm_s(11)), imm_s)
   val imm_b_sext = Cat(Fill(19,imm_b(11)), imm_b, 0.U)
   val imm_u_sext = Cat(imm_u, Fill(12,0.U))
   val imm_j_sext = Cat(Fill(11,imm_j(19)), imm_j, 0.U)

   // Operand 2 Mux
   // val alu_op2 = MuxCase(0.U, Array(
   //             (cs_op2_sel === OP2_RS2)    -> rf_rs2_data,
   //             (cs_op2_sel === OP2_ITYPE)  -> imm_i_sext,
   //             (cs_op2_sel === OP2_STYPE)  -> imm_s_sext,
   //             (cs_op2_sel === OP2_SBTYPE) -> imm_b_sext,
   //             (cs_op2_sel === OP2_UTYPE)  -> imm_u_sext,
   //             (cs_op2_sel === OP2_UJTYPE) -> imm_j_sext
   //             )).asUInt
   val alu_op2 = {
      // 创建查找表
      val op2LookupTable = VecInit(Seq(
         rf_rs2_data,   // OP2_RS2
         imm_i_sext,    // OP2_ITYPE
         imm_s_sext,    // OP2_STYPE
         imm_b_sext,    // OP2_SBTYPE
         imm_u_sext,    // OP2_UTYPE
         imm_j_sext     // OP2_UJTYPE
      ))
   
      // 安全选择器（防止越界）
      val safeSel = Mux(cs_op2_sel < op2LookupTable.size.U, cs_op2_sel, 0.U)
   
      // 查找结果
      op2LookupTable(safeSel)
   }

   val op1_data = Wire(UInt(conf.xprlen.W))
   val op2_data = Wire(UInt(conf.xprlen.W))
   val rs2_data = Wire(UInt(conf.xprlen.W))

   if (conf.USE_FULL_BYPASSING){
      // roll the OP1 mux into the bypass mux logic
      op1_data := MuxCase(rf_rs1_data, Array(
                           ((cs_op1_sel === OP1_IMZ)) -> imm_z,
                           ((cs_op1_sel === OP1_PC)) -> dec_reg_pc,
                           ((io.exe_ctl.wbaddr === dec_rs1_addr) && (dec_rs1_addr =/= 0.U) && io.exe_ctl.ctrl_rf_wen) -> io.exe_ctl.alu_out,
                           ((io.lsu_ctl.wbaddr === dec_rs1_addr) && (dec_rs1_addr =/= 0.U) && io.lsu_ctl.ctrl_rf_wen) -> io.lsu_ctl.wbdata,
                           ((io.wb_ctl.wbaddr  === dec_rs1_addr) && (dec_rs1_addr =/= 0.U) &&  io.wb_ctl.ctrl_rf_wen) -> io.wb_ctl.wbdata
                           ))

      op2_data := MuxCase(alu_op2, Array(
                           ((io.exe_ctl.wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && io.exe_ctl.ctrl_rf_wen && (cs_op2_sel === OP2_RS2)) -> io.exe_ctl.alu_out,
                           ((io.lsu_ctl.wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && io.lsu_ctl.ctrl_rf_wen && (cs_op2_sel === OP2_RS2)) -> io.lsu_ctl.wbdata,
                           ((io.wb_ctl.wbaddr  === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) &&  io.wb_ctl.ctrl_rf_wen && (cs_op2_sel === OP2_RS2)) -> io.wb_ctl.wbdata
                           ))

      rs2_data := MuxCase(rf_rs2_data, Array(
                           ((io.exe_ctl.wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && io.exe_ctl.ctrl_rf_wen) -> io.exe_ctl.alu_out,
                           ((io.lsu_ctl.wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && io.lsu_ctl.ctrl_rf_wen) -> io.lsu_ctl.wbdata,
                           ((io.wb_ctl.wbaddr  === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) &&  io.wb_ctl.ctrl_rf_wen) -> io.wb_ctl.wbdata
                           ))

   } else{
      // Rely only on control interlocking to resolve hazards
      op1_data := MuxCase(rf_rs1_data, Array(
                          ((cs_op1_sel === OP1_IMZ)) -> imm_z,
                          ((cs_op1_sel === OP1_PC))  -> dec_reg_pc
                          ))
      rs2_data := rf_rs2_data
      op2_data := alu_op2
   }

   /////// stall 
   val exe_inst_is_load = io.exe_ctl.inst_is_load
   // NOTE: stall for load-use hazard
   // when load inst in exe stage, bypass not work in dec stage, alu_out is not answer 
   // when load inst in exe stage, for WBDATA in mem stage is not ready 
   // after stall, dec inst can find wbdata in wb stage
   stall := ((exe_inst_is_load) && (io.exe_ctl.wbaddr === dec_rs1_addr) && (io.exe_ctl.wbaddr =/= 0.U) && dec_rs1_oen) ||
            ((exe_inst_is_load) && (io.exe_ctl.wbaddr === dec_rs2_addr) && (io.exe_ctl.wbaddr =/= 0.U) && dec_rs2_oen) ||
            (io.exe_ctl.is_csr) 

   // NOTE: when load-use hazard happen, should take BUBBLE inst to exe stage
   // or exe stage always load inst, and pipeline is broken
   when( stall || ifkill ||(!io.ifu_dec.valid && io.dec_exe.ready) || pipeline_kill){
      io.dec_exe.valid              := true.B
      io.dec_exe.bits.pc            := dec_reg_pc
      io.dec_exe.bits.pc_valid      := false.B
      io.dec_exe.bits.inst          := BUBBLE
      io.dec_exe.bits.wbaddr        := 0.U
      io.dec_exe.bits.ctrl_rf_wen   := false.B
      io.dec_exe.bits.ctrl_mem_val  := false.B
      io.dec_exe.bits.ctrl_mem_fcn  := M_X
      io.dec_exe.bits.ctrl_csr_cmd  := CSR.N
      io.dec_exe.bits.br_type       := BR_N
      io.dec_exe.bits.exception     := false.B
      io.dec_exe.bits.rs1_addr      := 0.U
      io.dec_exe.bits.rs2_addr      := 0.U
      io.dec_exe.bits.op1_data      := 0.U
      io.dec_exe.bits.op2_data      := 0.U
      io.dec_exe.bits.rs2_data      := 0.U
      io.dec_exe.bits.op2_sel       := OP2_X
      io.dec_exe.bits.alu_fun       := ALU_X
      io.dec_exe.bits.ctrl_wb_sel   := WB_X
      io.dec_exe.bits.ctrl_mem_typ  := MT_X

   } .otherwise {
      io.dec_exe.bits.pc            := dec_reg_pc
      io.dec_exe.bits.rs1_addr      := dec_rs1_addr
      io.dec_exe.bits.rs2_addr      := dec_rs2_addr
      io.dec_exe.bits.op1_data      := op1_data
      io.dec_exe.bits.op2_data      := op2_data
      io.dec_exe.bits.rs2_data      := rs2_data
      io.dec_exe.bits.op2_sel       := cs_op2_sel
      io.dec_exe.bits.alu_fun       := cs_alu_fun
      io.dec_exe.bits.ctrl_wb_sel   := cs_wb_sel

      when(deckill){
         io.dec_exe.valid              := true.B
         io.dec_exe.bits.pc_valid      := false.B
         io.dec_exe.bits.inst          := BUBBLE
         io.dec_exe.bits.wbaddr        := 0.U
         io.dec_exe.bits.ctrl_rf_wen   := false.B
         io.dec_exe.bits.ctrl_mem_val  := false.B
         io.dec_exe.bits.ctrl_mem_fcn  := M_X
         io.dec_exe.bits.ctrl_csr_cmd  := CSR.N
         io.dec_exe.bits.br_type       := BR_N  
         io.dec_exe.bits.exception     := false.B
         io.dec_exe.bits.ctrl_mem_typ  := MT_X

      }
      .otherwise{
         io.dec_exe.valid              := true.B
         io.dec_exe.bits.pc_valid      := io.ifu_dec.bits.pc_valid
         io.dec_exe.bits.inst          := dec_reg_inst
         io.dec_exe.bits.wbaddr        := dec_wbaddr
         io.dec_exe.bits.ctrl_rf_wen   := cs_rf_wen
         io.dec_exe.bits.ctrl_mem_val  := cs_mem_en
         io.dec_exe.bits.ctrl_mem_fcn  := cs_mem_fcn
         io.dec_exe.bits.ctrl_mem_typ  := cs_msk_sel
         io.dec_exe.bits.ctrl_csr_cmd  := cs_csr_cmd
         io.dec_exe.bits.br_type       := cs_br_type
         io.dec_exe.bits.exception     := dec_exception
      }
   }


   
   // TODO: some signals should be inform ifu when decoding, like jump, load/store ?
   io.ifu_dec.ready := io.dec_exe.ready  && !stall 




   /////////   Debug Signals
   val perfCounters = RegInit(VecInit(Seq.fill(8)(0.U(conf.perfCountBits.W))))
   val Seq( loadCount, storeCount, jtypeCount, utypeCount, itypeCount, 
            rtypeCount, csrCount, otherCount ) = perfCounters
  // 加载指令检测
   val isLoad = dec_reg_inst === LB || dec_reg_inst === LH || dec_reg_inst === LW || 
                  dec_reg_inst === LBU || dec_reg_inst === LHU
   
   // 存储指令检测
   val isStore = dec_reg_inst === SB || dec_reg_inst === SH || dec_reg_inst === SW
   
   // 分支指令检测
   val isBranch = dec_reg_inst === BEQ || dec_reg_inst === BNE || 
                  dec_reg_inst === BLT || dec_reg_inst === BGE || 
                  dec_reg_inst === BLTU || dec_reg_inst === BGEU
   
   // 跳转指令检测
   val isJump = dec_reg_inst === JAL || dec_reg_inst === JALR
   
   // I型指令检测
   val isIType = dec_reg_inst === ADDI || dec_reg_inst === ANDI || dec_reg_inst === ORI || 
                  dec_reg_inst === XORI || dec_reg_inst === SLTI || dec_reg_inst === SLTIU || 
                  dec_reg_inst === SLLI || dec_reg_inst === SRAI || dec_reg_inst === SRLI
   
   // R型指令检测
   val isRType = dec_reg_inst === ADD || dec_reg_inst === SUB || dec_reg_inst === SLL || 
                  dec_reg_inst === SLT || dec_reg_inst === SLTU || dec_reg_inst === XOR || 
                  dec_reg_inst === SRL || dec_reg_inst === SRA || dec_reg_inst === OR || 
                  dec_reg_inst === AND
   
   // CSR指令检测
   val isCSR = dec_reg_inst === CSRRSI ||dec_reg_inst === CSRRCI ||dec_reg_inst === CSRRW || dec_reg_inst === CSRRS || 
         dec_reg_inst === CSRRC || dec_reg_inst === ECALL || dec_reg_inst === MRET ||   dec_reg_inst === DRET || 
         dec_reg_inst === EBREAK ||dec_reg_inst === WFI  || dec_reg_inst === FENCE_I || dec_reg_inst === FENCE  

   val isUtype = dec_reg_inst === LUI || dec_reg_inst === AUIPC
   when(io.ifu_dec.valid){
      when(isLoad) {
         loadCount := loadCount + 1.U
      }.elsewhen(isStore) {
         storeCount := storeCount + 1.U
      }.elsewhen(isBranch) {
         jtypeCount := jtypeCount + 1.U
      }.elsewhen(isJump) {
         jtypeCount := jtypeCount + 1.U
      }.elsewhen(isIType) {
         itypeCount := itypeCount + 1.U
      }.elsewhen(isRType) {
         rtypeCount := rtypeCount + 1.U
      }.elsewhen(isCSR) {
         csrCount := csrCount + 1.U
      } .elsewhen(isUtype){
         utypeCount := utypeCount + 1.U
      }.otherwise {
         otherCount := otherCount + 1.U
      }
   }

   io.debug.csrCount    := csrCount      
   io.debug.storeCount  := storeCount  
   io.debug.loadCount   := loadCount    
   io.debug.itypeCount  := itypeCount  
   io.debug.rtypeCount  := rtypeCount  
   io.debug.jtypeCount  := jtypeCount  
   io.debug.utypeCount  := utypeCount
   io.debug.otherCount  := otherCount
}
