package sirius

import chisel3._
import chisel3.util._
import chisel3.experimental.dataview._

class BasicCore(
  implicit private val cfg:  CoreConfig,
  implicit private val ucfg: UnitConfig)
    extends Module {
  val io = IO(new Bundle {
    val axiIfu = new Axi4IO
    val axiLsu = new Axi4IO
    val bpu = Option.when(cfg.formal)(new IfuToBpuIO)
  })

  val globalPcHi = Module(new GlobalPcHi)
  val registerFile = Module(new RegisterFile)
  val csr = Module(new Csr)
  val ifu = Module(new Ifu)
  val idu = Module(new Idu)
  val exu = Module(new Exu)
  val lsu = Module(new Lsu)
  val wbu = Module(new Wbu)

  val ifuOut = ifu.out
  val iduOut = idu.out
  val exuOut = exu.out
  val lsuOut = lsu.out

  val globalCtrl = idu.exte.globalCtrl

  io.axiIfu :<>= ifu.exte.mem
  io.axiLsu :<>= lsu.exte.mem
  ifu.exte.pcHi := globalPcHi.io.pcHi
  exu.exte.pcHi := globalPcHi.io.pcHi
  lsu.exte.pcHi := globalPcHi.io.pcHi
  registerFile.iduIn :<>= idu.exte.regFile
  registerFile.wbuIn :<>= wbu.exte.regFlie
  csr.exuIn :<>= exu.exte.csr
  csr.wbuIn :<>= wbu.exte.csr
  val fencei = lsu.in.valid && lsu.in.bits.ctrl.lsuCtrl.isFlushIcache
  ifu.exte.fencei := fencei

  if (!cfg.formal) {
    val bpu = Module(
      new Bpu(
        btbIndexWidth = 3,
        btbTagWidth = 3,
        btbTargetWidth = cfg.predTargetWidth,
        phtIndexWidth = 4,
        phtCounterWidth = 2
      )
    )
    bpu.ifuIn :<>= ifu.exte.bpu
    bpu.lsuIn :<>= lsu.exte.bpu
  } else {
    io.bpu.get :<>= ifu.exte.bpu
  }

  if (cfg.pipeline) {
    val stallIdu = Wire(Bool())
    val stallExu = Wire(Bool())
    val flushIfu = Wire(Bool())
    val flushIdu = Wire(Bool())
    val flushExu = Wire(Bool())
    val iduForwardBits = WireDefault(iduOut.bits)
    // val pipeIfId = PipelineConnect(ifuOut, idu.in, flush = flushIfu)
    // val pipeIdEx = PipelineConnect(iduOut.map(_ => iduForwardBits), exu.in, stall = stallIdu, flush = flushIdu)
    // val pipeExLs = PipelineConnect(exuOut, lsu.in, stall = stallExu, flush = flushExu)
    // val pipeLsWb = PipelineConnect(lsuOut, wbu.in)
    val pipeIfId = PipelineConnectModule(ifuOut, idu.in, flush = flushIfu)
    val pipeIdEx = PipelineConnectModule(iduOut.map(_ => iduForwardBits), exu.in, stall = stallIdu, flush = flushIdu)
    val pipeExLs = PipelineConnectModule(exuOut, lsu.in, stall = stallExu, flush = flushExu)
    val pipeLsWb = PipelineConnectModule(lsuOut, wbu.in)

    // RAW (GPR)
    val readRs1 = globalCtrl.globalCtrl.readRs1
    val rs1 = idu.exte.regFile.rAddr(0)
    val rs1NeedRead = readRs1 && rs1 =/= 0.U 

    val readRs2 = globalCtrl.globalCtrl.readRs2
    val rs2 = idu.exte.regFile.rAddr(1)
    val rs2NeedRead = readRs2 && rs2 =/= 0.U

    // Forward
    // EX
    val exForwardValid = exu.out.valid && (exu.in.bits.ctrl.wbuCtrl.writeBackSel === WriteBackSelEnum.alu.asUInt)
    val exForwardData  = exu.out.bits.exuPayload.exu.aluOut

    // LS
    val lsForwardValid = lsu.in.valid && (lsu.in.bits.ctrl.wbuCtrl.writeBackSel === WriteBackSelEnum.alu.asUInt)
    val lsForwardData  = lsu.in.bits.exuPayload.exu.aluOut

    // WB
    val wbForwardValid = wbu.in.valid && ((wbu.in.bits.ctrl.wbuCtrl.writeBackSel === WriteBackSelEnum.alu.asUInt) || (wbu.in.bits.ctrl.wbuCtrl.writeBackSel === WriteBackSelEnum.lsu.asUInt))
    val wbForwardData  = wbu.in.bits.lsuPayload.lsu.regWData

    val exConflictRs1 = rs1NeedRead && exu.in.valid && exu.in.bits.ctrl.wbuCtrl.isWriteBackReg && (exu.in.bits.iduPayload.idu.wAddr === rs1)
    val lsConflictRs1 = rs1NeedRead && lsu.in.valid && lsu.in.bits.ctrl.wbuCtrl.isWriteBackReg && (lsu.in.bits.exuPayload.idu.wAddr === rs1)
    val wbConflictRs1 = rs1NeedRead && wbu.in.valid && wbu.in.bits.ctrl.wbuCtrl.isWriteBackReg && (wbu.in.bits.lsuPayload.idu.wAddr === rs1)

    val rs1Stall = MuxCase(false.B, Seq(
      exConflictRs1 -> !exForwardValid,
      lsConflictRs1 -> !lsForwardValid,
      wbConflictRs1 -> !wbForwardValid
    ))

    iduForwardBits.iduPayload.idu.rs1Data := MuxCase(iduOut.bits.iduPayload.idu.rs1Data, Seq(
      exConflictRs1 -> exForwardData,
      lsConflictRs1 -> lsForwardData,
      wbConflictRs1 -> wbForwardData
    ))

    val exConflictRs2 = rs2NeedRead && exu.in.valid && exu.in.bits.ctrl.wbuCtrl.isWriteBackReg && (exu.in.bits.iduPayload.idu.wAddr === rs2)
    val lsConflictRs2 = rs2NeedRead && lsu.in.valid && lsu.in.bits.ctrl.wbuCtrl.isWriteBackReg && (lsu.in.bits.exuPayload.idu.wAddr === rs2)
    val wbConflictRs2 = rs2NeedRead && wbu.in.valid && wbu.in.bits.ctrl.wbuCtrl.isWriteBackReg && (wbu.in.bits.lsuPayload.idu.wAddr === rs2)

    val rs2Stall = MuxCase(false.B, Seq(
      exConflictRs2 -> !exForwardValid,
      lsConflictRs2 -> !lsForwardValid,
      wbConflictRs2 -> !wbForwardValid
    ))

    iduForwardBits.iduPayload.idu.rs2Data := MuxCase(iduOut.bits.iduPayload.idu.rs2Data, Seq(
      exConflictRs2 -> exForwardData,
      lsConflictRs2 -> lsForwardData,
      wbConflictRs2 -> wbForwardData
    ))

    val isRawGpr = rs1Stall || rs2Stall

    // RAW (CSR)
    val exuWillReadCsr = exu.in.bits.ctrl.wbuCtrl.isWriteBackCsr
    val exuReadAddr    = exu.in.bits.iduPayload.idu.csrAddr

    val lsCsrWrite = lsu.in.valid && lsu.in.bits.ctrl.wbuCtrl.isWriteBackCsr &&
                     (!lsu.in.bits.ctrl.wbuCtrl.isCsrWriteCheck || lsu.in.bits.exuPayload.idu.immNotZero)

    val wbCsrWrite = wbu.in.valid && wbu.in.bits.ctrl.wbuCtrl.isWriteBackCsr &&
                     (!wbu.in.bits.ctrl.wbuCtrl.isCsrWriteCheck || wbu.in.bits.lsuPayload.idu.immNotZero)

    val rawCsr = exuWillReadCsr && (
      (lsCsrWrite && (lsu.in.bits.exuPayload.idu.csrAddr === exuReadAddr)) ||
      (wbCsrWrite && (wbu.in.bits.lsuPayload.idu.csrAddr === exuReadAddr))
    )

    // Pipeline ctrl
    val jumpTarget = Mux(wbu.exte.pipelineCtrl.isJump, wbu.exte.pipelineCtrl.target, lsu.exte.pipelineCtrl.target)
    globalPcHi.io.wEn := wbu.exte.pipelineCtrl.isJump || lsu.exte.pipelineCtrl.isJump
    globalPcHi.io.wData := jumpTarget.head(cfg.pcHiWidth)
    flushIfu := wbu.exte.pipelineCtrl.isJump || lsu.exte.pipelineCtrl.isJump
    flushIdu := wbu.exte.pipelineCtrl.isJump || lsu.exte.pipelineCtrl.isJump
    flushExu := wbu.exte.pipelineCtrl.isJump
    ifu.exte.jumpTarget := jumpTarget
    ifu.exte.flush := wbu.exte.pipelineCtrl.isJump || lsu.exte.pipelineCtrl.isJump

    stallIdu := isRawGpr
    stallExu := rawCsr || lsu.exte.pipelineCtrl.isJump
    exu.exte.stall := stallExu

    // Debug
    if (cfg.perf) {
      val stopFlag = wbu.in.bits.ctrl.wbuCtrl.isEbreak
      def perfPipeline(
        name:        String,
        thisInValid: Bool,
        nextInValid: Bool,
        nextInReady: Bool,
        cause:       Map[String, Bool] = Map.empty
      ) = {
        // val isStageStall = RegNext(thisInValid) && nextInReady && !nextInValid
        val isStageStall = RegNext(thisInValid) && !nextInValid
        PerfWhen(s"${name}TotalStallCyc", isStageStall, Some(stopFlag))
        cause.foreach { case (condName, cond) =>
          PerfWhen(
            s"${name}${condName}StallCyc",
            isStageStall && cond,
            Some(stopFlag)
          )
        }
      }

      perfPipeline(
        "ifu",
        !reset.asBool,
        idu.in.valid,
        idu.in.ready,
        Map("Flush" -> RegNext(wbu.exte.pipelineCtrl.isJump || lsu.exte.pipelineCtrl.isJump))
      )
      perfPipeline(
        "idu",
        idu.in.valid,
        exu.in.valid,
        exu.in.ready,
        Map(
          "Flush" -> RegNext(wbu.exte.pipelineCtrl.isJump || lsu.exte.pipelineCtrl.isJump),
          "RawGpr" -> (isRawGpr || RegNext(isRawGpr))
        )
      )
      perfPipeline(
        "exu",
        exu.in.valid,
        lsu.in.valid,
        lsu.in.ready,
        Map(
          "Flush" -> RegNext(wbu.exte.pipelineCtrl.isJump || lsu.exte.pipelineCtrl.isJump),
          "RawCsr" -> (rawCsr || RegNext(rawCsr))
          // "MayJump" -> (mayJump || RegNext(mayJump))
        )
      )
      perfPipeline(
        "lsu",
        lsu.in.valid,
        wbu.in.valid,
        wbu.in.ready,
        Map("Flush" -> RegNext(wbu.exte.pipelineCtrl.isJump || lsu.exte.pipelineCtrl.isJump))
      )

      PerfWhen("totalJump", wbu.exte.pipelineCtrl.isJump || lsu.exte.pipelineCtrl.isJump, Some(stopFlag))

      import rvspeccore.checker._
      implicit val XLEN = cfg.xlen
      case class InstTypeCounter(valid: Bool, inst: UInt)
      val instTypeCounters = Seq(
        InstTypeCounter(
          idu.in.valid,
          idu.in.bits.ifuPayload.ifu.inst
        ),
        InstTypeCounter(
          exu.in.valid,
          exu.in.bits.iduPayload.ifu.inst
        ),
        InstTypeCounter(
          lsu.in.valid,
          lsu.in.bits.exuPayload.ifu.inst
        ),
        InstTypeCounter(
          wbu.in.valid,
          wbu.in.bits.lsuPayload.ifu.inst
        )
      )
      val instTypes = Map(
        "IRegImm" -> RVI.regImm,
        "IRegReg" -> RVI.regReg,
        "IControl" -> RVI.control,
        "ILoadStore" -> RVI.loadStore,
        "IOther" -> RVI.other,
        "ZicsrReg" -> RVZicsr.reg,
        "ZicsrImm" -> RVZicsr.imm,
        "Zifencei" -> RVZifencei.fence_i
      )
      instTypes.foreach { case (name, fn) =>
        PerfWhen(
          s"type${name}",
          idu.in.fire && fn.apply(idu.in.bits.ifuPayload.ifu.inst),
          Some(stopFlag)
        )
        PerfWhen(
          s"type${name}Cyc",
          instTypeCounters.map(s => s.valid && fn.apply(s.inst)).reduce(_ || _),
          Some(stopFlag)
        )
      }
    }
  } else {
    ifu.exte.flush := false.B
    idu.in :<>= ifuOut
    exu.in :<>= iduOut
    lsu.in :<>= exuOut
    wbu.in :<>= lsuOut
  }
}

class Top(
  implicit private val cfg:  CoreConfig,
  implicit private val ucfg: UnitConfig)
    extends Module {

  override val desiredName = "ysyx_26010008"
  withModulePrefix(cfg.modulePrefix.getOrElse("")) {

    val basicCore = Module(new BasicCore)
    // val xbar = Module(
    //   new Xbar(
    //     2,
    //     2,
    //     Seq(
    //       addr => addr < "h02000000".U || addr >= "h02010000".U,
    //       addr => addr >= "h02000000".U && addr < "h02010000".U
    //     )
    //   )
    // )
    val xbar = Module(new SimpleXbar)
    val clintDevice = Module(new ClintDevice)

    xbar.io.in(0) :<>= basicCore.io.axiLsu
    xbar.io.in(1) :<>= basicCore.io.axiIfu
    clintDevice.in :<>= xbar.io.out(1)

    if (cfg.ysyxsoc) {
      val io = IO(new Bundle {
        val interrupt = Input(Bool())
        val master = new Axi4FlatIO
        val slave = Flipped(new Axi4FlatIO)
      })
      0.U.asTypeOf(chiselTypeOf(io.slave)) :>= io.slave
      io.master :<>= xbar.io.out(0).viewAs[Axi4FlatIO]
    } else if (cfg.isDebug) {
      val memDpiC = Module(new MemDpiC)
      val axi4BurstSpliter = Module(new Axi4BurstSpliter)
      axi4BurstSpliter.io.in :<>= xbar.io.out(0)
      memDpiC.axi :<>= axi4BurstSpliter.io.out.viewAs[Axi4FlatIO]
      memDpiC.clock := clock
      memDpiC.reset := reset
    }

    if (cfg.isDebug) {
      import chisel3.util.experimental.BoringUtils._
      val ebreaks = Seq(
        basicCore.ifu.exte.debugEbreak,
        basicCore.idu.exte.debugEbreak,
        basicCore.exu.exte.debugEbreak,
        basicCore.lsu.exte.debugEbreak,
        basicCore.wbu.exte.debugEbreak
      )
      val wbuIn = tapAndRead(basicCore.wbu.in)
      val ebreakSignal = wbuIn.bits.ctrl.wbuCtrl.isEbreak
      ebreaks.foreach { e => drive(e.get) := ebreakSignal }

      val debugInfoDpiC = Module(new DebugInfoDpiC)
      val getGprDpiC = Module(new GetGprDpiC)
      debugInfoDpiC.isEbreak := ebreakSignal
      debugInfoDpiC.pc := wbuIn.bits.lsuPayload.ifu.debugPc
      // debugInfoDpiC.pcRaw := tapAndRead(basicCore.pcReg.debug.get.pc)
      debugInfoDpiC.pcRaw := cfg.pcInit.U
      // debugInfoDpiC.dnpc := pcReg.debug.get.dnpc
      debugInfoDpiC.inst := wbuIn.bits.lsuPayload.ifu.inst
      debugInfoDpiC.wbuValid := tapAndRead(basicCore.wbu.debug.get.valid)
      debugInfoDpiC.isJump := tapAndRead(basicCore.wbu.debug.get.isJump)
      debugInfoDpiC.jumpTarget := tapAndRead(basicCore.wbu.debug.get.jumpTarget)
      getGprDpiC.gpr := tapAndRead(basicCore.registerFile.debug.get)
    }
  }
}
