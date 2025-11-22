`include "/home/furina/ysyx-workbench/npc/single-vsrc/defines.v"
module CSR(
    input             clk,
    input             reset,
    input             csrWrite,
    input      [11:0] addr,
    input      [31:0] wdata,
    input      [1:0]  op,
    output reg [31:0] rdata,
    input             ecall,
    input             mret,
    input      [31:0] pc,
    output     [31:0] mret_pc,
    output reg [31:0] ecall_pc
);
    reg [31:0] mstatus;  //机器状态寄存器
    reg [31:0] mtvec;    //机器陷阱向量基址寄存器
    reg [31:0] mepc;     //机器异常程序计数器
    reg [31:0] mcause;   //机器异常原因寄存器

    localparam MSTATUS = 12'h300;
    localparam MTVEC   = 12'h305;
    localparam MEPC    = 12'h341;
    localparam MCAUSE  = 12'h342;

    //读操作
    always @(*) begin
        case(addr)
            MSTATUS: rdata = mstatus;
            MTVEC:   rdata = mtvec;
            MEPC:    rdata = mepc;
            MCAUSE:  rdata = mcause;
            default: rdata = 32'h0;
        endcase
        // $display("[CSR] read 0x%h from 0x%h", rdata, addr);
    end

    always @(posedge clk or posedge reset) begin
        if(reset) begin
            mstatus = 32'h1800;
            mtvec   = 32'h0;
            mepc    = 32'h0;
            mcause  = 32'h0;

            ecall_pc = 32'h0;
            mret_pc = 32'h0;
        end
        else if(ecall) begin
            //ecall指令处理
            mepc = pc;
            mcause = 32'h0b;//来自M-mode调用
            ecall_pc = mtvec;
            // $display("ecall_pc=0x%h, mtevc=0x%h", ecall_pc, mtvec);
        end
        else if(mret) begin
            mret_pc = mepc;
        end
        else begin
            //写操作
            if(csrWrite) begin
                case(addr)
                    MSTATUS: if(op != `CSR_NONE) mstatus = (op == `CSR_CSRRW) ? wdata :
                                                (op == `CSR_CSRRS) ? (mstatus | wdata) :
                                                (mstatus & ~wdata);
                    MTVEC:  if(op != `CSR_NONE) mtvec = (op == `CSR_CSRRW) ? wdata :
                                                (op == `CSR_CSRRS) ? (mtvec | wdata) :
                                                (mtvec & ~wdata);
                    MEPC:   if(op != `CSR_NONE) mepc = (op == `CSR_CSRRW) ? wdata :
                                                (op == `CSR_CSRRS) ? (mepc | wdata) :
                                                (mepc & ~wdata);
                    MCAUSE: if(op != `CSR_NONE) mcause = (op == `CSR_CSRRW) ? wdata :
                                                (op == `CSR_CSRRS) ? (mcause | wdata) :
                                                (mcause & ~wdata);
                    default: begin end
                endcase
                // $display("Wirte at 0x%h with op=%b wdata=0x%h", addr, op, wdata);
            end
        end
    end
endmodule