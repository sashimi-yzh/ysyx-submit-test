
package npc.common

import chisel3._
import chisel3.util._

import Constants._
import npc.common._
import npc.devices.{ExtendedDevices,DeviceRange}


class AddressDecoder(deviceRanges: Seq[DeviceRange]) extends Module {
    // 确保设备范围不重叠
    deviceRanges.combinations(2).foreach { case Seq(a, b) =>
        assert(
        !a.contains(b.base) && !a.contains(b.end) &&
        !b.contains(a.base) && !b.contains(a.end),
        s"Device ranges overlap: ${a.base}-${a.end} and ${b.base}-${b.end}"
        )
    }
    val numDevices = deviceRanges.size
    val selWidth = if (numDevices == 0) 1 else log2Ceil(numDevices)

    val io = IO(new Bundle {
        val addr = Input(UInt(32.W))
        val valid = Output(Bool())  // 地址是否在任一设备范围内
        val deviceSel = Output(UInt(selWidth.W))  // 选择的设备索引
    })
  
    // 计算每个设备范围的匹配
    val inRange = deviceRanges.map { range =>
        val base = range.base.U(32.W)
        val end = (range.base + range.size - 1).U(32.W)
        // 使用范围检查，而非简单起始地址
        io.addr >= base && io.addr <= end
    }
  
    // 使用优先级编码器处理多个匹配（虽然理论上不应该发生）
    val deviceMatch = VecInit(inRange).asUInt
    io.deviceSel := PriorityEncoder(deviceMatch)
    
    // 验证是否有至少一个设备匹配
    io.valid := deviceMatch.orR
    
    // 可选：添加调试输出
    if (deviceRanges.nonEmpty) {
        printf(p"AddrDecoder: addr=0x${Hexadecimal(io.addr)} valid=${io.valid} " +
            p"deviceSel=${io.deviceSel} ranges: ${deviceRanges.map(_.base).mkString("|")}\n")
    }
}


// class AXIBar(num_masters: Int, num_slaves: Int) (implicit val conf: Config) extends Module { 
//     val io = IO(new Bundle { 
//         val masters = Vec(num_masters, new AXI4LiteIo)
//         val slaves = Vec(num_slaves, Flipped(new AXI4LiteIo))
//     })

//     val decoder = Seq.fill(num_masters)(Module(new AddressDecoder(ExtendedDevices)))
//     val arbiters = Seq.fill(numSlaves)(Module(new Arbiter(UInt(32.W), numMasters)))

//     val respRouting = RegInit(0.U(num_masters*num_slaves))

//     for (i <- 0 until num_masters) { 
//         decoder(i).io.addr := Mux(io.masters(i).aw.valid, io.masters(i).axi_io.aw.addr, io.masters(i).axi_io.ar.addr)
//         for (i <- 0 untils num_slaves){
//             val addrMatch := decoder(i).io.deviceSel === j.U
//             arbiters(j).io.in(i).valid :=  (io.masters(i).axi_io.ar.valid || io.masters(i).axi_io.ar.valid) && addrMatch && decoders(i).io.valid
//             arbiters(j).io.in(i).bits :=  (io.masters(i).axi_io.ar.addr || io.masters(i).axi_io.ar.valid) && addrMatch && decoders(i).io.valid

//             // slave aready
//             io.masters(i).ar.ready := Mux(addrMatch && decoders(i).io.valid, 
//                                  arbiters(j).io.in(i).ready, 
//                                  false.B)
//             when(arbiters(j).io.in(i).fire) {
//                 // 设置路由位（表示来自主设备i的事务正在访问从设备j）
//                 respRouting := respRouting.bitSet(i * numSlaves + j, true.B)
//             }
//         }
//     }
    
// }


