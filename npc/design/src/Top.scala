package top

import chisel3._

import regfile._

import cpu._

import chisel3.util.circt.dpi._
import chisel3.util._

import axi4._
import uart._
import clint._
import xbar._

import icache._
import common_def._

import btb._
import branchpredictor._

import config._

import dpiwrap.DifftestLayer

class TopIO extends Bundle {
  val interrupt = Input(Bool())
  val master    = AXI4IO.Master
  val slave     = AXI4IO.Slave
}

class CPUCoreAsBlackBox    extends BlackBox {
  override def desiredName: String = "ysyx_25100261"
  // force chisel to generate the signals name with the same prefix `io`
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val reset = Input(Bool())
    val io    = new TopIO
  })
}
class PCProviderAsBlackBox extends BlackBox {
  override def desiredName: String = "ysyx_25100261_ResetPCProvider"
  val io = IO(new Bundle {
    val resetPC = Output(Types.UWord)
  })
}

class ysyx_25100261(parm:CPUParameters) extends Module {
  val io = IO(new TopIO)
  implicit val p: CPUParameters = parm

  dontTouch(io)
  println(s"Add module prefix ${getClass.getSimpleName}")
  withModulePrefix(getClass.getSimpleName) {
    val core = Module(new CPUCore)
    core.io <> io
  }
}

class ysyx_25100261_ResetPCProvider extends BlackBox with HasBlackBoxInline {
  val io      = IO(new Bundle {
    val resetPC = Output(Types.UWord)
  })
  val pcMacro = name + "_RESET_PC"
  setInline(
    s"${name}.v",
    s"""
       |`ifndef ${pcMacro}
       |  `define ${pcMacro} 32'h80000000
       |`endif
       |module ${name}(
       |  output [31:0] resetPC
       |);
       |  assign resetPC = `$pcMacro;
       |endmodule
     """.stripMargin
  )
}

class CPUCore(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new TopIO)
  dontTouch(io)
  io := DontCare

  // withModulePrefix(getClass.getSimpleName) {

  val isBranchGuessWrong = Wire(Bool())

  val isFlushIDUReg     = RegInit(false.B)
  val needFlushPipeline = Wire(Bool())

  val gprs = Module(new RegisterFile(READ_PORTS = 2))
  val csrs = Module(new ControlStatusRegisterFile())

  val ifu = Module(new IFU)
  val idu = Module(new IDU)
  val exu = Module(new EXU)
  val lsu = Module(new LSU)
  val wbu = Module(new WBU)

  lsu.io.mcycle64 := csrs.io.mcycle64

  // val resetPCProvider = Module(new ysyx_25100261_ResetPCProvider)
  // val INIT_PC         = resetPCProvider.io.resetPC
  val INIT_PC = p.resetVector

  // val pc             = RegInit(INIT_PC)
  val pcReg = RegInit(INIT_PC(31,2).asTypeOf(new AlignedPC))

  val nxtPredictedPC = Wire(Types.UWord)
  dontTouch(nxtPredictedPC)

  if (Config.useBTBAndBP) {
    val btb = Module(new BranchTargetBuffer)
    val bp  = Module(new BranchPredictor)
    btb.io.query.addr   := pcReg.get
    bp.io.pc            := pcReg.get
    bp.io.historyHit    := btb.io.query.hit
    bp.io.historyTarget := btb.io.query.target
    bp.io.historyIsJAL  := btb.io.query.isJAL

    btb.io.update.en     := exu.io.out.valid && exu.io.jmpHappen
    btb.io.update.addr   := exu.io.pc
    btb.io.update.target := exu.io.nxtPC
    btb.io.update.isJAL  := exu.io.isJAL

    nxtPredictedPC := bp.io.predictTarget
  } else {
    nxtPredictedPC := pcReg.get + 4.U
    // val isBranch = ifu.io.out.bits.code(6, 0) === "b1100011".U
    // val immSign  = ifu.io.out.bits.code(31)
    // val imm      = Cat(
    //   Fill(20, immSign),
    //   ifu.io.out.bits.code(7),
    //   ifu.io.out.bits.code(30, 25),
    //   ifu.io.out.bits.code(11, 8),
    //   0.U(1.W)
    // )
    // nxtPredictedPC := ifu.io.out. + Mux(
    //   isBranch && immSign,
    //   imm,
    //   4.U
    // )
  }

  ifu.io.predictedNextPC := nxtPredictedPC

  val isBranchGuessWrongReg = RegInit(false.B)
  val isIFUAckCorrectTarget = Wire(Bool())
  isBranchGuessWrong := isBranchGuessWrongReg || (exu.io.out.valid && exu.io.predWrong)
  when(exu.io.out.valid) {
    isBranchGuessWrongReg := exu.io.predWrong
  }.elsewhen(isIFUAckCorrectTarget) {
    isBranchGuessWrongReg := false.B
  }

  dontTouch(isBranchGuessWrong)
  val curCorrectJmpTarget = RegEnableReadNew(
    exu.io.nxtPC,
    exu.io.out.valid
  )

  // NOTICE: for IFU
  // must wait until IFU accepts the jump target (pc fire) can not
  // just check the valid, sometimes IFU still fetching old wrong
  // target, if think it meets the correct target, then the wrong
  // target will be passed to IDU since that time isWrongPred is unset.
  isIFUAckCorrectTarget := ifu.io.pc.fire && (ifu.io.pc.bits === curCorrectJmpTarget)

  val isIDUMeetCorrectJmpTarget = Wire(Bool())
  isIDUMeetCorrectJmpTarget := ifu.io.out.valid && (ifu.io.out.bits.pc.get === curCorrectJmpTarget)
  dontTouch(isIFUAckCorrectTarget)
  dontTouch(isIDUMeetCorrectJmpTarget)
  dontTouch(curCorrectJmpTarget)

  when(isBranchGuessWrong && (!isIFUAckCorrectTarget)) {
    isFlushIDUReg := true.B
  }.elsewhen(isIDUMeetCorrectJmpTarget) {
    isFlushIDUReg := false.B
  }

  needFlushPipeline := (isFlushIDUReg) || isBranchGuessWrong
  dontTouch(needFlushPipeline)

  pcReg.pc30b := Mux(
    ifu.io.pc.ready,
    // Sometimes although jump,
    // target is near current pc and IFU just meets it
    Mux(isBranchGuessWrong && (!isIFUAckCorrectTarget), curCorrectJmpTarget(31,2), nxtPredictedPC(31,2)),
    pcReg.pc30b
  )

  val memArbiter = Module(new EXUIFU_MemVisitArbiter)
  AXI4IO.connectMasterSlave(lsu.io.mem, memArbiter.io.exu)

  val icache = Module(new ICache)
  icache.io.flush := exu.io.fencei
  AXI4IO.connectMasterSlave(ifu.io.mem, icache.io.cpu)
  AXI4IO.connectMasterSlave(icache.io.mem, memArbiter.io.ifu)

  // AXI4IO.connectMasterSlave(ifu.io.mem, memArbiter.io.ifu)

  // val clint = Module(new CLINTUnit)
  //
  // val otherReqSlave = Wire(AXI4IO.Slave)
  // AXI4IO.transformSlaveToMasterValidIf(!reset.asBool)(io.master, otherReqSlave)
  // val memXBar       = Module(
  //   new AXI4LiteXBar(
  //     Seq(
  //       AddrSpace.CLINT -> clint.io,
  //       AddrSpace.SOC   -> otherReqSlave
  //     )
  //   )
  // )

  // AXI4IO.connectMasterSlave(memArbiter.io.out, memXBar.io.in)
  // memXBar.connect()

  memArbiter.io.out <> io.master

  when(io.master.bvalid && io.master.bresp === AXI4IO.BResp.DECERR) {
    printf("AXI4 DECERR on write address 0x%x\n", io.master.awaddr)
    stop()
    stop()
  }
  when(io.master.rvalid && io.master.rresp === AXI4IO.RResp.DECERR) {
    printf("AXI4 DECERR on read address 0x%x\n", io.master.araddr)
    stop()
    stop()
  }

  ifu.io.pc.bits  := pcReg.get
  ifu.io.pc.valid := true.B

  layer.block(DifftestLayer) {
    val iduOut = Wire(Decoupled(new DecodedInst))
    iduOut.valid := idu.io.out.valid
    iduOut.bits  := idu.io.out.bits

    val exuDifftest = Module(new EXUForDifftest)
    exuDifftest.io.actual.inReady  := exu.io.in.ready
    exuDifftest.io.actual.pc       := exu.io.pc
    exuDifftest.io.actual.nxtPC    := exu.io.nxtPC
    exuDifftest.io.actual.memAddr  := exu.io.out.bits.destAddr
    exuDifftest.io.actual.outValid := exu.io.out.valid
    pipelineConnect(iduOut, exuDifftest.io.in, exuDifftest.io.out)

    val lsuDifftest = Module(new LSUForDifftest)
    pipelineConnect(exuDifftest.io.out, lsuDifftest.io.in, lsuDifftest.io.out)
    lsuDifftest.io.actualLSU.inReady  := lsu.io.in.ready
    lsuDifftest.io.actualLSU.outValid := lsu.io.out.valid

    val wbuDifftest = Module(new WBUForDifftest)
    pipelineConnect(lsuDifftest.io.out, wbuDifftest.io.in)
  }

  pipelineConnect(ifu.io.out, idu.io.in, idu.io.out)
  pipelineConnect(idu.io.out, exu.io.in, exu.io.out)
  pipelineConnect(exu.io.out, lsu.io.in, lsu.io.out)

  idu.io.rvec <> gprs.io.read
  exu.io.csr_rvec <> csrs.io.read

  // idu.io.wrBackInfo.exus1 := exu.io.fwd1
  // idu.io.wrBackInfo.exus2 := exu.io.fwd2
  idu.io.wrBackInfo.exu   := exu.io.fwd
  idu.io.wrBackInfo.lsu   := ExtractFwdInfoFromLSU(lsu.io.in)
  idu.io.wrBackInfo.wbu   := ExtractFwdInfoFromWrBack(wbu.io.in)

  val exuWrBackDataVaild = !(exu.io.out.bits.isLoad || exu.io.out.bits.isStore)

  idu.io.flush  := needFlushPipeline
  exu.io.flush1 := needFlushPipeline

  // Write back

  val foo = Wire(Decoupled(Bool()))
  foo       := DontCare
  foo.ready := true.B
  foo.valid := true.B
  pipelineConnect(lsu.io.out, wbu.io.in, foo)

  // wbu.io.in <> exu.io.out
  gprs.io.write <> wbu.io.gpr
  csrs.io.write <> wbu.io.csr
  csrs.io.is_ecall := wbu.io.is_ecall

  // }
}
