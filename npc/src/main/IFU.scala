package npc
import chisel3._
import chisel3.util._
import utils._

object toPC extends NPCParameters {
  def apply(x: UInt) = x(PALEN - 1, 2) ## 0.U(2.W)
}

class IFU extends NPCModule {
  val io = IO(new Bundle{
    val out = Decoupled(new IF2ID)
    val mem = new CacheBundle
    val redirect = Flipped(new RedirectIO)
  })
  val PC = RegInit("x30000000".U(PALEN.W))
  PC := toPC(Mux(io.redirect.valid, io.redirect.dnpc, Mux(io.mem.req.fire, PC + 4.U, PC)))

  io.mem.req.valid  := true.B
  io.mem.req.bits.addr := toPC(PC)
  io.mem.req.bits.size := "b10".U
  io.mem.req.bits.wen  := false.B
  io.mem.req.bits.wdata := DontCare
  io.mem.req.bits.wmask := DontCare
  io.mem.resp.ready := io.out.ready

  val rdata = io.mem.resp.bits.data
  val pc_s2 = toPC(io.mem.resp.bits.addr)
  io.out.bits.inst := (if (XLEN == 64) rdata.asTypeOf(Vec(2, UInt(32.W)))(pc_s2(2)) else rdata)
  io.out.bits.pc := pc_s2
  io.out.valid := io.mem.resp.valid
}
