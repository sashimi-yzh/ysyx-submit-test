package top

import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.formal._
import org.scalatest.flatspec.AnyFlatSpec

class ICacheFormalTop extends Module {
  private val numLines = 128

  val io = IO(new Bundle {
    val pc    = Input(UInt(32.W))
    val wen   = Input(Bool())
    val wdata = Input(UInt(32.W))
  })

  private val dut = Module(new ICache(4, numLines))
  dut.io.pc    := io.pc
  dut.io.wen   := io.wen
  dut.io.wdata := io.wdata

  private val offsetBits = log2Ceil(4)
  private val indexBits  = log2Ceil(numLines)
  private val tagBits    = 32 - offsetBits - indexBits

  private val refValid = RegInit(VecInit(Seq.fill(numLines)(false.B)))
  private val refTag   = RegInit(VecInit(Seq.fill(numLines)(0.U(tagBits.W))))
  private val refData  = RegInit(VecInit(Seq.fill(numLines)(0.U(32.W))))

  private val index = io.pc(offsetBits + indexBits - 1, offsetBits)
  private val tag   = io.pc(31, offsetBits + indexBits)

  private val refHit   = refValid(index) && refTag(index) === tag
  private val refRData = refData(index)

  assert(dut.io.hit === refHit)
  when(dut.io.hit) {
    assert(dut.io.rdata === refRData)
  }

  when(io.wen) {
    refValid(index) := true.B
    refTag(index)   := tag
    refData(index)   := io.wdata
  }
}

class ICacheFormalSpec extends AnyFlatSpec with ChiselScalatestTester with Formal {
  behavior of "ICache"

  it should "match the reference cache model" in {
    verify(new ICacheFormalTop, Seq(BoundedCheck(3), BtormcEngineAnnotation))
  }
}