package empty

import chisel3._
import chisel3.util._

class FFRAM(ADDRWIDTH: Int, BITWIDTH: Int) extends PrefixedModule {
  val io = IO(new Bundle {
    val addr = Input(UInt(ADDRWIDTH.W))
    val wdata = Input(UInt(BITWIDTH.W))
    val wen = Input(Bool())
    val rdata = Output(UInt(BITWIDTH.W))
  })
  val nr_regs = (1 << ADDRWIDTH);
  val content = Reg(Vec(nr_regs, UInt(BITWIDTH.W)))

  io.rdata := content(io.addr)
  when(io.wen) {
    content(io.addr) := io.wdata
  }

}