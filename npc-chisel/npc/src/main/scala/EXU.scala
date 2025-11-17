
package npc
{
import chisel3._
import chisel3.util._

import npc.common._
import npc.Constants._


class EXEPipeIO(implicit val conf: Config) extends Bundle() {
   // Memory State
   val csr_inst         = Output(UInt(12.W))
   val pc               = Output(UInt(conf.xprlen.W))
   val pc_valid         = Output(Bool())
   val wbaddr           = Output(UInt(5.W))
   val rs2_data         = Output(UInt(conf.xlen.W))
   val alu_out          = Output(UInt(conf.xlen.W))
   val ctrl_wb_sel      = Output(UInt(WB_X.getWidth.W))
   val ctrl_rf_wen      = Output(Bool())
   val ctrl_mem_val     = Output(Bool())
   val ctrl_mem_fcn     = Output(UInt(M_X.getWidth.W)) 
   val ctrl_mem_typ     = Output(UInt(MT_X.getWidth.W))
   val ctrl_csr_cmd     = Output(UInt(CSR.N.getWidth.W))
   val exception        = Output(UInt(EXC_NORMAL.getWidth.W))
}

class EXUToIFUOut (implicit val conf: Config) extends Bundle() {
   val exe_brjmp_target    =   Output(UInt(conf.xprlen.W))
   val exe_jump_reg_target =   Output(UInt(conf.xprlen.W))
}
class EXUToCTLIO (implicit val conf: Config) extends Bundle() {
   val alu_out       = Output(UInt(conf.xlen.W))
   val pc            = Output(UInt(conf.xprlen.W))
   val wbaddr        = Output(UInt(5.W))
   val inst_is_load  = Output(Bool())
   val ctrl_rf_wen   = Output(Bool())
   val is_csr        = Output(Bool())
   val br_type       = Output(UInt(BR_N.getWidth.W)) // for debug use
   val br_eq         = Output(Bool())
   val br_lt         = Output(Bool())
   val br_ltu        = Output(Bool())
   val pc_valid      = Output(Bool())
}


class DpathIo(implicit val conf: Config) extends Bundle() 
{
   val dec_exe = Flipped(new DecoupledIO(new DecPipeIO()))
   val exe_mem = new DecoupledIO(new EXEPipeIO())
   val ctl = new CtrlSignalIO()
   val ifu_out = new EXUToIFUOut()
   val to_ctl = new EXUToCTLIO()
}

class EXU(implicit conf: Config) extends Module
{
   val io = IO(new DpathIo())
   io := DontCare
   io.dec_exe.ready := true.B
   val alu_op1 = io.dec_exe.bits.op1_data.asUInt
   val alu_op2 = io.dec_exe.bits.op2_data.asUInt

   // ALU
   val alu_out   = Wire(UInt(conf.xprlen.W))
   val alu_shamt = alu_op2(4,0).asUInt
   val adder_out = (alu_op1 + alu_op2)(conf.xprlen-1,0)

   // alu_out := MuxCase(0.U, Seq(
   //                (io.dec_exe.bits.alu_fun === ALU_ADD)  -> (alu_op1 + alu_op2).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_SUB)  -> (alu_op1 - alu_op2).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_AND)  -> (alu_op1 & alu_op2).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_OR)   -> (alu_op1 | alu_op2).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_XOR)  -> (alu_op1 ^ alu_op2).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_SLT)  -> (alu_op1.asSInt < alu_op2.asSInt).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_SLTU) -> (alu_op1 < alu_op2).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_SLL)  -> ((alu_op1 << alu_shamt)(conf.xprlen-1, 0)).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_SRA)  -> (alu_op1.asSInt >> alu_shamt).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_SRL)  -> (alu_op1 >> alu_shamt).asUInt,
   //                (io.dec_exe.bits.alu_fun === ALU_COPY_1)-> alu_op1,
   //                (io.dec_exe.bits.alu_fun === ALU_COPY_2)-> alu_op2
   //                ))

   // 预计算共享结果
   val adderResult      = (alu_op1 + alu_op2).asUInt
   val subtractorResult = (alu_op1 - alu_op2).asUInt
   val andResult        = (alu_op1 & alu_op2).asUInt
   val orResult         = (alu_op1 | alu_op2).asUInt
   val xorResult        = (alu_op1 ^ alu_op2).asUInt
   val sltResult        = (alu_op1.asSInt < alu_op2.asSInt).asUInt
   val sltuResult       = (alu_op1 < alu_op2).asUInt
   val sllResult        = ((alu_op1 << alu_shamt)(conf.xprlen-1, 0)).asUInt
   val sraResult        = (alu_op1.asSInt >> alu_shamt).asUInt
   val srlResult        = (alu_op1 >> alu_shamt).asUInt
  
   alu_out := {
      // 使用并行选择逻辑替代MuxCase
      val results =  VecInit(Seq(
      // 直接连接预计算结果
         adderResult                   ,  // ALU_ADD
         subtractorResult              ,  // ALU_SUB
         sllResult                     ,  // ALU_SLL
         srlResult                     ,  // ALU_SRL
         sraResult                     ,  // ALU_SRA
         andResult                     ,  // ALU_AND
         orResult                      ,  // ALU_OR
         xorResult                     ,  // ALU_XOR
         sltResult                     ,  // ALU_SLT
         sltuResult                    ,  // ALU_SLTU
         alu_op1                       ,  // ALU_COPY_1
         alu_op2                         // ALU_COPY_2
      ))
      // 安全选择器  
      val safeSel = Mux(io.dec_exe.bits.alu_fun < 12.U, io.dec_exe.bits.alu_fun, 0.U)
      results.suggestName("alu_results")
      // 优化后的ALU输出选择
      results(safeSel)
   }

   // Branch/Jump Target Calculation
   val pc_plus4    = ( io.dec_exe.bits.pc + 4.U)(conf.xprlen-1,0)
   val brjmp_offset                 = io.dec_exe.bits.op2_data
   io.ifu_out.exe_brjmp_target      := io.dec_exe.bits.pc + brjmp_offset
   io.ifu_out.exe_jump_reg_target   := adder_out


   when (io.ctl.pipeline_kill){
      io.exe_mem.bits.pc_valid         := false.B
      io.exe_mem.bits.csr_inst         := 0.U
      io.exe_mem.bits.ctrl_rf_wen      := false.B
      io.exe_mem.bits.ctrl_mem_val     := false.B
      io.exe_mem.bits.ctrl_csr_cmd     := false.B
      io.exe_mem.valid                 := true.B
   } .otherwise{
      // (1) exe_mem.ready = false -> exe_mem_reg == old  exe_mem_reg != io.exe_mem
      // (2) io.dec_exe.valid = false -> dec_exe_reg == old, exe_mem_reg == io.exe_mem
      io.dec_exe.ready              := io.exe_mem.ready
      io.exe_mem.valid              := true.B
      io.exe_mem.bits.pc            := io.dec_exe.bits.pc
      io.exe_mem.bits.pc_valid      := io.dec_exe.bits.pc_valid
      io.exe_mem.bits.csr_inst      := io.dec_exe.bits.inst(CSR_ADDR_MSB,CSR_ADDR_LSB)
      io.exe_mem.bits.alu_out       := Mux((io.dec_exe.bits.ctrl_wb_sel === WB_PC4), pc_plus4, alu_out)
      io.exe_mem.bits.wbaddr        := io.dec_exe.bits.wbaddr
      io.exe_mem.bits.rs2_data      := io.dec_exe.bits.rs2_data
      io.exe_mem.bits.ctrl_rf_wen   := io.dec_exe.bits.ctrl_rf_wen
      io.exe_mem.bits.ctrl_mem_val  := io.dec_exe.bits.ctrl_mem_val
      io.exe_mem.bits.ctrl_mem_fcn  := io.dec_exe.bits.ctrl_mem_fcn
      io.exe_mem.bits.ctrl_mem_typ  := io.dec_exe.bits.ctrl_mem_typ
      io.exe_mem.bits.ctrl_wb_sel   := io.dec_exe.bits.ctrl_wb_sel
      io.exe_mem.bits.ctrl_csr_cmd  := io.dec_exe.bits.ctrl_csr_cmd
      io.exe_mem.bits.exception     := io.dec_exe.bits.exception
   }

   
   io.to_ctl.alu_out       := alu_out
   io.to_ctl.wbaddr        := io.dec_exe.bits.wbaddr
   io.to_ctl.ctrl_rf_wen   := io.dec_exe.bits.ctrl_rf_wen
   io.to_ctl.is_csr        := io.dec_exe.bits.ctrl_csr_cmd =/= CSR.N && io.dec_exe.bits.ctrl_csr_cmd =/= CSR.I
   io.to_ctl.inst_is_load  := io.dec_exe.bits.ctrl_mem_val && (io.dec_exe.bits.ctrl_mem_fcn === M_XRD)
   io.to_ctl.br_type       := io.dec_exe.bits.br_type // for debug use
   io.to_ctl.br_eq         := (io.dec_exe.bits.op1_data     ===  io.dec_exe.bits.rs2_data)
   io.to_ctl.br_lt         := (io.dec_exe.bits.op1_data.asSInt < io.dec_exe.bits.rs2_data.asSInt) 
   io.to_ctl.br_ltu        := (io.dec_exe.bits.op1_data.asUInt < io.dec_exe.bits.rs2_data.asUInt)
}

 
}