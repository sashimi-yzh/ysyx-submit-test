module ysyx_26010028_csr_file (
    input             clock,
    input             reset,
    input      [11:0] address,
    output reg [31:0] read_data,

    input             retire_valid,
    input             system_inst,
    input      [ 2:0] funct3,
    input      [31:0] operand,
    input      [31:0] retire_pc,
    input             take_ecall,
    input             take_mret,

    output     [31:0] mstatus,
    output     [31:0] mtvec,
    output     [31:0] mepc,
    output     [31:0] mcause
);

    localparam [11:0] MSTATUS   = 12'h300;
    localparam [11:0] MTVEC     = 12'h305;
    localparam [11:0] MEPC      = 12'h341;
    localparam [11:0] MCAUSE    = 12'h342;
    localparam [11:0] MVENDORID = 12'hF11;
    localparam [11:0] MARCHID   = 12'hF12;

    reg [31:0] mstatus_q;
    reg [31:0] mtvec_q;
    reg [31:0] mepc_q;
    reg [31:0] mcause_q;

    reg        csr_write_enable;
    reg [31:0] csr_write_data;

    assign mstatus = mstatus_q;
    assign mtvec   = mtvec_q;
    assign mepc    = mepc_q;
    assign mcause  = mcause_q;
    // CSR read port
    always @(*) begin
        case (address)
            MSTATUS:   read_data = mstatus_q;
            MTVEC:     read_data = mtvec_q;
            MEPC:      read_data = mepc_q;
            MCAUSE:    read_data = mcause_q;
            MVENDORID: read_data = 32'h0104_0104;
            MARCHID:   read_data = 32'h26010028;
            default:   read_data = 32'b0;
        endcase
    end
    // 
    always @(*) begin
        csr_write_enable = 1'b0;
        csr_write_data   = read_data;
        case (funct3[1:0])
            2'b01: begin
                csr_write_enable = 1'b1;
                csr_write_data   = operand;
            end
            2'b10: begin
                csr_write_enable = (operand != 32'b0);
                csr_write_data   = read_data | operand;
            end
            2'b11: begin
                csr_write_enable = (operand != 32'b0);
                csr_write_data   = read_data & ~operand;
            end
            default: begin end
        endcase
    end

    always @(posedge clock) begin
        if (reset) begin
            mstatus_q <= 32'h0000_1800;
            mtvec_q   <= 32'h0000_0001;
            mepc_q    <= 32'b0;
            mcause_q  <= 32'b0;
        end else if (retire_valid && system_inst) begin
            if (funct3 == 3'b000) begin
                if (take_ecall) begin
                    mstatus_q[3]     <= 1'b0;
                    mstatus_q[7]     <= mstatus_q[3];
                    mstatus_q[12:11] <= 2'b11;
                    mepc_q           <= retire_pc;
                    mcause_q         <= 32'd11;
                end else if (take_mret) begin
                    mstatus_q[3]     <= mstatus_q[7];
                    mstatus_q[7]     <= 1'b1;
                    mstatus_q[12:11] <= 2'b00;
                end
            end else if (csr_write_enable) begin
                case (address)
                    MSTATUS: mstatus_q <= csr_write_data;
                    MTVEC:   mtvec_q   <= csr_write_data;
                    MEPC:    mepc_q    <= csr_write_data;
                    MCAUSE:  mcause_q  <= csr_write_data;
                    default: begin end
                endcase
            end
        end
    end

endmodule
