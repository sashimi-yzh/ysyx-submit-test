package npc.core.icache

import chisel3._
import chisel3.util._
import scala.math._
import npc.common.Config._
import npc.common.Instructions._
import npc.bus.axi._
import npc.core.exu._

class FENCEI_FLUSH_IO_ICACHE extends Bundle{
    val fencing = Output(Bool())
}
/*
             ___ ____    _    ____ _   _ _____
            |_ _/ ___|  / \  / ___| | | | ____|
             | | |     / _ \| |   | |_| |  _|
             | | |___ / ___ \ |___|  _  | |___
            |___\____/_/   \_\____|_| |_|_____|
*/
class iCacheIO extends Bundle {
    val in = new AXI4WithoutClk//ifu
    val out = Flipped(new AXI4WithoutClk)//imem
}

class iCacheBlock(val m: Int, val n: Int) extends Bundle{
    val valid = Bool()
    val tag = UInt((WORD_LEN - m - n).W)
    val data = Vec((2 << (m - 1)) / (WORD_LEN / BYTE_LEN), UInt(WORD_LEN.W))
}

class iCacheSet(val m: Int, val n: Int, val ways: Int) extends Bundle{
    val set = Vec(ways, new iCacheBlock(m, n))
}

class iCache(val block_size: Int, val sets: Int, val ways: Int) extends Module{
    val io = IO(new iCacheIO)
    val io_fencei = IO(Flipped(new FENCEI_IO))
    val io_fencei_flush_icache = IO(new FENCEI_FLUSH_IO_ICACHE)

    // 寄存读出的数据以及要读的地址
    val send_rdata = Reg(UInt(WORD_LEN.W))
    val send_araddr = RegInit(0.U(WORD_LEN.W))

    val m = log2(block_size).toInt
    val n = log2(sets).toInt
    val w = math.ceil(log2(ways)).toInt
    val c = block_size / (WORD_LEN / BYTE_LEN)
    val index_width = n
    val offset_width = m
    val tag_width = WORD_LEN - m - n
    val ways_width = w

    val req_index = send_araddr(m + n - 1, m)
    val req_offset = send_araddr(m - 1, 0)
    val req_tag = send_araddr(WORD_LEN - 1, m + n)
    val addr_align = Cat(send_araddr(WORD_LEN - 1, m), 0.U(m.W))
    dontTouch(req_index)
    dontTouch(req_offset)
    dontTouch(req_tag)
    dontTouch(addr_align)

    val icache = RegInit(VecInit(Seq.fill(sets)(0.U.asTypeOf(new iCacheSet(m, n, ways)))))
    dontTouch(icache)

    /*-----------------------FSM-----------------------*/
    val s_IDLE :: s_icache_lookup :: s_fetch :: s_outdone :: s_fencei :: Nil = Enum(5)
    val c_state = RegInit(s_IDLE)
    val n_state = WireDefault(c_state)
    dontTouch(n_state)

    val hit = WireDefault(false.B)
    val hit_num = WireDefault(0.U(ways_width.W))
    for (i <- 0 until ways) {
        when(icache(req_index).set(i).tag === req_tag && icache(req_index).set(i).valid === true.B) {
            hit := true.B
            hit_num := i.U
        }
    }

    //state conditions
    val is_sdram_raddr = (send_araddr >= "ha000_0000".U(WORD_LEN.W) && send_araddr <= "hbfff_ffff".U(WORD_LEN.W))
    val is_ifu_ar_fire = io.in.arvalid && io.in.arready
    val is_hit_handshake = hit && io.in.rready
    val is_imem_ar_fire = io.out.arvalid && io.out.arready
    val is_imem_r_fire = io.out.rvalid && io.out.rready
    val is_ifu_r_fire = io.in.rvalid && io.in.rready

    val burst_done = io.out.rlast

    val hit_rdata = Mux(hit, icache(req_index).set(hit_num).data(req_offset >> 2), 0.U)
    when(is_hit_handshake){
        send_rdata := hit_rdata
    }.elsewhen(is_ifu_r_fire){
        send_rdata := io.out.rdata
    }.otherwise{
        send_rdata := send_rdata
    }
    io.in.rdata := send_rdata
    when(is_ifu_ar_fire){
        send_araddr := io.in.araddr
    }
    io.out.araddr := Mux(io.out.arlen === 0.U, send_araddr, addr_align)//不用突发的时候用原地址, 用突发的时候用对齐地址
    dontTouch(send_rdata)
    dontTouch(send_araddr)

    DefaultIFU()
    DefaultIMEM()
    io.in.arready := true.B
    io.in.rvalid := false.B

    /*-----------------------Burst---------------------*/
    val count = RegInit(0.U(log2Ceil(c).W))
    when(is_imem_ar_fire){
        count := 0.U
    }.elsewhen(is_imem_r_fire){
        count := count + 1.U
    }
    dontTouch(count)
    val is_ifu_require = count === req_offset >> 2
    dontTouch(is_ifu_require)

    /*-----------------------FENCEI---------------------*/
    val is_fencei_r = RegInit(false.B)
    val fencei_counter = RegInit(0.U(n.W))
    val fencei_fsh = fencei_counter === sets.U - 1.U

    val is_fencei = io_fencei.is_fencei
    io_fencei.fencei_done := fencei_fsh

    val fencing = is_fencei | is_fencei_r
    io_fencei_flush_icache.fencing := fencing

    when(is_fencei){
        is_fencei_r := true.B
    }.elsewhen(fencei_fsh){
        is_fencei_r := false.B
    }
    when(fencing && ~fencei_fsh){
        fencei_counter := fencei_counter + 1.U
    }.otherwise{
        fencei_counter := 0.U
    }
    when(fencing){
        for(i <- 0 until ways){
            icache(fencei_counter).set(i).valid := false.B
        }
    }

    /*fencei while fetch do not fill*/
    val while_fence = RegInit(false.B)
    when(is_fencei){
        while_fence := true.B
    }.elsewhen(n_state === s_IDLE){
        while_fence := false.B
    }

    c_state := n_state//first phase

    n_state := MuxLookup(c_state, s_IDLE)(Seq(//second phase
        s_IDLE           ->  Mux(is_ifu_ar_fire, Mux(is_sdram_raddr, s_icache_lookup, s_fetch), Mux(is_fencei, s_fencei, s_IDLE)),
        s_icache_lookup  ->  Mux(is_hit_handshake, s_IDLE, s_fetch),
        s_fetch          ->  Mux(is_imem_ar_fire, s_outdone, s_fetch),
        s_outdone        ->  Mux(is_imem_r_fire, Mux(burst_done || ~is_sdram_raddr, s_IDLE, s_outdone), s_outdone),
        s_fencei         ->  Mux(fencei_fsh, s_IDLE, s_fencei)
    ))

    switch(c_state){//third phase
        is(s_IDLE){
            DefaultIFU()
            DefaultIMEM()
            io.in.rvalid := false.B
            io.in.arready := true.B
        }
        is(s_icache_lookup){
            DefaultIFU()
            DefaultIMEM()
            io.in.rvalid := hit
            io.in.arready := false.B
        }
        is(s_fetch){
            connectAll_my()
            io.in.rvalid := false.B
            io.out.rready := false.B
            io.in.arready := false.B
            io.out.arvalid := true.B
        }
        is(s_outdone){
            connectAll_my()
            io.in.rvalid := Mux(is_ifu_require || ~is_sdram_raddr, io.out.rvalid, false.B)
            io.out.rready := Mux(is_ifu_require || ~is_sdram_raddr, io.in.rready, true.B)
            io.in.arready := false.B
            io.out.arvalid := false.B
        }
    }

    //检查空闲的cache块
    val hasEmpty = WireDefault(false.B)
    val emptyIndex = RegInit(0.U(ways_width.W))
    for (i <- (ways - 1) to 0 by -1) {
        when(icache(req_index).set(i).valid === false.B) {
            hasEmpty := true.B
            emptyIndex := i.U
        }
    }


    when(is_imem_r_fire && ~hit && is_sdram_raddr && ~while_fence){//替换或填充逻辑, 这里需要补充根据配置选择LRU或者FIFO或者RANDOM, 这里注意hit了就不需要替换或填充
        val set = icache(req_index).set
        when(hasEmpty === true.B) {
            // 如果有空闲块，填充
            set(emptyIndex).valid := io.out.rlast//突发传输, 分阶段写data块, valid只在最后一次拉高, 否则最后一次的data块因为没有hasEmpty而写入失败
            set(emptyIndex).tag := req_tag
            set(emptyIndex).data(count) := io.out.rdata
        }.otherwise{
            // 如果没有空闲块，替换逻辑
            val randomIndex = scala.util.Random.nextInt(ways)
            set(randomIndex).valid := io.out.rlast
            set(randomIndex).tag := req_tag
            set(randomIndex).data(count) := io.out.rdata
        }
    }

/*-----------------------function-----------------------*/
    def log2(x: Int): Double = {
        math.log(x) / math.log(2)
    }

    def DefaultIFU(): Unit = {
        // io.in.arready := true.B
        // io.in.rdata := 0.U
        io.in.rresp := 0.U
        // io.in.rvalid := false.B
        io.in.rlast := false.B
        io.in.rid := 0.U
        io.in.awready := false.B
        io.in.wready := false.B
        io.in.bresp := 0.U
        io.in.bvalid := false.B
        io.in.bid := 0.U
    }

    def DefaultIMEM(): Unit = {
        // io.out.araddr := 0.U
        io.out.arvalid := false.B
        io.out.arid := 0.U
        io.out.arlen := 0.U
        io.out.arsize := 0.U
        io.out.arburst := 0.U
        io.out.rready := false.B
        io.out.awaddr := 0.U
        io.out.awvalid := false.B
        io.out.awid := 0.U
        io.out.awlen := 0.U
        io.out.awsize := 0.U
        io.out.awburst := 0.U
        io.out.wdata := 0.U
        io.out.wstrb := 0.U
        io.out.wvalid := false.B
        io.out.wlast := false.B
        io.out.bready := false.B
    }

    def connectAll_my(): Unit = {
        // io.out.araddr   := io.in.araddr
        // io.out.arvalid  := io.in.arvalid
        io.out.arid     := io.in.arid
        io.out.arlen    := Mux(is_sdram_raddr, c.U - 1.U, 0.U)//transfer n + 1 data block during one transfer
        io.out.arsize   := "b10".U//one data block has 4B
        io.out.arburst  := "b01".U//incr burst mode
        // io.in.arready   := io.out.arready
    // Connect Read Data Channel (R)
        // io.in.rdata    := io.out.rdata
        io.in.rresp    := io.out.rresp
        // io.in.rvalid   := io.out.rvalid
        io.in.rlast    := io.out.rlast
        io.in.rid      := io.out.rid
        // io.out.rready  := io.in.rready
    // Connect Write Address Channel (AW)
        io.out.awaddr   := io.in.awaddr
        io.out.awvalid  := io.in.awvalid
        io.out.awid     := io.in.awid
        io.out.awlen    := io.in.awlen
        io.out.awsize   := io.in.awsize
        io.out.awburst  := io.in.awburst
        io.in.awready   := io.out.awready
    // Connect Write Data Channel (W)
        io.out.wdata    := io.in.wdata
        io.out.wstrb    := io.in.wstrb
        io.out.wvalid   := io.in.wvalid
        io.out.wlast    := io.in.wlast
        io.in.wready    := io.out.wready
    // Connect Write Response Channel (B)
        io.in.bresp    := io.out.bresp
        io.in.bvalid   := io.out.bvalid
        io.in.bid      := io.out.bid
        io.out.bready  := io.in.bready
    }
}