import socket
import sys

addr = str(sys.argv[1])
addr, port = addr.split(":")
addr = str(addr)
port = int(port)
client_socket = socket.socket()
client_socket.connect((addr, port))

print(client_socket.recv(2048).decode())
client_socket.close()
print("Connection Closed !")