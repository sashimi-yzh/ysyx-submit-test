package diplomatic

import org.chipsalliance.diplomacy._
import org.chipsalliance.diplomacy.nodes._
import org.chipsalliance.diplomacy.lazymodule.{LazyModule, LazyModuleImp}
import org.chipsalliance.cde.config.Parameters
import chisel3._
import chisel3.experimental.SourceInfo
import axi4.AXI4Bundle

case class AXI4MasterNodeParameters(
  addrBits: Int = 32,
  dataBits: Int = 32,
  idBits: Int = 4) {
  val endId: Int = 1 << idBits
}

case class AXI4SlaveNodeParameters(
  address: Seq[AddressSet])

case class AXI4EdgeParameters(
  master: AXI4MasterNodeParameters,
  slave: AXI4SlaveNodeParameters) {
  def addrBits: Int = master.addrBits
  def dataBits: Int = master.dataBits
  def idBits:   Int = master.idBits
}

object AXI4NodeImp
    extends SimpleNodeImp[
      AXI4MasterNodeParameters,
      AXI4SlaveNodeParameters,
      AXI4EdgeParameters,
      AXI4Bundle
    ] {
  def edge(
    pd:         AXI4MasterNodeParameters,
    pu:         AXI4SlaveNodeParameters,
    p:          Parameters,
    sourceInfo: SourceInfo
  ): AXI4EdgeParameters = AXI4EdgeParameters(pd, pu)
  def bundle(e: AXI4EdgeParameters): AXI4Bundle   = {
    new AXI4Bundle(axi4.AXI4Parameters(e.addrBits, e.dataBits, e.idBits))
  }
  def render(e: AXI4EdgeParameters): RenderedEdge =
    RenderedEdge(colour = "#0000ff")
}

class AXI4MasterNode(
  masterParams:     AXI4MasterNodeParameters
)(
  implicit valName: ValName)
    extends SourceNode(AXI4NodeImp)(Seq(masterParams))

class AXI4SlaveNode(
  slaveParams:      AXI4SlaveNodeParameters
)(
  implicit valName: ValName)
    extends SinkNode(AXI4NodeImp)(Seq(slaveParams))

class AXI4MasterWrapper(
  params:     AXI4MasterNodeParameters = AXI4MasterNodeParameters()
)(
  implicit p: Parameters)
    extends LazyModule {
  val node = new AXI4MasterNode(params)

  lazy val module = new Impl
  class Impl extends LazyModuleImp(this) {
    val axi            = IO(Flipped(new AXI4Bundle(axi4.AXI4Parameters(params.addrBits, params.dataBits, params.idBits))))
    val (bundle, edge) = node.out.head
    axi <> bundle
  }
}

class AXI4NexusNode(
  dFn:              Seq[AXI4MasterNodeParameters] => AXI4MasterNodeParameters,
  uFn:              Seq[AXI4SlaveNodeParameters] => AXI4SlaveNodeParameters
)(
  implicit valName: ValName)
    extends NexusNode(AXI4NodeImp)(
      dFn,
      uFn,
      inputRequiresOutput = false,
      outputRequiresInput = false
    )
