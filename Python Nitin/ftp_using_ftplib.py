from ftplib import FTP
import pyinputplus
import os

try:
    def show():
        list_choice = pyinputplus.inputYesNo("Want to look at files of the other side(y/n): ", yesVal = "y", noVal = "n", limit = 3)
        if list_choice == "y": ftp.dir()

    def upload() -> None:
        filename = pyinputplus.inputFilename("Enter the filename to upload: ", limit = 3)
        if os.path.isfile(filename):
            with open(filename, "rb") as file: ftp.storbinary(f"STOR {filename}", file)
        else: print("The file not exists !"); exit()
        print("Upload Success !")
        show()

    def download() -> None: 
        while True:
            show()
            filename = pyinputplus.inputFilename("Enter the filename for downloading at local server(Quit: 'Ctrl + C'): ", limit = 3)
            with open(filename, "wb") as file: ftp.retrbinary(f"RETR {filename}", file.write)
            print("Download Success !")
            list_choice = pyinputplus.inputYesNo("Want to look at files of your side(y/n): ", yesVal = "y", noVal = "n", limit = 3)
            if list_choice == "y": print(os.listdir("."))

    print(f"{"-" * 10} FTP on the go {"-" * 10}")
    print(f"What mode : \n1. Download \n2. Upload")
    mode = pyinputplus.inputInt()
    hc_addr = pyinputplus.inputStr("Enter the server/client hostname(<IPAddress>:<Port(optional)>): ", limit = 3)   # Hostname of the ftp side
    hc_username = pyinputplus.inputStr("Enter the server/client username: ", limit = 3, blank = True)
    hc_pass = pyinputplus.inputPassword("Enter the server/client password: ", limit = 3, blank = True)
    if ":" in hc_addr: hc_addr, hc_port = hc_addr.split(":")
    ftp = FTP()
    ftp.encoding = "utf-8"
    ftp.connect(hc_addr, int(hc_port))
    ftp.login(hc_username, hc_pass)
    if mode == 1: download()
    else: upload()

except pyinputplus.RetryLimitException: print("The maximum number of retries exceeded !")
except KeyboardInterrupt: print("You Decided to exit !"); exit()
else: ftp.quit()
