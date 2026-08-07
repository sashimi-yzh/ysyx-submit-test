package top

import chisel3._
import dto._
import chisel3.util._
import enums._
import axi4._
import org.chipsalliance.cde.config.Parameters
import config.Configs

class MemoryAccess(
  implicit p: Parameters)
    extends Module {
  val io                                                                  = IO(new Bundle {
    val exu     = Flipped(Decoupled(new Ex2Ma))
    val wbu     = Decoupled(new Ma2Wb)
    val axi     = new AXI4Bundle(new AXI4Parameters)
    // fence.i
    val fence_i = Output(new PcRedirect)
    // forward
    val forward = Output(new RegForward)
  })
  val s_wait_exu :: s_store :: s_load_ar :: s_load_r :: s_send_out :: Nil = Enum(5)
  val state                                                               = RegInit(s_wait_exu)
  val exuInfo                                                             = Reg(new Ex2Ma)
  val awSent                                                              = Reg(Bool())
  val wSent                                                               = Reg(Bool())
  val memStrb                                                             = MuxLookup(exuInfo.memSize, 0.U)(
    Seq(
      "b000".U -> "b0001".U,
      "b001".U -> "b0011".U,
      "b010".U -> "b1111".U
    )
  )
  io.wbu.bits.rd := exuInfo.rd
  io.wbu.bits.writeData    := exuInfo.rdData
  io.wbu.bits.writeEn      := exuInfo.rdWriteEn
  io.wbu.bits.mret         := exuInfo.mret
  io.wbu.bits.pc           := exuInfo.pc
  if (p(Configs.DebugMode)) {
    io.wbu.bits.npc         := exuInfo.npc
    io.wbu.bits.instruction := exuInfo.instruction
  }
  io.exu.ready             := state === s_wait_exu
  io.wbu.bits.csrWriteEn   := exuInfo.csrWriteEn
  io.wbu.bits.csrWriteAddr := exuInfo.csrWriteAddr
  io.wbu.bits.csrWriteData := exuInfo.csrWriteData
  io.wbu.bits.exception    := exuInfo.exception
  io.wbu.bits.exceptionNum := exuInfo.exceptionNum
  io.fence_i.valid         := RegNext(io.exu.fire, false.B) && io.exu.bits.fence_i
  io.fence_i.npc           := exuInfo.pc + 4.U
  // forwarding
  io.forward.valid         := state =/= s_wait_exu && exuInfo.rdWriteEn && exuInfo.rd =/= 0.U
  io.forward.dataValid     := state === s_send_out && (!exuInfo.needMA || exuInfo.rdWriteEn)
  io.forward.rd            := exuInfo.rd
  io.forward.rdData        := exuInfo.rdData
  // init axi
  val byteOffset = exuInfo.memAddr(1, 0)
  val bitOffset  = Cat(byteOffset, 0.U(3.W))
  io.axi.aw.valid      := state === s_store && !awSent
  io.axi.aw.bits.addr  := exuInfo.memAddr
  io.axi.aw.bits.id    := 0.U
  io.axi.aw.bits.len   := 0.U
  io.axi.aw.bits.size  := exuInfo.memSize
  io.axi.aw.bits.burst := AXI4BurstEnum.FIXED
  io.axi.w.valid       := state === s_store && !wSent
  io.axi.w.bits.data   := exuInfo.rdData << bitOffset
  io.axi.w.bits.strb   := memStrb << byteOffset
  io.axi.w.bits.last   := true.B
  io.axi.ar.valid      := state === s_load_ar
  io.axi.ar.bits.addr  := exuInfo.memAddr
  io.axi.ar.bits.burst := AXI4BurstEnum.FIXED
  io.axi.ar.bits.id    := 0.U
  io.axi.ar.bits.len   := 0.U
  io.axi.ar.bits.size  := exuInfo.memSize
  io.axi.r.ready       := state === s_load_r
  io.axi.b.ready       := state === s_store && awSent && wSent
  io.wbu.valid         := state === s_send_out
  val addrMisaligned = MuxLookup(io.exu.bits.memSize, false.B)(
    Seq(
      "b000".U -> false.B,
      "b001".U -> io.exu.bits.memAddr(0),
      "b010".U -> (io.exu.bits.memAddr(1, 0) =/= 0.U)
    )
  )
  state := MuxLookup(state, s_wait_exu)(
    Seq(
      s_wait_exu -> Mux(
        io.exu.fire,
        Mux(
          io.exu.bits.exception || (io.exu.bits.needMA && addrMisaligned) || !io.exu.bits.needMA,
          s_send_out,
          Mux(io.exu.bits.rdWriteEn, s_load_ar, s_store)
        ),
        s_wait_exu
      ),
      s_store    -> Mux(io.axi.b.fire, s_send_out, s_store),
      s_load_ar  -> Mux(io.axi.ar.fire, s_load_r, s_load_ar),
      s_load_r   -> Mux(io.axi.r.fire, s_send_out, s_load_r),
      s_send_out -> Mux(io.wbu.fire, s_wait_exu, s_send_out)
    )
  )
  switch(state) {
    is(s_wait_exu) {
      when(io.exu.fire) {
        awSent  := false.B
        wSent   := false.B
        exuInfo := io.exu.bits
        when(io.exu.bits.needMA && addrMisaligned && !io.exu.bits.exception) {
          exuInfo.exception    := true.B
          exuInfo.exceptionNum := Mux(
            io.exu.bits.rdWriteEn,
            SynchronousException.LoadAddressMisaligned,
            SynchronousException.Store_AMO_AddressMisaligned
          )
        }
      }
    }
    is(s_store) {
      when(io.axi.aw.fire) {
        awSent := true.B
      }
      when(io.axi.w.fire) {
        wSent := true.B
      }
      when(io.axi.b.fire) {
        when(io.axi.b.bits.resp =/= AXI4RespEnum.OKAY) {
          exuInfo.exception    := true.B
          exuInfo.exceptionNum := SynchronousException.Store_AMO_Access_Fault
        }
      }
    }
    is(s_load_ar) {}
    is(s_load_r) {
      val rdata    = io.axi.r.bits.data >> bitOffset
      val byteData = rdata(7, 0)
      val halfData = rdata(15, 0)
      val wordData = rdata(31, 0)
      when(io.axi.r.fire) {
        exuInfo.rdData := MuxLookup(exuInfo.memSize, 0.U(32.W))(
          Seq(
            "b000".U -> Mux(exuInfo.memSignEx, byteData.asSInt.pad(32).asUInt, byteData.zext.asUInt),
            "b001".U -> Mux(exuInfo.memSignEx, halfData.asSInt.pad(32).asUInt, halfData.zext.asUInt),
            "b010".U -> wordData
          )
        )
        when(io.axi.r.bits.resp =/= AXI4RespEnum.OKAY) {
          exuInfo.exception    := true.B
          exuInfo.exceptionNum := SynchronousException.LoadAccessFault
        }
      }
    }
  }
}
