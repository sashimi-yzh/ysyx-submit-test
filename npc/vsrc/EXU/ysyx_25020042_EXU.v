
module ysyx_25020042_EXU(
    input wire clock,
    input wire reset,
    input wire idu_valid,
    input wire lsu_ready,
    output wire exu_ready,
    // output reg exu_ready,
    output reg exu_valid,

    `ifdef VERILATOR
    output reg [63:0] performance_counter,
    output reg [63:0] cycles_counter,
    input  wire [63:0]   i_single_cycles_counter,
    output reg  [63:0]   o_single_cycles_counter,
    `endif

    input wire [7:0] i_inst,
    input wire [31:0] i_src1,
    input wire [31:0] i_src2,
    input wire [31:0] i_imm,
    input wire [31:0] i_pc_data,
    input wire [5:0]  i_shamt,
    input wire [31:0] i_csr_data,
    input wire [11:0] i_csr_addr,
    input wire [31:0] i_mepc_rdata,
    input wire [31:0] i_mtvec_rdata,
    input wire        i_src1_valid,
    input wire        i_src2_valid,
    input  wire [2:0]    i_IFU_Exception_Handling,
    output reg [2:0]     o_IFU_Exception_Handling,
    input  wire [2:0]    i_IDU_Exception_Handling,
    output reg [2:0]     o_IDU_Exception_Handling,
    input  wire [5:0]    i_LSU_Exception_Handling,
    `ifdef VERILATOR
    input  [31:0]     i_instruction_data,
    `endif
    // input wire [4:0]  i_rd,
    output reg [31:0]  o_csr_data,
    output reg [11:0]  o_csr_addr,
    output reg  [7:0]  o_idu_inst,
    output reg  [31:0] o_pc_data,
    output wire        o_fence_i_valid,
    `ifdef VERILATOR
    output reg [31:0] o_instruction_data,
    `endif
    output reg  [31:0] o_src2,
    // output reg  [4:0] o_rd,
    output reg [31:0] jump_pc,
    output wire        jump_valid,
    // output reg [31:0] o_data
    output wire  [31:0]  o_data
);

    localparam  EXU_INST     = 3'b001;
    localparam  JUMP_INST    = 3'b010;
    localparam  MEM_INST     = 3'b011;
    localparam  CSR_INST     = 3'b100;
    localparam  SPECIAL_INST = 3'b101;

    reg [31:0] alu_data1;
    reg [31:0] alu_data2;
    reg [3:0]  alu_ctrl;
    reg        B_jump_signal;
    reg        jump_valid_signal;
    reg        Exception_hit_reg;
    wire Exception_valid0 = |{i_IFU_Exception_Handling, i_IDU_Exception_Handling};
    wire Exception_valid1 = |i_LSU_Exception_Handling;
    wire [31:0] alu_out;
    wire equal       = (i_src1 == i_src2);
    // 翻转符号位把有符号比较变成无符号比较，避免 $signed，面积更小
wire sign_less   = ({i_src1[31] ^ 1'b1, i_src1[30:0]}) < ({i_src2[31] ^ 1'b1, i_src2[30:0]});
    wire unsign_less = (i_src1 < i_src2);

    always @(posedge clock) begin
        if (reset)
            Exception_hit_reg <= 1'b0;
        else if (Exception_valid1) 
            Exception_hit_reg <= 1'b1;
        else 
            Exception_hit_reg <= 1'b0;
    end

    assign exu_ready = idu_valid & !exu_valid & i_src1_valid & i_src2_valid;
    always @(posedge clock) begin
        if (reset) begin
            exu_valid <= 0;
        end
        else if (idu_valid & exu_ready) begin
            exu_valid <= 1;
        end
        else if ((lsu_ready | (Exception_valid1 & !Exception_hit_reg)) & exu_valid) begin
            exu_valid <= 0;
        end
    end

    // always @(posedge clock) begin
    //     if (reset) begin
    //         exu_ready <= 0;
    //         exu_valid <= 0;
    //     end
    //     else if (!exu_valid & !exu_ready & idu_valid & i_src1_valid & i_src2_valid) begin
    //         exu_ready <= 1;
    //     end
    //     else if (idu_valid & exu_ready) begin
    //         exu_ready <= 0;
    //         exu_valid <= 1;
    //     end
    //     else if ((lsu_ready | (Exception_valid1 & !Exception_hit_reg)) & exu_valid) begin
    //         exu_valid <= 0;
    //         if (idu_valid & i_src1_valid & i_src2_valid)
    //             exu_ready <= 1;
    //         else 
    //             exu_ready <= 0;
    //     end
    // end

    `ifdef VERILATOR
    // reg [63:0] performance_counter;
    always @(posedge clock) begin
        if (reset) begin
            o_single_cycles_counter <= 0;
        end
        else if (idu_valid & exu_ready) begin
            o_single_cycles_counter <= i_single_cycles_counter;
        end
        else begin
            o_single_cycles_counter <= o_single_cycles_counter + 1;
        end
    end

    reg exu_busy_signal;

    always @(posedge clock) begin
        if(reset) 
            performance_counter <= 0;
        else if (idu_valid & exu_ready)
            performance_counter <= performance_counter + 1;
    end

    always @(posedge clock) begin
        if(reset) 
            exu_busy_signal <= 0;
        else if (idu_valid & exu_ready)
            exu_busy_signal <= 1;
        else if (lsu_ready & exu_valid)
            exu_busy_signal <= 0;
    end

    always @(posedge clock) begin
        if(reset) 
            cycles_counter <= 0;
        else if (exu_busy_signal)
            cycles_counter <= cycles_counter + 1;
    end


    `endif

assign jump_valid = jump_valid_signal & (exu_valid | (Exception_valid1 & !Exception_hit_reg));
assign o_fence_i_valid = i_inst == 8'b10100001;

always @(posedge clock) begin
    if(reset) begin
        jump_pc <= 32'h0;
        jump_valid_signal <= 1'b0;
    end
    if (idu_valid & exu_ready) begin
        case(i_inst[7:5])
            JUMP_INST: begin
                if (B_jump_signal == 1'b1) begin
                    jump_pc <= alu_out;
                    jump_valid_signal <= 1'b1;
                end
                else if (i_inst[4:0] == 5'b00001) begin
                    jump_pc <= alu_out;
                    jump_valid_signal <= 1'b1;
                end
            end
        
            CSR_INST: begin
                case (i_inst[4:0])
                    5'b00100: begin // mret
                        jump_pc <= i_mepc_rdata;
                        jump_valid_signal <= 1'b1;
                    end
                    5'b00011: begin // ecall
                        jump_pc <= i_mtvec_rdata;
                        jump_valid_signal <= 1'b1;
                    end
                    default: begin
                        jump_valid_signal <= 1'b0;
                    end
                endcase
            end
            SPECIAL_INST: begin
                jump_pc <= i_pc_data + 4;
                jump_valid_signal <= 1'b1;
            end 
            default: begin
                if (Exception_valid0 | Exception_valid1) begin
                    jump_valid_signal <= 1'b1;
                    jump_pc <= i_mtvec_rdata;
                end
                else
                jump_valid_signal <= 1'b0;
            end
        endcase
    end
    else if (exu_valid)begin
        jump_valid_signal <= 1'b0;
    end
end

    assign o_data = alu_out;

    always @(posedge clock) begin
        if (reset) begin
            // o_pc_data <= 0;
            o_idu_inst <= 0;
            // o_csr_data <= 0;
            // o_src2     <= 0;
            // o_csr_addr <= 0;
            // o_IFU_Exception_Handling <= 0;
            // o_IDU_Exception_Handling <= 0;
            `ifdef VERILATOR
                o_instruction_data <= 32'b0;
            `endif
        end
        else if (idu_valid & exu_ready) begin
            o_pc_data <= i_pc_data;
            o_idu_inst <= i_inst;
            o_csr_data <= i_csr_data;
            o_src2     <= i_src2;
            o_csr_addr <= i_csr_addr;
            o_IFU_Exception_Handling <= i_IFU_Exception_Handling;
            o_IDU_Exception_Handling <= i_IDU_Exception_Handling;
            `ifdef VERILATOR
                o_instruction_data <= i_instruction_data;
            `endif
        end
    end

    always @(*) begin
        B_jump_signal = 1'b0;
        if(i_inst[7:5] == JUMP_INST) begin
            case(i_inst[4:0])
            5'b00001:  // jalr
                B_jump_signal = 1'b0;
            5'b00010:  // jal
                B_jump_signal = 1'b0;
            5'b00011:  // beq
                B_jump_signal = equal ? 1'b1 : 1'b0;
            5'b00100:  // bne
                B_jump_signal = equal ? 1'b0 : 1'b1;
            5'b00101:  // bge
                B_jump_signal = sign_less ? 1'b0 : 1'b1;
            5'b00110:  // bgeu
                B_jump_signal = unsign_less ? 1'b0 : 1'b1;   
            5'b00111:  // blt
                B_jump_signal = sign_less ? 1'b1 : 1'b0;          
            5'b01000:  // bltu
                B_jump_signal = unsign_less ? 1'b1 : 1'b0;           
            default: 
                B_jump_signal = 1'b0;
            endcase
        end
    end

// ALUctr[3] | ALUctr[2:0] | ALU操作
// ---------|------------|--------------------------------
// 0        | 000        | 选择加法器输出，做加法
// 1        | 000        | 选择加法器输出，做减法
// ×        | 001        | 选择移位器输出，左移
// 0        | 010        | 做减法，选择带符号小于置位结果输出, Less按带符号结果设置
// 1        | 010        | 做减法，选择无符号小于置位结果输出, Less按无符号结果设置
// ×        | 011        | 选择ALU输入B的结果直接输出
// ×        | 100        | 选择异或输出
// 0        | 101        | 选择移位器输出，逻辑右移
// 1        | 101        | 选择移位器输出，算术右移
// ×        | 110        | 选择逻辑或输出
// ×        | 111        | 选择逻辑与输出
    always @(*) begin
        case(i_inst[7:5])
            EXU_INST: begin
                case(i_inst[4:0])
                    5'b00001: begin//addi 
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0000;
                    end
                    5'b00010: begin // andi
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0111;
                    end
                    5'b00011: begin // xori
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0100;
                    end
                    5'b00100: begin // ori
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0110;
                    end
                    5'b00101: begin//auipc
                        alu_data1 = i_pc_data;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0000;
                    end
                    5'b00110: begin // lui
                        alu_data1 = 0;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0011;
                    end
                    5'b00111: begin // srai
                        alu_data1 = i_src1;
                        alu_data2 = {26'b0 ,i_shamt};
                        alu_ctrl = 4'b1101;
                    end
                    5'b01000: begin // slli
                        alu_data1 = i_src1;
                        alu_data2 = {26'b0 ,i_shamt};
                        alu_ctrl = 4'b0001;
                    end
                    5'b01001: begin // slti
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0010;
                    end
                    5'b01010: begin // sltiu
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b1010;
                    end
                    5'b01011: begin // srli
                        alu_data1 = i_src1;
                        alu_data2 = {26'b0 ,i_shamt};
                        alu_ctrl = 4'b0101;
                    end
                    5'b01100: begin // sll
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0001;
                    end
                    5'b01101: begin // add
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0000;
                    end
                    5'b01110: begin //and
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0111;
                    end
                    5'b01111: begin //or
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0110;
                    end
                    5'b10000: begin // xor
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0100;
                    end
                    5'b10001: begin // sub
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b1000;
                    end
                    5'b10010: begin // slt
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0010;
                    end
                    5'b10011: begin // sltu
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b1010;
                    end
                    5'b10100: begin // sra
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b1101;
                    end
                    5'b10101: begin // srl
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0101;
                    end
                    default: begin
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                endcase
            end
            JUMP_INST: begin
                case(i_inst[4:0])
                    5'b00001: begin // jalr
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0000;
                    end
                    default: begin
                        alu_data1 = i_pc_data;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0000;
                    end
                endcase
            end

            MEM_INST: begin
                alu_data1 = i_src1;
                alu_data2 = i_imm;
                alu_ctrl = 4'b0000;
            end

            CSR_INST: begin
                case(i_inst[4:0])
                    5'b00001: begin // csrrs
                        alu_data1 = i_src1;
                        alu_data2 = i_csr_data;
                        alu_ctrl = 4'b0110;
                    end
                    5'b00010: begin // csrrw
                        alu_data1 = 0;
                        alu_data2 = i_src1;
                        alu_ctrl = 4'b0011;
                    end
                    5'b00011: begin // ecall
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                    5'b00100: begin // mret
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                    5'b00101: begin // ebreak
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                    default: begin
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                endcase
            end

            SPECIAL_INST: begin
                case(i_inst[4:0])
                    5'b00001: begin // fencei
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                    default: begin
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                endcase
            end

            default: begin
                alu_data1 = 0;
                alu_data2 = 0;
                alu_ctrl = 4'b0011;
            end

        endcase
    end

ysyx_25020042_alu u_alu(
    .data1(alu_data1),
    .data2(alu_data2),
    .ALUctrl(alu_ctrl),
    .o_data(alu_out)
);

endmodule
