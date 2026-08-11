module ysyx_26010028_lsu #(
    parameter [15:0] TIMER_BASE_HI = 16'h0200,
    parameter [15:0] TIMER_LOW_OFF = 16'hbff8,
    parameter [15:0] TIMER_HIGH_OFF = 16'hbffc
) (
    input             clock,
    input             reset,
    // EXU input signals
    input             pipe_valid,
    output            pipe_ready,
    input             pipe_load,
    input             pipe_store,
    input      [ 2:0] pipe_funct3,
    input      [31:0] exu_data,
    input      [31:0] exu_addr,
    // CLINT timer register
    input      [63:0] mtime_value,
    // EXU输出信号
    output            retire_valid,
    output     [31:0] load_data,
    // AXI read address channel
    output     [31:0] lsu_araddr,
    output     [ 2:0] lsu_arsize,
    output            lsu_arvalid,
    input             lsu_arready,
    // AXI read data channel
    input      [31:0] lsu_rdata,
    input      [ 1:0] lsu_rresp,
    input             lsu_rvalid,
    output            lsu_rready,
    // AXI write address channel
    output     [31:0] lsu_awaddr,
    output     [ 2:0] lsu_awsize,
    output            lsu_awvalid,
    input             lsu_awready,
    // AXI write data channel
    output     [31:0] lsu_wdata,
    output     [ 3:0] lsu_wstrb,
    output            lsu_wvalid,
    input             lsu_wready,
    // AXI write response channel
    input      [ 1:0] lsu_bresp,
    input             lsu_bvalid,
    output            lsu_bready
);
    localparam [2:0] LD_SIGN8  = 3'b000;
    localparam [2:0] LD_SIGN16 = 3'b001;
    localparam [2:0] LD_WORD32 = 3'b010;
    localparam [2:0] LD_ZERO8  = 3'b100;
    localparam [2:0] LD_ZERO16 = 3'b101;

    localparam [2:0] ST_BYTE = 3'b000;
    localparam [2:0] ST_HALF = 3'b001;
    localparam [2:0] ST_WORD = 3'b010;

    localparam LOAD_IDLE = 1'b0;
    localparam LOAD_WAIT = 1'b1;

    localparam [1:0] STORE_IDLE = 2'd0;
    localparam [1:0] STORE_ADDR = 2'd1;
    localparam [1:0] STORE_DATA = 2'd2;
    localparam [1:0] STORE_RESP = 2'd3;

    reg       load_phase;
    reg [1:0] store_phase;
    reg       load_phase_n;
    reg [1:0] store_phase_n;

    wire timer_access;

    assign timer_access = exu_addr[31:16] == TIMER_BASE_HI;

    wire [31:0] clint_data;

    assign clint_data = (exu_addr[15:2] == TIMER_LOW_OFF[15:2]) ? mtime_value[31:0] : (exu_addr[15:2] == TIMER_HIGH_OFF[15:2]) ? mtime_value[63:32] : 32'b0;

    wire mem_rd_req;
    wire mem_wr_req;

    assign mem_rd_req = pipe_valid && pipe_load && !timer_access;
    assign mem_wr_req = pipe_valid && pipe_store && !timer_access;

    wire load_ar_hs;
    wire load_r_hs;
    wire store_aw_hs;
    wire store_w_hs;
    wire store_b_hs;

    assign load_ar_hs = lsu_arvalid && lsu_arready;
    assign load_r_hs = lsu_rvalid && lsu_rready;
    assign store_aw_hs = lsu_awvalid && lsu_awready;
    assign store_w_hs = lsu_wvalid && lsu_wready;
    assign store_b_hs = lsu_bvalid && lsu_bready;


    wire ready_now;

    assign ready_now = ~(mem_rd_req || mem_wr_req) || load_r_hs || store_b_hs;
    assign pipe_ready = ready_now;
    assign retire_valid = pipe_valid && ready_now;
    assign lsu_araddr = exu_addr;
    assign lsu_arsize = {1'b0, pipe_funct3[1:0]};
    assign lsu_arvalid = (load_phase == LOAD_IDLE) && mem_rd_req;
    assign lsu_rready = load_phase == LOAD_WAIT;

    assign lsu_awaddr = exu_addr;
    assign lsu_awsize = {1'b0, pipe_funct3[1:0]};
    assign lsu_awvalid = ((store_phase == STORE_IDLE) && mem_wr_req) || (store_phase == STORE_ADDR);
    assign lsu_wvalid = ((store_phase == STORE_IDLE) && mem_wr_req) || (store_phase == STORE_DATA);
    assign lsu_bready = (store_phase == STORE_RESP);
    wire [35:0] store_payload = pack_store(exu_data, exu_addr, pipe_funct3);
    assign lsu_wstrb = store_payload[35:32];
    assign lsu_wdata = store_payload[31:0];

    always @(*) begin
        load_phase_n = load_phase;
        case (load_phase)
            LOAD_IDLE: if (load_ar_hs) load_phase_n = LOAD_WAIT;
            LOAD_WAIT: if (load_r_hs) load_phase_n = LOAD_IDLE;
            default: load_phase_n = LOAD_IDLE;
        endcase
    end

    always @(*) begin
        store_phase_n = store_phase;
        case (store_phase)
            STORE_IDLE: begin
                case ({store_aw_hs, store_w_hs})
                    2'b01: store_phase_n = STORE_ADDR;
                    2'b10: store_phase_n = STORE_DATA;
                    2'b11: store_phase_n = STORE_RESP;
                    default: store_phase_n = STORE_IDLE;
                endcase
            end
            STORE_ADDR: if (store_aw_hs) store_phase_n = STORE_RESP;
            STORE_DATA: if (store_w_hs) store_phase_n = STORE_RESP;
            STORE_RESP: if (store_b_hs) store_phase_n = STORE_IDLE;
            default: store_phase_n = STORE_IDLE;
        endcase
    end

    always @(posedge clock) begin
        if (reset) begin
            load_phase <= LOAD_IDLE;
            store_phase <= STORE_IDLE;
        end else begin
            load_phase <= load_phase_n;
            store_phase <= store_phase_n;
        end
    end

    wire [31:0] load_raw_data;

    assign load_raw_data = timer_access ? clint_data : lsu_rdata;
    assign load_data = unpack_load(load_raw_data, pipe_funct3, exu_addr[1:0]);

    wire _unused_ok;
    assign _unused_ok = &{1'b0, lsu_rresp, lsu_bresp};
    function [35:0] pack_store;
        input [31:0] rs2_val;
        input [31:0] addr;
        input [ 2:0] funct3;
        begin
            case (funct3)
                ST_BYTE: begin
                    case (addr[1:0])
                        2'b00: pack_store = {4'b0001, 24'b0, rs2_val[7:0]};
                        2'b01: pack_store = {4'b0010, 16'b0, rs2_val[7:0], 8'b0};
                        2'b10: pack_store = {4'b0100, 8'b0, rs2_val[7:0], 16'b0};
                        default: pack_store = {4'b1000, rs2_val[7:0], 24'b0};
                    endcase
                end
                ST_HALF: pack_store = addr[1] ? {4'b1100, rs2_val[15:0], 16'b0} : {4'b0011, 16'b0, rs2_val[15:0]};
                ST_WORD: pack_store = {4'b1111, rs2_val};
                default: pack_store = 36'b0;
            endcase
        end
    endfunction

    function [31:0] unpack_load;
        input [31:0] raw_data;
        input [ 2:0] funct3;
        input [ 1:0] addr_offset;
        begin
            case (funct3)
                LD_SIGN8: begin
                    case (addr_offset)
                        2'b00: unpack_load = {{24{raw_data[7]}}, raw_data[7:0]};
                        2'b01: unpack_load = {{24{raw_data[15]}}, raw_data[15:8]};
                        2'b10: unpack_load = {{24{raw_data[23]}}, raw_data[23:16]};
                        default: unpack_load = {{24{raw_data[31]}}, raw_data[31:24]};
                    endcase
                end
                LD_SIGN16: unpack_load = addr_offset[1] ? {{16{raw_data[31]}}, raw_data[31:16]} : {{16{raw_data[15]}}, raw_data[15:0]};
                LD_WORD32: unpack_load = raw_data;
                LD_ZERO8: begin
                    case (addr_offset)
                        2'b00: unpack_load = {24'b0, raw_data[7:0]};
                        2'b01: unpack_load = {24'b0, raw_data[15:8]};
                        2'b10: unpack_load = {24'b0, raw_data[23:16]};
                        default: unpack_load = {24'b0, raw_data[31:24]};
                    endcase
                end
                LD_ZERO16: unpack_load = addr_offset[1] ? {16'b0, raw_data[31:16]} : {16'b0, raw_data[15:0]};
                default: unpack_load = 32'b0;
            endcase
        end
    endfunction
endmodule
