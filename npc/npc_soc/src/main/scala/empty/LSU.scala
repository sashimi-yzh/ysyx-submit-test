package empty

import chisel3._
import chisel3.util._
import chisel3.layer.block

class ControlSignalsLSU extends Bundle {
  val is_csr_visit = Bool()
  val is_gpr_wen = Bool()
  val rd = UInt(5.W)
  val csrd = UInt(12.W)
  val is_ebreak = Bool()
}

class MessageLSU2WBU extends Bundle {
  val pc = UInt(32.W)
  val inst = UInt(32.W)
  val controls = new ControlSignalsLSU
  val write_info = new WriteInfoWBU
  val exception = Bool()
}

class LSU() extends PrefixedModule {
  val in = IO(Flipped(DecoupledIO(new MessageEXU2LSU)))
  val out = IO(DecoupledIO(new MessageLSU2WBU))
  val conf = IO(new ConflictInfoRD)
  val fetch_port = IO(new AXI)
  set_AXIfull_zero(fetch_port)

  val ramWriter = Module(new RamWriteData)
  val ramLoader = Module(new RamLoadData)
  val should_mem_access_r = Wire(Bool())
  val should_mem_access_w = Wire(Bool())
  val fire = GenerateFireSignal(fetch_port)
  val has_signal = RegInit(false.B)
  val out_pc = IO(new Bundle {
    val dnpc = Output(UInt(32.W))
    val flush_valid = Output(Bool())
    val fencei = Output(Bool())
  })

  has_signal := MuxCase(
    has_signal,
    Seq(
      in.fire -> true.B,
      out.fire -> false.B
    )
  )

  val out_ar = RegInit(false.B)
  out_ar := MuxCase(
    out_ar,
    Seq(
      fire.ar_fire -> true.B,
      out.fire -> false.B
    )
  )
  val has_r = RegInit(false.B)
  has_r := MuxCase(
    has_r,
    Seq(
      fire.r_fire -> true.B,
      out.fire -> false.B
    )
  )
  val out_aw = RegInit(false.B)
  val out_w = RegInit(false.B)
  out_aw := MuxCase(
    out_aw,
    Seq(
      fire.aw_fire -> true.B,
      out.fire -> false.B
    )
  )
  out_w := MuxCase(
    out_w,
    Seq(
      fire.w_fire -> true.B,
      out.fire -> false.B
    )
  )
  val has_b = RegInit(false.B)
  has_b := MuxCase(
    has_b,
    Seq(
      fire.b_fire -> true.B,
      out.fire -> false.B
    )
  )

  val has_exception = has_signal && in.bits.exeption
  out.bits.exception := in.bits.exeption
  should_mem_access_r := !in.bits.exeption && has_signal && in.bits.controls.is_ram_valid && !in.bits.controls.is_ram_wen
  should_mem_access_w := !in.bits.exeption && has_signal && in.bits.controls.is_ram_valid && in.bits.controls.is_ram_wen

  fetch_port.ar.valid := has_signal && should_mem_access_r && !out_ar
  fetch_port.r.ready := out_ar && !has_r
  fetch_port.aw.valid := has_signal && should_mem_access_w && !out_aw
  fetch_port.w.valid := has_signal && should_mem_access_w && !out_w
  fetch_port.b.ready := out_aw && out_w && !has_b

  ramLoader.io.word := fetch_port.r.data
  ramLoader.io.size := in.bits.controls.ram_size
  ramLoader.io.is_unsigned := in.bits.controls.is_load_unsigned
  ramLoader.io.lower2bit := in.bits.write_info.alu_out(1, 0)
  ramWriter.io.word := in.bits.write_info.mem_word_or_csr_wdata
  ramWriter.io.size := in.bits.controls.ram_size
  ramWriter.io.lower2bit := in.bits.write_info.alu_out(1, 0)

  val rdata_latched = RegEnable(ramLoader.io.out, fire.r_fire)

  out.bits.pc := in.bits.pc
  out.bits.inst := in.bits.inst
  out.bits.controls := in.bits.controls
  out.bits.write_info.mem_word_or_csr_wdata := in.bits.write_info.mem_word_or_csr_wdata
  out.bits.write_info.gpr_wdata := Mux(
    in.bits.controls.gpr_wdata_sel === GprWdataSel.RAM,
    rdata_latched,
    in.bits.write_info.gpr_wdata
  )
  out.bits.write_info.dnpc := Mux(has_exception, in.bits.write_info.mtvec, in.bits.write_info.dnpc)

  fetch_port.ar.addr := in.bits.write_info.alu_out
  fetch_port.ar.size := Cat(0.U(1.W), in.bits.controls.ram_size)
  fetch_port.ar.id := "b1000".U(4.W)
  fetch_port.aw.addr := in.bits.write_info.alu_out
  fetch_port.aw.id := "b1000".U(4.W)
  fetch_port.w.data := ramWriter.io.out
  fetch_port.w.strb := ramWriter.io.mask
  fetch_port.aw.size := Cat(0.U(1.W), in.bits.controls.ram_size)
  fetch_port.w.last := true.B

  val no_pending_memory_access = (should_mem_access_r && has_r) || (should_mem_access_w && has_b) || (!should_mem_access_r && !should_mem_access_w)

  conf.rd_id := in.bits.controls.rd
  conf.rd_valid := has_signal && in.bits.controls.is_gpr_wen
  conf.csr_dest_valid := has_signal && in.bits.controls.is_csr_visit
  conf.csr_id := in.bits.controls.csrd
  conf.ok_to_forward_rd := has_r || in.bits.controls.gpr_wdata_sel =/= GprWdataSel.RAM
  conf.rd_data := out.bits.write_info.gpr_wdata

  out_pc.dnpc := Mux(has_exception, in.bits.write_info.mtvec, in.bits.write_info.dnpc)
  out_pc.flush_valid := has_exception || ((in.bits.fence || in.bits.csr_jump) && has_signal)
  out_pc.fencei := in.bits.fence
  out.valid := has_signal && no_pending_memory_access
  in.ready := no_pending_memory_access

  block(AXIAssertLayer) {
    check_signal_stable(
      fetch_port.ar.ready,
      fetch_port.ar.valid,
      Cat(fetch_port.ar.addr, fetch_port.ar.burst, fetch_port.ar.id, fetch_port.ar.len, fetch_port.ar.size),
      "LSU.ar"
    )
    check_signal_stable(
      fetch_port.w.ready,
      fetch_port.w.valid,
      Cat(fetch_port.w.data, fetch_port.w.last, fetch_port.w.strb),
      "LSU.w"
    )
    check_signal_stable(
      fetch_port.aw.ready,
      fetch_port.aw.valid,
      Cat(fetch_port.aw.addr, fetch_port.aw.burst, fetch_port.aw.id, fetch_port.aw.len, fetch_port.aw.size),
      "LSU.aw"
    )
    when(fire.r_fire) {
      assert(fetch_port.r.last, "lsu.axi.rlast is not set")
      assert(fetch_port.r.id === "b1000".U(4.W), "lsu.axi.rid is not b1000")
    }
    when(fire.b_fire) {
      assert(fetch_port.b.id === "b1000".U)
    }
  }
}
