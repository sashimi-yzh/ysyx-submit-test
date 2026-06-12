package sirius

import chisel3._
import chisel3.util._
import chisel3.experimental.dataview._

class Lsu(
  implicit private val cfg: CoreConfig)
    extends Module {
  if (cfg.xlen != 32) {
    throw new IllegalArgumentException("Unsupported xlen")
  }

  val exte = IO(new Bundle {
    val pcHi = Input(UInt(cfg.pcHiWidth.W))
    val mem = new Axi4IO
    val pipelineCtrl = new PipelineCtrlIO
    val bpu = new LsuToBpuIO
    val debugEbreak = Option.when(cfg.isDebug)(Input(Bool()))
  })
  val in = IO(Flipped(Decoupled(new ExuToLsuIO)))
  val out = IO(Decoupled(new LsuToWbuIO))

  val willJump = out.bits.ctrl.wbuCtrl.isJumpCsr || out.bits.lsuPayload.trap.isTrap
  val waitFlushFinish = RegNext(out.fire && willJump)
  val inValid = in.valid && !waitFlushFinish

  val inBits = in.bits
  val outBits = out.bits
  val ctrl = inBits.ctrl.lsuCtrl
  val addr = inBits.exuPayload.exu.aluOut
  val isMemAcc = ctrl.isLoad || ctrl.isStore
  val rData = exte.mem.r.bits.data
  val rem = addr(1, 0)
  val inTrap = inValid && inBits.exuPayload.trap.isTrap
  val pc = PcCat(cfg.hasC, exte.pcHi, inBits.exuPayload.ifu.pcLo)

  // 数据透传
  outBits.lsuPayload.viewAsSupertype(new ExuPayload) := inBits.exuPayload
  outBits.ctrl := inBits.ctrl.viewAsSupertype(new WbuCtrl)

  // Jump control
  val realTaken =
    inBits.ctrl.wbuCtrl.isJump || (inBits.ctrl.wbuCtrl.isBranch && inBits.exuPayload.exu.aluOut(0))
  val realTarget = inBits.exuPayload.exu.jumpTarget
  val predDirectionErr = inBits.exuPayload.ifu.predTaken =/= realTaken
  val predTargetErr = realTaken && inBits.exuPayload.exu.predTargetMayErr
  val predErr = predDirectionErr || predTargetErr
  val staticNextPc = pc + Mux(inBits.exuPayload.ifu.isC, 2.U, 4.U)
  // val staticNextPc = Mux(inBits.exuPayload.ifu.isC, inBits.exuPayload.ifu.pc + 2.U, inBits.exuPayload.ifu.pc + 4.U)
  val dynamicNextPc = Mux(realTaken, realTarget, staticNextPc)
  // val newIn = inValid && (RegNext(!inValid) || RegNext(in.fire))
  val newIn = inValid && (RegNext(!inValid || in.fire))
  val pcLo = inBits.exuPayload.ifu.pcLo
  val pcLoOverflow = pcLo(pcLo.getWidth - 1, 1).andR && Mux(inBits.exuPayload.ifu.isC, pcLo(0), true.B)
  exte.pipelineCtrl.isJump := newIn && (predErr || ctrl.isFlushIcache || pcLoOverflow)
  exte.pipelineCtrl.target := dynamicNextPc
  if (cfg.isDebug) {
  val debug = outBits.debug.get
    debug.isJump := realTaken
    debug.jumpTarget := realTarget
  }

  // Bpu
  exte.bpu.update := newIn
  exte.bpu.pc := pc
  exte.bpu.isCtrlInst := inBits.ctrl.wbuCtrl.isJump || inBits.ctrl.wbuCtrl.isBranch
  exte.bpu.predTaken := inBits.exuPayload.ifu.predTaken
  exte.bpu.realTaken := realTaken
  exte.bpu.target := realTarget

  exte.mem :<= 0.U.asTypeOf(chiselTypeOf(exte.mem))
  exte.mem.w.bits.last := true.B

  // 异常
  val eLoadStoreAddressMisaligned = isMemAcc &&
    ((ctrl.loadStoreLength === LoadStoreLengthEnum.h.asUInt && addr(0) =/= 0.U) ||
      (ctrl.loadStoreLength === LoadStoreLengthEnum.w.asUInt && rem =/= 0.U))
  val eLoadAddressMisaligned = ctrl.isLoad && eLoadStoreAddressMisaligned
  val eStoreAddressMisaligned = ctrl.isStore && eLoadStoreAddressMisaligned
  // val eLoadAccessFault = ctrl.isLoad &&
  //   !(exte.mem.r.bits.resp === Axi4Resp.okay.U || exte.mem.r.bits.resp === Axi4Resp.exokay.U)
  // val eStoreAccessFault = ctrl.isStore &&
  //   !(exte.mem.b.bits.resp === Axi4Resp.okay.U || exte.mem.b.bits.resp === Axi4Resp.exokay.U)
  val eLoadAccessFault = ctrl.isLoad && (exte.mem.r.bits.resp =/= Axi4Resp.okay.U)
  val eStoreAccessFault = ctrl.isStore && (exte.mem.b.bits.resp =/= Axi4Resp.okay.U)

  val eCause = MuxCase(
    0.U,
    Seq(
      eStoreAccessFault -> McauseEnum.StoreOrAmoAccessFault.U,
      eLoadAccessFault -> McauseEnum.LoadAccessFault.U,
      eStoreAddressMisaligned -> McauseEnum.StoreOrAmoAddressMisaligned.U,
      eLoadAddressMisaligned -> McauseEnum.LoadAddressMisaligned.U
    )
  )

  when(!inBits.exuPayload.trap.isTrap) {
    outBits.lsuPayload.trap.isTrap := eLoadStoreAddressMisaligned || eLoadAccessFault || eStoreAccessFault
    outBits.lsuPayload.trap.cause := eCause
  }

  val axiCanValid = inValid && isMemAcc && !inTrap && !eLoadStoreAddressMisaligned

  // FSM
  val sIdle :: sWaitAddrReady :: sWaitDataReady :: sWaitResp :: Nil = Enum(4)
  val state = RegInit(sIdle)

  // state := MuxLookup(state, sIdle)(
  //   Seq(
  //     sIdle -> Mux(
  //       axiCanValid,
  //       MuxCase(
  //         sIdle,
  //         Seq(
  //           (exte.mem.ar.ready && ctrl.isLoad) -> sWaitResp,
  //           (exte.mem.aw.ready && exte.mem.w.ready && ctrl.isStore) -> sWaitResp,
  //           (exte.mem.aw.ready && ctrl.isStore) -> sWaitDataReady,
  //           (exte.mem.w.ready && ctrl.isStore) -> sWaitAddrReady
  //         )
  //       ),
  //       sIdle
  //     ),
  //     sWaitAddrReady -> Mux(exte.mem.aw.ready, sWaitResp, sWaitAddrReady),
  //     sWaitDataReady -> Mux(exte.mem.w.ready, sWaitResp, sWaitDataReady),
  //     sWaitResp -> Mux(out.fire, sIdle, sWaitResp)
  //   )
  // )
  switch(state) {
    is(sIdle) {
      when(axiCanValid) {
        when(exte.mem.ar.ready && ctrl.isLoad) {state := sWaitResp}
        .elsewhen(exte.mem.aw.ready && exte.mem.w.ready && ctrl.isStore) {state := sWaitResp}
        .elsewhen(exte.mem.aw.ready && ctrl.isStore) {sWaitDataReady}
        .elsewhen(exte.mem.w.ready && ctrl.isStore) {sWaitAddrReady}
      }
    }
    is(sWaitAddrReady) {
      when(exte.mem.aw.ready) {state := sWaitResp}
    }
    is(sWaitDataReady) {
      when(exte.mem.w.ready) {state := sWaitResp}
    }
    is(sWaitResp) {
      when(out.fire) {state := sIdle}
    }
  }

  // Handshake
  val isBypass = inValid && !axiCanValid
  // val rValid = ctrl.isLoad && exte.mem.r.valid
  // val bValid = ctrl.isStore && exte.mem.b.valid
  val rValid = exte.mem.r.valid
  val bValid = exte.mem.b.valid
  val isMemDone = state === sWaitResp && (rValid || bValid)

  out.valid := isBypass || isMemDone
  in.ready := out.fire

  // Mem
  val axiRespCanReady = state === sWaitResp && out.ready
  exte.mem.r.ready := axiRespCanReady && ctrl.isLoad
  exte.mem.b.ready := axiRespCanReady && ctrl.isStore

  exte.mem.ar.bits.addr := addr
  exte.mem.aw.bits.addr := addr

  exte.mem.ar.valid := axiCanValid && state === sIdle && ctrl.isLoad
  exte.mem.aw.valid := axiCanValid &&
    (state === sIdle || state === sWaitAddrReady) && ctrl.isStore
  exte.mem.w.valid := axiCanValid &&
    (state === sIdle || state === sWaitDataReady) && ctrl.isStore

  val axSize = MuxLookup(ctrl.loadStoreLength, "b010".U)(
    Seq(
      LoadStoreLengthEnum.w.asUInt -> "b010".U,
      LoadStoreLengthEnum.h.asUInt -> "b001".U,
      LoadStoreLengthEnum.b.asUInt -> "b000".U
    )
  )
  exte.mem.ar.bits.size := axSize
  exte.mem.aw.bits.size := axSize

  // Load data
  val lbRaw = MuxLookup(rem, rData(7, 0))(Seq(
    0.U -> rData(7, 0),
    1.U -> rData(15, 8),
    2.U -> rData(23, 16),
    3.U -> rData(31, 24)
  ))
  val lbData = Mux(ctrl.isUnsignedLoad, ZeroExt(lbRaw, cfg.xlen), SignExt(lbRaw, cfg.xlen))

  val lhRaw = Mux(rem(1), rData(31, 16), rData(15, 0))
  val lhData = Mux(ctrl.isUnsignedLoad, ZeroExt(lhRaw, cfg.xlen), SignExt(lhRaw, cfg.xlen))

  val lwData = rData

  val loadData = MuxLookup(ctrl.loadStoreLength, lwData)(
    Seq(
      LoadStoreLengthEnum.w.asUInt -> lwData,
      LoadStoreLengthEnum.h.asUInt -> lhData,
      LoadStoreLengthEnum.b.asUInt -> lbData
    )
  )

  // Store data
  val regData = inBits.exuPayload.idu.rs2Data
  val sb = MuxLookup(rem, regData(7, 0))(Seq(
    0.U -> regData(7, 0),
    1.U -> regData(7, 0) ## 0.U(8.W),
    2.U -> regData(7, 0) ## 0.U(16.W),
    3.U -> regData(7, 0) ## 0.U(24.W),
  )).pad(cfg.xlen)
  val sh = Mux(rem(1), regData(15, 0) ## 0.U(16.W), regData(15, 0)).pad(cfg.xlen)
  val sw = regData(31, 0).pad(cfg.xlen)

  exte.mem.w.bits.data := MuxLookup(ctrl.loadStoreLength, sw)(
    Seq(
      LoadStoreLengthEnum.w.asUInt -> sw,
      LoadStoreLengthEnum.h.asUInt -> sh,
      LoadStoreLengthEnum.b.asUInt -> sb
    )
  )

  val sbMask = (1.U << rem).pad(cfg.xlen)
  val shMask = (3.U << (rem & 2.U)).pad(cfg.xlen)
  val swMask = 15.U(cfg.xlen.W)

  exte.mem.w.bits.strb := MuxLookup(ctrl.loadStoreLength, swMask)(
    Seq(
      LoadStoreLengthEnum.w.asUInt -> swMask,
      LoadStoreLengthEnum.h.asUInt -> shMask,
      LoadStoreLengthEnum.b.asUInt -> sbMask
    )
  )

  // Output
  outBits.lsuPayload.lsu.regWData := Mux(outBits.lsuPayload.trap.isTrap, pc,
    MuxLookup(inBits.ctrl.wbuCtrl.writeBackSel, inBits.exuPayload.exu.aluOut)(Seq(
      WriteBackSelEnum.lsu.asUInt -> loadData,
      WriteBackSelEnum.staticNextPc.asUInt -> staticNextPc
    )))

  // Debug
  if (cfg.formal) {
    when(inValid) {
      assume(!eLoadStoreAddressMisaligned)
      when(exte.mem.r.valid) {
        assume(exte.mem.r.bits.resp === Axi4Resp.okay.U)
      }
      when(exte.mem.b.valid) {
        assume(exte.mem.b.bits.resp === Axi4Resp.okay.U)
      }
    }

    val formalSig = out.bits.lsuPayload.lsu.formal.get
    val width = (1.U << axSize) * 8.U

    implicit val XLEN: Int = cfg.xlen
    val loadQueue = Module(new Queue(new rvspeccore.checker.StoreOrLoadInfo, 1, true, true))
    loadQueue.io.enq.valid := exte.mem.r.fire
    loadQueue.io.enq.bits.addr := addr
    loadQueue.io.enq.bits.data := exte.mem.r.bits.data
    loadQueue.io.enq.bits.memWidth := width

    val storeQueue = Module(new Queue(new rvspeccore.checker.StoreOrLoadInfo, 1, true, true))
    storeQueue.io.enq.valid := exte.mem.w.fire
    storeQueue.io.enq.bits.addr := addr
    storeQueue.io.enq.bits.data := regData
    storeQueue.io.enq.bits.memWidth := width

    formalSig.read.addr := loadQueue.io.deq.bits.addr
    formalSig.read.data := loadQueue.io.deq.bits.data
    formalSig.read.memWidth := loadQueue.io.deq.bits.memWidth
    formalSig.read.valid := loadQueue.io.deq.valid
    loadQueue.io.deq.ready := out.fire && loadQueue.io.deq.valid

    formalSig.write.addr := storeQueue.io.deq.bits.addr
    formalSig.write.data := storeQueue.io.deq.bits.data
    formalSig.write.memWidth := storeQueue.io.deq.bits.memWidth
    formalSig.write.valid := storeQueue.io.deq.valid
    storeQueue.io.deq.ready := out.fire && storeQueue.io.deq.valid
  }

  PerfWhen(
    "memoryRead",
    exte.mem.r.fire,
    exte.debugEbreak
  )
  PerfWhen(
    "waitRead",
    inValid && ctrl.isLoad && !outBits.lsuPayload.trap.isTrap,
    exte.debugEbreak
  )
  PerfWhen(
    "memoryWrite",
    exte.mem.b.fire,
    exte.debugEbreak
  )
  PerfWhen(
    "waitWrite",
    inValid && ctrl.isStore && !outBits.lsuPayload.trap.isTrap,
    exte.debugEbreak
  )
  PerfWhen(
    "bpuTotalReq",
    newIn,
    exte.debugEbreak
  )
  PerfWhen(
    "bpuTotalErr",
    newIn && predErr,
    exte.debugEbreak
  )
  PerfWhen(
    "bpuTotalDirectionErr",
    newIn && predDirectionErr,
    exte.debugEbreak
  )
  PerfWhen(
    "bpuTotalTargetErr",
    newIn && !predDirectionErr && predTargetErr,
    exte.debugEbreak
  )
  PerfWhen(
    "bpuCtrlInstReq",
    newIn && exte.bpu.isCtrlInst,
    exte.debugEbreak
  )
  PerfWhen(
    "bpuCtrlInstErr",
    newIn && exte.bpu.isCtrlInst && predErr,
    exte.debugEbreak
  )
  PerfWhen(
    "bpuCtrlInstDirectionErr",
    newIn && exte.bpu.isCtrlInst && predDirectionErr,
    exte.debugEbreak
  )
  PerfWhen(
    "bpuCtrlInstTargetErr",
    newIn && exte.bpu.isCtrlInst && !predDirectionErr && predTargetErr,
    exte.debugEbreak
  )

}
