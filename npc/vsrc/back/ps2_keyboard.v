module ps2_keyboard(
    input clk,
    input resetn,
    input ps2_clk,
    input ps2_data,
    output reg key_valid,
    output reg key_pressed,
    output reg[6:0] seg0,
    output reg[6:0] seg1,
    output reg[6:0] seg6,
    output reg[6:0] seg7
);

    reg [9:0] buffer;        // 10bit(除停止位)
    reg [3:0] count;         // 计数tag
    reg [7:0] last_keycode;        // 上一次的键码
    reg releasing;           // 释放状态标志
    reg [7:0] keycode;
    reg [7:0] press_counter; // 按键计数器
    
    // 延迟稳态处理
    reg [2:0] ps2_clk_sync;
    always @(posedge clk) begin
        ps2_clk_sync <= {ps2_clk_sync[1:0], ps2_clk};
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (resetn) begin // 复位
            count <= 0;
            key_valid <= 0;
            key_pressed <= 0;
            releasing <= 0;
            last_keycode <= 0;
            press_counter <= 0;
            $display("Reset");
        end
        else begin
            key_valid <= 0; // 默认无效
            
            if (sampling) begin
                if (count == 4'd10) begin
                    if ((buffer[0] == 0) &&  // 开始位
                        (ps2_data)       &&  // 停止位
                        (^buffer[9:1])) begin      // 奇偶校验位
                        
                        // 检查是否是释放码(0xF0)
                        if (buffer[8:1] == 8'hF0) begin
                            releasing <= 1;  // 进入释放状态
                        end
                        else if (!releasing) begin
                            // 避免重复按键
                            if (last_keycode != buffer[8:1]) begin
                                keycode <= buffer[8:1];
                                key_valid <= 1;
                                key_pressed <= 1;
                                last_keycode <= buffer[8:1];
                                press_counter <= press_counter + 1; 
                                $display("Key Pressed: %x", buffer[8:1]);
                            end
                        end
                        // 释放完成
                        else begin
                            $display("Key Released: %x", buffer[8:1]);
                            releasing <= 0;
                            key_pressed <= 0;
                            last_keycode <= 0;
                        end
                    end
                    count <= 0;     // 清零
                end else begin
                    buffer[count] <= ps2_data;  // 写入缓冲
                    count <= count + 3'b1;
                end
            end
        end
    end

    reg [6:0] seg0_code;
    reg [6:0] seg1_code;

    hex u_hex0 (
        .hex(keycode[3:0]),
        .seg(seg0_code)
    );
    hex u_hex1 (
        .hex(keycode[7:4]),
        .seg(seg1_code)
    );
    hex u_hex6 (
        .hex(press_counter[3:0]),
        .seg(seg6)
    );
    hex u_hex7 (
        .hex(press_counter[7:4]),
        .seg(seg7)
    );

    always @(posedge clk) begin
        if (key_valid) begin
            // 显示键码
            seg0 <= seg0_code;
            seg1 <= seg1_code;
        end else if (!key_pressed) begin
            // 无效或未按下时显示空白
            seg0 <= 7'b1111111;
            seg1 <= 7'b1111111;
        end
    end

endmodule
