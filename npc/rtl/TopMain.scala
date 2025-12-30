package npc_cloud

import chisel3.stage._

import java.io._
import scala.io._

import firrtl.options.TargetDirAnnotation
import firrtl.stage.OutputFileAnnotation

object TopMain extends App {

	// 在 args 中添加控制文件名的参数
	val allArgs = args ++ Array(
		"-o", "npc_cloud_cpu.v",  // 使用 -o 而不是 --output-file
		"--target-dir", "build"
	)

	(new ChiselStage).execute(
		allArgs,
		Seq(
			//ChiselGeneratorAnnotation(() => new ysyx_25080222(pcInitValue)), 
			ChiselGeneratorAnnotation(() => new ysyx_25080222), 
			firrtl.stage.RunFirrtlTransformAnnotation(new AddModulePrefix()), 
			ModulePrefixAnnotation("ysyx_25080222_")
		)
	)
	
  	// 合并DPI-C文件
	mergeDPI_C()
	
	println("Verilog generation completed with DPI-C integration!")

  	def mergeDPI_C(): Unit = {
		val verilogFile = new File("build/npc_cloud_cpu.v")
		val sourcedpiFile = new File("rtl/ysyx_25080222/DPI-C/npc_cloud_DPI_C.v")
		val pcinitFile = new File("build/ysyx_25080222_pc.v")
		val generatedDpiFile = new File("build/npc_cloud_DPI_C.v")
		val finalFile = new File("build/ysyx_25080222.v")            // 最终文件名
		
		// 检查源DPI-C文件是否存在
		if (!sourcedpiFile.exists()) {
			println(s"Warning: DPI-C source file not found: ${sourcedpiFile.getPath}")
			return  // 如果不存在，直接返回，不执行后续操作
		}
		
		// 读取Verilog和DPI-C内容
		val verilogContent = Source.fromFile(verilogFile).mkString
		val dpiContent = Source.fromFile(sourcedpiFile).mkString
		val pcContent = Source.fromFile(pcinitFile).mkString


		//合并DPI-C文件
		if (!verilogContent.contains("import.*DPI-C")) {  //检查Verilog中是否已经包含DPI-C导入语句
			//字符串拼接，用于在内存中创建合并后的内容(原始的CPU设计代码+所有DPI-C函数声明)
			val mergedContent = verilogContent + "\n\n" + 
        		"// DPI-C Functions\n" + dpiContent + "\n\n" + 
				"// PC_INIT\n" + pcContent
      		val pw = new PrintWriter(finalFile)// 写回文件
      		pw.write(mergedContent)     // 写入合并后的内容,覆盖原有内容
      		pw.close()
    	}


		  // 删除中间文件
  		if (verilogFile.exists() && verilogFile != finalFile) {
    		verilogFile.delete()
  		}

		//删除生成的DPI-C文件（如果存在）
    	if (generatedDpiFile.exists() && generatedDpiFile.delete()) {
      		//println(s"Cleaned up generated DPI-C file: ${generatedDpiFile.getPath}")
    	}

		//删除生成的pc初始化文件（如果存在）
    	if (pcinitFile.exists() && pcinitFile.delete()) {
      		//println(s"Cleaned up generated DPI-C file: ${generatedDpiFile.getPath}")
    	}

	}

}
