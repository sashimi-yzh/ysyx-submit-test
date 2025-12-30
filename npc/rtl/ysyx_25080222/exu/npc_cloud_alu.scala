// package npc_cloud

// import chisel3._
// import chisel3.util._
// //ALU单元
// class npc_cloud_alu extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(32.W))
//         val out = Output(UInt(32.W))
//     } )
//     io.out := io.A + io.B
// }

// class npc_cloud_sub extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(32.W))
//         val out = Output(UInt(32.W))
//         val overflow = Output(Bool())
//     } )

//     io.out := io.A + ~io.B + 1.U //补码（相反数）：取反加一
//     //溢出判断原理：两个参加加法运算的变量符号相同，而运算结果的符号与其不相同，则运算结果不准确，产生溢出
//     io.overflow := (io.A(31) =/= io.B(31)) && (io.A(31) =/= io.out(31))
// }

// class npc_cloud_alu_33bit extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(32.W))
//         val out = Output(UInt(33.W))
//     } )

//     io.out := Cat(0.U(1.W), io.A)+ Cat(0.U(1.W), io.B)
// }

// class npc_cloud_sub_u33bit extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(32.W))
//         val out = Output(UInt(33.W))
//     } )

//     //n位无符号数计算:(0,A)+((0,~B)+1) 借位(结果的n+1位)为1 则A>=B  借位为0则A<B  (也可以当做n+1位有符号正数计算)
//     io.out := Cat(0.U(1.W), io.A)+ Cat(0.U(1.W), ~io.B) + 1.U
// }

// class npc_cloud_xor extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(32.W))
//         val out = Output(UInt(32.W))
//     } )
//     io.out := io.A ^ io.B;
// }

// class npc_cloud_or extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(32.W))
//         val out = Output(UInt(32.W))
//     } )
//     io.out := io.A | io.B;
// }

// class npc_cloud_equ extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(32.W))
//         val out = Output(Bool())
//     } )
//     io.out := (io.A === io.B)
// }

// class npc_cloud_shift_right_arithmetic extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(5.W))
//         val out = Output(UInt(32.W))
//     } )
//     io.out := (io.A.asSInt >> io.B).asUInt

// }

// class npc_cloud_shift_right_logical extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(5.W))
//         val out = Output(UInt(32.W))
//     } )
//     io.out := io.A >> io.B
// }

// class npc_cloud_shift_left_logical extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(5.W))
//         val out = Output(UInt(32.W))
//     } )
//     io.out := io.A << io.B
// }

// class npc_cloud_bitwise_and extends Module{
//     val io = IO(new Bundle{
//         val A = Input(UInt(32.W))
//         val B = Input(UInt(32.W))
//         val out = Output(UInt(32.W))
//     } )
//     io.out := io.A & io.B
// }

