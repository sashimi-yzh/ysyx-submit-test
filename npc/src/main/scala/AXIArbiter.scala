package AXI4


import chisel3._
import chisel3.util._
import freechips.rocketchip.amba.axi4._


class ysyx_23060246_AXIArbiter(nMasters: Int, param : AXI4BundleParameters) extends Module {
  val io = IO(new Bundle {
    // multiple input 
    val in = Vec(nMasters, Flipped(new AXI4Bundle(param)))
    // single output 
    val out = new AXI4Bundle(param)
  })

    // 确保信号的初始化，防止未初始化信号的问题
  io.in.foreach { in =>
    // 读操作相关信号初始化
    in.ar.ready := false.B
    in.r.valid := false.B
    in.r.bits.data := 0.U
    in.r.bits.resp := 0.U
    in.r.bits.last := false.B
    in.r.bits.id := 0.U


    // 写操作相关信号初始化
    in.aw.ready := false.B
    in.w.ready := false.B
    in.b.valid := false.B
    in.b.bits.resp := 0.U
    in.b.bits.id := 0.U
  }

  
// 读操作仲裁
// 使用 Mux 来处理所有请求都无效的情况，默认返回第一个主设备
val readArbitrationValid = io.in.map(_.ar.valid).reduce(_ || _) // 如果任意一个主设备有效，则为 true
val readArbitrationIdx = PriorityEncoder(io.in.map(_.ar.valid)) // 使用 PriorityEncoder 选择请求最高优先级的主设备

// 使用寄存器来保持最终的仲裁索引
val readArbitrationFinalIdx = RegInit(0.U) 
val readArbitrationStarted = RegInit(false.B) 

// 写操作的状态可以更新
when (io.out.r.ready && io.out.r.valid && io.out.r.bits.last) {
  readArbitrationStarted := false.B
  readArbitrationFinalIdx := Mux(readArbitrationValid, readArbitrationIdx, 0.U) 
} .elsewhen (!readArbitrationStarted && readArbitrationValid) {
  readArbitrationStarted := true.B
  readArbitrationFinalIdx := readArbitrationIdx
}


  // 读操作传输
  io.out.ar.valid := io.in(readArbitrationFinalIdx).ar.valid
  io.out.ar.bits := io.in(readArbitrationFinalIdx).ar.bits
  io.out.r.ready := io.in(readArbitrationFinalIdx).r.ready
  io.in(readArbitrationFinalIdx).ar.ready := io.out.ar.ready
  io.in(readArbitrationFinalIdx).r.valid := io.out.r.valid
  io.in(readArbitrationFinalIdx).r.bits := io.out.r.bits


  // 写操作仲裁
// 使用 Mux 来处理所有请求都无效的情况，默认返回第一个主设备
val writeArbitrationValid = io.in.map(_.aw.valid).reduce(_ || _) // 如果任意一个主设备有效，则为 true
val writeArbitrationIdx = PriorityEncoder(io.in.map(_.aw.valid)) // 使用 PriorityEncoder 选择请求最高优先级的主设备

// 使用寄存器来保持最终的仲裁索引
val writeArbitrationFinalIdx = RegInit(0.U) // 初始化为 0（或者根据需要进行设置）
val writeArbitrationStarted = RegInit(false.B) // 用来标记是否开始了写操作

// 写操作的状态更新
when (io.out.b.ready && io.out.b.valid && io.out.w.bits.last) {
  // 当 b.ready 为 true 时，表示写操作已经完成，可以允许更新仲裁索引
  writeArbitrationStarted := false.B
  writeArbitrationFinalIdx := Mux(writeArbitrationValid, writeArbitrationIdx, 0.U) // 如果有有效请求，更新索引
} .elsewhen (!writeArbitrationStarted && writeArbitrationValid) {
  // 如果写操作还未开始且有有效的请求，更新仲裁索引
  writeArbitrationStarted := true.B
  writeArbitrationFinalIdx := writeArbitrationIdx
}
  // 写操作传输
  io.out.aw.valid := io.in(writeArbitrationFinalIdx).aw.valid
  io.out.aw.bits := io.in(writeArbitrationFinalIdx).aw.bits
  io.out.w.valid := io.in(writeArbitrationFinalIdx).w.valid
  io.out.w.bits := io.in(writeArbitrationFinalIdx).w.bits
  io.out.b.ready := io.in(writeArbitrationFinalIdx).b.ready
  io.in(writeArbitrationFinalIdx).aw.ready := io.out.aw.ready
  io.in(writeArbitrationFinalIdx).w.ready := io.out.w.ready
  io.in(writeArbitrationFinalIdx).b.valid := io.out.b.valid
  io.in(writeArbitrationFinalIdx).b.bits := io.out.b.bits


}