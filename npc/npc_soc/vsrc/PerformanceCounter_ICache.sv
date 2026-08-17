import "DPI-C" function void notify_icache_hit_event();


module PerformanceCounter_ICache (
    input clock,
    input reset,
    input icache_hit
);


  always @(posedge clock) begin
    if (!reset) begin
      if (icache_hit) notify_icache_hit_event();
    end
  end

endmodule
