package npc.core.isu

import chisel3._
import chisel3.util._
import npc.common.Config._
import npc.common._
import npc.common.Instructions._


class GPR {
    val gpr = Mem(GPR_NUM, UInt(WORD_LEN.W))
    def read(addr: UInt) : UInt = Mux(addr === 0.U, 0.U, gpr(addr))
    def write(addr: UInt, data: UInt) = {
        gpr(addr) := data(WORD_LEN - 1, 0)
    }
}

/*
             _   _ _   _ _____ ____  _   _ _____ _     _
            | \ | | | | |_   _/ ___|| | | | ____| |   | |
            |  \| | | | | | | \___ \| |_| |  _| | |   | |
            | |\  | |_| | | |  ___) |  _  | |___| |___| |___
            |_| \_|\___/  |_| |____/|_| |_|_____|_____|_____|
*/
class ScoreBoard {
  val busy = RegInit(0.U(GPR_NUM.W))
  def isBusy(idx: UInt): Bool = busy(idx)
  def mask(idx: UInt) = (1.U(GPR_NUM.W) << idx)(GPR_NUM-1, 0)
  def update(setMask: UInt, clearMask: UInt) = {
    // When clearMask(i) and setMask(i) are both set, setMask(i) wins.
    // This can correctly record the busy bit when reg(i) is written
    // and issued at the same cycle.
    // Note that rf(0) is always free.
    busy := Cat(((busy & ~clearMask) | setMask)(GPR_NUM-1, 1), 0.U(1.W))
  }
}
