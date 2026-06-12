package sub

import chisel3._
import chisel3.util._
import org.scalatest.flatspec.AnyFlatSpec
import scala.util.Random
import formal.Formal
import formal.ModuleWithInitReset

class SubTest extends ModuleWithInitReset {
  val io = IO(new Bundle {
    // val a = Input(UInt(32.W))
    // val b = Input(UInt(32.W))
    val c = Output(UInt(32.W))
  })

  // io.c := io.a + ~io.b + Mux(io.a === "h98765".U, 0.U, 1.U)
  // // io.c := io.a + ~io.b + 1.U
  //
  // val ref = io.a - io.b
  //
  // // AssertProperty(io.c === ref)
  // assert(io.c === ref)
  // assume(reset.asBool)
  // val initReset = Module(new InitAssume)
  // initReset.cond := reset.asBool
  val reg = RegInit(0.U(32.W))
  reg := Mux(reg < 15.U, reg + 1.U, 0.U)
  io.c := reg
  assert(io.c < 15.U)
}

class SubSpec extends AnyFlatSpec {
  "sub" should "pass" in {
    Formal.verify(new SubTest, "SubTest", 20)
  }
}
