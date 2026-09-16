
// `define LSU_MTRACE
module ysyx_25020042_LSU(
    input                           clock,
    input                           reset,
    input                           exu_valid,
    input                           wbu_ready,
    output reg                      lsu_valid,
    output reg                      lsu_ready,

    input [7:0]                     i_inst,
    input [31:0]                    i_src2,
    input [31:0]                    i_data, // exu data
    input [31:0]                    i_pc_data,
    input [31:0]                    i_csr_data,
    input [11:0]                    i_csr_addr,
    `ifdef VERILATOR
    input  [31:0]                   i_instruction_data,
    `endif

    output wire [7:5]                o_inst,
    output reg [31:0]               o_data,
    output reg [31:0]               o_pc_data,
    `ifdef VERILATOR
    output reg [31:0]               o_instruction_data,
    `endif
    output reg [31:0]               o_csr_data,
    output reg [11:0]               o_csr_addr,
    output                          load_valid,
    input  wire [2:0]    i_IFU_Exception_Handling,
    output reg [2:0]     o_IFU_Exception_Handling,
    input  wire [2:0]    i_IDU_Exception_Handling,
    output reg [2:0]     o_IDU_Exception_Handling,
    output wire [5:0]    o_LSU_Exception_Handling,

    `ifdef VERILATOR
    /* verilator lint_off UNUSEDSIGNAL */
    output reg [63:0]               performance_counter,
    output reg [63:0]               cycles_counter,
    input  wire [63:0]              i_single_cycles_counter,
    output reg [63:0]               o_single_cycles_counter,
    /* verilator lint_on UNUSEDSIGNAL */
    `endif

    // axi 握手信号
    output reg [31:0]               lsu_araddr,
    output reg                      lsu_arvalid,
    output reg [3:0]               lsu_arid,
    output reg [7:0]                lsu_arlen,
    output reg [2:0]                lsu_arsize,
    output reg [1:0]                lsu_arburst,
    input                           lsu_arready,

    input [31:0]                    lsu_rdata,
    input                           lsu_rvalid,
    input [1:0]                     lsu_rresp,
    input [3:0]                     lsu_rid,
    input                           lsu_rlast,
    output reg                      lsu_rready,

    output reg [31:0]               lsu_awaddr,
    output reg                      lsu_awvalid,
    output reg [3:0]               lsu_awid,
    output reg [7:0]               lsu_awlen,
    output reg [2:0]                lsu_awsize,
    output reg [1:0]               lsu_awburst,
    input                           lsu_awready,

    output reg [31:0]               lsu_wdata,
    output reg [3:0]                lsu_wstrb,
    output reg                      lsu_wvalid,
    output reg                      lsu_wlast,
    input                           lsu_wready,

    input                           lsu_bvalid,
    output reg                      lsu_bready,
    input [1:0]                     lsu_bresp,
    /* verilator lint_off UNUSEDSIGNAL */
    input [3:0]                     lsu_bid
    /* verilator lint_on UNUSEDSIGNAL */
);

`ifdef PLATFORM_NPC
`else
`ifdef VERILATOR
import "DPI-C" function void difftest_device_skip();
`endif
`endif

`ifdef VERILATOR

    // reg [63:0] performance_counter;
    reg lsu_mem_hit_signal;
    reg lsu_busy_signal;
    always @(posedge clock) begin
        if(reset) begin
            lsu_busy_signal <= 1'b0;
        end
        else if (exu_valid & lsu_ready) begin
            lsu_busy_signal <= 1;
        end
        else if (lsu_valid & wbu_ready) begin
            lsu_busy_signal <= 0;
        end
    end

    always @(posedge clock) begin
        if(reset) begin
            lsu_mem_hit_signal <= 1'b0;
        end
        else if (lsu_arvalid | lsu_awvalid) begin
            lsu_mem_hit_signal <= 1;
        end
        else if (lsu_rvalid | lsu_bvalid) begin
            lsu_mem_hit_signal <= 0;
        end
    end

    always @(posedge clock) begin
        if(reset) 
            performance_counter <= 0;
        else if ((lsu_bvalid | lsu_rvalid) & lsu_mem_hit_signal)
            performance_counter <= performance_counter + 1;
    end

    always @(posedge clock) begin
        if(reset) 
            cycles_counter <= 0;
        else if (lsu_busy_signal)
            cycles_counter <= cycles_counter + 1;
    end

        always @(posedge clock) begin
        if (reset) begin
            o_single_cycles_counter <= 0;
        end
        else if (exu_valid & lsu_ready) begin
            o_single_cycles_counter <= i_single_cycles_counter;
        end
        else begin
            o_single_cycles_counter <= o_single_cycles_counter + 1;
        end
    end
`endif

localparam  MEM_INST     = 3'b011;
// 状态定义
localparam IDLE = 1'b0;
localparam WAIT = 1'b1;

reg [7:0]                inst_reg;
reg       state;
reg [1:0] rresp;
reg [1:0] bresp;
wire [3:0] wstrb;
wire [31:0] wdata;
reg Load_address_misaligned;
reg Store_address_misaligned;
wire Load_access_fault;
wire Store_access_fault;
wire Load_page_fault;
wire Store_page_fault;

// 记得修改回来

wire [31:0] shifted_rdata = lsu_rdata >> (lsu_araddr[1:0] * 8);
reg wen;
reg ren;
reg is_write;   // 当前事务方向，发起时锁存，避免读/写响应分支互相干扰
reg [3:0] wmask;

assign o_LSU_Exception_Handling = {Store_page_fault, Load_page_fault, Store_access_fault, Store_address_misaligned, Load_access_fault, Load_address_misaligned};
assign Store_page_fault = 1'b0;
assign Load_page_fault = 1'b0;
assign Store_access_fault = bresp == 2'b10 | bresp == 2'b11;
assign Load_access_fault = |rresp;
assign o_inst = inst_reg[7:5];

always @(*) begin
    case (lsu_arsize)
        3'b010: Load_address_misaligned = |lsu_araddr[1:0];
        3'b001: Load_address_misaligned = lsu_araddr[0];
        3'b000: Load_address_misaligned = 1'b0;
        default: Load_address_misaligned = 1'b0;
    endcase

    case (lsu_awsize)
        3'b010: Store_address_misaligned = |lsu_awaddr[1:0];
        3'b001: Store_address_misaligned = lsu_awaddr[0];
        3'b000: Store_address_misaligned = 1'b0;
        default: Store_address_misaligned = 1'b0;
    endcase
end

always @(posedge clock) begin
    if(reset) begin
        inst_reg <= 8'b0;
        // o_pc_data <= 32'b0;
        // o_csr_data <= 32'b0;
        // o_csr_addr <= 12'b0;
        // o_IFU_Exception_Handling <= 3'b0;
        // o_IDU_Exception_Handling <= 3'b0;
        `ifdef VERILATOR
            o_instruction_data <= 32'b0;
        `endif
    end
    else if(exu_valid & lsu_ready) begin
        inst_reg <= i_inst;
        o_pc_data <= i_pc_data;
        o_csr_data <= i_csr_data;
        o_csr_addr <= i_csr_addr;
        o_IFU_Exception_Handling <= i_IFU_Exception_Handling;
        o_IDU_Exception_Handling <= i_IDU_Exception_Handling;
        `ifdef VERILATOR
            o_instruction_data <= i_instruction_data;
        `endif
    end
end

assign wdata = i_src2 << (i_data[1:0] * 8);
assign wstrb = wmask << i_data[1:0];

always @(*) begin
    wen = 1'b0;
    ren = 1'b0;
    wmask = 4'b0000;
    if(i_inst[7:5] == MEM_INST) begin
        case (i_inst[4:0])
            5'b00110: begin // sw
                wen = 1'b1;
                wmask = 4'b1111;
            end
            5'b00111: begin // sh
                wen = 1'b1;
                wmask = 4'b0011;
            end
            5'b01000: begin // sb
                wen = 1'b1;
                wmask = 4'b0001;
            end
            default: begin
                ren = 1'b1;
            end
    endcase
    end
end

assign load_valid = lsu_rvalid & lsu_rlast & lsu_rid == lsu_arid & state == WAIT;

always @(*) begin
    case (inst_reg[4:0])
        5'b00001: o_data = shifted_rdata[31:0];
        5'b00011: o_data = {16'b0, shifted_rdata[15:0]};
        5'b00010: o_data = {{16{shifted_rdata[15]}}, shifted_rdata[15:0]};
        5'b00101: o_data = {24'b0, shifted_rdata[7:0]};
        5'b00100: o_data = {{24{shifted_rdata[7]}}, shifted_rdata[7:0]};
        default:  o_data = 0;
    endcase
end

// assign lsu_arlen = 8'b0;
// assign lsu_awlen = 8'b0;

always @(posedge clock) begin
    if(reset) begin
        state <= IDLE;
        lsu_ready <= 1'b1;
        lsu_valid <= 1'b0;
        lsu_arvalid <= 1'b0;
        lsu_awvalid <= 1'b0;
        // lsu_araddr <= 32'b0;
        // lsu_awaddr <= 32'b0;
        lsu_rready <= 1'b0;
        // lsu_wdata <= 32'b0;
        // lsu_wstrb <= 4'b0;
        lsu_wvalid <= 1'b0;
        lsu_bready <= 1'b0;
        lsu_arid <= 4'b0;
        lsu_awid <= 4'b0;
        lsu_arlen <= 8'b0;
        lsu_awlen <= 8'b0;
        lsu_arsize <= 3'b0;
        lsu_awsize <= 3'b0;
        lsu_arburst <= 2'b00;
        lsu_awburst <= 2'b00;
        lsu_wlast <= 1'b0;
        is_write <= 1'b0;
        rresp <= 2'b0;
        bresp <= 2'b0;
    end
    else begin
        case (state)
            IDLE: begin
                if(exu_valid & lsu_ready) begin
                    if (wen || ren) begin
                        state <= WAIT;
                        lsu_ready <= 1'b0;
                        is_write <= wen;
                        lsu_wdata <= wdata;
                        lsu_wstrb <= wstrb;
                        lsu_araddr <= i_data;
                        lsu_awaddr <= i_data;

                        case (i_inst[4:0])
                            5'b00110: begin // sw
                                lsu_arsize <= 3'b000;
                                lsu_awsize <= 3'b010;
                            end
                            5'b00111: begin // sh
                                lsu_arsize <= 3'b000;
                                lsu_awsize <= 3'b001;
                            end
                            5'b00001: begin // lw
                                lsu_arsize <= 3'b010;
                                lsu_awsize <= 3'b000;
                            end
                            5'b00010: begin // lh
                                lsu_arsize <= 3'b001;
                                lsu_awsize <= 3'b000;
                            end
                            5'b00011: begin // lhu
                                lsu_arsize <= 3'b001;
                                lsu_awsize <= 3'b000;
                            end
                            default: begin
                                lsu_arsize <= 3'b000;
                                lsu_awsize <= 3'b000;
                            end
                        endcase
                        if (wen) begin
                            lsu_awvalid <= 1'b1;
                            lsu_wvalid <= 1'b1;
                            lsu_wlast <= 1'b1;
                            lsu_bready <= 1'b1;
                            `ifdef LSU_MTRACE
                                $display("LSU: write addr: %x data: %x", i_data, wdata);
                            `endif
                        end
                        else begin
                            lsu_rready <= 1'b1;
                            lsu_arvalid <= 1'b1;
                        end
                    end
                    else begin
                        // o_data <= i_data;
                        lsu_ready <= 1'b0;
                        lsu_valid <= 1'b1;
                    end
                end
                else begin
                    state <= IDLE;

                    // if (lsu_rready) begin
                        lsu_rready <= 1'b0;
                    // end

                    // if (lsu_bready) begin
                        lsu_bready <= 1'b0;
                    // end

                    if(lsu_valid & wbu_ready ) begin
                        lsu_ready <= 1'b1;
                        lsu_valid <= 1'b0;
                        rresp <= 2'b00;
                        bresp <= 2'b00;
                        lsu_araddr <= 32'b0;
                        lsu_awaddr <= 32'b0;
                    end
                end
            end
            WAIT: begin
                `ifdef VERILATOR 
                `ifdef PLATFORM_NPC
                `else
                    if (lsu_araddr >= 32'h1000_0000 && lsu_araddr < 32'h1000_1000 && lsu_arvalid && lsu_arready || 
                        lsu_araddr >= 32'h1000_1000 && lsu_araddr < 32'h1000_2000 && lsu_arvalid && lsu_arready) begin
                        difftest_device_skip();
                    end
                    if (lsu_araddr >= 32'h0200_0000 && lsu_araddr < 32'h0201_0000 && lsu_arvalid && lsu_arready) begin
                        difftest_device_skip();
                    end
                `endif
                `endif
                // AR / AW / W 是三条独立通道，VALID 各自在本通道 READY 拉高后撤销。
                // 原来要求 awready & wready 同拍才撤，awready/wready 不同拍时会重复握手或死锁。
                if (lsu_arvalid & lsu_arready)
                    lsu_arvalid <= 1'b0;

                if (lsu_awvalid & lsu_awready)
                    lsu_awvalid <= 1'b0;

                if (lsu_wvalid & lsu_wready) begin
                    lsu_wvalid <= 1'b0;
                    lsu_wlast <= 1'b0;
                end

                // 按事务方向分流，读响应不会被写通道的握手条件吞掉
                if (is_write) begin
                    if (lsu_bvalid) begin
                        lsu_bready <= 1'b0;
                        lsu_valid <= 1'b1;
                        bresp <= lsu_bresp;
                        state <= IDLE;
                    end
                    else begin
                        state <= WAIT;
                    end
                end
                else begin
                    if (lsu_rvalid & lsu_rlast & (lsu_rid == lsu_arid)) begin
                        lsu_rready <= 1'b0;
                        lsu_valid <= 1'b1;
                        rresp <= lsu_rresp;
                        state <= IDLE;
                        `ifdef LSU_MTRACE
                            $display("LSU: read addr: %x data: %x", lsu_araddr, shifted_rdata);
                        `endif
                    end
                    else begin
                        state <= WAIT;
                    end
                end
            end
            default: begin
                state <= IDLE;
            end
        endcase

    end
    
end

endmodule
