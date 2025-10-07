// module ysyx_24070003_raw (
//     // 来自译码的源寄存器
//     input  [4:0] idu_rs1_addr,
//     input  [4:0] idu_rs2_addr,
//     input         idu_rs1_valid,   // 为 1 表示本指令真正读 rs1
//     input         idu_rs2_valid,

//     // 来自
//     input         exu_reg_write_en,
//     input  [4:0]  exu_rd_addr,
//     input         exu_ren,

//     // 来自级
//     input         lsu_reg_write_en,
//     input  [4:0]  lsu_rd_addr,

//     output       rs1_raw_exu,
//     output       rs2_raw_exu,
//     output       rs1_raw_lsu,
//     output       rs2_raw_lsu,
//     // 输出有一个冲突就阻塞
//     output        stall
// );
//     function  conflict;
//         input [4:0] src;
//         input       src_valid;
//         input [4:0] dst;
//         input       dst_valid;
//         begin
//         conflict = src_valid & dst_valid & (src == dst) & (dst != 5'b0);
//         end
//     endfunction

//     assign rs1_raw_lsu = conflict(idu_rs1_addr, idu_rs1_valid, lsu_rd_addr, lsu_reg_write_en);
//     assign rs2_raw_lsu = conflict(idu_rs2_addr, idu_rs2_valid, lsu_rd_addr, lsu_reg_write_en);

//     wire rs1_raw_exu1 = conflict(idu_rs1_addr, idu_rs1_valid, exu_rd_addr, exu_reg_write_en);
//     wire rs2_raw_exu1 = conflict(idu_rs2_addr, idu_rs2_valid, exu_rd_addr, exu_reg_write_en);

//     assign rs1_raw_exu = rs1_raw_exu1 && (~exu_ren);
//     assign rs2_raw_exu = rs2_raw_exu1 && (~exu_ren);

    

//     assign stall         = (rs1_raw_exu1 | rs2_raw_exu1) && exu_ren ;
//                             //rs1_raw_wbu | rs2_raw_wbu ;
    
// endmodule

