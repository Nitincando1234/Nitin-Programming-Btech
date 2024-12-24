BEGIN {
    sent_packets = 0;
    recieved_packets = 0;
}
# for sender side
$1 == "+" && $3 == "0" && $4 == "1" && $5 == "cbr" {
    sent_packets++;
}
# for receiver side
$1 == "-" && $3 == "1" && $4 == "1" && $5 == "cbr" {
    recieved_packets++;
}

END {
    if (sent_packets > 0) {
        pdr = (recieved_packets / sent_packets) * 100;
        printf "Packet Delivery ratio: %.2f\n", pdr;
        printf "Total Packets sent: %.2f\n", sent_packets;
        printf "Total Packets recieved: %.2f\n", recieved_packets;
    }
    else {
        printf "No Packet were sent !\n";
    }
}