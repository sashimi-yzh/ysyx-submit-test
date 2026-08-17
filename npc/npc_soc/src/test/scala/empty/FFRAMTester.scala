package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class FFRAMTester extends AnyFlatSpec {
  behavior of "FFRAM"

  it should "store and read independent entries" in {
    simulate(new FFRAM(3, 32)) { dut =>
      dut.io.wen.poke(true.B)

      dut.io.addr.poke(0.U)
      dut.io.wdata.poke("h12345678".U)
      dut.clock.step()

      dut.io.addr.poke(3.U)
      dut.io.wdata.poke("hdeadbeef".U)
      dut.clock.step()

      dut.io.addr.poke(7.U)
      dut.io.wdata.poke("h80000001".U)
      dut.clock.step()

      dut.io.wen.poke(false.B)
      dut.io.addr.poke(0.U)
      dut.io.rdata.expect("h12345678".U)

      dut.io.addr.poke(3.U)
      dut.io.rdata.expect("hdeadbeef".U)

      dut.io.addr.poke(7.U)
      dut.io.rdata.expect("h80000001".U)
    }
  }

  it should "preserve data while writes are disabled" in {
    simulate(new FFRAM(2, 16)) { dut =>
      dut.io.addr.poke(2.U)
      dut.io.wdata.poke("h55aa".U)
      dut.io.wen.poke(true.B)
      dut.clock.step()

      dut.io.wdata.poke("ha55a".U)
      dut.io.wen.poke(false.B)
      dut.clock.step(2)

      dut.io.rdata.expect("h55aa".U)
    }
  }
}
