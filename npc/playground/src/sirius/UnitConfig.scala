package sirius

import chisel3._
import scala.collection.immutable.ListMap

case class UnitConfig(
  val aluMap: () => CfgMap[
    (ExuOutSelEnum.Type, () => AluParent),
    ListMap[ExuOutSelEnum.Type, () => AluParent]
  ] = () =>
    CfgMap(
      ListMap(
        (Set(ExtTypeEnum.I), Set(32, 64)) -> ListMap(
          ExuOutSelEnum.aluBase -> (() => new AluBase)
        )
      )
    ),
  val csr32Map: ListMap[(CsrEnum.Type, CsrEnum.Type), CoreConfig => CsrParent32] = ListMap(
    // (CsrAddr.mcycleh, CsrAddr.mcycle) -> (cfg => new CsrMcycle32()(cfg))
  ),
  val csrMap: ListMap[CsrEnum.Type, CoreConfig => CsrParent] = ListMap(
    CsrEnum.mvendorid -> (cfg => new CsrMvendorid()(cfg)),
    CsrEnum.marchid -> (cfg => new CsrMarchid()(cfg)),
    CsrEnum.mtvec -> (cfg => new CsrMtvec()(cfg)),
    CsrEnum.mepc -> (cfg => new CsrMepc()(cfg)),
    CsrEnum.mcause -> (cfg => new CsrMcause()(cfg)),
    CsrEnum.mstatus -> (cfg => new CsrMstatus()(cfg)),
  )) {
}
object UnitConfig {
  implicit val default: UnitConfig = UnitConfig()
}
