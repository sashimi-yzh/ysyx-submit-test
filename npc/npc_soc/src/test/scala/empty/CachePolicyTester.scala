package empty

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class __CachePolicy_test extends PrefixedModule {
  val io = IO(new Bundle {
    val addr = Input(UInt(32.W))
    val cacheable = Output(Bool())
  })

  io.cacheable := ShouldCache(io.addr)
}

class CachePolicyTester extends AnyFlatSpec {
  behavior of "CachePolicy"

  it should "accept cacheable address regions" in {
    simulate(new __CachePolicy_test) { dut =>
      Seq(
        0x30000000L,
        0x3fffffffL,
        0x80000000L,
        0x8fffffffL,
        0xa0000000L,
        0xafffffffL,
        0xb0000000L,
        0xbfffffffL,
        0x0f000000L,
        0x0fffffffL
      ).foreach { addr =>
        dut.io.addr.poke(addr.U)
        dut.io.cacheable.expect(true.B)
      }
    }
  }

  it should "reject non-cacheable address regions" in {
    simulate(new __CachePolicy_test) { dut =>
      Seq(
        0x00000000L,
        0x0effffffL,
        0x10000000L,
        0x40000000L,
        0x90000000L,
        0xc0000000L,
        0xffffffffL
      ).foreach { addr =>
        dut.io.addr.poke(addr.U)
        dut.io.cacheable.expect(false.B)
      }
    }
  }
}
