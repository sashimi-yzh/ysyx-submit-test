package top
import chisel3._
import chisel3.util._

class ICA2IDU extends IFU2ICA {
  val inst     = UInt(32.W)
  val excValid = Bool()
  val excType  = ExceptionType()
}

class ICacheBlock(blockSizeB: Int) extends Bundle {
  val tag  = UInt()
  val data = Vec(blockSizeB / 4, UInt(32.W))
}

class ICache(cacheSizeB: Int = 32, blockSizeB: Int = 4, assoc: Int = 1) extends Module {
  val io   = IO(new Bundle {
    val axi = new AXI4IO
    val out = Decoupled(new ICA2IDU)
    val in  = Flipped(Decoupled(new IFU2ICA))

    val fenceiValid = Input(Bool())

    val dpic_miss = Output(Bool())
  })
  val pc   = io.in.bits.pc
  val inst = io.out.bits.inst

  DriveZeroSinks(io.axi)
  io.dpic_miss := false.B

  // 参数计算
  require(isPow2(assoc), "PLRU 实现要求 assoc 为 2 的幂")
  require(cacheSizeB % (blockSizeB * assoc) == 0, "cacheSizeB must be a multiple of blockSizeB and assoc")
  val numBlocks     = cacheSizeB / blockSizeB
  val numGroups     = numBlocks / assoc
  val wordsPerBlock = blockSizeB / 4

  val offsetLen = log2Ceil(blockSizeB)
  val indexLen  = log2Ceil(numGroups)

  val offset = if (offsetLen > 2) pc(offsetLen - 1, 2) else 0.U
  val index  = if (indexLen > 0) pc(offsetLen + indexLen - 1, offsetLen) else 0.U
  val tag    = pc(31, offsetLen + indexLen)

  // 读取cache
  val cache    = Reg(Vec(numGroups, Vec(assoc, new ICacheBlock(blockSizeB))))
  val validArr = RegInit(VecInit(Seq.fill(numGroups)(VecInit(Seq.fill(assoc)(false.B)))))

  val wayHitsOH = (0 until assoc).map(i => validArr(index)(i) && cache(index)(i).tag === tag)
  val wayDatas  = (0 until assoc).map(i => cache(index)(i).data(offset))
  val hit       = VecInit(wayHitsOH).asUInt.orR
  inst := Mux1H(wayHitsOH, wayDatas)

  // 替换策略
  val plruBits   =
    if (assoc > 1)
      Some(RegInit(VecInit(Seq.fill(numGroups)(VecInit(Seq.fill(assoc - 1)(false.B))))))
    else None
  val wayHitIdx  = OHToUInt(wayHitsOH)
  val replaceWay = Wire(UInt())
  if (assoc == 1) {
    replaceWay := 0.U
  } else {
    replaceWay := PLRU.victim(plruBits.get(index))
  }

  // 状态机
  object State extends ChiselEnum {
    val sIdle, sArWait, sRWait = Value
  }
  val state = RegInit(State.sIdle)
  val refillOffset = Reg(UInt((log2Ceil(wordsPerBlock).max(1)).W))

  io.axi.ar.burst := "b01".U  // INCR
  io.axi.ar.size  := "b010".U // 4字节
  io.axi.ar.addr  := Cat(pc(31, offsetLen), 0.U(offsetLen.W))
  io.axi.ar.valid := state === State.sArWait
  io.axi.ar.len   := (wordsPerBlock - 1).U
  io.axi.r.ready  := state === State.sRWait

  io.out.bits.excType := ExceptionType.InstructionAccessFault
  val excValidReg = RegInit(false.B)
  io.out.bits.excValid := excValidReg
  BundleConnect(io.in.bits, io.out.bits)
  io.out.valid         := false.B
  io.in.ready          := false.B
//   io.out.valid         := io.in.valid && hit
  val flushReg = RegEnable(true.B,false.B, io.in.bits.flush)
  val isFlush = flushReg || io.in.bits.flush

  switch(state) {
    is(State.sIdle) {
      // io.out.valid := io.in.valid
      //   io.in.ready  := true.B

      excValidReg  := false.B
      io.in.ready  := io.out.ready && hit
      io.out.valid := io.in.valid && hit

      when(hit) {
        if (assoc > 1) PLRU.access(plruBits.get(index), wayHitIdx)

      }.elsewhen(io.in.valid) {
        io.dpic_miss                := true.B
        // io.out.valid                := false.B
        // io.in.ready                 := false.B
        refillOffset                := 0.U
        validArr(index)(replaceWay) := false.B
        state                       := State.sArWait
      }
    }
    is(State.sArWait) {
      when(io.axi.ar.ready) {
        state := State.sRWait
      }
    }
    is(State.sRWait) {
      when(io.axi.r.valid) {
        cache(index)(replaceWay).data(refillOffset) := io.axi.r.data
        refillOffset                                := refillOffset + 1.U
        when(io.axi.r.last) {
          validArr(index)(replaceWay)  := ! isFlush
          if (assoc > 1) PLRU.access(plruBits.get(index), replaceWay)
          cache(index)(replaceWay).tag := tag

          state                        := State.sIdle
          flushReg:= false.B
        }
        when(io.axi.r.resp =/= 0.U) {
          excValidReg := true.B
        }

      }
    }

  }

  when(io.fenceiValid) {
    validArr := 0.U.asTypeOf(validArr)
  }

}
