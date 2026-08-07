package xbar

import chisel3._
import chisel3.util._
import org.chipsalliance.cde.config.Parameters
import org.chipsalliance.diplomacy.lazymodule.{LazyModule, LazyModuleImp}
import axi4._
import diplomatic._

class Clint(
  implicit p: Parameters)
    extends LazyModule {
  val node = new AXI4SlaveNode(
    AXI4SlaveNodeParameters(
      AddressSet.misaligned(0x02000000L, 0x10000L)
    )
  )

  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) {
    val (in, edge)             = node.in.head
    val s_idl :: s_resp :: Nil = Enum(2)
    val loadState              = RegInit(s_idl)
    val loadId                 = Reg(UInt(edge.master.idBits.W))
    val mtime                  = RegInit(0.U(64.W))
    val mtimeLatch             = Reg(UInt(64.W))
    val offset                 = Reg(UInt(16.W))
    mtime          := mtime + 1.U
    // load
    in.ar.ready    := loadState === s_idl
    in.r.valid     := loadState === s_resp
    in.r.bits.data := Mux(offset === 0.U, mtimeLatch(31, 0), mtimeLatch(63, 32))
    in.r.bits.id   := loadId
    in.r.bits.last := true.B
    in.r.bits.resp := AXI4RespEnum.OKAY
    loadState      := MuxLookup(loadState, s_idl)(
      Seq(
        s_idl  -> Mux(in.ar.fire, s_resp, s_idl),
        s_resp -> Mux(in.r.fire, s_idl, s_resp)
      )
    )
    switch(loadState) {
      is(s_idl) {
        when(in.ar.fire) {
          offset := in.ar.bits.addr(15, 0)
          when(offset === 4.U) {
            mtimeLatch := mtime
          }
          loadId := in.ar.bits.id
        }
      }
    }
    // store
    in.aw.ready    := true.B
    in.w.ready     := true.B
    in.b.valid     := true.B
    in.b.bits.id   := in.aw.bits.id
    in.b.bits.resp := AXI4RespEnum.SLVERR
  }
}
