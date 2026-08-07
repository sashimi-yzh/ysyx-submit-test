package top

import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.freespec.AnyFreeSpec
import org.scalatest.matchers.must.Matchers
import java.nio.file.{Files, Paths}
import java.nio.{ByteBuffer, ByteOrder}
import config.Configs

class InstructionCacheTest extends AnyFreeSpec with Matchers {
  "InstructionCache" - {
    "cache sim" in {
      var dir   = Paths.get(sys.props("user.dir"))
      while (dir != null && !Files.exists(dir.resolve("build.mill"))) {
        dir = dir.getParent
      }
      val bytes = Files.readAllBytes(
        Option(dir).getOrElse(Paths.get(".")).resolve("build/itrace.bin")
      )
      val buf   = ByteBuffer.wrap(bytes).order(ByteOrder.LITTLE_ENDIAN)
      val addrs = Array.fill(bytes.length / 4) { buf.getInt & 0xffffffffL }

      def runSim(wordOffBits: Int, blockBits: Int): (Long, Long) = {
        val wordBits  = 2
        val wordCount = 1 << wordOffBits

        var hits   = 0L
        var misses = 0L

        implicit val p: org.chipsalliance.cde.config.Parameters =
          org.chipsalliance.cde.config.Parameters.empty.alterPartial {
            case Configs.ICacheWordOffBits => wordOffBits
            case Configs.ICacheBlockBits   => blockBits
          }
        simulate(new InstructionCache(wordBits = wordBits, addrWidth = 32)) { dut =>
          dut.reset.poke(true.B)
          dut.clock.step()
          dut.reset.poke(false.B)
          dut.clock.step()

          dut.io.axi.ar.ready.poke(true.B)
          dut.io.axi.r.valid.poke(true.B)
          dut.io.axi.r.bits.data.poke(0.U)
          dut.io.axi.r.bits.last.poke(false.B)

          var rBeats = 0

          for (addr <- addrs) {
            dut.io.req.valid.poke(true.B)
            dut.io.req.bits.addr.poke(addr.U)

            while (!dut.io.req.ready.peek().litToBoolean) {
              dut.clock.step()
            }
            dut.clock.step()

            if (dut.io.axi.ar.valid.peek().litToBoolean) {
              misses += 1
              rBeats = 0
            } else {
              hits += 1
            }

            dut.io.req.valid.poke(false.B)

            while (!dut.io.resp.valid.peek().litToBoolean) {
              dut.io.axi.r.bits.last.poke((rBeats == wordCount).B)
              dut.clock.step()
              rBeats += 1
            }
            dut.clock.step()
          }
        }
        (hits, misses)
      }

      val results = for {
        wordOffBits <- Seq(0, 1, 2)
        blockBits   <- Seq(2, 4, 6)
      } yield {
        val (hits, misses)  = runSim(wordOffBits, blockBits)
        val total           = hits + misses
        val hitRate         = if (total > 0) hits.toDouble / total * 100 else 0.0
        val wordCount       = 1 << wordOffBits
        val busTransactions = misses * wordCount
        val numBlocks       = 1 << blockBits
        info(
          f"wordOffBits=$wordOffBits  BlockBits=$blockBits  numBlocks=$numBlocks  wordCount=$wordCount  Total: $total  Hits: $hits  Misses: $misses  Hit Rate: $hitRate%.2f%%  BusTx: $busTransactions"
        )
        (wordOffBits, blockBits, hits, misses)
      }

      results.exists(_._3 > 0L) must be(true)
    }
  }
}
