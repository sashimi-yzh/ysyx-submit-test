package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class XBarCLINTTester extends AnyFlatSpec {
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

  def initialize(dut: XBar_CLINT): Unit = {
    clearMaster(dut.IN_AXI)
    clearSlave(dut.OUT_AXI)
    clearSlave(dut.CLINT_AXI)
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

  def setReadRequest(dut: XBar_CLINT, addr: Long): Unit = {
    dut.IN_AXI.ar.addr.poke(addr.U)
    dut.IN_AXI.ar.id.poke(8.U)
    dut.IN_AXI.ar.len.poke(0.U)
    dut.IN_AXI.ar.size.poke(2.U)
    dut.IN_AXI.ar.burst.poke(1.U)
    dut.IN_AXI.ar.valid.poke(true.B)
  }

  def completeReadAddress(dut: XBar_CLINT, target: AXI, addr: Long): Unit = {
    setReadRequest(dut, addr)
    waitUntil(dut.clock) {
      target.ar.valid.peek().litToBoolean
    }
    target.ar.addr.expect(addr.U)
    target.ar.id.expect(8.U)
    target.ar.len.expect(0.U)
    target.ar.size.expect(2.U)
    target.ar.burst.expect(1.U)

    target.ar.ready.poke(true.B)
    transfer(dut.clock, dut.IN_AXI.ar.valid, dut.IN_AXI.ar.ready)
    dut.IN_AXI.ar.valid.poke(false.B)
    target.ar.ready.poke(false.B)
  }

  def completeReadResponse(dut: XBar_CLINT, target: AXI, data: Long): Unit = {
    target.r.data.poke(data.U)
    target.r.resp.poke(0.U)
    target.r.id.poke(8.U)
    target.r.last.poke(true.B)
    target.r.valid.poke(true.B)

    waitUntil(dut.clock) {
      dut.IN_AXI.r.valid.peek().litToBoolean
    }
    dut.IN_AXI.r.data.expect(data.U)
    dut.IN_AXI.r.resp.expect(0.U)
    dut.IN_AXI.r.id.expect(8.U)
    dut.IN_AXI.r.last.expect(true.B)

    dut.IN_AXI.r.ready.poke(true.B)
    transfer(dut.clock, dut.IN_AXI.r.valid, dut.IN_AXI.r.ready)
    target.r.valid.poke(false.B)
    dut.IN_AXI.r.ready.poke(false.B)
  }

  def completeWriteResponse(dut: XBar_CLINT, target: AXI): Unit = {
    target.b.resp.poke(0.U)
    target.b.id.poke(8.U)
    target.b.valid.poke(true.B)

    waitUntil(dut.clock) {
      dut.IN_AXI.b.valid.peek().litToBoolean
    }
    dut.IN_AXI.b.resp.expect(0.U)
    dut.IN_AXI.b.id.expect(8.U)

    dut.IN_AXI.b.ready.poke(true.B)
    transfer(dut.clock, dut.IN_AXI.b.valid, dut.IN_AXI.b.ready)
    target.b.valid.poke(false.B)
    dut.IN_AXI.b.ready.poke(false.B)
  }

  behavior of "XBar_CLINT"

  it should "route external read transactions" in {
    simulate(new XBar_CLINT) { dut =>
      initialize(dut)
      completeReadAddress(dut, dut.OUT_AXI, 0x80000000L)
      dut.CLINT_AXI.ar.valid.expect(false.B)

      completeReadResponse(dut, dut.OUT_AXI, 0x12345678L)
      dut.CLINT_AXI.r.ready.expect(false.B)
    }
  }

  it should "route CLINT read transactions" in {
    simulate(new XBar_CLINT) { dut =>
      initialize(dut)
      completeReadAddress(dut, dut.CLINT_AXI, 0x0200bff8L)
      dut.OUT_AXI.ar.valid.expect(false.B)

      completeReadResponse(dut, dut.CLINT_AXI, 0x89abcdefL)
      dut.OUT_AXI.r.ready.expect(false.B)
    }
  }

  it should "route external writes and responses" in {
    simulate(new XBar_CLINT) { dut =>
      initialize(dut)
      dut.IN_AXI.aw.addr.poke(0x80001000L.U)
      dut.IN_AXI.aw.id.poke(8.U)
      dut.IN_AXI.aw.len.poke(0.U)
      dut.IN_AXI.aw.size.poke(2.U)
      dut.IN_AXI.aw.burst.poke(1.U)
      dut.IN_AXI.aw.valid.poke(true.B)
      dut.IN_AXI.w.data.poke(0xdeadbeefL.U)
      dut.IN_AXI.w.strb.poke("b1111".U)
      dut.IN_AXI.w.last.poke(true.B)
      dut.IN_AXI.w.valid.poke(true.B)

      waitUntil(dut.clock) {
        dut.OUT_AXI.aw.valid.peek().litToBoolean &&
        dut.OUT_AXI.w.valid.peek().litToBoolean
      }
      dut.OUT_AXI.aw.addr.expect(0x80001000L.U)
      dut.OUT_AXI.aw.id.expect(8.U)
      dut.OUT_AXI.w.data.expect(0xdeadbeefL.U)
      dut.OUT_AXI.w.strb.expect("b1111".U)
      dut.CLINT_AXI.aw.valid.expect(false.B)
      dut.CLINT_AXI.w.valid.expect(false.B)

      dut.OUT_AXI.aw.ready.poke(true.B)
      dut.OUT_AXI.w.ready.poke(true.B)
      waitUntil(dut.clock) {
        dut.IN_AXI.aw.ready.peek().litToBoolean &&
        dut.IN_AXI.w.ready.peek().litToBoolean
      }
      dut.clock.step()
      dut.IN_AXI.aw.valid.poke(false.B)
      dut.IN_AXI.w.valid.poke(false.B)
      dut.OUT_AXI.aw.ready.poke(false.B)
      dut.OUT_AXI.w.ready.poke(false.B)

      completeWriteResponse(dut, dut.OUT_AXI)
      dut.CLINT_AXI.b.ready.expect(false.B)
    }
  }

  it should "preserve CLINT write ownership until response" in {
    simulate(new XBar_CLINT) { dut =>
      initialize(dut)
      dut.IN_AXI.aw.addr.poke(0x02000000L.U)
      dut.IN_AXI.aw.id.poke(8.U)
      dut.IN_AXI.aw.len.poke(0.U)
      dut.IN_AXI.aw.size.poke(2.U)
      dut.IN_AXI.aw.burst.poke(1.U)
      dut.IN_AXI.aw.valid.poke(true.B)

      waitUntil(dut.clock) {
        dut.CLINT_AXI.aw.valid.peek().litToBoolean
      }
      dut.CLINT_AXI.aw.addr.expect(0x02000000L.U)
      dut.OUT_AXI.aw.valid.expect(false.B)

      dut.CLINT_AXI.aw.ready.poke(true.B)
      transfer(dut.clock, dut.IN_AXI.aw.valid, dut.IN_AXI.aw.ready)
      dut.IN_AXI.aw.valid.poke(false.B)
      dut.CLINT_AXI.aw.ready.poke(false.B)

      dut.IN_AXI.aw.addr.poke(0x80000000L.U)
      dut.IN_AXI.w.data.poke(0x11223344L.U)
      dut.IN_AXI.w.strb.poke("b1111".U)
      dut.IN_AXI.w.last.poke(true.B)
      dut.IN_AXI.w.valid.poke(true.B)

      waitUntil(dut.clock) {
        dut.CLINT_AXI.w.valid.peek().litToBoolean
      }
      dut.CLINT_AXI.w.data.expect(0x11223344L.U)
      dut.OUT_AXI.w.valid.expect(false.B)

      dut.CLINT_AXI.w.ready.poke(true.B)
      transfer(dut.clock, dut.IN_AXI.w.valid, dut.IN_AXI.w.ready)
      dut.IN_AXI.w.valid.poke(false.B)
      dut.CLINT_AXI.w.ready.poke(false.B)

      completeWriteResponse(dut, dut.CLINT_AXI)
      dut.OUT_AXI.b.ready.expect(false.B)
    }
  }
}
