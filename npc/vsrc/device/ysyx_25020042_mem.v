`timescale 1ns/1ns 
module ysyx_25020042_mem(
    input clock,
    input reset,
    // axi 握手信号
    input [31:0]      slave_araddr    ,
    input             slave_arvalid   ,
    output reg        slave_arready   ,
    input [3:0]       slave_arid      ,
    input [7:0]       slave_arlen     ,
    input [2:0]       slave_arsize    ,
    input [1:0]       slave_arburst   ,

    output reg [31:0] slave_rdata     ,
    output reg        slave_rvalid    ,
    output reg [1:0]  slave_rresp     ,
    input             slave_rready    ,
    output reg        slave_rlast     ,
    output reg  [3:0] slave_rid       ,

    input [31:0]      slave_awaddr    ,
    input             slave_awvalid   ,
    output reg        slave_awready   ,
    input  [3:0]      slave_awid      ,
    input [7:0]       slave_awlen     ,
    input  [2:0]       slave_awsize    ,
    input [1:0]       slave_awburst   ,

    input [31:0]      slave_wdata     ,
    input [3:0]       slave_wstrb     ,
    input             slave_wvalid    ,
    output reg        slave_wready    ,
    input             slave_wlast     ,

    output reg        slave_bvalid    ,
    input             slave_bready    ,
    output reg [1:0]  slave_bresp     ,
    output reg [3:0]  slave_bid    
);



reg [2:0] state;
reg [7:0] burst_count;
wire [31:0] read_addr = slave_araddr + 4 * burst_count;

// ============================================================
// 引导程序（Boot）：0x30000000 -> 0x80000000
//   0x30000000: lui  t0, 0x80000   => 32'h800002B7
//   0x30000004: jalr x0, 0(t0)     => 32'h00028067
// ============================================================
wire        is_boot_vec = (read_addr == 32'h30000000) ||
                          (read_addr == 32'h30000004);

wire [31:0] boot_instr  = (read_addr == 32'h30000000)
                          ? 32'h800002B7   // lui  t0, 0x80000
                          : 32'h00028067;  // jalr x0, 0(t0)

`ifdef VERILATOR
import "DPI-C" function int pmem_read(input int addr, input int len);
import "DPI-C" function void pmem_write(
    input int addr, int len, input int data);
`endif

`ifdef __ICARUS__
    reg [7:0] mem[0:4*1024*1024-1];

    wire [31:0] waddr = slave_awaddr >= 32'h80000000 && slave_awaddr < 32'h90000000 ?(slave_awaddr - 32'h80000000): 0;
    wire [31:0] waddr_fix = {waddr[31:2], 2'b0};
    wire [31:0] raddr = read_addr >= 32'h80000000 && read_addr <= 32'h90000000 ? (read_addr - 32'h80000000): 0;
    wire [31:0] raddr_fix = {raddr[31:2], 2'b0};
    wire [31:0] rdata_test = {mem[raddr+3], mem[raddr+2], mem[raddr+1], mem[raddr]};
`endif 

localparam IDLE = 3'd0;
localparam READ = 3'd1;
localparam READ_WAIT = 3'd2;
localparam WRITE = 3'd3;
localparam WRITE_WAIT = 3'd4;

always @(posedge clock) begin
    if (reset) 
        burst_count <= 0;
    else if (slave_rlast)
        burst_count <= 0;
    else if (slave_rvalid && state == READ)
        burst_count <= burst_count + 1;
end

always @(posedge clock) begin
    if (reset) begin
        state <= IDLE;
        slave_arready <= 1'b0;
        slave_awready <= 1'b0;
        slave_wready <= 1'b0;
        slave_bvalid <= 1'b0;
        slave_rdata <= 32'b0;
        slave_rvalid <= 1'b0;
        slave_rresp <= 2'b00;
        slave_rlast <= 1'b0;
        slave_rid <= 4'b0;
        slave_bid <= 0;
        slave_bresp <= 2'b00;
    end
    else begin
        case (state)
        IDLE: begin
                slave_arready <= 1'b1;
                slave_awready <= 1'b1;
                slave_wready <= 1'b1;
                slave_rlast <= 1'b0;

            if (slave_arvalid) begin
                // $display("[MEM_REQ] READ  araddr=%08x arlen=%d arsize=%d",
                //     slave_araddr, slave_arlen, slave_arsize);
                state <= READ;
                slave_arready <= 1'b0;
                slave_awready <= 1'b0;
                slave_wready <= 1'b0;
                slave_rid <= slave_arid;
            end
            else if (slave_awvalid && slave_wvalid) begin
                // $display("[MEM_REQ] WRITE awaddr=%08x wdata=%08x wstrb=%04b",
                //     slave_awaddr, slave_wdata, slave_wstrb);
                state <= WRITE;
                slave_arready <= 1'b0;
                slave_awready <= 1'b0;
                slave_wready <= 1'b0;
                slave_bid <= slave_awid;
            end
        end
        READ: begin
            if (slave_rready) begin
                if (burst_count == slave_arlen) begin
                    slave_rlast <= 1'b1;
                    slave_rresp <= 2'b00;
                    state <= READ_WAIT;
                    slave_rvalid <= 1'b1;
                    `ifdef VERILATOR
                    slave_rdata <= is_boot_vec ? boot_instr
                                               : (slave_rvalid == 0 ? pmem_read(read_addr, 4) : 32'b0);
                    `endif
                    `ifdef __ICARUS__
                    slave_rdata <= is_boot_vec ? boot_instr
                                               : {mem[raddr_fix+3], mem[raddr_fix+2], mem[raddr_fix+1], mem[raddr_fix]};
                    // $display("[MEM_RD] araddr=%08x raddr=%08x data=%08x",
                    //     slave_araddr, raddr, {mem[raddr+3], mem[raddr+2], mem[raddr+1], mem[raddr]});
                    `endif
                end
                else begin
                     if (slave_rvalid == 1'b0) begin
                        slave_rvalid <= 1'b1;
                        `ifdef VERILATOR
                        slave_rdata <= is_boot_vec ? boot_instr : pmem_read(read_addr, 4);
                        `endif
                        `ifdef __ICARUS__
                        slave_rdata <= is_boot_vec ? boot_instr
                                                   : {mem[raddr_fix+3], mem[raddr_fix+2], mem[raddr_fix+1], mem[raddr_fix]};
                        // $display("read_addr = %08x  raddr = %08x: %08x", slave_araddr, raddr, mem[raddr]);
                        `endif
                     end
                    else begin
                        slave_rvalid <= 1'b0;
                    end
                end
            end
        end
        READ_WAIT: begin
            if (slave_rready) begin
                slave_rvalid <= 1'b0;
                slave_rresp <= 2'b00;
                slave_rdata <= 32'b0;
                slave_rlast <= 1'b0;
                state <= IDLE;
            end
        end
        WRITE: begin
            `ifdef VERILATOR
            /* verilator lint_off WIDTHEXPAND */
            // $display("mem write addr = %08x, data = %08x", slave_awaddr, slave_wdata);
            pmem_write(slave_awaddr, slave_wstrb, slave_wdata);
            /* verilator lint_on WIDTHEXPAND */
            `endif
            `ifdef __ICARUS__
            if (slave_awaddr == 32'ha00003f8 || slave_awaddr == 32'ha00003fc) begin
                $write("%c", slave_wdata[7:0]);
            end
            else begin
            if(slave_wstrb[0]) mem[waddr_fix]   <= slave_wdata[7:0];
            if(slave_wstrb[1]) mem[waddr_fix+1]  <= slave_wdata[15:8];
            if(slave_wstrb[2]) mem[waddr_fix+2] <= slave_wdata[23:16];
            if(slave_wstrb[3]) mem[waddr_fix+3] <= slave_wdata[31:24];
            end
            `endif
            state <= WRITE_WAIT;
            slave_bresp <= 2'b00;
            slave_bvalid <= 1'b1;
        end
        WRITE_WAIT: begin
            if (slave_bready) begin
                slave_bvalid <= 1'b0;
                slave_bresp <= 2'b00;
                state <= IDLE;
            end
        end
        default: begin
            state <= IDLE;
        end
    endcase 
    end
end

endmodule