package top

import chisel3._
import chisel3.util._
class LSU2WBU extends EXU2LSU {
  val dpic_memAddr   = UInt(32.W)
  val dpic_memRdata  = UInt(32.W)
  val dpic_memWdata  = UInt(32.W)
  val dpic_memRValid = Bool()
  val dpic_memWValid = Bool()
}
class LSU     extends Module  {
  val io = IO(new Bundle {
    val in  = Flipped(Decoupled(new EXU2LSU))
    val out = Decoupled(new LSU2WBU)
    val axi = new AXI4IO
  })

  DriveZeroSinks(io.axi)
  BundleConnect(io.in.bits, io.out.bits)

  io.out.valid := false.B
  io.in.ready  := false.B

  io.out.bits.dpic_memRValid := false.B
  io.out.bits.dpic_memWValid := false.B

  // 组合逻辑解码
  val in      = io.in.bits
  val ctrl    = in.ctrl
  val memAddr = in.result

  // 写
  val wdata = MuxLookup(ctrl.memLen, in.rdata2)(
    Seq(
      MemLen.BYTE -> Fill(4, in.rdata2(7, 0)),
      MemLen.HALF -> Fill(2, in.rdata2(15, 0)),
      MemLen.WORD -> in.rdata2
    )
  )

  val wstrb = MuxLookup(ctrl.memLen, "b0000".U)(
    Seq(
      MemLen.BYTE -> UIntToOH(memAddr(1, 0)),
      MemLen.HALF -> Mux(memAddr(1), "b1100".U, "b0011".U),
      MemLen.WORD -> "b1111".U
    )
  )

  // 读
  val bytes = VecInit.tabulate(4)(i => io.axi.r.data(8 * i + 7, 8 * i))
  val b     = bytes(memAddr(1, 0))
  val h     = Mux(memAddr(1), Cat(bytes(3), bytes(2)), Cat(bytes(1), bytes(0)))

  val readByte = Mux(ctrl.memSext, b.asSInt.pad(32).asUInt, b.pad(32))
  val readHalf = Mux(ctrl.memSext, h.asSInt.pad(32).asUInt, h.pad(32))

  val memReadData = MuxLookup(ctrl.memLen, io.axi.r.data)(
    Seq(
      MemLen.BYTE -> readByte,
      MemLen.HALF -> readHalf,
      MemLen.WORD -> io.axi.r.data
    )
  )

  // 状态机控制AXI4读写事务

  val memRdataReg = Reg(UInt(32.W))
  object State extends ChiselEnum {
    val sIdle, sArWait, sAwWait, sRWait, sBWait = Value
  }
  val state = RegInit(State.sIdle)

  val awDone = RegInit(false.B)
  val wDone  = RegInit(false.B)
  when(io.axi.aw.valid && io.axi.aw.ready) {
    awDone := true.B
  }
  when(io.axi.w.valid && io.axi.w.ready) {
    wDone := true.B
  }

  io.axi.ar.addr  := memAddr
  io.axi.ar.valid := state === State.sArWait
  io.axi.ar.size  := ctrl.memLen
  io.axi.ar.len   := 0.U
  io.axi.r.ready  := state === State.sRWait

  io.axi.aw.addr  := memAddr
  io.axi.aw.valid := state === State.sAwWait && !awDone
  io.axi.aw.len   := 0.U
  io.axi.aw.size  := ctrl.memLen
  io.axi.w.data   := wdata
  io.axi.w.strb   := wstrb
  io.axi.w.valid  := state === State.sAwWait && !wDone
  io.axi.w.last   := true.B
  io.axi.b.ready  := state === State.sBWait

  switch(state) {
    is(State.sIdle) {
      io.out.valid := io.in.valid
      io.in.ready  := true.B

      when(io.in.valid && !io.in.bits.ctrl.excValid) {
        when(io.in.bits.ctrl.memR) {
          io.out.valid := false.B
          io.in.ready  := false.B
          state        := State.sArWait
        }.elsewhen(io.in.bits.ctrl.memWen) {
          io.out.valid := false.B
          io.in.ready  := false.B
          state        := State.sAwWait
          wDone        := false.B
          awDone       := false.B
        }
      }
    }
    is(State.sArWait) {
      when(io.axi.ar.valid && io.axi.ar.ready) {
        state := State.sRWait
      }
    }
    is(State.sAwWait) {
      when((awDone || io.axi.aw.ready) && (wDone || io.axi.w.ready)) {
        state := State.sBWait
      }
    }
    is(State.sRWait) {
      when(io.axi.r.valid && io.axi.r.ready) {
        state        := State.sIdle
        io.in.ready  := true.B
        io.out.valid := io.in.valid
        when(io.axi.r.resp =/= 0.U) {
          io.out.bits.ctrl.excType  := ExceptionType.LoadAccessFault
          io.out.bits.ctrl.excValid := true.B
        }

        io.out.bits.dpic_memRValid := true.B
      }
    }
    is(State.sBWait) {
      when(io.axi.b.valid && io.axi.b.ready) {
        state        := State.sIdle
        io.in.ready  := true.B
        io.out.valid := io.in.valid
        when(io.axi.b.resp =/= 0.U) {
          io.out.bits.ctrl.excType  := ExceptionType.StoreAccessFault
          io.out.bits.ctrl.excValid := true.B
        }

        io.out.bits.dpic_memWValid := true.B
      }
    }

  }

  when(ctrl.rdSel === RdSel.MEM) {
    io.out.bits.gprWdata := memReadData
  }
  io.out.bits.dpic_memAddr  := memAddr
  io.out.bits.dpic_memRdata := memRdataReg
  io.out.bits.dpic_memWdata := in.rdata2

  when(ctrl.excValid) {
    io.out.bits.ctrl.excType  := ctrl.excType
    io.out.bits.ctrl.excValid := true.B
  }
}
