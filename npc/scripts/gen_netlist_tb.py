#!/usr/bin/env python3
# 为"综合网表"生成一个专用 testbench：不改网表、不加 wrap，只把顶层端口
# 连接到 tb 里的向量信号，并加一个"程序结束"的判据。
#
# 用法: gen_netlist_tb.py <netlist.v> <out_tb.v>
import re
import sys

SRC = "ysyx_26030092"


def parse_ports(path):
    """返回 [(端口名, 方向, base, bit 或 None, base 的总位宽)]。

    兼容三种端口写法：
      1. 向量端口    input [31:0] io_master_araddr ;   （iEDA 输出的网表）
      2. 中括号分位  \io_master_araddr[3]              （yosys 的 splitnets -ports）
      3. 下划线分位  io_master_araddr_3_               （旧版 yosys）
    """
    text = open(path).read()
    m = re.search(r'^module\s+' + SRC + r'\s*\(', text, re.M)
    if not m:
        raise SystemExit("网表里找不到 module " + SRC)
    body = text[m.end():]
    end = body.index(");")
    names = [n.strip().replace("\\", "").strip() for n in body[:end].split(",")]
    names = [n for n in names if n]

    dirs = {}
    widths = {}
    for line in body[end:].split("\n"):
        line = line.strip().rstrip(";")
        mt = re.match(r'^(input|output|inout)\s*(\[[^\]]*\])?\s*(\S+)\s*$', line)
        if mt:
            d, rng, nm = mt.group(1), mt.group(2), mt.group(3)
            dirs[nm] = d
            if rng:
                hi, lo = [int(x) for x in re.findall(r'\d+', rng)[:2]]
                widths[nm] = abs(hi - lo) + 1
            else:
                widths[nm] = 1
            continue
        if line.startswith("assign") or line.startswith("endmodule"):
            break

    # 分位端口先归组，得到 base 的总位宽
    bits = {}
    for n in names:
        mt = re.match(r'^(.*)\[(\d+)\]$', n) or re.match(r'^(.*)_(\d+)_$', n)
        if mt:
            bits.setdefault(mt.group(1), set()).add(int(mt.group(2)))

    out = []
    for n in names:
        mt = re.match(r'^(.*)\[(\d+)\]$', n) or re.match(r'^(.*)_(\d+)_$', n)
        if mt:
            base, i = mt.group(1), int(mt.group(2))
            out.append((n, dirs.get(n, "input"), base, i, max(bits[base]) + 1))
        else:
            out.append((n, dirs.get(n, "input"), n, None, max(1, widths.get(n, 1))))
    return out


def sig_name(base):
    vn = "m_" + base.replace("io_master_", "").replace("io_slave_", "s_")
    return vn


def main():
    net, out = sys.argv[1], sys.argv[2]
    ports = parse_ports(net)
    text = open(net).read()

    # 保留层次的网表可以直接探内部 PC，结束判据更可靠；扁平网表只能看 AXI。
    hier = "_IFU_u_out_bits_pc_0_" in text

    # 1) 信号声明 + 连接表达式
    decl = []
    sig = {}
    seen = set()
    for (p, d, base, bit, w) in ports:
        if p in ("clock", "reset"):
            continue
        vn = sig_name(base)
        if vn not in seen:
            seen.add(vn)
            decl.append("  wire [%d:0] %s;" % (w - 1, vn) if w > 1 else "  wire %s;" % vn)
        if bit is None:
            sig[p] = vn
        else:
            sig[p] = "%s[%d]" % (vn, bit) if w > 1 else vn

    # 2) 例化：slave 侧输入接 0，输出不接
    conn = ["    .clock(clock)", "    .reset(reset)"]
    for (p, d, base, bit, w) in ports:
        if p in ("clock", "reset"):
            continue
        if p == "io_interrupt":
            conn.append("    .%s(%d'b0)" % (p, w))
            continue
        if p.startswith("io_slave_"):
            if d == "input":
                conn.append("    .%s(%d'b0)" % (p, w))
            continue
        conn.append("    .%s(%s)" % (p, sig[p]))

    # 3) 结束判据：ebreak 之后 PC 跳到 mtvec（复位值 0），IFU 会去取 0x0 的指令
    stop = """  wire fetch_zero = m_arvalid & m_arready & (m_araddr == 32'd0);"""
    if hier:
        stop += """
  wire pc_x = (^dut._IFU_u_out_bits_pc_0_ === 1'bx);"""
    else:
        stop += """
  wire pc_x = 1'b0;"""
    stop_cond = """    if ((cycles > 200) && (fetch_zero || pc_x)) begin
      $display("[netlist] EBREAK: 程序结束, cycles=%0d", cycles);
      $finish;
    end"""

    txt = """// 自动生成：综合网表专用 testbench（不改网表、不加 wrap）
// 端口连接由 gen_netlist_tb.py 生成（hier=@@HIER@@）
`timescale 1ns/1ps
module tb_netlist;
  reg clock = 1'b0;
  reg reset = 1'b1;
  always #0.625 clock = ~clock;

@@DECL@@

  @@SRC@@ dut(
@@CONN@@
  );

  axi_mem mem(
    .clock(clock), .reset(reset),
    .awready(m_awready), .awvalid(m_awvalid), .awaddr(m_awaddr), .awid(m_awid),
    .awlen(m_awlen), .awsize(m_awsize), .awburst(m_awburst),
    .wready(m_wready), .wvalid(m_wvalid), .wdata(m_wdata), .wstrb(m_wstrb), .wlast(m_wlast),
    .bready(m_bready), .bvalid(m_bvalid), .bresp(m_bresp), .bid(m_bid),
    .arready(m_arready), .arvalid(m_arvalid), .araddr(m_araddr), .arid(m_arid),
    .arlen(m_arlen), .arsize(m_arsize), .arburst(m_arburst),
    .rready(m_rready), .rvalid(m_rvalid), .rresp(m_rresp), .rdata(m_rdata),
    .rid(m_rid), .rlast(m_rlast)
  );

  integer cycles = 0;
  integer idle = 0;
  integer max_cycles = 2000000;

  reg [1023:0] hexfile;
  initial begin
    if ($value$plusargs("HEX=%s", hexfile)) $readmemh(hexfile, mem.mem);
`ifdef SIM_HEX
    else $readmemh(`SIM_HEX, mem.mem);
`endif
    void'($value$plusargs("CYCLES=%d", max_cycles));
    $display("[netlist] 已装载镜像，开始仿真");
    #20 reset = 1'b0;
  end

@@STOP@@

  wire axi_active = (m_arvalid & m_arready) | (m_awvalid & m_awready) |
                    (m_wvalid & m_wready) | (m_rvalid & m_rready) | (m_bvalid & m_bready);
  always @(posedge clock) begin
    cycles <= cycles + 1;
    idle   <= axi_active ? 0 : idle + 1;
@@STOPCOND@@
    if ((idle > 20000) && (cycles > 2000)) begin
      $display("[netlist] AXI 静止 20000 拍（程序已停），总 %0d 拍", cycles);
      $finish;
    end
    if (cycles > max_cycles) begin
      $display("[netlist] TIMEOUT: 达到周期上限 %0d", cycles);
      $finish;
    end
  end
endmodule
"""
    txt = (txt.replace("@@DECL@@", "\n".join(decl))
              .replace("@@SRC@@", SRC)
              .replace("@@CONN@@", ",\n".join(conn))
              .replace("@@HIER@@", "1" if hier else "0")
              .replace("@@STOP@@", stop)
              .replace("@@STOPCOND@@", stop_cond))
    open(out, "w").write(txt)
    print("gen_netlist_tb: %d 端口 -> %s (hier=%d, 向量端口=%d)"
          % (len(ports), out, hier, sum(1 for p in ports if p[3] is None and p[4] > 1)))


main()
