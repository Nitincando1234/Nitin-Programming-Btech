# EncryptionBreaker.py - Bruteforce Password breaker for the pdf files.
import PyPDF2, pyinputplus, time, send2trash, os

directory_path = "D:\\Nitin Programming Btech\\Python Nitin\\automate_boring_stuff\\CombinePdfs_15\\"
try: print("Your Base Dir is: ", directory_path); fileToEncrypt = pyinputplus.inputFilename("Enter the File Name in the current Dir u want to Encrypt: ", limit = 3)
except pyinputplus.RetryLimitException: print("Max retry limits reached !"); exit()
try: passwordForEncryption = pyinputplus.inputPassword("Enter the Password to Encrypt this file: ", limit = 1, timeout = 10)
except (pyinputplus.RetryLimitException, pyinputplus.TimeoutException): print(f"WE have done my best !!!\n\t{"*" * 8}But u'r idiot !{"*" * 8}"); exit()
full_path = os.path.join(directory_path, str(fileToEncrypt))
try: fileToEncryptFile = open(full_path, "rb")
except (FileNotFoundError): print("File not found !"), exit()
pdfReaderObj = PyPDF2.PdfFileReader(fileToEncryptFile)
pdfWriterObj = PyPDF2.PdfFileWriter()
for pageNum in range(pdfReaderObj.numPages):
    pdfWriterObj.addPage(pdfReaderObj.getPage(pageNum))
pdfWriterObj.encrypt(passwordForEncryption)
encFile = open(("enc_" + fileToEncrypt), "wb")
pdfWriterObj.write(encFile)
fileToEncryptFile.close()
encFile.close()
print("Encryption done.\nNow decrypting ...")
encFile = open(("enc_" + fileToEncrypt), "rb")
try:
    pdfReaderObj = PyPDF2.PdfFileReader(encFile)
    dictionary = open("D:\\Nitin Programming Btech\\Python Nitin\\automate_boring_stuff\\Materials Used in this book\\2151220-passwords.txt", "r")
    password = dictionary.readlines()

    decryptnResult: int = 0
    for passw in password:
        decryptnResult = pdfReaderObj.decrypt(passw.strip())
        if decryptnResult: 
            print(f"Password is: {"-" * 3}\t{passw}\t{"-" * 3}")
            time.sleep(5)
            break
    if decryptnResult == 0: print("Your pdf have good password !")
except (KeyboardInterrupt): print("Interrupted by the user !")
else: 
    print("Removing the ", "enc_" + fileToEncrypt, " as the work completed !")
    encFile.close()
    dictionary.close()
    send2trash.send2trash(os.path.join(directory_path, "enc_" + fileToEncrypt))
