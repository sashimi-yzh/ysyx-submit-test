`include "/home/furina/ysyx-workbench/npc/soc-vsrc/defines.v"
// 寄存器文件
module RegFile (
    input         clk,
    input         reset,
    input  [4:0]  rs1,
    input  [4:0]  rs2,
    input  [4:0]  rd,
    input         we,
    input  [31:0] wd,

    // output wire [31:0] rs1_val,
    // output wire [31:0] rs2_val
    output reg [31:0] rs1_val,
    output reg [31:0] rs2_val
);
    typedef enum { IDLE, BUSY, STALL} state_t;
    state_t state,next_state;
    reg [1:0] delay;
    parameter DELAY_CYCLES = 1;//处理周期
    //状态机定义(IDLE等待上游valid信号, BUSY处理, STALL等待下游ready信号)
    
    reg [31:0] regs [0:31]; // 32个寄存器

    // assign rs1_val = (rs1 != 0) ? regs[rs1] : 0;
    // assign rs2_val = (rs2 != 0) ? regs[rs2] : 0;

    always @(posedge clk or posedge reset) begin
        // if (we && rd != 0) regs[rd] <= wd;
        if(reset) begin
            state <= IDLE;
            delay <= DELAY_CYCLES;
            // reg_ready = 1'b1;
            // reg_valid = 1'b0;
            // rs1_val = 32'h0;
            // rs2_val = 32'h0;
            for(integer i = 0; i < 32; i = i + 1) begin
                regs[i] <= 32'h0;//初始化寄存器
            end
        end
        else begin
            state <= next_state;
            case(state)
                IDLE: begin
                    // reg_ready = 1'b1;
                    // reg_valid = 1'b0;
                    delay <= DELAY_CYCLES;
                    next_state <= BUSY; 
                end
                BUSY: begin
                    // reg_ready = 1'b0;
                    // reg_valid = 1'b0;
                    if(delay > 0) begin//牵手成功
                        if(we && rd != 0) begin
                            regs[rd] <= wd;
                            $display("\033[35m[REG]: regs[%d] = %h\033[0m", rd, wd);
                        end
                        // rs1_val = (rs1 != 0) ? regs[rs1] : 32'h0;
                        // rs2_val = (rs2 != 0) ? regs[rs2] : 32'h0;
                        delay <= delay - 1;
                        // $display("\033[35m[REG]: rs1_val=%h | rs2_val=%h\033[0m",rs1_val, rs2_val);
                    end
                    next_state <= (delay == 0) ? STALL : BUSY;
                end
                STALL: begin
                    // reg_ready = 1'b0;
                    // reg_valid = 1'b1;
                    next_state <= IDLE;
                end
            endcase
        end
    end
    always @(*) begin
        rs1_val = (rs1 != 0) ? regs[rs1] : 32'h0;
        rs2_val = (rs2 != 0) ? regs[rs2] : 32'h0;
        $display("\033[35m[REG]: rd=%h | rs1_val=%h | rs2_val=%h\033[0m",rd, rs1_val, rs2_val);
    end
endmodule