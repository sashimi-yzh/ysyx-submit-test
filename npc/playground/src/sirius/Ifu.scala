package sirius

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class Ifu(
  implicit private val cfg: CoreConfig)
    extends Module {
  val exte = IO(new Bundle {
    val pcHi = Input(UInt(cfg.pcHiWidth.W))
    val bpu = new IfuToBpuIO
    val mem = new Axi4IO
    val fencei = Input(Bool())
    val flush = Input(Bool())
    val jumpTarget = Input(UInt(cfg.xlen.W))
    val debugEbreak = Option.when(cfg.isDebug)(Input(Bool()))
  })
  val out = IO(Decoupled(new IfuToIduIO))
  val outBits = out.bits

  outBits.ifuPayload.trap.isTrap := false.B
  outBits.ifuPayload.trap.cause := DontCare

  val flush = exte.flush || (out.fire && exte.bpu.taken)
  val flushTarget = Mux(exte.flush, exte.jumpTarget, exte.bpu.target)

  if (!cfg.formal) {
    // icache
    // val icache = Module(
    //   new Icache(
    //     setNum = 4,
    //     wayNum = 1,
    //     wayByte = 8,
    //     busByte = 4,
    //     if (cfg.ysyxsoc) {
    //       Some(BigInt("a0000000", 16) until BigInt("c0000000", 16))
    //     } else { None }
    //   )
    // )
    // exte.mem :<>= icache.io.mem
    // val cached = icache.io.cached
    // cached.fencei := exte.fencei
    // cached.abort := flush
    // cached.ar.valid := true.B
    // val ifetchAddr = RegInit(cfg.pcInit.U(cfg.xlen.W))
    // when(flush) {
    //   ifetchAddr := flushTarget
    // }.elsewhen(cached.ar.fire) {
    //   ifetchAddr := ifetchAddr + 4.U
    // }
    // cached.ar.bits.addr := ifetchAddr

    val pcInitLo = (cfg.pcInit >> cfg.trivialBits) & ((1 << cfg.predTargetWidth) - 1)
    val pcLo = RegInit(pcInitLo.U(cfg.predTargetWidth.W))
    val pc = PcCat(cfg.hasC, exte.pcHi, pcLo)
    val icache = Module(
      new SimpleIcache(
        setNum = 4,
        if (cfg.ysyxsoc) {
          Some(BigInt("a0000000", 16) until BigInt("c0000000", 16))
        } else { None }
      )
    )
    exte.mem :<>= icache.io.mem
    val cached = icache.io.cached
    cached.fencei := exte.fencei
    cached.abort := flush
    cached.newAddr := Mux(cached.abort, flushTarget, pc)

    val iqueue = Module(new Iqueue(entries32 = 2))
    iqueue.io.flush := flush
    iqueue.io.targetUnalign := flushTarget(1)
    iqueue.io.enq :<>= cached.r.map(_.data)
    // PipelineConnect(cached.r.map(_.data), iqueue.io.enq, flush = flush)

    // val iqueueDeq = Wire(Flipped(chiselTypeOf(iqueue.io.deq)))
    // pipelineConnect(iqueue.io.deq, iqueueDeq, flush = flush)
    val iqueueDeq = iqueue.io.deq
    out.valid := iqueueDeq.valid
    iqueueDeq.ready := out.ready

    when(flush) {
      pcLo := ExtractFrom(flushTarget, cfg.trivialBits, cfg.predTargetWidth)
    }.elsewhen(out.fire) {
      pcLo := pcLo + Mux(iqueueDeq.bits.isC, (2 >> cfg.trivialBits).U, (4 >> cfg.trivialBits).U)
    }

    exte.bpu.pc := pc

    outBits.ifuPayload.ifu.pcLo := pcLo
    outBits.ifuPayload.ifu.debugPc := pc
    outBits.ifuPayload.ifu.predTaken := exte.bpu.taken
    outBits.ifuPayload.ifu.predTarget :=
        (if (cfg.hasC) exte.bpu.target(cfg.predTargetWidth - 1 + 1, 1)
        else exte.bpu.target(cfg.predTargetWidth - 1 + 2, 2))
    outBits.ifuPayload.ifu.inst := iqueueDeq.bits.inst
    outBits.ifuPayload.ifu.isC := iqueueDeq.bits.isC

    if (cfg.perf) {
      // val icacheState = BoringUtils.tapAndRead(icache.state)
      // val icacheNextState = BoringUtils.tapAndRead(icache.nextState)
      // val icacheInWhiteList = BoringUtils.tapAndRead(icache.inWhiteList)
      // val icacheSReadCache = 0.U
      // val icacheSReq = 1.U
      // val icacheSFirstResp = 2.U
      // val icacheSFillCache = 3.U
      // val icacheSWait = 4.U
      // PerfWhen(
      //   "icacheTotalAcc",
      //   icache.io.cached.ar.fire,
      //   exte.debugEbreak
      // )
      // PerfWhen(
      //   "icacheMiss",
      //   icacheState === icacheSReadCache && icacheNextState === icacheSReq && icacheInWhiteList,
      //   exte.debugEbreak
      // )
      // PerfWhen(
      //   "icacheHit",
      //   icache.io.cached.ar.valid && icacheState === icacheSReadCache && (icacheNextState === icacheSReadCache || icacheNextState === icacheSWait),
      //   exte.debugEbreak
      // )
      // PerfWhen(
      //   "icacheBlackList",
      //   icacheState === icacheSReadCache && icacheNextState === icacheSReq && !icacheInWhiteList,
      //   exte.debugEbreak
      // )
      // PerfWhen(
      //   "icacheMissPenalty",
      //   icacheInWhiteList && (icacheState =/= icacheSReadCache) && (icacheState =/= icacheSWait),
      //   exte.debugEbreak
      // )


      val icacheState = BoringUtils.tapAndRead(icache.state)
      val icacheLastState = RegNext(icacheState)
      val icacheInWhiteList = BoringUtils.tapAndRead(icache.inWhiteList)
      val icacheSReadCache = 0.U
      val icacheSReqMem = 1.U
      val icacheSFirstResp = 2.U
      val icacheSFillCache = 3.U
      PerfWhen(
        "icacheTotalAcc",
        RegNext(icache.io.cached.r.ready && !icache.io.cached.abort) && (icacheLastState === icacheSReadCache),
        exte.debugEbreak
      )
      PerfWhen(
        "icacheMiss",
        icacheLastState === icacheSReadCache && icacheState === icacheSReqMem && icacheInWhiteList,
        exte.debugEbreak
      )
      PerfWhen(
        "icacheHit",
        RegNext(icache.io.cached.r.ready && !icache.io.cached.abort) && icacheLastState === icacheSReadCache && icacheState === icacheSReadCache,
        exte.debugEbreak
      )
      PerfWhen(
        "icacheBlackList",
        icacheLastState === icacheSReadCache && icacheState === icacheSReqMem && !icacheInWhiteList,
        exte.debugEbreak
      )
      PerfWhen(
        "icacheMissPenalty",
        icacheInWhiteList && (icacheState =/= icacheSReadCache),
        exte.debugEbreak
      )
      PerfWhen(
        "icacheOutput",
        icache.io.cached.r.fire,
        exte.debugEbreak
      )
    }
  } else {
    // val ifetchAddr = RegInit(cfg.pcInit.U(cfg.xlen.W))
    // when(exte.flush) {
    //   ifetchAddr := exte.jumpTarget
    // }.elsewhen(exte.mem.ar.fire) {
    //   ifetchAddr := Mux(exte.bpu.taken, exte.bpu.target, ifetchAddr + 4.U)
    // }

    exte.mem :<= 0.U.asTypeOf(chiselTypeOf(exte.mem))
    exte.mem.ar.valid := true.B
    // exte.mem.ar.bits.addr := ifetchAddr
    exte.mem.ar.bits.addr := DontCare
    exte.mem.ar.bits.size := "b010".U
    exte.mem.ar.bits.burst := Axi4Burst.incr.U
    exte.mem.r.ready := out.ready

    out.valid := exte.mem.r.valid
    outBits.ifuPayload.ifu.inst := exte.mem.r.bits.data
  
    val pcInitLo = (cfg.pcInit >> cfg.trivialBits) & ((1 << cfg.predTargetWidth) - 1)
    val pcLo = RegInit(pcInitLo.U(cfg.predTargetWidth.W))
    val pc = PcCat(cfg.hasC, exte.pcHi, pcLo)

    when(flush) {
      pcLo := ExtractFrom(flushTarget, cfg.trivialBits, cfg.predTargetWidth)
    }.elsewhen(out.fire) {
      pcLo := pcLo + Mux(outBits.ifuPayload.ifu.isC, (2 >> cfg.trivialBits).U, (4 >> cfg.trivialBits).U)
    }

    exte.bpu.pc := pc

    outBits.ifuPayload.ifu.pcLo := pcLo
    outBits.ifuPayload.ifu.debugPc := pc
    outBits.ifuPayload.ifu.predTaken := exte.bpu.taken
    // outBits.ifuPayload.ifu.predTarget := exte.bpu.target
    outBits.ifuPayload.ifu.predTarget := 
        (if (cfg.hasC) exte.bpu.target(cfg.predTargetWidth - 1 + 1, 1)
        else exte.bpu.target(cfg.predTargetWidth - 1 + 2, 2))
    outBits.ifuPayload.ifu.isC := outBits.ifuPayload.ifu.inst(1, 0) =/= "b11".U
  }

  // debug
  if (cfg.formal) {
    import rvspeccore.checker._
    implicit val XLEN: Int = cfg.xlen
    when(out.valid) {
      val inst = out.bits.ifuPayload.ifu.inst
      assume(
        RVI(inst) ||
        RVZifencei(inst) ||
        {
          val allowCsr = Set(
            // CsrAddr.mcycle,
            // CsrAddr.mcycleh,
            CsrAddr.mepc,
            // CsrAddr.mstatus,
            CsrAddr.mtvec
          )
          RVZicsr(inst) && allowCsr.map(_ === inst(31, 20)).reduce(_ || _)
        } ||
        RVC(inst)
      )
    }
  }

  if (cfg.perf) {
    PerfWhen(
      "waitReadCyc",
      !out.valid && out.ready,
      exte.debugEbreak
    )
    PerfWhen(
      "keepDataCyc",
      out.valid && !out.ready,
      exte.debugEbreak
    )
  }
}
