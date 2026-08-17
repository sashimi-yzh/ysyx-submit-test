package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class __RamLoadTester_test extends PrefixedModule {
  val io = IO(new Bundle {
    val word = Input(UInt(32.W))
    val lower2bit = Input(UInt(2.W))
    val size = Input(UInt(2.W))
    val is_unsigned = Input(Bool())
    val out = Output(UInt(32.W))
  })

  val ramloader = Module(new RamLoadData)
  ramloader.io <> io
}

class RamLoaderTester extends AnyFlatSpec {
  def setInput(
      dut: __RamLoadTester_test,
      word: Long,
      offset: Int,
      size: UInt,
      unsigned: Boolean
  ): Unit = {
    dut.io.word.poke(word.U)
    dut.io.lower2bit.poke(offset.U)
    dut.io.size.poke(size)
    dut.io.is_unsigned.poke(unsigned.B)
  }

  behavior of "RamLoadData"

  it should "return complete words" in {
    simulate(new __RamLoadTester_test) { dut =>
      setInput(dut, 0x12345678L, 0, RamSize.WORD, false)
      dut.io.out.expect(0x12345678L.U)

      setInput(dut, 0x89abcdefL, 3, RamSize.WORD, true)
      dut.io.out.expect(0x89abcdefL.U)
    }
  }

  it should "select and sign extend bytes" in {
    simulate(new __RamLoadTester_test) { dut =>
      val expected = Seq(0x00000078L, 0x00000056L, 0xffffff84L, 0xffffff82L)

      expected.zipWithIndex.foreach { case (value, offset) =>
        setInput(dut, 0x82845678L, offset, RamSize.BYTE, false)
        dut.io.out.expect(value.U)
      }
    }
  }

  it should "select and zero extend bytes" in {
    simulate(new __RamLoadTester_test) { dut =>
      val expected = Seq(0x00000078L, 0x00000056L, 0x00000084L, 0x00000082L)

      expected.zipWithIndex.foreach { case (value, offset) =>
        setInput(dut, 0x82845678L, offset, RamSize.BYTE, true)
        dut.io.out.expect(value.U)
      }
    }
  }

  it should "select signed and unsigned halfwords" in {
    simulate(new __RamLoadTester_test) { dut =>
      setInput(dut, 0x82845678L, 0, RamSize.HALF, false)
      dut.io.out.expect(0x00005678L.U)

      setInput(dut, 0x82845678L, 2, RamSize.HALF, false)
      dut.io.out.expect(0xffff8284L.U)

      setInput(dut, 0x82845678L, 0, RamSize.HALF, true)
      dut.io.out.expect(0x00005678L.U)

      setInput(dut, 0x82845678L, 2, RamSize.HALF, true)
      dut.io.out.expect(0x00008284L.U)
    }
  }
}
