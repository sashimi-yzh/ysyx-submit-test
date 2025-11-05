package AXI4 

import chisel3._
import chisel3.util._




// 定义一个 AXI4Lite 的仲裁器
class AXI4LiteArbiter(nMasters: Int, addrWidthBits: Int, dataWidthBits: Int) extends Module {
  val io = IO(new Bundle {
    // 多个主设备接口，每个接口都是 AXILiteSlaveIF 类型
    val masters = Vec(nMasters, new AXILiteSlaveIF(addrWidthBits, dataWidthBits))
    // 单一从设备接口，类型为 AXILiteMasterIF
    val slave = new AXILiteMasterIF(addrWidthBits, dataWidthBits)
  })

    // 确保信号的初始化，防止未初始化信号的问题
  io.masters.foreach { master =>
    // 读操作相关信号初始化
    master.ar.ready := false.B
    master.r.valid := false.B
    master.r.bits.data := 0.U
    master.r.bits.resp := 0.U

    // 写操作相关信号初始化
    master.aw.ready := false.B
    master.w.ready := false.B
    master.b.valid := false.B
    master.b.bits := 0.U
  }

  
// 读操作仲裁
// 使用 Mux 来处理所有请求都无效的情况，默认返回第一个主设备
val readArbitrationValid = io.masters.map(_.ar.valid).reduce(_ || _) // 如果任意一个主设备有效，则为 true
val readArbitrationIdx = PriorityEncoder(io.masters.map(_.ar.valid)) // 使用 PriorityEncoder 选择请求最高优先级的主设备

// 使用寄存器来保持最终的仲裁索引
val readArbitrationFinalIdx = RegInit(0.U) 
val readArbitrationStarted = RegInit(false.B) 

// 写操作的状态可以更新
when (io.slave.r.ready && io.slave.r.valid) {
  readArbitrationStarted := false.B
  readArbitrationFinalIdx := Mux(readArbitrationValid, readArbitrationIdx, 0.U) 
} .elsewhen (!readArbitrationStarted && readArbitrationValid) {
  readArbitrationStarted := true.B
  readArbitrationFinalIdx := readArbitrationIdx
}


  // 读操作传输
  io.slave.ar.valid := io.masters(readArbitrationFinalIdx).ar.valid
  io.slave.ar.bits := io.masters(readArbitrationFinalIdx).ar.bits
  io.slave.r.ready := io.masters(readArbitrationFinalIdx).r.ready
  io.masters(readArbitrationFinalIdx).ar.ready := io.slave.ar.ready
  io.masters(readArbitrationFinalIdx).r.valid := io.slave.r.valid
  io.masters(readArbitrationFinalIdx).r.bits := io.slave.r.bits


  // 写操作仲裁
// 使用 Mux 来处理所有请求都无效的情况，默认返回第一个主设备
val writeArbitrationValid = io.masters.map(_.aw.valid).reduce(_ || _) // 如果任意一个主设备有效，则为 true
val writeArbitrationIdx = PriorityEncoder(io.masters.map(_.aw.valid)) // 使用 PriorityEncoder 选择请求最高优先级的主设备

// 使用寄存器来保持最终的仲裁索引
val writeArbitrationFinalIdx = RegInit(0.U) // 初始化为 0（或者根据需要进行设置）
val writeArbitrationStarted = RegInit(false.B) // 用来标记是否开始了写操作

// 写操作的状态更新
when (io.slave.b.ready) {
  // 当 b.ready 为 true 时，表示写操作已经完成，可以允许更新仲裁索引
  writeArbitrationStarted := false.B
  writeArbitrationFinalIdx := Mux(writeArbitrationValid, writeArbitrationIdx, 0.U) // 如果有有效请求，更新索引
} .elsewhen (!writeArbitrationStarted && writeArbitrationValid) {
  // 如果写操作还未开始且有有效的请求，更新仲裁索引
  writeArbitrationStarted := true.B
  writeArbitrationFinalIdx := writeArbitrationIdx
}
  // 写操作传输
  io.slave.aw.valid := io.masters(writeArbitrationFinalIdx).aw.valid
  io.slave.aw.bits := io.masters(writeArbitrationFinalIdx).aw.bits
  io.slave.w.valid := io.masters(writeArbitrationFinalIdx).w.valid
  io.slave.w.bits := io.masters(writeArbitrationFinalIdx).w.bits
  io.slave.b.ready := io.masters(writeArbitrationFinalIdx).b.ready
  io.masters(writeArbitrationFinalIdx).aw.ready := io.slave.aw.ready
  io.masters(writeArbitrationFinalIdx).w.ready := io.slave.w.ready
  io.masters(writeArbitrationFinalIdx).b.valid := io.slave.b.valid
  io.masters(writeArbitrationFinalIdx).b.bits := io.slave.b.bits


}