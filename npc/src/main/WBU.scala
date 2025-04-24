package npc
import chisel3._
import chisel3.util._

class WBU extends NPCModule {
  val io = IO(new Bundle{
    val in = Flipped(Decoupled(new LS2WB))
    val wb = new WriteBack
    val out = Decoupled(new Bundle {})
  })
  io.wb := io.in.bits
  io.wb.wen := io.in.bits.wen && io.in.valid
  io.out.valid := io.in.valid  // this is not used
  io.in.ready := true.B
}
