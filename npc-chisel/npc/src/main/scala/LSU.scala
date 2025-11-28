
package npc

import chisel3._
import chisel3.util._

import npc.common._
import npc.Constants._
import javax.xml.transform.OutputKeys

class LSUPipeIO(implicit val conf: Config) extends Bundle() {
    val wbaddr          = Output(UInt(5.W))
    val data            = Output(UInt(conf.xprlen.W))
    val pc              = Output(UInt(conf.xprlen.W))
    val pc_valid        = Output(Bool())
    val mem_resp_valid  = Output(Bool())
    val ebreak          = Output(Bool())
    val ctrl_rf_wen     = Output(Bool())
    val debug           = Output(new LSUDebugPort)
}

class CtlToLSUlIO (implicit val conf: Config) extends Bundle() {
    val mem_exception = Output(Bool())
}

class LSUTOCtlIO (implicit val conf: Config) extends Bundle() {
    val ctrl_mem_val    = Output(Bool())
    val alu_out         = Output(UInt(conf.xlen.W))
    val wbaddr          = Output(UInt(5.W))
    val wbdata          = Output(UInt(conf.xlen.W))
    val ctrl_rf_wen     = Output(Bool())
    val inst_is_load    = Output(Bool())
    val mem_exception   = Output(Bool())
    val csr_eret        = Output(Bool())
}


class LSUDebugPort(implicit val conf: Config) extends Bundle {
    val mem_en      = Output(Bool())
    val fcn         = Output(Bool())
    val addr        = Output(UInt(conf.xprlen.W))
    val rdata       = Output(UInt(conf.xprlen.W))
    val wdata       = Output(UInt(conf.xprlen.W))
    val valid       = Output(Bool())
    val typ         = Output(UInt(2.W))
    val storeCount  = Output(UInt(conf.perfCountBits.W))
    val loadCount   = Output(UInt(conf.perfCountBits.W))
}

class CSRFiles(implicit val conf: Config) extends Module {
    val io = IO(new Bundle{
        val csr_inst            = Input(UInt(12.W))
        val csr_cmd             = Input(UInt(CSR.N.getWidth.W))
        val pc                  = Input(UInt(conf.xprlen.W))
        val alu_out             = Input(UInt(conf.xlen.W))
        val exception           = Input(UInt(EXC_NORMAL.getWidth.W))
        val exception_target    = Output(UInt(conf.xprlen.W))
        val rdata               = Output(UInt(conf.xlen.W))
        val ebreak              = Output(Bool())
        val eret                = Output(Bool())
    }) 
    // Control Status Registers
    val csr = Module(new CSRFile())
    csr.io := DontCare
    csr.io.decode.csr   := io.csr_inst
    csr.io.rw.cmd       := io.csr_cmd
    csr.io.rw.wdata     := io.alu_out
    csr.io.exception := io.exception
    csr.io.pc           := io.pc
    io.exception_target := csr.io.evec
    io.rdata            := csr.io.rw.rdata    
    io.ebreak := csr.io.insn_break
    io.eret := csr.io.eret

}
class LSUIO(implicit val conf: Config) extends Bundle {
    val exe_mem             = Flipped(new DecoupledIO(new EXEPipeIO()))
    val mem_wb              = new DecoupledIO(new LSUPipeIO)
    val port                = new MemPortIo(conf.xprlen)
    val debug               = new LSUDebugPort
    val exception_target    = Output(UInt(conf.xprlen.W))
    val to_ctl             = new LSUTOCtlIO
    
    val clintIO = Flipped(  new Bundle{
            val dr      =   new AXIRport(conf.xprlen, conf.xlen)
            val dw      =   new AXIWport(conf.xprlen, conf.xlen)
        })
}
class LSU(implicit val conf: Config) extends Module {
    val io = IO(new LSUIO())
    io := DontCare
    
    val exception = Wire(UInt(EXC_NORMAL.getWidth.W))
    val addr = io.exe_mem.bits.alu_out
    val mem_en = io.exe_mem.bits.ctrl_mem_val
    val in_clint = addr >= CLINT_BASE && addr < (CLINT_BASE + CLINT_SIZE)
    val csr_files = Module(new CSRFiles)
    
    csr_files.io.pc         := io.exe_mem.bits.pc   
    csr_files.io.csr_inst   := io.exe_mem.bits.csr_inst
    csr_files.io.csr_cmd    := io.exe_mem.bits.ctrl_csr_cmd
    csr_files.io.alu_out    := io.exe_mem.bits.alu_out
    csr_files.io.exception  := exception

    io.exception_target     := csr_files.io.exception_target    
    
    // lsu should support mis-aligned access? or should based on slave type? 
    // val mis_aligned = Mux(mem_en && addr (1,0) =/= 0.U, true.B, false.B) 
    
    when(mem_en && !in_clint ) {
        io.port.req.valid    := mem_en
        io.port.req.bits.fcn := io.exe_mem.bits.ctrl_mem_fcn
        io.port.req.bits.typ := io.exe_mem.bits.ctrl_mem_typ
        io.port.req.bits.addr := addr
        io.port.req.bits.data := io.exe_mem.bits.rs2_data 
        io.port.req.bits.burstlen := 0.U
        io.port.req.bits.burst := BURST_FIXED
    } .otherwise {
        io.port.req.valid    := false.B
        when (mem_en && in_clint ){
            when (io.exe_mem.bits.ctrl_mem_fcn === M_XRD){
                io.clintIO.dr.en := true.B
                io.clintIO.dr.addr := addr
            } .otherwise{
                io.clintIO.dr.en := false.B
            }
        }
    }
    

    
    val mem_resp_valid  = Mux(in_clint, io.clintIO.dr.ready,    (io.port.resp.valid))
    val mem_exception   = Mux(in_clint, 0.U,                    (io.port.resp.bits.resp))
    val mem_data        = Mux(in_clint, io.clintIO.dr.data ,    ( io.port.resp.bits.data))
    val mem_ready = (!io.exe_mem.bits.ctrl_mem_val)  || (io.exe_mem.bits.ctrl_mem_val && mem_resp_valid)
    val ready = mem_ready
    io.exe_mem.ready := io.mem_wb.ready && ready

    // WB Mux
    val wbdata = MuxCase(io.exe_mem.bits.alu_out, Array(
                  (io.exe_mem.bits.ctrl_wb_sel === WB_ALU) -> io.exe_mem.bits.alu_out,
                  (io.exe_mem.bits.ctrl_wb_sel === WB_PC4) -> io.exe_mem.bits.alu_out,
                  (io.exe_mem.bits.ctrl_wb_sel === WB_MEM) -> mem_data,
                  (io.exe_mem.bits.ctrl_wb_sel === WB_CSR) -> csr_files.io.rdata
                  ))
    exception := Mux(mem_en && mem_exception =/= 0.U , 
            Mux(io.exe_mem.bits.ctrl_mem_typ === M_XRD, EXC_LOAD_ACCESS_FAULT, 
            Mux(io.exe_mem.bits.ctrl_mem_typ === M_XWR, EXC_STORE_ACCESS_FAULT,EXC_NORMAL)), io.exe_mem.bits.exception )
    io.mem_wb.valid                 := (!mem_en || (mem_en && mem_resp_valid))
    io.mem_wb.bits.data             := wbdata
    io.mem_wb.bits.wbaddr           := io.exe_mem.bits.wbaddr
    io.mem_wb.bits.ebreak           := csr_files.io.ebreak
    io.mem_wb.bits.pc               := io.exe_mem.bits.pc
    io.mem_wb.bits.ctrl_rf_wen      := io.exe_mem.bits.ctrl_rf_wen
    // io.mem_wb.bits.inst             := io.exe_mem.bits.inst
    io.mem_wb.bits.pc_valid         := io.exe_mem.bits.pc_valid 
    io.mem_wb.bits.mem_resp_valid   := mem_resp_valid
    io.mem_wb.bits.debug            := io.debug
    
    io.to_ctl.ctrl_mem_val      := mem_en
    io.to_ctl.wbdata            := wbdata
    io.to_ctl.wbaddr            := io.exe_mem.bits.wbaddr
    io.to_ctl.ctrl_rf_wen       := io.exe_mem.bits.ctrl_rf_wen
    io.to_ctl.alu_out           := io.exe_mem.bits.alu_out
    io.to_ctl.inst_is_load      := io.exe_mem.bits.ctrl_mem_val && (io.exe_mem.bits.ctrl_mem_fcn === M_XRD)
    io.to_ctl.csr_eret          := csr_files.io.eret
    io.to_ctl.mem_exception     := exception

    /////////// Debug Port
    val storeCnt        = RegInit(0.U(conf.perfCountBits.W))
    val loadCnt         = RegInit(0.U(conf.perfCountBits.W))
    io.debug.mem_en     := mem_en
    io.debug.addr       := addr
    io.debug.fcn        := io.exe_mem.bits.ctrl_mem_fcn
    io.debug.wdata      := io.exe_mem.bits.rs2_data 
    io.debug.rdata      := mem_data
    io.debug.valid      := mem_resp_valid
    io.debug.typ        := io.exe_mem.bits.ctrl_mem_typ
    when(io.port.resp.valid && mem_en) {
      when(io.exe_mem.bits.ctrl_mem_fcn === M_XWR) {
        storeCnt := storeCnt + 1.U
      }.otherwise {
        loadCnt := loadCnt + 1.U
      }
    }
    io.debug.loadCount  := loadCnt
    io.debug.storeCount := storeCnt
    /////////// Debug Port
}

