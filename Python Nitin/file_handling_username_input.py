def myname():
    fn=input("Enter the first name: ")
    mn=input("Enter the middle name: ")
    ln=input("Enter the last name: ")
    file=open("temp1.txt","w")
    file.write(fn+"\n")
    file.write(mn+"\n")
    file.write(ln+"\n")
    file.close()
myname()