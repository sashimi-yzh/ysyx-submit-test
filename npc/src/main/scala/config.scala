package cpu 

import io.circe._ 
import io.circe.generic.auto._
import io.circe.parser._
import scala.io.Source
import chisel3._
import freechips.rocketchip.amba.axi4._

case class NPCConfig(
  USE_SOC: Boolean,
  XLEN: Int,
  REG_NUM: Int,
  PC_INIT: BigInt,
  MSTATUS_INIT: Long,
  MTVEC_INIT: Long,
  CLINT_BASE: Long,
  CLINT_END: Long,
  PERF_CNT: Boolean,
  axiparams: AXI4BundleParameters,
  icacheparams: CacheParameters,
  USE_ICACHE: Boolean,
  bpuparameters: BPUParameters,
  USE_BPU: Boolean,
  USE_REG0: Boolean
){
  def asString: String = {
    s"""
       |NPCConfig(
       |  USE_SOC = $USE_SOC,
       |  XLEN = $XLEN,
       |  REG_NUM = $REG_NUM,
       |  PC_INIT = 0x${PC_INIT.toString(16)},
       |  MSTATUS_INIT = 0x${MSTATUS_INIT.toHexString},
       |  MTVEC_INIT = 0x${MTVEC_INIT.toHexString},
       |  CLINT_BASE = 0x${CLINT_BASE.toHexString},
       |  CLINT_END = 0x${CLINT_END.toHexString},
       |  PERF_CNT = $PERF_CNT,
       |  axiparams = $axiparams,
       |  icacheparams = $icacheparams,
       |  USE_ICACHE = $USE_ICACHE,
       |  bpuparameters = $bpuparameters,
       |  USE_BPU = $USE_BPU,
       |  USE_REG0 = $USE_REG0,
       |)
       |""".stripMargin
  }
}

object CPUAXI4BundleParameters {
  def apply() = AXI4BundleParameters(addrBits = 32, dataBits = 32, idBits = 4)
}

//blockSize: Byte
case class CacheParameters(nSets: Int, nWays: Int, blockSize: Int, addrBits: Int) {
  val cacheSize: Int = nSets * nWays * blockSize
  val offsetBits: Int = (math.log(blockSize) / math.log(2)).toInt
  val indexBits: Int = (math.log(nSets) / math.log(2)).toInt
  val tagBits: Int = (addrBits - indexBits - offsetBits)
  override def toString: String = 
    s"Cache Size: $cacheSize bytes, Tag: $tagBits bits, Index: $indexBits bits, Offset: $offsetBits bits"
}


object ICacheParameters{
    def apply() = CacheParameters(
        nSets = 4,    // should be 2^n
        nWays = 1,   
        blockSize = 8, // should be 4*n  // only support 4 now 
        addrBits = 32,
    )
}

case class BPUParameters(useDynamic: Boolean, nEntries: Int, pcWidth: Int, npcWidth: Int, cntWidth: Int) {
  override def toString: String = 
    if(useDynamic) s"Number of Entries: $nEntries, PC Width: $pcWidth bits, NPC Width: $npcWidth bits, Counter Width: $cntWidth bits"
    else s"Static Branch Prediction"
}

object BPUParameters {
  def apply(): BPUParameters = BPUParameters(useDynamic = false, nEntries = 2, pcWidth = 9, npcWidth = 9, cntWidth = 2)
}

object NPCConfig {

  def apply(): NPCConfig = {
    val npc_home = System.getenv("NPC_HOME")
    val configJson = parse(scala.io.Source.fromFile(npc_home + "/.config.json").mkString).getOrElse(Json.Null)
    val decodedConfig = configJson.asObject.getOrElse(JsonObject())

    def getConfig(key: String): String = {
        decodedConfig(key).flatMap(_.asString).getOrElse("")
    }
    //val SOC_EN = getConfig("CONFIG_SOC_EN") == "\"enable\""
    val USE_ICACHE = getConfig("CONFIG_USE_ICACHE") == "y"
    val USE_BPU = getConfig("CONFIG_USE_BPU") == "y"
    val PERF_CNT = getConfig("CONFIG_PERF_CNT") == "y"
    val USE_REG0 = getConfig("CONFIG_USE_REG0") == "y"
    val xlen = if (getConfig("CONFIG_ISA") == "\"riscv32\"") 32 else 64
    val USE_SOC: Boolean = Option(System.getProperty("USE_SOC"))
                            .orElse(sys.env.get("USE_SOC"))
                            .exists(_.equalsIgnoreCase("y"))
    
    NPCConfig(
      USE_SOC = USE_SOC,
      XLEN = xlen,
      REG_NUM = if (getConfig("CONFIG_RVE") == "y") 16 else 32,
      PC_INIT = if (USE_SOC) 0x30000000L else 0x80000000L,
      MSTATUS_INIT = if (xlen == 32) 0x1800 else 0xa00001800L,
      MTVEC_INIT = if (xlen == 32) 0x100 else 0x80000000L,
      CLINT_BASE = if(USE_SOC) 0x02000000L else 0xa0000040L,
      CLINT_END = if(USE_SOC) 0x0200ffffL else 0xa0000050L,
      PERF_CNT = PERF_CNT,
      axiparams = CPUAXI4BundleParameters(),
      icacheparams = ICacheParameters(),
      USE_ICACHE = USE_ICACHE,
      bpuparameters = BPUParameters(),
      USE_BPU = USE_BPU,
      USE_REG0 = USE_REG0
    )
  }
}