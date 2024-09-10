def file1():
    file=open("temp.txt","w+")
    str=input("Enter the Text: ")
    file.write(str)
    file.close()
    print("Sucessfully Written to the file !")
file1()