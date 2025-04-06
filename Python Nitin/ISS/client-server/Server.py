import sys, socket

def start_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        addr = "".join(sys.argv[1: ])
        if addr == "": print("Usage python Server.py host:<port>(Optional)"); sys.exit()
        port = 5555

        print(addr.split(":"))
        host, port = addr.split(":")
        port = int(port)
        print(port)
        s.bind((host, port))
        s.listen()
        print("Server start listening clients at port: ", port)
        conn, addr = s.accept()
        with conn:
            print("Connected with ", addr)
            while True:
                data = conn.recv(1024)
                data = data.decode()
                if data == "": break
                print("Data recieved: ", data)
                conn.sendall(data.encode())
        print("Server stopped !")

<<<<<<< HEAD
if __name__ == "__main__": start_server()
=======
if __name__ == "__main__": start_server()
>>>>>>> 542465eb118369df330e16a721424d9b7dac71e4
