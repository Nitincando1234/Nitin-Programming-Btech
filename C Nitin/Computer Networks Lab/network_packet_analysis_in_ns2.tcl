set ns [new Simulator]
set tracefile [open trace1.tr w]
$ns trace-all $tracefile

set namfile [open out.nam w]
$ns namtrace-all $namfile

proc finish {} {
    global ns namfile tracefile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam out.nam &
    exit 0
}

set node1 [$ns node]
set node2 [$ns node]
$ns duplex-link $node1 $node2 1Mb 10Ms DropTail

# set udp and cbr 
set udp [new Agent/UDP]
set sink [new Agent/Null]
$ns attach-agent $node1 $udp
$ns attach-agent $node2 $sink

$ns connect $udp $sink
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set packetSize_ 512
$cbr set rate_ 1Mb
$cbr set random_ false

$ns at 1.0 "$cbr start"
$ns at 10.0 "$cbr stop"
$ns at 12.0 "finish"

# run the simulation
$ns run