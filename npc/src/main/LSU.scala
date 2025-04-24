package npc
import chisel3._
import chisel3.util._
import utils._

class LSU extends NPCModule {
  val io = IO(new Bundle{
    val in = Flipped(Decoupled(new EX2LS))
    val out = Decoupled(new LS2WB)
    val redirect = new RedirectIO
    val mem = new DMEM
    val fw = new Forward
  })

  val in  = io.in.bits
  val out = io.out.bits
  val memAddr = in.res
  val funct3 = in.decode.funct3
  val isValidLoad  = in.decode.isLoad && io.in.valid
  val isValidStore = in.decode.isStore && io.in.valid

  object DMEMState extends ChiselEnum {
    val idle, waitRvalid, axiFinish = Value
  }
  val state = RegInit(DMEMState.idle)

  state := Lookup1H(state, Array(
    DMEMState.idle        -> Mux(isValidLoad && io.mem.ar.ready, DMEMState.waitRvalid, DMEMState.idle),
    DMEMState.waitRvalid  -> Mux(io.mem. r.valid, DMEMState.axiFinish,   DMEMState.waitRvalid),
    DMEMState.axiFinish   -> DMEMState.idle,
  ))

  io.mem.ar.valid := (state === DMEMState.idle) && isValidLoad
  io.mem.ar.bits.addr := memAddr
  io.mem.ar.bits.size := funct3(1, 0)
  io.mem. r.ready := (state === DMEMState.waitRvalid)
  val memFinish = state.isOneOf(DMEMState.axiFinish)

  val rdataMuxS2 = RegNext(io.mem.r.bits.data)
  def rdataSelect(pattern: String, group: Int, idx: UInt) = {
    require(pattern.length == XLEN / 8)
    val rdataMuxVecS2 = rdataMuxS2.asTypeOf(Vec(XLEN / 8, UInt(8.W)))
    VecInit(pattern.reverse.zipWithIndex.filter(_._1 == 'o').map(_._2)
      .grouped(group).toSeq.map(gp => Cat(gp.reverse.map(rdataMuxVecS2(_)))))(idx)
  }
  val (rdataSel_63_32, rdataSel_31_16, rdataSel_15_8, rdataSel_7_0) = if (XLEN == 64) (
    rdataSelect("ooooxxxx", 4, 0.U),
    rdataSelect("ooxxooxx", 2, memAddr(2)),
    rdataSelect("oxoxoxox", 1, memAddr(2, 1)),
    rdataSelect("oooooooo", 1, memAddr(2, 0))
  ) else (
    0.U,
    rdataSelect("ooxx", 2, 0.U),
    rdataSelect("oxox", 1, memAddr(1)),
    rdataSelect("oooo", 1, memAddr(1, 0)),
  )


  val loadUnsign = funct3(2)
  val loadByte   = funct3(1, 0) === "b00".U
  val loadHalf   = funct3(1, 0) === "b01".U
  val loadWord   = funct3(1, 0) === "b10".U
  def fillHigh(len: Int, isUnsign: Bool, sign: Bool) = Mux(isUnsign, 0.U(len.W), Fill(len, sign))
  def fillHighFrom_7_0(len: Int)   = fillHigh(len, loadUnsign, rdataSel_7_0(7))
  def fillHighFrom_15_8(len: Int)  = fillHigh(len, loadUnsign, rdataSel_15_8(7))
  def fillHighFrom_31_16(len: Int) = fillHigh(len, loadUnsign, rdataSel_31_16(15))

  val rdata7_0   = rdataSel_7_0
  val rdata15_8  = Mux(loadByte, fillHighFrom_7_0(8), rdataSel_15_8)
  val rdata31_16 = Mux(loadByte, fillHighFrom_7_0(16),
                   Mux(loadHalf, fillHighFrom_15_8(16), rdataSel_31_16))
  val rdata63_32 = Mux(loadByte, fillHighFrom_7_0(32),
                   Mux(loadHalf, fillHighFrom_15_8(32),
                   Mux(loadWord, fillHighFrom_31_16(32), rdataSel_63_32)))
  val rdata_31_0 = Cat(rdata31_16, rdata15_8, rdata7_0)
  val rdata = if (XLEN == 64) Cat(rdata63_32, rdata_31_0) else rdata_31_0

  object SbufState extends ChiselEnum {
    val idle, waitAWready, waitBvalid = Value
  }
  val sbufState = RegInit(SbufState.idle)

  val sbufReq = Wire(new MemSinglePortReqBundle)
  sbufReq.addr := memAddr
  sbufReq.size := funct3(1, 0)
  sbufReq.wen := true.B
  def genWmaskVec(bytes: Int) = VecInit((0 until (XLEN / 8 / bytes)).map(i => (((1 << bytes) - 1) << (i * bytes)).U))
  sbufReq.wmask := Lookup1H(StoreType(funct3(1,0)), Seq(
     StoreType.sb -> genWmaskVec(1)(if (XLEN == 64) memAddr(2, 0) else memAddr(1, 0)),
     StoreType.sh -> genWmaskVec(2)(if (XLEN == 64) memAddr(2, 1) else memAddr(1)),
     StoreType.sw -> genWmaskVec(4)(if (XLEN == 64) memAddr(2) else 0.U(1.W)),
  ) ++ (if (XLEN == 64) Seq(StoreType.sd -> Fill(8, 1.U(1.W))) else Seq()))
  sbufReq.wdata := Lookup1H(StoreType(funct3(1,0)), Seq(
     StoreType.sb -> Fill(8, in.res2(7 , 0)),
     StoreType.sh -> Fill(4, in.res2(15, 0)),
     StoreType.sw -> Fill(2, in.res2(31, 0)),
  ) ++ (if (XLEN == 64) Seq(StoreType.sd -> in.res2) else Seq()))


  val sbufWen = (sbufState === SbufState.idle) && isValidStore
  val sbuf = Mux(sbufWen, sbufReq, RegEnable(sbufReq, sbufWen))

  sbufState := Lookup1H(sbufState, Array(
    SbufState.idle        -> Mux(isValidStore, Mux(io.mem.aw.ready, SbufState.waitBvalid, SbufState.waitAWready), SbufState.idle),
    SbufState.waitAWready -> Mux(io.mem.aw.ready, SbufState.waitBvalid, SbufState.waitAWready),
    SbufState.waitBvalid  -> Mux(io.mem. b.valid, SbufState.idle,       SbufState.waitBvalid),
  ))

  io.mem.aw.valid := sbufWen || (sbufState === SbufState.waitAWready)
  io.mem.aw.bits.addr := sbuf.addr
  io.mem.aw.bits.size := sbuf.size
  io.mem. w.valid := io.mem.aw.valid
  io.mem. w.bits.data := sbuf.wdata
  io.mem. w.bits.strb := sbuf.wmask
  io.mem. b.ready := (sbufState === SbufState.waitBvalid)

  val mtvec = Reg(UInt(PALEN.W))
  val mcause = Reg(UInt(XLEN.W))
  val mstatus = RegInit(0x1800.U(XLEN.W))
  val mepc = Reg(UInt(PALEN.W))

  val mcycle = RegInit(0.U(XLEN.W))
  mcycle := mcycle + 1.U

  val mvendorid = RegInit("h79737978".U(XLEN.W))
  val marchid = RegInit("d19010006".U(XLEN.W))

  val raiseException = in.decode.illegal || in.decode.isEcall
  val csrAddr = in.res2(11, 0).asTypeOf(CSRAddr())
  when (in.decode.csrWen && io.in.valid) {
    when (csrAddr === CSRAddr.mtvec) { mtvec := toPC(in.res) }
    .elsewhen (csrAddr === CSRAddr.mstatus) { /* mstatus := in.res */ }
    .elsewhen (csrAddr === CSRAddr.mepc) { mepc := toPC(in.res) }
    .otherwise { assert(false.B, p"Bad csrAddr = $csrAddr\n") }
  }
  val csrOut = Lookup1H(csrAddr, Seq(
    CSRAddr.mtvec   -> toPC(mtvec),
    CSRAddr.mcause  -> mcause,
    CSRAddr.mstatus -> mstatus,
    CSRAddr.mepc    -> toPC(mepc),
    CSRAddr.cycle   -> mcycle,
    CSRAddr.mvendorid -> mvendorid,
    CSRAddr.marchid -> marchid,
  ))
  when (raiseException && io.in.valid) {
    mcause := Mux(in.decode.isEcall, 11.U, 2.U)
    mepc := in.res2
  }

  out.res := Mux(in.decode.isLoad, rdata, Mux(in.decode.isCSR, csrOut, in.res))
  out.wen := in.wen
  out.rd := in.rd

  val dnpc = Mux(raiseException, mtvec, Mux(in.decode.isMret, mepc, in.res2))
  io.redirect.dnpc := toPC(dnpc)
  io.redirect.valid := (raiseException || in.decode.isMret || in.redirect) && io.in.valid

  io.fw.wen := io.in.valid && out.wen
  io.fw.rd := out.rd
  io.fw.res := out.res
  io.fw.notReady := in.decode.isLoad && !memFinish

  out.npctrap := in.npctrap
  out.npctrap.isMMIO := (isValidLoad || isValidStore) && !memAddr(PALEN - 1)
  out.npctrap.memAddr := memAddr
  out.npctrap.dnpc := Mux(io.redirect.valid, io.redirect.dnpc, in.npctrap.dnpc)

  io.in.ready  := Mux(isValidStore, sbufWen, Mux(isValidLoad, memFinish, true.B)) && io.out.ready
  io.out.valid := Mux(in.decode.isStore, sbufWen, Mux(in.decode.isLoad, memFinish, true.B)) && io.in.valid
}
