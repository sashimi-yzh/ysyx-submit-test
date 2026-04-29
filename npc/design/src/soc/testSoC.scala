package testSoC

import chisel3._
import chisel3.util._

import axi4._
import xbar._
import uart._

import top.{CPUCoreAsBlackBox, PCProviderAsBlackBox}

trait TestSoCDevice extends Module {
  val io: AXI4IO.SlaveT
}

class TestSoC[T <: TestSoCDevice](deviceGen: => T/*, val resetPC: UInt = "h80000000".U*/) extends Module {
  val cpu     = Module(new CPUCoreAsBlackBox)
  val devices = Module(deviceGen)

  // val resetPCProvider = Module(new PCProviderAsBlackBox)
  // assert(resetPCProvider.io.resetPC === resetPC, f"Reset PC should be 0x${resetPC.litValue}%x for ${devices.getClass.getSimpleName} SoC")

  devices.io <> cpu.io.io.master
  cpu.io.clock        := clock
  cpu.io.reset        := reset
  cpu.io.io.slave     := DontCare
  cpu.io.io.interrupt := false.B
}
