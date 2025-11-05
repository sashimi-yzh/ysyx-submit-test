package cpu

import chisel3._
import chisel3.util._
import chisel3.stage._

class RegfileReadIO(config:NPCConfig) extends Bundle{
    var addr = Input(UInt(log2Ceil(config.REG_NUM).W))
    var data = Output(UInt(config.XLEN.W))
}

class RegfileWriteIO(config: NPCConfig) extends Bundle{
    var en = Input(Bool())
    var addr = Input(UInt(log2Ceil(config.REG_NUM).W))
    var data = Input(UInt(config.XLEN.W))
}

class RegfileIO(config: NPCConfig) extends Bundle{
    val read1 = new RegfileReadIO(config)
    val read2 = new RegfileReadIO(config)
    val write = new RegfileWriteIO(config)
}


class ysyx_23060246_Regfile(config: NPCConfig) extends Module{
    val io = IO(new RegfileIO(config))
    
    val N = config.USE_REG0 match {
        case true => config.REG_NUM
        case false => config.REG_NUM - 1
    }
    val regs = Mem(N, UInt(config.XLEN.W))
    //val regs = RegInit(VecInit(Seq.fill(N)(0.U(config.XLEN.W))))

    if(config.USE_REG0){

        // read data with internal forwarding 
        io.read1.data := Mux(io.write.addr === io.read1.addr && io.write.addr =/= 0.U && io.write.en, 
                                io.write.data, Mux(io.read1.addr.orR, regs(io.read1.addr), 0.U))
        io.read2.data := Mux(io.write.addr === io.read2.addr && io.write.addr =/= 0.U && io.write.en, 
                                io.write.data, Mux(io.read2.addr.orR, regs(io.read2.addr), 0.U))
        
        when(io.write.en) {
            regs(io.write.addr) := Mux(io.write.addr === 0.U, 0.U, io.write.data)
        }
    }
    else {

        // read data with internal forwarding 
        def readLogic(addr: UInt): UInt = {
            val rawData = Mux(addr.orR, regs(addr - 1.U), 0.U)
            Mux(io.write.en && (io.write.addr === addr) && addr.orR, 
                io.write.data, 
                rawData)
        }

        io.read1.data := readLogic(io.read1.addr)
        io.read2.data := readLogic(io.read2.addr)
        

        when(io.write.en && io.write.addr.orR) {
            regs(io.write.addr - 1.U) := io.write.data
        }
    }
}
