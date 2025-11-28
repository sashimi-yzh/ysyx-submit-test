// `timescale 1ns/1ps  // 时间单位/时间精度
module main ();
  localparam CLK_PERIOD = 10000000;
  reg clk, reset;         

  IverilogTop dut (
      .clock(clk),	// home/uenui/code
      .reset(reset)	// home/uenui/code
  );
    reg [31:0] cycle_count = 0; // 周期计数器

    // 3. 时钟生成器 (10ns周期 = 100MHz)
    initial begin
        clk = 1; // 初始时钟为0
        forever #1 clk = ~clk; // 每5ns翻转一次，产生10ns周期
    end
    
    // 4. 复位控制
    initial begin
        reset = 1; // 初始复位有效
        #10;       // 保持20ns（2个时钟周期）
        reset = 0; // 释放复位
    end

    wire a0 = 0;
    reg halt; 
    // 5. 周期计数器
    always @(posedge clk) begin
        if (reset) begin
            cycle_count <= 0; // 复位时清零
        end else begin
            cycle_count <= cycle_count + 1; // 每个时钟上升沿计数
            halt <= dut.core._core_io_ebreak; //转义标识符（escaped identifier）。转义标识符以反斜杠开始，以空格结束 
        end
    end

  initial begin
  // 初始化VCD波形文件
  // $dumpfile("iverilog_wave.vcd");
  // $dumpvars(0, dut); // 记录所有信号
  
  
  // 等待复位释放
  wait(reset == 0);
  $display("Reset released at time %t", $time);
  
  // 主仿真循环
  fork
    // 分支1: 周期计数监控
    begin
      while (cycle_count < CLK_PERIOD) begin
        @(posedge clk);
        cycle_count = cycle_count + 1;
      end
      $display("Completed %d cycles at time %t", cycle_count,$time);
    end
    
    // 分支2: Halt信号监控
    begin
      wait(halt == 1);
      $display("\nHalt signal detected at time %t", $time);
    end
  join_any // 任意一个条件满足即继续
  
  // 结束仿真
  #2; // 额外等待一个周期
  $display("Simulation completed");
  
  // 报告结束原因
  if (halt && !a0) begin
    $display("GOOD! Terminated by HALT signal after %d cycles a0 %x",cycle_count,a0 );
  end else if (halt) begin
    $display("BAD! Terminated by HALT signal after %d cycles a0 %x",cycle_count,a0);
  end else begin
    $display("Terminated after completing %d cycles a0 %x",cycle_count,a0);
  end
  
  $finish;
end

endmodule // main