package npc
import chisel3._
import chisel3.util._
import backend.intr2RFS

class WriteRegPortBundle extends Bundle{
    val wdata  = Output(UInt(32.W))
    val waddr  = Output(UInt(5.W))
    val wen    = Output(Bool())
}

class CSRWritePortBundle extends Bundle{
    val CSRWAddr = Output(UInt(12.W))
    val CSRWData = Output(UInt(32.W))
    val CSRWrite = Output(Bool())

}
class CSRReadPortBundle extends Bundle{
    val CSRRAddr = Output(UInt(12.W))
    val CSRRData = Input(UInt(32.W))

}
class ExceptionInfoBundle extends Bundle{
    val isTrap = Output(Bool())
    val PC = Output(UInt(32.W))
    val Exception_Code = Output(UInt(32.W))
}

class ReadRegPortBundle extends Bundle{

    val raddr1 = Output(UInt(5.W))
    val rdata1 = Input(UInt(32.W))
    val raddr2 = Output(UInt(5.W))
    val rdata2 = Input(UInt(32.W))
}

class ysyx_26030092_RegBlackBox extends ExtModule{
  val io = FlatIO(new Bundle {
    val clock = Input(Clock())
    val wdata  = Input(UInt(32.W))
    val waddr  = Input(UInt(5.W))
    val wen    = Input(Bool())
    val raddr1 = Input(UInt(5.W))
    val rdata1 = Output(UInt(32.W))
    val raddr2 = Input(UInt(5.W))
    val rdata2 = Output(UInt(32.W))
  })
  addResource("/RegBlackBox.v")
}

class ysyx_26030092_RFS extends Module {
    val RFS_ReadPort = IO(new Bundle {
        val RegReadPort = Flipped(new ReadRegPortBundle)
        val CSRReadPort = Flipped(new CSRReadPortBundle)
    })

    val WriteRegPort = IO(Input(new WriteRegPortBundle))
    val CSRWritePort = IO(Input(new CSRWritePortBundle))
    val ExceptionPort = IO(Input(new ExceptionInfoBundle))

    val mtvec_out = IO(Output(UInt(32.W)))
    val mtime_out = IO(Output(UInt(64.W)))
    val mret_in = IO(Input(Bool()))

    val trap = ExceptionPort.isTrap

    val Reg_u = Module(new ysyx_26030092_RegBlackBox())
    Reg_u.io.raddr1 := RFS_ReadPort.RegReadPort.raddr1
    Reg_u.io.raddr2 := RFS_ReadPort.RegReadPort.raddr2
    RFS_ReadPort.RegReadPort.rdata1 := Reg_u.io.rdata1
    RFS_ReadPort.RegReadPort.rdata2 := Reg_u.io.rdata2
    Reg_u.io.wdata := WriteRegPort.wdata
    Reg_u.io.waddr := WriteRegPort.waddr
    Reg_u.io.wen := WriteRegPort.wen && !trap
    Reg_u.io.clock := clock

    val mcycle = RegInit(0.U(64.W))
    mcycle := mcycle + 1.U
    val mepc = RegInit(0.U(32.W))
    val mcause = RegInit(0.U(32.W))
    val mtvec = RegInit(0.U(32.W))
    val mstatus = RegInit("h1800".U(32.W))

    val mtimer_div   = RegNext(mcycle(8), false.B)
    val mtimer_tick  = mcycle(8) && !mtimer_div
    val mtimer_ticks = RegInit(0.U(16.W))

    mtvec_out := mtvec
    mtime_out := mcycle

    RFS_ReadPort.CSRReadPort.CSRRData := 0.U
    switch(RFS_ReadPort.CSRReadPort.CSRRAddr){
      is("hB00".U){// mcycle
        RFS_ReadPort.CSRReadPort.CSRRData := mcycle(31,0)
      }
      is("hB80".U){// mcycleh
        RFS_ReadPort.CSRReadPort.CSRRData := mcycle(63,32)
      }
      is("hF11".U){// mvendorid
        RFS_ReadPort.CSRReadPort.CSRRData := "h79737978".U
      }
      is("hF12".U){// marchid
        RFS_ReadPort.CSRReadPort.CSRRData := 26030092.U
      }
      is("h305".U){
        RFS_ReadPort.CSRReadPort.CSRRData := mtvec
      }
      is("h300".U){
        RFS_ReadPort.CSRReadPort.CSRRData := mstatus
      }
      is("h341".U){
        RFS_ReadPort.CSRReadPort.CSRRData := mepc
      }
      is("h342".U){
        RFS_ReadPort.CSRReadPort.CSRRData := mcause
      }
      is("h7C0".U){
        RFS_ReadPort.CSRReadPort.CSRRData := Cat(0.U(16.W), mtimer_ticks)
      }
    }

    when(CSRWritePort.CSRWrite && !trap){
      switch(CSRWritePort.CSRWAddr){//mcycle
        is("hB00".U){
          mcycle := Cat(mcycle(63,32),CSRWritePort.CSRWData)
        }
        is("hB80".U){
          mcycle := Cat(CSRWritePort.CSRWData,mcycle(31,0))
        }
        is("h305".U){
          mtvec := CSRWritePort.CSRWData
        }
        is("h300".U){
          mstatus := CSRWritePort.CSRWData
        }
        is("h341".U){
          mepc := CSRWritePort.CSRWData
        }
        is("h7C0".U){
          mtimer_ticks := CSRWritePort.CSRWData(15,0)
        }
        is("h342".U){
          mcause := CSRWritePort.CSRWData
        }
      }
    }

    when(ExceptionPort.isTrap){
      mepc := ExceptionPort.PC
      mcause := ExceptionPort.Exception_Code
    }

    //timer intr
    val intr = IO(Flipped(new intr2RFS))
    intr.timer_intr  := false.B
    intr.intr_en     := mstatus(3)                 // MIE

    val armed = RegInit(false.B)
    when(CSRWritePort.CSRWrite && !trap && CSRWritePort.CSRWAddr === "h7C0".U){
      armed := CSRWritePort.CSRWData(15,0) =/= 0.U
    }
    when(mtimer_tick && mtimer_ticks === 1.U){ armed := false.B }
    intr.timer_armed := armed

    when(mtimer_tick && mtimer_ticks =/= 0.U){
        mtimer_ticks := mtimer_ticks - 1.U
        when(mtimer_ticks === 1.U){ intr.timer_intr := true.B }
    }
    when(intr.timer_intr_taken){
      mepc := intr.intr_pc
      mcause := "h80000007".U
    }

    when(mret_in){
      mstatus := (mstatus & "hFFFFFF77".U) | ((mstatus & "h80".U) >> 4) | "h80".U  // MIE <= MPIE, MPIE <= 1
    }
    when(ExceptionPort.isTrap || intr.timer_intr_taken){
      mstatus := (mstatus & "hFFFFFF77".U) | ((mstatus & "h8".U) << 4)   // MPIE <= MIE, MIE <= 0
    }

}
