def myfile():
    file1=open("temp.txt","r")
    file2=open("temp1.txt","r")
    str1=file1.read()
    str2=file2.read()
    file1.close()
    file1=open("temp.txt","w")
    print(str1)
    print(str2)
    file1.write(str1+"\n"+str2)
    file1.close()
    print("Successfully written to temp.txt !")
myfile()