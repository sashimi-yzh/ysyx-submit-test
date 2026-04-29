package npc

import chisel3._
import chisel3.util._

import axi4._
import xbar._
import uart._
import testSoC._

import common_def._

class NPCDevices extends Module with TestSoCDevice {
  val io = IO(AXI4IO.Slave)
  io := DontCare

  val uart = Module(new UARTUnit)
  val mem  = Module(new AXI4MemUnit(1024 * 1024 * 128, Some("build/npcmem_init.hex")))

  val startupROM = Module(new AXI4MemUnit(1024, Some("jmpROM/build/jmp.hex")))

  io <> AXI4XBar(
    Seq(
      AddrSpace.FLASH -> startupROM.io,
      AddrSpace.NPCMEM -> mem.io,
      AddrSpace.SERIAL -> uart.io
    )
  )
}
