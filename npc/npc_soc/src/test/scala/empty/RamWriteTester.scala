package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class __RamWriteTester_test extends PrefixedModule {
  val io = IO(new Bundle {
    val word = Input(UInt(32.W))
    val lower2bit = Input(UInt(2.W))
    val size = Input(UInt(2.W))
    val out = Output(UInt(32.W))
    val mask = Output(UInt(4.W))
  })

  val ramWriter = Module(new RamWriteData)
  ramWriter.io <> io
}

class RamWriteTester extends AnyFlatSpec {
  def setInput(
      dut: __RamWriteTester_test,
      word: Long,
      offset: Int,
      size: UInt
  ): Unit = {
    dut.io.word.poke(word.U)
    dut.io.lower2bit.poke(offset.U)
    dut.io.size.poke(size)
  }

  behavior of "RamWriteData"

  it should "write complete words" in {
    simulate(new __RamWriteTester_test) { dut =>
      setInput(dut, 0x12345678L, 0, RamSize.WORD)
      dut.io.out.expect(0x12345678L.U)
      dut.io.mask.expect("b1111".U)

      setInput(dut, 0x89abcdefL, 0, RamSize.WORD)
      dut.io.out.expect(0x89abcdefL.U)
      dut.io.mask.expect("b1111".U)
    }
  }

  it should "align halfwords and generate masks" in {
    simulate(new __RamWriteTester_test) { dut =>
      setInput(dut, 0x12345678L, 0, RamSize.HALF)
      dut.io.out.expect(0x12345678L.U)
      dut.io.mask.expect("b0011".U)

      setInput(dut, 0x12345678L, 2, RamSize.HALF)
      dut.io.out.expect(0x56780000L.U)
      dut.io.mask.expect("b1100".U)
    }
  }

  it should "align bytes and generate masks" in {
    simulate(new __RamWriteTester_test) { dut =>
      val expected = Seq(
        (0x12345678L, "b0001".U),
        (0x34567800L, "b0010".U),
        (0x56780000L, "b0100".U),
        (0x78000000L, "b1000".U)
      )

      expected.zipWithIndex.foreach { case ((data, mask), offset) =>
        setInput(dut, 0x12345678L, offset, RamSize.BYTE)
        dut.io.out.expect(data.U)
        dut.io.mask.expect(mask)
      }
    }
  }
}
