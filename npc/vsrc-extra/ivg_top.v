module ivg_top;

reg reset;
reg clock;

npc core(clock, reset);

always #1 clock = ~clock;
    
initial begin
    clock = 1;
    reset = 1;

    #60;
    @(negedge clock);
    reset = 0;
    #60 $display("start to sim the design\n");
end

// initial begin
//     $dumpfile("wave.vcd");    //生成的vcd文件名称
//     $dumpvars(0, ivg_top);    //tb模块名称
// end

endmodule
