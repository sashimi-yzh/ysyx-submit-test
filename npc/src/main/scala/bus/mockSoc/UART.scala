package top
import chisel3._
import chisel3.util._
import chisel3.ExtModule

class UART extends Module {
  val io    = IO(new Bundle {
    val axi = Flipped(new AXI4IO)
  })
  object State extends ChiselEnum {
    val sIdle, sBusy = Value
  }
  val state = RegInit(State.sIdle)

  DriveZeroSinks(io)

  val awreadyReg = RegInit(true.B)
  val wreadyReg  = RegInit(true.B)
  val bvalidReg  = RegInit(false.B)
  io.axi.aw.ready := awreadyReg
  io.axi.w.ready  := wreadyReg
  io.axi.b.valid  := bvalidReg

  val writer = Module(new WriteChar)
  writer.io.enable := false.B
  writer.io.data   := 0.U
  writer.io.clock := clock.asBool

  switch(state) {
    is(State.sIdle) {
      bvalidReg := false.B
      when(io.axi.aw.valid && io.axi.w.valid) {
        state      := State.sBusy
        awreadyReg := false.B
        wreadyReg  := false.B
      }
    }
    is(State.sBusy) {
      // printf("%c", io.axi.w.data(7, 0))
      writer.io.data   := io.axi.w.data(7, 0)
      writer.io.enable := true.B
      bvalidReg        := true.B
      when(io.axi.b.ready) {
        state      := State.sIdle
        awreadyReg := true.B
        wreadyReg  := true.B
      }
    }
  }

}

class WriteChar extends ExtModule {
  val io = IO(new Bundle {
    val data   = Input(UInt(8.W))
    val enable = Input(Bool())
    val clock = Input(Bool())
  })

  setInline(
    "WriteChar.v",
    """module WriteChar(
      |  input [7:0] io_data,
      |  input       io_enable,
      |  input       io_clock
      |);
      |
      |`ifdef __ICARUS__
      |  always @(posedge io_clock) begin
      |    if (io_enable) begin
      |      $write("%c", io_data);
      |    end
      |  end
      |
      |`else
      |  import "DPI-C" function void dpic_putch(input byte c);
      |
      |  always @(*) begin
      |    if (io_enable) begin
      |      dpic_putch(io_data);
      |    end
      |  end
      |`endif
      |
      |endmodule
    """.stripMargin
  )
}
