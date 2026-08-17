package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

import scala.util.Random

class __ALU_test(WIDTH: Int) extends PrefixedModule {
  val io = IO(new Bundle {
    val A = Input(UInt(WIDTH.W))
    val B = Input(UInt(WIDTH.W))
    val controls = Input(new ALUControl)
    val out = Output(UInt(WIDTH.W))
  })

  val alu = Module(new ALU(WIDTH))
  alu.io <> io
}

class ALUTester extends AnyFlatSpec {
  val mask = 0xffffffffL
  val testCases = 128

  def setInput(dut: __ALU_test, a: Long, b: Long, op: UInt): Unit = {
    dut.io.A.poke(a.U(32.W))
    dut.io.B.poke(b.U(32.W))
    dut.io.controls.op.poke(op)
  }

  def signed32(value: Long): Long = {
    if ((value & 0x80000000L) != 0) value - (1L << 32) else value
  }

  behavior of "ALU"

  it should "perform addition and subtraction" in {
    simulate(new __ALU_test(32)) { dut =>
      val random = new Random(12345)

      for (_ <- 0 until testCases) {
        val a = random.nextLong(1L << 32)
        val b = random.nextLong(1L << 32)

        setInput(dut, a, b, ALUOp.ADD)
        dut.io.out.expect(((a + b) & mask).U(32.W))

        setInput(dut, a, b, ALUOp.SUB)
        dut.io.out.expect(((a - b) & mask).U(32.W))
      }
    }
  }

  it should "perform signed and unsigned comparisons" in {
    simulate(new __ALU_test(32)) { dut =>
      val random = new Random(23456)

      for (_ <- 0 until testCases) {
        val a = random.nextLong(1L << 32)
        val b = random.nextLong(1L << 32)

        setInput(dut, a, b, ALUOp.SLT)
        dut.io.out.expect((if (signed32(a) < signed32(b)) 1 else 0).U(32.W))

        setInput(dut, a, b, ALUOp.SLTU)
        dut.io.out.expect((if (a < b) 1 else 0).U(32.W))
      }

      setInput(dut, 0x80000000L, 0x7fffffffL, ALUOp.SLT)
      dut.io.out.expect(1.U)

      setInput(dut, 0x80000000L, 0x7fffffffL, ALUOp.SLTU)
      dut.io.out.expect(0.U)
    }
  }

  it should "perform bitwise operations" in {
    simulate(new __ALU_test(32)) { dut =>
      val random = new Random(34567)

      for (_ <- 0 until testCases) {
        val a = random.nextLong(1L << 32)
        val b = random.nextLong(1L << 32)

        setInput(dut, a, b, ALUOp.AND)
        dut.io.out.expect((a & b).U(32.W))

        setInput(dut, a, b, ALUOp.OR)
        dut.io.out.expect((a | b).U(32.W))

        setInput(dut, a, b, ALUOp.XOR)
        dut.io.out.expect((a ^ b).U(32.W))
      }
    }
  }

  it should "perform logical and arithmetic shifts" in {
    simulate(new __ALU_test(32)) { dut =>
      val random = new Random(45678)

      for (_ <- 0 until testCases) {
        val a = random.nextLong(1L << 32)
        val b = random.nextLong(1L << 32)
        val shamt = (b & 31).toInt

        setInput(dut, a, b, ALUOp.SLL)
        dut.io.out.expect(((a << shamt) & mask).U(32.W))

        setInput(dut, a, b, ALUOp.SRL)
        dut.io.out.expect((a >> shamt).U(32.W))

        setInput(dut, a, b, ALUOp.SRA)
        dut.io.out.expect(((signed32(a) >> shamt) & mask).U(32.W))
      }

      setInput(dut, 1L, 32L, ALUOp.SLL)
      dut.io.out.expect(1.U)

      setInput(dut, 0x80000000L, 63L, ALUOp.SRL)
      dut.io.out.expect(1.U)

      setInput(dut, 0x80000000L, 63L, ALUOp.SRA)
      dut.io.out.expect(0xffffffffL.U)
    }
  }
}
