package light
import chisel3._

class Light(maxCnt: Int = 5000000) extends Module {
  val io = IO(new Bundle {
    val led = Output(UInt(16.W))
  })
  val cntReg = RegInit(0.U(32.W))
  cntReg := Mux(cntReg === maxCnt.U, 0.U, cntReg + 1.U)
  val ledReg = RegInit(1.U(16.W))
  ledReg := Mux(cntReg === maxCnt.U, ledReg(14, 0) ## ledReg(15), ledReg)
  io.led := ledReg
}
