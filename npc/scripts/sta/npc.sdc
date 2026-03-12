set CLK_PORT_NANE clock
set CLK_FREQ_MHZ 1200
set clk_io_pct 0.2

set clk_port [get_ports $CLK_PORT_NANE]
create_clock -name clock -period [expr 1000.0 / $CLK_FREQ_MHZ] $clk_port