package AXI4


import chisel3._
import chisel3.util._
import freechips.rocketchip.amba.axi4._

class AXILite2AXI(addrWidthBits: Int, dataWidthBits: Int) extends Module{
    val io = IO(new Bundle{
        val axilite = new AXILiteSlaveIF(addrWidthBits,dataWidthBits)
        //val axi = new AXIBundle(addrWidthBits,dataWidthBits)
        val axi = new AXI4Bundle( AXI4BundleParameters(
                                  addrBits = addrWidthBits, 
                                  dataBits = dataWidthBits, 
                                  idBits = 4))
    })

    val axi = io.axi
    val axilite = io.axilite

  axi.aw.bits.addr := axilite.aw.bits.addr
  axi.aw.valid := axilite.aw.valid
  axilite.aw.ready := axi.aw.ready

  axi.w.bits.data := axilite.w.bits.data
  axi.w.bits.strb := axilite.w.bits.strb
  axi.w.valid := axilite.w.valid
  axilite.w.ready := axi.w.ready

  axi.b.ready := axilite.b.ready
  axilite.b.bits := axi.b.bits.resp
  axilite.b.valid := axi.b.valid

  axi.ar.bits.addr := axilite.ar.bits.addr
  axi.ar.valid := axilite.ar.valid
  axilite.ar.ready := axi.ar.ready

  axi.r.ready := axilite.r.ready
  axilite.r.valid := axi.r.valid
  axilite.r.bits.data := axi.r.bits.data
  axilite.r.bits.resp := axi.r.bits.resp

  axi.aw.bits.len := 0.U
  axi.aw.bits.size := 2.U
  axi.aw.bits.burst := 0.U
  axi.w.bits.last := true.B
  axi.aw.bits.id := 0.U
  axi.ar.bits.burst := 0.U
  axi.ar.bits.len := 0.U
  axi.ar.bits.size := 2.U
  axi.ar.bits.burst := 0.U
 // axi.rlast := true.B
  axi.ar.bits.id := 0.U
  
  
  axi.aw.bits.lock := 0.U
  axi.aw.bits.cache := 0.U
  axi.aw.bits.prot := 0.U
  axi.aw.bits.qos := 0.U
  axi.ar.bits.lock := 0.U
  axi.ar.bits.cache := 0.U
  axi.ar.bits.prot := 0.U
  axi.ar.bits.qos := 0.U


}