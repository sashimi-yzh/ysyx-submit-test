package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

import scala.util.Random

class __Adder_test(WIDTH: Int) extends PrefixedModule {
  val io = IO(new Bundle {
    val A = Input(UInt(WIDTH.W))
    val B = Input(UInt(WIDTH.W))
    val Cin = Input(Bool())
    val out = Output(UInt(WIDTH.W))
    val Cout = Output(Bool())
    val overflow = Output(Bool())
  })

  val adder = Module(new Adder(WIDTH))
  adder.io <> io
}

class AdderTester extends AnyFlatSpec {
  val mask = 0xffffffffL

  def check(dut: __Adder_test, a: Long, b: Long, cin: Int): Unit = {
    val full = a + b + cin
    val sum = full & mask
    val carry = full > mask
    val signA = (a & 0x80000000L) != 0
    val signB = (b & 0x80000000L) != 0
    val signSum = (sum & 0x80000000L) != 0
    val overflow = signA == signB && signA != signSum

    dut.io.A.poke(a.U(32.W))
    dut.io.B.poke(b.U(32.W))
    dut.io.Cin.poke((cin == 1).B)
    dut.io.out.expect(sum.U(32.W))
    dut.io.Cout.expect(carry.B)
    dut.io.overflow.expect(overflow.B)
  }

  behavior of "Adder"

  it should "handle carry and signed overflow boundaries" in {
    simulate(new __Adder_test(32)) { dut =>
      Seq(
        (0x00000000L, 0x00000000L, 0),
        (0xffffffffL, 0x00000000L, 0),
        (0xffffffffL, 0x00000001L, 0),
        (0xffffffffL, 0x00000000L, 1),
        (0x7fffffffL, 0x00000000L, 1),
        (0x7fffffffL, 0x7fffffffL, 0),
        (0x80000000L, 0x80000000L, 0),
        (0x80000000L, 0xffffffffL, 0),
        (0x00000001L, 0xffffffffL, 1)
      ).foreach { case (a, b, cin) => check(dut, a, b, cin) }
    }
  }

  it should "match randomized sums and flags" in {
    simulate(new __Adder_test(32)) { dut =>
      val random = new Random(12345)

      for (_ <- 0 until 1024) {
        val a = random.nextLong(1L << 32)
        val b = random.nextLong(1L << 32)
        val cin = random.nextInt(2)
        check(dut, a, b, cin)
      }
    }
  }
}
