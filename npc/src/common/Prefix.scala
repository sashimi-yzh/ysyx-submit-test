package npc

import chisel3.experimental.prefix
import chisel3.withModulePrefix

object ysyxPrefix {
  def apply[T](body: => T): T =
    withModulePrefix("ysyx_26030092")(prefix("ysyx_26030092")(body))
}
