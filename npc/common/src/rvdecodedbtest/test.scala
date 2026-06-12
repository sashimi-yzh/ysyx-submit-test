package rvdecodedbtest

import org.chipsalliance.rvdecoderdb
import os.Path

object Test extends App {
  val insts = rvdecoderdb.instructions(Path("/home/waterblock/ysyx-workbench/npc/rvdecoderdb/riscv-opcodes/"))
  // val inst = insts.filter(_.name.contains("fence"))
  // val inst = insts.filter(_.name.contains("c."))
  // val inst = insts.filter(i => Seq("rv_c", "rv32_c").exists(i.instructionSets.map(_.name).contains) && i.pseudoFrom.isEmpty)
  // inst.foreach{println(_)}
  val inst = insts.filter(i => Seq("rv_c", "rv32_c").exists(i.instructionSets.map(_.name).contains) && i.pseudoFrom.isEmpty).groupBy(_.args)
  inst.foreach{_._2.foreach{println(_)}}
}
