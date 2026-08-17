package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class CSRTester extends AnyFlatSpec {
  def initialize(dut: CSR): Unit = {
    dut.io.csr_w.poke(0.U)
    dut.io.csr_r.poke(0.U)
    dut.io.wen.poke(false.B)
    dut.io.wdata.poke(0.U)
    dut.io.cur_pc.poke(0.U)
    dut.io.interruption.poke(false.B)
    dut.io.ok_to_step.poke(true.B)
    dut.reset.poke(true.B)
    dut.clock.step()
    dut.reset.poke(false.B)
  }

  def write(dut: CSR, addr: Int, data: Long): Unit = {
    dut.io.csr_w.poke(addr.U)
    dut.io.wdata.poke(data.U)
    dut.io.wen.poke(true.B)
    dut.clock.step()
    dut.io.wen.poke(false.B)
  }

  behavior of "CSR"

  it should "read fixed and reset values" in {
    simulate(new CSR) { dut =>
      initialize(dut)

      dut.io.csr_r.poke(0xf11.U)
      dut.io.rdata.expect(0x79737978L.U)

      dut.io.csr_r.poke(0xf12.U)
      dut.io.rdata.expect(0x017eb198L.U)

      dut.io.csr_r.poke(0x300.U)
      dut.io.rdata.expect(0x1800.U)

      dut.io.csr_r.poke(0x342.U)
      dut.io.rdata.expect(11.U)

      dut.io.csr_r.poke(0xb00.U)
      dut.io.rdata.expect(0.U)
      dut.io.mcycle.expect(0.U)
    }
  }

  it should "write and preserve machine CSRs" in {
    simulate(new CSR) { dut =>
      initialize(dut)

      write(dut, 0x300, 0x00001888L)
      dut.io.csr_r.poke(0x300.U)
      dut.io.rdata.expect(0x00001888L.U)

      write(dut, 0x305, 0x80000100L)
      dut.io.csr_r.poke(0x305.U)
      dut.io.rdata.expect(0x80000100L.U)
      dut.io.mtvec.expect(0x80000100L.U)

      write(dut, 0x341, 0x80000200L)
      dut.io.csr_r.poke(0x341.U)
      dut.io.rdata.expect(0x80000200L.U)
      dut.io.mepc.expect(0x80000200L.U)

      dut.io.csr_w.poke(0x305.U)
      dut.io.wdata.poke(0xdeadbeefL.U)
      dut.io.wen.poke(false.B)
      dut.clock.step()
      dut.io.mtvec.expect(0x80000100L.U)
    }
  }

  it should "increment and write both halves of mcycle" in {
    simulate(new CSR) { dut =>
      initialize(dut)

      write(dut, 0xb00, 0xfffffffeL)
      dut.io.csr_r.poke(0xb00.U)
      dut.io.rdata.expect(0xfffffffeL.U)

      dut.clock.step()
      dut.io.rdata.expect(0xffffffffL.U)

      dut.clock.step()
      dut.io.rdata.expect(0.U)
      dut.io.csr_r.poke(0xb80.U)
      dut.io.rdata.expect(1.U)

      write(dut, 0xb80, 0xabL)
      dut.io.csr_r.poke(0xb80.U)
      dut.io.rdata.expect(0xab.U)
      dut.io.csr_r.poke(0xb00.U)
      dut.io.rdata.expect(0.U)
      dut.io.mcycle.expect(0xab00000000L.U(64.W))
    }
  }

  it should "capture the interrupted program counter" in {
    simulate(new CSR) { dut =>
      initialize(dut)

      dut.io.cur_pc.poke(0x80000ff0L.U)
      dut.io.interruption.poke(true.B)
      dut.clock.step()
      dut.io.interruption.poke(false.B)

      dut.io.csr_r.poke(0x341.U)
      dut.io.rdata.expect(0x80000ff0L.U)
      dut.io.mepc.expect(0x80000ff0L.U)
    }
  }
}
