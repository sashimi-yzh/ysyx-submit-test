package npc.PMU

import chisel3._

class ysyx_26030092_PerfCounterArray extends ExtModule {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val reset = Input(Bool())
    val event = Input(Bool())
  })
  addResource("/perf.v")
}

object PerfCounter {
  private val usedNames = scala.collection.mutable.Set[String]()

  def apply(name: String): Bool = {
    require(!usedNames.contains(name), s"PerfCounter: duplicate name '$name'")
    usedNames += name
    val u = Module(new ysyx_26030092_PerfCounterArray)
    u.suggestName(name)
    u.io.clock := Module.clock
    u.io.reset := Module.reset.asBool
    u.io.event
  }
}
