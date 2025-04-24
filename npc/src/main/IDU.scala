package npc
import chisel3._
import chisel3.util._
import utils._

class IDU extends NPCModule {
  val io = IO(new Bundle{
    val in = Flipped(Decoupled(new IF2ID))
    val out = Decoupled(new ID2EX)
    val wb = Flipped(new WriteBack)
    val lsFw = Flipped(new Forward)
    val exFw = Flipped(new Forward)
  })

  val in  = io.in.bits
  val out = io.out.bits
  val inst = in.inst
  val isEbreak = (if (Global.mode != "syn") inst === "h00100073".U else false.B)

  val isUtype = inst(4, 2) === "b101".U
  val isJtype = inst(6, 2) === "b11011".U
  val isStype = inst(6, 2) === "b01000".U
  val isBtype = inst(6, 2) === "b11000".U
  val isItype = (inst(6, 2) === "b00100".U) || (inst(6, 2) === "b00110".U)
  val isRtype = (inst(6, 2) === "b01100".U) || (inst(6, 2) === "b01110".U)

  val funct3 = inst(14, 12)
  val isLui  = inst(6, 2) === "b01101".U
  val isCSR  = (inst(6, 2) === "b11100".U) && (funct3 =/= 0.U)
  val isLoad = inst(6, 2) === "b00000".U
  val isJalr = inst(6, 2) === "b11001".U

  out.decode.isLoad   := isLoad
  out.decode.isStore  := isStype
  out.decode.isJmp    := isJalr || isJtype
  out.decode.isBranch := isBtype
  out.decode.isWord   := (if (XLEN == 64) AllInst.tableRV64Word.map(i => AllInst.isInst(inst, i)).reduce(_ || _) else false.B)
  out.decode.isEcall  := AllInst.isInst(inst, AllInst.ecall)
  out.decode.isMret   := AllInst.isInst(inst, AllInst.mret)
  out.decode.isCSR    := isCSR
  out.decode.isFencei := AllInst.isInst(inst, AllInst.fence_i)
  out.decode.illegal  := AllInst.isIllegal(inst)

  val immI = SignEXT(inst(31, 20), XLEN)
  val immJ = SignEXT(Cat(inst(31), inst(19, 12), inst(20), inst(30, 21), 0.U(1.W)), XLEN)
  val immU = SignEXT(Cat(inst(31, 12), 0.U(12.W)), XLEN)
  val immB = SignEXT(Cat(inst(31), inst(7), inst(30, 25), inst(11, 8), 0.U(1.W)), XLEN)
  val immS = SignEXT(Cat(inst(31, 25), inst(11, 7)), XLEN)

  out.rd := inst(11, 7)(GPRIdxBits - 1, 0)
  val rs1 = Mux(isEbreak, 10.U, inst(19, 15))(GPRIdxBits - 1, 0)
  val rs2 = Mux(isEbreak, 11.U, inst(24, 20))(GPRIdxBits - 1, 0)
  out.wen := !(isStype || isBtype) && (out.rd =/= 0.U) // disable wen when rd == 0 to simplify forwarding logic
  val src1UseReg = !(isUtype || isJtype)
  val src2UseReg = isRtype || isBtype

  out.decode.isArithShift := inst(30)
  out.decode.aluop_isAdd := (isUtype || isStype || isLoad || isJtype || isJalr || (funct3 === 0.U)) && !(isRtype && inst(30))
  out.decode.funct3 := funct3

  val (regRead, regWrite) = if (Global.mode == "syn") {
    val R = List(0.U(XLEN.W)) ++ List.fill(NRregs - 1)(Reg(UInt(XLEN.W)))
    def read(idx: UInt) = R.zipWithIndex.map { case (r, i) => (r & Fill(XLEN, (i.U === idx))) } .reduce(_ | _)
    def write(idx: UInt, data: UInt) = R.zipWithIndex.map { case (r, i) => if (i != 0) when (i.U === idx) { r := data } }
    (read(_), write(_,_))
  } else {
    val R = Mem(NRregs, UInt(XLEN.W))
    def read(idx: UInt) = R(idx)
    def write(idx: UInt, data: UInt) = when (idx =/= 0.U) { R(idx) := data }
    (read(_), write(_,_))
  }


  def isDependent[T <: WriteBack](rs: UInt, fwSrc: T) = fwSrc.wen && (rs === fwSrc.rd)
  def genValAndReady(rs: UInt, exCanFw: Bool, lsCanFw : Bool, wbCanFw: Bool) = ( // forward from EX has higher priority
    Mux(exCanFw, io.exFw.res,      Mux(lsCanFw, io.lsFw.res,      Mux(wbCanFw, io.wb.res, regRead(rs)))),
   !Mux(exCanFw, io.exFw.notReady, Mux(lsCanFw, io.lsFw.notReady, false.B))
  )
  val exCanFwRs1 :: exCanFwRs2 :: Nil = List(rs1, rs2).map(isDependent(_, io.exFw))
  val lsCanFwRs1 :: lsCanFwRs2 :: Nil = List(rs1, rs2).map(isDependent(_, io.lsFw))
  val wbCanFwRs1 :: wbCanFwRs2 :: Nil = List(rs1, rs2).map(isDependent(_, io.wb))
  val (rs1Val, rs1ReadyTmp) = genValAndReady(rs1, exCanFwRs1, lsCanFwRs1, wbCanFwRs1)
  val (rs2Val, rs2ReadyTmp) = genValAndReady(rs2, exCanFwRs2, lsCanFwRs2, wbCanFwRs2)
  val rs1Ready = rs1ReadyTmp || !src1UseReg
  val rs2Ready = rs2ReadyTmp || !(src2UseReg || isStype)
  val canIssue = rs1Ready && rs2Ready

  val pc = toPC(in.pc)
  out.src1 := Mux(src1UseReg, rs1Val, Mux(isLui, 0.U, pc))
  out.src2 := Lookup1H(immI, Seq(
    src2UseReg -> rs2Val,
    isStype -> immS,
    isJtype -> immJ,
    isUtype -> immU,
  ))
  out.src3 := Mux(isStype, rs2Val, pc + Mux(isBtype, immB, Mux(out.decode.isJmp || out.decode.isFencei, 4.U, 0.U)))

  out.decode.csrRen := isCSR && !((CSRType(funct3) === CSRType.csrrw) && (out.rd === 0.U))
  out.decode.csrWen := isCSR && !((CSRType(funct3) =/= CSRType.csrrw) && (rs1 === 0.U))

  when (io.wb.wen) { regWrite(io.wb.rd, io.wb.res) }

  out.npctrap := DontCare
  out.npctrap.pc := in.pc
  out.npctrap.dnpc := in.pc + 4.U
  out.npctrap.isEbreak := isEbreak && io.in.valid
  out.npctrap.code := out.src1
  out.npctrap.skip := isCSR && List("hc00", "hf11", "hf12").map(immI(11, 0) === _.U).reduce(_ || _)

  // in.inst may be X, use in.valid to guard in.ready
  io.in.ready := (io.out.ready && canIssue) || !io.in.valid
  io.out.valid := io.in.valid && canIssue
}
