// package empty
// import chisel3._
// import chisel3.util._

// class Xbar() extends PrefixedModule {
//   val IN_AXI = IO(Flipped(new AXI_Lite))
//   val UART_AXI = IO(new AXI_Lite)
//   val CLINT_AXI = IO(new AXI_Lite)
//   val MEM_AXI = IO(new AXI_Lite)
//   set_flipped_AXI_zero(IN_AXI)
//   set_AXI_zero(UART_AXI)
//   set_AXI_zero(CLINT_AXI)
//   set_AXI_zero(MEM_AXI)
//   val sIDLE :: sMEM :: sUART :: sCLINT :: Nil = Enum(4)
//   val r_owner = RegInit(sIDLE)
//   val w_owner = RegInit(sIDLE)

//   val MEM_fire = GenerateFireSignal(MEM_AXI)
//   val UART_fire = GenerateFireSignal(UART_AXI)
//   val CLINT_fire = GenerateFireSignal(CLINT_AXI)
//   val IN_fire = GenerateFireSignal(IN_AXI)

//   val is_raddr_in_mem = (IN_AXI.ar.araddr >= 0x80000000L.U(
//     32.W
//   )) && (IN_AXI.ar.araddr < 0x88000000L.U(32.W))

//   val is_raddr_in_uart = (IN_AXI.ar.araddr >= 0xa0000300L.U(
//     32.W
//   )) && (IN_AXI.ar.araddr < 0xa0000400L.U(32.W))

//   val is_raddr_in_clint = false.B

//   val is_waddr_in_mem = (IN_AXI.aw.awaddr >= 0x80000000L.U(
//     32.W
//   )) && (IN_AXI.aw.awaddr < 0x88000000L.U(32.W))

//   val is_waddr_in_uart = (IN_AXI.aw.awaddr >= 0xa0000300L.U(
//     32.W
//   )) && (IN_AXI.aw.awaddr < 0xa0000400L.U(32.W))

//   val is_waddr_in_clint = false.B

//   val bind_to_mem_r =
//     (r_owner === sIDLE && IN_AXI.ar.arvalid && is_raddr_in_mem)
//   val bind_to_uart_r =
//     (r_owner === sIDLE && IN_AXI.ar.arvalid && is_raddr_in_uart)
//   val bind_to_clint_r =
//     (r_owner === sIDLE && IN_AXI.ar.arvalid && is_raddr_in_clint)

//   when(r_owner === sMEM) {
//     IN_AXI.ar <> MEM_AXI.ar
//     IN_AXI.r <> MEM_AXI.r
//   }

//   when(r_owner === sUART) {
//     IN_AXI.ar <> UART_AXI.ar
//     IN_AXI.r <> UART_AXI.r
//   }

//   when(r_owner === sCLINT) {
//     IN_AXI.ar <> CLINT_AXI.ar
//     IN_AXI.r <> CLINT_AXI.r
//   }

//   val bind_to_mem_w =
//     (w_owner === sIDLE && IN_AXI.aw.awvalid && is_waddr_in_mem)
//   val bind_to_uart_w =
//     (w_owner === sIDLE && IN_AXI.aw.awvalid && is_waddr_in_uart)
//   val bind_to_clint_w =
//     (w_owner === sIDLE && IN_AXI.aw.awvalid && is_waddr_in_clint)

//   when(w_owner === sMEM) {
//     IN_AXI.aw <> MEM_AXI.aw
//     IN_AXI.w <> MEM_AXI.w
//     IN_AXI.b <> MEM_AXI.b
//   }

//   when(w_owner === sUART) {
//     IN_AXI.aw <> UART_AXI.aw
//     IN_AXI.w <> UART_AXI.w
//     IN_AXI.b <> UART_AXI.b
//   }

//   when(w_owner === sCLINT) {
//     IN_AXI.aw <> CLINT_AXI.aw
//     IN_AXI.w <> CLINT_AXI.w
//     IN_AXI.b <> CLINT_AXI.b
//   }

//   r_owner := MuxLookup(r_owner, sIDLE)(
//     Seq(
//       sIDLE -> Mux(
//         IN_AXI.ar.arvalid,
//         MuxCase(
//           sIDLE,
//           Seq(
//             bind_to_mem_r -> sMEM,
//             bind_to_uart_r -> sUART,
//             bind_to_clint_r -> sCLINT
//           )
//         ),
//         sIDLE
//       ),
//       sMEM -> Mux(MEM_fire.r_fire, sIDLE, sMEM),
//       sUART -> Mux(UART_fire.r_fire, sIDLE, sUART),
//       sCLINT -> Mux(CLINT_fire.r_fire, sIDLE, sCLINT)
//     )
//   )

//   w_owner := MuxLookup(w_owner, sIDLE)(
//     Seq(
//       sIDLE -> Mux(
//         IN_AXI.aw.awvalid,
//         MuxCase(
//           sIDLE,
//           Seq(
//             bind_to_mem_w -> sMEM,
//             bind_to_uart_w -> sUART,
//             bind_to_clint_w -> sCLINT
//           )
//         ),
//         sIDLE
//       ),
//       sMEM -> Mux(MEM_fire.b_fire, sIDLE, sMEM),
//       sUART -> Mux(UART_fire.b_fire, sIDLE, sUART),
//       sCLINT -> Mux(CLINT_fire.b_fire, sIDLE, sCLINT)
//     )
//   )

// }
