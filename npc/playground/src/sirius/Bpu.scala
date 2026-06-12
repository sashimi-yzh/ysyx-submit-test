package sirius

import chisel3._

class Btb(
  indexWidth:  Int,
  tagWidth:    Int,
  targetWidth: Int
)(
  implicit private val cfg: CoreConfig)
    extends Module {
  val io = IO(new Bundle {
    val read = new Bundle {
      val pc = Input(UInt(cfg.xlen.W))
      val hit = Output(Bool())
      val target = Output(UInt(cfg.xlen.W))
    }
    val write = new Bundle {
      val update = Input(Bool())
      val pc = Input(UInt(cfg.xlen.W))
      val target = Input(UInt(cfg.xlen.W))
    }
  })

  val lineNum = 1 << indexWidth
  val tagIndexWidth = tagWidth + indexWidth
  val trivialBits = if (cfg.extensions().contains(ExtTypeEnum.C)) 1 else 2

  val tags = Reg(Vec(lineNum, UInt(tagWidth.W)))
  val targets = Reg(Vec(lineNum, UInt(targetWidth.W)))
  val valids = RegInit(VecInit.fill(lineNum)(false.B))

  def significantPc(pc: UInt) = pc >> trivialBits
  def hashTagIndex(pc: UInt) = {
    significantPc(pc)(tagIndexWidth - 1, 0) ^
      significantPc(pc)(2 * tagIndexWidth - 1, tagIndexWidth)
  }
  def idx(pc: UInt) = hashTagIndex(pc)(indexWidth - 1, 0)
  def tag(pc: UInt) = hashTagIndex(pc)(tagIndexWidth - 1, indexWidth)

  // Read
  val readIdx = idx(io.read.pc)
  val readTag = tag(io.read.pc)
  io.read.hit := tags(readIdx) === readTag && valids(readIdx)
  val pcHi = io.read.pc.head(io.read.pc.getWidth - targetWidth - trivialBits)
  io.read.target := pcHi ## targets(readIdx) ## 0.U(trivialBits.W)

  // Write
  val writeIdx = idx(io.write.pc)
  val writeTag = tag(io.write.pc)
  when(io.write.update) {
    valids(writeIdx) := true.B
    tags(writeIdx) := writeTag
    targets(writeIdx) := io.write.target(targetWidth + trivialBits - 1, trivialBits)
  }
}

class Pht(
  indexWidth:   Int,
  counterWidth: Int
)(
  implicit private val cfg: CoreConfig)
    extends Module {
  val io = IO(new Bundle {
    val read = new Bundle {
      val pc = Input(UInt(cfg.xlen.W))
      val taken = Output(Bool())
    }
    val write = new Bundle {
      val update = Input(Bool())
      val pc = Input(UInt(cfg.xlen.W))
      val taken = Input(Bool())
    }
  })

  val cntNum = 1 << indexWidth
  val cnts = RegInit(0.U.asTypeOf(Vec(cntNum, UInt(2.W))))

  def significantPc(pc: UInt): UInt = if (cfg.extensions().contains(ExtTypeEnum.C)) { pc >> 1 }
  else { pc >> 2 }
  def idx(pc: UInt): UInt = {
    val sigPc = significantPc(pc)
    sigPc(indexWidth - 1, 0) ^ sigPc(2 * indexWidth - 1, indexWidth)
  }

  // Read
  val readIdx = idx(io.read.pc)
  io.read.taken := cnts(readIdx) >= ((1 << counterWidth) / 2).U

  // Write
  val writeIdx = idx(io.write.pc)
  when(io.write.update) {
    val cnt = cnts(writeIdx)
    when(io.write.taken && (cnt < ((1 << counterWidth) - 1).U)) {
      cnt := cnt + 1.U
    }.elsewhen(!io.write.taken && cnt > 0.U) {
      cnt := cnt - 1.U
    }
  }
}

class Bpu(
  btbIndexWidth:   Int,
  btbTagWidth:     Int,
  btbTargetWidth:  Int,
  phtIndexWidth:   Int,
  phtCounterWidth: Int
)(
  implicit private val cfg: CoreConfig)
    extends Module {
  val ifuIn = IO(Flipped(new IfuToBpuIO))
  val lsuIn = IO(Flipped(new LsuToBpuIO))

  val btb = Module(
    new Btb(indexWidth = btbIndexWidth, tagWidth = btbTagWidth, targetWidth = btbTargetWidth)
  )
  val pht = Module(new Pht(indexWidth = phtIndexWidth, counterWidth = phtCounterWidth))

  // Prediction
  btb.io.read.pc := ifuIn.pc
  pht.io.read.pc := ifuIn.pc
  ifuIn.taken := btb.io.read.hit && pht.io.read.taken
  ifuIn.target := btb.io.read.target

  // Update
  btb.io.write.update := lsuIn.update && lsuIn.isCtrlInst
  btb.io.write.pc := lsuIn.pc
  btb.io.write.target := lsuIn.target
  pht.io.write.update := lsuIn.update && (lsuIn.isCtrlInst || lsuIn.predTaken)
  pht.io.write.pc := lsuIn.pc
  pht.io.write.taken := lsuIn.realTaken
}
