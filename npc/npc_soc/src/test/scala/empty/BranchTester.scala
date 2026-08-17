package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

import scala.util.Random

class __Branch_test(WIDTH: Int) extends PrefixedModule {
  val io = IO(new Bundle {
    val A = Input(UInt(WIDTH.W))
    val B = Input(UInt(WIDTH.W))
    val funct3 = Input(UInt(3.W))
    val jump = Output(Bool())
  })

  val branch = Module(new Branch(WIDTH))
  branch.io <> io
}

class BranchTester extends AnyFlatSpec {
  def check(dut: __Branch_test, a: Long, b: Long): Unit = {
    val signedA = if (a >= (1L << 31)) a - (1L << 32) else a
    val signedB = if (b >= (1L << 31)) b - (1L << 32) else b

    dut.io.A.poke(a.U(32.W))
    dut.io.B.poke(b.U(32.W))

    Seq(
      (0, a == b),
      (1, a != b),
      (4, signedA < signedB),
      (5, signedA >= signedB),
      (6, a < b),
      (7, a >= b)
    ).foreach { case (funct3, expected) =>
      dut.io.funct3.poke(funct3.U)
      dut.io.jump.expect(expected.B)
    }
  }

  behavior of "Branch"

  it should "compare equal and unequal operands" in {
    simulate(new __Branch_test(32)) { dut =>
      check(dut, 0L, 0L)
      check(dut, 0xffffffffL, 0xffffffffL)
      check(dut, 0x12345678L, 0x12345679L)
    }
  }

  it should "handle signed and unsigned boundaries" in {
    simulate(new __Branch_test(32)) { dut =>
      check(dut, 0x80000000L, 0x7fffffffL)
      check(dut, 0x7fffffffL, 0x80000000L)
      check(dut, 0xffffffffL, 0L)
      check(dut, 0L, 0xffffffffL)
    }
  }

  it should "match randomized comparisons" in {
    simulate(new __Branch_test(32)) { dut =>
      val random = new Random(12345)

      for (_ <- 0 until 256) {
        check(dut, random.nextLong(1L << 32), random.nextLong(1L << 32))
      }
    }
  }
}
