package npc

import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.formal._
import utils._
import org.scalatest.flatspec.AnyFlatSpec

class MemCache extends Module {
  val io = IO(new Bundle {
    val core = Flipped(new CacheBundle)
    val mem = new MemRWPortBundle
  })

  val icache = Module(new Cache(true))
  val mem = Module(new AXI4MemCtrl)
  icache.io.core <> io.core
  mem.io.axi <> icache.io.mem
  io.mem <> mem.io.dmem
  icache.io.fence_i := false.B
  icache.io.flush := false.B
}

class MemTest extends Module {
  val io = IO(new Bundle {
    val req = Flipped(new MemBundle)
  })

  val memSize = 512  // byte
  val memEntry = memSize / 4
  val addr = io.req.addr(31, 2)

  val dut = Module(new MemCache)
  val memREF = Mem(memEntry, UInt(32.W))

  //val memDUT = Reg(Vec(memEntry, Vec(4, UInt(8.W))))
  //val memREF = Mem(memEntry, Vec(4, UInt(8.W)))
  //when (reset.asBool) {
  //  (0 until memEntry).map(i => memDUT(i) := memREF(i))
  //}

  object State extends ChiselEnum {
    val idle, waitData = Value
  }

  val canIssue = dut.io.core.req.ready

  val state = RegInit(State.idle)
  state := Lookup1H(state, Array(
    State.idle     -> Mux(canIssue, State.waitData, State.idle),
    State.waitData -> Mux(dut.io.core.resp.valid, State.idle, State.waitData),
  ))

  val reqValid = (state === State.idle) && canIssue
  dut.io.core.req.valid := reqValid
  dut.io.core.req.bits := io.req
  dut.io.core.req.bits.wen := false.B
  dut.io.core.req.bits.wdata := 0.U
  dut.io.core.req.bits.wmask:= 0.U
  dut.io.core.resp.ready := true.B
  io.req.rdata := dut.io.core.resp.bits.data

  // dut memory
  dut.io.mem.rdata := memREF(dut.io.mem.raddr(31,2))
  // ref memory
  val refRData = memREF(addr)

  val refData = Mux(reqValid, refRData, RegEnable(refRData, reqValid))
  val dutData = dut.io.core.resp.bits.data
  when (dut.io.core.resp.valid) {
    assert(dutData === refData)
  }
}

class AllFormal extends AnyFlatSpec with ChiselScalatestTester with Formal {
  def formal(name: String, top: => chisel3.Module, bound: Int = 1): Unit = {
    val t0 = System.currentTimeMillis
    verify(top, Seq(BoundedCheck(bound)))
    val time = System.currentTimeMillis - t0
    print(s"${name}: ${time}ms\n")
  }
  "Test" should "pass" in {
    formal("MemTest", new MemTest, 20)
  }
}
