package npc.common

import chisel3._
import chisel3.util._

import Constants._
import Util._


object CSR
{
  // commands
  val SZ = 3
  def X = BitPat.dontCare(SZ)
  def N = 0.U(SZ.W)
  def R = 2.U(SZ.W)
  def I = 4.U(SZ.W)
  def W = 5.U(SZ.W)
  def S = 6.U(SZ.W)
  def C = 7.U(SZ.W)

  val ADDRSZ = 12
}




class CSRFileIO(implicit val conf: Config) extends Bundle {
  val hartid = Input(UInt(conf.xprlen.W))
  val rw = new Bundle {
    val cmd = Input(UInt(CSR.SZ.W))
    val rdata = Output(UInt(conf.xprlen.W))
    val wdata = Input(UInt(conf.xprlen.W))
  }

  val insn_break = Output(Bool())
  val eret = Output(Bool())

  val decode = new Bundle {
    val csr = Input(UInt(CSR.ADDRSZ.W))
  }

  val status = Output(UInt(conf.xprlen.W)) // using UInt for simplicity, can be changed to MStatus if needed
  val evec = Output(UInt(conf.xprlen.W))
  val exception = Input(UInt(5.W))
  val pc = Input(UInt(conf.xprlen.W))
  val retire = Input(Bool())


}

class CSRFile(implicit val conf: Config) extends Module
{
  val io = IO(new CSRFileIO)
  io := DontCare

  val reg_mstatus = Reg(UInt(conf.xprlen.W))
  val reg_mepc = Reg(UInt(conf.xprlen.W))
  val reg_mcause = Reg(UInt(5.W))
  val reg_mtvec = Reg(UInt(conf.xprlen.W))


  val system_insn = io.rw.cmd === CSR.I
  val cpu_ren = io.rw.cmd =/= CSR.N && !system_insn

  val read_mstatus = io.status.asUInt

  val read_mapping = collection.mutable.LinkedHashMap[Int,Bits](

    CSRs.marchid ->   24100012.U,
    CSRs.mvendorid -> 0x78797379.U,
    CSRs.mstatus -> read_mstatus,
    CSRs.mtvec -> reg_mtvec,      // kui: MTVEC is defined in constants.scala

    CSRs.mepc -> reg_mepc,
    CSRs.mcause -> reg_mcause,
    )

  val decoded_addr = read_mapping map { case (k, v) => k -> (io.decode.csr === k) }

  // val priv_sufficient = reg_mstatus.prv >= io.decode.csr(9,8)
  val priv_sufficient = true.B // TODO: remove this line, it is only for testing

  val read_only = io.decode.csr(11,10).andR
  val cpu_wen = cpu_ren && io.rw.cmd =/= CSR.R && priv_sufficient
  val wen = cpu_wen && !read_only
  val wdata = readModifyWriteCSR(io.rw.cmd, io.rw.rdata, io.rw.wdata)

  val opcode = 1.U << io.decode.csr(2,0)
  val insn_call = system_insn && opcode(0)
  val insn_break = system_insn && opcode(1)
  val insn_ret = system_insn && opcode(2) && priv_sufficient
  val insn_wfi = system_insn && opcode(5) && priv_sufficient
  io.status := reg_mstatus

  io.eret := insn_call || insn_break || insn_ret

  // ILLEGAL INSTR
  // TODO: Support misaligned address exceptions
  when (io.exception =/= 0.U) {
    reg_mcause :=  Cat(0.U(1.W),io.exception(3,0))
  }

  // io.evec must be held stable for more than one cycle for the
  // microcoded code to correctly redirect the PC on exceptions
  // ?????????? should be set to another value?
  io.evec := 1000.U


  //MRET
  when (insn_ret && !io.decode.csr(10)) {
    io.evec := reg_mepc
  }

  //ECALL
  when(insn_call){
    reg_mcause := Causes.machine_ecall
    io.evec := reg_mtvec

  }

  //EBREAK
  when(insn_break){
    reg_mcause := Causes.breakpoint
  }

  when (io.exception =/= 0.U || insn_call || insn_break) {
    reg_mepc := io.pc
  }

  io.insn_break := insn_break
  io.rw.rdata := Mux1H(for ((k, v) <- read_mapping) yield decoded_addr(k) -> v)

  when (wen) {

    when (decoded_addr(CSRs.mstatus)) {
      val new_mstatus = wdata.asUInt // using UInt for simplicity, can be changed to MStatus if needed
      reg_mstatus := new_mstatus
    }
    when (decoded_addr(CSRs.mtvec))    { reg_mtvec := wdata }
    when (decoded_addr(CSRs.mepc))     { reg_mepc := (wdata(conf.xprlen-1,0) >> 2.U) << 2.U }
  }

  def readModifyWriteCSR(cmd: UInt, rdata: UInt, wdata: UInt) =
    (Mux(cmd.isOneOf(CSR.S, CSR.C), rdata, 0.U) | wdata) & ~Mux(cmd === CSR.C, wdata, 0.U)
}
