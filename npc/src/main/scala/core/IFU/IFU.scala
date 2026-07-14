package top
import chisel3._
import chisel3.util._

class IFU2ICA extends Bundle {
  val pc             = UInt(32.W)
  val flush          = Output(Bool())
  val dpic_tag       = UInt(8.W)

}

class IFU extends Module {
  val io  = IO(new Bundle {
    val out        = Decoupled(new IFU2ICA)
    val redirectEn = Input(Bool())
    val redirectPc = Input(UInt(32.W))
  })
  val pc  = RegInit(0x30000000.U(32.W))
  // val pc  = RegInit("h80000000".U(32.W))
  val pc4 = WireInit((pc + 4.U)(31, 0))

  val dpic_tagReg = RegInit(0.U(8.W))

  io.out.bits.pc             := pc
  io.out.bits.dpic_tag       := dpic_tagReg
  io.out.valid               := false.B
  io.out.bits.flush          := io.redirectEn

  when(io.redirectEn) {
    pc := io.redirectPc
  }.otherwise {
    io.out.valid := true.B
    when(io.out.fire) {
      pc          := pc4
      dpic_tagReg := dpic_tagReg + 1.U
    }
  }
}

//unused

// class BTBEntry(tagWidth: Int) extends Bundle {
//   val tag     = UInt(tagWidth.W)
//   val target  = UInt(32.W)
//   // val dir     = UInt(1.W)
//   val history = UInt(2.W)
// }

// class BranchInfo extends Bundle {
//   val pc     = UInt(32.W)
//   val target = UInt(32.W)
//   val dir    = UInt(1.W)
//   val valid  = Bool()
//   val taken  = Bool()
// }

// class IFU_bp extends Module {
//   val io = IO(new Bundle {
//     val out        = Decoupled(new IFU2ICA)
//     val redirectEn = Input(Bool())
//     val redirectPc = Input(UInt(32.W))

//     val branch = Input(new BranchInfo)
//   })

//   var isNPC       = sys.env.getOrElse("USE_YSYXSOC", "1") == "0"
//   // isNPC = false
//   val initPc      =
//     if (isNPC) "h80000000"
//     else "h30000000"
//   val pc          = RegInit(initPc.U(32.W))
//   val pc4         = WireInit((pc + 4.U)(31, 0))
//   val dpic_tagReg = RegInit(0.U(8.W))
//   val updateBTB   = RegInit(false.B)

//   io.out.bits.pc       := pc
//   io.out.bits.pc4      := pc4
//   io.out.bits.dpic_tag := dpic_tagReg
//   io.out.valid         := false.B

//   // 保存跳转信息
//   val branchReg = RegEnable(io.branch, io.branch.valid)

//   // BTB参数计算
//   val numEntries = 4
//   val assoc      = 4
//   val numGroups  = numEntries / assoc
//   val indexLen   = log2Ceil(numGroups)
//   val tagWidth   = 32 - (indexLen + 2)

//   val btb      = Reg(Vec(numGroups, Vec(assoc, new BTBEntry(tagWidth))))
//   val validArr = RegInit(VecInit(Seq.fill(numGroups)(VecInit(Seq.fill(assoc)(false.B)))))

//   val readIndex     = if (indexLen > 0) pc(indexLen + 1, 2) else 0.U
//   val readTag       = pc(31, indexLen + 2)
//   val readWayHitsOH = VecInit((0 until assoc).map(i => btb(readIndex)(i).tag === readTag && validArr(readIndex)(i)))
//   val readWayDatas  = VecInit((0 until assoc).map(i => btb(readIndex)(i)))
//   val readHit       = readWayHitsOH.asUInt.orR
//   val entry         = Mux1H(readWayHitsOH, readWayDatas)
//   val readWayHitIdx = OHToUInt(readWayHitsOH)

//   val writeIndex     = if (indexLen > 0) branchReg.pc(indexLen + 1, 2) else 0.U
//   val writeTag       = branchReg.pc(31, indexLen + 2)
//   val writeWayHitsOH = VecInit((0 until assoc).map(i => btb(writeIndex)(i).tag === writeTag && validArr(writeIndex)(i)))
//   val writeHit       = writeWayHitsOH.asUInt.orR

//   val plruBits        =
//     if (assoc > 1) Some(RegInit(VecInit(Seq.fill(numGroups)(VecInit(Seq.fill(assoc - 1)(false.B)))))) else None
//   val writeReplaceWay = if (assoc > 1) PLRU.victim(plruBits.get(writeIndex)) else 0.U

//   // 处理跳转
//   val branchTaken  = WireInit(false.B)
//   val branchNextPc = WireInit(entry.target)
//   io.out.bits.branchPreTaken := branchTaken

//   when(io.redirectEn) {
//     pc          := io.redirectPc
//     dpic_tagReg := dpic_tagReg + 1.U
//     updateBTB   := true.B
//   }.otherwise {
//     io.out.valid := true.B
//     when(io.out.ready) {
//       pc          := Mux(branchTaken, branchNextPc, pc4)
//       dpic_tagReg := dpic_tagReg + 1.U
//     }
//   }

//   // 更新btb
//   when(updateBTB) {
//     when(branchReg.valid) {
//       when(writeHit) {

//         for (i <- 0 until assoc) {
//           when(writeWayHitsOH(i)) { // 直接用独热码做写使能
//             val hist             = btb(writeIndex)(i).history
//             val nextHistTaken    = Mux(hist === 3.U, 3.U, hist + 1.U)
//             val nextHistNotTaken = Mux(hist === 0.U, 0.U, hist - 1.U)

//             btb(writeIndex)(i).history := Mux(branchReg.taken, nextHistTaken, nextHistNotTaken)

//           }
//         }

//         if (assoc > 1) PLRU.access(plruBits.get(writeIndex), OHToUInt(writeWayHitsOH))

//       }.elsewhen(branchReg.taken) {
//         validArr(writeIndex)(writeReplaceWay) := true.B
//         val replaceEntry = btb(writeIndex)(writeReplaceWay)
//         replaceEntry.tag     := writeTag
//         replaceEntry.target  := branchReg.target
//         replaceEntry.history := 2.U

//         if (assoc > 1) PLRU.access(plruBits.get(writeIndex), writeReplaceWay)
//       }
//       branchReg.valid := false.B

//     }

//     updateBTB := false.B
//   }.otherwise {
//     when(readHit) {
//       if (assoc > 1) PLRU.access(plruBits.get(readIndex), readWayHitIdx)

//       /// btfn
//       when(entry.history(1).asBool) {
//         branchTaken := true.B
//       }.otherwise {
//         branchTaken := false.B
//       }
//     }
//   }

//   when(reset.asBool) {
//     branchReg.valid := false.B
//     branchReg.taken := false.B
//   }

// }
