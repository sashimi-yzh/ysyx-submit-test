package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class IDUTester extends AnyFlatSpec {
  def initialize(dut: IDU): Unit = {
    dut.in.valid.poke(false.B)
    dut.in.bits.pc.poke(0.U)
    dut.in.bits.inst.poke(0.U)
    dut.in.bits.in_cache.poke(false.B)
    dut.out.ready.poke(false.B)
    dut.conf.stall.poke(false.B)
    dut.conf.do_forward_src1.poke(false.B)
    dut.conf.do_forward_src2.poke(false.B)
    dut.conf.forward_data_src1.poke(0.U)
    dut.conf.forward_data_src2.poke(0.U)
    dut.flush.valid.poke(false.B)
    dut.fetch_port_in.gpr_rdata1.poke("h11111111".U)
    dut.fetch_port_in.gpr_rdata2.poke("h22222222".U)
    dut.fetch_port_in.csr_rdata.poke("h33333333".U)
    dut.fetch_port_in.csr_mtvec.poke("h80000100".U)
    dut.fetch_port_in.csr_mepc.poke("h80000200".U)
    dut.reset.poke(true.B)
    dut.clock.step()
    dut.reset.poke(false.B)
  }

  def waitUntil(clock: Clock, limit: Int = 64)(condition: => Boolean): Unit = {
    var cycles = 0
    var reached = condition

    while (!reached && cycles < limit) {
      clock.step()
      cycles += 1
      reached = condition
    }

    assert(reached, s"timeout after $limit cycles")
  }

  def transfer(clock: Clock, valid: Bool, ready: Bool): Unit = {
    waitUntil(clock) {
      valid.peek().litToBoolean && ready.peek().litToBoolean
    }
    clock.step()
  }

  def issue(dut: IDU, pc: Long, inst: Long): Unit = {
    dut.in.bits.pc.poke(pc.U)
    dut.in.bits.inst.poke(inst.U)
    dut.in.bits.in_cache.poke(true.B)
    dut.in.valid.poke(true.B)
    transfer(dut.clock, dut.in.valid, dut.in.ready)
    dut.in.valid.poke(false.B)
  }

  def waitForOutput(dut: IDU): Unit = {
    waitUntil(dut.clock) {
      dut.out.valid.peek().litToBoolean
    }
  }

  def consumeOutput(dut: IDU): Unit = {
    dut.out.ready.poke(true.B)
    transfer(dut.clock, dut.out.valid, dut.out.ready)
    dut.out.ready.poke(false.B)
    waitUntil(dut.clock) {
      !dut.out.valid.peek().litToBoolean
    }
  }

  behavior of "IDU"

  it should "decode register arithmetic and forward operands" in {
    simulate(new IDU) { dut =>
      initialize(dut)
      issue(dut, 0x80000000L, 0x002081b3L)
      waitForOutput(dut)

      dut.out.bits.pc.expect(0x80000000L.U)
      dut.out.bits.inst.expect(0x002081b3L.U)
      dut.out.bits.controls.alu_controls.op.expect(ALUOp.ADD)
      dut.out.bits.controls.is_gpr_wen.expect(true.B)
      dut.out.bits.controls.rd.expect(3.U)
      dut.out.bits.flags.is_arithmetic_reg.expect(true.B)
      dut.fetch_port_out.gpr_raddr1.expect(1.U)
      dut.fetch_port_out.gpr_raddr2.expect(2.U)
      dut.conf.rs1_valid.expect(true.B)
      dut.conf.rs2_valid.expect(true.B)
      dut.out.bits.sources.src1.expect("h11111111".U)
      dut.out.bits.sources.src2_or_csr.expect("h22222222".U)

      dut.conf.do_forward_src1.poke(true.B)
      dut.conf.do_forward_src2.poke(true.B)
      dut.conf.forward_data_src1.poke("haaaaaaaa".U)
      dut.conf.forward_data_src2.poke("hbbbbbbbb".U)
      dut.out.bits.sources.src1.expect("haaaaaaaa".U)
      dut.out.bits.sources.src2_or_csr.expect("hbbbbbbbb".U)

      dut.clock.step(2)
      dut.out.valid.expect(true.B)
      dut.out.bits.pc.expect(0x80000000L.U)
      dut.out.bits.inst.expect(0x002081b3L.U)

      consumeOutput(dut)
    }
  }

  it should "decode load and store controls" in {
    simulate(new IDU) { dut =>
      initialize(dut)
      issue(dut, 0x80000004L, 0xffc32283L)
      waitForOutput(dut)

      dut.out.bits.controls.gpr_wdata_sel.expect(GprWdataSel.RAM)
      dut.out.bits.controls.ram_size.expect(RamSize.WORD)
      dut.out.bits.controls.is_load_unsigned.expect(false.B)
      dut.out.bits.controls.is_ram_valid.expect(true.B)
      dut.out.bits.controls.is_ram_wen.expect(false.B)
      dut.out.bits.controls.is_gpr_wen.expect(true.B)
      dut.out.bits.controls.rd.expect(5.U)

      consumeOutput(dut)
      issue(dut, 0x80000008L, 0xfe731c23L)
      waitForOutput(dut)

      dut.out.bits.controls.ram_size.expect(RamSize.HALF)
      dut.out.bits.controls.is_ram_valid.expect(true.B)
      dut.out.bits.controls.is_ram_wen.expect(true.B)
      dut.out.bits.controls.is_gpr_wen.expect(false.B)
      dut.out.bits.flags.is_store.expect(true.B)
      dut.conf.rs1_valid.expect(true.B)
      dut.conf.rs2_valid.expect(true.B)
    }
  }

  it should "decode CSR and exception instructions" in {
    simulate(new IDU) { dut =>
      initialize(dut)
      issue(dut, 0x8000000cL, 0x305110f3L)
      waitForOutput(dut)

      dut.out.bits.controls.is_csr_visit.expect(true.B)
      dut.out.bits.controls.gpr_wdata_sel.expect(GprWdataSel.CSR)
      dut.out.bits.controls.csrd.expect(0x305.U)
      dut.out.bits.controls.is_csr_masked.expect(false.B)
      dut.out.bits.sources.src2_or_csr.expect("h33333333".U)
      dut.conf.csr_src_valid.expect(true.B)
      dut.fetch_port_out.csr_raddr.expect(0x305.U)

      consumeOutput(dut)
      issue(dut, 0x80000010L, 0x00000073L)
      waitForOutput(dut)

      dut.out.bits.exception.expect(true.B)
      dut.out.bits.controls.is_csr_visit.expect(false.B)
      dut.out.bits.controls.is_gpr_wen.expect(false.B)
    }
  }

  it should "stall and flush a pending instruction" in {
    simulate(new IDU) { dut =>
      initialize(dut)
      issue(dut, 0x80000000L, 0x002081b3L)
      waitForOutput(dut)

      dut.conf.stall.poke(true.B)
      waitUntil(dut.clock) {
        !dut.out.valid.peek().litToBoolean
      }
      dut.in.ready.expect(false.B)
      dut.perf_cnt.stalled.expect(true.B)

      dut.flush.valid.poke(true.B)
      dut.perf_cnt.flushed.expect(true.B)
      dut.clock.step()

      dut.flush.valid.poke(false.B)
      dut.conf.stall.poke(false.B)
      waitUntil(dut.clock) {
        !dut.out.valid.peek().litToBoolean
      }
      dut.perf_cnt.stalled.expect(false.B)
    }
  }
}
