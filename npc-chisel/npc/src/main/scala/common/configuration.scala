package npc
package common

import chisel3._
import chisel3.util._

case class Config(
 xprlen: Int = 32) {
    val xlen = xprlen
    val idBits = 4
    val sizeBits = 3
    val lenBits = 8
    val burstBits = 2
    val maskBits = xlen/8
    val perfCountBits = 32
    val AXIBurstLenBits = 8
    val USE_FULL_BYPASSING = true
    val regfileDepth = 16
    
    val burstLength = sys.env.get("BURST_LENGTH").map(_.toInt).getOrElse(1)   // burstLength = axlen - 1   
    val ICacheSizeBits = sys.env.get("ICACHE_SIZE_BITS").map(_.toInt).getOrElse(2)
    val ICacheBlockBits = sys.env.get("ICACHE_BLOCK_BITS").map(_.toInt).getOrElse(1)
    val EnableBurst = sys.env.get("ICACHE_ENABLE_BURST").map(java.lang.Boolean.parseBoolean).getOrElse(false)
    val ICacheEnableBurst = if (EnableBurst) true.B else false.B
    val EnableSOC = sys.env.get("ENABLE_SOC").map(java.lang.Boolean.parseBoolean).getOrElse(true)
    val ENABLE_DEBUG =  sys.env.get("NPC_ENABLE_DEBUG").map(java.lang.Boolean.parseBoolean).getOrElse(false)
    // val START_ADDR = if (EnableSOC) 0x30000000L.U(32.W) else 0x80000000L.U(32.W)
    val START_ADDR =  0x30000000L.U(32.W)
    val ENABLE_IVERILOG = sys.env.get("NPC_ENABLE_IVERILOG").map(java.lang.Boolean.parseBoolean).getOrElse(false)
}