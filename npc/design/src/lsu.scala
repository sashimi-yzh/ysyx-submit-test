package cpu
import chisel3._
import chisel3.util._
import common_def._
import busfsm._

import chisel3.util.circt.dpi._
import axi4._

import dpiwrap._
import dpiwrap.ClockedCallVoidDPIC

class LSUInput(
  implicit p: CPUParameters)
    extends Bundle {
  val isLoad       = Bool()
  val isStore      = Bool()
  val destAddr     = Types.UWord
  val storeData    = Types.UWord
  val func3t       = UInt(3.W)
  val exuWriteBack = new WriteBackInfo
}

object ExtractFwdInfoFromLSU {
  def apply(
    info:       DecoupledIO[LSUInput]
  )(
    implicit p: CPUParameters
  ): WrBackForwardInfo = {
    val wrBack = info.bits.exuWriteBack

    val out = Wire(new WrBackForwardInfo)
    out.addr      := wrBack.gpr.addr
    out.enWr      := wrBack.gpr.en && info.valid
    out.dataVaild := false.B
    out.data      := DontCare
    out
  }
}

// object ExtractGPRInfoFromLSU {
//   def apply(info: DecoupledIO[LSUInput]): GPRegReqIO._WriteRX = {
//     val gprInfo = info.bits.exuWriteBack.gpr
//     val valid   = info.valid
//
//     val out = Wire(GPRegReqIO.RX.Write)
//     out.en   := gprInfo.en && valid
//     out.addr := gprInfo.addr
//     out.data := gprInfo.data
//     out
//   }
// }

class LSUIO(
  implicit p: CPUParameters)
    extends Bundle {
  val mem = AXI4IO.Master

  val mcycle64 = Input(UInt(64.W))

  val in  = Flipped(Decoupled(new LSUInput))
  val out = Decoupled(new WriteBackInfo)
}

class LSU(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new LSUIO)

  object State extends ChiselEnum {
    val idle, waitAR, waitAW, waitR, waitW, waitB, waitOut = Value
  }
  val state = RegInit(State.idle)
  val isIdle    = state === State.idle
  val isWaitAR  = state === State.waitAR
  val isWaitAW  = state === State.waitAW
  val isWaitR   = state === State.waitR
  val isWaitW   = state === State.waitW
  val isWaitB   = state === State.waitB
  val isWaitOut = state === State.waitOut

  val outWriteBackInfo = io.out.bits

  // val inReg = RegEnable(io.in.bits, io.in.fire)
  // val inReg = RegEnableReadNew(io.in.bits, io.in.fire)

  val in                 = io.in.bits
  val inExuWriteBackInfo = in.exuWriteBack

  // val memRdRawData = Reg(Types.UWord)
  val memRdRawData = Wire(Types.UWord)
  memRdRawData := io.mem.rdata

  val isLoadOp    = in.isLoad && io.in.valid
  // only compare high 8 bit since clint addr is 0x0200_0048/4c, 0x02 is unique in whole addr space
  val isCLINTAddr = in.destAddr(31, 27) === AddrSpace.CLINT._1(31, 27)
  val isMemLoad   = isLoadOp && (!isCLINTAddr)
  val isStore     = in.isStore && io.in.valid

  val isMemOp = isMemLoad || isStore

  // Lo: 0x20000048 -> 08 -> 0b1000
  // Hi: 0x2000004c -> 12 -> 0b1100
  val clintRdData = Mux(in.destAddr(2), io.mcycle64(63, 32), io.mcycle64(31, 0))

  val memIO = io.mem
  io.out.valid := io.in.valid && ((!isMemOp) || isWaitOut || ((isWaitB | isWaitW) && memIO.bvalid) || ((isWaitR | isIdle) && memIO.rvalid))
  io.in.ready  := ((!isMemOp) || (isWaitOut) || ((isWaitW | isWaitB) && memIO.bvalid) || ((isWaitR | isIdle) && memIO.rvalid)) && io.out.ready

  val addrAck = Mux(isMemLoad, io.mem.arready, io.mem.awready)

  val nxtStateWhenIdleMeetMemOp = Mux(isMemLoad, State.waitAR, State.waitAW)

  val nxtStateWhenWaitOut = Mux(io.out.ready, State.idle, State.waitOut)
  val nxtStateWhenWaitB   = Mux(memIO.bvalid && memIO.bready, nxtStateWhenWaitOut, State.waitB)

  val nxtStateWhenWaitR = Mux(memIO.rvalid && memIO.rready, nxtStateWhenWaitOut, State.waitR)
  val nxtStateWhenWaitW = Mux(memIO.wvalid && memIO.wready, nxtStateWhenWaitB, State.waitW)

  val nxtStateWhenAddrAck = Mux(isMemLoad, nxtStateWhenWaitR, nxtStateWhenWaitW)

  state := MuxLookup(state, State.idle)(
    Seq(
      State.idle    -> Mux(
        isMemOp,
        Mux(addrAck, nxtStateWhenAddrAck, nxtStateWhenIdleMeetMemOp),
        State.idle
      ),
      State.waitAR  -> Mux(addrAck, nxtStateWhenWaitR, State.waitAR),
      State.waitAW  -> Mux(addrAck, nxtStateWhenWaitW, State.waitAW),
      State.waitR   -> nxtStateWhenWaitR,
      State.waitW   -> nxtStateWhenWaitW,
      State.waitB   -> nxtStateWhenWaitB,
      State.waitOut -> nxtStateWhenWaitOut
    )
  )

  val memAddr            = in.destAddr
  val func3t             = in.func3t
  val storeData          = in.storeData
  val memAddrUnalignPart = memAddr(1, 0)
  // val memAddrUnalignPartBitlen = memAddrUnalignPart << 3

  memIO.araddr  := memAddr
  memIO.arvalid := isMemLoad && (isIdle || isWaitAR)

  // val memOpSize = MuxLookup(func3t, 0.U)(
  //   Seq(
  //     MemOp.byte     -> 0.U,
  //     MemOp.halfword -> 1.U,
  //     MemOp.word     -> 2.U,
  //     MemOp.lbu      -> 0.U,
  //     MemOp.lhu      -> 1.U
  //   )
  // )
  val memOpSize = func3t(1, 0)

  val memOpIsWord = func3t(1)
  val memOpIsHalf = (~func3t(1)) && func3t(0)
  val memOpIsByte = (~func3t(1)) && (~func3t(0))

  memIO.arid    := 0.U
  memIO.arlen   := 0.U
  memIO.arsize  := memOpSize
  memIO.arburst := 1.U

  // val memRdData = memRdRawData >> memAddrUnalignPartBitlen
  val memRdData = MuxLookup(memAddrUnalignPart, 0.U(8.W))(
    Seq(
      0.U -> memRdRawData,
      1.U -> memRdRawData(31, 8).pad(32),
      2.U -> memRdRawData(31, 16).pad(32),
      3.U -> memRdRawData(31, 24).pad(32)
    )
  )
  // val memRdData = memRdRawData

  val memRdDataByte = Cat(Fill(24, memRdData(7) && (~func3t(2))), memRdData(7, 0))
  val memRdDataHalf = Cat(Fill(16, memRdData(15) && (~func3t(2))), memRdData(15, 0))
  val loadResult    = Mux(func3t(1), memRdData, Mux(func3t(0), memRdDataHalf, memRdDataByte))

  // val loadResult = MuxLookup(func3t, GARBAGE_UNINIT_VALUE)(
  //   Seq(
  //     MemOp.byte     -> Cat(Fill(24, memRdData(7)), memRdData(7, 0)),
  //     MemOp.halfword -> Cat(Fill(16, memRdData(15)), memRdData(15, 0)),
  //     MemOp.word     -> memRdData,
  //     MemOp.lbu      -> Cat(Fill(24, 0.U), memRdData(7, 0)),
  //     MemOp.lhu      -> Cat(Fill(16, 0.U), memRdData(15, 0))
  //   )
  // )

  // when(memIO.arvalid && memIO.arready) {
  //   memAddrSent := true.B
  // }

  // memRdRawData := memIO.rdata
  // when(memIO.rvalid && !memRDone) {
  //   memRdRawData := memIO.rdata
  //   memRDone     := true.B
  // }
  // val downStreamRecved = Reg(Bool())
  // dontTouch(downStreamRecved)
  // memIO.rready := io.out.ready

  // TODO: fix SoC AXI4 Delayer support delay ready
  memIO.rready := true.B
  // when(io.out.ready && io.out.valid) {
  //   downStreamRecved := true.B
  // }.elsewhen(io.dinst.valid && isMemOp){
  //   downStreamRecved := false.B
  // }
  // when((!isMemOp) || (io.out.fire)) {
  //   memRDone    := false.B
  //   memWDone    := false.B
  //   memAddrSent := false.B
  // }

  // mem write

  // for now sw only consider align addr

  val memWAddr = memIO.awaddr
  val memWData = memIO.wdata
  val memWMask = memIO.wstrb

  // memIO.awvalid := isStore && (!memWDone) && (!memAddrSent)
  // memIO.wvalid  := isStore && (!memWDone)
  memIO.awvalid := isStore && (isIdle || isWaitAW)
  memIO.wvalid  := isStore && (isIdle || isWaitAW || isWaitW)
  memIO.wlast   := true.B

  // NOTE: need keep to make simulation bind signal by names
  dontTouch(io.mem)

  // dontTouch(memIO.wlast)

  memIO.awid    := 0.U
  memIO.awlen   := 0.U
  memIO.awsize  := memOpSize
  memIO.awburst := 1.U

  // when(memIO.awvalid && memIO.awready) {
  //   memAddrSent := true.B
  // }
  // when(memIO.wvalid && memIO.wready) {
  //   memWDone := true.B
  // }

  //
  // need wait for bresp
  // since w done only means data has been sent
  // later read operation may have higher priority and
  // the write may not be finished yet
  //
  // when(memIO.bvalid && memIO.bready) {
  //   memWDone := true.B
  // }
  memIO.bready := true.B

  // memWData := storeData << memAddrUnalignPartBitlen
  memWData := MuxLookup(memAddrUnalignPart, 0.U(32.W))(
    Seq(
      0.U -> storeData,
      1.U -> Cat(storeData(23, 0), 0.U(8.W)),
      2.U -> Cat(storeData(15, 0), 0.U(16.W)),
      3.U -> Cat(storeData(7, 0), 0.U(24.W))
    )
  )
  // memWData := storeData
  val wByteMask = MuxLookup(memAddrUnalignPart, 0.U(4.W))(
    Seq(
      0.U -> "b0001".U(4.W),
      1.U -> "b0010".U(4.W),
      2.U -> "b0100".U(4.W),
      3.U -> "b1000".U(4.W)
    )
  )
  val wByteMaskHalf = MuxLookup(memAddrUnalignPart, 0.U(4.W))(
    Seq(
      0.U -> "b0011".U(4.W),
      1.U -> "b0110".U(4.W),
      2.U -> "b1100".U(4.W)
    )
  )

  memWAddr := memAddr
  memWMask := Mux1H(
    Seq(
      memOpIsByte -> wByteMask,
      memOpIsHalf -> wByteMaskHalf,
      memOpIsWord -> "b1111".U(4.W)
    )
  )
  // memWMask := MuxLookup(func3t, 0.U)(
  //   Seq(
  //     MemOp.byte     -> wByteMask,
  //     MemOp.halfword -> wByteMaskHalf,
  //     MemOp.word     -> 15.U(4.W)
  //   )
  // )

  outWriteBackInfo.csr           := inExuWriteBackInfo.csr
  outWriteBackInfo.csr_ecallflag := inExuWriteBackInfo.csr_ecallflag
  outWriteBackInfo.gpr.addr      := inExuWriteBackInfo.gpr.addr
  outWriteBackInfo.gpr.en        := inExuWriteBackInfo.gpr.en
  outWriteBackInfo.gpr.data      := Mux(isLoadOp, Mux(isCLINTAddr, clintRdData, loadResult), inExuWriteBackInfo.gpr.data)
  // outWriteBackInfo.is_ebreak     := inExuWriteBackInfo.is_ebreak
  // outWriteBackInfo.pc            := inExuWriteBackInfo.pc
  // outWriteBackInfo.nxt_pc        := inExuWriteBackInfo.nxt_pc
  outWriteBackInfo.iid           := inExuWriteBackInfo.iid

  val isSRAMAddr = AddrSpace.inRng(memAddr, AddrSpace.SRAM)
  when(io.mem.awvalid && io.mem.awready && isSRAMAddr) {
    ClockedCallVoidDPIC("sram_upd", Some(Seq("addr", "data", "mask")))(
      clock,
      isSRAMAddr,
      memWAddr,
      memWData,
      memWMask.pad(8)
    )
  }
}

class LSUInputForDifftest extends Bundle {
  val isLoad   = Bool()
  val isStore  = Bool()
  val destAddr = Types.UWord
  val pc       = Types.UWord
  val nxtPC    = Types.UWord
  val isEBreak = Bool()
}

class LSUForDifftest(
  implicit p: CPUParameters)
    extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new LSUInputForDifftest))

    val actualLSU = new Bundle {
      val inReady  = Input(Bool())
      val outValid = Input(Bool())
    }

    val out = Decoupled(new DifftestWriteBackInfo)
  })

  io.in.ready  := io.actualLSU.inReady
  io.out.valid := io.actualLSU.outValid

  val memAddr     = io.in.bits.destAddr
  // val isSerialAddr = AddrSpace.inRng(memAddr, AddrSpace.SERIAL)
  // val isSPIAddr    = AddrSpace.inRng(memAddr, AddrSpace.SPI)
  val isClintAddr = AddrSpace.inRng(memAddr, AddrSpace.CLINT)
  // val isVGAAddr    = AddrSpace.inRng(memAddr, AddrSpace.VGA)
  // val isPS2Addr    = AddrSpace.inRng(memAddr, AddrSpace.PS2)

  val isLoadOp  = io.in.bits.isLoad && io.in.valid
  val isStore   = io.in.bits.isStore && io.in.valid
  val isMemLoad = isLoadOp && (!isClintAddr)
  val isMemOp   = isMemLoad || isStore

  val inSkipRng = p.skipDifftestAddrs.map(addr => AddrSpace.inRng(memAddr, addr)).reduce(_ || _)
  val needSkipDifftest =
    (isMemOp && inSkipRng) || (isLoadOp && isClintAddr)

  // val needSkipDifftest =
  //   (isMemOp && (isSerialAddr || isSPIAddr || isClintAddr || isVGAAddr || isPS2Addr)) || (isLoadOp && isClintAddr)

  val outInfo = io.out.bits
  outInfo.pc          := io.in.bits.pc
  outInfo.needSkipRef := needSkipDifftest
  outInfo.isEBreak    := io.in.bits.isEBreak
  outInfo.nxtPC       := io.in.bits.nxtPC
}
