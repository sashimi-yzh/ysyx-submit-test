package table
import chisel3._
object XbarTable {
  val sramBase  = "h0f00_0000".U
  val sramSize  = "h0000_2000".U
  val mromBase  = "h2000_0000".U
  val mromSize  = "h0000_1000".U
  val flashBase = "h3000_0000".U
  val flashSize = "h1000_0000".U
  val psramBase = "h8000_0000".U
  val psramSize = "h2000_0000".U
  val sdramBase = "ha000_0000".U
  val sdramSize = "h2000_0000".U
  val clintBase = "h0200_0000".U
  val clintSize = "h0001_0000".U
}
