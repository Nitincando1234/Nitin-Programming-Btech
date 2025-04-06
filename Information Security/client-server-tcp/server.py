import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(("127.0.0.1", 5555))
sock.listen()
conn, addr = sock.accept()

while True:
    data, addr = sock.recv(1024)
    print("Recieved Message: ", data.decode())

conn.close()