import chisel3._
import chisel3.util._

// 顶层模块
class rv32e extends Module {
  val io = IO(new Bundle {
    val clk = Input(Clock())
    val reset = Input(Bool())
  })

  // 子模块实例
  val if_stage = Module(new IF)
  val id_stage = Module(new ID)
  val regfile = Module(new RegFile)
  val alu = Module(new ALU)
  val mem_stage = Module(new MEM)
  val wb_stage = Module(new WB)

  // 连接信号
  if_stage.io.clk := io.clk
  if_stage.io.reset := io.reset
  if_stage.io.branch_target := wb_stage.io.jalr_target
  if_stage.io.pc_src := wb_stage.io.is_jalr
  val pc = if_stage.io.pc
  val instr = if_stage.io.instr

  id_stage.io.instr := instr
  val opcode = id_stage.io.opcode
  val rs1 = id_stage.io.rs1
  val rs2 = id_stage.io.rs2
  val rd = id_stage.io.rd
  val imm = id_stage.io.imm
  val func3 = id_stage.io.func3
  val func7 = id_stage.io.func7
  val RegWrite = id_stage.io.RegWrite
  val MemWrite = id_stage.io.MemWrite
  val MemRead = id_stage.io.MemRead
  val alu_op = id_stage.io.alu_op
  val MemLen = id_stage.io.MemLen

  regfile.io.clk := io.clk
  regfile.io.rs1 := rs1
  regfile.io.rs2 := rs2
  regfile.io.rd := rd
  regfile.io.we := RegWrite
  regfile.io.wd := wb_stage.io.wb_data
  val rs1_val = regfile.io.rs1_val
  val rs2_val = regfile.io.rs2_val

  alu.io.alu_op := alu_op
  alu.io.a := rs1_val
  alu.io.b := Mux(opcode(6,2) === "b01100".U, rs2_val, imm) // R型使用rs2_val，其他使用imm
  val alu_result = alu.io.result

  mem_stage.io.clk := io.clk
  mem_stage.io.MemRead := MemRead
  mem_stage.io.MemWrite := MemWrite
  mem_stage.io.addr := rs1_val + imm
  mem_stage.io.data_in := rs2_val
  mem_stage.io.MemLen := MemLen
  val data_out = mem_stage.io.data_out

  wb_stage.io.pc := pc
  wb_stage.io.imm := imm
  wb_stage.io.rs1_val := rs1_val
  wb_stage.io.alu_result := alu_result
  wb_stage.io.opcode := opcode
  wb_stage.io.func3 := func3
  wb_stage.io.data_out := data_out
}

// 取指模块
class IF extends Module {
  val io = IO(new Bundle {
    val clk = Input(Clock())
    val reset = Input(Bool())
    val branch_target = Input(UInt(32.W))
    val pc_src = Input(Bool())
    val pc = Output(UInt(32.W))
    val instr = Output(UInt(32.W))
  })

  // 模拟内存读取，实际中需使用BlackBox调用C函数pmem_read
  val pmem = RegInit(VecInit(Seq.fill(1024)(0.U(32.W)))) // 1024个32位字的内存
  val pc = RegInit(0x80000000.U(32.W))
  val check = RegInit(true.B)

  when(io.reset) {
    pc := 0x80000000.U
    check := true.B
  } .elsewhen(!check) {
    when(io.pc_src) {
      pc := io.branch_target
    } .otherwise {
      pc := pc + 4.U
    }
  } .otherwise {
    check := false.B
  }

  io.pc := pc
  io.instr := pmem(pc >> 2) // 按字寻址
}

// 译码模块
class ID extends Module {
  val io = IO(new Bundle {
    val instr = Input(UInt(32.W))
    val opcode = Output(UInt(7.W))
    val rs1 = Output(UInt(5.W))
    val rs2 = Output(UInt(5.W))
    val rd = Output(UInt(5.W))
    val imm = Output(UInt(32.W))
    val func3 = Output(UInt(3.W))
    val func7 = Output(UInt(7.W))
    val RegWrite = Output(Bool())
    val MemWrite = Output(Bool())
    val MemRead = Output(Bool())
    val alu_op = Output(UInt(4.W))
    val MemLen = Output(UInt(3.W))
  })

  // 指令字段分解
  val opcode = io.instr(6, 0)
  val rs1 = io.instr(19, 15)
  val rs2 = io.instr(24, 20)
  val rd = io.instr(11, 7)
  val func3 = io.instr(14, 12)
  val func7 = io.instr(31, 25)

  // immediate值生成
  val immI = Cat(Fill(20, io.instr(31)), io.instr(31, 20))
  val immU = Cat(io.instr(31, 12), 0.U(12.W))
  val immS = Cat(Fill(20, io.instr(31)), io.instr(31, 25), io.instr(11, 7))
  val immJ = Cat(Fill(12, io.instr(31)), io.instr(19, 12), io.instr(20), io.instr(30, 21), 0.U(1.W))
  val immR = 0.U(32.W)

  // 输出信号赋值
  io.opcode := opcode
  io.rs1 := rs1
  io.rs2 := rs2
  io.rd := rd
  io.func3 := func3
  io.func7 := func7

  io.imm := 0.U
  io.RegWrite := false.B
  io.MemWrite := false.B
  io.MemRead := false.B
  io.alu_op := 0.U // 默认ALU_ADD
  io.MemLen := 2.U // 默认Mem_Word

  val get_opcode = opcode(6, 2)

  switch(get_opcode) {
    is("b01101".U) { // LUI
      io.imm := immU
      io.RegWrite := true.B
    }
    is("b00101".U) { // AUIPC
      io.imm := immU
      io.RegWrite := true.B
      io.alu_op := 0.U // ALU_ADD
    }
    is("b11001".U) { // JALR
      when(func3 === 0.U) {
        io.imm := immI
        io.RegWrite := true.B
      }
    }
    is("b01000".U) { // S型
      io.imm := immS
      io.MemWrite := true.B
      switch(func3) {
        is(2.U) { io.MemLen := 2.U } // SW
        is(0.U) { io.MemLen := 4.U } // SB
      }
    }
    is("b00000".U) { // L型
      when(func3 === 2.U) { // LW
        io.imm := immI
        io.RegWrite := true.B
        io.MemRead := true.B
        io.alu_op := 0.U
        io.MemLen := 2.U
      } .elsewhen(func3 === 4.U) { // LBU
        io.imm := immI
        io.RegWrite := true.B
        io.MemRead := true.B
        io.alu_op := 0.U
        io.MemLen := 0.U // Mem_UBit
      }
    }
    is("b01100".U) { // R型
      io.RegWrite := true.B
      io.imm := immR
      when(func3 === 0.U) { io.alu_op := 0.U } // ADD
    }
    is("b00100".U) { // I型
      io.imm := immI
      io.RegWrite := true.B
      when(func3 === 0.U) { io.alu_op := 0.U } // ADDI
    }
    is("b11100".U) { // E型 (EBREAK)
      when(io.instr === "h00100073".U) {
        // 在Chisel中无法直接调用ebreak，需通过BlackBox或仿真处理
      }
    }
  }
}

// 寄存器文件
class RegFile extends Module {
  val io = IO(new Bundle {
    val clk = Input(Clock())
    val rs1 = Input(UInt(5.W))
    val rs2 = Input(UInt(5.W))
    val rd = Input(UInt(5.W))
    val we = Input(Bool())
    val wd = Input(UInt(32.W))
    val rs1_val = Output(UInt(32.W))
    val rs2_val = Output(UInt(32.W))
  })

  val regs = RegInit(VecInit(Seq.fill(32)(0.U(32.W))))

  io.rs1_val := Mux(io.rs1 =/= 0.U, regs(io.rs1), 0.U)
  io.rs2_val := Mux(io.rs2 =/= 0.U, regs(io.rs2), 0.U)

  when(io.we && io.rd =/= 0.U) {
    regs(io.rd) := io.wd
  }
}

// ALU模块
class ALU extends Module {
  val io = IO(new Bundle {
    val alu_op = Input(UInt(4.W))
    val a = Input(UInt(32.W))
    val b = Input(UInt(32.W))
    val result = Output(UInt(32.W))
  })

  io.result := Mux(io.alu_op === 0.U, io.a + io.b, 0.U) // 仅实现ADD，其他操作可扩展
}

// 内存模块
class MEM extends Module {
  val io = IO(new Bundle {
    val clk = Input(Clock())
    val MemRead = Input(Bool())
    val MemWrite = Input(Bool())
    val addr = Input(UInt(32.W))
    val data_in = Input(UInt(32.W))
    val MemLen = Input(UInt(3.W))
    val data_out = Output(UInt(32.W))
  })

  // 模拟内存，实际中需使用BlackBox调用pmem_read和pmem_write
  val mem = RegInit(VecInit(Seq.fill(1024)(0.U(32.W))))
  io.data_out := 0.U

  when(io.MemRead) {
    switch(io.MemLen) {
      is(0.U) { // Mem_UBit
        io.data_out := Cat(0.U(24.W), mem(io.addr >> 2)(7, 0))
      }
      is(2.U) { // Mem_Word
        io.data_out := mem(io.addr >> 2)
      }
    }
  } .elsewhen(io.MemWrite) {
    switch(io.MemLen) {
      is(4.U) { // Mem_Bit
        mem(io.addr >> 2) := (mem(io.addr >> 2) & ~0xFF.U) | (io.data_in & 0xFF.U)
      }
      is(2.U) { // Mem_Word
        mem(io.addr >> 2) := io.data_in
      }
    }
  }
}

// 写回模块
class WB extends Module {
  val io = IO(new Bundle {
    val pc = Input(UInt(32.W))
    val imm = Input(UInt(32.W))
    val rs1_val = Input(UInt(32.W))
    val alu_result = Input(UInt(32.W))
    val opcode = Input(UInt(7.W))
    val func3 = Input(UInt(3.W))
    val data_out = Input(UInt(32.W))
    val jalr_target = Output(UInt(32.W))
    val is_jalr = Output(Bool())
    val wb_data = Output(UInt(32.W))
  })

  io.jalr_target := (io.rs1_val + io.imm) & ~1.U
  io.is_jalr := (io.opcode === "b1100111".U) && (io.func3 === 0.U)

  io.wb_data := MuxCase(0.U, Seq(
    (io.opcode === "b0110111".U) -> io.imm, // LUI
    (io.opcode === "b0010111".U) -> (io.pc + io.imm), // AUIPC
    (io.opcode === "b1100111".U) -> (io.pc + 4.U), // JALR
    (io.opcode === "b0000011".U) -> io.data_out, // LW
    ((io.opcode === "b0110011".U) || (io.opcode === "b0010011".U)) -> io.alu_result // R型, I型
  ))
}