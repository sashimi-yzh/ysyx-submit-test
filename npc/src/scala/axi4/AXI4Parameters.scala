package axi4

case class AXI4Parameters(addrBits: Int = 32, dataBits: Int = 32, idBits: Int = 4, lenBits: Int = 8) {
  val strbBits:   Int = dataBits / 8
  val sizeBits:   Int = 3
  val burstBits:  Int = 2
  val bRespWidth: Int = 2
  val rRespWidth: Int = 2
}
