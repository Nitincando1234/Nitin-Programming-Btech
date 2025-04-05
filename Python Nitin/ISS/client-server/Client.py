import sys, socket, pyinputplus

def start_client():
    addr = "".join(sys.argv[1: ])
    port = 5555
    if addr == "": print("Usage python Client.py host:<port(optional)>"); sys.exit(1)
    host, port = addr.split(":")
    port = int(port)
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host, port))
        message = pyinputplus.inputStr("Enter the message to send: ")
        s.sendall(message.encode())
        data_recv = s.recv(1024)
        print("The data recieved from the server: ", data_recv.decode())

<<<<<<< HEAD
if __name__ == "__main__": start_client()
=======
if __name__ == "__main__": start_client()
>>>>>>> 542465eb118369df330e16a721424d9b7dac71e4
