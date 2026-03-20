package uart
import chisel3._
import chisel3.util._

import common_def._
import axi4._

import chisel3.util.circt.dpi._

import dpiwrap._

class UARTToStdOut extends BlackBox with HasBlackBoxInline {
  val io = IO(new Bundle {
    val clock   = Input(Clock())
    val enable  = Input(Bool())
    val chData  = Input(UInt(8.W))
  })
  setInline("UARTToStdOut.v",
  s"""
     |module UARTToStdOut(
     |  input clock,
     |  input enable,
     |  input [7:0] chData
     |);
     |  always @(posedge clock) begin
     |    if (enable) begin
     |      $$write("%c", chData);
     |      $$fflush();
     |    end
     |  end
     |endmodule
  """.stripMargin)
}


class UARTUnit extends Module {
  val io = IO(AXI4IO.Slave)

  io.dontCareAR()
  io.dontCareR()

  io.dontCareNonLiteB()

  val sio = io

  sio.awready := true.B
  sio.wready  := true.B

  sio.bvalid := true.B
  sio.bresp  := AXI4IO.BResp.OKAY

  val uartToStdOut = Module(new UARTToStdOut)
  uartToStdOut.io.clock := clock
  uartToStdOut.io.enable := sio.wvalid
  uartToStdOut.io.chData := sio.wdata(7, 0)

  // when(sio.wvalid) {
  //   val chData = sio.wdata(7, 0)
  //   // ClockedCallVoidDPIC("uart_putch")(
  //   //   clock,
  //   //   sio.wvalid,
  //   //   chData
  //   // )
  //   // InlinePrintf(cf"$chData%c")
  //   SkipDifftestRef(clock, sio.wvalid)
  // }
}
