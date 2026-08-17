package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class WBUTester extends AnyFlatSpec {
  def initialize(dut: WBU): Unit = {
    dut.in.valid.poke(false.B)
    dut.in.bits.pc.poke(0.U)
    dut.in.bits.inst.poke(0.U)
    dut.in.bits.controls.is_csr_visit.poke(false.B)
    dut.in.bits.controls.is_gpr_wen.poke(false.B)
    dut.in.bits.controls.rd.poke(0.U)
    dut.in.bits.controls.csrd.poke(0.U)
    dut.in.bits.controls.is_ebreak.poke(false.B)
    dut.in.bits.write_info.mem_word_or_csr_wdata.poke(0.U)
    dut.in.bits.write_info.gpr_wdata.poke(0.U)
    dut.in.bits.write_info.dnpc.poke(0.U)
    dut.in.bits.exception.poke(false.B)
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

  def issue(dut: WBU): Unit = {
    dut.in.valid.poke(true.B)
    transfer(dut.clock, dut.in.valid, dut.in.ready)
    dut.in.valid.poke(false.B)
  }

  def waitForRetirement(dut: WBU): Unit = {
    waitUntil(dut.clock) {
      dut.out.ok_to_step.peek().litToBoolean
    }
  }

  behavior of "WBU"

  it should "retire and write normal instructions" in {
    simulate(new WBU) { dut =>
      initialize(dut)
      dut.out.ok_to_step.expect(false.B)

      dut.in.bits.pc.poke("h80000020".U)
      dut.in.bits.inst.poke("h305110f3".U)
      dut.in.bits.controls.is_csr_visit.poke(true.B)
      dut.in.bits.controls.is_gpr_wen.poke(true.B)
      dut.in.bits.controls.rd.poke(7.U)
      dut.in.bits.controls.csrd.poke("h305".U)
      dut.in.bits.controls.is_ebreak.poke(false.B)
      dut.in.bits.write_info.mem_word_or_csr_wdata.poke("h12345678".U)
      dut.in.bits.write_info.gpr_wdata.poke("h87654321".U)
      dut.in.bits.write_info.dnpc.poke("h80000024".U)
      dut.in.bits.exception.poke(false.B)
      issue(dut)
      waitForRetirement(dut)

      dut.out.retire_pc.expect("h80000020".U)
      dut.out.retire_inst.expect("h305110f3".U)
      dut.out.gpr_wen.expect(true.B)
      dut.out.gpr_waddr.expect(7.U)
      dut.out.gpr_wdata.expect("h87654321".U)
      dut.out.csr_wen.expect(true.B)
      dut.out.csr_waddr.expect("h305".U)
      dut.out.csr_wdata.expect("h12345678".U)
      dut.out.dnpc.expect("h80000024".U)
      dut.conf.rd_valid.expect(true.B)
      dut.conf.csr_dest_valid.expect(true.B)
      dut.conf.ok_to_forward_rd.expect(true.B)
      dut.conf.rd_data.expect("h87654321".U)

      waitUntil(dut.clock) {
        !dut.out.ok_to_step.peek().litToBoolean
      }
      dut.out.gpr_wen.expect(false.B)
      dut.out.csr_wen.expect(false.B)
    }
  }

  it should "suppress writes when retiring an exception" in {
    simulate(new WBU) { dut =>
      initialize(dut)

      dut.in.bits.pc.poke("h80000100".U)
      dut.in.bits.inst.poke("h00000073".U)
      dut.in.bits.controls.is_csr_visit.poke(true.B)
      dut.in.bits.controls.is_gpr_wen.poke(true.B)
      dut.in.bits.controls.rd.poke(10.U)
      dut.in.bits.controls.csrd.poke("h341".U)
      dut.in.bits.write_info.mem_word_or_csr_wdata.poke("h80000100".U)
      dut.in.bits.write_info.gpr_wdata.poke("hffffffff".U)
      dut.in.bits.exception.poke(true.B)
      issue(dut)
      waitForRetirement(dut)

      dut.out.csr_interruption.expect(true.B)
      dut.out.csr_cur_pc.expect("h80000100".U)
      dut.out.gpr_wen.expect(false.B)
      dut.out.csr_wen.expect(false.B)
    }
  }

  it should "report an ebreak instruction" in {
    simulate(new WBU) { dut =>
      initialize(dut)

      dut.in.bits.pc.poke("h80000200".U)
      dut.in.bits.inst.poke("h00100073".U)
      dut.in.bits.controls.is_ebreak.poke(true.B)
      issue(dut)
      waitForRetirement(dut)

      dut.out.ebreak.expect(true.B)
      dut.out.retire_pc.expect("h80000200".U)
      dut.out.retire_inst.expect("h00100073".U)
    }
  }
}
