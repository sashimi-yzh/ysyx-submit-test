package branchpredictor

import chisel3._
import chisel3.util._

import common_def._

class BranchPredictorIO extends Bundle {
  val historyHit = Input(Bool())

  val pc = Input(Types.UWord)

  val historyIsJAL  = Input(Bool())
  val historyTarget = Input(Types.UWord)
  val predictTarget = Output(Types.UWord)
}

class BranchPredictor extends Module {
  val io = IO(new BranchPredictorIO)

  // Simple static predictor: BTFN (Backward Taken, Forward Not Taken)

  val isBackward = io.historyTarget < io.pc

  // io.predictTarget := Mux(io.historyHit, io.historyTarget, io.pc + 4.U)
  // io.predictTarget := Mux(io.historyHit && isBackward, io.historyTarget, io.pc + 4.U)
  // io.predictTarget := io.pc + 4.U
  io.predictTarget := Mux(io.historyHit && (io.historyIsJAL || isBackward), io.historyTarget, io.pc + 4.U)
}
