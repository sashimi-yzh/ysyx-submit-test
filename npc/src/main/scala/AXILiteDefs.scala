package AXI4

//https://github.com/maltanar/axi-in-chisel



import chisel3._
import chisel3.util._
// import Literal._
// import Node._

// Part I: Definitions for the actual data carried over AXI channels
// in part II we will provide definitions for the actual AXI interfaces
// by wrapping the part I types in Decoupled (ready/valid) bundles


// AXI Lite channel data definitions

class AXILiteAddress(addrWidthBits: Int) extends Bundle {
  val addr    = UInt(addrWidthBits.W)
  val prot    = UInt(3.W)
  override def clone = { new AXILiteAddress(addrWidthBits).asInstanceOf[this.type] }
}

class AXILiteWriteData(dataWidthBits: Int) extends Bundle {
  val data    = UInt(dataWidthBits.W)
  val strb    = UInt((dataWidthBits/8).W)
  override def clone = { new AXILiteWriteData(dataWidthBits).asInstanceOf[this.type] }
}

class AXILiteReadData(dataWidthBits: Int) extends Bundle {
  val data    = UInt(dataWidthBits.W)
  val resp    = UInt(2.W)
  override def clone = { new AXILiteReadData(dataWidthBits).asInstanceOf[this.type] }
}

// Part II: Definitions for the actual AXI interfaces

class AXILiteSlaveIF(addrWidthBits: Int, dataWidthBits: Int) extends Bundle {
  // write address channel
  val aw   = Flipped(Decoupled(new AXILiteAddress(addrWidthBits)))
  // write data channel
  val w   = Flipped(Decoupled(new AXILiteWriteData(dataWidthBits)))
  // write response channel (for memory consistency)
  val b   = Decoupled(UInt(2.W))
  
  // read address channel
  val ar    = Flipped(Decoupled(new AXILiteAddress(addrWidthBits)))
  // read data channel
  val r    = Decoupled(new AXILiteReadData(dataWidthBits))
  
  
  override def clone = { new AXILiteSlaveIF(addrWidthBits, dataWidthBits).asInstanceOf[this.type] }
}



class AXILiteMasterIF(addrWidthBits: Int, dataWidthBits: Int) extends Bundle {  
  // write address channel
  val aw   = Decoupled(new AXILiteAddress(addrWidthBits))
  // write data channel
  val w   = Decoupled(new AXILiteWriteData(dataWidthBits))
  // write response channel (for memory consistency)
  val b   = Flipped(Decoupled(UInt(2.W)))
  
  // read address channel
  val ar    = Decoupled(new AXILiteAddress(addrWidthBits))
  // read data channel
  val r    = Flipped(Decoupled(new AXILiteReadData(dataWidthBits)))
  
  
  override def clone = { new AXILiteMasterIF(addrWidthBits, dataWidthBits).asInstanceOf[this.type] }
}


