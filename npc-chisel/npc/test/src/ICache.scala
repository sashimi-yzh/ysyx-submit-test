import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.formal._
import org.scalatest.flatspec.AnyFlatSpec

import npc.common._
import npc._

class MemPort(val data_width: Int)(implicit val conf: Config)  extends Module {
  val io = IO(Flipped(new MemPortIo(data_width)))
  val memSize = 256  // byte
  val mem = Mem(memSize, UInt(32.W))

  io.req := DontCare
  io.resp := DontCare
  io.resp.valid := io.req.valid
  io.resp.bits.data := mem(io.req.bits.addr)
  io.resp.bits.resp := 0.U
}

class CacheTest extends Module {
  implicit val conf = Config()
  val io = IO(new Bundle {
    val req = new ICacheIO
    val block = Input(Bool())
  })
  io := DontCare

  val mem = Module(new MemPort(32) )
  val refMem = Module(new MemPort(32) )
  
  val dut = Module(new ICache)
  dut.io.fencei := false.B
  dut.io.req_valid := true.B
  dut.io.pc <> io.req.pc
  dut.io.port <> mem.io

  refMem.io := DontCare
  refMem.io.req.valid := true.B
  refMem.io.req.bits.addr := io.req.pc
  

  val dutData = dut.io.inst
  val refData = RegNext(refMem.io.resp.bits.data)
  when (dut.io.valid) {
    assert(dutData === refData)
  }
}

class FormalTest extends AnyFlatSpec with ChiselScalatestTester with Formal {
  "Test" should "pass" in {
    verify(new CacheTest, Seq(BoundedCheck(3), BtormcEngineAnnotation))
  }
}


// import chisel3._
// import chisel3.util._
// import chiseltest._
// import chiseltest.formal._
// import org.scalatest.flatspec.AnyFlatSpec

// class Sub extends Module {
//   val io = IO(new Bundle {
//     val a = Input(UInt(4.W))
//     val b = Input(UInt(4.W))
//     val c = Output(UInt(4.W))
//   })
//   io.c := io.a + ~io.b + Mux(io.a === 2.U, 0.U, 1.U)

//   val ref = io.a - io.b
//   assert(io.c === ref)
// }

// class FormalTest extends AnyFlatSpec with ChiselScalatestTester with Formal {
//   "Test" should "pass" in {
//     verify(new Sub, Seq(BoundedCheck(1), BtormcEngineAnnotation))
//   }
// }