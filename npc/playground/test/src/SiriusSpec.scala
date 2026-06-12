package sirius

import chisel3._
import chisel3.util._
import formal.Formal
import formal.ModuleWithInitReset
import org.scalatest.flatspec.AnyFlatSpec
import scala.util.Random

object AxiSlaveConstraint {
  def apply[T <: Axi4IO](axi: T): T = {
    // when(axi.ar.valid) {
    //   assert(axi.ar.bits.len === 0.U)
    // }
    when(axi.aw.valid) {
      assert(axi.aw.bits.len === 0.U)
    }

    def keepBoolUntil(valid: Bool, reset: Bool): Bool = {
      val validReg = RegInit(false.B)
      when(valid) {
        validReg := true.B
      }
      when(reset) {
        validReg := false.B
      }
      valid || validReg
    }

    // R
    val arBits = RegEnable(axi.ar.bits, axi.ar.fire)
    val rBurstCnt = Counter(0 until 16, axi.r.fire, axi.ar.fire)
    when(axi.r.valid) {
      assume(axi.r.bits.id === arBits.id)
      when(rBurstCnt._1 === arBits.len) {
        assume(axi.r.bits.last)
      }.otherwise {
        assume(!axi.r.bits.last)
      }
    }
    val arFired = keepBoolUntil(axi.ar.fire, axi.r.fire && rBurstCnt._1 === arBits.len)
    when(!arFired) {
      assume(!axi.r.valid)
    }

    // W
    val wId = Reg(chiselTypeOf(axi.aw.bits.id))
    when(axi.aw.fire) {
      wId := axi.aw.bits.id
    }
    when(axi.w.valid) {
      assert(axi.w.bits.last)
    }
    when(axi.b.valid) {
      assume(axi.b.bits.id === wId)
    }
    val awFired = keepBoolUntil(axi.aw.fire, axi.b.fire)
    val wFired = keepBoolUntil(axi.w.fire, axi.b.fire)
    when(!awFired || !wFired) {
      assume(!axi.b.valid)
    }

    axi
  }
}

object IcacheMasterConstraint {
  def apply(io: IcacheIO): IcacheIO = {
    assume(io.ar.bits.addr(1, 0) === 0.U)

    val validReg = RegNext(io.ar.valid, init = false.B)
    val readyReg = RegNext(io.ar.ready, init = false.B)
    val bitsReg = RegNext(io.ar.bits)

    when(validReg && !readyReg) {
      assume(io.ar.valid)
      assume(io.ar.bits === bitsReg)
    }
    io
  }
}

object RefMemConstraint {
  def apply(memSize: Int, axi: Axi4IO, rAddr: UInt, rData: UInt) = {
    val random = new Random()
    val mem = RegInit(VecInit(Seq.fill(memSize / 4)(BigInt(32, random).U(32.W))))

    rData := mem(rAddr >> 2)

    AxiSlaveConstraint(axi)
    assume(axi.r.bits.resp === 0.U)
    val rBurstCnt = Counter(0 until 16, axi.r.fire, axi.ar.fire)

    val arBitsReg = RegEnable(axi.ar.bits, axi.ar.fire)
    val isWrap = arBitsReg.burst === 2.U
    val wrapMask = ((arBitsReg.len + 1.U) << arBitsReg.size) - 1.U
    val baseAddr = arBitsReg.addr & ~wrapMask

    val incrAddr = arBitsReg.addr + (rBurstCnt._1 << arBitsReg.size)
    val wrapAddr = baseAddr | (incrAddr & wrapMask)

    val curAddr = Mux(isWrap, wrapAddr, incrAddr)
    when(axi.r.valid) {
      assume(axi.r.bits.data === mem(curAddr >> 2))
    }
  }
}

class IcacheTest extends ModuleWithInitReset {
  val io = IO(new Bundle {
    val req = Flipped(new IcacheIO)
    val mem = new Axi4IO
  })
  IcacheMasterConstraint(io.req)

  val reqQueue = Module(new Queue(chiselTypeOf(io.req.ar.bits), 16, true, true))
  reqQueue.io.enq.valid := io.req.ar.fire
  reqQueue.io.enq.bits := io.req.ar.bits
  reqQueue.io.deq.ready := io.req.r.fire
  val refRData = Wire(UInt(32.W))
  dontTouch(refRData)
  RefMemConstraint(256, io.mem, reqQueue.io.deq.bits.addr, refRData)
  // RefMemConstraint(256, io.mem, io.req.ar.bits.addr, refRData)

  val dut = Module(new Icache(setNum = 2, wayNum = 8, wayByte = 8, busByte = 4))

  dut.io.cached :<>= io.req
  assume(!io.req.fencei)
  assume(!io.req.abort)

  io.mem :<>= dut.io.mem

  when(io.req.r.valid) {
    assert(io.req.r.bits.data === refRData)
  }
}

class BasicCoreTest extends ModuleWithInitReset {
  val io = IO(new Bundle {
    val imem = new Axi4IO
    val dmem = new Axi4IO
    val bpu = new IfuToBpuIO
  })
  AxiSlaveConstraint(io.imem)
  AxiSlaveConstraint(io.dmem)
  val workSpaceRoot = os.Path(sys.env("WORKSPACE_ROOT_DIR"))
  val rvOpCodesPath = workSpaceRoot / "riscv-opcodes"
  val cfg = CoreConfig.default.copy(
    isDebug = false,
    perf = false,
    formal = true,
    rvOpCodesPath = rvOpCodesPath,
    registerAddrWidth = 5
  )
  val ucfg = UnitConfig()
  val basicCore = Module(new BasicCore()(cfg, ucfg))
  io.imem :<>= basicCore.io.axiIfu
  io.dmem :<>= basicCore.io.axiLsu
  io.bpu :<>= basicCore.io.bpu.get

  val trivialBits = if (cfg.hasC) 1 else 2
  def pcHi(data: UInt): UInt = data.head(cfg.xlen - cfg.predTargetWidth - trivialBits)
  assume(pcHi(io.bpu.target) === pcHi(io.bpu.pc))
}

class SiriusSpec extends AnyFlatSpec {
  "icache" should "pass" in {
    Formal.verify(new IcacheTest, "IcacheTest", depth = 30, engines = Set("abc bmc3"))
  }
  "basicCore" should "pass" in {
    Formal.verify(
      new BasicCoreTest,
      "BasicCoreTest",
      depth = 50,
      skip = 0,
      append = 0,
      engines = Set("smtbmc boolector", "smtbmc boolector -- --noincr")
    )
  }
}
