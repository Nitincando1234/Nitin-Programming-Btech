from scapy.all import sniff
from collections import Counter

# Configuration
MONITOR_DURATION = 60
THRESHOLD_REQUEST = 100
TARGET_IP = "10.0.2.217"

requests_counter = Counter()

def process_packet(packet):
    if packet.haslayer("TCP") and packet.haslayer("IP"):
        ip_src = packet["IP"].src
        ip_dst = packet["IP"].dest
        tcp_dport = packet["TCP"].dport

        if ip_dst == TARGET_IP and tcp_dport == 80:     # For the HTTP requests
            requests_counter[ip_src] += 1

def intrusion_detect():
    print("Analysing...")
    sniff(prn = process_packet, timeout = MONITOR_DURATION) 
    for ip_src, count in requests_counter.items():
        if count > THRESHOLD_REQUEST: print(f"Possible DOS intrusion detected from -> {ip_src} with requests: {count}")

if __name__ == "__main__": intrusion_detect()    