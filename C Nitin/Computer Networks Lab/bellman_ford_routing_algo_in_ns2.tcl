set ns [new Simulator]
set tracefile [open out.tr w]
$ns trace-all $tracefile

set namfile [open out.nam w]
$ns namtrace-all $namfile

proc finish {} {
    global ns tracefile namfile    ;# get the ns and tracefile global objects
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam out.nam & 
    exit 0
}
set node1 [$ns node]
set node2 [$ns node]
set node3 [$ns node]
set node4 [$ns node]
set node5 [$ns node]
$ns rtproto DV
$ns duplex-link $node1 $node2 10Mb 10ms DropTail
$ns duplex-link $node2 $node3 10Mb 10ms DropTail
$ns duplex-link $node3 $node4 10Mb 10ms DropTail
$ns duplex-link $node4 $node5 10Mb 10ms DropTail
$ns duplex-link $node1 $node5 5Mb 50ms DropTail
$ns duplex-link $node2 $node4 5Mb 30ms DropTail

set tcp [new Agent/TCP]
$ns attach-agent $node1 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $node5 $sink

$ns connect $tcp $sink

$ns rtmodel-at 3.0 down $node2 $node3
$ns rtmodel-at 6.0 up $node2 $node3

$ns at 10.0 "finish"

$ns run