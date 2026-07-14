package top
import chisel3._
import chisel3.util._



object PLRU {
  /** 给定某个 set 的 PLRU 树状态(长度为 assoc-1 的 bit 数组),返回应替换的 way */
  def victim(bits: Vec[Bool]): UInt = {
    val assoc = bits.length + 1
    val depth = log2Ceil(assoc)
    def go(node: Int): UInt = {
      val l = 2 * node + 1
      val r = 2 * node + 2
      val lv = if (l < assoc - 1) go(l) else (l - (assoc - 1)).U(depth.W)
      val rv = if (r < assoc - 1) go(r) else (r - (assoc - 1)).U(depth.W)
      Mux(bits(node), rv, lv)
    }
    go(0)
  }

  /** 访问 way 后更新该 set 的 PLRU 树状态,标记 way 为最近使用 */
  def access(bits: Vec[Bool], way: UInt): Unit = {
    val assoc = bits.length + 1
    val depth = log2Ceil(assoc)
    def go(node: Int, level: Int): Unit = {
      if (level == depth) return
      when(way(depth - 1 - level)) {
        bits(node) := false.B        // 刚走了右边 -> 下次victim指向左边
        go(2 * node + 2, level + 1)
      }.otherwise {
        bits(node) := true.B         // 刚走了左边 -> 下次victim指向右边
        go(2 * node + 1, level + 1)
      }
    }
    go(0, 0)
  }
}