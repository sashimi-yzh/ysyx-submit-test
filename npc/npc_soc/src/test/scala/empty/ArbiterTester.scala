package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class ArbiterTester extends AnyFlatSpec {
  def clearMaster(axi: AXI): Unit = {
    axi.aw.valid.poke(false.B)
    axi.aw.addr.poke(0.U)
    axi.aw.id.poke(0.U)
    axi.aw.len.poke(0.U)
    axi.aw.size.poke(0.U)
    axi.aw.burst.poke(0.U)
    axi.w.valid.poke(false.B)
    axi.w.data.poke(0.U)
    axi.w.strb.poke(0.U)
    axi.w.last.poke(false.B)
    axi.b.ready.poke(false.B)
    axi.ar.valid.poke(false.B)
    axi.ar.addr.poke(0.U)
    axi.ar.id.poke(0.U)
    axi.ar.len.poke(0.U)
    axi.ar.size.poke(0.U)
    axi.ar.burst.poke(0.U)
    axi.r.ready.poke(false.B)
  }

  def clearSlave(axi: AXI): Unit = {
    axi.aw.ready.poke(false.B)
    axi.w.ready.poke(false.B)
    axi.b.valid.poke(false.B)
    axi.b.resp.poke(0.U)
    axi.b.id.poke(0.U)
    axi.ar.ready.poke(false.B)
    axi.r.valid.poke(false.B)
    axi.r.resp.poke(0.U)
    axi.r.data.poke(0.U)
    axi.r.last.poke(false.B)
    axi.r.id.poke(0.U)
  }

  def initialize(dut: Arbiter_2Master): Unit = {
    clearMaster(dut.IFU_AXI)
    clearMaster(dut.LSU_AXI)
    clearSlave(dut.OUT_AXI)
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

  def setReadRequest(axi: AXI, addr: Long, id: Int): Unit = {
    axi.ar.addr.poke(addr.U)
    axi.ar.id.poke(id.U)
    axi.ar.len.poke(0.U)
    axi.ar.size.poke(2.U)
    axi.ar.burst.poke(1.U)
    axi.ar.valid.poke(true.B)
  }

  def setReadResponse(axi: AXI, data: Long, id: Int): Unit = {
    axi.r.data.poke(data.U)
    axi.r.resp.poke(0.U)
    axi.r.id.poke(id.U)
    axi.r.last.poke(true.B)
    axi.r.valid.poke(true.B)
  }

  behavior of "Arbiter_2Master"

  it should "route IFU reads and responses" in {
    simulate(new Arbiter_2Master) { dut =>
      initialize(dut)
      setReadRequest(dut.IFU_AXI, 0x80000000L, 1)

      waitUntil(dut.clock) {
        dut.OUT_AXI.ar.valid.peek().litToBoolean
      }
      dut.OUT_AXI.ar.addr.expect(0x80000000L.U)
      dut.OUT_AXI.ar.id.expect(1.U)
      dut.OUT_AXI.ar.len.expect(0.U)
      dut.OUT_AXI.ar.size.expect(2.U)
      dut.OUT_AXI.ar.burst.expect(1.U)
      dut.LSU_AXI.ar.ready.expect(false.B)

      dut.OUT_AXI.ar.ready.poke(true.B)
      transfer(dut.clock, dut.IFU_AXI.ar.valid, dut.IFU_AXI.ar.ready)
      dut.IFU_AXI.ar.valid.poke(false.B)
      dut.OUT_AXI.ar.ready.poke(false.B)

      setReadResponse(dut.OUT_AXI, 0x12345678L, 1)
      waitUntil(dut.clock) {
        dut.IFU_AXI.r.valid.peek().litToBoolean
      }
      dut.IFU_AXI.r.data.expect(0x12345678L.U)
      dut.IFU_AXI.r.resp.expect(0.U)
      dut.IFU_AXI.r.id.expect(1.U)
      dut.IFU_AXI.r.last.expect(true.B)
      dut.LSU_AXI.r.valid.expect(false.B)

      dut.IFU_AXI.r.ready.poke(true.B)
      transfer(dut.clock, dut.IFU_AXI.r.valid, dut.IFU_AXI.r.ready)
      dut.OUT_AXI.r.valid.poke(false.B)
      dut.IFU_AXI.r.ready.poke(false.B)
    }
  }

  it should "prioritize LSU read requests" in {
    simulate(new Arbiter_2Master) { dut =>
      initialize(dut)
      setReadRequest(dut.IFU_AXI, 0x80000000L, 1)
      setReadRequest(dut.LSU_AXI, 0x80001000L, 8)

      waitUntil(dut.clock) {
        dut.OUT_AXI.ar.valid.peek().litToBoolean
      }
      dut.OUT_AXI.ar.addr.expect(0x80001000L.U)
      dut.OUT_AXI.ar.id.expect(8.U)
      dut.IFU_AXI.ar.ready.expect(false.B)

      dut.OUT_AXI.ar.ready.poke(true.B)
      transfer(dut.clock, dut.LSU_AXI.ar.valid, dut.LSU_AXI.ar.ready)
      dut.IFU_AXI.ar.valid.poke(false.B)
      dut.LSU_AXI.ar.valid.poke(false.B)
      dut.OUT_AXI.ar.ready.poke(false.B)

      setReadResponse(dut.OUT_AXI, 0x89abcdefL, 8)
      waitUntil(dut.clock) {
        dut.LSU_AXI.r.valid.peek().litToBoolean
      }
      dut.LSU_AXI.r.data.expect(0x89abcdefL.U)
      dut.IFU_AXI.r.valid.expect(false.B)

      dut.LSU_AXI.r.ready.poke(true.B)
      transfer(dut.clock, dut.LSU_AXI.r.valid, dut.LSU_AXI.r.ready)
      dut.OUT_AXI.r.valid.poke(false.B)
      dut.LSU_AXI.r.ready.poke(false.B)
    }
  }

  it should "route LSU writes and responses" in {
    simulate(new Arbiter_2Master) { dut =>
      initialize(dut)
      dut.LSU_AXI.aw.addr.poke(0x80002000L.U)
      dut.LSU_AXI.aw.id.poke(8.U)
      dut.LSU_AXI.aw.len.poke(0.U)
      dut.LSU_AXI.aw.size.poke(2.U)
      dut.LSU_AXI.aw.burst.poke(1.U)
      dut.LSU_AXI.aw.valid.poke(true.B)
      dut.LSU_AXI.w.data.poke(0xdeadbeefL.U)
      dut.LSU_AXI.w.strb.poke("b1111".U)
      dut.LSU_AXI.w.last.poke(true.B)
      dut.LSU_AXI.w.valid.poke(true.B)

      waitUntil(dut.clock) {
        dut.OUT_AXI.aw.valid.peek().litToBoolean &&
        dut.OUT_AXI.w.valid.peek().litToBoolean
      }
      dut.OUT_AXI.aw.addr.expect(0x80002000L.U)
      dut.OUT_AXI.aw.id.expect(8.U)
      dut.OUT_AXI.w.data.expect(0xdeadbeefL.U)
      dut.OUT_AXI.w.strb.expect("b1111".U)
      dut.OUT_AXI.w.last.expect(true.B)

      dut.OUT_AXI.aw.ready.poke(true.B)
      dut.OUT_AXI.w.ready.poke(true.B)
      waitUntil(dut.clock) {
        dut.LSU_AXI.aw.ready.peek().litToBoolean &&
        dut.LSU_AXI.w.ready.peek().litToBoolean
      }
      dut.clock.step()
      dut.LSU_AXI.aw.valid.poke(false.B)
      dut.LSU_AXI.w.valid.poke(false.B)
      dut.OUT_AXI.aw.ready.poke(false.B)
      dut.OUT_AXI.w.ready.poke(false.B)

      dut.OUT_AXI.b.resp.poke(0.U)
      dut.OUT_AXI.b.id.poke(8.U)
      dut.OUT_AXI.b.valid.poke(true.B)
      waitUntil(dut.clock) {
        dut.LSU_AXI.b.valid.peek().litToBoolean
      }
      dut.LSU_AXI.b.resp.expect(0.U)
      dut.LSU_AXI.b.id.expect(8.U)

      dut.LSU_AXI.b.ready.poke(true.B)
      transfer(dut.clock, dut.LSU_AXI.b.valid, dut.LSU_AXI.b.ready)
      dut.OUT_AXI.b.valid.poke(false.B)
      dut.LSU_AXI.b.ready.poke(false.B)
    }
  }
}
