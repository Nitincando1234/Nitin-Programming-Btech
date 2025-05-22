import time
from scapy.all import sniff
from collections import Counter

# Configuration
MONITOR_DURATION = 10
THRESHOLD_REQUEST = 5

requests_counter = Counter()

def process_packet(packet):
    if packet.haslayer("TCP") and packet.haslayer("IP"):
        ip_src = packet["IP"].src
        ip_dst = packet["IP"].dest
        tcp_dport = packet["TCP"].dport

        if ip_dst == TARGET_IP and tcp_dport == 5500:     # For the HTTP requests
            requests_counter[ip_src] += 1

def intrusion_detect():
    print("Analysing...")
    sniff(filter = "tcp and dst port 5500",prn = process_packet, timeout = MONITOR_DURATION, store = False) 
    for ip_src, count in requests_counter.items():
        if count > THRESHOLD_REQUEST: print(f"Possible DOS intrusion detected from -> {ip_src} with requests: {count}")

if __name__ == "__main__": 
    TARGET_IP = input("Enter the Machine ip address: ")
    intrusion_detect()   
    time.sleep(10) 