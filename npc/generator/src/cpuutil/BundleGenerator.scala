package cpuutil

import java.io.{File, PrintWriter}
import chisel3._
import chisel3.util.experimental.decode._

object BundleGenerator {
  def getChiselTypeName(d: Data): String = d match {
    case _: Bool   => "Bool()"
    case u: UInt   => s"UInt(${u.getWidth}.W)"
    case s: SInt   => s"SInt(${s.getWidth}.W)"
    case v: Vec[_] => s"Vec(${v.length}, ${getChiselTypeName(v.head)})"
    case b: Bundle =>
      val name = b.getClass.getSimpleName.replace("$", "")
      s"new $name"
    case d => throw new IllegalArgumentException(s"Unknow type: $d")
  }
}
class BundleGenerator(
  packageName: String,
  bundleName:  String,
  fields:      Seq[DecodeField[_, _ <: Data] with CanAutoGenSig]) {
  def generate(outputPath: String): Unit = {
    val groupedFields = fields.groupBy(_.stage)
    val code = new StringBuilder

    code.append(s"package $packageName\n\n")
    code.append("import chisel3._\n\n")
    code.append(s"/* AUTO GENERATE */\n")
    code.append(s"class $bundleName extends Bundle {\n")

    groupedFields.keys.toSeq.sorted.foreach { unit =>
      code.append(s"  val $unit = new Bundle {\n")
      groupedFields(unit).foreach { field =>
        code.append(
          s"    val ${field.name} = ${BundleGenerator.getChiselTypeName(field.chiselType)}\n"
        )
      }
      code.append("  }\n")
    }

    code.append("}\n")

    val file = new File(outputPath)
    file.getParentFile.mkdirs()
    val writer = new PrintWriter(file)
    writer.write(code.toString())
    writer.close()

    println(s"Generate $bundleName at $outputPath")
  }
}
