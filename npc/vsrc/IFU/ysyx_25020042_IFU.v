
module ysyx_25020042_IFU(
    input                  clock,
    input                  reset,
    input                  idu_ready,
    output reg             ifu_valid,

    input                  i_jump_valid,
    input      [31:0]      i_jump_pc,
    input                  i_fast_jump_valid,
    input      [31:0]      i_fast_jump_pc,

    input                  fencei_signal,
    input                  fault,
    output reg [31:0]      o_instruction,
    output wire [31:0]     o_pc_data    ,
    output [2:0]           o_IFU_Exception_Handling,

    `ifdef VERILATOR
    output     [63:0]      o_performance_counter,
    output reg [63:0]      o_cycles_counter,
    output reg [63:0]      o_single_cycles_counter,
    `ifdef ICACHE_ON
    output     [63:0]      o_icache_hit_count,
    `endif
    `endif

    output wire [31:0]     ifu_araddr,
    output wire            ifu_arvalid,
    input                  ifu_arready,
    output wire [7:0]      ifu_arlen,
    output wire [3:0]      ifu_arid,
    output wire [1:0]      ifu_arburst,
    output wire [2:0]      ifu_arsize,
    input      [31:0]      ifu_rdata,
    input                  ifu_rvalid,
    output wire            ifu_rready,
    input      [1:0]       ifu_rresp,
    input                  ifu_rlast,
    input      [3:0]       ifu_rid
);
`ifdef VERILATOR

    reg [63:0] performance_counter;
    reg        ifu_busy_signal;
    assign o_performance_counter = performance_counter;
    always @(posedge clock) begin
        if(reset) 
            performance_counter <= 0;
        else if (pc_valid & ifu_ready)
            performance_counter <= performance_counter + 1;
    end

    always @(posedge clock) begin
        if(reset) 
            ifu_busy_signal <= 0;
        else if(i_jump_valid) begin
            if (state == IDLE && !(pc_valid && ifu_ready)) begin
                ifu_busy_signal <= 1'b0;
            end
            else if (state == READY && instruction_ready) begin
                ifu_busy_signal <= 1'b0;
            end
            else begin
                ifu_busy_signal <= 1'b1;
            end
        end
        else if(state == READY && instruction_ready && Control_Hazard) begin
                ifu_busy_signal <= 1'b0;
        end
        else if (pc_valid & ifu_ready)
            ifu_busy_signal <= 1;
        else if (idu_ready & ifu_valid)
            ifu_busy_signal <= 0;
    end

    always @(posedge clock) begin
        if(reset) begin
            o_cycles_counter <= 0;
        end
        else if (ifu_busy_signal) begin
            o_cycles_counter <= o_cycles_counter + 1;
        end
    end

    always @(posedge clock) begin
        if(reset) begin
            o_single_cycles_counter <= 0;
        end
        else if (pc_valid && ifu_ready) begin
            o_single_cycles_counter <= 0;
        end
        else 
            o_single_cycles_counter <= o_single_cycles_counter + 1;
    end

`endif

wire Instruction_address_misaligned;
wire Instruction_access_fault;
wire Instruction_page_fault;
wire instruction_ready;
wire [31:0] instruction;
reg ifu_ready;
reg state ;
reg Control_Hazard;
localparam IDLE  = 1'b0;
localparam READY = 1'b1;

//-----------------pc------------------
reg [31:0] pc;
// reg [31:0] next_pc;
reg pc_valid;
always @(posedge clock) begin
        if (reset)begin
            `ifdef PLATFORM_NPC
            pc <= 32'h8000_0000;
            `else
            pc <= 32'h3000_0000;
            `endif
        end 
        else if (fault)begin
            pc <= 0;
        end
        else if (i_jump_valid) begin
            pc <= i_jump_pc;
        end
        else if (i_fast_jump_valid) begin
            pc <= i_fast_jump_pc;
        end
        else if (ifu_valid & idu_ready)begin
            pc <= pc + 4;
        end
    end

always @(posedge clock) begin
        if (reset)begin
            pc_valid <= 1'b1;
        end 
        else if (ifu_valid & idu_ready) 
            pc_valid <= 1'b1;
        else if (i_jump_valid)
            pc_valid <= 1'b1;
        else 
            pc_valid <= ifu_ready ? 1'b0 :pc_valid;
            
    end

//-----------------ifu-------------------
assign o_pc_data = pc;
assign o_IFU_Exception_Handling = {Instruction_page_fault, Instruction_access_fault, Instruction_address_misaligned};
assign Instruction_page_fault = 1'b0;
assign Instruction_address_misaligned = |pc[1:0];

always @(posedge clock) begin
    if(reset) begin
        state <= IDLE;
    end
    else begin
        case(state)
            IDLE: begin
                if(pc_valid & ifu_ready) begin
                    state <= READY;
                end
                else begin
                    state <= IDLE;
                end
            end
            READY: begin
                if(instruction_ready) begin
                    state <= IDLE;
                end
                else begin
                    state <= READY;
                end
            end
            default: begin
                state <= state;
                end
        endcase
    end
end

always @(posedge clock) begin
    if(reset) begin
        Control_Hazard <= 1'b0;
    end
    else begin
        if (Control_Hazard & instruction_ready) begin
            Control_Hazard <= 1'b0;
        end
        else if(i_jump_valid && ((state == READY) || (pc_valid & ifu_ready))) begin
            Control_Hazard <= 1'b1;
            if (instruction_ready) begin
                Control_Hazard <= 1'b0;
            end
        end
        else begin
            Control_Hazard <= Control_Hazard;
        end
    end
end

always @(posedge clock) begin
    if(reset) begin
        ifu_ready <= 1'b1;
        ifu_valid <= 1'b0;
    end
    else begin
        if(i_jump_valid) begin
            if (state == IDLE && !(pc_valid && ifu_ready)) begin
                ifu_ready <= 1'b1;
            end
            else if (state == READY && instruction_ready) begin
                ifu_ready <= 1'b1;
            end
            else begin
                ifu_ready <= 1'b0;
            end
            ifu_valid <= 1'b0;
        end
        else if(ifu_ready & pc_valid) begin
            ifu_ready <= 1'b0;
            ifu_valid <= 1'b0;
        end
        else if(state == READY && instruction_ready) begin
            if(Control_Hazard) begin
                ifu_valid <= 1'b0;
                ifu_ready <= 1'b1;
            end
            else begin
                ifu_valid <= 1'b1;
                ifu_ready <= 1'b0;
            end
        end
        else if (idu_ready & ifu_valid) begin
            ifu_valid <= 1'b0;
            ifu_ready <= 1'b1;
        end
    end
end

always @(posedge clock) begin
    if(reset) begin
        o_instruction <= 32'h0;
    end
    else if (i_jump_valid)
        o_instruction <= 32'h0;
    else begin
        if(state == READY && instruction_ready) begin
            o_instruction <= instruction;
        end
    end
end

ysyx_25020042_icache #(
    .CACHE_BLOCK_SIZE(16), //4 * 8
    .CACHE_BLOCK_BANK(2) //2 ^ n
) u_icache(
    .clock            (clock),
    .reset            (reset),
    .pc_valid         (pc_valid & ifu_ready),
    .pc_addr          (pc),
    .fencei_signal    (fencei_signal),
    `ifdef VERILATOR
    .icache_hit_count (o_icache_hit_count),
    `endif
    .instruction_ready(instruction_ready),
    .instruction      (instruction),
    .Instruction_access_fault(Instruction_access_fault),
    .io_icache_arready(ifu_arready),
    .io_icache_arvalid(ifu_arvalid),
    .io_icache_araddr (ifu_araddr),
    .io_icache_arid   (ifu_arid),
    .io_icache_arlen  (ifu_arlen),
    .io_icache_arsize (ifu_arsize),
    .io_icache_arburst(ifu_arburst),
    .io_icache_rready (ifu_rready),
    .io_icache_rvalid (ifu_rvalid),
    .io_icache_rresp  (ifu_rresp),
    .io_icache_rdata  (ifu_rdata),
    .io_icache_rlast  (ifu_rlast),
    .io_icache_rid    (ifu_rid)
);

endmodule
