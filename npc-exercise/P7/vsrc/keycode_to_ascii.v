module keycode_to_ascii (
    input [7:0] scancode,      // 第二套扫描码输入
    output reg [7:0] ascii,    // ASCII码输出
    output reg valid           // 是否为有效可显示字符
);

always @(*) begin
    valid = 1'b1;  // 默认有效
    case (scancode)
        // 数字键 (带Shift和不带Shift)
        8'h45: ascii = 8'h30; // 0
        8'h16: ascii = 8'h31; // 1
        8'h1E: ascii = 8'h32; // 2
        8'h26: ascii = 8'h33; // 3
        8'h25: ascii = 8'h34; // 4
        8'h2E: ascii = 8'h35; // 5
        8'h36: ascii = 8'h36; // 6
        8'h3D: ascii = 8'h37; // 7
        8'h3E: ascii = 8'h38; // 8
        8'h46: ascii = 8'h39; // 9
        
        // 字母键 (小写，假设CapsLock关闭且无Shift)
        8'h1C: ascii = 8'h61; // a
        8'h32: ascii = 8'h62; // b
        8'h21: ascii = 8'h63; // c
        8'h23: ascii = 8'h64; // d
        8'h24: ascii = 8'h65; // e
        8'h2B: ascii = 8'h66; // f
        8'h34: ascii = 8'h67; // g
        8'h33: ascii = 8'h68; // h
        8'h43: ascii = 8'h69; // i
        8'h3B: ascii = 8'h6A; // j
        8'h42: ascii = 8'h6B; // k
        8'h4B: ascii = 8'h6C; // l
        8'h3A: ascii = 8'h6D; // m
        8'h31: ascii = 8'h6E; // n
        8'h44: ascii = 8'h6F; // o
        8'h4D: ascii = 8'h70; // p
        8'h15: ascii = 8'h71; // q
        8'h2D: ascii = 8'h72; // r
        8'h1B: ascii = 8'h73; // s
        8'h2C: ascii = 8'h74; // t
        8'h3C: ascii = 8'h75; // u
        8'h2A: ascii = 8'h76; // v
        8'h1D: ascii = 8'h77; // w
        8'h22: ascii = 8'h78; // x
        8'h35: ascii = 8'h79; // y
        8'h1A: ascii = 8'h7A; // z
        
        // 空格键
        8'h29: ascii = 8'h20; // 空格
        
        // 常用符号键
        8'h0E: ascii = 8'h60; // ` (反引号)
        8'h4E: ascii = 8'h2D; // - (减号/连字符)
        8'h55: ascii = 8'h3D; // = (等号)
        8'h5D: ascii = 8'h5C; // \ (反斜杠)
        8'h54: ascii = 8'h5B; // [ (左方括号)
        8'h5B: ascii = 8'h5D; // ] (右方括号)
        8'h4C: ascii = 8'h3B; // ; (分号)
        8'h52: ascii = 8'h27; // ' (单引号)
        8'h41: ascii = 8'h2C; // , (逗号)
        8'h49: ascii = 8'h2E; // . (句点)
        8'h4A: ascii = 8'h2F; // / (斜杠)
        
        // 其他功能键或无效键
        8'h66: begin // Backspace (显示为退格符号)
            ascii = 8'h08;
            valid = 1'b1;
        end
        8'h0D: begin // Tab
            ascii = 8'h09;
            valid = 1'b1;
        end
        8'h5A: begin // Enter
            ascii = 8'h0D;
            valid = 1'b1;
        end
        8'h76: begin // Escape
            ascii = 8'h1B;
            valid = 1'b1;
        end
        
        // 默认情况：无效字符（可显示为空或特定符号）
        default: begin
            ascii = 8'h00;  // 空字符
            valid = 1'b0;   // 无效
        end
    endcase
end

endmodule
