import socket

s = socket.socket()
port = 5555
port = int(input("Enter the port you want to listen on to: "))
s.bind(("", port))
print(f"Socket is binded to port {port}")
s.listen(5)
print("Server is listening from the clients now:")

while True:
    client_socket, client_addr = s.accept()
    print(f"Connection to client established: {client_addr}")
    client_socket.send("Connection is succesfull !".encode())
    client_socket.close()
    break   # Breaks the loop when the connection is close with the server by the client
print("Connection was closed !")