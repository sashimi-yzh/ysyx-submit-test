package npc.device

import chisel3._
import chisel3.util._
import npc.AXI.AXI4Bundle

class ysyx_26030092_CLINT extends Module{
    val AXI4_port = IO(Flipped(new AXI4Bundle))

    AXI4_port.initSlave()
    val mtime = IO(Input(UInt(64.W)))

    val out_hi = Reg(Bool())

    val s_idle :: s_busy :: Nil = Enum(2)
    val status = RegInit(s_idle)

    switch(status){
        is(s_idle){
            AXI4_port.arready := true.B
            when(AXI4_port.arvalid){
                out_hi := AXI4_port.araddr === (0x02000000L + 0XBFF8 + 4).U
                status := s_busy
            }
        }
        is(s_busy){
            AXI4_port.rdata := Mux(out_hi, mtime(63,32), mtime(31,0))
            AXI4_port.rresp := false.B
            AXI4_port.rlast := true.B
            AXI4_port.rvalid := true.B
            when(AXI4_port.rready){
                status := s_idle
            }
        }
    }

    val aw_got = RegInit(false.B)
    val w_got  = RegInit(false.B)
    val b_valid = RegInit(false.B)

    AXI4_port.awready := !aw_got && !b_valid
    AXI4_port.wready  := !w_got  && !b_valid
    AXI4_port.bvalid  := b_valid
    AXI4_port.bid     := 0.U
    AXI4_port.bresp   := 0.U

    when(AXI4_port.awvalid && AXI4_port.awready){ aw_got := true.B }
    when(AXI4_port.wvalid  && AXI4_port.wready ){ w_got  := true.B }
    when(aw_got && w_got && !b_valid){
        b_valid := true.B
        aw_got  := false.B
        w_got   := false.B
    }
    when(b_valid && AXI4_port.bready){ b_valid := false.B }
}

class ysyx_26030092_CLINT_AXI4Router extends Module {

  val in = IO(Flipped(new AXI4Bundle))
  val toCLINT = IO(new AXI4Bundle)
  val toSoC = IO(new AXI4Bundle)

  val CLINT_BASE = 0x02000000L
  val CLINT_SIZE = 0x10000L

  in.initSlave()
  toCLINT.initMaster()
  toSoC.initMaster()

  val r_idle :: r_busy :: Nil = Enum(2)
  val r_status = RegInit(r_idle)
  val r_sel_clint = RegInit(false.B)

  switch(r_status) {
    is(r_idle) {
      when(in.arvalid) {
        val isCLINT = (in.araddr >= CLINT_BASE.U) && (in.araddr < (CLINT_BASE + CLINT_SIZE).U)

        r_sel_clint := isCLINT
        r_status := r_busy

        when(isCLINT) {
          toCLINT.connectARFrom(in, true.B)
          toCLINT.connectRFrom(in, true.B)
        }.otherwise {
          toSoC.connectARFrom(in, true.B)
          toSoC.connectRFrom(in, true.B)
        }
      }
    }
    is(r_busy) {
      when(r_sel_clint) {
        toCLINT.connectARFrom(in, true.B)
        toCLINT.connectRFrom(in, true.B)
      }.otherwise {
        toSoC.connectARFrom(in, true.B)
        toSoC.connectRFrom(in, true.B)
      }

      when(in.rready && in.rvalid) {
        r_status := r_idle
      }
    }
  }

  val w_idle :: w_busy :: Nil = Enum(2)
  val w_status = RegInit(w_idle)
  val w_sel_clint = RegInit(false.B)

  switch(w_status) {
    is(w_idle) {
      when(in.awvalid) {
        val isCLINT = (in.awaddr >= CLINT_BASE.U) && (in.awaddr < (CLINT_BASE + CLINT_SIZE).U)

        w_sel_clint := isCLINT
        w_status := w_busy

        when(isCLINT) {
          toCLINT.connectAWFrom(in, true.B)
          toCLINT.connectWFrom(in, true.B)
          toCLINT.connectBFrom(in, true.B)
        }.otherwise {
          toSoC.connectAWFrom(in, true.B)
          toSoC.connectWFrom(in, true.B)
          toSoC.connectBFrom(in, true.B)
        }
      }
    }
    is(w_busy) {
      when(w_sel_clint) {
        toCLINT.connectAWFrom(in, true.B)
        toCLINT.connectWFrom(in, true.B)
        toCLINT.connectBFrom(in, true.B)
      }.otherwise {
        toSoC.connectAWFrom(in, true.B)
        toSoC.connectWFrom(in, true.B)
        toSoC.connectBFrom(in, true.B)
      }

      when(in.bready && in.bvalid) {
        w_status := w_idle
      }
    }
  }
}
