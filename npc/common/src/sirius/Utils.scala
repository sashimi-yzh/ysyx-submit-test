package sirius

import scala.collection.Factory
import cpuutil.CanAutoGenSig
import chisel3._
import chisel3.util.BitPat
import chisel3.util.experimental.decode._

case class CfgMap[A, T <: Iterable[A]](
  map: Map[(Set[ExtTypeEnum.Type], Set[Int]), T]) {

  def flatten(
    implicit cfg: CoreConfig,
    factory:      Factory[A, T]
  ): T = {
    val items: Iterable[A] = map.filter { case ((exts, xlens), _) =>
      exts.forall(t => cfg.extensions().contains(t)) && xlens.contains(cfg.xlen)
    }.values.flatten

    factory.fromSpecific(items)
  }
}

