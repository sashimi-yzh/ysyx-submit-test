package scpu.scpu

import chisel3._
import chisel3.util._
import chisel3.util.BitPat
import chisel3.util.experimental.decode._
import scala.collection.mutable.ListBuffer
import dle.exp2.DecoderLed

class DecodePairSaver[T] {
  private val _all = ListBuffer[T]()
  def r(p: T): T = {
    _all += p
    p
  }
  def all = _all.toSeq
}

case class InstPattern(opCode: String) extends DecodePattern {
  def bitPat: BitPat = BitPat("b" + opCode + "??????")
}
object InstPatterns {
  val saver = new DecodePairSaver[InstPattern]
  import saver._
  val Add = r(InstPattern("00"))
  val OutRs = r(InstPattern("01"))
  val Li = r(InstPattern("10"))
  val Bner0 = r(InstPattern("11"))
}

object InstFields {
  val saver = new DecodePairSaver[DecodeField[InstPattern, _ <: Data]]
  import saver._
  import InstPatterns._

  object IsWriteReg extends BoolDecodeField[InstPattern] {
    def name = "Write registers"
    def genTable(p: InstPattern) = p match {
      case Add | Li => y
      case _        => n
    }
  }
  r(IsWriteReg)

  object GprRAddr1Src extends DecodeField[InstPattern, UInt] {
    def name = "The source of read address 1"
    def chiselType = UInt(1.W)
    def genTable(p: InstPattern) = p match {
      case Add   => BitPat("b0")
      case Bner0 => BitPat("b1")
      case _     => dc
    }
  }
  r(GprRAddr1Src)

  object GprRAddr2Src extends DecodeField[InstPattern, UInt] {
    def name = "The source of read address 2"
    def chiselType = UInt(1.W)
    def genTable(p: InstPattern) = p match {
      case Add | Bner0 | OutRs => BitPat("b0")
      case _                   => dc
    }
  }
  r(GprRAddr2Src)

  object AluOp extends DecodeField[InstPattern, UInt] {
    def name = "Chose which operation will be excuted by ALU"
    def chiselType = UInt(2.W)
    def genTable(p: InstPattern) = p match {
      case Add   => BitPat("b00")
      case Li    => BitPat("b01")
      case Bner0 => BitPat("b10")
      case _     => dc
    }
  }
  r(AluOp)

  object AluASrc extends DecodeField[InstPattern, UInt] {
    def name = "The source of OP NUM a"
    def chiselType = UInt(1.W)
    def genTable(p: InstPattern) = p match {
      case Add | Bner0 => BitPat("b0")
      case Li          => BitPat("b1")
      case _           => dc
    }
  }
  r(AluASrc)

  object AluBSrc extends DecodeField[InstPattern, UInt] {
    def name = "The source of OP NUM b"
    def chiselType = UInt(1.W)
    def genTable(p: InstPattern) = p match {
      case Add | Bner0 => BitPat("b0")
      case Li          => BitPat("b1")
      case _           => dc
    }
  }
  r(AluBSrc)

  object IsBranch extends BoolDecodeField[InstPattern] {
    def name = "Write PC"
    def genTable(p: InstPattern) = p match {
      case Bner0 => y
      case _     => n
    }
  }
  r(IsBranch)

  object IsWriteLed7 extends BoolDecodeField[InstPattern] {
    def name = "Update Led7"
    def genTable(p: InstPattern) = p match {
      case OutRs => y
      case _     => n
    }
  }
  r(IsWriteLed7)
}

class SelSignal extends Bundle {
  val isWriteReg = Bool()
  val gprRAddr1Src = UInt(1.W)
  val gprRAddr2Src = UInt(1.W)
  val aluOp = UInt(2.W)
  val aluASrc = UInt(1.W)
  val aluBSrc = UInt(1.W)
  val isBranch = Bool()
  val isWriteLed7 = Bool()
}

class Decoder extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(8.W))
    val selSignal = Output(new SelSignal)
  })

  val instPatterns = InstPatterns.saver.all
  val instFields = InstFields.saver.all
  print(instPatterns)
  print(instFields)
  val decodeTable = new DecodeTable(instPatterns, instFields)
  val decodeResult = decodeTable.decode(io.inst)

  io.selSignal.isWriteReg := decodeResult(InstFields.IsWriteReg)
  io.selSignal.gprRAddr1Src := decodeResult(InstFields.GprRAddr1Src)
  io.selSignal.gprRAddr2Src := decodeResult(InstFields.GprRAddr2Src)
  io.selSignal.aluOp := decodeResult(InstFields.AluOp)
  io.selSignal.aluASrc := decodeResult(InstFields.AluASrc)
  io.selSignal.aluBSrc := decodeResult(InstFields.AluBSrc)
  io.selSignal.isBranch := decodeResult(InstFields.IsBranch)
  io.selSignal.isWriteLed7 := decodeResult(InstFields.IsWriteLed7)
}

class Gpr extends Module {
  val io = IO(new Bundle {
    val wData = Input(UInt(8.W))
    val wAddr = Input(UInt(2.W))
    val rAddr = Input(Vec(2, UInt(2.W)))
    val selSignal = Input(new SelSignal)
    val rData = Output(Vec(2, UInt(8.W)))
  })

  val wEn = io.selSignal.isWriteReg
  val gpReg = RegInit(VecInit.fill(4)(0.U(8.W)))

  when(wEn) {
    gpReg(io.wAddr) := io.wData
  }

  io.rData(0) := gpReg(io.rAddr(0))
  io.rData(1) := gpReg(io.rAddr(1))
}

class Alu extends Module {
  val io = IO(new Bundle {
    val selSignal = Input(new SelSignal)
    val rData = Input(Vec(2, UInt(8.W)))
    val rs1 = Input(UInt(2.W))
    val rs2 = Input(UInt(2.W))
    val out = Output(UInt(8.W))
  })

  val a = Wire(UInt(8.W))
  val b = Wire(UInt(8.W))

  a := MuxLookup(io.selSignal.aluASrc, 0.U)(
    Seq(
      0.U -> io.rData(0),
      1.U -> io.rs1
    )
  )

  b := MuxLookup(io.selSignal.aluBSrc, 0.U)(
    Seq(
      0.U -> io.rData(1),
      1.U -> io.rs2
    )
  )

  io.out := MuxLookup(io.selSignal.aluOp, 0.U)(
    Seq(
      0.U -> (a + b),
      1.U -> (a(1, 0) ## b(1, 0)),
      2.U -> (a =/= b)
    )
  )
}

class SCpu extends Module {
  val io = IO(new Bundle {
    val led7 = Output(UInt(14.W))
  })

  val rom = VecInit.fill(16)(0.U(8.W))
  rom(0) := "b10001010".U
  rom(1) := "b10010000".U
  rom(2) := "b10100000".U
  rom(3) := "b10110001".U
  rom(4) := "b00010111".U
  rom(5) := "b00101001".U
  rom(6) := "b11010001".U
  rom(7) := "b01000010".U
  rom(8) := "b11011111".U

  val pcReg = RegInit(0.U(4.W))
  val inst = rom(pcReg)

  val rs1 = inst(3, 2)
  val rs2 = inst(1, 0)
  val branchAddr = inst(5, 2)
  val rd = inst(5, 4)

  val decoder = Module(new Decoder)
  val gpr = Module(new Gpr)
  val alu = Module(new Alu)

  decoder.io.inst := inst

  gpr.io.selSignal <> decoder.io.selSignal
  gpr.io.rAddr(0) := Mux(decoder.io.selSignal.gprRAddr1Src === 1.U, 0.U, rs1)
//  gpr.io.rAddr(1) := Mux(decoder.io.selSignal.gprRAddr2Src === 1.U, 2.U, rs2)
  gpr.io.rAddr(1) := rs2
  gpr.io.wData := alu.io.out
  gpr.io.wAddr := rd

  alu.io.selSignal <> decoder.io.selSignal
  alu.io.rData := gpr.io.rData
  alu.io.rs1 := rs1
  alu.io.rs2 := rs2

  pcReg := Mux(
    decoder.io.selSignal.isBranch,
    Mux(alu.io.out(0), branchAddr, pcReg + 1.U),
    pcReg + 1.U
  )

  val led7Reg = RegInit(0.U.asTypeOf(Vec(2, UInt(7.W))))
  val led7Dcd = Seq.fill(2)(Module(new DecoderLed))
  led7Dcd(0).io.in := gpr.io.rData(1)(3, 0)
  led7Dcd(1).io.in := gpr.io.rData(1)(7, 4)
  val isWriteLed7 = decoder.io.selSignal.isWriteLed7
  led7Reg(0) := Mux(isWriteLed7, led7Dcd(0).io.out, led7Reg(0))
  led7Reg(1) := Mux(isWriteLed7, led7Dcd(1).io.out, led7Reg(1))
  io.led7 := led7Reg.asUInt
}
