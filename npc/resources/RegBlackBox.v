
module ysyx_26030092_RegBlackBox(
    input         clock,
    input  [31:0] wdata,
    input  [4:0]  waddr,
    input         wen,
    input  [4:0]  raddr1,
    output [31:0] rdata1,
    input  [4:0]  raddr2,
    output [31:0] rdata2
);
    reg [31:0] rf [1:15];

    assign rdata1 = (raddr1[3:0] == 4'b0) ? 32'b0 : rf[raddr1[3:0]];
    assign rdata2 = (raddr2[3:0] == 4'b0) ? 32'b0 : rf[raddr2[3:0]];

    // 时钟使能实现：D 端直连 wdata，写选择放在 CE 引脚（比 D 端 mux 路径短）
    genvar gi;
    generate
      for (gi = 1; gi < 16; gi = gi + 1) begin : rf_ce
        always @(posedge clock) begin
          if (wen && waddr[3:0] == gi[3:0]) rf[gi] <= wdata;
        end
      end
    endgenerate

`ifdef NPC_DPI
    // DPI-C 必须和 rf 在同一个 module 作用域下！
    export "DPI-C" task read_reg;
    task read_reg(input int addr, output int data);
        data = (addr[3:0] == 4'b0) ? 32'b0 : rf[addr[3:0]];
    endtask
`endif
endmodule
