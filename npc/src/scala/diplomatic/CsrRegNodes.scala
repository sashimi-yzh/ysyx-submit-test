package diplomatic

import org.chipsalliance.diplomacy._
import org.chipsalliance.diplomacy.nodes._
import org.chipsalliance.diplomacy.lazymodule.{LazyModule, LazyModuleImp}
import org.chipsalliance.cde.config.Parameters
import chisel3._
import chisel3.experimental.SourceInfo
import dto.CsrRegOperator

case class CsrRegEdgeParameters()
class CsrRegBundle extends CsrRegOperator

object CsrRegNodeImp
    extends SimpleNodeImp[
      Unit,
      Unit,
      CsrRegEdgeParameters,
      CsrRegBundle
    ] {
  def edge(
    pd:         Unit,
    pu:         Unit,
    p:          Parameters,
    sourceInfo: SourceInfo
  ): CsrRegEdgeParameters = CsrRegEdgeParameters()
  def bundle(e: CsrRegEdgeParameters): CsrRegBundle = new CsrRegBundle
  def render(e: CsrRegEdgeParameters): RenderedEdge =
    RenderedEdge(colour = "#00cc00")
}

class CsrRegMasterNode(
  implicit valName: ValName)
    extends SourceNode(CsrRegNodeImp)(Seq(CsrRegEdgeParameters))

class CsrRegNexusNode(
  implicit valName: ValName)
    extends NexusNode(CsrRegNodeImp)(
      dFn = { _ => () },
      uFn = { _ => () },
      inputRequiresOutput = false,
      outputRequiresInput = false
    )

class CsrRegMasterWrapper(
  implicit p: Parameters)
    extends LazyModule {
  val node = new CsrRegMasterNode

  override lazy val module = new Impl
  class Impl extends LazyModuleImp(this) {
    val csrRegOperator = IO(Flipped(new CsrRegOperator))
    csrRegOperator <> node.out.head._1
  }
}
