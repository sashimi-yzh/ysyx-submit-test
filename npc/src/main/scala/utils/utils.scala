package top
import chisel3._
import chisel3.reflect.DataMirror
import chisel3.ActualDirection

object DriveZeroSinks {
  def apply(data: Data, isSubmodule: Boolean = false): Unit = {
    data match {
      case r: Record => r.elements.values.foreach(e => this.apply(e, isSubmodule))
      case v: Vec[_] => v.foreach(e => this.apply(e, isSubmodule))
      case b: Bits   =>
        val dir = DataMirror.directionOf(b)
        
        val shouldDrive = if (isSubmodule) {
          dir == ActualDirection.Input
        } else {
          dir == ActualDirection.Output
        }
        
        if (shouldDrive) {
          b := 0.U
        }
      case _ =>
    }
  }
}


object BundleConnect {
  def apply(source: Bundle, sink: Bundle): Unit = {
    source.elements.foreach { case (name, sourceData) =>
      if (sink.elements.contains(name)) {
        sink.elements(name) := sourceData
      }
    }
  }
}
