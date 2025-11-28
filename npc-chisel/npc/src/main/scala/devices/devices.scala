package npc.devices

import chisel3._
import chisel3.util._

// 设备地址范围定义类
case class DeviceRange(base: BigInt, size: BigInt) {
  val end: BigInt = base + size - 1
  def contains(address: BigInt): Boolean = address >= base && address < base + size
}

object ExtendedDevices {
  val RAM = DeviceRange(0x0000, 0x1000)
  val UART = DeviceRange(0x1000, 0x100)
  val I2C = DeviceRange(0x2000, 0x0100)
  val SPI = DeviceRange(0x3000, 0x1000)  // 新增SPI设备
  
  val allDevices = Seq(RAM, UART, I2C, SPI)
}
