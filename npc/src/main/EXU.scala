package npc
import chisel3._
import chisel3.util._
import utils._

class EXU extends NPCModule {
  val io = IO(new Bundle{
    val in = Flipped(Decoupled(new ID2EX))
    val out = Decoupled(new EX2LS)
    val fence_i = Output(Bool())
    val fw = new Forward
  })

  val in  = io.in.bits
  val out = io.out.bits
  val funct3 = in.decode.funct3

  def shiftamt = Cat(Mux(in.decode.isWord, 0.U(1.W), in.src2(log2Up(XLEN) - 1)), in.src2(log2Up(XLEN) - 2, 0))
  def shiftbaselogic = Mux(in.decode.isWord, ZeroEXT(in.src1(31, 0), XLEN), in.src1)
  def shiftbasearith = Mux(in.decode.isWord, SignEXT(in.src1(31, 0), XLEN), in.src1).asSInt
  val shiftRes = Mux(in.decode.isArithShift, (shiftbasearith >> shiftamt).asUInt, (shiftbaselogic >> shiftamt))

  val isSub = !in.decode.aluop_isAdd
  val adderRes = in.src1 +& Mux(isSub, ~in.src2, in.src2) + isSub
  val (carry, sum) = (adderRes(XLEN), adderRes(XLEN - 1, 0))
  val xor = in.src1 ^ in.src2
  val sltu = ~carry
  val slt = xor(XLEN - 1) ^ sltu
  val aluOP = Mux(in.decode.aluop_isAdd, ALUType.add, ALUType(funct3))
  val aluOut = Lookup1H(aluOP, Seq(
    ALUType.add  -> sum,
    ALUType.sll  -> (in.src1 << shiftamt),
    ALUType.slt  -> slt,
    ALUType.sltu -> sltu,
    ALUType.xor  -> xor,
    ALUType.srl  -> shiftRes,
    ALUType.or   -> (in.src1 | in.src2),
    ALUType.and  -> (in.src1 & in.src2),
  ))

  val branchResInv = funct3(0)
  val branchTaken = Lookup1H(BranchType(funct3(2,1) ## 0.U(1.W)), Seq(
    BranchType.beq  -> !xor.orR,
    BranchType.blt  -> slt,
    BranchType.bltu -> sltu,
  )) ^ branchResInv
  out.res2 := Mux(in.decode.isJmp, sum, Mux(in.decode.isCSR, in.src2(11, 0), in.src3))
  out.redirect := Mux(in.decode.isBranch, branchTaken, in.decode.isJmp) || in.decode.isFencei

  out.res := Lookup1H(aluOut, Seq(
    in.decode.isJmp -> in.src3,
    in.decode.isCSR -> in.src1,
  ) ++ (if (XLEN == 64) Seq(in.decode.isWord -> SignEXT(aluOut(31, 0), XLEN)) else Seq())
  )

  out.wen := in.wen
  out.rd := in.rd
  out.decode := in.decode

  io.fw.wen := io.out.valid && out.wen
  io.fw.rd := out.rd
  io.fw.res := aluOut
  io.fw.notReady := out.decode.isLoad || out.decode.isCSR || out.decode.isJmp

  out.npctrap := in.npctrap

  io.fence_i := in.decode.isFencei && io.in.valid

  io.in.ready := io.out.ready
  io.out.valid := io.in.valid
}
