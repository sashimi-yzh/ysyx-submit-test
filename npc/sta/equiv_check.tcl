# equiv_check_io_nopkg.tcl
# IO-level bounded equivalence check for RTL vs gate-level netlist.
# This script intentionally uses no Tcl packages: no json, no cmdline, no msgcat.
# Run:
#   yosys -c equiv_check_io_nopkg.tcl -- \
#     -top TOP -rtl rtl.sv -netlist top.v.sim -stdcell stdcell_func.v \
#     -reset reset -reset-active 1 -reset-cycles 4 -warmup 1 -cycles 10 \
#     -outdir reports/io_equiv -dump

proc usage {} {
    puts "Usage: yosys -c equiv_check_io_nopkg.tcl -- -top TOP -rtl RTL.sv -netlist NETLIST.v.sim -stdcell STDCELL.v \\"
    puts "       ?-reset RESET_NAME? ?-reset-active 0|1? ?-reset-cycles N? ?-warmup N? ?-cycles N? ?-init any|zero|undef|def? ?-outdir DIR? ?-dump?"
    puts ""
    puts "Required:"
    puts "  -top       top module name, before renaming"
    puts "  -rtl       Chisel-generated SystemVerilog file"
    puts "  -netlist   gate-level simulation netlist, usually *.v.sim"
    puts "  -stdcell   behavioral Verilog model for standard cells"
    puts ""
    puts "Notes:"
    puts "  This performs IO-level bounded equivalence by using Yosys miter -equiv."
    puts "  It does not compare internal registers/states, so it is suitable for retimed netlists."
    puts "  Yosys sat -seq time steps are treated as design clock cycles."
    exit 1
}

proc require_value {args idx key} {
    if {$idx >= [llength $args]} {
        puts "ERROR: missing value after $key"
        usage
    }
    return [lindex $args $idx]
}

proc rtlil_id {name} {
    if {$name eq ""} {
        return ""
    }
    if {[string index $name 0] eq "\\"} {
        return $name
    }
    return "\\$name"
}

proc norm_nonneg_int {value key} {
    if {![string is integer -strict $value] || $value < 0} {
        puts "ERROR: $key must be a non-negative integer, got '$value'"
        usage
    }
    return $value
}

# Defaults.
array set opt {
    -top ""
    -rtl ""
    -netlist ""
    -stdcell ""
    -reset ""
    -reset-active 1
    -reset-cycles 4
    -warmup 1
    -cycles 10
    -init any
    -outdir reports/io_equiv
    -dump 0
}

# Yosys usually passes arguments after '--' in argv, but tolerate both forms.
set args $argv
if {[llength $args] > 0 && [lindex $args 0] eq "--"} {
    set args [lrange $args 1 end]
}

for {set i 0} {$i < [llength $args]} {incr i} {
    set key [lindex $args $i]
    switch -- $key {
        -top - -rtl - -netlist - -stdcell - -reset - -reset-active - -reset-cycles - -warmup - -cycles - -init - -outdir {
            incr i
            set opt($key) [require_value $args $i $key]
        }
        -dump {
            set opt(-dump) 1
        }
        -h - --help - help {
            usage
        }
        -ignore-output {
            puts "ERROR: -ignore-output is not supported by this no-package fallback script."
            puts "       Use miter on all matching top-level outputs, or remove/rename ports before running."
            exit 1
        }
        default {
            puts "ERROR: unknown option '$key'"
            usage
        }
    }
}

foreach key {-top -rtl -netlist -stdcell} {
    if {$opt($key) eq ""} {
        puts "ERROR: required option $key is missing"
        usage
    }
}

set reset_active $opt(-reset-active)
if {$reset_active ne "0" && $reset_active ne "1"} {
    puts "ERROR: -reset-active must be 0 or 1"
    usage
}
set reset_inactive [expr {1 - $reset_active}]

set reset_cycles [norm_nonneg_int $opt(-reset-cycles) -reset-cycles]
set warmup       [norm_nonneg_int $opt(-warmup) -warmup]
set cycles       [norm_nonneg_int $opt(-cycles) -cycles]
set prove_skip   [expr {$reset_cycles + $warmup}]
if {$cycles <= $prove_skip} {
    puts "ERROR: -cycles must be greater than -reset-cycles + -warmup"
    puts "       got cycles=$cycles, reset_cycles=$reset_cycles, warmup=$warmup"
    usage
}

switch -- $opt(-init) {
    any - zero - undef - def {}
    default {
        puts "ERROR: -init must be one of: any, zero, undef, def"
        usage
    }
}

file mkdir $opt(-outdir)
puts "[clock format [clock seconds] -format {%Y-%m-%d %H:%M:%S}] IO equivalence setup"
puts "  top            : $opt(-top)"
puts "  rtl            : $opt(-rtl)"
puts "  netlist        : $opt(-netlist)"
puts "  stdcell        : $opt(-stdcell)"
puts "  reset          : $opt(-reset)"
puts "  reset-active   : $reset_active"
puts "  reset-cycles   : $reset_cycles"
puts "  warmup         : $warmup"
puts "  cycles         : $cycles"
puts "  init           : $opt(-init)"
puts "  outdir         : $opt(-outdir)"

# -----------------------------------------------------------------------------
# Build and stash GOLD design from RTL.
# -----------------------------------------------------------------------------
yosys design -reset
yosys read_verilog -sv $opt(-rtl)
yosys hierarchy -check -top $opt(-top)
yosys proc
yosys opt
yosys memory
yosys opt
yosys rename $opt(-top) gold
yosys design -stash gold

# -----------------------------------------------------------------------------
# Build and stash GATE design from stdcell functional model + netlist.
# -----------------------------------------------------------------------------
yosys design -reset
yosys read_verilog -sv $opt(-stdcell)
yosys read_verilog -sv $opt(-netlist)
yosys hierarchy -check -top $opt(-top)
# Some functional stdcell models contain processes. Make them SAT-friendly.
yosys proc
yosys opt
yosys rename $opt(-top) gate
yosys design -stash gate

# -----------------------------------------------------------------------------
# Build IO miter. miter -equiv compares matching top-level inputs/outputs only.
# It does not require internal state/register equivalence, so retiming is OK.
# -----------------------------------------------------------------------------
yosys design -reset
yosys design -copy-from gold -as gold gold
yosys design -copy-from gate -as gate gate
yosys miter -equiv -flatten gold gate equiv
yosys hierarchy -check -top equiv
# Normalize for SAT. Avoid bare 'proc' because Tcl has a proc command too.
yosys proc
yosys opt
yosys async2sync
yosys dffunmap
yosys opt_clean -purge

# Debug dumps that do not require write_ilang/write_rtlil.
yosys write_verilog -noattr [file join $opt(-outdir) equiv_miter.v]

# -----------------------------------------------------------------------------
# SAT/BMC proof.
# miter creates common input ports as in_<portname> and a trigger output.
# We assert trigger == 0 after reset/warmup cycles.
# -----------------------------------------------------------------------------
set sat_args [list sat -seq $cycles]

switch -- $opt(-init) {
    zero  { lappend sat_args -set-init-zero }
    undef { lappend sat_args -set-init-undef }
    def   { lappend sat_args -set-init-def }
    any   { }
}

if {$opt(-reset) ne ""} {
    set reset_sig [rtlil_id "in_$opt(-reset)"]
    for {set t 1} {$t <= $reset_cycles} {incr t} {
        lappend sat_args -set-at $t $reset_sig $reset_active
    }
    for {set t [expr {$reset_cycles + 1}]} {$t <= $cycles} {incr t} {
        lappend sat_args -set-at $t $reset_sig $reset_inactive
    }
}

lappend sat_args -prove [rtlil_id trigger] 0
lappend sat_args -prove-skip $prove_skip
lappend sat_args -show [rtlil_id trigger]
lappend sat_args -show-inputs
lappend sat_args -show-outputs

if {$opt(-dump)} {
    lappend sat_args -dump_vcd [file join $opt(-outdir) cex.vcd]
}

lappend sat_args equiv

puts "Running SAT command: yosys $sat_args"
yosys {*}$sat_args
puts "IO equivalence check completed."
