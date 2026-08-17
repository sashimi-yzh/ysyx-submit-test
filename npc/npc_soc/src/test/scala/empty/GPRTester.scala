package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

import scala.util.Random

class GPRTester extends AnyFlatSpec {
  def initialize(dut: GPR): Unit = {
    dut.io.raddr1.poke(0.U)
    dut.io.raddr2.poke(0.U)
    dut.io.wdata.poke(0.U)
    dut.io.wen.poke(true.B)

    for (addr <- 1 until 32) {
      dut.io.waddr.poke(addr.U)
      dut.clock.step()
    }

    dut.io.wen.poke(false.B)
  }

  behavior of "GPR"

  it should "keep register zero immutable" in {
    simulate(new GPR(32, 32)) { dut =>
      dut.io.raddr1.poke(0.U)
      dut.io.raddr2.poke(0.U)
      dut.io.waddr.poke(0.U)
      dut.io.wdata.poke("hffffffff".U)
      dut.io.wen.poke(true.B)
      dut.clock.step()

      dut.io.rdata1.expect(0.U)
      dut.io.rdata2.expect(0.U)
    }
  }

  it should "write and read through both ports" in {
    simulate(new GPR(32, 32)) { dut =>
      dut.io.raddr1.poke(1.U)
      dut.io.raddr2.poke(31.U)
      dut.io.wen.poke(true.B)

      dut.io.waddr.poke(1.U)
      dut.io.wdata.poke("h12345678".U)
      dut.clock.step()

      dut.io.waddr.poke(31.U)
      dut.io.wdata.poke("hdeadbeef".U)
      dut.clock.step()

      dut.io.rdata1.expect("h12345678".U)
      dut.io.rdata2.expect("hdeadbeef".U)

      dut.io.raddr1.poke(31.U)
      dut.io.raddr2.poke(1.U)
      dut.io.rdata1.expect("hdeadbeef".U)
      dut.io.rdata2.expect("h12345678".U)
    }
  }

  it should "preserve data while writes are disabled" in {
    simulate(new GPR(32, 32)) { dut =>
      dut.io.raddr1.poke(5.U)
      dut.io.raddr2.poke(5.U)
      dut.io.waddr.poke(5.U)
      dut.io.wdata.poke("h55aa55aa".U)
      dut.io.wen.poke(true.B)
      dut.clock.step()

      dut.io.wdata.poke("haa55aa55".U)
      dut.io.wen.poke(false.B)
      dut.clock.step(2)

      dut.io.rdata1.expect("h55aa55aa".U)
      dut.io.rdata2.expect("h55aa55aa".U)
    }
  }

  it should "make writes visible after the clock edge" in {
    simulate(new GPR(32, 32)) { dut =>
      dut.io.raddr1.poke(6.U)
      dut.io.raddr2.poke(6.U)
      dut.io.waddr.poke(6.U)
      dut.io.wdata.poke("h11111111".U)
      dut.io.wen.poke(true.B)
      dut.clock.step()

      dut.io.wdata.poke("h22222222".U)
      dut.io.rdata1.expect("h11111111".U)
      dut.io.rdata2.expect("h11111111".U)

      dut.clock.step()
      dut.io.rdata1.expect("h22222222".U)
      dut.io.rdata2.expect("h22222222".U)
    }
  }

  it should "match a randomized register model" in {
    simulate(new GPR(32, 32)) { dut =>
      initialize(dut)
      val random = new Random(12345)
      val expected = Array.fill[Long](32)(0L)

      for (_ <- 0 until 2048) {
        val raddr1 = random.nextInt(32)
        val raddr2 = random.nextInt(32)
        val waddr = random.nextInt(32)
        val wdata = random.nextLong(1L << 32)
        val wen = random.nextBoolean()

        dut.io.raddr1.poke(raddr1.U)
        dut.io.raddr2.poke(raddr2.U)
        dut.io.waddr.poke(waddr.U)
        dut.io.wdata.poke(wdata.U)
        dut.io.wen.poke(wen.B)
        dut.clock.step()

        if (wen && waddr != 0) expected(waddr) = wdata
        dut.io.rdata1.expect(expected(raddr1).U)
        dut.io.rdata2.expect(expected(raddr2).U)
      }
    }
  }
}
