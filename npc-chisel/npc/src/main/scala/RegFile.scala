package npc
import chisel3._
import chisel3.util._
import npc.common.{Config, MemPortIo}   
import npc.Constants._

class RegFileIo(implicit val conf: Config) extends Bundle {
  val out = new RegFileOut()
  val wb = Flipped(new DecoupledIO(new WBToRegIo()))
  val dec = new RegFilePipeIn()
}

class RegFilePipeIn(implicit val conf: Config) extends Bundle {
   val rs1_addr      = Input(UInt(5.W))
   val rs2_addr      = Input(UInt(5.W))
}

class RegFileOut(implicit val conf: Config) extends Bundle {
  val rs1_data = Output(UInt(conf.xlen.W))
  val rs2_data = Output(UInt(conf.xlen.W))
}




class RegFile(implicit val conf: Config) extends Module {
  val io = IO(new RegFileIo())
  io := DontCare
  val rs1_addr = io.dec.rs1_addr
  val rs2_addr = io.dec.rs2_addr
  val wb_addr  = io.wb.bits.wbaddr
  
  // Register File
  val regfile = Mem(16, UInt(conf.xlen.W)).suggestName("regfile_mem") 

  when (io.wb.valid && io.wb.bits.rf_wen && (wb_addr =/= 0.U)) {
    regfile(wb_addr) := io.wb.bits.data
  }

  io.out.rs1_data := Mux((rs1_addr =/= 0.U), regfile(rs1_addr), 0.asUInt(conf.xlen.W))
  io.out.rs2_data := Mux((rs2_addr =/= 0.U), regfile(rs2_addr), 0.asUInt(conf.xlen.W))
}